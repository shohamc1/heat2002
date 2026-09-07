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
	.byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x07, 0x1C, 0xB8, 0x68
	.byte 0x81, 0x46, 0x4A, 0x46, 0x12, 0x05, 0x91, 0x46, 0x12, 0x15, 0x90, 0x46, 0xBA, 0x60, 0x1B, 0x48
	.byte 0x02, 0x68, 0x10, 0x1C, 0xD1, 0x17, 0x3C, 0x68, 0xA2, 0x46, 0x52, 0x46, 0xD3, 0x17, 0x7E, 0x68
	.byte 0x34, 0x1C, 0xF5, 0x17, 0x12, 0x1B, 0xAB, 0x41, 0x01, 0xF0, 0xF9, 0xFC, 0x01, 0xF0, 0x2F, 0xFD
	.byte 0x0D, 0x1C, 0x04, 0x1C, 0x29, 0x06, 0x20, 0x0A, 0x0C, 0x1C, 0x04, 0x43, 0x11, 0x48, 0x02, 0x68
	.byte 0x10, 0x1C, 0xD1, 0x17, 0x42, 0x46, 0x4E, 0x46, 0xF3, 0x17, 0x01, 0xF0, 0xE8, 0xFC, 0x01, 0xF0
	.byte 0x1E, 0xFD, 0x0B, 0x06, 0x02, 0x0A, 0x18, 0x1C, 0x10, 0x43, 0x24, 0x18, 0x64, 0x10, 0xA0, 0x44
	.byte 0x40, 0x46, 0x00, 0x05, 0x00, 0x15, 0x80, 0x46, 0xB8, 0x60, 0xC2, 0x44, 0x52, 0x46, 0x3A, 0x60
	.byte 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x04, 0x78
	.byte 0x02, 0x02, 0x00, 0x78, 0x02, 0x02, 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4
	.byte 0x07, 0x1C, 0xB8, 0x68, 0x81, 0x46, 0x4A, 0x46, 0x12, 0x05, 0x91, 0x46, 0x12, 0x15, 0x90, 0x46
	.byte 0xBA, 0x60, 0x1B, 0x48, 0x02, 0x68, 0x10, 0x1C, 0xD1, 0x17, 0x3C, 0x68, 0xA2, 0x46, 0x52, 0x46
	.byte 0xD3, 0x17, 0x7E, 0x68, 0x34, 0x1C, 0xF5, 0x17, 0x12, 0x1B, 0xAB, 0x41, 0x01, 0xF0, 0xAF, 0xFC
	.byte 0x01, 0xF0, 0xE5, 0xFC, 0x0D, 0x1C, 0x04, 0x1C, 0x29, 0x06, 0x20, 0x0A, 0x0C, 0x1C, 0x04, 0x43
	.byte 0x11, 0x48, 0x02, 0x68, 0x10, 0x1C, 0xD1, 0x17, 0x42, 0x46, 0x4E, 0x46, 0xF3, 0x17, 0x01, 0xF0
	.byte 0x9E, 0xFC, 0x01, 0xF0, 0xD4, 0xFC, 0x0B, 0x06, 0x02, 0x0A, 0x18, 0x1C, 0x10, 0x43, 0x24, 0x18
	.byte 0x64, 0x10, 0xA0, 0x44, 0x40, 0x46, 0x00, 0x05, 0x00, 0x15, 0x80, 0x46, 0xB8, 0x60, 0xC2, 0x44
	.byte 0x52, 0x46, 0x3A, 0x60, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x0C, 0x78, 0x02, 0x02, 0x08, 0x78, 0x02, 0x02, 0x70, 0xB5, 0x04, 0x1C, 0x0B, 0x1C
	.byte 0x0B, 0x4E, 0x9C, 0x20, 0x40, 0x00, 0x25, 0x18, 0x31, 0x68, 0x28, 0x68, 0x81, 0x42, 0x10, 0xD0
	.byte 0x18, 0x1C, 0x11, 0x1C, 0x00, 0xF0, 0x15, 0xF8, 0x9A, 0x22, 0x52, 0x00, 0xA1, 0x18, 0x00, 0x06
	.byte 0x00, 0x0E, 0x08, 0x60, 0x30, 0x68, 0x28, 0x60, 0x08, 0x78, 0x06, 0xE0, 0x00, 0x00, 0xAC, 0x90
	.byte 0x03, 0x02, 0x9A, 0x21, 0x49, 0x00, 0x60, 0x18, 0x00, 0x78, 0x70, 0xBC, 0x02, 0xBC, 0x08, 0x47
	.byte 0x00, 0x00
	thumb_func_start sub_08343464
