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
	thumb_func_start sub_0833BCD8
sub_0833BCD8:
	adds r1, r0, #0x0
	ldr r2, _0833BCE8 @ =0x020390E4
	cmp r1, #0x00
	beq _0833BCF0
	ldr r0, _0833BCEC @ =0x7FFFFFFF
	ands r0, r1
	b _0833BCF2
	.byte 0x00, 0x00
_0833BCE8: .4byte 0x020390E4
_0833BCEC: .4byte 0x7FFFFFFF
_0833BCF0:
	movs r0, #0x01
_0833BCF2:
	str r0, [r2, #0x00]
	bx lr
	.byte 0x00, 0x00
