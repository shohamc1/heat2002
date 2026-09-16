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
	thumb_func_start sub_080076C8
sub_080076C8:
	push {r4, r5, lr}
	adds r3, r0, #0x0
	ldr r1, _080076E0 @ =0x02025860
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r4, #0x01
	.global _080076D4
_080076D4:
	ldr r0, [r1, #0x08]
	cmp r0, r3
	bne _080076E4
	str r4, [r1, #0x00]
	adds r0, r1, #0x0
	b _0800770E
	.global _080076E0
_080076E0: .4byte 0x02025860
	.global _080076E4
_080076E4:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _080076D4
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r4, #0x01
	movs r5, #0x03
	.global _080076F4
_080076F4:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08007704
	str r4, [r1, #0x00]
	strb r5, [r1, #0x04]
	str r3, [r1, #0x08]
	adds r0, r1, #0x0
	b _0800770E
	.global _08007704
_08007704:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _080076F4
	movs r0, #0x00
	.global _0800770E
_0800770E:
	pop {r4, r5}
	pop {r1}
	bx r1
