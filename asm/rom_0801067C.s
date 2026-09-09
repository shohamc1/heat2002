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
	.byte 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_08010680
sub_08010680:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	ldr r3, _080106C4 @ =0x0600F800
	movs r0, #0x00
	ldr r7, _080106C8 @ =0x0829FC80
	.global _0801068A
_0801068A:
	movs r5, #0x00
	adds r6, r0, #0x1
	.global _0801068E
_0801068E:
	ldrh r0, [r4, #0x00]
	adds r4, #0x02
	lsls r0, r0, #0x03
	adds r0, r0, r7
	ldrh r1, [r0, #0x00]
	strh r1, [r3, #0x00]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r3, #0x02]
	adds r0, #0x02
	ldrh r2, [r0, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x40
	strh r2, [r1, #0x00]
	ldrh r0, [r0, #0x02]
	strh r0, [r1, #0x02]
	adds r3, #0x04
	adds r5, #0x01
	cmp r5, #0x0F
	bne _0801068E
	adds r3, #0x44
	adds r0, r6, #0x0
	cmp r0, #0x0A
	bne _0801068A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _080106C4
_080106C4: .4byte 0x0600F800
	.global _080106C8
_080106C8: .4byte 0x0829FC80
	thumb_func_start sub_080106CC
sub_080106CC:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	adds r7, r1, #0x0
	ldr r3, _08010710 @ =0x0600F800
	movs r0, #0x00
	.global _080106D6
_080106D6:
	movs r5, #0x00
	adds r6, r0, #0x1
	.global _080106DA
_080106DA:
	ldrh r0, [r4, #0x00]
	adds r4, #0x02
	lsls r0, r0, #0x03
	adds r0, r7, r0
	ldrh r1, [r0, #0x00]
	strh r1, [r3, #0x00]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r3, #0x02]
	adds r0, #0x02
	ldrh r2, [r0, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x40
	strh r2, [r1, #0x00]
	ldrh r0, [r0, #0x02]
	strh r0, [r1, #0x02]
	adds r3, #0x04
	adds r5, #0x01
	cmp r5, #0x0F
	bne _080106DA
	adds r3, #0x44
	adds r0, r6, #0x0
	cmp r0, #0x0A
	bne _080106D6
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08010710
_08010710: .4byte 0x0600F800
	thumb_func_start sub_08010714
sub_08010714:
	push {r4, r5, r6, r7, lr}
	ldr r3, _08010758 @ =0x06008000
	ldr r5, _0801075C @ =0x082B751C
	movs r0, #0x00
	ldr r7, _08010760 @ =0x082B7648
	.global _0801071E
_0801071E:
	movs r4, #0x00
	adds r6, r0, #0x1
	.global _08010722
_08010722:
	ldrh r0, [r5, #0x00]
	adds r5, #0x02
	lsls r0, r0, #0x03
	adds r0, r0, r7
	ldrh r1, [r0, #0x00]
	strh r1, [r3, #0x00]
	adds r0, #0x02
	ldrh r1, [r0, #0x00]
	strh r1, [r3, #0x02]
	adds r0, #0x02
	ldrh r2, [r0, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x40
	strh r2, [r1, #0x00]
	ldrh r0, [r0, #0x02]
	strh r0, [r1, #0x02]
	adds r3, #0x04
	adds r4, #0x01
	cmp r4, #0x0F
	bne _08010722
	adds r3, #0x44
	adds r0, r6, #0x0
	cmp r0, #0x0A
	bne _0801071E
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08010758
_08010758: .4byte 0x06008000
	.global _0801075C
_0801075C: .4byte 0x082B751C
	.global _08010760
_08010760: .4byte 0x082B7648
	.byte 0x70, 0x47, 0x00, 0x00, 0x10, 0xB5, 0x41, 0x42, 0x08, 0x1C, 0x06, 0x21, 0x06, 0xF0, 0xAA, 0xFD
	.byte 0x01, 0x1C, 0x00, 0x29, 0x00, 0xDA, 0x06, 0x31, 0x07, 0x48, 0x01, 0x70, 0x07, 0x4C, 0x20, 0x1C
	.byte 0xF3, 0xF7, 0x16, 0xFB, 0xA0, 0x21, 0xC9, 0x04, 0x20, 0x1C, 0x40, 0x22, 0x06, 0xF0, 0x3E, 0xFB
	.byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xD0, 0xEE, 0x02, 0x02, 0xF0, 0xED, 0x02, 0x02
	.byte 0x00, 0xB5, 0x81, 0xB0, 0x0A, 0x4A, 0x10, 0x68, 0x01, 0x30, 0x1F, 0x21, 0x08, 0x40, 0x10, 0x60
	.byte 0x40, 0x01, 0xD0, 0x22, 0xD2, 0x01, 0x11, 0x1C, 0x08, 0x43, 0x69, 0x46, 0x08, 0x80, 0x05, 0x49
	.byte 0x68, 0x46, 0x01, 0x22, 0x06, 0xF0, 0x22, 0xFB, 0x01, 0xB0, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0xE4, 0xED, 0x02, 0x02, 0x3C, 0x01, 0x00, 0x05, 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_080107E0
sub_080107E0:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r4, _0801087C @ =0xFFFFFE00
	add sp, r4
	bl sub_08011A50
	ldr r1, _08010880 @ =0x0202EF40
	movs r5, #0x00
	movs r0, #0x00
	strh r0, [r1, #0x00]
	strh r0, [r1, #0x08]
	strh r0, [r1, #0x10]
	strh r0, [r1, #0x18]
	bl sub_08000458
	bl sub_080045D8
	bl sub_08007344
	bl sub_080073D8
	bl sub_08004484
	bl sub_080047DC
	ldr r0, _08010884 @ =0x020020C0
	strb r5, [r0, #0x00]
	bl sub_08000458
	bl sub_0800F3A4
	bl sub_0800F4FC
	ldr r0, _08010888 @ =0x082E4328
	mov r1, sp
	bl sub_0800F328
	movs r0, #0x00
	movs r1, #0x01
	bl sub_08010FE4
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r4, #0x80
	lsls r4, r4, #0x13
	movs r1, #0xA8
	lsls r1, r1, #0x03
	adds r0, r1, #0x0
	strh r0, [r4, #0x00]
	bl sub_08000458
	movs r2, #0xAA
	lsls r2, r2, #0x05
	adds r0, r2, #0x0
	strh r0, [r4, #0x00]
	movs r7, #0x40
	ldr r0, _0801088C @ =0x0202EF8C
	strb r5, [r0, #0x00]
	movs r0, #0x00
	mov r9, r0
	ldr r1, _08010890 @ =0x020020A0
	mov r8, r1
	.global _08010864
_08010864:
	bl sub_08004484
	bl sub_080073D8
	mov r2, r8
	ldrh r4, [r2, #0x00]
	bl sub_08003330
	cmp r0, #0x00
	beq _08010894
	movs r7, #0x03
	b _08010974
	.global _0801087C
_0801087C: .4byte 0xFFFFFE00
	.global _08010880
_08010880: .4byte 0x0202EF40
	.global _08010884
_08010884: .4byte 0x020020C0
	.global _08010888
_08010888: .4byte 0x082E4328
	.global _0801088C
_0801088C: .4byte 0x0202EF8C
	.global _08010890
_08010890: .4byte 0x020020A0
	.global _08010894
_08010894:
	mov r0, r8
	ldrh r0, [r0, #0x00]
	eors r4, r0
	mov r1, r8
	ldrh r1, [r1, #0x00]
	ands r4, r1
	movs r0, #0x10
	ands r0, r4
	ldr r6, _08010924 @ =0x0202EF8C
	cmp r0, #0x00
	beq _080108C8
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	strb r0, [r6, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x07
	bne _080108BC
	movs r0, #0x08
	strb r0, [r6, #0x00]
	.global _080108BC
_080108BC:
	movs r0, #0x00
	ldsb r0, [r6, r0]
	cmp r0, #0x0B
	ble _080108C8
	movs r0, #0x0B
	strb r0, [r6, #0x00]
	.global _080108C8
_080108C8:
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0x00
	beq _080108F2
	ldrb r0, [r6, #0x00]
	subs r0, #0x01
	strb r0, [r6, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x07
	bne _080108E2
	movs r0, #0x06
	strb r0, [r6, #0x00]
	.global _080108E2
_080108E2:
	movs r1, #0x00
	ldsb r1, [r6, r1]
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	bne _080108F2
	movs r0, #0x00
	strb r0, [r6, #0x00]
	.global _080108F2
_080108F2:
	adds r5, r6, #0x0
	movs r0, #0x00
	ldsb r0, [r5, r0]
	cmp r0, r9
	beq _0801090C
	movs r0, #0x08
	bl sub_08001208
	movs r0, #0x00
	ldsb r0, [r5, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	.global _0801090C
_0801090C:
	bl sub_08000458
	ldr r0, _08010928 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0801092C
	movs r0, #0x00
	ldsb r0, [r5, r0]
	movs r1, #0x01
	bl sub_08010FE4
	b _08010936
	.global _08010924
_08010924: .4byte 0x0202EF8C
	.global _08010928
_08010928: .4byte 0x0202EF90
	.global _0801092C
_0801092C:
	movs r0, #0x00
	ldsb r0, [r6, r0]
	movs r1, #0x01
	bl sub_08010FE4
	.global _08010936
_08010936:
	movs r0, #0x01
	ands r0, r4
	cmp r0, #0x00
	beq _08010954
	movs r0, #0x09
	bl sub_08001208
	ldr r2, _08010998 @ =0x0202EF8C
	ldr r1, _0801099C @ =0x083FDE78
	movs r0, #0x00
	ldsb r0, [r2, r0]
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	strb r0, [r2, #0x00]
	movs r7, #0x01
	.global _08010954
_08010954:
	movs r0, #0x02
	ands r4, r0
	cmp r4, #0x00
	beq _0801095E
	movs r7, #0x02
	.global _0801095E
_0801095E:
	bl sub_080047DC
	ldr r1, _080109A0 @ =0x020020C0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	.global _08010968
_08010968:
	ldr r0, _080109A0 @ =0x020020C0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08010968
	bl sub_08000458
	.global _08010974
_08010974:
	cmp r7, #0x40
	bne _0801097A
	b _08010864
	.global _0801097A
_0801097A:
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	bl sub_08000458
	cmp r7, #0x02
	bne _080109A4
	movs r0, #0x00
	b _080109AE
	.byte 0x00, 0x00
	.global _08010998
_08010998: .4byte 0x0202EF8C
	.global _0801099C
_0801099C: .4byte 0x083FDE78
	.global _080109A0
_080109A0: .4byte 0x020020C0
	.global _080109A4
_080109A4:
	cmp r7, #0x03
	beq _080109AC
	movs r0, #0x01
	b _080109AE
	.global _080109AC
_080109AC:
	movs r0, #0x02
	.global _080109AE
_080109AE:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
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
	thumb_func_start sub_08010CD0
sub_08010CD0:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r4, _08010DD8 @ =0xFFFFFE00
	add sp, r4
	movs r0, #0x0C
	mov r9, r0
	bl sub_080045D8
	bl sub_08007344
	bl sub_080073D8
	bl sub_08004484
	bl sub_080047DC
	ldr r5, _08010DDC @ =0x020020C0
	movs r0, #0x00
	strb r0, [r5, #0x00]
	bl sub_08000458
	bl sub_0800F3A4
	bl sub_0800F4FC
	ldr r0, _08010DE0 @ =0x082E4328
	mov r1, sp
	bl sub_0800F328
	movs r0, #0x0C
	bl sub_08010BA8
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r4, #0x80
	lsls r4, r4, #0x13
	movs r1, #0xA8
	lsls r1, r1, #0x03
	adds r0, r1, #0x0
	strh r0, [r4, #0x00]
	bl sub_08000458
	movs r2, #0xAA
	lsls r2, r2, #0x05
	adds r0, r2, #0x0
	strh r0, [r4, #0x00]
	movs r7, #0x40
	ldr r6, _08010DE4 @ =0x020005CC
	mov r8, r5
	.global _08010D3A
_08010D3A:
	bl sub_08004484
	mov r0, r9
	lsls r4, r0, #0x18
	lsrs r5, r4, #0x18
	adds r0, r5, #0x0
	bl sub_08010BA8
	bl sub_0800048C
	movs r0, #0x01
	ldrh r1, [r6, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08010D66
	ldr r0, _08010DE8 @ =0x0202EF20
	asrs r1, r4, #0x18
	adds r1, r1, r0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08010D66
	adds r7, r5, #0x0
	.global _08010D66
_08010D66:
	ldrh r0, [r6, #0x00]
	asrs r1, r4, #0x18
	movs r2, #0x00
	movs r3, #0x10
	bl sub_08011E00
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r9, r0
	movs r0, #0x02
	ldrh r2, [r6, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _08010D84
	movs r7, #0x00
	.global _08010D84
_08010D84:
	bl sub_080047DC
	movs r0, #0x00
	mov r1, r8
	strb r0, [r1, #0x00]
	lsls r4, r7, #0x18
	.global _08010D90
_08010D90:
	mov r2, r8
	ldrb r0, [r2, #0x00]
	cmp r0, #0x00
	beq _08010D90
	bl sub_08000458
	bl sub_08000458
	asrs r4, r4, #0x18
	cmp r4, #0x40
	beq _08010D3A
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	bl sub_08000458
	ldr r0, _08010DEC @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08010DC8
	movs r0, #0x09
	bl sub_08001208
	.global _08010DC8
_08010DC8:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	cmp r4, #0x00
	beq _08010DF0
	mov r0, r9
	b _08010DF2
	.global _08010DD8
_08010DD8: .4byte 0xFFFFFE00
	.global _08010DDC
_08010DDC: .4byte 0x020020C0
	.global _08010DE0
_08010DE0: .4byte 0x082E4328
	.global _08010DE4
_08010DE4: .4byte 0x020005CC
	.global _08010DE8
_08010DE8: .4byte 0x0202EF20
	.global _08010DEC
_08010DEC: .4byte 0x0202EF00
	.global _08010DF0
_08010DF0:
	movs r0, #0x00
	.global _08010DF2
_08010DF2:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start sub_08010E04
sub_08010E04:
	push {r4, lr}
	add sp, #-0x00C
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0x9C
	bl sub_08016558
	bl sub_080065A8
	ldr r0, _08010E80 @ =0x0829F2AC
	movs r1, #0x00
	movs r2, #0x06
	movs r3, #0x00
	bl sub_080063BC
	ldr r1, _08010E84 @ =0x083FDB98
	lsls r0, r4, #0x03
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x06
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _08010E88 @ =0x083FDEF4
	lsls r4, r4, #0x02
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	ldr r1, _08010E8C @ =0x05000200
	movs r2, #0x80
	lsls r2, r2, #0x01
	bl sub_08016E10
	ldr r0, _08010E90 @ =0x083FDF74
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	ldr r1, _08010E94 @ =0x06010000
	bl sub_08016E28
	ldr r0, _08010E98 @ =0x083FDFEC
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x00]
	ldr r1, _08010E9C @ =0x06011000
	bl sub_08016E28
	movs r0, #0x38
	movs r1, #0x40
	movs r2, #0x00
	bl sub_08010194
	movs r0, #0x78
	movs r1, #0x40
	movs r2, #0x80
	bl sub_08010194
	add sp, #0x00C
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08010E80
_08010E80: .4byte 0x0829F2AC
	.global _08010E84
_08010E84: .4byte 0x083FDB98
	.global _08010E88
_08010E88: .4byte 0x083FDEF4
	.global _08010E8C
_08010E8C: .4byte 0x05000200
	.global _08010E90
_08010E90: .4byte 0x083FDF74
	.global _08010E94
_08010E94: .4byte 0x06010000
	.global _08010E98
_08010E98: .4byte 0x083FDFEC
	.global _08010E9C
_08010E9C: .4byte 0x06011000
	thumb_func_start sub_08010EA0
sub_08010EA0:
	push {r4, r5, r6, r7, lr}
	ldr r4, _08010F5C @ =0xFFFFFE00
	add sp, r4
	movs r6, #0x00
	bl sub_080045D8
	bl sub_08007344
	bl sub_080073D8
	bl sub_08004484
	bl sub_080047DC
	ldr r0, _08010F60 @ =0x020020C0
	strb r6, [r0, #0x00]
	bl sub_08000458
	bl sub_0800F3A4
	bl sub_0800F4FC
	ldr r0, _08010F64 @ =0x082E4328
	mov r1, sp
	bl sub_0800F328
	movs r0, #0x00
	bl sub_08010E04
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r4, #0x80
	lsls r4, r4, #0x13
	movs r1, #0xA8
	lsls r1, r1, #0x03
	adds r0, r1, #0x0
	strh r0, [r4, #0x00]
	bl sub_08000458
	movs r2, #0xAA
	lsls r2, r2, #0x05
	adds r0, r2, #0x0
	strh r0, [r4, #0x00]
	movs r7, #0x40
	.global _08010EFC
_08010EFC:
	bl sub_08004484
	lsls r4, r6, #0x18
	lsrs r5, r4, #0x18
	adds r0, r5, #0x0
	bl sub_08010E04
	bl sub_0800048C
	ldr r1, _08010F68 @ =0x020005CC
	movs r0, #0x01
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08010F1C
	adds r7, r5, #0x0
	.global _08010F1C
_08010F1C:
	ldr r5, _08010F68 @ =0x020005CC
	ldrh r0, [r5, #0x00]
	asrs r1, r4, #0x18
	movs r2, #0x00
	movs r3, #0x0B
	bl sub_08011E00
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	asrs r1, r0, #0x18
	movs r2, #0xFA
	lsls r2, r2, #0x18
	adds r0, r0, r2
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bls _08010F44
	cmp r1, #0x0A
	beq _08010F44
	cmp r1, #0x0B
	bne _08010F6C
	.global _08010F44
_08010F44:
	ldr r1, _08010F68 @ =0x020005CC
	ldrh r2, [r1, #0x00]
	movs r0, #0x30
	ands r0, r2
	lsls r4, r6, #0x18
	cmp r0, #0x00
	bne _08010F1C
	movs r0, #0x10
	orrs r0, r2
	strh r0, [r1, #0x00]
	b _08010F1C
	.byte 0x00, 0x00
	.global _08010F5C
_08010F5C: .4byte 0xFFFFFE00
	.global _08010F60
_08010F60: .4byte 0x020020C0
	.global _08010F64
_08010F64: .4byte 0x082E4328
	.global _08010F68
_08010F68: .4byte 0x020005CC
	.global _08010F6C
_08010F6C:
	movs r0, #0x02
	ldrh r5, [r5, #0x00]
	ands r0, r5
	cmp r0, #0x00
	beq _08010F78
	movs r7, #0x00
	.global _08010F78
_08010F78:
	bl sub_080047DC
	ldr r1, _08010FCC @ =0x020020C0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	lsls r4, r7, #0x18
	.global _08010F84
_08010F84:
	ldr r0, _08010FCC @ =0x020020C0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08010F84
	bl sub_08000458
	bl sub_08000458
	asrs r4, r4, #0x18
	cmp r4, #0x40
	beq _08010EFC
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	bl sub_08000458
	ldr r0, _08010FD0 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08010FBC
	movs r0, #0x09
	bl sub_08001208
	.global _08010FBC
_08010FBC:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	cmp r4, #0x00
	beq _08010FD4
	adds r0, r6, #0x0
	b _08010FD6
	.global _08010FCC
_08010FCC: .4byte 0x020020C0
	.global _08010FD0
_08010FD0: .4byte 0x0202EF00
	.global _08010FD4
_08010FD4:
	movs r0, #0x00
	.global _08010FD6
_08010FD6:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_08010FE4
sub_08010FE4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x034
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	cmp r1, #0x00
	beq _08011004
	movs r0, #0xA1
	bl sub_08016558
	bl sub_080065A8
	.global _08011004
_08011004:
	ldr r4, _0801103C @ =0x0829F2AC
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x04
	movs r3, #0x00
	bl sub_080063BC
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x05
	movs r3, #0x00
	bl sub_080063BC
	cmp r7, #0x03
	beq _08011044
	ldr r1, _08011040 @ =0x083FDA78
	lsls r4, r7, #0x01
	adds r0, r4, r7
	lsls r0, r0, #0x03
	adds r1, #0x0C
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x04
	movs r2, #0x01
	bl sub_08006950
	b _0801105A
	.byte 0x00, 0x00
	.global _0801103C
_0801103C: .4byte 0x0829F2AC
	.global _08011040
_08011040: .4byte 0x083FDA78
	.global _08011044
_08011044:
	ldr r0, _0801112C @ =0x0829F2CC
	movs r1, #0x04
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _08011130 @ =0x0829F2D8
	movs r1, #0x05
	movs r2, #0x01
	bl sub_08006950
	movs r4, #0x06
	.global _0801105A
_0801105A:
	ldr r5, _08011134 @ =0x083FDA78
	adds r4, r4, r7
	lsls r4, r4, #0x03
	adds r0, r5, #0x0
	adds r0, #0x14
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	ldr r1, _08011138 @ =0x05000200
	movs r6, #0x80
	lsls r6, r6, #0x01
	adds r2, r6, #0x0
	bl sub_08016E10
	ldr r0, _0801113C @ =0x0830E670
	ldr r1, _08011140 @ =0x050003E0
	movs r2, #0x10
	bl sub_08016E10
	adds r5, #0x10
	adds r4, r4, r5
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x00]
	ldr r1, _08011144 @ =0x06010000
	bl sub_08016E28
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x04]
	ldr r1, _08011148 @ =0x06011000
	bl sub_08016E28
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x08]
	ldr r1, _0801114C @ =0x06012000
	bl sub_08016E28
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x0C]
	ldr r1, _08011150 @ =0x06013000
	bl sub_08016E28
	movs r0, #0x38
	movs r1, #0x20
	movs r2, #0x00
	bl sub_08010194
	movs r0, #0x78
	movs r1, #0x20
	movs r2, #0x80
	bl sub_08010194
	movs r0, #0x38
	movs r1, #0x60
	adds r2, r6, #0x0
	bl sub_08010194
	movs r2, #0xC0
	lsls r2, r2, #0x01
	movs r0, #0x78
	movs r1, #0x60
	bl sub_08010194
	mov r0, r8
	cmp r0, #0x00
	beq _08011116
	ldr r1, _08011154 @ =0x0202EED8
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08011116
	ldr r0, _08011158 @ =0x0830E618
	ldr r1, _0801115C @ =0x06014000
	bl sub_08016E28
	ldr r0, _08011160 @ =0x0830E690
	ldr r1, _08011164 @ =0x06015000
	bl sub_08016E28
	cmp r7, #0x00
	beq _08011106
	movs r2, #0x80
	lsls r2, r2, #0x02
	movs r0, #0x10
	movs r1, #0x48
	bl sub_0801027C
	.global _08011106
_08011106:
	cmp r7, #0x0B
	beq _08011116
	movs r2, #0xA0
	lsls r2, r2, #0x02
	movs r0, #0xD0
	movs r1, #0x48
	bl sub_0801027C
	.global _08011116
_08011116:
	ldr r1, _08011154 @ =0x0202EED8
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	add sp, #0x034
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _0801112C
_0801112C: .4byte 0x0829F2CC
	.global _08011130
_08011130: .4byte 0x0829F2D8
	.global _08011134
_08011134: .4byte 0x083FDA78
	.global _08011138
_08011138: .4byte 0x05000200
	.global _0801113C
_0801113C: .4byte 0x0830E670
	.global _08011140
_08011140: .4byte 0x050003E0
	.global _08011144
_08011144: .4byte 0x06010000
	.global _08011148
_08011148: .4byte 0x06011000
	.global _0801114C
_0801114C: .4byte 0x06012000
	.global _08011150
_08011150: .4byte 0x06013000
	.global _08011154
_08011154: .4byte 0x0202EED8
	.global _08011158
_08011158: .4byte 0x0830E618
	.global _0801115C
_0801115C: .4byte 0x06014000
	.global _08011160
_08011160: .4byte 0x0830E690
	.global _08011164
_08011164: .4byte 0x06015000
	thumb_func_start sub_08011168
sub_08011168:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _080112B0 @ =0xFFFFFE00
	add sp, r4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r6, #0x00
	cmp r5, #0x00
	bne _08011182
	adds r6, r1, #0x0
	.global _08011182
_08011182:
	ldr r0, _080112B4 @ =0x0202EED8
	movs r4, #0x00
	strb r4, [r0, #0x00]
	bl sub_080045D8
	bl sub_08007344
	bl sub_080073D8
	bl sub_08004484
	bl sub_080047DC
	ldr r0, _080112B8 @ =0x020020C0
	strb r4, [r0, #0x00]
	bl sub_08000458
	bl sub_0800F3A4
	bl sub_0800F4FC
	ldr r0, _080112BC @ =0x082E4328
	mov r1, sp
	bl sub_0800F328
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl sub_08010FE4
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r4, #0x80
	lsls r4, r4, #0x13
	movs r1, #0xA8
	lsls r1, r1, #0x03
	adds r0, r1, #0x0
	strh r0, [r4, #0x00]
	bl sub_08000458
	movs r2, #0xAA
	lsls r2, r2, #0x05
	adds r0, r2, #0x0
	strh r0, [r4, #0x00]
	movs r0, #0x40
	mov r8, r0
	ldr r7, _080112C0 @ =0x020005CC
	.global _080111E2
_080111E2:
	bl sub_08004484
	lsls r4, r6, #0x18
	lsrs r0, r4, #0x18
	adds r1, r5, #0x0
	bl sub_08010FE4
	bl sub_0800048C
	movs r0, #0x01
	ldrh r1, [r7, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08011202
	cmp r5, #0x01
	beq _0801120E
	.global _08011202
_08011202:
	cmp r5, #0x00
	bne _08011216
	ldr r0, _080112B4 @ =0x0202EED8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x20
	bne _08011212
	.global _0801120E
_0801120E:
	lsrs r4, r4, #0x18
	mov r8, r4
	.global _08011212
_08011212:
	cmp r5, #0x00
	beq _08011228
	.global _08011216
_08011216:
	ldrh r0, [r7, #0x00]
	lsls r1, r6, #0x18
	asrs r1, r1, #0x18
	movs r2, #0x00
	movs r3, #0x0B
	bl sub_08011EE8
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	.global _08011228
_08011228:
	ldr r2, _080112C0 @ =0x020005CC
	cmp r6, #0x07
	bne _08011244
	ldrh r1, [r7, #0x00]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _0801123A
	movs r6, #0x06
	.global _0801123A
_0801123A:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _08011244
	movs r6, #0x08
	.global _08011244
_08011244:
	ldr r0, _080112C4 @ =0x0202EF8C
	strb r6, [r0, #0x00]
	movs r0, #0x02
	ldrh r2, [r2, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _0801125A
	cmp r5, #0x00
	beq _0801125A
	movs r2, #0x00
	mov r8, r2
	.global _0801125A
_0801125A:
	bl sub_080047DC
	ldr r1, _080112B8 @ =0x020020C0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	mov r0, r8
	lsls r4, r0, #0x18
	.global _08011268
_08011268:
	ldr r0, _080112B8 @ =0x020020C0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08011268
	bl sub_08000458
	bl sub_08000458
	asrs r4, r4, #0x18
	cmp r4, #0x40
	beq _080111E2
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	bl sub_08000458
	ldr r0, _080112C8 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _080112A0
	movs r0, #0x09
	bl sub_08001208
	.global _080112A0
_080112A0:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	cmp r4, #0x00
	beq _080112CC
	adds r0, r6, #0x0
	b _080112CE
	.global _080112B0
_080112B0: .4byte 0xFFFFFE00
	.global _080112B4
_080112B4: .4byte 0x0202EED8
	.global _080112B8
_080112B8: .4byte 0x020020C0
	.global _080112BC
_080112BC: .4byte 0x082E4328
	.global _080112C0
_080112C0: .4byte 0x020005CC
	.global _080112C4
_080112C4: .4byte 0x0202EF8C
	.global _080112C8
_080112C8: .4byte 0x0202EF00
	.global _080112CC
_080112CC:
	movs r0, #0x00
	.global _080112CE
_080112CE:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_080112E0
sub_080112E0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	movs r5, #0x00
	ldr r2, _08011370 @ =0x020020AC
	mov r10, r2
	ldr r0, _08011374 @ =0x0202EFC0
	mov r9, r0
	ldrb r1, [r2, #0x00]
	cmp r5, r1
	beq _0801131C
	mov r4, r9
	ldr r3, _08011378 @ =0x0202A550
	.global _080112FE
_080112FE:
	lsls r0, r5, #0x02
	adds r0, r0, r4
	lsls r1, r5, #0x01
	adds r1, r1, r5
	lsls r1, r1, #0x03
	adds r1, r1, r5
	lsls r1, r1, #0x04
	adds r1, r1, r3
	str r1, [r0, #0x00]
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r0, [r2, #0x00]
	cmp r5, r0
	bne _080112FE
	.global _0801131C
_0801131C:
	mov r6, r9
	movs r5, #0x00
	movs r7, #0x00
	mov r1, r10
	ldrb r1, [r1, #0x00]
	cmp r1, #0x01
	beq _0801135C
	movs r2, #0xB6
	lsls r2, r2, #0x01
	mov r12, r2
	mov r8, r10
	.global _08011332
_08011332:
	ldr r4, [r6, #0x00]
	ldr r3, [r6, #0x04]
	mov r1, r12
	adds r0, r4, r1
	adds r1, r3, r1
	ldr r2, [r0, #0x00]
	ldr r0, [r1, #0x00]
	cmp r2, r0
	bls _0801134A
	str r3, [r6, #0x00]
	str r4, [r6, #0x04]
	movs r7, #0x01
	.global _0801134A
_0801134A:
	adds r6, #0x04
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r2, r8
	ldrb r0, [r2, #0x00]
	subs r0, #0x01
	cmp r5, r0
	bne _08011332
	.global _0801135C
_0801135C:
	cmp r7, #0x00
	bne _0801131C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08011370
_08011370: .4byte 0x020020AC
	.global _08011374
_08011374: .4byte 0x0202EFC0
	.global _08011378
_08011378: .4byte 0x0202A550
	thumb_func_start sub_0801137C
sub_0801137C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x034
	ldr r0, _08011404 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x5B
	bl sub_08016558
	bl sub_080065A8
	ldr r0, _08011408 @ =0x0202EFC0
	str r0, [sp, #0x030]
	movs r7, #0x00
	ldr r0, _0801140C @ =0x020020AC
	ldrb r0, [r0, #0x00]
	cmp r7, r0
	bne _080113AA
	b _080114FE
	.global _080113AA
_080113AA:
	add r1, sp, #0x028
	mov r10, r1
	movs r0, #0x2A
	add r0, sp
	mov r9, r0
	add r1, sp, #0x02C
	mov r8, r1
	mov r6, sp
	.global _080113BA
_080113BA:
	ldr r0, [sp, #0x030]
	ldr r5, [r0, #0x00]
	movs r1, #0xB6
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	add r1, sp, #0x028
	mov r2, sp
	adds r2, #0x2A
	add r3, sp, #0x02C
	bl sub_08016C50
	ldr r0, _08011410 @ =0x0202EF90
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _08011414 @ =0x0202A550
	adds r0, r0, r1
	cmp r5, r0
	bne _08011420
	ldr r1, _08011418 @ =0x0202539C
	movs r0, #0x10
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08011420
	lsls r2, r7, #0x01
	adds r2, #0x04
	ldr r0, _0801141C @ =0x0829F2F0
	movs r1, #0x04
	movs r3, #0x01
	bl sub_080063BC
	b _080114E8
	.global _08011404
_08011404: .4byte 0x083FDE18
	.global _08011408
_08011408: .4byte 0x0202EFC0
	.global _0801140C
_0801140C: .4byte 0x020020AC
	.global _08011410
_08011410: .4byte 0x0202EF90
	.global _08011414
_08011414: .4byte 0x0202A550
	.global _08011418
_08011418: .4byte 0x0202539C
	.global _0801141C
_0801141C: .4byte 0x0829F2F0
	.global _08011420
_08011420:
	adds r0, r7, #0x0
	adds r0, #0xC0
	bl sub_08016558
	lsls r4, r7, #0x01
	adds r4, #0x04
	movs r1, #0x01
	adds r2, r4, #0x0
	movs r3, #0x01
	bl sub_080063BC
	ldr r0, _08011518 @ =0x0202A550
	subs r0, r5, r0
	ldr r1, _0801151C @ =0xC28F5C29
	muls r0, r1
	asrs r0, r0, #0x04
	adds r0, #0x53
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_08016558
	movs r1, #0x06
	adds r2, r4, #0x0
	movs r3, #0x01
	bl sub_080063BC
	mov r1, r10
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r6, #0x00]
	mov r1, r10
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r6, #0x01]
	movs r0, #0x3A
	strb r0, [r6, #0x02]
	mov r1, r9
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r6, #0x03]
	mov r1, r9
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r6, #0x04]
	movs r0, #0x3A
	strb r0, [r6, #0x05]
	mov r1, r8
	ldrh r0, [r1, #0x00]
	movs r1, #0x64
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r6, #0x06]
	mov r1, r8
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r6, #0x07]
	movs r0, #0x00
	strb r0, [r6, #0x08]
	mov r0, sp
	movs r1, #0x12
	adds r2, r4, #0x0
	movs r3, #0x01
	bl sub_080063BC
	.global _080114E8
_080114E8:
	ldr r1, [sp, #0x030]
	adds r1, #0x04
	str r1, [sp, #0x030]
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _08011520 @ =0x020020AC
	ldrb r0, [r0, #0x00]
	cmp r7, r0
	beq _080114FE
	b _080113BA
	.global _080114FE
_080114FE:
	ldr r1, _08011524 @ =0x0202539C
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	add sp, #0x034
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08011518
_08011518: .4byte 0x0202A550
	.global _0801151C
_0801151C: .4byte 0xC28F5C29
	.global _08011520
_08011520: .4byte 0x020020AC
	.global _08011524
_08011524: .4byte 0x0202539C
	thumb_func_start sub_08011528
sub_08011528:
	push {r4, r5, r6, r7, lr}
	ldr r4, _0801156C @ =0xFFFFFE00
	add sp, r4
	bl sub_08011A50
	ldr r1, _08011570 @ =0x0202EF40
	movs r0, #0x00
	strh r0, [r1, #0x00]
	strh r0, [r1, #0x08]
	strh r0, [r1, #0x10]
	strh r0, [r1, #0x18]
	movs r7, #0x00
	bl sub_080112E0
	movs r0, #0x00
	mov r1, sp
	bl sub_08011C9C
	bl sub_0801137C
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r5, #0x40
	ldr r6, _08011574 @ =0x020020A0
	.global _0801155C
_0801155C:
	ldrh r4, [r6, #0x00]
	bl sub_08003330
	cmp r0, #0x00
	beq _08011578
	movs r5, #0x05
	b _080115BC
	.byte 0x00, 0x00
	.global _0801156C
_0801156C: .4byte 0xFFFFFE00
	.global _08011570
_08011570: .4byte 0x0202EF40
	.global _08011574
_08011574: .4byte 0x020020A0
	.global _08011578
_08011578:
	ldrh r0, [r6, #0x00]
	eors r4, r0
	ands r4, r0
	bl sub_0801137C
	ldr r0, _0801159C @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080115A0
	movs r0, #0x58
	bl sub_08016558
	movs r1, #0x0E
	movs r2, #0x01
	bl sub_08006950
	b _080115AE
	.byte 0x00, 0x00
	.global _0801159C
_0801159C: .4byte 0x0202EF90
	.global _080115A0
_080115A0:
	movs r0, #0x0F
	bl sub_08016558
	movs r1, #0x0E
	movs r2, #0x01
	bl sub_08006950
	.global _080115AE
_080115AE:
	movs r0, #0x09
	ands r4, r0
	cmp r4, #0x00
	beq _080115B8
	movs r5, #0x00
	.global _080115B8
_080115B8:
	bl sub_08000458
	.global _080115BC
_080115BC:
	lsls r4, r5, #0x18
	cmp r5, #0x40
	beq _0801155C
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r4, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start sub_080115D8
sub_080115D8:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0x0
	ldr r0, _08011648 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x5A
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x05
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _08011600
	movs r2, #0x01
	.global _08011600
_08011600:
	movs r1, #0x07
	bl sub_08006950
	movs r0, #0x06
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _08011614
	movs r2, #0x01
	.global _08011614
_08011614:
	movs r1, #0x09
	bl sub_08006950
	movs r0, #0x07
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x02
	bne _08011628
	movs r2, #0x01
	.global _08011628
_08011628:
	movs r1, #0x0B
	bl sub_08006950
	movs r0, #0x08
	bl sub_08016558
	movs r2, #0x00
	cmp r5, #0x03
	bne _0801163C
	movs r2, #0x01
	.global _0801163C
_0801163C:
	movs r1, #0x0D
	bl sub_08006950
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08011648
_08011648: .4byte 0x083FDE18
	thumb_func_start sub_0801164C
sub_0801164C:
	push {r4, r5, r6, r7, lr}
	ldr r4, _08011680 @ =0xFFFFFE00
	add sp, r4
	bl sub_08011A50
	movs r6, #0x00
	movs r0, #0x01
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_080115D8
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r5, #0x40
	ldr r7, _08011684 @ =0x020020A0
	.global _08011672
_08011672:
	ldrh r4, [r7, #0x00]
	bl sub_08003330
	cmp r0, #0x00
	beq _08011688
	movs r5, #0x05
	b _080116B6
	.global _08011680
_08011680: .4byte 0xFFFFFE00
	.global _08011684
_08011684: .4byte 0x020020A0
	.global _08011688
_08011688:
	ldrh r2, [r7, #0x00]
	eors r2, r4
	ldrh r0, [r7, #0x00]
	ands r2, r0
	movs r0, #0x09
	ands r0, r2
	lsls r1, r6, #0x18
	cmp r0, #0x00
	beq _0801169C
	lsrs r5, r1, #0x18
	.global _0801169C
_0801169C:
	asrs r1, r1, #0x18
	adds r0, r2, #0x0
	movs r2, #0x00
	movs r3, #0x03
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r6, #0x0
	bl sub_080115D8
	bl sub_08000458
	.global _080116B6
_080116B6:
	lsls r4, r5, #0x18
	cmp r5, #0x40
	beq _08011672
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r4, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_080116D4
sub_080116D4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, [sp, #0x01C]
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0x20
	ands r0, r6
	cmp r0, #0x00
	beq _08011728
	ldr r0, _0801176C @ =0x0202EFB0
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, _08011770 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r0, r4
	bne _08011716
	ldr r0, _08011774 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011716
	movs r0, #0x08
	bl sub_08001208
	.global _08011716
_08011716:
	lsls r0, r5, #0x10
	ldr r1, _08011778 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	mov r2, r8
	lsls r1, r2, #0x10
	cmp r0, r1
	bge _08011728
	adds r5, r7, #0x0
	.global _08011728
_08011728:
	movs r0, #0x10
	ands r0, r6
	cmp r0, #0x00
	beq _0801175E
	ldr r0, _0801176C @ =0x0202EFB0
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, _08011770 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r0, r4
	bne _0801174C
	ldr r0, _08011774 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0801174C
	movs r0, #0x08
	bl sub_08001208
	.global _0801174C
_0801174C:
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	lsls r1, r7, #0x10
	cmp r0, r1
	ble _0801175E
	mov r5, r8
	.global _0801175E
_0801175E:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _0801176C
_0801176C: .4byte 0x0202EFB0
	.global _08011770
_08011770: .4byte 0x0202EF90
	.global _08011774
_08011774: .4byte 0x0202EF00
	.global _08011778
_08011778: .4byte 0xFFFF0000
	thumb_func_start sub_0801177C
sub_0801177C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08011904 @ =0xFFFFFDD8
	add sp, r4
	bl sub_08011A50
	movs r4, #0x03
	ldr r0, _08011908 @ =0x0000020B
	add r0, sp
	.global _08011794
_08011794:
	strb r4, [r0, #0x00]
	subs r0, #0x01
	subs r4, #0x01
	cmp r4, #0x00
	bge _08011794
	add r4, sp, #0x208
	ldr r5, _0801190C @ =0x04000128
	ldr r0, [r5, #0x00]
	lsls r0, r0, #0x1A
	lsrs r0, r0, #0x1E
	adds r0, r4, r0
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x224]
	ldr r0, _08011910 @ =0x082B8710
	ldr r1, _08011914 @ =0x06016000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_080045D8
	bl sub_08007344
	bl sub_080073D8
	bl sub_08004484
	bl sub_080047DC
	ldr r1, _08011918 @ =0x020020C0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	bl sub_08000458
	bl sub_0800F3A4
	bl sub_0800F4FC
	ldr r0, _0801191C @ =0x082E4328
	add r1, sp, #0x008
	bl sub_0800F328
	ldr r0, [r5, #0x00]
	lsls r0, r0, #0x1A
	lsrs r0, r0, #0x1E
	adds r4, r4, r0
	ldrb r0, [r4, #0x00]
	bl sub_08010E04
	add r0, sp, #0x008
	movs r1, #0x0F
	bl sub_08004238
	movs r4, #0x80
	lsls r4, r4, #0x13
	movs r1, #0xA8
	lsls r1, r1, #0x03
	adds r0, r1, #0x0
	strh r0, [r4, #0x00]
	bl sub_08000458
	movs r2, #0xAA
	lsls r2, r2, #0x05
	adds r0, r2, #0x0
	strh r0, [r4, #0x00]
	movs r7, #0x40
	str r7, [sp, #0x220]
	movs r4, #0x00
	ldr r3, _08011920 @ =0x020020AC
	ldrb r0, [r3, #0x00]
	cmp r4, r0
	bge _08011838
	add r2, sp, #0x20C
	movs r5, #0xFF
	.global _08011828
_08011828:
	adds r1, r2, r4
	ldrb r0, [r1, #0x00]
	orrs r0, r5
	strb r0, [r1, #0x00]
	adds r4, #0x01
	ldrb r1, [r3, #0x00]
	cmp r4, r1
	blt _08011828
	.global _08011838
_08011838:
	ldr r2, [sp, #0x220]
	cmp r2, #0x40
	beq _08011840
	b _08011A04
	.global _08011840
_08011840:
	movs r7, #0x82
	lsls r7, r7, #0x02
	add r7, sp
	mov r10, r7
	.global _08011848
_08011848:
	bl sub_08004484
	ldr r0, _08011924 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	add r0, r10
	ldrb r0, [r0, #0x00]
	bl sub_08010E04
	ldr r0, _08011920 @ =0x020020AC
	ldrb r2, [r0, #0x00]
	cmp r2, #0x00
	beq _08011874
	ldr r3, _08011928 @ =0x020020A0
	add r1, sp, #0x218
	adds r4, r2, #0x0
	.global _08011866
_08011866:
	ldrh r0, [r3, #0x00]
	strh r0, [r1, #0x00]
	adds r3, #0x02
	adds r1, #0x02
	subs r4, #0x01
	cmp r4, #0x00
	bne _08011866
	.global _08011874
_08011874:
	bl sub_08003330
	cmp r0, #0x00
	beq _0801187E
	b _08011A20
	.global _0801187E
_0801187E:
	movs r4, #0x00
	ldr r0, _08011920 @ =0x020020AC
	adds r1, r0, #0x0
	ldrb r1, [r1, #0x00]
	cmp r4, r1
	bge _0801194C
	movs r2, #0x01
	negs r2, r2
	mov r9, r2
	mov r7, r10
	.global _08011892
_08011892:
	add r0, sp, #0x210
	lsls r2, r4, #0x01
	adds r5, r0, r2
	ldr r1, _08011928 @ =0x020020A0
	adds r1, r2, r1
	add r0, sp, #0x218
	adds r0, r0, r2
	ldrh r2, [r1, #0x00]
	ldrh r0, [r0, #0x00]
	eors r2, r0
	adds r0, r2, #0x0
	ldrh r1, [r1, #0x00]
	ands r0, r1
	strh r0, [r5, #0x00]
	add r6, sp, #0x20C
	adds r0, r6, r4
	mov r8, r0
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r9
	bne _080118D6
	ldrh r0, [r5, #0x00]
	ldrb r1, [r7, #0x00]
	mov r2, r10
	str r2, [sp, #0x000]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x004]
	movs r2, #0x00
	movs r3, #0x1D
	bl sub_080116D4
	strb r0, [r7, #0x00]
	.global _080118D6
_080118D6:
	movs r0, #0x01
	ldrh r1, [r5, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080118E6
	ldrb r0, [r7, #0x00]
	mov r2, r8
	strb r0, [r2, #0x00]
	.global _080118E6
_080118E6:
	movs r0, #0x02
	ldrh r5, [r5, #0x00]
	ands r0, r5
	cmp r0, #0x00
	beq _0801193E
	cmp r4, #0x00
	bne _08011938
	ldrb r1, [r6, #0x00]
	movs r0, #0x00
	ldsb r0, [r6, r0]
	cmp r0, r9
	beq _0801192C
	movs r0, #0xFF
	strb r0, [r6, #0x00]
	b _0801193E
	.global _08011904
_08011904: .4byte 0xFFFFFDD8
	.global _08011908
_08011908: .4byte 0x0000020B
	.global _0801190C
_0801190C: .4byte 0x04000128
	.global _08011910
_08011910: .4byte 0x082B8710
	.global _08011914
_08011914: .4byte 0x06016000
	.global _08011918
_08011918: .4byte 0x020020C0
	.global _0801191C
_0801191C: .4byte 0x082E4328
	.global _08011920
_08011920: .4byte 0x020020AC
	.global _08011924
_08011924: .4byte 0x0202EF90
	.global _08011928
_08011928: .4byte 0x020020A0
	.global _0801192C
_0801192C:
	movs r7, #0xFE
	str r7, [sp, #0x220]
	ldr r0, _08011934 @ =0x020020AC
	b _0801194C
	.global _08011934
_08011934: .4byte 0x020020AC
	.global _08011938
_08011938:
	movs r0, #0xFF
	mov r1, r8
	strb r0, [r1, #0x00]
	.global _0801193E
_0801193E:
	adds r7, #0x01
	adds r4, #0x01
	ldr r0, _080119D0 @ =0x020020AC
	adds r2, r0, #0x0
	ldrb r2, [r2, #0x00]
	cmp r4, r2
	blt _08011892
	.global _0801194C
_0801194C:
	movs r7, #0x00
	movs r4, #0x00
	ldr r5, _080119D4 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r4, r0
	bge _0801197A
	add r2, sp, #0x20C
	movs r3, #0x01
	negs r3, r3
	ldr r0, _080119D0 @ =0x020020AC
	ldrb r1, [r0, #0x00]
	.global _08011962
_08011962:
	adds r0, r2, r4
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r3
	beq _08011974
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	.global _08011974
_08011974:
	adds r4, #0x01
	cmp r4, r1
	blt _08011962
	.global _0801197A
_0801197A:
	add r6, sp, #0x20C
	ldrb r5, [r5, #0x00]
	adds r0, r5, r6
	movs r1, #0x00
	ldsb r1, [r0, r1]
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	beq _080119DC
	movs r0, #0x58
	bl sub_08016558
	movs r1, #0x11
	movs r2, #0x01
	bl sub_08006950
	ldr r5, _080119D0 @ =0x020020AC
	ldrb r0, [r5, #0x00]
	cmp r7, r0
	bne _080119E6
	movs r4, #0x00
	cmp r4, r0
	bge _080119E6
	mov r8, r6
	ldr r3, _080119D8 @ =0x0202A550
	movs r6, #0xC8
	lsls r6, r6, #0x01
	.global _080119B0
_080119B0:
	mov r1, r8
	adds r0, r1, r4
	ldrb r1, [r0, #0x00]
	movs r7, #0xB1
	lsls r7, r7, #0x01
	adds r2, r3, r7
	strb r1, [r2, #0x00]
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x220]
	adds r3, r3, r6
	adds r4, #0x01
	ldrb r0, [r5, #0x00]
	cmp r4, r0
	blt _080119B0
	b _080119E6
	.byte 0x00, 0x00
	.global _080119D0
_080119D0: .4byte 0x020020AC
	.global _080119D4
_080119D4: .4byte 0x0202EF90
	.global _080119D8
_080119D8: .4byte 0x0202A550
	.global _080119DC
_080119DC:
	ldr r0, _08011A18 @ =0x0829F30C
	movs r1, #0x11
	movs r2, #0x01
	bl sub_08006950
	.global _080119E6
_080119E6:
	bl sub_080047DC
	ldr r1, _08011A1C @ =0x020020C0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r2, [sp, #0x220]
	lsls r1, r2, #0x18
	.global _080119F4
_080119F4:
	ldr r0, _08011A1C @ =0x020020C0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080119F4
	asrs r0, r1, #0x18
	cmp r0, #0x40
	bne _08011A04
	b _08011848
	.global _08011A04
_08011A04:
	ldr r7, [sp, #0x220]
	lsls r0, r7, #0x18
	asrs r1, r0, #0x18
	movs r0, #0x02
	negs r0, r0
	cmp r1, r0
	bne _08011A26
	.global _08011A12
_08011A12:
	adds r0, r1, #0x0
	b _08011A3C
	.byte 0x00, 0x00
	.global _08011A18
_08011A18: .4byte 0x0829F30C
	.global _08011A1C
_08011A1C: .4byte 0x020020C0
	.global _08011A20
_08011A20:
	movs r0, #0xFF
	str r0, [sp, #0x220]
	b _08011A04
	.global _08011A26
_08011A26:
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	beq _08011A12
	cmp r1, #0x00
	beq _08011A3A
	ldr r1, [sp, #0x224]
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	b _08011A3C
	.global _08011A3A
_08011A3A:
	movs r0, #0x00
	.global _08011A3C
_08011A3C:
	movs r3, #0x8A
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start sub_08011A50
sub_08011A50:
	push {r4, r5, r6, lr}
	ldr r0, _08011AE8 @ =0x04000134
	movs r1, #0x00
	strh r1, [r0, #0x00]
	subs r0, #0x0C
	strh r1, [r0, #0x00]
	movs r2, #0x00
	ldr r5, _08011AEC @ =0x0202EDBC
	ldr r6, _08011AF0 @ =0x0200216C
	ldr r4, _08011AF4 @ =0x0202EFA0
	movs r3, #0xFF
	.global _08011A66
_08011A66:
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
	bne _08011A66
	movs r0, #0x00
	str r0, [r5, #0x00]
	strh r0, [r6, #0x00]
	bl sub_08000370
	bl sub_0800F7E0
	ldr r2, _08011AF8 @ =0x04000200
	ldrh r0, [r2, #0x00]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r1, _08011AFC @ =0x04000128
	movs r0, #0x30
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08011AB2
	ldrh r0, [r2, #0x00]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2, #0x00]
	.global _08011AB2
_08011AB2:
	movs r2, #0x00
	ldr r6, _08011B00 @ =0x0202ED78
	movs r4, #0x00
	ldr r5, _08011B04 @ =0x0202EF40
	.global _08011ABA
_08011ABA:
	lsls r0, r2, #0x01
	adds r0, r0, r6
	strh r4, [r0, #0x00]
	movs r1, #0x00
	adds r3, r2, #0x1
	lsls r2, r2, #0x03
	.global _08011AC6
_08011AC6:
	lsls r0, r1, #0x01
	adds r0, r0, r2
	adds r0, r0, r5
	strh r4, [r0, #0x00]
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x03
	bls _08011AC6
	lsls r0, r3, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x03
	bls _08011ABA
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08011AE8
_08011AE8: .4byte 0x04000134
	.global _08011AEC
_08011AEC: .4byte 0x0202EDBC
	.global _08011AF0
_08011AF0: .4byte 0x0200216C
	.global _08011AF4
_08011AF4: .4byte 0x0202EFA0
	.global _08011AF8
_08011AF8: .4byte 0x04000200
	.global _08011AFC
_08011AFC: .4byte 0x04000128
	.global _08011B00
_08011B00: .4byte 0x0202ED78
	.global _08011B04
_08011B04: .4byte 0x0202EF40
	thumb_func_start sub_08011B08
sub_08011B08:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	bl sub_08011A50
	movs r0, #0x00
	mov r8, r0
	ldr r1, _08011B34 @ =0x0202ED78
	mov r10, r1
	movs r2, #0xFF
	mov r9, r2
	.global _08011B22
_08011B22:
	ldr r1, _08011B38 @ =0x04000128
	movs r0, #0x30
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08011B3C
	bl sub_08016E30
	b _08011B44
	.global _08011B34
_08011B34: .4byte 0x0202ED78
	.global _08011B38
_08011B38: .4byte 0x04000128
	.global _08011B3C
_08011B3C:
	movs r0, #0x01
	movs r1, #0x80
	bl sub_08016E14
	.global _08011B44
_08011B44:
	bl sub_0800048C
	ldr r7, _08011C28 @ =0x04000128
	ldr r1, [r7, #0x00]
	lsls r1, r1, #0x1A
	lsrs r1, r1, #0x1E
	adds r1, #0x01
	lsls r1, r1, #0x0C
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r0, r3, #0x0
	orrs r1, r0
	ldr r6, _08011C2C @ =0x0202EDD0
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	mov r2, r9
	ands r0, r2
	orrs r1, r0
	mov r3, r10
	strh r1, [r3, #0x00]
	ldrh r0, [r3, #0x00]
	bl sub_0800F818
	ldr r2, _08011C30 @ =0x0202EFA0
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
	ldr r5, _08011C34 @ =0x0202EEF4
	movs r0, #0x00
	strb r0, [r5, #0x00]
	ldr r4, _08011C38 @ =0x0202EF40
	ldrh r3, [r4, #0x00]
	lsrs r1, r3, #0x0C
	cmp r1, #0x01
	bne _08011BDA
	strb r1, [r2, #0x02]
	strb r1, [r5, #0x00]
	movs r0, #0x30
	ldrb r7, [r7, #0x00]
	ands r0, r7
	cmp r0, #0x00
	beq _08011BB6
	subs r0, r3, #0x1
	strb r0, [r6, #0x00]
	.global _08011BB6
_08011BB6:
	ldrh r3, [r4, #0x08]
	lsrs r0, r3, #0x0C
	cmp r0, #0x02
	bne _08011BDA
	strb r1, [r2, #0x06]
	strb r0, [r5, #0x00]
	ldrh r3, [r4, #0x10]
	lsrs r0, r3, #0x0C
	cmp r0, #0x03
	bne _08011BDA
	strb r1, [r2, #0x0A]
	strb r0, [r5, #0x00]
	ldrh r4, [r4, #0x18]
	lsrs r0, r4, #0x0C
	cmp r0, #0x04
	bne _08011BDA
	strb r1, [r2, #0x0E]
	strb r0, [r5, #0x00]
	.global _08011BDA
_08011BDA:
	ldr r1, _08011C3C @ =0x0202EF90
	ldr r0, _08011C28 @ =0x04000128
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x1A
	lsrs r0, r0, #0x1E
	strb r0, [r1, #0x00]
	ldr r1, _08011C40 @ =0x020020AC
	ldr r0, _08011C34 @ =0x0202EEF4
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _08011C00
	mov r0, r8
	subs r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	.global _08011C00
_08011C00:
	ldr r1, _08011C38 @ =0x0202EF40
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
	bne _08011B22
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08011C28
_08011C28: .4byte 0x04000128
	.global _08011C2C
_08011C2C: .4byte 0x0202EDD0
	.global _08011C30
_08011C30: .4byte 0x0202EFA0
	.global _08011C34
_08011C34: .4byte 0x0202EEF4
	.global _08011C38
_08011C38: .4byte 0x0202EF40
	.global _08011C3C
_08011C3C: .4byte 0x0202EF90
	.global _08011C40
_08011C40: .4byte 0x020020AC
	thumb_func_start sub_08011C44
sub_08011C44:
	push {r4, r5, r6, lr}
	adds r3, r0, #0x0
	adds r4, r1, #0x0
	adds r6, r2, #0x0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r0, r3, #0x08
	subs r0, r0, r3
	movs r1, #0x64
	bl sub_08017230
	adds r5, r0, #0x0
	lsls r5, r5, #0x10
	lsls r0, r4, #0x08
	subs r0, r0, r4
	movs r1, #0x64
	bl sub_08017230
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsls r0, r6, #0x08
	subs r0, r0, r6
	movs r1, #0x64
	bl sub_08017230
	lsls r0, r0, #0x10
	lsrs r5, r5, #0x13
	lsrs r4, r4, #0x13
	lsrs r0, r0, #0x13
	lsls r0, r0, #0x0A
	lsls r4, r4, #0x05
	orrs r0, r4
	orrs r5, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r0, r5, #0x0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_08011C9C
sub_08011C9C:
	push {r4, r5, lr}
	adds r5, r1, #0x0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_08010664
	bl sub_0800F3A4
	ldr r0, _08011D24 @ =0x082A9730
	movs r2, #0x80
	lsls r2, r2, #0x01
	adds r1, r5, #0x0
	bl sub_08016E10
	ldr r4, _08011D28 @ =0x08332BC8
	movs r0, #0xF0
	lsls r0, r0, #0x01
	adds r1, r5, r0
	adds r0, r4, #0x0
	movs r2, #0x10
	bl sub_08016E10
	movs r2, #0xE0
	lsls r2, r2, #0x01
	adds r1, r5, r2
	adds r0, r4, #0x0
	movs r2, #0x10
	bl sub_08016E10
	movs r0, #0x34
	movs r1, #0x34
	movs r2, #0x34
	bl sub_08011C44
	movs r2, #0xEA
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	movs r0, #0x24
	movs r1, #0x24
	movs r2, #0x24
	bl sub_08011C44
	movs r2, #0xEB
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	movs r0, #0x0E
	movs r1, #0x0E
	movs r2, #0x0E
	bl sub_08011C44
	movs r2, #0xEC
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl sub_08011C44
	movs r2, #0xED
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08011D24
_08011D24: .4byte 0x082A9730
	.global _08011D28
_08011D28: .4byte 0x08332BC8
