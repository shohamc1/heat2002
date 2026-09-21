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
	thumb_func_start sub_0833DCB0
sub_0833DCB0:
	push {r4, r5, lr}
	ldr r4, _0833DD28 @ =0xFFFFFE00
	add sp, r4
	ldr r1, _0833DD2C @ =0x0203B850
	movs r0, #0xFF
	strb r0, [r1, #0x00]
	bl sub_0833DA34
	ldr r1, _0833DD30 @ =0x0203B6FC
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _0833DDA0
	ldr r0, _0833DD34 @ =0x02038F70
	bl sub_0833B074
	ldr r0, _0833DD38 @ =0x02038FB0
	bl sub_0833B074
	ldr r0, _0833DD3C @ =0x02038FF0
	bl sub_0833B074
	ldr r0, _0833DD40 @ =0x02039040
	bl sub_0833B074
	.global _0833DCE4
_0833DCE4:
	ldr r0, _0833DD44 @ =0x02039134
	movs r1, #0x00
	strh r1, [r0, #0x00]
	bl sub_0833C874
	cmp r0, #0x00
	beq _0833DD5C
	movs r0, #0x00
	bl sub_0833BD94
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_0833EE88
	ldr r0, _0833DD48 @ =0x0200CF1C
	movs r1, #0x0C
	movs r2, #0x01
	bl sub_0833EE88
	ldr r0, _0833DD4C @ =0x0200CF34
	movs r1, #0x0D
	movs r2, #0x01
	bl sub_0833EE88
	bl sub_0833AE90
	movs r5, #0x00
	ldr r4, _0833DD50 @ =0x0203E1B0
	.global _0833DD1C
_0833DD1C:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _0833DD54
	movs r0, #0x27
	b _0833DDA2
	.byte 0x00, 0x00
	.global _0833DD28
_0833DD28: .4byte 0xFFFFFE00
	.global _0833DD2C
_0833DD2C: .4byte 0x0203B850
	.global _0833DD30
_0833DD30: .4byte 0x0203B6FC
	.global _0833DD34
_0833DD34: .4byte 0x02038F70
	.global _0833DD38
_0833DD38: .4byte 0x02038FB0
	.global _0833DD3C
_0833DD3C: .4byte 0x02038FF0
	.global _0833DD40
_0833DD40: .4byte 0x02039040
	.global _0833DD44
_0833DD44: .4byte 0x02039134
	.global _0833DD48
_0833DD48: .4byte 0x0200CF1C
	.global _0833DD4C
_0833DD4C: .4byte 0x0200CF34
	.global _0833DD50
_0833DD50: .4byte 0x0203E1B0
	.global _0833DD54
_0833DD54:
	bl sub_08344B74
	cmp r5, #0x00
	beq _0833DD1C
	.global _0833DD5C
_0833DD5C:
	bl sub_0833DA34
	ldr r1, _0833DD78 @ =0x0203B6FC
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x00
	beq _0833DD7C
	bl sub_0833DC7C
	movs r0, #0x01
	b _0833DDA2
	.global _0833DD78
_0833DD78: .4byte 0x0203B6FC
	.global _0833DD7C
_0833DD7C:
	bl sub_0833DC14
	ldr r0, _0833DD98 @ =0x020390AC
	ldr r1, [r0, #0x00]
	adds r1, #0x01
	str r1, [r0, #0x00]
	ldr r0, _0833DD9C @ =0x020390D0
	strb r4, [r0, #0x00]
	.global _0833DD8C
_0833DD8C:
	ldr r0, _0833DD9C @ =0x020390D0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833DD8C
	b _0833DCE4
	.byte 0x00, 0x00
	.global _0833DD98
_0833DD98: .4byte 0x020390AC
	.global _0833DD9C
_0833DD9C: .4byte 0x020390D0
	.global _0833DDA0
_0833DDA0:
	movs r0, #0x00
	.global _0833DDA2
_0833DDA2:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
