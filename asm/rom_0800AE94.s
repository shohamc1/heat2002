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
	thumb_func_start sub_0800AE94
sub_0800AE94:
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x18]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _0800AEB4
	ldr r0, _0800AEB0 @ =0x0806C948
	movs r1, #0x0B
	movs r2, #0x0A
	bl sub_0800649C
	b _0800AEBE
	.byte 0x00, 0x00
_0800AEB0: .4byte 0x0806C948
_0800AEB4:
	ldr r0, _0800AF0C @ =0x0806C954
	movs r1, #0x0B
	movs r2, #0x0A
	bl sub_0800649C
_0800AEBE:
	ldr r0, [r4, #0x18]
	subs r0, #0x01
	str r0, [r4, #0x18]
	bl sub_0800048C
	ldr r1, _0800AF10 @ =0x020005C8
	ldr r0, _0800AF14 @ =0x000003FF
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _0800AEDA
	ldr r0, [r4, #0x18]
	cmp r0, #0x00
	bne _0800AF04
_0800AEDA:
	movs r0, #0x0A
	movs r1, #0x00
	bl sub_08003F84
	bl sub_08000458
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2, #0x00]
	ldr r0, _0800AF18 @ =0x0000EFFF
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r1, _0800AF1C @ =0x020021E0
	movs r0, #0x02
	strb r0, [r1, #0x00]
	adds r0, r4, #0x0
	bl sub_08007950
	adds r0, r4, #0x0
	bl sub_0800792C
_0800AF04:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800AF0C: .4byte 0x0806C954
_0800AF10: .4byte 0x020005C8
_0800AF14: .4byte 0x000003FF
_0800AF18: .4byte 0x0000EFFF
_0800AF1C: .4byte 0x020021E0
