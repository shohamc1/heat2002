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
	thumb_func_start sub_0800B384
sub_0800B384:
	push {r4, lr}
	add sp, #-0x028
	adds r4, r0, #0x0
	movs r0, #0x9A
	bl sub_08016558
	movs r1, #0x09
	movs r2, #0x05
	bl sub_0800649C
	ldr r0, _0800B3CC @ =0x0202CC10
	movs r1, #0x0D
	movs r2, #0x05
	bl sub_0800649C
	ldr r0, [r4, #0x18]
	subs r0, #0x01
	str r0, [r4, #0x18]
	cmp r0, #0x00
	bne _0800B3C2
	ldr r0, _0800B3D0 @ =0x0806C96C
	movs r1, #0x09
	movs r2, #0x05
	bl sub_0800649C
	adds r0, r4, #0x0
	bl sub_08007950
	adds r0, r4, #0x0
	bl sub_0800792C
_0800B3C2:
	add sp, #0x028
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800B3CC: .4byte 0x0202CC10
_0800B3D0: .4byte 0x0806C96C
