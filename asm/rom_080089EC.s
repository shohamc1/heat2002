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
	thumb_func_start sub_080089EC
sub_080089EC:
	push {r4, r5, lr}
	adds r2, r0, #0x0
	movs r4, #0x00
	movs r5, #0x00
	cmp r2, #0x00
	bge _080089FE
	negs r2, r2
	movs r4, #0x01
	movs r5, #0x80
_080089FE:
	cmp r1, #0x00
	bge _08008A08
	negs r1, r1
	movs r0, #0x01
	eors r4, r0
_08008A08:
	lsls r0, r1, #0x06
	adds r1, r2, r1
	bl sub_08017230
	cmp r4, #0x00
	beq _08008A16
	negs r0, r0
_08008A16:
	adds r0, r5, r0
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
