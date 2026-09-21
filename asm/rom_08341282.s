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
