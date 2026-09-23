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
	thumb_func_start sub_0800133C
sub_0800133C:
	push {r4, r5, lr}
	ldr r0, _08001360 @ =0x00000005
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _0800135A
	ldr r5, _08001364 @ =0x0801DA90
	adds r4, r0, #0x0
_0800134C:
	ldr r0, [r5, #0x00]
	bl sub_080019B4
	adds r5, #0x0C
	subs r4, #0x01
	cmp r4, #0x00
	bne _0800134C
_0800135A:
	pop {r4, r5}
	pop {r0}
	bx r0
_08001360: .4byte 0x00000005
_08001364: .4byte 0x0801DA90
