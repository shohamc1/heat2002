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
	thumb_func_start sub_08000444
sub_08000444:
	ldr r0, _08000450 @ =0x04000202
	movs r1, #0x01
	strh r1, [r0, #0x00]
	ldr r0, _08000454 @ =0x02000DD0
	strh r1, [r0, #0x00]
	bx lr
_08000450: .4byte 0x04000202
_08000454: .4byte 0x02000DD0
