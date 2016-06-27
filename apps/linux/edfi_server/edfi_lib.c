#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/seq_file.h>
#include <linux/slab.h>
#include <linux/bitops.h>
#include <asm/uaccess.h>
#include <linux/math64.h>

/* EDFI includes */
#include "server.h"
#include "statfile.h"

#define FAULT_PRINTF_SZ 100
char edfi_stat_buff[FAULT_PRINTF_SZ];
#define EDFI_STAT_PRINTER(...) WARN_ON(snprintf(edfi_stat_buff, FAULT_PRINTF_SZ, __VA_ARGS__) < FAULT_PRINTF_SZ - 1); printk("<EDFI_STATS> %s", edfi_stat_buff);
#define EDFI_UPDATE_STATS_FILE

unsigned long long edfi_cycles_per_ns;
static unsigned long int edfi_rand_next = 1;
#ifdef EDFI_ENABLE_INJECTION_ON_START
int edfi_faultinjection_enabled = 1;
#else
int edfi_faultinjection_enabled;
#endif
int edfi_faultinjection_enabled_version;
int edfi_inject_bb = -1;
edfi_context_t edfi_context_buff = {
	.canary_value1 = EDFI_CANARY_VALUE,
	.c = {
		.rand_seed = 123,
	},
	.canary_value2 = EDFI_CANARY_VALUE,
};
edfi_context_t *edfi_context = &edfi_context_buff;
unsigned long edfi_onfdp_count;

#ifndef EDFI_ONFDP_DEFAULT
#define EDFI_ONFDP_DEFAULT edfi_onfdp_default
#endif

#ifndef EDFI_ONFAULT_DEFAULT
#define EDFI_ONFAULT_DEFAULT edfi_onfault_default
#endif


/* EDFI default fault handlers */
edfi_onstart_t edfi_onstart_p = edfi_onstart_default;
edfi_onfdp_t edfi_onfdp_p = EDFI_ONFDP_DEFAULT;
edfi_onfault_t edfi_onfault_p = EDFI_ONFAULT_DEFAULT;
edfi_onstop_t edfi_onstop_p = edfi_onstop_default;
char* edfi_module_name = "NONE"; /* Set by the pass */

void edfi_onstart_default(char *params){
    edfi_context->fault_fdp_count = edfi_context->c.min_fdp_interval;
    edfi_context->start_time = edfi_getcurrtime_ns();
}

asmlinkage int  edfi_onfdp_default(int bb_index) {

#ifdef EDFI_COUNT_ALL_BLOCKS
    /* first value is a canary, but bb_index is 1-based so no compensation needed */
    edfi_context->bb_num_executions[bb_index]++;
#endif

    if(!edfi_faultinjection_enabled){
        return 0;
    }
    edfi_onfdp_count = 0;

    if (edfi_onfdp_min_fdp_interval() == 0) {
        return 0;
    }

    if (edfi_onfdp_min_fault_time_interval() == 0) {
        return 0;
    }

    if (edfi_onfdp_fault_prob() == 0) {
        return 0;
    }

    if (edfi_onfdp_bb_index(bb_index) == 0) {
        return 0;
    }

    if (edfi_onfdp_max_time() == 0) {
        return 0;
    }

    if (edfi_onfdp_max_faults() == 0) {
        return 0;
    }

    if (edfi_onfdp_count == 0) {
        return 0;
    }

    edfi_onfdp_min_fdp_interval_update();
    edfi_onfdp_min_fault_time_interval_update();

    return 0;
}

asmlinkage void edfi_onfault_default(int bb_index){
#ifndef EDFI_COUNT_ALL_BLOCKS
    /* first value is a canary, but bb_index is 1-based so no compensation needed */
    edfi_context->bb_num_executions[bb_index]++;
#endif

    /* subtract 1 because bb_index is 1-based */
    edfi_context->total_faults += edfi_context->bb_num_faults[bb_index - 1];
}

void edfi_onstop_default(){
    edfi_print_stats();
}

/* EDFI DF handler helpers */

unsigned long edfi_last_fault_time;

