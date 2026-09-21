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
	thumb_func_start sub_0833FDC4
sub_0833FDC4:
	push {r4, r5, r6, r7, lr}
	ldr r4, _0833FE98 @ =0xFFFFFE00
	add sp, r4
	ldr r1, _0833FE9C @ =0x0203C334
	movs r0, #0x00
	str r0, [r1, #0x00]
	ldr r5, _0833FEA0 @ =0x0203C220
	movs r6, #0x00
	.global _0833FDD4
_0833FDD4:
	ldrb r0, [r5, #0x04]
	cmp r0, #0x00
	beq _0833FDE8
	ldr r0, [r5, #0x08]
	ldr r4, [r5, #0x0C]
	adds r1, r4, #0x0
	bl sub_08344B70
	movs r0, #0x00
	strb r0, [r5, #0x04]
	.global _0833FDE8
_0833FDE8:
	adds r6, #0x01
	adds r5, #0x14
	cmp r6, #0x04
	bne _0833FDD4
	ldr r5, _0833FEA4 @ =0x0203B870
	movs r6, #0x00
	.global _0833FDF4
_0833FDF4:
	ldrb r0, [r5, #0x04]
	cmp r0, #0x00
	beq _0833FE08
	ldr r0, [r5, #0x08]
	ldr r4, [r5, #0x0C]
	adds r1, r4, #0x0
	bl sub_08344B70
	movs r0, #0x00
	strb r0, [r5, #0x04]
	.global _0833FE08
_0833FE08:
	adds r6, #0x01
	adds r5, #0x14
	cmp r6, #0x18
	bne _0833FDF4
	ldr r5, _0833FEA8 @ =0x0203BA50
	movs r6, #0x00
	.global _0833FE14
_0833FE14:
	ldrb r0, [r5, #0x04]
	cmp r0, #0x00
	beq _0833FE32
	ldr r0, [r5, #0x08]
	ldr r4, [r5, #0x0C]
	mov r1, sp
	bl sub_08344B70
	mov r0, sp
	adds r1, r4, #0x0
	movs r2, #0x20
	bl sub_08344B64
	movs r0, #0x00
	strb r0, [r5, #0x04]
	.global _0833FE32
_0833FE32:
	adds r6, #0x01
	adds r5, #0x14
	cmp r6, #0x20
	bne _0833FE14
	ldr r5, _0833FEAC @ =0x0203BF50
	movs r6, #0x00
	.global _0833FE3E
_0833FE3E:
	ldrb r0, [r5, #0x04]
	cmp r0, #0x00
	beq _0833FE52
	ldr r0, [r5, #0x08]
	ldr r4, [r5, #0x0C]
	adds r1, r4, #0x0
	bl sub_08344B70
	movs r0, #0x00
	strb r0, [r5, #0x04]
	.global _0833FE52
_0833FE52:
	adds r6, #0x01
	adds r5, #0x14
	cmp r6, #0x14
	bne _0833FE3E
	ldr r5, _0833FEB0 @ =0x0203C0E0
	movs r6, #0x00
	.global _0833FE5E
_0833FE5E:
	ldrb r0, [r5, #0x04]
	cmp r0, #0x00
	beq _0833FE72
	ldr r0, [r5, #0x08]
	ldr r4, [r5, #0x0C]
	adds r1, r4, #0x0
	bl sub_08344B70
	movs r0, #0x00
	strb r0, [r5, #0x04]
	.global _0833FE72
_0833FE72:
	adds r6, #0x01
	adds r5, #0x14
	cmp r6, #0x10
	bne _0833FE5E
	ldr r5, _0833FEB4 @ =0x0203BCD0
	movs r6, #0x00
	.global _0833FE7E
_0833FE7E:
	ldrb r1, [r5, #0x04]
	cmp r1, #0x00
	beq _0833FEC2
	ldr r0, [r5, #0x08]
	ldr r4, [r5, #0x0C]
	cmp r1, #0x01
	bne _0833FEB8
	adds r1, r4, #0x0
	movs r2, #0x10
	bl sub_08344B64
	b _0833FEBE
	.byte 0x00, 0x00
	.global _0833FE98
_0833FE98: .4byte 0xFFFFFE00
	.global _0833FE9C
_0833FE9C: .4byte 0x0203C334
	.global _0833FEA0
_0833FEA0: .4byte 0x0203C220
	.global _0833FEA4
_0833FEA4: .4byte 0x0203B870
	.global _0833FEA8
_0833FEA8: .4byte 0x0203BA50
	.global _0833FEAC
_0833FEAC: .4byte 0x0203BF50
	.global _0833FEB0
_0833FEB0: .4byte 0x0203C0E0
	.global _0833FEB4
_0833FEB4: .4byte 0x0203BCD0
	.global _0833FEB8
_0833FEB8:
	adds r1, r4, #0x0
	bl sub_08344B70
	.global _0833FEBE
_0833FEBE:
	movs r0, #0x00
	strb r0, [r5, #0x04]
	.global _0833FEC2
_0833FEC2:
	adds r6, #0x01
	adds r5, #0x14
	cmp r6, #0x20
	bne _0833FE7E
	ldr r5, _0833FF10 @ =0x0203C270
	movs r6, #0x00
	ldr r7, _0833FF14 @ =0x0203C334
	.global _0833FED0
_0833FED0:
	ldrb r0, [r5, #0x01]
	cmp r0, #0x00
	beq _0833FEEC
	ldr r0, [r5, #0x04]
	ldr r4, [r5, #0x08]
	adds r1, r4, #0x0
	movs r2, #0x10
	bl sub_08344B64
	movs r0, #0x00
	strb r0, [r5, #0x01]
	ldr r0, [r7, #0x00]
	adds r0, #0x20
	str r0, [r7, #0x00]
	.global _0833FEEC
_0833FEEC:
	adds r6, #0x01
	adds r5, #0x0C
	cmp r6, #0x10
	bne _0833FED0
	ldr r0, _0833FF14 @ =0x0203C334
	ldr r2, _0833FF18 @ =0x0203C330
	ldr r1, [r0, #0x00]
	ldr r0, [r2, #0x00]
	cmp r1, r0
	ble _0833FF02
	str r1, [r2, #0x00]
	.global _0833FF02
_0833FF02:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833FF10
_0833FF10: .4byte 0x0203C270
	.global _0833FF14
_0833FF14: .4byte 0x0203C334
	.global _0833FF18
_0833FF18: .4byte 0x0203C330
