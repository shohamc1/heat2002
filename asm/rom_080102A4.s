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
	thumb_func_start sub_080102A4
sub_080102A4:
	push {r4, lr}
	cmp r0, #0x00
	ble _080102B6
	adds r4, r0, #0x0
	.global _080102AC
_080102AC:
	bl sub_08000458
	subs r4, #0x01
	cmp r4, #0x00
	bne _080102AC
	.global _080102B6
_080102B6:
	pop {r4}
	pop {r0}
	bx r0
