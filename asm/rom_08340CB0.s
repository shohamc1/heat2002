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
	thumb_func_start sub_08340CB0
sub_08340CB0:
	adds r2, r0, #0x0
	ldr r0, _08340CCC @ =0x0203DD34
	ldr r0, [r0, #0x00]
	cmp r0, r2
	bgt _08340CD8
	ldr r0, _08340CD0 @ =0x0203D520
	ldr r0, [r0, #0x50]
	ldr r1, _08340CD4 @ =0x0000FFFF
	ands r0, r1
	cmp r0, r2
	bcc _08340CD8
	movs r0, #0x01
	b _08340CDA
	.byte 0x00, 0x00
_08340CCC: .4byte 0x0203DD34
_08340CD0: .4byte 0x0203D520
_08340CD4: .4byte 0x0000FFFF
_08340CD8:
	movs r0, #0x00
_08340CDA:
	bx lr
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
