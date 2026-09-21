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
	thumb_func_start sub_08342154
sub_08342154:
	push {r4, r5, lr}
	adds r3, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	adds r1, r3, #0x0
	adds r1, #0x84
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _083421BC @ =0x0203D520
	cmp r3, r0
	bne _083421C4
	ldr r0, [r3, #0x2C]
	cmp r0, #0x00
	ble _083421C4
	movs r0, #0x30
	ands r0, r4
	cmp r0, #0x00
	bne _0834218C
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
	.global _0834218C
_0834218C:
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0x00
	beq _083421A2
	movs r5, #0x96
	lsls r5, r5, #0x01
	adds r1, r3, r5
	ldrh r2, [r3, #0x34]
	ldr r5, _083421C0 @ =0xFFFFEC00
	adds r0, r2, r5
	str r0, [r1, #0x00]
	.global _083421A2
_083421A2:
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0x00
	beq _08342250
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldrh r3, [r3, #0x34]
	movs r2, #0xA0
	lsls r2, r2, #0x05
	adds r0, r3, r2
	str r0, [r1, #0x00]
	b _08342250
	.global _083421BC
_083421BC: .4byte 0x0203D520
	.global _083421C0
_083421C0: .4byte 0xFFFFEC00
	.global _083421C4
_083421C4:
	movs r0, #0x30
	ands r0, r4
	cmp r0, #0x00
	beq _083421E0
	movs r5, #0x88
	lsls r5, r5, #0x01
	adds r1, r3, r5
	ldrb r2, [r1, #0x00]
	movs r0, #0x00
	ldsb r0, [r1, r0]
	cmp r0, #0x00
	blt _083421F0
	adds r0, r2, #0x1
	b _083421EE
	.global _083421E0
_083421E0:
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _083421F0
	subs r0, #0x01
	.global _083421EE
_083421EE:
	strb r0, [r1, #0x00]
	.global _083421F0
_083421F0:
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
	bge _08342210
	movs r1, #0x00
	.global _08342210
_08342210:
	movs r0, #0xFF
	subs r1, r0, r1
	lsls r0, r1, #0x01
	adds r2, r2, r0
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0x00
	beq _08342234
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldr r0, [r1, #0x00]
	subs r0, r0, r2
	str r0, [r1, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x84
	movs r0, #0x00
	b _0834224E
	.global _08342234
_08342234:
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0x00
	beq _08342250
	movs r5, #0x96
	lsls r5, r5, #0x01
	adds r1, r3, r5
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x84
	movs r0, #0x02
	.global _0834224E
_0834224E:
	strb r0, [r1, #0x00]
	.global _08342250
_08342250:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start sub_08342258
sub_08342258:
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
	bl sub_0834029C
	adds r1, r5, #0x0
	adds r1, #0x55
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08342298
	subs r0, #0x01
	strb r0, [r1, #0x00]
	.global _08342298
_08342298:
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0x0
	bl sub_08342154
	adds r0, r5, #0x0
	bl sub_08341D64
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl sub_08341B14
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_083405F0
	movs r0, #0x00
	mov r9, r0
	adds r0, r5, #0x0
	bl sub_08341DA0
	ldr r0, _08342344 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x04
	beq _083422D2
	ldr r0, _08342348 @ =0x020390DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0B
	bhi _083422E4
	.global _083422D2
_083422D2:
	ldr r1, _0834234C @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08342300
	adds r0, r5, #0x0
	bl sub_08343A6C
	mov r9, r0
	.global _083422E4
_083422E4:
	mov r2, r9
	cmp r2, #0x00
	beq _08342300
	adds r0, r5, #0x0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	subs r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bhi _08342300
	movs r0, #0x01
	negs r0, r0
	mov r9, r0
	.global _08342300
_08342300:
	ldr r0, [r5, #0x2C]
	asrs r0, r0, #0x06
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r4, r5, r1
	adds r1, r0, #0x0
	muls r1, r0
	str r1, [r4, #0x00]
	cmp r0, #0x00
	ble _08342318
	negs r0, r1
	str r0, [r4, #0x00]
	.global _08342318
_08342318:
	ldr r0, _08342350 @ =0x020390EC
	ldrb r1, [r0, #0x00]
	ldr r7, _08342344 @ =0x0203916C
	mov r10, r0
	cmp r1, #0x00
	bne _0834232E
	ldrb r0, [r7, #0x00]
	cmp r0, #0x04
	beq _0834232E
	cmp r0, #0x03
	bne _08342358
	.global _0834232E
_0834232E:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r4, r5, r2
	ldr r0, [r4, #0x00]
	movs r1, #0xD7
	bl sub_08344BB8
	str r0, [r4, #0x00]
	ldr r0, _08342354 @ =0x0203D520
	mov r8, r0
	b _083423D2
	.global _08342344
_08342344: .4byte 0x0203916C
	.global _08342348
_08342348: .4byte 0x020390DC
	.global _0834234C
_0834234C: .4byte 0x00000175
	.global _08342350
_08342350: .4byte 0x020390EC
	.global _08342354
_08342354: .4byte 0x0203D520
	.global _08342358
_08342358:
	ldr r1, _08342390 @ =0x0203D520
	mov r8, r1
	cmp r5, r8
	beq _08342378
	cmp r0, #0x09
	beq _08342378
	cmp r0, #0x0D
	beq _08342378
	cmp r0, #0x0E
	beq _08342378
	cmp r0, #0x0F
	beq _08342378
	cmp r0, #0x11
	beq _08342378
	cmp r0, #0x04
	bne _083423BE
	.global _08342378
_08342378:
	movs r2, #0xB8
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08342394
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r4, r5, r0
	ldr r0, [r4, #0x00]
	movs r1, #0xFA
	b _083423CC
	.global _08342390
_08342390: .4byte 0x0203D520
	.global _08342394
_08342394:
	ldr r1, _083423AC @ =0x00000171
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _083423B0
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r4, r5, r2
	ldr r0, [r4, #0x00]
	movs r1, #0x64
	b _083423CC
	.byte 0x00, 0x00
	.global _083423AC
_083423AC: .4byte 0x00000171
	.global _083423B0
_083423B0:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r4, r5, r0
	ldr r0, [r4, #0x00]
	movs r1, #0xF0
	lsls r1, r1, #0x01
	b _083423CC
	.global _083423BE
_083423BE:
	ldr r1, _083424CC @ =0x020277D4
	ldr r0, _083424D0 @ =0x020390DC
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	ldr r0, [r4, #0x00]
	.global _083423CC
_083423CC:
	bl sub_08344BB8
	str r0, [r4, #0x00]
	.global _083423D2
_083423D2:
	ldr r0, _083424D4 @ =0x020390B8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _083423F0
	ldrb r0, [r7, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bls _083423F0
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x00
	str r0, [r1, #0x00]
	.global _083423F0
_083423F0:
	cmp r5, r8
	beq _083423FC
	mov r1, r10
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0834245A
	.global _083423FC
_083423FC:
	ldr r0, _083424D8 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _0834245A
	cmp r0, #0x0D
	beq _0834245A
	cmp r0, #0x0E
	beq _0834245A
	cmp r0, #0x0F
	beq _0834245A
	cmp r0, #0x11
	beq _0834245A
	adds r0, r5, #0x0
	bl sub_08343234
	cmp r0, #0x00
	bne _0834242A
	movs r2, #0xBB
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0834245A
	.global _0834242A
_0834242A:
	movs r0, #0xBB
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0834243A
	subs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0834243A
_0834243A:
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
	bl sub_08342DE8
	adds r0, r6, #0x0
	movs r1, #0x01
	bl sub_08342DE8
	.global _0834245A
_0834245A:
	ldr r0, _083424D8 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	beq _08342468
	adds r0, r5, #0x0
	bl sub_08343EA8
	.global _08342468
_08342468:
	ldr r1, [r5, #0x50]
	movs r2, #0xC6
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strh r1, [r0, #0x00]
	.global _08342472
_08342472:
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_0833F468
	ldr r1, _083424DC @ =0x020390CC
	strb r0, [r1, #0x00]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08342472
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
	beq _08342572
	ldr r0, _083424E0 @ =0x020390F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08342510
	ldr r0, _083424E4 @ =0x020391F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08342510
	ldr r0, _083424E8 @ =0x0203E120
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08342510
	ldr r0, _083424EC @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _083424F4
	ldr r0, _083424F0 @ =0x0203D520
	cmp r5, r0
	beq _0834250A
	b _08342510
	.byte 0x00, 0x00
	.global _083424CC
_083424CC: .4byte 0x020277D4
	.global _083424D0
_083424D0: .4byte 0x020390DC
	.global _083424D4
_083424D4: .4byte 0x020390B8
	.global _083424D8
_083424D8: .4byte 0x0203916C
	.global _083424DC
_083424DC: .4byte 0x020390CC
	.global _083424E0
_083424E0: .4byte 0x020390F0
	.global _083424E4
_083424E4: .4byte 0x020391F0
	.global _083424E8
_083424E8: .4byte 0x0203E120
	.global _083424EC
_083424EC: .4byte 0x020390EC
	.global _083424F0
_083424F0: .4byte 0x0203D520
	.global _083424F4
_083424F4:
	ldr r0, _083425B8 @ =0x0203E1B0
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _083425BC @ =0x0203D520
	adds r0, r0, r1
	cmp r5, r0
	bne _08342510
	.global _0834250A
_0834250A:
	movs r0, #0x12
	bl sub_0833A8C8
	.global _08342510
_08342510:
	adds r0, r5, #0x0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	subs r0, #0x05
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _08342536
	ldr r0, _083425C0 @ =0x0203E0E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08342536
	adds r2, r5, #0x0
	adds r2, #0x88
	mov r0, r9
	asrs r1, r0, #0x0C
	ldr r0, [r2, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	.global _08342536
_08342536:
	adds r1, r5, #0x0
	adds r1, #0x55
	movs r0, #0x06
	strb r0, [r1, #0x00]
	adds r0, r5, #0x0
	bl sub_08341D64
	ldr r0, [r5, #0x2C]
	str r0, [r5, #0x48]
	cmp r0, #0x00
	ble _08342550
	movs r0, #0x00
	str r0, [r5, #0x48]
	.global _08342550
_08342550:
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
	bl sub_08344BB8
	adds r1, r5, #0x0
	adds r1, #0x40
	strh r0, [r1, #0x00]
	.global _08342572
_08342572:
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
	.global _083425B8
_083425B8: .4byte 0x0203E1B0
	.global _083425BC
_083425BC: .4byte 0x0203D520
	.global _083425C0
_083425C0: .4byte 0x0203E0E0
	thumb_func_start sub_083425C4
sub_083425C4:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _083425F8 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08342614
	ldr r0, _083425FC @ =0x020391F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08342604
	adds r0, r5, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08342604
	ldr r0, _08342600 @ =0x020390B0
	lsls r1, r4, #0x01
	adds r1, r1, r0
	ldrh r1, [r1, #0x00]
	adds r0, r5, #0x0
	adds r2, r4, #0x0
	bl sub_08342258
	b _0834260E
	.global _083425F8
_083425F8: .4byte 0x020390EC
	.global _083425FC
_083425FC: .4byte 0x020391F0
	.global _08342600
_08342600: .4byte 0x020390B0
	.global _08342604
_08342604:
	adds r0, r5, #0x0
	movs r1, #0x02
	adds r2, r4, #0x0
	bl sub_08342258
	.global _0834260E
_0834260E:
	adds r0, r5, #0x0
	bl sub_08342074
	.global _08342614
_08342614:
	adds r0, r5, #0x0
	adds r0, #0x88
	ldr r1, [r0, #0x00]
	ldr r0, _0834267C @ =0x00011940
	cmp r1, r0
	ble _0834263C
	adds r0, r5, #0x0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _0834263C
	ldr r0, _08342680 @ =0x020390AC
	ldr r0, [r0, #0x00]
	movs r1, #0x3F
	ands r0, r1
	cmp r0, #0x00
	bne _0834263C
	adds r0, r5, #0x0
	bl sub_08342FAC
	.global _0834263C
_0834263C:
	ldr r0, _08342684 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08342690
	ldr r0, _08342688 @ =0x0203E1B0
	ldrb r0, [r0, #0x00]
	cmp r4, r0
	bne _083426B2
	adds r0, r4, #0x0
	bl sub_083415B0
	ldr r0, _0834268C @ =0x0203D520
	lsls r1, r4, #0x01
	adds r1, r1, r4
	lsls r1, r1, #0x03
	adds r1, r1, r4
	lsls r1, r1, #0x04
	adds r1, r1, r0
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _083426B2
	cmp r0, #0x63
	beq _083426B2
	movs r0, #0xB3
	lsls r0, r0, #0x01
	adds r1, r1, r0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	b _083426B2
	.global _0834267C
_0834267C: .4byte 0x00011940
	.global _08342680
_08342680: .4byte 0x020390AC
	.global _08342684
_08342684: .4byte 0x020390EC
	.global _08342688
_08342688: .4byte 0x0203E1B0
	.global _0834268C
_0834268C: .4byte 0x0203D520
	.global _08342690
_08342690:
	cmp r4, #0x00
	bne _083426B2
	movs r0, #0x00
	bl sub_083415B0
	ldr r1, _083426C4 @ =0x0203D520
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _083426B2
	cmp r0, #0x63
	beq _083426B2
	adds r2, #0x16
	adds r0, r1, r2
	strb r4, [r0, #0x00]
	.global _083426B2
_083426B2:
	movs r0, #0xAE
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r0, [r1, #0x00]
	adds r0, #0x01
	str r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _083426C4
_083426C4: .4byte 0x0203D520
	thumb_func_start sub_083426C8
sub_083426C8:
	push {r4, r5, r6, r7, lr}
	bl sub_08339B4C
	ldr r5, _083427AC @ =0x0203D520
	ldr r0, _083427B0 @ =0x020390A0
	ldrb r7, [r0, #0x00]
	ldr r0, _083427B4 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _083426E4
	ldr r0, _083427B8 @ =0x0203916C
	ldrb r1, [r0, #0x00]
	cmp r1, #0x04
	bne _083426EA
	.global _083426E4
_083426E4:
	ldr r0, _083427BC @ =0x020390BC
	ldrb r7, [r0, #0x00]
	ldr r0, _083427B8 @ =0x0203916C
	.global _083426EA
_083426EA:
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _083426F2
	movs r7, #0x01
	.global _083426F2
_083426F2:
	ldr r1, _083427C0 @ =0x0203D4E8
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	movs r6, #0x00
	cmp r6, r7
	beq _083427A4
	movs r0, #0xC6
	lsls r0, r0, #0x01
	adds r4, r5, r0
	.global _08342706
_08342706:
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0x0
	bl sub_083425C4
	ldr r1, _083427C4 @ =0x02026DC4
	ldr r0, _083427C8 @ =0x020390DC
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r2, r0, r1
	ldrh r1, [r4, #0x00]
	ldrh r0, [r2, #0x00]
	cmp r1, r0
	bhi _08342764
	ldr r0, [r5, #0x50]
	ldr r1, _083427CC @ =0x0000FFFF
	ands r0, r1
	ldrh r2, [r2, #0x00]
	cmp r0, r2
	bcc _08342764
	adds r0, r5, #0x0
	bl sub_08340028
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08342764
	ldr r0, _083427AC @ =0x0203D520
	cmp r5, r0
	beq _08342796
	ldr r0, _083427D0 @ =0x0203E0E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08342764
	bl sub_08340004
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x63
	beq _08342764
	bl sub_08340004
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0x0
	bl sub_08341280
	.global _08342764
_08342764:
	ldr r0, _083427AC @ =0x0203D520
	cmp r5, r0
	beq _08342796
	ldr r1, _083427D4 @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08342796
	ldr r0, _083427D8 @ =0x02026DDC
	ldr r1, _083427C8 @ =0x020390DC
	ldrb r1, [r1, #0x00]
	lsls r1, r1, #0x01
	adds r2, r1, r0
	ldrh r0, [r4, #0x00]
	ldrh r1, [r2, #0x00]
	cmp r0, r1
	bhi _08342796
	ldr r0, [r5, #0x50]
	ldr r1, _083427CC @ =0x0000FFFF
	ands r0, r1
	ldrh r2, [r2, #0x00]
	cmp r0, r2
	bcc _08342796
	movs r0, #0x00
	strb r0, [r4, #0x03]
	.global _08342796
_08342796:
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r4, r4, r0
	adds r5, r5, r0
	adds r6, #0x01
	cmp r6, r7
	bne _08342706
	.global _083427A4
_083427A4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _083427AC
_083427AC: .4byte 0x0203D520
	.global _083427B0
_083427B0: .4byte 0x020390A0
	.global _083427B4
_083427B4: .4byte 0x020390EC
	.global _083427B8
_083427B8: .4byte 0x0203916C
	.global _083427BC
_083427BC: .4byte 0x020390BC
	.global _083427C0
_083427C0: .4byte 0x0203D4E8
	.global _083427C4
_083427C4: .4byte 0x02026DC4
	.global _083427C8
_083427C8: .4byte 0x020390DC
	.global _083427CC
_083427CC: .4byte 0x0000FFFF
	.global _083427D0
_083427D0: .4byte 0x0203E0E0
	.global _083427D4
_083427D4: .4byte 0x00000175
	.global _083427D8
_083427D8: .4byte 0x02026DDC
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xA0, 0x69, 0x10, 0x21, 0x08, 0x40, 0x00, 0x28, 0x08, 0xD0, 0x03, 0x48
	.byte 0x0B, 0x21, 0x0A, 0x22, 0xFC, 0xF7, 0x8C, 0xFB, 0x07, 0xE0, 0x00, 0x00, 0xF4, 0xD0, 0x00, 0x02
	.byte 0x15, 0x48, 0x0B, 0x21, 0x0A, 0x22, 0xFC, 0xF7, 0x83, 0xFB, 0xA0, 0x69, 0x01, 0x38, 0xA0, 0x61
	.byte 0xF7, 0xF7, 0x9E, 0xF9, 0x11, 0x49, 0x12, 0x48, 0x09, 0x88, 0x08, 0x40, 0x00, 0x28, 0x02, 0xD1
	.byte 0xA0, 0x69, 0x00, 0x28, 0x14, 0xD1, 0x0A, 0x20, 0x00, 0x21, 0xFA, 0xF7, 0x2F, 0xFD, 0xF7, 0xF7
	.byte 0x75, 0xF9, 0x80, 0x22, 0xD2, 0x04, 0x11, 0x88, 0x0A, 0x48, 0x08, 0x40, 0x10, 0x80, 0x0A, 0x49
	.byte 0x02, 0x20, 0x08, 0x70, 0x20, 0x1C, 0xFD, 0xF7, 0xB1, 0xFB, 0x20, 0x1C, 0xFD, 0xF7, 0x9C, 0xFB
	.byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x00, 0xD1, 0x00, 0x02, 0x18, 0x76, 0x03, 0x02
	.byte 0xFF, 0x03, 0x00, 0x00, 0xFF, 0xEF, 0x00, 0x00, 0xF0, 0x91, 0x03, 0x02
