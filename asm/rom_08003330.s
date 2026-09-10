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
