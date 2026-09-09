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
	thumb_func_start sub_0833F968
sub_0833F968:
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	movs r3, #0x00
	cmp r3, r5
	beq _0833F99A
	ldr r0, _0833F9A0 @ =0x0000FFFF
	mov r12, r0
	movs r4, #0x00
	ldr r6, _0833F9A4 @ =0x06010000
	.global _0833F97A
_0833F97A:
	mov r7, r12
	str r7, [r2, #0x08]
	str r4, [r2, #0x00]
	strb r4, [r2, #0x04]
	ldrh r0, [r1, #0x00]
	str r0, [r2, #0x10]
	ldrh r7, [r1, #0x00]
	lsls r0, r7, #0x05
	adds r0, r0, r6
	str r0, [r2, #0x0C]
	strb r4, [r2, #0x06]
	adds r3, #0x01
	adds r2, #0x14
	adds r1, #0x02
	cmp r3, r5
	bne _0833F97A
	.global _0833F99A
_0833F99A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0833F9A0
_0833F9A0: .4byte 0x0000FFFF
	.global _0833F9A4
_0833F9A4: .4byte 0x06010000
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
	thumb_func_start sub_0833FBB0
sub_0833FBB0:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _0833FBC8 @ =0x0203B870
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r3, #0x01
	.global _0833FBBC
_0833FBBC:
	ldr r0, [r1, #0x08]
	cmp r0, r4
	bne _0833FBCC
	str r3, [r1, #0x00]
	adds r0, r1, #0x0
	b _0833FBF4
	.global _0833FBC8
_0833FBC8: .4byte 0x0203B870
	.global _0833FBCC
_0833FBCC:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x18
	bne _0833FBBC
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	.global _0833FBDA
_0833FBDA:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FBEA
	str r3, [r1, #0x00]
	strb r3, [r1, #0x04]
	str r4, [r1, #0x08]
	adds r0, r1, #0x0
	b _0833FBF4
	.global _0833FBEA
_0833FBEA:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x18
	bne _0833FBDA
	movs r0, #0x00
	.global _0833FBF4
_0833FBF4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0833FBFC
sub_0833FBFC:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _0833FC14 @ =0x0203BA50
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r3, #0x01
	.global _0833FC08
_0833FC08:
	ldr r0, [r1, #0x08]
	cmp r0, r4
	bne _0833FC18
	str r3, [r1, #0x00]
	adds r0, r1, #0x0
	b _0833FC40
	.global _0833FC14
_0833FC14: .4byte 0x0203BA50
	.global _0833FC18
_0833FC18:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _0833FC08
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	.global _0833FC26
_0833FC26:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FC36
	str r3, [r1, #0x00]
	strb r3, [r1, #0x04]
	str r4, [r1, #0x08]
	adds r0, r1, #0x0
	b _0833FC40
	.global _0833FC36
_0833FC36:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _0833FC26
	movs r0, #0x00
	.global _0833FC40
_0833FC40:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0833FC48
sub_0833FC48:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _0833FC60 @ =0x0203BF50
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r3, #0x01
	.global _0833FC54
_0833FC54:
	ldr r0, [r1, #0x08]
	cmp r0, r4
	bne _0833FC64
	str r3, [r1, #0x00]
	adds r0, r1, #0x0
	b _0833FC8C
	.global _0833FC60
_0833FC60: .4byte 0x0203BF50
	.global _0833FC64
_0833FC64:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x14
	bne _0833FC54
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	.global _0833FC72
_0833FC72:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FC82
	str r3, [r1, #0x00]
	strb r3, [r1, #0x04]
	str r4, [r1, #0x08]
	adds r0, r1, #0x0
	b _0833FC8C
	.global _0833FC82
_0833FC82:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x14
	bne _0833FC72
	movs r0, #0x00
	.global _0833FC8C
_0833FC8C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0833FC94
sub_0833FC94:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _0833FCAC @ =0x0203C0E0
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r3, #0x01
	.global _0833FCA0
_0833FCA0:
	ldr r0, [r1, #0x08]
	cmp r0, r4
	bne _0833FCB0
	str r3, [r1, #0x00]
	adds r0, r1, #0x0
	b _0833FCD8
	.global _0833FCAC
_0833FCAC: .4byte 0x0203C0E0
	.global _0833FCB0
_0833FCB0:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x10
	bne _0833FCA0
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	.global _0833FCBE
_0833FCBE:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FCCE
	str r3, [r1, #0x00]
	strb r3, [r1, #0x04]
	str r4, [r1, #0x08]
	adds r0, r1, #0x0
	b _0833FCD8
	.global _0833FCCE
_0833FCCE:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x10
	bne _0833FCBE
	movs r0, #0x00
	.global _0833FCD8
_0833FCD8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0833FCE0
sub_0833FCE0:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _0833FCF8 @ =0x0203BCD0
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r3, #0x01
	.global _0833FCEC
_0833FCEC:
	ldr r0, [r1, #0x08]
	cmp r0, r4
	bne _0833FCFC
	str r3, [r1, #0x00]
	adds r0, r1, #0x0
	b _0833FD24
	.global _0833FCF8
_0833FCF8: .4byte 0x0203BCD0
	.global _0833FCFC
_0833FCFC:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _0833FCEC
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	.global _0833FD0A
_0833FD0A:
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FD1A
	str r3, [r1, #0x00]
	strb r3, [r1, #0x04]
	str r4, [r1, #0x08]
	adds r0, r1, #0x0
	b _0833FD24
	.global _0833FD1A
_0833FD1A:
	adds r2, #0x01
	adds r1, #0x14
	cmp r2, #0x20
	bne _0833FD0A
	movs r0, #0x00
	.global _0833FD24
_0833FD24:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x30, 0xB5, 0x03, 0x1C, 0x04, 0x49, 0x00, 0x22, 0x0D, 0x1C, 0x01, 0x24, 0x88, 0x68
	.byte 0x98, 0x42, 0x04, 0xD1, 0x0C, 0x60, 0x08, 0x1C, 0x16, 0xE0, 0xD0, 0xBC, 0x03, 0x02, 0x01, 0x32
	.byte 0x14, 0x31, 0x20, 0x2A, 0xF3, 0xD1, 0x29, 0x1C, 0x00, 0x22, 0x01, 0x24, 0x03, 0x25, 0x08, 0x68
	.byte 0x00, 0x28, 0x04, 0xD1, 0x0C, 0x60, 0x0D, 0x71, 0x8B, 0x60, 0x08, 0x1C, 0x04, 0xE0, 0x01, 0x32
	.byte 0x14, 0x31, 0x20, 0x2A, 0xF3, 0xD1, 0x00, 0x20, 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47
	thumb_func_start sub_0833FD78
sub_0833FD78:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _0833FD90 @ =0x0203C270
	movs r2, #0x00
	adds r5, r1, #0x0
	movs r3, #0x01
	.global _0833FD84
_0833FD84:
	ldr r0, [r1, #0x04]
	cmp r0, r4
	bne _0833FD94
	strb r3, [r1, #0x00]
	strb r3, [r1, #0x01]
	b _0833FDAE
	.global _0833FD90
_0833FD90: .4byte 0x0203C270
	.global _0833FD94
_0833FD94:
	adds r2, #0x01
	adds r1, #0x0C
	cmp r2, #0x10
	bne _0833FD84
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	.global _0833FDA2
_0833FDA2:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833FDB4
	strb r3, [r1, #0x00]
	strb r3, [r1, #0x01]
	str r4, [r1, #0x04]
	.global _0833FDAE
_0833FDAE:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	b _0833FDBE
	.global _0833FDB4
_0833FDB4:
	adds r2, #0x01
	adds r1, #0x0C
	cmp r2, #0x10
	bne _0833FDA2
	movs r0, #0x00
	.global _0833FDBE
_0833FDBE:
	pop {r4, r5}
	pop {r1}
	bx r1
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
