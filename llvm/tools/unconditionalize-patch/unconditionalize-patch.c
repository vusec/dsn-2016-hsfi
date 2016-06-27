#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../../include/edfi/unconditionalize/ucpatch.h"

enum patchmode {
	pm_keep,
	pm_orig,
	pm_golden,
	pm_faulty,
};

static struct bb_list {
	struct bb_list *next;
	long bb_index;
	enum patchmode mode;
} *bb_list;

static int setting_print;

static int setting_verbose;

static int warnings;

static const char *patchmodestr[] = {
	"keep",
	"orig",
	"golden",
	"faulty",
};

static void *calloc_checked(size_t count, size_t size, const char *name);
static void fault_list_add(long bb_index, enum patchmode);
static void perform_patch_bytes(int fd, struct bb_list *bb,
	struct ucpatch_byte *bytes, size_t bytecount);
static void perform_patch_bb(int fdpatch, int fd, struct bb_list *bb);
static void perform_patch_with_fd(int fdpatch, int fd);
static void perform_patch(const char *patchpath, const char *path);
static ssize_t pread_checked(int fd, void *buffer, size_t size, off_t off);
static ssize_t pwrite_checked(int fd, const void *buffer, size_t size, off_t off);
static void usage(void);

#define CALLOC(count, type) ((type *) calloc_checked(count, sizeof(type), #type))

static void *calloc_checked(size_t count, size_t size, const char *type) {
	void *p = calloc(count, size);
	if (!p && size > 0) {
		fprintf(stderr, "error: could not allocate %zd instances of %s: %s\n",
			count, type, strerror(errno));
		exit(-1);
	}
	return p;
}

static void fault_list_add(long bb_index, enum patchmode mode) {
	struct bb_list *new_fault;

	new_fault = CALLOC(1, struct bb_list);
	new_fault->next = bb_list;
	new_fault->bb_index = bb_index;
	new_fault->mode = mode;
	bb_list = new_fault;
}

static void perform_patch_bytes(int fd, struct bb_list *bb,
	struct ucpatch_byte *bytes, size_t bytecount) {
	struct ucpatch_byte *byte;
	uint8_t *data, *p, value;
	size_t datasize;
	int i;
	uint64_t offsetmin, offsetmax;
	int was_faulty = 1, was_golden = 1, was_orig = 1;

	assert(bytes);

	if (bytecount < 1) return;

	offsetmin = offsetmax = bytes[0].offset;
	for (i = 1; i < bytecount; i++) {
		if (offsetmin > bytes[i].offset) offsetmin = bytes[i].offset;
		if (offsetmax < bytes[i].offset) offsetmax = bytes[i].offset;
	}

	datasize = offsetmax - offsetmin + 1;
	data = CALLOC(datasize, uint8_t);
	pread_checked(fd, data, datasize, offsetmin);

	for (i = 0; i < bytecount; i++) {
		byte = &bytes[i];
		p = &data[byte->offset - offsetmin];
		value = *p;
		if (value != byte->value_faulty) was_faulty = 0;
		if (value != byte->value_golden) was_golden = 0;
		if (value != byte->value_orig) was_orig = 0;
		if (!was_faulty && !was_golden && !was_orig) {
			fprintf(stderr,
				"warning: patch does not match at 0x%llx\n",
				(long long) byte->offset);
			warnings++;
			return;
		}
		switch (bb->mode) {
		case pm_faulty: *p = byte->value_faulty; break;
		case pm_golden: *p = byte->value_golden; break;
		case pm_orig: *p = byte->value_orig; break;
		case pm_keep: break;
		default: assert(0 || "bad bb->mode");
		}
	}

	if (bb->mode == pm_keep) {
		printf("bb %ld: %s%s%s (%zd bytes)\n",
			bb->bb_index,
			was_faulty ? "faulty" : "",
			was_golden ? "golden" : "",
			was_orig ? "orig" : "",
			bytecount);
	} else {
		pwrite_checked(fd, data, datasize, offsetmin);
		printf("patched bb %ld: %s%s%s -> %s\n",
			bb->bb_index,
			was_faulty ? "faulty" : "",
			was_golden ? "golden" : "",
			was_orig ? "orig" : "",
			patchmodestr[bb->mode]);
	}
	free(data);
}

static void perform_patch_bb(int fdpatch, int fd, struct bb_list *bb) {
	struct ucpatch_byte *bytes;
	size_t bytecount;
	struct ucpatch_location loc;
	off_t off;

	assert(bb);

	off = sizeof(uint32_t) + sizeof(loc) * bb->bb_index;
	pread_checked(fdpatch, &loc, sizeof(loc), off);
	assert(loc.count % sizeof(struct ucpatch_byte) == 0);

	bytecount = loc.count / sizeof(struct ucpatch_byte);
	bytes = CALLOC(bytecount, struct ucpatch_byte);
	pread_checked(fdpatch, bytes, loc.count, loc.offset);

	perform_patch_bytes(fd, bb, bytes, bytecount);

	free(bytes);
}

static void perform_patch_with_fd(int fdpatch, int fd) {
	struct bb_list *bb, bbshow = { .mode = pm_keep };
	uint32_t bbcount, bbindex;

	pread_checked(fdpatch, &bbcount, sizeof(bbcount), 0);
	if (setting_verbose) {
		printf("%ld basic blocks in patch\n", (long) bbcount);
		for (bbindex = 0; bbindex < bbcount; bbindex++) {
			bbshow.bb_index = bbindex;
			perform_patch_bb(fdpatch, fd, &bbshow);
		}
	}
	for (bb = bb_list; bb; bb = bb->next) {
		assert(bb->bb_index >= 0);
		if (bb->bb_index >= bbcount) {
			fprintf(stderr, "warning: skipping out-of-range "
				"bb index %ld\n", bb->bb_index);
			warnings++;
			continue;
		}
		perform_patch_bb(fdpatch, fd, bb);
	}
}

