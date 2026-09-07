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
	thumb_func_start sub_0833C70C
sub_0833C70C:
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r3, r2, #0x0
	movs r0, #0x08
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	negs r0, r0
	lsrs r1, r0, #0x1F
	movs r0, #0x02
	ands r0, r2
	cmp r0, #0x00
	beq _0833C72A
	movs r0, #0x02
	orrs r1, r0
	.global _0833C72A
_0833C72A:
	movs r0, #0x01
	ands r0, r2
	cmp r0, #0x00
	beq _0833C73A
	movs r0, #0x04
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	.global _0833C73A
_0833C73A:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0x00
	beq _0833C74A
	movs r0, #0x08
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	.global _0833C74A
_0833C74A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0x00
	beq _0833C75A
	movs r0, #0x10
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	.global _0833C75A
_0833C75A:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0x00
	beq _0833C76A
	movs r0, #0x20
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	.global _0833C76A
_0833C76A:
	movs r0, #0x40
	ands r3, r0
	cmp r3, #0x00
	beq _0833C778
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	.global _0833C778
_0833C778:
	adds r0, r1, #0x0
	bx lr
	thumb_func_start sub_0833C77C
sub_0833C77C:
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r3, r2, #0x0
	movs r1, #0x01
	ands r1, r2
	negs r0, r1
	orrs r0, r1
	asrs r1, r0, #0x1F
	movs r4, #0x08
	ands r1, r4
	movs r0, #0x02
	ands r0, r2
	cmp r0, #0x00
	beq _0833C79E
	movs r0, #0x02
	orrs r1, r0
	.global _0833C79E
_0833C79E:
	movs r0, #0x04
	ands r0, r2
	cmp r0, #0x00
	beq _0833C7AA
	movs r0, #0x01
	orrs r1, r0
	.global _0833C7AA
_0833C7AA:
	adds r0, r2, #0x0
	ands r0, r4
	cmp r0, #0x00
	beq _0833C7BA
	movs r0, #0x10
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	.global _0833C7BA
_0833C7BA:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0x00
	beq _0833C7CA
	movs r0, #0x20
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	.global _0833C7CA
_0833C7CA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0x00
	beq _0833C7DA
	movs r0, #0x80
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	.global _0833C7DA
_0833C7DA:
	movs r0, #0x40
	ands r3, r0
	cmp r3, #0x00
	beq _0833C7E8
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	.global _0833C7E8
_0833C7E8:
	adds r0, r1, #0x0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0xB5, 0x81, 0xB0, 0x03, 0x48, 0x00, 0x78, 0x00, 0x28, 0x05, 0xD1, 0x08, 0xF0, 0xBA, 0xF9
	.byte 0x09, 0xE0, 0x00, 0x00, 0xB0, 0xE1, 0x03, 0x02, 0x04, 0x4A, 0x80, 0x23, 0x11, 0x88, 0x18, 0x1C
	.byte 0x08, 0x40, 0x00, 0x28, 0xFA, 0xD0, 0x01, 0xB0, 0x01, 0xBC, 0x00, 0x47, 0xF8, 0x7F, 0x00, 0x03
	.byte 0x8A, 0xB0, 0x0A, 0xB0, 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_0833C828