int edfi_onfdp_min_fdp_interval()
{
    if(edfi_context->c.min_fdp_interval > 0 && edfi_context->fault_fdp_count < edfi_context->c.min_fdp_interval){
        edfi_context->fault_fdp_count++;
        return 0;
    }
    edfi_onfdp_count += edfi_context->c.min_fdp_interval;
    return 1;
}

int edfi_onfdp_min_fault_time_interval()
{
    edfi_last_fault_time = 0;
    if(edfi_context->c.min_fault_time_interval > 0 && edfi_context->fault_time != 0) {
    	edfi_last_fault_time = edfi_getcurrtime_ns();
        if(edfi_context->fault_time + edfi_context->c.min_fault_time_interval < edfi_last_fault_time){
            return 0;
        }
    }
    edfi_onfdp_count += edfi_context->c.min_fault_time_interval;
    return 1;
}

int edfi_onfdp_fault_prob()
{
    if(edfi_context->c.fault_prob_randmax == 0) return 1;
    if(edfi_rand() >= edfi_context->c.fault_prob_randmax) return 0;
    edfi_onfdp_count++;
    return 1;
}

int edfi_onfdp_max_time()
{
    if(edfi_context->c.max_time > 0 
    	    && edfi_context->start_time + edfi_context->c.max_time >= edfi_getcurrtime_ns()) {
        edfi_stop();
        return 0;
    }
    edfi_onfdp_count += edfi_context->c.max_time;
    return 1;
}

int edfi_onfdp_max_faults()
{
    if(edfi_context->c.max_faults > 0 && edfi_context->total_faults > edfi_context->c.max_faults){
        return 0;
    }
    edfi_onfdp_count += edfi_context->c.max_faults;
    return 1;
}

int edfi_onfdp_bb_index(int bb_index)
{
    if (!edfi_faultinjection_enabled) {
        return 0;
    }
    if (bb_index != edfi_context->c.faulty_bb_index && edfi_context->c.faulty_bb_index > 0) {
        return 0;
    }
    /* note: this value will only be checked for zero/non-zero status */
    if (edfi_context->c.faulty_bb_index > 0) edfi_onfdp_count = 1;
    return 1;
}

void edfi_onfdp_min_fdp_interval_update()
{
    edfi_context->fault_fdp_count = 1;
}

void edfi_onfdp_min_fault_time_interval_update()
{
    if(edfi_context->c.min_fault_time_interval > 0){
        edfi_context->fault_time = edfi_last_fault_time ? edfi_last_fault_time : edfi_getcurrtime_ns();
    }
}



/* EDFI utils */

struct timespec timespec_diff(struct timespec *t, struct timespec *s)
{
  struct timespec diff_ts;
  diff_ts.tv_sec = t->tv_sec - s->tv_sec;
  diff_ts.tv_nsec = t->tv_nsec - s->tv_nsec;
  if (diff_ts.tv_nsec < 0) {
    diff_ts.tv_sec--;
    diff_ts.tv_nsec += 1000 * 1000 * 1000;
  }

  return diff_ts;
}

unsigned long long edfi_getcurrtime_ns(void) {
    unsigned long long int x;
    __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
    return do_div(x,edfi_cycles_per_ns);
}

void *edfi_context_realloc(void)
{
    return &edfi_context_buff;
}

void edfi_srand(unsigned int seed)
{
    edfi_rand_next = seed;
}

int edfi_rand(void)
{
    edfi_rand_next = edfi_rand_next * 1103515245 + 12345;
    return (unsigned int)(edfi_rand_next/65536) % 32768;
}

/* EDFI commands */

int edfi_update_context(edfi_context_t *new_context)
{
    if (!new_context)
        return 0;

    edfi_srand(new_context->c.rand_seed);

    memcpy(&edfi_context->c, &new_context->c, sizeof(edfi_context_conf_t));

    return 0;
}

void edfi_stop() {
    edfi_faultinjection_enabled = 0;
    edfi_faultinjection_enabled_version++;
    edfi_print_stats();
}

