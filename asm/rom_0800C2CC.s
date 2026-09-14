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
	thumb_func_start sub_0800C2CC
sub_0800C2CC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r12, r0
	mov r8, r1
	ldrb r1, [r3, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r2
	ldrh r4, [r0, #0x00]
	ldrh r5, [r0, #0x02]
	ldrb r7, [r3, #0x01]
	lsls r0, r7, #0x02
	adds r0, r0, r2
	mov r2, r12
	subs r1, r2, r4
	ldrh r7, [r0, #0x00]
	subs r6, r7, r4
	muls r1, r6
	mov r7, r8
	subs r2, r7, r5
	ldrh r0, [r0, #0x02]
	subs r7, r0, r5
	adds r0, r2, #0x0
	muls r0, r7
	adds r1, r1, r0
	ldrb r3, [r3, #0x02]
	muls r1, r3
	cmp r1, #0x00
	bge _0800C308
	movs r1, #0x00
	.global _0800C308
_0800C308:
	ldr r0, _0800C34C @ =0x0000FFFF
	cmp r1, r0
	ble _0800C310
	adds r1, r0, #0x0
	.global _0800C310
_0800C310:
	adds r0, r6, #0x0
	muls r0, r1
	asrs r0, r0, #0x10
	adds r3, r4, r0
	adds r0, r7, #0x0
	muls r0, r1
	asrs r0, r0, #0x10
	adds r2, r5, r0
	ldr r0, _0800C350 @ =0x0202CC24
	str r3, [r0, #0x00]
	ldr r0, _0800C354 @ =0x0202CC38
	str r2, [r0, #0x00]
	mov r1, r12
	subs r0, r1, r3
	asrs r3, r0, #0x02
	mov r7, r8
	subs r0, r7, r2
	asrs r2, r0, #0x02
	adds r1, r3, #0x0
	muls r1, r3
	adds r0, r2, #0x0
	muls r0, r2
	adds r1, r1, r0
	adds r0, r1, #0x0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _0800C34C
_0800C34C: .4byte 0x0000FFFF
	.global _0800C350
_0800C350: .4byte 0x0202CC24
	.global _0800C354
_0800C354: .4byte 0x0202CC38
