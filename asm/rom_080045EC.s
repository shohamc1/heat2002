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
	thumb_func_start sub_080045EC
sub_080045EC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	.global _080045F2
_080045F2:
	movs r0, #0x00
	mov r8, r0
	movs r1, #0x00
	ldr r2, _08004644 @ =0x02025160
	mov r12, r2
	ldr r7, _08004648 @ =0x02024C40
	.global _080045FE
_080045FE:
	lsls r0, r1, #0x01
	mov r2, r12
	adds r5, r0, r2
	ldrh r3, [r5, #0x00]
	adds r6, r1, #0x1
	lsls r0, r6, #0x01
	adds r4, r0, r2
	ldrh r2, [r4, #0x00]
	lsls r1, r3, #0x01
	adds r1, r1, r3
	lsls r1, r1, #0x02
	adds r1, r1, r7
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x02
	adds r0, r0, r7
	ldrh r1, [r1, #0x08]
	ldrh r0, [r0, #0x08]
	cmp r1, r0
	bcs _0800462E
	strh r2, [r5, #0x00]
	strh r3, [r4, #0x00]
	movs r0, #0x01
	mov r8, r0
	.global _0800462E
_0800462E:
	adds r1, r6, #0x0
	cmp r1, #0x3F
	bne _080045FE
	mov r1, r8
	cmp r1, #0x00
	bne _080045F2
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _08004644
_08004644: .4byte 0x02025160
	.global _08004648
_08004648: .4byte 0x02024C40
	thumb_func_start sub_0800464C
sub_0800464C:
	push {r4, r5, r6, r7, lr}
	ldr r0, _080046BC @ =0x02024824
	ldrb r3, [r0, #0x00]
	cmp r3, #0x3F
	beq _0800466E
	ldr r1, _080046C0 @ =0x02024820
	movs r4, #0x00
	movs r2, #0x01
	negs r2, r2
	.global _0800465E
_0800465E:
	ldr r0, [r1, #0x00]
	strh r4, [r0, #0x08]
	str r2, [r0, #0x04]
	adds r0, #0x0C
	str r0, [r1, #0x00]
	adds r3, #0x01
	cmp r3, #0x3F
	bne _0800465E
	.global _0800466E
_0800466E:
	bl sub_080045EC
	ldr r4, _080046C4 @ =0x02025160
	movs r3, #0x00
	ldr r0, _080046BC @ =0x02024824
	ldrb r1, [r0, #0x00]
	cmp r3, r1
	beq _080046B4
	ldr r1, _080046C8 @ =0x02024C40
	mov r12, r1
	ldr r5, _080046CC @ =0x02024828
	movs r7, #0x01
	negs r7, r7
	adds r6, r0, #0x0
	.global _0800468A
_0800468A:
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	mov r1, r12
	adds r2, r0, r1
	ldr r0, [r2, #0x04]
	cmp r0, r7
	beq _080046AA
	ldr r0, [r5, #0x00]
	ldr r1, [r2, #0x00]
	str r1, [r0, #0x00]
	ldr r1, [r2, #0x04]
	str r1, [r0, #0x04]
	adds r0, #0x08
	str r0, [r5, #0x00]
	.global _080046AA
_080046AA:
	adds r4, #0x02
	adds r3, #0x01
	ldrb r0, [r6, #0x00]
	cmp r3, r0
	bne _0800468A
	.global _080046B4
_080046B4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _080046BC
_080046BC: .4byte 0x02024824
	.global _080046C0
_080046C0: .4byte 0x02024820
	.global _080046C4
_080046C4: .4byte 0x02025160
	.global _080046C8
_080046C8: .4byte 0x02024C40
	.global _080046CC
_080046CC: .4byte 0x02024828
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
