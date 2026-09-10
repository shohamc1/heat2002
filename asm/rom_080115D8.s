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
	thumb_func_start sub_080115D8
sub_080115D8:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0x0
	ldr r0, _08011648 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x5A
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x05
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _08011600
	movs r2, #0x01
	.global _08011600
_08011600:
	movs r1, #0x07
	bl sub_08006950
	movs r0, #0x06
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _08011614
	movs r2, #0x01
	.global _08011614
_08011614:
	movs r1, #0x09
	bl sub_08006950
	movs r0, #0x07
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x02
	bne _08011628
	movs r2, #0x01
	.global _08011628
_08011628:
	movs r1, #0x0B
	bl sub_08006950
	movs r0, #0x08
	bl sub_08016558
	movs r2, #0x00
	cmp r5, #0x03
	bne _0801163C
	movs r2, #0x01
	.global _0801163C
_0801163C:
	movs r1, #0x0D
	bl sub_08006950
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08011648
_08011648: .4byte 0x083FDE18
