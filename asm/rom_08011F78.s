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
	thumb_func_start sub_08011F78
sub_08011F78:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0x0
	ldr r0, _08011FC0 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x5A
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x51
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _08011FA0
	movs r2, #0x01
	.global _08011FA0
_08011FA0:
	movs r1, #0x09
	bl sub_08006950
	movs r0, #0x52
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _08011FB4
	movs r2, #0x01
	.global _08011FB4
_08011FB4:
	movs r1, #0x0B
	bl sub_08006950
	pop {r4}
	pop {r0}
	bx r0
	.global _08011FC0
_08011FC0: .4byte 0x083FDE18
