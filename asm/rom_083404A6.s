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
	.byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x00, 0x23, 0x0F, 0x48, 0x84, 0x46, 0x0F, 0x48
	.byte 0x80, 0x46, 0x0F, 0x4F, 0x10, 0x4E, 0x65, 0x46, 0x10, 0x4C, 0x59, 0x00, 0xCA, 0x19, 0x88, 0x19
	.byte 0x00, 0x88, 0x10, 0x80, 0x4A, 0x19, 0x09, 0x19, 0x08, 0x88, 0x10, 0x80, 0x58, 0x1C, 0x00, 0x06
	.byte 0x03, 0x0E, 0x05, 0x2B, 0xF1, 0xD1, 0x60, 0x46, 0x41, 0x46, 0xFF, 0xF7, 0xCC, 0xFF, 0x08, 0xBC
	.byte 0x98, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x40, 0xDD, 0x03, 0x02, 0x20, 0xDD
	.byte 0x03, 0x02, 0x10, 0xD5, 0x03, 0x02, 0xC6, 0x70, 0x02, 0x02, 0xD0, 0x70, 0x02, 0x02, 0x02, 0x1C
	.byte 0x06, 0x48, 0x00, 0x78, 0x11, 0x1C, 0xE4, 0x31, 0x05, 0x48, 0x08, 0x60, 0x04, 0x31, 0x04, 0x48
	.byte 0x08, 0x60, 0x04, 0x31, 0x04, 0x48, 0x08, 0x60, 0x70, 0x47, 0x6C, 0x91, 0x03, 0x02, 0x3E, 0x71
	.byte 0x02, 0x02, 0x4A, 0x71, 0x02, 0x02, 0x54, 0x71, 0x02, 0x02
	thumb_func_start sub_08340530
