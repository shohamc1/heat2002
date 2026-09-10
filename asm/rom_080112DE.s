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
	thumb_func_start sub_080112E0
sub_080112E0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	movs r5, #0x00
	ldr r2, _08011370 @ =0x020020AC
	mov r10, r2
	ldr r0, _08011374 @ =0x0202EFC0
	mov r9, r0
	ldrb r1, [r2, #0x00]
	cmp r5, r1
	beq _0801131C
	mov r4, r9
	ldr r3, _08011378 @ =0x0202A550
	.global _080112FE
_080112FE:
	lsls r0, r5, #0x02
	adds r0, r0, r4
	lsls r1, r5, #0x01
	adds r1, r1, r5
	lsls r1, r1, #0x03
	adds r1, r1, r5
	lsls r1, r1, #0x04
	adds r1, r1, r3
	str r1, [r0, #0x00]
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r0, [r2, #0x00]
	cmp r5, r0
	bne _080112FE
	.global _0801131C
_0801131C:
	mov r6, r9
	movs r5, #0x00
	movs r7, #0x00
	mov r1, r10
	ldrb r1, [r1, #0x00]
	cmp r1, #0x01
	beq _0801135C
	movs r2, #0xB6
	lsls r2, r2, #0x01
	mov r12, r2
	mov r8, r10
	.global _08011332
_08011332:
	ldr r4, [r6, #0x00]
	ldr r3, [r6, #0x04]
	mov r1, r12
	adds r0, r4, r1
	adds r1, r3, r1
	ldr r2, [r0, #0x00]
	ldr r0, [r1, #0x00]
	cmp r2, r0
	bls _0801134A
	str r3, [r6, #0x00]
	str r4, [r6, #0x04]
	movs r7, #0x01
	.global _0801134A
_0801134A:
	adds r6, #0x04
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r2, r8
	ldrb r0, [r2, #0x00]
	subs r0, #0x01
	cmp r5, r0
	bne _08011332
	.global _0801135C
_0801135C:
	cmp r7, #0x00
	bne _0801131C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08011370
_08011370: .4byte 0x020020AC
	.global _08011374
_08011374: .4byte 0x0202EFC0
	.global _08011378
_08011378: .4byte 0x0202A550
	thumb_func_start sub_0801137C
sub_0801137C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x034
	ldr r0, _08011404 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x5B
	bl sub_08016558
	bl sub_080065A8
	ldr r0, _08011408 @ =0x0202EFC0
	str r0, [sp, #0x030]
	movs r7, #0x00
	ldr r0, _0801140C @ =0x020020AC
	ldrb r0, [r0, #0x00]
	cmp r7, r0
	bne _080113AA
	b _080114FE
	.global _080113AA
_080113AA:
	add r1, sp, #0x028
	mov r10, r1
	movs r0, #0x2A
	add r0, sp
	mov r9, r0
	add r1, sp, #0x02C
	mov r8, r1
	mov r6, sp
	.global _080113BA
_080113BA:
	ldr r0, [sp, #0x030]
	ldr r5, [r0, #0x00]
	movs r1, #0xB6
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	add r1, sp, #0x028
	mov r2, sp
	adds r2, #0x2A
	add r3, sp, #0x02C
	bl sub_08016C50
	ldr r0, _08011410 @ =0x0202EF90
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _08011414 @ =0x0202A550
	adds r0, r0, r1
	cmp r5, r0
	bne _08011420
	ldr r1, _08011418 @ =0x0202539C
	movs r0, #0x10
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08011420
	lsls r2, r7, #0x01
	adds r2, #0x04
	ldr r0, _0801141C @ =0x0829F2F0
	movs r1, #0x04
	movs r3, #0x01
	bl sub_080063BC
	b _080114E8
	.global _08011404
_08011404: .4byte 0x083FDE18
	.global _08011408
_08011408: .4byte 0x0202EFC0
	.global _0801140C
_0801140C: .4byte 0x020020AC
	.global _08011410
_08011410: .4byte 0x0202EF90
	.global _08011414
_08011414: .4byte 0x0202A550
	.global _08011418
_08011418: .4byte 0x0202539C
	.global _0801141C
_0801141C: .4byte 0x0829F2F0
	.global _08011420
_08011420:
	adds r0, r7, #0x0
	adds r0, #0xC0
	bl sub_08016558
	lsls r4, r7, #0x01
	adds r4, #0x04
	movs r1, #0x01
	adds r2, r4, #0x0
	movs r3, #0x01
	bl sub_080063BC
	ldr r0, _08011518 @ =0x0202A550
	subs r0, r5, r0
	ldr r1, _0801151C @ =0xC28F5C29
	muls r0, r1
	asrs r0, r0, #0x04
	adds r0, #0x53
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_08016558
	movs r1, #0x06
	adds r2, r4, #0x0
	movs r3, #0x01
	bl sub_080063BC
	mov r1, r10
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r6, #0x00]
	mov r1, r10
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r6, #0x01]
	movs r0, #0x3A
	strb r0, [r6, #0x02]
	mov r1, r9
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r6, #0x03]
	mov r1, r9
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r6, #0x04]
	movs r0, #0x3A
	strb r0, [r6, #0x05]
	mov r1, r8
	ldrh r0, [r1, #0x00]
	movs r1, #0x64
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r6, #0x06]
	mov r1, r8
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r6, #0x07]
	movs r0, #0x00
	strb r0, [r6, #0x08]
	mov r0, sp
	movs r1, #0x12
	adds r2, r4, #0x0
	movs r3, #0x01
	bl sub_080063BC
	.global _080114E8
_080114E8:
	ldr r1, [sp, #0x030]
	adds r1, #0x04
	str r1, [sp, #0x030]
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _08011520 @ =0x020020AC
	ldrb r0, [r0, #0x00]
	cmp r7, r0
	beq _080114FE
	b _080113BA
	.global _080114FE
_080114FE:
	ldr r1, _08011524 @ =0x0202539C
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	add sp, #0x034
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08011518
_08011518: .4byte 0x0202A550
	.global _0801151C
_0801151C: .4byte 0xC28F5C29
	.global _08011520
_08011520: .4byte 0x020020AC
	.global _08011524
_08011524: .4byte 0x0202539C