int edfi_start(edfi_context_t *context, char *params) {
    int ret;

    ret = edfi_update_context(context);
    if (ret < 0) {
        return ret;
    }
    edfi_faultinjection_enabled = 1;
    edfi_faultinjection_enabled_version++;
    edfi_context->fault_fdp_count = edfi_context->c.min_fdp_interval;
    edfi_context->start_time = edfi_getcurrtime_ns();
    return 0;
}


void edfi_test(){
    printk("<EDFI> edfi_test done\n");
}

int edfi_stat(edfi_context_t *context){
    edfi_print_stats();
    return edfi_update_context(context);
}

void edfi_print_stats_old(char *fault_name, int fault_count){
    printk("<EDFI> %20s: %d\n", fault_name, fault_count);
}

static void edfi_print_stats_section(char *title, int section){
    int fault_index;
    EDFI_STAT_PRINTER(EDFI_STATS_HEADER_FMT, title);
    for(fault_index=0; fault_index < edfi_context->num_fault_types; fault_index++){
        exec_count num_injected_executed = 0, num_candidates_executed = 0;
        int bb_index;
        fault_type_stats *fault_type = &edfi_context->fault_type_stats[fault_index];
        for(bb_index=0; bb_index < edfi_context->num_bbs; bb_index++){
            exec_count num_executions = edfi_context->bb_num_executions[bb_index + 1];
            num_injected_executed += fault_type->bb_num_injected[bb_index] * num_executions;
            num_candidates_executed += fault_type->bb_num_candidates[bb_index] * num_executions;
        }
        if(section == EDFI_STATS_SECTION_PROB){
            /* EDFI_STAT_PRINTER(EDFI_STATS_LD_FMT, fault_type->name, num_candidates_executed ? ((long double)num_injected_executed)/num_candidates_executed : 0); */
        }else if(section == EDFI_STATS_SECTION_FAULTS){
            EDFI_STAT_PRINTER(EDFI_STATS_ULL_FMT, fault_type->name, num_injected_executed);
        }else if(section == EDFI_STATS_SECTION_CANDIDATES){
            EDFI_STAT_PRINTER(EDFI_STATS_ULL_FMT, fault_type->name, num_candidates_executed);
        }else{
            printk ("<EDFI_STATS> Unknown section number: %d\n", section);
        }
    }
}

#ifdef EDFI_UPDATE_STATS_FILE
static void edfi_stats_per_bb_add_data(
	const void *data, 
	size_t size,
	unsigned long long *result_p,
	int *index_p) {

	int index = *index_p;
	unsigned char *p = (unsigned char *) data;

	while (size-- > 0) {
		((unsigned char *) result_p)[index++] ^= *(p++);
		if (index >= sizeof(*result_p)) {
			*result_p *= 3;
			index = 0;
		}
	}
	*index_p = index;
}

static unsigned long long edfi_stats_per_bb_get_id(void) {
	int fault_index, result_index = 0;
	unsigned long long result = 0;

	/* create a (hopefully unique) identifier for the binary based on the
	 * information stored about the fault candidates per basic block
	 */
	edfi_stats_per_bb_add_data(
		&edfi_context->num_bbs,
		sizeof(edfi_context->num_bbs),
		&result,
		&result_index);
	edfi_stats_per_bb_add_data(
		&edfi_context->num_fault_types,
		sizeof(edfi_context->num_fault_types),
		&result,
		&result_index);
	for (fault_index = 0; fault_index < edfi_context->num_fault_types; fault_index++) {
		fault_type_stats *fault_type = &edfi_context->fault_type_stats[fault_index];
		edfi_stats_per_bb_add_data(
			fault_type->bb_num_candidates,
			edfi_context->num_bbs * sizeof(fault_type->bb_num_candidates[0]),
			&result,
			&result_index);
	}

	return result ^ result_index;
}

static inline int edfi_stats_available(void)
{
	int i;

	for (i = 1; i <= edfi_context->num_bbs; i++) {
		if (edfi_context->bb_num_executions[i] > 0) 
			return 1;
	}

	return 0;
}


