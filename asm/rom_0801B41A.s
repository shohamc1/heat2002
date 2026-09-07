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
	.byte 0x01, 0x20, 0x40, 0x42, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x30, 0xB5
	.byte 0x02, 0x1C, 0x0B, 0x1C, 0x00, 0x2A, 0x09, 0xD0, 0x11, 0x24, 0x00, 0x25, 0x20, 0x1C, 0x29, 0x1C
	.byte 0xAB, 0xDF, 0x05, 0x1C, 0x2C, 0x1C, 0x14, 0x60, 0x00, 0x20, 0x50, 0x60, 0x00, 0x2B, 0x02, 0xD0
	.byte 0x00, 0x20, 0x18, 0x60, 0x58, 0x60, 0x00, 0x20, 0x30, 0xBD, 0x30, 0xB5, 0x02, 0x1C, 0x10, 0x24
	.byte 0x00, 0x25, 0x20, 0x1C, 0x29, 0x1C, 0xAB, 0xDF, 0x03, 0x1C, 0x00, 0x2A, 0x04, 0xD0, 0x13, 0x60
	.byte 0x00, 0x20, 0x50, 0x60, 0x90, 0x60, 0xD0, 0x60, 0x18, 0x1C, 0x30, 0xBD, 0x00, 0x00
	thumb_func_start sub_0801B478
sub_0801B478:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	adds r2, r3, #0x0
	ldr r4, _0801B4A4 @ =0x0202F244
	movs r3, #0x00
	str r3, [r4, #0x00]
	bl sub_0801B250
	adds r1, r0, #0x0
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	bne _0801B49E
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0801B49E
	str r0, [r5, #0x00]
	.global _0801B49E
_0801B49E:
	adds r0, r1, #0x0
	pop {r4, r5, pc}
	.byte 0x00, 0x00
	.global _0801B4A4
_0801B4A4: .4byte 0x0202F244
	thumb_func_start sub_0801B4A8
sub_0801B4A8:
	push {r4, lr}
	muls r1, r2
	bl sub_08019FC0
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _0801B4BA
	movs r0, #0x00
	b _0801B4FE
	.global _0801B4BA
_0801B4BA:
	adds r0, r4, #0x0
	subs r0, #0x08
	ldr r0, [r0, #0x04]
	movs r1, #0x04
	negs r1, r1
	ands r0, r1
	subs r2, r0, #0x4
	cmp r2, #0x24
	bhi _0801B4F4
	adds r1, r4, #0x0
	cmp r2, #0x13
	bls _0801B4EA
	movs r0, #0x00
	stm r1!, {r0}
	str r0, [r4, #0x04]
	adds r1, #0x04
	cmp r2, #0x1B
	bls _0801B4EA
	stm r1!, {r0}
	stm r1!, {r0}
	cmp r2, #0x23
	bls _0801B4EA
	stm r1!, {r0}
	stm r1!, {r0}
	.global _0801B4EA
_0801B4EA:
	movs r0, #0x00
	stm r1!, {r0}
	stm r1!, {r0}
	str r0, [r1, #0x00]
	b _0801B4FC
	.global _0801B4F4
_0801B4F4:
	adds r0, r4, #0x0
	movs r1, #0x00
	bl sub_0801A514
	.global _0801B4FC
_0801B4FC:
	adds r0, r4, #0x0
	.global _0801B4FE
_0801B4FE:
	pop {r4, pc}
	thumb_func_start sub_0801B500
sub_0801B500:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r0, r1, #0x0
	ldr r4, _0801B528 @ =0x0202F244
	movs r1, #0x00
	str r1, [r4, #0x00]
	bl sub_0801B384
	adds r1, r0, #0x0
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	bne _0801B522
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0801B522
	str r0, [r5, #0x00]
	.global _0801B522
_0801B522:
	adds r0, r1, #0x0
	pop {r4, r5, pc}
	.byte 0x00, 0x00
	.global _0801B528
_0801B528: .4byte 0x0202F244
