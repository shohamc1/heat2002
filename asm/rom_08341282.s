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
	movs r0, #0x01
	b _083414A6
	movs r0, #0x04
	b _083414A6
	movs r0, #0x05
	b _083414A6
	movs r0, #0x28
	b _083414A6
	movs r0, #0x28
	b _083414A6
	movs r0, #0x0F
	b _083414A6
	movs r0, #0x0F
	b _083414A6
	movs r0, #0x55
	b _083414A6
	movs r0, #0x12
	b _083414A6
	movs r0, #0x05
	b _083414A6
	movs r0, #0x14
	b _083414A6
	.global _083414A4
_083414A4:
	movs r0, #0x00
_083414A6:
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
