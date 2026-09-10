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
	thumb_func_start sub_0800F328
sub_0800F328:
	push {r4, r5, lr}
	adds r5, r1, #0x0
	movs r2, #0x80
	lsls r2, r2, #0x01
	bl sub_08016E10
	ldr r4, _0800F3A0 @ =0x08332BC8
	movs r0, #0xF0
	lsls r0, r0, #0x01
	adds r1, r5, r0
	adds r0, r4, #0x0
	movs r2, #0x10
	bl sub_08016E10
	movs r2, #0xE0
	lsls r2, r2, #0x01
	adds r1, r5, r2
	adds r0, r4, #0x0
	movs r2, #0x10
	bl sub_08016E10
	movs r0, #0x34
	movs r1, #0x34
	movs r2, #0x34
	bl sub_08011C44
	movs r2, #0xEA
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	movs r0, #0x24
	movs r1, #0x24
	movs r2, #0x24
	bl sub_08011C44
	movs r2, #0xEB
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	movs r0, #0x0E
	movs r1, #0x0E
	movs r2, #0x0E
	bl sub_08011C44
	movs r2, #0xEC
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl sub_08011C44
	movs r2, #0xED
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _0800F3A0
_0800F3A0: .4byte 0x08332BC8
