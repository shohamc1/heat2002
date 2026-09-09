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
	.byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x82, 0xB0, 0x04, 0x1C
	.byte 0x20, 0x68, 0xA1, 0x68, 0x6A, 0x46, 0xFE, 0xF7, 0xB2, 0xF8, 0x00, 0x06, 0x00, 0x28, 0x0C, 0xD0
	.byte 0x00, 0x99, 0x78, 0x39, 0x25, 0x4A, 0x90, 0x69, 0x09, 0x18, 0x01, 0x98, 0x50, 0x38, 0xD2, 0x69
	.byte 0x80, 0x18, 0x09, 0x04, 0x00, 0x91, 0x00, 0x04, 0x01, 0x90, 0x20, 0x68, 0x20, 0x49, 0x09, 0x18
	.byte 0x8A, 0x46, 0xC0, 0x21, 0x09, 0x03, 0x46, 0x18, 0xA0, 0x68, 0x1C, 0x4A, 0x85, 0x18, 0x43, 0x18
	.byte 0x1C, 0x49, 0x00, 0x22, 0x7C, 0x27, 0x7F, 0x18, 0xB9, 0x46, 0xB0, 0x20, 0x40, 0x00, 0x40, 0x18
	.byte 0x80, 0x46, 0x32, 0x27, 0xBC, 0x46, 0x4F, 0x46, 0x38, 0x78, 0x00, 0x28, 0x0C, 0xD1, 0x08, 0x68
	.byte 0x50, 0x45, 0x09, 0xDD, 0xB0, 0x42, 0x07, 0xDA, 0x88, 0x68, 0xA8, 0x42, 0x04, 0xDD, 0x98, 0x42
	.byte 0x02, 0xDA, 0x67, 0x46, 0x40, 0x46, 0x07, 0x80, 0x50, 0x1C, 0x00, 0x06, 0x02, 0x0E, 0x08, 0x2A
	.byte 0xE9, 0xD1, 0xA0, 0x69, 0x01, 0x38, 0xA0, 0x61, 0x00, 0x28, 0x05, 0xD1, 0x20, 0x1C, 0xFB, 0xF7
	.byte 0x3C, 0xFF, 0x20, 0x1C, 0xFB, 0xF7, 0x27, 0xFF, 0x02, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46
	.byte 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x00, 0x21, 0x00, 0x02, 0x00, 0x00
	.byte 0xF4, 0xFF, 0x50, 0xA5, 0x02, 0x02, 0x30, 0xB5, 0x04, 0x1C, 0x0D, 0x1C, 0x0C, 0x48, 0x00, 0x78
	.byte 0x02, 0x28, 0x11, 0xD0, 0x0A, 0x28, 0x0F, 0xD0, 0xFB, 0xF7, 0xE9, 0xFE, 0x01, 0x1C, 0x00, 0x29
	.byte 0x0A, 0xD0, 0xF0, 0x20, 0x88, 0x61, 0x0C, 0x60, 0x00, 0x20, 0x48, 0x60, 0x8D, 0x60, 0x04, 0x48
	.byte 0xC8, 0x60, 0x08, 0x1C, 0xFB, 0xF7, 0x07, 0xFF, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x5C, 0x21
	.byte 0x00, 0x02, 0x39, 0xBA, 0x00, 0x08, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47
	.byte 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47
	.byte 0x00, 0x00
	thumb_func_start sub_0800BB58
