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
	thumb_func_start sub_0800920C
sub_0800920C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x02C
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _08009284 @ =0x08364B08
	ldr r1, [r0, #0x00]
	movs r0, #0xA4
	lsls r0, r0, #0x02
	adds r5, r1, r0
	ldr r2, _08009288 @ =0x08335A8C
	ldr r3, _0800928C @ =0x08334DCC
	movs r4, #0xE6
	lsls r4, r4, #0x03
	adds r0, r3, r4
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r7, #0xE0
	lsls r7, r7, #0x08
	adds r4, r7, #0x0
	ldrh r0, [r0, #0x00]
	orrs r0, r4
	strh r0, [r5, #0x00]
	ldr r0, _08009290 @ =0x00000292
	adds r5, r1, r0
	movs r7, #0x00
	movs r1, #0x00
	mov r12, r1
	mov r10, r3
	ldr r0, _08009294 @ =0x00000742
	adds r0, r0, r3
	mov r9, r0
	ldr r1, _08009298 @ =0x00000732
	adds r1, r1, r3
	mov r8, r1
	.global _0800925A
_0800925A:
	adds r0, r7, #0x7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0x0
	cmp r6, r1
	bls _08009278
	mov r3, r9
	ldrh r3, [r3, #0x00]
	lsls r3, r3, #0x01
	str r3, [sp, #0x028]
	adds r0, r3, r2
	ldrh r0, [r0, #0x00]
	orrs r0, r4
	strh r0, [r5, #0x00]
	adds r5, #0x02
	.global _08009278
_08009278:
	cmp r6, r7
	bcs _0800929C
	mov r1, r8
	ldrh r1, [r1, #0x00]
	lsls r0, r1, #0x01
	b _080092B0
	.global _08009284
_08009284: .4byte 0x08364B08
	.global _08009288
_08009288: .4byte 0x08335A8C
	.global _0800928C
_0800928C: .4byte 0x08334DCC
	.global _08009290
_08009290: .4byte 0x00000292
	.global _08009294
_08009294: .4byte 0x00000742
	.global _08009298
_08009298: .4byte 0x00000732
	.global _0800929C
_0800929C:
	cmp r6, r1
	bhi _080092BA
	subs r0, r6, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	ldr r3, _080092FC @ =0x00000734
	adds r0, r0, r3
	add r0, r10
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
	.global _080092B0
_080092B0:
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	orrs r0, r4
	strh r0, [r5, #0x00]
	adds r5, #0x02
	.global _080092BA
_080092BA:
	adds r0, r7, #0x0
	adds r0, #0x08
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r0, r12
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r12, r0
	cmp r0, #0x0C
	bne _0800925A
	ldr r4, _08009300 @ =0x08334DCC
	ldr r7, _08009304 @ =0x00000744
	adds r0, r4, r7
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	ldr r0, _08009308 @ =0x08335A8C
	adds r1, r1, r0
	movs r2, #0xE0
	lsls r2, r2, #0x08
	adds r0, r2, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r5, #0x00]
	add sp, #0x02C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _080092FC
_080092FC: .4byte 0x00000734
	.global _08009300
_08009300: .4byte 0x08334DCC
	.global _08009304
_08009304: .4byte 0x00000744
	.global _08009308
_08009308: .4byte 0x08335A8C
	thumb_func_start sub_0800930C
sub_0800930C:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _08009334 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	beq _08009394
	ldr r1, _08009338 @ =0x00000175
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08009394
	ldr r0, _0800933C @ =0x0202A550
	cmp r4, r0
	bne _08009344
	ldr r1, _08009340 @ =0x0202CBD0
	movs r0, #0x01
	b _08009358
	.byte 0x00, 0x00
	.global _08009334
_08009334: .4byte 0x0200215C
	.global _08009338
_08009338: .4byte 0x00000175
	.global _0800933C
_0800933C: .4byte 0x0202A550
	.global _08009340
_08009340: .4byte 0x0202CBD0
	.global _08009344
_08009344:
	movs r0, #0xBC
	lsls r0, r0, #0x01
	adds r1, r4, r0
	adds r0, r4, #0x0
	adds r0, #0xF0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, _0800939C @ =0x0000018F
	adds r1, r4, r0
	movs r0, #0x01
	.global _08009358
_08009358:
	strb r0, [r1, #0x00]
	ldr r0, _080093A0 @ =0x00000175
	adds r1, r4, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _080093A4 @ =0x083681BC
	ldr r1, _080093A8 @ =0x020020CC
	ldrb r1, [r1, #0x00]
	adds r0, r1, r0
	ldrb r0, [r0, #0x00]
	lsls r1, r0, #0x08
	adds r0, r4, #0x0
	bl sub_0800BE00
	ldr r0, _080093AC @ =0x0202A550
	cmp r4, r0
	bne _08009386
	ldr r0, _080093B0 @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08009386
	bl sub_08008090
	.global _08009386
_08009386:
	ldr r1, _080093B4 @ =0x00000181
	adds r0, r4, r1
	strb r5, [r0, #0x00]
	ldr r0, _080093B8 @ =0x0202CBC8
	adds r0, r5, r0
	movs r1, #0x01
	strb r1, [r0, #0x00]
	.global _08009394
_08009394:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800939C
_0800939C: .4byte 0x0000018F
	.global _080093A0
_080093A0: .4byte 0x00000175
	.global _080093A4
_080093A4: .4byte 0x083681BC
	.global _080093A8
_080093A8: .4byte 0x020020CC
	.global _080093AC
_080093AC: .4byte 0x0202A550
	.global _080093B0
_080093B0: .4byte 0x0202EEB0
	.global _080093B4
_080093B4: .4byte 0x00000181
	.global _080093B8
_080093B8: .4byte 0x0202CBC8
	thumb_func_start sub_080093BC
sub_080093BC:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r0, _08009404 @ =0x0202CAD0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080093D6
	ldr r7, _08009408 @ =0x0202A550
	cmp r4, r7
	bne _080093EE
	bl sub_080080B4
	.global _080093D6
_080093D6:
	ldr r7, _08009408 @ =0x0202A550
	cmp r4, r7
	bne _080093EE
	ldr r0, _0800940C @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080093EE
	ldr r0, _08009410 @ =0x0806C918
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006418
	.global _080093EE
_080093EE:
	ldr r1, _08009414 @ =0x00000175
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x06
	bls _080093FA
	b _08009790
	.global _080093FA
_080093FA:
	lsls r0, r0, #0x02
	ldr r1, _08009418 @ =0x0800941C
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.global _08009404
_08009404: .4byte 0x0202CAD0
	.global _08009408
_08009408: .4byte 0x0202A550
	.global _0800940C
_0800940C: .4byte 0x0202EEB0
	.global _08009410
_08009410: .4byte 0x0806C918
	.global _08009414
_08009414: .4byte 0x00000175
	.global _08009418
_08009418: .4byte 0x0800941C
	.byte 0x90, 0x97, 0x00, 0x08, 0x38, 0x94, 0x00, 0x08, 0x38, 0x94, 0x00, 0x08, 0x38, 0x94, 0x00, 0x08
	.byte 0x42, 0x94, 0x00, 0x08, 0x64, 0x95, 0x00, 0x08, 0x10, 0x97, 0x00, 0x08, 0x20, 0x1C, 0x31, 0x1C
	.byte 0x03, 0xF0, 0x7A, 0xF8, 0xA6, 0xE1, 0x05, 0x48, 0x00, 0x78, 0x00, 0x28, 0x0C, 0xD1, 0x04, 0x48
	.byte 0x00, 0x78, 0x00, 0x28, 0x08, 0xD1, 0x03, 0x4A, 0xA1, 0x18, 0x11, 0xE0, 0xD0, 0xCA, 0x02, 0x02
	.byte 0x3C, 0xA5, 0x02, 0x02, 0x75, 0x01, 0x00, 0x00, 0x03, 0x48, 0x00, 0x78, 0x00, 0x28, 0x05, 0xD0
	.byte 0x20, 0x1C, 0x01, 0xF0, 0xA5, 0xF8, 0x05, 0xE0, 0xB0, 0xEE, 0x02, 0x02, 0x07, 0x4E, 0xA1, 0x19
	.byte 0x05, 0x20, 0x08, 0x70, 0x06, 0x48, 0x00, 0x78, 0x06, 0x4F, 0x00, 0x28, 0x0C, 0xD0, 0xBC, 0x42
	.byte 0x0A, 0xD1, 0x20, 0x1C, 0x01, 0xF0, 0x94, 0xF8, 0x7C, 0xE1, 0x00, 0x00, 0x75, 0x01, 0x00, 0x00
	.byte 0xD0, 0xCA, 0x02, 0x02, 0x50, 0xA5, 0x02, 0x02, 0xC2, 0x21, 0x49, 0x00, 0x60, 0x18, 0x00, 0x25
	.byte 0x05, 0x60, 0xC4, 0x22, 0x52, 0x00, 0xA3, 0x18, 0xC8, 0x20, 0xC0, 0x01, 0x18, 0x60, 0x11, 0x4E
	.byte 0xA1, 0x19, 0x05, 0x20, 0x08, 0x70, 0xBC, 0x42, 0x00, 0xD0, 0x63, 0xE1, 0x0E, 0x49, 0x0F, 0x4A
	.byte 0x16, 0x78, 0xB0, 0x00, 0x40, 0x18, 0x00, 0x68, 0x18, 0x60, 0x13, 0x1C, 0x0C, 0x4A, 0x58, 0x78
	.byte 0x02, 0x28, 0x00, 0xD1, 0x15, 0x60, 0x59, 0x78, 0x01, 0x29, 0x16, 0xD1, 0x20, 0x1C, 0x9C, 0x30
	.byte 0x01, 0x68, 0x82, 0x20, 0x00, 0x02, 0x81, 0x42, 0x0C, 0xDD, 0xB4, 0x20, 0x00, 0x02, 0x40, 0x1A
	.byte 0x0A, 0xE0, 0x00, 0x00, 0x75, 0x01, 0x00, 0x00, 0x24, 0x81, 0x36, 0x08, 0xC0, 0xCB, 0x02, 0x02
	.byte 0x20, 0xA5, 0x02, 0x02, 0xC8, 0x20, 0x80, 0x01, 0x10, 0x60, 0x58, 0x78, 0x00, 0x28, 0x06, 0xD1
	.byte 0x20, 0x1C, 0x9C, 0x30, 0x01, 0x68, 0xB4, 0x20, 0x00, 0x02, 0x40, 0x1A, 0x10, 0x60, 0xC4, 0x26
	.byte 0x76, 0x00, 0xA4, 0x19, 0x21, 0x68, 0x10, 0x68, 0x09, 0x18, 0x21, 0x60, 0x08, 0x4A, 0x9B, 0x78
	.byte 0x98, 0x00, 0x80, 0x18, 0x00, 0x68, 0x09, 0x18, 0x21, 0x60, 0x06, 0x4E, 0x09, 0x12, 0xC8, 0x25
	.byte 0xED, 0x01, 0x28, 0x1C, 0x0D, 0xF0, 0x6E, 0xFE, 0x30, 0x60, 0x25, 0x60, 0x1A, 0xE1, 0x00, 0x00
	.byte 0x34, 0x81, 0x36, 0x08, 0xE0, 0xCA, 0x02, 0x02, 0x11, 0x4D, 0x28, 0x78, 0x00, 0x28, 0x02, 0xD0
	.byte 0x20, 0x1C, 0x01, 0xF0, 0x25, 0xF8, 0xC2, 0x21, 0x49, 0x00, 0x60, 0x18, 0xC4, 0x22, 0x52, 0x00
	.byte 0xA1, 0x18, 0x02, 0x68, 0x08, 0x68, 0x0B, 0x4F, 0x82, 0x42, 0x08, 0xDA, 0xBC, 0x42, 0x03, 0xD1
	.byte 0x09, 0x48, 0x00, 0x78, 0x00, 0x28, 0x02, 0xD0, 0x28, 0x78, 0x00, 0x28, 0x1A, 0xD1, 0xBC, 0x42
	.byte 0x0C, 0xD1, 0xFF, 0xF7, 0x2B, 0xFE, 0xC1, 0x26, 0x76, 0x00, 0xA1, 0x19, 0x09, 0xE0, 0x00, 0x00
	.byte 0xB0, 0xEE, 0x02, 0x02, 0x50, 0xA5, 0x02, 0x02, 0x3C, 0xA5, 0x02, 0x02, 0xC1, 0x20, 0x40, 0x00
	.byte 0x21, 0x18, 0x01, 0x20, 0x08, 0x80, 0x02, 0x4A, 0xA1, 0x18, 0x06, 0x20, 0x08, 0x70, 0xE1, 0xE0
	.byte 0x75, 0x01, 0x00, 0x00, 0xBC, 0x42, 0x3C, 0xD1, 0x22, 0x48, 0x00, 0x78, 0x00, 0x28, 0x35, 0xD0
	.byte 0x21, 0x48, 0xC0, 0x78, 0x00, 0x28, 0x25, 0xD0, 0x20, 0x48, 0x00, 0x78, 0x00, 0x28, 0x21, 0xD1
	.byte 0x1F, 0x48, 0x00, 0x78, 0x00, 0x28, 0x1D, 0xD1, 0xF9, 0xF7, 0x02, 0xF8, 0x0F, 0x21, 0x01, 0x40
	.byte 0x0D, 0x29, 0x17, 0xD9, 0xF8, 0xF7, 0xFC, 0xFF, 0x03, 0x25, 0x05, 0x40, 0x00, 0x2D, 0x02, 0xD1
	.byte 0x19, 0x20, 0xF7, 0xF7, 0xFB, 0xFD, 0x01, 0x2D, 0x02, 0xD1, 0x1A, 0x20, 0xF7, 0xF7, 0xF6, 0xFD
	.byte 0x02, 0x2D, 0x02, 0xD1, 0x18, 0x20, 0xF7, 0xF7, 0xF1, 0xFD, 0x03, 0x2D, 0x02, 0xD1, 0x18, 0x20
	.byte 0xF7, 0xF7, 0xEC, 0xFD, 0xC2, 0x26, 0x76, 0x00, 0xA0, 0x19, 0x00, 0x68, 0x00, 0x12, 0x64, 0x21
	.byte 0x0D, 0xF0, 0x44, 0xFE, 0x00, 0x06, 0x00, 0x0E, 0xFF, 0xF7, 0xE2, 0xFD, 0x09, 0x4F, 0xBC, 0x42
	.byte 0x12, 0xD0, 0xC2, 0x20, 0x40, 0x00, 0x21, 0x18, 0x08, 0x68, 0x80, 0x22, 0x52, 0x00, 0x80, 0x18
	.byte 0x08, 0x60, 0x11, 0xE0, 0x3C, 0xA5, 0x02, 0x02, 0x00, 0xEF, 0x02, 0x02, 0xE0, 0x20, 0x00, 0x02
	.byte 0xE0, 0x21, 0x00, 0x02, 0x50, 0xA5, 0x02, 0x02, 0xC2, 0x26, 0x76, 0x00, 0xA2, 0x19, 0x17, 0x49
	.byte 0x10, 0x68, 0x09, 0x68, 0x40, 0x18, 0x10, 0x60, 0xBC, 0x42, 0x31, 0xD1, 0x14, 0x48, 0x00, 0x78
	.byte 0x00, 0x28, 0x00, 0xD1, 0x7E, 0xE0, 0x13, 0x49, 0x08, 0x68, 0x00, 0x28, 0x09, 0xDD, 0x12, 0x4A
	.byte 0x80, 0x18, 0x08, 0x60, 0x21, 0x1C, 0x9C, 0x31, 0x08, 0x68, 0x80, 0x26, 0x76, 0x00, 0x80, 0x19
	.byte 0x08, 0x60, 0x0E, 0x4A, 0x10, 0x78, 0x03, 0x28, 0x09, 0xD0, 0x20, 0x1C, 0x8C, 0x30, 0x00, 0x21
	.byte 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x93, 0x78
	.byte 0x00, 0x2B, 0x5F, 0xD1, 0x20, 0x1C, 0x88, 0x30, 0x03, 0x60, 0x5B, 0xE0, 0xE0, 0xCA, 0x02, 0x02
	.byte 0x3C, 0xA5, 0x02, 0x02, 0x20, 0xA5, 0x02, 0x02, 0x00, 0xFF, 0xFF, 0xFF, 0xC0, 0xCB, 0x02, 0x02
	.byte 0x21, 0x1C, 0x9C, 0x31, 0xB4, 0x20, 0x00, 0x02, 0x08, 0x60, 0x20, 0x1C, 0x8C, 0x30, 0x00, 0x21
	.byte 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x10, 0x38
	.byte 0x01, 0x60, 0x3F, 0xE0, 0xC1, 0x21, 0x49, 0x00, 0x60, 0x18, 0x05, 0x88, 0x00, 0x2D, 0x29, 0xD1
	.byte 0x0E, 0x4A, 0xA0, 0x18, 0x05, 0x70, 0x0E, 0x4E, 0xB4, 0x42, 0x09, 0xD0, 0x0A, 0x39, 0x60, 0x18
	.byte 0x01, 0x68, 0x20, 0x1C, 0x02, 0xF0, 0x66, 0xFB, 0x0A, 0x4A, 0xA1, 0x18, 0x01, 0x20, 0x08, 0x70
	.byte 0x09, 0x48, 0x0A, 0x4A, 0xA1, 0x18, 0x09, 0x78, 0x08, 0x18, 0x05, 0x70, 0xB4, 0x42, 0x21, 0xD1
	.byte 0x07, 0x48, 0x09, 0x21, 0x0A, 0x22, 0xFC, 0xF7, 0xA3, 0xFE, 0x1B, 0xE0, 0x75, 0x01, 0x00, 0x00
	.byte 0x50, 0xA5, 0x02, 0x02, 0x8F, 0x01, 0x00, 0x00, 0xC8, 0xCB, 0x02, 0x02, 0x81, 0x01, 0x00, 0x00
	.byte 0x24, 0xC9, 0x06, 0x08, 0x20, 0x1C, 0x31, 0x1C, 0x02, 0xF0, 0xDE, 0xFE, 0x07, 0x48, 0x84, 0x42
	.byte 0x08, 0xD1, 0x07, 0x48, 0x00, 0x78, 0x00, 0x28, 0x04, 0xD0, 0x06, 0x48, 0x0A, 0x21, 0x0A, 0x22
	.byte 0xFC, 0xF7, 0x86, 0xFE
	.global _08009790
_08009790:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x50, 0xA5, 0x02, 0x02, 0xB0, 0xEE, 0x02, 0x02, 0x34, 0xC9, 0x06, 0x08
	thumb_func_start sub_080097A4
sub_080097A4:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r5, r1, #0x0
	adds r4, r2, #0x0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, _08009854 @ =0x0200215C
	mov r9, r0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x04
	bne _080097CE
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x00
	strb r0, [r1, #0x00]
	.global _080097CE
_080097CE:
	movs r1, #0xC7
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r2, _08009858 @ =0x00000175
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	ldr r0, _0800985C @ =0x0202CAD0
	strb r1, [r0, #0x00]
	adds r2, #0x0B
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	subs r2, #0x0A
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	movs r0, #0xBE
	lsls r0, r0, #0x01
	adds r2, r5, r0
	ldr r0, _08009860 @ =0x020253B8
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	ldr r0, _08009864 @ =0x0202A51C
	strb r1, [r0, #0x00]
	movs r0, #0xB3
	lsls r0, r0, #0x01
	adds r2, r5, r0
	movs r0, #0x01
	strb r0, [r2, #0x00]
	ldr r2, _08009868 @ =0x00000167
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	str r4, [r5, #0x00]
	str r3, [r5, #0x08]
	movs r2, #0x00
	mov r3, sp
	ldrh r3, [r3, #0x24]
	strh r3, [r5, #0x34]
	str r1, [r5, #0x2C]
	str r1, [r5, #0x28]
	adds r0, r5, #0x0
	adds r0, #0x40
	strh r1, [r0, #0x00]
	subs r0, #0x02
	strb r2, [r0, #0x00]
	adds r0, #0x17
	strb r2, [r0, #0x00]
	subs r0, #0x08
	strb r2, [r0, #0x00]
	movs r1, #0xBA
	lsls r1, r1, #0x01
	adds r0, r5, r1
	strb r2, [r0, #0x00]
	mov r2, r9
	ldrb r2, [r2, #0x00]
	cmp r2, #0x04
	bne _08009870
	ldr r0, _0800986C @ =0x08367730
	mov r3, r8
	lsls r1, r3, #0x01
	add r1, r8
	b _0800987A
	.byte 0x00, 0x00
	.global _08009854
_08009854: .4byte 0x0200215C
	.global _08009858
_08009858: .4byte 0x00000175
	.global _0800985C
_0800985C: .4byte 0x0202CAD0
	.global _08009860
_08009860: .4byte 0x020253B8
	.global _08009864
_08009864: .4byte 0x0202A51C
	.global _08009868
_08009868: .4byte 0x00000167
	.global _0800986C
_0800986C: .4byte 0x08367730
	.global _08009870
_08009870:
	ldr r0, _08009988 @ =0x08367730
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldrb r1, [r1, #0x00]
	.global _0800987A
_0800987A:
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	str r0, [r5, #0x58]
	adds r0, r5, #0x0
	adds r0, #0x7C
	movs r1, #0x00
	strb r1, [r0, #0x00]
	adds r2, r5, #0x0
	adds r2, #0x84
	movs r0, #0x01
	strb r0, [r2, #0x00]
	str r1, [r5, #0x30]
	adds r0, r5, #0x0
	adds r0, #0x88
	str r1, [r0, #0x00]
	adds r0, #0x1A
	strh r1, [r0, #0x00]
	subs r0, #0x16
	str r1, [r0, #0x00]
	adds r0, #0x04
	str r1, [r0, #0x00]
	adds r0, #0x04
	str r1, [r0, #0x00]
	adds r0, #0x04
	str r1, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x9C
	movs r0, #0xB4
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	mov r3, r9
	ldrb r3, [r3, #0x00]
	cmp r3, #0x0F
	bne _080098D4
	ldr r0, _0800998C @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _080098D4
	ldr r0, _08009990 @ =0x0202A550
	cmp r5, r0
	bne _080098D4
	movs r0, #0xA0
	lsls r0, r0, #0x07
	str r0, [r1, #0x00]
	.global _080098D4
_080098D4:
	ldr r4, _08009994 @ =0x0200215C
	ldrb r0, [r4, #0x00]
	cmp r0, #0x04
	beq _080098E4
	adds r0, r5, #0x0
	mov r1, r8
	bl sub_0800C0E8
	.global _080098E4
_080098E4:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x05
	beq _080098F8
	cmp r0, #0x11
	beq _080098F8
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x00
	str r0, [r1, #0x00]
	.global _080098F8
_080098F8:
	movs r3, #0xB8
	lsls r3, r3, #0x01
	adds r0, r5, r3
	movs r4, #0x00
	strb r4, [r0, #0x00]
	ldr r0, _08009998 @ =0x00000171
	adds r6, r5, r0
	strb r4, [r6, #0x00]
	movs r1, #0xB9
	lsls r1, r1, #0x01
	adds r0, r5, r1
	strb r4, [r0, #0x00]
	movs r2, #0x94
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r1, [sp, #0x024]
	bl sub_0800C984
	movs r3, #0x9A
	lsls r3, r3, #0x01
	adds r0, r5, r3
	str r4, [r0, #0x00]
	movs r0, #0x9C
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x01
	negs r0, r0
	str r0, [r1, #0x00]
	ldr r1, _0800999C @ =0x00000173
	adds r0, r5, r1
	strb r4, [r0, #0x00]
	strb r4, [r6, #0x00]
	movs r1, #0x00
	adds r2, r5, #0x0
	adds r2, #0x4C
	adds r6, r5, #0x0
	adds r6, #0xE4
	adds r7, r5, #0x0
	adds r7, #0xE8
	movs r3, #0xEC
	adds r3, r3, r5
	mov r12, r3
	movs r0, #0x7D
	adds r0, r0, r5
	mov r10, r0
	adds r3, r5, #0x0
	adds r3, #0x4E
	str r3, [sp, #0x000]
	ldr r4, _080099A0 @ =0x0202CBC8
	movs r3, #0x00
	.global _0800995C
_0800995C:
	adds r0, r1, r4
	strb r3, [r0, #0x00]
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x08
	bne _0800995C
	ldr r0, _08009994 @ =0x0200215C
	mov r9, r0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0F
	bne _08009A14
	ldr r0, _0800998C @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0F
	bhi _08009A14
	lsls r0, r0, #0x02
	ldr r1, _080099A4 @ =0x080099A8
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
	.global _08009988
_08009988: .4byte 0x08367730
	.global _0800998C
_0800998C: .4byte 0x0202ED70
	.global _08009990
_08009990: .4byte 0x0202A550
	.global _08009994
_08009994: .4byte 0x0200215C
	.global _08009998
_08009998: .4byte 0x00000171
	.global _0800999C
_0800999C: .4byte 0x00000173
	.global _080099A0
_080099A0: .4byte 0x0202CBC8
	.global _080099A4
_080099A4: .4byte 0x080099A8
	.byte 0xE8, 0x99, 0x00, 0x08, 0xEC, 0x99, 0x00, 0x08, 0xF0, 0x99, 0x00, 0x08, 0xF4, 0x99, 0x00, 0x08
	.byte 0x14, 0x9A, 0x00, 0x08, 0x14, 0x9A, 0x00, 0x08, 0xF8, 0x99, 0x00, 0x08, 0x14, 0x9A, 0x00, 0x08
	.byte 0x14, 0x9A, 0x00, 0x08, 0x14, 0x9A, 0x00, 0x08, 0xFC, 0x99, 0x00, 0x08, 0x00, 0x9A, 0x00, 0x08
	.byte 0x04, 0x9A, 0x00, 0x08, 0x08, 0x9A, 0x00, 0x08, 0x0C, 0x9A, 0x00, 0x08, 0x10, 0x9A, 0x00, 0x08
	.byte 0x01, 0x20, 0x14, 0xE0, 0x04, 0x20, 0x12, 0xE0, 0x05, 0x20, 0x10, 0xE0, 0x28, 0x20, 0x0E, 0xE0
	.byte 0x28, 0x20, 0x0C, 0xE0, 0x0F, 0x20, 0x0A, 0xE0, 0x0F, 0x20, 0x08, 0xE0, 0x55, 0x20, 0x06, 0xE0
	.byte 0x12, 0x20, 0x04, 0xE0, 0x05, 0x20, 0x02, 0xE0, 0x14, 0x20, 0x00, 0xE0
	.global _08009A14
_08009A14:
	movs r0, #0x00
	strb r0, [r2, #0x00]
	mov r1, r9
	ldrb r0, [r1, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bls _08009A2C
	ldrb r0, [r2, #0x00]
	subs r0, #0x01
	strb r0, [r2, #0x00]
	.global _08009A2C
_08009A2C:
	movs r1, #0x00
	str r1, [r5, #0x50]
	movs r3, #0xAE
	lsls r3, r3, #0x01
	adds r2, r5, r3
	movs r0, #0x96
	lsls r0, r0, #0x01
	str r0, [r2, #0x00]
	str r1, [r5, #0x0C]
	str r1, [r5, #0x14]
	movs r2, #0x88
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	subs r3, #0x1C
	adds r0, r5, r3
	str r1, [r0, #0x00]
	adds r2, #0x34
	adds r0, r5, r2
	str r1, [r0, #0x00]
	subs r3, #0x04
	adds r0, r5, r3
	str r1, [r0, #0x00]
	adds r2, #0x04
	adds r0, r5, r2
	str r1, [r0, #0x00]
	adds r3, #0x10
	adds r0, r5, r3
	str r1, [r0, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x63
	strb r0, [r1, #0x00]
	ldr r4, _08009B00 @ =0x08367FBC
	adds r2, #0x1A
	adds r1, r5, r2
	ldrb r3, [r1, #0x00]
	lsls r0, r3, #0x02
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x00]
	ldr r3, _08009B04 @ =0x08368034
	ldrb r2, [r1, #0x00]
	lsls r0, r2, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x00]
	ldr r2, _08009B08 @ =0x083680AC
	ldrb r1, [r1, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	mov r1, r12
	str r0, [r1, #0x00]
	ldr r0, _08009B0C @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08009ACA
	mov r0, r8
	cmp r0, #0x00
	beq _08009ACA
	mov r1, r9
	ldrb r1, [r1, #0x00]
	cmp r1, #0x02
	beq _08009ACA
	ldr r0, _08009B10 @ =0x08367BFA
	str r0, [r6, #0x00]
	ldr r0, _08009B14 @ =0x08367C06
	str r0, [r7, #0x00]
	ldr r0, _08009B18 @ =0x08367C10
	mov r1, r12
	str r0, [r1, #0x00]
	ldr r0, [r4, #0x00]
	str r0, [r6, #0x00]
	ldr r0, [r3, #0x00]
	str r0, [r7, #0x00]
	ldr r0, [r2, #0x00]
	str r0, [r1, #0x00]
	.global _08009ACA
_08009ACA:
	movs r2, #0xAC
	lsls r2, r2, #0x01
	adds r0, r5, r2
	movs r1, #0x00
	str r1, [r0, #0x00]
	mov r3, r10
	strb r1, [r3, #0x00]
	movs r2, #0x00
	mov r0, sp
	ldrh r0, [r0, #0x24]
	strh r0, [r5, #0x36]
	strh r1, [r5, #0x38]
	movs r3, #0xB0
	lsls r3, r3, #0x01
	adds r0, r5, r3
	strh r1, [r0, #0x00]
	ldr r0, [sp, #0x000]
	strb r2, [r0, #0x00]
	strh r1, [r5, #0x3C]
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08009B00
_08009B00: .4byte 0x08367FBC
	.global _08009B04
_08009B04: .4byte 0x08368034
	.global _08009B08
_08009B08: .4byte 0x083680AC
	.global _08009B0C
_08009B0C: .4byte 0x020020DC
	.global _08009B10
_08009B10: .4byte 0x08367BFA
	.global _08009B14
_08009B14: .4byte 0x08367C06
	.global _08009B18
_08009B18: .4byte 0x08367C10
	.byte 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_08009B20
sub_08009B20:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _08009B94 @ =0x02002090
	ldrb r5, [r0, #0x00]
	ldr r0, _08009B98 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08009B3A
	ldr r0, _08009B9C @ =0x020020AC
	ldrb r5, [r0, #0x00]
	.global _08009B3A
_08009B3A:
	movs r6, #0x00
	ldr r0, _08009BA0 @ =0x0202A550
	lsls r2, r4, #0x01
	adds r1, r2, r4
	lsls r1, r1, #0x03
	adds r1, r1, r4
	lsls r1, r1, #0x04
	adds r7, r0, #0x0
	adds r7, #0x50
	adds r1, r1, r7
	ldr r1, [r1, #0x00]
	mov r12, r1
	movs r3, #0x00
	mov r8, r0
	cmp r6, r5
	beq _08009B78
	adds r1, r7, #0x0
	movs r7, #0xC8
	lsls r7, r7, #0x01
	.global _08009B60
_08009B60:
	cmp r3, r4
	beq _08009B70
	ldr r0, [r1, #0x00]
	cmp r0, r12
	ble _08009B70
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	.global _08009B70
_08009B70:
	adds r1, r1, r7
	adds r3, #0x01
	cmp r3, r5
	bne _08009B60
	.global _08009B78
_08009B78:
	adds r0, r2, r4
	lsls r0, r0, #0x03
	adds r0, r0, r4
	lsls r0, r0, #0x04
	add r0, r8
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r0, r1
	strb r6, [r0, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08009B94
_08009B94: .4byte 0x02002090
	.global _08009B98
_08009B98: .4byte 0x020020DC
	.global _08009B9C
_08009B9C: .4byte 0x020020AC
	.global _08009BA0
_08009BA0: .4byte 0x0202A550
	.byte 0xC3, 0x0F, 0xC0, 0x18, 0x40, 0x10, 0x0B, 0x18, 0x09, 0x1A, 0x13, 0x60, 0x51, 0x60, 0x70, 0x47
	thumb_func_start sub_08009BB4
sub_08009BB4:
	push {r4, lr}
	adds r4, r2, #0x0
	ldr r3, _08009BF0 @ =0x02002100
	ldr r2, [r3, #0x00]
	subs r0, r0, r2
	ldr r2, [r3, #0x04]
	subs r1, r1, r2
	subs r2, r0, r1
	lsls r2, r2, #0x01
	adds r0, r0, r1
	movs r1, #0xF1
	lsls r1, r1, #0x10
	adds r2, r2, r1
	movs r1, #0xA1
	lsls r1, r1, #0x10
	adds r3, r0, r1
	asrs r2, r2, #0x11
	asrs r3, r3, #0x11
	adds r1, r2, #0x0
	adds r1, #0x18
	movs r0, #0x90
	lsls r0, r0, #0x01
	cmp r1, r0
	bhi _08009BEC
	adds r0, r3, #0x0
	adds r0, #0x20
	cmp r0, #0xD0
	bls _08009BF4
	.global _08009BEC
_08009BEC:
	movs r0, #0x00
	b _08009BF8
	.global _08009BF0
_08009BF0: .4byte 0x02002100
	.global _08009BF4
_08009BF4:
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
	.global _08009BF8
_08009BF8:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x10, 0xB5, 0x14, 0x1C, 0x0D, 0x4B, 0x1A, 0x68, 0x80, 0x1A, 0x5A, 0x68, 0x89, 0x1A
	.byte 0x42, 0x1A, 0x52, 0x00, 0x40, 0x18, 0xF1, 0x21, 0x09, 0x04, 0x52, 0x18, 0xA1, 0x21, 0x09, 0x04
	.byte 0x43, 0x18, 0x52, 0x14, 0x5B, 0x14, 0x11, 0x1C, 0x10, 0x31, 0x88, 0x20, 0x40, 0x00, 0x81, 0x42
	.byte 0x03, 0xD8, 0x18, 0x1C, 0x20, 0x30, 0xC0, 0x28, 0x03, 0xD9, 0x00, 0x20, 0x03, 0xE0, 0x00, 0x21
	.byte 0x00, 0x02, 0x22, 0x60, 0x63, 0x60, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	thumb_func_start sub_08009C4C
sub_08009C4C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r6, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r10, r1
	ldr r0, [r6, #0x00]
	ldr r1, [r6, #0x08]
	mov r2, sp
	bl sub_08009BB4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08009C72
	b _08009F2A
	.global _08009C72
_08009C72:
	ldr r1, [sp, #0x004]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	ldr r0, [sp, #0x000]
	subs r0, #0x18
	str r0, [sp, #0x000]
	subs r1, #0x10
	str r1, [sp, #0x004]
	adds r0, r6, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08009CA4
	ldr r0, _08009CF4 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08009CA4
	ldr r0, _08009CF8 @ =0x0200209C
	ldr r0, [r0, #0x00]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _08009CA4
	b _08009F2A
	.global _08009CA4
_08009CA4:
	ldrh r1, [r6, #0x34]
	movs r2, #0x80
	lsls r2, r2, #0x02
	adds r0, r1, r2
	asrs r4, r0, #0x0A
	adds r4, #0x28
	movs r0, #0x3F
	ands r4, r0
	movs r1, #0x20
	adds r0, r4, #0x0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r0, #0x1F
	ands r4, r0
	cmp r7, #0x00
	beq _08009CCA
	movs r0, #0x20
	subs r4, r0, r4
	.global _08009CCA
_08009CCA:
	ldr r1, _08009CFC @ =0x08367730
	movs r3, #0xB1
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl sub_08007714
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x0C
	movs r1, #0xB9
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08009D00
	movs r0, #0x80
	lsls r0, r0, #0x04
	b _08009D04
	.global _08009CF4
_08009CF4: .4byte 0x020020DC
	.global _08009CF8
_08009CF8: .4byte 0x0200209C
	.global _08009CFC
_08009CFC: .4byte 0x08367730
	.global _08009D00
_08009D00:
	movs r0, #0x80
	lsls r0, r0, #0x03
	.global _08009D04
_08009D04:
	orrs r5, r0
	cmp r7, #0x00
	bne _08009DA0
	ldr r1, _08009D90 @ =0x08367640
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r7, r6, r2
	ldrb r3, [r7, #0x00]
	lsls r0, r3, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	lsls r4, r4, #0x02
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	bl sub_080075E4
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _08009D4E
	ldr r0, [sp, #0x004]
	movs r1, #0xFF
	ands r0, r1
	ldr r1, [sp, #0x000]
	ldr r2, _08009D94 @ =0x000001FF
	ands r1, r2
	lsls r1, r1, #0x10
	orrs r0, r1
	ldr r1, _08009D98 @ =0x80008000
	orrs r0, r1
	ldr r1, [r3, #0x10]
	orrs r1, r5
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl sub_080044DC
	.global _08009D4E
_08009D4E:
	ldr r1, _08009D9C @ =0x083676B8
	ldrb r7, [r7, #0x00]
	lsls r0, r7, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	bl sub_0800754C
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _08009E38
	ldr r0, [sp, #0x004]
	movs r1, #0xFF
	ands r0, r1
	ldr r1, [sp, #0x000]
	adds r1, #0x10
	ldr r2, _08009D94 @ =0x000001FF
	ands r1, r2
	lsls r1, r1, #0x10
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	ldr r1, [r3, #0x10]
	orrs r1, r5
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl sub_080044DC
	b _08009E38
	.global _08009D90
_08009D90: .4byte 0x08367640
	.global _08009D94
_08009D94: .4byte 0x000001FF
	.global _08009D98
_08009D98: .4byte 0x80008000
	.global _08009D9C
_08009D9C: .4byte 0x083676B8
	.global _08009DA0
_08009DA0:
	ldr r1, _08009EAC @ =0x083676B8
	movs r0, #0xB1
	lsls r0, r0, #0x01
	adds r0, r0, r6
	mov r8, r0
	ldrb r2, [r0, #0x00]
	lsls r0, r2, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	lsls r7, r4, #0x02
	adds r0, r7, r0
	ldr r0, [r0, #0x00]
	bl sub_0800754C
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _08009DF0
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	ldr r1, _08009EB0 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r4, r0
	ldr r1, [r3, #0x10]
	orrs r1, r5
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r4, r0
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	bl sub_080044DC
	.global _08009DF0
_08009DF0:
	ldr r1, _08009EB4 @ =0x08367640
	mov r3, r8
	ldrb r3, [r3, #0x00]
	lsls r0, r3, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	adds r0, r7, r0
	ldr r0, [r0, #0x00]
	bl sub_080075E4
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _08009E38
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	adds r0, #0x20
	ldr r1, _08009EB0 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	ldr r0, _08009EB8 @ =0x80008000
	orrs r4, r0
	ldr r1, [r3, #0x10]
	orrs r1, r5
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r4, r0
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	bl sub_080044DC
	.global _08009E38
_08009E38:
	ldr r0, _08009EBC @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08009ECC
	ldr r1, _08009EC0 @ =0x083681E8
	mov r2, r10
	lsls r0, r2, #0x02
	adds r0, r0, r1
	ldr r5, [r0, #0x00]
	ldr r0, _08009EC4 @ =0x0200209C
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x01
	movs r1, #0x07
	bl sub_080172C8
	lsls r0, r0, #0x02
	adds r5, r5, r0
	ldr r1, [sp, #0x004]
	subs r1, #0x0C
	str r1, [sp, #0x004]
	ldr r0, [sp, #0x000]
	adds r0, #0x10
	str r0, [sp, #0x000]
	movs r4, #0xFF
	ands r4, r1
	ldr r1, _08009EB0 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r4, r0
	ldr r0, [r5, #0x00]
	bl sub_08007630
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _08009F2A
	ldr r5, [r3, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x03
	orrs r5, r0
	ldr r0, _08009EC8 @ =0x08337C20
	bl sub_08007714
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	orrs r5, r0
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_080044DC
	b _08009F2A
	.byte 0x00, 0x00
	.global _08009EAC
_08009EAC: .4byte 0x083676B8
	.global _08009EB0
_08009EB0: .4byte 0x000001FF
	.global _08009EB4
_08009EB4: .4byte 0x08367640
	.global _08009EB8
_08009EB8: .4byte 0x80008000
	.global _08009EBC
_08009EBC: .4byte 0x020020DC
	.global _08009EC0
_08009EC0: .4byte 0x083681E8
	.global _08009EC4
_08009EC4: .4byte 0x0200209C
	.global _08009EC8
_08009EC8: .4byte 0x08337C20
	.global _08009ECC
_08009ECC:
	ldr r1, _08009F3C @ =0x083681F8
	movs r3, #0xB1
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r5, [r0, #0x00]
	ldr r1, [sp, #0x004]
	subs r1, #0x08
	str r1, [sp, #0x004]
	ldr r0, [sp, #0x000]
	adds r0, #0x10
	str r0, [sp, #0x000]
	movs r4, #0xFF
	ands r4, r1
	ldr r1, _08009F40 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x07
	orrs r4, r0
	ldr r0, [r5, #0x00]
	bl sub_08007598
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _08009F2A
	ldr r5, [r3, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x03
	orrs r5, r0
	ldr r0, _08009F44 @ =0x0831D0EC
	bl sub_08007714
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	orrs r5, r0
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_080044DC
	.global _08009F2A
_08009F2A:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08009F3C
_08009F3C: .4byte 0x083681F8
	.global _08009F40
_08009F40: .4byte 0x000001FF
	.global _08009F44
_08009F44: .4byte 0x0831D0EC
	thumb_func_start sub_08009F48
sub_08009F48:
	push {r4, r5, r6, lr}
	ldr r0, _08009F8C @ =0x02002090
	ldrb r5, [r0, #0x00]
	ldr r0, _08009F90 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08009F5A
	ldr r0, _08009F94 @ =0x020020AC
	ldrb r5, [r0, #0x00]
	.global _08009F5A
_08009F5A:
	ldr r6, _08009F98 @ =0x0202A550
	movs r4, #0x00
	cmp r4, r5
	beq _08009F84
	.global _08009F62
_08009F62:
	ldr r0, _08009F9C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _08009F6E
	cmp r4, #0x00
	bne _08009F78
	.global _08009F6E
_08009F6E:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0x0
	bl sub_08009C4C
	.global _08009F78
_08009F78:
	adds r4, #0x01
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r6, r6, r0
	cmp r4, r5
	bne _08009F62
	.global _08009F84
_08009F84:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08009F8C
_08009F8C: .4byte 0x02002090
	.global _08009F90
_08009F90: .4byte 0x020020DC
	.global _08009F94
_08009F94: .4byte 0x020020AC
	.global _08009F98
_08009F98: .4byte 0x0202A550
	.global _08009F9C
_08009F9C: .4byte 0x0200215C
	thumb_func_start sub_08009FA0
sub_08009FA0:
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, _08009FF8 @ =0x083681E8
	lsls r2, r2, #0x02
	adds r2, r2, r0
	ldr r4, [r2, #0x00]
	ldr r0, _08009FFC @ =0x0200209C
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x01
	movs r1, #0x07
	bl sub_080172C8
	lsls r0, r0, #0x02
	adds r4, r4, r0
	movs r0, #0xFF
	ands r6, r0
	ldr r0, _0800A000 @ =0x000001FF
	ands r0, r5
	lsls r0, r0, #0x10
	orrs r6, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r6, r0
	ldr r0, [r4, #0x00]
	bl sub_08007630
	cmp r0, #0x00
	beq _08009FF0
	ldr r4, [r0, #0x10]
	ldr r0, _0800A004 @ =0x08337C20
	bl sub_08007714
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	orrs r4, r0
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl sub_080044A4
	.global _08009FF0
_08009FF0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08009FF8
_08009FF8: .4byte 0x083681E8
	.global _08009FFC
_08009FFC: .4byte 0x0200209C
	.global _0800A000
_0800A000: .4byte 0x000001FF
	.global _0800A004
_0800A004: .4byte 0x08337C20
	.byte 0x10, 0xB5, 0x02, 0x9C, 0x8A, 0x42, 0x01, 0xDD, 0x20, 0x1C, 0x0B, 0xE0, 0x11, 0x1A, 0x00, 0x29
	.byte 0x07, 0xDB, 0x80, 0x20, 0xC0, 0x01, 0x40, 0x1A, 0x58, 0x43, 0x61, 0x43, 0x40, 0x18, 0x80, 0x13
	.byte 0x00, 0xE0, 0x18, 0x1C, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	thumb_func_start sub_0800A034
sub_0800A034:
	push {r4, r5, lr}
	movs r2, #0x00
	adds r0, #0xEC
	ldr r3, [r0, #0x00]
	ldr r5, _0800A06C @ =0xFFFFF82F
	ldr r4, _0800A070 @ =0x00002326
	.global _0800A040
_0800A040:
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	lsls r0, r2, #0x01
	adds r0, r0, r3
	ldrh r0, [r0, #0x00]
	negs r0, r0
	muls r0, r1
	asrs r0, r0, #0x08
	adds r0, r0, r5
	cmp r0, r4
	bls _0800A078
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x05
	bne _0800A040
	ldr r0, _0800A074 @ =0xFFFDB610
	cmp r1, r0
	bgt _0800A07C
	movs r0, #0x04
	b _0800A07E
	.global _0800A06C
_0800A06C: .4byte 0xFFFFF82F
	.global _0800A070
_0800A070: .4byte 0x00002326
	.global _0800A074
_0800A074: .4byte 0xFFFDB610
	.global _0800A078
_0800A078:
	adds r0, r2, #0x0
	b _0800A07E
	.global _0800A07C
_0800A07C:
	movs r0, #0x00
	.global _0800A07E
_0800A07E:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_start sub_0800A084
sub_0800A084:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x028
	adds r4, r0, #0x0
	mov r8, r1
	movs r7, #0x00
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0800A170
	ldr r0, _0800A114 @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A0BE
	ldr r1, _0800A118 @ =0x00000175
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800A0BE
	adds r1, r4, #0x0
	adds r1, #0x9C
	ldr r0, [r1, #0x00]
	subs r0, #0x0A
	str r0, [r1, #0x00]
	cmp r0, #0x00
	bge _0800A0BE
	str r7, [r1, #0x00]
	.global _0800A0BE
_0800A0BE:
	adds r0, r4, #0x0
	adds r0, #0xA2
	movs r1, #0x80
	lsls r1, r1, #0x01
	strh r1, [r0, #0x00]
	ldr r1, _0800A11C @ =0x0202A550
	mov r12, r0
	cmp r4, r1
	bne _0800A0E8
	subs r0, #0x06
	ldr r2, [r0, #0x00]
	cmp r2, #0x00
	bne _0800A0E8
	ldr r1, _0800A120 @ =0x0202A51C
	movs r0, #0x08
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _0800A0E8
	mov r3, r12
	strh r2, [r3, #0x00]
	.global _0800A0E8
_0800A0E8:
	ldr r0, _0800A124 @ =0x020020A8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A128
	adds r2, r4, #0x0
	adds r2, #0x3E
	movs r5, #0xE4
	adds r5, r5, r4
	mov r9, r5
	ldr r1, [r5, #0x00]
	ldrb r6, [r2, #0x00]
	lsls r0, r6, #0x01
	adds r0, r0, r1
	mov r1, r12
	ldrh r1, [r1, #0x00]
	ldrh r5, [r0, #0x00]
	adds r3, r1, #0x0
	muls r3, r5
	adds r0, r3, #0x0
	asrs r0, r0, #0x06
	b _0800A148
	.byte 0x00, 0x00
	.global _0800A114
_0800A114: .4byte 0x0202EEB0
	.global _0800A118
_0800A118: .4byte 0x00000175
	.global _0800A11C
_0800A11C: .4byte 0x0202A550
	.global _0800A120
_0800A120: .4byte 0x0202A51C
	.global _0800A124
_0800A124: .4byte 0x020020A8
	.global _0800A128
_0800A128:
	adds r2, r4, #0x0
	adds r2, #0x3E
	movs r6, #0xE4
	adds r6, r6, r4
	mov r9, r6
	ldr r1, [r6, #0x00]
	ldrb r3, [r2, #0x00]
	lsls r0, r3, #0x01
	adds r0, r0, r1
	mov r5, r12
	ldrh r5, [r5, #0x00]
	ldrh r1, [r0, #0x00]
	adds r6, r5, #0x0
	muls r6, r1
	adds r0, r6, #0x0
	asrs r0, r0, #0x08
	.global _0800A148
_0800A148:
	adds r7, r7, r0
	adds r6, r2, #0x0
	mov r3, r9
	ldr r0, [r4, #0x2C]
	adds r5, r4, #0x0
	adds r5, #0x40
	cmp r0, #0x00
	ble _0800A1D8
	ldr r0, [r3, #0x00]
	ldrb r2, [r6, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r0
	mov r3, r12
	ldrh r3, [r3, #0x00]
	ldrh r1, [r1, #0x00]
	adds r0, r3, #0x0
	muls r0, r1
	asrs r0, r0, #0x05
	adds r7, r7, r0
	b _0800A1D8
	.global _0800A170
_0800A170:
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	ble _0800A188
	movs r5, #0xA6
	lsls r5, r5, #0x01
	adds r1, r4, r5
	negs r0, r0
	asrs r0, r0, #0x02
	str r0, [r1, #0x00]
	adds r6, r4, #0x0
	adds r6, #0x3E
	b _0800A1C0
	.global _0800A188
_0800A188:
	adds r3, r4, #0x0
	adds r3, #0xA2
	ldrh r0, [r3, #0x00]
	cmp r0, #0x00
	beq _0800A1C6
	subs r0, #0x20
	strh r0, [r3, #0x00]
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, r1
	bls _0800A1A2
	strh r7, [r3, #0x00]
	.global _0800A1A2
_0800A1A2:
	adds r2, r4, #0x0
	adds r2, #0x3E
	adds r0, r4, #0x0
	adds r0, #0xE4
	ldr r1, [r0, #0x00]
	ldrb r6, [r2, #0x00]
	lsls r0, r6, #0x01
	adds r0, r0, r1
	ldrh r3, [r3, #0x00]
	ldrh r5, [r0, #0x00]
	adds r1, r3, #0x0
	muls r1, r5
	adds r0, r1, #0x0
	asrs r7, r0, #0x08
	adds r6, r2, #0x0
	.global _0800A1C0
_0800A1C0:
	adds r5, r4, #0x0
	adds r5, #0x40
	b _0800A1D8
	.global _0800A1C6
_0800A1C6:
	adds r1, r4, #0x0
	adds r1, #0x40
	ldrh r6, [r1, #0x00]
	lsls r0, r6, #0x02
	negs r0, r0
	asrs r7, r0, #0x10
	adds r6, r4, #0x0
	adds r6, #0x3E
	adds r5, r1, #0x0
	.global _0800A1D8
_0800A1D8:
	movs r0, #0x02
	mov r1, r8
	ands r0, r1
	cmp r0, #0x00
	beq _0800A244
	ldrh r2, [r5, #0x00]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x01
	negs r0, r0
	asrs r0, r0, #0x08
	adds r7, r7, r0
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r1, r4, r3
	ldr r0, [r1, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x09
	adds r0, r0, r2
	str r0, [r1, #0x00]
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	ble _0800A244
	ldr r0, _0800A228 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800A220
	ldr r0, _0800A22C @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A230
	adds r0, r4, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A230
	.global _0800A220
_0800A220:
	adds r0, r4, #0x0
	bl sub_0800A5BC
	b _0800A244
	.global _0800A228
_0800A228: .4byte 0x020021E0
	.global _0800A22C
_0800A22C: .4byte 0x020020DC
	.global _0800A230
_0800A230:
	ldr r0, [r4, #0x2C]
	movs r2, #0xFA
	lsls r2, r2, #0x0A
	cmp r0, r2
	ble _0800A244
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r1, r4, r3
	subs r0, r2, r0
	str r0, [r1, #0x00]
	.global _0800A244
_0800A244:
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	bge _0800A268
	ldrh r1, [r5, #0x00]
	adds r0, r1, r7
	ldr r2, _0800A264 @ =0x000032C8
	cmp r0, r2
	ble _0800A256
	subs r7, r2, r1
	.global _0800A256
_0800A256:
	adds r0, r1, r7
	cmp r0, #0x00
	bge _0800A25E
	negs r7, r1
	.global _0800A25E
_0800A25E:
	adds r0, r1, r7
	b _0800A26A
	.byte 0x00, 0x00
	.global _0800A264
_0800A264: .4byte 0x000032C8
	.global _0800A268
_0800A268:
	movs r0, #0x00
	.global _0800A26A
_0800A26A:
	strh r0, [r5, #0x00]
	ldr r1, [r4, #0x2C]
	cmp r1, #0x00
	bgt _0800A27E
	adds r0, r4, #0x0
	bl sub_0800A034
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	b _0800A280
	.global _0800A27E
_0800A27E:
	movs r3, #0x00
	.global _0800A280
_0800A280:
	movs r0, #0x9E
	lsls r0, r0, #0x01
	adds r0, r0, r4
	mov r8, r0
	adds r0, r4, #0x0
	adds r0, #0xE8
	ldr r1, [r0, #0x00]
	ldrb r2, [r6, #0x00]
	lsls r0, r2, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	negs r0, r0
	muls r0, r7
	negs r0, r0
	asrs r0, r0, #0x08
	mov r1, r8
	str r0, [r1, #0x00]
	ldr r2, [r4, #0x2C]
	cmp r2, #0x00
	bgt _0800A2C0
	adds r0, r4, #0x0
	adds r0, #0xEC
	ldr r1, [r0, #0x00]
	lsls r0, r3, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	negs r0, r0
	muls r0, r2
	asrs r0, r0, #0x08
	strh r0, [r5, #0x00]
	strb r3, [r6, #0x00]
	b _0800A2C6
	.global _0800A2C0
_0800A2C0:
	movs r0, #0x00
	strb r0, [r6, #0x00]
	strh r0, [r5, #0x00]
	.global _0800A2C6
_0800A2C6:
	add sp, #0x028
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start sub_0800A2D4
sub_0800A2D4:
	push {r4, r5, lr}
	ldrh r1, [r0, #0x34]
	lsrs r2, r1, #0x0B
	negs r2, r2
	movs r1, #0x1F
	ands r2, r1
	lsls r2, r2, #0x03
	ldr r3, _0800A30C @ =0x0801CD08
	lsls r1, r2, #0x01
	adds r1, r1, r3
	movs r5, #0x00
	ldsh r4, [r1, r5]
	adds r2, #0x40
	lsls r2, r2, #0x01
	adds r2, r2, r3
	movs r1, #0x00
	ldsh r3, [r2, r1]
	ldr r1, [r0, #0x0C]
	ldr r2, [r0, #0x14]
	muls r1, r4
	muls r2, r3
	adds r1, r1, r2
	asrs r1, r1, #0x08
	str r1, [r0, #0x2C]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800A30C
_0800A30C: .4byte 0x0801CD08
	thumb_func_start sub_0800A310
sub_0800A310:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	mov r12, r0
	ldrh r0, [r0, #0x34]
	lsrs r2, r0, #0x08
	ldr r0, _0800A42C @ =0x0801CD08
	lsls r1, r2, #0x01
	adds r1, r1, r0
	movs r4, #0x00
	ldsh r3, [r1, r4]
	mov r9, r3
	adds r1, r2, #0x0
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r0
	movs r2, #0x00
	ldsh r5, [r1, r2]
	mov r8, r5
	movs r7, #0x00
	ldr r3, _0800A430 @ =0x08368270
	mov r10, r3
	.global _0800A342
_0800A342:
	lsls r4, r7, #0x02
	mov r5, r10
	adds r5, #0x04
	mov r10, r5
	subs r5, #0x04
	ldm r5!, {r6}
	ldr r1, _0800A434 @ =0x08368280
	adds r0, r4, r1
	ldr r5, [r0, #0x00]
	mov r3, r12
	adds r3, #0xA4
	adds r3, r3, r4
	mov r0, r8
	muls r0, r6
	mov r1, r9
	muls r1, r5
	subs r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	mov r2, r12
	adds r2, #0xB4
	adds r2, r2, r4
	mov r0, r9
	muls r0, r6
	mov r1, r8
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r2, #0x00]
	ldr r0, [r3, #0x00]
	mov r4, r12
	ldr r1, [r4, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	ldr r0, [r2, #0x00]
	ldr r1, [r4, #0x08]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r7, #0x01
	cmp r7, #0x04
	bne _0800A342
	movs r5, #0x3C
	ldsh r0, [r4, r5]
	ldrh r1, [r4, #0x34]
	adds r0, r1, r0
	asrs r2, r0, #0x08
	movs r0, #0xFF
	ands r2, r0
	lsls r0, r2, #0x01
	ldr r3, _0800A42C @ =0x0801CD08
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r4, [r0, r5]
	mov r9, r4
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r2, #0x00
	ldsh r1, [r0, r2]
	mov r8, r1
	movs r7, #0x00
	movs r3, #0xC4
	add r3, r12
	mov r10, r3
	mov r4, r12
	adds r4, #0xD4
	ldr r5, _0800A430 @ =0x08368270
	str r5, [sp, #0x000]
	.global _0800A3CC
_0800A3CC:
	lsls r2, r7, #0x02
	ldr r0, [sp, #0x000]
	ldm r0!, {r6}
	str r0, [sp, #0x000]
	ldr r1, _0800A434 @ =0x08368280
	adds r0, r2, r1
	ldr r5, [r0, #0x00]
	mov r0, r10
	adds r3, r0, r2
	mov r0, r8
	muls r0, r6
	mov r1, r9
	muls r1, r5
	subs r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	adds r2, r4, r2
	mov r0, r9
	muls r0, r6
	mov r1, r8
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r2, #0x00]
	mov r5, r12
	ldr r1, [r5, #0x00]
	ldr r0, [r5, #0x0C]
	adds r1, r1, r0
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	ldr r1, [r5, #0x08]
	ldr r0, [r5, #0x14]
	adds r1, r1, r0
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r7, #0x01
	cmp r7, #0x04
	bne _0800A3CC
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800A42C
_0800A42C: .4byte 0x0801CD08
	.global _0800A430
_0800A430: .4byte 0x08368270
	.global _0800A434
_0800A434: .4byte 0x08368280
	thumb_func_start sub_0800A438
sub_0800A438:
	adds r2, r0, #0x0
	ldr r0, _0800A464 @ =0x02025260
	ldrh r1, [r0, #0x00]
	movs r3, #0x82
	lsls r3, r3, #0x01
	adds r0, r2, r3
	strh r1, [r0, #0x00]
	ldr r0, _0800A468 @ =0x02025220
	ldrh r0, [r0, #0x00]
	adds r3, #0x02
	adds r1, r2, r3
	strh r0, [r1, #0x00]
	ldr r0, _0800A46C @ =0x02025224
	ldrh r1, [r0, #0x00]
	adds r3, #0x02
	adds r0, r2, r3
	strh r1, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0x7D
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bx lr
	.global _0800A464
_0800A464: .4byte 0x02025260
	.global _0800A468
_0800A468: .4byte 0x02025220
	.global _0800A46C
_0800A46C: .4byte 0x02025224
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x10, 0xB5, 0x04, 0x1C, 0x88, 0x30, 0x00, 0x22
	.byte 0x02, 0x60, 0x21, 0x1C, 0x7C, 0x31, 0x02, 0x20, 0x08, 0x70, 0x04, 0x31, 0x01, 0x20, 0x08, 0x60
	.byte 0xB0, 0x21, 0x49, 0x00, 0x60, 0x18, 0x02, 0x80, 0x20, 0x1C, 0xA2, 0x30, 0x02, 0x80, 0x20, 0x1C
	.byte 0xFF, 0xF7, 0xE8, 0xFF, 0x08, 0x48, 0x84, 0x42, 0x0B, 0xD1, 0x08, 0x48, 0x00, 0x78, 0x00, 0x28
	.byte 0x07, 0xD1, 0x07, 0x49, 0x08, 0x68, 0x05, 0x30, 0x08, 0x60, 0x63, 0x28, 0x01, 0xDD, 0x63, 0x20
	.byte 0x08, 0x60, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x50, 0xA5, 0x02, 0x02, 0x5C, 0x21, 0x00, 0x02
	.byte 0x1C, 0x52, 0x02, 0x02, 0x30, 0xB5, 0x04, 0x1C, 0x0C, 0x48, 0x05, 0x1C, 0x28, 0x78, 0x0C, 0x48
	.byte 0x22, 0x8F, 0x51, 0x00, 0x89, 0x18, 0xC9, 0x00, 0x00, 0x68, 0x42, 0x18, 0x10, 0x68, 0x91, 0x68
	.byte 0x40, 0x18, 0xC0, 0x03, 0x20, 0x60, 0x50, 0x68, 0xD1, 0x68, 0x40, 0x18, 0xC0, 0x03, 0xA0, 0x60
	.byte 0x10, 0x8A, 0x01, 0x28, 0x06, 0xD1, 0x02, 0x48, 0x02, 0x68, 0x04, 0xE0, 0xCC, 0x20, 0x00, 0x02
	.byte 0xD0, 0x53, 0x02, 0x02, 0x18, 0x32, 0x10, 0x68, 0x91, 0x68, 0x40, 0x18, 0xC3, 0x03, 0x50, 0x68
	.byte 0xD1, 0x68, 0x40, 0x18, 0xC1, 0x03, 0x20, 0x68, 0x1B, 0x1A, 0xA0, 0x68, 0x09, 0x1A, 0x2D, 0x78
	.byte 0x07, 0x2D, 0x0B, 0xD0, 0x18, 0x11, 0x09, 0x11, 0x02, 0xF0, 0xEE, 0xFA, 0x00, 0x02, 0x02, 0x4A
	.byte 0x11, 0x1C, 0x09, 0x1A, 0xA1, 0x86, 0x03, 0xE0, 0x00, 0x84, 0xFF, 0xFF, 0xE0, 0x8E, 0xA0, 0x86
	.byte 0x00, 0x22, 0xA2, 0x87, 0x9E, 0x21, 0x49, 0x00, 0x60, 0x18, 0x02, 0x60, 0x0C, 0x31, 0x60, 0x18
	.byte 0x02, 0x60, 0xE2, 0x60, 0x62, 0x61, 0x96, 0x20, 0x40, 0x00, 0x21, 0x18, 0xA0, 0x8E, 0x08, 0x60
	.byte 0x94, 0x20, 0x40, 0x00, 0x21, 0x18, 0xA0, 0x8E, 0x08, 0x60, 0x98, 0x21, 0x49, 0x00, 0x60, 0x18
	.byte 0x02, 0x60, 0x21, 0x1C, 0x4E, 0x31, 0x01, 0x20, 0x08, 0x70, 0x07, 0x49, 0x23, 0x8F, 0x58, 0x00
	.byte 0xC0, 0x18, 0xC0, 0x00, 0x09, 0x68, 0x0A, 0x18, 0x12, 0x8A, 0x01, 0x2A, 0x06, 0xD1, 0x21, 0x1C
	.byte 0x4D, 0x31, 0x00, 0x20, 0x08, 0x70, 0x05, 0xE0, 0xD0, 0x53, 0x02, 0x02, 0x59, 0x1C, 0x20, 0x1C
	.byte 0x4D, 0x30, 0x01, 0x70, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	thumb_func_start sub_0800A5BC
sub_0800A5BC:
	push {r4, lr}
	adds r3, r0, #0x0
	movs r1, #0x00
	str r1, [r3, #0x0C]
	str r1, [r3, #0x14]
	movs r2, #0x00
	strh r1, [r3, #0x3C]
	movs r4, #0xA4
	lsls r4, r4, #0x01
	adds r0, r3, r4
	str r1, [r0, #0x00]
	adds r0, r3, #0x0
	adds r0, #0x40
	strh r1, [r0, #0x00]
	subs r0, #0x02
	strb r2, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x70, 0xB5, 0x03, 0x1C, 0x98, 0x8E, 0x01, 0x0A, 0x96, 0x20, 0x40, 0x00, 0x1E, 0x18
	.byte 0x30, 0x68, 0x02, 0x12, 0x0D, 0x1C, 0x30, 0x3D, 0x0C, 0x1C, 0x30, 0x34, 0x8A, 0x42, 0x08, 0xDD
	.byte 0x08, 0x1C, 0x80, 0x30, 0x82, 0x42, 0x04, 0xDA, 0xA2, 0x42, 0x09, 0xDD, 0x20, 0x02, 0x30, 0x60
	.byte 0x06, 0xE0, 0xAA, 0x42, 0x04, 0xDA, 0x96, 0x20, 0x40, 0x00, 0x19, 0x18, 0x28, 0x02, 0x08, 0x60
	.byte 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47
	thumb_func_start sub_0800A628
sub_0800A628:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r12, r0
	ldrh r1, [r0, #0x34]
	lsrs r0, r1, #0x0A
	lsls r0, r0, #0x10
	mov r9, r0
	lsrs r2, r0, #0x0E
	ldr r7, _0800A6D8 @ =0x0801CD08
	lsls r0, r2, #0x01
	adds r0, r0, r7
	movs r1, #0x00
	ldsh r3, [r0, r1]
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r7
	movs r1, #0x00
	ldsh r2, [r0, r1]
	ldr r1, _0800A6DC @ =0xFFFFFF00
	adds r0, r3, #0x0
	muls r0, r1
	negs r0, r0
	asrs r5, r0, #0x08
	adds r0, r2, #0x0
	muls r0, r1
	asrs r4, r0, #0x08
	movs r6, #0x96
	lsls r6, r6, #0x01
	add r6, r12
	ldr r0, [r6, #0x00]
	asrs r2, r0, #0x0A
	movs r0, #0x3F
	ands r2, r0
	lsls r2, r2, #0x02
	lsls r0, r2, #0x01
	adds r3, r0, r7
	movs r0, #0x00
	ldsh r3, [r3, r0]
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r2, r0, r7
	movs r0, #0x00
	ldsh r2, [r2, r0]
	adds r0, r3, #0x0
	muls r0, r1
	negs r0, r0
	asrs r0, r0, #0x08
	mov r8, r0
	adds r0, r2, #0x0
	muls r0, r1
	asrs r3, r0, #0x08
	mov r0, r8
	muls r0, r5
	adds r1, r4, #0x0
	muls r1, r3
	adds r0, r0, r1
	asrs r0, r0, #0x08
	cmp r0, #0x8D
	bgt _0800A6FA
	mov r1, r9
	lsrs r2, r1, #0x0E
	lsls r1, r2, #0x01
	adds r1, r1, r7
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r7
	movs r2, #0x00
	ldsh r5, [r0, r2]
	movs r0, #0x00
	ldsh r4, [r1, r0]
	mov r0, r8
	muls r0, r5
	adds r1, r4, #0x0
	muls r1, r3
	adds r0, r0, r1
	cmp r0, #0x00
	bge _0800A6E4
	mov r1, r12
	ldrh r1, [r1, #0x34]
	ldr r2, _0800A6E0 @ =0xFFFFD800
	adds r0, r1, r2
	b _0800A6EE
	.byte 0x00, 0x00
	.global _0800A6D8
_0800A6D8: .4byte 0x0801CD08
	.global _0800A6DC
_0800A6DC: .4byte 0xFFFFFF00
	.global _0800A6E0
_0800A6E0: .4byte 0xFFFFD800
	.global _0800A6E4
_0800A6E4:
	mov r3, r12
	ldrh r3, [r3, #0x34]
	movs r1, #0xA0
	lsls r1, r1, #0x06
	adds r0, r3, r1
	.global _0800A6EE
_0800A6EE:
	str r0, [r6, #0x00]
	movs r1, #0x96
	lsls r1, r1, #0x01
	add r1, r12
	ldrh r0, [r1, #0x00]
	str r0, [r1, #0x00]
	.global _0800A6FA
_0800A6FA:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start sub_0800A708
sub_0800A708:
	push {r4, r5, lr}
	adds r3, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	adds r1, r3, #0x0
	adds r1, #0x84
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _0800A770 @ =0x0202A550
	cmp r3, r0
	bne _0800A778
	ldr r0, [r3, #0x2C]
	cmp r0, #0x00
	ble _0800A778
	movs r0, #0x30
	ands r0, r4
	cmp r0, #0x00
	bne _0800A740
	movs r1, #0x96
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldr r1, [r0, #0x00]
	ldrh r2, [r3, #0x34]
	adds r1, r2, r1
	lsrs r2, r1, #0x1F
	adds r1, r1, r2
	asrs r1, r1, #0x01
	str r1, [r0, #0x00]
	.global _0800A740
_0800A740:
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0x00
	beq _0800A756
	movs r5, #0x96
	lsls r5, r5, #0x01
	adds r1, r3, r5
	ldrh r2, [r3, #0x34]
	ldr r5, _0800A774 @ =0xFFFFEC00
	adds r0, r2, r5
	str r0, [r1, #0x00]
	.global _0800A756
_0800A756:
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0x00
	beq _0800A804
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldrh r3, [r3, #0x34]
	movs r2, #0xA0
	lsls r2, r2, #0x05
	adds r0, r3, r2
	str r0, [r1, #0x00]
	b _0800A804
	.global _0800A770
_0800A770: .4byte 0x0202A550
	.global _0800A774
_0800A774: .4byte 0xFFFFEC00
	.global _0800A778
_0800A778:
	movs r0, #0x30
	ands r0, r4
	cmp r0, #0x00
	beq _0800A794
	movs r5, #0x88
	lsls r5, r5, #0x01
	adds r1, r3, r5
	ldrb r2, [r1, #0x00]
	movs r0, #0x00
	ldsb r0, [r1, r0]
	cmp r0, #0x00
	blt _0800A7A4
	adds r0, r2, #0x1
	b _0800A7A2
	.global _0800A794
_0800A794:
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0800A7A4
	subs r0, #0x01
	.global _0800A7A2
_0800A7A2:
	strb r0, [r1, #0x00]
	.global _0800A7A4
_0800A7A4:
	movs r2, #0x88
	lsls r2, r2, #0x01
	adds r1, r3, r2
	ldrb r5, [r1, #0x00]
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsrs r0, r0, #0x02
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r2, r0, r1
	ldr r0, [r3, #0x2C]
	negs r0, r0
	asrs r1, r0, #0x0C
	cmp r1, #0x00
	bge _0800A7C4
	movs r1, #0x00
	.global _0800A7C4
_0800A7C4:
	movs r0, #0xFF
	subs r1, r0, r1
	lsls r0, r1, #0x01
	adds r2, r2, r0
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0x00
	beq _0800A7E8
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldr r0, [r1, #0x00]
	subs r0, r0, r2
	str r0, [r1, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x84
	movs r0, #0x00
	b _0800A802
	.global _0800A7E8
_0800A7E8:
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0x00
	beq _0800A804
	movs r5, #0x96
	lsls r5, r5, #0x01
	adds r1, r3, r5
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x84
	movs r0, #0x02
	.global _0800A802
_0800A802:
	strb r0, [r1, #0x00]
	.global _0800A804
_0800A804:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start sub_0800A80C
sub_0800A80C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	movs r1, #0xA0
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r1, #0x00
	str r1, [r0, #0x00]
	movs r2, #0xA2
	lsls r2, r2, #0x01
	adds r0, r5, r2
	str r1, [r0, #0x00]
	adds r2, #0x04
	adds r0, r5, r2
	str r1, [r0, #0x00]
	adds r0, r5, #0x0
	bl sub_08007C44
	adds r1, r5, #0x0
	adds r1, #0x55
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0800A84C
	subs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0800A84C
_0800A84C:
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0x0
	bl sub_0800A708
	adds r0, r5, #0x0
	bl sub_0800A2D4
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl sub_0800A084
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_08008480
	movs r0, #0x00
	mov r9, r0
	adds r0, r5, #0x0
	bl sub_0800A310
	ldr r0, _0800A8F8 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x04
	beq _0800A886
	ldr r0, _0800A8FC @ =0x020020CC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0B
	bhi _0800A898
	.global _0800A886
_0800A886:
	ldr r1, _0800A900 @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800A8B4
	adds r0, r5, #0x0
	bl sub_0800D248
	mov r9, r0
	.global _0800A898
_0800A898:
	mov r2, r9
	cmp r2, #0x00
	beq _0800A8B4
	adds r0, r5, #0x0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	subs r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bhi _0800A8B4
	movs r0, #0x01
	negs r0, r0
	mov r9, r0
	.global _0800A8B4
_0800A8B4:
	ldr r0, [r5, #0x2C]
	asrs r0, r0, #0x06
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r4, r5, r1
	adds r1, r0, #0x0
	muls r1, r0
	str r1, [r4, #0x00]
	cmp r0, #0x00
	ble _0800A8CC
	negs r0, r1
	str r0, [r4, #0x00]
	.global _0800A8CC
_0800A8CC:
	ldr r0, _0800A904 @ =0x020020DC
	ldrb r1, [r0, #0x00]
	ldr r7, _0800A8F8 @ =0x0200215C
	mov r10, r0
	cmp r1, #0x00
	bne _0800A8E2
	ldrb r0, [r7, #0x00]
	cmp r0, #0x04
	beq _0800A8E2
	cmp r0, #0x03
	bne _0800A90C
	.global _0800A8E2
_0800A8E2:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r4, r5, r2
	ldr r0, [r4, #0x00]
	movs r1, #0xD7
	bl sub_08017230
	str r0, [r4, #0x00]
	ldr r0, _0800A908 @ =0x0202A550
	mov r8, r0
	b _0800A986
	.global _0800A8F8
_0800A8F8: .4byte 0x0200215C
	.global _0800A8FC
_0800A8FC: .4byte 0x020020CC
	.global _0800A900
_0800A900: .4byte 0x00000175
	.global _0800A904
_0800A904: .4byte 0x020020DC
	.global _0800A908
_0800A908: .4byte 0x0202A550
	.global _0800A90C
_0800A90C:
	ldr r1, _0800A944 @ =0x0202A550
	mov r8, r1
	cmp r5, r8
	beq _0800A92C
	cmp r0, #0x09
	beq _0800A92C
	cmp r0, #0x0D
	beq _0800A92C
	cmp r0, #0x0E
	beq _0800A92C
	cmp r0, #0x0F
	beq _0800A92C
	cmp r0, #0x11
	beq _0800A92C
	cmp r0, #0x04
	bne _0800A972
	.global _0800A92C
_0800A92C:
	movs r2, #0xB8
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A948
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r4, r5, r0
	ldr r0, [r4, #0x00]
	movs r1, #0xFA
	b _0800A980
	.global _0800A944
_0800A944: .4byte 0x0202A550
	.global _0800A948
_0800A948:
	ldr r1, _0800A960 @ =0x00000171
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A964
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r4, r5, r2
	ldr r0, [r4, #0x00]
	movs r1, #0x64
	b _0800A980
	.byte 0x00, 0x00
	.global _0800A960
_0800A960: .4byte 0x00000171
	.global _0800A964
_0800A964:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r4, r5, r0
	ldr r0, [r4, #0x00]
	movs r1, #0xF0
	lsls r1, r1, #0x01
	b _0800A980
	.global _0800A972
_0800A972:
	ldr r1, _0800AA80 @ =0x08368290
	ldr r0, _0800AA84 @ =0x020020CC
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	ldr r0, [r4, #0x00]
	.global _0800A980
_0800A980:
	bl sub_08017230
	str r0, [r4, #0x00]
	.global _0800A986
_0800A986:
	ldr r0, _0800AA88 @ =0x020020A8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A9A4
	ldrb r0, [r7, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bls _0800A9A4
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x00
	str r0, [r1, #0x00]
	.global _0800A9A4
_0800A9A4:
	cmp r5, r8
	beq _0800A9B0
	mov r1, r10
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0800AA0E
	.global _0800A9B0
_0800A9B0:
	ldr r0, _0800AA8C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _0800AA0E
	cmp r0, #0x0D
	beq _0800AA0E
	cmp r0, #0x0E
	beq _0800AA0E
	cmp r0, #0x0F
	beq _0800AA0E
	cmp r0, #0x11
	beq _0800AA0E
	adds r0, r5, #0x0
	bl sub_0800C164
	cmp r0, #0x00
	bne _0800A9DE
	movs r2, #0xBB
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AA0E
	.global _0800A9DE
_0800A9DE:
	movs r0, #0xBB
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0800A9EE
	subs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0800A9EE
_0800A9EE:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r2, r5, r1
	ldr r1, [r2, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	asrs r0, r0, #0x02
	str r0, [r2, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x00
	bl sub_0800B618
	adds r0, r6, #0x0
	movs r1, #0x01
	bl sub_0800B618
	.global _0800AA0E
_0800AA0E:
	ldr r0, _0800AA8C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	beq _0800AA1C
	adds r0, r5, #0x0
	bl sub_0800D684
	.global _0800AA1C
_0800AA1C:
	ldr r1, [r5, #0x50]
	movs r2, #0xC6
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strh r1, [r0, #0x00]
	.global _0800AA26
_0800AA26:
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_08006A34
	ldr r1, _0800AA90 @ =0x020020BC
	strb r0, [r1, #0x00]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0800AA26
	ldr r0, [r5, #0x00]
	ldr r1, [r5, #0x0C]
	adds r0, r0, r1
	str r0, [r5, #0x00]
	ldr r0, [r5, #0x08]
	ldr r1, [r5, #0x14]
	adds r0, r0, r1
	str r0, [r5, #0x08]
	ldrh r1, [r5, #0x34]
	ldrh r2, [r5, #0x3C]
	adds r0, r1, r2
	strh r0, [r5, #0x34]
	mov r0, r9
	cmp r0, #0x00
	beq _0800AB26
	ldr r0, _0800AA94 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800AAC4
	ldr r0, _0800AA98 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800AAC4
	ldr r0, _0800AA9C @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0800AAC4
	ldr r0, _0800AAA0 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800AAA8
	ldr r0, _0800AAA4 @ =0x0202A550
	cmp r5, r0
	beq _0800AABE
	b _0800AAC4
	.byte 0x00, 0x00
	.global _0800AA80
_0800AA80: .4byte 0x08368290
	.global _0800AA84
_0800AA84: .4byte 0x020020CC
	.global _0800AA88
_0800AA88: .4byte 0x020020A8
	.global _0800AA8C
_0800AA8C: .4byte 0x0200215C
	.global _0800AA90
_0800AA90: .4byte 0x020020BC
	.global _0800AA94
_0800AA94: .4byte 0x020020E0
	.global _0800AA98
_0800AA98: .4byte 0x020021E0
	.global _0800AA9C
_0800AA9C: .4byte 0x0202EF00
	.global _0800AAA0
_0800AAA0: .4byte 0x020020DC
	.global _0800AAA4
_0800AAA4: .4byte 0x0202A550
	.global _0800AAA8
_0800AAA8:
	ldr r0, _0800AB6C @ =0x0202EF90
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _0800AB70 @ =0x0202A550
	adds r0, r0, r1
	cmp r5, r0
	bne _0800AAC4
	.global _0800AABE
_0800AABE:
	movs r0, #0x12
	bl sub_08001208
	.global _0800AAC4
_0800AAC4:
	adds r0, r5, #0x0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	subs r0, #0x05
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _0800AAEA
	ldr r0, _0800AB74 @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AAEA
	adds r2, r5, #0x0
	adds r2, #0x88
	mov r0, r9
	asrs r1, r0, #0x0C
	ldr r0, [r2, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	.global _0800AAEA
_0800AAEA:
	adds r1, r5, #0x0
	adds r1, #0x55
	movs r0, #0x06
	strb r0, [r1, #0x00]
	adds r0, r5, #0x0
	bl sub_0800A2D4
	ldr r0, [r5, #0x2C]
	str r0, [r5, #0x48]
	cmp r0, #0x00
	ble _0800AB04
	movs r0, #0x00
	str r0, [r5, #0x48]
	.global _0800AB04
_0800AB04:
	ldr r0, [r5, #0x48]
	lsls r0, r0, #0x08
	adds r3, r5, #0x0
	adds r3, #0x3E
	adds r1, r5, #0x0
	adds r1, #0xE8
	ldr r2, [r1, #0x00]
	ldrb r3, [r3, #0x00]
	lsls r1, r3, #0x01
	adds r1, r1, r2
	ldrh r1, [r1, #0x00]
	negs r1, r1
	bl sub_08017230
	adds r1, r5, #0x0
	adds r1, #0x40
	strh r0, [r1, #0x00]
	.global _0800AB26
_0800AB26:
	movs r2, #0xA0
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r0, [r5, #0x0C]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	movs r0, #0xA2
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r0, [r5, #0x14]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x14]
	movs r1, #0xA4
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrh r0, [r0, #0x00]
	ldrh r2, [r5, #0x3C]
	adds r0, r0, r2
	strh r0, [r5, #0x3C]
	movs r0, #0x3C
	ldsh r1, [r5, r0]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	asrs r0, r0, #0x05
	strh r0, [r5, #0x3C]
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800AB6C
_0800AB6C: .4byte 0x0202EF90
	.global _0800AB70
_0800AB70: .4byte 0x0202A550
	.global _0800AB74
_0800AB74: .4byte 0x0202EEB0
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
	thumb_func_start sub_0800AD80
sub_0800AD80:
	push {r4, r5, r6, r7, lr}
	bl sub_0800048C
	ldr r5, _0800AE64 @ =0x0202A550
	ldr r0, _0800AE68 @ =0x02002090
	ldrb r7, [r0, #0x00]
	ldr r0, _0800AE6C @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800AD9C
	ldr r0, _0800AE70 @ =0x0200215C
	ldrb r1, [r0, #0x00]
	cmp r1, #0x04
	bne _0800ADA2
	.global _0800AD9C
_0800AD9C:
	ldr r0, _0800AE74 @ =0x020020AC
	ldrb r7, [r0, #0x00]
	ldr r0, _0800AE70 @ =0x0200215C
	.global _0800ADA2
_0800ADA2:
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _0800ADAA
	movs r7, #0x01
	.global _0800ADAA
_0800ADAA:
	ldr r1, _0800AE78 @ =0x0202A51C
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	movs r6, #0x00
	cmp r6, r7
	beq _0800AE5C
	movs r0, #0xC6
	lsls r0, r0, #0x01
	adds r4, r5, r0
	.global _0800ADBE
_0800ADBE:
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0x0
	bl sub_0800AB78
	ldr r1, _0800AE7C @ =0x083675F0
	ldr r0, _0800AE80 @ =0x020020CC
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r2, r0, r1
	ldrh r1, [r4, #0x00]
	ldrh r0, [r2, #0x00]
	cmp r1, r0
	bhi _0800AE1C
	ldr r0, [r5, #0x50]
	ldr r1, _0800AE84 @ =0x0000FFFF
	ands r0, r1
	ldrh r2, [r2, #0x00]
	cmp r0, r2
	bcc _0800AE1C
	adds r0, r5, #0x0
	bl sub_080079D0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800AE1C
	ldr r0, _0800AE64 @ =0x0202A550
	cmp r5, r0
	beq _0800AE4E
	ldr r0, _0800AE88 @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AE1C
	bl sub_080079AC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x63
	beq _0800AE1C
	bl sub_080079AC
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0x0
	bl sub_0800930C
	.global _0800AE1C
_0800AE1C:
	ldr r0, _0800AE64 @ =0x0202A550
	cmp r5, r0
	beq _0800AE4E
	ldr r1, _0800AE8C @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AE4E
	ldr r0, _0800AE90 @ =0x08367608
	ldr r1, _0800AE80 @ =0x020020CC
	ldrb r1, [r1, #0x00]
	lsls r1, r1, #0x01
	adds r2, r1, r0
	ldrh r0, [r4, #0x00]
	ldrh r1, [r2, #0x00]
	cmp r0, r1
	bhi _0800AE4E
	ldr r0, [r5, #0x50]
	ldr r1, _0800AE84 @ =0x0000FFFF
	ands r0, r1
	ldrh r2, [r2, #0x00]
	cmp r0, r2
	bcc _0800AE4E
	movs r0, #0x00
	strb r0, [r4, #0x03]
	.global _0800AE4E
_0800AE4E:
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r4, r4, r0
	adds r5, r5, r0
	adds r6, #0x01
	cmp r6, r7
	bne _0800ADBE
	.global _0800AE5C
_0800AE5C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800AE64
_0800AE64: .4byte 0x0202A550
	.global _0800AE68
_0800AE68: .4byte 0x02002090
	.global _0800AE6C
_0800AE6C: .4byte 0x020020DC
	.global _0800AE70
_0800AE70: .4byte 0x0200215C
	.global _0800AE74
_0800AE74: .4byte 0x020020AC
	.global _0800AE78
_0800AE78: .4byte 0x0202A51C
	.global _0800AE7C
_0800AE7C: .4byte 0x083675F0
	.global _0800AE80
_0800AE80: .4byte 0x020020CC
	.global _0800AE84
_0800AE84: .4byte 0x0000FFFF
	.global _0800AE88
_0800AE88: .4byte 0x0202EEB0
	.global _0800AE8C
_0800AE8C: .4byte 0x00000175
	.global _0800AE90
_0800AE90: .4byte 0x08367608
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xA0, 0x69, 0x10, 0x21, 0x08, 0x40, 0x00, 0x28, 0x08, 0xD0, 0x03, 0x48
	.byte 0x0B, 0x21, 0x0A, 0x22, 0xFB, 0xF7, 0xF8, 0xFA, 0x07, 0xE0, 0x00, 0x00, 0x48, 0xC9, 0x06, 0x08
	.byte 0x15, 0x48, 0x0B, 0x21, 0x0A, 0x22, 0xFB, 0xF7, 0xEF, 0xFA, 0xA0, 0x69, 0x01, 0x38, 0xA0, 0x61
	.byte 0xF5, 0xF7, 0xE2, 0xFA, 0x11, 0x49, 0x12, 0x48, 0x09, 0x88, 0x08, 0x40, 0x00, 0x28, 0x02, 0xD1
	.byte 0xA0, 0x69, 0x00, 0x28, 0x14, 0xD1, 0x0A, 0x20, 0x00, 0x21, 0xF9, 0xF7, 0x51, 0xF8, 0xF5, 0xF7
	.byte 0xB9, 0xFA, 0x80, 0x22, 0xD2, 0x04, 0x11, 0x88, 0x0A, 0x48, 0x08, 0x40, 0x10, 0x80, 0x0A, 0x49
	.byte 0x02, 0x20, 0x08, 0x70, 0x20, 0x1C, 0xFC, 0xF7, 0x29, 0xFD, 0x20, 0x1C, 0xFC, 0xF7, 0x14, 0xFD
	.byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x54, 0xC9, 0x06, 0x08, 0xC8, 0x05, 0x00, 0x02
	.byte 0xFF, 0x03, 0x00, 0x00, 0xFF, 0xEF, 0x00, 0x00, 0xE0, 0x21, 0x00, 0x02
