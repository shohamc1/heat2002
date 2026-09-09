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
	thumb_func_start sub_08008338
sub_08008338:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r3, #0x00
	ldr r0, _08008380 @ =0x0202CB20
	mov r12, r0
	ldr r0, _08008384 @ =0x0202CB00
	mov r8, r0
	ldr r7, _08008388 @ =0x0202A540
	ldr r6, _0800838C @ =0x08367B82
	mov r5, r12
	ldr r4, _08008390 @ =0x08367B8C
	.global _08008350
_08008350:
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
	bne _08008350
	mov r0, r12
	mov r1, r8
	bl sub_0800830C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08008380
_08008380: .4byte 0x0202CB20
	.global _08008384
_08008384: .4byte 0x0202CB00
	.global _08008388
_08008388: .4byte 0x0202A540
	.global _0800838C
_0800838C: .4byte 0x08367B82
	.global _08008390
_08008390: .4byte 0x08367B8C
