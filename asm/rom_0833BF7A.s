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
	thumb_func_start sub_0833BF80
sub_0833BF80:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r1, _0833C098 @ =0x02039100
	movs r2, #0x00
	strb r2, [r1, #0x00]
	ldr r1, _0833C09C @ =0x020391CC
	strb r2, [r1, #0x00]
	ldr r1, _0833C0A0 @ =0x02039154
	strb r2, [r1, #0x00]
	ldr r1, _0833C0A4 @ =0x0203916C
	strb r6, [r1, #0x00]
	ldr r4, _0833C0A8 @ =0x020390F0
	strb r0, [r4, #0x00]
	adds r3, r1, #0x0
	cmp r6, #0x0F
	beq _0833BFAA
	ldr r1, _0833C0AC @ =0x020390A0
	movs r0, #0x05
	strb r0, [r1, #0x00]
	.global _0833BFAA
_0833BFAA:
	ldrb r2, [r3, #0x00]
	cmp r2, #0x02
	bne _0833BFB6
	ldr r1, _0833C0AC @ =0x020390A0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0833BFB6
_0833BFB6:
	cmp r2, #0x11
	bne _0833BFC0
	ldr r1, _0833C0AC @ =0x020390A0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0833BFC0
_0833BFC0:
	cmp r2, #0x0D
	bne _0833BFCA
	ldr r1, _0833C0AC @ =0x020390A0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0833BFCA
_0833BFCA:
	cmp r2, #0x0E
	bne _0833BFD4
	ldr r1, _0833C0AC @ =0x020390A0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0833BFD4
_0833BFD4:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0833BFE0
	ldr r1, _0833C0AC @ =0x020390A0
	movs r0, #0x02
	strb r0, [r1, #0x00]
	.global _0833BFE0
_0833BFE0:
	ldr r0, _0833C0B0 @ =0x020390DC
	ldrb r1, [r0, #0x00]
	adds r5, r0, #0x0
	cmp r1, #0x06
	bls _0833C000
	cmp r1, #0x08
	beq _0833C000
	cmp r1, #0x09
	beq _0833C000
	cmp r1, #0x0A
	beq _0833C000
	cmp r1, #0x0B
	beq _0833C000
	ldr r1, _0833C0AC @ =0x020390A0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0833C000
_0833C000:
	ldrb r0, [r3, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _0833C014
	ldr r0, _0833C0AC @ =0x020390A0
	ldr r1, _0833C0B4 @ =0x020390BC
	ldrb r1, [r1, #0x00]
	strb r1, [r0, #0x00]
	.global _0833C014
_0833C014:
	ldr r0, _0833C0B8 @ =0x020391E0
	movs r4, #0x00
	str r4, [r0, #0x00]
	str r4, [r0, #0x04]
	str r4, [r0, #0x08]
	str r4, [r0, #0x0C]
	ldrb r0, [r5, #0x00]
	bl sub_0833CD2C
	ldrb r0, [r5, #0x00]
	bl sub_0833F448
	ldrb r0, [r5, #0x00]
	bl sub_0833D9E8
	bl sub_0833EE20
	bl sub_0833BF20
	ldr r1, _0833C0BC @ =0x02039158
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r1, #0x00]
	movs r0, #0x32
	bl sub_0833D3E4
	ldrb r0, [r5, #0x00]
	bl sub_08343504
	bl sub_0833F9A8
	bl sub_0833FF1C
	bl sub_0833D7D4
	bl sub_0833D680
	bl sub_0833D9D8
	ldr r1, _0833C0C0 @ =0x020391D4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _0833C0C4 @ =0x020390D0
	strb r4, [r1, #0x00]
	ldrb r0, [r1, #0x00]
	subs r6, #0x03
	cmp r0, #0x00
	bne _0833C07A
	.global _0833C074
_0833C074:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0833C074
	.global _0833C07A
_0833C07A:
	bl sub_08339B18
	ldr r0, _0833C0C8 @ =0x020390FC
	movs r1, #0x00
	strb r1, [r0, #0x00]
	bl sub_0833BF6C
	ldr r0, _0833C0A4 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0E
	bne _0833C0CC
	bl sub_0833EDF8
	b _0833C0D0
	.byte 0x00, 0x00
	.global _0833C098
_0833C098: .4byte 0x02039100
	.global _0833C09C
_0833C09C: .4byte 0x020391CC
	.global _0833C0A0
_0833C0A0: .4byte 0x02039154
	.global _0833C0A4
_0833C0A4: .4byte 0x0203916C
	.global _0833C0A8
_0833C0A8: .4byte 0x020390F0
	.global _0833C0AC
_0833C0AC: .4byte 0x020390A0
	.global _0833C0B0
_0833C0B0: .4byte 0x020390DC
	.global _0833C0B4
_0833C0B4: .4byte 0x020390BC
	.global _0833C0B8
_0833C0B8: .4byte 0x020391E0
	.global _0833C0BC
_0833C0BC: .4byte 0x02039158
	.global _0833C0C0
_0833C0C0: .4byte 0x020391D4
	.global _0833C0C4
_0833C0C4: .4byte 0x020390D0
	.global _0833C0C8
_0833C0C8: .4byte 0x020390FC
	.global _0833C0CC
_0833C0CC:
	bl sub_0833EDB8
	.global _0833C0D0
_0833C0D0:
	ldr r4, _0833C10C @ =0x020390F0
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0833C11C
	ldr r0, _0833C110 @ =0x0203E120
	ldrb r0, [r0, #0x02]
	cmp r0, #0x00
	beq _0833C0E6
	movs r0, #0x01
	bl sub_0833A8C8
	.global _0833C0E6
_0833C0E6:
	ldr r1, _0833C114 @ =0x020390D4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _0833C118 @ =0x020250EC
	movs r0, #0x02
	strb r0, [r1, #0x00]
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0833C11C
	movs r4, #0x00
	.global _0833C0FA
_0833C0FA:
	bl sub_083426C8
	adds r4, #0x01
	cmp r4, #0x64
	bne _0833C0FA
	bl sub_08342868
	b _0833C12E
	.byte 0x00, 0x00
	.global _0833C10C
_0833C10C: .4byte 0x020390F0
	.global _0833C110
_0833C110: .4byte 0x0203E120
	.global _0833C114
_0833C114: .4byte 0x020390D4
	.global _0833C118
_0833C118: .4byte 0x020250EC
	.global _0833C11C
_0833C11C:
	ldr r0, _0833C188 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _0833C12E
	bl sub_08342B04
	.global _0833C12E
_0833C12E:
	ldr r0, _0833C188 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _0833C148
	cmp r0, #0x0D
	beq _0833C148
	cmp r0, #0x0E
	beq _0833C148
	cmp r0, #0x0F
	beq _0833C148
	ldr r1, _0833C18C @ =0x020390B8
	cmp r0, #0x11
	bne _0833C160
	.global _0833C148
_0833C148:
	ldr r1, _0833C18C @ =0x020390B8
	movs r0, #0x01
	strb r0, [r1, #0x00]
	movs r4, #0x00
	.global _0833C150
_0833C150:
	bl sub_083426C8
	adds r4, #0x01
	cmp r4, #0x14
	bne _0833C150
	ldr r1, _0833C18C @ =0x020390B8
	movs r0, #0x00
	strb r0, [r1, #0x00]
	.global _0833C160
_0833C160:
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r0, _0833C190 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833C1A8
	ldr r0, _0833C194 @ =0x04000128
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x1A
	lsrs r1, r1, #0x1E
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _0833C198 @ =0x0203D520
	adds r0, r0, r1
	bl sub_0833D5F4
	b _0833C1AE
	.global _0833C188
_0833C188: .4byte 0x0203916C
	.global _0833C18C
_0833C18C: .4byte 0x020390B8
	.global _0833C190
_0833C190: .4byte 0x020390EC
	.global _0833C194
_0833C194: .4byte 0x04000128
	.global _0833C198
_0833C198: .4byte 0x0203D520
	.global _0833C19C
_0833C19C:
	ldr r1, _0833C1A4 @ =0x02039154
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _0833C582
	.global _0833C1A4
_0833C1A4: .4byte 0x02039154
	.global _0833C1A8
_0833C1A8:
	ldr r0, _0833C230 @ =0x0203D520
	bl sub_0833D5F4
	.global _0833C1AE
_0833C1AE:
	ldr r0, _0833C234 @ =0x02039110
	ldr r1, [r0, #0x08]
	str r1, [r0, #0x00]
	ldr r1, [r0, #0x0C]
	str r1, [r0, #0x04]
	ldr r0, _0833C238 @ =0x020390AC
	movs r4, #0x00
	str r4, [r0, #0x00]
	ldr r0, _0833C23C @ =0x020391F0
	strb r4, [r0, #0x00]
	ldr r1, _0833C240 @ =0x020390C4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _0833C1D4
	bl sub_08344878
	.global _0833C1D4
_0833C1D4:
	movs r0, #0x38
	bl sub_0833A8C8
	ldr r0, _0833C244 @ =0x0203921C
	strb r4, [r0, #0x00]
	ldr r0, _0833C248 @ =0x02039134
	movs r1, #0x00
	strh r4, [r0, #0x00]
	movs r7, #0x00
	ldr r0, _0833C24C @ =0x02039218
	strb r1, [r0, #0x03]
	strb r1, [r0, #0x02]
	strb r1, [r0, #0x01]
	strb r1, [r0, #0x00]
	ldr r0, _0833C250 @ =0x02039154
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833C1FA
	b _0833C57E
	.global _0833C1FA
_0833C1FA:
	bl sub_0833FA3C
	bl sub_0833D680
	ldr r0, _0833C254 @ =0x02039160
	movs r1, #0x4B
	movs r2, #0x3C
	bl sub_08343148
	ldr r0, _0833C244 @ =0x0203921C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833C21E
	ldr r0, _0833C258 @ =0x02039170
	movs r1, #0x4B
	movs r2, #0x5A
	bl sub_08343148
	.global _0833C21E
_0833C21E:
	ldr r1, _0833C248 @ =0x02039134
	movs r0, #0x00
	strh r0, [r1, #0x00]
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bls _0833C25C
	ldr r3, _0833C230 @ =0x0203D520
	b _0833C26E
	.global _0833C230
_0833C230: .4byte 0x0203D520
	.global _0833C234
_0833C234: .4byte 0x02039110
	.global _0833C238
_0833C238: .4byte 0x020390AC
	.global _0833C23C
_0833C23C: .4byte 0x020391F0
	.global _0833C240
_0833C240: .4byte 0x020390C4
	.global _0833C244
_0833C244: .4byte 0x0203921C
	.global _0833C248
_0833C248: .4byte 0x02039134
	.global _0833C24C
_0833C24C: .4byte 0x02039218
	.global _0833C250
_0833C250: .4byte 0x02039154
	.global _0833C254
_0833C254: .4byte 0x02039160
	.global _0833C258
_0833C258: .4byte 0x02039170
	.global _0833C25C
_0833C25C:
	ldr r0, _0833C2C8 @ =0x0203E1B0
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _0833C2CC @ =0x0203D520
	adds r3, r0, r1
	.global _0833C26E
_0833C26E:
	ldr r2, _0833C2D0 @ =0x02025190
	adds r0, r3, #0x0
	adds r0, #0x3E
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r2
	ldr r2, [r0, #0x00]
	adds r3, #0x40
	ldr r0, _0833C2D4 @ =0x020251A4
	adds r1, r1, r0
	ldrb r1, [r1, #0x00]
	ldrh r3, [r3, #0x00]
	adds r0, r1, #0x0
	muls r0, r3
	asrs r0, r0, #0x06
	adds r2, r2, r0
	lsls r2, r2, #0x10
	asrs r2, r2, #0x13
	ldr r0, _0833C2D8 @ =0x02038FB0
	movs r1, #0x01
	bl sub_0833B81C
	ldr r0, _0833C2DC @ =0x020390F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833C2EC
	ldr r0, _0833C2E0 @ =0x0203D6B0
	bl sub_0833D5F4
	ldr r2, _0833C2E4 @ =0x020250EC
	ldr r0, _0833C2E8 @ =0x020390AC
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bge _0833C2B4
	adds r0, #0xFF
	.global _0833C2B4
_0833C2B4:
	asrs r1, r0, #0x08
	strb r1, [r2, #0x00]
	movs r0, #0x07
	ands r0, r1
	cmp r0, #0x00
	bne _0833C346
	movs r0, #0x04
	strb r0, [r2, #0x00]
	b _0833C346
	.byte 0x00, 0x00
	.global _0833C2C8
_0833C2C8: .4byte 0x0203E1B0
	.global _0833C2CC
_0833C2CC: .4byte 0x0203D520
	.global _0833C2D0
_0833C2D0: .4byte 0x02025190
	.global _0833C2D4
_0833C2D4: .4byte 0x020251A4
	.global _0833C2D8
_0833C2D8: .4byte 0x02038FB0
	.global _0833C2DC
_0833C2DC: .4byte 0x020390F0
	.global _0833C2E0
_0833C2E0: .4byte 0x0203D6B0
	.global _0833C2E4
_0833C2E4: .4byte 0x020250EC
	.global _0833C2E8
_0833C2E8: .4byte 0x020390AC
	.global _0833C2EC
_0833C2EC:
	ldr r0, _0833C310 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833C31C
	ldr r0, _0833C314 @ =0x04000128
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x1A
	lsrs r1, r1, #0x1E
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _0833C318 @ =0x0203D520
	adds r0, r0, r1
	bl sub_0833D5F4
	b _0833C322
	.global _0833C310
_0833C310: .4byte 0x020390EC
	.global _0833C314
_0833C314: .4byte 0x04000128
	.global _0833C318
_0833C318: .4byte 0x0203D520
	.global _0833C31C
_0833C31C:
	ldr r0, _0833C3DC @ =0x0203D520
	bl sub_0833D5F4
	.global _0833C322
_0833C322:
	ldr r0, _0833C3E0 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _0833C33A
	cmp r0, #0x0D
	beq _0833C33A
	cmp r0, #0x0E
	beq _0833C33A
	cmp r0, #0x0F
	beq _0833C33A
	cmp r0, #0x11
	bne _0833C346
	.global _0833C33A
_0833C33A:
	ldr r2, _0833C3E4 @ =0x02039110
	ldr r1, _0833C3DC @ =0x0203D520
	ldr r0, [r1, #0x00]
	str r0, [r2, #0x00]
	ldr r0, [r1, #0x08]
	str r0, [r2, #0x04]
	.global _0833C346
_0833C346:
	bl sub_0833D448
	bl sub_0833D5B8
	bl sub_0833D57C
	bl sub_0833FFC4
	bl sub_083419D8
	bl sub_0833DF58
	ldr r0, _0833C3E8 @ =0x020390D4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833C37E
	ldr r0, _0833C3E0 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _0833C37E
	cmp r0, #0x0D
	beq _0833C37E
	cmp r0, #0x0E
	beq _0833C37E
	cmp r0, #0x0F
	beq _0833C37E
	cmp r0, #0x11
	bne _0833C382
	.global _0833C37E
_0833C37E:
	bl sub_083426C8
	.global _0833C382
_0833C382:
	ldr r1, _0833C3E4 @ =0x02039110
	ldr r0, [r1, #0x00]
	ldr r1, [r1, #0x04]
	bl sub_0833CF10
	bl sub_0833D9D8
	bl sub_08340EFC
	ldr r0, _0833C3EC @ =0x020391D4
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, _0833C3F0 @ =0x020390F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833C40C
	ldr r0, _0833C3F4 @ =0x0203761C
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833C3AC
	b _0833C506
	.global _0833C3AC
_0833C3AC:
	ldr r0, _0833C3F8 @ =0x020391CC
	strb r1, [r0, #0x00]
	ldr r1, _0833C3FC @ =0x020391F0
	movs r0, #0x02
	strb r0, [r1, #0x00]
	bl sub_08339B18
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2, #0x00]
	ldr r3, _0833C400 @ =0x0000EFFF
	adds r1, r3, #0x0
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r0, _0833C404 @ =0x0203E120
	ldrb r0, [r0, #0x02]
	cmp r0, #0x00
	bne _0833C3D2
	b _0833C4E8
	.global _0833C3D2
_0833C3D2:
	ldr r0, _0833C408 @ =0x02038F70
	movs r1, #0x02
	bl sub_0833AA60
	b _0833C4E8
	.global _0833C3DC
_0833C3DC: .4byte 0x0203D520
	.global _0833C3E0
_0833C3E0: .4byte 0x0203916C
	.global _0833C3E4
_0833C3E4: .4byte 0x02039110
	.global _0833C3E8
_0833C3E8: .4byte 0x020390D4
	.global _0833C3EC
_0833C3EC: .4byte 0x020391D4
	.global _0833C3F0
_0833C3F0: .4byte 0x020390F0
	.global _0833C3F4
_0833C3F4: .4byte 0x0203761C
	.global _0833C3F8
_0833C3F8: .4byte 0x020391CC
	.global _0833C3FC
_0833C3FC: .4byte 0x020391F0
	.global _0833C400
_0833C400: .4byte 0x0000EFFF
	.global _0833C404
_0833C404: .4byte 0x0203E120
	.global _0833C408
_0833C408: .4byte 0x02038F70
	.global _0833C40C
_0833C40C:
	ldr r1, _0833C434 @ =0x0203916C
	ldrb r0, [r1, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r1, #0x0
	cmp r0, #0x01
	bls _0833C440
	ldr r0, _0833C438 @ =0x020391F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833C440
	ldr r0, _0833C43C @ =0x020392C4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833C46E
	bl sub_0833DBC8
	b _0833C468
	.byte 0x00, 0x00
	.global _0833C434
_0833C434: .4byte 0x0203916C
	.global _0833C438
_0833C438: .4byte 0x020391F0
	.global _0833C43C
_0833C43C: .4byte 0x020392C4
	.global _0833C440
_0833C440:
	ldr r0, _0833C45C @ =0x020392C4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833C46E
	ldr r0, _0833C460 @ =0x020391F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833C46E
	ldrb r3, [r3, #0x00]
	cmp r3, #0x04
	bne _0833C464
	bl sub_0833DCB0
	b _0833C468
	.global _0833C45C
_0833C45C: .4byte 0x020392C4
	.global _0833C460
_0833C460: .4byte 0x020391F0
	.global _0833C464
_0833C464:
	bl sub_0833DBF4
	.global _0833C468
_0833C468:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0833C470
	.global _0833C46E
_0833C46E:
	movs r0, #0x00
	.global _0833C470
_0833C470:
	cmp r0, #0x01
	beq _0833C482
	cmp r0, #0x01
	ble _0833C506
	cmp r0, #0x02
	beq _0833C48A
	cmp r0, #0x27
	beq _0833C504
	b _0833C506
	.global _0833C482
_0833C482:
	movs r0, #0x38
	bl sub_0833A8C8
	b _0833C506
	.global _0833C48A
_0833C48A:
	ldr r0, _0833C4F4 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	beq _0833C4CA
	cmp r0, #0x0E
	beq _0833C4CA
	cmp r0, #0x00
	beq _0833C4CA
	cmp r0, #0x07
	beq _0833C4CA
	cmp r0, #0x06
	beq _0833C4CA
	cmp r0, #0x09
	beq _0833C4CA
	cmp r0, #0x05
	beq _0833C4CA
	cmp r0, #0x11
	beq _0833C4CA
	cmp r0, #0x01
	beq _0833C4CA
	cmp r0, #0x03
	beq _0833C4CA
	cmp r0, #0x0C
	beq _0833C4CA
	cmp r0, #0x0D
	beq _0833C4CA
	cmp r0, #0x10
	beq _0833C4CA
	cmp r0, #0x0F
	beq _0833C4CA
	cmp r0, #0x11
	bne _0833C506
	.global _0833C4CA
_0833C4CA:
	ldr r1, _0833C4F8 @ =0x020391CC
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _0833C4FC @ =0x020391F0
	movs r0, #0x02
	strb r0, [r1, #0x00]
	bl sub_08339B18
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2, #0x00]
	ldr r3, _0833C500 @ =0x0000EFFF
	adds r1, r3, #0x0
	ands r0, r1
	strh r0, [r2, #0x00]
	.global _0833C4E8
_0833C4E8:
	movs r0, #0x19
	movs r1, #0x00
	bl sub_0833D288
	b _0833C506
	.byte 0x00, 0x00
	.global _0833C4F4
_0833C4F4: .4byte 0x0203916C
	.global _0833C4F8
_0833C4F8: .4byte 0x020391CC
	.global _0833C4FC
_0833C4FC: .4byte 0x020391F0
	.global _0833C500
_0833C500: .4byte 0x0000EFFF
	.global _0833C504
_0833C504:
	movs r7, #0x01
	.global _0833C506
_0833C506:
	ldr r0, _0833C530 @ =0x020390EC
	ldrb r1, [r0, #0x00]
	cmp r1, #0x00
	beq _0833C544
	bl sub_0833C874
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0x00
	beq _0833C51C
	b _0833C19C
	.global _0833C51C
_0833C51C:
	ldr r0, _0833C534 @ =0x020390D0
	strb r1, [r0, #0x00]
	ldr r4, _0833C538 @ =0x02039154
	adds r2, r0, #0x0
	ldr r3, _0833C53C @ =0x020390AC
	ldr r5, _0833C540 @ =0x020391F0
	.global _0833C528
_0833C528:
	ldrb r0, [r2, #0x00]
	cmp r0, #0x00
	beq _0833C528
	b _0833C55E
	.global _0833C530
_0833C530: .4byte 0x020390EC
	.global _0833C534
_0833C534: .4byte 0x020390D0
	.global _0833C538
_0833C538: .4byte 0x02039154
	.global _0833C53C
_0833C53C: .4byte 0x020390AC
	.global _0833C540
_0833C540: .4byte 0x020391F0
	.global _0833C544
_0833C544:
	ldr r0, _0833C588 @ =0x020390D0
	strb r1, [r0, #0x00]
	ldrb r1, [r0, #0x00]
	ldr r4, _0833C58C @ =0x02039154
	adds r2, r0, #0x0
	ldr r3, _0833C590 @ =0x020390AC
	ldr r5, _0833C594 @ =0x020391F0
	cmp r1, #0x00
	bne _0833C55E
	adds r1, r2, #0x0
	.global _0833C558
_0833C558:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0833C558
	.global _0833C55E
_0833C55E:
	ldr r0, [r3, #0x00]
	adds r0, #0x01
	str r0, [r3, #0x00]
	ldrb r5, [r5, #0x00]
	cmp r5, #0x02
	bne _0833C576
	ldr r0, _0833C598 @ =0x020392C4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833C576
	movs r0, #0x01
	strb r0, [r4, #0x00]
	.global _0833C576
_0833C576:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _0833C57E
	b _0833C1FA
	.global _0833C57E
_0833C57E:
	cmp r7, #0x00
	beq _0833C59C
	.global _0833C582
_0833C582:
	movs r0, #0x01
	b _0833C5A4
	.byte 0x00, 0x00
	.global _0833C588
_0833C588: .4byte 0x020390D0
	.global _0833C58C
_0833C58C: .4byte 0x02039154
	.global _0833C590
_0833C590: .4byte 0x020390AC
	.global _0833C594
_0833C594: .4byte 0x020391F0
	.global _0833C598
_0833C598: .4byte 0x020392C4
	.global _0833C59C
_0833C59C:
	ldr r0, _0833C5AC @ =0x02038FB0
	bl sub_0833B074
	movs r0, #0x00
	.global _0833C5A4
_0833C5A4:
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _0833C5AC
_0833C5AC: .4byte 0x02038FB0
	.byte 0x10, 0xB5, 0xFD, 0xF7, 0x13, 0xFE, 0x09, 0x4A, 0x10, 0x88, 0x01, 0x30, 0x10, 0x80, 0x08, 0x49
	.byte 0x08, 0x88, 0x01, 0x30, 0x08, 0x80, 0x07, 0x48, 0x00, 0x78, 0x00, 0x28, 0x14, 0xD0, 0x10, 0x88
	.byte 0x01, 0x28, 0x0B, 0xD9, 0x04, 0x49, 0x01, 0x20, 0x12, 0xE0, 0x00, 0x00, 0x34, 0x91, 0x03, 0x02
	.byte 0x7C, 0x91, 0x03, 0x02, 0xEC, 0x90, 0x03, 0x02, 0xFC, 0x90, 0x03, 0x02, 0x01, 0x49, 0x00, 0x20
	.byte 0x06, 0xE0, 0x00, 0x00, 0xFC, 0x90, 0x03, 0x02, 0x22, 0x49, 0x01, 0x20, 0x0A, 0x78, 0x50, 0x40
	.byte 0x08, 0x70, 0x21, 0x48, 0x00, 0x78, 0x00, 0x28, 0x01, 0xD1, 0x01, 0x20, 0x08, 0x70, 0x1F, 0x49
	.byte 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x00, 0x06, 0x00, 0x0E, 0x02, 0x28, 0x53, 0xD9, 0x1C, 0x48
	.byte 0x00, 0x78, 0x04, 0x1C, 0x00, 0x2C, 0x4E, 0xD1, 0x0C, 0x70, 0x1A, 0x48, 0xE0, 0x21, 0xC9, 0x04
	.byte 0x80, 0x22, 0x52, 0x00, 0x08, 0xF0, 0x94, 0xFA, 0x17, 0x48, 0x00, 0x78, 0x00, 0x28, 0x3D, 0xD0
	.byte 0x16, 0x49, 0x17, 0x48, 0x00, 0x68, 0x08, 0x80, 0x02, 0x31, 0x16, 0x48, 0x00, 0x68, 0x08, 0x80
	.byte 0x06, 0x39, 0x15, 0x48, 0x00, 0x68, 0x08, 0x80, 0x02, 0x31, 0x14, 0x48, 0x00, 0x68, 0x08, 0x80
	.byte 0x06, 0x39, 0x13, 0x48, 0x00, 0x68, 0x08, 0x80, 0x02, 0x31, 0x12, 0x48, 0x00, 0x68, 0x08, 0x80
	.byte 0x11, 0x48, 0x04, 0x80, 0x02, 0x30, 0x04, 0x80, 0x00, 0xF0, 0x0C, 0xFD, 0x03, 0xF0, 0xA2, 0xFB
	.byte 0x1E, 0xE0, 0x00, 0x00, 0xFC, 0x90, 0x03, 0x02, 0xEC, 0x90, 0x03, 0x02, 0xC8, 0x91, 0x03, 0x02
	.byte 0xD0, 0x90, 0x03, 0x02, 0xE0, 0xAC, 0x03, 0x02, 0xD4, 0x91, 0x03, 0x02, 0x1C, 0x00, 0x00, 0x04
	.byte 0x90, 0x92, 0x03, 0x02, 0x98, 0x92, 0x03, 0x02, 0xA8, 0x92, 0x03, 0x02, 0x40, 0x92, 0x03, 0x02
	.byte 0x5C, 0x92, 0x03, 0x02, 0x60, 0x92, 0x03, 0x02, 0x10, 0x00, 0x00, 0x04, 0x03, 0xF0, 0x82, 0xFB
	.byte 0x09, 0x49, 0x01, 0x20, 0x08, 0x70, 0x00, 0xF0, 0x0D, 0xFF, 0xFE, 0xF7, 0xF7, 0xF8, 0x07, 0x4B
	.byte 0x00, 0x20, 0x18, 0x80, 0x06, 0x4A, 0x10, 0x88, 0x01, 0x21, 0x08, 0x43, 0x10, 0x80, 0x19, 0x80
	.byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xD0, 0x90, 0x03, 0x02, 0x08, 0x02, 0x00, 0x04
	.byte 0xF8, 0x7F, 0x00, 0x03, 0x00, 0x04, 0xFE, 0x21, 0xC9, 0x03, 0x01, 0x40, 0x09, 0x0C, 0x7F, 0x29
	.byte 0x01, 0xD0, 0x01, 0x20, 0x00, 0xE0, 0x00, 0x20, 0x70, 0x47, 0x00, 0x00
