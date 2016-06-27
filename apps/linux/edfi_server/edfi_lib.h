#ifndef _EDFI_LIB_H
#define _EDFI_LIB_H
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/seq_file.h>
#include <linux/slab.h>
#include <linux/bitops.h>
#include <asm/uaccess.h>

#include "common.h"
#include "server.h"

struct timespec timespec_diff(struct timespec *t, struct timespec *s);

/* EDFI context definitions. */
extern edfi_context_t edfi_context_buff;
extern edfi_context_t *edfi_context;

/* DF handlers. */
typedef void (*edfi_onstart_t)(char *params);
typedef int (*edfi_onfdp_t)(int bb_index);
typedef void (*edfi_onfault_t)(int bb_index);
typedef void (*edfi_onstop_t)(void);

/* DF default handlers. */
void edfi_onstart_default(char *params);
asmlinkage int  edfi_onfdp_default(int bb_index);
asmlinkage void edfi_onfault_default(int bb_index);
void edfi_onstop_default(void);

extern edfi_onstart_t edfi_onstart_p;
extern edfi_onfdp_t edfi_onfdp_p;
extern edfi_onfault_t edfi_onfault_p;
extern edfi_onstop_t edfi_onstop_p;

/* DF handler helpers. */
int edfi_onfdp_min_fdp_interval(void);
int edfi_onfdp_min_fault_time_interval(void);
int edfi_onfdp_fault_prob(void);
int edfi_onfdp_bb_index(int bb_index);
void edfi_onfdp_min_fdp_interval_update(void);
void edfi_onfdp_min_fault_time_interval_update(void);
int edfi_onfdp_max_time(void);
int edfi_onfdp_max_faults(void);

/* DF API. */
int edfi_start(edfi_context_t *context, char *params);
void edfi_stop(void);
void edfi_test(void);
int edfi_stat(edfi_context_t *context);
void edfi_print_stats(void);
int edfi_update_context(edfi_context_t *context);
int edfi_process_cmd(edfi_cmd_data_t *data);

#endif
