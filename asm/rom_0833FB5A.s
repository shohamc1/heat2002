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
	thumb_func_start sub_0833FB5C
sub_0833FB5C:
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r2, _0833FB7C @ =0x0203C220
	movs r3, #0x00
	adds r6, r2, #0x0
	movs r1, #0x01
_0833FB6C:
	ldr r0, [r2, #0x08]
	cmp r0, r5
	bne _0833FB80
	str r1, [r2, #0x00]
	strb r4, [r2, #0x05]
	adds r0, r2, #0x0
	b _0833FBAA
	.byte 0x00, 0x00
_0833FB7C: .4byte 0x0203C220
_0833FB80:
	adds r3, #0x01
	adds r2, #0x14
	cmp r3, #0x04
	bne _0833FB6C
	adds r2, r6, #0x0
	movs r3, #0x00
	movs r1, #0x01
_0833FB8E:
	ldr r0, [r2, #0x00]
	cmp r0, #0x00
	bne _0833FBA0
	str r1, [r2, #0x00]
	strb r4, [r2, #0x05]
	strb r1, [r2, #0x04]
	str r5, [r2, #0x08]
	adds r0, r2, #0x0
	b _0833FBAA
_0833FBA0:
	adds r3, #0x01
	adds r2, #0x14
	cmp r3, #0x04
	bne _0833FB8E
	movs r0, #0x00
_0833FBAA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
