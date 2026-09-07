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
	.byte 0xF0, 0xB5, 0x05, 0x7A, 0xC4, 0x6A, 0x00, 0x2D, 0x1B, 0xDD, 0x80, 0x27, 0x21, 0x78
	.byte 0x38, 0x1C, 0x08, 0x40, 0x00, 0x28, 0x11, 0xD0, 0x40, 0x26, 0x30, 0x1C, 0x08, 0x40, 0x00, 0x28
	.byte 0x0C, 0xD0, 0x20, 0x1C, 0x00, 0xF0, 0xAF, 0xF8, 0x27, 0x70, 0x02, 0x20, 0xE0, 0x73, 0xE6, 0x74
	.byte 0x16, 0x20, 0x60, 0x76, 0x21, 0x1C, 0x24, 0x31, 0x01, 0x20, 0x08, 0x70, 0x01, 0x3D, 0x50, 0x34
	.byte 0x00, 0x2D, 0xE4, 0xDC, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47
	thumb_func_start sub_080013F8
sub_080013F8:
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	ldr r1, _080014C4 @ =0x04000084
	movs r0, #0x8F
	strh r0, [r1, #0x00]
	ldr r2, _080014C8 @ =0x04000080
	movs r0, #0x77
	strh r0, [r2, #0x00]
	ldr r0, _080014CC @ =0x04000063
	movs r1, #0x08
	strb r1, [r0, #0x00]
	adds r0, #0x06
	strb r1, [r0, #0x00]
	adds r0, #0x10
	strb r1, [r0, #0x00]
	subs r0, #0x14
	movs r1, #0x80
	strb r1, [r0, #0x00]
	adds r0, #0x08
	strb r1, [r0, #0x00]
	adds r0, #0x10
	strb r1, [r0, #0x00]
	ldr r1, _080014D0 @ =0x04000070
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r1, _080014D4 @ =0x0000FF77
	adds r0, r1, #0x0
	strh r0, [r2, #0x00]
	ldr r0, _080014D8 @ =0x03007FF0
	ldr r4, [r0, #0x00]
	ldr r6, [r4, #0x00]
	ldr r0, _080014DC @ =0x68736D53
	cmp r6, r0
	bne _080014BC
	adds r0, r6, #0x1
	str r0, [r4, #0x00]
	ldr r1, _080014E0 @ =0x02001D90
	ldr r0, _080014E4 @ =0x08002341
	str r0, [r1, #0x20]
	ldr r0, _080014E8 @ =0x080010A5
	str r0, [r1, #0x44]
	ldr r0, _080014EC @ =0x080010B9
	str r0, [r1, #0x4C]
	ldr r0, _080014F0 @ =0x08002499
	str r0, [r1, #0x70]
	ldr r0, _080014F4 @ =0x0800103D
	str r0, [r1, #0x74]
	ldr r0, _080014F8 @ =0x08001641
	str r0, [r1, #0x78]
	ldr r0, _080014FC @ =0x08000DC9
	str r0, [r1, #0x7C]
	adds r2, r1, #0x0
	adds r2, #0x80
	ldr r0, _08001500 @ =0x080019F5
	str r0, [r2, #0x00]
	adds r1, #0x84
	ldr r0, _08001504 @ =0x08001A75
	str r0, [r1, #0x00]
	str r5, [r4, #0x1C]
	ldr r0, _08001508 @ =0x08001C89
	str r0, [r4, #0x28]
	ldr r0, _0800150C @ =0x08001BD1
	str r0, [r4, #0x2C]
	ldr r0, _08001510 @ =0x08001B29
	str r0, [r4, #0x30]
	ldr r0, _08001514 @ =0x00000000
	movs r1, #0x00
	strb r0, [r4, #0x0C]
	str r1, [sp, #0x000]
	ldr r2, _08001518 @ =0x05000040
	mov r0, sp
	adds r1, r5, #0x0
	bl sub_08016E10
	movs r0, #0x01
	strb r0, [r5, #0x01]
	movs r0, #0x11
	strb r0, [r5, #0x1C]
	adds r1, r5, #0x0
	adds r1, #0x41
	movs r0, #0x02
	strb r0, [r1, #0x00]
	adds r1, #0x1B
	movs r0, #0x22
	strb r0, [r1, #0x00]
	adds r1, #0x25
	movs r0, #0x03
	strb r0, [r1, #0x00]
	adds r1, #0x1B
	movs r0, #0x44
	strb r0, [r1, #0x00]
	adds r1, #0x24
	movs r0, #0x04
	strb r0, [r1, #0x01]
	movs r0, #0x88
	strb r0, [r1, #0x1C]
	str r6, [r4, #0x00]
	.global _080014BC
_080014BC:
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _080014C4
_080014C4: .4byte 0x04000084
	.global _080014C8
_080014C8: .4byte 0x04000080
	.global _080014CC
_080014CC: .4byte 0x04000063
	.global _080014D0
_080014D0: .4byte 0x04000070
	.global _080014D4
_080014D4: .4byte 0x0000FF77
	.global _080014D8
_080014D8: .4byte 0x03007FF0
	.global _080014DC
_080014DC: .4byte 0x68736D53
	.global _080014E0
_080014E0: .4byte 0x02001D90
	.global _080014E4
_080014E4: .4byte 0x08002341
	.global _080014E8
_080014E8: .4byte 0x080010A5
	.global _080014EC
_080014EC: .4byte 0x080010B9
	.global _080014F0
_080014F0: .4byte 0x08002499
	.global _080014F4
_080014F4: .4byte 0x0800103D
	.global _080014F8
_080014F8: .4byte sub_08001640
	.global _080014FC
_080014FC: .4byte sub_08000DC8
	.global _08001500
_08001500: .4byte sub_080019F4
	.global _08001504
_08001504: .4byte sub_08001A74
	.global _08001508
_08001508: .4byte 0x08001C89
	.global _0800150C
_0800150C: .4byte 0x08001BD1
	.global _08001510
_08001510: .4byte 0x08001B29
	.global _08001514
_08001514: .4byte 0x00000000
	.global _08001518
_08001518: .4byte 0x05000040
	.byte 0x2A, 0xDF, 0x70, 0x47
