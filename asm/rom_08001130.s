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
	.byte 0x70, 0x47, 0x00, 0x00, 0x02, 0x1C, 0x53, 0x6B, 0x03, 0x48, 0x83, 0x42, 0x03, 0xD1, 0x50, 0x68
	.byte 0x02, 0x49, 0x08, 0x40, 0x50, 0x60, 0x70, 0x47, 0x53, 0x6D, 0x73, 0x68, 0xFF, 0xFF, 0xFF, 0x7F
