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
	.byte 0x70, 0xB5, 0x05, 0x1C, 0x0C, 0x1C, 0x00, 0x26, 0x28, 0x1C, 0x21, 0x1C, 0x10, 0x22, 0x07, 0xF0
	.byte 0x6F, 0xFD, 0x40, 0x35, 0x40, 0x34, 0x01, 0x36, 0x1C, 0x2E, 0xF5, 0xD1, 0x70, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00
