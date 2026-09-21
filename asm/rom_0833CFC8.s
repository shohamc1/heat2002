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
	thumb_func_start sub_0833CFC8
sub_0833CFC8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r12, r3
	ldr r6, [sp, #0x018]
	ldr r4, _0833D03C @ =0x02039244
	ldr r3, [r4, #0x00]
	muls r1, r3
	adds r2, r2, r1
	adds r2, r2, r0
	movs r0, #0x00
	mov r8, r4
	.global _0833CFE0
_0833CFE0:
	movs r4, #0x00
	adds r5, r0, #0x4
	mov r3, r12
	adds r3, #0x90
	.global _0833CFE8
_0833CFE8:
	ldrb r1, [r2, #0x00]
	adds r2, #0x01
	lsls r1, r1, #0x05
	adds r1, r6, r1
	ldm r1!, {r0}
	mov r7, r12
	str r0, [r7, #0x00]
	ldm r1!, {r0}
	str r0, [r7, #0x04]
	ldm r1!, {r0}
	str r0, [r7, #0x48]
	ldm r1!, {r0}
	str r0, [r7, #0x4C]
	ldm r1!, {r0}
	str r0, [r3, #0x00]
	ldm r1!, {r0}
	str r0, [r3, #0x04]
	ldm r1!, {r0}
	str r0, [r3, #0x48]
	ldr r0, [r1, #0x00]
	str r0, [r3, #0x4C]
	adds r3, #0x08
	movs r0, #0x08
	add r12, r0
	adds r4, #0x01
	cmp r4, #0x09
	bne _0833CFE8
	movs r1, #0xD8
	add r12, r1
	mov r7, r8
	ldr r0, [r7, #0x00]
	subs r0, #0x09
	adds r2, r2, r0
	adds r0, r5, #0x0
	cmp r0, #0x18
	bne _0833CFE0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833D03C
_0833D03C: .4byte 0x02039244
