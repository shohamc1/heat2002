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
	thumb_func_start sub_0800BAFC
sub_0800BAFC:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _0800BB34 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	beq _0800BB2E
	cmp r0, #0x0A
	beq _0800BB2E
	bl AllocTask
	adds r1, r0, #0x0
	cmp r1, #0x00
	beq _0800BB2E
	movs r0, #0xF0
	str r0, [r1, #0x18]
	str r4, [r1, #0x00]
	movs r0, #0x00
	str r0, [r1, #0x04]
	str r5, [r1, #0x08]
	ldr r0, _0800BB38 @ =0x0800BA39
	str r0, [r1, #0x0C]
	adds r0, r1, #0x0
	bl AddTask
_0800BB2E:
	pop {r4, r5}
	pop {r0}
	bx r0
_0800BB34: .4byte 0x0200215C
_0800BB38: .4byte sub_0800BA38
