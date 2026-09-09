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
	thumb_func_start sub_0833AC08
sub_0833AC08:
	push {r4, r5, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	movs r3, #0x00
	str r3, [r5, #0x00]
	ldr r1, _0833ACC0 @ =0x040000C4
	ldr r0, [r1, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x12
	ands r0, r2
	cmp r0, #0x00
	beq _0833AC24
	ldr r0, _0833ACC4 @ =0x84400004
	str r0, [r1, #0x00]
	.global _0833AC24
_0833AC24:
	ldr r1, _0833ACC8 @ =0x040000D0
	ldr r0, [r1, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _0833AC32
	ldr r0, _0833ACC4 @ =0x84400004
	str r0, [r1, #0x00]
	.global _0833AC32
_0833AC32:
	ldr r0, _0833ACCC @ =0x040000C6
	movs r2, #0x80
	lsls r2, r2, #0x03
	adds r1, r2, #0x0
	strh r1, [r0, #0x00]
	adds r0, #0x0C
	strh r1, [r0, #0x00]
	ldr r1, _0833ACD0 @ =0x04000084
	movs r0, #0x8F
	strh r0, [r1, #0x00]
	subs r1, #0x02
	ldr r2, _0833ACD4 @ =0x0000A90E
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r2, _0833ACD8 @ =0x04000089
	ldrb r1, [r2, #0x00]
	movs r0, #0x3F
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2, #0x00]
	ldr r1, _0833ACDC @ =0x040000BC
	movs r2, #0xD4
	lsls r2, r2, #0x02
	adds r0, r5, r2
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _0833ACE0 @ =0x040000A0
	str r0, [r1, #0x00]
	adds r1, #0x08
	movs r2, #0x98
	lsls r2, r2, #0x04
	adds r0, r5, r2
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _0833ACE4 @ =0x040000A4
	str r0, [r1, #0x00]
	ldr r0, _0833ACE8 @ =0x03007FF0
	str r5, [r0, #0x00]
	str r3, [sp, #0x000]
	ldr r2, _0833ACEC @ =0x050003EC
	mov r0, sp
	adds r1, r5, #0x0
	bl sub_08344B64
	movs r0, #0x08
	strb r0, [r5, #0x06]
	movs r0, #0x0F
	strb r0, [r5, #0x07]
	ldr r0, _0833ACF0 @ =0x02001A7D
	str r0, [r5, #0x38]
	ldr r0, _0833ACF4 @ =0x020031F9
	str r0, [r5, #0x28]
	str r0, [r5, #0x2C]
	str r0, [r5, #0x30]
	str r0, [r5, #0x3C]
	ldr r4, _0833ACF8 @ =0x02038DE0
	adds r0, r4, #0x0
	bl sub_0833A018
	str r4, [r5, #0x34]
	movs r0, #0x80
	lsls r0, r0, #0x0B
	bl sub_0833AD00
	ldr r0, _0833ACFC @ =0x68736D53
	str r0, [r5, #0x00]
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _0833ACC0
_0833ACC0: .4byte 0x040000C4
	.global _0833ACC4
_0833ACC4: .4byte 0x84400004
	.global _0833ACC8
_0833ACC8: .4byte 0x040000D0
	.global _0833ACCC
_0833ACCC: .4byte 0x040000C6
	.global _0833ACD0
_0833ACD0: .4byte 0x04000084
	.global _0833ACD4
_0833ACD4: .4byte 0x0000A90E
	.global _0833ACD8
_0833ACD8: .4byte 0x04000089
	.global _0833ACDC
_0833ACDC: .4byte 0x040000BC
	.global _0833ACE0
_0833ACE0: .4byte 0x040000A0
	.global _0833ACE4
_0833ACE4: .4byte 0x040000A4
	.global _0833ACE8
_0833ACE8: .4byte 0x03007FF0
	.global _0833ACEC
_0833ACEC: .4byte 0x050003EC
	.global _0833ACF0
_0833ACF0: .4byte 0x02001A7D
	.global _0833ACF4
_0833ACF4: .4byte 0x020031F9
	.global _0833ACF8
_0833ACF8: .4byte 0x02038DE0
	.global _0833ACFC
_0833ACFC: .4byte 0x68736D53
	thumb_func_start sub_0833AD00
sub_0833AD00:
	push {r4, r5, r6, lr}
	adds r2, r0, #0x0
	ldr r0, _0833AD80 @ =0x03007FF0
	ldr r4, [r0, #0x00]
	movs r0, #0xF0
	lsls r0, r0, #0x0C
	ands r0, r2
	lsrs r2, r0, #0x10
	movs r6, #0x00
	strb r2, [r4, #0x08]
	ldr r1, _0833AD84 @ =0x0200C7DC
	subs r0, r2, #0x1
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r5, [r0, #0x00]
	str r5, [r4, #0x10]
	movs r0, #0xC6
	lsls r0, r0, #0x03
	adds r1, r5, #0x0
	bl sub_08344BB8
	strb r0, [r4, #0x0B]
	ldr r0, _0833AD88 @ =0x00091D1B
	muls r0, r5
	ldr r1, _0833AD8C @ =0x00001388
	adds r0, r0, r1
	ldr r1, _0833AD90 @ =0x00002710
	bl sub_08344BB8
	adds r1, r0, #0x0
	str r1, [r4, #0x14]
	movs r0, #0x80
	lsls r0, r0, #0x11
	bl sub_08344BB8
	adds r0, #0x01
	asrs r0, r0, #0x01
	str r0, [r4, #0x18]
	ldr r0, _0833AD94 @ =0x04000102
	strh r6, [r0, #0x00]
	ldr r4, _0833AD98 @ =0x04000100
	ldr r0, _0833AD9C @ =0x00044940
	adds r1, r5, #0x0
	bl sub_08344BB8
	negs r0, r0
	strh r0, [r4, #0x00]
	bl sub_0833AF0C
	ldr r1, _0833ADA0 @ =0x04000006
	.global _0833AD64
_0833AD64:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x9F
	beq _0833AD64
	ldr r1, _0833ADA0 @ =0x04000006
	.global _0833AD6C
_0833AD6C:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x9F
	bne _0833AD6C
	ldr r1, _0833AD94 @ =0x04000102
	movs r0, #0x80
	strh r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833AD80
_0833AD80: .4byte 0x03007FF0
	.global _0833AD84
_0833AD84: .4byte 0x0200C7DC
	.global _0833AD88
_0833AD88: .4byte 0x00091D1B
	.global _0833AD8C
_0833AD8C: .4byte 0x00001388
	.global _0833AD90
_0833AD90: .4byte 0x00002710
	.global _0833AD94
_0833AD94: .4byte 0x04000102
	.global _0833AD98
_0833AD98: .4byte 0x04000100
	.global _0833AD9C
_0833AD9C: .4byte 0x00044940
	.global _0833ADA0
_0833ADA0: .4byte 0x04000006
	thumb_func_start sub_0833ADA4
sub_0833ADA4:
	push {r4, r5, lr}
	adds r3, r0, #0x0
	ldr r0, _0833AE30 @ =0x03007FF0
	ldr r5, [r0, #0x00]
	ldr r1, [r5, #0x00]
	ldr r0, _0833AE34 @ =0x68736D53
	cmp r1, r0
	bne _0833AE2A
	adds r0, r1, #0x1
	str r0, [r5, #0x00]
	movs r4, #0xFF
	ands r4, r3
	cmp r4, #0x00
	beq _0833ADC6
	movs r0, #0x7F
	ands r4, r0
	strb r4, [r5, #0x05]
	.global _0833ADC6
_0833ADC6:
	movs r4, #0xF0
	lsls r4, r4, #0x04
	ands r4, r3
	cmp r4, #0x00
	beq _0833ADE6
	lsrs r0, r4, #0x08
	strb r0, [r5, #0x06]
	movs r4, #0x0C
	adds r0, r5, #0x0
	adds r0, #0x50
	movs r1, #0x00
	.global _0833ADDC
_0833ADDC:
	strb r1, [r0, #0x00]
	subs r4, #0x01
	adds r0, #0x40
	cmp r4, #0x00
	bne _0833ADDC
	.global _0833ADE6
_0833ADE6:
	movs r4, #0xF0
	lsls r4, r4, #0x08
	ands r4, r3
	cmp r4, #0x00
	beq _0833ADF4
	lsrs r0, r4, #0x0C
	strb r0, [r5, #0x07]
	.global _0833ADF4
_0833ADF4:
	movs r4, #0xB0
	lsls r4, r4, #0x10
	ands r4, r3
	cmp r4, #0x00
	beq _0833AE12
	movs r0, #0xC0
	lsls r0, r0, #0x0E
	ands r0, r4
	lsrs r4, r0, #0x0E
	ldr r2, _0833AE38 @ =0x04000089
	ldrb r1, [r2, #0x00]
	movs r0, #0x3F
	ands r0, r1
	orrs r0, r4
	strb r0, [r2, #0x00]
	.global _0833AE12
_0833AE12:
	movs r4, #0xF0
	lsls r4, r4, #0x0C
	ands r4, r3
	cmp r4, #0x00
	beq _0833AE26
	bl sub_0833AE90
	adds r0, r4, #0x0
	bl sub_0833AD00
	.global _0833AE26
_0833AE26:
	ldr r0, _0833AE34 @ =0x68736D53
	str r0, [r5, #0x00]
	.global _0833AE2A
_0833AE2A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _0833AE30
_0833AE30: .4byte 0x03007FF0
	.global _0833AE34
_0833AE34: .4byte 0x68736D53
	.global _0833AE38
_0833AE38: .4byte 0x04000089
	.byte 0xF0, 0xB5, 0x12, 0x48, 0x06, 0x68, 0x31, 0x68, 0x11, 0x48, 0x81, 0x42, 0x1B, 0xD1, 0x48, 0x1C
	.byte 0x30, 0x60, 0x0C, 0x25, 0x34, 0x1C, 0x50, 0x34, 0x00, 0x20, 0x20, 0x70, 0x01, 0x3D, 0x40, 0x34
	.byte 0x00, 0x2D, 0xFA, 0xDC, 0xF4, 0x69, 0x00, 0x2C, 0x0B, 0xD0, 0x01, 0x25, 0x00, 0x27, 0x28, 0x06
	.byte 0x00, 0x0E, 0xF1, 0x6A, 0x09, 0xF0, 0x86, 0xFE, 0x27, 0x70, 0x01, 0x35, 0x40, 0x34, 0x04, 0x2D
	.byte 0xF5, 0xDD, 0x03, 0x48, 0x30, 0x60, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xF0, 0x7F, 0x00, 0x03
	.byte 0x53, 0x6D, 0x73, 0x68
	thumb_func_start sub_0833AE90
sub_0833AE90:
	push {lr}
	add sp, #-0x004
	ldr r0, _0833AEF0 @ =0x03007FF0
	ldr r2, [r0, #0x00]
	ldr r1, [r2, #0x00]
	ldr r3, _0833AEF4 @ =0x978C92AD
	adds r0, r1, r3
	cmp r0, #0x01
	bhi _0833AEE8
	adds r0, r1, #0x0
	adds r0, #0x0A
	str r0, [r2, #0x00]
	ldr r1, _0833AEF8 @ =0x040000C4
	ldr r0, [r1, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x12
	ands r0, r3
	cmp r0, #0x00
	beq _0833AEBA
	ldr r0, _0833AEFC @ =0x84400004
	str r0, [r1, #0x00]
	.global _0833AEBA
_0833AEBA:
	ldr r1, _0833AF00 @ =0x040000D0
	ldr r0, [r1, #0x00]
	ands r0, r3
	cmp r0, #0x00
	beq _0833AEC8
	ldr r0, _0833AEFC @ =0x84400004
	str r0, [r1, #0x00]
	.global _0833AEC8
_0833AEC8:
	ldr r0, _0833AF04 @ =0x040000C6
	movs r3, #0x80
	lsls r3, r3, #0x03
	adds r1, r3, #0x0
	strh r1, [r0, #0x00]
	adds r0, #0x0C
	strh r1, [r0, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x000]
	movs r0, #0xD4
	lsls r0, r0, #0x02
	adds r1, r2, r0
	ldr r2, _0833AF08 @ =0x05000318
	mov r0, sp
	bl sub_08344B64
	.global _0833AEE8
_0833AEE8:
	add sp, #0x004
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833AEF0
_0833AEF0: .4byte 0x03007FF0
	.global _0833AEF4
_0833AEF4: .4byte 0x978C92AD
	.global _0833AEF8
_0833AEF8: .4byte 0x040000C4
	.global _0833AEFC
_0833AEFC: .4byte 0x84400004
	.global _0833AF00
_0833AF00: .4byte 0x040000D0
	.global _0833AF04
_0833AF04: .4byte 0x040000C6
	.global _0833AF08
_0833AF08: .4byte 0x05000318
