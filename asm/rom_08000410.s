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
	.byte 0x00, 0xB5, 0x05, 0x48, 0x00, 0x68, 0x00, 0x28, 0x01, 0xD0, 0x16, 0xF0, 0xEB, 0xFE, 0x00, 0xF0
	.byte 0x11, 0xF8, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x80, 0x05, 0x00, 0x02, 0x70, 0x47, 0x00, 0x00
