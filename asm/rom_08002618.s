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
	thumb_func_start sub_08002618
sub_08002618:
	adds r1, r0, #0x0
	ldr r2, _08002628 @ =0x020020D4
	cmp r1, #0x00
	beq _08002630
	ldr r0, _0800262C @ =0x7FFFFFFF
	ands r0, r1
	b _08002632
	.byte 0x00, 0x00
_08002628: .4byte 0x020020D4
_0800262C: .4byte 0x7FFFFFFF
_08002630:
	movs r0, #0x01
_08002632:
	str r0, [r2, #0x00]
	bx lr
	.byte 0x00, 0x00
