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
	thumb_func_start sub_080109C0
sub_080109C0:
	push {r4, r5, r6, lr}
	adds r5, r1, #0x0
	adds r4, r0, #0x0
	ldrb r1, [r4, #0x00]
	adds r4, #0x01
	cmp r1, #0x00
	beq _080109F8
	movs r6, #0xFF
	ands r6, r2
	.global _080109D2
_080109D2:
	cmp r1, #0x20
	beq _080109EE
	ldr r0, _08010A00 @ =0x000001FF
	ands r0, r5
	lsls r0, r0, #0x10
	orrs r0, r6
	movs r2, #0xB8
	lsls r2, r2, #0x02
	adds r1, r1, r2
	movs r2, #0xD8
	lsls r2, r2, #0x08
	orrs r1, r2
	bl sub_080044A4
	.global _080109EE
_080109EE:
	adds r5, #0x04
	ldrb r1, [r4, #0x00]
	adds r4, #0x01
	cmp r1, #0x00
	bne _080109D2
	.global _080109F8
_080109F8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08010A00
_08010A00: .4byte 0x000001FF
	.byte 0xF0, 0xB5, 0x0D, 0x1C, 0x16, 0x1C, 0x00, 0x06, 0x04, 0x0E, 0x27, 0x1C, 0x01, 0x2C, 0x02, 0xD1
	.byte 0x1B, 0x48, 0xFF, 0xF7, 0xD3, 0xFF, 0x02, 0x2C, 0x04, 0xD1, 0x1A, 0x48, 0x29, 0x1C, 0x32, 0x1C
	.byte 0xFF, 0xF7, 0xCC, 0xFF, 0x03, 0x2C, 0x04, 0xD1, 0x17, 0x48, 0x29, 0x1C, 0x32, 0x1C, 0xFF, 0xF7
	.byte 0xC5, 0xFF, 0x04, 0x2C, 0x04, 0xD1, 0x15, 0x48, 0x29, 0x1C, 0x32, 0x1C, 0xFF, 0xF7, 0xBE, 0xFF
	.byte 0x05, 0x2C, 0x04, 0xD1, 0x12, 0x48, 0x29, 0x1C, 0x32, 0x1C, 0xFF, 0xF7, 0xB7, 0xFF, 0x06, 0x2C
	.byte 0x04, 0xD1, 0x10, 0x48, 0x29, 0x1C, 0x32, 0x1C, 0xFF, 0xF7, 0xB0, 0xFF, 0x07, 0x2C, 0x04, 0xD1
	.byte 0x0D, 0x48, 0x29, 0x1C, 0x32, 0x1C, 0xFF, 0xF7, 0xA9, 0xFF, 0x08, 0x2F, 0x04, 0xD1, 0x0B, 0x48
	.byte 0x29, 0x1C, 0x32, 0x1C, 0xFF, 0xF7, 0xA2, 0xFF, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0xA0, 0xF2, 0x29, 0x08, 0x94, 0xF2, 0x29, 0x08, 0x88, 0xF2, 0x29, 0x08, 0x7C, 0xF2, 0x29, 0x08
	.byte 0x70, 0xF2, 0x29, 0x08, 0x64, 0xF2, 0x29, 0x08, 0x58, 0xF2, 0x29, 0x08, 0x4C, 0xF2, 0x29, 0x08
	thumb_func_start sub_08010AA4
sub_08010AA4:
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r5, _08010B0C @ =0x0829F2AC
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x04
	movs r3, #0x00
	bl sub_080063BC
	ldr r0, _08010B10 @ =0x083FDDD0
	lsls r6, r4, #0x02
	adds r0, r6, r0
	ldr r0, [r0, #0x00]
	movs r1, #0x04
	movs r2, #0x01
	bl sub_08006950
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x11
	movs r3, #0x00
	bl sub_080063BC
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x12
	movs r3, #0x00
	bl sub_080063BC
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x13
	movs r3, #0x00
	bl sub_080063BC
	ldr r0, _08010B14 @ =0x0202EF20
	adds r4, r4, r0
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08010B1C
	ldr r0, _08010B18 @ =0x083FDCF0
	adds r0, r6, r0
	ldr r0, [r0, #0x00]
	movs r1, #0x00
	movs r2, #0x11
	movs r3, #0x01
	bl sub_080063BC
	b _08010B2C
	.byte 0x00, 0x00
	.global _08010B0C
_08010B0C: .4byte 0x0829F2AC
	.global _08010B10
_08010B10: .4byte 0x083FDDD0
	.global _08010B14
_08010B14: .4byte 0x0202EF20
	.global _08010B18
_08010B18: .4byte 0x083FDCF0
	.global _08010B1C
_08010B1C:
	ldr r0, _08010B34 @ =0x083FDC88
	adds r0, r6, r0
	ldr r0, [r0, #0x00]
	movs r1, #0x00
	movs r2, #0x11
	movs r3, #0x01
	bl sub_080063BC
	.global _08010B2C
_08010B2C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08010B34
_08010B34: .4byte 0x083FDC88
	thumb_func_start sub_08010B38
sub_08010B38:
	push {r4, r5, lr}
	add sp, #-0x004
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	mov r1, sp
	movs r2, #0xFF
	ldrb r0, [r1, #0x00]
	orrs r0, r2
	strb r0, [r1, #0x00]
	ldrb r0, [r1, #0x01]
	orrs r0, r2
	strb r0, [r1, #0x01]
	movs r1, #0x00
	ldr r4, _08010BA4 @ =0x083FDB98
	mov r2, sp
	.global _08010B56
_08010B56:
	lsls r0, r1, #0x03
	adds r0, r0, r4
	ldrb r0, [r0, #0x04]
	cmp r0, r3
	bne _08010B62
	strb r1, [r2, #0x00]
	.global _08010B62
_08010B62:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x1E
	bne _08010B56
	movs r1, #0x00
	mov r2, sp
	ldr r5, _08010BA4 @ =0x083FDB98
	ldrb r4, [r2, #0x00]
	.global _08010B74
_08010B74:
	cmp r1, r4
	beq _08010B84
	lsls r0, r1, #0x03
	adds r0, r0, r5
	ldrb r0, [r0, #0x04]
	cmp r0, r3
	bne _08010B84
	strb r1, [r2, #0x01]
	.global _08010B84
_08010B84:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x1E
	bne _08010B74
	mov r1, sp
	mov r0, sp
	ldrb r0, [r0, #0x01]
	lsls r0, r0, #0x08
	ldrb r1, [r1, #0x00]
	orrs r0, r1
	add sp, #0x004
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08010BA4
_08010BA4: .4byte 0x083FDB98
	thumb_func_start sub_08010BA8
sub_08010BA8:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0x0
	bl sub_08010B38
	add r6, sp, #0x00C
	strb r0, [r6, #0x00]
	movs r1, #0xFF
	lsls r1, r1, #0x08
	ands r1, r0
	asrs r1, r1, #0x08
	strb r1, [r6, #0x01]
	movs r0, #0x70
	bl sub_08016558
	bl sub_080065A8
	adds r0, r4, #0x0
	bl sub_08010AA4
	ldr r0, _08010C28 @ =0x083FDEF4
	ldr r0, [r0, #0x00]
	ldr r1, _08010C2C @ =0x05000200
	movs r7, #0x80
	lsls r7, r7, #0x01
	adds r2, r7, #0x0
	bl sub_08016E10
	ldrb r0, [r6, #0x01]
	cmp r0, #0xFF
	bne _08010C40
	ldr r1, _08010C30 @ =0x083FDF74
	ldrb r2, [r6, #0x00]
	lsls r0, r2, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	ldr r1, _08010C34 @ =0x06010000
	bl sub_08016E28
	ldr r1, _08010C38 @ =0x083FDFEC
	ldrb r6, [r6, #0x00]
	lsls r0, r6, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	ldr r1, _08010C3C @ =0x06011000
	bl sub_08016E28
	movs r0, #0x38
	movs r1, #0x30
	movs r2, #0x00
	bl sub_08010194
	movs r0, #0x78
	movs r1, #0x30
	movs r2, #0x80
	bl sub_08010194
	b _08010CAE
	.byte 0x00, 0x00
	.global _08010C28
_08010C28: .4byte 0x083FDEF4
	.global _08010C2C
_08010C2C: .4byte 0x05000200
	.global _08010C30
_08010C30: .4byte 0x083FDF74
	.global _08010C34
_08010C34: .4byte 0x06010000
	.global _08010C38
_08010C38: .4byte 0x083FDFEC
	.global _08010C3C
_08010C3C: .4byte 0x06011000
	.global _08010C40
_08010C40:
	ldr r4, _08010CB8 @ =0x083FDF74
	ldrb r1, [r6, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	ldr r1, _08010CBC @ =0x06010000
	bl sub_08016E28
	ldr r5, _08010CC0 @ =0x083FDFEC
	ldrb r2, [r6, #0x00]
	lsls r0, r2, #0x02
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	ldr r1, _08010CC4 @ =0x06011000
	bl sub_08016E28
	ldrb r0, [r6, #0x01]
	lsls r0, r0, #0x02
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	ldr r1, _08010CC8 @ =0x06012000
	bl sub_08016E28
	ldrb r0, [r6, #0x01]
	lsls r0, r0, #0x02
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	ldr r1, _08010CCC @ =0x06013000
	bl sub_08016E28
	movs r0, #0x60
	movs r1, #0x30
	adds r2, r7, #0x0
	bl sub_08010194
	movs r2, #0xC0
	lsls r2, r2, #0x01
	movs r0, #0xA0
	movs r1, #0x30
	bl sub_08010194
	movs r0, #0x10
	movs r1, #0x30
	movs r2, #0x00
	bl sub_08010194
	movs r0, #0x50
	movs r1, #0x30
	movs r2, #0x80
	bl sub_08010194
	.global _08010CAE
_08010CAE:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08010CB8
_08010CB8: .4byte 0x083FDF74
	.global _08010CBC
_08010CBC: .4byte 0x06010000
	.global _08010CC0
_08010CC0: .4byte 0x083FDFEC
	.global _08010CC4
_08010CC4: .4byte 0x06011000
	.global _08010CC8
_08010CC8: .4byte 0x06012000
	.global _08010CCC
_08010CCC: .4byte 0x06013000
