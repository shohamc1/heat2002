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
	thumb_func_start sub_080044A4
sub_080044A4:
	push {r4, lr}
	adds r3, r0, #0x0
	adds r4, r1, #0x0
	ldr r2, _080044CC @ =0x02025150
	movs r0, #0x00
	ldsb r0, [r2, r0]
	cmp r0, #0x00
	blt _080044D4
	ldr r0, _080044D0 @ =0x02024828
	ldr r1, [r0, #0x00]
	str r3, [r1, #0x00]
	str r4, [r1, #0x04]
	adds r1, #0x08
	str r1, [r0, #0x00]
	ldrb r0, [r2, #0x00]
	adds r0, #0x01
	strb r0, [r2, #0x00]
	movs r0, #0x01
	b _080044D6
	.byte 0x00, 0x00
	.global _080044CC
_080044CC: .4byte 0x02025150
	.global _080044D0
_080044D0: .4byte 0x02024828
	.global _080044D4
_080044D4:
	movs r0, #0x00
	.global _080044D6
_080044D6:
	pop {r4}
	pop {r1}
	bx r1
