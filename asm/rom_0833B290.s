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
	thumb_func_start sub_0833B290
sub_0833B290:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0x0
	cmp r0, #0x02
	beq _0833B2B8
	cmp r0, #0x02
	bgt _0833B2A4
	cmp r0, #0x01
	beq _0833B2AA
	b _0833B2CC
_0833B2A4:
	cmp r1, #0x03
	beq _0833B2C0
	b _0833B2CC
_0833B2AA:
	ldr r1, _0833B2B4 @ =0x04000063
	movs r0, #0x08
	strb r0, [r1, #0x00]
	adds r1, #0x02
	b _0833B2D4
_0833B2B4: .4byte 0x04000063
_0833B2B8:
	ldr r1, _0833B2BC @ =0x04000069
	b _0833B2CE
_0833B2BC: .4byte 0x04000069
_0833B2C0:
	ldr r1, _0833B2C8 @ =0x04000070
	movs r0, #0x00
	b _0833B2D6
	.byte 0x00, 0x00
_0833B2C8: .4byte 0x04000070
_0833B2CC:
	ldr r1, _0833B2DC @ =0x04000079
_0833B2CE:
	movs r0, #0x08
	strb r0, [r1, #0x00]
	adds r1, #0x04
_0833B2D4:
	movs r0, #0x80
_0833B2D6:
	strb r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_0833B2DC: .4byte 0x04000079
