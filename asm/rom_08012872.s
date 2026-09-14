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
	thumb_func_start sub_08012874
sub_08012874:
	push {r4, r5, lr}
	ldr r4, _080128D4 @ =0xFFFFFE00
	add sp, r4
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl sub_0800F3A4
	bl sub_0800F498
	ldr r0, _080128D8 @ =0x082EE104
	mov r1, sp
	bl sub_0800F328
	adds r0, r4, #0x0
	bl sub_080127E4
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r5, #0x40
	.global _080128A0
_080128A0:
	bl sub_0800048C
	adds r0, r4, #0x0
	bl sub_080127E4
	ldr r1, _080128DC @ =0x020005CC
	movs r0, #0x01
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080128B8
	adds r5, r4, #0x0
	.global _080128B8
_080128B8:
	bl sub_08000458
	cmp r5, #0x40
	beq _080128A0
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _080128D4
_080128D4: .4byte 0xFFFFFE00
	.global _080128D8
_080128D8: .4byte 0x082EE104
	.global _080128DC
_080128DC: .4byte 0x020005CC
