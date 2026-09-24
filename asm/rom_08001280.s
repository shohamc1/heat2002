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
	thumb_func_start sub_08001280
sub_08001280:
	push {lr}
	lsls r0, r0, #0x10
	ldr r2, _080012AC @ =0x0801DA90
	ldr r1, _080012B0 @ =0x0801DACC
	lsrs r0, r0, #0x0D
	adds r0, r0, r1
	ldrh r3, [r0, #0x04]
	lsls r1, r3, #0x01
	adds r1, r1, r3
	lsls r1, r1, #0x02
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldr r3, [r1, #0x00]
	ldr r2, [r0, #0x00]
	cmp r3, r2
	beq _080012B4
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	bl sub_08001900
	b _080012D0
	.byte 0x00, 0x00
_080012AC: .4byte 0x0801DA90
_080012B0: .4byte 0x0801DACC
_080012B4:
	ldr r2, [r1, #0x04]
	ldrh r0, [r1, #0x04]
	cmp r0, #0x00
	bne _080012C6
	adds r0, r1, #0x0
	adds r1, r3, #0x0
	bl sub_08001900
	b _080012D0
_080012C6:
	cmp r2, #0x00
	bge _080012D0
	adds r0, r1, #0x0
	bl sub_08001134
_080012D0:
	pop {r0}
	bx r0
