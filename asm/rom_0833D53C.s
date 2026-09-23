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
	thumb_func_start sub_0833D53C
sub_0833D53C:
	push {r4, r5, lr}
	adds r2, r0, #0x0
	adds r5, r1, #0x0
	adds r0, r5, #0x0
	adds r1, r2, #0x0
	bl sub_0833D31C
	movs r4, #0x00
	cmp r4, r5
	beq _0833D55E
_0833D550:
	bl sub_08339B18
	bl sub_0833D448
	adds r4, #0x01
	cmp r4, r5
	bne _0833D550
_0833D55E:
	pop {r4, r5}
	pop {r0}
	bx r0
