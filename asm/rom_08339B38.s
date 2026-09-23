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
	thumb_func_start sub_08339B38
sub_08339B38:
	ldr r0, _08339B44 @ =0x02037618
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldr r0, _08339B48 @ =0x0203761C
	strh r1, [r0, #0x00]
	bx lr
_08339B44: .4byte 0x02037618
_08339B48: .4byte 0x0203761C
