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
	thumb_func_start sub_0800A5E4
sub_0800A5E4:
	push {r4, r5, r6, lr}
	adds r3, r0, #0x0
	ldrh r0, [r3, #0x34]
	lsrs r1, r0, #0x08
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r6, r3, r0
	ldr r0, [r6, #0x00]
	asrs r2, r0, #0x08
	adds r5, r1, #0x0
	subs r5, #0x30
	adds r4, r1, #0x0
	adds r4, #0x30
	cmp r2, r1
	ble _0800A614
	adds r0, r1, #0x0
	adds r0, #0x80
	cmp r2, r0
	bge _0800A614
	cmp r2, r4
	ble _0800A622
	lsls r0, r4, #0x08
	str r0, [r6, #0x00]
	b _0800A622
_0800A614:
	cmp r2, r5
	bge _0800A622
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r1, r3, r0
	lsls r0, r5, #0x08
	str r0, [r1, #0x00]
_0800A622:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
