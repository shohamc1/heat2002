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
	thumb_func_start sub_0800295C
sub_0800295C:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r1, _08002A74 @ =0x020020F0
	movs r2, #0x00
	strb r2, [r1, #0x00]
	ldr r1, _08002A78 @ =0x020021BC
	strb r2, [r1, #0x00]
	ldr r1, _08002A7C @ =0x02002144
	strb r2, [r1, #0x00]
	ldr r1, _08002A80 @ =0x0200215C
	strb r6, [r1, #0x00]
	ldr r4, _08002A84 @ =0x020020E0
	strb r0, [r4, #0x00]
	adds r3, r1, #0x0
	cmp r6, #0x0F
	beq _08002986
	ldr r1, _08002A88 @ =0x02002090
	movs r0, #0x18
	strb r0, [r1, #0x00]
	.global _08002986
_08002986:
	ldrb r2, [r3, #0x00]
	cmp r2, #0x02
	bne _08002992
	ldr r1, _08002A88 @ =0x02002090
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _08002992
_08002992:
	cmp r2, #0x11
	bne _0800299C
	ldr r1, _08002A88 @ =0x02002090
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0800299C
_0800299C:
	cmp r2, #0x0D
	bne _080029A6
	ldr r1, _08002A88 @ =0x02002090
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _080029A6
_080029A6:
	cmp r2, #0x0E
	bne _080029B0
	ldr r1, _08002A88 @ =0x02002090
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _080029B0
_080029B0:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080029BC
	ldr r1, _08002A88 @ =0x02002090
	movs r0, #0x02
	strb r0, [r1, #0x00]
	.global _080029BC
_080029BC:
	ldr r0, _08002A8C @ =0x020020CC
	ldrb r1, [r0, #0x00]
	adds r5, r0, #0x0
	cmp r1, #0x06
	bls _080029DC
	cmp r1, #0x08
	beq _080029DC
	cmp r1, #0x09
	beq _080029DC
	cmp r1, #0x0A
	beq _080029DC
	cmp r1, #0x0B
	beq _080029DC
	ldr r1, _08002A88 @ =0x02002090
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _080029DC
_080029DC:
	ldrb r0, [r3, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _080029F0
	ldr r0, _08002A88 @ =0x02002090
	ldr r1, _08002A90 @ =0x020020AC
	ldrb r1, [r1, #0x00]
	strb r1, [r0, #0x00]
	.global _080029F0
_080029F0:
	ldr r0, _08002A94 @ =0x020021D0
	movs r4, #0x00
	str r4, [r0, #0x00]
	str r4, [r0, #0x04]
	str r4, [r0, #0x08]
	str r4, [r0, #0x0C]
	ldrb r0, [r5, #0x00]
	bl sub_08003928
	ldrb r0, [r5, #0x00]
	bl sub_08006A14
	ldrb r0, [r5, #0x00]
	bl sub_08004944
	bl sub_080063B0
	bl _08002718
	ldr r1, _08002A98 @ =0x02002148
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r1, #0x00]
	movs r0, #0x32
	bl sub_080040E0
	ldrb r0, [r5, #0x00]
	bl sub_0800CCE0
	bl sub_08007344
	bl sub_080078B8
	bl sub_080045D8
	bl sub_08004484
	bl sub_080047DC
	ldr r1, _08002A9C @ =0x020021C4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _08002AA0 @ =0x020020C0
	strb r4, [r1, #0x00]
	ldrb r0, [r1, #0x00]
	subs r6, #0x03
	cmp r0, #0x00
	bne _08002A56
	.global _08002A50
_08002A50:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08002A50
	.global _08002A56
_08002A56:
	bl sub_08000458
	ldr r0, _08002AA4 @ =0x020020EC
	movs r1, #0x00
	strb r1, [r0, #0x00]
	bl sub_08002940
	ldr r0, _08002A80 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0E
	bne _08002AA8
	bl sub_08006388
	b _08002AAC
	.byte 0x00, 0x00
	.global _08002A74
_08002A74: .4byte 0x020020F0
	.global _08002A78
_08002A78: .4byte 0x020021BC
	.global _08002A7C
_08002A7C: .4byte 0x02002144
	.global _08002A80
_08002A80: .4byte 0x0200215C
	.global _08002A84
_08002A84: .4byte 0x020020E0
	.global _08002A88
_08002A88: .4byte 0x02002090
	.global _08002A8C
_08002A8C: .4byte 0x020020CC
	.global _08002A90
_08002A90: .4byte 0x020020AC
	.global _08002A94
_08002A94: .4byte 0x020021D0
	.global _08002A98
_08002A98: .4byte 0x02002148
	.global _08002A9C
_08002A9C: .4byte 0x020021C4
	.global _08002AA0
_08002AA0: .4byte 0x020020C0
	.global _08002AA4
_08002AA4: .4byte 0x020020EC
	.global _08002AA8
_08002AA8:
	bl sub_080062BC
	.global _08002AAC
_08002AAC:
	ldr r4, _08002AE8 @ =0x020020E0
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08002AF8
	ldr r0, _08002AEC @ =0x0202EF00
	ldrb r0, [r0, #0x02]
	cmp r0, #0x00
	beq _08002AC2
	movs r0, #0x01
	bl sub_08001208
	.global _08002AC2
_08002AC2:
	ldr r1, _08002AF0 @ =0x020020C4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _08002AF4 @ =0x08364ADC
	movs r0, #0x02
	strb r0, [r1, #0x00]
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08002AF8
	movs r4, #0x00
	.global _08002AD6
_08002AD6:
	bl sub_0800AD80
	adds r4, #0x01
	cmp r4, #0x64
	bne _08002AD6
	bl sub_0800AF20
	b _08002B0A
	.byte 0x00, 0x00
	.global _08002AE8
_08002AE8: .4byte 0x020020E0
	.global _08002AEC
_08002AEC: .4byte 0x0202EF00
	.global _08002AF0
_08002AF0: .4byte 0x020020C4
	.global _08002AF4
_08002AF4: .4byte 0x08364ADC
	.global _08002AF8
_08002AF8:
	ldr r0, _08002B98 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _08002B0A
	bl sub_0800B334
	.global _08002B0A
_08002B0A:
	ldr r0, _08002B98 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _08002B30
	cmp r0, #0x02
	beq _08002B30
	cmp r0, #0x07
	beq _08002B30
	ldr r0, _08002B9C @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08002B3C
	ldr r0, _08002BA0 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08002B30
	movs r0, #0x1E
	bl sub_08001208
	.global _08002B30
_08002B30:
	ldr r0, _08002B9C @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08002B3C
	bl sub_08002950
	.global _08002B3C
_08002B3C:
	ldr r0, _08002B98 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _08002B56
	cmp r0, #0x0D
	beq _08002B56
	cmp r0, #0x0E
	beq _08002B56
	cmp r0, #0x0F
	beq _08002B56
	ldr r1, _08002BA4 @ =0x020020A8
	cmp r0, #0x11
	bne _08002B6E
	.global _08002B56
_08002B56:
	ldr r1, _08002BA4 @ =0x020020A8
	movs r0, #0x01
	strb r0, [r1, #0x00]
	movs r4, #0x00
	.global _08002B5E
_08002B5E:
	bl sub_0800AD80
	adds r4, #0x01
	cmp r4, #0x14
	bne _08002B5E
	ldr r1, _08002BA4 @ =0x020020A8
	movs r0, #0x00
	strb r0, [r1, #0x00]
	.global _08002B6E
_08002B6E:
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r0, _08002BA8 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08002BC0
	ldr r0, _08002BAC @ =0x04000128
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x1A
	lsrs r1, r1, #0x1E
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _08002BB0 @ =0x0202A550
	adds r0, r0, r1
	bl sub_080043F8
	b _08002BC6
	.byte 0x00, 0x00
	.global _08002B98
_08002B98: .4byte 0x0200215C
	.global _08002B9C
_08002B9C: .4byte 0x020020E0
	.global _08002BA0
_08002BA0: .4byte 0x0202EF00
	.global _08002BA4
_08002BA4: .4byte 0x020020A8
	.global _08002BA8
_08002BA8: .4byte 0x020020DC
	.global _08002BAC
_08002BAC: .4byte 0x04000128
	.global _08002BB0
_08002BB0: .4byte 0x0202A550
	.global _08002BB4
_08002BB4:
	ldr r1, _08002BBC @ =0x02002144
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _0800303E
	.global _08002BBC
_08002BBC: .4byte 0x02002144
	.global _08002BC0
_08002BC0:
	ldr r0, _08002C5C @ =0x0202A550
	bl sub_080043F8
	.global _08002BC6
_08002BC6:
	ldr r0, _08002C60 @ =0x02002100
	ldr r1, [r0, #0x08]
	str r1, [r0, #0x00]
	ldr r1, [r0, #0x0C]
	str r1, [r0, #0x04]
	ldr r0, _08002C64 @ =0x0200209C
	movs r1, #0x00
	str r1, [r0, #0x00]
	ldr r0, _08002C68 @ =0x020021E0
	strb r1, [r0, #0x00]
	ldr r1, _08002C6C @ =0x020020B4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _08002BEC
	bl sub_0800F7E0
	.global _08002BEC
_08002BEC:
	ldr r0, _08002C70 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08002C02
	ldr r0, _08002C74 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08002C02
	movs r0, #0x0A
	bl sub_08001208
	.global _08002C02
_08002C02:
	ldr r1, _08002C78 @ =0x020021F0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r0, _08002C7C @ =0x02002124
	movs r1, #0x00
	strh r1, [r0, #0x00]
	movs r7, #0x00
	ldr r0, _08002C80 @ =0x020021EC
	strb r1, [r0, #0x03]
	strb r1, [r0, #0x02]
	strb r1, [r0, #0x01]
	strb r1, [r0, #0x00]
	ldr r0, _08002C84 @ =0x02002144
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08002C24
	b _0800303A
	.global _08002C24
_08002C24:
	bl sub_080073D8
	bl sub_08004484
	ldr r0, _08002C88 @ =0x02002150
	movs r1, #0x4B
	movs r2, #0x3C
	bl sub_0800BB58
	ldr r0, _08002C78 @ =0x020021F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08002C48
	ldr r0, _08002C8C @ =0x02002160
	movs r1, #0x4B
	movs r2, #0x5A
	bl sub_0800BB58
	.global _08002C48
_08002C48:
	ldr r1, _08002C7C @ =0x02002124
	movs r0, #0x00
	strh r0, [r1, #0x00]
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bls _08002C90
	ldr r3, _08002C5C @ =0x0202A550
	b _08002CA2
	.byte 0x00, 0x00
	.global _08002C5C
_08002C5C: .4byte 0x0202A550
	.global _08002C60
_08002C60: .4byte 0x02002100
	.global _08002C64
_08002C64: .4byte 0x0200209C
	.global _08002C68
_08002C68: .4byte 0x020021E0
	.global _08002C6C
_08002C6C: .4byte 0x020020B4
	.global _08002C70
_08002C70: .4byte 0x0202EF00
	.global _08002C74
_08002C74: .4byte 0x020020E0
	.global _08002C78
_08002C78: .4byte 0x020021F0
	.global _08002C7C
_08002C7C: .4byte 0x02002124
	.global _08002C80
_08002C80: .4byte 0x020021EC
	.global _08002C84
_08002C84: .4byte 0x02002144
	.global _08002C88
_08002C88: .4byte 0x02002150
	.global _08002C8C
_08002C8C: .4byte 0x02002160
	.global _08002C90
_08002C90:
	ldr r0, _08002CFC @ =0x0202EF90
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _08002D00 @ =0x0202A550
	adds r3, r0, r1
	.global _08002CA2
_08002CA2:
	ldr r2, _08002D04 @ =0x08364AE0
	adds r0, r3, #0x0
	adds r0, #0x3E
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r2
	ldr r2, [r0, #0x00]
	adds r3, #0x40
	ldr r0, _08002D08 @ =0x08364AF4
	adds r1, r1, r0
	ldrb r1, [r1, #0x00]
	ldrh r3, [r3, #0x00]
	adds r0, r1, #0x0
	muls r0, r3
	asrs r0, r0, #0x06
	adds r2, r2, r0
	lsls r2, r2, #0x10
	asrs r2, r2, #0x13
	ldr r0, _08002D0C @ =0x02001F60
	movs r1, #0x01
	bl sub_0800215C
	ldr r0, _08002D10 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08002D20
	ldr r0, _08002D14 @ =0x0202A6E0
	bl sub_080043F8
	ldr r2, _08002D18 @ =0x08364ADC
	ldr r0, _08002D1C @ =0x0200209C
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bge _08002CE8
	adds r0, #0xFF
	.global _08002CE8
_08002CE8:
	asrs r1, r0, #0x08
	strb r1, [r2, #0x00]
	movs r0, #0x07
	ands r0, r1
	cmp r0, #0x00
	bne _08002D7A
	movs r0, #0x04
	strb r0, [r2, #0x00]
	b _08002D7A
	.byte 0x00, 0x00
	.global _08002CFC
_08002CFC: .4byte 0x0202EF90
	.global _08002D00
_08002D00: .4byte 0x0202A550
	.global _08002D04
_08002D04: .4byte 0x08364AE0
	.global _08002D08
_08002D08: .4byte 0x08364AF4
	.global _08002D0C
_08002D0C: .4byte 0x02001F60
	.global _08002D10
_08002D10: .4byte 0x020020E0
	.global _08002D14
_08002D14: .4byte 0x0202A6E0
	.global _08002D18
_08002D18: .4byte 0x08364ADC
	.global _08002D1C
_08002D1C: .4byte 0x0200209C
	.global _08002D20
_08002D20:
	ldr r0, _08002D44 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08002D50
	ldr r0, _08002D48 @ =0x04000128
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x1A
	lsrs r1, r1, #0x1E
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _08002D4C @ =0x0202A550
	adds r0, r0, r1
	bl sub_080043F8
	b _08002D56
	.global _08002D44
_08002D44: .4byte 0x020020DC
	.global _08002D48
_08002D48: .4byte 0x04000128
	.global _08002D4C
_08002D4C: .4byte 0x0202A550
	.global _08002D50
_08002D50:
	ldr r0, _08002DFC @ =0x0202A550
	bl sub_080043F8
	.global _08002D56
_08002D56:
	ldr r0, _08002E00 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _08002D6E
	cmp r0, #0x0D
	beq _08002D6E
	cmp r0, #0x0E
	beq _08002D6E
	cmp r0, #0x0F
	beq _08002D6E
	cmp r0, #0x11
	bne _08002D7A
	.global _08002D6E
_08002D6E:
	ldr r2, _08002E04 @ =0x02002100
	ldr r1, _08002DFC @ =0x0202A550
	ldr r0, [r1, #0x00]
	str r0, [r2, #0x00]
	ldr r0, [r1, #0x08]
	str r0, [r2, #0x04]
	.global _08002D7A
_08002D7A:
	bl sub_08004144
	bl sub_080043BC
	bl sub_08004278
	bl sub_0800796C
	bl sub_08009F48
	ldr r4, _08002E00 @ =0x0200215C
	ldrb r0, [r4, #0x00]
	cmp r0, #0x04
	bne _08002D9A
	bl sub_0800545C
	.global _08002D9A
_08002D9A:
	ldr r0, _08002E08 @ =0x020020C4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08002DB8
	ldrb r0, [r4, #0x00]
	cmp r0, #0x09
	beq _08002DB8
	cmp r0, #0x0D
	beq _08002DB8
	cmp r0, #0x0E
	beq _08002DB8
	cmp r0, #0x0F
	beq _08002DB8
	cmp r0, #0x11
	bne _08002DBC
	.global _08002DB8
_08002DB8:
	bl sub_0800AD80
	.global _08002DBC
_08002DBC:
	ldr r1, _08002E04 @ =0x02002100
	ldr r0, [r1, #0x00]
	ldr r1, [r1, #0x04]
	bl sub_08003B44
	ldr r0, _08002E00 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _08002DDE
	cmp r0, #0x0D
	beq _08002DDE
	cmp r0, #0x0E
	beq _08002DDE
	cmp r0, #0x0F
	beq _08002DDE
	cmp r0, #0x11
	bne _08002E1A
	.global _08002DDE
_08002DDE:
	ldr r0, _08002E0C @ =0x0200209C
	ldr r0, [r0, #0x00]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _08002E10
	movs r0, #0x5D
	bl sub_08016558
	movs r1, #0x08
	movs r2, #0x01
	bl sub_08006418
	b _08002E1A
	.byte 0x00, 0x00
	.global _08002DFC
_08002DFC: .4byte 0x0202A550
	.global _08002E00
_08002E00: .4byte 0x0200215C
	.global _08002E04
_08002E04: .4byte 0x02002100
	.global _08002E08
_08002E08: .4byte 0x020020C4
	.global _08002E0C
_08002E0C: .4byte 0x0200209C
	.global _08002E10
_08002E10:
	ldr r0, _08002E6C @ =0x0806C678
	movs r1, #0x08
	movs r2, #0x01
	bl sub_08006418
	.global _08002E1A
_08002E1A:
	bl sub_080047DC
	bl sub_08008D8C
	ldr r0, _08002E70 @ =0x020021C4
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, _08002E74 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08002E90
	ldr r0, _08002E78 @ =0x020005CC
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08002E3A
	b _08002FC2
	.global _08002E3A
_08002E3A:
	ldr r0, _08002E7C @ =0x020021BC
	strb r1, [r0, #0x00]
	ldr r1, _08002E80 @ =0x020021E0
	movs r0, #0x02
	strb r0, [r1, #0x00]
	bl sub_08000458
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2, #0x00]
	ldr r3, _08002E84 @ =0x0000EFFF
	adds r1, r3, #0x0
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r0, _08002E88 @ =0x0202EF00
	ldrb r0, [r0, #0x02]
	cmp r0, #0x00
	bne _08002E60
	b _08002F98
	.global _08002E60
_08002E60:
	ldr r0, _08002E8C @ =0x02001F20
	movs r1, #0x02
	bl sub_080013A0
	b _08002F98
	.byte 0x00, 0x00
	.global _08002E6C
_08002E6C: .4byte 0x0806C678
	.global _08002E70
_08002E70: .4byte 0x020021C4
	.global _08002E74
_08002E74: .4byte 0x020020E0
	.global _08002E78
_08002E78: .4byte 0x020005CC
	.global _08002E7C
_08002E7C: .4byte 0x020021BC
	.global _08002E80
_08002E80: .4byte 0x020021E0
	.global _08002E84
_08002E84: .4byte 0x0000EFFF
	.global _08002E88
_08002E88: .4byte 0x0202EF00
	.global _08002E8C
_08002E8C: .4byte 0x02001F20
	.global _08002E90
_08002E90:
	ldr r1, _08002EB8 @ =0x0200215C
	ldrb r0, [r1, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r1, #0x0
	cmp r0, #0x01
	bls _08002EC4
	ldr r0, _08002EBC @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08002EC4
	ldr r0, _08002EC0 @ =0x02022E14
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08002EF2
	bl sub_08004F48
	b _08002EEC
	.byte 0x00, 0x00
	.global _08002EB8
_08002EB8: .4byte 0x0200215C
	.global _08002EBC
_08002EBC: .4byte 0x020021E0
	.global _08002EC0
_08002EC0: .4byte 0x02022E14
	.global _08002EC4
_08002EC4:
	ldr r0, _08002EE0 @ =0x02022E14
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08002EF2
	ldr r0, _08002EE4 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08002EF2
	ldrb r3, [r3, #0x00]
	cmp r3, #0x04
	bne _08002EE8
	bl sub_08005280
	b _08002EEC
	.global _08002EE0
_08002EE0: .4byte 0x02022E14
	.global _08002EE4
_08002EE4: .4byte 0x020021E0
	.global _08002EE8
_08002EE8:
	bl sub_080050F0
	.global _08002EEC
_08002EEC:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _08002EF4
	.global _08002EF2
_08002EF2:
	movs r0, #0x00
	.global _08002EF4
_08002EF4:
	cmp r0, #0x01
	beq _08002F06
	cmp r0, #0x01
	ble _08002FC2
	cmp r0, #0x02
	beq _08002F28
	cmp r0, #0x27
	beq _08002FC0
	b _08002FC2
	.global _08002F06
_08002F06:
	ldr r0, _08002F20 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08002FC2
	ldr r0, _08002F24 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08002FC2
	movs r0, #0x0A
	bl sub_08001208
	b _08002FC2
	.byte 0x00, 0x00
	.global _08002F20
_08002F20: .4byte 0x0202EF00
	.global _08002F24
_08002F24: .4byte 0x020020E0
	.global _08002F28
_08002F28:
	ldr r0, _08002FA4 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	beq _08002F68
	cmp r0, #0x0E
	beq _08002F68
	cmp r0, #0x00
	beq _08002F68
	cmp r0, #0x07
	beq _08002F68
	cmp r0, #0x06
	beq _08002F68
	cmp r0, #0x09
	beq _08002F68
	cmp r0, #0x05
	beq _08002F68
	cmp r0, #0x11
	beq _08002F68
	cmp r0, #0x01
	beq _08002F68
	cmp r0, #0x03
	beq _08002F68
	cmp r0, #0x0C
	beq _08002F68
	cmp r0, #0x0D
	beq _08002F68
	cmp r0, #0x10
	beq _08002F68
	cmp r0, #0x0F
	beq _08002F68
	cmp r0, #0x11
	bne _08002FC2
	.global _08002F68
_08002F68:
	ldr r1, _08002FA8 @ =0x020021BC
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _08002FAC @ =0x020021E0
	movs r0, #0x02
	strb r0, [r1, #0x00]
	bl sub_08000458
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2, #0x00]
	ldr r3, _08002FB0 @ =0x0000EFFF
	adds r1, r3, #0x0
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r0, _08002FB4 @ =0x02001FA0
	bl sub_080019B4
	ldr r0, _08002FB8 @ =0x02002030
	bl sub_080019B4
	ldr r0, _08002FBC @ =0x02001FE0
	bl sub_080019B4
	.global _08002F98
_08002F98:
	movs r0, #0x19
	movs r1, #0x00
	bl sub_08003F84
	b _08002FC2
	.byte 0x00, 0x00
	.global _08002FA4
_08002FA4: .4byte 0x0200215C
	.global _08002FA8
_08002FA8: .4byte 0x020021BC
	.global _08002FAC
_08002FAC: .4byte 0x020021E0
	.global _08002FB0
_08002FB0: .4byte 0x0000EFFF
	.global _08002FB4
_08002FB4: .4byte 0x02001FA0
	.global _08002FB8
_08002FB8: .4byte 0x02002030
	.global _08002FBC
_08002FBC: .4byte 0x02001FE0
	.global _08002FC0
_08002FC0:
	movs r7, #0x01
	.global _08002FC2
_08002FC2:
	ldr r0, _08002FEC @ =0x020020DC
	ldrb r1, [r0, #0x00]
	cmp r1, #0x00
	beq _08003000
	bl sub_08003330
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0x00
	beq _08002FD8
	b _08002BB4
	.global _08002FD8
_08002FD8:
	ldr r0, _08002FF0 @ =0x020020C0
	strb r1, [r0, #0x00]
	ldr r4, _08002FF4 @ =0x02002144
	adds r2, r0, #0x0
	ldr r3, _08002FF8 @ =0x0200209C
	ldr r5, _08002FFC @ =0x020021E0
	.global _08002FE4
_08002FE4:
	ldrb r0, [r2, #0x00]
	cmp r0, #0x00
	beq _08002FE4
	b _0800301A
	.global _08002FEC
_08002FEC: .4byte 0x020020DC
	.global _08002FF0
_08002FF0: .4byte 0x020020C0
	.global _08002FF4
_08002FF4: .4byte 0x02002144
	.global _08002FF8
_08002FF8: .4byte 0x0200209C
	.global _08002FFC
_08002FFC: .4byte 0x020021E0
	.global _08003000
_08003000:
	ldr r0, _08003044 @ =0x020020C0
	strb r1, [r0, #0x00]
	ldrb r1, [r0, #0x00]
	ldr r4, _08003048 @ =0x02002144
	adds r2, r0, #0x0
	ldr r3, _0800304C @ =0x0200209C
	ldr r5, _08003050 @ =0x020021E0
	cmp r1, #0x00
	bne _0800301A
	adds r1, r2, #0x0
	.global _08003014
_08003014:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08003014
	.global _0800301A
_0800301A:
	ldr r0, [r3, #0x00]
	adds r0, #0x01
	str r0, [r3, #0x00]
	ldrb r5, [r5, #0x00]
	cmp r5, #0x02
	bne _08003032
	ldr r0, _08003054 @ =0x02022E14
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08003032
	movs r0, #0x01
	strb r0, [r4, #0x00]
	.global _08003032
_08003032:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _0800303A
	b _08002C24
	.global _0800303A
_0800303A:
	cmp r7, #0x00
	beq _08003058
	.global _0800303E
_0800303E:
	movs r0, #0x01
	b _08003060
	.byte 0x00, 0x00
	.global _08003044
_08003044: .4byte 0x020020C0
	.global _08003048
_08003048: .4byte 0x02002144
	.global _0800304C
_0800304C: .4byte 0x0200209C
	.global _08003050
_08003050: .4byte 0x020021E0
	.global _08003054
_08003054: .4byte 0x02022E14
	.global _08003058
_08003058:
	ldr r0, _08003068 @ =0x02001F60
	bl sub_080019B4
	movs r0, #0x00
	.global _08003060
_08003060:
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _08003068
_08003068: .4byte 0x02001F60
	.byte 0x10, 0xB5, 0xFD, 0xF7, 0x55, 0xFD, 0x09, 0x4A, 0x10, 0x88, 0x01, 0x30, 0x10, 0x80, 0x08, 0x49
	.byte 0x08, 0x88, 0x01, 0x30, 0x08, 0x80, 0x07, 0x48, 0x00, 0x78, 0x00, 0x28, 0x14, 0xD0, 0x10, 0x88
	.byte 0x01, 0x28, 0x0B, 0xD9, 0x04, 0x49, 0x01, 0x20, 0x12, 0xE0, 0x00, 0x00, 0x24, 0x21, 0x00, 0x02
	.byte 0x6C, 0x21, 0x00, 0x02, 0xDC, 0x20, 0x00, 0x02, 0xEC, 0x20, 0x00, 0x02, 0x01, 0x49, 0x00, 0x20
	.byte 0x06, 0xE0, 0x00, 0x00, 0xEC, 0x20, 0x00, 0x02, 0x22, 0x49, 0x01, 0x20, 0x0A, 0x78, 0x50, 0x40
	.byte 0x08, 0x70, 0x21, 0x48, 0x00, 0x78, 0x00, 0x28, 0x01, 0xD1, 0x01, 0x20, 0x08, 0x70, 0x1F, 0x49
	.byte 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x00, 0x06, 0x00, 0x0E, 0x02, 0x28, 0x53, 0xD9, 0x1C, 0x48
	.byte 0x00, 0x78, 0x04, 0x1C, 0x00, 0x2C, 0x4E, 0xD1, 0x0C, 0x70, 0x1A, 0x48, 0xE0, 0x21, 0xC9, 0x04
	.byte 0x80, 0x22, 0x52, 0x00, 0x13, 0xF0, 0x8C, 0xFE, 0x17, 0x48, 0x00, 0x78, 0x00, 0x28, 0x3D, 0xD0
	.byte 0x16, 0x49, 0x17, 0x48, 0x00, 0x68, 0x08, 0x80, 0x02, 0x31, 0x16, 0x48, 0x00, 0x68, 0x08, 0x80
	.byte 0x06, 0x39, 0x15, 0x48, 0x00, 0x68, 0x08, 0x80, 0x02, 0x31, 0x14, 0x48, 0x00, 0x68, 0x08, 0x80
	.byte 0x06, 0x39, 0x13, 0x48, 0x00, 0x68, 0x08, 0x80, 0x02, 0x31, 0x12, 0x48, 0x00, 0x68, 0x08, 0x80
	.byte 0x11, 0x48, 0x04, 0x80, 0x02, 0x30, 0x04, 0x80, 0x00, 0xF0, 0x2C, 0xFE, 0x04, 0xF0, 0x12, 0xFB
	.byte 0x1E, 0xE0, 0x00, 0x00, 0xEC, 0x20, 0x00, 0x02, 0xDC, 0x20, 0x00, 0x02, 0xB8, 0x21, 0x00, 0x02
	.byte 0xC0, 0x20, 0x00, 0x02, 0x30, 0x48, 0x02, 0x02, 0xC4, 0x21, 0x00, 0x02, 0x1C, 0x00, 0x00, 0x04
	.byte 0xE0, 0x2D, 0x02, 0x02, 0xE8, 0x2D, 0x02, 0x02, 0xF8, 0x2D, 0x02, 0x02, 0x2C, 0xBC, 0x00, 0x02
	.byte 0x48, 0xBC, 0x00, 0x02, 0x4C, 0xBC, 0x00, 0x02, 0x10, 0x00, 0x00, 0x04, 0x04, 0xF0, 0xF2, 0xFA
	.byte 0x09, 0x49, 0x01, 0x20, 0x08, 0x70, 0x01, 0xF0, 0x2D, 0xF8, 0xFE, 0xF7, 0x39, 0xF8, 0x07, 0x4B
	.byte 0x00, 0x20, 0x18, 0x80, 0x06, 0x4A, 0x10, 0x88, 0x01, 0x21, 0x08, 0x43, 0x10, 0x80, 0x19, 0x80
	.byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xC0, 0x20, 0x00, 0x02, 0x08, 0x02, 0x00, 0x04
	.byte 0xF8, 0x7F, 0x00, 0x03, 0x00, 0x04, 0xFE, 0x21, 0xC9, 0x03, 0x01, 0x40, 0x09, 0x0C, 0x7F, 0x29
	.byte 0x01, 0xD0, 0x01, 0x20, 0x00, 0xE0, 0x00, 0x20, 0x70, 0x47, 0x00, 0x00
