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
	thumb_func_start sub_08002514
sub_08002514:
	ldr r0, [r1, #0x40]
	ldrb r2, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x24
	strb r2, [r0, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08002528
sub_08002528:
	ldr r0, [r1, #0x40]
	ldrb r2, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x2C
	strb r2, [r0, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800253C
sub_0800253C:
	ldr r0, [r1, #0x40]
	ldrb r0, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x2D
	strb r0, [r2, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08002550
sub_08002550:
	ldr r0, [r1, #0x40]
	ldrb r0, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x2E
	strb r0, [r2, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08002564
sub_08002564:
	ldr r0, [r1, #0x40]
	ldrb r0, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x2F
	strb r0, [r2, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08002578
sub_08002578:
	ldr r0, [r1, #0x40]
	ldrb r2, [r0, #0x00]
	strb r2, [r1, #0x1E]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	thumb_func_start sub_08002584
sub_08002584:
	ldr r0, [r1, #0x40]
	ldrb r2, [r0, #0x00]
	strb r2, [r1, #0x1F]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	thumb_func_start sub_08002590
sub_08002590:
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
	thumb_func_start sub_080025A4
sub_080025A4:
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
