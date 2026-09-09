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
	thumb_func_start sub_0833AAB8
sub_0833AAB8:
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	ldr r1, _0833AB84 @ =0x04000084
	movs r0, #0x8F
	strh r0, [r1, #0x00]
	ldr r2, _0833AB88 @ =0x04000080
	movs r0, #0x77
	strh r0, [r2, #0x00]
	ldr r0, _0833AB8C @ =0x04000063
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
	ldr r1, _0833AB90 @ =0x04000070
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r1, _0833AB94 @ =0x0000FF77
	adds r0, r1, #0x0
	strh r0, [r2, #0x00]
	ldr r0, _0833AB98 @ =0x03007FF0
	ldr r4, [r0, #0x00]
	ldr r6, [r4, #0x00]
	ldr r0, _0833AB9C @ =0x68736D53
	cmp r6, r0
	bne _0833AB7C
	adds r0, r6, #0x1
	str r0, [r4, #0x00]
	ldr r1, _0833ABA0 @ =0x02038DE0
	ldr r0, _0833ABA4 @ =0x02002F81
	str r0, [r1, #0x20]
	ldr r0, _0833ABA8 @ =0x02001CE5
	str r0, [r1, #0x44]
	ldr r0, _0833ABAC @ =0x02001CF9
	str r0, [r1, #0x4C]
	ldr r0, _0833ABB0 @ =0x020030D9
	str r0, [r1, #0x70]
	ldr r0, _0833ABB4 @ =0x02001C7D
	str r0, [r1, #0x74]
	ldr r0, _0833ABB8 @ =0x02002281
	str r0, [r1, #0x78]
	ldr r0, _0833ABBC @ =0x02001A09
	str r0, [r1, #0x7C]
	adds r2, r1, #0x0
	adds r2, #0x80
	ldr r0, _0833ABC0 @ =0x02002635
	str r0, [r2, #0x00]
	adds r1, #0x84
	ldr r0, _0833ABC4 @ =0x020026B5
	str r0, [r1, #0x00]
	str r5, [r4, #0x1C]
	ldr r0, _0833ABC8 @ =0x020028C9
	str r0, [r4, #0x28]
	ldr r0, _0833ABCC @ =0x02002811
	str r0, [r4, #0x2C]
	ldr r0, _0833ABD0 @ =0x02002769
	str r0, [r4, #0x30]
	ldr r0, _0833ABD4 @ =0x00000000
	movs r1, #0x00
	strb r0, [r4, #0x0C]
	str r1, [sp, #0x000]
	ldr r2, _0833ABD8 @ =0x05000040
	mov r0, sp
	adds r1, r5, #0x0
	bl sub_08344B64
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
	.global _0833AB7C
_0833AB7C:
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _0833AB84
_0833AB84: .4byte 0x04000084
	.global _0833AB88
_0833AB88: .4byte 0x04000080
	.global _0833AB8C
_0833AB8C: .4byte 0x04000063
	.global _0833AB90
_0833AB90: .4byte 0x04000070
	.global _0833AB94
_0833AB94: .4byte 0x0000FF77
	.global _0833AB98
_0833AB98: .4byte 0x03007FF0
	.global _0833AB9C
_0833AB9C: .4byte 0x68736D53
	.global _0833ABA0
_0833ABA0: .4byte 0x02038DE0
	.global _0833ABA4
_0833ABA4: .4byte 0x02002F81
	.global _0833ABA8
_0833ABA8: .4byte 0x02001CE5
	.global _0833ABAC
_0833ABAC: .4byte 0x02001CF9
	.global _0833ABB0
_0833ABB0: .4byte 0x020030D9
	.global _0833ABB4
_0833ABB4: .4byte 0x02001C7D
	.global _0833ABB8
_0833ABB8: .4byte 0x02002281
	.global _0833ABBC
_0833ABBC: .4byte 0x02001A09
	.global _0833ABC0
_0833ABC0: .4byte 0x02002635
	.global _0833ABC4
_0833ABC4: .4byte 0x020026B5
	.global _0833ABC8
_0833ABC8: .4byte 0x020028C9
	.global _0833ABCC
_0833ABCC: .4byte 0x02002811
	.global _0833ABD0
_0833ABD0: .4byte 0x02002769
	.global _0833ABD4
_0833ABD4: .4byte 0x00000000
	.global _0833ABD8
_0833ABD8: .4byte 0x05000040
	.byte 0x2A, 0xDF, 0x70, 0x47
	thumb_func_start sub_0833ABE0
sub_0833ABE0:
	push {lr}
	ldr r1, _0833ABF0 @ =0x02038E68
	ldr r1, [r1, #0x00]
	bl _08344B80
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833ABF0
_0833ABF0: .4byte 0x02038E68
