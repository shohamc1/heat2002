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
	.byte 0x30, 0xB5, 0x02, 0x1C, 0x0D, 0x1C, 0x28, 0x1C, 0x11, 0x1C, 0xFF, 0xF7, 0xE9, 0xFE, 0x00, 0x24
	.byte 0xAC, 0x42, 0x06, 0xD0, 0xFC, 0xF7, 0xE2, 0xFA, 0xFF, 0xF7, 0x78, 0xFF, 0x01, 0x34, 0xAC, 0x42
	.byte 0xF8, 0xD1, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
