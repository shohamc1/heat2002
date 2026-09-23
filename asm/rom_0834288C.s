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
	thumb_func_start sub_0834288C
sub_0834288C:
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _083428F4 @ =0x020392C4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _083428EC
	ldr r0, _083428F8 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _083428B0
	movs r0, #0x04
	bl sub_0833BD94
	movs r1, #0x0A
	movs r2, #0x03
	movs r3, #0x01
	bl sub_0833EF0C
_083428B0:
	ldr r0, [r4, #0x18]
	subs r0, #0x01
	str r0, [r4, #0x18]
	cmp r0, #0x00
	bne _083428EC
	adds r0, r4, #0x0
	bl sub_0833FFA8
	adds r0, r4, #0x0
	bl sub_0833FF84
	ldr r0, _083428FC @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x04
	beq _083428E6
	movs r0, #0x0A
	movs r1, #0x00
	bl sub_0833D288
	bl sub_08339B18
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2, #0x00]
	ldr r0, _08342900 @ =0x0000EFFF
	ands r0, r1
	strh r0, [r2, #0x00]
_083428E6:
	ldr r1, _08342904 @ =0x020391F0
	movs r0, #0x02
	strb r0, [r1, #0x00]
_083428EC:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_083428F4: .4byte 0x020392C4
_083428F8: .4byte 0x020390EC
_083428FC: .4byte 0x0203916C
_08342900: .4byte 0x0000EFFF
_08342904: .4byte 0x020391F0
