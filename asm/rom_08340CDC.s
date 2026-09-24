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
	thumb_func_start sub_08340CDC
sub_08340CDC:
	ldr r1, _08340CF8 @ =0x0203DCFC
	ldr r2, [r1, #0x00]
	lsls r1, r2, #0x05
	subs r1, r1, r2
	lsls r1, r1, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x03
	ldr r2, _08340CFC @ =0x0203D500
	ldr r2, [r2, #0x00]
	adds r1, r1, r2
	cmp r1, r0
	ble _08340D00
	movs r0, #0x00
	b _08340D02
_08340CF8: .4byte 0x0203DCFC
_08340CFC: .4byte 0x0203D500
_08340D00:
	movs r0, #0x01
_08340D02:
	bx lr
