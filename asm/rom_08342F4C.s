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
	thumb_func_start sub_08342F4C
sub_08342F4C:
	push {r4, lr}
	add sp, #-0x008
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x08]
	mov r2, sp
	bl sub_08341644
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08342F74
	ldr r0, [sp, #0x000]
	subs r0, #0x04
	str r0, [sp, #0x000]
	ldr r1, [sp, #0x004]
	subs r1, #0x04
	ldr r0, [r4, #0x04]
	asrs r0, r0, #0x02
	adds r1, r1, r0
	str r1, [sp, #0x004]
_08342F74:
	ldr r2, [r4, #0x18]
	adds r2, #0x02
	str r2, [r4, #0x18]
	ldr r0, [r4, #0x04]
	subs r0, #0x01
	str r0, [r4, #0x04]
	ldr r1, [r4, #0x28]
	asrs r1, r1, #0x01
	ldr r0, [r4, #0x00]
	adds r0, r0, r1
	str r0, [r4, #0x00]
	ldr r1, [r4, #0x30]
	asrs r1, r1, #0x01
	ldr r0, [r4, #0x08]
	adds r0, r0, r1
	str r0, [r4, #0x08]
	cmp r2, #0x10
	bne _08342FA4
	adds r0, r4, #0x0
	bl sub_0833FFA8
	adds r0, r4, #0x0
	bl sub_0833FF84
_08342FA4:
	add sp, #0x008
	pop {r4}
	pop {r0}
	bx r0
