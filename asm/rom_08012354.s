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
	thumb_func_start sub_08012354
sub_08012354:
	push {lr}
	mov r12, r4
	ldr r4, _08012380 @ =0xFFFFFE00
	add sp, r4
	mov r4, r12
	movs r0, #0x04
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_08011F78
	mov r0, sp
	movs r1, #0x0F
	bl FadeToBrightenedPalette
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08012380: .4byte 0xFFFFFE00
