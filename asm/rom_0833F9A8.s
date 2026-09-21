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
	thumb_func_start sub_0833F9A8
sub_0833F9A8:
	push {r4, r5, r6, lr}
	ldr r1, _0833FA04 @ =0x020269C4
	ldr r2, _0833FA08 @ =0x0203C220
	movs r0, #0x04
	bl sub_0833F968
	ldr r1, _0833FA0C @ =0x020269CC
	ldr r2, _0833FA10 @ =0x0203B870
	movs r0, #0x18
	bl sub_0833F968
	ldr r1, _0833FA14 @ =0x020269FC
	ldr r2, _0833FA18 @ =0x0203BA50
	movs r0, #0x20
	bl sub_0833F968
	ldr r1, _0833FA1C @ =0x02026A3C
	ldr r2, _0833FA20 @ =0x0203BF50
	movs r0, #0x14
	bl sub_0833F968
	ldr r1, _0833FA24 @ =0x02026A64
	ldr r2, _0833FA28 @ =0x0203C0E0
	movs r0, #0x10
	bl sub_0833F968
	ldr r1, _0833FA2C @ =0x02026A84
	ldr r2, _0833FA30 @ =0x0203BCD0
	movs r0, #0x20
	bl sub_0833F968
	movs r6, #0x00
	ldr r5, _0833FA34 @ =0x05000200
	ldr r4, _0833FA38 @ =0x0203C270
	.global _0833F9EC
