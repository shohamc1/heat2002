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
	thumb_func_start sub_08001C88
sub_08001C88:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x020
	ldr r0, _08001CA8 @ =0x03007FF0
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x004]
	ldrb r0, [r0, #0x0A]
	cmp r0, #0x00
	beq _08001CAC
	subs r0, #0x01
	ldr r1, [sp, #0x004]
	strb r0, [r1, #0x0A]
	b _08001CB2
_08001CA8: .4byte 0x03007FF0
_08001CAC:
	movs r0, #0x0E
	ldr r2, [sp, #0x004]
	strb r0, [r2, #0x0A]
_08001CB2:
	movs r6, #0x01
	ldr r0, [sp, #0x004]
	ldr r4, [r0, #0x1C]
_08001CB8:
	ldrb r1, [r4, #0x00]
	movs r0, #0xC7
	ands r0, r1
	adds r2, r6, #0x1
	mov r9, r2
	movs r2, #0x40
	adds r2, r2, r4
	mov r8, r2
	cmp r0, #0x00
	bne _08001CCE
	b _080020B2
_08001CCE:
	cmp r6, #0x02
	beq _08001D00
	cmp r6, #0x02
	bgt _08001CDC
	cmp r6, #0x01
	beq _08001CE2
	b _08001D38
_08001CDC:
	cmp r6, #0x03
	beq _08001D18
	b _08001D38
_08001CE2:
	ldr r0, _08001CF4 @ =0x04000060
	str r0, [sp, #0x008]
	ldr r7, _08001CF8 @ =0x04000062
	ldr r2, _08001CFC @ =0x04000063
	str r2, [sp, #0x00C]
	adds r0, #0x04
	str r0, [sp, #0x010]
	adds r2, #0x02
	b _08001D48
_08001CF4: .4byte 0x04000060
_08001CF8: .4byte 0x04000062
_08001CFC: .4byte 0x04000063
_08001D00:
	ldr r0, _08001D0C @ =0x04000061
	str r0, [sp, #0x008]
	ldr r7, _08001D10 @ =0x04000068
	ldr r2, _08001D14 @ =0x04000069
	b _08001D40
	.byte 0x00, 0x00
_08001D0C: .4byte 0x04000061
_08001D10: .4byte 0x04000068
_08001D14: .4byte 0x04000069
_08001D18:
	ldr r0, _08001D2C @ =0x04000070
	str r0, [sp, #0x008]
	ldr r7, _08001D30 @ =0x04000072
	ldr r2, _08001D34 @ =0x04000073
	str r2, [sp, #0x00C]
	adds r0, #0x04
	str r0, [sp, #0x010]
	adds r2, #0x02
	b _08001D48
	.byte 0x00, 0x00
_08001D2C: .4byte 0x04000070
_08001D30: .4byte 0x04000072
_08001D34: .4byte 0x04000073
_08001D38:
	ldr r0, _08001D94 @ =0x04000071
	str r0, [sp, #0x008]
	ldr r7, _08001D98 @ =0x04000078
	ldr r2, _08001D9C @ =0x04000079
_08001D40:
	str r2, [sp, #0x00C]
	adds r0, #0x0B
	str r0, [sp, #0x010]
	adds r2, #0x04
_08001D48:
	str r2, [sp, #0x014]
	ldr r0, [sp, #0x004]
	ldrb r0, [r0, #0x0A]
	str r0, [sp, #0x000]
	adds r2, r1, #0x0
	movs r0, #0x80
	mov r10, r0
	ands r0, r2
	cmp r0, #0x00
	beq _08001E42
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
	bne _08001E66
	movs r0, #0x03
	strb r0, [r4, #0x00]
	strb r0, [r4, #0x1D]
	adds r0, r4, #0x0
	str r3, [sp, #0x01C]
	bl sub_08001C20
	ldr r3, [sp, #0x01C]
	cmp r6, #0x02
	beq _08001DAC
	cmp r6, #0x02
	bgt _08001DA0
	cmp r6, #0x01
	beq _08001DA6
	b _08001E04
	.byte 0x00, 0x00
_08001D94: .4byte 0x04000071
_08001D98: .4byte 0x04000078
_08001D9C: .4byte 0x04000079
_08001DA0:
	cmp r6, #0x03
	beq _08001DB8
	b _08001E04
_08001DA6:
	ldrb r0, [r4, #0x1F]
	ldr r1, [sp, #0x008]
	strb r0, [r1, #0x00]
_08001DAC:
	ldr r0, [r4, #0x24]
	lsls r0, r0, #0x06
	ldrb r2, [r4, #0x1E]
	adds r0, r2, r0
	strb r0, [r7, #0x00]
	b _08001E10
_08001DB8:
	ldr r1, [r4, #0x24]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	beq _08001DE0
	ldr r0, [sp, #0x008]
	strb r3, [r0, #0x00]
	ldr r1, _08001DF8 @ =0x04000090
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
_08001DE0:
	ldr r1, [sp, #0x008]
	strb r5, [r1, #0x00]
	ldrb r0, [r4, #0x1E]
	strb r0, [r7, #0x00]
	ldrb r0, [r4, #0x1E]
	cmp r0, #0x00
	beq _08001DFC
	movs r0, #0xC0
	strb r0, [r4, #0x1A]
	ldrb r1, [r4, #0x04]
	b _08001E26
	.byte 0x00, 0x00
_08001DF8: .4byte 0x04000090
_08001DFC:
	mov r2, r10
	strb r2, [r4, #0x1A]
	ldrb r1, [r4, #0x04]
	b _08001E26
_08001E04:
	ldrb r0, [r4, #0x1E]
	strb r0, [r7, #0x00]
	ldr r0, [r4, #0x24]
	lsls r0, r0, #0x03
	ldr r1, [sp, #0x010]
	strb r0, [r1, #0x00]
_08001E10:
	ldrb r1, [r4, #0x04]
	adds r0, r1, #0x0
	adds r0, #0x08
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x018]
	ldrb r0, [r4, #0x1E]
	cmp r0, #0x00
	beq _08001E24
	movs r0, #0x40
_08001E24:
	strb r0, [r4, #0x1A]
_08001E26:
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
	bne _08001E3E
	b _08001F72
_08001E3E:
	strb r2, [r4, #0x09]
	b _08001FA0
_08001E42:
	movs r0, #0x04
	ands r0, r2
	cmp r0, #0x00
	beq _08001E74
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
	ble _08001E66
	b _08001FB2
_08001E66:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl sub_08001BD0
	movs r0, #0x00
	strb r0, [r4, #0x00]
	b _080020AE
_08001E74:
	movs r0, #0x40
	ands r0, r1
	adds r2, r6, #0x1
	mov r9, r2
	movs r2, #0x40
	adds r2, r2, r4
	mov r8, r2
	cmp r0, #0x00
	beq _08001EB4
	movs r0, #0x03
	ands r0, r1
	cmp r0, #0x00
	beq _08001EB4
	movs r0, #0xFC
	ands r0, r1
	movs r2, #0x00
	strb r0, [r4, #0x00]
	ldrb r1, [r4, #0x07]
	strb r1, [r4, #0x0B]
	movs r0, #0xFF
	ands r0, r1
	cmp r0, #0x00
	beq _08001EE6
	movs r0, #0x01
	ldrb r1, [r4, #0x1D]
	orrs r0, r1
	strb r0, [r4, #0x1D]
	cmp r6, #0x03
	beq _08001FA0
	ldrb r2, [r4, #0x07]
	str r2, [sp, #0x018]
	b _08001FA0
_08001EB4:
	ldrb r0, [r4, #0x0B]
	cmp r0, #0x00
	bne _08001FA0
	cmp r6, #0x03
	bne _08001EC6
	movs r0, #0x01
	ldrb r1, [r4, #0x1D]
	orrs r0, r1
	strb r0, [r4, #0x1D]
_08001EC6:
	adds r0, r4, #0x0
	bl sub_08001C20
	movs r0, #0x03
	ldrb r2, [r4, #0x00]
	ands r0, r2
	cmp r0, #0x00
	bne _08001F12
	ldrb r0, [r4, #0x09]
	subs r0, #0x01
	strb r0, [r4, #0x09]
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bgt _08001F0E
_08001EE6:
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
	beq _08001E66
	movs r0, #0x04
	ldrb r2, [r4, #0x00]
	orrs r0, r2
	strb r0, [r4, #0x00]
	movs r0, #0x01
	ldrb r1, [r4, #0x1D]
	orrs r0, r1
	strb r0, [r4, #0x1D]
	b _08001FB2
_08001F0E:
	ldrb r0, [r4, #0x07]
	b _08001F9E
_08001F12:
	cmp r0, #0x01
	bne _08001F1E
_08001F16:
	ldrb r0, [r4, #0x19]
	strb r0, [r4, #0x09]
	movs r0, #0x07
	b _08001F9E
_08001F1E:
	cmp r0, #0x02
	bne _08001F62
	ldrb r0, [r4, #0x09]
	subs r0, #0x01
	strb r0, [r4, #0x09]
	movs r2, #0xFF
	ands r0, r2
	lsls r0, r0, #0x18
	ldrb r2, [r4, #0x19]
	lsls r1, r2, #0x18
	cmp r0, r1
	bgt _08001F5E
_08001F36:
	ldrb r0, [r4, #0x06]
	cmp r0, #0x00
	bne _08001F46
	movs r0, #0xFC
	ldrb r1, [r4, #0x00]
	ands r0, r1
	strb r0, [r4, #0x00]
	b _08001EE6
_08001F46:
	ldrb r0, [r4, #0x00]
	subs r0, #0x01
	strb r0, [r4, #0x00]
	movs r0, #0x01
	ldrb r2, [r4, #0x1D]
	orrs r0, r2
	strb r0, [r4, #0x1D]
	cmp r6, #0x03
	beq _08001F16
	movs r0, #0x08
	str r0, [sp, #0x018]
	b _08001F16
_08001F5E:
	ldrb r0, [r4, #0x05]
	b _08001F9E
_08001F62:
	ldrb r0, [r4, #0x09]
	adds r0, #0x01
	strb r0, [r4, #0x09]
	movs r1, #0xFF
	ands r0, r1
	ldrb r2, [r4, #0x0A]
	cmp r0, r2
	bcc _08001F9C
_08001F72:
	ldrb r0, [r4, #0x00]
	subs r0, #0x01
	movs r2, #0x00
	strb r0, [r4, #0x00]
	ldrb r1, [r4, #0x05]
	strb r1, [r4, #0x0B]
	movs r0, #0xFF
	ands r0, r1
	cmp r0, #0x00
	beq _08001F36
	movs r0, #0x01
	ldrb r1, [r4, #0x1D]
	orrs r0, r1
	strb r0, [r4, #0x1D]
	ldrb r0, [r4, #0x0A]
	strb r0, [r4, #0x09]
	cmp r6, #0x03
	beq _08001FA0
	ldrb r2, [r4, #0x05]
	str r2, [sp, #0x018]
	b _08001FA0
_08001F9C:
	ldrb r0, [r4, #0x04]
_08001F9E:
	strb r0, [r4, #0x0B]
_08001FA0:
	ldrb r0, [r4, #0x0B]
	subs r0, #0x01
	strb r0, [r4, #0x0B]
	ldr r0, [sp, #0x000]
	cmp r0, #0x00
	bne _08001FB2
	subs r0, #0x01
	str r0, [sp, #0x000]
	b _08001EB4
_08001FB2:
	movs r0, #0x02
	ldrb r1, [r4, #0x1D]
	ands r0, r1
	cmp r0, #0x00
	beq _0800202A
	cmp r6, #0x03
	bgt _08001FF2
	movs r0, #0x08
	ldrb r2, [r4, #0x01]
	ands r0, r2
	cmp r0, #0x00
	beq _08001FF2
	ldr r0, _08001FDC @ =0x04000089
	ldrb r0, [r0, #0x00]
	cmp r0, #0x3F
	bgt _08001FE4
	ldr r0, [r4, #0x20]
	adds r0, #0x02
	ldr r1, _08001FE0 @ =0x000007FC
	b _08001FEE
	.byte 0x00, 0x00
_08001FDC: .4byte 0x04000089
_08001FE0: .4byte 0x000007FC
_08001FE4:
	cmp r0, #0x7F
	bgt _08001FF2
	ldr r0, [r4, #0x20]
	adds r0, #0x01
	ldr r1, _08002000 @ =0x000007FE
_08001FEE:
	ands r0, r1
	str r0, [r4, #0x20]
_08001FF2:
	cmp r6, #0x04
	beq _08002004
	ldr r0, [r4, #0x20]
	ldr r1, [sp, #0x010]
	strb r0, [r1, #0x00]
	b _08002012
	.byte 0x00, 0x00
_08002000: .4byte 0x000007FE
_08002004:
	ldr r2, [sp, #0x010]
	ldrb r0, [r2, #0x00]
	movs r1, #0x08
	ands r1, r0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	strb r0, [r2, #0x00]
_08002012:
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
_0800202A:
	movs r0, #0x01
	ldrb r2, [r4, #0x1D]
	ands r0, r2
	cmp r0, #0x00
	beq _080020AE
	ldr r1, _08002074 @ =0x04000081
	ldrb r0, [r1, #0x00]
	ldrb r2, [r4, #0x1C]
	bics r0, r2
	ldrb r2, [r4, #0x1B]
	orrs r0, r2
	strb r0, [r1, #0x00]
	cmp r6, #0x03
	bne _0800207C
	ldr r0, _08002078 @ =0x0801D1EC
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
	beq _080020AE
	ldr r0, [sp, #0x008]
	strb r1, [r0, #0x00]
	ldrb r0, [r4, #0x1A]
	ldr r1, [sp, #0x014]
	strb r0, [r1, #0x00]
	movs r0, #0x7F
	ldrb r2, [r4, #0x1A]
	ands r0, r2
	strb r0, [r4, #0x1A]
	b _080020AE
	.byte 0x00, 0x00
_08002074: .4byte 0x04000081
_08002078: .4byte 0x0801D1EC
_0800207C:
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
	bne _080020AE
	ldr r0, [sp, #0x008]
	ldrb r1, [r0, #0x00]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080020AE
	ldrb r0, [r4, #0x1A]
	orrs r0, r2
	ldr r1, [sp, #0x014]
	strb r0, [r1, #0x00]
_080020AE:
	movs r0, #0x00
	strb r0, [r4, #0x1D]
_080020B2:
	mov r6, r9
	mov r4, r8
	cmp r6, #0x04
	bgt _080020BC
	b _08001CB8
_080020BC:
	add sp, #0x020
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start sub_080020CC
sub_080020CC:
	push {r4, lr}
	adds r2, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [r2, #0x34]
	ldr r0, _080020F0 @ =0x68736D53
	cmp r3, r0
	bne _080020E8
	strh r1, [r2, #0x1E]
	ldrh r4, [r2, #0x1C]
	adds r0, r1, #0x0
	muls r0, r4
	asrs r0, r0, #0x08
	strh r0, [r2, #0x20]
_080020E8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080020F0: .4byte 0x68736D53
	thumb_func_start sub_080020F4
sub_080020F4:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r6, r2, #0x10
	ldr r3, [r4, #0x34]
	ldr r0, _08002158 @ =0x68736D53
	cmp r3, r0
	bne _0800214C
	adds r0, r3, #0x1
	str r0, [r4, #0x34]
	ldrb r2, [r4, #0x08]
	ldr r1, [r4, #0x2C]
	movs r5, #0x01
	cmp r2, #0x00
	ble _08002148
	movs r0, #0x80
	mov r8, r0
	lsrs r6, r6, #0x12
	movs r0, #0x03
	mov r12, r0
_08002124:
	adds r0, r7, #0x0
	ands r0, r5
	cmp r0, #0x00
	beq _0800213E
	ldrb r3, [r1, #0x00]
	mov r0, r8
	ands r0, r3
	cmp r0, #0x00
	beq _0800213E
	strb r6, [r1, #0x13]
	mov r0, r12
	orrs r0, r3
	strb r0, [r1, #0x00]
_0800213E:
	subs r2, #0x01
	adds r1, #0x50
	lsls r5, r5, #0x01
	cmp r2, #0x00
	bgt _08002124
_08002148:
	ldr r0, _08002158 @ =0x68736D53
	str r0, [r4, #0x34]
_0800214C:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08002158: .4byte 0x68736D53
