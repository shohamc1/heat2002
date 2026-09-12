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
	.byte 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_08010680
sub_08010680:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	ldr r3, _080106C4 @ =0x0600F800
	movs r0, #0x00
	ldr r7, _080106C8 @ =0x0829FC80
	.global _0801068A
_0801068A:
	movs r5, #0x00
	adds r6, r0, #0x1
	.global _0801068E
_0801068E:
	ldrh r0, [r4, #0x00]
	adds r4, #0x02
	lsls r0, r0, #0x03
	adds r0, r0, r7
	ldrh r1, [r0, #0x00]
	strh r1, [r3, #0x00]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r3, #0x02]
	adds r0, #0x02
	ldrh r2, [r0, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x40
	strh r2, [r1, #0x00]
	ldrh r0, [r0, #0x02]
	strh r0, [r1, #0x02]
	adds r3, #0x04
	adds r5, #0x01
	cmp r5, #0x0F
	bne _0801068E
	adds r3, #0x44
	adds r0, r6, #0x0
	cmp r0, #0x0A
	bne _0801068A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _080106C4
_080106C4: .4byte 0x0600F800
	.global _080106C8
_080106C8: .4byte 0x0829FC80
