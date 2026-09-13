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
	thumb_func_start sub_0800D684
sub_0800D684:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x044
	str r0, [sp, #0x024]
	ldr r0, _0800D9F8 @ =0x02002090
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x040]
	ldr r0, _0800D9FC @ =0x020020DC
	ldrb r1, [r0, #0x00]
	cmp r1, #0x00
	beq _0800D6A6
	ldr r0, _0800DA00 @ =0x020020AC
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x040]
	.global _0800D6A6
_0800D6A6:
	ldr r0, [sp, #0x024]
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800D6B6
	cmp r1, #0x00
	beq _0800D6B6
	b _0800DE48
	.global _0800D6B6
_0800D6B6:
	ldr r1, [sp, #0x024]
	ldr r2, _0800DA04 @ =0x00000175
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	ldr r2, _0800DA08 @ =0x0202A550
	cmp r0, #0x00
	beq _0800D6D8
	cmp r1, r2
	bne _0800D6CA
	b _0800DE48
	.global _0800D6CA
_0800D6CA:
	ldr r3, [sp, #0x024]
	ldr r1, _0800DA0C @ =0x0000018F
	adds r0, r3, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800D6D8
	b _0800DE48
	.global _0800D6D8
_0800D6D8:
	ldr r1, _0800DA10 @ =0x0202CD24
	movs r0, #0x80
	lsls r0, r0, #0x0E
	str r0, [r1, #0x00]
	add r4, sp, #0x020
	movs r0, #0x00
	strb r0, [r4, #0x00]
	mov r10, r2
	ldr r7, _0800DA14 @ =0x0202CCB0
	ldr r0, [sp, #0x024]
	adds r1, r7, #0x0
	bl sub_0800D5D4
	movs r2, #0x00
	str r2, [sp, #0x02C]
	ldr r3, [sp, #0x040]
	cmp r2, r3
	bne _0800D6FE
	b _0800DB38
	.global _0800D6FE
_0800D6FE:
	ldr r0, [sp, #0x024]
	cmp r10, r0
	bne _0800D706
	b _0800DB1E
	.global _0800D706
_0800D706:
	ldr r0, _0800DA04 @ =0x00000175
	add r0, r10
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800D724
	ldr r0, _0800DA08 @ =0x0202A550
	cmp r10, r0
	bne _0800D718
	b _0800DB1E
	.global _0800D718
_0800D718:
	ldr r0, _0800DA0C @ =0x0000018F
	add r0, r10
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800D724
	b _0800DB1E
	.global _0800D724
_0800D724:
	mov r0, r10
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800D738
	ldr r0, _0800D9FC @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800D738
	b _0800DB1E
	.global _0800D738
_0800D738:
	ldr r1, [sp, #0x024]
	ldr r2, [r1, #0x00]
	mov r3, r10
	ldr r0, [r3, #0x00]
	subs r2, r2, r0
	ldr r0, [r1, #0x08]
	ldr r1, [r3, #0x08]
	subs r0, r0, r1
	asrs r0, r0, #0x08
	asrs r2, r2, #0x08
	cmp r2, #0x00
	bge _0800D752
	negs r2, r2
	.global _0800D752
_0800D752:
	movs r1, #0xC8
	lsls r1, r1, #0x07
	cmp r2, r1
	ble _0800D75C
	b _0800DB1E
	.global _0800D75C
_0800D75C:
	cmp r0, #0x00
	bge _0800D762
	negs r0, r0
	.global _0800D762
_0800D762:
	cmp r0, r1
	ble _0800D768
	b _0800DB1E
	.global _0800D768
_0800D768:
	mov r0, r10
	ldr r1, _0800DA18 @ =0x0202CD30
	bl sub_0800D5D4
	ldr r0, _0800DA14 @ =0x0202CCB0
	ldr r5, [r0, #0x10]
	ldr r6, [r0, #0x14]
	ldr r1, _0800DA18 @ =0x0202CD30
	ldr r0, [r1, #0x10]
	subs r5, r5, r0
	ldr r0, [r1, #0x14]
	subs r6, r6, r0
	ldr r3, [r1, #0x04]
	adds r1, r3, #0x0
	muls r1, r5
	ldr r0, _0800DA18 @ =0x0202CD30
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	muls r0, r6
	subs r1, r1, r0
	asrs r1, r1, #0x08
	mov r9, r1
	str r1, [sp, #0x010]
	adds r0, r2, #0x0
	muls r0, r5
	adds r1, r3, #0x0
	muls r1, r6
	adds r0, r0, r1
	asrs r4, r0, #0x08
	str r4, [sp, #0x014]
	ldr r1, _0800DA14 @ =0x0202CCB0
	ldr r5, [r1, #0x18]
	ldr r6, [r1, #0x1C]
	ldr r2, _0800DA18 @ =0x0202CD30
	ldr r0, [r2, #0x18]
	subs r5, r5, r0
	ldr r0, [r2, #0x1C]
	subs r6, r6, r0
	ldr r3, [r2, #0x0C]
	adds r2, r3, #0x0
	muls r2, r5
	ldr r0, _0800DA18 @ =0x0202CD30
	ldr r1, [r0, #0x08]
	adds r0, r1, #0x0
	muls r0, r6
	subs r2, r2, r0
	asrs r2, r2, #0x08
	str r2, [sp, #0x018]
	adds r0, r1, #0x0
	muls r0, r5
	adds r1, r3, #0x0
	muls r1, r6
	adds r0, r0, r1
	asrs r1, r0, #0x08
	str r1, [sp, #0x01C]
	mov r3, r9
	subs r3, r2, r3
	mov r8, r3
	subs r7, r1, r4
	cmp r7, #0x00
	bge _0800D82E
	movs r0, #0xE0
	lsls r0, r0, #0x05
	cmp r1, r0
	bgt _0800D82E
	ldr r0, _0800DA1C @ =0xFFFFE400
	adds r4, r4, r0
	cmp r4, #0x00
	blt _0800D82E
	mov r0, r8
	muls r0, r4
	adds r1, r7, #0x0
	bl sub_08017230
	adds r1, r0, #0x0
	add r1, r9
	movs r2, #0xF0
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bhi _0800D82E
	ldr r3, _0800DA20 @ =0x0202CC90
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	negs r1, r7
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08017230
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x024]
	ldr r1, [sp, #0x028]
	mov r2, r10
	movs r3, #0x00
	bl sub_0800D64C
	.global _0800D82E
_0800D82E:
	cmp r7, #0x00
	ble _0800D880
	ldr r0, [sp, #0x01C]
	ldr r1, _0800DA1C @ =0xFFFFE400
	cmp r0, r1
	blt _0800D880
	ldr r0, [sp, #0x014]
	subs r4, r1, r0
	cmp r4, #0x00
	blt _0800D880
	mov r0, r8
	muls r0, r4
	adds r1, r7, #0x0
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, [sp, #0x010]
	adds r1, r1, r0
	movs r2, #0xF0
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bhi _0800D880
	ldr r3, _0800DA20 @ =0x0202CC90
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	str r7, [sp, #0x008]
	lsls r0, r4, #0x10
	adds r1, r7, #0x0
	bl sub_08017230
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x024]
	ldr r1, [sp, #0x028]
	mov r2, r10
	movs r3, #0x01
	bl sub_0800D64C
	.global _0800D880
_0800D880:
	mov r1, r8
	cmp r1, #0x00
	ble _0800D8D4
	ldr r0, [sp, #0x018]
	ldr r1, _0800DA24 @ =0xFFFFF100
	cmp r0, r1
	blt _0800D8D4
	ldr r0, [sp, #0x010]
	subs r4, r1, r0
	cmp r4, #0x00
	blt _0800D8D4
	adds r0, r4, #0x0
	muls r0, r7
	mov r1, r8
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, [sp, #0x014]
	adds r1, r1, r0
	movs r2, #0xE0
	lsls r2, r2, #0x05
	adds r1, r1, r2
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r1, r0
	bhi _0800D8D4
	ldr r3, _0800DA20 @ =0x0202CC90
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	mov r1, r8
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08017230
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x024]
	ldr r1, [sp, #0x028]
	mov r2, r10
	movs r3, #0x02
	bl sub_0800D64C
	.global _0800D8D4
_0800D8D4:
	mov r2, r8
	cmp r2, #0x00
	bge _0800D92E
	ldr r1, [sp, #0x018]
	movs r0, #0xF0
	lsls r0, r0, #0x04
	cmp r1, r0
	bgt _0800D92E
	ldr r0, [sp, #0x010]
	ldr r3, _0800DA24 @ =0xFFFFF100
	adds r4, r0, r3
	cmp r4, #0x00
	blt _0800D92E
	adds r0, r4, #0x0
	muls r0, r7
	mov r1, r8
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, [sp, #0x014]
	adds r1, r1, r0
	movs r0, #0xE0
	lsls r0, r0, #0x05
	adds r1, r1, r0
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r1, r0
	bhi _0800D92E
	ldr r1, _0800DA20 @ =0x0202CC90
	str r1, [sp, #0x000]
	add r2, sp, #0x020
	str r2, [sp, #0x004]
	mov r3, r8
	negs r1, r3
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08017230
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x024]
	ldr r1, [sp, #0x028]
	mov r2, r10
	movs r3, #0x03
	bl sub_0800D64C
	.global _0800D92E
_0800D92E:
	ldr r0, _0800DA18 @ =0x0202CD30
	ldr r5, [r0, #0x10]
	ldr r6, [r0, #0x14]
	ldr r1, _0800DA14 @ =0x0202CCB0
	ldr r0, [r1, #0x10]
	subs r5, r5, r0
	ldr r0, [r1, #0x14]
	subs r6, r6, r0
	ldr r3, [r1, #0x04]
	adds r1, r3, #0x0
	muls r1, r5
	ldr r0, _0800DA14 @ =0x0202CCB0
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	muls r0, r6
	subs r1, r1, r0
	asrs r1, r1, #0x08
	mov r9, r1
	str r1, [sp, #0x010]
	adds r0, r2, #0x0
	muls r0, r5
	adds r1, r3, #0x0
	muls r1, r6
	adds r0, r0, r1
	asrs r4, r0, #0x08
	str r4, [sp, #0x014]
	ldr r1, _0800DA18 @ =0x0202CD30
	ldr r5, [r1, #0x18]
	ldr r6, [r1, #0x1C]
	ldr r2, _0800DA14 @ =0x0202CCB0
	ldr r0, [r2, #0x18]
	subs r5, r5, r0
	ldr r0, [r2, #0x1C]
	subs r6, r6, r0
	ldr r3, [r2, #0x0C]
	adds r2, r3, #0x0
	muls r2, r5
	ldr r0, _0800DA14 @ =0x0202CCB0
	ldr r1, [r0, #0x08]
	adds r0, r1, #0x0
	muls r0, r6
	subs r2, r2, r0
	asrs r2, r2, #0x08
	str r2, [sp, #0x018]
	adds r0, r1, #0x0
	muls r0, r5
	adds r1, r3, #0x0
	muls r1, r6
	adds r0, r0, r1
	asrs r1, r0, #0x08
	str r1, [sp, #0x01C]
	mov r3, r9
	subs r3, r2, r3
	mov r8, r3
	subs r7, r1, r4
	cmp r7, #0x00
	bge _0800D9EC
	movs r0, #0xE0
	lsls r0, r0, #0x05
	cmp r1, r0
	bgt _0800D9EC
	ldr r0, _0800DA1C @ =0xFFFFE400
	adds r4, r4, r0
	cmp r4, #0x00
	blt _0800D9EC
	mov r0, r8
	muls r0, r4
	adds r1, r7, #0x0
	bl sub_08017230
	adds r1, r0, #0x0
	add r1, r9
	movs r2, #0xF0
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bhi _0800D9EC
	ldr r3, _0800DA20 @ =0x0202CC90
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	negs r1, r7
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08017230
	str r0, [sp, #0x00C]
	mov r0, r10
	ldr r1, [sp, #0x028]
	ldr r2, [sp, #0x024]
	movs r3, #0x00
	bl sub_0800D64C
	.global _0800D9EC
_0800D9EC:
	cmp r7, #0x00
	ble _0800DA70
	ldr r0, [sp, #0x01C]
	ldr r1, _0800DA1C @ =0xFFFFE400
	cmp r0, r1
	b _0800DA28
	.global _0800D9F8
_0800D9F8: .4byte 0x02002090
	.global _0800D9FC
_0800D9FC: .4byte 0x020020DC
	.global _0800DA00
_0800DA00: .4byte 0x020020AC
	.global _0800DA04
_0800DA04: .4byte 0x00000175
	.global _0800DA08
_0800DA08: .4byte 0x0202A550
	.global _0800DA0C
_0800DA0C: .4byte 0x0000018F
	.global _0800DA10
_0800DA10: .4byte 0x0202CD24
	.global _0800DA14
_0800DA14: .4byte 0x0202CCB0
	.global _0800DA18
_0800DA18: .4byte 0x0202CD30
	.global _0800DA1C
_0800DA1C: .4byte 0xFFFFE400
	.global _0800DA20
_0800DA20: .4byte 0x0202CC90
	.global _0800DA24
_0800DA24: .4byte 0xFFFFF100
	.global _0800DA28
_0800DA28:
	blt _0800DA70
	ldr r0, [sp, #0x014]
	subs r4, r1, r0
	cmp r4, #0x00
	blt _0800DA70
	mov r0, r8
	muls r0, r4
	adds r1, r7, #0x0
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, [sp, #0x010]
	adds r1, r1, r0
	movs r2, #0xF0
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bhi _0800DA70
	ldr r3, _0800DC90 @ =0x0202CC90
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	str r7, [sp, #0x008]
	lsls r0, r4, #0x10
	adds r1, r7, #0x0
	bl sub_08017230
	str r0, [sp, #0x00C]
	mov r0, r10
	ldr r1, [sp, #0x028]
	ldr r2, [sp, #0x024]
	movs r3, #0x01
	bl sub_0800D64C
	.global _0800DA70
_0800DA70:
	mov r1, r8
	cmp r1, #0x00
	ble _0800DAC4
	ldr r0, [sp, #0x018]
	ldr r1, _0800DC94 @ =0xFFFFF100
	cmp r0, r1
	blt _0800DAC4
	ldr r0, [sp, #0x010]
	subs r4, r1, r0
	cmp r4, #0x00
	blt _0800DAC4
	adds r0, r4, #0x0
	muls r0, r7
	mov r1, r8
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, [sp, #0x014]
	adds r1, r1, r0
	movs r2, #0xE0
	lsls r2, r2, #0x05
	adds r1, r1, r2
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r1, r0
	bhi _0800DAC4
	ldr r3, _0800DC90 @ =0x0202CC90
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	mov r1, r8
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08017230
	str r0, [sp, #0x00C]
	mov r0, r10
	ldr r1, [sp, #0x028]
	ldr r2, [sp, #0x024]
	movs r3, #0x02
	bl sub_0800D64C
	.global _0800DAC4
_0800DAC4:
	mov r2, r8
	cmp r2, #0x00
	bge _0800DB1E
	ldr r1, [sp, #0x018]
	movs r0, #0xF0
	lsls r0, r0, #0x04
	cmp r1, r0
	bgt _0800DB1E
	ldr r0, [sp, #0x010]
	ldr r3, _0800DC94 @ =0xFFFFF100
	adds r4, r0, r3
	cmp r4, #0x00
	blt _0800DB1E
	adds r0, r4, #0x0
	muls r0, r7
	mov r1, r8
	bl sub_08017230
	adds r1, r0, #0x0
	ldr r0, [sp, #0x014]
	adds r1, r1, r0
	movs r0, #0xE0
	lsls r0, r0, #0x05
	adds r1, r1, r0
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r1, r0
	bhi _0800DB1E
	ldr r1, _0800DC90 @ =0x0202CC90
	str r1, [sp, #0x000]
	add r2, sp, #0x020
	str r2, [sp, #0x004]
	mov r3, r8
	negs r1, r3
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08017230
	str r0, [sp, #0x00C]
	mov r0, r10
	ldr r1, [sp, #0x028]
	ldr r2, [sp, #0x024]
	movs r3, #0x03
	bl sub_0800D64C
	.global _0800DB1E
_0800DB1E:
	ldr r0, [sp, #0x02C]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x02C]
	movs r0, #0xC8
	lsls r0, r0, #0x01
	add r10, r0
	ldr r1, [sp, #0x02C]
	ldr r2, [sp, #0x040]
	cmp r1, r2
	beq _0800DB38
	b _0800D6FE
	.global _0800DB38
_0800DB38:
	add r3, sp, #0x020
	ldrb r0, [r3, #0x00]
	cmp r0, #0x00
	bne _0800DB42
	b _0800DE48
	.global _0800DB42
_0800DB42:
	ldr r4, _0800DC90 @ =0x0202CC90
	ldr r7, [r4, #0x00]
	ldr r6, [r4, #0x04]
	mov r8, r6
	ldrh r0, [r6, #0x34]
	lsrs r1, r0, #0x08
	ldr r2, _0800DC98 @ =0x0801CD08
	lsls r0, r1, #0x01
	adds r0, r0, r2
	movs r3, #0x00
	ldsh r6, [r0, r3]
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r2
	movs r0, #0x00
	ldsh r5, [r1, r0]
	ldr r0, _0800DC9C @ =0x083FDA2C
	ldrb r2, [r4, #0x09]
	lsls r1, r2, #0x03
	adds r2, r1, r0
	ldr r3, [r2, #0x00]
	adds r0, #0x04
	adds r1, r1, r0
	ldr r2, [r1, #0x00]
	adds r0, r3, #0x0
	muls r0, r5
	adds r1, r2, #0x0
	muls r1, r6
	subs r0, r0, r1
	asrs r0, r0, #0x04
	str r0, [sp, #0x030]
	adds r0, r3, #0x0
	muls r0, r6
	adds r1, r2, #0x0
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x04
	str r0, [sp, #0x034]
	ldr r0, [r4, #0x0C]
	negs r5, r0
	ldr r3, [sp, #0x030]
	adds r0, r5, #0x0
	muls r0, r3
	negs r0, r0
	cmp r0, #0x00
	bge _0800DBA0
	adds r0, #0xFF
	.global _0800DBA0
_0800DBA0:
	asrs r0, r0, #0x08
	str r0, [sp, #0x038]
	ldr r6, [sp, #0x034]
	adds r0, r5, #0x0
	muls r0, r6
	negs r0, r0
	cmp r0, #0x00
	bge _0800DBB2
	adds r0, #0xFF
	.global _0800DBB2
_0800DBB2:
	asrs r0, r0, #0x08
	str r0, [sp, #0x03C]
	ldr r0, [r7, #0x0C]
	ldr r1, [sp, #0x038]
	adds r0, r0, r1
	str r0, [r7, #0x0C]
	ldr r0, [r7, #0x14]
	ldr r2, [sp, #0x03C]
	adds r0, r0, r2
	str r0, [r7, #0x14]
	movs r4, #0xA0
	lsls r4, r4, #0x01
	adds r0, r7, r4
	movs r1, #0x00
	str r1, [r0, #0x00]
	movs r3, #0xA2
	lsls r3, r3, #0x01
	adds r0, r7, r3
	str r1, [r0, #0x00]
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r0, r7, r2
	str r1, [r0, #0x00]
	mov r6, r8
	ldr r0, [r6, #0x0C]
	ldr r6, [sp, #0x038]
	subs r0, r0, r6
	mov r6, r8
	str r0, [r6, #0x0C]
	ldr r0, [r6, #0x14]
	ldr r6, [sp, #0x03C]
	subs r0, r0, r6
	mov r6, r8
	str r0, [r6, #0x14]
	add r4, r8
	str r1, [r4, #0x00]
	add r3, r8
	str r1, [r3, #0x00]
	add r2, r8
	str r1, [r2, #0x00]
	lsls r0, r5, #0x05
	subs r0, r0, r5
	lsls r0, r0, #0x02
	adds r0, r0, r5
	lsls r5, r0, #0x03
	adds r0, r7, #0x0
	adds r0, #0x55
	ldrb r1, [r0, #0x00]
	adds r6, r0, #0x0
	cmp r1, #0x00
	bne _0800DC30
	movs r2, #0x06
	negs r2, r2
	str r1, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	movs r0, #0x00
	movs r1, #0x00
	movs r3, #0x00
	bl sub_0800BA34
	.global _0800DC30
_0800DC30:
	adds r0, r7, #0x0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	subs r0, #0x05
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _0800DCCC
	ldr r0, _0800DCA0 @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	adds r2, r7, #0x0
	adds r2, #0x88
	cmp r0, #0x00
	beq _0800DC54
	asrs r1, r5, #0x0C
	ldr r0, [r2, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	.global _0800DC54
_0800DC54:
	ldr r1, [r2, #0x00]
	ldr r0, _0800DCA4 @ =0x00009C40
	cmp r1, r0
	ble _0800DCC4
	ldr r0, [r7, #0x2C]
	negs r0, r0
	asrs r0, r0, #0x0C
	cmp r0, #0x00
	bge _0800DC68
	movs r0, #0x00
	.global _0800DC68
_0800DC68:
	cmp r0, #0x32
	ble _0800DCB4
	ldr r0, _0800DCA8 @ =0x0202A550
	subs r0, r7, r0
	ldr r1, _0800DCAC @ =0xC28F5C29
	adds r4, r0, #0x0
	muls r4, r1
	asrs r4, r4, #0x04
	ldr r0, _0800DCB0 @ =0x0202A530
	ldrb r0, [r0, #0x00]
	movs r1, #0x03
	bl sub_08017498
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0x0
	bl sub_0800E708
	b _0800DCC4
	.global _0800DC90
_0800DC90: .4byte 0x0202CC90
	.global _0800DC94
_0800DC94: .4byte 0xFFFFF100
	.global _0800DC98
_0800DC98: .4byte 0x0801CD08
	.global _0800DC9C
_0800DC9C: .4byte 0x083FDA2C
	.global _0800DCA0
_0800DCA0: .4byte 0x0202EEB0
	.global _0800DCA4
_0800DCA4: .4byte 0x00009C40
	.global _0800DCA8
_0800DCA8: .4byte 0x0202A550
	.global _0800DCAC
_0800DCAC: .4byte 0xC28F5C29
	.global _0800DCB0
_0800DCB0: .4byte 0x0202A530
	.global _0800DCB4
_0800DCB4:
	ldr r0, _0800DD64 @ =0x0202A550
	subs r0, r7, r0
	ldr r1, _0800DD68 @ =0xC28F5C29
	muls r0, r1
	asrs r0, r0, #0x04
	movs r1, #0x04
	bl sub_0800E708
	.global _0800DCC4
_0800DCC4:
	ldr r1, _0800DD6C @ =0x0202A530
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	.global _0800DCCC
_0800DCCC:
	adds r0, r7, #0x0
	bl sub_0800A2D4
	ldr r0, [r7, #0x2C]
	str r0, [r7, #0x48]
	cmp r0, #0x00
	ble _0800DCDE
	movs r0, #0x00
	str r0, [r7, #0x48]
	.global _0800DCDE
_0800DCDE:
	ldr r0, [r7, #0x48]
	lsls r0, r0, #0x08
	adds r3, r7, #0x0
	adds r3, #0x3E
	adds r1, r7, #0x0
	adds r1, #0xE8
	ldr r2, [r1, #0x00]
	ldrb r3, [r3, #0x00]
	lsls r1, r3, #0x01
	adds r1, r1, r2
	ldrh r1, [r1, #0x00]
	negs r1, r1
	bl sub_08017230
	adds r1, r7, #0x0
	adds r1, #0x40
	strh r0, [r1, #0x00]
	mov r0, r8
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	subs r0, #0x05
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _0800DD92
	ldr r0, _0800DD70 @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	mov r2, r8
	adds r2, #0x88
	cmp r0, #0x00
	beq _0800DD24
	asrs r1, r5, #0x0E
	ldr r0, [r2, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	.global _0800DD24
_0800DD24:
	ldr r1, [r2, #0x00]
	ldr r0, _0800DD74 @ =0x00009C40
	cmp r1, r0
	ble _0800DD8A
	mov r1, r8
	ldr r0, [r1, #0x2C]
	negs r0, r0
	asrs r0, r0, #0x0C
	cmp r0, #0x00
	bge _0800DD3A
	movs r0, #0x00
	.global _0800DD3A
_0800DD3A:
	cmp r0, #0x32
	ble _0800DD78
	ldr r0, _0800DD64 @ =0x0202A550
	mov r2, r8
	subs r0, r2, r0
	ldr r1, _0800DD68 @ =0xC28F5C29
	adds r4, r0, #0x0
	muls r4, r1
	asrs r4, r4, #0x04
	ldr r0, _0800DD6C @ =0x0202A530
	ldrb r0, [r0, #0x00]
	movs r1, #0x03
	bl sub_08017498
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0x0
	bl sub_0800E708
	b _0800DD8A
	.global _0800DD64
_0800DD64: .4byte 0x0202A550
	.global _0800DD68
_0800DD68: .4byte 0xC28F5C29
	.global _0800DD6C
_0800DD6C: .4byte 0x0202A530
	.global _0800DD70
_0800DD70: .4byte 0x0202EEB0
	.global _0800DD74
_0800DD74: .4byte 0x00009C40
	.global _0800DD78
_0800DD78:
	ldr r0, _0800DE2C @ =0x0202A550
	mov r3, r8
	subs r0, r3, r0
	ldr r1, _0800DE30 @ =0xC28F5C29
	muls r0, r1
	asrs r0, r0, #0x04
	movs r1, #0x04
	bl sub_0800E708
	.global _0800DD8A
_0800DD8A:
	ldr r1, _0800DE34 @ =0x0202A530
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	.global _0800DD92
_0800DD92:
	mov r0, r8
	bl sub_0800A2D4
	mov r1, r8
	ldr r0, [r1, #0x2C]
	str r0, [r1, #0x48]
	cmp r0, #0x00
	ble _0800DDA6
	movs r0, #0x00
	str r0, [r1, #0x48]
	.global _0800DDA6
_0800DDA6:
	mov r2, r8
	ldr r0, [r2, #0x48]
	lsls r0, r0, #0x08
	mov r3, r8
	adds r3, #0x3E
	mov r1, r8
	adds r1, #0xE8
	ldr r2, [r1, #0x00]
	ldrb r3, [r3, #0x00]
	lsls r1, r3, #0x01
	adds r1, r1, r2
	ldrh r1, [r1, #0x00]
	negs r1, r1
	bl sub_08017230
	mov r1, r8
	adds r1, #0x40
	strh r0, [r1, #0x00]
	ldr r2, _0800DE2C @ =0x0202A550
	cmp r7, r2
	beq _0800DDE0
	cmp r8, r2
	beq _0800DDE0
	ldr r0, _0800DE38 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	mov r4, r8
	adds r4, #0x55
	cmp r0, #0x00
	beq _0800DE20
	.global _0800DDE0
_0800DDE0:
	ldr r0, _0800DE3C @ =0x020021E0
	ldrb r0, [r0, #0x00]
	mov r4, r8
	adds r4, #0x55
	cmp r0, #0x00
	bne _0800DE20
	ldr r0, _0800DE40 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800DE20
	ldr r0, _0800DE44 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0800DE20
	ldr r3, [sp, #0x024]
	cmp r3, r2
	beq _0800DE0A
	ldr r0, _0800DE38 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800DE20
	.global _0800DE0A
_0800DE0A:
	ldrb r0, [r6, #0x00]
	mov r4, r8
	adds r4, #0x55
	cmp r0, #0x00
	bne _0800DE20
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _0800DE20
	movs r0, #0x12
	bl sub_08001208
	.global _0800DE20
_0800DE20:
	movs r0, #0x10
	strb r0, [r6, #0x00]
	strb r0, [r4, #0x00]
	movs r0, #0x01
	b _0800DE4A
	.byte 0x00, 0x00
	.global _0800DE2C
_0800DE2C: .4byte 0x0202A550
	.global _0800DE30
_0800DE30: .4byte 0xC28F5C29
	.global _0800DE34
_0800DE34: .4byte 0x0202A530
	.global _0800DE38
_0800DE38: .4byte 0x020020DC
	.global _0800DE3C
_0800DE3C: .4byte 0x020021E0
	.global _0800DE40
_0800DE40: .4byte 0x020020E0
	.global _0800DE44
_0800DE44: .4byte 0x0202EF00
	.global _0800DE48
_0800DE48:
	movs r0, #0x00
	.global _0800DE4A
_0800DE4A:
	add sp, #0x044
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x00, 0x47, 0x70, 0x47
	thumb_func_start sub_0800DE60
sub_0800DE60:
	push {r4, lr}
	ldr r3, _0800DE90 @ =0x0202E960
	lsls r0, r0, #0x17
	lsrs r0, r0, #0x17
	ldr r2, _0800DE94 @ =0xFFFFFE00
	ldrh r4, [r3, #0x12]
	ands r2, r4
	orrs r2, r0
	strh r2, [r3, #0x12]
	strb r1, [r3, #0x10]
	movs r0, #0x3F
	ldrb r1, [r3, #0x13]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r3, #0x13]
	ldr r0, _0800DE98 @ =0xFFFFFC00
	ldrh r4, [r3, #0x14]
	ands r0, r4
	strh r0, [r3, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800DE90
_0800DE90: .4byte 0x0202E960
	.global _0800DE94
_0800DE94: .4byte 0xFFFFFE00
	.global _0800DE98
_0800DE98: .4byte 0xFFFFFC00
	thumb_func_start sub_0800DE9C
sub_0800DE9C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r0, _0800DF44 @ =0x0202E960
	mov r12, r0
	mov r1, r12
	adds r1, #0x4A
	ldr r4, _0800DF48 @ =0xFFFFFE00
	adds r0, r4, #0x0
	ldrh r2, [r1, #0x00]
	ands r0, r2
	strh r0, [r1, #0x00]
	mov r0, r12
	adds r0, #0x48
	strb r6, [r0, #0x00]
	mov r2, r12
	adds r2, #0x4B
	movs r0, #0x3F
	ldrb r7, [r2, #0x00]
	ands r0, r7
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #0x00]
	mov r1, r12
	adds r1, #0x4D
	movs r0, #0x0F
	ldrb r2, [r1, #0x00]
	ands r0, r2
	strb r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x4C
	ldr r3, _0800DF4C @ =0xFFFFFC00
	adds r0, r3, #0x0
	ldrh r7, [r2, #0x00]
	ands r0, r7
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r5, #0x00
	mov r10, r12
	mov r9, r4
	adds r4, r3, #0x0
	.global _0800DEFE
_0800DEFE:
	adds r0, r5, #0x0
	adds r0, #0x0A
	lsls r0, r0, #0x03
	mov r1, r10
	adds r3, r0, r1
	lsls r2, r5, #0x05
	adds r2, #0x20
	ldr r7, _0800DF50 @ =0x000001FF
	adds r0, r7, #0x0
	adds r1, r2, #0x0
	ands r1, r0
	mov r0, r9
	ldrh r7, [r3, #0x02]
	ands r0, r7
	orrs r0, r1
	strh r0, [r3, #0x02]
	strb r6, [r3, #0x00]
	movs r0, #0x3F
	ldrb r1, [r3, #0x03]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r3, #0x03]
	movs r0, #0x0F
	ldrb r7, [r3, #0x05]
	ands r0, r7
	strb r0, [r3, #0x05]
	cmp r8, r2
	bge _0800DF54
	adds r0, r4, #0x0
	ldrh r1, [r3, #0x04]
	ands r0, r1
	movs r1, #0x20
	b _0800DF5C
	.byte 0x00, 0x00
	.global _0800DF44
_0800DF44: .4byte 0x0202E960
	.global _0800DF48
_0800DF48: .4byte 0xFFFFFE00
	.global _0800DF4C
_0800DF4C: .4byte 0xFFFFFC00
	.global _0800DF50
_0800DF50: .4byte 0x000001FF
	.global _0800DF54
_0800DF54:
	adds r0, r4, #0x0
	ldrh r2, [r3, #0x04]
	ands r0, r2
	movs r1, #0x10
	.global _0800DF5C
_0800DF5C:
	orrs r0, r1
	strh r0, [r3, #0x04]
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x07
	bls _0800DEFE
	mov r2, r12
	adds r2, #0x82
	ldr r0, _0800DFB8 @ =0xFFFFFE00
	ldrh r7, [r2, #0x00]
	ands r0, r7
	movs r1, #0xD0
	orrs r0, r1
	strh r0, [r2, #0x00]
	mov r0, r12
	adds r0, #0x80
	strb r6, [r0, #0x00]
	adds r2, #0x01
	movs r0, #0x3F
	ldrb r1, [r2, #0x00]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #0x00]
	mov r1, r12
	adds r1, #0x85
	movs r0, #0x0F
	ldrb r2, [r1, #0x00]
	ands r0, r2
	strb r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x84
	ldr r0, _0800DFBC @ =0xFFFFFC00
	ldrh r7, [r2, #0x00]
	ands r0, r7
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r2, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800DFB8
_0800DFB8: .4byte 0xFFFFFE00
	.global _0800DFBC
_0800DFBC: .4byte 0xFFFFFC00
	.byte 0x01, 0x49, 0x01, 0x20, 0x08, 0x80, 0x70, 0x47, 0xF8, 0x7F, 0x00, 0x03
