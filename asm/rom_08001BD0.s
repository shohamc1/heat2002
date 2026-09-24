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
	thumb_func_start sub_08001BD0
sub_08001BD0:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0x0
	cmp r0, #0x02
	beq _08001BF8
	cmp r0, #0x02
	bgt _08001BE4
	cmp r0, #0x01
	beq _08001BEA
	b _08001C0C
_08001BE4:
	cmp r1, #0x03
	beq _08001C00
	b _08001C0C
_08001BEA:
	ldr r1, _08001BF4 @ =0x04000063
	movs r0, #0x08
	strb r0, [r1, #0x00]
	adds r1, #0x02
	b _08001C14
_08001BF4: .4byte 0x04000063
_08001BF8:
	ldr r1, _08001BFC @ =0x04000069
	b _08001C0E
_08001BFC: .4byte 0x04000069
_08001C00:
	ldr r1, _08001C08 @ =0x04000070
	movs r0, #0x00
	b _08001C16
	.byte 0x00, 0x00
_08001C08: .4byte 0x04000070
_08001C0C:
	ldr r1, _08001C1C @ =0x04000079
_08001C0E:
	movs r0, #0x08
	strb r0, [r1, #0x00]
	adds r1, #0x04
_08001C14:
	movs r0, #0x80
_08001C16:
	strb r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_08001C1C: .4byte 0x04000079
