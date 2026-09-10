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
