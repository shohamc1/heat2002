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
	thumb_func_start sub_0833AA34
sub_0833AA34:
	push {r4, r5, lr}
	ldr r0, _0833AA58 @ =0x00000004
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _0833AA52
	ldr r5, _0833AA5C @ =0x0200CA74
	adds r4, r0, #0x0
_0833AA44:
	ldr r0, [r5, #0x00]
	bl sub_0833A7F4
	adds r5, #0x0C
	subs r4, #0x01
	cmp r4, #0x00
	bne _0833AA44
_0833AA52:
	pop {r4, r5}
	pop {r0}
	bx r0
_0833AA58: .4byte 0x00000004
_0833AA5C: .4byte 0x0200CA74
