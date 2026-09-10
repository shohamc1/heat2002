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
	thumb_func_start sub_08012B50
sub_08012B50:
	push {r4, r5, r6, r7, lr}
	ldr r4, _08012BB4 @ =0xFFFFFE00
	add sp, r4
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0x03
	mov r1, sp
	bl sub_08011C9C
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	bl sub_08012AF8
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r6, #0x40
	.global _08012B7A
_08012B7A:
	bl sub_0800048C
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	bl sub_08012AF8
	ldr r1, _08012BB8 @ =0x020005CC
	movs r0, #0x01
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08012B94
	adds r6, r4, #0x0
	.global _08012B94
_08012B94:
	bl sub_08000458
	lsls r5, r6, #0x18
	cmp r6, #0x40
	beq _08012B7A
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
	.global _08012BB4
_08012BB4: .4byte 0xFFFFFE00
	.global _08012BB8
_08012BB8: .4byte 0x020005CC
