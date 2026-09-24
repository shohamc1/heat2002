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
	thumb_func_start sub_0800B1A4
sub_0800B1A4:
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldr r0, _0800B2A8 @ =0x02022E14
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800B2A2
	ldr r0, [r6, #0x18]
	cmp r0, #0x00
	beq _0800B1BE
	cmp r0, #0x14
	beq _0800B1BE
	cmp r0, #0x28
	bne _0800B1D4
_0800B1BE:
	ldr r0, _0800B2AC @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0800B1D4
	ldr r0, _0800B2B0 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800B1D4
	movs r0, #0x17
	bl sub_08001208
_0800B1D4:
	ldr r0, [r6, #0x18]
	cmp r0, #0x3C
	bne _0800B1F0
	ldr r0, _0800B2AC @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0800B1F0
	ldr r0, _0800B2B0 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800B1F0
	movs r0, #0x15
	bl sub_08001208
_0800B1F0:
	ldr r4, [r6, #0x18]
	adds r0, r4, #0x0
	subs r0, #0x3C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x17
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r4, #0x3C
	ble _0800B242
	ldr r0, _0800B2B4 @ =0x083FF5B0
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	bl sub_0800754C
	adds r5, r0, #0x0
	cmp r5, #0x00
	beq _0800B242
	movs r4, #0x68
	lsls r4, r4, #0x10
	movs r0, #0x40
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r4, r0
	ldr r0, _0800B2B8 @ =0x08330AD4
	bl sub_08007714
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	movs r1, #0x80
	lsls r1, r1, #0x03
	orrs r0, r1
	ldr r1, [r5, #0x10]
	orrs r1, r0
	adds r0, r4, #0x0
	bl sub_080044A4
_0800B242:
	ldr r2, [r6, #0x18]
	cmp r2, #0x2D
	ble _0800B282
	ldr r1, _0800B2BC @ =0x0200215C
	ldrb r0, [r1, #0x00]
	cmp r0, #0x09
	bne _0800B254
	movs r0, #0x06
	strb r0, [r1, #0x00]
_0800B254:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x0D
	bne _0800B25E
	movs r0, #0x0C
	strb r0, [r1, #0x00]
_0800B25E:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x0E
	bne _0800B268
	movs r0, #0x02
	strb r0, [r1, #0x00]
_0800B268:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x0F
	bne _0800B272
	movs r0, #0x10
	strb r0, [r1, #0x00]
_0800B272:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x11
	bne _0800B27C
	movs r0, #0x05
	strb r0, [r1, #0x00]
_0800B27C:
	ldr r1, _0800B2C0 @ =0x020020C4
	movs r0, #0x01
	strb r0, [r1, #0x00]
_0800B282:
	adds r0, r2, #0x1
	str r0, [r6, #0x18]
	cmp r0, #0x7A
	bne _0800B296
	adds r0, r6, #0x0
	bl sub_08007950
	adds r0, r6, #0x0
	bl sub_0800792C
_0800B296:
	ldr r0, _0800B2C0 @ =0x020020C4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800B2A2
	bl sub_08000458
_0800B2A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0800B2A8: .4byte 0x02022E14
_0800B2AC: .4byte 0x0202EF00
_0800B2B0: .4byte 0x020020E0
_0800B2B4: .4byte 0x083FF5B0
_0800B2B8: .4byte 0x08330AD4
_0800B2BC: .4byte 0x0200215C
_0800B2C0: .4byte 0x020020C4
