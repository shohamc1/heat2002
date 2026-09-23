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
	thumb_func_start sub_08342B54
sub_08342B54:
	push {r4, lr}
	add sp, #-0x028
	adds r4, r0, #0x0
	movs r0, #0x06
	bl sub_0833BD94
	movs r1, #0x09
	movs r2, #0x05
	bl sub_0833EF0C
	ldr r0, _08342B9C @ =0x0203DE30
	movs r1, #0x0D
	movs r2, #0x05
	bl sub_0833EF0C
	ldr r0, [r4, #0x18]
	subs r0, #0x01
	str r0, [r4, #0x18]
	cmp r0, #0x00
	bne _08342B92
	ldr r0, _08342BA0 @ =0x0200D118
	movs r1, #0x09
	movs r2, #0x05
	bl sub_0833EF0C
	adds r0, r4, #0x0
	bl sub_0833FFA8
	adds r0, r4, #0x0
	bl sub_0833FF84
_08342B92:
	add sp, #0x028
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08342B9C: .4byte 0x0203DE30
_08342BA0: .4byte 0x0200D118
