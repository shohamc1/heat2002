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
	thumb_func_start sub_08343110
sub_08343110:
	push {r4, lr}
	adds r4, r0, #0x0
	bl sub_08343948
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x28]
	adds r0, r0, r1
	str r0, [r4, #0x00]
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x2C]
	adds r0, r0, r1
	str r0, [r4, #0x04]
	ldr r0, [r4, #0x08]
	ldr r1, [r4, #0x30]
	adds r0, r0, r1
	str r0, [r4, #0x08]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
