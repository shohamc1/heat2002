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
	.byte 0x00, 0xB5, 0x04, 0x48, 0x14, 0x21, 0x4C, 0x22, 0xFD, 0xF7, 0x54, 0xFA, 0x00, 0x06, 0x00, 0x0E
	.byte 0x02, 0xBC, 0x08, 0x47, 0x18, 0xF5, 0x29, 0x08
	thumb_func_start sub_08014EE8
sub_08014EE8:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0x0
	ldr r0, _08014F58 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x09
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x05
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _08014F10
	movs r2, #0x01
	.global _08014F10
_08014F10:
	movs r1, #0x07
	bl sub_08006950
	movs r0, #0x06
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _08014F24
	movs r2, #0x01
	.global _08014F24
_08014F24:
	movs r1, #0x09
	bl sub_08006950
	movs r0, #0x9D
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x02
	bne _08014F38
	movs r2, #0x01
	.global _08014F38
_08014F38:
	movs r1, #0x0B
	bl sub_08006950
	movs r0, #0x08
	bl sub_08016558
	movs r2, #0x00
	cmp r5, #0x03
	bne _08014F4C
	movs r2, #0x01
	.global _08014F4C
_08014F4C:
	movs r1, #0x0D
	bl sub_08006950
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08014F58
_08014F58: .4byte 0x083FDE18
