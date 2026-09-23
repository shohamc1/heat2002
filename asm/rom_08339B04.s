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
	thumb_func_start sub_08339B04
sub_08339B04:
	ldr r0, _08339B10 @ =0x04000202
	movs r1, #0x01
	strh r1, [r0, #0x00]
	ldr r0, _08339B14 @ =0x02037E20
	strh r1, [r0, #0x00]
	bx lr
_08339B10: .4byte 0x04000202
_08339B14: .4byte 0x02037E20
