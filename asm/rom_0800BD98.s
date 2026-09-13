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
	thumb_func_start sub_0800BD98
sub_0800BD98:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r6, r2, #0x0
	adds r4, r3, #0x0
	ldrh r1, [r4, #0x06]
	cmp r1, r0
	bge _0800BDB2
	.global _0800BDAA
_0800BDAA:
	adds r4, #0x14
	ldrh r2, [r4, #0x06]
	cmp r2, r0
	blt _0800BDAA
	.global _0800BDB2
_0800BDB2:
	ldrh r1, [r4, #0x04]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r3, [r4, #0x06]
	subs r1, r3, r1
	bl sub_08017230
	ldrb r7, [r4, #0x01]
	lsls r2, r7, #0x02
	adds r2, r2, r6
	ldrb r3, [r4, #0x00]
	lsls r1, r3, #0x02
	adds r1, r1, r6
	ldrh r3, [r1, #0x00]
	ldrh r7, [r2, #0x00]
	subs r5, r7, r3
	ldrh r2, [r2, #0x02]
	ldrh r1, [r1, #0x02]
	subs r2, r2, r1
	adds r1, r5, #0x0
	muls r1, r0
	asrs r5, r1, #0x10
	muls r0, r2
	asrs r2, r0, #0x10
	adds r3, r3, r5
	mov r0, r8
	str r3, [r0, #0x00]
	ldrb r4, [r4, #0x00]
	lsls r0, r4, #0x02
	adds r0, r0, r6
	ldrh r0, [r0, #0x02]
	adds r0, r0, r2
	mov r1, r8
	str r0, [r1, #0x04]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
