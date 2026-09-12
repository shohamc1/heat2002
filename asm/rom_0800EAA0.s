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
	thumb_func_start sub_0800EAA0
sub_0800EAA0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0x0
	bl sub_0800EFC0
	cmp r0, #0x00
	beq _0800EAB6
	b _0800EE7C
	.global _0800EAB6
_0800EAB6:
	adds r0, r6, #0x0
	adds r0, #0x4A
	ldrb r1, [r0, #0x00]
	mov r10, r0
	cmp r1, #0x0F
	bls _0800EACA
	subs r0, r1, #0x1
	mov r1, r10
	strb r0, [r1, #0x00]
	b _0800EE7C
	.global _0800EACA
_0800EACA:
	adds r1, r6, #0x0
	adds r1, #0x48
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0800EAF4
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r0, _0800EAF0 @ =0x04000128
	ldrh r0, [r0, #0x00]
	movs r4, #0xFC
	ands r4, r0
	cmp r4, #0x08
	beq _0800EAF4
	adds r0, r6, #0x0
	bl sub_0800EA64
	movs r0, #0x08
	eors r0, r4
	b _0800EE7E
	.global _0800EAF0
_0800EAF0: .4byte 0x04000128
	.global _0800EAF4
_0800EAF4:
	ldrb r2, [r6, #0x18]
	cmp r2, #0xDF
	bls _0800EB46
	adds r0, r6, #0x0
	bl sub_0800EFD0
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _0800EB08
	b _0800EE7E
	.global _0800EB08
_0800EB08:
	adds r0, r6, #0x0
	adds r0, #0x4B
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0800EB24
	ldrb r0, [r6, #0x18]
	cmp r0, #0xE1
	bls _0800EB24
	adds r0, r6, #0x0
	bl sub_0800EFC0
	cmp r0, #0x00
	bne _0800EB24
	b _0800EE6C
	.global _0800EB24
_0800EB24:
	adds r0, r6, #0x0
	bl sub_0800EFC0
	cmp r0, #0x00
	beq _0800EB30
	b _0800EE7C
	.global _0800EB30
_0800EB30:
	ldrh r0, [r6, #0x16]
	cmp r0, #0x00
	bne _0800EB40
	adds r0, r6, #0x0
	bl sub_0800EA64
	movs r0, #0x71
	b _0800EE7E
	.global _0800EB40
_0800EB40:
	subs r0, #0x01
	strh r0, [r6, #0x16]
	b _0800EE7C
	.global _0800EB46
_0800EB46:
	ldrb r0, [r6, #0x18]
	cmp r0, #0x02
	bne _0800EB4E
	b _0800EC84
	.global _0800EB4E
_0800EB4E:
	cmp r0, #0x02
	bgt _0800EB5C
	cmp r0, #0x00
	beq _0800EB6A
	cmp r0, #0x01
	beq _0800EC28
	b _0800EDC0
	.global _0800EB5C
_0800EB5C:
	cmp r0, #0xD0
	bne _0800EB62
	b _0800ECD0
	.global _0800EB62
_0800EB62:
	cmp r0, #0xD1
	bne _0800EB68
	b _0800ED6C
	.global _0800EB68
_0800EB68:
	b _0800EDC0
	.global _0800EB6A
_0800EB6A:
	movs r5, #0x0E
	movs r4, #0x03
	ldr r0, _0800EBB0 @ =0x04000120
	ldrh r0, [r0, #0x06]
	adds r1, r0, #0x0
	ldr r0, _0800EBB4 @ =0x0000FFFF
	ldrb r2, [r6, #0x1E]
	adds r7, r2, #0x0
	cmp r1, r0
	bne _0800EB92
	adds r3, r1, #0x0
	ldr r1, _0800EBB8 @ =0x04000126
	.global _0800EB82
_0800EB82:
	asrs r5, r5, #0x01
	subs r1, #0x02
	subs r4, #0x01
	cmp r4, #0x00
	beq _0800EB92
	ldrh r0, [r1, #0x00]
	cmp r0, r3
	beq _0800EB82
	.global _0800EB92
_0800EB92:
	movs r0, #0x0E
	ands r5, r0
	strb r5, [r6, #0x1D]
	movs r4, #0x03
	ldr r0, _0800EBB0 @ =0x04000120
	ldrh r0, [r0, #0x06]
	adds r3, r0, #0x0
	asrs r0, r2, #0x03
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0800EBC0
	ldr r0, _0800EBBC @ =0x00007208
	b _0800EBE6
	.byte 0x00, 0x00
	.global _0800EBB0
_0800EBB0: .4byte 0x04000120
	.global _0800EBB4
_0800EBB4: .4byte 0x0000FFFF
	.global _0800EBB8
_0800EBB8: .4byte 0x04000126
	.global _0800EBBC
_0800EBBC: .4byte 0x00007208
	.global _0800EBC0
_0800EBC0:
	subs r4, #0x01
	cmp r4, #0x00
	beq _0800EBEC
	lsls r0, r4, #0x01
	ldr r1, _0800EC14 @ =0x04000120
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	adds r3, r0, #0x0
	adds r0, r2, #0x0
	asrs r0, r4
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0800EBC0
	adds r0, r1, #0x0
	lsls r0, r4
	movs r1, #0xE4
	lsls r1, r1, #0x07
	orrs r0, r1
	.global _0800EBE6
_0800EBE6:
	cmp r3, r0
	beq _0800EBC0
	movs r5, #0x00
	.global _0800EBEC
_0800EBEC:
	adds r0, r5, #0x0
	ands r0, r7
	strb r0, [r6, #0x1E]
	cmp r5, #0x00
	bne _0800EBFC
	movs r0, #0x0F
	mov r2, r10
	strb r0, [r2, #0x00]
	.global _0800EBFC
_0800EBFC:
	mov r1, r10
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0800EC18
	ldrb r2, [r6, #0x1D]
	ldrb r0, [r6, #0x1E]
	cmp r2, r0
	beq _0800EC1E
	adds r0, r6, #0x0
	bl sub_0800EED8
	b _0800EC28
	.global _0800EC14
_0800EC14: .4byte 0x04000120
	.global _0800EC18
_0800EC18:
	subs r0, #0x01
	mov r1, r10
	strb r0, [r1, #0x00]
	.global _0800EC1E
_0800EC1E:
	movs r2, #0xC4
	lsls r2, r2, #0x07
	adds r0, r2, #0x0
	ldrb r1, [r6, #0x1E]
	b _0800ED28
	.global _0800EC28
_0800EC28:
	adds r1, r6, #0x0
	adds r1, #0x49
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r4, #0x03
	adds r7, r1, #0x0
	ldr r5, _0800EC7C @ =0x0200048C
	.global _0800EC36
_0800EC36:
	lsls r0, r4, #0x01
	ldr r2, _0800EC80 @ =0x04000120
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	adds r3, r0, #0x0
	asrs r0, r3, #0x08
	subs r2, r4, #0x1
	cmp r0, #0x72
	bne _0800EC60
	lsls r0, r2, #0x01
	adds r0, r0, r5
	strh r3, [r0, #0x00]
	movs r0, #0xFF
	ands r3, r0
	movs r0, #0x01
	lsls r0, r4
	cmp r3, r0
	bne _0800EC60
	ldrb r0, [r1, #0x00]
	orrs r3, r0
	strb r3, [r1, #0x00]
	.global _0800EC60
_0800EC60:
	adds r4, r2, #0x0
	cmp r4, #0x00
	bne _0800EC36
	ldrb r1, [r6, #0x1D]
	ldrb r2, [r7, #0x00]
	cmp r1, r2
	bne _0800EC1E
	movs r0, #0x02
	strb r0, [r6, #0x18]
	movs r1, #0xC2
	lsls r1, r1, #0x07
	adds r0, r1, #0x0
	ldrb r1, [r7, #0x00]
	b _0800ED28
	.global _0800EC7C
_0800EC7C: .4byte 0x0200048C
	.global _0800EC80
_0800EC80: .4byte 0x04000120
	.global _0800EC84
_0800EC84:
	movs r4, #0x03
	adds r7, r6, #0x0
	adds r7, #0x49
	adds r5, r7, #0x0
	movs r2, #0x01
	mov r12, r2
	ldr r0, _0800ECC8 @ =0x0200048C
	mov r9, r0
	ldr r1, _0800ECCC @ =0x04000120
	mov r8, r1
	.global _0800EC98
_0800EC98:
	ldrb r3, [r5, #0x00]
	adds r0, r3, #0x0
	asrs r0, r4
	mov r2, r12
	ands r0, r2
	subs r2, r4, #0x1
	cmp r0, #0x00
	beq _0800ECC0
	lsls r0, r4, #0x01
	add r0, r8
	ldrh r1, [r0, #0x00]
	lsls r0, r2, #0x01
	add r0, r9
	ldrh r0, [r0, #0x00]
	cmp r1, r0
	beq _0800ECC0
	mov r0, r12
	lsls r0, r4
	eors r3, r0
	strb r3, [r5, #0x00]
	.global _0800ECC0
_0800ECC0:
	adds r4, r2, #0x0
	cmp r4, #0x00
	bne _0800EC98
	b _0800EE24
	.global _0800ECC8
_0800ECC8: .4byte 0x0200048C
	.global _0800ECCC
_0800ECCC: .4byte 0x04000120
	.global _0800ECD0
_0800ECD0:
	movs r5, #0x01
	movs r4, #0x03
	adds r7, r6, #0x0
	adds r7, #0x49
	movs r0, #0x19
	adds r0, r0, r6
	mov r12, r0
	ldr r1, _0800ED34 @ =0x0200048C
	mov r8, r1
	.global _0800ECE2
_0800ECE2:
	lsls r0, r4, #0x01
	ldr r2, _0800ED38 @ =0x04000120
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	adds r3, r0, #0x0
	subs r2, r4, #0x1
	mov r1, r12
	adds r0, r1, r2
	strb r3, [r0, #0x00]
	ldrb r1, [r7, #0x00]
	asrs r1, r4
	movs r0, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0800ED16
	asrs r0, r3, #0x08
	subs r0, #0x72
	cmp r0, #0x01
	bls _0800ED0A
	b _0800EE72
	.global _0800ED0A
_0800ED0A:
	lsls r0, r2, #0x01
	add r0, r8
	ldrh r0, [r0, #0x00]
	cmp r3, r0
	bne _0800ED16
	movs r5, #0x00
	.global _0800ED16
_0800ED16:
	adds r4, r2, #0x0
	cmp r4, #0x00
	bne _0800ECE2
	cmp r5, #0x00
	bne _0800ED3C
	movs r2, #0xC6
	lsls r2, r2, #0x07
	adds r0, r2, #0x0
	ldrb r1, [r6, #0x1C]
	.global _0800ED28
_0800ED28:
	orrs r1, r0
	adds r0, r6, #0x0
	bl sub_0800EE8C
	b _0800EE7E
	.byte 0x00, 0x00
	.global _0800ED34
_0800ED34: .4byte 0x0200048C
	.global _0800ED38
_0800ED38: .4byte 0x04000120
	.global _0800ED3C
_0800ED3C:
	movs r0, #0xD1
	strb r0, [r6, #0x18]
	movs r5, #0x11
	movs r4, #0x03
	mov r0, r12
	adds r0, #0x02
	.global _0800ED48
_0800ED48:
	ldrb r1, [r0, #0x00]
	adds r5, r1, r5
	subs r0, #0x01
	subs r4, #0x01
	cmp r4, #0x00
	bne _0800ED48
	strb r5, [r6, #0x14]
	movs r0, #0xFF
	ands r5, r0
	movs r2, #0xC8
	lsls r2, r2, #0x07
	adds r0, r2, #0x0
	orrs r5, r0
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl sub_0800EE8C
	b _0800EE7E
	.global _0800ED6C
_0800ED6C:
	movs r4, #0x03
	adds r7, r6, #0x0
	adds r7, #0x49
	ldrb r1, [r7, #0x00]
	ldr r2, _0800EDAC @ =0x04000126
	movs r5, #0x01
	.global _0800ED78
_0800ED78:
	ldrh r0, [r2, #0x00]
	adds r3, r0, #0x0
	adds r0, r1, #0x0
	asrs r0, r4
	ands r0, r5
	cmp r0, #0x00
	beq _0800ED8C
	asrs r0, r3, #0x08
	cmp r0, #0x73
	bne _0800EE72
	.global _0800ED8C
_0800ED8C:
	subs r2, #0x02
	subs r4, #0x01
	cmp r4, #0x00
	bne _0800ED78
	adds r0, r6, #0x0
	bl sub_08016E20
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _0800EDB0
	movs r0, #0xE0
	strb r0, [r6, #0x18]
	adds r0, #0xB0
	strh r0, [r6, #0x16]
	b _0800EE7C
	.byte 0x00, 0x00
	.global _0800EDAC
_0800EDAC: .4byte 0x04000126
	.global _0800EDB0
_0800EDB0:
	adds r0, r6, #0x0
	bl sub_0800EA64
	movs r0, #0x1E
	mov r1, r10
	strb r0, [r1, #0x00]
	movs r0, #0x70
	b _0800EE7E
	.global _0800EDC0
_0800EDC0:
	movs r4, #0x03
	adds r7, r6, #0x0
	adds r7, #0x49
	mov r12, r7
	movs r2, #0x01
	mov r8, r2
	.global _0800EDCC
_0800EDCC:
	mov r0, r12
	ldrb r5, [r0, #0x00]
	adds r0, r5, #0x0
	asrs r0, r4
	mov r1, r8
	ands r0, r1
	cmp r0, #0x00
	beq _0800EE06
	lsls r0, r4, #0x01
	ldr r2, _0800EE20 @ =0x04000120
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	adds r3, r0, #0x0
	asrs r2, r3, #0x08
	ldrb r0, [r6, #0x18]
	lsrs r1, r0, #0x01
	movs r0, #0x62
	subs r0, r0, r1
	mov r1, r8
	lsls r1, r4
	cmp r2, r0
	bne _0800EE00
	movs r0, #0xFF
	ands r3, r0
	cmp r3, r1
	beq _0800EE06
	.global _0800EE00
_0800EE00:
	eors r5, r1
	mov r1, r12
	strb r5, [r1, #0x00]
	.global _0800EE06
_0800EE06:
	subs r4, #0x01
	cmp r4, #0x00
	bne _0800EDCC
	ldrb r2, [r6, #0x18]
	cmp r2, #0xC4
	bne _0800EE24
	movs r0, #0x0E
	ldrb r7, [r7, #0x00]
	ands r0, r7
	strb r0, [r6, #0x1E]
	strb r4, [r6, #0x18]
	b _0800EC1E
	.byte 0x00, 0x00
	.global _0800EE20
_0800EE20: .4byte 0x04000120
	.global _0800EE24
_0800EE24:
	ldrb r0, [r7, #0x00]
	cmp r0, #0x00
	bne _0800EE34
	adds r0, r6, #0x0
	bl sub_0800EA64
	movs r0, #0x50
	b _0800EE7E
	.global _0800EE34
_0800EE34:
	ldrb r0, [r6, #0x18]
	adds r0, #0x02
	strb r0, [r6, #0x18]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xC4
	bne _0800EE44
	b _0800EC1E
	.global _0800EE44
_0800EE44:
	ldr r0, [r6, #0x28]
	ldrb r1, [r6, #0x18]
	adds r0, r1, r0
	subs r1, r0, #0x3
	ldrb r1, [r1, #0x00]
	lsls r1, r1, #0x08
	subs r0, #0x04
	ldrb r0, [r0, #0x00]
	orrs r1, r0
	adds r0, r6, #0x0
	bl sub_0800EE8C
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _0800EE7E
	adds r0, r6, #0x0
	adds r0, #0x4B
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0800EE7C
	.global _0800EE6C
_0800EE6C:
	bl sub_0800F0D4
	b _0800EACA
	.global _0800EE72
_0800EE72:
	adds r0, r6, #0x0
	bl sub_0800EA64
	movs r0, #0x60
	b _0800EE7E
	.global _0800EE7C
_0800EE7C:
	movs r0, #0x00
	.global _0800EE7E
_0800EE7E:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