sub_08340530:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _0834055C @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08340578
	ldr r1, _08340560 @ =0x0203DCF4
	ldr r2, _08340564 @ =0x02026E20
	ldr r0, [r2, #0x00]
	strb r0, [r1, #0x00]
	ldr r1, _08340568 @ =0x0203D4E0
	ldr r0, [r2, #0x04]
	strb r0, [r1, #0x00]
	ldr r1, _0834056C @ =0x0203DDE4
	ldr r0, [r2, #0x08]
	strb r0, [r1, #0x00]
	ldr r1, _08340570 @ =0x0203DDFC
	ldr r0, [r2, #0x0C]
	strb r0, [r1, #0x00]
	ldr r1, _08340574 @ =0x0203D4DC
	ldr r0, [r2, #0x10]
	b _083405CE
	.global _0834055C
_0834055C: .4byte 0x020390EC
	.global _08340560
_08340560: .4byte 0x0203DCF4
	.global _08340564
_08340564: .4byte 0x02026E20
	.global _08340568
_08340568: .4byte 0x0203D4E0
	.global _0834056C
_0834056C: .4byte 0x0203DDE4
	.global _08340570
_08340570: .4byte 0x0203DDFC
	.global _08340574
_08340574: .4byte 0x0203D4DC
	.global _08340578
_08340578:
	cmp r1, #0x00
	bne _083405B4
	ldr r1, _0834059C @ =0x0203DCF4
	ldr r2, _083405A0 @ =0x02026E20
	ldr r0, [r2, #0x00]
	strb r0, [r1, #0x00]
	ldr r1, _083405A4 @ =0x0203D4E0
	ldr r0, [r2, #0x04]
	strb r0, [r1, #0x00]
	ldr r1, _083405A8 @ =0x0203DDE4
	ldr r0, [r2, #0x08]
	strb r0, [r1, #0x00]
	ldr r1, _083405AC @ =0x0203DDFC
	ldr r0, [r2, #0x0C]
	strb r0, [r1, #0x00]
	ldr r1, _083405B0 @ =0x0203D4DC
	ldr r0, [r2, #0x10]
	b _083405CE
	.global _0834059C
_0834059C: .4byte 0x0203DCF4
	.global _083405A0
_083405A0: .4byte 0x02026E20
	.global _083405A4
_083405A4: .4byte 0x0203D4E0
	.global _083405A8
_083405A8: .4byte 0x0203DDE4
	.global _083405AC
_083405AC: .4byte 0x0203DDFC
	.global _083405B0
_083405B0: .4byte 0x0203D4DC
	.global _083405B4
_083405B4:
	ldr r1, _083405D4 @ =0x0203DCF4
	movs r0, #0xA0
	strb r0, [r1, #0x00]
	ldr r1, _083405D8 @ =0x0203D4E0
	movs r0, #0xFF
	strb r0, [r1, #0x00]
	ldr r0, _083405DC @ =0x0203DDE4
	movs r1, #0x80
	strb r1, [r0, #0x00]
	ldr r0, _083405E0 @ =0x0203DDFC
	strb r1, [r0, #0x00]
	ldr r1, _083405E4 @ =0x0203D4DC
	ldr r0, _083405E8 @ =0x0000B060
	.global _083405CE
_083405CE:
	str r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
	.global _083405D4
_083405D4: .4byte 0x0203DCF4
	.global _083405D8
_083405D8: .4byte 0x0203D4E0
	.global _083405DC
_083405DC: .4byte 0x0203DDE4
	.global _083405E0
_083405E0: .4byte 0x0203DDFC
	.global _083405E4
_083405E4: .4byte 0x0203D4DC
	.global _083405E8
_083405E8: .4byte 0x0000B060
	.byte 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_083405F0
sub_083405F0:
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r0, _0834064C @ =0x0203DD38
	strb r6, [r0, #0x00]
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_08340530
	ldr r0, _08340650 @ =0x0203D520
	cmp r5, r0
	bne _08340664
	adds r0, r5, #0x0
	adds r0, #0x8C
	ldr r0, [r0, #0x00]
	movs r1, #0xFA
	lsls r1, r1, #0x0B
	cmp r0, r1
	bgt _08340636
	adds r0, r5, #0x0
	adds r0, #0x90
	ldr r0, [r0, #0x00]
	cmp r0, r1
	bgt _08340636
	adds r0, r5, #0x0
	adds r0, #0x94
	ldr r0, [r0, #0x00]
	cmp r0, r1
	bgt _08340636
	adds r0, r5, #0x0
	adds r0, #0x98
	ldr r0, [r0, #0x00]
	cmp r0, r1
	ble _08340664
	.global _08340636
_08340636:
	ldr r1, _08340654 @ =0x0203DD4C
	movs r0, #0x40
	str r0, [r1, #0x00]
	ldr r2, _08340658 @ =0x0203DD0C
	movs r0, #0x80
	str r0, [r2, #0x00]
	ldr r1, _0834065C @ =0x0203D4E4
	ldr r0, _08340660 @ =0x00011F40
	str r0, [r1, #0x00]
	mov r12, r2
	b _083406EA
	.global _0834064C
_0834064C: .4byte 0x0203DD38
	.global _08340650
_08340650: .4byte 0x0203D520
	.global _08340654
_08340654: .4byte 0x0203DD4C
	.global _08340658
_08340658: .4byte 0x0203DD0C
	.global _0834065C
_0834065C: .4byte 0x0203D4E4
	.global _08340660
_08340660: .4byte 0x00011F40
	.global _08340664
_08340664:
	ldr r0, [r5, #0x2C]
	negs r0, r0
	asrs r4, r0, #0x0C
	cmp r4, #0x00
	bge _08340670
	movs r4, #0x00
	.global _08340670
_08340670:
	cmp r6, #0x00
	beq _083406B4
	ldr r0, _08340698 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _083406B4
	ldr r1, _0834069C @ =0x0203DD4C
	ldr r0, _083406A0 @ =0x0203D4E0
	ldrb r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r2, _083406A4 @ =0x0203DD0C
	ldr r0, _083406A8 @ =0x0203DDFC
	ldrb r0, [r0, #0x00]
	str r0, [r2, #0x00]
	ldr r1, _083406AC @ =0x0203D4E4
	ldr r0, _083406B0 @ =0x0203D4DC
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	mov r12, r2
	b _083406EA
	.global _08340698
_08340698: .4byte 0x020390EC
	.global _0834069C
_0834069C: .4byte 0x0203DD4C
	.global _083406A0
_083406A0: .4byte 0x0203D4E0
	.global _083406A4
_083406A4: .4byte 0x0203DD0C
	.global _083406A8
_083406A8: .4byte 0x0203DDFC
	.global _083406AC
_083406AC: .4byte 0x0203D4E4
	.global _083406B0
_083406B0: .4byte 0x0203D4DC
	.global _083406B4
_083406B4:
	ldr r3, _08340794 @ =0x0203DD4C
	ldr r0, _08340798 @ =0x0203DCF4
	movs r2, #0xFF
	subs r2, r2, r4
	ldrb r0, [r0, #0x00]
	muls r0, r2
	ldr r1, _0834079C @ =0x0203D4E0
	ldrb r1, [r1, #0x00]
	muls r1, r4
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	ldr r3, _083407A0 @ =0x0203DD0C
	ldr r0, _083407A4 @ =0x0203DDE4
	ldrb r0, [r0, #0x00]
	muls r0, r2
	ldr r1, _083407A8 @ =0x0203DDFC
	ldrb r1, [r1, #0x00]
	muls r1, r4
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	ldr r1, _083407AC @ =0x0203D4E4
	ldr r0, _083407B0 @ =0x0203D4DC
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	mov r12, r3
	.global _083406EA
_083406EA:
	adds r2, r1, #0x0
	ldr r0, _083407B4 @ =0x0203D520
	cmp r5, r0
	beq _083406FA
	ldr r0, _083407B8 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0834072E
	.global _083406FA
_083406FA:
	movs r1, #0xB8
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0834071C
	ldr r1, _08340794 @ =0x0203DD4C
	ldr r0, [r1, #0x00]
	asrs r0, r0, #0x01
	str r0, [r1, #0x00]
	mov r3, r12
	ldr r0, [r3, #0x00]
	lsls r0, r0, #0x01
	str r0, [r3, #0x00]
	ldr r0, [r2, #0x00]
	asrs r0, r0, #0x01
	str r0, [r2, #0x00]
	.global _0834071C
_0834071C:
	ldr r4, _083407BC @ =0x00000171
	adds r0, r5, r4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0834072E
	mov r6, r12
	ldr r0, [r6, #0x00]
	asrs r0, r0, #0x01
	str r0, [r6, #0x00]
	.global _0834072E
_0834072E:
	ldr r2, _083407C0 @ =0x0203DE04
	ldrh r7, [r5, #0x34]
	lsrs r1, r7, #0x08
	subs r1, #0x40
	movs r0, #0xFF
	ands r1, r0
	str r1, [r2, #0x00]
	ldr r0, _083407C4 @ =0x0203DCF8
	movs r3, #0x3C
	ldsh r2, [r5, r3]
	lsls r2, r2, #0x07
	str r2, [r0, #0x00]
	ldr r3, _083407C8 @ =0x0203DE08
	ldr r4, _083407CC @ =0x0200C3E8
	lsls r0, r1, #0x01
	adds r0, r0, r4
	movs r6, #0x00
	ldsh r0, [r0, r6]
	negs r0, r0
	adds r6, r2, #0x0
	muls r6, r0
	asrs r7, r6, #0x08
	str r7, [r3, #0x00]
	ldr r3, _083407D0 @ =0x0203DE0C
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r4
	movs r4, #0x00
	ldsh r0, [r1, r4]
	adds r4, r2, #0x0
	muls r4, r0
	asrs r2, r4, #0x08
	str r2, [r3, #0x00]
	movs r1, #0xB0
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _083407DC
	ldr r2, _083407D4 @ =0x0203D51C
	asrs r1, r6, #0x09
	ldr r0, [r5, #0x0C]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	ldr r2, _083407D8 @ =0x0203D4F4
	asrs r1, r4, #0x09
	ldr r0, [r5, #0x14]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	b _083407EC
	.byte 0x00, 0x00
	.global _08340794
_08340794: .4byte 0x0203DD4C
	.global _08340798
_08340798: .4byte 0x0203DCF4
	.global _0834079C
_0834079C: .4byte 0x0203D4E0
	.global _083407A0
_083407A0: .4byte 0x0203DD0C
	.global _083407A4
_083407A4: .4byte 0x0203DDE4
	.global _083407A8
_083407A8: .4byte 0x0203DDFC
	.global _083407AC
_083407AC: .4byte 0x0203D4E4
	.global _083407B0
_083407B0: .4byte 0x0203D4DC
	.global _083407B4
_083407B4: .4byte 0x0203D520
	.global _083407B8
_083407B8: .4byte 0x020390EC
	.global _083407BC
_083407BC: .4byte 0x00000171
	.global _083407C0
_083407C0: .4byte 0x0203DE04
	.global _083407C4
_083407C4: .4byte 0x0203DCF8
	.global _083407C8
_083407C8: .4byte 0x0203DE08
	.global _083407CC
_083407CC: .4byte 0x0200C3E8
	.global _083407D0
_083407D0: .4byte 0x0203DE0C
	.global _083407D4
_083407D4: .4byte 0x0203D51C
	.global _083407D8
_083407D8: .4byte 0x0203D4F4
	.global _083407DC
_083407DC:
	ldr r1, _08340844 @ =0x0203D51C
	ldr r0, [r5, #0x0C]
	adds r0, r0, r7
	str r0, [r1, #0x00]
	ldr r1, _08340848 @ =0x0203D4F4
	ldr r0, [r5, #0x14]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _083407EC
_083407EC:
	ldr r1, _0834084C @ =0x0203DDF4
	mov r2, r12
	ldr r0, [r2, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _08340850 @ =0x0203DD2C
	ldr r0, _08340854 @ =0x0203DE04
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r2, _08340858 @ =0x0203DE10
	movs r3, #0x96
	lsls r3, r3, #0x01
	adds r0, r5, r3
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	subs r0, #0x40
	movs r1, #0xFF
	ands r0, r1
	asrs r0, r0, #0x02
	lsls r0, r0, #0x02
	str r0, [r2, #0x00]
	movs r0, #0x00
	adds r1, r5, #0x0
	bl sub_08340964
	movs r4, #0xB0
	lsls r4, r4, #0x01
	adds r0, r5, r4
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08340864
	ldr r2, _08340844 @ =0x0203D51C
	ldr r0, _0834085C @ =0x0203DE08
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x01
	ldr r0, [r5, #0x0C]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	ldr r2, _08340848 @ =0x0203D4F4
	ldr r0, _08340860 @ =0x0203DE0C
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x01
	ldr r0, [r5, #0x14]
	b _08340878
	.byte 0x00, 0x00
	.global _08340844
_08340844: .4byte 0x0203D51C
	.global _08340848
_08340848: .4byte 0x0203D4F4
	.global _0834084C
_0834084C: .4byte 0x0203DDF4
	.global _08340850
_08340850: .4byte 0x0203DD2C
	.global _08340854
_08340854: .4byte 0x0203DE04
	.global _08340858
_08340858: .4byte 0x0203DE10
	.global _0834085C
_0834085C: .4byte 0x0203DE08
	.global _08340860
_08340860: .4byte 0x0203DE0C
	.global _08340864
_08340864:
	ldr r2, _0834093C @ =0x0203D51C
	ldr r1, _08340940 @ =0x0203DE08
	ldr r0, [r5, #0x0C]
	ldr r1, [r1, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	ldr r2, _08340944 @ =0x0203D4F4
	ldr r1, _08340948 @ =0x0203DE0C
	ldr r0, [r5, #0x14]
	ldr r1, [r1, #0x00]
	.global _08340878
_08340878:
	subs r0, r0, r1
	str r0, [r2, #0x00]
	ldr r1, _0834094C @ =0x0203DDF4
	ldr r0, _08340950 @ =0x0203DD4C
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r3, _08340954 @ =0x0203DD2C
	ldr r7, _08340958 @ =0x0203DE04
	ldr r1, [r7, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x80
	movs r2, #0xFF
	ands r0, r2
	str r0, [r3, #0x00]
	ldr r0, _0834095C @ =0x0203DE10
	ands r1, r2
	str r1, [r0, #0x00]
	movs r0, #0x01
	adds r1, r5, #0x0
	bl sub_08340964
	movs r6, #0x9E
	lsls r6, r6, #0x01
	adds r6, r6, r5
	mov r12, r6
	ldr r1, [r6, #0x00]
	cmp r1, #0x00
	beq _083408EC
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r3, r5, r0
	asrs r1, r1, #0x08
	ldr r4, _08340960 @ =0x0200C3E8
	ldr r2, [r7, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r6, #0x00
	ldsh r0, [r0, r6]
	muls r1, r0
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	movs r0, #0xA2
	lsls r0, r0, #0x01
	adds r3, r5, r0
	mov r6, r12
	ldr r1, [r6, #0x00]
	asrs r1, r1, #0x08
	lsls r2, r2, #0x01
	adds r2, r2, r4
	movs r4, #0x00
	ldsh r0, [r2, r4]
	muls r1, r0
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	.global _083408EC
_083408EC:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r6, r5, r0
	ldr r1, [r6, #0x00]
	cmp r1, #0x00
	beq _08340936
	movs r2, #0xA0
	lsls r2, r2, #0x01
	adds r3, r5, r2
	asrs r1, r1, #0x08
	ldr r4, _08340960 @ =0x0200C3E8
	ldr r2, [r7, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r7, #0x00
	ldsh r0, [r0, r7]
	muls r1, r0
	asrs r1, r1, #0x04
	ldr r0, [r3, #0x00]
	subs r0, r0, r1
	str r0, [r3, #0x00]
	movs r0, #0xA2
	lsls r0, r0, #0x01
	adds r3, r5, r0
	ldr r1, [r6, #0x00]
	asrs r1, r1, #0x08
	lsls r2, r2, #0x01
	adds r2, r2, r4
	movs r4, #0x00
	ldsh r0, [r2, r4]
	muls r1, r0
	asrs r1, r1, #0x04
	ldr r0, [r3, #0x00]
	subs r0, r0, r1
	str r0, [r3, #0x00]
	.global _08340936
_08340936:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0834093C
_0834093C: .4byte 0x0203D51C
	.global _08340940
_08340940: .4byte 0x0203DE08
	.global _08340944
_08340944: .4byte 0x0203D4F4
	.global _08340948
_08340948: .4byte 0x0203DE0C
	.global _0834094C
_0834094C: .4byte 0x0203DDF4
	.global _08340950
_08340950: .4byte 0x0203DD4C
	.global _08340954
_08340954: .4byte 0x0203DD2C
	.global _08340958
_08340958: .4byte 0x0203DE04
	.global _0834095C
_0834095C: .4byte 0x0203DE10
	.global _08340960
_08340960: .4byte 0x0200C3E8
	thumb_func_start sub_08340964
sub_08340964:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r1, #0x0
	lsls r0, r0, #0x18
	ldr r3, _083409FC @ =0x0200C3E8
	ldr r1, _08340A00 @ =0x0203DE10
	ldr r2, [r1, #0x00]
	adds r2, #0x40
	movs r1, #0xFF
	ands r2, r1
	adds r1, r2, #0x0
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r3
	movs r4, #0x00
	ldsh r7, [r1, r4]
	lsls r2, r2, #0x01
	adds r2, r2, r3
	movs r3, #0x00
	ldsh r1, [r2, r3]
	mov r8, r1
	ldr r1, _08340A04 @ =0x0203D51C
	ldr r1, [r1, #0x00]
	adds r2, r7, #0x0
	muls r2, r1
	ldr r1, _08340A08 @ =0x0203D4F4
	ldr r1, [r1, #0x00]
	mov r4, r8
	muls r4, r1
	adds r1, r4, #0x0
	adds r2, r2, r1
	asrs r6, r2, #0x08
	cmp r0, #0x00
	beq _08340A84
	ldr r0, _08340A0C @ =0x0203E0E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _083409D6
	adds r3, r5, #0x0
	adds r3, #0x8C
	asrs r2, r2, #0x11
	adds r1, r2, #0x0
	cmp r2, #0x00
	bge _083409C0
	negs r1, r2
	.global _083409C0
_083409C0:
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x90
	cmp r2, #0x00
	bge _083409D0
	negs r2, r2
	.global _083409D0
_083409D0:
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _083409D6
_083409D6:
	ldr r0, _08340A10 @ =0x0203D4E4
	ldr r2, [r0, #0x00]
	negs r1, r2
	cmp r6, r1
	bge _08340A1C
	lsrs r0, r1, #0x1F
	adds r0, r1, r0
	asrs r6, r0, #0x01
	ldr r4, _08340A14 @ =0x0203DD38
	ldrb r0, [r4, #0x00]
	movs r1, #0x02
	bl sub_08342ED0
	ldr r0, _08340A18 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08340A38
	b _08340A48
	.byte 0x00, 0x00
	.global _083409FC
_083409FC: .4byte 0x0200C3E8
	.global _08340A00
_08340A00: .4byte 0x0203DE10
	.global _08340A04
_08340A04: .4byte 0x0203D51C
	.global _08340A08
_08340A08: .4byte 0x0203D4F4
	.global _08340A0C
_08340A0C: .4byte 0x0203E0E0
	.global _08340A10
_08340A10: .4byte 0x0203D4E4
	.global _08340A14
_08340A14: .4byte 0x0203DD38
	.global _08340A18
_08340A18: .4byte 0x020390EC
	.global _08340A1C
_08340A1C:
	cmp r6, r2
	ble _08340AB0
	lsrs r0, r2, #0x1F
	adds r0, r2, r0
	asrs r6, r0, #0x01
	ldr r4, _08340A40 @ =0x0203DD38
	ldrb r0, [r4, #0x00]
	movs r1, #0x03
	bl sub_08342ED0
	ldr r0, _08340A44 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08340A48
	.global _08340A38
_08340A38:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08340A52
	b _08340AB0
	.global _08340A40
_08340A40: .4byte 0x0203DD38
	.global _08340A44
_08340A44: .4byte 0x020390EC
	.global _08340A48
_08340A48:
	ldr r0, _08340A74 @ =0x0203E1B0
	ldrb r4, [r4, #0x00]
	ldrb r0, [r0, #0x00]
	cmp r4, r0
	bne _08340AB0
	.global _08340A52
_08340A52:
	ldr r0, _08340A78 @ =0x0203E120
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08340AB0
	ldr r0, _08340A7C @ =0x020390F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08340AB0
	ldr r0, _08340A80 @ =0x020391F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08340AB0
	movs r0, #0x0B
	bl sub_0833A8C8
	b _08340AB0
	.byte 0x00, 0x00
	.global _08340A74
_08340A74: .4byte 0x0203E1B0
	.global _08340A78
_08340A78: .4byte 0x0203E120
	.global _08340A7C
_08340A7C: .4byte 0x020390F0
	.global _08340A80
_08340A80: .4byte 0x020391F0
	.global _08340A84
_08340A84:
	ldr r0, _08340B2C @ =0x0203E0E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08340AB0
	adds r3, r5, #0x0
	adds r3, #0x94
	asrs r2, r2, #0x11
	adds r1, r2, #0x0
	cmp r2, #0x00
	bge _08340A9A
	negs r1, r2
	.global _08340A9A
_08340A9A:
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x98
	cmp r2, #0x00
	bge _08340AAA
	negs r2, r2
	.global _08340AAA
_08340AAA:
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _08340AB0
_08340AB0:
	ldr r0, _08340B30 @ =0x0203DDF4
	ldr r0, [r0, #0x00]
	adds r2, r6, #0x0
	muls r2, r0
	asrs r2, r2, #0x08
	negs r2, r2
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r3, r5, r0
	adds r1, r2, #0x0
	muls r1, r7
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	movs r1, #0xA2
	lsls r1, r1, #0x01
	adds r3, r5, r1
	mov r1, r8
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	ldr r0, _08340B34 @ =0x0203DE10
	ldr r0, [r0, #0x00]
	adds r0, #0x40
	ldr r1, _08340B38 @ =0x0203DD2C
	ldr r1, [r1, #0x00]
	subs r0, r0, r1
	movs r1, #0xFF
	ands r0, r1
	ldr r1, _08340B3C @ =0x0200C3E8
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r3, #0x00
	ldsh r0, [r0, r3]
	muls r0, r2
	asrs r2, r0, #0x08
	lsls r2, r2, #0x07
	adds r1, r2, #0x0
	cmp r2, #0x00
	bge _08340B0A
	ldr r4, _08340B40 @ =0x00007FFF
	adds r1, r2, r4
	.global _08340B0A
_08340B0A:
	asrs r2, r1, #0x0F
	movs r0, #0xC0
	lsls r0, r0, #0x01
	adds r3, r5, r0
	ldrb r0, [r3, #0x00]
	cmp r0, #0x00
	beq _08340B44
	subs r0, #0x01
	strb r0, [r3, #0x00]
	movs r3, #0xA4
	lsls r3, r3, #0x01
	adds r2, r5, r3
	asrs r1, r1, #0x10
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	b _08340B50
	.global _08340B2C
_08340B2C: .4byte 0x0203E0E0
	.global _08340B30
_08340B30: .4byte 0x0203DDF4
	.global _08340B34
_08340B34: .4byte 0x0203DE10
	.global _08340B38
_08340B38: .4byte 0x0203DD2C
	.global _08340B3C
_08340B3C: .4byte 0x0200C3E8
	.global _08340B40
_08340B40: .4byte 0x00007FFF
	.global _08340B44
_08340B44:
	movs r4, #0xA4
	lsls r4, r4, #0x01
	adds r1, r5, r4
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _08340B50
_08340B50:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x30, 0xB5, 0x02, 0x1C, 0x00, 0x24, 0x00, 0x25, 0x00, 0x2A, 0x02, 0xDA, 0x52, 0x42
	.byte 0x01, 0x24, 0x80, 0x25, 0x00, 0x29, 0x02, 0xDA, 0x49, 0x42, 0x01, 0x20, 0x44, 0x40, 0x88, 0x01
	.byte 0x51, 0x18, 0x04, 0xF0, 0x1C, 0xF8, 0x00, 0x2C, 0x00, 0xD0, 0x40, 0x42, 0x28, 0x18, 0x30, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x01, 0x24, 0x1F, 0x48
	.byte 0x80, 0x46, 0x63, 0x22, 0x1F, 0x48, 0x40, 0x44, 0xC8, 0x21, 0x49, 0x00, 0x02, 0x70, 0x40, 0x18
	.byte 0x01, 0x34, 0x05, 0x2C, 0xFA, 0xD1, 0x01, 0x24, 0xFB, 0xF7, 0x83, 0xF8, 0x1F, 0x22, 0x02, 0x40
	.byte 0x1D, 0x2A, 0xF9, 0xD8, 0x00, 0x25, 0x00, 0x21, 0x15, 0x48, 0x80, 0x46, 0x63, 0x00, 0x67, 0x1C
	.byte 0xC4, 0x46, 0xB1, 0x26, 0x76, 0x00, 0x48, 0x00, 0x40, 0x18, 0xC0, 0x00, 0x40, 0x18, 0x00, 0x01
	.byte 0x60, 0x44, 0x80, 0x19, 0x00, 0x78, 0x82, 0x42, 0x00, 0xD1, 0x01, 0x25, 0x48, 0x1C, 0x00, 0x06
	.byte 0x01, 0x0E, 0x05, 0x29, 0xEF, 0xD1, 0x00, 0x2D, 0xDE, 0xD1, 0x18, 0x19, 0xC0, 0x00, 0x00, 0x19
	.byte 0x00, 0x01, 0x40, 0x44, 0xB1, 0x21, 0x49, 0x00, 0x40, 0x18, 0x02, 0x70, 0x3C, 0x1C, 0x05, 0x2C
	.byte 0xD2, 0xD1, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x20, 0xD5
	.byte 0x03, 0x02, 0xF2, 0x02, 0x00, 0x00, 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x01, 0x24, 0x20, 0x48
	.byte 0x84, 0x46, 0x61, 0x00, 0x08, 0x19, 0xC0, 0x00, 0x00, 0x19, 0x00, 0x01, 0x60, 0x44, 0xB1, 0x22
	.byte 0x52, 0x00, 0x80, 0x18, 0x0F, 0x1C, 0x61, 0x1C, 0x88, 0x46, 0x00, 0x78, 0x63, 0x28, 0x27, 0xD1
	.byte 0xFB, 0xF7, 0x37, 0xF8, 0x1F, 0x22, 0x02, 0x40, 0x1D, 0x2A, 0xF9, 0xD8, 0x00, 0x23, 0x00, 0x21
	.byte 0x14, 0x48, 0x84, 0x46, 0x66, 0x46, 0xB1, 0x25, 0x6D, 0x00, 0x48, 0x00, 0x40, 0x18, 0xC0, 0x00
	.byte 0x40, 0x18, 0x00, 0x01, 0x80, 0x19, 0x40, 0x19, 0x00, 0x78, 0x82, 0x42, 0x00, 0xD1, 0x01, 0x23
	.byte 0x48, 0x1C, 0x00, 0x06, 0x01, 0x0E, 0x05, 0x29, 0xEF, 0xD1, 0x00, 0x2B, 0xE0, 0xD1, 0x38, 0x19
	.byte 0xC0, 0x00, 0x00, 0x19, 0x00, 0x01, 0x60, 0x44, 0xB1, 0x21, 0x49, 0x00, 0x40, 0x18, 0x02, 0x70
	.byte 0x44, 0x46, 0x05, 0x2C, 0xC5, 0xD1, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x00, 0x00, 0x20, 0xD5, 0x03, 0x02, 0x02, 0x1C, 0x06, 0x48, 0x00, 0x68, 0x90, 0x42, 0x0E, 0xDC
	.byte 0x05, 0x48, 0x00, 0x6D, 0x05, 0x49, 0x08, 0x40, 0x90, 0x42, 0x08, 0xD3, 0x01, 0x20, 0x07, 0xE0
	.byte 0x00, 0x00, 0x34, 0xDD, 0x03, 0x02, 0x20, 0xD5, 0x03, 0x02, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x20
	.byte 0x70, 0x47, 0x06, 0x49, 0x0A, 0x68, 0x51, 0x01, 0x89, 0x1A, 0x89, 0x00, 0x89, 0x18, 0xC9, 0x00
	.byte 0x04, 0x4A, 0x12, 0x68, 0x89, 0x18, 0x81, 0x42, 0x05, 0xDD, 0x00, 0x20, 0x04, 0xE0, 0xFC, 0xDC
	.byte 0x03, 0x02, 0x00, 0xD5, 0x03, 0x02, 0x01, 0x20, 0x70, 0x47
	thumb_func_start sub_08340D04
sub_08340D04:
	push {r4, r5, r6, lr}
	ldr r0, _08340D9C @ =0x020251B8
	ldr r6, [r0, #0x00]
	movs r0, #0x94
	lsls r0, r0, #0x02
	adds r5, r6, r0
	ldr r0, _08340DA0 @ =0x0200D0B8
	movs r1, #0x08
	movs r2, #0x08
	bl sub_0833EF0C
	adds r0, r5, #0x0
	movs r1, #0x00
	bl sub_0833E36C
	movs r0, #0x95
	lsls r0, r0, #0x02
	adds r5, r6, r0
	ldr r0, _08340DA4 @ =0x0203DD04
	ldr r1, [r0, #0x00]
	adds r0, r5, #0x0
	bl sub_0833E36C
	ldr r0, _08340DA8 @ =0x0000025A
	adds r5, r6, r0
	ldr r4, _08340DAC @ =0x0203DCFC
	ldr r0, [r4, #0x00]
	movs r1, #0x0A
	bl sub_08344BB8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_0833E36C
	ldr r0, _08340DB0 @ =0x0000025E
	adds r5, r6, r0
	ldr r0, [r4, #0x00]
	movs r1, #0x0A
	bl sub_08344C50
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_0833E36C
	movs r0, #0x99
	lsls r0, r0, #0x02
	adds r5, r6, r0
	ldr r4, _08340DB4 @ =0x0203D500
	ldr r0, [r4, #0x00]
	movs r1, #0x64
	bl sub_08344BB8
	movs r1, #0x0A
	bl sub_08344C50
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_0833E36C
	movs r0, #0x9A
	lsls r0, r0, #0x02
	adds r5, r6, r0
	ldr r0, [r4, #0x00]
	movs r1, #0x0A
	bl sub_08344BB8
	movs r1, #0x0A
	bl sub_08344C50
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_0833E36C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _08340D9C
_08340D9C: .4byte 0x020251B8
	.global _08340DA0
_08340DA0: .4byte 0x0200D0B8
	.global _08340DA4
_08340DA4: .4byte 0x0203DD04
	.global _08340DA8
_08340DA8: .4byte 0x0000025A
	.global _08340DAC
_08340DAC: .4byte 0x0203DCFC
	.global _08340DB0
_08340DB0: .4byte 0x0000025E
	.global _08340DB4
_08340DB4: .4byte 0x0203D500
