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
	thumb_func_start sub_083399E8
sub_083399E8:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	muls r0, r1
	adds r1, r0, #0x0
	cmp r0, #0x00
	bge _083399FA
	adds r1, #0xFF
_083399FA:
	lsls r0, r1, #0x08
	asrs r0, r0, #0x10
	bx lr
	thumb_func_start sub_08339A00
sub_08339A00:
	push {lr}
	lsls r0, r0, #0x10
	asrs r0, r0, #0x08
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_08344BB8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
