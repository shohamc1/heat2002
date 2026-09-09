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
	thumb_func_start sub_08008CDC
sub_08008CDC:
	ldr r2, _08008D0C @ =0x0202A534
	ldr r3, [r2, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x28
	str r1, [r2, #0x00]
	ldr r0, _08008D10 @ =0x000003E7
	cmp r1, r0
	ble _08008D0A
	ldr r1, _08008D14 @ =0xFFFFFC40
	adds r0, r3, r1
	str r0, [r2, #0x00]
	ldr r1, _08008D18 @ =0x0202CADC
	ldr r2, [r1, #0x00]
	adds r0, r2, #0x1
	str r0, [r1, #0x00]
	cmp r0, #0x3B
	ble _08008D0A
	subs r0, #0x3C
	str r0, [r1, #0x00]
	ldr r1, _08008D1C @ =0x0202CAE4
	ldr r0, [r1, #0x00]
	adds r0, #0x01
	str r0, [r1, #0x00]
	.global _08008D0A
_08008D0A:
	bx lr
	.global _08008D0C
_08008D0C: .4byte 0x0202A534
	.global _08008D10
_08008D10: .4byte 0x000003E7
	.global _08008D14
_08008D14: .4byte 0xFFFFFC40
	.global _08008D18
_08008D18: .4byte 0x0202CADC
	.global _08008D1C
_08008D1C: .4byte 0x0202CAE4
