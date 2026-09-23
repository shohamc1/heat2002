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
	thumb_func_start sub_0800A008
sub_0800A008:
	push {r4, lr}
	ldr r4, [sp, #0x008]
	cmp r2, r1
	ble _0800A014
	adds r0, r4, #0x0
	b _0800A02C
_0800A014:
	subs r1, r2, r0
	cmp r1, #0x00
	blt _0800A02A
	movs r0, #0x80
	lsls r0, r0, #0x07
	subs r0, r0, r1
	muls r0, r3
	muls r1, r4
	adds r0, r0, r1
	asrs r0, r0, #0x0E
	b _0800A02C
_0800A02A:
	adds r0, r3, #0x0
_0800A02C:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
