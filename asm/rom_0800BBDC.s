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
	thumb_func_start sub_0800BBDC
sub_0800BBDC:
	adds r3, r1, #0x0
	b _0800BBE2
_0800BBE0:
	adds r3, #0x14
_0800BBE2:
	ldrb r0, [r3, #0x00]
	cmp r0, #0xFF
	bne _0800BBE0
	subs r3, #0x14
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r1, r2, r0
	ldrh r0, [r3, #0x06]
	str r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800BBF8
sub_0800BBF8:
	bx lr
	.byte 0x00, 0x00
