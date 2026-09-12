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
	.byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x07, 0x1C, 0xB8, 0x68
	.byte 0x81, 0x46, 0x4A, 0x46, 0x12, 0x05, 0x91, 0x46, 0x12, 0x15, 0x90, 0x46, 0xBA, 0x60, 0x1B, 0x48
	.byte 0x02, 0x68, 0x10, 0x1C, 0xD1, 0x17, 0x3C, 0x68, 0xA2, 0x46, 0x52, 0x46, 0xD3, 0x17, 0x7E, 0x68
	.byte 0x34, 0x1C, 0xF5, 0x17, 0x12, 0x1B, 0xAB, 0x41, 0x0A, 0xF0, 0xE9, 0xFC, 0x0A, 0xF0, 0x1F, 0xFD
	.byte 0x0D, 0x1C, 0x04, 0x1C, 0x29, 0x06, 0x20, 0x0A, 0x0C, 0x1C, 0x04, 0x43, 0x11, 0x48, 0x02, 0x68
	.byte 0x10, 0x1C, 0xD1, 0x17, 0x42, 0x46, 0x4E, 0x46, 0xF3, 0x17, 0x0A, 0xF0, 0xD8, 0xFC, 0x0A, 0xF0
	.byte 0x0E, 0xFD, 0x0B, 0x06, 0x02, 0x0A, 0x18, 0x1C, 0x10, 0x43, 0x24, 0x18, 0x64, 0x10, 0xA0, 0x44
	.byte 0x40, 0x46, 0x00, 0x05, 0x00, 0x15, 0x80, 0x46, 0xB8, 0x60, 0xC2, 0x44, 0x52, 0x46, 0x3A, 0x60
	.byte 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xB8, 0xA0
	.byte 0x3C, 0x08, 0xB4, 0xA0, 0x3C, 0x08, 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4
	.byte 0x07, 0x1C, 0xB8, 0x68, 0x81, 0x46, 0x4A, 0x46, 0x12, 0x05, 0x91, 0x46, 0x12, 0x15, 0x90, 0x46
	.byte 0xBA, 0x60, 0x1B, 0x48, 0x02, 0x68, 0x10, 0x1C, 0xD1, 0x17, 0x3C, 0x68, 0xA2, 0x46, 0x52, 0x46
	.byte 0xD3, 0x17, 0x7E, 0x68, 0x34, 0x1C, 0xF5, 0x17, 0x12, 0x1B, 0xAB, 0x41, 0x0A, 0xF0, 0x9F, 0xFC
	.byte 0x0A, 0xF0, 0xD5, 0xFC, 0x0D, 0x1C, 0x04, 0x1C, 0x29, 0x06, 0x20, 0x0A, 0x0C, 0x1C, 0x04, 0x43
	.byte 0x11, 0x48, 0x02, 0x68, 0x10, 0x1C, 0xD1, 0x17, 0x42, 0x46, 0x4E, 0x46, 0xF3, 0x17, 0x0A, 0xF0
	.byte 0x8E, 0xFC, 0x0A, 0xF0, 0xC4, 0xFC, 0x0B, 0x06, 0x02, 0x0A, 0x18, 0x1C, 0x10, 0x43, 0x24, 0x18
	.byte 0x64, 0x10, 0xA0, 0x44, 0x40, 0x46, 0x00, 0x05, 0x00, 0x15, 0x80, 0x46, 0xB8, 0x60, 0xC2, 0x44
	.byte 0x52, 0x46, 0x3A, 0x60, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0xC0, 0xA0, 0x3C, 0x08, 0xBC, 0xA0, 0x3C, 0x08
	thumb_func_start sub_0800CAB4
sub_0800CAB4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	cmp r7, #0x01
	bls _0800CB0C
	movs r5, #0x00
	lsrs r4, r7, #0x01
	cmp r4, #0x00
	beq _0800CAD0
	.global _0800CAC8
_0800CAC8:
	adds r5, #0x01
	lsrs r4, r4, #0x01
	cmp r4, #0x00
	bne _0800CAC8
	.global _0800CAD0
_0800CAD0:
	lsrs r5, r5, #0x01
	movs r4, #0x01
	lsls r4, r5
	adds r6, r4, #0x0
	lsls r6, r5
	subs r5, #0x01
	movs r0, #0x01
	negs r0, r0
	cmp r5, r0
	beq _0800CB0A
	movs r1, #0x01
	mov r8, r1
	mov r12, r0
	.global _0800CAEA
_0800CAEA:
	mov r3, r8
	lsls r3, r5
	adds r0, r3, #0x0
	lsls r0, r5
	adds r2, r5, #0x1
	adds r1, r4, #0x0
	lsls r1, r2
	adds r1, r6, r1
	adds r1, r1, r0
	cmp r1, r7
	bhi _0800CB04
	adds r4, r4, r3
	adds r6, r1, #0x0
	.global _0800CB04
_0800CB04:
	subs r5, #0x01
	cmp r5, r12
	bne _0800CAEA
	.global _0800CB0A
_0800CB0A:
	adds r0, r4, #0x0
	.global _0800CB0C
_0800CB0C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0800CB18
sub_0800CB18:
	adds r2, r0, #0x0
	.global _0800CB1A
_0800CB1A:
	adds r0, r2, #0x0
	adds r0, #0x7F
	cmp r0, #0xFE
	bhi _0800CB2E
	movs r0, #0x7F
	negs r0, r0
	cmp r1, r0
	blt _0800CB2E
	cmp r1, #0x7F
	ble _0800CB3C
	.global _0800CB2E
_0800CB2E:
	lsrs r0, r2, #0x1F
	adds r0, r2, r0
	asrs r2, r0, #0x01
	lsrs r0, r1, #0x1F
	adds r0, r1, r0
	asrs r1, r0, #0x01
	b _0800CB1A
	.global _0800CB3C
_0800CB3C:
	cmp r1, r0
	blt _0800CB44
	cmp r1, #0x7F
	ble _0800CB48
	.global _0800CB44
_0800CB44:
	movs r0, #0x00
	b _0800CB56
	.global _0800CB48
