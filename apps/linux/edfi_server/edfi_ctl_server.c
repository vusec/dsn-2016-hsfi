/* Kernel include */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/seq_file.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <asm/stacktrace.h>

/* EDFI includes */
#include "server.h"
#include "edfi_hyper.h"

/*
static void *edfi_dflib = NULL;
*/
static volatile int edfi_completed_req;
static volatile int edfi_max_req;
static int edfi_cmd_ack;
extern unsigned long long edfi_cycles_per_ns;
extern int edfi_faultinjection_enabled;

extern edfi_context_t *edfi_context;

static void edfi_ctl_time_init(void);
static void edfi_ctl_init(void);
static void edfi_ctl_close(void);
ssize_t edfi_ctl_read (struct file *, char __user *, size_t, loff_t *);
ssize_t edfi_ctl_write (struct file *, const char __user *, size_t, loff_t *);


#ifdef MAGIC_WITH_EDFI
#undef EDFI_CONTEXT_RELOCATE
#define EDFI_CONTEXT_RELOCATE 0
#include <magic_mem.h>
#define EDFI_WRAPPER_BEGIN MAGIC_MEM_WRAPPER_BEGIN
#define EDFI_WRAPPER_END MAGIC_MEM_WRAPPER_END
#else
#define EDFI_WRAPPER_BEGIN()
#define EDFI_WRAPPER_END()
#endif

int edfi_process_cmd(edfi_cmd_data_t*);


static const struct file_operations edfi_ops = {
    .owner       = THIS_MODULE,
    .read        = edfi_ctl_read,
    .write       = edfi_ctl_write,
};

static struct proc_dir_entry *edfi_ctl_file;

int __edfi_ctl_init(void) {
    EDFI_WRAPPER_BEGIN();
    edfi_ctl_init();
    EDFI_WRAPPER_END();
    return 0;
}

void __edfi_ctl_close(void) {
    EDFI_WRAPPER_BEGIN();
    edfi_ctl_close();
    EDFI_WRAPPER_END();
}

ssize_t edfi_ctl_read (struct file *filp, char __user *buff, size_t count, loff_t *off) {
    char msg[8];
    static int parity = 0;
    int ret;
    memset(msg, 0, 8);
    snprintf(msg, 8, "%d\n", edfi_cmd_ack);
    ret = copy_to_user(buff, msg, 8);
    printk("<EDFI> Written %d: %s", ret, msg);
    edfi_cmd_ack = 0;

    /* We do this in order to avoid getting into an infinite loop when reading */
    parity = !parity;
    return (parity) ? strlen(msg) : 0;
}

ssize_t edfi_ctl_write (struct file *filp, const char __user *buff, size_t count, loff_t *offset) {
    char *data_buff = NULL;
    size_t data_buff_size;
    int ret;
    edfi_cmd_data_t *data;

    edfi_cmd_ack = 0;
    if (edfi_max_req == 0 || (edfi_completed_req < edfi_max_req)) {
        if (count < sizeof(edfi_cmd_data_t)) {
            printk("<EDFI> Wrong command size (%u > %zu)\n", 
                    sizeof(edfi_cmd_data_t), count);

            goto exit_write;
        }
        data = kmalloc(sizeof(edfi_cmd_data_t), GFP_ATOMIC);
        if (!data) {
            panic("Failed to allocate memory for edfi_cmd_data\n");
        }
        memset(&data, 0, sizeof(edfi_cmd_data_t));
        ret = copy_from_user(data, buff, sizeof(edfi_cmd_data_t));
        if (ret) {
            printk("<EDFI> Copy from user failed to fetch command\n");
            goto free_data;
        }
        data_buff_size = data->context_size + data->params_size;

        if (data_buff_size > 0) {
            if (data->context_size != sizeof(edfi_context_t)) {
                printk("<EDFI> Wrong context size (%zd != %u)\n", data->context_size, sizeof(edfi_context_t));
                goto free_data;
            }
            data_buff = kmalloc(data_buff_size, GFP_ATOMIC);
            if (!data_buff) {
                panic("Failed to allocate memory for edfi_buffer\n");
            }

            ret = copy_from_user(data_buff, buff + sizeof(edfi_cmd_data_t), data_buff_size);
            if (ret) {
                printk ("<EDFI> Copy from user failed to fetch context\n");
                goto free_buff;
            }
            data->context = (edfi_context_t*) data_buff;
            data->params = data_buff + sizeof(edfi_context_t);
        }

        data->status = edfi_process_cmd(data);

        edfi_cmd_ack = data->status;
        edfi_completed_req ++;
    }
    else
        goto exit_write;

    if (!data_buff)
        goto free_data;

free_buff:
    kfree(data_buff);

free_data:
    kfree(data);

exit_write:
    if (!edfi_cmd_ack) edfi_cmd_ack = -1;

    return count;
}