sub_0800BB58:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0x0
	adds r6, r0, #0x0
	ldrb r1, [r6, #0x00]
	adds r6, #0x01
	cmp r1, #0x00
	beq _0800BBBE
	movs r0, #0xFF
	mov r8, r0
	ands r0, r2
	mov r8, r0
	.global _0800BB72
_0800BB72:
	cmp r1, #0x20
	beq _0800BBB4
	lsls r1, r1, #0x01
	ldr r0, _0800BBC8 @ =0x08332D88
	adds r1, r1, r0
	ldr r2, _0800BBCC @ =0x08333208
	ldrh r1, [r1, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x05
	ldr r1, _0800BBD0 @ =0x0833338C
	adds r0, r0, r1
	bl sub_0800767C
	adds r5, r0, #0x0
	cmp r5, #0x00
	beq _0800BBB4
	ldr r4, _0800BBD4 @ =0x000001FF
	ands r4, r7
	lsls r4, r4, #0x10
	mov r0, r8
	orrs r4, r0
	ldr r0, _0800BBD8 @ =0x08332BC8
	bl sub_08007714
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	ldr r1, [r5, #0x10]
	orrs r1, r0
	adds r0, r4, #0x0
	bl sub_080044A4
	.global _0800BBB4
_0800BBB4:
	adds r7, #0x08
	ldrb r1, [r6, #0x00]
	adds r6, #0x01
	cmp r1, #0x00
	bne _0800BB72
	.global _0800BBBE
_0800BBBE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800BBC8
_0800BBC8: .4byte 0x08332D88
	.global _0800BBCC
_0800BBCC: .4byte 0x08333208
	.global _0800BBD0
_0800BBD0: .4byte 0x0833338C
	.global _0800BBD4
_0800BBD4: .4byte 0x000001FF
	.global _0800BBD8
_0800BBD8: .4byte 0x08332BC8
	.byte 0x0B, 0x1C, 0x00, 0xE0, 0x14, 0x33, 0x18, 0x78, 0xFF, 0x28, 0xFB, 0xD1, 0x14, 0x3B, 0xAA, 0x20
	.byte 0x40, 0x00, 0x11, 0x18, 0xD8, 0x88, 0x08, 0x60, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_0800BBFC
sub_0800BBFC:
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	adds r6, r1, #0x0
	ldrb r0, [r3, #0x00]
	lsls r1, r0, #0x02
	adds r1, r1, r2
	ldrh r5, [r1, #0x00]
	ldrb r4, [r3, #0x01]
	lsls r0, r4, #0x02
	adds r0, r0, r2
	ldrh r4, [r1, #0x02]
	ldrh r1, [r0, #0x02]
	ldrh r0, [r0, #0x00]
	subs r2, r0, r5
	cmp r2, #0x00
	bge _0800BC1E
	negs r2, r2
	.global _0800BC1E
_0800BC1E:
	subs r0, r1, r4
	cmp r0, #0x00
	bge _0800BC26
	negs r0, r0
	.global _0800BC26
_0800BC26:
	cmp r2, r0
	ble _0800BC30
	subs r1, r7, r5
	ldr r0, [r3, #0x0C]
	b _0800BC34
	.global _0800BC30
_0800BC30:
	subs r1, r6, r4
	ldr r0, [r3, #0x10]
	.global _0800BC34
_0800BC34:
	adds r2, r1, #0x0
	muls r2, r0
	ldrh r0, [r3, #0x04]
	ldrh r3, [r3, #0x06]
	subs r1, r3, r0
	muls r1, r2
	asrs r1, r1, #0x10
	adds r0, r0, r1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0800BC4C
sub_0800BC4C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x030
	ldr r3, _0800BD18 @ =0x083671C0
	ldr r2, _0800BD1C @ =0x020020CC
	ldrb r2, [r2, #0x00]
	lsls r2, r2, #0x02
	adds r2, r2, r3
	ldr r7, [r2, #0x00]
	ldrb r3, [r1, #0x00]
	lsls r2, r3, #0x02
	adds r2, r2, r0
	ldrh r4, [r2, #0x00]
	str r4, [sp, #0x000]
	ldrb r5, [r1, #0x00]
	lsls r2, r5, #0x02
	adds r2, r2, r0
	ldrh r3, [r2, #0x02]
	str r3, [sp, #0x004]
	ldrb r5, [r1, #0x01]
	lsls r2, r5, #0x02
	adds r2, r2, r0
	ldrh r2, [r2, #0x00]
	str r2, [sp, #0x008]
	ldrb r1, [r1, #0x01]
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldrh r0, [r1, #0x02]
	str r0, [sp, #0x00C]
	str r4, [sp, #0x018]
	mov r10, r3
	str r2, [sp, #0x01C]
	str r0, [sp, #0x020]
	movs r0, #0x00
	str r0, [sp, #0x024]
	movs r1, #0x00
	str r1, [sp, #0x028]
	.global _0800BC9C
_0800BC9C:
	ldr r2, [r7, #0x00]
	mov r12, r2
	ldr r5, [r7, #0x04]
	ldr r2, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	ldrh r3, [r7, #0x10]
	cmp r3, #0x01
	bne _0800BCB0
	movs r4, #0x01
	str r4, [sp, #0x024]
	.global _0800BCB0
_0800BCB0:
	ldr r1, [sp, #0x01C]
	ldr r3, [sp, #0x018]
	subs r1, r1, r3
	mov r9, r1
	subs r3, r0, r5
	mov r1, r9
	muls r1, r3
	ldr r4, [sp, #0x020]
	mov r0, r10
	subs r4, r4, r0
	mov r8, r4
	mov r4, r12
	subs r2, r2, r4
	mov r0, r8
	muls r0, r2
	subs r4, r1, r0
	cmp r4, #0x00
	beq _0800BD20
	mov r0, r10
	subs r6, r0, r5
	adds r0, r6, #0x0
	muls r0, r2
	ldr r1, [sp, #0x018]
	mov r2, r12
	subs r5, r1, r2
	adds r1, r5, #0x0
	muls r1, r3
	subs r0, r0, r1
	lsls r0, r0, #0x08
	adds r1, r4, #0x0
	bl sub_08017230
	movs r2, #0x80
	lsls r2, r2, #0x01
	cmp r0, r2
	bhi _0800BD20
	mov r0, r9
	muls r0, r6
	mov r1, r8
	muls r1, r5
	subs r0, r0, r1
	lsls r0, r0, #0x08
	adds r1, r4, #0x0
	str r2, [sp, #0x02C]
	bl sub_08017230
	ldr r2, [sp, #0x02C]
	cmp r0, r2
	bhi _0800BD20
	ldr r0, [sp, #0x028]
	b _0800BD32
	.byte 0x00, 0x00
	.global _0800BD18
_0800BD18: .4byte 0x083671C0
	.global _0800BD1C
_0800BD1C: .4byte 0x020020CC
	.global _0800BD20
_0800BD20:
	adds r7, #0x18
	ldr r3, [sp, #0x028]
	adds r3, #0x01
	str r3, [sp, #0x028]
	ldr r4, [sp, #0x024]
	cmp r4, #0x00
	beq _0800BC9C
	movs r0, #0x01
	negs r0, r0
	.global _0800BD32
_0800BD32:
	add sp, #0x030
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0800BD44
sub_0800BD44:
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0x0
	adds r5, r2, #0x0
	adds r6, r3, #0x0
	adds r4, r5, #0x0
	ldrh r1, [r5, #0x06]
	cmp r1, r0
	bge _0800BD5C
	.global _0800BD54
_0800BD54:
	adds r4, #0x14
	ldrh r1, [r4, #0x06]
	cmp r1, r0
	blt _0800BD54
	.global _0800BD5C
_0800BD5C:
	adds r0, r7, #0x0
	adds r1, r4, #0x0
	bl sub_0800BC4C
	adds r1, r0, #0x0
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	bne _0800BD84
	adds r4, #0x14
	ldrb r0, [r4, #0x01]
	cmp r0, #0xFF
	bne _0800BD5C
	adds r1, r6, #0x0
	adds r1, #0x4C
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	adds r4, r5, #0x0
	b _0800BD5C
	.global _0800BD84
_0800BD84:
	adds r0, r6, #0x0
	adds r0, #0x4D
	strb r1, [r0, #0x00]
	adds r1, r6, #0x0
	adds r1, #0x4E
	movs r0, #0x0F
	strb r0, [r1, #0x00]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start sub_0800BD98
sub_0800BD98:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r6, r2, #0x0
	adds r4, r3, #0x0
	ldrh r1, [r4, #0x06]
	cmp r1, r0
	bge _0800BDB2
	.global _0800BDAA
_0800BDAA:
	adds r4, #0x14
	ldrh r2, [r4, #0x06]
	cmp r2, r0
	blt _0800BDAA
	.global _0800BDB2
_0800BDB2:
	ldrh r1, [r4, #0x04]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r3, [r4, #0x06]
	subs r1, r3, r1
	bl sub_08017230
	ldrb r7, [r4, #0x01]
	lsls r2, r7, #0x02
	adds r2, r2, r6
	ldrb r3, [r4, #0x00]
	lsls r1, r3, #0x02
	adds r1, r1, r6
	ldrh r3, [r1, #0x00]
	ldrh r7, [r2, #0x00]
	subs r5, r7, r3
	ldrh r2, [r2, #0x02]
	ldrh r1, [r1, #0x02]
	subs r2, r2, r1
	adds r1, r5, #0x0
	muls r1, r0
	asrs r5, r1, #0x10
	muls r0, r2
	asrs r2, r0, #0x10
	adds r3, r3, r5
	mov r0, r8
	str r3, [r0, #0x00]
	ldrb r4, [r4, #0x00]
	lsls r0, r4, #0x02
	adds r0, r0, r6
	ldrh r0, [r0, #0x02]
	adds r0, r0, r2
	mov r1, r8
	str r0, [r1, #0x04]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start sub_0800BE00
sub_0800BE00:
	push {r4, r5, lr}
	mov r12, r0
	asrs r2, r1, #0x08
	adds r0, #0xF0
	str r1, [r0, #0x00]
	mov r4, r12
	adds r4, #0xF4
	ldr r3, _0800BE8C @ =0x083C9574
	ldr r1, _0800BE90 @ =0x020020CC
	ldrb r5, [r1, #0x00]
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsls r0, r0, #0x02
	adds r0, r2, r0
	lsls r0, r0, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x00]
	adds r4, #0x04
	ldr r3, _0800BE94 @ =0x083C97B4
	ldrb r5, [r1, #0x00]
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsls r0, r0, #0x02
	adds r0, r2, r0
	lsls r0, r0, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x00]
	adds r4, #0x04
	ldr r3, _0800BE98 @ =0x083C99F4
	ldrb r5, [r1, #0x00]
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsls r0, r0, #0x02
	adds r0, r2, r0
	lsls r0, r0, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x01
	add r4, r12
	ldr r3, _0800BE9C @ =0x083C9C34
	ldrb r5, [r1, #0x00]
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsls r0, r0, #0x02
	adds r0, r2, r0
	lsls r0, r0, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x00]
	movs r4, #0xAA
	lsls r4, r4, #0x01
	add r4, r12
	ldr r3, _0800BEA0 @ =0x083C9E74
	ldrb r5, [r1, #0x00]
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsls r0, r0, #0x02
	adds r2, r2, r0
	lsls r2, r2, #0x02
	adds r2, r2, r3
	ldr r0, [r2, #0x00]
	ldrh r0, [r0, #0x00]
	str r0, [r4, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _0800BE8C
_0800BE8C: .4byte 0x083C9574
	.global _0800BE90
_0800BE90: .4byte 0x020020CC
	.global _0800BE94
_0800BE94: .4byte 0x083C97B4
	.global _0800BE98
_0800BE98: .4byte 0x083C99F4
	.global _0800BE9C
_0800BE9C: .4byte 0x083C9C34
	.global _0800BEA0
_0800BEA0: .4byte 0x083C9E74
	thumb_func_start sub_0800BEA4
sub_0800BEA4:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	str r0, [sp, #0x00C]
	adds r5, r3, #0x0
	ldr r0, [sp, #0x038]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x010]
	ldr r0, [sp, #0x00C]
	ldr r6, [r0, #0x00]
	movs r1, #0x00
	mov r8, r1
	.global _0800BEC4
_0800BEC4:
	ldr r2, [sp, #0x010]
	cmp r2, #0x00
	bne _0800BEEC
	movs r0, #0x01
	mov r1, r8
	ands r0, r1
	cmp r0, #0x00
	beq _0800BEE0
	adds r0, r6, #0x0
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl sub_0800BE00
	b _0800BEF6
	.global _0800BEE0
_0800BEE0:
	adds r0, r6, #0x0
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl sub_0800BE00
	b _0800BEF6
	.global _0800BEEC
_0800BEEC:
	adds r0, r6, #0x0
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl sub_0800BE00
	.global _0800BEF6
_0800BEF6:
	movs r2, #0x01
	add r8, r2
	mov r0, r8
	cmp r0, #0x18
	bne _0800BEC4
	ldr r1, [sp, #0x00C]
	ldr r6, [r1, #0x00]
	movs r0, #0x00
	str r0, [r6, #0x2C]
	adds r0, r6, #0x0
	bl sub_0800C28C
	ldr r0, [r6, #0x00]
	str r0, [r6, #0x18]
	ldr r0, [r6, #0x08]
	str r0, [r6, #0x1C]
	adds r0, r6, #0x0
	movs r1, #0x00
	bl sub_0800C358
	movs r1, #0x01
	negs r1, r1
	cmp r0, r1
	bne _0800BF28
	b _0800C0C2
	.global _0800BF28
_0800BF28:
	ldr r0, _0800BF94 @ =0x0202CC24
	ldr r0, [r0, #0x00]
	ldr r1, _0800BF98 @ =0x0202CC38
	ldr r1, [r1, #0x00]
	adds r2, r6, #0x0
	adds r2, #0xF4
	ldr r2, [r2, #0x00]
	ldr r3, _0800BF9C @ =0x0202CC3C
	ldr r3, [r3, #0x00]
	ldr r4, _0800BFA0 @ =0x0202CC34
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	bl sub_0800BBFC
	adds r7, r0, #0x0
	ldr r2, _0800BFA4 @ =0xFFFFEC78
	adds r7, r7, r2
	cmp r7, #0x00
	bge _0800BF58
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	adds r7, r7, r0
	.global _0800BF58
_0800BF58:
	ldr r2, [sp, #0x00C]
	mov r9, r2
	movs r0, #0x00
	mov r8, r0
	ldr r0, _0800BFA8 @ =0x02002090
	ldrb r0, [r0, #0x00]
	cmp r8, r0
	bne _0800BF6A
	b _0800C086
	.global _0800BF6A
_0800BF6A:
	mov r1, sp
	adds r1, #0x04
	str r1, [sp, #0x014]
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r0, r0, #0x01
	mov r10, r0
	.global _0800BF7C
_0800BF7C:
	mov r2, r9
	ldr r6, [r2, #0x00]
	ldr r0, [sp, #0x010]
	cmp r0, #0x00
	beq _0800BFAC
	adds r0, r6, #0x0
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl sub_0800BE00
	b _0800BFCC
	.byte 0x00, 0x00
	.global _0800BF94
_0800BF94: .4byte 0x0202CC24
	.global _0800BF98
_0800BF98: .4byte 0x0202CC38
	.global _0800BF9C
_0800BF9C: .4byte 0x0202CC3C
	.global _0800BFA0
_0800BFA0: .4byte 0x0202CC34
	.global _0800BFA4
_0800BFA4: .4byte 0xFFFFEC78
	.global _0800BFA8
_0800BFA8: .4byte 0x02002090
	.global _0800BFAC
_0800BFAC:
	movs r0, #0x01
	mov r1, r8
	ands r0, r1
	cmp r0, #0x00
	beq _0800BFC2
	adds r0, r6, #0x0
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl sub_0800BE00
	b _0800BFCC
	.global _0800BFC2
_0800BFC2:
	adds r0, r6, #0x0
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl sub_0800BE00
	.global _0800BFCC
_0800BFCC:
	adds r5, r6, #0x0
	adds r5, #0xF4
	ldr r1, [r5, #0x00]
	adds r4, r6, #0x0
	adds r4, #0xF8
	ldr r2, [r4, #0x00]
	adds r0, r7, #0x0
	adds r3, r6, #0x0
	bl sub_0800BD44
	ldr r2, [r5, #0x00]
	ldr r3, [r4, #0x00]
	adds r0, r7, #0x0
	add r1, sp, #0x004
	bl sub_0800BD98
	ldr r0, [sp, #0x004]
	lsls r0, r0, #0x10
	str r0, [r6, #0x00]
	ldr r2, [sp, #0x014]
	ldr r0, [r2, #0x04]
	lsls r0, r0, #0x10
	str r0, [r6, #0x08]
	adds r0, r7, #0x0
	adds r0, #0x32
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r1, [r1, #0x00]
	bl sub_080172C8
	ldr r2, [r5, #0x00]
	ldr r3, [r4, #0x00]
	add r1, sp, #0x004
	bl sub_0800BD98
	ldr r0, [sp, #0x004]
	lsls r0, r0, #0x10
	ldr r1, [r6, #0x00]
	subs r0, r0, r1
	ldr r2, [sp, #0x014]
	ldr r1, [r2, #0x04]
	lsls r1, r1, #0x10
	ldr r2, [r6, #0x08]
	subs r1, r1, r2
	asrs r0, r0, #0x05
	asrs r1, r1, #0x05
	bl sub_0800CB18
	lsls r0, r0, #0x08
	ldr r2, _0800C0D4 @ =0xFFFF8400
	adds r1, r2, #0x0
	subs r1, r1, r0
	strh r1, [r6, #0x34]
	ldr r0, _0800C0D8 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0F
	bne _0800C052
	mov r0, r8
	cmp r0, #0x00
	bne _0800C052
	ldr r0, _0800C0DC @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _0800C052
	ldr r1, _0800C0E0 @ =0xFFFFFE0C
	adds r7, r7, r1
	.global _0800C052
_0800C052:
	ldr r2, [sp, #0x010]
	cmp r2, #0x00
	bne _0800C062
	movs r0, #0x01
	mov r2, r8
	ands r0, r2
	cmp r0, #0x00
	beq _0800C074
	.global _0800C062
_0800C062:
	mov r0, r10
	subs r7, r7, r0
	cmp r7, #0x00
	bge _0800C074
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	adds r7, r7, r0
	.global _0800C074
_0800C074:
	movs r2, #0x01
	add r8, r2
	movs r0, #0x04
	add r9, r0
	ldr r0, _0800C0E4 @ =0x02002090
	ldrb r0, [r0, #0x00]
	cmp r8, r0
	beq _0800C086
	b _0800BF7C
	.global _0800C086
_0800C086:
	movs r1, #0x00
	.global _0800C088
_0800C088:
	ldr r2, [sp, #0x00C]
	mov r9, r2
	movs r0, #0x00
	mov r8, r0
	ldr r0, _0800C0E4 @ =0x02002090
	adds r4, r1, #0x1
	ldrb r1, [r0, #0x00]
	cmp r8, r1
	beq _0800C0BC
	adds r5, r0, #0x0
	.global _0800C09C
_0800C09C:
	mov r2, r9
	adds r2, #0x04
	mov r9, r2
	subs r2, #0x04
	ldm r2!, {r6}
	mov r0, r8
	lsls r1, r0, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0x0
	bl sub_0800C534
	movs r1, #0x01
	add r8, r1
	ldrb r2, [r5, #0x00]
	cmp r8, r2
	bne _0800C09C
	.global _0800C0BC
_0800C0BC:
	adds r1, r4, #0x0
	cmp r1, #0x32
	bne _0800C088
	.global _0800C0C2
_0800C0C2:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800C0D4
_0800C0D4: .4byte 0xFFFF8400
	.global _0800C0D8
_0800C0D8: .4byte 0x0200215C
	.global _0800C0DC
_0800C0DC: .4byte 0x0202ED70
	.global _0800C0E0
_0800C0E0: .4byte 0xFFFFFE0C
	.global _0800C0E4
_0800C0E4: .4byte 0x02002090
