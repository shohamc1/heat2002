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
	thumb_func_start sub_080046D0
sub_080046D0:
	push {r4, r5, r6, r7, lr}
	bl sub_0800464C
	ldr r7, _080047BC @ =0x0801CD08
	ldr r0, _080047C0 @ =0x0202522C
	ldrh r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r7
	lsls r0, r0, #0x01
	adds r0, r0, r7
	movs r3, #0x00
	ldsh r2, [r0, r3]
	negs r3, r2
	lsls r2, r2, #0x10
	lsls r3, r3, #0x10
	ldrh r1, [r1, #0x00]
	lsls r1, r1, #0x10
	ldr r4, _080047C4 @ =0x02024830
	adds r0, r1, #0x0
	ldrh r5, [r4, #0x04]
	orrs r0, r5
	str r0, [r4, #0x04]
	ldrh r0, [r4, #0x0C]
	orrs r2, r0
	str r2, [r4, #0x0C]
	ldrh r2, [r4, #0x14]
	orrs r3, r2
	str r3, [r4, #0x14]
	ldrh r3, [r4, #0x1C]
	orrs r1, r3
	str r1, [r4, #0x1C]
	ldr r0, _080047C8 @ =0x02025398
	ldrh r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r7
	lsls r0, r0, #0x01
	adds r0, r0, r7
	movs r5, #0x00
	ldsh r2, [r0, r5]
	negs r3, r2
	lsls r2, r2, #0x10
	lsls r3, r3, #0x10
	ldrh r1, [r1, #0x00]
	lsls r1, r1, #0x10
	adds r0, r1, #0x0
	ldrh r5, [r4, #0x24]
	orrs r0, r5
	str r0, [r4, #0x24]
	ldrh r0, [r4, #0x2C]
	orrs r2, r0
	str r2, [r4, #0x2C]
	ldrh r2, [r4, #0x34]
	orrs r3, r2
	str r3, [r4, #0x34]
	ldr r6, _080047CC @ =0x0000FFFF
	ldrh r3, [r4, #0x3C]
	orrs r1, r3
	str r1, [r4, #0x3C]
	ldr r1, _080047D0 @ =0x020251F0
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080047B4
	adds r1, r0, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r7
	movs r2, #0x00
	ldsh r5, [r0, r2]
	lsls r1, r1, #0x01
	adds r1, r1, r7
	movs r3, #0x00
	ldsh r2, [r1, r3]
	negs r3, r2
	adds r1, r5, #0x0
	ldr r0, _080047D4 @ =0x020253C8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08004778
	negs r5, r1
	adds r3, r2, #0x0
	.global _08004778
_08004778:
	ldr r0, _080047D8 @ =0x0202523C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08004784
	negs r2, r2
	negs r1, r1
	.global _08004784
_08004784:
	ands r5, r6
	ands r2, r6
	ands r3, r6
	ands r1, r6
	lsls r5, r5, #0x10
	lsls r2, r2, #0x10
	lsls r3, r3, #0x10
	lsls r1, r1, #0x10
	ldr r0, [r4, #0x44]
	ands r0, r6
	orrs r0, r5
	str r0, [r4, #0x44]
	ldr r0, [r4, #0x4C]
	ands r0, r6
	orrs r0, r2
	str r0, [r4, #0x4C]
	ldr r0, [r4, #0x54]
	ands r0, r6
	orrs r0, r3
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x5C]
	ands r0, r6
	orrs r0, r1
	str r0, [r4, #0x5C]
	.global _080047B4
_080047B4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _080047BC
_080047BC: .4byte 0x0801CD08
	.global _080047C0
_080047C0: .4byte 0x0202522C
	.global _080047C4
_080047C4: .4byte 0x02024830
	.global _080047C8
_080047C8: .4byte 0x02025398
	.global _080047CC
_080047CC: .4byte 0x0000FFFF
	.global _080047D0
_080047D0: .4byte 0x020251F0
	.global _080047D4
_080047D4: .4byte 0x020253C8
	.global _080047D8
_080047D8: .4byte 0x0202523C
