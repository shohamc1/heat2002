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
	thumb_func_start sub_08341A30
sub_08341A30:
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, _08341A88 @ =0x0202772C
	lsls r2, r2, #0x02
	adds r2, r2, r0
	ldr r4, [r2, #0x00]
	ldr r0, _08341A8C @ =0x020390AC
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x01
	movs r1, #0x07
	bl sub_08344C50
	lsls r0, r0, #0x02
	adds r4, r4, r0
	movs r0, #0xFF
	ands r6, r0
	ldr r0, _08341A90 @ =0x000001FF
	ands r0, r5
	lsls r0, r0, #0x10
	orrs r6, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r6, r0
	ldr r0, [r4, #0x00]
	bl sub_0833FC94
	cmp r0, #0x00
	beq _08341A80
	ldr r4, [r0, #0x10]
	ldr r0, _08341A94 @ =0x020243E8
	bl sub_0833FD78
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	orrs r4, r0
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl sub_0833D6A0
	.global _08341A80
_08341A80:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08341A88
_08341A88: .4byte 0x0202772C
	.global _08341A8C
_08341A8C: .4byte 0x020390AC
	.global _08341A90
_08341A90: .4byte 0x000001FF
	.global _08341A94
_08341A94: .4byte 0x020243E8
	.byte 0x10, 0xB5, 0x02, 0x9C, 0x8A, 0x42, 0x01, 0xDD, 0x20, 0x1C, 0x0B, 0xE0, 0x11, 0x1A, 0x00, 0x29
	.byte 0x07, 0xDB, 0x80, 0x20, 0xC0, 0x01, 0x40, 0x1A, 0x58, 0x43, 0x61, 0x43, 0x40, 0x18, 0x80, 0x13
	.byte 0x00, 0xE0, 0x18, 0x1C, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
