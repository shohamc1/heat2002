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
	thumb_func_start sub_0833DBE0
sub_0833DBE0:
	mov r12, r4
	ldr r4, _0833DBF0 @ =0xFFFFFE00
	add sp, r4
	mov r4, r12
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	bx lr
_0833DBF0: .4byte 0xFFFFFE00
