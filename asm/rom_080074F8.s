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
	thumb_func_start sub_080074F8
sub_080074F8:
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r2, _08007518 @ =0x02025DB0
	movs r3, #0x00
	adds r6, r2, #0x0
	movs r1, #0x01
	.global _08007508
_08007508:
	ldr r0, [r2, #0x08]
	cmp r0, r5
	bne _0800751C
	str r1, [r2, #0x00]
	strb r4, [r2, #0x05]
	adds r0, r2, #0x0
	b _08007546
	.byte 0x00, 0x00
	.global _08007518
_08007518: .4byte 0x02025DB0
	.global _0800751C
_0800751C:
	adds r3, #0x01
	adds r2, #0x14
	cmp r3, #0x04
	bne _08007508
	adds r2, r6, #0x0
	movs r3, #0x00
	movs r1, #0x01
	.global _0800752A
_0800752A:
	ldr r0, [r2, #0x00]
	cmp r0, #0x00
	bne _0800753C
	str r1, [r2, #0x00]
	strb r4, [r2, #0x05]
	strb r1, [r2, #0x04]
	str r5, [r2, #0x08]
	adds r0, r2, #0x0
	b _08007546
	.global _0800753C
_0800753C:
	adds r3, #0x01
	adds r2, #0x14
	cmp r3, #0x04
	bne _0800752A
	movs r0, #0x00
	.global _08007546
_08007546:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
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
	thumb_func_start sub_08007630
sub_08007630:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _08007648 @ =0x02025C70
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r3, #0x01
	.global _0800763C
_0800763C:
	ldr r0, [r1, #0x08]
	cmp r0, r4
	bne _0800764C
	str r3, [r1, #0x00]
	adds r0, r1, #0x0
	b _08007674
	.global _08007648
_08007648: .4byte 0x02025C70
	.global _0800764C
_0800764C:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x10
	bne _0800763C
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	.global _0800765A
_0800765A:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0800766A
	str r3, [r1, #0x00]
	strb r3, [r1, #0x04]
	str r4, [r1, #0x08]
	adds r0, r1, #0x0
	b _08007674
	.global _0800766A
_0800766A:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x10
	bne _0800765A
	movs r0, #0x00
	.global _08007674
_08007674:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0800767C
sub_0800767C:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _08007694 @ =0x02025860
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r3, #0x01
	.global _08007688
_08007688:
	ldr r0, [r1, #0x08]
	cmp r0, r4
	bne _08007698
	str r3, [r1, #0x00]
	adds r0, r1, #0x0
	b _080076C0
	.global _08007694
_08007694: .4byte 0x02025860
	.global _08007698
_08007698:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _08007688
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	.global _080076A6
_080076A6:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080076B6
	str r3, [r1, #0x00]
	strb r3, [r1, #0x04]
	str r4, [r1, #0x08]
	adds r0, r1, #0x0
	b _080076C0
	.global _080076B6
_080076B6:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _080076A6
	movs r0, #0x00
	.global _080076C0
_080076C0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_080076C8
sub_080076C8:
	push {r4, r5, lr}
	adds r3, r0, #0x0
	ldr r1, _080076E0 @ =0x02025860
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r4, #0x01
	.global _080076D4
_080076D4:
	ldr r0, [r1, #0x08]
	cmp r0, r3
	bne _080076E4
	str r4, [r1, #0x00]
	adds r0, r1, #0x0
	b _0800770E
	.global _080076E0
_080076E0: .4byte 0x02025860
	.global _080076E4
_080076E4:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _080076D4
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r4, #0x01
	movs r5, #0x03
	.global _080076F4
_080076F4:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08007704
	str r4, [r1, #0x00]
	strb r5, [r1, #0x04]
	str r3, [r1, #0x08]
	adds r0, r1, #0x0
	b _0800770E
	.global _08007704
_08007704:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _080076F4
	movs r0, #0x00
	.global _0800770E
_0800770E:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_start sub_08007714
sub_08007714:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _0800772C @ =0x02025E00
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r3, #0x01
	.global _08007720
_08007720:
	ldr r0, [r1, #0x04]
	cmp r0, r4
	bne _08007730
	strb r3, [r1, #0x00]
	strb r3, [r1, #0x01]
	b _0800774A
	.global _0800772C
_0800772C: .4byte 0x02025E00
	.global _08007730
_08007730:
	adds r2, #0x01
	adds r1, #0x0C
	cmp r2, #0x10
	bne _08007720
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	.global _0800773E
_0800773E:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08007750
	strb r3, [r1, #0x00]
	strb r3, [r1, #0x01]
	str r4, [r1, #0x04]
	.global _0800774A
_0800774A:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	b _0800775A
	.global _08007750
_08007750:
	adds r2, #0x01
	adds r1, #0x0C
	cmp r2, #0x10
	bne _0800773E
	movs r0, #0x00
	.global _0800775A
_0800775A:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_start sub_08007760
sub_08007760:
	push {r4, r5, r6, r7, lr}
	ldr r4, _08007834 @ =0xFFFFFE00
	add sp, r4
	ldr r1, _08007838 @ =0x02025EC4
	movs r0, #0x00
	str r0, [r1, #0x00]
	ldr r5, _0800783C @ =0x02025DB0
	movs r6, #0x00
	.global _08007770
_08007770:
	ldrb r0, [r5, #0x04]
	cmp r0, #0x00
	beq _08007784
	ldr r0, [r5, #0x08]
	ldr r4, [r5, #0x0C]
	adds r1, r4, #0x0
	bl sub_08016E28
	movs r0, #0x00
	strb r0, [r5, #0x04]
	.global _08007784
_08007784:
	adds r6, #0x01
	adds r5, #0x14
	cmp r6, #0x04
	bne _08007770
	ldr r5, _08007840 @ =0x02025400
	movs r6, #0x00
	.global _08007790
_08007790:
	ldrb r0, [r5, #0x04]
	cmp r0, #0x00
	beq _080077A4
	ldr r0, [r5, #0x08]
	ldr r4, [r5, #0x0C]
	adds r1, r4, #0x0
	bl sub_08016E28
	movs r0, #0x00
	strb r0, [r5, #0x04]
	.global _080077A4
_080077A4:
	adds r6, #0x01
	adds r5, #0x14
	cmp r6, #0x18
	bne _08007790
	ldr r5, _08007844 @ =0x020255E0
	movs r6, #0x00
	.global _080077B0
_080077B0:
	ldrb r0, [r5, #0x04]
	cmp r0, #0x00
	beq _080077CE
	ldr r0, [r5, #0x08]
	ldr r4, [r5, #0x0C]
	mov r1, sp
	bl sub_08016E28
	mov r0, sp
	adds r1, r4, #0x0
	movs r2, #0x20
	bl sub_08016E10
	movs r0, #0x00
	strb r0, [r5, #0x04]
	.global _080077CE
_080077CE:
	adds r6, #0x01
	adds r5, #0x14
	cmp r6, #0x20
	bne _080077B0
	ldr r5, _08007848 @ =0x02025AE0
	movs r6, #0x00
	.global _080077DA
_080077DA:
	ldrb r0, [r5, #0x04]
	cmp r0, #0x00
	beq _080077EE
	ldr r0, [r5, #0x08]
	ldr r4, [r5, #0x0C]
	adds r1, r4, #0x0
	bl sub_08016E28
	movs r0, #0x00
	strb r0, [r5, #0x04]
	.global _080077EE
_080077EE:
	adds r6, #0x01
	adds r5, #0x14
	cmp r6, #0x14
	bne _080077DA
	ldr r5, _0800784C @ =0x02025C70
	movs r6, #0x00
	.global _080077FA
_080077FA:
	ldrb r0, [r5, #0x04]
	cmp r0, #0x00
	beq _0800780E
	ldr r0, [r5, #0x08]
	ldr r4, [r5, #0x0C]
	adds r1, r4, #0x0
	bl sub_08016E28
	movs r0, #0x00
	strb r0, [r5, #0x04]
	.global _0800780E
_0800780E:
	adds r6, #0x01
	adds r5, #0x14
	cmp r6, #0x10
	bne _080077FA
	ldr r5, _08007850 @ =0x02025860
	movs r6, #0x00
	.global _0800781A
_0800781A:
	ldrb r1, [r5, #0x04]
	cmp r1, #0x00
	beq _0800785E
	ldr r0, [r5, #0x08]
	ldr r4, [r5, #0x0C]
	cmp r1, #0x01
	bne _08007854
	adds r1, r4, #0x0
	movs r2, #0x10
	bl sub_08016E10
	b _0800785A
	.byte 0x00, 0x00
	.global _08007834
_08007834: .4byte 0xFFFFFE00
	.global _08007838
_08007838: .4byte 0x02025EC4
	.global _0800783C
_0800783C: .4byte 0x02025DB0
	.global _08007840
_08007840: .4byte 0x02025400
	.global _08007844
_08007844: .4byte 0x020255E0
	.global _08007848
_08007848: .4byte 0x02025AE0
	.global _0800784C
_0800784C: .4byte 0x02025C70
	.global _08007850
_08007850: .4byte 0x02025860
	.global _08007854
_08007854:
	adds r1, r4, #0x0
	bl sub_08016E28
	.global _0800785A
_0800785A:
	movs r0, #0x00
	strb r0, [r5, #0x04]
	.global _0800785E
_0800785E:
	adds r6, #0x01
	adds r5, #0x14
	cmp r6, #0x20
	bne _0800781A
	ldr r5, _080078AC @ =0x02025E00
	movs r6, #0x00
	ldr r7, _080078B0 @ =0x02025EC4
	.global _0800786C
_0800786C:
	ldrb r0, [r5, #0x01]
	cmp r0, #0x00
	beq _08007888
	ldr r0, [r5, #0x04]
	ldr r4, [r5, #0x08]
	adds r1, r4, #0x0
	movs r2, #0x10
	bl sub_08016E10
	movs r0, #0x00
	strb r0, [r5, #0x01]
	ldr r0, [r7, #0x00]
	adds r0, #0x20
	str r0, [r7, #0x00]
	.global _08007888
_08007888:
	adds r6, #0x01
	adds r5, #0x0C
	cmp r6, #0x10
	bne _0800786C
	ldr r0, _080078B0 @ =0x02025EC4
	ldr r2, _080078B4 @ =0x02025EC0
	ldr r1, [r0, #0x00]
	ldr r0, [r2, #0x00]
	cmp r1, r0
	ble _0800789E
	str r1, [r2, #0x00]
	.global _0800789E
_0800789E:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _080078AC
_080078AC: .4byte 0x02025E00
	.global _080078B0
_080078B0: .4byte 0x02025EC4
	.global _080078B4
_080078B4: .4byte 0x02025EC0
