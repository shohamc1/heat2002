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
	thumb_func_start sub_08343EA8
sub_08343EA8:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x044
	str r0, [sp, #0x024]
	ldr r0, _0834421C @ =0x020390A0
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x040]
	ldr r0, _08344220 @ =0x020390EC
	ldrb r1, [r0, #0x00]
	cmp r1, #0x00
	beq _08343ECA
	ldr r0, _08344224 @ =0x020390BC
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x040]
	.global _08343ECA
_08343ECA:
	ldr r0, [sp, #0x024]
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08343EDA
	cmp r1, #0x00
	beq _08343EDA
	b _0834466C
	.global _08343EDA
_08343EDA:
	ldr r1, [sp, #0x024]
	ldr r2, _08344228 @ =0x00000175
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	ldr r2, _0834422C @ =0x0203D520
	cmp r0, #0x00
	beq _08343EFC
	cmp r1, r2
	bne _08343EEE
	b _0834466C
	.global _08343EEE
_08343EEE:
	ldr r3, [sp, #0x024]
	ldr r1, _08344230 @ =0x0000018F
	adds r0, r3, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08343EFC
	b _0834466C
	.global _08343EFC
_08343EFC:
	ldr r1, _08344234 @ =0x0203DF44
	movs r0, #0x80
	lsls r0, r0, #0x0E
	str r0, [r1, #0x00]
	add r4, sp, #0x020
	movs r0, #0x00
	strb r0, [r4, #0x00]
	mov r10, r2
	ldr r7, _08344238 @ =0x0203DED0
	ldr r0, [sp, #0x024]
	adds r1, r7, #0x0
	bl sub_08343DF8
	movs r2, #0x00
	str r2, [sp, #0x02C]
	ldr r3, [sp, #0x040]
	cmp r2, r3
	bne _08343F22
	b _0834435C
	.global _08343F22
_08343F22:
	ldr r0, [sp, #0x024]
	cmp r10, r0
	bne _08343F2A
	b _08344342
	.global _08343F2A
_08343F2A:
	ldr r0, _08344228 @ =0x00000175
	add r0, r10
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08343F48
	ldr r0, _0834422C @ =0x0203D520
	cmp r10, r0
	bne _08343F3C
	b _08344342
	.global _08343F3C
_08343F3C:
	ldr r0, _08344230 @ =0x0000018F
	add r0, r10
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08343F48
	b _08344342
	.global _08343F48
_08343F48:
	mov r0, r10
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08343F5C
	ldr r0, _08344220 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08343F5C
	b _08344342
	.global _08343F5C
_08343F5C:
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
	bge _08343F76
	negs r2, r2
	.global _08343F76
_08343F76:
	movs r1, #0xC8
	lsls r1, r1, #0x07
	cmp r2, r1
	ble _08343F80
	b _08344342
	.global _08343F80
_08343F80:
	cmp r0, #0x00
	bge _08343F86
	negs r0, r0
	.global _08343F86
_08343F86:
	cmp r0, r1
	ble _08343F8C
	b _08344342
	.global _08343F8C
_08343F8C:
	mov r0, r10
	ldr r1, _0834423C @ =0x0203DF50
	bl sub_08343DF8
	ldr r0, _08344238 @ =0x0203DED0
	ldr r5, [r0, #0x10]
	ldr r6, [r0, #0x14]
	ldr r1, _0834423C @ =0x0203DF50
	ldr r0, [r1, #0x10]
	subs r5, r5, r0
	ldr r0, [r1, #0x14]
	subs r6, r6, r0
	ldr r3, [r1, #0x04]
	adds r1, r3, #0x0
	muls r1, r5
	ldr r0, _0834423C @ =0x0203DF50
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
	ldr r1, _08344238 @ =0x0203DED0
	ldr r5, [r1, #0x18]
	ldr r6, [r1, #0x1C]
	ldr r2, _0834423C @ =0x0203DF50
	ldr r0, [r2, #0x18]
	subs r5, r5, r0
	ldr r0, [r2, #0x1C]
	subs r6, r6, r0
	ldr r3, [r2, #0x0C]
	adds r2, r3, #0x0
	muls r2, r5
	ldr r0, _0834423C @ =0x0203DF50
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
	bge _08344052
	movs r0, #0xE0
	lsls r0, r0, #0x05
	cmp r1, r0
	bgt _08344052
	ldr r0, _08344240 @ =0xFFFFE400
	adds r4, r4, r0
	cmp r4, #0x00
	blt _08344052
	mov r0, r8
	muls r0, r4
	adds r1, r7, #0x0
	bl sub_08344BB8
	adds r1, r0, #0x0
	add r1, r9
	movs r2, #0xF0
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bhi _08344052
	ldr r3, _08344244 @ =0x0203DEB0
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	negs r1, r7
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08344BB8
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x024]
	ldr r1, [sp, #0x028]
	mov r2, r10
	movs r3, #0x00
	bl sub_08343E70
	.global _08344052
_08344052:
	cmp r7, #0x00
	ble _083440A4
	ldr r0, [sp, #0x01C]
	ldr r1, _08344240 @ =0xFFFFE400
	cmp r0, r1
	blt _083440A4
	ldr r0, [sp, #0x014]
	subs r4, r1, r0
	cmp r4, #0x00
	blt _083440A4
	mov r0, r8
	muls r0, r4
	adds r1, r7, #0x0
	bl sub_08344BB8
	adds r1, r0, #0x0
	ldr r0, [sp, #0x010]
	adds r1, r1, r0
	movs r2, #0xF0
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bhi _083440A4
	ldr r3, _08344244 @ =0x0203DEB0
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	str r7, [sp, #0x008]
	lsls r0, r4, #0x10
	adds r1, r7, #0x0
	bl sub_08344BB8
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x024]
	ldr r1, [sp, #0x028]
	mov r2, r10
	movs r3, #0x01
	bl sub_08343E70
	.global _083440A4
_083440A4:
	mov r1, r8
	cmp r1, #0x00
	ble _083440F8
	ldr r0, [sp, #0x018]
	ldr r1, _08344248 @ =0xFFFFF100
	cmp r0, r1
	blt _083440F8
	ldr r0, [sp, #0x010]
	subs r4, r1, r0
	cmp r4, #0x00
	blt _083440F8
	adds r0, r4, #0x0
	muls r0, r7
	mov r1, r8
	bl sub_08344BB8
	adds r1, r0, #0x0
	ldr r0, [sp, #0x014]
	adds r1, r1, r0
	movs r2, #0xE0
	lsls r2, r2, #0x05
	adds r1, r1, r2
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r1, r0
	bhi _083440F8
	ldr r3, _08344244 @ =0x0203DEB0
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	mov r1, r8
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08344BB8
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x024]
	ldr r1, [sp, #0x028]
	mov r2, r10
	movs r3, #0x02
	bl sub_08343E70
	.global _083440F8
_083440F8:
	mov r2, r8
	cmp r2, #0x00
	bge _08344152
	ldr r1, [sp, #0x018]
	movs r0, #0xF0
	lsls r0, r0, #0x04
	cmp r1, r0
	bgt _08344152
	ldr r0, [sp, #0x010]
	ldr r3, _08344248 @ =0xFFFFF100
	adds r4, r0, r3
	cmp r4, #0x00
	blt _08344152
	adds r0, r4, #0x0
	muls r0, r7
	mov r1, r8
	bl sub_08344BB8
	adds r1, r0, #0x0
	ldr r0, [sp, #0x014]
	adds r1, r1, r0
	movs r0, #0xE0
	lsls r0, r0, #0x05
	adds r1, r1, r0
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r1, r0
	bhi _08344152
	ldr r1, _08344244 @ =0x0203DEB0
	str r1, [sp, #0x000]
	add r2, sp, #0x020
	str r2, [sp, #0x004]
	mov r3, r8
	negs r1, r3
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08344BB8
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x024]
	ldr r1, [sp, #0x028]
	mov r2, r10
	movs r3, #0x03
	bl sub_08343E70
	.global _08344152
_08344152:
	ldr r0, _0834423C @ =0x0203DF50
	ldr r5, [r0, #0x10]
	ldr r6, [r0, #0x14]
	ldr r1, _08344238 @ =0x0203DED0
	ldr r0, [r1, #0x10]
	subs r5, r5, r0
	ldr r0, [r1, #0x14]
	subs r6, r6, r0
	ldr r3, [r1, #0x04]
	adds r1, r3, #0x0
	muls r1, r5
	ldr r0, _08344238 @ =0x0203DED0
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
	ldr r1, _0834423C @ =0x0203DF50
	ldr r5, [r1, #0x18]
	ldr r6, [r1, #0x1C]
	ldr r2, _08344238 @ =0x0203DED0
	ldr r0, [r2, #0x18]
	subs r5, r5, r0
	ldr r0, [r2, #0x1C]
	subs r6, r6, r0
	ldr r3, [r2, #0x0C]
	adds r2, r3, #0x0
	muls r2, r5
	ldr r0, _08344238 @ =0x0203DED0
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
	bge _08344210
	movs r0, #0xE0
	lsls r0, r0, #0x05
	cmp r1, r0
	bgt _08344210
	ldr r0, _08344240 @ =0xFFFFE400
	adds r4, r4, r0
	cmp r4, #0x00
	blt _08344210
	mov r0, r8
	muls r0, r4
	adds r1, r7, #0x0
	bl sub_08344BB8
	adds r1, r0, #0x0
	add r1, r9
	movs r2, #0xF0
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bhi _08344210
	ldr r3, _08344244 @ =0x0203DEB0
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	negs r1, r7
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08344BB8
	str r0, [sp, #0x00C]
	mov r0, r10
	ldr r1, [sp, #0x028]
	ldr r2, [sp, #0x024]
	movs r3, #0x00
	bl sub_08343E70
	.global _08344210
_08344210:
	cmp r7, #0x00
	ble _08344294
	ldr r0, [sp, #0x01C]
	ldr r1, _08344240 @ =0xFFFFE400
	cmp r0, r1
	b _0834424C
	.global _0834421C
_0834421C: .4byte 0x020390A0
	.global _08344220
_08344220: .4byte 0x020390EC
	.global _08344224
_08344224: .4byte 0x020390BC
	.global _08344228
_08344228: .4byte 0x00000175
	.global _0834422C
_0834422C: .4byte 0x0203D520
	.global _08344230
_08344230: .4byte 0x0000018F
	.global _08344234
_08344234: .4byte 0x0203DF44
	.global _08344238
_08344238: .4byte 0x0203DED0
	.global _0834423C
_0834423C: .4byte 0x0203DF50
	.global _08344240
_08344240: .4byte 0xFFFFE400
	.global _08344244
_08344244: .4byte 0x0203DEB0
	.global _08344248
_08344248: .4byte 0xFFFFF100
	.global _0834424C
_0834424C:
	blt _08344294
	ldr r0, [sp, #0x014]
	subs r4, r1, r0
	cmp r4, #0x00
	blt _08344294
	mov r0, r8
	muls r0, r4
	adds r1, r7, #0x0
	bl sub_08344BB8
	adds r1, r0, #0x0
	ldr r0, [sp, #0x010]
	adds r1, r1, r0
	movs r2, #0xF0
	lsls r2, r2, #0x04
	adds r1, r1, r2
	movs r0, #0xF0
	lsls r0, r0, #0x05
	cmp r1, r0
	bhi _08344294
	ldr r3, _083444B4 @ =0x0203DEB0
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	str r7, [sp, #0x008]
	lsls r0, r4, #0x10
	adds r1, r7, #0x0
	bl sub_08344BB8
	str r0, [sp, #0x00C]
	mov r0, r10
	ldr r1, [sp, #0x028]
	ldr r2, [sp, #0x024]
	movs r3, #0x01
	bl sub_08343E70
	.global _08344294
_08344294:
	mov r1, r8
	cmp r1, #0x00
	ble _083442E8
	ldr r0, [sp, #0x018]
	ldr r1, _083444B8 @ =0xFFFFF100
	cmp r0, r1
	blt _083442E8
	ldr r0, [sp, #0x010]
	subs r4, r1, r0
	cmp r4, #0x00
	blt _083442E8
	adds r0, r4, #0x0
	muls r0, r7
	mov r1, r8
	bl sub_08344BB8
	adds r1, r0, #0x0
	ldr r0, [sp, #0x014]
	adds r1, r1, r0
	movs r2, #0xE0
	lsls r2, r2, #0x05
	adds r1, r1, r2
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r1, r0
	bhi _083442E8
	ldr r3, _083444B4 @ =0x0203DEB0
	str r3, [sp, #0x000]
	add r0, sp, #0x020
	str r0, [sp, #0x004]
	mov r1, r8
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08344BB8
	str r0, [sp, #0x00C]
	mov r0, r10
	ldr r1, [sp, #0x028]
	ldr r2, [sp, #0x024]
	movs r3, #0x02
	bl sub_08343E70
	.global _083442E8
_083442E8:
	mov r2, r8
	cmp r2, #0x00
	bge _08344342
	ldr r1, [sp, #0x018]
	movs r0, #0xF0
	lsls r0, r0, #0x04
	cmp r1, r0
	bgt _08344342
	ldr r0, [sp, #0x010]
	ldr r3, _083444B8 @ =0xFFFFF100
	adds r4, r0, r3
	cmp r4, #0x00
	blt _08344342
	adds r0, r4, #0x0
	muls r0, r7
	mov r1, r8
	bl sub_08344BB8
	adds r1, r0, #0x0
	ldr r0, [sp, #0x014]
	adds r1, r1, r0
	movs r0, #0xE0
	lsls r0, r0, #0x05
	adds r1, r1, r0
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r1, r0
	bhi _08344342
	ldr r1, _083444B4 @ =0x0203DEB0
	str r1, [sp, #0x000]
	add r2, sp, #0x020
	str r2, [sp, #0x004]
	mov r3, r8
	negs r1, r3
	str r1, [sp, #0x008]
	lsls r0, r4, #0x10
	bl sub_08344BB8
	str r0, [sp, #0x00C]
	mov r0, r10
	ldr r1, [sp, #0x028]
	ldr r2, [sp, #0x024]
	movs r3, #0x03
	bl sub_08343E70
	.global _08344342
_08344342:
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
	beq _0834435C
	b _08343F22
	.global _0834435C
_0834435C:
	add r3, sp, #0x020
	ldrb r0, [r3, #0x00]
	cmp r0, #0x00
	bne _08344366
	b _0834466C
	.global _08344366
_08344366:
	ldr r4, _083444B4 @ =0x0203DEB0
	ldr r7, [r4, #0x00]
	ldr r6, [r4, #0x04]
	mov r8, r6
	ldrh r0, [r6, #0x34]
	lsrs r1, r0, #0x08
	ldr r2, _083444BC @ =0x0200C3E8
	lsls r0, r1, #0x01
	adds r0, r0, r2
	movs r3, #0x00
	ldsh r6, [r0, r3]
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r2
	movs r0, #0x00
	ldsh r5, [r1, r0]
	ldr r0, _083444C0 @ =0x0202AF08
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
	bge _083443C4
	adds r0, #0xFF
	.global _083443C4
_083443C4:
	asrs r0, r0, #0x08
	str r0, [sp, #0x038]
	ldr r6, [sp, #0x034]
	adds r0, r5, #0x0
	muls r0, r6
	negs r0, r0
	cmp r0, #0x00
	bge _083443D6
	adds r0, #0xFF
	.global _083443D6
_083443D6:
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
	bne _08344454
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
	bl sub_08343138
	.global _08344454
_08344454:
	adds r0, r7, #0x0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	subs r0, #0x05
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _083444F0
	ldr r0, _083444C4 @ =0x0203E0E0
	ldrb r0, [r0, #0x00]
	adds r2, r7, #0x0
	adds r2, #0x88
	cmp r0, #0x00
	beq _08344478
	asrs r1, r5, #0x0C
	ldr r0, [r2, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	.global _08344478
_08344478:
	ldr r1, [r2, #0x00]
	ldr r0, _083444C8 @ =0x00009C40
	cmp r1, r0
	ble _083444E8
	ldr r0, [r7, #0x2C]
	negs r0, r0
	asrs r0, r0, #0x0C
	cmp r0, #0x00
	bge _0834448C
	movs r0, #0x00
	.global _0834448C
_0834448C:
	cmp r0, #0x32
	ble _083444D8
	ldr r0, _083444CC @ =0x0203D520
	subs r0, r7, r0
	ldr r1, _083444D0 @ =0xC28F5C29
	adds r4, r0, #0x0
	muls r4, r1
	asrs r4, r4, #0x04
	ldr r0, _083444D4 @ =0x0203D4FC
	ldrb r0, [r0, #0x00]
	movs r1, #0x03
	bl sub_08344DA8
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0x0
	bl sub_08344680
	b _083444E8
	.global _083444B4
_083444B4: .4byte 0x0203DEB0
	.global _083444B8
_083444B8: .4byte 0xFFFFF100
	.global _083444BC
_083444BC: .4byte 0x0200C3E8
	.global _083444C0
_083444C0: .4byte 0x0202AF08
	.global _083444C4
_083444C4: .4byte 0x0203E0E0
	.global _083444C8
_083444C8: .4byte 0x00009C40
	.global _083444CC
_083444CC: .4byte 0x0203D520
	.global _083444D0
_083444D0: .4byte 0xC28F5C29
	.global _083444D4
_083444D4: .4byte 0x0203D4FC
	.global _083444D8
_083444D8:
	ldr r0, _08344588 @ =0x0203D520
	subs r0, r7, r0
	ldr r1, _0834458C @ =0xC28F5C29
	muls r0, r1
	asrs r0, r0, #0x04
	movs r1, #0x04
	bl sub_08344680
	.global _083444E8
_083444E8:
	ldr r1, _08344590 @ =0x0203D4FC
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	.global _083444F0
_083444F0:
	adds r0, r7, #0x0
	bl sub_08341D64
	ldr r0, [r7, #0x2C]
	str r0, [r7, #0x48]
	cmp r0, #0x00
	ble _08344502
	movs r0, #0x00
	str r0, [r7, #0x48]
	.global _08344502
_08344502:
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
	bl sub_08344BB8
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
	bls _083445B6
	ldr r0, _08344594 @ =0x0203E0E0
	ldrb r0, [r0, #0x00]
	mov r2, r8
	adds r2, #0x88
	cmp r0, #0x00
	beq _08344548
	asrs r1, r5, #0x0E
	ldr r0, [r2, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	.global _08344548
_08344548:
	ldr r1, [r2, #0x00]
	ldr r0, _08344598 @ =0x00009C40
	cmp r1, r0
	ble _083445AE
	mov r1, r8
	ldr r0, [r1, #0x2C]
	negs r0, r0
	asrs r0, r0, #0x0C
	cmp r0, #0x00
	bge _0834455E
	movs r0, #0x00
	.global _0834455E
_0834455E:
	cmp r0, #0x32
	ble _0834459C
	ldr r0, _08344588 @ =0x0203D520
	mov r2, r8
	subs r0, r2, r0
	ldr r1, _0834458C @ =0xC28F5C29
	adds r4, r0, #0x0
	muls r4, r1
	asrs r4, r4, #0x04
	ldr r0, _08344590 @ =0x0203D4FC
	ldrb r0, [r0, #0x00]
	movs r1, #0x03
	bl sub_08344DA8
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0x0
	bl sub_08344680
	b _083445AE
	.global _08344588
_08344588: .4byte 0x0203D520
	.global _0834458C
_0834458C: .4byte 0xC28F5C29
	.global _08344590
_08344590: .4byte 0x0203D4FC
	.global _08344594
_08344594: .4byte 0x0203E0E0
	.global _08344598
_08344598: .4byte 0x00009C40
	.global _0834459C
_0834459C:
	ldr r0, _08344650 @ =0x0203D520
	mov r3, r8
	subs r0, r3, r0
	ldr r1, _08344654 @ =0xC28F5C29
	muls r0, r1
	asrs r0, r0, #0x04
	movs r1, #0x04
	bl sub_08344680
	.global _083445AE
_083445AE:
	ldr r1, _08344658 @ =0x0203D4FC
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	.global _083445B6
_083445B6:
	mov r0, r8
	bl sub_08341D64
	mov r1, r8
	ldr r0, [r1, #0x2C]
	str r0, [r1, #0x48]
	cmp r0, #0x00
	ble _083445CA
	movs r0, #0x00
	str r0, [r1, #0x48]
	.global _083445CA
_083445CA:
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
	bl sub_08344BB8
	mov r1, r8
	adds r1, #0x40
	strh r0, [r1, #0x00]
	ldr r2, _08344650 @ =0x0203D520
	cmp r7, r2
	beq _08344604
	cmp r8, r2
	beq _08344604
	ldr r0, _0834465C @ =0x020390EC
	ldrb r0, [r0, #0x00]
	mov r4, r8
	adds r4, #0x55
	cmp r0, #0x00
	beq _08344644
	.global _08344604
_08344604:
	ldr r0, _08344660 @ =0x020391F0
	ldrb r0, [r0, #0x00]
	mov r4, r8
	adds r4, #0x55
	cmp r0, #0x00
	bne _08344644
	ldr r0, _08344664 @ =0x020390F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08344644
	ldr r0, _08344668 @ =0x0203E120
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08344644
	ldr r3, [sp, #0x024]
	cmp r3, r2
	beq _0834462E
	ldr r0, _0834465C @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08344644
	.global _0834462E
_0834462E:
	ldrb r0, [r6, #0x00]
	mov r4, r8
	adds r4, #0x55
	cmp r0, #0x00
	bne _08344644
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _08344644
	movs r0, #0x12
	bl sub_0833A8C8
	.global _08344644
_08344644:
	movs r0, #0x10
	strb r0, [r6, #0x00]
	strb r0, [r4, #0x00]
	movs r0, #0x01
	b _0834466E
	.byte 0x00, 0x00
	.global _08344650
_08344650: .4byte 0x0203D520
	.global _08344654
_08344654: .4byte 0xC28F5C29
	.global _08344658
_08344658: .4byte 0x0203D4FC
	.global _0834465C
_0834465C: .4byte 0x020390EC
	.global _08344660
_08344660: .4byte 0x020391F0
	.global _08344664
_08344664: .4byte 0x020390F0
	.global _08344668
_08344668: .4byte 0x0203E120
	.global _0834466C
_0834466C:
	movs r0, #0x00
	.global _0834466E
_0834466E:
	add sp, #0x044
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
