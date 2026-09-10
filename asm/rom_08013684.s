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
	thumb_func_start sub_08013684
sub_08013684:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0x0
	ldr r0, _080136F4 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x00
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x01
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _080136AC
	movs r2, #0x01
	.global _080136AC
_080136AC:
	movs r1, #0x06
	bl sub_08006950
	movs r0, #0x02
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _080136C0
	movs r2, #0x01
	.global _080136C0
_080136C0:
	movs r1, #0x08
	bl sub_08006950
	movs r0, #0x03
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x02
	bne _080136D4
	movs r2, #0x01
	.global _080136D4
_080136D4:
	movs r1, #0x0A
	bl sub_08006950
	movs r0, #0x08
	bl sub_08016558
	movs r2, #0x00
	cmp r5, #0x03
	bne _080136E8
	movs r2, #0x01
	.global _080136E8
_080136E8:
	movs r1, #0x0C
	bl sub_08006950
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _080136F4
_080136F4: .4byte 0x083FDE18