sub_0833C828:
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x18
	cmp r1, #0x00
	bne _0833C83C
	ldr r0, _0833C838 @ =0x02039180
	ldrh r0, [r0, #0x00]
	b _0833C846
	.global _0833C838
_0833C838: .4byte 0x02039180
	.global _0833C83C
_0833C83C:
	ldr r0, _0833C850 @ =0x02039180
	ldrh r0, [r0, #0x00]
	adds r0, #0x01
	movs r1, #0x07
	ands r0, r1
	.global _0833C846
_0833C846:
	cmp r2, r0
	beq _0833C854
	movs r0, #0x00
	b _0833C856
	.byte 0x00, 0x00
	.global _0833C850
_0833C850: .4byte 0x02039180
	.global _0833C854
_0833C854:
	movs r0, #0x01
	.global _0833C856
_0833C856:
	bx lr
	thumb_func_start sub_0833C858
sub_0833C858:
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x15
	movs r2, #0x03
	ands r0, r2
	cmp r0, #0x03
	beq _0833C870
	lsrs r0, r1, #0x13
	ands r0, r2
	cmp r0, #0x03
	beq _0833C870
	movs r0, #0x01
	b _0833C872
	.global _0833C870
_0833C870:
	movs r0, #0x00
	.global _0833C872
_0833C872:
	bx lr
	thumb_func_start sub_0833C874
sub_0833C874:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x020
	ldr r0, _0833C8FC @ =0x04000130
	ldrh r0, [r0, #0x00]
	mvns r0, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0x0
	bl sub_0833C70C
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r3, _0833C900 @ =0x020390BC
	ldr r0, [sp, #0x008]
	ldrb r2, [r3, #0x00]
	cmp r0, r2
	bge _0833C8C6
	ldr r5, _0833C904 @ =0x0203E160
	movs r2, #0x00
	ldr r4, _0833C908 @ =0x02039188
	.global _0833C8A8
_0833C8A8:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x03
	adds r0, r0, r5
	strh r2, [r0, #0x00]
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	adds r0, r0, r4
	strh r2, [r0, #0x00]
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldrb r6, [r3, #0x00]
	cmp r0, r6
	blt _0833C8A8
	.global _0833C8C6
_0833C8C6:
	movs r0, #0x00
	mov r10, r0
	movs r2, #0x00
	str r2, [sp, #0x018]
	movs r3, #0x00
	str r3, [sp, #0x01C]
	movs r4, #0x7F
	mov r9, r4
	adds r5, r1, #0x0
	ands r5, r4
	movs r6, #0x0F
	mov r8, r6
	ands r1, r6
	lsls r0, r1, #0x07
	orrs r5, r0
	.global _0833C8E4
_0833C8E4:
	ldr r0, _0833C900 @ =0x020390BC
	ldr r1, [sp, #0x01C]
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bls _0833C924
	ldr r0, _0833C90C @ =0x0203917C
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldr r0, _0833C910 @ =0x02039180
	strh r1, [r0, #0x00]
	movs r0, #0x01
	b _0833CC5A
	.global _0833C8FC
_0833C8FC: .4byte 0x04000130
	.global _0833C900
_0833C900: .4byte 0x020390BC
	.global _0833C904
_0833C904: .4byte 0x0203E160
	.global _0833C908
_0833C908: .4byte 0x02039188
	.global _0833C90C
_0833C90C: .4byte 0x0203917C
	.global _0833C910
_0833C910: .4byte 0x02039180
	.global _0833C914
_0833C914:
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r0, [sp, #0x01C]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x01C]
	b _0833C8E4
	.global _0833C924
_0833C924:
	mov r2, r10
	cmp r2, #0x00
	bne _0833C94C
	ldr r0, _0833C940 @ =0x02039180
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x0B
	orrs r0, r5
	ldr r3, _0833C944 @ =0xFFFF8000
	adds r1, r3, #0x0
	orrs r0, r1
	ldr r4, _0833C948 @ =0x0203DFB8
	strh r0, [r4, #0x00]
	adds r0, r4, #0x0
	b _0833C962
	.global _0833C940
_0833C940: .4byte 0x02039180
	.global _0833C944
_0833C944: .4byte 0xFFFF8000
	.global _0833C948
_0833C948: .4byte 0x0203DFB8
	.global _0833C94C
_0833C94C:
	ldr r0, _0833C97C @ =0x02039180
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x0B
	orrs r0, r5
	movs r6, #0x80
	lsls r6, r6, #0x07
	adds r1, r6, #0x0
	orrs r0, r1
	ldr r1, _0833C980 @ =0x0203DFB8
	strh r0, [r1, #0x00]
	adds r0, r1, #0x0
	.global _0833C962
_0833C962:
	ldrh r0, [r0, #0x00]
	bl sub_083448B0
	ldr r2, _0833C984 @ =0x03007FF8
	movs r0, #0x80
	ldrh r3, [r2, #0x00]
	ands r0, r3
	cmp r0, #0x00
	beq _0833C98C
	ldrh r0, [r2, #0x00]
	ldr r4, _0833C988 @ =0x0000FF7F
	adds r1, r4, #0x0
	b _0833C9A6
	.global _0833C97C
_0833C97C: .4byte 0x02039180
	.global _0833C980
_0833C980: .4byte 0x0203DFB8
	.global _0833C984
_0833C984: .4byte 0x03007FF8
	.global _0833C988
_0833C988: .4byte 0x0000FF7F
	.global _0833C98C
_0833C98C:
	ldr r1, _0833CAF0 @ =0x0203917C
	ldrh r0, [r1, #0x00]
	cmp r0, #0x64
	bhi _0833C914
	ldr r2, _0833CAF4 @ =0x03007FF8
	movs r0, #0x80
	ldrh r6, [r2, #0x00]
	ands r0, r6
	cmp r0, #0x00
	beq _0833C98C
	ldrh r0, [r2, #0x00]
	ldr r3, _0833CAF8 @ =0x0000FF7F
	adds r1, r3, #0x0
	.global _0833C9A6
_0833C9A6:
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r0, _0833CAFC @ =0x0203E1B0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833C9C8
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r1, _0833CB00 @ =0x00000257
	cmp r0, r1
	bgt _0833C9C8
	.global _0833C9BC
_0833C9BC:
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	cmp r0, r1
	ble _0833C9BC
	.global _0833C9C8
_0833C9C8:
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r3, _0833CB04 @ =0x020390BC
	ldr r0, [sp, #0x008]
	ldrb r4, [r3, #0x00]
	cmp r0, r4
	bge _0833C9F8
	ldr r2, _0833CB08 @ =0x0203E160
	.global _0833C9D8
_0833C9D8:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r6, sp
	adds r1, r6, r0
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x03
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldrb r1, [r3, #0x00]
	cmp r0, r1
	blt _0833C9D8
	.global _0833C9F8
_0833C9F8:
	mov r2, r10
	cmp r2, #0x00
	beq _0833CA00
	b _0833CB14
	.global _0833CA00
_0833CA00:
	movs r4, #0x00
	str r2, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r3, _0833CB04 @ =0x020390BC
	ldrb r3, [r3, #0x00]
	cmp r0, r3
	bge _0833CAAC
	movs r7, #0x0F
	ldr r6, _0833CB0C @ =0x0000FFFF
	.global _0833CA12
_0833CA12:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r1, sp
	adds r2, r1, r0
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r1, r0, #0x07
	mov r0, r8
	ldrh r2, [r2, #0x00]
	ands r0, r2
	ands r1, r7
	cmp r0, r1
	bne _0833CA9C
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	cmp r0, r6
	beq _0833CA9C
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833CA9C
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0E
	cmp r0, #0x02
	beq _0833CA64
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0E
	cmp r0, #0x01
	bne _0833CA9C
	.global _0833CA64
_0833CA64:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0B
	movs r1, #0x07
	ands r0, r1
	movs r1, #0x00
	bl sub_0833C828
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0833CA9C
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r2, sp
	adds r1, r2, r0
	mov r0, r9
	ldrh r1, [r1, #0x00]
	ands r0, r1
	bl sub_0833C858
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0833CA9C
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	.global _0833CA9C
_0833CA9C:
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r1, _0833CB04 @ =0x020390BC
	ldr r0, [sp, #0x008]
	ldrb r1, [r1, #0x00]
	cmp r0, r1
	blt _0833CA12
	.global _0833CAAC
_0833CAAC:
	ldr r3, _0833CB04 @ =0x020390BC
	ldrb r3, [r3, #0x00]
	cmp r4, r3
	beq _0833CAB6
	b _0833CC44
	.global _0833CAB6
_0833CAB6:
	movs r4, #0x01
	mov r10, r4
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r6, _0833CB04 @ =0x020390BC
	ldrb r6, [r6, #0x00]
	cmp r0, r6
	blt _0833CACA
	b _0833CC44
	.global _0833CACA
_0833CACA:
	ldr r3, _0833CB10 @ =0x02039188
	ldr r2, _0833CB04 @ =0x020390BC
	.global _0833CACE
_0833CACE:
	ldr r1, [sp, #0x008]
	lsls r1, r1, #0x01
	adds r1, r1, r3
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldrb r1, [r2, #0x00]
	cmp r0, r1
	blt _0833CACE
	b _0833CC44
	.byte 0x00, 0x00
	.global _0833CAF0
_0833CAF0: .4byte 0x0203917C
	.global _0833CAF4
_0833CAF4: .4byte 0x03007FF8
	.global _0833CAF8
_0833CAF8: .4byte 0x0000FF7F
	.global _0833CAFC
_0833CAFC: .4byte 0x0203E1B0
	.global _0833CB00
_0833CB00: .4byte 0x00000257
	.global _0833CB04
_0833CB04: .4byte 0x020390BC
	.global _0833CB08
_0833CB08: .4byte 0x0203E160
	.global _0833CB0C
_0833CB0C: .4byte 0x0000FFFF
	.global _0833CB10
_0833CB10: .4byte 0x02039188
	.global _0833CB14
_0833CB14:
	movs r4, #0x00
	str r4, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r2, _0833CBA4 @ =0x020390BC
	ldrb r2, [r2, #0x00]
	cmp r0, r2
	bge _0833CBFE
	.global _0833CB22
_0833CB22:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r3, sp
	adds r2, r3, r0
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r1, r0, #0x07
	mov r0, r8
	ldrh r2, [r2, #0x00]
	ands r0, r2
	mov r6, r8
	ands r1, r6
	cmp r0, r1
	bne _0833CBEE
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldr r0, _0833CBA8 @ =0x0000FFFF
	ldrh r1, [r1, #0x00]
	cmp r1, r0
	beq _0833CBEE
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833CBEE
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	adds r1, r3, r0
	mov r0, r9
	ldrh r1, [r1, #0x00]
	ands r0, r1
	bl sub_0833C858
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0833CBEE
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0E
	cmp r0, #0x01
	bne _0833CBAC
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0B
	movs r1, #0x07
	ands r0, r1
	movs r1, #0x00
	bl sub_0833C828
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0833CBAC
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	b _0833CBEE
	.byte 0x00, 0x00
	.global _0833CBA4
_0833CBA4: .4byte 0x020390BC
	.global _0833CBA8
_0833CBA8: .4byte 0x0000FFFF
	.global _0833CBAC
_0833CBAC:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0E
	cmp r0, #0x02
	bne _0833CBEE
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0B
	movs r1, #0x07
	ands r0, r1
	movs r1, #0x01
	bl sub_0833C828
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0833CBEE
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r1, sp
	adds r2, r1, r0
	ldr r1, _0833CC6C @ =0x02039188
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	strh r0, [r2, #0x00]
	.global _0833CBEE
_0833CBEE:
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r1, _0833CC70 @ =0x020390BC
	ldr r0, [sp, #0x008]
	ldrb r1, [r1, #0x00]
	cmp r0, r1
	blt _0833CB22
	.global _0833CBFE
_0833CBFE:
	ldr r2, _0833CC70 @ =0x020390BC
	ldrb r2, [r2, #0x00]
	cmp r4, r2
	bne _0833CC44
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r3, _0833CC70 @ =0x020390BC
	ldrb r3, [r3, #0x00]
	cmp r0, r3
	bge _0833CC40
	ldr r4, _0833CC74 @ =0x020390B0
	.global _0833CC16
_0833CC16:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r6, sp
	adds r1, r6, r0
	mov r0, r9
	ldrh r1, [r1, #0x00]
	ands r0, r1
	bl sub_0833C77C
	ldr r1, [sp, #0x008]
	lsls r1, r1, #0x01
	adds r1, r1, r4
	strh r0, [r1, #0x00]
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r1, _0833CC70 @ =0x020390BC
	ldr r0, [sp, #0x008]
	ldrb r1, [r1, #0x00]
	cmp r0, r1
	blt _0833CC16
	.global _0833CC40
_0833CC40:
	movs r0, #0x01
	str r0, [sp, #0x018]
	.global _0833CC44
_0833CC44:
	ldr r1, [sp, #0x018]
	cmp r1, #0x00
	bne _0833CC4C
	b _0833C8E4
	.global _0833CC4C
_0833CC4C:
	ldr r0, _0833CC78 @ =0x02039180
	ldrh r1, [r0, #0x00]
	adds r1, #0x01
	movs r2, #0x07
	ands r1, r2
	strh r1, [r0, #0x00]
	movs r0, #0x00
	.global _0833CC5A
_0833CC5A:
	add sp, #0x020
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _0833CC6C
_0833CC6C: .4byte 0x02039188
	.global _0833CC70
_0833CC70: .4byte 0x020390BC
	.global _0833CC74
_0833CC74: .4byte 0x020390B0
	.global _0833CC78
_0833CC78: .4byte 0x02039180
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0xB5, 0x12, 0x04, 0x16, 0x0C, 0x12, 0x4B, 0x02, 0x1C, 0x14, 0x88
	.byte 0x02, 0x32, 0x01, 0x25, 0xB5, 0x42, 0x19, 0xD2, 0x0C, 0x80, 0x02, 0x31, 0x9C, 0x42, 0x0D, 0xD1
	.byte 0x13, 0x88, 0x02, 0x32, 0x68, 0x1C, 0x00, 0x04, 0x05, 0x0C, 0x00, 0x2B, 0x06, 0xD0, 0x0C, 0x80
	.byte 0x02, 0x31, 0x58, 0x1E, 0x00, 0x04, 0x03, 0x0C, 0x00, 0x2B, 0xF8, 0xD1, 0x23, 0x1C, 0x14, 0x88
	.byte 0x02, 0x32, 0x68, 0x1C, 0x00, 0x04, 0x05, 0x0C, 0xB5, 0x42, 0xE5, 0xD3, 0x70, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00
	thumb_func_start sub_0833CCD4
sub_0833CCD4:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _0833CD18 @ =0x020251BC
	movs r1, #0x64
	adds r4, r0, #0x0
	muls r4, r1
	adds r0, r5, #0x4
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x07
	bl sub_08344B64
	adds r4, r4, r5
	ldr r0, [r4, #0x00]
	ldr r1, _0833CD1C @ =0x06008000
	movs r2, #0x80
	lsls r2, r2, #0x06
	bl sub_08344B64
	ldr r0, _0833CD20 @ =0x02039294
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldr r0, _0833CD24 @ =0x02039248
	strh r1, [r0, #0x00]
	ldr r0, _0833CD28 @ =0x020392A4
	strh r1, [r0, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833CD18
_0833CD18: .4byte 0x020251BC
	.global _0833CD1C
_0833CD1C: .4byte 0x06008000
	.global _0833CD20
_0833CD20: .4byte 0x02039294
	.global _0833CD24
_0833CD24: .4byte 0x02039248
	.global _0833CD28
_0833CD28: .4byte 0x020392A4
	thumb_func_start sub_0833CD2C
sub_0833CD2C:
	push {r4, r5, r6, lr}
	ldr r4, _0833CEBC @ =0xFFFFFDF8
	add sp, r4
	adds r6, r0, #0x0
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl sub_0833CCD4
	ldr r0, _0833CEC0 @ =0x02022428
	ldr r1, _0833CEC4 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08344B64
	ldr r5, _0833CEC8 @ =0x020251BC
	movs r0, #0x64
	adds r4, r6, #0x0
	muls r4, r0
	adds r0, r5, #0x0
	adds r0, #0x18
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x01
	add r1, sp, #0x008
	bl sub_08344B64
	ldr r0, _0833CECC @ =0x02021394
	add r1, sp, #0x1C8
	movs r2, #0x10
	bl sub_08344B64
	movs r0, #0x1E
	add r1, sp, #0x008
	bl sub_0833D31C
	ldr r1, _0833CED0 @ =0x02039244
	adds r0, r5, #0x0
	adds r0, #0x2C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CED4 @ =0x02039288
	adds r0, r5, #0x0
	adds r0, #0x34
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CED8 @ =0x02039228
	adds r0, r5, #0x0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEDC @ =0x02039268
	adds r0, r5, #0x0
	adds r0, #0x24
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEE0 @ =0x02039224
	adds r0, r5, #0x0
	adds r0, #0x28
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEE4 @ =0x02039238
	adds r0, r5, #0x0
	adds r0, #0x0C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEE8 @ =0x0203922C
	adds r0, r5, #0x0
	adds r0, #0x10
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEEC @ =0x020392A0
	adds r0, r5, #0x0
	adds r0, #0x3C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEF0 @ =0x02039280
	adds r0, r5, #0x0
	adds r0, #0x40
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEF4 @ =0x0203929C
	adds r0, r5, #0x0
	adds r0, #0x48
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	str r0, [r1, #0x00]
	cmp r6, #0x00
	bne _0833CDF6
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CDF6
_0833CDF6:
	cmp r6, #0x01
	bne _0833CE00
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x70
	str r0, [r1, #0x00]
	.global _0833CE00
_0833CE00:
	cmp r6, #0x02
	bne _0833CE0A
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0xA8
	str r0, [r1, #0x00]
	.global _0833CE0A
_0833CE0A:
	cmp r6, #0x03
	bne _0833CE14
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x6B
	str r0, [r1, #0x00]
	.global _0833CE14
_0833CE14:
	cmp r6, #0x04
	bne _0833CE1E
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0xA3
	str r0, [r1, #0x00]
	.global _0833CE1E
_0833CE1E:
	cmp r6, #0x05
	bne _0833CE28
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0xA6
	str r0, [r1, #0x00]
	.global _0833CE28
_0833CE28:
	cmp r6, #0x06
	bne _0833CE32
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CE32
_0833CE32:
	cmp r6, #0x08
	bne _0833CE3C
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CE3C
_0833CE3C:
	cmp r6, #0x09
	bne _0833CE46
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CE46
_0833CE46:
	cmp r6, #0x0A
	bne _0833CE50
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x5E
	str r0, [r1, #0x00]
	.global _0833CE50
_0833CE50:
	cmp r6, #0x0B
	bne _0833CE5A
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CE5A
_0833CE5A:
	ldr r0, _0833CED8 @ =0x02039228
	ldr r2, [r0, #0x00]
	ldr r3, _0833CEFC @ =0x03000800
	ldr r0, _0833CEE4 @ =0x02039238
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _0833CF00 @ =0x02039294
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x00
	movs r1, #0x00
	bl sub_0833CFC8
	ldr r0, _0833CEDC @ =0x02039268
	ldr r2, [r0, #0x00]
	ldr r3, _0833CF04 @ =0x03001000
	ldr r0, _0833CEE8 @ =0x0203922C
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _0833CF08 @ =0x02039248
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x00
	movs r1, #0x00
	bl sub_0833CFC8
	bl sub_0833D094
	movs r0, #0x00
	movs r1, #0x00
	bl sub_0833D564
	adds r0, r6, #0x0
	bl sub_0834108C
	bl sub_0833E05C
	bl sub_0833E078
	ldr r1, _0833CF0C @ =0x0203B864
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r3, #0x82
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833CEBC
_0833CEBC: .4byte 0xFFFFFDF8
	.global _0833CEC0
_0833CEC0: .4byte 0x02022428
	.global _0833CEC4
_0833CEC4: .4byte 0x0600C000
	.global _0833CEC8
_0833CEC8: .4byte 0x020251BC
	.global _0833CECC
_0833CECC: .4byte 0x02021394
	.global _0833CED0
_0833CED0: .4byte 0x02039244
	.global _0833CED4
_0833CED4: .4byte 0x02039288
	.global _0833CED8
_0833CED8: .4byte 0x02039228
	.global _0833CEDC
_0833CEDC: .4byte 0x02039268
	.global _0833CEE0
_0833CEE0: .4byte 0x02039224
	.global _0833CEE4
_0833CEE4: .4byte 0x02039238
	.global _0833CEE8
_0833CEE8: .4byte 0x0203922C
	.global _0833CEEC
_0833CEEC: .4byte 0x020392A0
	.global _0833CEF0
_0833CEF0: .4byte 0x02039280
	.global _0833CEF4
_0833CEF4: .4byte 0x0203929C
	.global _0833CEF8
_0833CEF8: .4byte 0x02039220
	.global _0833CEFC
_0833CEFC: .4byte 0x03000800
	.global _0833CF00
_0833CF00: .4byte 0x02039294
	.global _0833CF04
_0833CF04: .4byte 0x03001000
	.global _0833CF08
_0833CF08: .4byte 0x02039248
	.global _0833CF0C
_0833CF0C: .4byte 0x0203B864
	thumb_func_start sub_0833CF10
sub_0833CF10:
	push {r4, r5, lr}
	add sp, #-0x008
	ldr r0, _0833CF8C @ =0x02039110
	ldr r4, [r0, #0x18]
	subs r4, #0x78
	ldr r5, [r0, #0x1C]
	subs r5, #0x50
	ldr r0, _0833CF90 @ =0x0203925C
	movs r2, #0x0F
	ands r2, r4
	str r2, [r0, #0x00]
	ldr r0, _0833CF94 @ =0x02039260
	movs r1, #0x1F
	ands r1, r5
	str r1, [r0, #0x00]
	ldr r0, _0833CF98 @ =0x020392A8
	str r2, [r0, #0x00]
	ldr r0, _0833CF9C @ =0x02039240
	str r1, [r0, #0x00]
	ldr r0, _0833CFA0 @ =0x02039290
	str r2, [r0, #0x00]
	ldr r0, _0833CFA4 @ =0x02039298
	str r1, [r0, #0x00]
	ldr r2, _0833CFA8 @ =0x02039234
	movs r1, #0x10
	adds r0, r4, #0x0
	ands r0, r1
	strb r0, [r2, #0x00]
	asrs r4, r4, #0x05
	asrs r5, r5, #0x05
	ldr r0, _0833CFAC @ =0x02039228
	ldr r2, [r0, #0x00]
	movs r3, #0xC0
	lsls r3, r3, #0x12
	ldr r0, _0833CFB0 @ =0x02039238
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _0833CFB4 @ =0x02039248
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_0833CFC8
	ldr r0, _0833CFB8 @ =0x02039268
	ldr r2, [r0, #0x00]
	ldr r3, _0833CFBC @ =0x03000800
	ldr r0, _0833CFC0 @ =0x0203922C
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _0833CFC4 @ =0x020392A4
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_0833CFC8
	add sp, #0x008
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833CF8C
_0833CF8C: .4byte 0x02039110
	.global _0833CF90
_0833CF90: .4byte 0x0203925C
	.global _0833CF94
_0833CF94: .4byte 0x02039260
	.global _0833CF98
_0833CF98: .4byte 0x020392A8
	.global _0833CF9C
_0833CF9C: .4byte 0x02039240
	.global _0833CFA0
_0833CFA0: .4byte 0x02039290
	.global _0833CFA4
_0833CFA4: .4byte 0x02039298
	.global _0833CFA8
_0833CFA8: .4byte 0x02039234
	.global _0833CFAC
_0833CFAC: .4byte 0x02039228
	.global _0833CFB0
_0833CFB0: .4byte 0x02039238
	.global _0833CFB4
_0833CFB4: .4byte 0x02039248
	.global _0833CFB8
_0833CFB8: .4byte 0x02039268
	.global _0833CFBC
_0833CFBC: .4byte 0x03000800
	.global _0833CFC0
_0833CFC0: .4byte 0x0203922C
	.global _0833CFC4
_0833CFC4: .4byte 0x020392A4
	thumb_func_start sub_0833CFC8
sub_0833CFC8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r12, r3
	ldr r6, [sp, #0x018]
	ldr r4, _0833D03C @ =0x02039244
	ldr r3, [r4, #0x00]
	muls r1, r3
	adds r2, r2, r1
	adds r2, r2, r0
	movs r0, #0x00
	mov r8, r4
	.global _0833CFE0
_0833CFE0:
	movs r4, #0x00
	adds r5, r0, #0x4
	mov r3, r12
	adds r3, #0x90
	.global _0833CFE8
_0833CFE8:
	ldrb r1, [r2, #0x00]
	adds r2, #0x01
	lsls r1, r1, #0x05
	adds r1, r6, r1
	ldm r1!, {r0}
	mov r7, r12
	str r0, [r7, #0x00]
	ldm r1!, {r0}
	str r0, [r7, #0x04]
	ldm r1!, {r0}
	str r0, [r7, #0x48]
	ldm r1!, {r0}
	str r0, [r7, #0x4C]
	ldm r1!, {r0}
	str r0, [r3, #0x00]
	ldm r1!, {r0}
	str r0, [r3, #0x04]
	ldm r1!, {r0}
	str r0, [r3, #0x48]
	ldr r0, [r1, #0x00]
	str r0, [r3, #0x4C]
	adds r3, #0x08
	movs r0, #0x08
	add r12, r0
	adds r4, #0x01
	cmp r4, #0x09
	bne _0833CFE8
	movs r1, #0xD8
	add r12, r1
	mov r7, r8
	ldr r0, [r7, #0x00]
	subs r0, #0x09
	adds r2, r2, r0
	adds r0, r5, #0x0
	cmp r0, #0x18
	bne _0833CFE0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833D03C
_0833D03C: .4byte 0x02039244
	thumb_func_start sub_0833D040
sub_0833D040:
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _0833D06C @ =0x02039234
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833D050
	adds r4, #0x04
	.global _0833D050
_0833D050:
	movs r6, #0x00
	.global _0833D052
_0833D052:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0x10
	bl sub_08344B60
	adds r4, #0x48
	adds r5, #0x40
	adds r6, #0x01
	cmp r6, #0x18
	bne _0833D052
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _0833D06C
_0833D06C: .4byte 0x02039234
	.byte 0x70, 0xB5, 0x05, 0x1C, 0x0C, 0x1C, 0x00, 0x26, 0x28, 0x1C, 0x21, 0x1C, 0x10, 0x22, 0x07, 0xF0
	.byte 0x6F, 0xFD, 0x40, 0x35, 0x40, 0x34, 0x01, 0x36, 0x1C, 0x2E, 0xF5, 0xD1, 0x70, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00
	thumb_func_start sub_0833D094
sub_0833D094:
	push {lr}
	movs r0, #0xC0
	lsls r0, r0, #0x12
	ldr r1, _0833D0AC @ =0x0600E800
	bl sub_0833D040
	ldr r0, _0833D0B0 @ =0x03000800
	ldr r1, _0833D0B4 @ =0x0600F000
	bl sub_0833D040
	pop {r0}
	bx r0
	.global _0833D0AC
_0833D0AC: .4byte 0x0600E800
	.global _0833D0B0
_0833D0B0: .4byte 0x03000800
	.global _0833D0B4
_0833D0B4: .4byte 0x0600F000
	.byte 0xF0, 0xB5, 0x04, 0x1C, 0x00, 0x26, 0x1F, 0x25, 0x0C, 0x4B, 0x80, 0x27, 0x7F, 0x00, 0x20, 0x88
	.byte 0x02, 0x34, 0x01, 0x1C, 0x02, 0x1C, 0x28, 0x40, 0x49, 0x11, 0x29, 0x40, 0x92, 0x12, 0x2A, 0x40
	.byte 0x00, 0x04, 0x18, 0x60, 0x09, 0x04, 0x59, 0x60, 0x12, 0x04, 0x9A, 0x60, 0x0C, 0x33, 0x01, 0x36
	.byte 0xBE, 0x42, 0xEC, 0xD1, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xD0, 0x92, 0x03, 0x02
	.byte 0x70, 0xB5, 0x0C, 0x1C, 0x03, 0x1C, 0x00, 0x26, 0x1F, 0x25, 0x18, 0x88, 0x02, 0x33, 0x01, 0x1C
	.byte 0x02, 0x1C, 0x28, 0x40, 0x49, 0x11, 0x29, 0x40, 0x92, 0x12, 0x2A, 0x40, 0x00, 0x04, 0x01, 0xC4
	.byte 0x09, 0x04, 0x02, 0xC4, 0x12, 0x04, 0x04, 0xC4, 0x01, 0x36, 0x10, 0x2E, 0xED, 0xD1, 0x70, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0x70, 0xB5, 0x04, 0x1C, 0x0B, 0x1C, 0x00, 0x26, 0x1F, 0x25, 0x01, 0xCC
	.byte 0x02, 0xCC, 0x04, 0xCC, 0x00, 0x14, 0x09, 0x14, 0x12, 0x14, 0x28, 0x40, 0x29, 0x40, 0x2A, 0x40
	.byte 0x49, 0x01, 0x08, 0x43, 0x92, 0x02, 0x10, 0x43, 0x18, 0x80, 0x02, 0x33, 0x01, 0x36, 0x10, 0x2E
	.byte 0xED, 0xD1, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x30, 0xB5, 0x04, 0x1C, 0x04, 0xCC, 0x12, 0x14
	.byte 0x06, 0x25, 0x43, 0x5F, 0x06, 0x20, 0x24, 0x5E, 0x1F, 0x20, 0x02, 0x40, 0x03, 0x40, 0x04, 0x40
	.byte 0x5B, 0x01, 0x1A, 0x43, 0xA4, 0x02, 0x22, 0x43, 0x0A, 0x80, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0xF0, 0xB5, 0x06, 0x1C, 0x14, 0x1C, 0x0D, 0x1C, 0x00, 0x20, 0x84, 0x46, 0x1F, 0x27, 0x2B, 0x88
	.byte 0x02, 0x35, 0x19, 0x1C, 0x3B, 0x40, 0x4A, 0x11, 0x3A, 0x40, 0x89, 0x12, 0x39, 0x40, 0x1B, 0x04
	.byte 0x12, 0x04, 0x09, 0x04, 0x01, 0xCE, 0x18, 0x1A, 0x23, 0x1C, 0x04, 0x34, 0x00, 0x28, 0x00, 0xDA
	.byte 0x0F, 0x30, 0x00, 0x11, 0x18, 0x60, 0x01, 0xCE, 0x10, 0x1A, 0x22, 0x1C, 0x04, 0x34, 0x00, 0x28
	.byte 0x00, 0xDA, 0x0F, 0x30, 0x00, 0x11, 0x10, 0x60, 0x01, 0xCE, 0x08, 0x1A, 0x23, 0x1C, 0x1C, 0x1D
	.byte 0x00, 0x28, 0x00, 0xDA, 0x0F, 0x30, 0x00, 0x11, 0x18, 0x60, 0x01, 0x20, 0x84, 0x44, 0x60, 0x46
	.byte 0x10, 0x28, 0xD4, 0xD1, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x10, 0xB5, 0x02, 0x1C
	.byte 0x0C, 0x1C, 0x00, 0x23, 0x10, 0x68, 0x02, 0xCC, 0x40, 0x18, 0x01, 0xC2, 0x01, 0x33, 0x30, 0x2B
	.byte 0xF8, 0xD1, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xF0, 0xB5, 0x04, 0x1C, 0x00, 0x26, 0x1F, 0x25
	.byte 0x0C, 0x4B, 0x80, 0x27, 0x7F, 0x00, 0x20, 0x88, 0x02, 0x34, 0x01, 0x1C, 0x02, 0x1C, 0x28, 0x40
	.byte 0x49, 0x11, 0x29, 0x40, 0x92, 0x12, 0x2A, 0x40, 0x00, 0x04, 0x18, 0x60, 0x09, 0x04, 0x59, 0x60
	.byte 0x12, 0x04, 0x9A, 0x60, 0x0C, 0x33, 0x01, 0x36, 0xBE, 0x42, 0xEC, 0xD1, 0xF0, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0xD0, 0x92, 0x03, 0x02
	thumb_func_start sub_0833D250
sub_0833D250:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	movs r3, #0x1F
	movs r4, #0xF8
	lsls r4, r4, #0x0D
	lsrs r2, r0, #0x15
	ands r2, r3
	lsrs r1, r0, #0x1A
	ands r1, r3
	movs r3, #0x00
	ands r4, r0
	ldr r0, _0833D284 @ =0x020392D0
	lsls r2, r2, #0x10
	lsls r1, r1, #0x10
	movs r5, #0x80
	lsls r5, r5, #0x01
	.global _0833D270
_0833D270:
	str r4, [r0, #0x00]
	str r2, [r0, #0x04]
	str r1, [r0, #0x08]
	adds r0, #0x0C
	adds r3, #0x01
	cmp r3, r5
	bne _0833D270
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _0833D284
_0833D284: .4byte 0x020392D0
	thumb_func_start sub_0833D288
sub_0833D288:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0x0
	lsls r1, r1, #0x10
	movs r0, #0x1F
	movs r2, #0xF8
	lsls r2, r2, #0x0D
	mov r10, r2
	lsrs r2, r1, #0x15
	ands r2, r0
	lsrs r7, r1, #0x1A
	ands r7, r0
	mov r0, r10
	ands r0, r1
	mov r10, r0
	lsls r2, r2, #0x10
	mov r8, r2
	lsls r7, r7, #0x10
	movs r1, #0x00
	mov r9, r1
	ldr r5, _0833D30C @ =0x020392D0
	ldr r4, _0833D310 @ =0x02039ED0
	.global _0833D2BA
_0833D2BA:
	ldr r0, [r5, #0x00]
	mov r2, r10
	subs r0, r2, r0
	adds r1, r6, #0x0
	bl sub_08344BB8
	str r0, [r4, #0x00]
	ldr r0, [r5, #0x04]
	mov r1, r8
	subs r0, r1, r0
	adds r1, r6, #0x0
	bl sub_08344BB8
	str r0, [r4, #0x04]
	ldr r0, [r5, #0x08]
	subs r0, r7, r0
	adds r1, r6, #0x0
	bl sub_08344BB8
	str r0, [r4, #0x08]
	adds r5, #0x0C
	adds r4, #0x0C
	movs r2, #0x01
	add r9, r2
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r9, r0
	bne _0833D2BA
	ldr r0, _0833D314 @ =0x020392C8
	strh r6, [r0, #0x00]
	movs r0, #0x01
	ldr r1, _0833D318 @ =0x020392C4
	strb r0, [r1, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833D30C
_0833D30C: .4byte 0x020392D0
	.global _0833D310
_0833D310: .4byte 0x02039ED0
	.global _0833D314
_0833D314: .4byte 0x020392C8
	.global _0833D318
_0833D318: .4byte 0x020392C4
	thumb_func_start sub_0833D31C
sub_0833D31C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0x0
	mov r9, r1
	movs r0, #0x00
	mov r10, r0
	ldr r1, _0833D3D4 @ =0x020392D0
	mov r8, r1
	ldr r7, _0833D3D8 @ =0x02039ED0
	.global _0833D334
_0833D334:
	mov r0, r9
	ldrh r2, [r0, #0x00]
	movs r1, #0x02
	add r9, r1
	adds r4, r2, #0x0
	movs r0, #0x1F
	ands r2, r0
	asrs r5, r4, #0x05
	ands r5, r0
	asrs r4, r4, #0x0A
	ands r4, r0
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r2, r0, #0x01
	cmp r2, #0x1F
	ble _0833D35A
	movs r2, #0x1F
	.global _0833D35A
_0833D35A:
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r5, r0, #0x01
	cmp r5, #0x1F
	ble _0833D36A
	movs r5, #0x1F
	.global _0833D36A
_0833D36A:
	lsls r0, r4, #0x01
	adds r0, r0, r4
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r4, r0, #0x01
	cmp r4, #0x1F
	ble _0833D37A
	movs r4, #0x1F
	.global _0833D37A
_0833D37A:
	lsls r2, r2, #0x10
	lsls r5, r5, #0x10
	lsls r4, r4, #0x10
	mov r1, r8
	ldr r0, [r1, #0x00]
	subs r0, r2, r0
	adds r1, r6, #0x0
	bl sub_08344BB8
	str r0, [r7, #0x00]
	mov r1, r8
	ldr r0, [r1, #0x04]
	subs r0, r5, r0
	adds r1, r6, #0x0
	bl sub_08344BB8
	str r0, [r7, #0x04]
	mov r1, r8
	ldr r0, [r1, #0x08]
	subs r0, r4, r0
	adds r1, r6, #0x0
	bl sub_08344BB8
	str r0, [r7, #0x08]
	movs r0, #0x0C
	add r8, r0
	adds r7, #0x0C
	movs r1, #0x01
	add r10, r1
	adds r0, #0xF4
	cmp r10, r0
	bne _0833D334
	ldr r0, _0833D3DC @ =0x020392C8
	strh r6, [r0, #0x00]
	movs r0, #0x01
	ldr r1, _0833D3E0 @ =0x020392C4
	strb r0, [r1, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833D3D4
_0833D3D4: .4byte 0x020392D0
	.global _0833D3D8
_0833D3D8: .4byte 0x02039ED0
	.global _0833D3DC
_0833D3DC: .4byte 0x020392C8
	.global _0833D3E0
_0833D3E0: .4byte 0x020392C4
	thumb_func_start sub_0833D3E4
sub_0833D3E4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	movs r0, #0xF0
	mov r8, r0
	ldr r2, _0833D440 @ =0x02039ED0
	ldr r1, _0833D444 @ =0x020392D0
	movs r0, #0xB4
	lsls r0, r0, #0x04
	adds r6, r1, r0
	adds r5, r2, r0
	.global _0833D3FC
_0833D3FC:
	movs r4, #0xF8
	lsls r4, r4, #0x0D
	ldr r0, [r6, #0x00]
	subs r0, r4, r0
	adds r1, r7, #0x0
	bl sub_08344BB8
	str r0, [r5, #0x00]
	ldr r0, [r6, #0x04]
	subs r0, r4, r0
	adds r1, r7, #0x0
	bl sub_08344BB8
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	subs r4, r4, r0
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	bl sub_08344BB8
	str r0, [r5, #0x08]
	adds r6, #0x0C
	adds r5, #0x0C
	movs r0, #0x01
	add r8, r0
	adds r0, #0xFF
	cmp r8, r0
	bne _0833D3FC
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833D440
_0833D440: .4byte 0x02039ED0
	.global _0833D444
_0833D444: .4byte 0x020392D0
	thumb_func_start sub_0833D448
sub_0833D448:
	push {r4, r5, lr}
	ldr r0, _0833D490 @ =0x020392C8
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r1, _0833D494 @ =0x020392C4
	cmp r0, #0x00
	bne _0833D458
	strb r0, [r1, #0x00]
	.global _0833D458
_0833D458:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0833D482
	bl sub_0833D4A4
	movs r2, #0x00
	movs r5, #0xC0
	lsls r5, r5, #0x02
	ldr r3, _0833D498 @ =0x020392D0
	ldr r4, _0833D49C @ =0x02039ED0
	.global _0833D46C
_0833D46C:
	ldr r0, [r3, #0x00]
	ldm r4!, {r1}
	adds r0, r0, r1
	stm r3!, {r0}
	adds r2, #0x01
	cmp r2, r5
	bne _0833D46C
	ldr r1, _0833D490 @ =0x020392C8
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	.global _0833D482
_0833D482:
	ldr r1, _0833D4A0 @ =0x020392C0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833D490
_0833D490: .4byte 0x020392C8
	.global _0833D494
_0833D494: .4byte 0x020392C4
	.global _0833D498
_0833D498: .4byte 0x020392D0
	.global _0833D49C
_0833D49C: .4byte 0x02039ED0
	.global _0833D4A0
_0833D4A0: .4byte 0x020392C0
	thumb_func_start sub_0833D4A4
sub_0833D4A4:
	push {r4, r5, r6, r7, lr}
	ldr r6, _0833D4DC @ =0x020392D0
	ldr r5, _0833D4E0 @ =0x0203AAD0
	movs r4, #0x00
	movs r3, #0x1F
	movs r7, #0x80
	lsls r7, r7, #0x01
	.global _0833D4B2
_0833D4B2:
	ldm r6!, {r0}
	ldm r6!, {r1}
	ldm r6!, {r2}
	asrs r0, r0, #0x10
	asrs r1, r1, #0x10
	asrs r2, r2, #0x10
	ands r0, r3
	ands r1, r3
	ands r2, r3
	lsls r1, r1, #0x05
	orrs r0, r1
	lsls r2, r2, #0x0A
	orrs r0, r2
	strh r0, [r5, #0x00]
	adds r5, #0x02
	adds r4, #0x01
	cmp r4, r7
	bne _0833D4B2
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0833D4DC
_0833D4DC: .4byte 0x020392D0
	.global _0833D4E0
_0833D4E0: .4byte 0x0203AAD0
	thumb_func_start sub_0833D4E4
sub_0833D4E4:
	push {r4, lr}
	ldr r4, _0833D508 @ =0x020392C0
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0833D500
	ldr r0, _0833D50C @ =0x0203AAD0
	movs r1, #0xA0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x01
	bl sub_08344B64
	movs r0, #0x00
	strb r0, [r4, #0x00]
	.global _0833D500
_0833D500:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833D508
_0833D508: .4byte 0x020392C0
	.global _0833D50C
_0833D50C: .4byte 0x0203AAD0
	thumb_func_start sub_0833D510
sub_0833D510:
	push {r4, r5, lr}
	adds r2, r0, #0x0
	adds r5, r1, #0x0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0x0
	adds r1, r2, #0x0
	bl sub_0833D288
	movs r4, #0x00
	cmp r4, r5
	beq _0833D536
	.global _0833D528
_0833D528:
	bl sub_08339B18
	bl sub_0833D448
	adds r4, #0x01
	cmp r4, r5
	bne _0833D528
	.global _0833D536
_0833D536:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x30, 0xB5, 0x02, 0x1C, 0x0D, 0x1C, 0x28, 0x1C, 0x11, 0x1C, 0xFF, 0xF7, 0xE9, 0xFE, 0x00, 0x24
	.byte 0xAC, 0x42, 0x06, 0xD0, 0xFC, 0xF7, 0xE2, 0xFA, 0xFF, 0xF7, 0x78, 0xFF, 0x01, 0x34, 0xAC, 0x42
	.byte 0xF8, 0xD1, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
