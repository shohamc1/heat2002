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
	thumb_func_start sub_0800AB78
sub_0800AB78:
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r0, _0800ABAC @ =0x020020DC
	ldrb r1, [r0, #0x00]
	cmp r1, #0x00
	beq _0800ABC0
	ldr r0, _0800ABB0 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800ABB8
	adds r0, r5, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800ABB8
	ldr r0, _0800ABB4 @ =0x020020A0
	lsls r1, r6, #0x01
	adds r1, r1, r0
	ldrh r1, [r1, #0x00]
	adds r0, r5, #0x0
	adds r2, r6, #0x0
	bl sub_0800A80C
	b _0800AC4A
	.global _0800ABAC
_0800ABAC: .4byte 0x020020DC
	.global _0800ABB0
_0800ABB0: .4byte 0x020021E0
	.global _0800ABB4
_0800ABB4: .4byte 0x020020A0
	.global _0800ABB8
_0800ABB8:
	adds r0, r5, #0x0
	movs r1, #0x02
	adds r2, r6, #0x0
	b _0800AC46
	.global _0800ABC0
_0800ABC0:
	cmp r6, #0x00
	bne _0800AC52
	ldr r1, _0800ABE8 @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800ABEC
	adds r0, r5, #0x0
	movs r1, #0x00
	bl sub_080093BC
	adds r0, r5, #0x0
	adds r0, #0xA0
	ldrh r1, [r0, #0x00]
	adds r0, r5, #0x0
	movs r2, #0x00
	bl sub_0800A80C
	b _0800ACCA
	.byte 0x00, 0x00
	.global _0800ABE8
_0800ABE8: .4byte 0x00000175
	.global _0800ABEC
_0800ABEC:
	ldr r0, _0800AC1C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _0800AC04
	cmp r0, #0x0D
	beq _0800AC04
	cmp r0, #0x0E
	beq _0800AC04
	cmp r0, #0x0F
	beq _0800AC04
	cmp r0, #0x11
	bne _0800AC20
	.global _0800AC04
_0800AC04:
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_0800C534
	adds r0, r5, #0x0
	adds r0, #0xA0
	ldrh r1, [r0, #0x00]
	adds r0, r5, #0x0
	adds r2, r6, #0x0
	bl sub_0800A80C
	b _0800ACCA
	.global _0800AC1C
_0800AC1C: .4byte 0x0200215C
	.global _0800AC20
_0800AC20:
	ldr r0, _0800AC38 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800AC40
	ldr r0, _0800AC3C @ =0x020005C8
	ldrh r1, [r0, #0x00]
	adds r0, r5, #0x0
	movs r2, #0x00
	bl sub_0800A80C
	b _0800AC4A
	.byte 0x00, 0x00
	.global _0800AC38
_0800AC38: .4byte 0x020021E0
	.global _0800AC3C
_0800AC3C: .4byte 0x020005C8
	.global _0800AC40
_0800AC40:
	adds r0, r5, #0x0
	movs r1, #0x02
	movs r2, #0x00
	.global _0800AC46
_0800AC46:
	bl sub_0800A80C
	.global _0800AC4A
_0800AC4A:
	adds r0, r5, #0x0
	bl sub_0800A628
	b _0800ACCA
	.global _0800AC52
_0800AC52:
	ldr r0, _0800AC8C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _0800AC98
	cmp r0, #0x0D
	beq _0800AC98
	cmp r0, #0x0E
	beq _0800AC98
	cmp r0, #0x0F
	beq _0800AC98
	cmp r0, #0x11
	beq _0800AC98
	cmp r0, #0x04
	beq _0800ACB2
	ldr r0, _0800AC90 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800ACA6
	ldr r2, _0800AC94 @ =0x00000175
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AC98
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_080093BC
	b _0800ACA0
	.byte 0x00, 0x00
	.global _0800AC8C
_0800AC8C: .4byte 0x0200215C
	.global _0800AC90
_0800AC90: .4byte 0x020021E0
	.global _0800AC94
_0800AC94: .4byte 0x00000175
	.global _0800AC98
_0800AC98:
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_0800C534
	.global _0800ACA0
_0800ACA0:
	adds r4, r5, #0x0
	adds r4, #0xA0
	b _0800ACBA
	.global _0800ACA6
_0800ACA6:
	adds r1, r5, #0x0
	adds r1, #0xA0
	movs r0, #0x02
	strh r0, [r1, #0x00]
	adds r4, r1, #0x0
	b _0800ACBA
	.global _0800ACB2
_0800ACB2:
	adds r0, r5, #0x0
	adds r0, #0xA0
	strh r1, [r0, #0x00]
	adds r4, r0, #0x0
	.global _0800ACBA
_0800ACBA:
	adds r0, r5, #0x0
	bl sub_0800A628
	ldrh r1, [r4, #0x00]
	adds r0, r5, #0x0
	adds r2, r6, #0x0
	bl sub_0800A80C
	.global _0800ACCA
_0800ACCA:
	adds r0, r5, #0x0
	adds r0, #0x88
	ldr r1, [r0, #0x00]
	ldr r0, _0800AD34 @ =0x00011940
	cmp r1, r0
	ble _0800ACF2
	adds r0, r5, #0x0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _0800ACF2
	ldr r0, _0800AD38 @ =0x0200209C
	ldr r0, [r0, #0x00]
	movs r1, #0x3F
	ands r0, r1
	cmp r0, #0x00
	bne _0800ACF2
	adds r0, r5, #0x0
	bl sub_0800B8A8
	.global _0800ACF2
_0800ACF2:
	ldr r0, _0800AD3C @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AD48
	ldr r0, _0800AD40 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r6, r0
	bne _0800AD6A
	adds r0, r6, #0x0
	bl sub_08009B20
	ldr r0, _0800AD44 @ =0x0202A550
	lsls r1, r6, #0x01
	adds r1, r1, r6
	lsls r1, r1, #0x03
	adds r1, r1, r6
	lsls r1, r1, #0x04
	adds r1, r1, r0
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AD6A
	cmp r0, #0x63
	beq _0800AD6A
	movs r0, #0xB3
	lsls r0, r0, #0x01
	adds r1, r1, r0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	b _0800AD6A
	.byte 0x00, 0x00
	.global _0800AD34
_0800AD34: .4byte 0x00011940
	.global _0800AD38
_0800AD38: .4byte 0x0200209C
	.global _0800AD3C
_0800AD3C: .4byte 0x020020DC
	.global _0800AD40
_0800AD40: .4byte 0x0202EF90
	.global _0800AD44
_0800AD44: .4byte 0x0202A550
	.global _0800AD48
_0800AD48:
	cmp r6, #0x00
	bne _0800AD6A
	movs r0, #0x00
	bl sub_08009B20
	ldr r1, _0800AD7C @ =0x0202A550
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AD6A
	cmp r0, #0x63
	beq _0800AD6A
	adds r2, #0x16
	adds r0, r1, r2
	strb r6, [r0, #0x00]
	.global _0800AD6A
_0800AD6A:
	movs r0, #0xAE
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r0, [r1, #0x00]
	adds r0, #0x01
	str r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _0800AD7C
_0800AD7C: .4byte 0x0202A550
