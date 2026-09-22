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
	thumb_func_start sub_08019D1C
sub_08019D1C:
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	adds r4, r2, #0x0
	cmp r4, #0x00
	beq _08019D50
	ldr r1, _08019D44 @ =0x08339530
	adds r0, r4, #0x0
	bl sub_0801AF74
	cmp r0, #0x00
	beq _08019D4C
	ldr r1, _08019D48 @ =0x08339528
	adds r0, r4, #0x0
	bl sub_0801AF74
	cmp r0, #0x00
	beq _08019D4C
	movs r0, #0x00
	b _08019D52
	.global _08019D44
_08019D44: .4byte 0x08339530
	.global _08019D48
_08019D48: .4byte 0x08339528
	.global _08019D4C
_08019D4C:
	str r6, [r5, #0x30]
	str r4, [r5, #0x34]
	.global _08019D50
_08019D50:
	ldr r0, _08019D54 @ =0x08339530
	.global _08019D52
_08019D52:
	pop {r4, r5, r6, pc}
	.global _08019D54
_08019D54: .4byte 0x08339530