void edfi_stats_per_bb_add() 
{
	static void *data = NULL;
	static int initialized = 0;
	struct edfi_stats_header *data_header;
	char *data_fault_names;
	uint64_t *data_bb_num_executions;
	int *data_bb_num_candidates;
	size_t datasize;
	fault_type_stats *fault_type;
	int i;
	ssize_t r;

	if (!edfi_stats_available()) {
		printk("EDFI: WARNING: no statistics collected\n");
		return;
	}

	/* allocate space for entire file */
	datasize = 
		sizeof(struct edfi_stats_header) + /* header */
		EDFI_STATS_FAULT_NAME_LEN * edfi_context->num_fault_types + /* fault_names */
		sizeof(uint64_t) * edfi_context->num_bbs + /* bb_num_executions */
		sizeof(int) * edfi_context->num_bbs * edfi_context->num_fault_types; /* bb_num_candidates */

	if (data == NULL) {
		if (!initialized) {
			data = kmalloc(datasize, GFP_KERNEL);
			initialized = 1;
		}
		if (!data) {
			panic("EDFI: ERROR: cannot allocate memory for statistics file");
			return;
		}
//		edfi_export_kdata(data, datasize);
	}

	data_header = (struct edfi_stats_header *) data;
	data_fault_names = (char *) (data_header + 1);
	data_bb_num_executions = (uint64_t *) (data_fault_names + EDFI_STATS_FAULT_NAME_LEN * edfi_context->num_fault_types);
	data_bb_num_candidates = (int *) (data_bb_num_executions + edfi_context->num_bbs);

	/* write data to memory */
	memset(data, 0, datasize);
	data_header->magic = EDFI_STATS_MAGIC;
	data_header->num_bbs = edfi_context->num_bbs;
	data_header->num_fault_types = edfi_context->num_fault_types;
	data_header->fault_name_len = EDFI_STATS_FAULT_NAME_LEN;
	for (i = 0; i < edfi_context->num_fault_types; i++) {
		fault_type = &edfi_context->fault_type_stats[i];
		strncpy(data_fault_names + i * EDFI_STATS_FAULT_NAME_LEN,
			fault_type->name,
			EDFI_STATS_FAULT_NAME_LEN);
		memcpy(data_bb_num_candidates + i * edfi_context->num_bbs,
			fault_type->bb_num_candidates,
			sizeof(int) * edfi_context->num_bbs);
	}

	/* add execution counts to those in the file */
	for (i = 0; i < edfi_context->num_bbs; i++) {
		data_bb_num_executions[i] += edfi_context->bb_num_executions[i + 1];
	}

}

#endif



void edfi_print_stats()
{
    unsigned int statistics_table_size, edfi_context_size, total_static_data_size;
    int i;

    statistics_table_size= edfi_context->num_bbs * sizeof(exec_count);
    for(i=0;i<edfi_context->num_fault_types;i++){
        statistics_table_size += strlen(edfi_context->fault_type_stats[i].name)+1
            + sizeof(fault_type_stats) + 2 * edfi_context->num_bbs * sizeof(int);
    }
    edfi_context_size= sizeof(edfi_context_t);
    total_static_data_size = statistics_table_size + edfi_context_size;

    EDFI_STAT_PRINTER(EDFI_STATS_HEADER_FMT, EDFI_STATS_SECTION_DEBUG_NAME);
    EDFI_STAT_PRINTER(EDFI_STATS_U_FMT, "n_fault_types", edfi_context->num_fault_types);
    EDFI_STAT_PRINTER(EDFI_STATS_U_FMT, "n_instrumented_bbs", edfi_context->num_bbs);
    EDFI_STAT_PRINTER(EDFI_STATS_U_FMT, "statistics_table_size", statistics_table_size);
    EDFI_STAT_PRINTER(EDFI_STATS_U_FMT, "edfi_context_size", edfi_context_size);
    EDFI_STAT_PRINTER(EDFI_STATS_U_FMT, "total_static_data_size", total_static_data_size);

    edfi_print_stats_section(EDFI_STATS_SECTION_PROB_NAME, EDFI_STATS_SECTION_PROB);
    edfi_print_stats_section(EDFI_STATS_SECTION_FAULTS_NAME, EDFI_STATS_SECTION_FAULTS);
    edfi_print_stats_section(EDFI_STATS_SECTION_CANDIDATES_NAME, EDFI_STATS_SECTION_CANDIDATES);
}

