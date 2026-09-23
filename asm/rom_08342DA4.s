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
	thumb_func_start sub_08342DA4
sub_08342DA4:
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x18]
	subs r0, #0x01
	str r0, [r4, #0x18]
	cmp r0, #0x00
	bne _08342DBE
	adds r0, r4, #0x0
	bl sub_0833FFA8
	adds r0, r4, #0x0
	bl sub_0833FF84
_08342DBE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_start sub_08342DC4
sub_08342DC4:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08342DC8
sub_08342DC8:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08342DCC
sub_08342DCC:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08342DD0
sub_08342DD0:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08342DD4
sub_08342DD4:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08342DD8
sub_08342DD8:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08342DDC
sub_08342DDC:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08342DE0
sub_08342DE0:
	bx lr
	.byte 0x00, 0x00
