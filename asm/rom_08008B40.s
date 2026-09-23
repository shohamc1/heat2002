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
	thumb_func_start sub_08008B40
sub_08008B40:
	adds r2, r0, #0x0
	ldr r0, _08008B5C @ =0x0202CB14
	ldr r0, [r0, #0x00]
	cmp r0, r2
	bgt _08008B68
	ldr r0, _08008B60 @ =0x0202A550
	ldr r0, [r0, #0x50]
	ldr r1, _08008B64 @ =0x0000FFFF
	ands r0, r1
	cmp r0, r2
	bcc _08008B68
	movs r0, #0x01
	b _08008B6A
	.byte 0x00, 0x00
_08008B5C: .4byte 0x0202CB14
_08008B60: .4byte 0x0202A550
_08008B64: .4byte 0x0000FFFF
_08008B68:
	movs r0, #0x00
_08008B6A:
	bx lr
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
