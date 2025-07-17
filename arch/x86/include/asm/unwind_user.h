/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_X86_UNWIND_USER_H
#define _ASM_X86_UNWIND_USER_H

#ifdef CONFIG_IA32_EMULATION
/* Currently compat mode is not supported for deferred stack trace */
static inline bool arch_unwind_can_defer(void)
{
	struct pt_regs *regs = task_pt_regs(current);

	return user_64bit_mode(regs);
}
# define arch_unwind_can_defer	arch_unwind_can_defer
#endif /* CONFIG_IA32_EMULATION */

#define ARCH_INIT_USER_FP_FRAME							\
	.cfa_off	= (s32)sizeof(long) *  2,				\
	.ra_off		= (s32)sizeof(long) * -1,				\
	.fp_off		= (s32)sizeof(long) * -2,				\
	.use_fp		= true,

#endif /* _ASM_X86_UNWIND_USER_H */
