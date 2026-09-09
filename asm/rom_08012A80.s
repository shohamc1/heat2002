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
	thumb_func_start sub_08012A80
sub_08012A80:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r4, _08012AF0 @ =0xFFFFFE00
	add sp, r4
	mov r8, r0
	adds r7, r1, #0x0
	adds r6, r2, #0x0
	movs r0, #0x03
	mov r1, sp
	bl sub_08011C9C
	mov r0, r8
	adds r1, r7, #0x0
	adds r2, r6, #0x0
	bl sub_08012A4C
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r5, #0x40
	.global _08012AAE
_08012AAE:
	bl sub_0800048C
	mov r0, r8
	adds r1, r7, #0x0
	adds r2, r6, #0x0
	bl sub_08012A4C
	ldr r1, _08012AF4 @ =0x020005CC
	movs r0, #0x01
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08012ACA
	movs r5, #0x00
	.global _08012ACA
_08012ACA:
	bl sub_08000458
	lsls r4, r5, #0x18
	cmp r4, #0x00
	bne _08012AAE
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r4, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _08012AF0
_08012AF0: .4byte 0xFFFFFE00
	.global _08012AF4
_08012AF4: .4byte 0x020005CC
