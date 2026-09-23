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
	thumb_func_start sub_08003C78
sub_08003C78:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r3, #0x0
	ldr r3, [sp, #0x01C]
	mov r8, r3
	ldr r4, _08003D38 @ =0x0200BC30
	ldr r3, [r4, #0x00]
	muls r1, r3
	adds r2, r2, r1
	adds r6, r2, r0
	adds r3, r5, #0x0
	movs r0, #0x00
	mov r9, r4
_08003C96:
	movs r7, #0x00
	adds r0, #0x04
	mov r12, r0
	adds r5, r3, #0x0
	adds r5, #0x90
	adds r4, r3, #0x0
	adds r4, #0xD8
	adds r2, r3, #0x0
	adds r2, #0x48
_08003CA8:
	ldrb r0, [r6, #0x00]
	adds r6, #0x01
	lsls r0, r0, #0x05
	add r0, r8
	ldrh r1, [r0, #0x00]
	strh r1, [r3, #0x00]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r3, #0x02]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r3, #0x04]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r3, #0x06]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r2, #0x00]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r2, #0x02]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r2, #0x04]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r2, #0x06]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r5, #0x00]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r5, #0x02]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r5, #0x04]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r5, #0x06]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r4, #0x00]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r4, #0x02]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r4, #0x04]
	ldrh r0, [r0, #0x02]
	strh r0, [r4, #0x06]
	adds r5, #0x08
	adds r4, #0x08
	adds r2, #0x08
	adds r3, #0x08
	adds r7, #0x01
	cmp r7, #0x09
	bne _08003CA8
	adds r3, #0xD8
	mov r1, r9
	ldr r0, [r1, #0x00]
	subs r0, #0x09
	adds r6, r6, r0
	mov r0, r12
	cmp r0, #0x18
	bne _08003C96
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08003D38: .4byte 0x0200BC30
