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
	thumb_func_start sub_08342948
sub_08342948:
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _083429A4 @ =0x0203E000
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _083429A8 @ =0x020392C4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0834299C
	movs r0, #0x05
	bl sub_0833BD94
	movs r1, #0x4C
	movs r2, #0x18
	bl sub_08343148
	ldr r0, [r4, #0x18]
	subs r0, #0x01
	str r0, [r4, #0x18]
	cmp r0, #0x00
	bne _0834299C
	adds r0, r4, #0x0
	bl sub_0833FFA8
	adds r0, r4, #0x0
	bl sub_0833FF84
	movs r0, #0x0A
	movs r1, #0x00
	bl sub_0833D288
	bl sub_08339B18
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2, #0x00]
	ldr r0, _083429AC @ =0x0000EFFF
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r1, _083429B0 @ =0x020391F0
	movs r0, #0x02
	strb r0, [r1, #0x00]
_0834299C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_083429A4: .4byte 0x0203E000
_083429A8: .4byte 0x020392C4
_083429AC: .4byte 0x0000EFFF
_083429B0: .4byte 0x020391F0
