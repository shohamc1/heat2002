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
	thumb_func_start sub_0833A7F0
sub_0833A7F0:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833A7F4
sub_0833A7F4:
	adds r2, r0, #0x0
	ldr r3, [r2, #0x34]
	ldr r0, _0833A808 @ =0x68736D53
	cmp r3, r0
	bne _0833A806
	ldr r0, [r2, #0x04]
	ldr r1, _0833A80C @ =0x7FFFFFFF
	ands r0, r1
	str r0, [r2, #0x04]
_0833A806:
	bx lr
_0833A808: .4byte 0x68736D53
_0833A80C: .4byte 0x7FFFFFFF