static void edfi_ctl_time_init(void) {
    struct timespec start_ts, end_ts, diff_ts;
    unsigned long long i, start = 0, end = 0, diff, span;

    edfi_cycles_per_ns = 1;
    local_bh_disable();
    getnstimeofday(&start_ts);
    start = edfi_getcurrtime_ns();
    for (i = 0; i < 1000000; i++);
    end = edfi_getcurrtime_ns();
    getnstimeofday(&end_ts);
    local_bh_enable();

    diff_ts = timespec_diff(&end_ts, &start_ts);
    diff = diff_ts.tv_sec * (1000 * 1000 * 1000) + diff_ts.tv_nsec;
    span = end - start;
    edfi_cycles_per_ns = do_div((span),(diff ? diff : 1));
    if (edfi_cycles_per_ns == 0) {
        edfi_cycles_per_ns = 1;
    }
}

static void edfi_ctl_context_init(void) {
    extern int edfi_faultinjection_enabled;
    edfi_context->no_svr_thread =  0;
    edfi_context->num_requests_on_start = 0;
    edfi_context->c.fault_prob_randmax = 0;
    edfi_context->c.rand_seed = 0;
    edfi_context->verbosity = 0;

    if (edfi_context->verbosity > 0) {
        printk("edfi_ctl_context_init: EDFI_NO_SVR_THREAD=%d EDFI_NUM_REQUESTS_ON_START=%d EDFI_FAULT_PROB=%d EDFI_RAND_SEED=%d EDFI_VERBOSITY=%d EDFI_FI_ENABLED=%d\n",
            edfi_context->no_svr_thread, edfi_context->num_requests_on_start, edfi_context->c.fault_prob_randmax, edfi_context->c.rand_seed, edfi_context->verbosity, edfi_faultinjection_enabled);
    }
}


static void edfi_ctl_init(void) {
    int i;

    static int edfi_first_run = 1;
    static int edfi_disabled;
    if (edfi_disabled) return;
    if (edfi_first_run) {
        edfi_context = (edfi_context_t*) edfi_context_realloc();
	if (!EDFI_IS_OK_CONTEXT(edfi_context)) {
		printk("EDFI pass not performed, EDFI disabled\n");
		edfi_disabled = 1;
		return;
	}
        edfi_ctl_file = proc_create("edfi_ctl", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IWOTH | S_IROTH, NULL, &edfi_ops);
        edfi_ctl_time_init();
        edfi_ctl_context_init();
    }
    edfi_srand(edfi_context->c.rand_seed);

    if (edfi_context->bb_num_executions) {
        edfi_context->bb_num_executions[0] = EDFI_CANARY_VALUE;
        for(i = 1; i <= edfi_context->num_bbs; i++){
            edfi_context->bb_num_executions[i] = 0;
        }
        edfi_context->bb_num_executions[edfi_context->num_bbs + 1] = EDFI_CANARY_VALUE;
    }

    if(!edfi_context->no_svr_thread || edfi_context->num_requests_on_start > 0) {
        edfi_completed_req = 0;
        edfi_max_req = 0;
        if (edfi_context->no_svr_thread) {
            edfi_max_req = edfi_context->num_requests_on_start;
        }
    }

    edfi_first_run = 0;
    edfi_context->num_requests_on_start = 0;
    EDFI_PRINT_CONTEXT(printk, edfi_context);
    EDFI_CHECK_CONTEXT(edfi_context);

    hypermem_report_startup();
    printk("<EDFI> Created proc file %s\n", EDFI_CTL_PATH);
    printk("<EDFI> Finished initialization\n");
}

static void edfi_ctl_close(void) {
    if (edfi_ctl_file) proc_remove(edfi_ctl_file);
}

module_init(__edfi_ctl_init);
module_exit(__edfi_ctl_close);
