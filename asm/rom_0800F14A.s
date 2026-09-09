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
	thumb_func_start sub_0800F14C
sub_0800F14C:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, r2, #0x0
	cmp r2, #0x00
	bne _0800F168
	ldr r1, _0800F18C @ =0x0202EF20
	movs r0, #0x01
	strb r0, [r1, #0x00]
	strb r0, [r1, #0x01]
	strb r0, [r1, #0x02]
	strb r0, [r1, #0x03]
	strb r0, [r1, #0x04]
	strb r0, [r1, #0x05]
	strb r0, [r1, #0x06]
	.global _0800F168
_0800F168:
	cmp r2, #0x01
	bne _0800F178
	ldr r0, _0800F18C @ =0x0202EF20
	strb r2, [r0, #0x07]
	strb r2, [r0, #0x08]
	strb r2, [r0, #0x09]
	strb r2, [r0, #0x0A]
	strb r2, [r0, #0x0B]
	.global _0800F178
_0800F178:
	cmp r3, #0x02
	bne _0800F18A
	ldr r1, _0800F18C @ =0x0202EF20
	movs r0, #0x01
	strb r0, [r1, #0x0C]
	strb r0, [r1, #0x0D]
	strb r0, [r1, #0x0E]
	strb r0, [r1, #0x0F]
	strb r0, [r1, #0x10]
	.global _0800F18A
_0800F18A:
	bx lr
	.global _0800F18C
_0800F18C: .4byte 0x0202EF20
