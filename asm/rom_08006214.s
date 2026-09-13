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
	thumb_func_start sub_08006214
sub_08006214:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _080062AC @ =0x08364B08
	ldr r0, [r1, #0x00]
	movs r3, #0xEA
	lsls r3, r3, #0x02
	adds r2, r0, r3
	movs r0, #0x00
	mov r12, r1
	ldr r1, _080062B0 @ =0x0202EEB0
	mov r8, r1
	ldr r7, _080062B4 @ =0x08335A8C
	ldr r6, _080062B8 @ =0x08334DCC
	movs r3, #0xE0
	lsls r3, r3, #0x08
	adds r5, r3, #0x0
	.global _08006236
_08006236:
	movs r3, #0x00
	adds r1, r0, #0x0
	adds r1, #0x08
	adds r4, r0, #0x1
	lsls r0, r1, #0x04
	adds r0, r0, r1
	lsls r1, r0, #0x02
	.global _08006244
_08006244:
	adds r0, r1, r3
	adds r0, #0x33
	lsls r0, r0, #0x01
	adds r0, r0, r6
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r7
	ldrh r0, [r0, #0x00]
	orrs r0, r5
	strh r0, [r2, #0x00]
	adds r2, #0x02
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x0A
	bne _08006244
	adds r2, #0x2C
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x06
	bne _08006236
	mov r1, r12
	ldr r0, [r1, #0x00]
	movs r3, #0xEA
	lsls r3, r3, #0x02
	adds r2, r0, r3
	mov r1, r8
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080062A0
	movs r0, #0x00
	movs r1, #0x47
	.global _08006284
_08006284:
	movs r3, #0x00
	adds r4, r0, #0x1
	.global _08006288
_08006288:
	strh r1, [r2, #0x00]
	adds r2, #0x02
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x04
	bne _08006288
	adds r2, #0x38
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x06
	bne _08006284
	.global _080062A0
_080062A0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _080062AC
_080062AC: .4byte 0x08364B08
	.global _080062B0
_080062B0: .4byte 0x0202EEB0
	.global _080062B4
_080062B4: .4byte 0x08335A8C
	.global _080062B8
_080062B8: .4byte 0x08334DCC
	thumb_func_start sub_080062BC
sub_080062BC:
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r0, _08006374 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800636A
	bl sub_080078E4
	adds r1, r0, #0x0
	cmp r1, #0x00
	beq _080062DE
	ldr r0, _08006378 @ =0x08006095
	str r0, [r1, #0x0C]
	adds r0, r1, #0x0
	bl sub_0800793C
	.global _080062DE
_080062DE:
	bl sub_08006214
	ldr r0, _0800637C @ =0x0806C784
	movs r1, #0x00
	movs r2, #0x13
	bl sub_0800649C
	ldr r4, _08006380 @ =0x08331FC8
	ldr r5, _08006384 @ =0x06016280
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0xC0
	bl sub_08016E10
	movs r0, #0xC0
	lsls r0, r0, #0x01
	mov r8, r0
	add r4, r8
	movs r6, #0x80
	lsls r6, r6, #0x03
	adds r5, r5, r6
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0xC0
	bl sub_08016E10
	add r4, r8
	adds r5, r5, r6
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0xC0
	bl sub_08016E10
	add r4, r8
	adds r5, r5, r6
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0xC0
	bl sub_08016E10
	add r4, r8
	adds r5, r5, r6
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0xC0
	bl sub_08016E10
	add r4, r8
	adds r5, r5, r6
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0xC0
	bl sub_08016E10
	add r4, r8
	adds r5, r5, r6
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0xC0
	bl sub_08016E10
	add r4, r8
	adds r5, r5, r6
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0xC0
	bl sub_08016E10
	bl sub_080055B0
	.global _0800636A
_0800636A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _08006374
_08006374: .4byte 0x020020E0
	.global _08006378
_08006378: .4byte 0x08006095
	.global _0800637C
_0800637C: .4byte 0x0806C784
	.global _08006380
_08006380: .4byte 0x08331FC8
	.global _08006384
_08006384: .4byte 0x06016280
