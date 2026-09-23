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
	thumb_func_start sub_08001374
sub_08001374:
	push {r4, r5, lr}
	ldr r0, _08001398 @ =0x00000005
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _08001392
	ldr r5, _0800139C @ =0x0801DA90
	adds r4, r0, #0x0
_08001384:
	ldr r0, [r5, #0x00]
	bl sub_08001134
	adds r5, #0x0C
	subs r4, #0x01
	cmp r4, #0x00
	bne _08001384
_08001392:
	pop {r4, r5}
	pop {r0}
	bx r0
_08001398: .4byte 0x00000005
_0800139C: .4byte 0x0801DA90
