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
	.byte 0x0B, 0x1C, 0x00, 0xE0, 0x14, 0x33, 0x18, 0x78, 0xFF, 0x28, 0xFB, 0xD1, 0x14, 0x3B, 0xAA, 0x20
	.byte 0x40, 0x00, 0x11, 0x18, 0xD8, 0x88, 0x08, 0x60, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
