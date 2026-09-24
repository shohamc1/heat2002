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
	thumb_func_start sub_0833BC38
sub_0833BC38:
	ldr r0, [r1, #0x40]
	ldrb r2, [r0, #0x00]
	strb r2, [r1, #0x1E]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	thumb_func_start sub_0833BC44
sub_0833BC44:
	ldr r0, [r1, #0x40]
	ldrb r2, [r0, #0x00]
	strb r2, [r1, #0x1F]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	thumb_func_start sub_0833BC50
sub_0833BC50:
	ldr r0, [r1, #0x40]
	ldrb r0, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x26
	strb r0, [r2, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833BC64
sub_0833BC64:
	ldr r0, [r1, #0x40]
	ldrb r0, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x27
	strb r0, [r2, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