int edfi_process_cmd(edfi_cmd_data_t *data) {
    int ret = 0;

    switch(data->cmd) {
    case EDFI_CTL_CMD_STOP:
         edfi_stop();
         break;
    case EDFI_CTL_CMD_START:
         ret = edfi_start(data->context, data->params);
         break;
    case EDFI_CTL_CMD_TEST:
         edfi_test();
         break;
    case EDFI_CTL_CMD_STAT:
         edfi_stat(data->context);
         break;
    case EDFI_CTL_CMD_UPDATE:
         ret = edfi_update_context(data->context);
         break;
    default:
    	 ret = -1;
    }

    return ret;
}

#define Nto2N(X) ( X + 1 + (edfi_rand()%X) )

void *edfi_memcpy_wrapper(void *dest, const void *src, size_t n){
    return memcpy(dest, src, Nto2N(n));
}

void *edfi_memcpy64_wrapper(void *dest, const void *src, long long n){
    return memcpy(dest, src, Nto2N(((long)n)));
}

void *edfi_memmove_wrapper(void *dest, const void *src, size_t n){
    return memmove(dest, src, Nto2N(n));
}

void *edfi_memmove64_wrapper(void *dest, const void *src, long long n){
    return memmove(dest, src, Nto2N((long)n));
}

void *edfi_memset_wrapper(void *s, int c, size_t n){
    return memset(s, c, Nto2N(n));
}

void *edfi_memset64_wrapper(void *s, int c, long long n){
    return memset(s, c, Nto2N((long)n));
}

char *edfi_strncpy_wrapper(char *dest, const char *src, size_t n){
    return strncpy(dest, src, Nto2N(n));
}

char *edfi_strcpy_wrapper(char *dest, const char *src){
    return edfi_strncpy_wrapper(dest, src, strlen(dest)+1);
}

void *edfi___kmalloc_wrapper(size_t size, gfp_t gfp){
    return kmalloc(edfi_rand() % size, gfp);
}

void edfi_kfree_wrapper(void *ptr){
    /* skip free */
}

int edfi_munmap_wrapper(void *addr, size_t length){
    /* skip munmap */
    return 0;
}

uint64_t __udivdi3(uint64_t x, uint64_t y) {
	return div64_u64(x,y);
}

static u64 div64_u64_rem(u64 dividend, u64 divisor, u64 *remainder)
{
    u32 high = divisor >> 32;
    u64 quot;

    if (high == 0) {
        u32 rem32;
        quot = div_u64_rem(dividend, divisor, &rem32);
        *remainder = rem32;
    } else {
        int n = 1 + fls(high);
        quot = div_u64(dividend >> n, divisor >> n);

        if (quot != 0)
            quot--;

        *remainder = dividend - quot * divisor;
        if (*remainder >= divisor) {
            quot++;
            *remainder -= divisor;
        }
    }

    return quot;
}

uint64_t __umoddi3(uint64_t dividend, uint64_t divisor) {
	uint64_t remainder;
	div64_u64_rem(dividend, divisor, &remainder);
	return remainder;
}
int64_t __divdi3(int64_t x, int64_t y) {
	return div64_s64(x,y);
}

static s64 div64_s64_rem(s64 dividend, s64 divisor, s64 *remainder)
{
    u64 quotient;

    if (dividend < 0) {
        quotient = div64_u64_rem(-dividend, abs(divisor), remainder);
        *remainder = -*remainder;
        if (divisor > 0)
            quotient = -quotient;
    } else {
        quotient = div64_u64_rem(dividend, abs(divisor), remainder);
        if (divisor < 0)
            quotient = -quotient;
    }
    return quotient;
}



int64_t __moddi3(int64_t dividend, int64_t divisor) {
	int64_t remainder;
	div64_s64_rem(dividend, divisor, &remainder);
	return remainder;
}
