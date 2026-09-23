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
	thumb_func_start sub_0834009C
sub_0834009C:
	push {r4, r5, lr}
	movs r3, #0x00
	ldr r1, _083400CC @ =0x0203D520
	ldr r5, _083400D0 @ =0x00000175
	movs r4, #0xC8
	lsls r4, r4, #0x01
_083400A8:
	adds r0, r1, r5
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _083400B6
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_083400B6:
	adds r1, r1, r4
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r1, r4
	cmp r3, #0x05
	bne _083400A8
	adds r0, r2, #0x0
	pop {r4, r5}
	pop {r1}
	bx r1
_083400CC: .4byte 0x0203D520
_083400D0: .4byte 0x00000175
