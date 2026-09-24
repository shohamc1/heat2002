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
	thumb_func_start sub_08342A14
sub_08342A14:
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _08342A88 @ =0x020392C4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08342A80
	ldr r2, [r4, #0x18]
	cmp r2, #0x2D
	ble _08342A60
	ldr r1, _08342A8C @ =0x0203916C
	ldrb r0, [r1, #0x00]
	cmp r0, #0x09
	bne _08342A32
	movs r0, #0x06
	strb r0, [r1, #0x00]
_08342A32:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x0D
	bne _08342A3C
	movs r0, #0x0C
	strb r0, [r1, #0x00]
_08342A3C:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x0E
	bne _08342A46
	movs r0, #0x02
	strb r0, [r1, #0x00]
_08342A46:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x0F
	bne _08342A50
	movs r0, #0x10
	strb r0, [r1, #0x00]
_08342A50:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x11
	bne _08342A5A
	movs r0, #0x05
	strb r0, [r1, #0x00]
_08342A5A:
	ldr r1, _08342A90 @ =0x020390D4
	movs r0, #0x01
	strb r0, [r1, #0x00]
_08342A60:
	adds r0, r2, #0x1
	str r0, [r4, #0x18]
	cmp r0, #0x7A
	bne _08342A74
	adds r0, r4, #0x0
	bl sub_0833FFA8
	adds r0, r4, #0x0
	bl sub_0833FF84
_08342A74:
	ldr r0, _08342A90 @ =0x020390D4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08342A80
	bl sub_08339B18
_08342A80:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08342A88: .4byte 0x020392C4
_08342A8C: .4byte 0x0203916C
_08342A90: .4byte 0x020390D4
