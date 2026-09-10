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
	thumb_func_start sub_08012984
sub_08012984:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080129D0 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0xA9
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0xC5
	bl sub_08016558
	movs r1, #0x06
	movs r2, #0x01
	bl sub_08006950
	adds r0, r4, #0x0
	adds r0, #0xC5
	bl sub_08016558
	movs r1, #0x07
	movs r2, #0x01
	bl sub_08006950
	cmp r4, #0x04
	beq _080129D4
	adds r0, r4, #0x0
	adds r0, #0xAA
	bl sub_08016558
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006950
	b _080129E2
	.global _080129D0
_080129D0: .4byte 0x083FDE18
	.global _080129D4
_080129D4:
	movs r0, #0xB3
	bl sub_08016558
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006950
	.global _080129E2
_080129E2:
	pop {r4}
	pop {r0}
	bx r0
