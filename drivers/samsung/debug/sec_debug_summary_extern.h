#ifndef __SEC_DEBUG_SUMMARY_EXTERN_H__
#define __SEC_DEBUG_SUMMARY_EXTERN_H__

/* kernel/kallsyms.c */
extern const unsigned long kallsyms_addresses[] __weak;
extern const int kallsyms_offsets[] __weak;
extern const u8 kallsyms_names[] __weak;
extern const unsigned long kallsyms_num_syms
__attribute__((weak, section(".rodata")));
extern const unsigned long kallsyms_relative_base
__attribute__((weak, section(".rodata")));
extern const u8 kallsyms_token_table[] __weak;
extern const u16 kallsyms_token_index[] __weak;
extern const unsigned long kallsyms_markers[] __weak;

/* kernel/sched/walt.c */
#ifdef CONFIG_SCHED_WALT
#include "../../kernel/sched/sched.h"
extern struct sched_cluster *sched_cluster[NR_CPUS];
extern int num_clusters;
#endif

/* kernel/sched/core.c */
DECLARE_PER_CPU_SHARED_ALIGNED(struct rq, runqueues);

#ifndef CONFIG_VMAP_STACK
/* arch/arm64/kernel/irq.c */
DECLARE_PER_CPU_ALIGNED(unsigned long [IRQ_STACK_SIZE/sizeof(long)], irq_stack);
#endif

/* implemented @ kernel/printk/printk.c */
extern void sec_debug_summary_set_klog_info(struct sec_debug_summary_data_apss *apss);

/* implemented @ kernel/trace/msm_rtb.c */
extern void sec_debug_summary_set_rtb_info(struct sec_debug_summary_data_apss *apss);

/* implemented @ drivers/soc/qcom/memory_dump_v2.c */
extern void sec_debug_summary_set_msm_memdump_info(struct sec_debug_summary_data_apss *apss);

#endif /* __SEC_DEBUG_SUMMARY_EXTERN_H__ */
