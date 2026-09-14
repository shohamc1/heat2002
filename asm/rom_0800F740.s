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
	thumb_func_start sub_0800F740
sub_0800F740:
	push {lr}
	mov r12, r4
	ldr r4, _0800F7B4 @ =0xFFFFFE00
	add sp, r4
	mov r4, r12
	ldr r1, _0800F7B8 @ =0x04000008
	ldr r2, _0800F7BC @ =0x00001C0D
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	adds r1, #0x04
	ldr r2, _0800F7C0 @ =0x00001F82
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F7C4 @ =0x083171A4
	movs r1, #0xC0
	lsls r1, r1, #0x13
	ldr r2, _0800F7C8 @ =0x00005140
	bl sub_08016E10
	ldr r0, _0800F7CC @ =0x0833338C
	ldr r1, _0800F7D0 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0x88
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F7D4 @ =0x08316D30
	ldr r1, _0800F7D8 @ =0x08316E5C
	bl sub_080106CC
	ldr r0, _0800F7DC @ =0x08316B30
	mov r1, sp
	bl sub_0800F328
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r0, #0x96
	lsls r0, r0, #0x02
	bl sub_080102BC
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r0}
	bx r0
	.global _0800F7B4
_0800F7B4: .4byte 0xFFFFFE00
	.global _0800F7B8
_0800F7B8: .4byte 0x04000008
	.global _0800F7BC
_0800F7BC: .4byte 0x00001C0D
	.global _0800F7C0
_0800F7C0: .4byte 0x00001F82
	.global _0800F7C4
_0800F7C4: .4byte 0x083171A4
	.global _0800F7C8
_0800F7C8: .4byte 0x00005140
	.global _0800F7CC
_0800F7CC: .4byte 0x0833338C
	.global _0800F7D0
_0800F7D0: .4byte 0x0600C000
	.global _0800F7D4
_0800F7D4: .4byte 0x08316D30
	.global _0800F7D8
_0800F7D8: .4byte 0x08316E5C
	.global _0800F7DC
_0800F7DC: .4byte 0x08316B30
