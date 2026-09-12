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
	thumb_func_start sub_08001900
sub_08001900:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0x0
	adds r7, r1, #0x0
	ldr r1, [r5, #0x34]
	ldr r0, _080019B0 @ =0x68736D53
	cmp r1, r0
	bne _080019A6
	adds r0, r1, #0x1
	str r0, [r5, #0x34]
	movs r1, #0x00
	str r1, [r5, #0x04]
	str r7, [r5, #0x00]
	ldr r0, [r7, #0x04]
	str r0, [r5, #0x30]
	ldrb r0, [r7, #0x02]
	strb r0, [r5, #0x09]
	str r1, [r5, #0x0C]
	movs r0, #0x96
	strh r0, [r5, #0x1C]
	strh r0, [r5, #0x20]
	adds r0, #0x6A
	strh r0, [r5, #0x1E]
	strh r1, [r5, #0x22]
	strh r1, [r5, #0x24]
	movs r6, #0x00
	ldr r4, [r5, #0x2C]
	ldrb r0, [r7, #0x00]
	cmp r6, r0
	bge _08001972
	ldrb r1, [r5, #0x08]
	cmp r6, r1
	bge _08001992
	mov r8, r6
	.global _08001946
_08001946:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl sub_08000DC8
	movs r0, #0xC0
	strb r0, [r4, #0x00]
	mov r0, r8
	str r0, [r4, #0x20]
	lsls r1, r6, #0x02
	adds r0, r7, #0x0
	adds r0, #0x08
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x40]
	adds r6, #0x01
	adds r4, #0x50
	ldrb r1, [r7, #0x00]
	cmp r6, r1
	bge _08001972
	ldrb r0, [r5, #0x08]
	cmp r6, r0
	blt _08001946
	.global _08001972
_08001972:
	ldrb r1, [r5, #0x08]
	cmp r6, r1
	bge _08001992
	movs r0, #0x00
	mov r8, r0
	.global _0800197C
_0800197C:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl sub_08000DC8
	mov r1, r8
	strb r1, [r4, #0x00]
	adds r6, #0x01
	adds r4, #0x50
	ldrb r0, [r5, #0x08]
	cmp r6, r0
	blt _0800197C
	.global _08001992
_08001992:
	movs r0, #0x80
	ldrb r1, [r7, #0x03]
	ands r0, r1
	cmp r0, #0x00
	beq _080019A2
	ldrb r0, [r7, #0x03]
	bl sub_080016E4
	.global _080019A2
_080019A2:
	ldr r0, _080019B0 @ =0x68736D53
	str r0, [r5, #0x34]
	.global _080019A6
_080019A6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _080019B0
_080019B0: .4byte 0x68736D53
