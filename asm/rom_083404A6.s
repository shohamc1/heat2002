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
	thumb_func_start sub_083404A8
sub_083404A8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r3, #0x00
	ldr r0, _083404F0 @ =0x0203DD40
	mov r12, r0
	ldr r0, _083404F4 @ =0x0203DD20
	mov r8, r0
	ldr r7, _083404F8 @ =0x0203D510
	ldr r6, _083404FC @ =0x020270C6
	mov r5, r12
	ldr r4, _08340500 @ =0x020270D0
_083404C0:
	lsls r1, r3, #0x01
	adds r2, r1, r7
	adds r0, r1, r6
	ldrh r0, [r0, #0x00]
	strh r0, [r2, #0x00]
	adds r2, r1, r5
	adds r1, r1, r4
	ldrh r0, [r1, #0x00]
	strh r0, [r2, #0x00]
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x05
	bne _083404C0
	mov r0, r12
	mov r1, r8
	bl sub_0834047C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_083404F0: .4byte 0x0203DD40
_083404F4: .4byte 0x0203DD20
_083404F8: .4byte 0x0203D510
_083404FC: .4byte 0x020270C6
_08340500: .4byte 0x020270D0
	thumb_func_start sub_08340504
sub_08340504:
	adds r2, r0, #0x0
	ldr r0, _08340520 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xE4
	ldr r0, _08340524 @ =0x0202713E
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _08340528 @ =0x0202714A
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _0834052C @ =0x02027154
	str r0, [r1, #0x00]
	bx lr
_08340520: .4byte 0x0203916C
_08340524: .4byte 0x0202713E
_08340528: .4byte 0x0202714A
_0834052C: .4byte 0x02027154
