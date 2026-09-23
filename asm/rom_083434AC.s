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
	thumb_func_start sub_083434AC
sub_083434AC:
	movs r0, #0xC0
	lsls r0, r0, #0x04
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_083434B4
sub_083434B4:
	movs r0, #0xC0
	lsls r0, r0, #0x04
	bx lr
	.byte 0x00, 0x00
