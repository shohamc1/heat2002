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
	thumb_func_start sub_080016E4
sub_080016E4:
	push {r4, r5, lr}
	adds r3, r0, #0x0
	ldr r0, _08001770 @ =0x03007FF0
	ldr r5, [r0, #0x00]
	ldr r1, [r5, #0x00]
	ldr r0, _08001774 @ =0x68736D53
	cmp r1, r0
	bne _0800176A
	adds r0, r1, #0x1
	str r0, [r5, #0x00]
	movs r4, #0xFF
	ands r4, r3
	cmp r4, #0x00
	beq _08001706
	movs r0, #0x7F
	ands r4, r0
	strb r4, [r5, #0x05]
	.global _08001706
_08001706:
	movs r4, #0xF0
	lsls r4, r4, #0x04
	ands r4, r3
	cmp r4, #0x00
	beq _08001726
	lsrs r0, r4, #0x08
	strb r0, [r5, #0x06]
	movs r4, #0x0C
	adds r0, r5, #0x0
	adds r0, #0x50
	movs r1, #0x00
	.global _0800171C
_0800171C:
	strb r1, [r0, #0x00]
	subs r4, #0x01
	adds r0, #0x40
	cmp r4, #0x00
	bne _0800171C
	.global _08001726
_08001726:
	movs r4, #0xF0
	lsls r4, r4, #0x08
	ands r4, r3
	cmp r4, #0x00
	beq _08001734
	lsrs r0, r4, #0x0C
	strb r0, [r5, #0x07]
	.global _08001734
_08001734:
	movs r4, #0xB0
	lsls r4, r4, #0x10
	ands r4, r3
	cmp r4, #0x00
	beq _08001752
	movs r0, #0xC0
	lsls r0, r0, #0x0E
	ands r0, r4
	lsrs r4, r0, #0x0E
	ldr r2, _08001778 @ =0x04000089
	ldrb r1, [r2, #0x00]
	movs r0, #0x3F
	ands r0, r1
	orrs r0, r4
	strb r0, [r2, #0x00]
	.global _08001752
_08001752:
	movs r4, #0xF0
	lsls r4, r4, #0x0C
	ands r4, r3
	cmp r4, #0x00
	beq _08001766
	bl sub_080017D0
	adds r0, r4, #0x0
	bl sub_08001640
	.global _08001766
_08001766:
	ldr r0, _08001774 @ =0x68736D53
	str r0, [r5, #0x00]
	.global _0800176A
_0800176A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08001770
_08001770: .4byte 0x03007FF0
	.global _08001774
_08001774: .4byte 0x68736D53
	.global _08001778
_08001778: .4byte 0x04000089
	.byte 0xF0, 0xB5, 0x12, 0x48, 0x06, 0x68, 0x31, 0x68, 0x11, 0x48, 0x81, 0x42, 0x1B, 0xD1, 0x48, 0x1C
	.byte 0x30, 0x60, 0x0C, 0x25, 0x34, 0x1C, 0x50, 0x34, 0x00, 0x20, 0x20, 0x70, 0x01, 0x3D, 0x40, 0x34
	.byte 0x00, 0x2D, 0xFA, 0xDC, 0xF4, 0x69, 0x00, 0x2C, 0x0B, 0xD0, 0x01, 0x25, 0x00, 0x27, 0x28, 0x06
	.byte 0x00, 0x0E, 0xF1, 0x6A, 0x15, 0xF0, 0x22, 0xFD, 0x27, 0x70, 0x01, 0x35, 0x40, 0x34, 0x04, 0x2D
	.byte 0xF5, 0xDD, 0x03, 0x48, 0x30, 0x60, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xF0, 0x7F, 0x00, 0x03
	.byte 0x53, 0x6D, 0x73, 0x68
