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
	thumb_func_start sub_0800F22C
sub_0800F22C:
	push {r4, r5, r6, r7, lr}
	ldr r4, _0800F2B0 @ =0xFFFFFE00
	add sp, r4
	movs r4, #0x00
	movs r0, #0x06
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_0800F1EC
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r6, #0x40
	ldr r7, _0800F2B4 @ =0x020005CC
	.global _0800F24E
_0800F24E:
	bl sub_0800048C
	lsls r5, r4, #0x18
	lsrs r4, r5, #0x18
	adds r0, r4, #0x0
	bl sub_0800F1EC
	ldrh r1, [r7, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0800F268
	adds r6, r4, #0x0
	.global _0800F268
_0800F268:
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _0800F272
	movs r6, #0x0A
	.global _0800F272
_0800F272:
	ldrh r0, [r7, #0x00]
	asrs r1, r5, #0x18
	movs r2, #0x00
	movs r3, #0x01
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_08000458
	lsls r5, r6, #0x18
	cmp r6, #0x40
	beq _0800F24E
	ldr r0, _0800F2B8 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0800F29A
	movs r0, #0x09
	bl sub_08001208
	.global _0800F29A
_0800F29A:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r5, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _0800F2B0
_0800F2B0: .4byte 0xFFFFFE00
	.global _0800F2B4
_0800F2B4: .4byte 0x020005CC
	.global _0800F2B8
_0800F2B8: .4byte 0x0202EF00
	thumb_func_start sub_0800F2BC
sub_0800F2BC:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _0800F2E4 @ =0x083FDCDD
	adds r0, r4, r3
	ldrb r0, [r0, #0x00]
	subs r0, #0x01
	cmp r1, r0
	blt _0800F2EC
	bl sub_0800F1B4
	ldr r0, _0800F2E8 @ =0x0202EF20
	adds r0, r4, r0
	movs r1, #0x00
	strb r1, [r0, #0x00]
	movs r0, #0x01
	b _0800F31A
	.byte 0x00, 0x00
	.global _0800F2E4
_0800F2E4: .4byte 0x083FDCDD
	.global _0800F2E8
_0800F2E8: .4byte 0x0202EF20
	.global _0800F2EC
_0800F2EC:
	movs r2, #0x00
	adds r6, r3, #0x0
	ldr r5, _0800F320 @ =0x0202EF20
	movs r3, #0x01
	.global _0800F2F4
_0800F2F4:
	adds r0, r2, r6
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bcs _0800F300
	adds r0, r2, r5
	strb r3, [r0, #0x00]
	.global _0800F300
_0800F300:
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x11
	bne _0800F2F4
	bl sub_0800F1D0
	ldr r0, _0800F324 @ =0x083FDCCC
	adds r0, r4, r0
	ldrb r0, [r0, #0x00]
	bl sub_0800F14C
	movs r0, #0x00
	.global _0800F31A
_0800F31A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.global _0800F320
_0800F320: .4byte 0x0202EF20
	.global _0800F324
_0800F324: .4byte 0x083FDCCC
	thumb_func_start sub_0800F328
sub_0800F328:
	push {r4, r5, lr}
	adds r5, r1, #0x0
	movs r2, #0x80
	lsls r2, r2, #0x01
	bl sub_08016E10
	ldr r4, _0800F3A0 @ =0x08332BC8
	movs r0, #0xF0
	lsls r0, r0, #0x01
	adds r1, r5, r0
	adds r0, r4, #0x0
	movs r2, #0x10
	bl sub_08016E10
	movs r2, #0xE0
	lsls r2, r2, #0x01
	adds r1, r5, r2
	adds r0, r4, #0x0
	movs r2, #0x10
	bl sub_08016E10
	movs r0, #0x34
	movs r1, #0x34
	movs r2, #0x34
	bl sub_08011C44
	movs r2, #0xEA
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	movs r0, #0x24
	movs r1, #0x24
	movs r2, #0x24
	bl sub_08011C44
	movs r2, #0xEB
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	movs r0, #0x0E
	movs r1, #0x0E
	movs r2, #0x0E
	bl sub_08011C44
	movs r2, #0xEC
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl sub_08011C44
	movs r2, #0xED
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _0800F3A0
_0800F3A0: .4byte 0x08332BC8
