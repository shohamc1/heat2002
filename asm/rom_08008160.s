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
	thumb_func_start sub_08008160
sub_08008160:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x04C
	ldr r0, _080082A8 @ =0x0202A550
	ldr r1, [r0, #0x00]
	ldr r0, [r0, #0x08]
	asrs r1, r1, #0x13
	mov r8, r1
	asrs r0, r0, #0x13
	mov r9, r0
	movs r0, #0x02
	add r9, r0
	movs r1, #0x01
	add r8, r1
	movs r0, #0x00
	str r0, [sp, #0x038]
	movs r1, #0x00
	str r1, [sp, #0x034]
	str r0, [sp, #0x03C]
	mov r5, r9
	subs r5, #0x03
	mov r0, r9
	adds r0, #0x04
	cmp r5, r0
	beq _0800825E
	mov r1, r8
	adds r1, #0x04
	str r1, [sp, #0x040]
	str r0, [sp, #0x048]
_080081A0:
	mov r4, r8
	subs r4, #0x03
	adds r0, r5, #0x1
	str r0, [sp, #0x044]
	ldr r1, [sp, #0x040]
	cmp r4, r1
	beq _08008256
	add r6, sp, #0x02C
_080081B0:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl GetTrackTileType
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r10, r7
	lsls r0, r4, #0x13
	lsls r1, r5, #0x13
	adds r2, r6, #0x0
	bl WorldToScreen
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800824E
	ldr r0, [sp, #0x02C]
	subs r0, #0x78
	ldr r2, _080082AC @ =0x02002100
	ldr r1, [r2, #0x18]
	adds r0, r0, r1
	str r0, [sp, #0x02C]
	ldr r0, [r6, #0x04]
	subs r0, #0x50
	ldr r1, [r2, #0x1C]
	adds r0, r0, r1
	str r0, [r6, #0x04]
	ldr r0, [sp, #0x02C]
	adds r0, #0x0A
	str r0, [sp, #0x02C]
	ldr r1, [r6, #0x04]
	adds r1, #0x08
	str r1, [r6, #0x04]
	ldr r0, [sp, #0x02C]
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	ldr r3, _080082B0 @ =0x083FF68C
	lsls r2, r7, #0x02
	adds r2, r2, r3
	ldr r2, [r2, #0x00]
	movs r3, #0x00
	str r3, [sp, #0x000]
	ldr r3, _080082B4 @ =0x08331360
	bl sub_08007A7C
	mov r0, r8
	subs r0, #0x02
	cmp r4, r0
	ble _0800824E
	adds r0, #0x04
	cmp r4, r0
	bge _0800824E
	mov r0, r9
	subs r0, #0x02
	cmp r5, r0
	ble _0800824E
	adds r0, #0x04
	cmp r5, r0
	bge _0800824E
	movs r0, #0x01
	ands r0, r7
	cmp r0, #0x00
	beq _08008230
	movs r0, #0x01
	str r0, [sp, #0x03C]
_08008230:
	subs r0, r7, #0x2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _0800823E
	movs r1, #0x01
	str r1, [sp, #0x034]
_0800823E:
	mov r0, r10
	subs r0, #0x04
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _0800824E
	movs r0, #0x01
	str r0, [sp, #0x038]
_0800824E:
	adds r4, #0x01
	ldr r1, [sp, #0x040]
	cmp r4, r1
	bne _080081B0
_08008256:
	ldr r5, [sp, #0x044]
	ldr r0, [sp, #0x048]
	cmp r5, r0
	bne _080081A0
_0800825E:
	ldr r1, [sp, #0x038]
	cmp r1, #0x00
	beq _0800826E
	ldr r0, _080082B8 @ =0x0806C8B4
	movs r1, #0x64
	movs r2, #0x64
	bl DrawSpriteText
_0800826E:
	ldr r0, [sp, #0x034]
	cmp r0, #0x00
	beq _0800827E
	ldr r0, _080082BC @ =0x0806C8BC
	movs r1, #0x64
	movs r2, #0x64
	bl DrawSpriteText
_0800827E:
	ldr r1, [sp, #0x038]
	cmp r1, #0x00
	bne _08008294
	ldr r0, [sp, #0x034]
	cmp r0, #0x00
	bne _08008294
	ldr r0, _080082C0 @ =0x0806C8C4
	movs r1, #0x64
	movs r2, #0x64
	bl DrawSpriteText
_08008294:
	ldr r1, [sp, #0x03C]
	cmp r1, #0x00
	beq _080082C8
	ldr r0, _080082C4 @ =0x0806C8CC
	movs r1, #0x64
	movs r2, #0x6E
	bl DrawSpriteText
	b _080082D2
	.byte 0x00, 0x00
_080082A8: .4byte 0x0202A550
_080082AC: .4byte 0x02002100
_080082B0: .4byte 0x083FF68C
_080082B4: .4byte 0x08331360
_080082B8: .4byte 0x0806C8B4
_080082BC: .4byte 0x0806C8BC
_080082C0: .4byte 0x0806C8C4
_080082C4: .4byte 0x0806C8CC
_080082C8:
	ldr r0, _08008300 @ =0x0806C8D4
	movs r1, #0x64
	movs r2, #0x6E
	bl DrawSpriteText
_080082D2:
	ldr r1, _08008304 @ =0x0806C8DC
	ldr r0, _08008308 @ =0x0202A550
	ldr r2, [r0, #0x00]
	asrs r2, r2, #0x13
	ldr r3, [r0, #0x08]
	asrs r3, r3, #0x13
	add r0, sp, #0x004
	bl sub_08017594
	add r0, sp, #0x004
	movs r1, #0x64
	movs r2, #0x78
	bl DrawSpriteText
	add sp, #0x04C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08008300: .4byte 0x0806C8D4
_08008304: .4byte 0x0806C8DC
_08008308: .4byte 0x0202A550
