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
	thumb_func_start sub_080065A8
sub_080065A8:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0x0
	ldr r0, _08006724 @ =0x08364B08
	ldr r0, [r0, #0x00]
	adds r0, #0x40
	mov r12, r0
	movs r6, #0xF0
	lsls r6, r6, #0x08
	movs r5, #0x00
	adds r1, r4, #0x0
	movs r2, #0x00
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080065D6
	.global _080065CC
_080065CC:
	adds r1, #0x01
	adds r2, #0x01
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080065CC
	.global _080065D6
_080065D6:
	movs r0, #0x1E
	subs r0, r0, r2
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r0, r0, #0x01
	adds r1, r4, #0x1
	mov r9, r1
	cmp r5, r0
	bge _0800664A
	ldr r7, _08006728 @ =0x08333208
	mov r8, r0
	ldr r2, _0800672C @ =0x08332DC8
	mov r10, r2
	.global _080065F0
_080065F0:
	ldr r1, _08006730 @ =0x08365340
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
	mov r1, r10
	adds r3, r0, r1
	ldrh r2, [r3, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r7
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	mov r1, r12
	strh r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x40
	adds r0, r3, #0x0
	adds r0, #0x40
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r7
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r2, #0x00]
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r2, #0x02
	add r12, r2
	cmp r5, r8
	blt _080065F0
	.global _0800664A
_0800664A:
	ldrb r1, [r4, #0x00]
	mov r4, r9
	cmp r1, #0x00
	beq _080066B0
	ldr r7, _08006728 @ =0x08333208
	ldr r0, _0800672C @ =0x08332DC8
	mov r8, r0
	.global _08006658
_08006658:
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
	adds r3, r0, r1
	ldrh r2, [r3, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r7
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	mov r1, r12
	strh r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x40
	adds r0, r3, #0x0
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
	ldrb r1, [r4, #0x00]
	adds r4, #0x01
	cmp r1, #0x00
	bne _08006658
	.global _080066B0
_080066B0:
	cmp r5, #0x1F
	bhi _08006714
	ldr r4, _08006728 @ =0x08333208
	ldr r0, _08006730 @ =0x08365340
	mov r8, r0
	ldr r7, _0800672C @ =0x08332DC8
	.global _080066BC
_080066BC:
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
	adds r3, r0, r7
	ldrh r0, [r3, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r4
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	mov r1, r12
	strh r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x40
	adds r0, r3, #0x0
	adds r0, #0x40
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r4
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
	bls _080066BC
	.global _08006714
_08006714:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08006724
_08006724: .4byte 0x08364B08
	.global _08006728
_08006728: .4byte 0x08333208
	.global _0800672C
_0800672C: .4byte 0x08332DC8
	.global _08006730
_08006730: .4byte 0x08365340
