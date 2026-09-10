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
	thumb_func_start sub_08015364
sub_08015364:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08015470 @ =0xFFFFFDFC
	add sp, r4
	ldr r1, _08015474 @ =0x0202F030
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r1, #0x00
	ldr r0, _08015478 @ =0x020021C4
	strb r1, [r0, #0x00]
	ldr r0, _0801547C @ =0x020020DC
	strb r1, [r0, #0x00]
	bl sub_08015304
	movs r5, #0x00
	ldr r1, _08015480 @ =0x0202EF20
	movs r3, #0x00
	adds r2, r1, #0x0
	.global _0801538E
_0801538E:
	adds r0, r5, r1
	strb r3, [r0, #0x00]
	adds r5, #0x01
	cmp r5, #0x11
	bne _0801538E
	movs r5, #0x00
	movs r0, #0x01
	strb r0, [r2, #0x0C]
	strb r0, [r2, #0x0D]
	strb r0, [r2, #0x0E]
	strb r0, [r2, #0x0F]
	strb r0, [r2, #0x10]
	bl sub_08011A50
	bl sub_08016BF8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080153C4
	bl sub_0801238C
	bl sub_08016A38
	bl sub_0801692C
	bl sub_08016A04
	.global _080153C4
_080153C4:
	bl sub_08016BF8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080153DA
	bl sub_080167E0
	bl sub_08016888
	bl sub_080169CC
	.global _080153DA
_080153DA:
	ldr r0, _08015484 @ =0x04000020
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r2, r1, #0x0
	strh r2, [r0, #0x00]
	adds r0, #0x04
	movs r4, #0x00
	strh r5, [r0, #0x00]
	adds r0, #0x02
	strh r2, [r0, #0x00]
	adds r0, #0x0A
	strh r2, [r0, #0x00]
	adds r0, #0x02
	strh r2, [r0, #0x00]
	ldr r1, _08015488 @ =0x04000034
	ldr r3, _0801548C @ =0xFFFFFF00
	adds r0, r3, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _08015490 @ =0x04000036
	strh r2, [r0, #0x00]
	subs r0, #0x0E
	strh r5, [r0, #0x00]
	adds r0, #0x02
	strh r5, [r0, #0x00]
	adds r0, #0x02
	strh r5, [r0, #0x00]
	adds r0, #0x02
	strh r5, [r0, #0x00]
	adds r0, #0x0A
	strh r5, [r0, #0x00]
	adds r0, #0x02
	strh r5, [r0, #0x00]
	adds r0, #0x02
	strh r5, [r0, #0x00]
	adds r0, #0x02
	strh r5, [r0, #0x00]
	bl sub_0800F560
	bl sub_08010334
	bl sub_080102F0
	bl sub_08001170
	ldr r0, _08015494 @ =0x00007FFF
	bl sub_08003F4C
	ldr r0, _08015498 @ =0x0202EDD0
	strb r4, [r0, #0x00]
	ldr r1, _0801549C @ =0x0202A514
	movs r0, #0x60
	strb r0, [r1, #0x00]
	ldr r1, _080154A0 @ =0x0202CBDC
	movs r0, #0xB6
	strb r0, [r1, #0x00]
	ldr r1, _080154A4 @ =0x0202CAD4
	movs r0, #0xA0
	strb r0, [r1, #0x00]
	ldr r1, _080154A8 @ =0x0202CBC4
	movs r0, #0xFF
	strb r0, [r1, #0x00]
	ldr r1, _080154AC @ =0x0202A510
	ldr r0, _080154B0 @ =0x00008950
	str r0, [r1, #0x00]
	bl sub_08008338
	ldr r1, _080154B4 @ =0x020020D4
	ldr r0, _080154B8 @ =0x009F9AC4
	str r0, [r1, #0x00]
	ldr r4, _080154BC @ =0x0202A550
	movs r5, #0x00
	adds r7, r4, #0x0
	adds r7, #0x7D
	ldr r6, _080154C0 @ =0x02002184
	b _080154F2
	.global _08015470
_08015470: .4byte 0xFFFFFDFC
	.global _08015474
_08015474: .4byte 0x0202F030
	.global _08015478
_08015478: .4byte 0x020021C4
	.global _0801547C
_0801547C: .4byte 0x020020DC
	.global _08015480
_08015480: .4byte 0x0202EF20
	.global _08015484
_08015484: .4byte 0x04000020
	.global _08015488
_08015488: .4byte 0x04000034
	.global _0801548C
_0801548C: .4byte 0xFFFFFF00
	.global _08015490
_08015490: .4byte 0x04000036
	.global _08015494
_08015494: .4byte 0x00007FFF
	.global _08015498
_08015498: .4byte 0x0202EDD0
	.global _0801549C
_0801549C: .4byte 0x0202A514
	.global _080154A0
_080154A0: .4byte 0x0202CBDC
	.global _080154A4
_080154A4: .4byte 0x0202CAD4
	.global _080154A8
_080154A8: .4byte 0x0202CBC4
	.global _080154AC
_080154AC: .4byte 0x0202A510
	.global _080154B0
_080154B0: .4byte 0x00008950
	.global _080154B4
_080154B4: .4byte 0x020020D4
	.global _080154B8
_080154B8: .4byte 0x009F9AC4
	.global _080154BC
_080154BC: .4byte 0x0202A550
	.global _080154C0
_080154C0: .4byte 0x02002184
	.global _080154C4
_080154C4:
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r0, r4, r2
	str r5, [r0, #0x00]
	strb r1, [r7, #0x00]
	movs r0, #0x01
	bl sub_08016D28
	bl sub_08008A20
	bl sub_0800F3C0
	movs r0, #0x03
	strb r0, [r6, #0x00]
	ldr r0, _080156C8 @ =0x0202EEB0
	strb r5, [r0, #0x00]
	movs r0, #0x01
	movs r1, #0x00
	ldr r2, _080156CC @ =0x0202CDA8
	bl sub_0800295C
	bl sub_08015304
	.global _080154F2
_080154F2:
	bl sub_0801042C
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x01
	beq _080154C4
	movs r5, #0x00
	ldr r0, _080156D0 @ =0x0202A550
	movs r3, #0xB1
	lsls r3, r3, #0x01
	adds r4, r0, r3
	.global _08015508
_08015508:
	adds r0, r5, #0x0
	movs r1, #0x0C
	bl sub_080172C8
	strb r0, [r4, #0x00]
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r4, r4, r0
	adds r5, #0x01
	cmp r5, #0x18
	bne _08015508
	bl sub_0800F3A4
	movs r0, #0x00
	bl sub_08010664
	movs r0, #0x80
	lsls r0, r0, #0x13
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r1, r2, #0x0
	strh r1, [r0, #0x00]
	movs r0, #0x01
	mov r1, sp
	bl sub_08011C9C
	ldr r4, _080156D4 @ =0x0202EF00
	ldrb r0, [r4, #0x02]
	cmp r0, #0x00
	beq _0801554A
	movs r0, #0x02
	bl sub_08001208
	.global _0801554A
_0801554A:
	ldr r0, _080156D8 @ =0x0202EDD4
	ldrb r0, [r0, #0x00]
	bl sub_08010664
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r5, #0x00
	mov r10, r4
	ldr r3, _080156D0 @ =0x0202A550
	mov r8, r3
	.global _08015562
_08015562:
	cmp r5, #0x00
	beq _08015590
	movs r5, #0x00
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r4, #0xA8
	lsls r4, r4, #0x03
	adds r0, r4, #0x0
	strh r0, [r1, #0x00]
	movs r0, #0x01
	mov r1, sp
	bl sub_08011C9C
	bl sub_0800F3A4
	ldr r0, _080156D8 @ =0x0202EDD4
	ldrb r0, [r0, #0x00]
	bl sub_08010664
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	.global _08015590
_08015590:
	bl sub_0800048C
	ldr r0, _080156DC @ =0x020005C8
	ldr r1, _080156E0 @ =0x020005CC
	ldrh r2, [r1, #0x00]
	ldrh r0, [r0, #0x00]
	ands r2, r0
	str r2, [sp, #0x200]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0x00
	beq _080155CC
	ldr r4, _080156D8 @ =0x0202EDD4
	ldr r0, [r4, #0x00]
	subs r0, #0x01
	str r0, [r4, #0x00]
	cmp r0, #0x00
	bge _080155B8
	movs r0, #0x06
	str r0, [r4, #0x00]
	.global _080155B8
_080155B8:
	mov r3, r10
	ldrb r0, [r3, #0x03]
	cmp r0, #0x00
	beq _080155C6
	movs r0, #0x08
	bl sub_08001208
	.global _080155C6
_080155C6:
	ldrb r0, [r4, #0x00]
	bl sub_08010664
	.global _080155CC
_080155CC:
	movs r0, #0x80
	ldr r4, [sp, #0x200]
	ands r0, r4
	cmp r0, #0x00
	beq _080155FA
	ldr r4, _080156D8 @ =0x0202EDD4
	ldr r0, [r4, #0x00]
	adds r0, #0x01
	str r0, [r4, #0x00]
	cmp r0, #0x06
	ble _080155E6
	movs r0, #0x00
	str r0, [r4, #0x00]
	.global _080155E6
_080155E6:
	mov r1, r10
	ldrb r0, [r1, #0x03]
	cmp r0, #0x00
	beq _080155F4
	movs r0, #0x08
	bl sub_08001208
	.global _080155F4
_080155F4:
	ldrb r0, [r4, #0x00]
	bl sub_08010664
	.global _080155FA
_080155FA:
	ldr r1, _080156E4 @ =0x04000128
	movs r0, #0x30
	ldrb r2, [r1, #0x00]
	ands r0, r2
	cmp r0, #0x00
	bne _0801561E
	ldr r2, _080156E8 @ =0x0202ED78
	ldr r0, [r1, #0x00]
	lsls r0, r0, #0x1A
	lsrs r0, r0, #0x1E
	adds r0, #0x01
	lsls r0, r0, #0x0C
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldrh r0, [r2, #0x00]
	bl sub_0800F818
	.global _0801561E
_0801561E:
	ldr r0, _080156D8 @ =0x0202EDD4
	ldr r1, [r0, #0x00]
	adds r2, r0, #0x0
	cmp r1, #0x03
	beq _0801562A
	b _08015826
	.global _0801562A
_0801562A:
	movs r0, #0x09
	ldr r3, [sp, #0x200]
	ands r0, r3
	cmp r0, #0x00
	bne _08015636
	b _08015826
	.global _08015636
_08015636:
	ldr r0, _080156C8 @ =0x0202EEB0
	movs r6, #0x00
	strb r6, [r0, #0x00]
	ldr r7, _080156D4 @ =0x0202EF00
	ldrb r0, [r7, #0x03]
	cmp r0, #0x00
	beq _0801564A
	movs r0, #0x09
	bl sub_08001208
	.global _0801564A
_0801564A:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	ldr r0, _080156EC @ =0x0202EED4
	strb r6, [r0, #0x00]
	bl sub_08011FC4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x01
	beq _08015664
	b _080157EC
	.global _08015664
_08015664:
	bl sub_080122B4
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	cmp r4, #0x00
	bne _08015672
	b _080157AC
	.global _08015672
_08015672:
	ldr r1, _080156F0 @ =0x020020AC
	ldr r0, _080156F4 @ =0x0202EEF4
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	ldr r0, _080156F8 @ =0x020020DC
	strb r5, [r0, #0x00]
	ldr r0, _080156FC @ =0x020020CC
	strb r6, [r0, #0x00]
	.global _08015682
_08015682:
	bl sub_0801177C
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	movs r0, #0x02
	negs r0, r0
	cmp r4, r0
	bne _080156A2
	b _0801580E
	.global _080156A2
_080156A2:
	adds r0, #0x01
	cmp r4, r0
	beq _0801574E
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	.global _080156B0
_080156B0:
	bl sub_080107E0
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	beq _08015706
	cmp r0, #0x01
	bgt _08015700
	cmp r0, #0x00
	beq _08015718
	b _0801571E
	.byte 0x00, 0x00
	.global _080156C8
_080156C8: .4byte 0x0202EEB0
	.global _080156CC
_080156CC: .4byte 0x0202CDA8
	.global _080156D0
_080156D0: .4byte 0x0202A550
	.global _080156D4
_080156D4: .4byte 0x0202EF00
	.global _080156D8
_080156D8: .4byte 0x0202EDD4
	.global _080156DC
_080156DC: .4byte 0x020005C8
	.global _080156E0
_080156E0: .4byte 0x020005CC
	.global _080156E4
_080156E4: .4byte 0x04000128
	.global _080156E8
_080156E8: .4byte 0x0202ED78
	.global _080156EC
_080156EC: .4byte 0x0202EED4
	.global _080156F0
_080156F0: .4byte 0x020020AC
	.global _080156F4
_080156F4: .4byte 0x0202EEF4
	.global _080156F8
_080156F8: .4byte 0x020020DC
	.global _080156FC
_080156FC: .4byte 0x020020CC
	.global _08015700
_08015700:
	cmp r0, #0x02
	beq _0801574E
	b _0801571E
	.global _08015706
_08015706:
	ldr r0, _08015710 @ =0x020020CC
	ldr r1, _08015714 @ =0x0202EF8C
	ldrb r1, [r1, #0x00]
	strb r1, [r0, #0x00]
	b _0801571E
	.global _08015710
_08015710: .4byte 0x020020CC
	.global _08015714
_08015714: .4byte 0x0202EF8C
	.global _08015718
_08015718:
	bl sub_08000458
	b _08015682
	.global _0801571E
_0801571E:
	bl sub_08000458
	movs r0, #0x03
	ldr r4, _08015754 @ =0x02002184
	strb r0, [r4, #0x00]
	ldr r1, _08015758 @ =0x020020D4
	ldr r0, _0801575C @ =0x009F9AC4
	str r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r0, #0x00
	movs r1, #0x03
	ldr r2, _08015760 @ =0x0202CDC0
	bl sub_0800295C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08015764
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	.global _0801574E
_0801574E:
	bl sub_080164A8
	b _0801580E
	.global _08015754
_08015754: .4byte 0x02002184
	.global _08015758
_08015758: .4byte 0x020020D4
	.global _0801575C
_0801575C: .4byte 0x009F9AC4
	.global _08015760
_08015760: .4byte 0x0202CDC0
	.global _08015764
_08015764:
	movs r0, #0x02
	bl sub_08001208
	bl sub_08015304
	ldr r0, _080157A8 @ =0x020021BC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08015782
	bl sub_08011528
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x05
	beq _0801574E
	.global _08015782
_08015782:
	bl sub_0801164C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	beq _0801571E
	cmp r0, #0x01
	beq _080156B0
	cmp r0, #0x02
	bne _08015798
	b _08015682
	.global _08015798
_08015798:
	cmp r0, #0x04
	bne _080157A0
	bl _08016312
	.global _080157A0
_080157A0:
	cmp r0, #0x05
	bne _080157D0
	b _0801574E
	.byte 0x00, 0x00
	.global _080157A8
_080157A8: .4byte 0x020021BC
	.global _080157AC
_080157AC:
	ldrb r0, [r7, #0x02]
	cmp r0, #0x00
	beq _080157B8
	movs r0, #0x02
	bl sub_08001208
	.global _080157B8
_080157B8:
	bl sub_08015304
	ldr r0, _080157E0 @ =0x020020DC
	strb r4, [r0, #0x00]
	bl sub_08004484
	bl sub_080047DC
	ldr r0, _080157E4 @ =0x020020C0
	strb r4, [r0, #0x00]
	ldr r0, _080157E8 @ =0x020021C4
	strb r4, [r0, #0x00]
	.global _080157D0
_080157D0:
	mov r5, r10
	ldrb r0, [r5, #0x02]
	cmp r0, #0x00
	beq _0801581C
	movs r0, #0x02
	bl sub_08001208
	b _0801580E
	.global _080157E0
_080157E0: .4byte 0x020020DC
	.global _080157E4
_080157E4: .4byte 0x020020C0
	.global _080157E8
_080157E8: .4byte 0x020021C4
	.global _080157EC
_080157EC:
	cmp r5, #0x02
	bne _0801580E
	bl sub_08010074
	bl sub_08000458
	bl sub_08003738
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0801580E
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	bl sub_080100B0
	.global _0801580E
_0801580E:
	mov r1, r10
	ldrb r0, [r1, #0x02]
	cmp r0, #0x00
	beq _0801581C
	movs r0, #0x02
	bl sub_08001208
	.global _0801581C
_0801581C:
	ldr r0, _080158F4 @ =0x020020DC
	movs r2, #0x00
	strb r2, [r0, #0x00]
	movs r5, #0x01
	ldr r2, _080158F8 @ =0x0202EDD4
	.global _08015826
_08015826:
	ldr r1, [r2, #0x00]
	cmp r1, #0x00
	beq _0801582E
	b _08015AE0
	.global _0801582E
_0801582E:
	movs r0, #0x09
	ldr r3, [sp, #0x200]
	ands r0, r3
	cmp r0, #0x00
	bne _0801583A
	b _08015AE0
	.global _0801583A
_0801583A:
	ldr r0, _080158FC @ =0x0202EEB0
	strb r1, [r0, #0x00]
	mov r4, r10
	ldrb r0, [r4, #0x03]
	cmp r0, #0x00
	beq _0801584C
	movs r0, #0x09
	bl sub_08001208
	.global _0801584C
_0801584C:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r5, #0x00
	ldr r0, _08015900 @ =0x0202A550
	movs r2, #0x00
	movs r1, #0xB2
	lsls r1, r1, #0x01
	adds r0, r0, r1
	adds r1, #0x2C
	.global _08015862
_08015862:
	strh r2, [r0, #0x00]
	adds r0, r0, r1
	adds r5, #0x01
	cmp r5, #0x18
	bne _08015862
	bl sub_08010EA0
	ldr r2, _08015904 @ =0x0202A6B2
	strb r0, [r2, #0x00]
	bl sub_08008A20
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r0, #0x02
	ldr r3, _08015908 @ =0x020005CC
	ldrh r3, [r3, #0x00]
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x00
	beq _08015892
	b _08015ADC
	.global _08015892
_08015892:
	ldr r0, _0801590C @ =0x0202F024
	strb r1, [r0, #0x00]
	ldr r0, _08015910 @ =0x0202EEC8
	strb r1, [r0, #0x00]
	ldr r0, _08015914 @ =0x0202F034
	strb r1, [r0, #0x00]
	ldr r0, _08015918 @ =0x0202F020
	strb r1, [r0, #0x00]
	.global _080158A2
_080158A2:
	ldr r6, _0801590C @ =0x0202F024
	ldr r7, _08015914 @ =0x0202F034
	ldrb r1, [r7, #0x00]
	ldrb r0, [r6, #0x00]
	orrs r0, r1
	ldr r4, _08015910 @ =0x0202EEC8
	mov r9, r4
	ldrb r5, [r4, #0x00]
	orrs r1, r5
	bl sub_080136F8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r3, #0x02
	movs r0, #0x02
	ldr r2, _08015908 @ =0x020005CC
	ldrh r2, [r2, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _080158CC
	b _08015ADC
	.global _080158CC
_080158CC:
	cmp r1, #0x03
	bne _080158D2
	b _08015ADC
	.global _080158D2
_080158D2:
	ldr r2, _0801591C @ =0x0202EEF8
	strb r1, [r2, #0x00]
	ldr r5, _08015920 @ =0x020020CC
	ldr r0, _08015924 @ =0x083FDE1C
	ldr r1, _08015918 @ =0x0202F020
	ldrb r1, [r1, #0x00]
	adds r0, r1, r0
	ldrb r0, [r0, #0x00]
	strb r0, [r5, #0x00]
	ldrb r4, [r2, #0x00]
	cmp r4, #0x01
	beq _080159A4
	cmp r4, #0x01
	bgt _08015928
	cmp r4, #0x00
	beq _0801592E
	b _08015AC6
	.global _080158F4
_080158F4: .4byte 0x020020DC
	.global _080158F8
_080158F8: .4byte 0x0202EDD4
	.global _080158FC
_080158FC: .4byte 0x0202EEB0
	.global _08015900
_08015900: .4byte 0x0202A550
	.global _08015904
_08015904: .4byte 0x0202A6B2
	.global _08015908
_08015908: .4byte 0x020005CC
	.global _0801590C
_0801590C: .4byte 0x0202F024
	.global _08015910
_08015910: .4byte 0x0202EEC8
	.global _08015914
_08015914: .4byte 0x0202F034
	.global _08015918
_08015918: .4byte 0x0202F020
	.global _0801591C
_0801591C: .4byte 0x0202EEF8
	.global _08015920
_08015920: .4byte 0x020020CC
	.global _08015924
_08015924: .4byte 0x083FDE1C
	.global _08015928
_08015928:
	cmp r4, #0x02
	beq _08015A08
	b _08015AC6
	.global _0801592E
_0801592E:
	movs r0, #0x0A
	ldr r3, _08015990 @ =0x02002184
	strb r0, [r3, #0x00]
	movs r0, #0xB6
	lsls r0, r0, #0x01
	add r0, r8
	str r4, [r0, #0x00]
	mov r0, r8
	adds r0, #0x7D
	movs r6, #0x01
	strb r6, [r0, #0x00]
	movs r0, #0x01
	bl sub_08016D28
	bl sub_0800F3C0
	ldr r0, _08015994 @ =0x0202EFC0
	mov r1, r8
	str r1, [r0, #0x00]
	ldr r0, _08015998 @ =0x0202EEB0
	strb r4, [r0, #0x00]
	ldrb r1, [r5, #0x00]
	movs r0, #0x00
	bl sub_08011168
	movs r0, #0x00
	movs r1, #0x0E
	ldr r2, _0801599C @ =0x0202CD9C
	bl sub_0800295C
	mov r2, r10
	ldrb r0, [r2, #0x02]
	cmp r0, #0x00
	beq _08015978
	movs r0, #0x02
	bl sub_08001208
	.global _08015978
_08015978:
	bl sub_08015304
	ldr r0, _080159A0 @ =0x020020F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08015988
	bl sub_08016834
	.global _08015988
_08015988:
	mov r3, r9
	strb r6, [r3, #0x00]
	b _08015AC6
	.byte 0x00, 0x00
	.global _08015990
_08015990: .4byte 0x02002184
	.global _08015994
_08015994: .4byte 0x0202EFC0
	.global _08015998
_08015998: .4byte 0x0202EEB0
	.global _0801599C
_0801599C: .4byte 0x0202CD9C
	.global _080159A0
_080159A0: .4byte 0x020020F0
	.global _080159A4
_080159A4:
	ldr r0, _080159F4 @ =0x02002184
	strb r3, [r0, #0x00]
	ldr r0, _080159F8 @ =0x0202EFC0
	mov r1, r8
	str r1, [r0, #0x00]
	movs r1, #0xB6
	lsls r1, r1, #0x01
	add r1, r8
	ldr r0, _080159FC @ =0x0002BF20
	str r0, [r1, #0x00]
	ldrb r1, [r5, #0x00]
	movs r0, #0x00
	bl sub_08011168
	movs r0, #0x00
	movs r1, #0x11
	ldr r2, _08015A00 @ =0x0202CDA8
	bl sub_0800295C
	mov r2, r10
	ldrb r0, [r2, #0x02]
	cmp r0, #0x00
	beq _080159D8
	movs r0, #0x03
	bl sub_08001208
	.global _080159D8
_080159D8:
	bl sub_08015304
	bl sub_08016CB0
	ldr r0, _08015A04 @ =0x020020F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080159EC
	bl sub_08016834
	.global _080159EC
_080159EC:
	strb r4, [r6, #0x00]
	bl sub_08013D5C
	b _08015AC6
	.global _080159F4
_080159F4: .4byte 0x02002184
	.global _080159F8
_080159F8: .4byte 0x0202EFC0
	.global _080159FC
_080159FC: .4byte 0x0002BF20
	.global _08015A00
_08015A00: .4byte 0x0202CDA8
	.global _08015A04
_08015A04: .4byte 0x020020F0
	.global _08015A08
_08015A08:
	ldrb r0, [r6, #0x00]
	cmp r0, #0x00
	beq _08015A14
	ldrb r7, [r7, #0x00]
	cmp r7, #0x01
	bne _08015A22
	.global _08015A14
_08015A14:
	movs r1, #0xB6
	lsls r1, r1, #0x01
	add r1, r8
	ldr r0, _08015A94 @ =0x0002BF20
	str r0, [r1, #0x00]
	bl sub_08016CB0
	.global _08015A22
_08015A22:
	bl sub_0800F3C0
	movs r0, #0x03
	ldr r3, _08015A98 @ =0x02002184
	strb r0, [r3, #0x00]
	ldr r0, _08015A9C @ =0x083FDA6E
	mov r4, r10
	ldrb r4, [r4, #0x01]
	adds r0, r4, r0
	ldrb r0, [r0, #0x00]
	strb r0, [r3, #0x00]
	ldr r0, _08015AA0 @ =0x020020CC
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	bl sub_08011168
	movs r0, #0x00
	movs r1, #0x09
	ldr r2, _08015AA4 @ =0x0202CDA8
	bl sub_0800295C
	mov r5, r10
	ldrb r0, [r5, #0x02]
	cmp r0, #0x00
	beq _08015A5A
	movs r0, #0x02
	bl sub_08001208
	.global _08015A5A
_08015A5A:
	bl sub_08015304
	ldr r0, _08015AA8 @ =0x020021BC
	ldrb r1, [r0, #0x00]
	cmp r1, #0x00
	bne _08015AC0
	ldr r0, _08015AAC @ =0x0202F024
	strb r1, [r0, #0x00]
	ldr r0, _08015AB0 @ =0x0202EEC8
	strb r1, [r0, #0x00]
	ldr r0, _08015AB4 @ =0x0202F034
	strb r1, [r0, #0x00]
	ldr r0, _08015AB8 @ =0x020020F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08015A7E
	bl sub_08016834
	.global _08015A7E
_08015A7E:
	bl sub_08014004
	bl sub_080140D8
	bl sub_08014278
	ldr r1, _08015ABC @ =0x0202F020
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	b _08015AC4
	.byte 0x00, 0x00
	.global _08015A94
_08015A94: .4byte 0x0002BF20
	.global _08015A98
_08015A98: .4byte 0x02002184
	.global _08015A9C
_08015A9C: .4byte 0x083FDA6E
	.global _08015AA0
_08015AA0: .4byte 0x020020CC
	.global _08015AA4
_08015AA4: .4byte 0x0202CDA8
	.global _08015AA8
_08015AA8: .4byte 0x020021BC
	.global _08015AAC
_08015AAC: .4byte 0x0202F024
	.global _08015AB0
_08015AB0: .4byte 0x0202EEC8
	.global _08015AB4
_08015AB4: .4byte 0x0202F034
	.global _08015AB8
_08015AB8: .4byte 0x020020F0
	.global _08015ABC
_08015ABC: .4byte 0x0202F020
	.global _08015AC0
_08015AC0:
	ldr r1, _08015E14 @ =0x0202F034
	movs r0, #0x01
	.global _08015AC4
_08015AC4:
	strb r0, [r1, #0x00]
	.global _08015AC6
_08015AC6:
	ldr r0, _08015E18 @ =0x0202F020
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0B
	beq _08015AD0
	b _080158A2
	.global _08015AD0
_08015AD0:
	bl sub_08012C20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_08012D34
	.global _08015ADC
_08015ADC:
	movs r5, #0x01
	ldr r2, _08015E1C @ =0x0202EDD4
	.global _08015AE0
_08015AE0:
	ldr r1, [r2, #0x00]
	cmp r1, #0x01
	beq _08015AE8
	b _08015C10
	.global _08015AE8
_08015AE8:
	movs r0, #0x09
	ldr r3, [sp, #0x200]
	ands r0, r3
	cmp r0, #0x00
	bne _08015AF4
	b _08015C10
	.global _08015AF4
_08015AF4:
	ldr r2, _08015E20 @ =0x0202EEB0
	movs r4, #0x00
	strb r4, [r2, #0x00]
	mov r5, r10
	ldrb r0, [r5, #0x04]
	ldr r6, _08015E24 @ =0x0202EF00
	cmp r0, #0x00
	beq _08015B06
	strb r1, [r2, #0x00]
	.global _08015B06
_08015B06:
	movs r5, #0x00
	ldr r0, _08015E28 @ =0x0202A550
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r4, r0, r1
	.global _08015B10
_08015B10:
	adds r0, r5, #0x0
	movs r1, #0x0C
	bl sub_080172C8
	strb r0, [r4, #0x00]
	movs r2, #0xC8
	lsls r2, r2, #0x01
	adds r4, r4, r2
	adds r5, #0x01
	cmp r5, #0x18
	bne _08015B10
	ldrb r0, [r6, #0x03]
	cmp r0, #0x00
	beq _08015B32
	movs r0, #0x09
	bl sub_08001208
	.global _08015B32
_08015B32:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	.global _08015B3A
_08015B3A:
	bl sub_08010EA0
	ldr r3, _08015E2C @ =0x0202A6B2
	strb r0, [r3, #0x00]
	bl sub_08008A20
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r0, #0x02
	ldr r4, _08015E30 @ =0x020005CC
	ldrh r4, [r4, #0x00]
	ands r0, r4
	cmp r0, #0x00
	bne _08015C0C
	.global _08015B5A
_08015B5A:
	movs r0, #0x01
	movs r1, #0x00
	bl sub_08011168
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r0, #0x02
	ldr r5, _08015E30 @ =0x020005CC
	ldrh r5, [r5, #0x00]
	ands r0, r5
	cmp r0, #0x00
	bne _08015C0C
	ldr r1, _08015E34 @ =0x020020CC
	ldr r0, _08015E38 @ =0x0202EF8C
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	ldr r0, _08015E3C @ =0x083FDA6E
	mov r1, r10
	ldrb r1, [r1, #0x01]
	adds r0, r1, r0
	ldrb r0, [r0, #0x00]
	ldr r2, _08015E40 @ =0x02002184
	strb r0, [r2, #0x00]
	.global _08015B8C
_08015B8C:
	movs r4, #0xB6
	lsls r4, r4, #0x01
	add r4, r8
	movs r3, #0x00
	str r3, [r4, #0x00]
	mov r1, r8
	adds r1, #0x7D
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bl sub_08016D28
	movs r5, #0x00
	ldr r1, _08015E44 @ =0xFFFFFE94
	adds r0, r4, r1
	movs r1, #0xC8
	lsls r1, r1, #0x01
	.global _08015BAC
_08015BAC:
	str r5, [r4, #0x00]
	adds r4, r4, r1
	adds r5, #0x01
	cmp r5, #0x18
	bne _08015BAC
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r1, r0, r2
	ldr r0, _08015E48 @ =0x0002CAD8
	str r0, [r1, #0x00]
	bl sub_0800F3C0
	movs r0, #0x00
	movs r1, #0x09
	ldr r2, _08015E4C @ =0x0202CDA8
	bl sub_0800295C
	ldr r0, _08015E50 @ =0x020020F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08015BDA
	bl sub_08016834
	.global _08015BDA
_08015BDA:
	mov r3, r10
	ldrb r0, [r3, #0x02]
	cmp r0, #0x00
	beq _08015BE8
	movs r0, #0x02
	bl sub_08001208
	.global _08015BE8
_08015BE8:
	bl sub_08015304
	ldr r0, _08015E54 @ =0x020021BC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08015BF8
	bl sub_08014E28
	.global _08015BF8
_08015BF8:
	bl sub_08014F5C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	beq _08015B8C
	cmp r0, #0x01
	beq _08015B5A
	cmp r0, #0x02
	beq _08015B3A
	.global _08015C0C
_08015C0C:
	movs r5, #0x01
	ldr r2, _08015E1C @ =0x0202EDD4
	.global _08015C10
_08015C10:
	ldr r0, [r2, #0x00]
	cmp r0, #0x04
	bne _08015CF4
	movs r0, #0x09
	ldr r4, [sp, #0x200]
	ands r0, r4
	cmp r0, #0x00
	beq _08015CF4
	ldr r0, _08015E20 @ =0x0202EEB0
	movs r5, #0x00
	strb r5, [r0, #0x00]
	mov r1, r10
	ldrb r0, [r1, #0x03]
	cmp r0, #0x00
	beq _08015C34
	movs r0, #0x09
	bl sub_08001208
	.global _08015C34
_08015C34:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	.global _08015C3C
_08015C3C:
	bl sub_08010EA0
	ldr r2, _08015E2C @ =0x0202A6B2
	strb r0, [r2, #0x00]
	bl sub_08008A20
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r0, #0x02
	ldr r3, _08015E30 @ =0x020005CC
	ldrh r3, [r3, #0x00]
	ands r0, r3
	cmp r0, #0x00
	bne _08015CF0
	.global _08015C5C
_08015C5C:
	movs r0, #0x01
	movs r1, #0x00
	bl sub_08011168
	ldr r5, _08015E34 @ =0x020020CC
	ldr r4, _08015E38 @ =0x0202EF8C
	ldrb r0, [r4, #0x00]
	strb r0, [r5, #0x00]
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r0, #0x02
	ldr r1, _08015E30 @ =0x020005CC
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08015CF0
	ldrb r0, [r4, #0x00]
	strb r0, [r5, #0x00]
	movs r0, #0x03
	ldr r2, _08015E40 @ =0x02002184
	strb r0, [r2, #0x00]
	.global _08015C8A
_08015C8A:
	movs r0, #0xB6
	lsls r0, r0, #0x01
	add r0, r8
	movs r3, #0x00
	str r3, [r0, #0x00]
	mov r0, r8
	adds r0, #0x7D
	movs r5, #0x01
	strb r5, [r0, #0x00]
	movs r0, #0x01
	bl sub_08016D28
	bl sub_0800F3C0
	ldr r0, _08015E58 @ =0x0202EFC0
	mov r4, r8
	str r4, [r0, #0x00]
	ldr r4, _08015E5C @ =0x0202F030
	strb r5, [r4, #0x00]
	movs r0, #0x00
	movs r1, #0x0E
	ldr r2, _08015E60 @ =0x0202CD9C
	bl sub_0800295C
	movs r5, #0x00
	strb r5, [r4, #0x00]
	mov r1, r10
	ldrb r0, [r1, #0x02]
	cmp r0, #0x00
	beq _08015CCC
	movs r0, #0x02
	bl sub_08001208
	.global _08015CCC
_08015CCC:
	bl sub_08015304
	ldr r0, _08015E50 @ =0x020020F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08015CDC
	bl sub_08016834
	.global _08015CDC
_08015CDC:
	bl sub_080144F4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	beq _08015C8A
	cmp r0, #0x01
	beq _08015C5C
	cmp r0, #0x02
	beq _08015C3C
	.global _08015CF0
_08015CF0:
	movs r5, #0x01
	ldr r2, _08015E1C @ =0x0202EDD4
	.global _08015CF4
_08015CF4:
	ldr r0, [r2, #0x00]
	cmp r0, #0x02
	beq _08015CFC
	b _08015F22
	.global _08015CFC
_08015CFC:
	movs r0, #0x09
	ldr r3, [sp, #0x200]
	ands r0, r3
	cmp r0, #0x00
	bne _08015D08
	b _08015F22
	.global _08015D08
_08015D08:
	mov r4, r10
	ldrb r0, [r4, #0x03]
	cmp r0, #0x00
	beq _08015D16
	movs r0, #0x09
	bl sub_08001208
	.global _08015D16
_08015D16:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	.global _08015D1E
_08015D1E:
	bl sub_0801465C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r9, r0
	movs r0, #0x02
	ldr r5, _08015E30 @ =0x020005CC
	ldrh r5, [r5, #0x00]
	ands r0, r5
	cmp r0, #0x00
	beq _08015D36
	b _08015F1E
	.global _08015D36
_08015D36:
	ldr r1, _08015E64 @ =0x0202ED70
	mov r2, r9
	lsls r0, r2, #0x02
	strb r0, [r1, #0x00]
	.global _08015D3E
_08015D3E:
	ldr r7, _08015E68 @ =0x0202EF60
	ldr r5, _08015E64 @ =0x0202ED70
	ldrb r3, [r5, #0x00]
	adds r2, r3, r7
	movs r1, #0x00
	ldsb r1, [r2, r1]
	movs r4, #0xFF
	lsls r4, r4, #0x18
	asrs r0, r4, #0x18
	cmp r1, r0
	bne _08015D5C
	movs r0, #0x00
	strb r0, [r2, #0x00]
	bl sub_0801692C
	.global _08015D5C
_08015D5C:
	ldrb r1, [r5, #0x00]
	mov r0, r9
	bl sub_08014874
	strb r0, [r5, #0x00]
	movs r0, #0x02
	ldr r1, _08015E30 @ =0x020005CC
	ldrh r1, [r1, #0x00]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x00
	bne _08015D1E
	ldr r6, _08015E6C @ =0x02002098
	strb r4, [r6, #0x00]
	ldr r1, _08015E34 @ =0x020020CC
	ldr r0, _08015E70 @ =0x083FDE2D
	ldrb r2, [r5, #0x00]
	adds r0, r2, r0
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	ldrb r0, [r5, #0x00]
	bl sub_0800F8D0
	ldr r1, _08015E20 @ =0x0202EEB0
	movs r2, #0x01
	strb r2, [r1, #0x00]
	ldrb r0, [r5, #0x00]
	cmp r0, #0x01
	bne _08015D9A
	strb r4, [r1, #0x00]
	.global _08015D9A
_08015D9A:
	cmp r0, #0x06
	bne _08015DA0
	strb r4, [r1, #0x00]
	.global _08015DA0
_08015DA0:
	cmp r0, #0x0A
	bne _08015DA6
	strb r4, [r1, #0x00]
	.global _08015DA6
_08015DA6:
	cmp r0, #0x0E
	bne _08015DAC
	strb r4, [r1, #0x00]
	.global _08015DAC
_08015DAC:
	movs r0, #0x00
	movs r1, #0x0F
	ldr r2, _08015E4C @ =0x0202CDA8
	bl sub_0800295C
	ldr r0, _08015E74 @ =0x0202EEE4
	ldrb r0, [r0, #0x00]
	strb r0, [r6, #0x00]
	mov r3, r10
	ldrb r0, [r3, #0x02]
	cmp r0, #0x00
	beq _08015DCA
	movs r0, #0x02
	bl sub_08001208
	.global _08015DCA
_08015DCA:
	bl sub_08015304
	ldrb r0, [r6, #0x00]
	cmp r0, #0x00
	bne _08015DD6
	b _08015EEC
	.global _08015DD6
_08015DD6:
	ldrb r2, [r5, #0x00]
	movs r1, #0x00
	adds r0, r2, r7
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r4, [r6, #0x00]
	cmp r0, r4
	blt _08015DEA
	movs r1, #0x01
	.global _08015DEA
_08015DEA:
	adds r0, r2, #0x0
	bl sub_08012B50
	ldrb r2, [r6, #0x00]
	ldrb r0, [r5, #0x00]
	adds r1, r0, r7
	movs r0, #0x00
	ldsb r0, [r1, r0]
	cmp r2, r0
	ble _08015E04
	strb r2, [r1, #0x00]
	bl sub_0801692C
	.global _08015E04
_08015E04:
	ldrb r0, [r5, #0x00]
	adds r0, #0x01
	strb r0, [r5, #0x00]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x04
	b _08015E78
	.byte 0x00, 0x00
	.global _08015E14
_08015E14: .4byte 0x0202F034
	.global _08015E18
_08015E18: .4byte 0x0202F020
	.global _08015E1C
_08015E1C: .4byte 0x0202EDD4
	.global _08015E20
_08015E20: .4byte 0x0202EEB0
	.global _08015E24
_08015E24: .4byte 0x0202EF00
	.global _08015E28
_08015E28: .4byte 0x0202A550
	.global _08015E2C
_08015E2C: .4byte 0x0202A6B2
	.global _08015E30
_08015E30: .4byte 0x020005CC
	.global _08015E34
_08015E34: .4byte 0x020020CC
	.global _08015E38
_08015E38: .4byte 0x0202EF8C
	.global _08015E3C
_08015E3C: .4byte 0x083FDA6E
	.global _08015E40
_08015E40: .4byte 0x02002184
	.global _08015E44
_08015E44: .4byte 0xFFFFFE94
	.global _08015E48
_08015E48: .4byte 0x0002CAD8
	.global _08015E4C
_08015E4C: .4byte 0x0202CDA8
	.global _08015E50
_08015E50: .4byte 0x020020F0
	.global _08015E54
_08015E54: .4byte 0x020021BC
	.global _08015E58
_08015E58: .4byte 0x0202EFC0
	.global _08015E5C
_08015E5C: .4byte 0x0202F030
	.global _08015E60
_08015E60: .4byte 0x0202CD9C
	.global _08015E64
_08015E64: .4byte 0x0202ED70
	.global _08015E68
_08015E68: .4byte 0x0202EF60
	.global _08015E6C
_08015E6C: .4byte 0x02002098
	.global _08015E70
_08015E70: .4byte 0x083FDE2D
	.global _08015E74
_08015E74: .4byte 0x0202EEE4
	.global _08015E78
_08015E78:
	bne _08015E90
	ldr r1, _08015E8C @ =0x0202EF08
	ldrb r0, [r1, #0x01]
	cmp r0, #0x00
	beq _08015E84
	b _08015D1E
	.global _08015E84
_08015E84:
	movs r0, #0x01
	strb r0, [r1, #0x01]
	b _08015EDC
	.byte 0x00, 0x00
	.global _08015E8C
_08015E8C: .4byte 0x0202EF08
	.global _08015E90
_08015E90:
	cmp r1, #0x08
	bne _08015EAC
	ldr r1, _08015EA8 @ =0x0202EF08
	ldrb r0, [r1, #0x02]
	cmp r0, #0x00
	beq _08015E9E
	b _08015D1E
	.global _08015E9E
_08015E9E:
	movs r0, #0x01
	strb r0, [r1, #0x02]
	movs r0, #0x02
	b _08015EDC
	.byte 0x00, 0x00
	.global _08015EA8
_08015EA8: .4byte 0x0202EF08
	.global _08015EAC
_08015EAC:
	cmp r1, #0x0C
	bne _08015EC8
	ldr r1, _08015EC4 @ =0x0202EF08
	ldrb r0, [r1, #0x03]
	cmp r0, #0x00
	beq _08015EBA
	b _08015D1E
	.global _08015EBA
_08015EBA:
	movs r0, #0x01
	strb r0, [r1, #0x03]
	movs r0, #0x03
	b _08015EDC
	.byte 0x00, 0x00
	.global _08015EC4
_08015EC4: .4byte 0x0202EF08
	.global _08015EC8
_08015EC8:
	cmp r1, #0x10
	bne _08015EF4
	ldr r1, _08015EE8 @ =0x0202EF08
	ldrb r0, [r1, #0x04]
	cmp r0, #0x00
	beq _08015ED6
	b _08015D1E
	.global _08015ED6
_08015ED6:
	movs r0, #0x01
	strb r0, [r1, #0x04]
	movs r0, #0x04
	.global _08015EDC
_08015EDC:
	bl sub_080129E8
	bl sub_0801692C
	b _08015D1E
	.byte 0x00, 0x00
	.global _08015EE8
_08015EE8: .4byte 0x0202EF08
	.global _08015EEC
_08015EEC:
	ldrb r0, [r5, #0x00]
	bl sub_08012BBC
	b _08015D3E
	.global _08015EF4
_08015EF4:
	ldrb r0, [r6, #0x00]
	cmp r0, #0x00
	beq _08015F1E
	cmp r1, #0x04
	beq _08015F0C
	cmp r1, #0x08
	beq _08015F0C
	cmp r1, #0x0C
	beq _08015F0C
	cmp r1, #0x10
	beq _08015F0C
	b _08015D3E
	.global _08015F0C
_08015F0C:
	ldr r1, _08015FA4 @ =0x0202EF08
	ldr r0, _08015FA8 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	lsrs r0, r0, #0x02
	adds r0, r0, r1
	movs r1, #0x01
	strb r1, [r0, #0x00]
	bl sub_08016A04
	.global _08015F1E
_08015F1E:
	movs r5, #0x01
	ldr r2, _08015FAC @ =0x0202EDD4
	.global _08015F22
_08015F22:
	ldr r0, [r2, #0x00]
	cmp r0, #0x05
	beq _08015F2A
	b _080162C8
	.global _08015F2A
_08015F2A:
	movs r0, #0x09
	ldr r1, [sp, #0x200]
	ands r0, r1
	cmp r0, #0x00
	bne _08015F36
	b _080162C8
	.global _08015F36
_08015F36:
	ldr r1, _08015FB0 @ =0x0202EF10
	ldr r0, _08015FB4 @ =0x083FDA6E
	mov r2, r10
	ldrb r2, [r2, #0x01]
	adds r0, r2, r0
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	ldr r1, _08015FB8 @ =0x0202EEB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	mov r3, r10
	ldrb r0, [r3, #0x03]
	cmp r0, #0x00
	beq _08015F58
	movs r0, #0x09
	bl sub_08001208
	.global _08015F58
_08015F58:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r5, #0x00
	ldr r0, _08015FBC @ =0x0202A550
	movs r2, #0x00
	movs r4, #0xB2
	lsls r4, r4, #0x01
	adds r0, r0, r4
	movs r1, #0xC8
	lsls r1, r1, #0x01
	.global _08015F70
_08015F70:
	strh r2, [r0, #0x00]
	adds r0, r0, r1
	adds r5, #0x01
	cmp r5, #0x18
	bne _08015F70
	bl sub_08016634
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08015FC4
	bl sub_08014A84
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r0, #0x02
	ldr r5, _08015FC0 @ =0x020005CC
	ldrh r5, [r5, #0x00]
	ands r0, r5
	cmp r0, #0x00
	beq _08015F9A
	b _080162C4
	.global _08015F9A
_08015F9A:
	cmp r1, #0x01
	bne _08015FC4
	bl sub_08016724
	b _0801606A
	.global _08015FA4
_08015FA4: .4byte 0x0202EF08
	.global _08015FA8
_08015FA8: .4byte 0x0202ED70
	.global _08015FAC
_08015FAC: .4byte 0x0202EDD4
	.global _08015FB0
_08015FB0: .4byte 0x0202EF10
	.global _08015FB4
_08015FB4: .4byte 0x083FDA6E
	.global _08015FB8
_08015FB8: .4byte 0x0202EEB0
	.global _08015FBC
_08015FBC: .4byte 0x0202A550
	.global _08015FC0
_08015FC0: .4byte 0x020005CC
	.global _08015FC4
_08015FC4:
	movs r5, #0x00
	ldr r0, _08015FF4 @ =0x0202A550
	movs r2, #0x00
	movs r3, #0xB2
	lsls r3, r3, #0x01
	adds r1, r0, r3
	movs r0, #0xC8
	lsls r0, r0, #0x01
	.global _08015FD4
_08015FD4:
	strh r2, [r1, #0x00]
	adds r1, r1, r0
	adds r5, #0x01
	cmp r5, #0x18
	bne _08015FD4
	bl sub_0800F190
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08016004
	ldr r0, _08015FF8 @ =0x0829F590
	ldr r1, _08015FFC @ =0x0829F59C
	ldr r2, _08016000 @ =0x0829F5B4
	bl sub_08012A80
	b _080162C4
	.global _08015FF4
_08015FF4: .4byte 0x0202A550
	.global _08015FF8
_08015FF8: .4byte 0x0829F590
	.global _08015FFC
_08015FFC: .4byte 0x0829F59C
	.global _08016000
_08016000: .4byte 0x0829F5B4
	.global _08016004
_08016004:
	bl sub_08010CD0
	ldr r1, _080160BC @ =0x0202EDD8
	strb r0, [r1, #0x00]
	movs r0, #0x02
	ldr r4, _080160C0 @ =0x020005CC
	ldrh r4, [r4, #0x00]
	ands r0, r4
	cmp r0, #0x00
	beq _0801601A
	b _080162C4
	.global _0801601A
_0801601A:
	ldrb r0, [r1, #0x00]
	bl sub_0800F120
	ldr r5, _080160C4 @ =0x0202A6B2
	strb r0, [r5, #0x00]
	ldrb r0, [r5, #0x00]
	bl sub_080128E0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08015FC4
	.global _08016030
_08016030:
	ldr r0, _080160BC @ =0x0202EDD8
	ldrb r0, [r0, #0x00]
	bl sub_0800F120
	ldr r1, _080160C4 @ =0x0202A6B2
	strb r0, [r1, #0x00]
	bl sub_08008A20
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r0, #0x02
	ldr r2, _080160C0 @ =0x020005CC
	ldrh r2, [r2, #0x00]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x00
	beq _0801605A
	b _080162C4
	.global _0801605A
_0801605A:
	ldr r0, _080160C8 @ =0x0202F024
	strb r1, [r0, #0x00]
	ldr r0, _080160CC @ =0x0202EEC8
	strb r1, [r0, #0x00]
	ldr r0, _080160D0 @ =0x0202F034
	strb r1, [r0, #0x00]
	ldr r0, _080160D4 @ =0x0202F020
	strb r1, [r0, #0x00]
	.global _0801606A
_0801606A:
	ldr r4, _080160C8 @ =0x0202F024
	ldr r7, _080160D0 @ =0x0202F034
	ldrb r1, [r7, #0x00]
	ldrb r0, [r4, #0x00]
	orrs r0, r1
	ldr r3, _080160CC @ =0x0202EEC8
	mov r9, r3
	ldrb r5, [r3, #0x00]
	orrs r1, r5
	bl sub_08013570
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r3, #0x02
	movs r0, #0x02
	ldr r2, _080160C0 @ =0x020005CC
	ldrh r2, [r2, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _08016094
	b _080162C4
	.global _08016094
_08016094:
	cmp r1, #0x04
	bne _0801609A
	b _080162C4
	.global _0801609A
_0801609A:
	ldr r2, _080160D8 @ =0x0202EEF8
	strb r1, [r2, #0x00]
	ldr r6, _080160DC @ =0x020020CC
	ldr r0, _080160E0 @ =0x083FDE1C
	ldr r1, _080160D4 @ =0x0202F020
	ldrb r1, [r1, #0x00]
	adds r0, r1, r0
	ldrb r0, [r0, #0x00]
	strb r0, [r6, #0x00]
	ldrb r5, [r2, #0x00]
	cmp r5, #0x01
	beq _0801615C
	cmp r5, #0x01
	bgt _080160E4
	cmp r5, #0x00
	beq _080160F0
	b _08016280
	.global _080160BC
_080160BC: .4byte 0x0202EDD8
	.global _080160C0
_080160C0: .4byte 0x020005CC
	.global _080160C4
_080160C4: .4byte 0x0202A6B2
	.global _080160C8
_080160C8: .4byte 0x0202F024
	.global _080160CC
_080160CC: .4byte 0x0202EEC8
	.global _080160D0
_080160D0: .4byte 0x0202F034
	.global _080160D4
_080160D4: .4byte 0x0202F020
	.global _080160D8
_080160D8: .4byte 0x0202EEF8
	.global _080160DC
_080160DC: .4byte 0x020020CC
	.global _080160E0
_080160E0: .4byte 0x083FDE1C
	.global _080160E4
_080160E4:
	cmp r5, #0x02
	beq _080161C0
	cmp r5, #0x03
	bne _080160EE
	b _0801627C
	.global _080160EE
_080160EE:
	b _08016280
	.global _080160F0
_080160F0:
	movs r0, #0xB6
	lsls r0, r0, #0x01
	add r0, r8
	str r5, [r0, #0x00]
	mov r0, r8
	adds r0, #0x7D
	movs r7, #0x01
	strb r7, [r0, #0x00]
	movs r0, #0x01
	bl sub_08016D28
	bl sub_0800F3C0
	ldr r0, _0801614C @ =0x0202EFC0
	mov r3, r8
	str r3, [r0, #0x00]
	ldr r4, _08016150 @ =0x0202EEB0
	strb r5, [r4, #0x00]
	ldrb r1, [r6, #0x00]
	movs r0, #0x00
	bl sub_08011168
	movs r0, #0x00
	movs r1, #0x0E
	ldr r2, _08016154 @ =0x0202CD9C
	bl sub_0800295C
	strb r7, [r4, #0x00]
	mov r4, r10
	ldrb r0, [r4, #0x02]
	cmp r0, #0x00
	beq _08016136
	movs r0, #0x02
	bl sub_08001208
	.global _08016136
_08016136:
	bl sub_08015304
	ldr r0, _08016158 @ =0x020020F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08016146
	bl sub_08016834
	.global _08016146
_08016146:
	mov r5, r9
	strb r7, [r5, #0x00]
	b _08016280
	.global _0801614C
_0801614C: .4byte 0x0202EFC0
	.global _08016150
_08016150: .4byte 0x0202EEB0
	.global _08016154
_08016154: .4byte 0x0202CD9C
	.global _08016158
_08016158: .4byte 0x020020F0
	.global _0801615C
_0801615C:
	ldr r0, _080161AC @ =0x02002184
	strb r3, [r0, #0x00]
	ldr r0, _080161B0 @ =0x0202EFC0
	mov r1, r8
	str r1, [r0, #0x00]
	movs r1, #0xB6
	lsls r1, r1, #0x01
	add r1, r8
	ldr r0, _080161B4 @ =0x0002BF20
	str r0, [r1, #0x00]
	ldrb r1, [r6, #0x00]
	movs r0, #0x00
	bl sub_08011168
	movs r0, #0x00
	movs r1, #0x11
	ldr r2, _080161B8 @ =0x0202CDA8
	bl sub_0800295C
	mov r2, r10
	ldrb r0, [r2, #0x02]
	cmp r0, #0x00
	beq _08016190
	movs r0, #0x02
	bl sub_08001208
	.global _08016190
_08016190:
	bl sub_08015304
	bl sub_08016CB0
	ldr r0, _080161BC @ =0x020020F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080161A4
	bl sub_08016834
	.global _080161A4
_080161A4:
	strb r5, [r4, #0x00]
	bl sub_08013D5C
	b _08016280
	.global _080161AC
_080161AC: .4byte 0x02002184
	.global _080161B0
_080161B0: .4byte 0x0202EFC0
	.global _080161B4
_080161B4: .4byte 0x0002BF20
	.global _080161B8
_080161B8: .4byte 0x0202CDA8
	.global _080161BC
_080161BC: .4byte 0x020020F0
	.global _080161C0
_080161C0:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080161CC
	ldrb r7, [r7, #0x00]
	cmp r7, #0x01
	bne _080161DA
	.global _080161CC
_080161CC:
	movs r1, #0xB6
	lsls r1, r1, #0x01
	add r1, r8
	ldr r0, _08016244 @ =0x0002BF20
	str r0, [r1, #0x00]
	bl sub_08016CB0
	.global _080161DA
_080161DA:
	bl sub_0800F3C0
	ldr r0, _08016248 @ =0x0202EF10
	ldrb r0, [r0, #0x00]
	ldr r3, _0801624C @ =0x02002184
	strb r0, [r3, #0x00]
	ldr r0, _08016250 @ =0x020020CC
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	bl sub_08011168
	movs r0, #0x00
	movs r1, #0x09
	ldr r2, _08016254 @ =0x0202CDA8
	bl sub_0800295C
	mov r4, r10
	ldrb r0, [r4, #0x02]
	cmp r0, #0x00
	beq _08016208
	movs r0, #0x02
	bl sub_08001208
	.global _08016208
_08016208:
	bl sub_08015304
	ldr r0, _08016258 @ =0x020021BC
	ldrb r1, [r0, #0x00]
	cmp r1, #0x00
	bne _08016270
	ldr r0, _0801625C @ =0x0202F024
	strb r1, [r0, #0x00]
	ldr r0, _08016260 @ =0x0202EEC8
	strb r1, [r0, #0x00]
	ldr r0, _08016264 @ =0x0202F034
	strb r1, [r0, #0x00]
	ldr r0, _08016268 @ =0x020020F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0801622C
	bl sub_08016834
	.global _0801622C
_0801622C:
	bl sub_08014004
	bl sub_080140D8
	bl sub_08014278
	ldr r1, _0801626C @ =0x0202F020
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	b _08016280
	.byte 0x00, 0x00
	.global _08016244
_08016244: .4byte 0x0002BF20
	.global _08016248
_08016248: .4byte 0x0202EF10
	.global _0801624C
_0801624C: .4byte 0x02002184
	.global _08016250
_08016250: .4byte 0x020020CC
	.global _08016254
_08016254: .4byte 0x0202CDA8
	.global _08016258
_08016258: .4byte 0x020021BC
	.global _0801625C
_0801625C: .4byte 0x0202F024
	.global _08016260
_08016260: .4byte 0x0202EEC8
	.global _08016264
_08016264: .4byte 0x0202F034
	.global _08016268
_08016268: .4byte 0x020020F0
	.global _0801626C
_0801626C: .4byte 0x0202F020
	.global _08016270
_08016270:
	ldr r1, _08016278 @ =0x0202F034
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _08016280
	.global _08016278
_08016278: .4byte 0x0202F034
	.global _0801627C
_0801627C:
	bl sub_08013964
	.global _08016280
_08016280:
	ldr r0, _080162BC @ =0x0202F020
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0B
	beq _0801628A
	b _0801606A
	.global _0801628A
_0801628A:
	bl sub_08012C20
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0x0
	bl sub_08012D34
	ldr r0, _080162C0 @ =0x0202EDD8
	ldrb r0, [r0, #0x00]
	adds r1, r4, #0x0
	bl sub_0800F2BC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080162AC
	b _08015FC4
	.global _080162AC
_080162AC:
	bl sub_0800F22C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080162B8
	b _08015FC4
	.global _080162B8
_080162B8:
	b _08016030
	.byte 0x00, 0x00
	.global _080162BC
_080162BC: .4byte 0x0202F020
	.global _080162C0
_080162C0: .4byte 0x0202EDD8
	.global _080162C4
_080162C4:
	movs r5, #0x01
	ldr r2, _08016328 @ =0x0202EDD4
	.global _080162C8
_080162C8:
	ldr r0, [r2, #0x00]
	cmp r0, #0x06
	bne _08016304
	movs r0, #0x09
	ldr r1, [sp, #0x200]
	ands r1, r0
	cmp r1, #0x00
	beq _08016304
	mov r2, r10
	ldrb r0, [r2, #0x03]
	cmp r0, #0x00
	beq _080162E6
	movs r0, #0x09
	bl sub_08001208
	.global _080162E6
_080162E6:
	ldr r4, _0801632C @ =0x0202EFB0
	movs r3, #0x00
	strb r3, [r4, #0x00]
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	bl sub_08012530
	movs r5, #0x01
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08016304
	bl sub_08016A04
	.global _08016304
_08016304:
	bl sub_08000458
	movs r4, #0x00
	cmp r4, #0x00
	bne _08016312
	bl _08015562
	.global _08016312
_08016312:
	movs r0, #0x00
	movs r3, #0x81
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _08016328
_08016328: .4byte 0x0202EDD4
	.global _0801632C
_0801632C: .4byte 0x0202EFB0
	thumb_func_start sub_08016330
sub_08016330:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _080163E8 @ =0xFFFFFE00
	add sp, r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r10, r0
	ldr r4, _080163EC @ =0x06008000
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r0, #0x00
	mov r9, r0
	mov r0, r10
	cmp r0, #0x00
	bne _0801635C
	movs r0, #0x01
	mov r10, r0
	.global _0801635C
_0801635C:
	mov r8, r10
	ldr r0, _080163F0 @ =0x0202EF00
	ldrb r0, [r0, #0x02]
	cmp r0, #0x00
	beq _0801636C
	movs r0, #0x01
	bl sub_08001208
	.global _0801636C
_0801636C:
	movs r0, #0x01
	mov r1, sp
	bl sub_08011D2C
	movs r6, #0x00
	movs r2, #0x00
	movs r1, #0xE0
	lsls r1, r1, #0x02
	.global _0801637C
_0801637C:
	strh r2, [r4, #0x00]
	adds r4, #0x02
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, r1
	bne _0801637C
	ldr r0, _080163F4 @ =0x0829F94C
	bl sub_08006738
	movs r7, #0x14
	movs r6, #0x00
	.global _08016394
_08016394:
	adds r0, r6, r7
	adds r5, r0, #0x0
	subs r5, #0x14
	adds r4, r5, #0x0
	cmp r5, #0x00
	bge _080163A4
	adds r4, r0, #0x0
	adds r4, #0x0B
	.global _080163A4
_080163A4:
	asrs r4, r4, #0x05
	lsls r4, r4, #0x05
	subs r4, r5, r4
	ldr r0, _080163F8 @ =0x0829F2AC
	adds r1, r4, #0x0
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _080163FC @ =0x083FE114
	lsls r1, r5, #0x03
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	ldrb r2, [r1, #0x04]
	adds r1, r4, #0x0
	bl sub_08006950
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0x13
	bls _08016394
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r6, #0x00
	.global _080163D8
_080163D8:
	bl sub_08016E30
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0x13
	bls _080163D8
	b _08016468
	.global _080163E8
_080163E8: .4byte 0xFFFFFE00
	.global _080163EC
_080163EC: .4byte 0x06008000
	.global _080163F0
_080163F0: .4byte 0x0202EF00
	.global _080163F4
_080163F4: .4byte 0x0829F94C
	.global _080163F8
_080163F8: .4byte 0x0829F2AC
	.global _080163FC
_080163FC: .4byte 0x083FE114
	.global _08016400
_08016400:
	mov r0, r8
	subs r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0x00
	bne _08016464
	mov r8, r10
	mov r0, r9
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r9, r0
	cmp r0, #0x07
	bls _08016458
	movs r0, #0x00
	mov r9, r0
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0xB6
	beq _08016478
	ldr r0, _08016498 @ =0x0829F2AC
	subs r5, r7, #0x1
	adds r4, r5, #0x0
	cmp r5, #0x00
	bge _0801643A
	adds r4, r7, #0x0
	adds r4, #0x1E
	.global _0801643A
_0801643A:
	asrs r4, r4, #0x05
	lsls r4, r4, #0x05
	subs r4, r5, r4
	adds r1, r4, #0x0
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _0801649C @ =0x083FE114
	lsls r1, r5, #0x03
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	ldrb r2, [r1, #0x04]
	adds r1, r4, #0x0
	bl sub_08006950
	.global _08016458
_08016458:
	ldr r1, _080164A0 @ =0x04000012
	adds r0, r7, #0x0
	subs r0, #0x14
	lsls r0, r0, #0x03
	add r0, r9
	strh r0, [r1, #0x00]
	.global _08016464
_08016464:
	bl sub_08016E30
	.global _08016468
_08016468:
	bl sub_0800048C
	ldr r1, _080164A4 @ =0x020005CC
	movs r0, #0x02
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08016400
	.global _08016478
_08016478:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	bl sub_08015304
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08016498
_08016498: .4byte 0x0829F2AC
	.global _0801649C
_0801649C: .4byte 0x083FE114
	.global _080164A0
_080164A0: .4byte 0x04000012
	.global _080164A4
_080164A4: .4byte 0x020005CC
	thumb_func_start sub_080164A8
sub_080164A8:
	push {lr}
	mov r12, r4
	ldr r4, _08016540 @ =0xFFFFFE00
	add sp, r4
	mov r4, r12
	ldr r0, _08016544 @ =0x02001F60
	bl sub_080019B4
	ldr r0, _08016548 @ =0x02001F20
	bl sub_080019B4
	bl sub_080045D8
	bl sub_08007344
	bl sub_080073D8
	bl sub_08004484
	bl sub_080047DC
	bl sub_08015304
	ldr r1, _0801654C @ =0x020020DC
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r0, #0x01
	mov r1, sp
	bl sub_08011C9C
	ldr r0, _08016550 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x75
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x75
	bl sub_08016558
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006950
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	.global _0801650C
_0801650C:
	bl sub_08016E30
	bl sub_0800048C
	movs r0, #0x0F
	bl sub_08016558
	movs r1, #0x0F
	movs r2, #0x01
	bl sub_08006950
	ldr r1, _08016554 @ =0x020005CC
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _0801650C
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r0}
	bx r0
	.global _08016540
_08016540: .4byte 0xFFFFFE00
	.global _08016544
_08016544: .4byte 0x02001F60
	.global _08016548
_08016548: .4byte 0x02001F20
	.global _0801654C
_0801654C: .4byte 0x020020DC
	.global _08016550
_08016550: .4byte 0x083FDE18
	.global _08016554
_08016554: .4byte 0x020005CC
