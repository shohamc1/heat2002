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
	thumb_func_start sub_08016568
sub_08016568:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _08016594 @ =0x083FECAC
	movs r2, #0x46
	muls r2, r0
	ldr r3, _08016598 @ =0x0202EDD0
	ldrb r5, [r3, #0x00]
	lsls r0, r5, #0x03
	subs r0, r0, r5
	lsls r0, r0, #0x01
	adds r2, r2, r0
	adds r2, r2, r1
	lsls r2, r2, #0x02
	adds r2, r2, r4
	ldr r0, [r2, #0x00]
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08016594: .4byte 0x083FECAC
_08016598: .4byte 0x0202EDD0