_0833F9EC:
	adds r0, r4, #0x0
	bl sub_0833F958
	str r5, [r4, #0x08]
	adds r5, #0x20
	adds r4, #0x0C
	adds r6, #0x01
	cmp r6, #0x10
	bne _0833F9EC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _0833FA04
_0833FA04: .4byte 0x020269C4
	.global _0833FA08
_0833FA08: .4byte 0x0203C220
	.global _0833FA0C
_0833FA0C: .4byte 0x020269CC
	.global _0833FA10
_0833FA10: .4byte 0x0203B870
	.global _0833FA14
_0833FA14: .4byte 0x020269FC
	.global _0833FA18
_0833FA18: .4byte 0x0203BA50
	.global _0833FA1C
_0833FA1C: .4byte 0x02026A3C
	.global _0833FA20
_0833FA20: .4byte 0x0203BF50
	.global _0833FA24
_0833FA24: .4byte 0x02026A64
	.global _0833FA28
_0833FA28: .4byte 0x0203C0E0
	.global _0833FA2C
_0833FA2C: .4byte 0x02026A84
	.global _0833FA30
_0833FA30: .4byte 0x0203BCD0
	.global _0833FA34
_0833FA34: .4byte 0x05000200
	.global _0833FA38
_0833FA38: .4byte 0x0203C270
	thumb_func_start sub_0833FA3C
sub_0833FA3C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _0833FA64 @ =0x0203C220
	movs r2, #0x00
	ldr r4, _0833FA68 @ =0x0203B870
	ldr r5, _0833FA6C @ =0x0203BA50
	ldr r6, _0833FA70 @ =0x0203BF50
	ldr r7, _0833FA74 @ =0x0203C0E0
	ldr r0, _0833FA78 @ =0x0203BCD0
	mov r12, r0
	ldr r0, _0833FA7C @ =0x0203C270
	mov r8, r0
	ldr r3, _0833FA80 @ =0x0000FFFF
	.global _0833FA58
_0833FA58:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FA84
	str r3, [r1, #0x08]
	b _0833FA88
	.byte 0x00, 0x00
	.global _0833FA64
_0833FA64: .4byte 0x0203C220
	.global _0833FA68
_0833FA68: .4byte 0x0203B870
	.global _0833FA6C
_0833FA6C: .4byte 0x0203BA50
	.global _0833FA70
_0833FA70: .4byte 0x0203BF50
	.global _0833FA74
_0833FA74: .4byte 0x0203C0E0
	.global _0833FA78
_0833FA78: .4byte 0x0203BCD0
	.global _0833FA7C
_0833FA7C: .4byte 0x0203C270
	.global _0833FA80
_0833FA80: .4byte 0x0000FFFF
	.global _0833FA84
_0833FA84:
	subs r0, #0x01
	str r0, [r1, #0x00]
	.global _0833FA88
_0833FA88:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x04
	bne _0833FA58
	adds r1, r4, #0x0
	movs r2, #0x00
	ldr r3, _0833FAA0 @ =0x0000FFFF
	.global _0833FA96
_0833FA96:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FAA4
	str r3, [r1, #0x08]
	b _0833FAA8
	.global _0833FAA0
_0833FAA0: .4byte 0x0000FFFF
	.global _0833FAA4
_0833FAA4:
	subs r0, #0x01
	str r0, [r1, #0x00]
	.global _0833FAA8
_0833FAA8:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x18
	bne _0833FA96
	adds r1, r5, #0x0
	movs r2, #0x00
	ldr r3, _0833FAC0 @ =0x0000FFFF
	.global _0833FAB6
_0833FAB6:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FAC4
	str r3, [r1, #0x08]
	b _0833FAC8
	.global _0833FAC0
_0833FAC0: .4byte 0x0000FFFF
	.global _0833FAC4
_0833FAC4:
	subs r0, #0x01
	str r0, [r1, #0x00]
	.global _0833FAC8
_0833FAC8:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _0833FAB6
	adds r1, r6, #0x0
	movs r2, #0x00
	ldr r3, _0833FAE0 @ =0x0000FFFF
	.global _0833FAD6
_0833FAD6:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FAE4
	str r3, [r1, #0x08]
	b _0833FAE8
	.global _0833FAE0
_0833FAE0: .4byte 0x0000FFFF
	.global _0833FAE4
_0833FAE4:
	subs r0, #0x01
	str r0, [r1, #0x00]
	.global _0833FAE8
_0833FAE8:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x14
	bne _0833FAD6
	adds r1, r7, #0x0
	movs r2, #0x00
	ldr r3, _0833FB00 @ =0x0000FFFF
	.global _0833FAF6
_0833FAF6:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FB04
	str r3, [r1, #0x08]
	b _0833FB08
	.global _0833FB00
_0833FB00: .4byte 0x0000FFFF
	.global _0833FB04
_0833FB04:
	subs r0, #0x01
	str r0, [r1, #0x00]
	.global _0833FB08
_0833FB08:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x10
	bne _0833FAF6
	mov r1, r12
	movs r2, #0x00
	ldr r3, _0833FB20 @ =0x0000FFFF
	.global _0833FB16
_0833FB16:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FB24
	str r3, [r1, #0x08]
	b _0833FB28
	.global _0833FB20
_0833FB20: .4byte 0x0000FFFF
	.global _0833FB24
_0833FB24:
	subs r0, #0x01
	str r0, [r1, #0x00]
	.global _0833FB28
_0833FB28:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _0833FB16
	mov r1, r8
	movs r2, #0x00
	ldr r3, _0833FB40 @ =0x0000FFFF
	.global _0833FB36
_0833FB36:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FB44
	str r3, [r1, #0x04]
	b _0833FB48
	.global _0833FB40
_0833FB40: .4byte 0x0000FFFF
	.global _0833FB44
_0833FB44:
	subs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0833FB48
_0833FB48:
	adds r2, #0x01
	adds r1, #0x0C
	cmp r2, #0x10
	bne _0833FB36
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x70, 0xB5, 0x05, 0x1C, 0x09, 0x06, 0x0C, 0x0E, 0x05, 0x4A, 0x00, 0x23, 0x16, 0x1C
	.byte 0x01, 0x21, 0x90, 0x68, 0xA8, 0x42, 0x06, 0xD1, 0x11, 0x60, 0x54, 0x71, 0x10, 0x1C, 0x17, 0xE0
	.byte 0x00, 0x00, 0x20, 0xC2, 0x03, 0x02, 0x01, 0x33, 0x14, 0x32, 0x04, 0x2B, 0xF1, 0xD1, 0x32, 0x1C
	.byte 0x00, 0x23, 0x01, 0x21, 0x10, 0x68, 0x00, 0x28, 0x05, 0xD1, 0x11, 0x60, 0x54, 0x71, 0x11, 0x71
	.byte 0x95, 0x60, 0x10, 0x1C, 0x04, 0xE0, 0x01, 0x33, 0x14, 0x32, 0x04, 0x2B, 0xF2, 0xD1, 0x00, 0x20
	.byte 0x70, 0xBC, 0x02, 0xBC, 0x08, 0x47
