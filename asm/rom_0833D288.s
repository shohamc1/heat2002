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
	thumb_func_start sub_0833D288
sub_0833D288:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0x0
	lsls r1, r1, #0x10
	movs r0, #0x1F
	movs r2, #0xF8
	lsls r2, r2, #0x0D
	mov r10, r2
	lsrs r2, r1, #0x15
	ands r2, r0
	lsrs r7, r1, #0x1A
	ands r7, r0
	mov r0, r10
	ands r0, r1
	mov r10, r0
	lsls r2, r2, #0x10
	mov r8, r2
	lsls r7, r7, #0x10
	movs r1, #0x00
	mov r9, r1
	ldr r5, _0833D30C @ =0x020392D0
	ldr r4, _0833D310 @ =0x02039ED0
	.global _0833D2BA
_0833D2BA:
	ldr r0, [r5, #0x00]
	mov r2, r10
	subs r0, r2, r0
	adds r1, r6, #0x0
	bl sub_08344BB8
	str r0, [r4, #0x00]
	ldr r0, [r5, #0x04]
	mov r1, r8
	subs r0, r1, r0
	adds r1, r6, #0x0
	bl sub_08344BB8
	str r0, [r4, #0x04]
	ldr r0, [r5, #0x08]
	subs r0, r7, r0
	adds r1, r6, #0x0
	bl sub_08344BB8
	str r0, [r4, #0x08]
	adds r5, #0x0C
	adds r4, #0x0C
	movs r2, #0x01
	add r9, r2
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r9, r0
	bne _0833D2BA
	ldr r0, _0833D314 @ =0x020392C8
	strh r6, [r0, #0x00]
	movs r0, #0x01
	ldr r1, _0833D318 @ =0x020392C4
	strb r0, [r1, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833D30C
_0833D30C: .4byte 0x020392D0
	.global _0833D310
_0833D310: .4byte 0x02039ED0
	.global _0833D314
_0833D314: .4byte 0x020392C8
	.global _0833D318
_0833D318: .4byte 0x020392C4
	thumb_func_start sub_0833D31C
sub_0833D31C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0x0
	mov r9, r1
	movs r0, #0x00
	mov r10, r0
	ldr r1, _0833D3D4 @ =0x020392D0
	mov r8, r1
	ldr r7, _0833D3D8 @ =0x02039ED0
	.global _0833D334
_0833D334:
	mov r0, r9
	ldrh r2, [r0, #0x00]
	movs r1, #0x02
	add r9, r1
	adds r4, r2, #0x0
	movs r0, #0x1F
	ands r2, r0
	asrs r5, r4, #0x05
	ands r5, r0
	asrs r4, r4, #0x0A
	ands r4, r0
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r2, r0, #0x01
	cmp r2, #0x1F
	ble _0833D35A
	movs r2, #0x1F
	.global _0833D35A
_0833D35A:
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r5, r0, #0x01
	cmp r5, #0x1F
	ble _0833D36A
	movs r5, #0x1F
	.global _0833D36A
_0833D36A:
	lsls r0, r4, #0x01
	adds r0, r0, r4
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r4, r0, #0x01
	cmp r4, #0x1F
	ble _0833D37A
	movs r4, #0x1F
	.global _0833D37A
_0833D37A:
	lsls r2, r2, #0x10
	lsls r5, r5, #0x10
	lsls r4, r4, #0x10
	mov r1, r8
	ldr r0, [r1, #0x00]
	subs r0, r2, r0
	adds r1, r6, #0x0
	bl sub_08344BB8
	str r0, [r7, #0x00]
	mov r1, r8
	ldr r0, [r1, #0x04]
	subs r0, r5, r0
	adds r1, r6, #0x0
	bl sub_08344BB8
	str r0, [r7, #0x04]
	mov r1, r8
	ldr r0, [r1, #0x08]
	subs r0, r4, r0
	adds r1, r6, #0x0
	bl sub_08344BB8
	str r0, [r7, #0x08]
	movs r0, #0x0C
	add r8, r0
	adds r7, #0x0C
	movs r1, #0x01
	add r10, r1
	adds r0, #0xF4
	cmp r10, r0
	bne _0833D334
	ldr r0, _0833D3DC @ =0x020392C8
	strh r6, [r0, #0x00]
	movs r0, #0x01
	ldr r1, _0833D3E0 @ =0x020392C4
	strb r0, [r1, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833D3D4
_0833D3D4: .4byte 0x020392D0
	.global _0833D3D8
_0833D3D8: .4byte 0x02039ED0
	.global _0833D3DC
_0833D3DC: .4byte 0x020392C8
	.global _0833D3E0
_0833D3E0: .4byte 0x020392C4
	thumb_func_start sub_0833D3E4
sub_0833D3E4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	movs r0, #0xF0
	mov r8, r0
	ldr r2, _0833D440 @ =0x02039ED0
	ldr r1, _0833D444 @ =0x020392D0
	movs r0, #0xB4
	lsls r0, r0, #0x04
	adds r6, r1, r0
	adds r5, r2, r0
	.global _0833D3FC
_0833D3FC:
	movs r4, #0xF8
	lsls r4, r4, #0x0D
	ldr r0, [r6, #0x00]
	subs r0, r4, r0
	adds r1, r7, #0x0
	bl sub_08344BB8
	str r0, [r5, #0x00]
	ldr r0, [r6, #0x04]
	subs r0, r4, r0
	adds r1, r7, #0x0
	bl sub_08344BB8
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	subs r4, r4, r0
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	bl sub_08344BB8
	str r0, [r5, #0x08]
	adds r6, #0x0C
	adds r5, #0x0C
	movs r0, #0x01
	add r8, r0
	adds r0, #0xFF
	cmp r8, r0
	bne _0833D3FC
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833D440
_0833D440: .4byte 0x02039ED0
	.global _0833D444
_0833D444: .4byte 0x020392D0
	thumb_func_start sub_0833D448
sub_0833D448:
	push {r4, r5, lr}
	ldr r0, _0833D490 @ =0x020392C8
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r1, _0833D494 @ =0x020392C4
	cmp r0, #0x00
	bne _0833D458
	strb r0, [r1, #0x00]
	.global _0833D458
_0833D458:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0833D482
	bl sub_0833D4A4
	movs r2, #0x00
	movs r5, #0xC0
	lsls r5, r5, #0x02
	ldr r3, _0833D498 @ =0x020392D0
	ldr r4, _0833D49C @ =0x02039ED0
	.global _0833D46C
_0833D46C:
	ldr r0, [r3, #0x00]
	ldm r4!, {r1}
	adds r0, r0, r1
	stm r3!, {r0}
	adds r2, #0x01
	cmp r2, r5
	bne _0833D46C
	ldr r1, _0833D490 @ =0x020392C8
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	.global _0833D482
_0833D482:
	ldr r1, _0833D4A0 @ =0x020392C0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833D490
_0833D490: .4byte 0x020392C8
	.global _0833D494
_0833D494: .4byte 0x020392C4
	.global _0833D498
_0833D498: .4byte 0x020392D0
	.global _0833D49C
_0833D49C: .4byte 0x02039ED0
	.global _0833D4A0
_0833D4A0: .4byte 0x020392C0
	thumb_func_start sub_0833D4A4
sub_0833D4A4:
	push {r4, r5, r6, r7, lr}
	ldr r6, _0833D4DC @ =0x020392D0
	ldr r5, _0833D4E0 @ =0x0203AAD0
	movs r4, #0x00
	movs r3, #0x1F
	movs r7, #0x80
	lsls r7, r7, #0x01
	.global _0833D4B2
_0833D4B2:
	ldm r6!, {r0}
	ldm r6!, {r1}
	ldm r6!, {r2}
	asrs r0, r0, #0x10
	asrs r1, r1, #0x10
	asrs r2, r2, #0x10
	ands r0, r3
	ands r1, r3
	ands r2, r3
	lsls r1, r1, #0x05
	orrs r0, r1
	lsls r2, r2, #0x0A
	orrs r0, r2
	strh r0, [r5, #0x00]
	adds r5, #0x02
	adds r4, #0x01
	cmp r4, r7
	bne _0833D4B2
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0833D4DC
_0833D4DC: .4byte 0x020392D0
	.global _0833D4E0
_0833D4E0: .4byte 0x0203AAD0
