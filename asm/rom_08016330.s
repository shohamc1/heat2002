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
	thumb_func_start sub_08016330
sub_08016330:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _080163E8 @ =0xFFFFFE00
	add sp, r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r10, r0
	ldr r4, _080163EC @ =0x06008000
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r0, #0x00
	mov r9, r0
	mov r0, r10
	cmp r0, #0x00
	bne _0801635C
	movs r0, #0x01
	mov r10, r0
	.global _0801635C
_0801635C:
	mov r8, r10
	ldr r0, _080163F0 @ =0x0202EF00
	ldrb r0, [r0, #0x02]
	cmp r0, #0x00
	beq _0801636C
	movs r0, #0x01
	bl sub_08001208
	.global _0801636C
_0801636C:
	movs r0, #0x01
	mov r1, sp
	bl sub_08011D2C
	movs r6, #0x00
	movs r2, #0x00
	movs r1, #0xE0
	lsls r1, r1, #0x02
	.global _0801637C
_0801637C:
	strh r2, [r4, #0x00]
	adds r4, #0x02
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, r1
	bne _0801637C
	ldr r0, _080163F4 @ =0x0829F94C
	bl sub_08006738
	movs r7, #0x14
	movs r6, #0x00
	.global _08016394
_08016394:
	adds r0, r6, r7
	adds r5, r0, #0x0
	subs r5, #0x14
	adds r4, r5, #0x0
	cmp r5, #0x00
	bge _080163A4
	adds r4, r0, #0x0
	adds r4, #0x0B
	.global _080163A4
_080163A4:
	asrs r4, r4, #0x05
	lsls r4, r4, #0x05
	subs r4, r5, r4
	ldr r0, _080163F8 @ =0x0829F2AC
	adds r1, r4, #0x0
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _080163FC @ =0x083FE114
	lsls r1, r5, #0x03
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	ldrb r2, [r1, #0x04]
	adds r1, r4, #0x0
	bl sub_08006950
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0x13
	bls _08016394
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r6, #0x00
	.global _080163D8
_080163D8:
	bl sub_08016E30
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0x13
	bls _080163D8
	b _08016468
	.global _080163E8
_080163E8: .4byte 0xFFFFFE00
	.global _080163EC
_080163EC: .4byte 0x06008000
	.global _080163F0
_080163F0: .4byte 0x0202EF00
	.global _080163F4
_080163F4: .4byte 0x0829F94C
	.global _080163F8
_080163F8: .4byte 0x0829F2AC
	.global _080163FC
_080163FC: .4byte 0x083FE114
	.global _08016400
_08016400:
	mov r0, r8
	subs r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0x00
	bne _08016464
	mov r8, r10
	mov r0, r9
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r9, r0
	cmp r0, #0x07
	bls _08016458
	movs r0, #0x00
	mov r9, r0
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0xB6
	beq _08016478
	ldr r0, _08016498 @ =0x0829F2AC
	subs r5, r7, #0x1
	adds r4, r5, #0x0
	cmp r5, #0x00
	bge _0801643A
	adds r4, r7, #0x0
	adds r4, #0x1E
	.global _0801643A
_0801643A:
	asrs r4, r4, #0x05
	lsls r4, r4, #0x05
	subs r4, r5, r4
	adds r1, r4, #0x0
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _0801649C @ =0x083FE114
	lsls r1, r5, #0x03
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	ldrb r2, [r1, #0x04]
	adds r1, r4, #0x0
	bl sub_08006950
	.global _08016458
_08016458:
	ldr r1, _080164A0 @ =0x04000012
	adds r0, r7, #0x0
	subs r0, #0x14
	lsls r0, r0, #0x03
	add r0, r9
	strh r0, [r1, #0x00]
	.global _08016464
_08016464:
	bl sub_08016E30
	.global _08016468
_08016468:
	bl sub_0800048C
	ldr r1, _080164A4 @ =0x020005CC
	movs r0, #0x02
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08016400
	.global _08016478
_08016478:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	bl sub_08015304
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08016498
_08016498: .4byte 0x0829F2AC
	.global _0801649C
_0801649C: .4byte 0x083FE114
	.global _080164A0
_080164A0: .4byte 0x04000012
	.global _080164A4
_080164A4: .4byte 0x020005CC
