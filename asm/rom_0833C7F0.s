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
	thumb_func_start sub_0833C7F0
sub_0833C7F0:
	push {lr}
	add sp, #-0x004
	ldr r0, _0833C804 @ =0x0203E1B0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833C808
	bl sub_08344B74
	b _0833C816
	.byte 0x00, 0x00
_0833C804: .4byte 0x0203E1B0
_0833C808:
	ldr r2, _0833C81C @ =0x03007FF8
	movs r3, #0x80
_0833C80C:
	ldrh r1, [r2, #0x00]
	adds r0, r3, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _0833C80C
_0833C816:
	add sp, #0x004
	pop {r0}
	bx r0
_0833C81C: .4byte 0x03007FF8
