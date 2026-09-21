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
	thumb_func_start sub_083431CC
sub_083431CC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r5, #0x96
	lsls r5, r5, #0x01
	adds r4, r0, r5
	ldr r4, [r4, #0x00]
	asrs r4, r4, #0x0B
	negs r4, r4
	movs r5, #0x1F
	ands r4, r5
	lsls r4, r4, #0x03
	ldr r6, _08343230 @ =0x0200C3E8
	lsls r5, r4, #0x01
	adds r5, r5, r6
	mov r8, r5
	movs r7, #0x00
	ldsh r5, [r5, r7]
	mov r8, r5
	adds r4, #0x40
	lsls r4, r4, #0x01
	adds r4, r4, r6
	movs r6, #0x00
	ldsh r5, [r4, r6]
	ldr r4, [r0, #0x00]
	subs r1, r1, r4
	asrs r1, r1, #0x10
	ldr r0, [r0, #0x08]
	subs r2, r2, r0
	asrs r2, r2, #0x10
	adds r0, r1, #0x0
	muls r0, r5
	mov r4, r8
	muls r4, r2
	subs r0, r0, r4
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	mov r0, r8
	muls r0, r1
	adds r1, r2, #0x0
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x04]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08343230
_08343230: .4byte 0x0200C3E8
