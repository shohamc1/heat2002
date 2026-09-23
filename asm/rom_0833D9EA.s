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
	thumb_func_start sub_0833D9EC
sub_0833D9EC:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833D9F0
sub_0833D9F0:
	ldr r0, _0833DA20 @ =0x020251B8
	ldr r0, [r0, #0x00]
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r0, r2
	movs r2, #0x00
	ldr r0, _0833DA24 @ =0x0000E047
	adds r3, r0, #0x0
_0833DA00:
	movs r0, #0x00
	adds r2, #0x01
_0833DA04:
	strh r3, [r1, #0x00]
	adds r1, #0x02
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bne _0833DA04
	adds r1, #0x1A
	lsls r0, r2, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x08
	bne _0833DA00
	bx lr
	.byte 0x00, 0x00
_0833DA20: .4byte 0x020251B8
_0833DA24: .4byte 0x0000E047
	thumb_func_start sub_0833DA28
sub_0833DA28:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833DA2C
sub_0833DA2C:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833DA30
sub_0833DA30:
	bx lr
	.byte 0x00, 0x00
