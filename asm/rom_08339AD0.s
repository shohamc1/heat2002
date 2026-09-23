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
	thumb_func_start sub_08339AD0
sub_08339AD0:
	push {lr}
	ldr r0, _08339AE8 @ =0x020375D0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08339ADE
	bl _08344B7C
_08339ADE:
	bl sub_08339B04
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08339AE8: .4byte 0x020375D0
