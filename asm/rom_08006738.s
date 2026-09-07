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
	thumb_func_start sub_08006A14
sub_08006A14:
	ldr r2, _08006A28 @ =0x020253D0
	ldr r1, _08006A2C @ =0x083671C0
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	ldr r1, _08006A30 @ =0x02025240
	movs r0, #0x14
	strb r0, [r1, #0x00]
	bx lr
	.global _08006A28
_08006A28: .4byte 0x020253D0
	.global _08006A2C
_08006A2C: .4byte 0x083671C0
	.global _08006A30
_08006A30: .4byte 0x02025240
	thumb_func_start sub_08006A34
sub_08006A34:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x094
	adds r7, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x054]
	ldr r1, _08006A6C @ =0x0202EF00
	movs r0, #0x03
	ldrb r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x058]
	ldr r2, _08006A70 @ =0x020020BC
	movs r0, #0x00
	strb r0, [r2, #0x00]
	ldr r0, _08006A74 @ =0x020020DC
	ldrb r1, [r0, #0x00]
	adds r2, r0, #0x0
	cmp r1, #0x00
	beq _08006A7C
	ldr r0, _08006A78 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	b _08006A7E
	.global _08006A6C
_08006A6C: .4byte 0x0202EF00
	.global _08006A70
_08006A70: .4byte 0x020020BC
	.global _08006A74
_08006A74: .4byte 0x020020DC
	.global _08006A78
_08006A78: .4byte 0x0202EF90
	.global _08006A7C
_08006A7C:
	movs r0, #0x00
	.global _08006A7E
_08006A7E:
	str r0, [sp, #0x06C]
	ldrb r0, [r2, #0x00]
	cmp r0, #0x00
	beq _08006A90
	ldr r0, _08006A8C @ =0x020020AC
	b _08006A92
	.byte 0x00, 0x00
	.global _08006A8C
_08006A8C: .4byte 0x020020AC
	.global _08006A90
_08006A90:
	ldr r0, _08006BC4 @ =0x02002090
	.global _08006A92
_08006A92:
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x068]
	ldr r2, _08006BC8 @ =0x020253D0
	adds r1, r7, #0x0
	adds r1, #0x4D
	ldrb r3, [r1, #0x00]
	lsls r0, r3, #0x01
	adds r0, r0, r3
	lsls r0, r0, #0x03
	ldr r2, [r2, #0x00]
	adds r0, r2, r0
	str r0, [sp, #0x064]
	adds r3, r0, #0x0
	adds r3, #0x18
	str r1, [sp, #0x07C]
	ldrh r4, [r0, #0x10]
	cmp r4, #0x01
	bne _08006AB8
	adds r3, r2, #0x0
	.global _08006AB8
_08006AB8:
	add r1, sp, #0x028
	ldr r5, [r7, #0x00]
	asrs r0, r5, #0x10
	str r0, [sp, #0x028]
	ldr r6, [r7, #0x08]
	asrs r0, r6, #0x10
	mov r12, r0
	str r0, [r1, #0x04]
	ldr r0, [r7, #0x0C]
	adds r5, r5, r0
	asrs r5, r5, #0x10
	str r5, [r1, #0x08]
	ldr r0, [r7, #0x14]
	adds r6, r6, r0
	asrs r6, r6, #0x10
	str r6, [sp, #0x090]
	str r6, [r1, #0x0C]
	ldr r1, [sp, #0x064]
	ldr r0, [r1, #0x00]
	ldr r2, [r1, #0x04]
	str r2, [sp, #0x084]
	ldr r4, [r1, #0x08]
	ldr r6, [r1, #0x0C]
	str r6, [sp, #0x088]
	ldr r1, [r3, #0x00]
	ldr r2, [r3, #0x04]
	mov r9, r2
	ldr r6, [r3, #0x08]
	mov r8, r6
	ldr r3, [r3, #0x0C]
	mov r10, r3
	adds r2, r7, #0x0
	adds r2, #0x4E
	str r2, [sp, #0x070]
	ldrb r3, [r2, #0x00]
	movs r2, #0x10
	subs r2, r2, r3
	muls r0, r2
	muls r1, r3
	adds r0, r0, r1
	asrs r0, r0, #0x04
	str r0, [sp, #0x05C]
	muls r4, r2
	mov r0, r8
	muls r0, r3
	adds r4, r4, r0
	asrs r4, r4, #0x04
	str r4, [sp, #0x08C]
	ldr r4, [sp, #0x084]
	adds r0, r4, #0x0
	muls r0, r2
	mov r1, r9
	muls r1, r3
	adds r0, r0, r1
	asrs r0, r0, #0x04
	str r0, [sp, #0x060]
	ldr r6, [sp, #0x088]
	muls r2, r6
	mov r0, r10
	muls r0, r3
	adds r2, r2, r0
	asrs r2, r2, #0x04
	movs r0, #0x4C
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	ldr r4, [sp, #0x07C]
	ldrb r4, [r4, #0x00]
	lsls r1, r4, #0x04
	adds r0, r0, r1
	adds r0, r0, r3
	str r0, [r7, #0x50]
	ldr r6, [sp, #0x028]
	mov r9, r6
	mov r0, r9
	subs r0, r5, r0
	str r0, [sp, #0x074]
	ldr r1, [sp, #0x060]
	subs r2, r2, r1
	adds r1, r0, #0x0
	muls r1, r2
	ldr r3, [sp, #0x090]
	mov r4, r12
	subs r3, r3, r4
	mov r10, r3
	ldr r6, [sp, #0x08C]
	ldr r0, [sp, #0x05C]
	subs r3, r6, r0
	mov r0, r10
	muls r0, r3
	subs r4, r1, r0
	ldr r1, [sp, #0x070]
	str r1, [sp, #0x080]
	mov r6, r8
	str r6, [sp, #0x078]
	cmp r4, #0x00
	beq _08006BC0
	mov r0, r12
	ldr r1, [sp, #0x060]
	subs r6, r0, r1
	adds r0, r6, #0x0
	muls r0, r3
	mov r3, r9
	ldr r1, [sp, #0x05C]
	subs r5, r3, r1
	adds r1, r5, #0x0
	muls r1, r2
	subs r0, r0, r1
	lsls r0, r0, #0x08
	adds r1, r4, #0x0
	bl sub_08017230
	movs r2, #0x80
	lsls r2, r2, #0x01
	mov r8, r2
	cmp r0, r8
	bhi _08006BC0
	ldr r3, [sp, #0x074]
	adds r0, r6, #0x0
	muls r0, r3
	mov r1, r10
	muls r1, r5
	subs r0, r0, r1
	lsls r0, r0, #0x08
	adds r1, r4, #0x0
	bl sub_08017230
	cmp r0, r8
	bls _08006BCC
	.global _08006BC0
_08006BC0:
	movs r0, #0x00
	b _080072BE
	.global _08006BC4
_08006BC4: .4byte 0x02002090
	.global _08006BC8
_08006BC8: .4byte 0x020253D0
	.global _08006BCC
_08006BCC:
	movs r4, #0xBA
	lsls r4, r4, #0x01
	adds r1, r7, r4
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08006BE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _08006F08 @ =0x0202CAF0
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	.global _08006BE4
_08006BE4:
	ldr r6, [sp, #0x080]
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	strb r0, [r6, #0x00]
	movs r0, #0x01
	ldr r1, _08006F0C @ =0x020020BC
	strb r0, [r1, #0x00]
	ldr r2, [sp, #0x078]
	movs r0, #0x00
	ldsb r0, [r2, r0]
	lsls r0, r0, #0x10
	ldr r3, [sp, #0x07C]
	ldrb r3, [r3, #0x00]
	lsls r1, r3, #0x04
	adds r0, r0, r1
	ldrb r4, [r6, #0x00]
	adds r0, r4, r0
	str r0, [r7, #0x50]
	ldrb r6, [r6, #0x00]
	cmp r6, #0x10
	beq _08006C10
	b _080072BC
	.global _08006C10
_08006C10:
	movs r0, #0x00
	ldr r1, [sp, #0x080]
	strb r0, [r1, #0x00]
	ldr r0, _08006F10 @ =0x0202A550
	cmp r7, r0
	bne _08006C42
	ldr r0, _08006F14 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x10
	bne _08006C42
	ldr r0, _08006F18 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	bne _08006C42
	ldr r0, _08006F1C @ =0x0202CB40
	ldr r2, [sp, #0x07C]
	ldrb r2, [r2, #0x00]
	lsls r4, r2, #0x02
	adds r4, r4, r0
	ldr r0, [r7, #0x2C]
	negs r0, r0
	ldr r1, _08006F20 @ =0x00001B58
	bl sub_08017230
	str r0, [r4, #0x00]
	.global _08006C42
_08006C42:
	ldrh r0, [r7, #0x34]
	strh r0, [r7, #0x36]
	ldr r3, [sp, #0x07C]
	ldrb r0, [r3, #0x00]
	strh r0, [r7, #0x38]
	ldr r4, [sp, #0x064]
	ldrh r3, [r4, #0x10]
	cmp r3, #0x01
	beq _08006C56
	b _08007224
	.global _08006C56
_08006C56:
	movs r6, #0xBE
	lsls r6, r6, #0x01
	adds r1, r7, r6
	ldr r0, _08006F24 @ =0x020253B8
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, _08006F10 @ =0x0202A550
	cmp r7, r0
	bne _08006C72
	ldr r1, _08006F28 @ =0x0202524C
	movs r2, #0x01
	negs r2, r2
	adds r0, r2, #0x0
	strb r0, [r1, #0x00]
	.global _08006C72
_08006C72:
	ldr r0, _08006F14 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0C
	bne _08006CA6
	ldr r1, _08006F2C @ =0x02025218
	ldr r0, _08006F30 @ =0x0000EA60
	ldrh r1, [r1, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	ldr r0, _08006F34 @ =0x020251FC
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, r2, r0
	ldr r0, _08006F38 @ =0x020253CC
	ldrh r0, [r0, #0x00]
	adds r1, r0, r2
	ldr r0, _08006F3C @ =0x0202ED84
	ldr r0, [r0, #0x00]
	cmp r1, r0
	bcs _08006CA6
	ldr r0, _08006F40 @ =0x0202EEE4
	strb r3, [r0, #0x00]
	.global _08006CA6
_08006CA6:
	ldr r3, [sp, #0x054]
	ldr r4, [sp, #0x06C]
	cmp r3, r4
	bne _08006CD6
	ldr r0, _08006F14 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0C
	beq _08006CD6
	movs r6, #0xB3
	lsls r6, r6, #0x01
	adds r0, r7, r6
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08006CD6
	ldr r0, _08006F44 @ =0x00000167
	adds r1, r7, r0
	movs r0, #0x1E
	strb r0, [r1, #0x00]
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r1, r7, r2
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	.global _08006CD6
_08006CD6:
	ldr r3, [sp, #0x078]
	ldrb r0, [r3, #0x00]
	adds r0, #0x01
	movs r1, #0x00
	strb r0, [r3, #0x00]
	subs r0, r1, #0x1
	ldr r4, [sp, #0x07C]
	strb r0, [r4, #0x00]
	ldr r6, [sp, #0x080]
	strb r1, [r6, #0x00]
	movs r0, #0x00
	ldsb r0, [r3, r0]
	lsls r0, r0, #0x10
	ldrb r2, [r4, #0x00]
	lsls r1, r2, #0x04
	adds r0, r0, r1
	str r0, [r7, #0x50]
	ldr r3, [sp, #0x054]
	ldr r4, [sp, #0x06C]
	cmp r3, r4
	bne _08006D24
	ldr r0, _08006F48 @ =0x0202F030
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08006D24
	movs r6, #0xC7
	lsls r6, r6, #0x01
	adds r0, r7, r6
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08006D24
	ldr r0, _08006F2C @ =0x02025218
	ldrh r0, [r0, #0x00]
	ldr r1, _08006F34 @ =0x020251FC
	ldrh r1, [r1, #0x00]
	ldr r2, _08006F38 @ =0x020253CC
	ldrh r2, [r2, #0x00]
	bl sub_08005664
	.global _08006D24
_08006D24:
	ldr r0, _08006F14 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x10
	beq _08006D2E
	b _08007066
	.global _08006D2E
_08006D2E:
	ldr r0, _08006F18 @ =0x0202ED70
	ldrb r3, [r0, #0x00]
	cmp r3, #0x01
	bne _08006D66
	ldr r1, _08006F2C @ =0x02025218
	ldr r0, _08006F30 @ =0x0000EA60
	ldrh r1, [r1, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	ldr r0, _08006F34 @ =0x020251FC
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, r2, r0
	ldr r0, _08006F38 @ =0x020253CC
	ldrh r0, [r0, #0x00]
	adds r2, r0, r2
	movs r0, #0xFA
	lsls r0, r0, #0x07
	cmp r2, r0
	bgt _08006D62
	ldr r0, _08006F40 @ =0x0202EEE4
	strb r3, [r0, #0x00]
	.global _08006D62
_08006D62:
	bl sub_0800AFF0
	.global _08006D66
_08006D66:
	ldr r0, _08006F18 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _08006D9A
	ldr r0, [sp, #0x054]
	cmp r0, #0x00
	bne _08006D9A
	ldr r2, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r2, r1]
	ldr r0, _08006F4C @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bne _08006D9A
	bl sub_0800AFF0
	ldr r0, _08006F10 @ =0x0202A550
	movs r3, #0xA8
	lsls r3, r3, #0x01
	adds r0, r0, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bhi _08006D9A
	ldr r1, _08006F40 @ =0x0202EEE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _08006D9A
_08006D9A:
	ldr r0, _08006F18 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _08006DD6
	ldr r4, [sp, #0x054]
	cmp r4, #0x00
	bne _08006DD6
	ldr r6, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r6, r1]
	ldr r0, _08006F4C @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bne _08006DD6
	ldr r0, _08006F10 @ =0x0202A550
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08006DD2
	ldr r0, _08006F50 @ =0x0202CBD0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08006DD2
	ldr r1, _08006F40 @ =0x0202EEE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _08006DD2
_08006DD2:
	bl sub_0800AFF0
	.global _08006DD6
_08006DD6:
	ldr r0, _08006F18 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x05
	bne _08006E0C
	ldr r0, _08006F10 @ =0x0202A550
	cmp r7, r0
	bne _08006E0C
	movs r2, #0xB3
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08006DFA
	ldr r1, _08006F40 @ =0x0202EEE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bl sub_0800AFF0
	.global _08006DFA
_08006DFA:
	ldr r3, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r3, r1]
	ldr r0, _08006F4C @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bne _08006E0C
	bl sub_0800AFF0
	.global _08006E0C
_08006E0C:
	ldr r0, _08006F18 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x06
	bne _08006E40
	ldr r4, [sp, #0x054]
	cmp r4, #0x00
	bne _08006E40
	ldr r6, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r6, r1]
	ldr r0, _08006F4C @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bne _08006E40
	bl sub_0800AFF0
	ldr r0, _08006F10 @ =0x0202A550
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08006E40
	ldr r1, _08006F40 @ =0x0202EEE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _08006E40
_08006E40:
	ldr r0, _08006F18 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x07
	bne _08006E78
	ldr r1, _08006F2C @ =0x02025218
	ldr r0, _08006F30 @ =0x0000EA60
	ldrh r1, [r1, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	ldr r0, _08006F34 @ =0x020251FC
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, r2, r0
	ldr r0, _08006F38 @ =0x020253CC
	ldrh r0, [r0, #0x00]
	adds r2, r0, r2
	ldr r0, _08006F54 @ =0x000068CE
	cmp r2, r0
	bgt _08006E78
	ldr r1, _08006F40 @ =0x0202EEE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bl sub_0800AFF0
	.global _08006E78
_08006E78:
	ldr r0, _08006F18 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x08
	bne _08006EB0
	ldr r1, _08006F2C @ =0x02025218
	ldr r0, _08006F30 @ =0x0000EA60
	ldrh r1, [r1, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	ldr r0, _08006F34 @ =0x020251FC
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, r2, r0
	ldr r0, _08006F38 @ =0x020253CC
	ldrh r0, [r0, #0x00]
	adds r2, r0, r2
	ldr r0, _08006F58 @ =0x00006E87
	cmp r2, r0
	bgt _08006EB0
	ldr r1, _08006F40 @ =0x0202EEE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bl sub_0800AFF0
	.global _08006EB0
_08006EB0:
	ldr r0, _08006F18 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0A
	bne _08006EE2
	ldr r0, _08006F10 @ =0x0202A550
	cmp r7, r0
	bne _08006EE2
	ldr r2, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r2, r1]
	ldr r0, _08006F4C @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bne _08006EE2
	movs r3, #0xA8
	lsls r3, r3, #0x01
	adds r0, r7, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08006EDE
	ldr r1, _08006F40 @ =0x0202EEE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _08006EDE
_08006EDE:
	bl sub_0800AFF0
	.global _08006EE2
_08006EE2:
	ldr r0, _08006F18 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0B
	bne _08006F6A
	ldr r0, _08006F10 @ =0x0202A550
	cmp r7, r0
	bne _08006F6A
	ldr r4, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r4, r1]
	ldr r0, _08006F4C @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bne _08006F6A
	movs r6, #0xA8
	lsls r6, r6, #0x01
	adds r0, r7, r6
	ldrb r0, [r0, #0x00]
	b _08006F5C
	.global _08006F08
_08006F08: .4byte 0x0202CAF0
	.global _08006F0C
_08006F0C: .4byte 0x020020BC
	.global _08006F10
_08006F10: .4byte 0x0202A550
	.global _08006F14
_08006F14: .4byte 0x0200215C
	.global _08006F18
_08006F18: .4byte 0x0202ED70
	.global _08006F1C
_08006F1C: .4byte 0x0202CB40
	.global _08006F20
_08006F20: .4byte 0x00001B58
	.global _08006F24
_08006F24: .4byte 0x020253B8
	.global _08006F28
_08006F28: .4byte 0x0202524C
	.global _08006F2C
_08006F2C: .4byte 0x02025218
	.global _08006F30
_08006F30: .4byte 0x0000EA60
	.global _08006F34
_08006F34: .4byte 0x020251FC
	.global _08006F38
_08006F38: .4byte 0x020253CC
	.global _08006F3C
_08006F3C: .4byte 0x0202ED84
	.global _08006F40
_08006F40: .4byte 0x0202EEE4
	.global _08006F44
_08006F44: .4byte 0x00000167
	.global _08006F48
_08006F48: .4byte 0x0202F030
	.global _08006F4C
_08006F4C: .4byte 0x02002184
	.global _08006F50
_08006F50: .4byte 0x0202CBD0
	.global _08006F54
_08006F54: .4byte 0x000068CE
	.global _08006F58
_08006F58: .4byte 0x00006E87
	.global _08006F5C
_08006F5C:
	cmp r0, #0x00
	bne _08006F66
	ldr r1, _080071BC @ =0x0202EEE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _08006F66
_08006F66:
	bl sub_0800AFF0
	.global _08006F6A
_08006F6A:
	ldr r0, _080071C0 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0C
	bne _08006FA0
	ldr r0, _080071C4 @ =0x0202A550
	cmp r7, r0
	bne _08006FA0
	movs r1, #0xB3
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08006F8E
	ldr r1, _080071BC @ =0x0202EEE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bl sub_0800AFF0
	.global _08006F8E
_08006F8E:
	ldr r2, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r2, r1]
	ldr r0, _080071C8 @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bne _08006FA0
	bl sub_0800AFF0
	.global _08006FA0
_08006FA0:
	ldr r0, _080071C0 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0D
	bne _08006FD2
	ldr r0, _080071C4 @ =0x0202A550
	cmp r7, r0
	bne _08006FD2
	ldr r3, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r3, r1]
	ldr r0, _080071C8 @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bne _08006FD2
	movs r4, #0xA8
	lsls r4, r4, #0x01
	adds r0, r7, r4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08006FCE
	ldr r1, _080071BC @ =0x0202EEE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _08006FCE
_08006FCE:
	bl sub_0800AFF0
	.global _08006FD2
_08006FD2:
	ldr r0, _080071C0 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0E
	bne _0800701C
	ldr r0, _080071C4 @ =0x0202A550
	cmp r7, r0
	bne _0800701C
	movs r6, #0xA8
	lsls r6, r6, #0x01
	adds r0, r7, r6
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08007004
	ldr r0, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r0, r1]
	ldr r0, _080071C8 @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bne _08007004
	ldr r1, _080071BC @ =0x0202EEE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bl sub_0800AFF0
	.global _08007004
_08007004:
	ldr r0, _080071C4 @ =0x0202A550
	cmp r7, r0
	bne _0800701C
	ldr r2, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r2, r1]
	ldr r0, _080071C8 @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bne _0800701C
	bl sub_0800AFF0
	.global _0800701C
_0800701C:
	ldr r0, _080071C0 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0F
	bne _08007066
	ldr r0, _080071C4 @ =0x0202A550
	cmp r7, r0
	bne _08007066
	movs r3, #0xA8
	lsls r3, r3, #0x01
	adds r0, r7, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800704E
	ldr r4, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r4, r1]
	ldr r0, _080071C8 @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bne _0800704E
	ldr r1, _080071BC @ =0x0202EEE4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bl sub_0800AFF0
	.global _0800704E
_0800704E:
	ldr r0, _080071C4 @ =0x0202A550
	cmp r7, r0
	bne _08007066
	ldr r6, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r6, r1]
	ldr r0, _080071C8 @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bne _08007066
	bl sub_0800AFF0
	.global _08007066
_08007066:
	movs r0, #0xB3
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _080071C4 @ =0x0202A550
	cmp r7, r0
	bne _080070B8
	ldr r0, _080071CC @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x05
	bne _080070B8
	movs r1, #0xC7
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080070B8
	ldr r1, _080071D0 @ =0x02025218
	ldr r0, _080071D4 @ =0x0000EA60
	ldrh r1, [r1, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	ldr r0, _080071D8 @ =0x020251FC
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, r2, r0
	ldr r0, _080071DC @ =0x020253CC
	ldrh r0, [r0, #0x00]
	adds r1, r0, r2
	movs r3, #0xB6
	lsls r3, r3, #0x01
	adds r2, r7, r3
	ldr r0, [r2, #0x00]
	cmp r1, r0
	bcs _080070B8
	str r1, [r2, #0x00]
	.global _080070B8
_080070B8:
	ldr r4, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r4, r1]
	ldr r0, _080071C8 @ =0x02002184
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	beq _080070C8
	b _080071F4
	.global _080070C8
_080070C8:
	ldr r0, _080071CC @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080070D8
	cmp r0, #0x06
	beq _080070D8
	cmp r0, #0x01
	bne _08007100
	.global _080070D8
_080070D8:
	movs r6, #0xB6
	lsls r6, r6, #0x01
	adds r3, r7, r6
	ldr r1, _080071E0 @ =0x02025260
	ldr r0, _080071D4 @ =0x0000EA60
	ldrh r1, [r1, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	ldr r0, _080071E4 @ =0x02025220
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, r2, r0
	ldr r0, _080071E8 @ =0x02025224
	ldrh r0, [r0, #0x00]
	adds r2, r0, r2
	str r2, [r3, #0x00]
	.global _08007100
_08007100:
	ldr r0, [sp, #0x054]
	ldr r1, [sp, #0x06C]
	cmp r0, r1
	bne _08007124
	movs r2, #0xC7
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08007124
	ldr r0, _080071D0 @ =0x02025218
	ldrh r0, [r0, #0x00]
	ldr r1, _080071D8 @ =0x020251FC
	ldrh r1, [r1, #0x00]
	ldr r2, _080071DC @ =0x020253CC
	ldrh r2, [r2, #0x00]
	bl sub_0800B3D4
	.global _08007124
_08007124:
	ldr r4, _080071CC @ =0x0200215C
	ldrb r3, [r4, #0x00]
	cmp r3, #0x02
	beq _08007218
	adds r0, r7, #0x0
	bl sub_0800A438
	ldr r0, _080071EC @ =0x020253E0
	ldr r1, _080071F0 @ =0x020253D4
	ldrb r6, [r1, #0x00]
	adds r0, r6, r0
	add r2, sp, #0x054
	ldrb r2, [r2, #0x00]
	strb r2, [r0, #0x00]
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	ldrb r0, [r4, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _0800717A
	movs r6, #0xB6
	lsls r6, r6, #0x01
	adds r3, r7, r6
	ldr r1, _080071E0 @ =0x02025260
	ldr r0, _080071D4 @ =0x0000EA60
	ldrh r1, [r1, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	ldr r0, _080071E4 @ =0x02025220
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, r2, r0
	ldr r0, _080071E8 @ =0x02025224
	ldrh r0, [r0, #0x00]
	adds r2, r0, r2
	str r2, [r3, #0x00]
	.global _0800717A
_0800717A:
	ldr r0, [sp, #0x054]
	ldr r1, [sp, #0x06C]
	cmp r0, r1
	bne _08007198
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08007190
	cmp r0, #0x06
	beq _08007190
	cmp r0, #0x01
	bne _08007198
	.global _08007190
_08007190:
	bl sub_08016D28
	bl sub_0800AFF0
	.global _08007198
_08007198:
	ldr r0, _080071F0 @ =0x020253D4
	ldrb r0, [r0, #0x00]
	ldr r2, [sp, #0x068]
	cmp r0, r2
	bne _08007218
	ldr r0, _080071CC @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x10
	beq _08007218
	cmp r0, #0x0F
	beq _08007218
	cmp r0, #0x02
	beq _08007218
	cmp r0, #0x0E
	beq _08007218
	bl sub_0800AFF0
	b _08007218
	.global _080071BC
_080071BC: .4byte 0x0202EEE4
	.global _080071C0
_080071C0: .4byte 0x0202ED70
	.global _080071C4
_080071C4: .4byte 0x0202A550
	.global _080071C8
_080071C8: .4byte 0x02002184
	.global _080071CC
_080071CC: .4byte 0x0200215C
	.global _080071D0
_080071D0: .4byte 0x02025218
	.global _080071D4
_080071D4: .4byte 0x0000EA60
	.global _080071D8
_080071D8: .4byte 0x020251FC
	.global _080071DC
_080071DC: .4byte 0x020253CC
	.global _080071E0
_080071E0: .4byte 0x02025260
	.global _080071E4
_080071E4: .4byte 0x02025220
	.global _080071E8
_080071E8: .4byte 0x02025224
	.global _080071EC
_080071EC: .4byte 0x020253E0
	.global _080071F0
_080071F0: .4byte 0x020253D4
	.global _080071F4
_080071F4:
	ldr r3, [sp, #0x054]
	ldr r4, [sp, #0x06C]
	cmp r3, r4
	bne _08007224
	movs r6, #0xC7
	lsls r6, r6, #0x01
	adds r0, r7, r6
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08007218
	ldr r0, _080072D0 @ =0x02025218
	ldrh r0, [r0, #0x00]
	ldr r1, _080072D4 @ =0x020251FC
	ldrh r1, [r1, #0x00]
	ldr r2, _080072D8 @ =0x020253CC
	ldrh r2, [r2, #0x00]
	bl sub_0800B3D4
	.global _08007218
_08007218:
	ldr r0, [sp, #0x054]
	ldr r1, [sp, #0x06C]
	cmp r0, r1
	bne _08007224
	bl sub_08005560
	.global _08007224
_08007224:
	ldr r3, [sp, #0x064]
	ldrh r2, [r3, #0x10]
	subs r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	bhi _080072B4
	ldr r4, [sp, #0x054]
	ldr r6, [sp, #0x06C]
	cmp r4, r6
	bne _08007294
	ldr r1, _080072DC @ =0x0202CC20
	movs r3, #0xAE
	lsls r3, r3, #0x01
	adds r0, r7, r3
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	beq _08007252
	bl sub_0800B540
	.global _08007252
_08007252:
	ldr r0, _080072E0 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08007270
	ldr r0, _080072E4 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08007270
	ldr r0, _080072E8 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08007270
	movs r0, #0x33
	bl sub_08001208
	.global _08007270
_08007270:
	ldr r4, [sp, #0x054]
	ldr r6, [sp, #0x06C]
	cmp r4, r6
	bne _08007294
	ldr r0, _080072EC @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0A
	beq _08007294
	ldr r1, [sp, #0x058]
	lsrs r0, r1, #0x01
	adds r0, #0x06
	ldr r2, [sp, #0x064]
	ldrb r2, [r2, #0x14]
	adds r0, r2, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_08005598
	.global _08007294
_08007294:
	ldr r3, [sp, #0x064]
	ldrh r5, [r3, #0x10]
	cmp r5, #0x01
	bne _080072B4
	movs r6, #0xC7
	lsls r6, r6, #0x01
	adds r4, r7, r6
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _080072B4
	ldr r0, _080072F0 @ =0x0202A550
	cmp r7, r0
	bne _080072B2
	bl sub_0800B2C4
	.global _080072B2
_080072B2:
	strb r5, [r4, #0x00]
	.global _080072B4
_080072B4:
	ldr r1, [sp, #0x07C]
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	.global _080072BC
_080072BC:
	movs r0, #0x01
	.global _080072BE
_080072BE:
	add sp, #0x094
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _080072D0
_080072D0: .4byte 0x02025218
	.global _080072D4
_080072D4: .4byte 0x020251FC
	.global _080072D8
_080072D8: .4byte 0x020253CC
	.global _080072DC
_080072DC: .4byte 0x0202CC20
	.global _080072E0
_080072E0: .4byte 0x0202EF00
	.global _080072E4
_080072E4: .4byte 0x020020E0
	.global _080072E8
_080072E8: .4byte 0x020021E0
	.global _080072EC
_080072EC: .4byte 0x0200215C
	.global _080072F0
_080072F0: .4byte 0x0202A550
