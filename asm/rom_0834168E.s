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
	thumb_func_start sub_08341690
sub_08341690:
	push {r4, lr}
	adds r4, r2, #0x0
	ldr r3, _083416CC @ =0x02039110
	ldr r2, [r3, #0x00]
	subs r0, r0, r2
	ldr r2, [r3, #0x04]
	subs r1, r1, r2
	subs r2, r0, r1
	lsls r2, r2, #0x01
	adds r0, r0, r1
	movs r1, #0xF1
	lsls r1, r1, #0x10
	adds r2, r2, r1
	movs r1, #0xA1
	lsls r1, r1, #0x10
	adds r3, r0, r1
	asrs r2, r2, #0x11
	asrs r3, r3, #0x11
	adds r1, r2, #0x0
	adds r1, #0x10
	movs r0, #0x88
	lsls r0, r0, #0x01
	cmp r1, r0
	bhi _083416C8
	adds r0, r3, #0x0
	adds r0, #0x20
	cmp r0, #0xC0
	bls _083416D0
_083416C8:
	movs r0, #0x00
	b _083416D4
_083416CC: .4byte 0x02039110
_083416D0:
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
_083416D4:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
