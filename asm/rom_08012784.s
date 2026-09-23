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
	thumb_func_start sub_08012784
sub_08012784:
	push {r4, r5, r6, lr}
	ldr r4, _080127DC @ =0xFFFFFE00
	add sp, r4
	movs r0, #0x00
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_08012758
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r6, #0x40
	movs r5, #0x00
_080127A4:
	bl sub_0800048C
	asrs r0, r5, #0x18
	bl sub_08012758
	ldr r1, _080127E0 @ =0x020005CC
	movs r0, #0x01
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080127BC
	lsrs r6, r5, #0x18
_080127BC:
	bl sub_08000458
	lsls r4, r6, #0x18
	cmp r4, #0x00
	bne _080127A4
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r4, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_080127DC: .4byte 0xFFFFFE00
_080127E0: .4byte 0x020005CC
