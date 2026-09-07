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
	thumb_func_start sub_08341288
sub_08341288:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r5, r1, #0x0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r9, r0
	ldr r6, _0834140C @ =0x0203916C
	ldrb r0, [r6, #0x00]
	cmp r0, #0x04
	bne _083412AE
	movs r4, #0xB1
	lsls r4, r4, #0x01
	adds r1, r5, r4
	movs r0, #0x00
	strb r0, [r1, #0x00]
	.global _083412AE
_083412AE:
	movs r7, #0xC7
	lsls r7, r7, #0x01
	adds r0, r5, r7
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r4, _08341410 @ =0x00000175
	adds r0, r5, r4
	strb r1, [r0, #0x00]
	ldr r0, _08341414 @ =0x0203DCF0
	strb r1, [r0, #0x00]
	subs r7, #0x0E
	adds r0, r5, r7
	strb r1, [r0, #0x00]
	adds r4, #0x01
	adds r0, r5, r4
	strb r1, [r0, #0x00]
	subs r7, #0x18
	adds r0, r5, r7
	strb r1, [r0, #0x00]
	ldr r0, _08341418 @ =0x0203D4E8
	strb r1, [r0, #0x00]
	subs r4, #0x10
	adds r0, r5, r4
	movs r4, #0x01
	strb r4, [r0, #0x00]
	subs r7, #0x01
	adds r0, r5, r7
	strb r1, [r0, #0x00]
	str r2, [r5, #0x00]
	str r3, [r5, #0x08]
	movs r2, #0x00
	mov r0, sp
	ldrh r0, [r0, #0x24]
	strh r0, [r5, #0x34]
	str r1, [r5, #0x2C]
	str r1, [r5, #0x28]
	adds r0, r5, #0x0
	adds r0, #0x40
	strh r1, [r0, #0x00]
	subs r0, #0x02
	strb r2, [r0, #0x00]
	adds r0, #0x17
	strb r2, [r0, #0x00]
	subs r0, #0x08
	strb r2, [r0, #0x00]
	movs r3, #0xBA
	lsls r3, r3, #0x01
	adds r0, r5, r3
	strb r2, [r0, #0x00]
	ldr r3, _0834141C @ =0x02026E1C
	mov r7, r9
	lsls r0, r7, #0x01
	add r0, r9
	lsls r0, r0, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x58]
	adds r0, r5, #0x0
	adds r0, #0x7C
	strb r2, [r0, #0x00]
	adds r0, #0x08
	strb r4, [r0, #0x00]
	str r1, [r5, #0x30]
	adds r0, #0x04
	str r1, [r0, #0x00]
	adds r0, #0x1A
	strh r1, [r0, #0x00]
	subs r0, #0x16
	str r1, [r0, #0x00]
	adds r0, #0x04
	str r1, [r0, #0x00]
	adds r0, #0x04
	str r1, [r0, #0x00]
	adds r0, #0x04
	str r1, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x9C
	movs r0, #0xB4
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	ldrb r6, [r6, #0x00]
	cmp r6, #0x0F
	bne _08341368
	ldr r0, _08341420 @ =0x0203DFB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _08341368
	ldr r0, _08341424 @ =0x0203D520
	cmp r5, r0
	bne _08341368
	movs r0, #0xA0
	lsls r0, r0, #0x07
	str r0, [r1, #0x00]
	.global _08341368
_08341368:
	ldr r0, _0834140C @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x05
	beq _0834137E
	cmp r0, #0x11
	beq _0834137E
	movs r0, #0xB6
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x00
	str r0, [r1, #0x00]
	.global _0834137E
_0834137E:
	movs r1, #0xB8
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r4, #0x00
	strb r4, [r0, #0x00]
	ldr r2, _08341428 @ =0x00000171
	adds r6, r5, r2
	strb r4, [r6, #0x00]
	movs r3, #0xB9
	lsls r3, r3, #0x01
	adds r0, r5, r3
	strb r4, [r0, #0x00]
	movs r7, #0x94
	lsls r7, r7, #0x01
	adds r0, r5, r7
	ldr r1, [sp, #0x024]
	bl sub_083432EC
	movs r1, #0x9A
	lsls r1, r1, #0x01
	adds r0, r5, r1
	str r4, [r0, #0x00]
	movs r2, #0x9C
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x01
	negs r0, r0
	str r0, [r1, #0x00]
	ldr r3, _0834142C @ =0x00000173
	adds r0, r5, r3
	strb r4, [r0, #0x00]
	strb r4, [r6, #0x00]
	movs r1, #0x00
	adds r2, r5, #0x0
	adds r2, #0x4C
	adds r6, r5, #0x0
	adds r6, #0xE4
	adds r7, r5, #0x0
	adds r7, #0xE8
	movs r4, #0xEC
	adds r4, r4, r5
	mov r12, r4
	movs r0, #0x7D
	adds r0, r0, r5
	mov r10, r0
	adds r3, r5, #0x0
	adds r3, #0x4E
	str r3, [sp, #0x000]
	ldr r4, _08341430 @ =0x0203DDE8
	movs r3, #0x00
	.global _083413E2
_083413E2:
	adds r0, r1, r4
	strb r3, [r0, #0x00]
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x08
	bne _083413E2
	ldr r0, _0834140C @ =0x0203916C
	mov r8, r0
	ldrb r4, [r0, #0x00]
	cmp r4, #0x0F
	bne _083414A4
	ldr r0, _08341420 @ =0x0203DFB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0F
	bhi _083414A4
	lsls r0, r0, #0x02
	ldr r1, _08341434 @ =0x020089B8
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.global _0834140C
_0834140C: .4byte 0x0203916C
	.global _08341410
_08341410: .4byte 0x00000175
	.global _08341414
_08341414: .4byte 0x0203DCF0
	.global _08341418
_08341418: .4byte 0x0203D4E8
	.global _0834141C
_0834141C: .4byte 0x02026E1C
	.global _08341420
_08341420: .4byte 0x0203DFB0
	.global _08341424
_08341424: .4byte 0x0203D520
	.global _08341428
_08341428: .4byte 0x00000171
	.global _0834142C
_0834142C: .4byte 0x00000173
	.global _08341430
_08341430: .4byte 0x0203DDE8
	.global _08341434
_08341434: .4byte 0x020089B8
	.byte 0xF8, 0x89, 0x00, 0x02, 0xFC, 0x89, 0x00, 0x02, 0x00, 0x8A, 0x00, 0x02, 0x04, 0x8A, 0x00, 0x02
	.byte 0x24, 0x8A, 0x00, 0x02, 0x24, 0x8A, 0x00, 0x02, 0x08, 0x8A, 0x00, 0x02, 0x24, 0x8A, 0x00, 0x02
	.byte 0x24, 0x8A, 0x00, 0x02, 0x24, 0x8A, 0x00, 0x02, 0x0C, 0x8A, 0x00, 0x02, 0x10, 0x8A, 0x00, 0x02
	.byte 0x14, 0x8A, 0x00, 0x02, 0x18, 0x8A, 0x00, 0x02, 0x1C, 0x8A, 0x00, 0x02, 0x20, 0x8A, 0x00, 0x02
	.byte 0x01, 0x20, 0x14, 0xE0, 0x04, 0x20, 0x12, 0xE0, 0x05, 0x20, 0x10, 0xE0, 0x28, 0x20, 0x0E, 0xE0
	.byte 0x28, 0x20, 0x0C, 0xE0, 0x0F, 0x20, 0x0A, 0xE0, 0x0F, 0x20, 0x08, 0xE0, 0x55, 0x20, 0x06, 0xE0
	.byte 0x12, 0x20, 0x04, 0xE0, 0x05, 0x20, 0x02, 0xE0, 0x14, 0x20, 0x00, 0xE0
	.global _083414A4
_083414A4:
	movs r0, #0x00
	strb r0, [r2, #0x00]
	mov r1, r8
	ldrb r0, [r1, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bls _083414BC
	ldrb r0, [r2, #0x00]
	subs r0, #0x01
	strb r0, [r2, #0x00]
	.global _083414BC
_083414BC:
	movs r1, #0x00
	str r1, [r5, #0x50]
	movs r3, #0xAE
	lsls r3, r3, #0x01
	adds r2, r5, r3
	movs r0, #0x96
	lsls r0, r0, #0x01
	str r0, [r2, #0x00]
	str r1, [r5, #0x0C]
	str r1, [r5, #0x14]
	movs r4, #0x88
	lsls r4, r4, #0x01
	adds r0, r5, r4
	strb r1, [r0, #0x00]
	movs r2, #0xA0
	lsls r2, r2, #0x01
	adds r0, r5, r2
	str r1, [r0, #0x00]
	subs r3, #0x18
	adds r0, r5, r3
	str r1, [r0, #0x00]
	adds r4, #0x2C
	adds r0, r5, r4
	str r1, [r0, #0x00]
	adds r2, #0x08
	adds r0, r5, r2
	str r1, [r0, #0x00]
	adds r3, #0x08
	adds r0, r5, r3
	str r1, [r0, #0x00]
	adds r4, #0x14
	adds r1, r5, r4
	movs r0, #0x63
	strb r0, [r1, #0x00]
	ldr r4, _08341590 @ =0x02027500
	adds r0, #0xFF
	adds r1, r5, r0
	ldrb r2, [r1, #0x00]
	lsls r0, r2, #0x02
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x00]
	ldr r3, _08341594 @ =0x02027578
	ldrb r2, [r1, #0x00]
	lsls r0, r2, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x00]
	ldr r2, _08341598 @ =0x020275F0
	ldrb r1, [r1, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	mov r1, r12
	str r0, [r1, #0x00]
	ldr r0, _0834159C @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0834155A
	mov r0, r9
	cmp r0, #0x00
	beq _0834155A
	mov r1, r8
	ldrb r1, [r1, #0x00]
	cmp r1, #0x02
	beq _0834155A
	ldr r0, _083415A0 @ =0x0202713E
	str r0, [r6, #0x00]
	ldr r0, _083415A4 @ =0x0202714A
	str r0, [r7, #0x00]
	ldr r0, _083415A8 @ =0x02027154
	mov r1, r12
	str r0, [r1, #0x00]
	ldr r0, [r4, #0x00]
	str r0, [r6, #0x00]
	ldr r0, [r3, #0x00]
	str r0, [r7, #0x00]
	ldr r0, [r2, #0x00]
	str r0, [r1, #0x00]
	.global _0834155A
_0834155A:
	movs r2, #0xAC
	lsls r2, r2, #0x01
	adds r0, r5, r2
	movs r1, #0x00
	str r1, [r0, #0x00]
	mov r3, r10
	strb r1, [r3, #0x00]
	movs r2, #0x00
	mov r4, sp
	ldrh r4, [r4, #0x24]
	strh r4, [r5, #0x36]
	strh r1, [r5, #0x38]
	movs r7, #0xB0
	lsls r7, r7, #0x01
	adds r0, r5, r7
	strh r1, [r0, #0x00]
	ldr r0, [sp, #0x000]
	strb r2, [r0, #0x00]
	strh r1, [r5, #0x3C]
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08341590
_08341590: .4byte 0x02027500
	.global _08341594
_08341594: .4byte 0x02027578
	.global _08341598
_08341598: .4byte 0x020275F0
	.global _0834159C
_0834159C: .4byte 0x020390EC
	.global _083415A0
_083415A0: .4byte 0x0202713E
	.global _083415A4
_083415A4: .4byte 0x0202714A
	.global _083415A8
_083415A8: .4byte 0x02027154
	.byte 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_083415B0
sub_083415B0:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _08341624 @ =0x020390A0
	ldrb r5, [r0, #0x00]
	ldr r0, _08341628 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _083415CA
	ldr r0, _0834162C @ =0x020390BC
	ldrb r5, [r0, #0x00]
	.global _083415CA
_083415CA:
	movs r6, #0x00
	ldr r0, _08341630 @ =0x0203D520
	lsls r2, r4, #0x01
	adds r1, r2, r4
	lsls r1, r1, #0x03
	adds r1, r1, r4
	lsls r1, r1, #0x04
	adds r7, r0, #0x0
	adds r7, #0x50
	adds r1, r1, r7
	ldr r1, [r1, #0x00]
	mov r12, r1
	movs r3, #0x00
	mov r8, r0
	cmp r6, r5
	beq _08341608
	adds r1, r7, #0x0
	movs r7, #0xC8
	lsls r7, r7, #0x01
	.global _083415F0
_083415F0:
	cmp r3, r4
	beq _08341600
	ldr r0, [r1, #0x00]
	cmp r0, r12
	ble _08341600
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	.global _08341600
_08341600:
	adds r1, r1, r7
	adds r3, #0x01
	cmp r3, r5
	bne _083415F0
	.global _08341608
_08341608:
	adds r0, r2, r4
	lsls r0, r0, #0x03
	adds r0, r0, r4
	lsls r0, r0, #0x04
	add r0, r8
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r0, r1
	strb r6, [r0, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08341624
_08341624: .4byte 0x020390A0
	.global _08341628
_08341628: .4byte 0x020390EC
	.global _0834162C
_0834162C: .4byte 0x020390BC
	.global _08341630
_08341630: .4byte 0x0203D520
	.byte 0xC3, 0x0F, 0xC0, 0x18, 0x40, 0x10, 0x0B, 0x18, 0x09, 0x1A, 0x13, 0x60, 0x51, 0x60, 0x70, 0x47
	thumb_func_start sub_08341644
sub_08341644:
	push {r4, lr}
	adds r4, r2, #0x0
	ldr r3, _08341680 @ =0x02039110
	ldr r2, [r3, #0x00]
	subs r0, r0, r2
	ldr r2, [r3, #0x04]
	subs r1, r1, r2
	subs r2, r0, r1
	lsls r2, r2, #0x01
	adds r0, r0, r1
	movs r1, #0xF1
	lsls r1, r1, #0x10
	adds r2, r2, r1
	movs r1, #0xA1
	lsls r1, r1, #0x10
	adds r3, r0, r1
	asrs r2, r2, #0x11
	asrs r3, r3, #0x11
	adds r1, r2, #0x0
	adds r1, #0x18
	movs r0, #0x90
	lsls r0, r0, #0x01
	cmp r1, r0
	bhi _0834167C
	adds r0, r3, #0x0
	adds r0, #0x20
	cmp r0, #0xD0
	bls _08341684
	.global _0834167C
_0834167C:
	movs r0, #0x00
	b _08341688
	.global _08341680
_08341680: .4byte 0x02039110
	.global _08341684
_08341684:
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
	.global _08341688
_08341688:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x10, 0xB5, 0x14, 0x1C, 0x0D, 0x4B, 0x1A, 0x68, 0x80, 0x1A, 0x5A, 0x68, 0x89, 0x1A
	.byte 0x42, 0x1A, 0x52, 0x00, 0x40, 0x18, 0xF1, 0x21, 0x09, 0x04, 0x52, 0x18, 0xA1, 0x21, 0x09, 0x04
	.byte 0x43, 0x18, 0x52, 0x14, 0x5B, 0x14, 0x11, 0x1C, 0x10, 0x31, 0x88, 0x20, 0x40, 0x00, 0x81, 0x42
	.byte 0x03, 0xD8, 0x18, 0x1C, 0x20, 0x30, 0xC0, 0x28, 0x03, 0xD9, 0x00, 0x20, 0x03, 0xE0, 0x10, 0x91
	.byte 0x03, 0x02, 0x22, 0x60, 0x63, 0x60, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	thumb_func_start sub_083416DC
sub_083416DC:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r6, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r10, r1
	ldr r0, [r6, #0x00]
	ldr r1, [r6, #0x08]
	mov r2, sp
	bl sub_08341644
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08341702
	b _083419BA
	.global _08341702
_08341702:
	ldr r1, [sp, #0x004]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	ldr r0, [sp, #0x000]
	subs r0, #0x18
	str r0, [sp, #0x000]
	subs r1, #0x10
	str r1, [sp, #0x004]
	adds r0, r6, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341734
	ldr r0, _08341784 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341734
	ldr r0, _08341788 @ =0x020390AC
	ldr r0, [r0, #0x00]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _08341734
	b _083419BA
	.global _08341734
_08341734:
	ldrh r1, [r6, #0x34]
	movs r2, #0x80
	lsls r2, r2, #0x02
	adds r0, r1, r2
	asrs r4, r0, #0x0A
	adds r4, #0x28
	movs r0, #0x3F
	ands r4, r0
	movs r1, #0x20
	adds r0, r4, #0x0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r0, #0x1F
	ands r4, r0
	cmp r7, #0x00
	beq _0834175A
	movs r0, #0x20
	subs r4, r0, r4
	.global _0834175A
_0834175A:
	ldr r1, _0834178C @ =0x02026E1C
	movs r3, #0xB1
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl sub_0833FD78
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x0C
	movs r1, #0xB9
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341790
	movs r0, #0x80
	lsls r0, r0, #0x04
	b _08341794
	.global _08341784
_08341784: .4byte 0x020390EC
	.global _08341788
_08341788: .4byte 0x020390AC
	.global _0834178C
_0834178C: .4byte 0x02026E1C
	.global _08341790
_08341790:
	movs r0, #0x80
	lsls r0, r0, #0x03
	.global _08341794
_08341794:
	orrs r5, r0
	cmp r7, #0x00
	bne _08341830
	ldr r1, _08341820 @ =0x02026E14
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r7, r6, r2
	ldrb r3, [r7, #0x00]
	lsls r0, r3, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	lsls r4, r4, #0x02
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	bl sub_0833FC48
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _083417DE
	ldr r0, [sp, #0x004]
	movs r1, #0xFF
	ands r0, r1
	ldr r1, [sp, #0x000]
	ldr r2, _08341824 @ =0x000001FF
	ands r1, r2
	lsls r1, r1, #0x10
	orrs r0, r1
	ldr r1, _08341828 @ =0x80008000
	orrs r0, r1
	ldr r1, [r3, #0x10]
	orrs r1, r5
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl sub_0833D6D8
	.global _083417DE
_083417DE:
	ldr r1, _0834182C @ =0x02026E18
	ldrb r7, [r7, #0x00]
	lsls r0, r7, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	bl sub_0833FBB0
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _083418C8
	ldr r0, [sp, #0x004]
	movs r1, #0xFF
	ands r0, r1
	ldr r1, [sp, #0x000]
	adds r1, #0x10
	ldr r2, _08341824 @ =0x000001FF
	ands r1, r2
	lsls r1, r1, #0x10
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	ldr r1, [r3, #0x10]
	orrs r1, r5
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl sub_0833D6D8
	b _083418C8
	.global _08341820
_08341820: .4byte 0x02026E14
	.global _08341824
_08341824: .4byte 0x000001FF
	.global _08341828
_08341828: .4byte 0x80008000
	.global _0834182C
_0834182C: .4byte 0x02026E18
	.global _08341830
_08341830:
	ldr r1, _0834193C @ =0x02026E18
	movs r0, #0xB1
	lsls r0, r0, #0x01
	adds r0, r0, r6
	mov r8, r0
	ldrb r2, [r0, #0x00]
	lsls r0, r2, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	lsls r7, r4, #0x02
	adds r0, r7, r0
	ldr r0, [r0, #0x00]
	bl sub_0833FBB0
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _08341880
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	ldr r1, _08341940 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r4, r0
	ldr r1, [r3, #0x10]
	orrs r1, r5
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r4, r0
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	bl sub_0833D6D8
	.global _08341880
_08341880:
	ldr r1, _08341944 @ =0x02026E14
	mov r3, r8
	ldrb r3, [r3, #0x00]
	lsls r0, r3, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	adds r0, r7, r0
	ldr r0, [r0, #0x00]
	bl sub_0833FC48
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _083418C8
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	adds r0, #0x20
	ldr r1, _08341940 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	ldr r0, _08341948 @ =0x80008000
	orrs r4, r0
	ldr r1, [r3, #0x10]
	orrs r1, r5
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r4, r0
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	bl sub_0833D6D8
	.global _083418C8
_083418C8:
	ldr r0, _0834194C @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0834195C
	ldr r1, _08341950 @ =0x0202772C
	mov r2, r10
	lsls r0, r2, #0x02
	adds r0, r0, r1
	ldr r5, [r0, #0x00]
	ldr r0, _08341954 @ =0x020390AC
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x01
	movs r1, #0x07
	bl sub_08344C50
	lsls r0, r0, #0x02
	adds r5, r5, r0
	ldr r1, [sp, #0x004]
	subs r1, #0x0C
	str r1, [sp, #0x004]
	ldr r0, [sp, #0x000]
	adds r0, #0x10
	str r0, [sp, #0x000]
	movs r4, #0xFF
	ands r4, r1
	ldr r1, _08341940 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r4, r0
	ldr r0, [r5, #0x00]
	bl sub_0833FC94
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _083419BA
	ldr r5, [r3, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x03
	orrs r5, r0
	ldr r0, _08341958 @ =0x020243E8
	bl sub_0833FD78
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	orrs r5, r0
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_0833D6D8
	b _083419BA
	.byte 0x00, 0x00
	.global _0834193C
_0834193C: .4byte 0x02026E18
	.global _08341940
_08341940: .4byte 0x000001FF
	.global _08341944
_08341944: .4byte 0x02026E14
	.global _08341948
_08341948: .4byte 0x80008000
	.global _0834194C
_0834194C: .4byte 0x020390EC
	.global _08341950
_08341950: .4byte 0x0202772C
	.global _08341954
_08341954: .4byte 0x020390AC
	.global _08341958
_08341958: .4byte 0x020243E8
	.global _0834195C
_0834195C:
	ldr r1, _083419CC @ =0x0202773C
	movs r3, #0xB1
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r5, [r0, #0x00]
	ldr r1, [sp, #0x004]
	subs r1, #0x08
	str r1, [sp, #0x004]
	ldr r0, [sp, #0x000]
	adds r0, #0x10
	str r0, [sp, #0x000]
	movs r4, #0xFF
	ands r4, r1
	ldr r1, _083419D0 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x07
	orrs r4, r0
	ldr r0, [r5, #0x00]
	bl sub_0833FBFC
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _083419BA
	ldr r5, [r3, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x03
	orrs r5, r0
	ldr r0, _083419D4 @ =0x0201B590
	bl sub_0833FD78
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	orrs r5, r0
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_0833D6D8
	.global _083419BA
_083419BA:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _083419CC
_083419CC: .4byte 0x0202773C
	.global _083419D0
_083419D0: .4byte 0x000001FF
	.global _083419D4
_083419D4: .4byte 0x0201B590
	thumb_func_start sub_083419D8
sub_083419D8:
	push {r4, r5, r6, lr}
	ldr r0, _08341A1C @ =0x020390A0
	ldrb r5, [r0, #0x00]
	ldr r0, _08341A20 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _083419EA
	ldr r0, _08341A24 @ =0x020390BC
	ldrb r5, [r0, #0x00]
	.global _083419EA
_083419EA:
	ldr r6, _08341A28 @ =0x0203D520
	movs r4, #0x00
	cmp r4, r5
	beq _08341A14
	.global _083419F2
_083419F2:
	ldr r0, _08341A2C @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _083419FE
	cmp r4, #0x00
	bne _08341A08
	.global _083419FE
_083419FE:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0x0
	bl sub_083416DC
	.global _08341A08
_08341A08:
	adds r4, #0x01
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r6, r6, r0
	cmp r4, r5
	bne _083419F2
	.global _08341A14
_08341A14:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08341A1C
_08341A1C: .4byte 0x020390A0
	.global _08341A20
_08341A20: .4byte 0x020390EC
	.global _08341A24
_08341A24: .4byte 0x020390BC
	.global _08341A28
_08341A28: .4byte 0x0203D520
	.global _08341A2C
_08341A2C: .4byte 0x0203916C
	thumb_func_start sub_08341A30
sub_08341A30:
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, _08341A88 @ =0x0202772C
	lsls r2, r2, #0x02
	adds r2, r2, r0
	ldr r4, [r2, #0x00]
	ldr r0, _08341A8C @ =0x020390AC
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x01
	movs r1, #0x07
	bl sub_08344C50
	lsls r0, r0, #0x02
	adds r4, r4, r0
	movs r0, #0xFF
	ands r6, r0
	ldr r0, _08341A90 @ =0x000001FF
	ands r0, r5
	lsls r0, r0, #0x10
	orrs r6, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r6, r0
	ldr r0, [r4, #0x00]
	bl sub_0833FC94
	cmp r0, #0x00
	beq _08341A80
	ldr r4, [r0, #0x10]
	ldr r0, _08341A94 @ =0x020243E8
	bl sub_0833FD78
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	orrs r4, r0
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl sub_0833D6A0
	.global _08341A80
_08341A80:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08341A88
_08341A88: .4byte 0x0202772C
	.global _08341A8C
_08341A8C: .4byte 0x020390AC
	.global _08341A90
_08341A90: .4byte 0x000001FF
	.global _08341A94
_08341A94: .4byte 0x020243E8
	.byte 0x10, 0xB5, 0x02, 0x9C, 0x8A, 0x42, 0x01, 0xDD, 0x20, 0x1C, 0x0B, 0xE0, 0x11, 0x1A, 0x00, 0x29
	.byte 0x07, 0xDB, 0x80, 0x20, 0xC0, 0x01, 0x40, 0x1A, 0x58, 0x43, 0x61, 0x43, 0x40, 0x18, 0x80, 0x13
	.byte 0x00, 0xE0, 0x18, 0x1C, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	thumb_func_start sub_08341AC4
sub_08341AC4:
	push {r4, r5, lr}
	movs r2, #0x00
	adds r0, #0xEC
	ldr r3, [r0, #0x00]
	ldr r5, _08341AFC @ =0xFFFFF82F
	ldr r4, _08341B00 @ =0x00002326
	.global _08341AD0
_08341AD0:
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	lsls r0, r2, #0x01
	adds r0, r0, r3
	ldrh r0, [r0, #0x00]
	negs r0, r0
	muls r0, r1
	asrs r0, r0, #0x08
	adds r0, r0, r5
	cmp r0, r4
	bls _08341B08
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x05
	bne _08341AD0
	ldr r0, _08341B04 @ =0xFFFDB610
	cmp r1, r0
	bgt _08341B0C
	movs r0, #0x04
	b _08341B0E
	.global _08341AFC
_08341AFC: .4byte 0xFFFFF82F
	.global _08341B00
_08341B00: .4byte 0x00002326
	.global _08341B04
_08341B04: .4byte 0xFFFDB610
	.global _08341B08
_08341B08:
	adds r0, r2, #0x0
	b _08341B0E
	.global _08341B0C
_08341B0C:
	movs r0, #0x00
	.global _08341B0E
_08341B0E:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_start sub_08341B14
sub_08341B14:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x028
	adds r4, r0, #0x0
	mov r8, r1
	movs r7, #0x00
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _08341C00
	ldr r0, _08341BA4 @ =0x0203E0E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341B4E
	ldr r1, _08341BA8 @ =0x00000175
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08341B4E
	adds r1, r4, #0x0
	adds r1, #0x9C
	ldr r0, [r1, #0x00]
	subs r0, #0x0A
	str r0, [r1, #0x00]
	cmp r0, #0x00
	bge _08341B4E
	str r7, [r1, #0x00]
	.global _08341B4E
_08341B4E:
	adds r0, r4, #0x0
	adds r0, #0xA2
	movs r1, #0x80
	lsls r1, r1, #0x01
	strh r1, [r0, #0x00]
	ldr r1, _08341BAC @ =0x0203D520
	mov r12, r0
	cmp r4, r1
	bne _08341B78
	subs r0, #0x06
	ldr r2, [r0, #0x00]
	cmp r2, #0x00
	bne _08341B78
	ldr r1, _08341BB0 @ =0x0203D4E8
	movs r0, #0x08
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08341B78
	mov r3, r12
	strh r2, [r3, #0x00]
	.global _08341B78
_08341B78:
	ldr r0, _08341BB4 @ =0x020390B8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341BB8
	adds r2, r4, #0x0
	adds r2, #0x3E
	movs r5, #0xE4
	adds r5, r5, r4
	mov r9, r5
	ldr r1, [r5, #0x00]
	ldrb r6, [r2, #0x00]
	lsls r0, r6, #0x01
	adds r0, r0, r1
	mov r1, r12
	ldrh r1, [r1, #0x00]
	ldrh r5, [r0, #0x00]
	adds r3, r1, #0x0
	muls r3, r5
	adds r0, r3, #0x0
	asrs r0, r0, #0x06
	b _08341BD8
	.byte 0x00, 0x00
	.global _08341BA4
_08341BA4: .4byte 0x0203E0E0
	.global _08341BA8
_08341BA8: .4byte 0x00000175
	.global _08341BAC
_08341BAC: .4byte 0x0203D520
	.global _08341BB0
_08341BB0: .4byte 0x0203D4E8
	.global _08341BB4
_08341BB4: .4byte 0x020390B8
	.global _08341BB8
_08341BB8:
	adds r2, r4, #0x0
	adds r2, #0x3E
	movs r6, #0xE4
	adds r6, r6, r4
	mov r9, r6
	ldr r1, [r6, #0x00]
	ldrb r3, [r2, #0x00]
	lsls r0, r3, #0x01
	adds r0, r0, r1
	mov r5, r12
	ldrh r5, [r5, #0x00]
	ldrh r1, [r0, #0x00]
	adds r6, r5, #0x0
	muls r6, r1
	adds r0, r6, #0x0
	asrs r0, r0, #0x08
	.global _08341BD8
_08341BD8:
	adds r7, r7, r0
	adds r6, r2, #0x0
	mov r3, r9
	ldr r0, [r4, #0x2C]
	adds r5, r4, #0x0
	adds r5, #0x40
	cmp r0, #0x00
	ble _08341C68
	ldr r0, [r3, #0x00]
	ldrb r2, [r6, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r0
	mov r3, r12
	ldrh r3, [r3, #0x00]
	ldrh r1, [r1, #0x00]
	adds r0, r3, #0x0
	muls r0, r1
	asrs r0, r0, #0x05
	adds r7, r7, r0
	b _08341C68
	.global _08341C00
_08341C00:
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	ble _08341C18
	movs r5, #0xA6
	lsls r5, r5, #0x01
	adds r1, r4, r5
	negs r0, r0
	asrs r0, r0, #0x02
	str r0, [r1, #0x00]
	adds r6, r4, #0x0
	adds r6, #0x3E
	b _08341C50
	.global _08341C18
_08341C18:
	adds r3, r4, #0x0
	adds r3, #0xA2
	ldrh r0, [r3, #0x00]
	cmp r0, #0x00
	beq _08341C56
	subs r0, #0x20
	strh r0, [r3, #0x00]
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, r1
	bls _08341C32
	strh r7, [r3, #0x00]
	.global _08341C32
_08341C32:
	adds r2, r4, #0x0
	adds r2, #0x3E
	adds r0, r4, #0x0
	adds r0, #0xE4
	ldr r1, [r0, #0x00]
	ldrb r6, [r2, #0x00]
	lsls r0, r6, #0x01
	adds r0, r0, r1
	ldrh r3, [r3, #0x00]
	ldrh r5, [r0, #0x00]
	adds r1, r3, #0x0
	muls r1, r5
	adds r0, r1, #0x0
	asrs r7, r0, #0x08
	adds r6, r2, #0x0
	.global _08341C50
_08341C50:
	adds r5, r4, #0x0
	adds r5, #0x40
	b _08341C68
	.global _08341C56
_08341C56:
	adds r1, r4, #0x0
	adds r1, #0x40
	ldrh r6, [r1, #0x00]
	lsls r0, r6, #0x02
	negs r0, r0
	asrs r7, r0, #0x10
	adds r6, r4, #0x0
	adds r6, #0x3E
	adds r5, r1, #0x0
	.global _08341C68
_08341C68:
	movs r0, #0x02
	mov r1, r8
	ands r0, r1
	cmp r0, #0x00
	beq _08341CD4
	ldrh r2, [r5, #0x00]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x01
	negs r0, r0
	asrs r0, r0, #0x08
	adds r7, r7, r0
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r1, r4, r3
	ldr r0, [r1, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x09
	adds r0, r0, r2
	str r0, [r1, #0x00]
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	ble _08341CD4
	ldr r0, _08341CB8 @ =0x020391F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08341CB0
	ldr r0, _08341CBC @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341CC0
	adds r0, r4, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341CC0
	.global _08341CB0
_08341CB0:
	adds r0, r4, #0x0
	bl sub_08342008
	b _08341CD4
	.global _08341CB8
_08341CB8: .4byte 0x020391F0
	.global _08341CBC
_08341CBC: .4byte 0x020390EC
	.global _08341CC0
_08341CC0:
	ldr r0, [r4, #0x2C]
	movs r2, #0xFA
	lsls r2, r2, #0x0A
	cmp r0, r2
	ble _08341CD4
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r1, r4, r3
	subs r0, r2, r0
	str r0, [r1, #0x00]
	.global _08341CD4
_08341CD4:
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	bge _08341CF8
	ldrh r1, [r5, #0x00]
	adds r0, r1, r7
	ldr r2, _08341CF4 @ =0x000032C8
	cmp r0, r2
	ble _08341CE6
	subs r7, r2, r1
	.global _08341CE6
_08341CE6:
	adds r0, r1, r7
	cmp r0, #0x00
	bge _08341CEE
	negs r7, r1
	.global _08341CEE
_08341CEE:
	adds r0, r1, r7
	b _08341CFA
	.byte 0x00, 0x00
	.global _08341CF4
_08341CF4: .4byte 0x000032C8
	.global _08341CF8
_08341CF8:
	movs r0, #0x00
	.global _08341CFA
_08341CFA:
	strh r0, [r5, #0x00]
	ldr r1, [r4, #0x2C]
	cmp r1, #0x00
	bgt _08341D0E
	adds r0, r4, #0x0
	bl sub_08341AC4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	b _08341D10
	.global _08341D0E
_08341D0E:
	movs r3, #0x00
	.global _08341D10
_08341D10:
	movs r0, #0x9E
	lsls r0, r0, #0x01
	adds r0, r0, r4
	mov r8, r0
	adds r0, r4, #0x0
	adds r0, #0xE8
	ldr r1, [r0, #0x00]
	ldrb r2, [r6, #0x00]
	lsls r0, r2, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	negs r0, r0
	muls r0, r7
	negs r0, r0
	asrs r0, r0, #0x08
	mov r1, r8
	str r0, [r1, #0x00]
	ldr r2, [r4, #0x2C]
	cmp r2, #0x00
	bgt _08341D50
	adds r0, r4, #0x0
	adds r0, #0xEC
	ldr r1, [r0, #0x00]
	lsls r0, r3, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	negs r0, r0
	muls r0, r2
	asrs r0, r0, #0x08
	strh r0, [r5, #0x00]
	strb r3, [r6, #0x00]
	b _08341D56
	.global _08341D50
_08341D50:
	movs r0, #0x00
	strb r0, [r6, #0x00]
	strh r0, [r5, #0x00]
	.global _08341D56
_08341D56:
	add sp, #0x028
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start sub_08341D64
sub_08341D64:
	push {r4, r5, lr}
	ldrh r1, [r0, #0x34]
	lsrs r2, r1, #0x0B
	negs r2, r2
	movs r1, #0x1F
	ands r2, r1
	lsls r2, r2, #0x03
	ldr r3, _08341D9C @ =0x0200C3E8
	lsls r1, r2, #0x01
	adds r1, r1, r3
	movs r5, #0x00
	ldsh r4, [r1, r5]
	adds r2, #0x40
	lsls r2, r2, #0x01
	adds r2, r2, r3
	movs r1, #0x00
	ldsh r3, [r2, r1]
	ldr r1, [r0, #0x0C]
	ldr r2, [r0, #0x14]
	muls r1, r4
	muls r2, r3
	adds r1, r1, r2
	asrs r1, r1, #0x08
	str r1, [r0, #0x2C]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08341D9C
_08341D9C: .4byte 0x0200C3E8
	thumb_func_start sub_08341DA0
sub_08341DA0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	mov r12, r0
	ldrh r0, [r0, #0x34]
	lsrs r2, r0, #0x08
	ldr r0, _08341EBC @ =0x0200C3E8
	lsls r1, r2, #0x01
	adds r1, r1, r0
	movs r4, #0x00
	ldsh r3, [r1, r4]
	mov r9, r3
	adds r1, r2, #0x0
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r0
	movs r2, #0x00
	ldsh r5, [r1, r2]
	mov r8, r5
	movs r7, #0x00
	ldr r3, _08341EC0 @ =0x020277B4
	mov r10, r3
	.global _08341DD2
_08341DD2:
	lsls r4, r7, #0x02
	mov r5, r10
	adds r5, #0x04
	mov r10, r5
	subs r5, #0x04
	ldm r5!, {r6}
	ldr r1, _08341EC4 @ =0x020277C4
	adds r0, r4, r1
	ldr r5, [r0, #0x00]
	mov r3, r12
	adds r3, #0xA4
	adds r3, r3, r4
	mov r0, r8
	muls r0, r6
	mov r1, r9
	muls r1, r5
	subs r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	mov r2, r12
	adds r2, #0xB4
	adds r2, r2, r4
	mov r0, r9
	muls r0, r6
	mov r1, r8
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r2, #0x00]
	ldr r0, [r3, #0x00]
	mov r4, r12
	ldr r1, [r4, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	ldr r0, [r2, #0x00]
	ldr r1, [r4, #0x08]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r7, #0x01
	cmp r7, #0x04
	bne _08341DD2
	movs r5, #0x3C
	ldsh r0, [r4, r5]
	ldrh r1, [r4, #0x34]
	adds r0, r1, r0
	asrs r2, r0, #0x08
	movs r0, #0xFF
	ands r2, r0
	lsls r0, r2, #0x01
	ldr r3, _08341EBC @ =0x0200C3E8
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r4, [r0, r5]
	mov r9, r4
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r2, #0x00
	ldsh r1, [r0, r2]
	mov r8, r1
	movs r7, #0x00
	movs r3, #0xC4
	add r3, r12
	mov r10, r3
	mov r4, r12
	adds r4, #0xD4
	ldr r5, _08341EC0 @ =0x020277B4
	str r5, [sp, #0x000]
	.global _08341E5C
_08341E5C:
	lsls r2, r7, #0x02
	ldr r0, [sp, #0x000]
	ldm r0!, {r6}
	str r0, [sp, #0x000]
	ldr r1, _08341EC4 @ =0x020277C4
	adds r0, r2, r1
	ldr r5, [r0, #0x00]
	mov r0, r10
	adds r3, r0, r2
	mov r0, r8
	muls r0, r6
	mov r1, r9
	muls r1, r5
	subs r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	adds r2, r4, r2
	mov r0, r9
	muls r0, r6
	mov r1, r8
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r2, #0x00]
	mov r5, r12
	ldr r1, [r5, #0x00]
	ldr r0, [r5, #0x0C]
	adds r1, r1, r0
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	ldr r1, [r5, #0x08]
	ldr r0, [r5, #0x14]
	adds r1, r1, r0
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r7, #0x01
	cmp r7, #0x04
	bne _08341E5C
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08341EBC
_08341EBC: .4byte 0x0200C3E8
	.global _08341EC0
_08341EC0: .4byte 0x020277B4
	.global _08341EC4
_08341EC4: .4byte 0x020277C4
	thumb_func_start sub_08341EC8
sub_08341EC8:
	adds r2, r0, #0x0
	ldr r0, _08341EF4 @ =0x0203B704
	ldrh r1, [r0, #0x00]
	movs r3, #0x82
	lsls r3, r3, #0x01
	adds r0, r2, r3
	strh r1, [r0, #0x00]
	ldr r0, _08341EF8 @ =0x0203B6D0
	ldrh r0, [r0, #0x00]
	adds r3, #0x02
	adds r1, r2, r3
	strh r0, [r1, #0x00]
	ldr r0, _08341EFC @ =0x0203B6D4
	ldrh r1, [r0, #0x00]
	adds r3, #0x02
	adds r0, r2, r3
	strh r1, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0x7D
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bx lr
	.global _08341EF4
_08341EF4: .4byte 0x0203B704
	.global _08341EF8
_08341EF8: .4byte 0x0203B6D0
	.global _08341EFC
_08341EFC: .4byte 0x0203B6D4
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x10, 0xB5, 0x04, 0x1C, 0x88, 0x30, 0x00, 0x22
	.byte 0x02, 0x60, 0x21, 0x1C, 0x7C, 0x31, 0x02, 0x20, 0x08, 0x70, 0x04, 0x31, 0x01, 0x20, 0x08, 0x60
	.byte 0xB0, 0x21, 0x49, 0x00, 0x60, 0x18, 0x02, 0x80, 0x20, 0x1C, 0xA2, 0x30, 0x02, 0x80, 0x20, 0x1C
	.byte 0xFF, 0xF7, 0xE8, 0xFF, 0x08, 0x48, 0x84, 0x42, 0x0B, 0xD1, 0x08, 0x48, 0x00, 0x78, 0x00, 0x28
	.byte 0x07, 0xD1, 0x07, 0x49, 0x08, 0x68, 0x05, 0x30, 0x08, 0x60, 0x63, 0x28, 0x01, 0xDD, 0x63, 0x20
	.byte 0x08, 0x60, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x20, 0xD5, 0x03, 0x02, 0x6C, 0x91, 0x03, 0x02
	.byte 0xCC, 0xB6, 0x03, 0x02, 0x10, 0xB5, 0x84, 0x46, 0x22, 0x4A, 0x01, 0x8F, 0x48, 0x00, 0x63, 0x46
	.byte 0x1B, 0x8F, 0xC0, 0x18, 0xC0, 0x00, 0x11, 0x68, 0x0B, 0x18, 0x18, 0x68, 0x99, 0x68, 0x40, 0x18
	.byte 0xC0, 0x03, 0x61, 0x46, 0x08, 0x60, 0x58, 0x68, 0xD9, 0x68, 0x40, 0x18, 0xC0, 0x03, 0x61, 0x46
	.byte 0x88, 0x60, 0x14, 0x1C, 0x1B, 0x8A, 0x63, 0x46, 0xD8, 0x8E, 0x00, 0x22, 0x98, 0x86, 0x9A, 0x87
	.byte 0x9E, 0x20, 0x40, 0x00, 0x60, 0x44, 0x02, 0x60, 0xA4, 0x20, 0x40, 0x00, 0x60, 0x44, 0x02, 0x60
	.byte 0xDA, 0x60, 0x5A, 0x61, 0x96, 0x21, 0x49, 0x00, 0x61, 0x44, 0x98, 0x8E, 0x08, 0x60, 0x94, 0x21
	.byte 0x49, 0x00, 0x61, 0x44, 0x98, 0x8E, 0x08, 0x60, 0x98, 0x20, 0x40, 0x00, 0x60, 0x44, 0x02, 0x60
	.byte 0x61, 0x46, 0x4E, 0x31, 0x01, 0x20, 0x08, 0x70, 0x1A, 0x8F, 0x50, 0x00, 0x80, 0x18, 0xC0, 0x00
	.byte 0x21, 0x68, 0x0B, 0x18, 0x1B, 0x8A, 0x01, 0x2B, 0x06, 0xD1, 0x61, 0x46, 0x4D, 0x31, 0x00, 0x20
	.byte 0x08, 0x70, 0x05, 0xE0, 0x60, 0xB8, 0x03, 0x02, 0x51, 0x1C, 0x60, 0x46, 0x4D, 0x30, 0x01, 0x70
	.byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	thumb_func_start sub_08342008
sub_08342008:
	push {r4, lr}
	adds r3, r0, #0x0
	movs r1, #0x00
	str r1, [r3, #0x0C]
	str r1, [r3, #0x14]
	movs r2, #0x00
	strh r1, [r3, #0x3C]
	movs r4, #0xA4
	lsls r4, r4, #0x01
	adds r0, r3, r4
	str r1, [r0, #0x00]
	adds r0, r3, #0x0
	adds r0, #0x40
	strh r1, [r0, #0x00]
	subs r0, #0x02
	strb r2, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x70, 0xB5, 0x03, 0x1C, 0x98, 0x8E, 0x01, 0x0A, 0x96, 0x20, 0x40, 0x00, 0x1E, 0x18
	.byte 0x30, 0x68, 0x02, 0x12, 0x0D, 0x1C, 0x30, 0x3D, 0x0C, 0x1C, 0x30, 0x34, 0x8A, 0x42, 0x08, 0xDD
	.byte 0x08, 0x1C, 0x80, 0x30, 0x82, 0x42, 0x04, 0xDA, 0xA2, 0x42, 0x09, 0xDD, 0x20, 0x02, 0x30, 0x60
	.byte 0x06, 0xE0, 0xAA, 0x42, 0x04, 0xDA, 0x96, 0x20, 0x40, 0x00, 0x19, 0x18, 0x28, 0x02, 0x08, 0x60
	.byte 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47
	thumb_func_start sub_08342074
sub_08342074:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r12, r0
	ldrh r1, [r0, #0x34]
	lsrs r0, r1, #0x0A
	lsls r0, r0, #0x10
	mov r9, r0
	lsrs r2, r0, #0x0E
	ldr r7, _08342124 @ =0x0200C3E8
	lsls r0, r2, #0x01
	adds r0, r0, r7
	movs r1, #0x00
	ldsh r3, [r0, r1]
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r7
	movs r1, #0x00
	ldsh r2, [r0, r1]
	ldr r1, _08342128 @ =0xFFFFFF00
	adds r0, r3, #0x0
	muls r0, r1
	negs r0, r0
	asrs r5, r0, #0x08
	adds r0, r2, #0x0
	muls r0, r1
	asrs r4, r0, #0x08
	movs r6, #0x96
	lsls r6, r6, #0x01
	add r6, r12
	ldr r0, [r6, #0x00]
	asrs r2, r0, #0x0A
	movs r0, #0x3F
	ands r2, r0
	lsls r2, r2, #0x02
	lsls r0, r2, #0x01
	adds r3, r0, r7
	movs r0, #0x00
	ldsh r3, [r3, r0]
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r2, r0, r7
	movs r0, #0x00
	ldsh r2, [r2, r0]
	adds r0, r3, #0x0
	muls r0, r1
	negs r0, r0
	asrs r0, r0, #0x08
	mov r8, r0
	adds r0, r2, #0x0
	muls r0, r1
	asrs r3, r0, #0x08
	mov r0, r8
	muls r0, r5
	adds r1, r4, #0x0
	muls r1, r3
	adds r0, r0, r1
	asrs r0, r0, #0x08
	cmp r0, #0x8D
	bgt _08342146
	mov r1, r9
	lsrs r2, r1, #0x0E
	lsls r1, r2, #0x01
	adds r1, r1, r7
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r7
	movs r2, #0x00
	ldsh r5, [r0, r2]
	movs r0, #0x00
	ldsh r4, [r1, r0]
	mov r0, r8
	muls r0, r5
	adds r1, r4, #0x0
	muls r1, r3
	adds r0, r0, r1
	cmp r0, #0x00
	bge _08342130
	mov r1, r12
	ldrh r1, [r1, #0x34]
	ldr r2, _0834212C @ =0xFFFFD800
	adds r0, r1, r2
	b _0834213A
	.byte 0x00, 0x00
	.global _08342124
_08342124: .4byte 0x0200C3E8
	.global _08342128
_08342128: .4byte 0xFFFFFF00
	.global _0834212C
_0834212C: .4byte 0xFFFFD800
	.global _08342130
_08342130:
	mov r3, r12
	ldrh r3, [r3, #0x34]
	movs r1, #0xA0
	lsls r1, r1, #0x06
	adds r0, r3, r1
	.global _0834213A
_0834213A:
	str r0, [r6, #0x00]
	movs r1, #0x96
	lsls r1, r1, #0x01
	add r1, r12
	ldrh r0, [r1, #0x00]
	str r0, [r1, #0x00]
	.global _08342146
_08342146:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
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
	thumb_func_start sub_08342868
sub_08342868:
	push {lr}
	bl sub_0833FF44
	adds r1, r0, #0x0
	cmp r1, #0x00
	beq _08342884
	movs r0, #0xE1
	lsls r0, r0, #0x02
	str r0, [r1, #0x18]
	ldr r0, _08342888 @ =0x02009D5D
	str r0, [r1, #0x0C]
	adds r0, r1, #0x0
	bl sub_0833FF94
	.global _08342884
_08342884:
	pop {r0}
	bx r0
	.global _08342888
_08342888: .4byte 0x02009D5D
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x18, 0x48, 0x00, 0x78, 0x00, 0x28, 0x29, 0xD1, 0x17, 0x48, 0x00, 0x78
	.byte 0x00, 0x28, 0x07, 0xD1, 0x04, 0x20, 0xF9, 0xF7, 0x77, 0xFA, 0x0A, 0x21, 0x03, 0x22, 0x01, 0x23
	.byte 0xFC, 0xF7, 0x2E, 0xFB, 0xA0, 0x69, 0x01, 0x38, 0xA0, 0x61, 0x00, 0x28, 0x18, 0xD1, 0x20, 0x1C
	.byte 0xFD, 0xF7, 0x74, 0xFB, 0x20, 0x1C, 0xFD, 0xF7, 0x5F, 0xFB, 0x0D, 0x48, 0x00, 0x78, 0x04, 0x28
	.byte 0x0B, 0xD0, 0x0A, 0x20, 0x00, 0x21, 0xFA, 0xF7, 0xD9, 0xFC, 0xF7, 0xF7, 0x1F, 0xF9, 0x80, 0x22
	.byte 0xD2, 0x04, 0x11, 0x88, 0x07, 0x48, 0x08, 0x40, 0x10, 0x80, 0x07, 0x49, 0x02, 0x20, 0x08, 0x70
	.byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xC4, 0x92, 0x03, 0x02, 0xEC, 0x90, 0x03, 0x02
	.byte 0x6C, 0x91, 0x03, 0x02, 0xFF, 0xEF, 0x00, 0x00, 0xF0, 0x91, 0x03, 0x02
	thumb_func_start sub_08342908
sub_08342908:
	push {r4, lr}
	ldr r4, _0834293C @ =0x020391F0
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _08342934
	bl sub_0833FF44
	adds r1, r0, #0x0
	cmp r1, #0x00
	beq _08342930
	ldr r0, _08342940 @ =0x020390A8
	ldrb r0, [r0, #0x00]
	str r0, [r1, #0x1C]
	movs r0, #0x64
	str r0, [r1, #0x18]
	ldr r0, _08342944 @ =0x02009E0D
	str r0, [r1, #0x0C]
	adds r0, r1, #0x0
	bl sub_0833FF94
	.global _08342930
_08342930:
	movs r0, #0x01
	strb r0, [r4, #0x00]
	.global _08342934
_08342934:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0834293C
_0834293C: .4byte 0x020391F0
	.global _08342940
_08342940: .4byte 0x020390A8
	.global _08342944
_08342944: .4byte 0x02009E0D
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x15, 0x49, 0x01, 0x20, 0x08, 0x70, 0x15, 0x48, 0x00, 0x78, 0x00, 0x28
	.byte 0x20, 0xD1, 0x05, 0x20, 0xF9, 0xF7, 0x1A, 0xFA, 0x4C, 0x21, 0x18, 0x22, 0x00, 0xF0, 0xF0, 0xFB
	.byte 0xA0, 0x69, 0x01, 0x38, 0xA0, 0x61, 0x00, 0x28, 0x14, 0xD1, 0x20, 0x1C, 0xFD, 0xF7, 0x18, 0xFB
	.byte 0x20, 0x1C, 0xFD, 0xF7, 0x03, 0xFB, 0x0A, 0x20, 0x00, 0x21, 0xFA, 0xF7, 0x81, 0xFC, 0xF7, 0xF7
	.byte 0xC7, 0xF8, 0x80, 0x22, 0xD2, 0x04, 0x11, 0x88, 0x06, 0x48, 0x08, 0x40, 0x10, 0x80, 0x06, 0x49
	.byte 0x02, 0x20, 0x08, 0x70, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x00, 0xE0, 0x03, 0x02
	.byte 0xC4, 0x92, 0x03, 0x02, 0xFF, 0xEF, 0x00, 0x00, 0xF0, 0x91, 0x03, 0x02, 0x70, 0x47, 0x00, 0x00
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xA0, 0x69, 0x01, 0x30, 0xA0, 0x61, 0x30, 0x28, 0x05, 0xD1, 0x20, 0x1C
	.byte 0xFD, 0xF7, 0xEE, 0xFA, 0x20, 0x1C, 0xFD, 0xF7, 0xD9, 0xFA, 0x04, 0x48, 0x08, 0x21, 0x01, 0x22
	.byte 0xFC, 0xF7, 0x56, 0xFA, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x18, 0xD1, 0x00, 0x02
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xA0, 0x69, 0x01, 0x30, 0xA0, 0x61, 0x4E, 0x28, 0x08, 0xD1, 0x20, 0x1C
	.byte 0xFD, 0xF7, 0xD6, 0xFA, 0x20, 0x1C, 0xFD, 0xF7, 0xC1, 0xFA, 0x03, 0x49, 0x01, 0x20, 0x08, 0x70
	.byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xD4, 0x90, 0x03, 0x02, 0x10, 0xB5, 0x04, 0x1C
	.byte 0x1B, 0x48, 0x00, 0x78, 0x00, 0x28, 0x2F, 0xD1, 0xA2, 0x69, 0x2D, 0x2A, 0x1C, 0xDD, 0x19, 0x49
	.byte 0x08, 0x78, 0x09, 0x28, 0x01, 0xD1, 0x06, 0x20, 0x08, 0x70, 0x08, 0x78, 0x0D, 0x28, 0x01, 0xD1
	.byte 0x0C, 0x20, 0x08, 0x70, 0x08, 0x78, 0x0E, 0x28, 0x01, 0xD1, 0x02, 0x20, 0x08, 0x70, 0x08, 0x78
	.byte 0x0F, 0x28, 0x01, 0xD1, 0x10, 0x20, 0x08, 0x70, 0x08, 0x78, 0x11, 0x28, 0x01, 0xD1, 0x05, 0x20
	.byte 0x08, 0x70, 0x0D, 0x49, 0x01, 0x20, 0x08, 0x70, 0x50, 0x1C, 0xA0, 0x61, 0x7A, 0x28, 0x05, 0xD1
	.byte 0x20, 0x1C, 0xFD, 0xF7, 0x9D, 0xFA, 0x20, 0x1C, 0xFD, 0xF7, 0x88, 0xFA, 0x06, 0x48, 0x00, 0x78
	.byte 0x00, 0x28, 0x01, 0xD1, 0xF7, 0xF7, 0x4C, 0xF8, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0xC4, 0x92, 0x03, 0x02, 0x6C, 0x91, 0x03, 0x02, 0xD4, 0x90, 0x03, 0x02
	thumb_func_start sub_08342A94
sub_08342A94:
	push {r4, lr}
	ldr r1, _08342AF4 @ =0x0203916C
	ldrb r0, [r1, #0x00]
	cmp r0, #0x09
	bne _08342AA2
	movs r0, #0x06
	strb r0, [r1, #0x00]
	.global _08342AA2
_08342AA2:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x0D
	bne _08342AAC
	movs r0, #0x0C
	strb r0, [r1, #0x00]
	.global _08342AAC
_08342AAC:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x0E
	bne _08342AB6
	movs r0, #0x02
	strb r0, [r1, #0x00]
	.global _08342AB6
_08342AB6:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x0F
	bne _08342AC0
	movs r0, #0x10
	strb r0, [r1, #0x00]
	.global _08342AC0
_08342AC0:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x11
	bne _08342ACA
	movs r0, #0x05
	strb r0, [r1, #0x00]
	.global _08342ACA
_08342ACA:
	ldr r1, _08342AF8 @ =0x020390D4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bl sub_0833FF44
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _08342AEC
	movs r0, #0x00
	str r0, [r4, #0x18]
	ldr r0, _08342AFC @ =0x02009F39
	str r0, [r4, #0x0C]
	adds r0, r4, #0x0
	bl sub_0833FF94
	ldr r0, _08342B00 @ =0x0203DE24
	str r4, [r0, #0x00]
	.global _08342AEC
_08342AEC:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08342AF4
_08342AF4: .4byte 0x0203916C
	.global _08342AF8
_08342AF8: .4byte 0x020390D4
	.global _08342AFC
_08342AFC: .4byte 0x02009F39
	.global _08342B00
_08342B00: .4byte 0x0203DE24
	thumb_func_start sub_08342B04
sub_08342B04:
	push {r4, lr}
	ldr r0, _08342B40 @ =0x020390D4
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r0, _08342B44 @ =0x020391F0
	strb r1, [r0, #0x00]
	ldr r0, _08342B48 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _08342B3A
	bl sub_0833FF44
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _08342B3A
	movs r0, #0x00
	str r0, [r4, #0x18]
	ldr r0, _08342B4C @ =0x02009F69
	str r0, [r4, #0x0C]
	adds r0, r4, #0x0
	bl sub_0833FF94
	ldr r0, _08342B50 @ =0x0203DE24
	str r4, [r0, #0x00]
	.global _08342B3A
_08342B3A:
	pop {r4}
	pop {r0}
	bx r0
	.global _08342B40
_08342B40: .4byte 0x020390D4
	.global _08342B44
_08342B44: .4byte 0x020391F0
	.global _08342B48
_08342B48: .4byte 0x0203916C
	.global _08342B4C
_08342B4C: .4byte 0x02009F69
	.global _08342B50
_08342B50: .4byte 0x0203DE24
	.byte 0x10, 0xB5, 0x8A, 0xB0, 0x04, 0x1C, 0x06, 0x20, 0xF9, 0xF7, 0x1A, 0xF9, 0x09, 0x21, 0x05, 0x22
	.byte 0xFC, 0xF7, 0xD2, 0xF9, 0x0C, 0x48, 0x0D, 0x21, 0x05, 0x22, 0xFC, 0xF7, 0xCD, 0xF9, 0xA0, 0x69
	.byte 0x01, 0x38, 0xA0, 0x61, 0x00, 0x28, 0x0A, 0xD1, 0x08, 0x48, 0x09, 0x21, 0x05, 0x22, 0xFC, 0xF7
	.byte 0xC3, 0xF9, 0x20, 0x1C, 0xFD, 0xF7, 0x0E, 0xFA, 0x20, 0x1C, 0xFD, 0xF7, 0xF9, 0xF9, 0x0A, 0xB0
	.byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x30, 0xDE, 0x03, 0x02, 0x18, 0xD1, 0x00, 0x02
	thumb_func_start sub_08342BA4
sub_08342BA4:
	push {r4, r5, r6, lr}
	mov r6, r9
	mov r5, r8
	push {r5, r6}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	mov r8, r2
	ldr r4, _08342C34 @ =0x0203DE30
	movs r0, #0x00
	mov r9, r0
	movs r0, #0x2E
	strb r0, [r4, #0x02]
	strb r0, [r4, #0x05]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl sub_08344BB8
	adds r0, #0x30
	strb r0, [r4, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl sub_08344C50
	adds r0, #0x30
	strb r0, [r4, #0x01]
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl sub_08344BB8
	adds r0, #0x30
	strb r0, [r4, #0x03]
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl sub_08344C50
	adds r0, #0x30
	strb r0, [r4, #0x04]
	mov r0, r8
	movs r1, #0x64
	bl sub_08344BB8
	adds r0, #0x30
	strb r0, [r4, #0x06]
	mov r0, r8
	movs r1, #0x64
	bl sub_08344C50
	movs r1, #0x0A
	bl sub_08344BB8
	adds r0, #0x30
	strb r0, [r4, #0x07]
	mov r0, r9
	strb r0, [r4, #0x08]
	bl sub_0833FF44
	adds r1, r0, #0x0
	cmp r1, #0x00
	beq _08342C28
	movs r0, #0x5A
	str r0, [r1, #0x18]
	ldr r0, _08342C38 @ =0x0200A0D5
	str r0, [r1, #0x0C]
	adds r0, r1, #0x0
	bl sub_0833FF94
	.global _08342C28
_08342C28:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _08342C34
_08342C34: .4byte 0x0203DE30
	.global _08342C38
_08342C38: .4byte 0x0200A0D5
	.byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x98, 0xB0, 0x07, 0x1C, 0x6C, 0x46, 0x2E, 0x48, 0x05, 0x68
	.byte 0x28, 0x1C, 0x0A, 0x21, 0x01, 0xF0, 0xB2, 0xFF, 0x0A, 0x21, 0x01, 0xF0, 0xFB, 0xFF, 0x30, 0x30
	.byte 0x00, 0x21, 0x88, 0x46, 0x20, 0x70, 0x6C, 0x46, 0x28, 0x1C, 0x0A, 0x21, 0x01, 0xF0, 0xF2, 0xFF
	.byte 0x30, 0x30, 0x60, 0x70, 0x68, 0x46, 0x3A, 0x26, 0x86, 0x70, 0x6C, 0x46, 0x23, 0x48, 0x05, 0x68
	.byte 0x28, 0x1C, 0x0A, 0x21, 0x01, 0xF0, 0x9A, 0xFF, 0x0A, 0x21, 0x01, 0xF0, 0xE3, 0xFF, 0x30, 0x30
	.byte 0xE0, 0x70, 0x6C, 0x46, 0x28, 0x1C, 0x0A, 0x21, 0x01, 0xF0, 0xDC, 0xFF, 0x30, 0x30, 0x20, 0x71
	.byte 0x68, 0x46, 0x46, 0x71, 0x6D, 0x46, 0x1A, 0x48, 0x04, 0x68, 0x20, 0x1C, 0x64, 0x21, 0x01, 0xF0
	.byte 0x85, 0xFF, 0x0A, 0x21, 0x01, 0xF0, 0xCE, 0xFF, 0x30, 0x30, 0xA8, 0x71, 0x6D, 0x46, 0x20, 0x1C
	.byte 0x0A, 0x21, 0x01, 0xF0, 0x7B, 0xFF, 0x0A, 0x21, 0x01, 0xF0, 0xC4, 0xFF, 0x30, 0x30, 0xE8, 0x71
	.byte 0x6D, 0x46, 0x20, 0x1C, 0x0A, 0x21, 0x01, 0xF0, 0xBD, 0xFF, 0x30, 0x30, 0x28, 0x72, 0x68, 0x46
	.byte 0x41, 0x46, 0x41, 0x72, 0xB8, 0x69, 0x02, 0x38, 0xB8, 0x61, 0x00, 0x28, 0x05, 0xD1, 0x38, 0x1C
	.byte 0xFD, 0xF7, 0x5C, 0xF9, 0x38, 0x1C, 0xFD, 0xF7, 0x47, 0xF9, 0x18, 0xB0, 0x08, 0xBC, 0x98, 0x46
	.byte 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x28, 0xDE, 0x03, 0x02, 0x3C, 0xDE, 0x03, 0x02
	.byte 0x20, 0xDE, 0x03, 0x02
	thumb_func_start sub_08342D10
sub_08342D10:
	push {lr}
	bl sub_0833FF44
	adds r1, r0, #0x0
	cmp r1, #0x00
	beq _08342D42
	movs r0, #0x40
	str r0, [r1, #0x18]
	ldr r0, _08342D48 @ =0x0200A1BD
	str r0, [r1, #0x0C]
	adds r0, r1, #0x0
	bl sub_0833FF94
	ldr r1, _08342D4C @ =0x0203DE28
	ldr r0, _08342D50 @ =0x0203B6C8
	ldrh r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _08342D54 @ =0x0203DE3C
	ldr r0, _08342D58 @ =0x0203B6A8
	ldrh r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _08342D5C @ =0x0203DE20
	ldr r0, _08342D60 @ =0x0203B858
	ldrh r0, [r0, #0x00]
	str r0, [r1, #0x00]
	.global _08342D42
_08342D42:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08342D48
_08342D48: .4byte 0x0200A1BD
	.global _08342D4C
_08342D4C: .4byte 0x0203DE28
	.global _08342D50
_08342D50: .4byte 0x0203B6C8
	.global _08342D54
_08342D54: .4byte 0x0203DE3C
	.global _08342D58
_08342D58: .4byte 0x0203B6A8
	.global _08342D5C
_08342D5C: .4byte 0x0203DE20
	.global _08342D60
_08342D60: .4byte 0x0203B858
	thumb_func_start sub_08342D64
sub_08342D64:
	push {r4, lr}
	movs r4, #0x00
	.global _08342D68
_08342D68:
	bl sub_0833FF44
	adds r1, r0, #0x0
	cmp r1, #0x00
	beq _08342D90
	movs r0, #0x60
	str r0, [r1, #0x18]
	lsls r0, r4, #0x05
	str r0, [r1, #0x1C]
	ldr r0, _08342D9C @ =0x020277F4
	adds r0, r4, r0
	ldrb r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r0, #0x28
	str r0, [r1, #0x04]
	ldr r0, _08342DA0 @ =0x0200A325
	str r0, [r1, #0x0C]
	adds r0, r1, #0x0
	bl sub_0833FF94
	.global _08342D90
_08342D90:
	adds r4, #0x01
	cmp r4, #0x0C
	bne _08342D68
	pop {r4}
	pop {r0}
	bx r0
	.global _08342D9C
_08342D9C: .4byte 0x020277F4
	.global _08342DA0
_08342DA0: .4byte 0x0200A325
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xA0, 0x69, 0x01, 0x38, 0xA0, 0x61, 0x00, 0x28, 0x05, 0xD1, 0x20, 0x1C
	.byte 0xFD, 0xF7, 0xF8, 0xF8, 0x20, 0x1C, 0xFD, 0xF7, 0xE3, 0xF8, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
