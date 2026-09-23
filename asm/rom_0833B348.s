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
	thumb_func_start sub_0833B348
sub_0833B348:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x020
	ldr r0, _0833B368 @ =0x03007FF0
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x004]
	ldrb r0, [r0, #0x0A]
	cmp r0, #0x00
	beq _0833B36C
	subs r0, #0x01
	ldr r1, [sp, #0x004]
	strb r0, [r1, #0x0A]
	b _0833B372
_0833B368: .4byte 0x03007FF0
_0833B36C:
	movs r0, #0x0E
	ldr r2, [sp, #0x004]
	strb r0, [r2, #0x0A]
_0833B372:
	movs r6, #0x01
	ldr r0, [sp, #0x004]
	ldr r4, [r0, #0x1C]
_0833B378:
	ldrb r1, [r4, #0x00]
	movs r0, #0xC7
	ands r0, r1
	adds r2, r6, #0x1
	mov r9, r2
	movs r2, #0x40
	adds r2, r2, r4
	mov r8, r2
	cmp r0, #0x00
	bne _0833B38E
	b _0833B772
_0833B38E:
	cmp r6, #0x02
	beq _0833B3C0
	cmp r6, #0x02
	bgt _0833B39C
	cmp r6, #0x01
	beq _0833B3A2
	b _0833B3F8
_0833B39C:
	cmp r6, #0x03
	beq _0833B3D8
	b _0833B3F8
_0833B3A2:
	ldr r0, _0833B3B4 @ =0x04000060
	str r0, [sp, #0x008]
	ldr r7, _0833B3B8 @ =0x04000062
	ldr r2, _0833B3BC @ =0x04000063
	str r2, [sp, #0x00C]
	adds r0, #0x04
	str r0, [sp, #0x010]
	adds r2, #0x02
	b _0833B408
_0833B3B4: .4byte 0x04000060
_0833B3B8: .4byte 0x04000062
_0833B3BC: .4byte 0x04000063
_0833B3C0:
	ldr r0, _0833B3CC @ =0x04000061
	str r0, [sp, #0x008]
	ldr r7, _0833B3D0 @ =0x04000068
	ldr r2, _0833B3D4 @ =0x04000069
	b _0833B400
	.byte 0x00, 0x00
_0833B3CC: .4byte 0x04000061
_0833B3D0: .4byte 0x04000068
_0833B3D4: .4byte 0x04000069
_0833B3D8:
	ldr r0, _0833B3EC @ =0x04000070
	str r0, [sp, #0x008]
	ldr r7, _0833B3F0 @ =0x04000072
	ldr r2, _0833B3F4 @ =0x04000073
	str r2, [sp, #0x00C]
	adds r0, #0x04
	str r0, [sp, #0x010]
	adds r2, #0x02
	b _0833B408
	.byte 0x00, 0x00
_0833B3EC: .4byte 0x04000070
_0833B3F0: .4byte 0x04000072
_0833B3F4: .4byte 0x04000073
_0833B3F8:
	ldr r0, _0833B454 @ =0x04000071
	str r0, [sp, #0x008]
	ldr r7, _0833B458 @ =0x04000078
	ldr r2, _0833B45C @ =0x04000079
_0833B400:
	str r2, [sp, #0x00C]
	adds r0, #0x0B
	str r0, [sp, #0x010]
	adds r2, #0x04
_0833B408:
	str r2, [sp, #0x014]
	ldr r0, [sp, #0x004]
	ldrb r0, [r0, #0x0A]
	str r0, [sp, #0x000]
	adds r2, r1, #0x0
	movs r0, #0x80
	mov r10, r0
	ands r0, r2
	cmp r0, #0x00
	beq _0833B502
	movs r3, #0x40
	adds r0, r3, #0x0
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r1, r6, #0x1
	mov r9, r1
	movs r2, #0x40
	adds r2, r2, r4
	mov r8, r2
	cmp r5, #0x00
	bne _0833B526
	movs r0, #0x03
	strb r0, [r4, #0x00]
	strb r0, [r4, #0x1D]
	adds r0, r4, #0x0
	str r3, [sp, #0x01C]
	bl sub_0833B2E0
	ldr r3, [sp, #0x01C]
	cmp r6, #0x02
	beq _0833B46C
	cmp r6, #0x02
	bgt _0833B460
	cmp r6, #0x01
	beq _0833B466
	b _0833B4C4
	.byte 0x00, 0x00
_0833B454: .4byte 0x04000071
_0833B458: .4byte 0x04000078
_0833B45C: .4byte 0x04000079
_0833B460:
	cmp r6, #0x03
	beq _0833B478
	b _0833B4C4
_0833B466:
	ldrb r0, [r4, #0x1F]
	ldr r1, [sp, #0x008]
	strb r0, [r1, #0x00]
_0833B46C:
	ldr r0, [r4, #0x24]
	lsls r0, r0, #0x06
	ldrb r2, [r4, #0x1E]
	adds r0, r2, r0
	strb r0, [r7, #0x00]
	b _0833B4D0
_0833B478:
	ldr r1, [r4, #0x24]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	beq _0833B4A0
	ldr r0, [sp, #0x008]
	strb r3, [r0, #0x00]
	ldr r1, _0833B4B8 @ =0x04000090
	ldr r2, [r4, #0x24]
	ldr r0, [r2, #0x00]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r2, #0x04]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r2, #0x08]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r2, #0x0C]
	str r0, [r1, #0x00]
	str r2, [r4, #0x28]
_0833B4A0:
	ldr r1, [sp, #0x008]
	strb r5, [r1, #0x00]
	ldrb r0, [r4, #0x1E]
	strb r0, [r7, #0x00]
	ldrb r0, [r4, #0x1E]
	cmp r0, #0x00
	beq _0833B4BC
	movs r0, #0xC0
	strb r0, [r4, #0x1A]
	ldrb r1, [r4, #0x04]
	b _0833B4E6
	.byte 0x00, 0x00
_0833B4B8: .4byte 0x04000090
_0833B4BC:
	mov r2, r10
	strb r2, [r4, #0x1A]
	ldrb r1, [r4, #0x04]
	b _0833B4E6
_0833B4C4:
	ldrb r0, [r4, #0x1E]
	strb r0, [r7, #0x00]
	ldr r0, [r4, #0x24]
	lsls r0, r0, #0x03
	ldr r1, [sp, #0x010]
	strb r0, [r1, #0x00]
_0833B4D0:
	ldrb r1, [r4, #0x04]
	adds r0, r1, #0x0
	adds r0, #0x08
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x018]
	ldrb r0, [r4, #0x1E]
	cmp r0, #0x00
	beq _0833B4E4
	movs r0, #0x40
_0833B4E4:
	strb r0, [r4, #0x1A]
_0833B4E6:
	movs r2, #0x00
	strb r1, [r4, #0x0B]
	movs r0, #0xFF
	ands r0, r1
	adds r1, r6, #0x1
	mov r9, r1
	movs r1, #0x40
	adds r1, r1, r4
	mov r8, r1
	cmp r0, #0x00
	bne _0833B4FE
	b _0833B632
_0833B4FE:
	strb r2, [r4, #0x09]
	b _0833B660
_0833B502:
	movs r0, #0x04
	ands r0, r2
	cmp r0, #0x00
	beq _0833B534
	ldrb r0, [r4, #0x0D]
	subs r0, #0x01
	strb r0, [r4, #0x0D]
	movs r2, #0xFF
	ands r0, r2
	lsls r0, r0, #0x18
	adds r1, r6, #0x1
	mov r9, r1
	movs r2, #0x40
	adds r2, r2, r4
	mov r8, r2
	cmp r0, #0x00
	ble _0833B526
	b _0833B672
_0833B526:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl sub_0833B290
	movs r0, #0x00
	strb r0, [r4, #0x00]
	b _0833B76E
_0833B534:
	movs r0, #0x40
	ands r0, r1
	adds r2, r6, #0x1
	mov r9, r2
	movs r2, #0x40
	adds r2, r2, r4
	mov r8, r2
	cmp r0, #0x00
	beq _0833B574
	movs r0, #0x03
	ands r0, r1
	cmp r0, #0x00
	beq _0833B574
	movs r0, #0xFC
	ands r0, r1
	movs r2, #0x00
	strb r0, [r4, #0x00]
	ldrb r1, [r4, #0x07]
	strb r1, [r4, #0x0B]
	movs r0, #0xFF
	ands r0, r1
	cmp r0, #0x00
	beq _0833B5A6
	movs r0, #0x01
	ldrb r1, [r4, #0x1D]
	orrs r0, r1
	strb r0, [r4, #0x1D]
	cmp r6, #0x03
	beq _0833B660
	ldrb r2, [r4, #0x07]
	str r2, [sp, #0x018]
	b _0833B660
_0833B574:
	ldrb r0, [r4, #0x0B]
	cmp r0, #0x00
	bne _0833B660
	cmp r6, #0x03
	bne _0833B586
	movs r0, #0x01
	ldrb r1, [r4, #0x1D]
	orrs r0, r1
	strb r0, [r4, #0x1D]
_0833B586:
	adds r0, r4, #0x0
	bl sub_0833B2E0
	movs r0, #0x03
	ldrb r2, [r4, #0x00]
	ands r0, r2
	cmp r0, #0x00
	bne _0833B5D2
	ldrb r0, [r4, #0x09]
	subs r0, #0x01
	strb r0, [r4, #0x09]
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bgt _0833B5CE
_0833B5A6:
	ldrb r2, [r4, #0x0C]
	ldrb r1, [r4, #0x0A]
	adds r0, r2, #0x0
	muls r0, r1
	adds r0, #0xFF
	asrs r0, r0, #0x08
	movs r1, #0x00
	strb r0, [r4, #0x09]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0833B526
	movs r0, #0x04
	ldrb r2, [r4, #0x00]
	orrs r0, r2
	strb r0, [r4, #0x00]
	movs r0, #0x01
	ldrb r1, [r4, #0x1D]
	orrs r0, r1
	strb r0, [r4, #0x1D]
	b _0833B672
_0833B5CE:
	ldrb r0, [r4, #0x07]
	b _0833B65E
_0833B5D2:
	cmp r0, #0x01
	bne _0833B5DE
_0833B5D6:
	ldrb r0, [r4, #0x19]
	strb r0, [r4, #0x09]
	movs r0, #0x07
	b _0833B65E
_0833B5DE:
	cmp r0, #0x02
	bne _0833B622
	ldrb r0, [r4, #0x09]
	subs r0, #0x01
	strb r0, [r4, #0x09]
	movs r2, #0xFF
	ands r0, r2
	lsls r0, r0, #0x18
	ldrb r2, [r4, #0x19]
	lsls r1, r2, #0x18
	cmp r0, r1
	bgt _0833B61E
_0833B5F6:
	ldrb r0, [r4, #0x06]
	cmp r0, #0x00
	bne _0833B606
	movs r0, #0xFC
	ldrb r1, [r4, #0x00]
	ands r0, r1
	strb r0, [r4, #0x00]
	b _0833B5A6
_0833B606:
	ldrb r0, [r4, #0x00]
	subs r0, #0x01
	strb r0, [r4, #0x00]
	movs r0, #0x01
	ldrb r2, [r4, #0x1D]
	orrs r0, r2
	strb r0, [r4, #0x1D]
	cmp r6, #0x03
	beq _0833B5D6
	movs r0, #0x08
	str r0, [sp, #0x018]
	b _0833B5D6
_0833B61E:
	ldrb r0, [r4, #0x05]
	b _0833B65E
_0833B622:
	ldrb r0, [r4, #0x09]
	adds r0, #0x01
	strb r0, [r4, #0x09]
	movs r1, #0xFF
	ands r0, r1
	ldrb r2, [r4, #0x0A]
	cmp r0, r2
	bcc _0833B65C
_0833B632:
	ldrb r0, [r4, #0x00]
	subs r0, #0x01
	movs r2, #0x00
	strb r0, [r4, #0x00]
	ldrb r1, [r4, #0x05]
	strb r1, [r4, #0x0B]
	movs r0, #0xFF
	ands r0, r1
	cmp r0, #0x00
	beq _0833B5F6
	movs r0, #0x01
	ldrb r1, [r4, #0x1D]
	orrs r0, r1
	strb r0, [r4, #0x1D]
	ldrb r0, [r4, #0x0A]
	strb r0, [r4, #0x09]
	cmp r6, #0x03
	beq _0833B660
	ldrb r2, [r4, #0x05]
	str r2, [sp, #0x018]
	b _0833B660
_0833B65C:
	ldrb r0, [r4, #0x04]
_0833B65E:
	strb r0, [r4, #0x0B]
_0833B660:
	ldrb r0, [r4, #0x0B]
	subs r0, #0x01
	strb r0, [r4, #0x0B]
	ldr r0, [sp, #0x000]
	cmp r0, #0x00
	bne _0833B672
	subs r0, #0x01
	str r0, [sp, #0x000]
	b _0833B574
_0833B672:
	movs r0, #0x02
	ldrb r1, [r4, #0x1D]
	ands r0, r1
	cmp r0, #0x00
	beq _0833B6EA
	cmp r6, #0x03
	bgt _0833B6B2
	movs r0, #0x08
	ldrb r2, [r4, #0x01]
	ands r0, r2
	cmp r0, #0x00
	beq _0833B6B2
	ldr r0, _0833B69C @ =0x04000089
	ldrb r0, [r0, #0x00]
	cmp r0, #0x3F
	bgt _0833B6A4
	ldr r0, [r4, #0x20]
	adds r0, #0x02
	ldr r1, _0833B6A0 @ =0x000007FC
	b _0833B6AE
	.byte 0x00, 0x00
_0833B69C: .4byte 0x04000089
_0833B6A0: .4byte 0x000007FC
_0833B6A4:
	cmp r0, #0x7F
	bgt _0833B6B2
	ldr r0, [r4, #0x20]
	adds r0, #0x01
	ldr r1, _0833B6C0 @ =0x000007FE
_0833B6AE:
	ands r0, r1
	str r0, [r4, #0x20]
_0833B6B2:
	cmp r6, #0x04
	beq _0833B6C4
	ldr r0, [r4, #0x20]
	ldr r1, [sp, #0x010]
	strb r0, [r1, #0x00]
	b _0833B6D2
	.byte 0x00, 0x00
_0833B6C0: .4byte 0x000007FE
_0833B6C4:
	ldr r2, [sp, #0x010]
	ldrb r0, [r2, #0x00]
	movs r1, #0x08
	ands r1, r0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	strb r0, [r2, #0x00]
_0833B6D2:
	movs r0, #0xC0
	ldrb r1, [r4, #0x1A]
	ands r0, r1
	adds r1, r4, #0x0
	adds r1, #0x21
	ldrb r1, [r1, #0x00]
	adds r0, r1, r0
	strb r0, [r4, #0x1A]
	movs r2, #0xFF
	ands r0, r2
	ldr r1, [sp, #0x014]
	strb r0, [r1, #0x00]
_0833B6EA:
	movs r0, #0x01
	ldrb r2, [r4, #0x1D]
	ands r0, r2
	cmp r0, #0x00
	beq _0833B76E
	ldr r1, _0833B734 @ =0x04000081
	ldrb r0, [r1, #0x00]
	ldrb r2, [r4, #0x1C]
	bics r0, r2
	ldrb r2, [r4, #0x1B]
	orrs r0, r2
	strb r0, [r1, #0x00]
	cmp r6, #0x03
	bne _0833B73C
	ldr r0, _0833B738 @ =0x0200C8CC
	ldrb r1, [r4, #0x09]
	adds r0, r1, r0
	ldrb r0, [r0, #0x00]
	ldr r2, [sp, #0x00C]
	strb r0, [r2, #0x00]
	movs r1, #0x80
	adds r0, r1, #0x0
	ldrb r2, [r4, #0x1A]
	ands r0, r2
	cmp r0, #0x00
	beq _0833B76E
	ldr r0, [sp, #0x008]
	strb r1, [r0, #0x00]
	ldrb r0, [r4, #0x1A]
	ldr r1, [sp, #0x014]
	strb r0, [r1, #0x00]
	movs r0, #0x7F
	ldrb r2, [r4, #0x1A]
	ands r0, r2
	strb r0, [r4, #0x1A]
	b _0833B76E
	.byte 0x00, 0x00
_0833B734: .4byte 0x04000081
_0833B738: .4byte 0x0200C8CC
_0833B73C:
	movs r0, #0x0F
	ldr r1, [sp, #0x018]
	ands r0, r1
	ldrb r2, [r4, #0x09]
	lsls r1, r2, #0x04
	adds r0, r0, r1
	ldr r1, [sp, #0x00C]
	strb r0, [r1, #0x00]
	movs r2, #0x80
	ldrb r0, [r4, #0x1A]
	orrs r0, r2
	ldr r1, [sp, #0x014]
	strb r0, [r1, #0x00]
	cmp r6, #0x01
	bne _0833B76E
	ldr r0, [sp, #0x008]
	ldrb r1, [r0, #0x00]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _0833B76E
	ldrb r0, [r4, #0x1A]
	orrs r0, r2
	ldr r1, [sp, #0x014]
	strb r0, [r1, #0x00]
_0833B76E:
	movs r0, #0x00
	strb r0, [r4, #0x1D]
_0833B772:
	mov r6, r9
	mov r4, r8
	cmp r6, #0x04
	bgt _0833B77C
	b _0833B378
_0833B77C:
	add sp, #0x020
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start sub_0833B78C
sub_0833B78C:
	push {r4, lr}
	adds r2, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [r2, #0x34]
	ldr r0, _0833B7B0 @ =0x68736D53
	cmp r3, r0
	bne _0833B7A8
	strh r1, [r2, #0x1E]
	ldrh r4, [r2, #0x1C]
	adds r0, r1, #0x0
	muls r0, r4
	asrs r0, r0, #0x08
	strh r0, [r2, #0x20]
_0833B7A8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0833B7B0: .4byte 0x68736D53
	thumb_func_start sub_0833B7B4
sub_0833B7B4:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r6, r2, #0x10
	ldr r3, [r4, #0x34]
	ldr r0, _0833B818 @ =0x68736D53
	cmp r3, r0
	bne _0833B80C
	adds r0, r3, #0x1
	str r0, [r4, #0x34]
	ldrb r2, [r4, #0x08]
	ldr r1, [r4, #0x2C]
	movs r5, #0x01
	cmp r2, #0x00
	ble _0833B808
	movs r0, #0x80
	mov r8, r0
	lsrs r6, r6, #0x12
	movs r0, #0x03
	mov r12, r0
_0833B7E4:
	adds r0, r7, #0x0
	ands r0, r5
	cmp r0, #0x00
	beq _0833B7FE
	ldrb r3, [r1, #0x00]
	mov r0, r8
	ands r0, r3
	cmp r0, #0x00
	beq _0833B7FE
	strb r6, [r1, #0x13]
	mov r0, r12
	orrs r0, r3
	strb r0, [r1, #0x00]
_0833B7FE:
	subs r2, #0x01
	adds r1, #0x50
	lsls r5, r5, #0x01
	cmp r2, #0x00
	bgt _0833B7E4
_0833B808:
	ldr r0, _0833B818 @ =0x68736D53
	str r0, [r4, #0x34]
_0833B80C:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0833B818: .4byte 0x68736D53
