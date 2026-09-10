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
	thumb_func_start sub_08012C4C
sub_08012C4C:
	push {r4, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	ldr r0, _08012C78 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x8F
	bl sub_08016558
	bl sub_080065A8
	cmp r4, #0x02
	bhi _08012C7C
	movs r0, #0x91
	bl sub_08016558
	movs r1, #0x04
	movs r2, #0x01
	bl sub_08006950
	b _08012C90
	.global _08012C78
_08012C78: .4byte 0x083FDE18
	.global _08012C7C
_08012C7C:
	ldr r0, _08012D0C @ =0x0829F374
	movs r1, #0x06
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _08012D10 @ =0x0829F388
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006950
	.global _08012C90
_08012C90:
	cmp r4, #0x02
	bhi _08012C9E
	ldr r0, _08012D14 @ =0x083FEF00
	ldr r0, [r0, #0x00]
	ldr r1, _08012D18 @ =0x06010000
	bl sub_08016E28
	.global _08012C9E
_08012C9E:
	cmp r4, #0x00
	bne _08012CB0
	ldr r3, _08012D1C @ =0x08310160
	str r4, [sp, #0x000]
	movs r0, #0x58
	movs r1, #0x40
	movs r2, #0x00
	bl sub_080100CC
	.global _08012CB0
_08012CB0:
	cmp r4, #0x01
	bne _08012CC4
	ldr r3, _08012D20 @ =0x0830EC58
	movs r0, #0x00
	str r0, [sp, #0x000]
	movs r0, #0x58
	movs r1, #0x40
	movs r2, #0x00
	bl sub_080100CC
	.global _08012CC4
_08012CC4:
	cmp r4, #0x02
	bne _08012CD8
	ldr r3, _08012D24 @ =0x08310140
	movs r0, #0x00
	str r0, [sp, #0x000]
	movs r0, #0x58
	movs r1, #0x40
	movs r2, #0x00
	bl sub_080100CC
	.global _08012CD8
_08012CD8:
	cmp r4, #0x00
	bne _08012CE6
	ldr r0, _08012D28 @ =0x0829F3A4
	movs r1, #0x12
	movs r2, #0x01
	bl sub_08006950
	.global _08012CE6
_08012CE6:
	cmp r4, #0x01
	bne _08012CF4
	ldr r0, _08012D2C @ =0x0829F3AC
	movs r1, #0x12
	movs r2, #0x01
	bl sub_08006950
	.global _08012CF4
_08012CF4:
	cmp r4, #0x02
	bne _08012D02
	ldr r0, _08012D30 @ =0x0829F3B4
	movs r1, #0x12
	movs r2, #0x01
	bl sub_08006950
	.global _08012D02
_08012D02:
	add sp, #0x004
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08012D0C
_08012D0C: .4byte 0x0829F374
	.global _08012D10
_08012D10: .4byte 0x0829F388
	.global _08012D14
_08012D14: .4byte 0x083FEF00
	.global _08012D18
_08012D18: .4byte 0x06010000
	.global _08012D1C
_08012D1C: .4byte 0x08310160
	.global _08012D20
_08012D20: .4byte 0x0830EC58
	.global _08012D24
_08012D24: .4byte 0x08310140
	.global _08012D28
_08012D28: .4byte 0x0829F3A4
	.global _08012D2C
_08012D2C: .4byte 0x0829F3AC
	.global _08012D30
_08012D30: .4byte 0x0829F3B4
