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
	thumb_func_start sub_0800E640
sub_0800E640:
	push {r4, r5, lr}
	ldr r2, _0800E664 @ =0x04000120
	ldr r3, [r2, #0x00]
	ldr r5, _0800E668 @ =0x0202CDD0
	adds r4, r5, #0x0
	ldrb r0, [r5, #0x00]
	cmp r0, #0x01
	beq _0800E670
	ldr r0, _0800E66C @ =0x04000128
	ldrh r1, [r0, #0x00]
	movs r2, #0x80
	orrs r1, r2
	strh r1, [r0, #0x00]
	ldr r2, [r4, #0x08]
	cmp r2, #0x00
	bge _0800E6BC
	b _0800E6AA
	.byte 0x00, 0x00
_0800E664: .4byte 0x04000120
_0800E668: .4byte 0x0202CDD0
_0800E66C: .4byte 0x04000128
_0800E670:
	ldr r1, _0800E684 @ =0x0400010E
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r1, [r4, #0x08]
	cmp r1, #0x00
	bge _0800E68C
	ldr r0, _0800E688 @ =0xFEFEFEFE
	str r0, [r2, #0x00]
	b _0800E6D2
	.byte 0x00, 0x00
_0800E684: .4byte 0x0400010E
_0800E688: .4byte 0xFEFEFEFE
_0800E68C:
	ldr r0, _0800E6A0 @ =0x00001FFF
	cmp r1, r0
	bgt _0800E6A4
	ldr r0, [r4, #0x04]
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	str r0, [r2, #0x00]
	b _0800E6D2
	.byte 0x00, 0x00
_0800E6A0: .4byte 0x00001FFF
_0800E6A4:
	ldr r0, [r4, #0x0C]
	str r0, [r2, #0x00]
	b _0800E6D2
_0800E6AA:
	ldr r0, _0800E6B8 @ =0xFEFEFEFE
	cmp r3, r0
	beq _0800E6D2
	subs r0, r2, #0x1
	str r0, [r5, #0x08]
	b _0800E6D2
	.byte 0x00, 0x00
_0800E6B8: .4byte 0xFEFEFEFE
_0800E6BC:
	ldr r0, _0800E6CC @ =0x00001FFF
	cmp r2, r0
	bgt _0800E6D0
	ldr r1, [r4, #0x04]
	lsls r0, r2, #0x02
	adds r0, r0, r1
	str r3, [r0, #0x00]
	b _0800E6D2
_0800E6CC: .4byte 0x00001FFF
_0800E6D0:
	str r3, [r4, #0x0C]
_0800E6D2:
	ldr r1, [r4, #0x08]
	ldr r0, _0800E6FC @ =0x00002002
	cmp r1, r0
	bgt _0800E6F4
	adds r0, r1, #0x1
	str r0, [r4, #0x08]
	ldrb r4, [r4, #0x00]
	cmp r4, #0x01
	bne _0800E6F4
	ldr r2, _0800E700 @ =0x04000128
	ldrh r0, [r2, #0x00]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r1, _0800E704 @ =0x0400010E
	movs r0, #0xC0
	strh r0, [r1, #0x00]
_0800E6F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800E6FC: .4byte 0x00002002
_0800E700: .4byte 0x04000128
_0800E704: .4byte 0x0400010E
