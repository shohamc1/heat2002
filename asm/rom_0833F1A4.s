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
	thumb_func_start sub_0833F1A4
sub_0833F1A4:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833F1A8
sub_0833F1A8:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r3, r0, #0x0
	ldr r0, _0833F3A0 @ =0x06008040
	mov r12, r0
	movs r6, #0xF0
	lsls r6, r6, #0x08
	movs r5, #0x00
	ldrb r1, [r3, #0x00]
	adds r3, #0x01
	ldr r2, _0833F3A4 @ =0x0202522C
	mov r9, r2
	ldr r0, _0833F3A8 @ =0x02025234
	mov r10, r0
	cmp r1, #0x00
	beq _0833F22C
	ldr r7, _0833F3AC @ =0x0201F9D0
	ldr r2, _0833F3B0 @ =0x0201F590
	mov r8, r2
_0833F1D4:
	subs r1, #0x20
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x1D
	lsls r0, r0, #0x16
	movs r2, #0xC0
	lsls r2, r2, #0x0F
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	movs r0, #0xF8
	lsls r0, r0, #0x15
	ands r0, r1
	lsrs r0, r0, #0x18
	adds r0, r2, r0
	lsls r0, r0, #0x01
	mov r1, r8
	adds r4, r0, r1
	ldrh r2, [r4, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r7
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	mov r1, r12
	strh r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x40
	adds r0, r4, #0x0
	adds r0, #0x40
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r7
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r2, #0x02
	add r12, r2
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r1, [r3, #0x00]
	adds r3, #0x01
	cmp r1, #0x00
	bne _0833F1D4
_0833F22C:
	mov r0, r9
	ldr r3, [r0, #0x00]
	ldrb r1, [r3, #0x00]
	adds r3, #0x01
	cmp r1, #0x00
	beq _0833F296
	ldr r7, _0833F3AC @ =0x0201F9D0
	ldr r2, _0833F3B0 @ =0x0201F590
	mov r8, r2
_0833F23E:
	subs r1, #0x20
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x1D
	lsls r0, r0, #0x16
	movs r2, #0xC0
	lsls r2, r2, #0x0F
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	movs r0, #0xF8
	lsls r0, r0, #0x15
	ands r0, r1
	lsrs r0, r0, #0x18
	adds r0, r2, r0
	lsls r0, r0, #0x01
	mov r1, r8
	adds r4, r0, r1
	ldrh r2, [r4, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r7
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	mov r1, r12
	strh r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x40
	adds r0, r4, #0x0
	adds r0, #0x40
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r7
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r2, #0x02
	add r12, r2
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r1, [r3, #0x00]
	adds r3, #0x01
	cmp r1, #0x00
	bne _0833F23E
_0833F296:
	cmp r5, #0x1F
	bhi _0833F2FA
	ldr r3, _0833F3AC @ =0x0201F9D0
	ldr r0, _0833F3B4 @ =0x02025230
	mov r8, r0
	ldr r7, _0833F3B0 @ =0x0201F590
_0833F2A2:
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldrb r1, [r0, #0x00]
	subs r1, #0x20
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x1D
	lsls r0, r0, #0x16
	movs r2, #0xC0
	lsls r2, r2, #0x0F
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	movs r0, #0xF8
	lsls r0, r0, #0x15
	ands r0, r1
	lsrs r0, r0, #0x18
	adds r0, r2, r0
	lsls r0, r0, #0x01
	adds r4, r0, r7
	ldrh r0, [r4, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r3
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	mov r1, r12
	strh r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x40
	adds r0, r4, #0x0
	adds r0, #0x40
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r3
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r2, #0x00]
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r2, #0x02
	add r12, r2
	cmp r5, #0x1F
	bls _0833F2A2
_0833F2FA:
	mov r0, r10
	ldr r3, [r0, #0x00]
	ldr r1, _0833F3B8 @ =0x06008440
	mov r12, r1
	ldrb r0, [r3, #0x00]
	adds r3, #0x01
	cmp r0, #0x00
	beq _0833F366
	ldr r0, _0833F3B0 @ =0x0201F590
	adds r4, r0, #0x0
	adds r4, #0xC0
	ldr r5, _0833F3AC @ =0x0201F9D0
	movs r2, #0x80
	lsls r2, r2, #0x01
	adds r7, r0, r2
_0833F318:
	ldrh r0, [r4, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r5
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	mov r1, r12
	strh r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x40
	ldrh r0, [r7, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r5
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r2, #0x00]
	adds r2, #0x40
	ldrh r0, [r7, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r5
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r2, #0x00]
	adds r2, #0x40
	ldrh r0, [r7, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r5
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r1, #0x02
	add r12, r1
	ldrb r0, [r3, #0x00]
	adds r3, #0x01
	cmp r0, #0x00
	bne _0833F318
_0833F366:
	ldr r2, _0833F3BC @ =0x06008000
	mov r12, r2
	movs r2, #0x00
	ldr r5, _0833F3AC @ =0x0201F9D0
	adds r3, r4, #0x0
	adds r3, #0x40
_0833F372:
	ldrh r1, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r5
	adds r1, r6, #0x0
	ldrh r0, [r0, #0x00]
	orrs r1, r0
	mov r0, r12
	strh r1, [r0, #0x00]
	movs r1, #0x02
	add r12, r1
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x20
	bne _0833F372
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0833F3A0: .4byte 0x06008040
_0833F3A4: .4byte 0x0202522C
_0833F3A8: .4byte 0x02025234
_0833F3AC: .4byte 0x0201F9D0
_0833F3B0: .4byte 0x0201F590
_0833F3B4: .4byte 0x02025230
_0833F3B8: .4byte 0x06008440
_0833F3BC: .4byte 0x06008000
