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
	thumb_func_start sub_08008B6C
sub_08008B6C:
	ldr r1, _08008B88 @ =0x0202CADC
	ldr r2, [r1, #0x00]
	lsls r1, r2, #0x05
	subs r1, r1, r2
	lsls r1, r1, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x03
	ldr r2, _08008B8C @ =0x0202A534
	ldr r2, [r2, #0x00]
	adds r1, r1, r2
	cmp r1, r0
	ble _08008B90
	movs r0, #0x00
	b _08008B92
_08008B88: .4byte 0x0202CADC
_08008B8C: .4byte 0x0202A534
_08008B90:
	movs r0, #0x01
_08008B92:
	bx lr
