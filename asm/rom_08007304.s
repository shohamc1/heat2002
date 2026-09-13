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
	thumb_func_start sub_08007304
sub_08007304:
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	movs r3, #0x00
	cmp r3, r5
	beq _08007336
	ldr r0, _0800733C @ =0x0000FFFF
	mov r12, r0
	movs r4, #0x00
	ldr r6, _08007340 @ =0x06010000
	.global _08007316
_08007316:
	mov r7, r12
	str r7, [r2, #0x08]
	str r4, [r2, #0x00]
	strb r4, [r2, #0x04]
	ldrh r0, [r1, #0x00]
	str r0, [r2, #0x10]
	ldrh r7, [r1, #0x00]
	lsls r0, r7, #0x05
	adds r0, r0, r6
	str r0, [r2, #0x0C]
	strb r4, [r2, #0x06]
	adds r3, #0x01
	adds r2, #0x14
	adds r1, #0x02
	cmp r3, r5
	bne _08007316
	.global _08007336
_08007336:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800733C
_0800733C: .4byte 0x0000FFFF
	.global _08007340
_08007340: .4byte 0x06010000
