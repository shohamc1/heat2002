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
	.byte 0x41, 0x69, 0x02, 0x69, 0x00, 0x2A, 0x01, 0xD0, 0x51, 0x61, 0x01, 0xE0, 0x02, 0x48, 0x01, 0x60
	.byte 0x00, 0x29, 0x00, 0xD0, 0x0A, 0x61, 0x70, 0x47, 0x80, 0xC3, 0x03, 0x02
