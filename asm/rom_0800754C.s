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
	thumb_func_start sub_0800754C
sub_0800754C:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _08007564 @ =0x02025400
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r3, #0x01
	.global _08007558
_08007558:
	ldr r0, [r1, #0x08]
	cmp r0, r4
	bne _08007568
	str r3, [r1, #0x00]
	adds r0, r1, #0x0
	b _08007590
	.global _08007564
_08007564: .4byte 0x02025400
	.global _08007568
_08007568:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x18
	bne _08007558
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	.global _08007576
_08007576:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08007586
	str r3, [r1, #0x00]
	strb r3, [r1, #0x04]
	str r4, [r1, #0x08]
	adds r0, r1, #0x0
	b _08007590
	.global _08007586
_08007586:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x18
	bne _08007576
	movs r0, #0x00
	.global _08007590
_08007590:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_08007598
sub_08007598:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _080075B0 @ =0x020255E0
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r3, #0x01
	.global _080075A4
_080075A4:
	ldr r0, [r1, #0x08]
	cmp r0, r4
	bne _080075B4
	str r3, [r1, #0x00]
	adds r0, r1, #0x0
	b _080075DC
	.global _080075B0
_080075B0: .4byte 0x020255E0
	.global _080075B4
_080075B4:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _080075A4
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	.global _080075C2
_080075C2:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080075D2
	str r3, [r1, #0x00]
	strb r3, [r1, #0x04]
	str r4, [r1, #0x08]
	adds r0, r1, #0x0
	b _080075DC
	.global _080075D2
_080075D2:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _080075C2
	movs r0, #0x00
	.global _080075DC
_080075DC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_080075E4
sub_080075E4:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _080075FC @ =0x02025AE0
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r3, #0x01
	.global _080075F0
_080075F0:
	ldr r0, [r1, #0x08]
	cmp r0, r4
	bne _08007600
	str r3, [r1, #0x00]
	adds r0, r1, #0x0
	b _08007628
	.global _080075FC
_080075FC: .4byte 0x02025AE0
	.global _08007600
_08007600:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x14
	bne _080075F0
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	.global _0800760E
_0800760E:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0800761E
	str r3, [r1, #0x00]
	strb r3, [r1, #0x04]
	str r4, [r1, #0x08]
	adds r0, r1, #0x0
	b _08007628
	.global _0800761E
_0800761E:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x14
	bne _0800760E
	movs r0, #0x00
	.global _08007628
_08007628:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
