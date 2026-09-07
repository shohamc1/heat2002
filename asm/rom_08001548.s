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
	thumb_func_start sub_08001548
sub_08001548:
	push {r4, r5, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	movs r3, #0x00
	str r3, [r5, #0x00]
	ldr r1, _08001600 @ =0x040000C4
	ldr r0, [r1, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x12
	ands r0, r2
	cmp r0, #0x00
	beq _08001564
	ldr r0, _08001604 @ =0x84400004
	str r0, [r1, #0x00]
	.global _08001564
_08001564:
	ldr r1, _08001608 @ =0x040000D0
	ldr r0, [r1, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _08001572
	ldr r0, _08001604 @ =0x84400004
	str r0, [r1, #0x00]
	.global _08001572
_08001572:
	ldr r0, _0800160C @ =0x040000C6
	movs r2, #0x80
	lsls r2, r2, #0x03
	adds r1, r2, #0x0
	strh r1, [r0, #0x00]
	adds r0, #0x0C
	strh r1, [r0, #0x00]
	ldr r1, _08001610 @ =0x04000084
	movs r0, #0x8F
	strh r0, [r1, #0x00]
	subs r1, #0x02
	ldr r2, _08001614 @ =0x0000A90E
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r2, _08001618 @ =0x04000089
	ldrb r1, [r2, #0x00]
	movs r0, #0x3F
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2, #0x00]
	ldr r1, _0800161C @ =0x040000BC
	movs r2, #0xD4
	lsls r2, r2, #0x02
	adds r0, r5, r2
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _08001620 @ =0x040000A0
	str r0, [r1, #0x00]
	adds r1, #0x08
	movs r2, #0x98
	lsls r2, r2, #0x04
	adds r0, r5, r2
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _08001624 @ =0x040000A4
	str r0, [r1, #0x00]
	ldr r0, _08001628 @ =0x03007FF0
	str r5, [r0, #0x00]
	str r3, [sp, #0x000]
	ldr r2, _0800162C @ =0x050003EC
	mov r0, sp
	adds r1, r5, #0x0
	bl sub_08016E10
	movs r0, #0x08
	strb r0, [r5, #0x06]
	movs r0, #0x0F
	strb r0, [r5, #0x07]
	ldr r0, _08001630 @ =0x08000E3D
	str r0, [r5, #0x38]
	ldr r0, _08001634 @ =0x080025B9
	str r0, [r5, #0x28]
	str r0, [r5, #0x2C]
	str r0, [r5, #0x30]
	str r0, [r5, #0x3C]
	ldr r4, _08001638 @ =0x02001D90
	adds r0, r4, #0x0
	bl sub_08000958
	str r4, [r5, #0x34]
	movs r0, #0x80
	lsls r0, r0, #0x0B
	bl sub_08001640
	ldr r0, _0800163C @ =0x68736D53
	str r0, [r5, #0x00]
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08001600
_08001600: .4byte 0x040000C4
	.global _08001604
_08001604: .4byte 0x84400004
	.global _08001608
_08001608: .4byte 0x040000D0
	.global _0800160C
_0800160C: .4byte 0x040000C6
	.global _08001610
_08001610: .4byte 0x04000084
	.global _08001614
_08001614: .4byte 0x0000A90E
	.global _08001618
_08001618: .4byte 0x04000089
	.global _0800161C
_0800161C: .4byte 0x040000BC
	.global _08001620
_08001620: .4byte 0x040000A0
	.global _08001624
_08001624: .4byte 0x040000A4
	.global _08001628
_08001628: .4byte 0x03007FF0
	.global _0800162C
_0800162C: .4byte 0x050003EC
	.global _08001630
_08001630: .4byte 0x08000E3D
	.global _08001634
_08001634: .4byte 0x080025B9
	.global _08001638
_08001638: .4byte 0x02001D90
	.global _0800163C
_0800163C: .4byte 0x68736D53
