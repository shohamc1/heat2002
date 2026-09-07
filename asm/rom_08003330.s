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
	thumb_func_start sub_08003330
sub_08003330:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x020
	ldr r0, _080033B8 @ =0x04000130
	ldrh r0, [r0, #0x00]
	mvns r0, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0x0
	bl sub_080031C8
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r3, _080033BC @ =0x020020AC
	ldr r0, [sp, #0x008]
	ldrb r2, [r3, #0x00]
	cmp r0, r2
	bge _08003382
	ldr r5, _080033C0 @ =0x0202EF40
	movs r2, #0x00
	ldr r4, _080033C4 @ =0x02002178
	.global _08003364
_08003364:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x03
	adds r0, r0, r5
	strh r2, [r0, #0x00]
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	adds r0, r0, r4
	strh r2, [r0, #0x00]
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldrb r6, [r3, #0x00]
	cmp r0, r6
	blt _08003364
	.global _08003382
_08003382:
	movs r0, #0x00
	mov r10, r0
	movs r2, #0x00
	str r2, [sp, #0x018]
	movs r3, #0x00
	str r3, [sp, #0x01C]
	movs r4, #0x7F
	mov r9, r4
	adds r5, r1, #0x0
	ands r5, r4
	movs r6, #0x0F
	mov r8, r6
	ands r1, r6
	lsls r0, r1, #0x07
	orrs r5, r0
	.global _080033A0
_080033A0:
	ldr r0, _080033BC @ =0x020020AC
	ldr r1, [sp, #0x01C]
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bls _080033E0
	ldr r0, _080033C8 @ =0x0200216C
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldr r0, _080033CC @ =0x02002170
	strh r1, [r0, #0x00]
	movs r0, #0x01
	b _08003716
	.global _080033B8
_080033B8: .4byte 0x04000130
	.global _080033BC
_080033BC: .4byte 0x020020AC
	.global _080033C0
_080033C0: .4byte 0x0202EF40
	.global _080033C4
_080033C4: .4byte 0x02002178
	.global _080033C8
_080033C8: .4byte 0x0200216C
	.global _080033CC
_080033CC: .4byte 0x02002170
	.global _080033D0
_080033D0:
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r0, [sp, #0x01C]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x01C]
	b _080033A0
	.global _080033E0
_080033E0:
	mov r2, r10
	cmp r2, #0x00
	bne _08003408
	ldr r0, _080033FC @ =0x02002170
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x0B
	orrs r0, r5
	ldr r3, _08003400 @ =0xFFFF8000
	adds r1, r3, #0x0
	orrs r0, r1
	ldr r4, _08003404 @ =0x0202ED78
	strh r0, [r4, #0x00]
	adds r0, r4, #0x0
	b _0800341E
	.global _080033FC
_080033FC: .4byte 0x02002170
	.global _08003400
_08003400: .4byte 0xFFFF8000
	.global _08003404
_08003404: .4byte 0x0202ED78
	.global _08003408
_08003408:
	ldr r0, _08003438 @ =0x02002170
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x0B
	orrs r0, r5
	movs r6, #0x80
	lsls r6, r6, #0x07
	adds r1, r6, #0x0
	orrs r0, r1
	ldr r1, _0800343C @ =0x0202ED78
	strh r0, [r1, #0x00]
	adds r0, r1, #0x0
	.global _0800341E
_0800341E:
	ldrh r0, [r0, #0x00]
	bl sub_0800F818
	ldr r2, _08003440 @ =0x03007FF8
	movs r0, #0x80
	ldrh r3, [r2, #0x00]
	ands r0, r3
	cmp r0, #0x00
	beq _08003448
	ldrh r0, [r2, #0x00]
	ldr r4, _08003444 @ =0x0000FF7F
	adds r1, r4, #0x0
	b _08003462
	.global _08003438
_08003438: .4byte 0x02002170
	.global _0800343C
_0800343C: .4byte 0x0202ED78
	.global _08003440
_08003440: .4byte 0x03007FF8
	.global _08003444
_08003444: .4byte 0x0000FF7F
	.global _08003448
_08003448:
	ldr r1, _080035AC @ =0x0200216C
	ldrh r0, [r1, #0x00]
	cmp r0, #0x64
	bhi _080033D0
	ldr r2, _080035B0 @ =0x03007FF8
	movs r0, #0x80
	ldrh r6, [r2, #0x00]
	ands r0, r6
	cmp r0, #0x00
	beq _08003448
	ldrh r0, [r2, #0x00]
	ldr r3, _080035B4 @ =0x0000FF7F
	adds r1, r3, #0x0
	.global _08003462
_08003462:
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r0, _080035B8 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08003484
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r1, _080035BC @ =0x00000257
	cmp r0, r1
	bgt _08003484
	.global _08003478
_08003478:
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	cmp r0, r1
	ble _08003478
	.global _08003484
_08003484:
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r3, _080035C0 @ =0x020020AC
	ldr r0, [sp, #0x008]
	ldrb r4, [r3, #0x00]
	cmp r0, r4
	bge _080034B4
	ldr r2, _080035C4 @ =0x0202EF40
	.global _08003494
_08003494:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r6, sp
	adds r1, r6, r0
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x03
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldrb r1, [r3, #0x00]
	cmp r0, r1
	blt _08003494
	.global _080034B4
_080034B4:
	mov r2, r10
	cmp r2, #0x00
	beq _080034BC
	b _080035D0
	.global _080034BC
_080034BC:
	movs r4, #0x00
	str r2, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r3, _080035C0 @ =0x020020AC
	ldrb r3, [r3, #0x00]
	cmp r0, r3
	bge _08003568
	movs r7, #0x0F
	ldr r6, _080035C8 @ =0x0000FFFF
	.global _080034CE
_080034CE:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r1, sp
	adds r2, r1, r0
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r1, r0, #0x07
	mov r0, r8
	ldrh r2, [r2, #0x00]
	ands r0, r2
	ands r1, r7
	cmp r0, r1
	bne _08003558
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	cmp r0, r6
	beq _08003558
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08003558
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0E
	cmp r0, #0x02
	beq _08003520
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0E
	cmp r0, #0x01
	bne _08003558
	.global _08003520
_08003520:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0B
	movs r1, #0x07
	ands r0, r1
	movs r1, #0x00
	bl sub_080032E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08003558
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r2, sp
	adds r1, r2, r0
	mov r0, r9
	ldrh r1, [r1, #0x00]
	ands r0, r1
	bl sub_08003314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08003558
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	.global _08003558
_08003558:
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r1, _080035C0 @ =0x020020AC
	ldr r0, [sp, #0x008]
	ldrb r1, [r1, #0x00]
	cmp r0, r1
	blt _080034CE
	.global _08003568
_08003568:
	ldr r3, _080035C0 @ =0x020020AC
	ldrb r3, [r3, #0x00]
	cmp r4, r3
	beq _08003572
	b _08003700
	.global _08003572
_08003572:
	movs r4, #0x01
	mov r10, r4
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r6, _080035C0 @ =0x020020AC
	ldrb r6, [r6, #0x00]
	cmp r0, r6
	blt _08003586
	b _08003700
	.global _08003586
_08003586:
	ldr r3, _080035CC @ =0x02002178
	ldr r2, _080035C0 @ =0x020020AC
	.global _0800358A
_0800358A:
	ldr r1, [sp, #0x008]
	lsls r1, r1, #0x01
	adds r1, r1, r3
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldrb r1, [r2, #0x00]
	cmp r0, r1
	blt _0800358A
	b _08003700
	.byte 0x00, 0x00
	.global _080035AC
_080035AC: .4byte 0x0200216C
	.global _080035B0
_080035B0: .4byte 0x03007FF8
	.global _080035B4
_080035B4: .4byte 0x0000FF7F
	.global _080035B8
_080035B8: .4byte 0x0202EF90
	.global _080035BC
_080035BC: .4byte 0x00000257
	.global _080035C0
_080035C0: .4byte 0x020020AC
	.global _080035C4
_080035C4: .4byte 0x0202EF40
	.global _080035C8
_080035C8: .4byte 0x0000FFFF
	.global _080035CC
_080035CC: .4byte 0x02002178
	.global _080035D0
_080035D0:
	movs r4, #0x00
	str r4, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r2, _08003660 @ =0x020020AC
	ldrb r2, [r2, #0x00]
	cmp r0, r2
	bge _080036BA
	.global _080035DE
_080035DE:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r3, sp
	adds r2, r3, r0
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r1, r0, #0x07
	mov r0, r8
	ldrh r2, [r2, #0x00]
	ands r0, r2
	mov r6, r8
	ands r1, r6
	cmp r0, r1
	bne _080036AA
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldr r0, _08003664 @ =0x0000FFFF
	ldrh r1, [r1, #0x00]
	cmp r1, r0
	beq _080036AA
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080036AA
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	adds r1, r3, r0
	mov r0, r9
	ldrh r1, [r1, #0x00]
	ands r0, r1
	bl sub_08003314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080036AA
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0E
	cmp r0, #0x01
	bne _08003668
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0B
	movs r1, #0x07
	ands r0, r1
	movs r1, #0x00
	bl sub_080032E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08003668
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	b _080036AA
	.byte 0x00, 0x00
	.global _08003660
_08003660: .4byte 0x020020AC
	.global _08003664
_08003664: .4byte 0x0000FFFF
	.global _08003668
_08003668:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0E
	cmp r0, #0x02
	bne _080036AA
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0B
	movs r1, #0x07
	ands r0, r1
	movs r1, #0x01
	bl sub_080032E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080036AA
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r1, sp
	adds r2, r1, r0
	ldr r1, _08003728 @ =0x02002178
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	strh r0, [r2, #0x00]
	.global _080036AA
_080036AA:
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r1, _0800372C @ =0x020020AC
	ldr r0, [sp, #0x008]
	ldrb r1, [r1, #0x00]
	cmp r0, r1
	blt _080035DE
	.global _080036BA
_080036BA:
	ldr r2, _0800372C @ =0x020020AC
	ldrb r2, [r2, #0x00]
	cmp r4, r2
	bne _08003700
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r3, _0800372C @ =0x020020AC
	ldrb r3, [r3, #0x00]
	cmp r0, r3
	bge _080036FC
	ldr r4, _08003730 @ =0x020020A0
	.global _080036D2
_080036D2:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r6, sp
	adds r1, r6, r0
	mov r0, r9
	ldrh r1, [r1, #0x00]
	ands r0, r1
	bl sub_08003238
	ldr r1, [sp, #0x008]
	lsls r1, r1, #0x01
	adds r1, r1, r4
	strh r0, [r1, #0x00]
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r1, _0800372C @ =0x020020AC
	ldr r0, [sp, #0x008]
	ldrb r1, [r1, #0x00]
	cmp r0, r1
	blt _080036D2
	.global _080036FC
_080036FC:
	movs r0, #0x01
	str r0, [sp, #0x018]
	.global _08003700
_08003700:
	ldr r1, [sp, #0x018]
	cmp r1, #0x00
	bne _08003708
	b _080033A0
	.global _08003708
_08003708:
	ldr r0, _08003734 @ =0x02002170
	ldrh r1, [r0, #0x00]
	adds r1, #0x01
	movs r2, #0x07
	ands r1, r2
	strh r1, [r0, #0x00]
	movs r0, #0x00
	.global _08003716
_08003716:
	add sp, #0x020
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08003728
_08003728: .4byte 0x02002178
	.global _0800372C
_0800372C: .4byte 0x020020AC
	.global _08003730
_08003730: .4byte 0x020020A0
	.global _08003734
_08003734: .4byte 0x02002170
	thumb_func_start sub_08003738
sub_08003738:
	push {r4, r5, r6, lr}
	bl sub_0800E200
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bne _0800374A
	movs r0, #0x01
	b _08003836
	.global _0800374A
_0800374A:
	bl sub_08000380
	ldr r6, _08003800 @ =0x04000200
	movs r0, #0x00
	strh r0, [r6, #0x00]
	ldr r1, _08003804 @ =0x04000208
	movs r0, #0x01
	strh r0, [r1, #0x00]
	ldr r5, _08003808 @ =0x04000004
	movs r4, #0x08
	strh r4, [r5, #0x00]
	bl sub_0800048C
	ldr r0, _0800380C @ =0x0800306D
	bl sub_080003F8
	ldr r1, _08003810 @ =0x00002001
	adds r0, r1, #0x0
	strh r0, [r6, #0x00]
	strh r4, [r5, #0x00]
	bl sub_08001170
	bl sub_0800184C
	bl sub_08000370
	movs r0, #0x00
	movs r1, #0x0A
	bl sub_0800420C
	movs r4, #0x00
	.global _08003788
_08003788:
	bl sub_08000458
	adds r4, #0x01
	cmp r4, #0x32
	bne _08003788
	.global _08003792
_08003792:
	ldr r5, _08003814 @ =0x020020DC
	movs r4, #0x01
	strb r4, [r5, #0x00]
	bl sub_08011B08
	strb r4, [r5, #0x00]
	ldr r1, _08003818 @ =0x020020CC
	movs r0, #0x07
	strb r0, [r1, #0x00]
	ldr r1, _0800381C @ =0x02002184
	movs r0, #0x03
	strb r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x04
	ldr r2, _08003820 @ =0x0202CD90
	bl sub_0800295C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800382C
	movs r0, #0x75
	bl sub_08016558
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006418
	ldr r0, _08003824 @ =0x0806C688
	movs r1, #0x0C
	movs r2, #0x01
	bl sub_08006418
	bl sub_08010074
	.global _080037D6
_080037D6:
	bl sub_0800048C
	ldr r1, _08003828 @ =0x020005CC
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080037D6
	.global _080037E6
_080037E6:
	bl sub_0800048C
	ldr r1, _08003828 @ =0x020005CC
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _080037E6
	movs r0, #0x00
	movs r1, #0x32
	bl sub_0800420C
	b _08003836
	.global _08003800
_08003800: .4byte 0x04000200
	.global _08003804
_08003804: .4byte 0x04000208
	.global _08003808
_08003808: .4byte 0x04000004
	.global _0800380C
_0800380C: .4byte 0x0800306D
	.global _08003810
_08003810: .4byte 0x00002001
	.global _08003814
_08003814: .4byte 0x020020DC
	.global _08003818
_08003818: .4byte 0x020020CC
	.global _0800381C
_0800381C: .4byte 0x02002184
	.global _08003820
_08003820: .4byte 0x0202CD90
	.global _08003824
_08003824: .4byte 0x0806C688
	.global _08003828
_08003828: .4byte 0x020005CC
	.global _0800382C
_0800382C:
	bl sub_080112E0
	bl sub_080053B8
	b _08003792
	.global _08003836
_08003836:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_start sub_0800383C
sub_0800383C:
	push {r4, r5, r6, lr}
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r3, _0800388C @ =0x0000FFFF
	adds r2, r0, #0x0
	ldrh r4, [r2, #0x00]
	adds r2, #0x02
	movs r5, #0x01
	cmp r5, r6
	bcs _08003884
	.global _08003850
_08003850:
	strh r4, [r1, #0x00]
	adds r1, #0x02
	cmp r4, r3
	bne _08003874
	ldrh r3, [r2, #0x00]
	adds r2, #0x02
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r3, #0x00
	beq _08003874
	.global _08003866
_08003866:
	strh r4, [r1, #0x00]
	adds r1, #0x02
	subs r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x00
	bne _08003866
	.global _08003874
_08003874:
	adds r3, r4, #0x0
	ldrh r4, [r2, #0x00]
	adds r2, #0x02
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, r6
	bcc _08003850
	.global _08003884
_08003884:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800388C
_0800388C: .4byte 0x0000FFFF
	thumb_func_start sub_08003890
sub_08003890:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x0B
	bhi _0800390C
	lsls r0, r4, #0x02
	ldr r1, _080038A4 @ =0x080038A8
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.global _080038A4
_080038A4: .4byte 0x080038A8
	.byte 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08
	.byte 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08
	.byte 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08
	.byte 0x0E, 0x4D, 0x64, 0x20, 0x44, 0x43, 0x28, 0x1D, 0x20, 0x18, 0x00, 0x68, 0xC0, 0x21, 0xC9, 0x04
	.byte 0x80, 0x22, 0xD2, 0x01, 0x13, 0xF0, 0x90, 0xFA, 0x64, 0x19, 0x20, 0x68, 0x08, 0x49, 0x80, 0x22
	.byte 0x92, 0x01, 0x13, 0xF0, 0x89, 0xFA, 0x07, 0x48, 0x00, 0x21, 0x01, 0x80, 0x06, 0x48, 0x01, 0x80
	.byte 0x06, 0x48, 0x01, 0x80
	.global _0800390C
_0800390C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x0C, 0x4B, 0x36, 0x08, 0x00, 0x80, 0x00, 0x06, 0xE4, 0x2D, 0x02, 0x02, 0x34, 0xBC
	.byte 0x00, 0x02, 0xF4, 0x2D, 0x02, 0x02
	thumb_func_start sub_08003928
sub_08003928:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08003AE8 @ =0xFFFFFDF8
	add sp, r4
	adds r7, r0, #0x0
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	bl sub_08003890
	ldr r0, _08003AEC @ =0x08335C60
	ldr r1, _08003AF0 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	ldr r6, _08003AF4 @ =0x08364B0C
	movs r0, #0x64
	adds r4, r7, #0x0
	muls r4, r0
	adds r0, r6, #0x0
	adds r0, #0x18
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x01
	add r1, sp, #0x008
	bl sub_08016E10
	ldr r0, _08003AF8 @ =0x08334BCC
	add r1, sp, #0x1C8
	movs r2, #0x10
	bl sub_08016E10
	movs r0, #0x1E
	add r1, sp, #0x008
	bl sub_08004018
	ldr r1, _08003AFC @ =0x0200BC30
	adds r0, r6, #0x0
	adds r0, #0x2C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _08003B00 @ =0x02022DD8
	adds r0, r6, #0x0
	adds r0, #0x34
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, _08003B04 @ =0x02002208
	ldr r1, _08003B08 @ =0x02002220
	str r1, [r0, #0x00]
	ldr r0, _08003B0C @ =0x0200BC54
	ldr r5, _08003B10 @ =0x0200BC70
	str r5, [r0, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	adds r2, r4, r6
	mov r8, r2
	adds r2, #0x5C
	ldrh r2, [r2, #0x00]
	bl sub_0800383C
	adds r0, r6, #0x0
	adds r0, #0x24
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	mov r1, r8
	adds r1, #0x5E
	ldrh r2, [r1, #0x00]
	adds r1, r5, #0x0
	bl sub_0800383C
	ldr r1, _08003B14 @ =0x0200221C
	adds r0, r6, #0x0
	adds r0, #0x0C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _08003B18 @ =0x02002210
	adds r0, r6, #0x0
	adds r0, #0x10
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _08003B1C @ =0x02022DF0
	adds r0, r6, #0x0
	adds r0, #0x3C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _08003B20 @ =0x0201567C
	adds r0, r6, #0x0
	adds r0, #0x40
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, _08003B24 @ =0x0200BC50
	ldr r1, _08003B28 @ =0x02015690
	str r1, [r0, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x44
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	mov r2, r8
	adds r2, #0x60
	ldrh r2, [r2, #0x00]
	bl sub_0800383C
	ldr r1, _08003B2C @ =0x02022DEC
	adds r0, r6, #0x0
	adds r0, #0x48
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	str r0, [r1, #0x00]
	cmp r7, #0x00
	bne _08003A1E
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _08003A1E
_08003A1E:
	cmp r7, #0x01
	bne _08003A28
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x70
	str r0, [r1, #0x00]
	.global _08003A28
_08003A28:
	cmp r7, #0x02
	bne _08003A32
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0xA8
	str r0, [r1, #0x00]
	.global _08003A32
_08003A32:
	cmp r7, #0x03
	bne _08003A3C
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x6B
	str r0, [r1, #0x00]
	.global _08003A3C
_08003A3C:
	cmp r7, #0x04
	bne _08003A46
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0xA3
	str r0, [r1, #0x00]
	.global _08003A46
_08003A46:
	cmp r7, #0x05
	bne _08003A50
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0xA6
	str r0, [r1, #0x00]
	.global _08003A50
_08003A50:
	cmp r7, #0x06
	bne _08003A5A
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _08003A5A
_08003A5A:
	cmp r7, #0x08
	bne _08003A64
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _08003A64
_08003A64:
	cmp r7, #0x09
	bne _08003A6E
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _08003A6E
_08003A6E:
	cmp r7, #0x0A
	bne _08003A78
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x5E
	str r0, [r1, #0x00]
	.global _08003A78
_08003A78:
	cmp r7, #0x0B
	bne _08003A82
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _08003A82
_08003A82:
	ldr r0, _08003B04 @ =0x02002208
	ldr r2, [r0, #0x00]
	movs r3, #0xC0
	lsls r3, r3, #0x12
	ldr r0, _08003B14 @ =0x0200221C
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _08003B34 @ =0x02022DE4
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x00
	movs r1, #0x00
	bl sub_08003BFC
	ldr r0, _08003B0C @ =0x0200BC54
	ldr r2, [r0, #0x00]
	ldr r3, _08003B38 @ =0x03000800
	ldr r0, _08003B18 @ =0x02002210
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _08003B3C @ =0x0200BC34
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x00
	movs r1, #0x00
	bl sub_08003BFC
	bl sub_08003D90
	movs r0, #0x00
	movs r1, #0x00
	bl sub_08004260
	adds r0, r7, #0x0
	bl sub_08008F1C
	bl sub_08005560
	bl sub_0800557C
	ldr r1, _08003B40 @ =0x020253D4
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r3, #0x82
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08003AE8
_08003AE8: .4byte 0xFFFFFDF8
	.global _08003AEC
_08003AEC: .4byte 0x08335C60
	.global _08003AF0
_08003AF0: .4byte 0x0600C000
	.global _08003AF4
_08003AF4: .4byte 0x08364B0C
	.global _08003AF8
_08003AF8: .4byte 0x08334BCC
	.global _08003AFC
_08003AFC: .4byte 0x0200BC30
	.global _08003B00
_08003B00: .4byte 0x02022DD8
	.global _08003B04
_08003B04: .4byte 0x02002208
	.global _08003B08
_08003B08: .4byte 0x02002220
	.global _08003B0C
_08003B0C: .4byte 0x0200BC54
	.global _08003B10
_08003B10: .4byte 0x0200BC70
	.global _08003B14
_08003B14: .4byte 0x0200221C
	.global _08003B18
_08003B18: .4byte 0x02002210
	.global _08003B1C
_08003B1C: .4byte 0x02022DF0
	.global _08003B20
_08003B20: .4byte 0x0201567C
	.global _08003B24
_08003B24: .4byte 0x0200BC50
	.global _08003B28
_08003B28: .4byte 0x02015690
	.global _08003B2C
_08003B2C: .4byte 0x02022DEC
	.global _08003B30
_08003B30: .4byte 0x02002200
	.global _08003B34
_08003B34: .4byte 0x02022DE4
	.global _08003B38
_08003B38: .4byte 0x03000800
	.global _08003B3C
_08003B3C: .4byte 0x0200BC34
	.global _08003B40
_08003B40: .4byte 0x020253D4
	thumb_func_start sub_08003B44
sub_08003B44:
	push {r4, r5, lr}
	add sp, #-0x008
	ldr r0, _08003BC0 @ =0x02002100
	ldr r4, [r0, #0x18]
	subs r4, #0x78
	ldr r5, [r0, #0x1C]
	subs r5, #0x50
	ldr r0, _08003BC4 @ =0x0200BC48
	movs r2, #0x0F
	ands r2, r4
	str r2, [r0, #0x00]
	ldr r0, _08003BC8 @ =0x0200BC4C
	movs r1, #0x1F
	ands r1, r5
	str r1, [r0, #0x00]
	ldr r0, _08003BCC @ =0x02022DF8
	str r2, [r0, #0x00]
	ldr r0, _08003BD0 @ =0x0200BC2C
	str r1, [r0, #0x00]
	ldr r0, _08003BD4 @ =0x02022DE0
	str r2, [r0, #0x00]
	ldr r0, _08003BD8 @ =0x02022DE8
	str r1, [r0, #0x00]
	ldr r2, _08003BDC @ =0x02002218
	movs r1, #0x10
	adds r0, r4, #0x0
	ands r0, r1
	strb r0, [r2, #0x00]
	asrs r4, r4, #0x05
	asrs r5, r5, #0x05
	ldr r0, _08003BE0 @ =0x02002208
	ldr r2, [r0, #0x00]
	movs r3, #0xC0
	lsls r3, r3, #0x12
	ldr r0, _08003BE4 @ =0x0200221C
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _08003BE8 @ =0x02022DE4
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_08003BFC
	ldr r0, _08003BEC @ =0x0200BC54
	ldr r2, [r0, #0x00]
	ldr r3, _08003BF0 @ =0x03000800
	ldr r0, _08003BF4 @ =0x02002210
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _08003BF8 @ =0x0200BC34
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_08003BFC
	add sp, #0x008
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08003BC0
_08003BC0: .4byte 0x02002100
	.global _08003BC4
_08003BC4: .4byte 0x0200BC48
	.global _08003BC8
_08003BC8: .4byte 0x0200BC4C
	.global _08003BCC
_08003BCC: .4byte 0x02022DF8
	.global _08003BD0
_08003BD0: .4byte 0x0200BC2C
	.global _08003BD4
_08003BD4: .4byte 0x02022DE0
	.global _08003BD8
_08003BD8: .4byte 0x02022DE8
	.global _08003BDC
_08003BDC: .4byte 0x02002218
	.global _08003BE0
_08003BE0: .4byte 0x02002208
	.global _08003BE4
_08003BE4: .4byte 0x0200221C
	.global _08003BE8
_08003BE8: .4byte 0x02022DE4
	.global _08003BEC
_08003BEC: .4byte 0x0200BC54
	.global _08003BF0
_08003BF0: .4byte 0x03000800
	.global _08003BF4
_08003BF4: .4byte 0x02002210
	.global _08003BF8
_08003BF8: .4byte 0x0200BC34
	thumb_func_start sub_08003BFC
sub_08003BFC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r12, r3
	ldr r6, [sp, #0x018]
	ldr r4, _08003C74 @ =0x0200BC30
	ldr r3, [r4, #0x00]
	muls r1, r3
	lsls r1, r1, #0x01
	adds r2, r2, r1
	lsls r0, r0, #0x01
	adds r2, r2, r0
	movs r0, #0x00
	mov r8, r4
	.global _08003C18
_08003C18:
	movs r4, #0x00
	adds r5, r0, #0x4
	mov r3, r12
	adds r3, #0x90
	.global _08003C20
_08003C20:
	ldrh r1, [r2, #0x00]
	adds r2, #0x02
	lsls r1, r1, #0x05
	adds r1, r6, r1
	ldm r1!, {r0}
	mov r7, r12
	str r0, [r7, #0x00]
	ldm r1!, {r0}
	str r0, [r7, #0x04]
	ldm r1!, {r0}
	str r0, [r7, #0x48]
	ldm r1!, {r0}
	str r0, [r7, #0x4C]
	ldm r1!, {r0}
	str r0, [r3, #0x00]
	ldm r1!, {r0}
	str r0, [r3, #0x04]
	ldm r1!, {r0}
	str r0, [r3, #0x48]
	ldr r0, [r1, #0x00]
	str r0, [r3, #0x4C]
	adds r3, #0x08
	movs r0, #0x08
	add r12, r0
	adds r4, #0x01
	cmp r4, #0x09
	bne _08003C20
	movs r1, #0xD8
	add r12, r1
	mov r7, r8
	ldr r0, [r7, #0x00]
	lsls r0, r0, #0x01
	subs r0, #0x12
	adds r2, r2, r0
	adds r0, r5, #0x0
	cmp r0, #0x18
	bne _08003C18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08003C74
_08003C74: .4byte 0x0200BC30
	.byte 0xF0, 0xB5, 0x4F, 0x46, 0x46, 0x46, 0xC0, 0xB4, 0x1D, 0x1C, 0x07, 0x9B, 0x98, 0x46, 0x2C, 0x4C
	.byte 0x23, 0x68, 0x59, 0x43, 0x52, 0x18, 0x16, 0x18, 0x2B, 0x1C, 0x00, 0x20, 0xA1, 0x46, 0x00, 0x27
	.byte 0x04, 0x30, 0x84, 0x46, 0x1D, 0x1C, 0x90, 0x35, 0x1C, 0x1C, 0xD8, 0x34, 0x1A, 0x1C, 0x48, 0x32
	.byte 0x30, 0x78, 0x01, 0x36, 0x40, 0x01, 0x40, 0x44, 0x01, 0x88, 0x19, 0x80, 0x02, 0x30, 0x01, 0x88
	.byte 0x59, 0x80, 0x02, 0x30, 0x01, 0x88, 0x99, 0x80, 0x02, 0x30, 0x01, 0x88, 0xD9, 0x80, 0x02, 0x30
	.byte 0x01, 0x88, 0x11, 0x80, 0x02, 0x30, 0x01, 0x88, 0x51, 0x80, 0x02, 0x30, 0x01, 0x88, 0x91, 0x80
	.byte 0x02, 0x30, 0x01, 0x88, 0xD1, 0x80, 0x02, 0x30, 0x01, 0x88, 0x29, 0x80, 0x02, 0x30, 0x01, 0x88
	.byte 0x69, 0x80, 0x02, 0x30, 0x01, 0x88, 0xA9, 0x80, 0x02, 0x30, 0x01, 0x88, 0xE9, 0x80, 0x02, 0x30
	.byte 0x01, 0x88, 0x21, 0x80, 0x02, 0x30, 0x01, 0x88, 0x61, 0x80, 0x02, 0x30, 0x01, 0x88, 0xA1, 0x80
	.byte 0x40, 0x88, 0xE0, 0x80, 0x08, 0x35, 0x08, 0x34, 0x08, 0x32, 0x08, 0x33, 0x01, 0x37, 0x09, 0x2F
	.byte 0xC6, 0xD1, 0xD8, 0x33, 0x49, 0x46, 0x08, 0x68, 0x09, 0x38, 0x36, 0x18, 0x60, 0x46, 0x18, 0x28
	.byte 0xB5, 0xD1, 0x18, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x30, 0xBC, 0x00, 0x02
	thumb_func_start sub_08003D3C
sub_08003D3C:
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _08003D68 @ =0x02002218
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08003D4C
	adds r4, #0x04
	.global _08003D4C
_08003D4C:
	movs r6, #0x00
	.global _08003D4E
_08003D4E:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0x10
	bl sub_08016E0C
	adds r4, #0x48
	adds r5, #0x40
	adds r6, #0x01
	cmp r6, #0x18
	bne _08003D4E
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _08003D68
_08003D68: .4byte 0x02002218
	.byte 0x70, 0xB5, 0x05, 0x1C, 0x0C, 0x1C, 0x00, 0x26, 0x28, 0x1C, 0x21, 0x1C, 0x10, 0x22, 0x13, 0xF0
	.byte 0x47, 0xF8, 0x40, 0x35, 0x40, 0x34, 0x01, 0x36, 0x1C, 0x2E, 0xF5, 0xD1, 0x70, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00
