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
	thumb_func_start sub_0833A9FC
sub_0833A9FC:
	push {r4, r5, lr}
	ldr r0, _0833AA20 @ =0x00000004
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _0833AA1A
	ldr r5, _0833AA24 @ =0x0200CA74
	adds r4, r0, #0x0
_0833AA0C:
	ldr r0, [r5, #0x00]
	bl sub_0833B074
	adds r5, #0x0C
	subs r4, #0x01
	cmp r4, #0x00
	bne _0833AA0C
_0833AA1A:
	pop {r4, r5}
	pop {r0}
	bx r0
_0833AA20: .4byte 0x00000004
_0833AA24: .4byte 0x0200CA74
