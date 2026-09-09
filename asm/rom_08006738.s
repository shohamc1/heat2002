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

	thumb_func_start sub_08006738
sub_08006738:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r3, r0, #0x0
	ldr r0, _08006930 @ =0x06008040
	mov r12, r0
	movs r6, #0xF0
	lsls r6, r6, #0x08
	movs r5, #0x00
	ldrb r1, [r3, #0x00]
	adds r3, #0x01
	ldr r2, _08006934 @ =0x0836533C
	mov r9, r2
	ldr r0, _08006938 @ =0x08365344
	mov r10, r0
	cmp r1, #0x00
	beq _080067BC
	ldr r7, _0800693C @ =0x08333208
	ldr r2, _08006940 @ =0x08332DC8
	mov r8, r2
	.global _08006764
_08006764:
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
	bne _08006764
	.global _080067BC
_080067BC:
	mov r0, r9
	ldr r3, [r0, #0x00]
	ldrb r1, [r3, #0x00]
	adds r3, #0x01
	cmp r1, #0x00
	beq _08006826
	ldr r7, _0800693C @ =0x08333208
	ldr r2, _08006940 @ =0x08332DC8
	mov r8, r2
	.global _080067CE
_080067CE:
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
	bne _080067CE
	.global _08006826
_08006826:
	cmp r5, #0x1F
	bhi _0800688A
	ldr r3, _0800693C @ =0x08333208
	ldr r0, _08006944 @ =0x08365340
	mov r8, r0
	ldr r7, _08006940 @ =0x08332DC8
	.global _08006832
_08006832:
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
	bls _08006832
	.global _0800688A
_0800688A:
	mov r0, r10
	ldr r3, [r0, #0x00]
	ldr r1, _08006948 @ =0x06008440
	mov r12, r1
	ldrb r0, [r3, #0x00]
	adds r3, #0x01
	cmp r0, #0x00
	beq _080068F6
	ldr r0, _08006940 @ =0x08332DC8
	adds r4, r0, #0x0
	adds r4, #0xC0
	ldr r5, _0800693C @ =0x08333208
	movs r2, #0x80
	lsls r2, r2, #0x01
	adds r7, r0, r2
	.global _080068A8
_080068A8:
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
	bne _080068A8
	.global _080068F6
_080068F6:
	ldr r2, _0800694C @ =0x06008000
	mov r12, r2
	movs r2, #0x00
	ldr r5, _0800693C @ =0x08333208
	adds r3, r4, #0x0
	adds r3, #0x40
	.global _08006902
_08006902:
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
	bne _08006902
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08006930
_08006930: .4byte 0x06008040
	.global _08006934
_08006934: .4byte 0x0836533C
	.global _08006938
_08006938: .4byte 0x08365344
	.global _0800693C
_0800693C: .4byte 0x08333208
	.global _08006940
_08006940: .4byte 0x08332DC8
	.global _08006944
_08006944: .4byte 0x08365340
	.global _08006948
_08006948: .4byte 0x06008440
	.global _0800694C
_0800694C: .4byte 0x06008000
	thumb_func_start sub_08006950
sub_08006950:
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	adds r1, r4, #0x0
	movs r3, #0x00
	ldrb r0, [r4, #0x00]
	ldr r2, _080069CC @ =0x08364B08
	cmp r0, #0x00
	beq _08006974
	.global _08006966
_08006966:
	adds r1, #0x01
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08006966
	.global _08006974
_08006974:
	movs r0, #0x1E
	subs r0, r0, r3
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r0, r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, [r2, #0x00]
	lsls r1, r5, #0x05
	adds r1, r1, r0
	lsls r1, r1, #0x01
	adds r3, r3, r1
	movs r2, #0xE0
	lsls r2, r2, #0x08
	cmp r6, #0x00
	beq _08006998
	movs r2, #0xF0
	lsls r2, r2, #0x08
	.global _08006998
_08006998:
	ldrb r0, [r4, #0x00]
	adds r4, #0x01
	cmp r0, #0x00
	beq _080069C4
	ldr r6, _080069D0 @ =0x08332DC8
	ldr r5, _080069D4 @ =0x08333208
	.global _080069A4
_080069A4:
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r5
	adds r0, r2, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r3, #0x00]
	adds r3, #0x02
	ldrb r0, [r4, #0x00]
	adds r4, #0x01
	cmp r0, #0x00
	bne _080069A4
	.global _080069C4
_080069C4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _080069CC
_080069CC: .4byte 0x08364B08
	.global _080069D0
_080069D0: .4byte 0x08332DC8
	.global _080069D4
_080069D4: .4byte 0x08333208
	.byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x05, 0x04, 0x0C, 0x04, 0x12, 0x04, 0x1B, 0x04, 0x52, 0x1B
	.byte 0x12, 0x11, 0x90, 0x46, 0x1B, 0x1B, 0x1F, 0x11, 0x00, 0x26, 0x28, 0x1C, 0x21, 0x1C, 0x02, 0x22
	.byte 0x05, 0xF0, 0x10, 0xFC, 0x45, 0x44, 0xE4, 0x19, 0x70, 0x1C, 0x00, 0x06, 0x06, 0x0E, 0x10, 0x2E
	.byte 0xF3, 0xD1, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47
