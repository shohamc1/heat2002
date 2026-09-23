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
	thumb_func_start sub_0800B5D4
sub_0800B5D4:
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x18]
	subs r0, #0x01
	str r0, [r4, #0x18]
	cmp r0, #0x00
	bne _0800B5EE
	adds r0, r4, #0x0
	bl sub_08007950
	adds r0, r4, #0x0
	bl sub_0800792C
_0800B5EE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_start sub_0800B5F4
sub_0800B5F4:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800B5F8
sub_0800B5F8:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800B5FC
sub_0800B5FC:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800B600
sub_0800B600:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800B604
sub_0800B604:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800B608
sub_0800B608:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800B60C
sub_0800B60C:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800B610
sub_0800B610:
	bx lr
	.byte 0x00, 0x00
