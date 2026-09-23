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
	thumb_func_start sub_08007950
sub_08007950:
	ldr r1, [r0, #0x14]
	ldr r2, [r0, #0x10]
	cmp r2, #0x00
	beq _0800795C
	str r1, [r2, #0x14]
	b _08007960
_0800795C:
	ldr r0, _08007968 @ =0x02025FD0
	str r1, [r0, #0x00]
_08007960:
	cmp r1, #0x00
	beq _08007966
	str r2, [r1, #0x10]
_08007966:
	bx lr
_08007968: .4byte 0x02025FD0