static void perform_patch(const char *patchpath, const char *path) {
	int fd, fdpatch;

	assert(patchpath);
	assert(path);

	fdpatch = open(patchpath, O_RDONLY);
	if (fdpatch < 0) {
		fprintf(stderr, "error: cannot open patch file %s: %s\n",
			patchpath, strerror(errno));
		exit(3);
	}

	fd = open(path, O_RDWR);
	if (fd < 0) {
		fprintf(stderr, "error: cannot open binary file %s: %s\n",
			path, strerror(errno));
		exit(3);
	}

	perform_patch_with_fd(fdpatch, fd);

	close(fd);
	close(fdpatch);
}

static void print_patch_with_fd(int fdpatch) {
	uint32_t bbcount, bbindex;
	int diff_of, diff_og, diff_fg;
	struct ucpatch_location loc;
	off_t off;
	struct ucpatch_byte patch;
	int patchcount, patchindex;

	assert(fdpatch >= 0);

	printf("bb\tcount\tdiff_of\tdiff_og\tdiff_fg\n");
	pread_checked(fdpatch, &bbcount, sizeof(bbcount), 0);
	for (bbindex = 0; bbindex < bbcount; bbindex++) {
		diff_of = 0;
		diff_og = 0;
		diff_fg = 0;

		off = sizeof(bbcount) + bbindex * sizeof(loc);
		pread_checked(fdpatch, &loc, sizeof(loc), off);

		assert(loc.count % sizeof(patch) == 0);
		patchcount = loc.count / sizeof(patch);
		for (patchindex = 0; patchindex < patchcount; patchindex++) {
			off = loc.offset + patchindex * sizeof(patch);
			pread_checked(fdpatch, &patch, sizeof(patch), off);

			if (patch.value_orig != patch.value_faulty) diff_of++;
			if (patch.value_orig != patch.value_golden) diff_og++;
			if (patch.value_faulty != patch.value_golden) diff_fg++;
		}

		printf("%d\t%d\t%d\t%d\t%d\n", (int) bbindex, patchcount,
			diff_of, diff_og, diff_fg);
	}
}

static void print_patch(const char *patchpath) {
	int fdpatch;

	assert(patchpath);

	fdpatch = open(patchpath, O_RDONLY);
	if (fdpatch < 0) {
		fprintf(stderr, "error: cannot open patch file %s: %s\n",
			patchpath, strerror(errno));
		exit(3);
	}

	print_patch_with_fd(fdpatch);

	close(fdpatch);
}

static ssize_t pread_checked(int fd, void *buffer, size_t size, off_t off) {
	ssize_t r;

	assert(fd >= 0);
	assert(buffer);
	assert(size > 0);
	assert(off >= 0);

	r = pread(fd, buffer, size, off);
	if (r < 0) {
		fprintf(stderr, "error: read failed: %s\n", strerror(errno));
		exit(-1);
	}
	if (r != size) {
		fprintf(stderr, "error: premature end of file\n");
		exit(3);
	}
	return r;
}

static ssize_t pwrite_checked(int fd, const void *buffer, size_t size, off_t off) {
	ssize_t r;

	assert(fd >= 0);
	assert(buffer);
	assert(size > 0);
	assert(off >= 0);

	r = pwrite(fd, buffer, size, off);
	if (r < 0) {
		fprintf(stderr, "error: write failed: %s\n", strerror(errno));
		exit(-1);
	}
	if (r != size) {
		fprintf(stderr, "error: write size mismatch\n");
		exit(3);
	}
	return r;
}

static void usage(void) {
	printf("usage:\n");
	printf("  unconditionalize-patch [-pv] {{-f|-g|-o} bbindex}... patch-path bin-path...\n");
	printf("\n");
	printf("-p print, dump patch file (no bin-path needed).\n");
	printf("-v verbose, dump info for each basic block.\n");
	printf("-f selects the faulty version of the basic block.\n");
	printf("-g selects the faultless (golden) version of the basic block.\n");
	printf("-o selects the original (dynamic) version of the basic block.\n");
	exit(2);
}

int main(int argc, char **argv) {
	long bb_index;
	int c;
	char *endptr;
	enum patchmode mode;
	const char *patchpath;

	while ((c = getopt(argc, argv, "f:g:o:pv")) != -1) {
		switch (c) {
		case 'f':
		case 'g':
		case 'o':
			bb_index = strtol(optarg, &endptr, 10);
			if (endptr == optarg || *endptr || bb_index < 0) usage();
			mode = (c == 'f') ? pm_faulty : 
				(c == 'g') ? pm_golden : pm_orig;
			fault_list_add(bb_index, mode);
			break;
		case 'p':
			setting_print = 1;
			break;
		case 'v':
			setting_verbose = 1;
			break;
		default:
			assert(0 || "invalid option");
			return 1;
		}
	}

	if (optind >= argc) usage();
	patchpath = argv[optind++];

	if (setting_print) {
		print_patch(patchpath);
		if (optind >= argc) return 0;
	}

	if (optind >= argc) usage();
	do {
		perform_patch(patchpath, argv[optind]);
	} while (++optind < argc);

	if (warnings) printf("completed with %d warnings\n", warnings);

	return warnings ? 1 : 0;
}
