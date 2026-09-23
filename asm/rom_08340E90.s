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
	thumb_func_start sub_08340E90
sub_08340E90:
	ldr r0, _08340EA0 @ =0x0203D500
	movs r1, #0x00
	str r1, [r0, #0x00]
	ldr r0, _08340EA4 @ =0x0203DCFC
	str r1, [r0, #0x00]
	ldr r0, _08340EA8 @ =0x0203DD04
	str r1, [r0, #0x00]
	bx lr
_08340EA0: .4byte 0x0203D500
_08340EA4: .4byte 0x0203DCFC
_08340EA8: .4byte 0x0203DD04
