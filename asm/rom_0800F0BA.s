@ Generated with Luvdis v0.9.0
.syntax unified
.text
@ Begin embedded Luvdis macros
	.macro arm_func_start name
	.align 2, 0
	.global \name
	.arm
	.type \name, %function
	.endm

	.macro arm_func_end name
	.size \name, .-\name
	.endm

	.macro thumb_func_start name
	.align 2, 0
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro non_word_aligned_thumb_func_start name
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro thumb_func_end name
	.size \name, .-\name
	.endm
@ End embedded Luvdis macros
	thumb_func_start sub_0800F0BC
sub_0800F0BC:
	mov r2, pc
	lsrs r2, r2, #0x18
	movs r1, #0x0C
	cmp r2, #0x02
	beq _0800F0CE
	movs r1, #0x0D
	cmp r2, #0x08
	beq _0800F0CE
	movs r1, #0x04
	.global _0800F0CE
_0800F0CE:
	subs r0, r0, r1
	bgt _0800F0CE
	bx lr
