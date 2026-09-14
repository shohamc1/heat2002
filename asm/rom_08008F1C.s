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
	thumb_func_start sub_08008F1C
sub_08008F1C:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r4, r0, #0x0
	bl sub_08004944
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0x0
	bl sub_08007BB8
	ldr r1, _08008F94 @ =0x0202CAF0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r0, _08008F98 @ =0x0202EED0
	ldrb r0, [r0, #0x00]
	mov r9, r0
	bl sub_08008D70
	ldr r0, _08008F9C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08008FB0
	ldr r0, _08008FA0 @ =0x0202EFC0
	mov r8, r0
	ldr r6, _08008FA4 @ =0x0202A3F0
	movs r7, #0x00
	.global _08008F56
_08008F56:
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	mov r2, r8
	ldr r1, [r2, #0x00]
	ldr r2, [r6, #0x00]
	lsls r2, r2, #0x10
	ldr r3, [r6, #0x04]
	lsls r3, r3, #0x10
	ldr r4, [r6, #0x08]
	lsls r4, r4, #0x08
	str r4, [sp, #0x000]
	mov r4, r8
	adds r4, #0x04
	mov r8, r4
	subs r4, #0x04
	ldm r4!, {r5}
	ldr r4, _08008FA8 @ =0x0202A550
	subs r5, r5, r4
	ldr r4, _08008FAC @ =0xC28F5C29
	muls r4, r5
	asrs r4, r4, #0x04
	add r4, r9
	str r4, [sp, #0x004]
	bl sub_080097A4
	adds r6, #0x0C
	adds r7, #0x01
	cmp r7, #0x18
	bne _08008F56
	b _08008FE4
	.byte 0x00, 0x00
	.global _08008F94
_08008F94: .4byte 0x0202CAF0
	.global _08008F98
_08008F98: .4byte 0x0202EED0
	.global _08008F9C
_08008F9C: .4byte 0x0200215C
	.global _08008FA0
_08008FA0: .4byte 0x0202EFC0
	.global _08008FA4
_08008FA4: .4byte 0x0202A3F0
	.global _08008FA8
_08008FA8: .4byte 0x0202A550
	.global _08008FAC
_08008FAC: .4byte 0xC28F5C29
	.global _08008FB0
_08008FB0:
	ldr r6, _08009060 @ =0x0202A3F0
	movs r7, #0x00
	movs r5, #0x00
	.global _08008FB6
_08008FB6:
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08009064 @ =0x0202A550
	adds r1, r5, r1
	ldr r2, [r6, #0x00]
	lsls r2, r2, #0x10
	ldr r3, [r6, #0x04]
	lsls r3, r3, #0x10
	ldr r4, [r6, #0x08]
	lsls r4, r4, #0x08
	str r4, [sp, #0x000]
	adds r4, r7, #0x0
	add r4, r9
	str r4, [sp, #0x004]
	bl sub_080097A4
	adds r6, #0x0C
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r5, r5, r0
	adds r7, #0x01
	cmp r7, #0x18
	bne _08008FB6
	.global _08008FE4
_08008FE4:
	ldr r0, _08009068 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0E
	beq _08008FF8
	cmp r0, #0x09
	beq _08008FF8
	cmp r0, #0x0D
	beq _08008FF8
	cmp r0, #0x11
	bne _08009092
	.global _08008FF8
_08008FF8:
	ldr r7, _0800906C @ =0x0202EFC0
	ldr r6, [r7, #0x00]
	ldr r0, _08009070 @ =0x083C9E74
	ldr r5, _08009074 @ =0x020020CC
	ldrb r1, [r5, #0x00]
	lsls r4, r1, #0x01
	adds r4, r4, r1
	lsls r4, r4, #0x04
	adds r4, #0x14
	adds r0, r4, r0
	ldr r2, [r0, #0x00]
	ldr r0, _08009078 @ =0x083681B0
	adds r1, r1, r0
	ldrb r1, [r1, #0x00]
	ldrh r2, [r2, #0x00]
	adds r0, r1, #0x0
	muls r0, r2
	movs r1, #0x64
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, _0800907C @ =0x083C9574
	adds r0, r4, r0
	ldr r2, [r0, #0x00]
	ldr r0, _08009080 @ =0x083C97B4
	adds r4, r4, r0
	ldr r3, [r4, #0x00]
	adds r0, r1, #0x0
	add r1, sp, #0x008
	bl sub_0800BD98
	ldr r0, [sp, #0x008]
	lsls r1, r0, #0x10
	str r1, [r6, #0x00]
	ldr r0, [sp, #0x00C]
	lsls r0, r0, #0x10
	str r0, [r6, #0x08]
	movs r0, #0x00
	str r0, [r6, #0x0C]
	str r0, [r6, #0x14]
	str r0, [r6, #0x2C]
	strh r0, [r6, #0x34]
	ldrb r0, [r5, #0x00]
	cmp r0, #0x01
	bne _08009084
	ldr r2, [r6, #0x04]
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	movs r3, #0x46
	bl sub_0800BEA4
	b _08009092
	.global _08009060
_08009060: .4byte 0x0202A3F0
	.global _08009064
_08009064: .4byte 0x0202A550
	.global _08009068
_08009068: .4byte 0x0200215C
	.global _0800906C
_0800906C: .4byte 0x0202EFC0
	.global _08009070
_08009070: .4byte 0x083C9E74
	.global _08009074
_08009074: .4byte 0x020020CC
	.global _08009078
_08009078: .4byte 0x083681B0
	.global _0800907C
_0800907C: .4byte 0x083C9574
	.global _08009080
_08009080: .4byte 0x083C97B4
	.global _08009084
_08009084:
	ldr r2, [r6, #0x04]
	movs r0, #0x01
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	movs r3, #0x64
	bl sub_0800BEA4
	.global _08009092
_08009092:
	ldr r0, _0800912C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0F
	beq _0800909C
	b _080091E0
	.global _0800909C
_0800909C:
	ldr r7, _08009130 @ =0x0202EFC0
	ldr r6, [r7, #0x00]
	ldr r1, _08009134 @ =0x083C9E74
	ldr r0, _08009138 @ =0x020020CC
	ldrb r2, [r0, #0x00]
	lsls r4, r2, #0x01
	adds r4, r4, r2
	lsls r4, r4, #0x04
	adds r4, #0x14
	adds r1, r4, r1
	ldr r2, [r1, #0x00]
	ldr r1, _0800913C @ =0x08368170
	ldr r5, _08009140 @ =0x0202ED70
	ldrb r3, [r5, #0x00]
	lsls r0, r3, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldrh r2, [r2, #0x00]
	muls r0, r2
	movs r1, #0x64
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, _08009144 @ =0x083C9574
	adds r0, r4, r0
	ldr r2, [r0, #0x00]
	ldr r0, _08009148 @ =0x083C97B4
	adds r4, r4, r0
	ldr r3, [r4, #0x00]
	adds r0, r1, #0x0
	add r1, sp, #0x008
	bl sub_0800BD98
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x10
	str r0, [r6, #0x00]
	ldr r0, [sp, #0x00C]
	lsls r0, r0, #0x10
	str r0, [r6, #0x08]
	movs r1, #0x00
	str r1, [r6, #0x0C]
	str r1, [r6, #0x14]
	str r1, [r6, #0x2C]
	strh r1, [r6, #0x34]
	ldrb r0, [r5, #0x00]
	cmp r0, #0x06
	beq _0800910E
	cmp r0, #0x0A
	beq _0800910E
	cmp r0, #0x0B
	beq _0800910E
	cmp r0, #0x0C
	beq _08009154
	cmp r0, #0x0E
	beq _0800910E
	cmp r0, #0x0F
	bne _08009180
	.global _0800910E
_0800910E:
	ldr r0, _08009140 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0C
	beq _08009154
	cmp r0, #0x06
	bne _0800914C
	ldr r0, _08009130 @ =0x0202EFC0
	movs r1, #0x01
	str r1, [sp, #0x000]
	movs r1, #0x00
	movs r2, #0x00
	movs r3, #0x28
	bl sub_0800BEA4
	b _080091D0
	.global _0800912C
_0800912C: .4byte 0x0200215C
	.global _08009130
_08009130: .4byte 0x0202EFC0
	.global _08009134
_08009134: .4byte 0x083C9E74
	.global _08009138
_08009138: .4byte 0x020020CC
	.global _0800913C
_0800913C: .4byte 0x08368170
	.global _08009140
_08009140: .4byte 0x0202ED70
	.global _08009144
_08009144: .4byte 0x083C9574
	.global _08009148
_08009148: .4byte 0x083C97B4
	.global _0800914C
_0800914C:
	cmp r0, #0x0B
	beq _08009154
	cmp r0, #0x0E
	bne _0800916C
	.global _08009154
_08009154:
	ldr r0, _08009168 @ =0x0202EFC0
	movs r1, #0x01
	str r1, [sp, #0x000]
	movs r1, #0x00
	movs r2, #0x00
	movs r3, #0x50
	bl sub_0800BEA4
	b _080091D0
	.byte 0x00, 0x00
	.global _08009168
_08009168: .4byte 0x0202EFC0
	.global _0800916C
_0800916C:
	ldr r0, _08009178 @ =0x0202EFC0
	ldr r1, _0800917C @ =0x0202A550
	str r1, [r0, #0x00]
	movs r1, #0x00
	str r1, [sp, #0x000]
	b _080091B8
	.global _08009178
_08009178: .4byte 0x0202EFC0
	.global _0800917C
_0800917C: .4byte 0x0202A550
	.global _08009180
_08009180:
	cmp r0, #0x03
	bne _08009196
	movs r0, #0x01
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	movs r1, #0x00
	movs r2, #0x00
	movs r3, #0x14
	bl sub_0800BEA4
	b _080091D0
	.global _08009196
_08009196:
	cmp r0, #0x0D
	bne _080091AC
	movs r0, #0x01
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	movs r1, #0x00
	movs r2, #0x00
	movs r3, #0x4B
	bl sub_0800BEA4
	b _080091D0
	.global _080091AC
_080091AC:
	cmp r0, #0x02
	bne _080091C2
	movs r0, #0x01
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	movs r1, #0x00
	.global _080091B8
_080091B8:
	movs r2, #0x00
	movs r3, #0x32
	bl sub_0800BEA4
	b _080091D0
	.global _080091C2
_080091C2:
	str r1, [sp, #0x000]
	adds r0, r7, #0x0
	movs r1, #0x00
	movs r2, #0x00
	movs r3, #0x32
	bl sub_0800BEA4
	.global _080091D0
_080091D0:
	ldr r1, _080091F0 @ =0x0202CAE8
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r1, _080091F4 @ =0x0202CB14
	movs r0, #0x00
	str r0, [r1, #0x00]
	bl sub_08008D20
	.global _080091E0
_080091E0:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _080091F0
_080091F0: .4byte 0x0202CAE8
	.global _080091F4
_080091F4: .4byte 0x0202CB14
