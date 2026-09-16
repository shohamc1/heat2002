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
	.byte 0x00, 0xB5, 0x04, 0x48, 0x14, 0x21, 0x4C, 0x22, 0xFD, 0xF7, 0x54, 0xFA, 0x00, 0x06, 0x00, 0x0E
	.byte 0x02, 0xBC, 0x08, 0x47, 0x18, 0xF5, 0x29, 0x08
