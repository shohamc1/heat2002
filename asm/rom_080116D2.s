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
	thumb_func_start sub_080116D4
sub_080116D4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, [sp, #0x01C]
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0x20
	ands r0, r6
	cmp r0, #0x00
	beq _08011728
	ldr r0, _0801176C @ =0x0202EFB0
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, _08011770 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r0, r4
	bne _08011716
	ldr r0, _08011774 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011716
	movs r0, #0x08
	bl sub_08001208
	.global _08011716
_08011716:
	lsls r0, r5, #0x10
	ldr r1, _08011778 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	mov r2, r8
	lsls r1, r2, #0x10
	cmp r0, r1
	bge _08011728
	adds r5, r7, #0x0
	.global _08011728
_08011728:
	movs r0, #0x10
	ands r0, r6
	cmp r0, #0x00
	beq _0801175E
	ldr r0, _0801176C @ =0x0202EFB0
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, _08011770 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r0, r4
	bne _0801174C
	ldr r0, _08011774 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0801174C
	movs r0, #0x08
	bl sub_08001208
	.global _0801174C
_0801174C:
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	lsls r1, r7, #0x10
	cmp r0, r1
	ble _0801175E
	mov r5, r8
	.global _0801175E
_0801175E:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _0801176C
_0801176C: .4byte 0x0202EFB0
	.global _08011770
_08011770: .4byte 0x0202EF90
	.global _08011774
_08011774: .4byte 0x0202EF00
	.global _08011778
_08011778: .4byte 0xFFFF0000
	thumb_func_start sub_0801177C
sub_0801177C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08011904 @ =0xFFFFFDD8
	add sp, r4
	bl sub_08011A50
	movs r4, #0x03
	ldr r0, _08011908 @ =0x0000020B
	add r0, sp
	.global _08011794
_08011794:
	strb r4, [r0, #0x00]
	subs r0, #0x01
	subs r4, #0x01
	cmp r4, #0x00
	bge _08011794
	add r4, sp, #0x208
	ldr r5, _0801190C @ =0x04000128
	ldr r0, [r5, #0x00]
	lsls r0, r0, #0x1A
	lsrs r0, r0, #0x1E
	adds r0, r4, r0
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x224]
	ldr r0, _08011910 @ =0x082B8710
	ldr r1, _08011914 @ =0x06016000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_080045D8
	bl sub_08007344
	bl sub_080073D8
	bl sub_08004484
	bl sub_080047DC
	ldr r1, _08011918 @ =0x020020C0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	bl sub_08000458
	bl sub_0800F3A4
	bl sub_0800F4FC
	ldr r0, _0801191C @ =0x082E4328
	add r1, sp, #0x008
	bl sub_0800F328
	ldr r0, [r5, #0x00]
	lsls r0, r0, #0x1A
	lsrs r0, r0, #0x1E
	adds r4, r4, r0
	ldrb r0, [r4, #0x00]
	bl sub_08010E04
	add r0, sp, #0x008
	movs r1, #0x0F
	bl sub_08004238
	movs r4, #0x80
	lsls r4, r4, #0x13
	movs r1, #0xA8
	lsls r1, r1, #0x03
	adds r0, r1, #0x0
	strh r0, [r4, #0x00]
	bl sub_08000458
	movs r2, #0xAA
	lsls r2, r2, #0x05
	adds r0, r2, #0x0
	strh r0, [r4, #0x00]
	movs r7, #0x40
	str r7, [sp, #0x220]
	movs r4, #0x00
	ldr r3, _08011920 @ =0x020020AC
	ldrb r0, [r3, #0x00]
	cmp r4, r0
	bge _08011838
	add r2, sp, #0x20C
	movs r5, #0xFF
	.global _08011828
_08011828:
	adds r1, r2, r4
	ldrb r0, [r1, #0x00]
	orrs r0, r5
	strb r0, [r1, #0x00]
	adds r4, #0x01
	ldrb r1, [r3, #0x00]
	cmp r4, r1
	blt _08011828
	.global _08011838
_08011838:
	ldr r2, [sp, #0x220]
	cmp r2, #0x40
	beq _08011840
	b _08011A04
	.global _08011840
_08011840:
	movs r7, #0x82
	lsls r7, r7, #0x02
	add r7, sp
	mov r10, r7
	.global _08011848
_08011848:
	bl sub_08004484
	ldr r0, _08011924 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	add r0, r10
	ldrb r0, [r0, #0x00]
	bl sub_08010E04
	ldr r0, _08011920 @ =0x020020AC
	ldrb r2, [r0, #0x00]
	cmp r2, #0x00
	beq _08011874
	ldr r3, _08011928 @ =0x020020A0
	add r1, sp, #0x218
	adds r4, r2, #0x0
	.global _08011866
_08011866:
	ldrh r0, [r3, #0x00]
	strh r0, [r1, #0x00]
	adds r3, #0x02
	adds r1, #0x02
	subs r4, #0x01
	cmp r4, #0x00
	bne _08011866
	.global _08011874
_08011874:
	bl sub_08003330
	cmp r0, #0x00
	beq _0801187E
	b _08011A20
	.global _0801187E
_0801187E:
	movs r4, #0x00
	ldr r0, _08011920 @ =0x020020AC
	adds r1, r0, #0x0
	ldrb r1, [r1, #0x00]
	cmp r4, r1
	bge _0801194C
	movs r2, #0x01
	negs r2, r2
	mov r9, r2
	mov r7, r10
	.global _08011892
_08011892:
	add r0, sp, #0x210
	lsls r2, r4, #0x01
	adds r5, r0, r2
	ldr r1, _08011928 @ =0x020020A0
	adds r1, r2, r1
	add r0, sp, #0x218
	adds r0, r0, r2
	ldrh r2, [r1, #0x00]
	ldrh r0, [r0, #0x00]
	eors r2, r0
	adds r0, r2, #0x0
	ldrh r1, [r1, #0x00]
	ands r0, r1
	strh r0, [r5, #0x00]
	add r6, sp, #0x20C
	adds r0, r6, r4
	mov r8, r0
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r9
	bne _080118D6
	ldrh r0, [r5, #0x00]
	ldrb r1, [r7, #0x00]
	mov r2, r10
	str r2, [sp, #0x000]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x004]
	movs r2, #0x00
	movs r3, #0x1D
	bl sub_080116D4
	strb r0, [r7, #0x00]
	.global _080118D6
_080118D6:
	movs r0, #0x01
	ldrh r1, [r5, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080118E6
	ldrb r0, [r7, #0x00]
	mov r2, r8
	strb r0, [r2, #0x00]
	.global _080118E6
_080118E6:
	movs r0, #0x02
	ldrh r5, [r5, #0x00]
	ands r0, r5
	cmp r0, #0x00
	beq _0801193E
	cmp r4, #0x00
	bne _08011938
	ldrb r1, [r6, #0x00]
	movs r0, #0x00
	ldsb r0, [r6, r0]
	cmp r0, r9
	beq _0801192C
	movs r0, #0xFF
	strb r0, [r6, #0x00]
	b _0801193E
	.global _08011904
_08011904: .4byte 0xFFFFFDD8
	.global _08011908
_08011908: .4byte 0x0000020B
	.global _0801190C
_0801190C: .4byte 0x04000128
	.global _08011910
_08011910: .4byte 0x082B8710
	.global _08011914
_08011914: .4byte 0x06016000
	.global _08011918
_08011918: .4byte 0x020020C0
	.global _0801191C
_0801191C: .4byte 0x082E4328
	.global _08011920
_08011920: .4byte 0x020020AC
	.global _08011924
_08011924: .4byte 0x0202EF90
	.global _08011928
_08011928: .4byte 0x020020A0
	.global _0801192C
_0801192C:
	movs r7, #0xFE
	str r7, [sp, #0x220]
	ldr r0, _08011934 @ =0x020020AC
	b _0801194C
	.global _08011934
_08011934: .4byte 0x020020AC
	.global _08011938
_08011938:
	movs r0, #0xFF
	mov r1, r8
	strb r0, [r1, #0x00]
	.global _0801193E
_0801193E:
	adds r7, #0x01
	adds r4, #0x01
	ldr r0, _080119D0 @ =0x020020AC
	adds r2, r0, #0x0
	ldrb r2, [r2, #0x00]
	cmp r4, r2
	blt _08011892
	.global _0801194C
_0801194C:
	movs r7, #0x00
	movs r4, #0x00
	ldr r5, _080119D4 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r4, r0
	bge _0801197A
	add r2, sp, #0x20C
	movs r3, #0x01
	negs r3, r3
	ldr r0, _080119D0 @ =0x020020AC
	ldrb r1, [r0, #0x00]
	.global _08011962
_08011962:
	adds r0, r2, r4
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r3
	beq _08011974
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	.global _08011974
_08011974:
	adds r4, #0x01
	cmp r4, r1
	blt _08011962
	.global _0801197A
_0801197A:
	add r6, sp, #0x20C
	ldrb r5, [r5, #0x00]
	adds r0, r5, r6
	movs r1, #0x00
	ldsb r1, [r0, r1]
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	beq _080119DC
	movs r0, #0x58
	bl sub_08016558
	movs r1, #0x11
	movs r2, #0x01
	bl sub_08006950
	ldr r5, _080119D0 @ =0x020020AC
	ldrb r0, [r5, #0x00]
	cmp r7, r0
	bne _080119E6
	movs r4, #0x00
	cmp r4, r0
	bge _080119E6
	mov r8, r6
	ldr r3, _080119D8 @ =0x0202A550
	movs r6, #0xC8
	lsls r6, r6, #0x01
	.global _080119B0
_080119B0:
	mov r1, r8
	adds r0, r1, r4
	ldrb r1, [r0, #0x00]
	movs r7, #0xB1
	lsls r7, r7, #0x01
	adds r2, r3, r7
	strb r1, [r2, #0x00]
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x220]
	adds r3, r3, r6
	adds r4, #0x01
	ldrb r0, [r5, #0x00]
	cmp r4, r0
	blt _080119B0
	b _080119E6
	.byte 0x00, 0x00
	.global _080119D0
_080119D0: .4byte 0x020020AC
	.global _080119D4
_080119D4: .4byte 0x0202EF90
	.global _080119D8
_080119D8: .4byte 0x0202A550
	.global _080119DC
_080119DC:
	ldr r0, _08011A18 @ =0x0829F30C
	movs r1, #0x11
	movs r2, #0x01
	bl sub_08006950
	.global _080119E6
_080119E6:
	bl sub_080047DC
	ldr r1, _08011A1C @ =0x020020C0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r2, [sp, #0x220]
	lsls r1, r2, #0x18
	.global _080119F4
_080119F4:
	ldr r0, _08011A1C @ =0x020020C0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080119F4
	asrs r0, r1, #0x18
	cmp r0, #0x40
	bne _08011A04
	b _08011848
	.global _08011A04
_08011A04:
	ldr r7, [sp, #0x220]
	lsls r0, r7, #0x18
	asrs r1, r0, #0x18
	movs r0, #0x02
	negs r0, r0
	cmp r1, r0
	bne _08011A26
	.global _08011A12
_08011A12:
	adds r0, r1, #0x0
	b _08011A3C
	.byte 0x00, 0x00
	.global _08011A18
_08011A18: .4byte 0x0829F30C
	.global _08011A1C
_08011A1C: .4byte 0x020020C0
	.global _08011A20
_08011A20:
	movs r0, #0xFF
	str r0, [sp, #0x220]
	b _08011A04
	.global _08011A26
_08011A26:
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	beq _08011A12
	cmp r1, #0x00
	beq _08011A3A
	ldr r1, [sp, #0x224]
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	b _08011A3C
	.global _08011A3A
_08011A3A:
	movs r0, #0x00
	.global _08011A3C
_08011A3C:
	movs r3, #0x8A
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