sub_08343464:
	push {r4, r5, lr}
	subs r0, #0x01
	asrs r4, r0, #0x02
	subs r1, #0x01
	asrs r5, r1, #0x02
	movs r2, #0x03
	adds r3, r2, #0x0
	ands r3, r0
	ands r2, r1
	ldr r0, _083434A0 @ =0x02039220
	ldr r0, [r0, #0x00]
	muls r0, r5
	ldr r1, _083434A4 @ =0x02039264
	ldr r1, [r1, #0x00]
	lsls r4, r4, #0x01
	lsls r0, r0, #0x01
	adds r0, r0, r1
	adds r4, r4, r0
	lsls r2, r2, #0x02
	adds r3, r3, r2
	ldr r0, _083434A8 @ =0x0203929C
	ldr r1, [r0, #0x00]
	ldrh r4, [r4, #0x00]
	lsls r0, r4, #0x04
	adds r0, r0, r1
	adds r0, r0, r3
	ldrb r0, [r0, #0x00]
	pop {r4, r5}
	pop {r1}
	bx r1
	.global _083434A0
_083434A0: .4byte 0x02039220
	.global _083434A4
_083434A4: .4byte 0x02039264
	.global _083434A8
_083434A8: .4byte 0x0203929C
	.byte 0xC0, 0x20, 0x00, 0x01, 0x70, 0x47, 0x00, 0x00, 0xC0, 0x20, 0x00, 0x01, 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_083434BC
sub_083434BC:
	asrs r3, r0, #0x07
	asrs r1, r1, #0x07
	cmp r3, #0x30
	bgt _083434D0
	cmp r1, #0x30
	bgt _083434D0
	cmp r3, #0x00
	blt _083434D0
	cmp r1, #0x00
	bge _083434E0
	.global _083434D0
_083434D0:
	ldr r2, _083434D8 @ =0x0203DE8C
	ldr r0, _083434DC @ =0x0203DE88
	ldr r0, [r0, #0x00]
	b _083434F2
	.global _083434D8
_083434D8: .4byte 0x0203DE8C
	.global _083434DC
_083434DC: .4byte 0x0203DE88
	.global _083434E0
_083434E0:
	ldr r2, _083434FC @ =0x0203DE8C
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r0, r0, r3
	ldr r1, _08343500 @ =0x0203DE88
	ldr r1, [r1, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	.global _083434F2
_083434F2:
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	bx lr
	.global _083434FC
_083434FC: .4byte 0x0203DE8C
	.global _08343500
_08343500: .4byte 0x0203DE88
	thumb_func_start sub_08343504
sub_08343504:
	ldr r3, _08343544 @ =0x0203DE60
	ldr r2, _08343548 @ =0x0202AED4
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x02
	adds r0, r2, #0x4
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x00]
	ldr r3, _0834354C @ =0x0203DE64
	adds r0, r1, r2
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x00]
	ldr r3, _08343550 @ =0x0203DE68
	adds r0, r2, #0x0
	adds r0, #0x08
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x00]
	ldr r3, _08343554 @ =0x0203DE8C
	adds r0, r2, #0x0
	adds r0, #0x0C
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x00]
	ldr r3, _08343558 @ =0x0203DE88
	adds r2, #0x10
	adds r1, r1, r2
	ldr r0, [r1, #0x00]
	str r0, [r3, #0x00]
	bx lr
	.byte 0x00, 0x00
	.global _08343544
_08343544: .4byte 0x0203DE60
	.global _08343548
_08343548: .4byte 0x0202AED4
	.global _0834354C
_0834354C: .4byte 0x0203DE64
	.global _08343550
_08343550: .4byte 0x0203DE68
	.global _08343554
_08343554: .4byte 0x0203DE8C
	.global _08343558
_08343558: .4byte 0x0203DE88
	thumb_func_start sub_0834355C
sub_0834355C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x048
	str r0, [sp, #0x010]
	str r1, [sp, #0x014]
	str r2, [sp, #0x018]
	str r3, [sp, #0x01C]
	ldr r0, [sp, #0x068]
	str r0, [sp, #0x03C]
	ldr r0, _08343768 @ =0x0000FFFF
	ldr r1, [sp, #0x03C]
	ldrh r1, [r1, #0x00]
	cmp r1, r0
	bne _08343580
	b _08343758
	.global _08343580
_08343580:
	ldr r0, _0834376C @ =0x0203DE60
	ldr r2, [sp, #0x03C]
	ldrh r2, [r2, #0x00]
	lsls r1, r2, #0x05
	ldr r0, [r0, #0x00]
	adds r0, r0, r1
	mov r8, r0
	ldr r3, [sp, #0x014]
	ldr r1, [r3, #0x00]
	ldr r0, [r0, #0x10]
	ldr r4, [sp, #0x03C]
	adds r4, #0x02
	str r4, [sp, #0x040]
	cmp r1, r0
	ble _083435A0
	b _0834374A
	.global _083435A0
_083435A0:
	ldr r1, [r3, #0x08]
	mov r6, r8
	ldr r0, [r6, #0x18]
	cmp r1, r0
	ble _083435AC
	b _0834374A
	.global _083435AC
_083435AC:
	ldr r1, [r3, #0x04]
	ldr r0, [r6, #0x0C]
	cmp r1, r0
	bge _083435B6
	b _0834374A
	.global _083435B6
_083435B6:
	ldr r1, [r3, #0x0C]
	ldr r0, [r6, #0x14]
	cmp r1, r0
	bge _083435C0
	b _0834374A
	.global _083435C0
_083435C0:
	ldr r0, _08343770 @ =0x0203DE64
	ldr r1, [r0, #0x00]
	ldrh r2, [r6, #0x00]
	lsls r0, r2, #0x03
	adds r0, r0, r1
	ldr r3, [r0, #0x00]
	str r3, [sp, #0x020]
	ldr r0, [r0, #0x04]
	str r0, [sp, #0x024]
	ldrh r4, [r6, #0x02]
	lsls r0, r4, #0x03
	adds r0, r0, r1
	ldr r6, [r0, #0x00]
	str r6, [sp, #0x028]
	ldr r0, [r0, #0x04]
	str r0, [sp, #0x02C]
	ldr r0, [sp, #0x010]
	str r0, [sp, #0x030]
	ldr r1, [sp, #0x018]
	str r1, [sp, #0x034]
	movs r2, #0x00
	str r2, [sp, #0x038]
	.global _083435EC
_083435EC:
	mov r3, r8
	ldr r0, [r3, #0x10]
	adds r0, #0x01
	ldr r4, [sp, #0x034]
	ldr r1, [r4, #0x00]
	cmp r1, r0
	ble _083435FC
	b _08343732
	.global _083435FC
_083435FC:
	ldr r0, [r3, #0x18]
	adds r0, #0x01
	ldr r1, [r4, #0x08]
	cmp r1, r0
	ble _08343608
	b _08343732
	.global _08343608
_08343608:
	ldr r0, [r3, #0x0C]
	subs r0, #0x01
	ldr r1, [r4, #0x04]
	cmp r1, r0
	bge _08343614
	b _08343732
	.global _08343614
_08343614:
	ldr r0, [r3, #0x14]
	subs r0, #0x01
	ldr r1, [r4, #0x0C]
	cmp r1, r0
	bge _08343620
	b _08343732
	.global _08343620
_08343620:
	ldr r6, [sp, #0x030]
	ldr r0, [r6, #0x10]
	asrs r0, r0, #0x08
	ldr r1, [r3, #0x04]
	adds r2, r0, #0x0
	muls r2, r1
	ldr r0, [r6, #0x14]
	asrs r0, r0, #0x08
	ldr r1, [r3, #0x08]
	muls r0, r1
	adds r2, r2, r0
	cmp r2, #0x00
	bgt _08343732
	ldr r0, _08343774 @ =0x020375B0
	ldr r1, [sp, #0x020]
	str r1, [r0, #0x00]
	ldr r0, _08343778 @ =0x020375B4
	ldr r2, [sp, #0x024]
	str r2, [r0, #0x00]
	ldr r0, _0834377C @ =0x020375B8
	ldr r3, [sp, #0x028]
	str r3, [r0, #0x00]
	ldr r0, _08343780 @ =0x020375BC
	ldr r4, [sp, #0x02C]
	str r4, [r0, #0x00]
	ldr r0, _08343784 @ =0x020375A0
	movs r1, #0x02
	ldsh r6, [r6, r1]
	mov r12, r6
	str r6, [r0, #0x00]
	ldr r0, _08343788 @ =0x020375A4
	ldr r2, [sp, #0x030]
	movs r3, #0x06
	ldsh r5, [r2, r3]
	str r5, [r0, #0x00]
	ldr r0, _0834378C @ =0x020375A8
	movs r4, #0x0A
	ldsh r1, [r2, r4]
	str r1, [r0, #0x00]
	ldr r0, _08343790 @ =0x020375AC
	movs r6, #0x0E
	ldsh r2, [r2, r6]
	str r2, [r0, #0x00]
	ldr r3, _08343794 @ =0x020375C0
	mov r0, r12
	subs r0, r1, r0
	mov r10, r0
	ldr r1, [sp, #0x02C]
	ldr r6, [sp, #0x024]
	subs r4, r1, r6
	mov r1, r10
	muls r1, r4
	subs r2, r2, r5
	mov r9, r2
	ldr r0, [sp, #0x028]
	ldr r6, [sp, #0x020]
	subs r2, r0, r6
	mov r0, r9
	muls r0, r2
	subs r6, r1, r0
	str r6, [r3, #0x00]
	cmp r6, #0x00
	beq _08343732
	ldr r0, [sp, #0x024]
	subs r7, r5, r0
	adds r0, r7, #0x0
	muls r0, r2
	mov r1, r12
	ldr r2, [sp, #0x020]
	subs r5, r1, r2
	adds r1, r5, #0x0
	muls r1, r4
	subs r0, r0, r1
	lsls r0, r0, #0x08
	ldr r3, _08343798 @ =0x020375C8
	str r0, [r3, #0x00]
	adds r1, r6, #0x0
	bl sub_08344BB8
	adds r4, r0, #0x0
	ldr r0, _08343798 @ =0x020375C8
	str r4, [r0, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x01
	cmp r4, r2
	bhi _08343732
	mov r0, r10
	muls r0, r7
	mov r1, r9
	muls r1, r5
	subs r0, r0, r1
	lsls r0, r0, #0x08
	ldr r1, _0834379C @ =0x020375C4
	str r0, [r1, #0x00]
	adds r1, r6, #0x0
	str r2, [sp, #0x044]
	bl sub_08344BB8
	adds r1, r0, #0x0
	ldr r3, _0834379C @ =0x020375C4
	str r1, [r3, #0x00]
	ldr r2, [sp, #0x044]
	cmp r1, r2
	bhi _08343732
	ldr r6, [sp, #0x06C]
	ldr r0, [r6, #0x00]
	cmp r4, r0
	bge _08343732
	str r1, [r6, #0x00]
	mov r0, r8
	ldr r1, [r0, #0x04]
	lsls r0, r1, #0x06
	adds r0, r0, r1
	lsls r0, r0, #0x02
	asrs r0, r0, #0x08
	ldr r1, [sp, #0x01C]
	str r0, [r1, #0x04]
	mov r2, r8
	ldr r1, [r2, #0x08]
	lsls r0, r1, #0x06
	adds r0, r0, r1
	lsls r0, r0, #0x02
	asrs r0, r0, #0x08
	ldr r3, [sp, #0x01C]
	str r0, [r3, #0x08]
	ldrb r0, [r2, #0x1C]
	strb r0, [r3, #0x0D]
	ldrb r0, [r2, #0x1D]
	strb r0, [r3, #0x0E]
	ldrb r0, [r2, #0x1E]
	strb r0, [r3, #0x0F]
	ldr r4, [sp, #0x03C]
	ldrh r0, [r4, #0x00]
	str r0, [r3, #0x10]
	add r6, sp, #0x038
	ldrb r6, [r6, #0x00]
	strb r6, [r3, #0x0C]
	.global _08343732
_08343732:
	ldr r0, [sp, #0x038]
	adds r0, #0x01
	str r0, [sp, #0x038]
	ldr r1, [sp, #0x030]
	adds r1, #0x18
	str r1, [sp, #0x030]
	ldr r2, [sp, #0x034]
	adds r2, #0x10
	str r2, [sp, #0x034]
	cmp r0, #0x04
	beq _0834374A
	b _083435EC
	.global _0834374A
_0834374A:
	ldr r3, [sp, #0x040]
	str r3, [sp, #0x03C]
	ldr r0, _08343768 @ =0x0000FFFF
	ldrh r4, [r3, #0x00]
	cmp r4, r0
	beq _08343758
	b _08343580
	.global _08343758
_08343758:
	add sp, #0x048
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _08343768
_08343768: .4byte 0x0000FFFF
	.global _0834376C
_0834376C: .4byte 0x0203DE60
	.global _08343770
_08343770: .4byte 0x0203DE64
	.global _08343774
_08343774: .4byte 0x020375B0
	.global _08343778
_08343778: .4byte 0x020375B4
	.global _0834377C
_0834377C: .4byte 0x020375B8
	.global _08343780
_08343780: .4byte 0x020375BC
	.global _08343784
_08343784: .4byte 0x020375A0
	.global _08343788
_08343788: .4byte 0x020375A4
	.global _0834378C
_0834378C: .4byte 0x020375A8
	.global _08343790
_08343790: .4byte 0x020375AC
	.global _08343794
_08343794: .4byte 0x020375C0
	.global _08343798
_08343798: .4byte 0x020375C8
	.global _0834379C
_0834379C: .4byte 0x020375C4
	thumb_func_start sub_083437A0
sub_083437A0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x030
	str r0, [sp, #0x010]
	str r3, [sp, #0x014]
	str r2, [sp, #0x020]
	ldr r0, [sp, #0x050]
	str r0, [sp, #0x024]
	ldr r0, _083438E8 @ =0x0000FFFF
	ldr r1, [sp, #0x024]
	ldrh r1, [r1, #0x00]
	cmp r1, r0
	bne _083437C2
	b _08343930
	.global _083437C2
_083437C2:
	ldr r0, _083438EC @ =0x0203DE60
	ldr r2, [sp, #0x024]
	ldrh r2, [r2, #0x00]
	lsls r1, r2, #0x05
	ldr r0, [r0, #0x00]
	adds r0, r0, r1
	mov r8, r0
	ldr r0, _083438F0 @ =0x0203DE64
	ldr r1, [r0, #0x00]
	mov r3, r8
	ldrh r3, [r3, #0x00]
	lsls r0, r3, #0x03
	adds r0, r0, r1
	ldr r5, [r0, #0x00]
	str r5, [sp, #0x018]
	ldr r0, [r0, #0x04]
	mov r12, r0
	mov r2, r8
	ldrh r2, [r2, #0x02]
	lsls r0, r2, #0x03
	adds r0, r0, r1
	ldr r3, [r0, #0x00]
	str r3, [sp, #0x01C]
	ldr r5, [r0, #0x04]
	ldr r1, [sp, #0x010]
	ldr r0, [r1, #0x10]
	mov r2, r8
	ldr r2, [r2, #0x04]
	str r2, [sp, #0x028]
	adds r1, r0, #0x0
	muls r1, r2
	ldr r3, [sp, #0x010]
	ldr r2, [r3, #0x14]
	mov r3, r8
	ldr r0, [r3, #0x08]
	muls r0, r2
	adds r1, r1, r0
	cmp r1, #0x00
	ble _08343812
	b _08343920
	.global _08343812
_08343812:
	ldr r0, [sp, #0x020]
	ldr r1, [r0, #0x00]
	ldr r0, [r3, #0x10]
	cmp r1, r0
	ble _0834381E
	b _08343920
	.global _0834381E
_0834381E:
	ldr r2, [sp, #0x020]
	ldr r1, [r2, #0x08]
	ldr r0, [r3, #0x18]
	cmp r1, r0
	bgt _08343920
	ldr r1, [r2, #0x04]
	ldr r0, [r3, #0x0C]
	cmp r1, r0
	blt _08343920
	ldr r1, [r2, #0x0C]
	ldr r0, [r3, #0x14]
	cmp r1, r0
	blt _08343920
	ldr r0, _083438F4 @ =0x020375B0
	ldr r3, [sp, #0x018]
	str r3, [r0, #0x00]
	ldr r0, _083438F8 @ =0x020375B4
	mov r1, r12
	str r1, [r0, #0x00]
	ldr r0, _083438FC @ =0x020375B8
	ldr r2, [sp, #0x01C]
	str r2, [r0, #0x00]
	ldr r0, _08343900 @ =0x020375BC
	str r5, [r0, #0x00]
	ldr r0, _08343904 @ =0x020375A0
	ldr r3, [sp, #0x010]
	ldr r6, [r3, #0x00]
	str r6, [r0, #0x00]
	ldr r0, _08343908 @ =0x020375A4
	ldr r4, [r3, #0x04]
	str r4, [r0, #0x00]
	ldr r0, _0834390C @ =0x020375A8
	ldr r1, [r3, #0x08]
	str r1, [r0, #0x00]
	ldr r0, _08343910 @ =0x020375AC
	ldr r2, [r3, #0x0C]
	str r2, [r0, #0x00]
	ldr r3, _08343914 @ =0x020375C0
	subs r1, r1, r6
	mov r10, r1
	mov r0, r12
	subs r7, r5, r0
	mov r1, r10
	muls r1, r7
	subs r2, r2, r4
	mov r9, r2
	ldr r5, [sp, #0x01C]
	ldr r0, [sp, #0x018]
	subs r2, r5, r0
	mov r0, r9
	muls r0, r2
	subs r5, r1, r0
	str r5, [r3, #0x00]
	cmp r5, #0x00
	beq _08343920
	mov r1, r12
	subs r3, r4, r1
	adds r0, r3, #0x0
	muls r0, r2
	ldr r2, [sp, #0x018]
	subs r4, r6, r2
	adds r1, r4, #0x0
	muls r1, r7
	subs r0, r0, r1
	lsls r0, r0, #0x08
	ldr r1, _08343918 @ =0x020375C8
	str r0, [r1, #0x00]
	adds r1, r5, #0x0
	str r3, [sp, #0x02C]
	bl sub_08344BB8
	ldr r2, _08343918 @ =0x020375C8
	str r0, [r2, #0x00]
	movs r6, #0x80
	lsls r6, r6, #0x01
	ldr r3, [sp, #0x02C]
	cmp r0, r6
	bhi _08343920
	mov r0, r10
	muls r0, r3
	mov r1, r9
	muls r1, r4
	subs r0, r0, r1
	lsls r0, r0, #0x08
	ldr r3, _0834391C @ =0x020375C4
	str r0, [r3, #0x00]
	adds r1, r5, #0x0
	bl sub_08344BB8
	ldr r5, _0834391C @ =0x020375C4
	str r0, [r5, #0x00]
	cmp r0, r6
	bhi _08343920
	ldr r0, [sp, #0x028]
	ldr r1, [sp, #0x014]
	str r0, [r1, #0x04]
	mov r2, r8
	ldr r0, [r2, #0x08]
	str r0, [r1, #0x08]
	movs r0, #0x01
	b _08343932
	.global _083438E8
_083438E8: .4byte 0x0000FFFF
	.global _083438EC
_083438EC: .4byte 0x0203DE60
	.global _083438F0
_083438F0: .4byte 0x0203DE64
	.global _083438F4
_083438F4: .4byte 0x020375B0
	.global _083438F8
_083438F8: .4byte 0x020375B4
	.global _083438FC
_083438FC: .4byte 0x020375B8
	.global _08343900
_08343900: .4byte 0x020375BC
	.global _08343904
_08343904: .4byte 0x020375A0
	.global _08343908
_08343908: .4byte 0x020375A4
	.global _0834390C
_0834390C: .4byte 0x020375A8
	.global _08343910
_08343910: .4byte 0x020375AC
	.global _08343914
_08343914: .4byte 0x020375C0
	.global _08343918
_08343918: .4byte 0x020375C8
	.global _0834391C
_0834391C: .4byte 0x020375C4
	.global _08343920
_08343920:
	ldr r3, [sp, #0x024]
	adds r3, #0x02
	str r3, [sp, #0x024]
	ldr r0, _08343944 @ =0x0000FFFF
	ldrh r5, [r3, #0x00]
	cmp r5, r0
	beq _08343930
	b _083437C2
	.global _08343930
_08343930:
	movs r0, #0x00
	.global _08343932
_08343932:
	add sp, #0x030
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08343944
_08343944: .4byte 0x0000FFFF
	thumb_func_start sub_08343948
sub_08343948:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x048
	adds r7, r0, #0x0
	ldr r0, _083439CC @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x07
	beq _083439C6
	ldr r1, [r7, #0x00]
	asrs r4, r1, #0x10
	str r4, [sp, #0x004]
	ldr r2, [r7, #0x08]
	asrs r6, r2, #0x10
	str r6, [sp, #0x008]
	ldr r3, [r7, #0x28]
	adds r1, r1, r3
	asrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	ldr r0, [r7, #0x30]
	adds r2, r2, r0
	asrs r2, r2, #0x10
	str r2, [sp, #0x010]
	asrs r3, r3, #0x08
	str r3, [sp, #0x014]
	asrs r0, r0, #0x08
	str r0, [sp, #0x018]
	cmp r4, r1
	bge _08343984
	adds r1, r4, #0x0
	.global _08343984
_08343984:
	add r5, sp, #0x01C
	str r1, [sp, #0x01C]
	cmp r6, r2
	bge _0834398E
	adds r2, r6, #0x0
	.global _0834398E
_0834398E:
	str r2, [r5, #0x08]
	ldr r1, [sp, #0x004]
	ldr r0, [sp, #0x00C]
	cmp r1, r0
	ble _0834399A
	adds r0, r1, #0x0
	.global _0834399A
_0834399A:
	str r0, [r5, #0x04]
	ldr r1, [sp, #0x008]
	ldr r0, [sp, #0x010]
	cmp r1, r0
	ble _083439A6
	adds r0, r1, #0x0
	.global _083439A6
_083439A6:
	str r0, [r5, #0x0C]
	ldr r0, [sp, #0x004]
	ldr r1, [sp, #0x008]
	bl sub_083434BC
	add r4, sp, #0x02C
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r5, #0x0
	adds r2, r5, #0x0
	adds r3, r4, #0x0
	bl sub_083437A0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _083439D0
	.global _083439C6
_083439C6:
	movs r0, #0x00
	b _08343A5E
	.byte 0x00, 0x00
	.global _083439CC
_083439CC: .4byte 0x0203916C
	.global _083439D0
_083439D0:
	ldr r0, [sp, #0x014]
	ldr r2, [r4, #0x04]
	adds r1, r0, #0x0
	muls r1, r2
	mov r8, r1
	ldr r0, [sp, #0x018]
	ldr r6, [r4, #0x08]
	muls r0, r6
	add r8, r0
	adds r0, r2, #0x0
	asrs r1, r2, #0x1F
	mov r4, r8
	asrs r5, r4, #0x1F
	adds r3, r5, #0x0
	adds r2, r4, #0x0
	bl sub_08344D20
	lsls r3, r1, #0x0B
	lsrs r2, r0, #0x15
	orrs r3, r2
	str r3, [sp, #0x040]
	asrs r0, r1, #0x15
	str r0, [sp, #0x044]
	adds r0, r6, #0x0
	asrs r1, r6, #0x1F
	adds r3, r5, #0x0
	adds r2, r4, #0x0
	bl sub_08344D20
	lsls r3, r1, #0x0B
	lsrs r2, r0, #0x15
	adds r4, r3, #0x0
	orrs r4, r2
	asrs r5, r1, #0x15
	ldr r2, [sp, #0x040]
	lsrs r3, r2, #0x1F
	ldr r0, [sp, #0x044]
	lsls r2, r0, #0x01
	adds r1, r3, #0x0
	orrs r1, r2
	ldr r2, [sp, #0x040]
	lsls r0, r2, #0x01
	ldr r2, [sp, #0x040]
	ldr r3, [sp, #0x044]
	adds r0, r0, r2
	adcs r1, r3
	lsls r3, r1, #0x1E
	lsrs r2, r0, #0x02
	orrs r3, r2
	str r3, [sp, #0x040]
	asrs r0, r1, #0x02
	str r0, [sp, #0x044]
	lsrs r3, r4, #0x1F
	lsls r2, r5, #0x01
	adds r1, r3, #0x0
	orrs r1, r2
	lsls r0, r4, #0x01
	adds r0, r0, r4
	adcs r1, r5
	lsls r3, r1, #0x1E
	lsrs r2, r0, #0x02
	adds r4, r3, #0x0
	orrs r4, r2
	ldr r0, [r7, #0x28]
	ldr r3, [sp, #0x040]
	subs r0, r0, r3
	str r0, [r7, #0x28]
	ldr r0, [r7, #0x30]
	subs r0, r0, r4
	str r0, [r7, #0x30]
	mov r0, r8
	.global _08343A5E
_08343A5E:
	add sp, #0x048
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_08343A6C
sub_08343A6C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x118
	mov r10, r0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _08343A84
	b _08343DCC
	.global _08343A84
_08343A84:
	movs r0, #0x00
	mov r12, r0
	mov r1, r10
	adds r1, #0xA4
	str r1, [sp, #0x114]
	mov r2, sp
	adds r2, #0x0C
	str r2, [sp, #0x0D8]
	mov r3, r10
	adds r3, #0xB4
	str r3, [sp, #0x0E4]
	mov r6, sp
	adds r6, #0x10
	str r6, [sp, #0x0DC]
	mov r7, r10
	adds r7, #0xC4
	str r7, [sp, #0x0F4]
	mov r0, sp
	adds r0, #0x14
	str r0, [sp, #0x0E0]
	adds r1, #0x30
	str r1, [sp, #0x0F8]
	adds r2, #0x0C
	str r2, [sp, #0x0E8]
	mov r3, sp
	adds r3, #0x1C
	str r3, [sp, #0x0F0]
	adds r6, #0x58
	str r6, [sp, #0x0FC]
	mov r7, sp
	adds r7, #0x70
	str r7, [sp, #0x104]
	adds r0, #0x58
	str r0, [sp, #0x100]
	mov r1, sp
	adds r1, #0x74
	str r1, [sp, #0x108]
	adds r2, #0x90
	str r2, [sp, #0x10C]
	adds r3, #0xB0
	str r3, [sp, #0x0EC]
	adds r6, #0x50
	str r6, [sp, #0x110]
	add r7, sp, #0x008
	mov r8, r7
	movs r0, #0x00
	mov r9, r0
	.global _08343AE2
_08343AE2:
	mov r2, r12
	lsls r1, r2, #0x02
	ldr r3, [sp, #0x114]
	adds r0, r3, r1
	ldr r4, [r0, #0x00]
	mov r6, r8
	str r4, [r6, #0x00]
	ldr r7, [sp, #0x0D8]
	add r7, r9
	ldr r2, [sp, #0x0E4]
	adds r0, r2, r1
	ldr r3, [r0, #0x00]
	str r3, [r7, #0x00]
	ldr r5, [sp, #0x0DC]
	add r5, r9
	ldr r6, [sp, #0x0F4]
	adds r0, r6, r1
	ldr r2, [r0, #0x00]
	str r2, [r5, #0x00]
	ldr r6, [sp, #0x0E0]
	add r6, r9
	ldr r0, [sp, #0x0F8]
	adds r1, r0, r1
	ldr r0, [r1, #0x00]
	str r0, [r6, #0x00]
	ldr r1, [sp, #0x0E8]
	add r1, r9
	subs r2, r2, r4
	str r2, [r1, #0x00]
	ldr r1, [sp, #0x0F0]
	add r1, r9
	subs r0, r0, r3
	str r0, [r1, #0x00]
	mov r2, r8
	ldr r1, [r2, #0x00]
	ldr r0, [r5, #0x00]
	cmp r1, r0
	bge _08343B30
	adds r0, r1, #0x0
	.global _08343B30
_08343B30:
	mov r3, r12
	lsls r2, r3, #0x04
	ldr r3, [sp, #0x0FC]
	adds r1, r3, r2
	asrs r0, r0, #0x10
	str r0, [r1, #0x00]
	ldr r1, [r7, #0x00]
	ldr r0, [r6, #0x00]
	cmp r1, r0
	bge _08343B46
	adds r0, r1, #0x0
	.global _08343B46
_08343B46:
	ldr r3, [sp, #0x104]
	adds r1, r3, r2
	asrs r0, r0, #0x10
	str r0, [r1, #0x00]
	mov r0, r8
	ldr r1, [r0, #0x00]
	ldr r0, [r5, #0x00]
	cmp r1, r0
	ble _08343B5A
	adds r0, r1, #0x0
	.global _08343B5A
_08343B5A:
	ldr r3, [sp, #0x100]
	adds r1, r3, r2
	asrs r0, r0, #0x10
	str r0, [r1, #0x00]
	ldr r1, [r7, #0x00]
	ldr r0, [r6, #0x00]
	cmp r1, r0
	ble _08343B6C
	adds r0, r1, #0x0
	.global _08343B6C
_08343B6C:
	ldr r6, [sp, #0x108]
	adds r1, r6, r2
	asrs r0, r0, #0x10
	str r0, [r1, #0x00]
	movs r7, #0x18
	add r8, r7
	movs r0, #0x18
	add r9, r0
	movs r1, #0x01
	add r12, r1
	mov r2, r12
	cmp r2, #0x04
	bne _08343AE2
	ldr r6, [sp, #0x0FC]
	ldr r1, [sp, #0x068]
	ldr r0, [r6, #0x10]
	cmp r1, r0
	bge _08343B92
	adds r0, r1, #0x0
	.global _08343B92
_08343B92:
	ldr r7, [sp, #0x10C]
	str r0, [r7, #0x00]
	ldr r1, [r6, #0x20]
	cmp r0, r1
	bge _08343B9E
	adds r1, r0, #0x0
	.global _08343B9E
_08343B9E:
	str r1, [r7, #0x00]
	ldr r0, [r6, #0x30]
	cmp r1, r0
	bge _08343BA8
	adds r0, r1, #0x0
	.global _08343BA8
_08343BA8:
	str r0, [r7, #0x00]
	ldr r1, [r6, #0x08]
	ldr r0, [r6, #0x18]
	cmp r1, r0
	bge _08343BB4
	adds r0, r1, #0x0
	.global _08343BB4
_08343BB4:
	str r0, [r7, #0x08]
	ldr r1, [r6, #0x28]
	cmp r0, r1
	bge _08343BBE
	adds r1, r0, #0x0
	.global _08343BBE
_08343BBE:
	str r1, [r7, #0x08]
	ldr r0, [r6, #0x38]
	cmp r1, r0
	bge _08343BC8
	adds r0, r1, #0x0
	.global _08343BC8
_08343BC8:
	str r0, [r7, #0x08]
	ldr r1, [r6, #0x04]
	ldr r0, [r6, #0x14]
	cmp r1, r0
	ble _08343BD4
	adds r0, r1, #0x0
	.global _08343BD4
_08343BD4:
	str r0, [r7, #0x04]
	ldr r1, [r6, #0x24]
	cmp r0, r1
	ble _08343BDE
	adds r1, r0, #0x0
	.global _08343BDE
_08343BDE:
	str r1, [r7, #0x04]
	ldr r0, [r6, #0x34]
	cmp r1, r0
	ble _08343BE8
	adds r0, r1, #0x0
	.global _08343BE8
_08343BE8:
	str r0, [r7, #0x04]
	ldr r1, [r6, #0x0C]
	ldr r0, [r6, #0x1C]
	cmp r1, r0
	ble _08343BF4
	adds r0, r1, #0x0
	.global _08343BF4
_08343BF4:
	str r0, [r7, #0x0C]
	ldr r1, [r6, #0x2C]
	cmp r0, r1
	ble _08343BFE
	adds r1, r0, #0x0
	.global _08343BFE
_08343BFE:
	str r1, [r7, #0x0C]
	ldr r0, [r6, #0x3C]
	cmp r1, r0
	ble _08343C08
	adds r0, r1, #0x0
	.global _08343C08
_08343C08:
	str r0, [r7, #0x0C]
	ldr r0, [sp, #0x008]
	asrs r0, r0, #0x10
	ldr r1, [sp, #0x00C]
	asrs r1, r1, #0x10
	bl sub_083434BC
	ldr r5, _08343DAC @ =0x0001869F
	ldr r3, [sp, #0x0EC]
	str r5, [r3, #0x00]
	str r0, [sp, #0x000]
	add r4, sp, #0x0CC
	str r4, [sp, #0x004]
	add r0, sp, #0x008
	adds r1, r7, #0x0
	adds r2, r6, #0x0
	ldr r3, [sp, #0x110]
	bl sub_0834355C
	ldr r0, [r4, #0x00]
	cmp r0, r5
	bne _08343C36
	b _08343DCC
	.global _08343C36
_08343C36:
	ldr r6, [sp, #0x110]
	ldrb r6, [r6, #0x0C]
	lsls r4, r6, #0x01
	ldr r7, [sp, #0x110]
	ldrb r7, [r7, #0x0C]
	adds r4, r4, r7
	lsls r4, r4, #0x03
	ldr r1, [sp, #0x0E8]
	adds r0, r1, r4
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	asrs r1, r2, #0x1F
	ldr r2, [sp, #0x110]
	ldr r5, [r2, #0x04]
	adds r2, r5, #0x0
	asrs r3, r5, #0x1F
	bl sub_08344D20
	str r0, [sp, #0x0D0]
	str r1, [sp, #0x0D4]
	ldr r3, [sp, #0x0F0]
	adds r4, r3, r4
	ldr r2, [r4, #0x00]
	adds r0, r2, #0x0
	asrs r1, r2, #0x1F
	ldr r6, [sp, #0x110]
	ldr r4, [r6, #0x08]
	adds r2, r4, #0x0
	asrs r3, r4, #0x1F
	bl sub_08344D20
	ldr r2, [sp, #0x0D0]
	ldr r3, [sp, #0x0D4]
	adds r2, r2, r0
	adcs r3, r1
	str r2, [sp, #0x0D0]
	str r3, [sp, #0x0D4]
	lsrs r3, r2, #0x1F
	ldr r6, [sp, #0x0D4]
	lsls r2, r6, #0x01
	adds r1, r3, #0x0
	orrs r1, r2
	ldr r7, [sp, #0x0D0]
	lsls r0, r7, #0x01
	ldr r2, [sp, #0x0D0]
	ldr r3, [sp, #0x0D4]
	adds r0, r0, r2
	adcs r1, r3
	lsrs r5, r0, #0x1A
	lsls r4, r1, #0x06
	adds r3, r5, #0x0
	orrs r3, r4
	lsls r2, r0, #0x06
	lsls r1, r3, #0x18
	lsrs r0, r2, #0x08
	orrs r1, r0
	str r1, [sp, #0x0D0]
	asrs r2, r3, #0x08
	str r2, [sp, #0x0D4]
	movs r0, #0x01
	negs r0, r0
	cmp r2, r0
	bgt _08343CC2
	cmp r2, r0
	bne _08343CCA
	movs r0, #0x80
	lsls r0, r0, #0x18
	adds r3, r1, #0x0
	cmp r3, r0
	bls _08343CCA
	.global _08343CC2
_08343CC2:
	ldr r6, _08343DB0 @ =0x80000000
	ldr r7, _08343DB4 @ =0xFFFFFFFF
	str r6, [sp, #0x0D0]
	str r7, [sp, #0x0D4]
	.global _08343CCA
_08343CCA:
	ldr r7, [sp, #0x110]
	ldr r7, [r7, #0x04]
	mov r9, r7
	mov r0, r9
	asrs r1, r0, #0x1F
	ldr r2, [sp, #0x0D0]
	ldr r3, [sp, #0x0D4]
	bl sub_08344D20
	adds r5, r1, #0x0
	adds r4, r0, #0x0
	lsls r1, r5, #0x03
	lsrs r0, r4, #0x1D
	adds r4, r1, #0x0
	orrs r4, r0
	ldr r0, [sp, #0x110]
	ldr r0, [r0, #0x08]
	mov r8, r0
	asrs r1, r0, #0x1F
	ldr r2, [sp, #0x0D0]
	ldr r3, [sp, #0x0D4]
	bl sub_08344D20
	lsls r3, r1, #0x03
	lsrs r2, r0, #0x1D
	adds r0, r3, #0x0
	orrs r0, r2
	ldr r2, _08343DB8 @ =0x0203DE90
	mov r3, r10
	ldr r6, [r3, #0x0C]
	str r6, [r2, #0x00]
	ldr r2, _08343DBC @ =0x0203DE84
	ldr r3, [r3, #0x14]
	str r3, [r2, #0x00]
	ldr r2, _08343DC0 @ =0x0203DE6C
	ldr r7, [sp, #0x0D0]
	str r7, [r2, #0x00]
	ldr r2, _08343DC4 @ =0x0203DE70
	mov r7, r9
	str r7, [r2, #0x04]
	mov r7, r8
	str r7, [r2, #0x08]
	subs r6, r6, r4
	mov r2, r10
	str r6, [r2, #0x0C]
	subs r3, r3, r0
	str r3, [r2, #0x14]
	ldr r3, [sp, #0x110]
	ldrb r3, [r3, #0x0C]
	lsls r1, r3, #0x02
	ldr r6, [sp, #0x114]
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	ldr r7, [sp, #0x0E4]
	adds r1, r7, r1
	ldr r1, [r1, #0x00]
	bl sub_08342DE4
	ldr r2, _08343DC8 @ =0x0200C3E8
	ldr r0, [sp, #0x110]
	ldrb r3, [r0, #0x0D]
	lsls r0, r3, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r5, [r0, r1]
	adds r0, r3, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r6, #0x00
	ldsh r4, [r0, r6]
	mov r7, r10
	ldrh r7, [r7, #0x34]
	lsrs r1, r7, #0x08
	lsls r0, r1, #0x01
	adds r0, r0, r2
	movs r6, #0x00
	ldsh r0, [r0, r6]
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r2
	movs r7, #0x00
	ldsh r1, [r1, r7]
	muls r0, r5
	muls r1, r4
	adds r0, r0, r1
	cmp r0, #0x00
	bgt _08343D7E
	ldr r0, [sp, #0x110]
	ldrb r3, [r0, #0x0E]
	.global _08343D7E
_08343D7E:
	movs r1, #0x96
	lsls r1, r1, #0x01
	add r1, r10
	lsls r0, r3, #0x08
	str r0, [r1, #0x00]
	mov r1, r10
	ldrh r1, [r1, #0x34]
	subs r0, r0, r1
	lsls r3, r0, #0x10
	asrs r3, r3, #0x14
	mov r2, r10
	ldrh r2, [r2, #0x3C]
	adds r0, r2, r3
	mov r3, r10
	strh r0, [r3, #0x3C]
	ldr r6, [sp, #0x0D4]
	lsls r3, r6, #0x19
	ldr r7, [sp, #0x0D0]
	lsrs r2, r7, #0x07
	adds r0, r3, #0x0
	orrs r0, r2
	b _08343DCE
	.byte 0x00, 0x00
	.global _08343DAC
_08343DAC: .4byte 0x0001869F
	.global _08343DB0
_08343DB0: .4byte 0x80000000
	.global _08343DB4
_08343DB4: .4byte 0xFFFFFFFF
	.global _08343DB8
_08343DB8: .4byte 0x0203DE90
	.global _08343DBC
_08343DBC: .4byte 0x0203DE84
	.global _08343DC0
_08343DC0: .4byte 0x0203DE6C
	.global _08343DC4
_08343DC4: .4byte 0x0203DE70
	.global _08343DC8
_08343DC8: .4byte 0x0200C3E8
	.global _08343DCC
_08343DCC:
	movs r0, #0x00
	.global _08343DCE
_08343DCE:
	add sp, #0x118
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x02, 0x1C, 0x08, 0x1C, 0x82, 0x42, 0x00, 0xDA, 0x10, 0x1C, 0x70, 0x47, 0x02, 0x1C
	.byte 0x08, 0x1C, 0x82, 0x42, 0x00, 0xDD, 0x10, 0x1C, 0x70, 0x47
	thumb_func_start sub_08343DF8
sub_08343DF8:
	push {r4, r5, r6, r7, lr}
	ldrh r3, [r0, #0x34]
	lsrs r2, r3, #0x08
	negs r7, r2
	movs r5, #0xFF
	mov r12, r5
	ands r7, r5
	ldr r5, _08343E6C @ =0x0200C3E8
	lsls r2, r7, #0x01
	adds r2, r2, r5
	movs r6, #0x00
	ldsh r2, [r2, r6]
	str r2, [r1, #0x00]
	adds r2, r7, #0x0
	adds r2, #0x40
	lsls r2, r2, #0x01
	adds r2, r2, r5
	movs r3, #0x00
	ldsh r2, [r2, r3]
	str r2, [r1, #0x04]
	ldr r3, [r0, #0x00]
	asrs r2, r3, #0x08
	str r2, [r1, #0x10]
	ldr r4, [r0, #0x08]
	asrs r2, r4, #0x08
	str r2, [r1, #0x14]
	movs r6, #0x3C
	ldsh r2, [r0, r6]
	ldrh r6, [r0, #0x34]
	adds r7, r6, r2
	asrs r2, r7, #0x08
	negs r7, r2
	mov r2, r12
	ands r7, r2
	lsls r2, r7, #0x01
	adds r2, r2, r5
	movs r6, #0x00
	ldsh r2, [r2, r6]
	str r2, [r1, #0x08]
	adds r2, r7, #0x0
	adds r2, #0x40
	lsls r2, r2, #0x01
	adds r2, r2, r5
	movs r5, #0x00
	ldsh r2, [r2, r5]
	str r2, [r1, #0x0C]
	ldr r2, [r0, #0x0C]
	adds r3, r3, r2
	asrs r3, r3, #0x08
	str r3, [r1, #0x18]
	ldr r0, [r0, #0x14]
	adds r4, r4, r0
	asrs r4, r4, #0x08
	str r4, [r1, #0x1C]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08343E6C
_08343E6C: .4byte 0x0200C3E8
	thumb_func_start sub_08343E70
sub_08343E70:
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	adds r4, r2, #0x0
	ldr r2, [sp, #0x014]
	ldr r7, [sp, #0x020]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r5, _08343EA4 @ =0x0203DF44
	ldr r0, [r5, #0x00]
	cmp r7, r0
	bge _08343E9E
	str r6, [r2, #0x00]
	str r4, [r2, #0x04]
	strb r1, [r2, #0x08]
	strb r3, [r2, #0x09]
	ldr r0, [sp, #0x01C]
	str r0, [r2, #0x0C]
	movs r1, #0x01
	ldr r0, [sp, #0x018]
	strb r1, [r0, #0x00]
	str r7, [r5, #0x00]
	.global _08343E9E
_08343E9E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08343EA4
_08343EA4: .4byte 0x0203DF44
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