_0800CB48:
	ldr r0, _0800CB58 @ =0x0806C97C
	adds r1, #0x80
	lsls r1, r1, #0x08
	adds r1, #0x80
	adds r1, r2, r1
	adds r1, r1, r0
	ldrb r0, [r1, #0x00]
	.global _0800CB56
_0800CB56:
	bx lr
	.global _0800CB58
_0800CB58: .4byte 0x0806C97C
	.byte 0x00, 0xB5, 0x02, 0x1C, 0x42, 0x43, 0x08, 0x1C, 0x48, 0x43, 0x10, 0x18, 0xFF, 0xF7, 0xA4, 0xFF
	.byte 0x02, 0xBC, 0x08, 0x47
	thumb_func_start sub_0800CB70
sub_0800CB70:
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r3, r1, #0x0
	ldr r6, _0800CBA4 @ =0x0200209C
	movs r0, #0x9C
	lsls r0, r0, #0x01
	adds r5, r4, r0
	ldr r1, [r6, #0x00]
	ldr r0, [r5, #0x00]
	cmp r1, r0
	beq _0800CBA8
	adds r0, r3, #0x0
	adds r1, r2, #0x0
	bl sub_0800CBB8
	movs r2, #0x9A
	lsls r2, r2, #0x01
	adds r1, r4, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1, #0x00]
	ldr r0, [r6, #0x00]
	str r0, [r5, #0x00]
	ldrb r0, [r1, #0x00]
	b _0800CBB0
	.byte 0x00, 0x00
	.global _0800CBA4
_0800CBA4: .4byte 0x0200209C
	.global _0800CBA8
_0800CBA8:
	movs r1, #0x9A
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	.global _0800CBB0
_0800CBB0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0800CBB8
sub_0800CBB8:
	push {r4, r5, lr}
	subs r0, #0x01
	asrs r4, r0, #0x02
	subs r1, #0x01
	asrs r5, r1, #0x02
	movs r2, #0x03
	adds r3, r2, #0x0
	ands r3, r0
	ands r2, r1
	ldr r0, _0800CBF4 @ =0x02002200
	ldr r0, [r0, #0x00]
	muls r0, r5
	ldr r1, _0800CBF8 @ =0x0200BC50
	ldr r1, [r1, #0x00]
	lsls r4, r4, #0x01
	lsls r0, r0, #0x01
	adds r0, r0, r1
	adds r4, r4, r0
	lsls r2, r2, #0x02
	adds r3, r3, r2
	ldr r0, _0800CBFC @ =0x02022DEC
	ldr r1, [r0, #0x00]
	ldrh r4, [r4, #0x00]
	lsls r0, r4, #0x04
	adds r0, r0, r1
	adds r0, r0, r3
	ldrb r0, [r0, #0x00]
	pop {r4, r5}
	pop {r1}
	bx r1
	.global _0800CBF4
_0800CBF4: .4byte 0x02002200
	.global _0800CBF8
_0800CBF8: .4byte 0x0200BC50
	.global _0800CBFC
_0800CBFC: .4byte 0x02022DEC
	.byte 0x00, 0xB5, 0x03, 0x1C, 0x0C, 0x48, 0x00, 0x78, 0x03, 0x28, 0x1B, 0xD0, 0x0B, 0x48, 0x09, 0x18
	.byte 0x0B, 0x48, 0x12, 0x18, 0x18, 0x1C, 0xFF, 0xF7, 0xAB, 0xFF, 0x01, 0x1C, 0x09, 0x06, 0xFF, 0x20
	.byte 0x00, 0x06, 0x09, 0x18, 0xC0, 0x20, 0x80, 0x04, 0x08, 0x40, 0x00, 0x0E, 0x01, 0x21, 0x08, 0x40
	.byte 0x02, 0x21, 0x08, 0x43, 0x80, 0x02, 0x07, 0xE0, 0xCC, 0x20, 0x00, 0x02, 0x00, 0x00, 0xC0, 0xFF
	.byte 0x00, 0x00, 0xC8, 0xFF, 0xC0, 0x20, 0x00, 0x01, 0x02, 0xBC, 0x08, 0x47, 0x00, 0xB5, 0x02, 0x1C
	.byte 0x0C, 0x48, 0x00, 0x78, 0x03, 0x28, 0x1B, 0xD0, 0x0B, 0x4B, 0xD0, 0x18, 0x0B, 0x4A, 0x89, 0x18
	.byte 0xFF, 0xF7, 0xAA, 0xFF, 0x01, 0x1C, 0x09, 0x06, 0xFF, 0x23, 0x1B, 0x06, 0xC9, 0x18, 0xC0, 0x20
	.byte 0x80, 0x04, 0x08, 0x40, 0x00, 0x0E, 0x01, 0x21, 0x08, 0x40, 0x02, 0x21, 0x08, 0x43, 0x80, 0x02
	.byte 0x08, 0xE0, 0x00, 0x00, 0xCC, 0x20, 0x00, 0x02, 0x00, 0x00, 0xC0, 0xFF, 0x00, 0x00, 0xA0, 0xFF
	.byte 0xC0, 0x20, 0x00, 0x01, 0x02, 0xBC, 0x08, 0x47
	thumb_func_start sub_0800CC98
sub_0800CC98:
	asrs r3, r0, #0x07
	asrs r1, r1, #0x07
	cmp r3, #0x30
	bgt _0800CCAC
	cmp r1, #0x30
	bgt _0800CCAC
	cmp r3, #0x00
	blt _0800CCAC
	cmp r1, #0x00
	bge _0800CCBC
	.global _0800CCAC
_0800CCAC:
	ldr r2, _0800CCB4 @ =0x0202CC6C
	ldr r0, _0800CCB8 @ =0x0202CC68
	ldr r0, [r0, #0x00]
	b _0800CCCE
	.global _0800CCB4
_0800CCB4: .4byte 0x0202CC6C
	.global _0800CCB8
_0800CCB8: .4byte 0x0202CC68
	.global _0800CCBC
_0800CCBC:
	ldr r2, _0800CCD8 @ =0x0202CC6C
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r0, r0, r3
	ldr r1, _0800CCDC @ =0x0202CC68
	ldr r1, [r1, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	.global _0800CCCE
_0800CCCE:
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	bx lr
	.global _0800CCD8
_0800CCD8: .4byte 0x0202CC6C
	.global _0800CCDC
_0800CCDC: .4byte 0x0202CC68
	thumb_func_start sub_0800CCE0
sub_0800CCE0:
	ldr r3, _0800CD20 @ =0x0202CC40
	ldr r2, _0800CD24 @ =0x083FD91C
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x02
	adds r0, r2, #0x4
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x00]
	ldr r3, _0800CD28 @ =0x0202CC44
	adds r0, r1, r2
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x00]
	ldr r3, _0800CD2C @ =0x0202CC48
	adds r0, r2, #0x0
	adds r0, #0x08
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x00]
	ldr r3, _0800CD30 @ =0x0202CC6C
	adds r0, r2, #0x0
	adds r0, #0x0C
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x00]
	ldr r3, _0800CD34 @ =0x0202CC68
	adds r2, #0x10
	adds r1, r1, r2
	ldr r0, [r1, #0x00]
	str r0, [r3, #0x00]
	bx lr
	.byte 0x00, 0x00
	.global _0800CD20
_0800CD20: .4byte 0x0202CC40
	.global _0800CD24
_0800CD24: .4byte 0x083FD91C
	.global _0800CD28
_0800CD28: .4byte 0x0202CC44
	.global _0800CD2C
_0800CD2C: .4byte 0x0202CC48
	.global _0800CD30
_0800CD30: .4byte 0x0202CC6C
	.global _0800CD34
_0800CD34: .4byte 0x0202CC68
	thumb_func_start sub_0800CD38
sub_0800CD38:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x048
	str r0, [sp, #0x010]
	str r1, [sp, #0x014]
	str r2, [sp, #0x018]
	str r3, [sp, #0x01C]
	ldr r0, [sp, #0x068]
	str r0, [sp, #0x03C]
	ldr r0, _0800CF44 @ =0x0000FFFF
	ldr r1, [sp, #0x03C]
	ldrh r1, [r1, #0x00]
	cmp r1, r0
	bne _0800CD5C
	b _0800CF34
	.global _0800CD5C
_0800CD5C:
	ldr r0, _0800CF48 @ =0x0202CC40
	ldr r2, [sp, #0x03C]
	ldrh r2, [r2, #0x00]
	lsls r1, r2, #0x05
	ldr r0, [r0, #0x00]
	adds r0, r0, r1
	mov r8, r0
	ldr r3, [sp, #0x014]
	ldr r1, [r3, #0x00]
	ldr r0, [r0, #0x10]
	ldr r4, [sp, #0x03C]
	adds r4, #0x02
	str r4, [sp, #0x040]
	cmp r1, r0
	ble _0800CD7C
	b _0800CF26
	.global _0800CD7C
_0800CD7C:
	ldr r1, [r3, #0x08]
	mov r6, r8
	ldr r0, [r6, #0x18]
	cmp r1, r0
	ble _0800CD88
	b _0800CF26
	.global _0800CD88
_0800CD88:
	ldr r1, [r3, #0x04]
	ldr r0, [r6, #0x0C]
	cmp r1, r0
	bge _0800CD92
	b _0800CF26
	.global _0800CD92
_0800CD92:
	ldr r1, [r3, #0x0C]
	ldr r0, [r6, #0x14]
	cmp r1, r0
	bge _0800CD9C
	b _0800CF26
	.global _0800CD9C
_0800CD9C:
	ldr r0, _0800CF4C @ =0x0202CC44
	ldr r1, [r0, #0x00]
	ldrh r2, [r6, #0x00]
	lsls r0, r2, #0x03
	adds r0, r0, r1
	ldr r3, [r0, #0x00]
	str r3, [sp, #0x020]
	ldr r0, [r0, #0x04]
	str r0, [sp, #0x024]
	ldrh r4, [r6, #0x02]
	lsls r0, r4, #0x03
	adds r0, r0, r1
	ldr r6, [r0, #0x00]
	str r6, [sp, #0x028]
	ldr r0, [r0, #0x04]
	str r0, [sp, #0x02C]
	ldr r0, [sp, #0x010]
	str r0, [sp, #0x030]
	ldr r1, [sp, #0x018]
	str r1, [sp, #0x034]
	movs r2, #0x00
	str r2, [sp, #0x038]
	.global _0800CDC8
_0800CDC8:
	mov r3, r8
	ldr r0, [r3, #0x10]
	adds r0, #0x01
	ldr r4, [sp, #0x034]
	ldr r1, [r4, #0x00]
	cmp r1, r0
	ble _0800CDD8
	b _0800CF0E
	.global _0800CDD8
_0800CDD8:
	ldr r0, [r3, #0x18]
	adds r0, #0x01
	ldr r1, [r4, #0x08]
	cmp r1, r0
	ble _0800CDE4
	b _0800CF0E
	.global _0800CDE4
_0800CDE4:
	ldr r0, [r3, #0x0C]
	subs r0, #0x01
	ldr r1, [r4, #0x04]
	cmp r1, r0
	bge _0800CDF0
	b _0800CF0E
	.global _0800CDF0
_0800CDF0:
	ldr r0, [r3, #0x14]
	subs r0, #0x01
	ldr r1, [r4, #0x0C]
	cmp r1, r0
	bge _0800CDFC
	b _0800CF0E
	.global _0800CDFC
_0800CDFC:
	ldr r6, [sp, #0x030]
	ldr r0, [r6, #0x10]
	asrs r0, r0, #0x08
	ldr r1, [r3, #0x04]
	adds r2, r0, #0x0
	muls r2, r1
	ldr r0, [r6, #0x14]
	asrs r0, r0, #0x08
	ldr r1, [r3, #0x08]
	muls r0, r1
	adds r2, r2, r0
	cmp r2, #0x00
	bgt _0800CF0E
	ldr r0, _0800CF50 @ =0x02000470
	ldr r1, [sp, #0x020]
	str r1, [r0, #0x00]
	ldr r0, _0800CF54 @ =0x02000474
	ldr r2, [sp, #0x024]
	str r2, [r0, #0x00]
	ldr r0, _0800CF58 @ =0x02000478
	ldr r3, [sp, #0x028]
	str r3, [r0, #0x00]
	ldr r0, _0800CF5C @ =0x0200047C
	ldr r4, [sp, #0x02C]
	str r4, [r0, #0x00]
	ldr r0, _0800CF60 @ =0x02000460
	movs r1, #0x02
	ldsh r6, [r6, r1]
	mov r12, r6
	str r6, [r0, #0x00]
	ldr r0, _0800CF64 @ =0x02000464
	ldr r2, [sp, #0x030]
	movs r3, #0x06
	ldsh r5, [r2, r3]
	str r5, [r0, #0x00]
	ldr r0, _0800CF68 @ =0x02000468
	movs r4, #0x0A
	ldsh r1, [r2, r4]
	str r1, [r0, #0x00]
	ldr r0, _0800CF6C @ =0x0200046C
	movs r6, #0x0E
	ldsh r2, [r2, r6]
	str r2, [r0, #0x00]
	ldr r3, _0800CF70 @ =0x02000480
	mov r0, r12
	subs r0, r1, r0
	mov r10, r0
	ldr r1, [sp, #0x02C]
	ldr r6, [sp, #0x024]
	subs r4, r1, r6
	mov r1, r10
	muls r1, r4
	subs r2, r2, r5
	mov r9, r2
	ldr r0, [sp, #0x028]
	ldr r6, [sp, #0x020]
	subs r2, r0, r6
	mov r0, r9
	muls r0, r2
	subs r6, r1, r0
	str r6, [r3, #0x00]
	cmp r6, #0x00
	beq _0800CF0E
	ldr r0, [sp, #0x024]
	subs r7, r5, r0
	adds r0, r7, #0x0
	muls r0, r2
	mov r1, r12
	ldr r2, [sp, #0x020]
	subs r5, r1, r2
	adds r1, r5, #0x0
	muls r1, r4
	subs r0, r0, r1
	lsls r0, r0, #0x08
	ldr r3, _0800CF74 @ =0x02000488
	str r0, [r3, #0x00]
	adds r1, r6, #0x0
	bl sub_08017230
	adds r4, r0, #0x0
	ldr r0, _0800CF74 @ =0x02000488
	str r4, [r0, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x01
	cmp r4, r2
	bhi _0800CF0E
	mov r0, r10
	muls r0, r7
	mov r1, r9
	muls r1, r5
	subs r0, r0, r1
	lsls r0, r0, #0x08
	ldr r1, _0800CF78 @ =0x02000484
	str r0, [r1, #0x00]
	adds r1, r6, #0x0
	str r2, [sp, #0x044]
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r3, _0800CF78 @ =0x02000484
	str r1, [r3, #0x00]
	ldr r2, [sp, #0x044]
	cmp r1, r2
	bhi _0800CF0E
	ldr r6, [sp, #0x06C]
	ldr r0, [r6, #0x00]
	cmp r4, r0
	bge _0800CF0E
	str r1, [r6, #0x00]
	mov r0, r8
	ldr r1, [r0, #0x04]
	lsls r0, r1, #0x06
	adds r0, r0, r1
	lsls r0, r0, #0x02
	asrs r0, r0, #0x08
	ldr r1, [sp, #0x01C]
	str r0, [r1, #0x04]
	mov r2, r8
	ldr r1, [r2, #0x08]
	lsls r0, r1, #0x06
	adds r0, r0, r1
	lsls r0, r0, #0x02
	asrs r0, r0, #0x08
	ldr r3, [sp, #0x01C]
	str r0, [r3, #0x08]
	ldrb r0, [r2, #0x1C]
	strb r0, [r3, #0x0D]
	ldrb r0, [r2, #0x1D]
	strb r0, [r3, #0x0E]
	ldrb r0, [r2, #0x1E]
	strb r0, [r3, #0x0F]
	ldr r4, [sp, #0x03C]
	ldrh r0, [r4, #0x00]
	str r0, [r3, #0x10]
	add r6, sp, #0x038
	ldrb r6, [r6, #0x00]
	strb r6, [r3, #0x0C]
	.global _0800CF0E
_0800CF0E:
	ldr r0, [sp, #0x038]
	adds r0, #0x01
	str r0, [sp, #0x038]
	ldr r1, [sp, #0x030]
	adds r1, #0x18
	str r1, [sp, #0x030]
	ldr r2, [sp, #0x034]
	adds r2, #0x10
	str r2, [sp, #0x034]
	cmp r0, #0x04
	beq _0800CF26
	b _0800CDC8
	.global _0800CF26
_0800CF26:
	ldr r3, [sp, #0x040]
	str r3, [sp, #0x03C]
	ldr r0, _0800CF44 @ =0x0000FFFF
	ldrh r4, [r3, #0x00]
	cmp r4, r0
	beq _0800CF34
	b _0800CD5C
	.global _0800CF34
_0800CF34:
	add sp, #0x048
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _0800CF44
_0800CF44: .4byte 0x0000FFFF
	.global _0800CF48
_0800CF48: .4byte 0x0202CC40
	.global _0800CF4C
_0800CF4C: .4byte 0x0202CC44
	.global _0800CF50
_0800CF50: .4byte 0x02000470
	.global _0800CF54
_0800CF54: .4byte 0x02000474
	.global _0800CF58
_0800CF58: .4byte 0x02000478
	.global _0800CF5C
_0800CF5C: .4byte 0x0200047C
	.global _0800CF60
_0800CF60: .4byte 0x02000460
	.global _0800CF64
_0800CF64: .4byte 0x02000464
	.global _0800CF68
_0800CF68: .4byte 0x02000468
	.global _0800CF6C
_0800CF6C: .4byte 0x0200046C
	.global _0800CF70
_0800CF70: .4byte 0x02000480
	.global _0800CF74
_0800CF74: .4byte 0x02000488
	.global _0800CF78
_0800CF78: .4byte 0x02000484
	thumb_func_start sub_0800CF7C
sub_0800CF7C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x030
	str r0, [sp, #0x010]
	str r3, [sp, #0x014]
	str r2, [sp, #0x020]
	ldr r0, [sp, #0x050]
	str r0, [sp, #0x024]
	ldr r0, _0800D0C4 @ =0x0000FFFF
	ldr r1, [sp, #0x024]
	ldrh r1, [r1, #0x00]
	cmp r1, r0
	bne _0800CF9E
	b _0800D10C
	.global _0800CF9E
_0800CF9E:
	ldr r0, _0800D0C8 @ =0x0202CC40
	ldr r2, [sp, #0x024]
	ldrh r2, [r2, #0x00]
	lsls r1, r2, #0x05
	ldr r0, [r0, #0x00]
	adds r0, r0, r1
	mov r8, r0
	ldr r0, _0800D0CC @ =0x0202CC44
	ldr r1, [r0, #0x00]
	mov r3, r8
	ldrh r3, [r3, #0x00]
	lsls r0, r3, #0x03
	adds r0, r0, r1
	ldr r5, [r0, #0x00]
	str r5, [sp, #0x018]
	ldr r0, [r0, #0x04]
	mov r12, r0
	mov r2, r8
	ldrh r2, [r2, #0x02]
	lsls r0, r2, #0x03
	adds r0, r0, r1
	ldr r3, [r0, #0x00]
	str r3, [sp, #0x01C]
	ldr r5, [r0, #0x04]
	ldr r1, [sp, #0x010]
	ldr r0, [r1, #0x10]
	mov r2, r8
	ldr r2, [r2, #0x04]
	str r2, [sp, #0x028]
	adds r1, r0, #0x0
	muls r1, r2
	ldr r3, [sp, #0x010]
	ldr r2, [r3, #0x14]
	mov r3, r8
	ldr r0, [r3, #0x08]
	muls r0, r2
	adds r1, r1, r0
	cmp r1, #0x00
	ble _0800CFEE
	b _0800D0FC
	.global _0800CFEE
_0800CFEE:
	ldr r0, [sp, #0x020]
	ldr r1, [r0, #0x00]
	ldr r0, [r3, #0x10]
	cmp r1, r0
	ble _0800CFFA
	b _0800D0FC
	.global _0800CFFA
_0800CFFA:
	ldr r2, [sp, #0x020]
	ldr r1, [r2, #0x08]
	ldr r0, [r3, #0x18]
	cmp r1, r0
	bgt _0800D0FC
	ldr r1, [r2, #0x04]
	ldr r0, [r3, #0x0C]
	cmp r1, r0
	blt _0800D0FC
	ldr r1, [r2, #0x0C]
	ldr r0, [r3, #0x14]
	cmp r1, r0
	blt _0800D0FC
	ldr r0, _0800D0D0 @ =0x02000470
	ldr r3, [sp, #0x018]
	str r3, [r0, #0x00]
	ldr r0, _0800D0D4 @ =0x02000474
	mov r1, r12
	str r1, [r0, #0x00]
	ldr r0, _0800D0D8 @ =0x02000478
	ldr r2, [sp, #0x01C]
	str r2, [r0, #0x00]
	ldr r0, _0800D0DC @ =0x0200047C
	str r5, [r0, #0x00]
	ldr r0, _0800D0E0 @ =0x02000460
	ldr r3, [sp, #0x010]
	ldr r6, [r3, #0x00]
	str r6, [r0, #0x00]
	ldr r0, _0800D0E4 @ =0x02000464
	ldr r4, [r3, #0x04]
	str r4, [r0, #0x00]
	ldr r0, _0800D0E8 @ =0x02000468
	ldr r1, [r3, #0x08]
	str r1, [r0, #0x00]
	ldr r0, _0800D0EC @ =0x0200046C
	ldr r2, [r3, #0x0C]
	str r2, [r0, #0x00]
	ldr r3, _0800D0F0 @ =0x02000480
	subs r1, r1, r6
	mov r10, r1
	mov r0, r12
	subs r7, r5, r0
	mov r1, r10
	muls r1, r7
	subs r2, r2, r4
	mov r9, r2
	ldr r5, [sp, #0x01C]
	ldr r0, [sp, #0x018]
	subs r2, r5, r0
	mov r0, r9
	muls r0, r2
	subs r5, r1, r0
	str r5, [r3, #0x00]
	cmp r5, #0x00
	beq _0800D0FC
	mov r1, r12
	subs r3, r4, r1
	adds r0, r3, #0x0
	muls r0, r2
	ldr r2, [sp, #0x018]
	subs r4, r6, r2
	adds r1, r4, #0x0
	muls r1, r7
	subs r0, r0, r1
	lsls r0, r0, #0x08
	ldr r1, _0800D0F4 @ =0x02000488
	str r0, [r1, #0x00]
	adds r1, r5, #0x0
	str r3, [sp, #0x02C]
	bl sub_08017230
	ldr r2, _0800D0F4 @ =0x02000488
	str r0, [r2, #0x00]
	movs r6, #0x80
	lsls r6, r6, #0x01
	ldr r3, [sp, #0x02C]
	cmp r0, r6
	bhi _0800D0FC
	mov r0, r10
	muls r0, r3
	mov r1, r9
	muls r1, r4
	subs r0, r0, r1
	lsls r0, r0, #0x08
	ldr r3, _0800D0F8 @ =0x02000484
	str r0, [r3, #0x00]
	adds r1, r5, #0x0
	bl sub_08017230
	ldr r5, _0800D0F8 @ =0x02000484
	str r0, [r5, #0x00]
	cmp r0, r6
	bhi _0800D0FC
	ldr r0, [sp, #0x028]
	ldr r1, [sp, #0x014]
	str r0, [r1, #0x04]
	mov r2, r8
	ldr r0, [r2, #0x08]
	str r0, [r1, #0x08]
	movs r0, #0x01
	b _0800D10E
	.global _0800D0C4
_0800D0C4: .4byte 0x0000FFFF
	.global _0800D0C8
_0800D0C8: .4byte 0x0202CC40
	.global _0800D0CC
_0800D0CC: .4byte 0x0202CC44
	.global _0800D0D0
_0800D0D0: .4byte 0x02000470
	.global _0800D0D4
_0800D0D4: .4byte 0x02000474
	.global _0800D0D8
_0800D0D8: .4byte 0x02000478
	.global _0800D0DC
_0800D0DC: .4byte 0x0200047C
	.global _0800D0E0
_0800D0E0: .4byte 0x02000460
	.global _0800D0E4
_0800D0E4: .4byte 0x02000464
	.global _0800D0E8
_0800D0E8: .4byte 0x02000468
	.global _0800D0EC
_0800D0EC: .4byte 0x0200046C
	.global _0800D0F0
_0800D0F0: .4byte 0x02000480
	.global _0800D0F4
_0800D0F4: .4byte 0x02000488
	.global _0800D0F8
_0800D0F8: .4byte 0x02000484
	.global _0800D0FC
_0800D0FC:
	ldr r3, [sp, #0x024]
	adds r3, #0x02
	str r3, [sp, #0x024]
	ldr r0, _0800D120 @ =0x0000FFFF
	ldrh r5, [r3, #0x00]
	cmp r5, r0
	beq _0800D10C
	b _0800CF9E
	.global _0800D10C
_0800D10C:
	movs r0, #0x00
	.global _0800D10E
_0800D10E:
	add sp, #0x030
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _0800D120
_0800D120: .4byte 0x0000FFFF
	thumb_func_start sub_0800D124
sub_0800D124:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x048
	adds r7, r0, #0x0
	ldr r0, _0800D1A8 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x07
	beq _0800D1A2
	ldr r1, [r7, #0x00]
	asrs r4, r1, #0x10
	str r4, [sp, #0x004]
	ldr r2, [r7, #0x08]
	asrs r6, r2, #0x10
	str r6, [sp, #0x008]
	ldr r3, [r7, #0x28]
	adds r1, r1, r3
	asrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	ldr r0, [r7, #0x30]
	adds r2, r2, r0
	asrs r2, r2, #0x10
	str r2, [sp, #0x010]
	asrs r3, r3, #0x08
	str r3, [sp, #0x014]
	asrs r0, r0, #0x08
	str r0, [sp, #0x018]
	cmp r4, r1
	bge _0800D160
	adds r1, r4, #0x0
	.global _0800D160
_0800D160:
	add r5, sp, #0x01C
	str r1, [sp, #0x01C]
	cmp r6, r2
	bge _0800D16A
	adds r2, r6, #0x0
	.global _0800D16A
_0800D16A:
	str r2, [r5, #0x08]
	ldr r1, [sp, #0x004]
	ldr r0, [sp, #0x00C]
	cmp r1, r0
	ble _0800D176
	adds r0, r1, #0x0
	.global _0800D176
_0800D176:
	str r0, [r5, #0x04]
	ldr r1, [sp, #0x008]
	ldr r0, [sp, #0x010]
	cmp r1, r0
	ble _0800D182
	adds r0, r1, #0x0
	.global _0800D182
_0800D182:
	str r0, [r5, #0x0C]
	ldr r0, [sp, #0x004]
	ldr r1, [sp, #0x008]
	bl sub_0800CC98
	add r4, sp, #0x02C
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r5, #0x0
	adds r2, r5, #0x0
	adds r3, r4, #0x0
	bl sub_0800CF7C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0800D1AC
	.global _0800D1A2
_0800D1A2:
	movs r0, #0x00
	b _0800D23A
	.byte 0x00, 0x00
	.global _0800D1A8
_0800D1A8: .4byte 0x0200215C
	.global _0800D1AC
_0800D1AC:
	ldr r0, [sp, #0x014]
	ldr r2, [r4, #0x04]
	adds r1, r0, #0x0
	muls r1, r2
	mov r8, r1
	ldr r0, [sp, #0x018]
	ldr r6, [r4, #0x08]
	muls r0, r6
	add r8, r0
	adds r0, r2, #0x0
	asrs r1, r2, #0x1F
	mov r4, r8
	asrs r5, r4, #0x1F
	adds r3, r5, #0x0
	adds r2, r4, #0x0
	bl sub_08017398
	lsls r3, r1, #0x0B
	lsrs r2, r0, #0x15
	orrs r3, r2
	str r3, [sp, #0x040]
	asrs r0, r1, #0x15
	str r0, [sp, #0x044]
	adds r0, r6, #0x0
	asrs r1, r6, #0x1F
	adds r3, r5, #0x0
	adds r2, r4, #0x0
	bl sub_08017398
	lsls r3, r1, #0x0B
	lsrs r2, r0, #0x15
	adds r4, r3, #0x0
	orrs r4, r2
	asrs r5, r1, #0x15
	ldr r2, [sp, #0x040]
	lsrs r3, r2, #0x1F
	ldr r0, [sp, #0x044]
	lsls r2, r0, #0x01
	adds r1, r3, #0x0
	orrs r1, r2
	ldr r2, [sp, #0x040]
	lsls r0, r2, #0x01
	ldr r2, [sp, #0x040]
	ldr r3, [sp, #0x044]
	adds r0, r0, r2
	adcs r1, r3
	lsls r3, r1, #0x1E
	lsrs r2, r0, #0x02
	orrs r3, r2
	str r3, [sp, #0x040]
	asrs r0, r1, #0x02
	str r0, [sp, #0x044]
	lsrs r3, r4, #0x1F
	lsls r2, r5, #0x01
	adds r1, r3, #0x0
	orrs r1, r2
	lsls r0, r4, #0x01
	adds r0, r0, r4
	adcs r1, r5
	lsls r3, r1, #0x1E
	lsrs r2, r0, #0x02
	adds r4, r3, #0x0
	orrs r4, r2
	ldr r0, [r7, #0x28]
	ldr r3, [sp, #0x040]
	subs r0, r0, r3
	str r0, [r7, #0x28]
	ldr r0, [r7, #0x30]
	subs r0, r0, r4
	str r0, [r7, #0x30]
	mov r0, r8
	.global _0800D23A
_0800D23A:
	add sp, #0x048
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0800D248
sub_0800D248:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x118
	mov r10, r0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0800D260
	b _0800D5A8
	.global _0800D260
_0800D260:
	movs r0, #0x00
	mov r12, r0
	mov r1, r10
	adds r1, #0xA4
	str r1, [sp, #0x114]
	mov r2, sp
	adds r2, #0x0C
	str r2, [sp, #0x0D8]
	mov r3, r10
	adds r3, #0xB4
	str r3, [sp, #0x0E4]
	mov r6, sp
	adds r6, #0x10
	str r6, [sp, #0x0DC]
	mov r7, r10
	adds r7, #0xC4
	str r7, [sp, #0x0F4]
	mov r0, sp
	adds r0, #0x14
	str r0, [sp, #0x0E0]
	adds r1, #0x30
	str r1, [sp, #0x0F8]
	adds r2, #0x0C
	str r2, [sp, #0x0E8]
	mov r3, sp
	adds r3, #0x1C
	str r3, [sp, #0x0F0]
	adds r6, #0x58
	str r6, [sp, #0x0FC]
	mov r7, sp
	adds r7, #0x70
	str r7, [sp, #0x104]
	adds r0, #0x58
	str r0, [sp, #0x100]
	mov r1, sp
	adds r1, #0x74
	str r1, [sp, #0x108]
	adds r2, #0x90
	str r2, [sp, #0x10C]
	adds r3, #0xB0
	str r3, [sp, #0x0EC]
	adds r6, #0x50
	str r6, [sp, #0x110]
	add r7, sp, #0x008
	mov r8, r7
	movs r0, #0x00
	mov r9, r0
	.global _0800D2BE
_0800D2BE:
	mov r2, r12
	lsls r1, r2, #0x02
	ldr r3, [sp, #0x114]
	adds r0, r3, r1
	ldr r4, [r0, #0x00]
	mov r6, r8
	str r4, [r6, #0x00]
	ldr r7, [sp, #0x0D8]
	add r7, r9
	ldr r2, [sp, #0x0E4]
	adds r0, r2, r1
	ldr r3, [r0, #0x00]
	str r3, [r7, #0x00]
	ldr r5, [sp, #0x0DC]
	add r5, r9
	ldr r6, [sp, #0x0F4]
	adds r0, r6, r1
	ldr r2, [r0, #0x00]
	str r2, [r5, #0x00]
	ldr r6, [sp, #0x0E0]
	add r6, r9
	ldr r0, [sp, #0x0F8]
	adds r1, r0, r1
	ldr r0, [r1, #0x00]
	str r0, [r6, #0x00]
	ldr r1, [sp, #0x0E8]
	add r1, r9
	subs r2, r2, r4
	str r2, [r1, #0x00]
	ldr r1, [sp, #0x0F0]
	add r1, r9
	subs r0, r0, r3
	str r0, [r1, #0x00]
	mov r2, r8
	ldr r1, [r2, #0x00]
	ldr r0, [r5, #0x00]
	cmp r1, r0
	bge _0800D30C
	adds r0, r1, #0x0
	.global _0800D30C
_0800D30C:
	mov r3, r12
	lsls r2, r3, #0x04
	ldr r3, [sp, #0x0FC]
	adds r1, r3, r2
	asrs r0, r0, #0x10
	str r0, [r1, #0x00]
	ldr r1, [r7, #0x00]
	ldr r0, [r6, #0x00]
	cmp r1, r0
	bge _0800D322
	adds r0, r1, #0x0
	.global _0800D322
_0800D322:
	ldr r3, [sp, #0x104]
	adds r1, r3, r2
	asrs r0, r0, #0x10
	str r0, [r1, #0x00]
	mov r0, r8
	ldr r1, [r0, #0x00]
	ldr r0, [r5, #0x00]
	cmp r1, r0
	ble _0800D336
	adds r0, r1, #0x0
	.global _0800D336
_0800D336:
	ldr r3, [sp, #0x100]
	adds r1, r3, r2
	asrs r0, r0, #0x10
	str r0, [r1, #0x00]
	ldr r1, [r7, #0x00]
	ldr r0, [r6, #0x00]
	cmp r1, r0
	ble _0800D348
	adds r0, r1, #0x0
	.global _0800D348
_0800D348:
	ldr r6, [sp, #0x108]
	adds r1, r6, r2
	asrs r0, r0, #0x10
	str r0, [r1, #0x00]
	movs r7, #0x18
	add r8, r7
	movs r0, #0x18
	add r9, r0
	movs r1, #0x01
	add r12, r1
	mov r2, r12
	cmp r2, #0x04
	bne _0800D2BE
	ldr r6, [sp, #0x0FC]
	ldr r1, [sp, #0x068]
	ldr r0, [r6, #0x10]
	cmp r1, r0
	bge _0800D36E
	adds r0, r1, #0x0
	.global _0800D36E
_0800D36E:
	ldr r7, [sp, #0x10C]
	str r0, [r7, #0x00]
	ldr r1, [r6, #0x20]
	cmp r0, r1
	bge _0800D37A
	adds r1, r0, #0x0
	.global _0800D37A
_0800D37A:
	str r1, [r7, #0x00]
	ldr r0, [r6, #0x30]
	cmp r1, r0
	bge _0800D384
	adds r0, r1, #0x0
	.global _0800D384
_0800D384:
	str r0, [r7, #0x00]
	ldr r1, [r6, #0x08]
	ldr r0, [r6, #0x18]
	cmp r1, r0
	bge _0800D390
	adds r0, r1, #0x0
	.global _0800D390
_0800D390:
	str r0, [r7, #0x08]
	ldr r1, [r6, #0x28]
	cmp r0, r1
	bge _0800D39A
	adds r1, r0, #0x0
	.global _0800D39A
_0800D39A:
	str r1, [r7, #0x08]
	ldr r0, [r6, #0x38]
	cmp r1, r0
	bge _0800D3A4
	adds r0, r1, #0x0
	.global _0800D3A4
_0800D3A4:
	str r0, [r7, #0x08]
	ldr r1, [r6, #0x04]
	ldr r0, [r6, #0x14]
	cmp r1, r0
	ble _0800D3B0
	adds r0, r1, #0x0
	.global _0800D3B0
_0800D3B0:
	str r0, [r7, #0x04]
	ldr r1, [r6, #0x24]
	cmp r0, r1
	ble _0800D3BA
	adds r1, r0, #0x0
	.global _0800D3BA
_0800D3BA:
	str r1, [r7, #0x04]
	ldr r0, [r6, #0x34]
	cmp r1, r0
	ble _0800D3C4
	adds r0, r1, #0x0
	.global _0800D3C4
_0800D3C4:
	str r0, [r7, #0x04]
	ldr r1, [r6, #0x0C]
	ldr r0, [r6, #0x1C]
	cmp r1, r0
	ble _0800D3D0
	adds r0, r1, #0x0
	.global _0800D3D0
_0800D3D0:
	str r0, [r7, #0x0C]
	ldr r1, [r6, #0x2C]
	cmp r0, r1
	ble _0800D3DA
	adds r1, r0, #0x0
	.global _0800D3DA
_0800D3DA:
	str r1, [r7, #0x0C]
	ldr r0, [r6, #0x3C]
	cmp r1, r0
	ble _0800D3E4
	adds r0, r1, #0x0
	.global _0800D3E4
_0800D3E4:
	str r0, [r7, #0x0C]
	ldr r0, [sp, #0x008]
	asrs r0, r0, #0x10
	ldr r1, [sp, #0x00C]
	asrs r1, r1, #0x10
	bl sub_0800CC98
	ldr r5, _0800D588 @ =0x0001869F
	ldr r3, [sp, #0x0EC]
	str r5, [r3, #0x00]
	str r0, [sp, #0x000]
	add r4, sp, #0x0CC
	str r4, [sp, #0x004]
	add r0, sp, #0x008
	adds r1, r7, #0x0
	adds r2, r6, #0x0
	ldr r3, [sp, #0x110]
	bl sub_0800CD38
	ldr r0, [r4, #0x00]
	cmp r0, r5
	bne _0800D412
	b _0800D5A8
	.global _0800D412
_0800D412:
	ldr r6, [sp, #0x110]
	ldrb r6, [r6, #0x0C]
	lsls r4, r6, #0x01
	ldr r7, [sp, #0x110]
	ldrb r7, [r7, #0x0C]
	adds r4, r4, r7
	lsls r4, r4, #0x03
	ldr r1, [sp, #0x0E8]
	adds r0, r1, r4
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	asrs r1, r2, #0x1F
	ldr r2, [sp, #0x110]
	ldr r5, [r2, #0x04]
	adds r2, r5, #0x0
	asrs r3, r5, #0x1F
	bl sub_08017398
	str r0, [sp, #0x0D0]
	str r1, [sp, #0x0D4]
	ldr r3, [sp, #0x0F0]
	adds r4, r3, r4
	ldr r2, [r4, #0x00]
	adds r0, r2, #0x0
	asrs r1, r2, #0x1F
	ldr r6, [sp, #0x110]
	ldr r4, [r6, #0x08]
	adds r2, r4, #0x0
	asrs r3, r4, #0x1F
	bl sub_08017398
	ldr r2, [sp, #0x0D0]
	ldr r3, [sp, #0x0D4]
	adds r2, r2, r0
	adcs r3, r1
	str r2, [sp, #0x0D0]
	str r3, [sp, #0x0D4]
	lsrs r3, r2, #0x1F
	ldr r6, [sp, #0x0D4]
	lsls r2, r6, #0x01
	adds r1, r3, #0x0
	orrs r1, r2
	ldr r7, [sp, #0x0D0]
	lsls r0, r7, #0x01
	ldr r2, [sp, #0x0D0]
	ldr r3, [sp, #0x0D4]
	adds r0, r0, r2
	adcs r1, r3
	lsrs r5, r0, #0x1A
	lsls r4, r1, #0x06
	adds r3, r5, #0x0
	orrs r3, r4
	lsls r2, r0, #0x06
	lsls r1, r3, #0x18
	lsrs r0, r2, #0x08
	orrs r1, r0
	str r1, [sp, #0x0D0]
	asrs r2, r3, #0x08
	str r2, [sp, #0x0D4]
	movs r0, #0x01
	negs r0, r0
	cmp r2, r0
	bgt _0800D49E
	cmp r2, r0
	bne _0800D4A6
	movs r0, #0x80
	lsls r0, r0, #0x18
	adds r3, r1, #0x0
	cmp r3, r0
	bls _0800D4A6
	.global _0800D49E
_0800D49E:
	ldr r6, _0800D58C @ =0x80000000
	ldr r7, _0800D590 @ =0xFFFFFFFF
	str r6, [sp, #0x0D0]
	str r7, [sp, #0x0D4]
	.global _0800D4A6
_0800D4A6:
	ldr r7, [sp, #0x110]
	ldr r7, [r7, #0x04]
	mov r9, r7
	mov r0, r9
	asrs r1, r0, #0x1F
	ldr r2, [sp, #0x0D0]
	ldr r3, [sp, #0x0D4]
	bl sub_08017398
	adds r5, r1, #0x0
	adds r4, r0, #0x0
	lsls r1, r5, #0x03
	lsrs r0, r4, #0x1D
	adds r4, r1, #0x0
	orrs r4, r0
	ldr r0, [sp, #0x110]
	ldr r0, [r0, #0x08]
	mov r8, r0
	asrs r1, r0, #0x1F
	ldr r2, [sp, #0x0D0]
	ldr r3, [sp, #0x0D4]
	bl sub_08017398
	lsls r3, r1, #0x03
	lsrs r2, r0, #0x1D
	adds r0, r3, #0x0
	orrs r0, r2
	ldr r2, _0800D594 @ =0x0202CC70
	mov r3, r10
	ldr r6, [r3, #0x0C]
	str r6, [r2, #0x00]
	ldr r2, _0800D598 @ =0x0202CC64
	ldr r3, [r3, #0x14]
	str r3, [r2, #0x00]
	ldr r2, _0800D59C @ =0x0202CC4C
	ldr r7, [sp, #0x0D0]
	str r7, [r2, #0x00]
	ldr r2, _0800D5A0 @ =0x0202CC50
	mov r7, r9
	str r7, [r2, #0x04]
	mov r7, r8
	str r7, [r2, #0x08]
	subs r6, r6, r4
	mov r2, r10
	str r6, [r2, #0x0C]
	subs r3, r3, r0
	str r3, [r2, #0x14]
	ldr r3, [sp, #0x110]
	ldrb r3, [r3, #0x0C]
	lsls r1, r3, #0x02
	ldr r6, [sp, #0x114]
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	ldr r7, [sp, #0x0E4]
	adds r1, r7, r1
	ldr r1, [r1, #0x00]
	bl sub_0800B614
	ldr r2, _0800D5A4 @ =0x0801CD08
	ldr r0, [sp, #0x110]
	ldrb r3, [r0, #0x0D]
	lsls r0, r3, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r5, [r0, r1]
	adds r0, r3, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r6, #0x00
	ldsh r4, [r0, r6]
	mov r7, r10
	ldrh r7, [r7, #0x34]
	lsrs r1, r7, #0x08
	lsls r0, r1, #0x01
	adds r0, r0, r2
	movs r6, #0x00
	ldsh r0, [r0, r6]
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r2
	movs r7, #0x00
	ldsh r1, [r1, r7]
	muls r0, r5
	muls r1, r4
	adds r0, r0, r1
	cmp r0, #0x00
	bgt _0800D55A
	ldr r0, [sp, #0x110]
	ldrb r3, [r0, #0x0E]
	.global _0800D55A
_0800D55A:
	movs r1, #0x96
	lsls r1, r1, #0x01
	add r1, r10
	lsls r0, r3, #0x08
	str r0, [r1, #0x00]
	mov r1, r10
	ldrh r1, [r1, #0x34]
	subs r0, r0, r1
	lsls r3, r0, #0x10
	asrs r3, r3, #0x14
	mov r2, r10
	ldrh r2, [r2, #0x3C]
	adds r0, r2, r3
	mov r3, r10
	strh r0, [r3, #0x3C]
	ldr r6, [sp, #0x0D4]
	lsls r3, r6, #0x19
	ldr r7, [sp, #0x0D0]
	lsrs r2, r7, #0x07
	adds r0, r3, #0x0
	orrs r0, r2
	b _0800D5AA
	.byte 0x00, 0x00
	.global _0800D588
_0800D588: .4byte 0x0001869F
	.global _0800D58C
_0800D58C: .4byte 0x80000000
	.global _0800D590
_0800D590: .4byte 0xFFFFFFFF
	.global _0800D594
_0800D594: .4byte 0x0202CC70
	.global _0800D598
_0800D598: .4byte 0x0202CC64
	.global _0800D59C
_0800D59C: .4byte 0x0202CC4C
	.global _0800D5A0
_0800D5A0: .4byte 0x0202CC50
	.global _0800D5A4
_0800D5A4: .4byte 0x0801CD08
	.global _0800D5A8
_0800D5A8:
	movs r0, #0x00
	.global _0800D5AA
_0800D5AA:
	add sp, #0x118
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x02, 0x1C, 0x08, 0x1C, 0x82, 0x42, 0x00, 0xDA, 0x10, 0x1C, 0x70, 0x47, 0x02, 0x1C
	.byte 0x08, 0x1C, 0x82, 0x42, 0x00, 0xDD, 0x10, 0x1C, 0x70, 0x47
	thumb_func_start sub_0800D5D4
sub_0800D5D4:
	push {r4, r5, r6, r7, lr}
	ldrh r3, [r0, #0x34]
	lsrs r2, r3, #0x08
	negs r7, r2
	movs r5, #0xFF
	mov r12, r5
	ands r7, r5
	ldr r5, _0800D648 @ =0x0801CD08
	lsls r2, r7, #0x01
	adds r2, r2, r5
	movs r6, #0x00
	ldsh r2, [r2, r6]
	str r2, [r1, #0x00]
	adds r2, r7, #0x0
	adds r2, #0x40
	lsls r2, r2, #0x01
	adds r2, r2, r5
	movs r3, #0x00
	ldsh r2, [r2, r3]
	str r2, [r1, #0x04]
	ldr r3, [r0, #0x00]
	asrs r2, r3, #0x08
	str r2, [r1, #0x10]
	ldr r4, [r0, #0x08]
	asrs r2, r4, #0x08
	str r2, [r1, #0x14]
	movs r6, #0x3C
	ldsh r2, [r0, r6]
	ldrh r6, [r0, #0x34]
	adds r7, r6, r2
	asrs r2, r7, #0x08
	negs r7, r2
	mov r2, r12
	ands r7, r2
	lsls r2, r7, #0x01
	adds r2, r2, r5
	movs r6, #0x00
	ldsh r2, [r2, r6]
	str r2, [r1, #0x08]
	adds r2, r7, #0x0
	adds r2, #0x40
	lsls r2, r2, #0x01
	adds r2, r2, r5
	movs r5, #0x00
	ldsh r2, [r2, r5]
	str r2, [r1, #0x0C]
	ldr r2, [r0, #0x0C]
	adds r3, r3, r2
	asrs r3, r3, #0x08
	str r3, [r1, #0x18]
	ldr r0, [r0, #0x14]
	adds r4, r4, r0
	asrs r4, r4, #0x08
	str r4, [r1, #0x1C]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800D648
_0800D648: .4byte 0x0801CD08
	thumb_func_start sub_0800D64C
sub_0800D64C:
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	adds r4, r2, #0x0
	ldr r2, [sp, #0x014]
	ldr r7, [sp, #0x020]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r5, _0800D680 @ =0x0202CD24
	ldr r0, [r5, #0x00]
	cmp r7, r0
	bge _0800D67A
	str r6, [r2, #0x00]
	str r4, [r2, #0x04]
	strb r1, [r2, #0x08]
	strb r3, [r2, #0x09]
	ldr r0, [sp, #0x01C]
	str r0, [r2, #0x0C]
	movs r1, #0x01
	ldr r0, [sp, #0x018]
	strb r1, [r0, #0x00]
	str r7, [r5, #0x00]
	.global _0800D67A
_0800D67A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800D680
_0800D680: .4byte 0x0202CD24
	thumb_func_start sub_0800D684
sub_0800D684:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x044
	str r0, [sp, #0x024]
	ldr r0, _0800D9F8 @ =0x02002090
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x040]
	ldr r0, _0800D9FC @ =0x020020DC
	ldrb r1, [r0, #0x00]
	cmp r1, #0x00
	beq _0800D6A6
	ldr r0, _0800DA00 @ =0x020020AC
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x040]
	.global _0800D6A6
_0800D6A6:
	ldr r0, [sp, #0x024]
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800D6B6
	cmp r1, #0x00
	beq _0800D6B6
	b _0800DE48
	.global _0800D6B6
_0800D6B6:
	ldr r1, [sp, #0x024]
	ldr r2, _0800DA04 @ =0x00000175
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	ldr r2, _0800DA08 @ =0x0202A550
	cmp r0, #0x00
	beq _0800D6D8
	cmp r1, r2
	bne _0800D6CA
	b _0800DE48
	.global _0800D6CA
_0800D6CA:
	ldr r3, [sp, #0x024]
	ldr r1, _0800DA0C @ =0x0000018F
	adds r0, r3, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800D6D8
	b _0800DE48
	.global _0800D6D8
_0800D6D8:
	ldr r1, _0800DA10 @ =0x0202CD24
	movs r0, #0x80
	lsls r0, r0, #0x0E
	str r0, [r1, #0x00]
	add r4, sp, #0x020
	movs r0, #0x00
	strb r0, [r4, #0x00]
	mov r10, r2
	ldr r7, _0800DA14 @ =0x0202CCB0
	ldr r0, [sp, #0x024]
	adds r1, r7, #0x0
	bl sub_0800D5D4
	movs r2, #0x00
	str r2, [sp, #0x02C]
	ldr r3, [sp, #0x040]
	cmp r2, r3
	bne _0800D6FE
	b _0800DB38
	.global _0800D6FE
_0800D6FE:
	ldr r0, [sp, #0x024]
	cmp r10, r0
	bne _0800D706
	b _0800DB1E
	.global _0800D706
_0800D706:
	ldr r0, _0800DA04 @ =0x00000175
	add r0, r10
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800D724
	ldr r0, _0800DA08 @ =0x0202A550
	cmp r10, r0
	bne _0800D718
	b _0800DB1E
	.global _0800D718
_0800D718:
	ldr r0, _0800DA0C @ =0x0000018F
	add r0, r10
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800D724
	b _0800DB1E
	.global _0800D724
_0800D724:
	mov r0, r10
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800D738
	ldr r0, _0800D9FC @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800D738
	b _0800DB1E
	.global _0800D738
_0800D738:
	ldr r1, [sp, #0x024]
	ldr r2, [r1, #0x00]
	mov r3, r10
	ldr r0, [r3, #0x00]
	subs r2, r2, r0
	ldr r0, [r1, #0x08]
	ldr r1, [r3, #0x08]
	subs r0, r0, r1
	asrs r0, r0, #0x08
	asrs r2, r2, #0x08
	cmp r2, #0x00
	bge _0800D752
	negs r2, r2
	.global _0800D752
_0800D752:
	movs r1, #0xC8
	lsls r1, r1, #0x07
	cmp r2, r1
	ble _0800D75C
	b _0800DB1E
	.global _0800D75C
_0800D75C:
	cmp r0, #0x00
	bge _0800D762
	negs r0, r0
	.global _0800D762
_0800D762:
	cmp r0, r1
	ble _0800D768
	b _0800DB1E
	.global _0800D768
_0800D768:
	mov r0, r10
	ldr r1, _0800DA18 @ =0x0202CD30
	bl sub_0800D5D4
	ldr r0, _0800DA14 @ =0x0202CCB0
	ldr r5, [r0, #0x10]
	ldr r6, [r0, #0x14]
	ldr r1, _0800DA18 @ =0x0202CD30
	ldr r0, [r1, #0x10]
	subs r5, r5, r0
	ldr r0, [r1, #0x14]
	subs r6, r6, r0
	ldr r3, [r1, #0x04]
	adds r1, r3, #0x0
	muls r1, r5
	ldr r0, _0800DA18 @ =0x0202CD30
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	muls r0, r6
	subs r1, r1, r0
	asrs r1, r1, #0x08
	mov r9, r1
	str r1, [sp, #0x010]
	adds r0, r2, #0x0
	muls r0, r5
	adds r1, r3, #0x0
	muls r1, r6
	adds r0, r0, r1
	asrs r4, r0, #0x08
	str r4, [sp, #0x014]
	ldr r1, _0800DA14 @ =0x0202CCB0
	ldr r5, [r1, #0x18]
	ldr r6, [r1, #0x1C]
	ldr r2, _0800DA18 @ =0x0202CD30
	ldr r0, [r2, #0x18]
	subs r5, r5, r0
	ldr r0, [r2, #0x1C]
	subs r6, r6, r0
	ldr r3, [r2, #0x0C]
	adds r2, r3, #0x0
	muls r2, r5
	ldr r0, _0800DA18 @ =0x0202CD30
	ldr r1, [r0, #0x08]
	adds r0, r1, #0x0
	muls r0, r6
	subs r2, r2, r0
	asrs r2, r2, #0x08
	str r2, [sp, #0x018]
	adds r0, r1, #0x0
	muls r0, r5
	adds r1, r3, #0x0
	muls r1, r6
	adds r0, r0, r1
	asrs r1, r0, #0x08
	str r1, [sp, #0x01C]
	mov r3, r9
	subs r3, r2, r3
	mov r8, r3
	subs r7, r1, r4
	cmp r7, #0x00
	bge _0800D82E
	movs r0, #0xE0
	lsls r0, r0, #0x05
	cmp r1, r0
	bgt _0800D82E
	ldr r0, _0800DA1C @ =0xFFFFE400
	adds r4, r4, r0
	cmp r4, #0x00
	blt _0800D82E
	mov r0, r8
	muls r0, r4
	adds r1, r7, #0x0
	bl sub_08017230
	adds r1, r0, #0x0
	add r1, r9
	movs r2, #0xF0
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bhi _0800D82E
	ldr r3, _0800DA20 @ =0x0202CC90
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	negs r1, r7
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08017230
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x024]
	ldr r1, [sp, #0x028]
	mov r2, r10
	movs r3, #0x00
	bl sub_0800D64C
	.global _0800D82E
_0800D82E:
	cmp r7, #0x00
	ble _0800D880
	ldr r0, [sp, #0x01C]
	ldr r1, _0800DA1C @ =0xFFFFE400
	cmp r0, r1
	blt _0800D880
	ldr r0, [sp, #0x014]
	subs r4, r1, r0
	cmp r4, #0x00
	blt _0800D880
	mov r0, r8
	muls r0, r4
	adds r1, r7, #0x0
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, [sp, #0x010]
	adds r1, r1, r0
	movs r2, #0xF0
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bhi _0800D880
	ldr r3, _0800DA20 @ =0x0202CC90
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	str r7, [sp, #0x008]
	lsls r0, r4, #0x10
	adds r1, r7, #0x0
	bl sub_08017230
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x024]
	ldr r1, [sp, #0x028]
	mov r2, r10
	movs r3, #0x01
	bl sub_0800D64C
	.global _0800D880
_0800D880:
	mov r1, r8
	cmp r1, #0x00
	ble _0800D8D4
	ldr r0, [sp, #0x018]
	ldr r1, _0800DA24 @ =0xFFFFF100
	cmp r0, r1
	blt _0800D8D4
	ldr r0, [sp, #0x010]
	subs r4, r1, r0
	cmp r4, #0x00
	blt _0800D8D4
	adds r0, r4, #0x0
	muls r0, r7
	mov r1, r8
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, [sp, #0x014]
	adds r1, r1, r0
	movs r2, #0xE0
	lsls r2, r2, #0x05
	adds r1, r1, r2
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r1, r0
	bhi _0800D8D4
	ldr r3, _0800DA20 @ =0x0202CC90
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	mov r1, r8
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08017230
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x024]
	ldr r1, [sp, #0x028]
	mov r2, r10
	movs r3, #0x02
	bl sub_0800D64C
	.global _0800D8D4
_0800D8D4:
	mov r2, r8
	cmp r2, #0x00
	bge _0800D92E
	ldr r1, [sp, #0x018]
	movs r0, #0xF0
	lsls r0, r0, #0x04
	cmp r1, r0
	bgt _0800D92E
	ldr r0, [sp, #0x010]
	ldr r3, _0800DA24 @ =0xFFFFF100
	adds r4, r0, r3
	cmp r4, #0x00
	blt _0800D92E
	adds r0, r4, #0x0
	muls r0, r7
	mov r1, r8
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, [sp, #0x014]
	adds r1, r1, r0
	movs r0, #0xE0
	lsls r0, r0, #0x05
	adds r1, r1, r0
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r1, r0
	bhi _0800D92E
	ldr r1, _0800DA20 @ =0x0202CC90
	str r1, [sp, #0x000]
	add r2, sp, #0x020
	str r2, [sp, #0x004]
	mov r3, r8
	negs r1, r3
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08017230
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x024]
	ldr r1, [sp, #0x028]
	mov r2, r10
	movs r3, #0x03
	bl sub_0800D64C
	.global _0800D92E
_0800D92E:
	ldr r0, _0800DA18 @ =0x0202CD30
	ldr r5, [r0, #0x10]
	ldr r6, [r0, #0x14]
	ldr r1, _0800DA14 @ =0x0202CCB0
	ldr r0, [r1, #0x10]
	subs r5, r5, r0
	ldr r0, [r1, #0x14]
	subs r6, r6, r0
	ldr r3, [r1, #0x04]
	adds r1, r3, #0x0
	muls r1, r5
	ldr r0, _0800DA14 @ =0x0202CCB0
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	muls r0, r6
	subs r1, r1, r0
	asrs r1, r1, #0x08
	mov r9, r1
	str r1, [sp, #0x010]
	adds r0, r2, #0x0
	muls r0, r5
	adds r1, r3, #0x0
	muls r1, r6
	adds r0, r0, r1
	asrs r4, r0, #0x08
	str r4, [sp, #0x014]
	ldr r1, _0800DA18 @ =0x0202CD30
	ldr r5, [r1, #0x18]
	ldr r6, [r1, #0x1C]
	ldr r2, _0800DA14 @ =0x0202CCB0
	ldr r0, [r2, #0x18]
	subs r5, r5, r0
	ldr r0, [r2, #0x1C]
	subs r6, r6, r0
	ldr r3, [r2, #0x0C]
	adds r2, r3, #0x0
	muls r2, r5
	ldr r0, _0800DA14 @ =0x0202CCB0
	ldr r1, [r0, #0x08]
	adds r0, r1, #0x0
	muls r0, r6
	subs r2, r2, r0
	asrs r2, r2, #0x08
	str r2, [sp, #0x018]
	adds r0, r1, #0x0
	muls r0, r5
	adds r1, r3, #0x0
	muls r1, r6
	adds r0, r0, r1
	asrs r1, r0, #0x08
	str r1, [sp, #0x01C]
	mov r3, r9
	subs r3, r2, r3
	mov r8, r3
	subs r7, r1, r4
	cmp r7, #0x00
	bge _0800D9EC
	movs r0, #0xE0
	lsls r0, r0, #0x05
	cmp r1, r0
	bgt _0800D9EC
	ldr r0, _0800DA1C @ =0xFFFFE400
	adds r4, r4, r0
	cmp r4, #0x00
	blt _0800D9EC
	mov r0, r8
	muls r0, r4
	adds r1, r7, #0x0
	bl sub_08017230
	adds r1, r0, #0x0
	add r1, r9
	movs r2, #0xF0
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bhi _0800D9EC
	ldr r3, _0800DA20 @ =0x0202CC90
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	negs r1, r7
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08017230
	str r0, [sp, #0x00C]
	mov r0, r10
	ldr r1, [sp, #0x028]
	ldr r2, [sp, #0x024]
	movs r3, #0x00
	bl sub_0800D64C
	.global _0800D9EC
_0800D9EC:
	cmp r7, #0x00
	ble _0800DA70
	ldr r0, [sp, #0x01C]
	ldr r1, _0800DA1C @ =0xFFFFE400
	cmp r0, r1
	b _0800DA28
	.global _0800D9F8
_0800D9F8: .4byte 0x02002090
	.global _0800D9FC
_0800D9FC: .4byte 0x020020DC
	.global _0800DA00
_0800DA00: .4byte 0x020020AC
	.global _0800DA04
_0800DA04: .4byte 0x00000175
	.global _0800DA08
_0800DA08: .4byte 0x0202A550
	.global _0800DA0C
_0800DA0C: .4byte 0x0000018F
	.global _0800DA10
_0800DA10: .4byte 0x0202CD24
	.global _0800DA14
_0800DA14: .4byte 0x0202CCB0
	.global _0800DA18
_0800DA18: .4byte 0x0202CD30
	.global _0800DA1C
_0800DA1C: .4byte 0xFFFFE400
	.global _0800DA20
_0800DA20: .4byte 0x0202CC90
	.global _0800DA24
_0800DA24: .4byte 0xFFFFF100
	.global _0800DA28
_0800DA28:
	blt _0800DA70
	ldr r0, [sp, #0x014]
	subs r4, r1, r0
	cmp r4, #0x00
	blt _0800DA70
	mov r0, r8
	muls r0, r4
	adds r1, r7, #0x0
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, [sp, #0x010]
	adds r1, r1, r0
	movs r2, #0xF0
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bhi _0800DA70
	ldr r3, _0800DC90 @ =0x0202CC90
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	str r7, [sp, #0x008]
	lsls r0, r4, #0x10
	adds r1, r7, #0x0
	bl sub_08017230
	str r0, [sp, #0x00C]
	mov r0, r10
	ldr r1, [sp, #0x028]
	ldr r2, [sp, #0x024]
	movs r3, #0x01
	bl sub_0800D64C
	.global _0800DA70
_0800DA70:
	mov r1, r8
	cmp r1, #0x00
	ble _0800DAC4
	ldr r0, [sp, #0x018]
	ldr r1, _0800DC94 @ =0xFFFFF100
	cmp r0, r1
	blt _0800DAC4
	ldr r0, [sp, #0x010]
	subs r4, r1, r0
	cmp r4, #0x00
	blt _0800DAC4
	adds r0, r4, #0x0
	muls r0, r7
	mov r1, r8
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, [sp, #0x014]
	adds r1, r1, r0
	movs r2, #0xE0
	lsls r2, r2, #0x05
	adds r1, r1, r2
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r1, r0
	bhi _0800DAC4
	ldr r3, _0800DC90 @ =0x0202CC90
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	mov r1, r8
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08017230
	str r0, [sp, #0x00C]
	mov r0, r10
	ldr r1, [sp, #0x028]
	ldr r2, [sp, #0x024]
	movs r3, #0x02
	bl sub_0800D64C
	.global _0800DAC4
_0800DAC4:
	mov r2, r8
	cmp r2, #0x00
	bge _0800DB1E
	ldr r1, [sp, #0x018]
	movs r0, #0xF0
	lsls r0, r0, #0x04
	cmp r1, r0
	bgt _0800DB1E
	ldr r0, [sp, #0x010]
	ldr r3, _0800DC94 @ =0xFFFFF100
	adds r4, r0, r3
	cmp r4, #0x00
	blt _0800DB1E
	adds r0, r4, #0x0
	muls r0, r7
	mov r1, r8
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, [sp, #0x014]
	adds r1, r1, r0
	movs r0, #0xE0
	lsls r0, r0, #0x05
	adds r1, r1, r0
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r1, r0
	bhi _0800DB1E
	ldr r1, _0800DC90 @ =0x0202CC90
	str r1, [sp, #0x000]
	add r2, sp, #0x020
	str r2, [sp, #0x004]
	mov r3, r8
	negs r1, r3
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08017230
	str r0, [sp, #0x00C]
	mov r0, r10
	ldr r1, [sp, #0x028]
	ldr r2, [sp, #0x024]
	movs r3, #0x03
	bl sub_0800D64C
	.global _0800DB1E
_0800DB1E:
	ldr r0, [sp, #0x02C]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x02C]
	movs r0, #0xC8
	lsls r0, r0, #0x01
	add r10, r0
	ldr r1, [sp, #0x02C]
	ldr r2, [sp, #0x040]
	cmp r1, r2
	beq _0800DB38
	b _0800D6FE
	.global _0800DB38
_0800DB38:
	add r3, sp, #0x020
	ldrb r0, [r3, #0x00]
	cmp r0, #0x00
	bne _0800DB42
	b _0800DE48
	.global _0800DB42
_0800DB42:
	ldr r4, _0800DC90 @ =0x0202CC90
	ldr r7, [r4, #0x00]
	ldr r6, [r4, #0x04]
	mov r8, r6
	ldrh r0, [r6, #0x34]
	lsrs r1, r0, #0x08
	ldr r2, _0800DC98 @ =0x0801CD08
	lsls r0, r1, #0x01
	adds r0, r0, r2
	movs r3, #0x00
	ldsh r6, [r0, r3]
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r2
	movs r0, #0x00
	ldsh r5, [r1, r0]
	ldr r0, _0800DC9C @ =0x083FDA2C
	ldrb r2, [r4, #0x09]
	lsls r1, r2, #0x03
	adds r2, r1, r0
	ldr r3, [r2, #0x00]
	adds r0, #0x04
	adds r1, r1, r0
	ldr r2, [r1, #0x00]
	adds r0, r3, #0x0
	muls r0, r5
	adds r1, r2, #0x0
	muls r1, r6
	subs r0, r0, r1
	asrs r0, r0, #0x04
	str r0, [sp, #0x030]
	adds r0, r3, #0x0
	muls r0, r6
	adds r1, r2, #0x0
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x04
	str r0, [sp, #0x034]
	ldr r0, [r4, #0x0C]
	negs r5, r0
	ldr r3, [sp, #0x030]
	adds r0, r5, #0x0
	muls r0, r3
	negs r0, r0
	cmp r0, #0x00
	bge _0800DBA0
	adds r0, #0xFF
	.global _0800DBA0
_0800DBA0:
	asrs r0, r0, #0x08
	str r0, [sp, #0x038]
	ldr r6, [sp, #0x034]
	adds r0, r5, #0x0
	muls r0, r6
	negs r0, r0
	cmp r0, #0x00
	bge _0800DBB2
	adds r0, #0xFF
	.global _0800DBB2
_0800DBB2:
	asrs r0, r0, #0x08
	str r0, [sp, #0x03C]
	ldr r0, [r7, #0x0C]
	ldr r1, [sp, #0x038]
	adds r0, r0, r1
	str r0, [r7, #0x0C]
	ldr r0, [r7, #0x14]
	ldr r2, [sp, #0x03C]
	adds r0, r0, r2
	str r0, [r7, #0x14]
	movs r4, #0xA0
	lsls r4, r4, #0x01
	adds r0, r7, r4
	movs r1, #0x00
	str r1, [r0, #0x00]
	movs r3, #0xA2
	lsls r3, r3, #0x01
	adds r0, r7, r3
	str r1, [r0, #0x00]
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r0, r7, r2
	str r1, [r0, #0x00]
	mov r6, r8
	ldr r0, [r6, #0x0C]
	ldr r6, [sp, #0x038]
	subs r0, r0, r6
	mov r6, r8
	str r0, [r6, #0x0C]
	ldr r0, [r6, #0x14]
	ldr r6, [sp, #0x03C]
	subs r0, r0, r6
	mov r6, r8
	str r0, [r6, #0x14]
	add r4, r8
	str r1, [r4, #0x00]
	add r3, r8
	str r1, [r3, #0x00]
	add r2, r8
	str r1, [r2, #0x00]
	lsls r0, r5, #0x05
	subs r0, r0, r5
	lsls r0, r0, #0x02
	adds r0, r0, r5
	lsls r5, r0, #0x03
	adds r0, r7, #0x0
	adds r0, #0x55
	ldrb r1, [r0, #0x00]
	adds r6, r0, #0x0
	cmp r1, #0x00
	bne _0800DC30
	movs r2, #0x06
	negs r2, r2
	str r1, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	movs r0, #0x00
	movs r1, #0x00
	movs r3, #0x00
	bl sub_0800BA34
	.global _0800DC30
_0800DC30:
	adds r0, r7, #0x0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	subs r0, #0x05
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _0800DCCC
	ldr r0, _0800DCA0 @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	adds r2, r7, #0x0
	adds r2, #0x88
	cmp r0, #0x00
	beq _0800DC54
	asrs r1, r5, #0x0C
	ldr r0, [r2, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	.global _0800DC54
_0800DC54:
	ldr r1, [r2, #0x00]
	ldr r0, _0800DCA4 @ =0x00009C40
	cmp r1, r0
	ble _0800DCC4
	ldr r0, [r7, #0x2C]
	negs r0, r0
	asrs r0, r0, #0x0C
	cmp r0, #0x00
	bge _0800DC68
	movs r0, #0x00
	.global _0800DC68
_0800DC68:
	cmp r0, #0x32
	ble _0800DCB4
	ldr r0, _0800DCA8 @ =0x0202A550
	subs r0, r7, r0
	ldr r1, _0800DCAC @ =0xC28F5C29
	adds r4, r0, #0x0
	muls r4, r1
	asrs r4, r4, #0x04
	ldr r0, _0800DCB0 @ =0x0202A530
	ldrb r0, [r0, #0x00]
	movs r1, #0x03
	bl sub_08017498
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0x0
	bl sub_0800E708
	b _0800DCC4
	.global _0800DC90
_0800DC90: .4byte 0x0202CC90
	.global _0800DC94
_0800DC94: .4byte 0xFFFFF100
	.global _0800DC98
_0800DC98: .4byte 0x0801CD08
	.global _0800DC9C
_0800DC9C: .4byte 0x083FDA2C
	.global _0800DCA0
_0800DCA0: .4byte 0x0202EEB0
	.global _0800DCA4
_0800DCA4: .4byte 0x00009C40
	.global _0800DCA8
_0800DCA8: .4byte 0x0202A550
	.global _0800DCAC
_0800DCAC: .4byte 0xC28F5C29
	.global _0800DCB0
_0800DCB0: .4byte 0x0202A530
	.global _0800DCB4
_0800DCB4:
	ldr r0, _0800DD64 @ =0x0202A550
	subs r0, r7, r0
	ldr r1, _0800DD68 @ =0xC28F5C29
	muls r0, r1
	asrs r0, r0, #0x04
	movs r1, #0x04
	bl sub_0800E708
	.global _0800DCC4
_0800DCC4:
	ldr r1, _0800DD6C @ =0x0202A530
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	.global _0800DCCC
_0800DCCC:
	adds r0, r7, #0x0
	bl sub_0800A2D4
	ldr r0, [r7, #0x2C]
	str r0, [r7, #0x48]
	cmp r0, #0x00
	ble _0800DCDE
	movs r0, #0x00
	str r0, [r7, #0x48]
	.global _0800DCDE
_0800DCDE:
	ldr r0, [r7, #0x48]
	lsls r0, r0, #0x08
	adds r3, r7, #0x0
	adds r3, #0x3E
	adds r1, r7, #0x0
	adds r1, #0xE8
	ldr r2, [r1, #0x00]
	ldrb r3, [r3, #0x00]
	lsls r1, r3, #0x01
	adds r1, r1, r2
	ldrh r1, [r1, #0x00]
	negs r1, r1
	bl sub_08017230
	adds r1, r7, #0x0
	adds r1, #0x40
	strh r0, [r1, #0x00]
	mov r0, r8
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	subs r0, #0x05
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _0800DD92
	ldr r0, _0800DD70 @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	mov r2, r8
	adds r2, #0x88
	cmp r0, #0x00
	beq _0800DD24
	asrs r1, r5, #0x0E
	ldr r0, [r2, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	.global _0800DD24
_0800DD24:
	ldr r1, [r2, #0x00]
	ldr r0, _0800DD74 @ =0x00009C40
	cmp r1, r0
	ble _0800DD8A
	mov r1, r8
	ldr r0, [r1, #0x2C]
	negs r0, r0
	asrs r0, r0, #0x0C
	cmp r0, #0x00
	bge _0800DD3A
	movs r0, #0x00
	.global _0800DD3A
_0800DD3A:
	cmp r0, #0x32
	ble _0800DD78
	ldr r0, _0800DD64 @ =0x0202A550
	mov r2, r8
	subs r0, r2, r0
	ldr r1, _0800DD68 @ =0xC28F5C29
	adds r4, r0, #0x0
	muls r4, r1
	asrs r4, r4, #0x04
	ldr r0, _0800DD6C @ =0x0202A530
	ldrb r0, [r0, #0x00]
	movs r1, #0x03
	bl sub_08017498
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0x0
	bl sub_0800E708
	b _0800DD8A
	.global _0800DD64
_0800DD64: .4byte 0x0202A550
	.global _0800DD68
_0800DD68: .4byte 0xC28F5C29
	.global _0800DD6C
_0800DD6C: .4byte 0x0202A530
	.global _0800DD70
_0800DD70: .4byte 0x0202EEB0
	.global _0800DD74
_0800DD74: .4byte 0x00009C40
	.global _0800DD78
_0800DD78:
	ldr r0, _0800DE2C @ =0x0202A550
	mov r3, r8
	subs r0, r3, r0
	ldr r1, _0800DE30 @ =0xC28F5C29
	muls r0, r1
	asrs r0, r0, #0x04
	movs r1, #0x04
	bl sub_0800E708
	.global _0800DD8A
_0800DD8A:
	ldr r1, _0800DE34 @ =0x0202A530
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	.global _0800DD92
_0800DD92:
	mov r0, r8
	bl sub_0800A2D4
	mov r1, r8
	ldr r0, [r1, #0x2C]
	str r0, [r1, #0x48]
	cmp r0, #0x00
	ble _0800DDA6
	movs r0, #0x00
	str r0, [r1, #0x48]
	.global _0800DDA6
_0800DDA6:
	mov r2, r8
	ldr r0, [r2, #0x48]
	lsls r0, r0, #0x08
	mov r3, r8
	adds r3, #0x3E
	mov r1, r8
	adds r1, #0xE8
	ldr r2, [r1, #0x00]
	ldrb r3, [r3, #0x00]
	lsls r1, r3, #0x01
	adds r1, r1, r2
	ldrh r1, [r1, #0x00]
	negs r1, r1
	bl sub_08017230
	mov r1, r8
	adds r1, #0x40
	strh r0, [r1, #0x00]
	ldr r2, _0800DE2C @ =0x0202A550
	cmp r7, r2
	beq _0800DDE0
	cmp r8, r2
	beq _0800DDE0
	ldr r0, _0800DE38 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	mov r4, r8
	adds r4, #0x55
	cmp r0, #0x00
	beq _0800DE20
	.global _0800DDE0
_0800DDE0:
	ldr r0, _0800DE3C @ =0x020021E0
	ldrb r0, [r0, #0x00]
	mov r4, r8
	adds r4, #0x55
	cmp r0, #0x00
	bne _0800DE20
	ldr r0, _0800DE40 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800DE20
	ldr r0, _0800DE44 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0800DE20
	ldr r3, [sp, #0x024]
	cmp r3, r2
	beq _0800DE0A
	ldr r0, _0800DE38 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800DE20
	.global _0800DE0A
_0800DE0A:
	ldrb r0, [r6, #0x00]
	mov r4, r8
	adds r4, #0x55
	cmp r0, #0x00
	bne _0800DE20
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _0800DE20
	movs r0, #0x12
	bl sub_08001208
	.global _0800DE20
_0800DE20:
	movs r0, #0x10
	strb r0, [r6, #0x00]
	strb r0, [r4, #0x00]
	movs r0, #0x01
	b _0800DE4A
	.byte 0x00, 0x00
	.global _0800DE2C
_0800DE2C: .4byte 0x0202A550
	.global _0800DE30
_0800DE30: .4byte 0xC28F5C29
	.global _0800DE34
_0800DE34: .4byte 0x0202A530
	.global _0800DE38
_0800DE38: .4byte 0x020020DC
	.global _0800DE3C
_0800DE3C: .4byte 0x020021E0
	.global _0800DE40
_0800DE40: .4byte 0x020020E0
	.global _0800DE44
_0800DE44: .4byte 0x0202EF00
	.global _0800DE48
_0800DE48:
	movs r0, #0x00
	.global _0800DE4A
_0800DE4A:
	add sp, #0x044
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x00, 0x47, 0x70, 0x47
	thumb_func_start sub_0800DE60
sub_0800DE60:
	push {r4, lr}
	ldr r3, _0800DE90 @ =0x0202E960
	lsls r0, r0, #0x17
	lsrs r0, r0, #0x17
	ldr r2, _0800DE94 @ =0xFFFFFE00
	ldrh r4, [r3, #0x12]
	ands r2, r4
	orrs r2, r0
	strh r2, [r3, #0x12]
	strb r1, [r3, #0x10]
	movs r0, #0x3F
	ldrb r1, [r3, #0x13]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r3, #0x13]
	ldr r0, _0800DE98 @ =0xFFFFFC00
	ldrh r4, [r3, #0x14]
	ands r0, r4
	strh r0, [r3, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800DE90
_0800DE90: .4byte 0x0202E960
	.global _0800DE94
_0800DE94: .4byte 0xFFFFFE00
	.global _0800DE98
_0800DE98: .4byte 0xFFFFFC00
	thumb_func_start sub_0800DE9C
sub_0800DE9C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r0, _0800DF44 @ =0x0202E960
	mov r12, r0
	mov r1, r12
	adds r1, #0x4A
	ldr r4, _0800DF48 @ =0xFFFFFE00
	adds r0, r4, #0x0
	ldrh r2, [r1, #0x00]
	ands r0, r2
	strh r0, [r1, #0x00]
	mov r0, r12
	adds r0, #0x48
	strb r6, [r0, #0x00]
	mov r2, r12
	adds r2, #0x4B
	movs r0, #0x3F
	ldrb r7, [r2, #0x00]
	ands r0, r7
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #0x00]
	mov r1, r12
	adds r1, #0x4D
	movs r0, #0x0F
	ldrb r2, [r1, #0x00]
	ands r0, r2
	strb r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x4C
	ldr r3, _0800DF4C @ =0xFFFFFC00
	adds r0, r3, #0x0
	ldrh r7, [r2, #0x00]
	ands r0, r7
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r5, #0x00
	mov r10, r12
	mov r9, r4
	adds r4, r3, #0x0
	.global _0800DEFE
_0800DEFE:
	adds r0, r5, #0x0
	adds r0, #0x0A
	lsls r0, r0, #0x03
	mov r1, r10
	adds r3, r0, r1
	lsls r2, r5, #0x05
	adds r2, #0x20
	ldr r7, _0800DF50 @ =0x000001FF
	adds r0, r7, #0x0
	adds r1, r2, #0x0
	ands r1, r0
	mov r0, r9
	ldrh r7, [r3, #0x02]
	ands r0, r7
	orrs r0, r1
	strh r0, [r3, #0x02]
	strb r6, [r3, #0x00]
	movs r0, #0x3F
	ldrb r1, [r3, #0x03]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r3, #0x03]
	movs r0, #0x0F
	ldrb r7, [r3, #0x05]
	ands r0, r7
	strb r0, [r3, #0x05]
	cmp r8, r2
	bge _0800DF54
	adds r0, r4, #0x0
	ldrh r1, [r3, #0x04]
	ands r0, r1
	movs r1, #0x20
	b _0800DF5C
	.byte 0x00, 0x00
	.global _0800DF44
_0800DF44: .4byte 0x0202E960
	.global _0800DF48
_0800DF48: .4byte 0xFFFFFE00
	.global _0800DF4C
_0800DF4C: .4byte 0xFFFFFC00
	.global _0800DF50
_0800DF50: .4byte 0x000001FF
	.global _0800DF54
_0800DF54:
	adds r0, r4, #0x0
	ldrh r2, [r3, #0x04]
	ands r0, r2
	movs r1, #0x10
	.global _0800DF5C
_0800DF5C:
	orrs r0, r1
	strh r0, [r3, #0x04]
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x07
	bls _0800DEFE
	mov r2, r12
	adds r2, #0x82
	ldr r0, _0800DFB8 @ =0xFFFFFE00
	ldrh r7, [r2, #0x00]
	ands r0, r7
	movs r1, #0xD0
	orrs r0, r1
	strh r0, [r2, #0x00]
	mov r0, r12
	adds r0, #0x80
	strb r6, [r0, #0x00]
	adds r2, #0x01
	movs r0, #0x3F
	ldrb r1, [r2, #0x00]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #0x00]
	mov r1, r12
	adds r1, #0x85
	movs r0, #0x0F
	ldrb r2, [r1, #0x00]
	ands r0, r2
	strb r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x84
	ldr r0, _0800DFBC @ =0xFFFFFC00
	ldrh r7, [r2, #0x00]
	ands r0, r7
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r2, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800DFB8
_0800DFB8: .4byte 0xFFFFFE00
	.global _0800DFBC
_0800DFBC: .4byte 0xFFFFFC00
	.byte 0x01, 0x49, 0x01, 0x20, 0x08, 0x80, 0x70, 0x47, 0xF8, 0x7F, 0x00, 0x03
