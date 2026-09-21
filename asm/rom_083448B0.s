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
	thumb_func_start sub_083448B0
sub_083448B0:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _083448E4 @ =0x0400012A
	strh r0, [r1, #0x00]
	ldr r2, _083448E8 @ =0x04000208
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r1, _083448EC @ =0x03007FF8
	ldr r0, _083448F0 @ =0x0000FF7F
	ldrh r3, [r1, #0x00]
	ands r0, r3
	strh r0, [r1, #0x00]
	movs r0, #0x01
	strh r0, [r2, #0x00]
	subs r2, #0xE0
	movs r0, #0x30
	ldrb r1, [r2, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _083448E0
	ldrh r0, [r2, #0x00]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2, #0x00]
	.global _083448E0
_083448E0:
	bx lr
	.byte 0x00, 0x00
	.global _083448E4
_083448E4: .4byte 0x0400012A
	.global _083448E8
_083448E8: .4byte 0x04000208
	.global _083448EC
_083448EC: .4byte 0x03007FF8
	.global _083448F0
_083448F0: .4byte 0x0000FF7F
	.byte 0x09, 0x48, 0x01, 0x88, 0x40, 0x20, 0x08, 0x40, 0x00, 0x28, 0x19, 0xD1, 0x07, 0x49, 0x08, 0x48
	.byte 0x00, 0x88, 0x08, 0x80, 0x07, 0x48, 0x00, 0x88, 0x08, 0x81, 0x07, 0x48, 0x00, 0x88, 0x08, 0x82
	.byte 0x06, 0x48, 0x00, 0x88, 0x11, 0xE0, 0x00, 0x00, 0x28, 0x01, 0x00, 0x04, 0x60, 0xE1, 0x03, 0x02
	.byte 0x20, 0x01, 0x00, 0x04, 0x22, 0x01, 0x00, 0x04, 0x24, 0x01, 0x00, 0x04, 0x26, 0x01, 0x00, 0x04
	.byte 0x08, 0x49, 0x00, 0x20, 0x08, 0x80, 0x08, 0x81, 0x08, 0x82, 0x08, 0x83, 0x06, 0x4A, 0x00, 0x20
	.byte 0x10, 0x80, 0x06, 0x49, 0x80, 0x20, 0x0B, 0x88, 0x18, 0x43, 0x08, 0x80, 0x01, 0x20, 0x10, 0x80
	.byte 0x70, 0x47, 0x00, 0x00, 0x60, 0xE1, 0x03, 0x02, 0x08, 0x02, 0x00, 0x04, 0xF8, 0x7F, 0x00, 0x03
	.byte 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_08344968
sub_08344968:
	push {r4, r5, r6, lr}
	ldr r0, _08344A00 @ =0x04000134
	movs r1, #0x00
	strh r1, [r0, #0x00]
	subs r0, #0x0C
	strh r1, [r0, #0x00]
	movs r2, #0x00
	ldr r5, _08344A04 @ =0x0203DFF4
	ldr r6, _08344A08 @ =0x0203917C
	ldr r4, _08344A0C @ =0x0203E1C0
	movs r3, #0xFF
	.global _0834497E
_0834497E:
	lsls r0, r2, #0x02
	adds r0, r0, r4
	ldrb r1, [r0, #0x00]
	orrs r1, r3
	strb r1, [r0, #0x00]
	ldrb r1, [r0, #0x01]
	orrs r1, r3
	strb r1, [r0, #0x01]
	ldrb r1, [r0, #0x02]
	orrs r1, r3
	strb r1, [r0, #0x02]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x04
	bne _0834497E
	movs r0, #0x00
	str r0, [r5, #0x00]
	strh r0, [r6, #0x00]
	bl sub_08339A30
	bl sub_08344878
	ldr r2, _08344A10 @ =0x04000200
	ldrh r0, [r2, #0x00]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r1, _08344A14 @ =0x04000128
	movs r0, #0x30
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _083449CA
	ldrh r0, [r2, #0x00]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2, #0x00]
	.global _083449CA
_083449CA:
	movs r2, #0x00
	ldr r6, _08344A18 @ =0x0203DFB8
	movs r4, #0x00
	ldr r5, _08344A1C @ =0x0203E160
	.global _083449D2
_083449D2:
	lsls r0, r2, #0x01
	adds r0, r0, r6
	strh r4, [r0, #0x00]
	movs r1, #0x00
	adds r3, r2, #0x1
	lsls r2, r2, #0x03
	.global _083449DE
_083449DE:
	lsls r0, r1, #0x01
	adds r0, r0, r2
	adds r0, r0, r5
	strh r4, [r0, #0x00]
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x03
	bls _083449DE
	lsls r0, r3, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x03
	bls _083449D2
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08344A00
_08344A00: .4byte 0x04000134
	.global _08344A04
_08344A04: .4byte 0x0203DFF4
	.global _08344A08
_08344A08: .4byte 0x0203917C
	.global _08344A0C
_08344A0C: .4byte 0x0203E1C0
	.global _08344A10
_08344A10: .4byte 0x04000200
	.global _08344A14
_08344A14: .4byte 0x04000128
	.global _08344A18
_08344A18: .4byte 0x0203DFB8
	.global _08344A1C
_08344A1C: .4byte 0x0203E160
	thumb_func_start sub_08344A20
sub_08344A20:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	bl sub_08344968
	movs r0, #0x00
	mov r8, r0
	ldr r1, _08344A4C @ =0x0203DFB8
	mov r10, r1
	movs r2, #0xFF
	mov r9, r2
	.global _08344A3A
_08344A3A:
	ldr r1, _08344A50 @ =0x04000128
	movs r0, #0x30
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08344A54
	bl sub_08344B74
	b _08344A5C
	.global _08344A4C
_08344A4C: .4byte 0x0203DFB8
	.global _08344A50
_08344A50: .4byte 0x04000128
	.global _08344A54
_08344A54:
	movs r0, #0x01
	movs r1, #0x80
	bl sub_08344B68
	.global _08344A5C
_08344A5C:
	bl sub_08339B4C
	ldr r7, _08344B40 @ =0x04000128
	ldr r1, [r7, #0x00]
	lsls r1, r1, #0x1A
	lsrs r1, r1, #0x1E
	adds r1, #0x01
	lsls r1, r1, #0x0C
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r0, r3, #0x0
	orrs r1, r0
	ldr r6, _08344B44 @ =0x0203E004
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	mov r2, r9
	ands r0, r2
	orrs r1, r0
	mov r3, r10
	strh r1, [r3, #0x00]
	ldrh r0, [r3, #0x00]
	bl sub_083448B0
	ldr r2, _08344B48 @ =0x0203E1C0
	mov r0, r9
	ldrb r1, [r2, #0x02]
	orrs r0, r1
	strb r0, [r2, #0x02]
	mov r0, r9
	ldrb r3, [r2, #0x06]
	orrs r0, r3
	strb r0, [r2, #0x06]
	mov r0, r9
	ldrb r1, [r2, #0x0A]
	orrs r0, r1
	strb r0, [r2, #0x0A]
	mov r0, r9
	ldrb r3, [r2, #0x0E]
	orrs r0, r3
	strb r0, [r2, #0x0E]
	ldr r5, _08344B4C @ =0x0203E110
	movs r0, #0x00
	strb r0, [r5, #0x00]
	ldr r4, _08344B50 @ =0x0203E160
	ldrh r3, [r4, #0x00]
	lsrs r1, r3, #0x0C
	cmp r1, #0x01
	bne _08344AF2
	strb r1, [r2, #0x02]
	strb r1, [r5, #0x00]
	movs r0, #0x30
	ldrb r7, [r7, #0x00]
	ands r0, r7
	cmp r0, #0x00
	beq _08344ACE
	subs r0, r3, #0x1
	strb r0, [r6, #0x00]
	.global _08344ACE
_08344ACE:
	ldrh r3, [r4, #0x08]
	lsrs r0, r3, #0x0C
	cmp r0, #0x02
	bne _08344AF2
	strb r1, [r2, #0x06]
	strb r0, [r5, #0x00]
	ldrh r3, [r4, #0x10]
	lsrs r0, r3, #0x0C
	cmp r0, #0x03
	bne _08344AF2
	strb r1, [r2, #0x0A]
	strb r0, [r5, #0x00]
	ldrh r4, [r4, #0x18]
	lsrs r0, r4, #0x0C
	cmp r0, #0x04
	bne _08344AF2
	strb r1, [r2, #0x0E]
	strb r0, [r5, #0x00]
	.global _08344AF2
_08344AF2:
	ldr r1, _08344B54 @ =0x0203E1B0
	ldr r0, _08344B40 @ =0x04000128
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x1A
	lsrs r0, r0, #0x1E
	strb r0, [r1, #0x00]
	ldr r1, _08344B58 @ =0x020390BC
	ldr r0, _08344B4C @ =0x0203E110
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _08344B18
	mov r0, r8
	subs r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	.global _08344B18
_08344B18:
	ldr r1, _08344B50 @ =0x0203E160
	movs r0, #0x00
	strh r0, [r1, #0x00]
	strh r0, [r1, #0x08]
	strh r0, [r1, #0x10]
	strh r0, [r1, #0x18]
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0x05
	bne _08344A3A
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08344B40
_08344B40: .4byte 0x04000128
	.global _08344B44
_08344B44: .4byte 0x0203E004
	.global _08344B48
_08344B48: .4byte 0x0203E1C0
	.global _08344B4C
_08344B4C: .4byte 0x0203E110
	.global _08344B50
_08344B50: .4byte 0x0203E160
	.global _08344B54
_08344B54: .4byte 0x0203E1B0
	.global _08344B58
_08344B58: .4byte 0x020390BC
	.byte 0x70, 0x47, 0x00, 0x00
