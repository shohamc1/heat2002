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
	thumb_func_start sub_0833FFA8
sub_0833FFA8:
	ldr r1, [r0, #0x14]
	ldr r2, [r0, #0x10]
	cmp r2, #0x00
	beq _0833FFB4
	str r1, [r2, #0x14]
	b _0833FFB8
_0833FFB4:
	ldr r0, _0833FFC0 @ =0x0203C380
	str r1, [r0, #0x00]
_0833FFB8:
	cmp r1, #0x00
	beq _0833FFBE
	str r2, [r1, #0x10]
_0833FFBE:
	bx lr
_0833FFC0: .4byte 0x0203C380
