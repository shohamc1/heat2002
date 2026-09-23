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
	thumb_func_start sub_0833FD2C
sub_0833FD2C:
	push {r4, r5, lr}
	adds r3, r0, #0x0
	ldr r1, _0833FD44 @ =0x0203BCD0
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r4, #0x01
_0833FD38:
	ldr r0, [r1, #0x08]
	cmp r0, r3
	bne _0833FD48
	str r4, [r1, #0x00]
	adds r0, r1, #0x0
	b _0833FD72
_0833FD44: .4byte 0x0203BCD0
_0833FD48:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _0833FD38
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r4, #0x01
	movs r5, #0x03
_0833FD58:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FD68
	str r4, [r1, #0x00]
	strb r5, [r1, #0x04]
	str r3, [r1, #0x08]
	adds r0, r1, #0x0
	b _0833FD72
_0833FD68:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _0833FD58
	movs r0, #0x00
_0833FD72:
	pop {r4, r5}
	pop {r1}
	bx r1
