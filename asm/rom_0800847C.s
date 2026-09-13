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
	.byte 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_08008480
sub_08008480:
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r0, _080084DC @ =0x0202CB18
	strb r6, [r0, #0x00]
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_080083C0
	ldr r0, _080084E0 @ =0x0202A550
	cmp r5, r0
	bne _080084F4
	adds r0, r5, #0x0
	adds r0, #0x8C
	ldr r0, [r0, #0x00]
	movs r1, #0xFA
	lsls r1, r1, #0x0B
	cmp r0, r1
	bgt _080084C6
	adds r0, r5, #0x0
	adds r0, #0x90
	ldr r0, [r0, #0x00]
	cmp r0, r1
	bgt _080084C6
	adds r0, r5, #0x0
	adds r0, #0x94
	ldr r0, [r0, #0x00]
	cmp r0, r1
	bgt _080084C6
	adds r0, r5, #0x0
	adds r0, #0x98
	ldr r0, [r0, #0x00]
	cmp r0, r1
	ble _080084F4
	.global _080084C6
_080084C6:
	ldr r1, _080084E4 @ =0x0202CB2C
	movs r0, #0x40
	str r0, [r1, #0x00]
	ldr r2, _080084E8 @ =0x0202CAEC
	movs r0, #0x80
	str r0, [r2, #0x00]
	ldr r1, _080084EC @ =0x0202A518
	ldr r0, _080084F0 @ =0x00011F40
	str r0, [r1, #0x00]
	mov r12, r2
	b _0800857A
	.global _080084DC
_080084DC: .4byte 0x0202CB18
	.global _080084E0
_080084E0: .4byte 0x0202A550
	.global _080084E4
_080084E4: .4byte 0x0202CB2C
	.global _080084E8
_080084E8: .4byte 0x0202CAEC
	.global _080084EC
_080084EC: .4byte 0x0202A518
	.global _080084F0
_080084F0: .4byte 0x00011F40
	.global _080084F4
_080084F4:
	ldr r0, [r5, #0x2C]
	negs r0, r0
	asrs r4, r0, #0x0C
	cmp r4, #0x00
	bge _08008500
	movs r4, #0x00
	.global _08008500
_08008500:
	cmp r6, #0x00
	beq _08008544
	ldr r0, _08008528 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08008544
	ldr r1, _0800852C @ =0x0202CB2C
	ldr r0, _08008530 @ =0x0202A514
	ldrb r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r2, _08008534 @ =0x0202CAEC
	ldr r0, _08008538 @ =0x0202CBDC
	ldrb r0, [r0, #0x00]
	str r0, [r2, #0x00]
	ldr r1, _0800853C @ =0x0202A518
	ldr r0, _08008540 @ =0x0202A510
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	mov r12, r2
	b _0800857A
	.global _08008528
_08008528: .4byte 0x020020DC
	.global _0800852C
_0800852C: .4byte 0x0202CB2C
	.global _08008530
_08008530: .4byte 0x0202A514
	.global _08008534
_08008534: .4byte 0x0202CAEC
	.global _08008538
_08008538: .4byte 0x0202CBDC
	.global _0800853C
_0800853C: .4byte 0x0202A518
	.global _08008540
_08008540: .4byte 0x0202A510
	.global _08008544
_08008544:
	ldr r3, _08008624 @ =0x0202CB2C
	ldr r0, _08008628 @ =0x0202CAD4
	movs r2, #0xFF
	subs r2, r2, r4
	ldrb r0, [r0, #0x00]
	muls r0, r2
	ldr r1, _0800862C @ =0x0202A514
	ldrb r1, [r1, #0x00]
	muls r1, r4
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	ldr r3, _08008630 @ =0x0202CAEC
	ldr r0, _08008634 @ =0x0202CBC4
	ldrb r0, [r0, #0x00]
	muls r0, r2
	ldr r1, _08008638 @ =0x0202CBDC
	ldrb r1, [r1, #0x00]
	muls r1, r4
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	ldr r1, _0800863C @ =0x0202A518
	ldr r0, _08008640 @ =0x0202A510
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	mov r12, r3
	.global _0800857A
_0800857A:
	adds r2, r1, #0x0
	ldr r0, _08008644 @ =0x0202A550
	cmp r5, r0
	beq _0800858A
	ldr r0, _08008648 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080085BE
	.global _0800858A
_0800858A:
	movs r1, #0xB8
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080085AC
	ldr r1, _08008624 @ =0x0202CB2C
	ldr r0, [r1, #0x00]
	asrs r0, r0, #0x01
	str r0, [r1, #0x00]
	mov r3, r12
	ldr r0, [r3, #0x00]
	lsls r0, r0, #0x01
	str r0, [r3, #0x00]
	ldr r0, [r2, #0x00]
	asrs r0, r0, #0x01
	str r0, [r2, #0x00]
	.global _080085AC
_080085AC:
	ldr r4, _0800864C @ =0x00000171
	adds r0, r5, r4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080085BE
	mov r6, r12
	ldr r0, [r6, #0x00]
	asrs r0, r0, #0x01
	str r0, [r6, #0x00]
	.global _080085BE
_080085BE:
	ldr r2, _08008650 @ =0x0202CBE4
	ldrh r7, [r5, #0x34]
	lsrs r1, r7, #0x08
	subs r1, #0x40
	movs r0, #0xFF
	ands r1, r0
	str r1, [r2, #0x00]
	ldr r0, _08008654 @ =0x0202CAD8
	movs r3, #0x3C
	ldsh r2, [r5, r3]
	lsls r2, r2, #0x07
	str r2, [r0, #0x00]
	ldr r3, _08008658 @ =0x0202CBE8
	ldr r4, _0800865C @ =0x0801CD08
	lsls r0, r1, #0x01
	adds r0, r0, r4
	movs r6, #0x00
	ldsh r0, [r0, r6]
	negs r0, r0
	adds r6, r2, #0x0
	muls r6, r0
	asrs r7, r6, #0x08
	str r7, [r3, #0x00]
	ldr r3, _08008660 @ =0x0202CBEC
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r4
	movs r4, #0x00
	ldsh r0, [r1, r4]
	adds r4, r2, #0x0
	muls r4, r0
	asrs r2, r4, #0x08
	str r2, [r3, #0x00]
	movs r1, #0xB0
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800866C
	ldr r2, _08008664 @ =0x0202A54C
	asrs r1, r6, #0x09
	ldr r0, [r5, #0x0C]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	ldr r2, _08008668 @ =0x0202A528
	asrs r1, r4, #0x09
	ldr r0, [r5, #0x14]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	b _0800867C
	.byte 0x00, 0x00
	.global _08008624
_08008624: .4byte 0x0202CB2C
	.global _08008628
_08008628: .4byte 0x0202CAD4
	.global _0800862C
_0800862C: .4byte 0x0202A514
	.global _08008630
_08008630: .4byte 0x0202CAEC
	.global _08008634
_08008634: .4byte 0x0202CBC4
	.global _08008638
_08008638: .4byte 0x0202CBDC
	.global _0800863C
_0800863C: .4byte 0x0202A518
	.global _08008640
_08008640: .4byte 0x0202A510
	.global _08008644
_08008644: .4byte 0x0202A550
	.global _08008648
_08008648: .4byte 0x020020DC
	.global _0800864C
_0800864C: .4byte 0x00000171
	.global _08008650
_08008650: .4byte 0x0202CBE4
	.global _08008654
_08008654: .4byte 0x0202CAD8
	.global _08008658
_08008658: .4byte 0x0202CBE8
	.global _0800865C
_0800865C: .4byte 0x0801CD08
	.global _08008660
_08008660: .4byte 0x0202CBEC
	.global _08008664
_08008664: .4byte 0x0202A54C
	.global _08008668
_08008668: .4byte 0x0202A528
	.global _0800866C
_0800866C:
	ldr r1, _080086D4 @ =0x0202A54C
	ldr r0, [r5, #0x0C]
	adds r0, r0, r7
	str r0, [r1, #0x00]
	ldr r1, _080086D8 @ =0x0202A528
	ldr r0, [r5, #0x14]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _0800867C
_0800867C:
	ldr r1, _080086DC @ =0x0202CBD4
	mov r2, r12
	ldr r0, [r2, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _080086E0 @ =0x0202CB0C
	ldr r0, _080086E4 @ =0x0202CBE4
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r2, _080086E8 @ =0x0202CBF0
	movs r3, #0x96
	lsls r3, r3, #0x01
	adds r0, r5, r3
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	subs r0, #0x40
	movs r1, #0xFF
	ands r0, r1
	asrs r0, r0, #0x02
	lsls r0, r0, #0x02
	str r0, [r2, #0x00]
	movs r0, #0x00
	adds r1, r5, #0x0
	bl sub_080087F4
	movs r4, #0xB0
	lsls r4, r4, #0x01
	adds r0, r5, r4
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080086F4
	ldr r2, _080086D4 @ =0x0202A54C
	ldr r0, _080086EC @ =0x0202CBE8
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x01
	ldr r0, [r5, #0x0C]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	ldr r2, _080086D8 @ =0x0202A528
	ldr r0, _080086F0 @ =0x0202CBEC
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x01
	ldr r0, [r5, #0x14]
	b _08008708
	.byte 0x00, 0x00
	.global _080086D4
_080086D4: .4byte 0x0202A54C
	.global _080086D8
_080086D8: .4byte 0x0202A528
	.global _080086DC
_080086DC: .4byte 0x0202CBD4
	.global _080086E0
_080086E0: .4byte 0x0202CB0C
	.global _080086E4
_080086E4: .4byte 0x0202CBE4
	.global _080086E8
_080086E8: .4byte 0x0202CBF0
	.global _080086EC
_080086EC: .4byte 0x0202CBE8
	.global _080086F0
_080086F0: .4byte 0x0202CBEC
	.global _080086F4
_080086F4:
	ldr r2, _080087CC @ =0x0202A54C
	ldr r1, _080087D0 @ =0x0202CBE8
	ldr r0, [r5, #0x0C]
	ldr r1, [r1, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	ldr r2, _080087D4 @ =0x0202A528
	ldr r1, _080087D8 @ =0x0202CBEC
	ldr r0, [r5, #0x14]
	ldr r1, [r1, #0x00]
	.global _08008708
_08008708:
	subs r0, r0, r1
	str r0, [r2, #0x00]
	ldr r1, _080087DC @ =0x0202CBD4
	ldr r0, _080087E0 @ =0x0202CB2C
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r3, _080087E4 @ =0x0202CB0C
	ldr r7, _080087E8 @ =0x0202CBE4
	ldr r1, [r7, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x80
	movs r2, #0xFF
	ands r0, r2
	str r0, [r3, #0x00]
	ldr r0, _080087EC @ =0x0202CBF0
	ands r1, r2
	str r1, [r0, #0x00]
	movs r0, #0x01
	adds r1, r5, #0x0
	bl sub_080087F4
	movs r6, #0x9E
	lsls r6, r6, #0x01
	adds r6, r6, r5
	mov r12, r6
	ldr r1, [r6, #0x00]
	cmp r1, #0x00
	beq _0800877C
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r3, r5, r0
	asrs r1, r1, #0x08
	ldr r4, _080087F0 @ =0x0801CD08
	ldr r2, [r7, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r6, #0x00
	ldsh r0, [r0, r6]
	muls r1, r0
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	movs r0, #0xA2
	lsls r0, r0, #0x01
	adds r3, r5, r0
	mov r6, r12
	ldr r1, [r6, #0x00]
	asrs r1, r1, #0x08
	lsls r2, r2, #0x01
	adds r2, r2, r4
	movs r4, #0x00
	ldsh r0, [r2, r4]
	muls r1, r0
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	.global _0800877C
_0800877C:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r6, r5, r0
	ldr r1, [r6, #0x00]
	cmp r1, #0x00
	beq _080087C6
	movs r2, #0xA0
	lsls r2, r2, #0x01
	adds r3, r5, r2
	asrs r1, r1, #0x08
	ldr r4, _080087F0 @ =0x0801CD08
	ldr r2, [r7, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r7, #0x00
	ldsh r0, [r0, r7]
	muls r1, r0
	asrs r1, r1, #0x04
	ldr r0, [r3, #0x00]
	subs r0, r0, r1
	str r0, [r3, #0x00]
	movs r0, #0xA2
	lsls r0, r0, #0x01
	adds r3, r5, r0
	ldr r1, [r6, #0x00]
	asrs r1, r1, #0x08
	lsls r2, r2, #0x01
	adds r2, r2, r4
	movs r4, #0x00
	ldsh r0, [r2, r4]
	muls r1, r0
	asrs r1, r1, #0x04
	ldr r0, [r3, #0x00]
	subs r0, r0, r1
	str r0, [r3, #0x00]
	.global _080087C6
_080087C6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _080087CC
_080087CC: .4byte 0x0202A54C
	.global _080087D0
_080087D0: .4byte 0x0202CBE8
	.global _080087D4
_080087D4: .4byte 0x0202A528
	.global _080087D8
_080087D8: .4byte 0x0202CBEC
	.global _080087DC
_080087DC: .4byte 0x0202CBD4
	.global _080087E0
_080087E0: .4byte 0x0202CB2C
	.global _080087E4
_080087E4: .4byte 0x0202CB0C
	.global _080087E8
_080087E8: .4byte 0x0202CBE4
	.global _080087EC
_080087EC: .4byte 0x0202CBF0
	.global _080087F0
_080087F0: .4byte 0x0801CD08
	thumb_func_start sub_080087F4
sub_080087F4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r1, #0x0
	lsls r0, r0, #0x18
	ldr r3, _0800888C @ =0x0801CD08
	ldr r1, _08008890 @ =0x0202CBF0
	ldr r2, [r1, #0x00]
	adds r2, #0x40
	movs r1, #0xFF
	ands r2, r1
	adds r1, r2, #0x0
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r3
	movs r4, #0x00
	ldsh r7, [r1, r4]
	lsls r2, r2, #0x01
	adds r2, r2, r3
	movs r3, #0x00
	ldsh r1, [r2, r3]
	mov r8, r1
	ldr r1, _08008894 @ =0x0202A54C
	ldr r1, [r1, #0x00]
	adds r2, r7, #0x0
	muls r2, r1
	ldr r1, _08008898 @ =0x0202A528
	ldr r1, [r1, #0x00]
	mov r4, r8
	muls r4, r1
	adds r1, r4, #0x0
	adds r2, r2, r1
	asrs r6, r2, #0x08
	cmp r0, #0x00
	beq _08008914
	ldr r0, _0800889C @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08008866
	adds r3, r5, #0x0
	adds r3, #0x8C
	asrs r2, r2, #0x11
	adds r1, r2, #0x0
	cmp r2, #0x00
	bge _08008850
	negs r1, r2
	.global _08008850
_08008850:
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x90
	cmp r2, #0x00
	bge _08008860
	negs r2, r2
	.global _08008860
_08008860:
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _08008866
_08008866:
	ldr r0, _080088A0 @ =0x0202A518
	ldr r2, [r0, #0x00]
	negs r1, r2
	cmp r6, r1
	bge _080088AC
	lsrs r0, r1, #0x1F
	adds r0, r1, r0
	asrs r6, r0, #0x01
	ldr r4, _080088A4 @ =0x0202CB18
	ldrb r0, [r4, #0x00]
	movs r1, #0x02
	bl sub_0800B764
	ldr r0, _080088A8 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080088C8
	b _080088D8
	.byte 0x00, 0x00
	.global _0800888C
_0800888C: .4byte 0x0801CD08
	.global _08008890
_08008890: .4byte 0x0202CBF0
	.global _08008894
_08008894: .4byte 0x0202A54C
	.global _08008898
_08008898: .4byte 0x0202A528
	.global _0800889C
_0800889C: .4byte 0x0202EEB0
	.global _080088A0
_080088A0: .4byte 0x0202A518
	.global _080088A4
_080088A4: .4byte 0x0202CB18
	.global _080088A8
_080088A8: .4byte 0x020020DC
	.global _080088AC
_080088AC:
	cmp r6, r2
	ble _08008940
	lsrs r0, r2, #0x1F
	adds r0, r2, r0
	asrs r6, r0, #0x01
	ldr r4, _080088D0 @ =0x0202CB18
	ldrb r0, [r4, #0x00]
	movs r1, #0x03
	bl sub_0800B764
	ldr r0, _080088D4 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080088D8
	.global _080088C8
_080088C8:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080088E2
	b _08008940
	.global _080088D0
_080088D0: .4byte 0x0202CB18
	.global _080088D4
_080088D4: .4byte 0x020020DC
	.global _080088D8
_080088D8:
	ldr r0, _08008904 @ =0x0202EF90
	ldrb r4, [r4, #0x00]
	ldrb r0, [r0, #0x00]
	cmp r4, r0
	bne _08008940
	.global _080088E2
_080088E2:
	ldr r0, _08008908 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08008940
	ldr r0, _0800890C @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08008940
	ldr r0, _08008910 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08008940
	movs r0, #0x0B
	bl sub_08001208
	b _08008940
	.byte 0x00, 0x00
	.global _08008904
_08008904: .4byte 0x0202EF90
	.global _08008908
_08008908: .4byte 0x0202EF00
	.global _0800890C
_0800890C: .4byte 0x020020E0
	.global _08008910
_08008910: .4byte 0x020021E0
	.global _08008914
_08008914:
	ldr r0, _080089BC @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08008940
	adds r3, r5, #0x0
	adds r3, #0x94
	asrs r2, r2, #0x11
	adds r1, r2, #0x0
	cmp r2, #0x00
	bge _0800892A
	negs r1, r2
	.global _0800892A
_0800892A:
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x98
	cmp r2, #0x00
	bge _0800893A
	negs r2, r2
	.global _0800893A
_0800893A:
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _08008940
_08008940:
	ldr r0, _080089C0 @ =0x0202CBD4
	ldr r0, [r0, #0x00]
	adds r2, r6, #0x0
	muls r2, r0
	asrs r2, r2, #0x08
	negs r2, r2
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r3, r5, r0
	adds r1, r2, #0x0
	muls r1, r7
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	movs r1, #0xA2
	lsls r1, r1, #0x01
	adds r3, r5, r1
	mov r1, r8
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	ldr r0, _080089C4 @ =0x0202CBF0
	ldr r0, [r0, #0x00]
	adds r0, #0x40
	ldr r1, _080089C8 @ =0x0202CB0C
	ldr r1, [r1, #0x00]
	subs r0, r0, r1
	movs r1, #0xFF
	ands r0, r1
	ldr r1, _080089CC @ =0x0801CD08
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r3, #0x00
	ldsh r0, [r0, r3]
	muls r0, r2
	asrs r2, r0, #0x08
	lsls r2, r2, #0x07
	adds r1, r2, #0x0
	cmp r2, #0x00
	bge _0800899A
	ldr r4, _080089D0 @ =0x00007FFF
	adds r1, r2, r4
	.global _0800899A
_0800899A:
	asrs r2, r1, #0x0F
	movs r0, #0xC0
	lsls r0, r0, #0x01
	adds r3, r5, r0
	ldrb r0, [r3, #0x00]
	cmp r0, #0x00
	beq _080089D4
	subs r0, #0x01
	strb r0, [r3, #0x00]
	movs r3, #0xA4
	lsls r3, r3, #0x01
	adds r2, r5, r3
	asrs r1, r1, #0x10
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	b _080089E0
	.global _080089BC
_080089BC: .4byte 0x0202EEB0
	.global _080089C0
_080089C0: .4byte 0x0202CBD4
	.global _080089C4
_080089C4: .4byte 0x0202CBF0
	.global _080089C8
_080089C8: .4byte 0x0202CB0C
	.global _080089CC
_080089CC: .4byte 0x0801CD08
	.global _080089D0
_080089D0: .4byte 0x00007FFF
	.global _080089D4
_080089D4:
	movs r4, #0xA4
	lsls r4, r4, #0x01
	adds r1, r5, r4
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _080089E0
_080089E0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x30, 0xB5, 0x02, 0x1C, 0x00, 0x24, 0x00, 0x25, 0x00, 0x2A, 0x02, 0xDA, 0x52, 0x42
	.byte 0x01, 0x24, 0x80, 0x25, 0x00, 0x29, 0x02, 0xDA, 0x49, 0x42, 0x01, 0x20, 0x44, 0x40, 0x88, 0x01
	.byte 0x51, 0x18, 0x0E, 0xF0, 0x10, 0xFC, 0x00, 0x2C, 0x00, 0xD0, 0x40, 0x42, 0x28, 0x18, 0x30, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
