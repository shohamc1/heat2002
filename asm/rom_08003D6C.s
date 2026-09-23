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
	thumb_func_start sub_08003D6C
sub_08003D6C:
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	movs r6, #0x00
_08003D74:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x10
	bl sub_08016E0C
	adds r5, #0x40
	adds r4, #0x40
	adds r6, #0x01
	cmp r6, #0x1C
	bne _08003D74
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
