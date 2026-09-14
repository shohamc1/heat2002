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
	.byte 0x70, 0xB5, 0x03, 0x1C, 0x98, 0x8E, 0x01, 0x0A, 0x96, 0x20, 0x40, 0x00, 0x1E, 0x18
	.byte 0x30, 0x68, 0x02, 0x12, 0x0D, 0x1C, 0x30, 0x3D, 0x0C, 0x1C, 0x30, 0x34, 0x8A, 0x42, 0x08, 0xDD
	.byte 0x08, 0x1C, 0x80, 0x30, 0x82, 0x42, 0x04, 0xDA, 0xA2, 0x42, 0x09, 0xDD, 0x20, 0x02, 0x30, 0x60
	.byte 0x06, 0xE0, 0xAA, 0x42, 0x04, 0xDA, 0x96, 0x20, 0x40, 0x00, 0x19, 0x18, 0x28, 0x02, 0x08, 0x60
	.byte 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47
	thumb_func_start sub_0800A628
sub_0800A628:
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
	ldr r7, _0800A6D8 @ =0x0801CD08
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
	ldr r1, _0800A6DC @ =0xFFFFFF00
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
	bgt _0800A6FA
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
	bge _0800A6E4
	mov r1, r12
	ldrh r1, [r1, #0x34]
	ldr r2, _0800A6E0 @ =0xFFFFD800
	adds r0, r1, r2
	b _0800A6EE
	.byte 0x00, 0x00
	.global _0800A6D8
_0800A6D8: .4byte 0x0801CD08
	.global _0800A6DC
_0800A6DC: .4byte 0xFFFFFF00
	.global _0800A6E0
_0800A6E0: .4byte 0xFFFFD800
	.global _0800A6E4
_0800A6E4:
	mov r3, r12
	ldrh r3, [r3, #0x34]
	movs r1, #0xA0
	lsls r1, r1, #0x06
	adds r0, r3, r1
	.global _0800A6EE
_0800A6EE:
	str r0, [r6, #0x00]
	movs r1, #0x96
	lsls r1, r1, #0x01
	add r1, r12
	ldrh r0, [r1, #0x00]
	str r0, [r1, #0x00]
	.global _0800A6FA
_0800A6FA:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start sub_0800A708
sub_0800A708:
	push {r4, r5, lr}
	adds r3, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	adds r1, r3, #0x0
	adds r1, #0x84
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _0800A770 @ =0x0202A550
	cmp r3, r0
	bne _0800A778
	ldr r0, [r3, #0x2C]
	cmp r0, #0x00
	ble _0800A778
	movs r0, #0x30
	ands r0, r4
	cmp r0, #0x00
	bne _0800A740
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
	.global _0800A740
_0800A740:
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0x00
	beq _0800A756
	movs r5, #0x96
	lsls r5, r5, #0x01
	adds r1, r3, r5
	ldrh r2, [r3, #0x34]
	ldr r5, _0800A774 @ =0xFFFFEC00
	adds r0, r2, r5
	str r0, [r1, #0x00]
	.global _0800A756
_0800A756:
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0x00
	beq _0800A804
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldrh r3, [r3, #0x34]
	movs r2, #0xA0
	lsls r2, r2, #0x05
	adds r0, r3, r2
	str r0, [r1, #0x00]
	b _0800A804
	.global _0800A770
_0800A770: .4byte 0x0202A550
	.global _0800A774
_0800A774: .4byte 0xFFFFEC00
	.global _0800A778
_0800A778:
	movs r0, #0x30
	ands r0, r4
	cmp r0, #0x00
	beq _0800A794
	movs r5, #0x88
	lsls r5, r5, #0x01
	adds r1, r3, r5
	ldrb r2, [r1, #0x00]
	movs r0, #0x00
	ldsb r0, [r1, r0]
	cmp r0, #0x00
	blt _0800A7A4
	adds r0, r2, #0x1
	b _0800A7A2
	.global _0800A794
_0800A794:
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0800A7A4
	subs r0, #0x01
	.global _0800A7A2
_0800A7A2:
	strb r0, [r1, #0x00]
	.global _0800A7A4
_0800A7A4:
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
	bge _0800A7C4
	movs r1, #0x00
	.global _0800A7C4
_0800A7C4:
	movs r0, #0xFF
	subs r1, r0, r1
	lsls r0, r1, #0x01
	adds r2, r2, r0
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0x00
	beq _0800A7E8
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldr r0, [r1, #0x00]
	subs r0, r0, r2
	str r0, [r1, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x84
	movs r0, #0x00
	b _0800A802
	.global _0800A7E8
_0800A7E8:
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0x00
	beq _0800A804
	movs r5, #0x96
	lsls r5, r5, #0x01
	adds r1, r3, r5
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x84
	movs r0, #0x02
	.global _0800A802
_0800A802:
	strb r0, [r1, #0x00]
	.global _0800A804
_0800A804:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start sub_0800A80C
sub_0800A80C:
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
	bl sub_08007C44
	adds r1, r5, #0x0
	adds r1, #0x55
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0800A84C
	subs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0800A84C
_0800A84C:
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0x0
	bl sub_0800A708
	adds r0, r5, #0x0
	bl sub_0800A2D4
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl sub_0800A084
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_08008480
	movs r0, #0x00
	mov r9, r0
	adds r0, r5, #0x0
	bl sub_0800A310
	ldr r0, _0800A8F8 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x04
	beq _0800A886
	ldr r0, _0800A8FC @ =0x020020CC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0B
	bhi _0800A898
	.global _0800A886
_0800A886:
	ldr r1, _0800A900 @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800A8B4
	adds r0, r5, #0x0
	bl sub_0800D248
	mov r9, r0
	.global _0800A898
_0800A898:
	mov r2, r9
	cmp r2, #0x00
	beq _0800A8B4
	adds r0, r5, #0x0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	subs r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bhi _0800A8B4
	movs r0, #0x01
	negs r0, r0
	mov r9, r0
	.global _0800A8B4
_0800A8B4:
	ldr r0, [r5, #0x2C]
	asrs r0, r0, #0x06
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r4, r5, r1
	adds r1, r0, #0x0
	muls r1, r0
	str r1, [r4, #0x00]
	cmp r0, #0x00
	ble _0800A8CC
	negs r0, r1
	str r0, [r4, #0x00]
	.global _0800A8CC
_0800A8CC:
	ldr r0, _0800A904 @ =0x020020DC
	ldrb r1, [r0, #0x00]
	ldr r7, _0800A8F8 @ =0x0200215C
	mov r10, r0
	cmp r1, #0x00
	bne _0800A8E2
	ldrb r0, [r7, #0x00]
	cmp r0, #0x04
	beq _0800A8E2
	cmp r0, #0x03
	bne _0800A90C
	.global _0800A8E2
_0800A8E2:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r4, r5, r2
	ldr r0, [r4, #0x00]
	movs r1, #0xD7
	bl sub_08017230
	str r0, [r4, #0x00]
	ldr r0, _0800A908 @ =0x0202A550
	mov r8, r0
	b _0800A986
	.global _0800A8F8
_0800A8F8: .4byte 0x0200215C
	.global _0800A8FC
_0800A8FC: .4byte 0x020020CC
	.global _0800A900
_0800A900: .4byte 0x00000175
	.global _0800A904
_0800A904: .4byte 0x020020DC
	.global _0800A908
_0800A908: .4byte 0x0202A550
	.global _0800A90C
_0800A90C:
	ldr r1, _0800A944 @ =0x0202A550
	mov r8, r1
	cmp r5, r8
	beq _0800A92C
	cmp r0, #0x09
	beq _0800A92C
	cmp r0, #0x0D
	beq _0800A92C
	cmp r0, #0x0E
	beq _0800A92C
	cmp r0, #0x0F
	beq _0800A92C
	cmp r0, #0x11
	beq _0800A92C
	cmp r0, #0x04
	bne _0800A972
	.global _0800A92C
_0800A92C:
	movs r2, #0xB8
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A948
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r4, r5, r0
	ldr r0, [r4, #0x00]
	movs r1, #0xFA
	b _0800A980
	.global _0800A944
_0800A944: .4byte 0x0202A550
	.global _0800A948
_0800A948:
	ldr r1, _0800A960 @ =0x00000171
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A964
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r4, r5, r2
	ldr r0, [r4, #0x00]
	movs r1, #0x64
	b _0800A980
	.byte 0x00, 0x00
	.global _0800A960
_0800A960: .4byte 0x00000171
	.global _0800A964
_0800A964:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r4, r5, r0
	ldr r0, [r4, #0x00]
	movs r1, #0xF0
	lsls r1, r1, #0x01
	b _0800A980
	.global _0800A972
_0800A972:
	ldr r1, _0800AA80 @ =0x08368290
	ldr r0, _0800AA84 @ =0x020020CC
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	ldr r0, [r4, #0x00]
	.global _0800A980
_0800A980:
	bl sub_08017230
	str r0, [r4, #0x00]
	.global _0800A986
_0800A986:
	ldr r0, _0800AA88 @ =0x020020A8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A9A4
	ldrb r0, [r7, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bls _0800A9A4
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x00
	str r0, [r1, #0x00]
	.global _0800A9A4
_0800A9A4:
	cmp r5, r8
	beq _0800A9B0
	mov r1, r10
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0800AA0E
	.global _0800A9B0
_0800A9B0:
	ldr r0, _0800AA8C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _0800AA0E
	cmp r0, #0x0D
	beq _0800AA0E
	cmp r0, #0x0E
	beq _0800AA0E
	cmp r0, #0x0F
	beq _0800AA0E
	cmp r0, #0x11
	beq _0800AA0E
	adds r0, r5, #0x0
	bl sub_0800C164
	cmp r0, #0x00
	bne _0800A9DE
	movs r2, #0xBB
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AA0E
	.global _0800A9DE
_0800A9DE:
	movs r0, #0xBB
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0800A9EE
	subs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0800A9EE
_0800A9EE:
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
	bl sub_0800B618
	adds r0, r6, #0x0
	movs r1, #0x01
	bl sub_0800B618
	.global _0800AA0E
_0800AA0E:
	ldr r0, _0800AA8C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	beq _0800AA1C
	adds r0, r5, #0x0
	bl sub_0800D684
	.global _0800AA1C
_0800AA1C:
	ldr r1, [r5, #0x50]
	movs r2, #0xC6
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strh r1, [r0, #0x00]
	.global _0800AA26
_0800AA26:
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_08006A34
	ldr r1, _0800AA90 @ =0x020020BC
	strb r0, [r1, #0x00]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0800AA26
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
	beq _0800AB26
	ldr r0, _0800AA94 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800AAC4
	ldr r0, _0800AA98 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800AAC4
	ldr r0, _0800AA9C @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0800AAC4
	ldr r0, _0800AAA0 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800AAA8
	ldr r0, _0800AAA4 @ =0x0202A550
	cmp r5, r0
	beq _0800AABE
	b _0800AAC4
	.byte 0x00, 0x00
	.global _0800AA80
_0800AA80: .4byte 0x08368290
	.global _0800AA84
_0800AA84: .4byte 0x020020CC
	.global _0800AA88
_0800AA88: .4byte 0x020020A8
	.global _0800AA8C
_0800AA8C: .4byte 0x0200215C
	.global _0800AA90
_0800AA90: .4byte 0x020020BC
	.global _0800AA94
_0800AA94: .4byte 0x020020E0
	.global _0800AA98
_0800AA98: .4byte 0x020021E0
	.global _0800AA9C
_0800AA9C: .4byte 0x0202EF00
	.global _0800AAA0
_0800AAA0: .4byte 0x020020DC
	.global _0800AAA4
_0800AAA4: .4byte 0x0202A550
	.global _0800AAA8
_0800AAA8:
	ldr r0, _0800AB6C @ =0x0202EF90
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _0800AB70 @ =0x0202A550
	adds r0, r0, r1
	cmp r5, r0
	bne _0800AAC4
	.global _0800AABE
_0800AABE:
	movs r0, #0x12
	bl sub_08001208
	.global _0800AAC4
_0800AAC4:
	adds r0, r5, #0x0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	subs r0, #0x05
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _0800AAEA
	ldr r0, _0800AB74 @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AAEA
	adds r2, r5, #0x0
	adds r2, #0x88
	mov r0, r9
	asrs r1, r0, #0x0C
	ldr r0, [r2, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	.global _0800AAEA
_0800AAEA:
	adds r1, r5, #0x0
	adds r1, #0x55
	movs r0, #0x06
	strb r0, [r1, #0x00]
	adds r0, r5, #0x0
	bl sub_0800A2D4
	ldr r0, [r5, #0x2C]
	str r0, [r5, #0x48]
	cmp r0, #0x00
	ble _0800AB04
	movs r0, #0x00
	str r0, [r5, #0x48]
	.global _0800AB04
_0800AB04:
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
	bl sub_08017230
	adds r1, r5, #0x0
	adds r1, #0x40
	strh r0, [r1, #0x00]
	.global _0800AB26
_0800AB26:
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
	.global _0800AB6C
_0800AB6C: .4byte 0x0202EF90
	.global _0800AB70
_0800AB70: .4byte 0x0202A550
	.global _0800AB74
_0800AB74: .4byte 0x0202EEB0
	thumb_func_start sub_0800AB78
sub_0800AB78:
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r0, _0800ABAC @ =0x020020DC
	ldrb r1, [r0, #0x00]
	cmp r1, #0x00
	beq _0800ABC0
	ldr r0, _0800ABB0 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800ABB8
	adds r0, r5, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800ABB8
	ldr r0, _0800ABB4 @ =0x020020A0
	lsls r1, r6, #0x01
	adds r1, r1, r0
	ldrh r1, [r1, #0x00]
	adds r0, r5, #0x0
	adds r2, r6, #0x0
	bl sub_0800A80C
	b _0800AC4A
	.global _0800ABAC
_0800ABAC: .4byte 0x020020DC
	.global _0800ABB0
_0800ABB0: .4byte 0x020021E0
	.global _0800ABB4
_0800ABB4: .4byte 0x020020A0
	.global _0800ABB8
_0800ABB8:
	adds r0, r5, #0x0
	movs r1, #0x02
	adds r2, r6, #0x0
	b _0800AC46
	.global _0800ABC0
_0800ABC0:
	cmp r6, #0x00
	bne _0800AC52
	ldr r1, _0800ABE8 @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800ABEC
	adds r0, r5, #0x0
	movs r1, #0x00
	bl sub_080093BC
	adds r0, r5, #0x0
	adds r0, #0xA0
	ldrh r1, [r0, #0x00]
	adds r0, r5, #0x0
	movs r2, #0x00
	bl sub_0800A80C
	b _0800ACCA
	.byte 0x00, 0x00
	.global _0800ABE8
_0800ABE8: .4byte 0x00000175
	.global _0800ABEC
_0800ABEC:
	ldr r0, _0800AC1C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _0800AC04
	cmp r0, #0x0D
	beq _0800AC04
	cmp r0, #0x0E
	beq _0800AC04
	cmp r0, #0x0F
	beq _0800AC04
	cmp r0, #0x11
	bne _0800AC20
	.global _0800AC04
_0800AC04:
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_0800C534
	adds r0, r5, #0x0
	adds r0, #0xA0
	ldrh r1, [r0, #0x00]
	adds r0, r5, #0x0
	adds r2, r6, #0x0
	bl sub_0800A80C
	b _0800ACCA
	.global _0800AC1C
_0800AC1C: .4byte 0x0200215C
	.global _0800AC20
_0800AC20:
	ldr r0, _0800AC38 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800AC40
	ldr r0, _0800AC3C @ =0x020005C8
	ldrh r1, [r0, #0x00]
	adds r0, r5, #0x0
	movs r2, #0x00
	bl sub_0800A80C
	b _0800AC4A
	.byte 0x00, 0x00
	.global _0800AC38
_0800AC38: .4byte 0x020021E0
	.global _0800AC3C
_0800AC3C: .4byte 0x020005C8
	.global _0800AC40
_0800AC40:
	adds r0, r5, #0x0
	movs r1, #0x02
	movs r2, #0x00
	.global _0800AC46
_0800AC46:
	bl sub_0800A80C
	.global _0800AC4A
_0800AC4A:
	adds r0, r5, #0x0
	bl sub_0800A628
	b _0800ACCA
	.global _0800AC52
_0800AC52:
	ldr r0, _0800AC8C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _0800AC98
	cmp r0, #0x0D
	beq _0800AC98
	cmp r0, #0x0E
	beq _0800AC98
	cmp r0, #0x0F
	beq _0800AC98
	cmp r0, #0x11
	beq _0800AC98
	cmp r0, #0x04
	beq _0800ACB2
	ldr r0, _0800AC90 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800ACA6
	ldr r2, _0800AC94 @ =0x00000175
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AC98
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_080093BC
	b _0800ACA0
	.byte 0x00, 0x00
	.global _0800AC8C
_0800AC8C: .4byte 0x0200215C
	.global _0800AC90
_0800AC90: .4byte 0x020021E0
	.global _0800AC94
_0800AC94: .4byte 0x00000175
	.global _0800AC98
_0800AC98:
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_0800C534
	.global _0800ACA0
_0800ACA0:
	adds r4, r5, #0x0
	adds r4, #0xA0
	b _0800ACBA
	.global _0800ACA6
_0800ACA6:
	adds r1, r5, #0x0
	adds r1, #0xA0
	movs r0, #0x02
	strh r0, [r1, #0x00]
	adds r4, r1, #0x0
	b _0800ACBA
	.global _0800ACB2
_0800ACB2:
	adds r0, r5, #0x0
	adds r0, #0xA0
	strh r1, [r0, #0x00]
	adds r4, r0, #0x0
	.global _0800ACBA
_0800ACBA:
	adds r0, r5, #0x0
	bl sub_0800A628
	ldrh r1, [r4, #0x00]
	adds r0, r5, #0x0
	adds r2, r6, #0x0
	bl sub_0800A80C
	.global _0800ACCA
_0800ACCA:
	adds r0, r5, #0x0
	adds r0, #0x88
	ldr r1, [r0, #0x00]
	ldr r0, _0800AD34 @ =0x00011940
	cmp r1, r0
	ble _0800ACF2
	adds r0, r5, #0x0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _0800ACF2
	ldr r0, _0800AD38 @ =0x0200209C
	ldr r0, [r0, #0x00]
	movs r1, #0x3F
	ands r0, r1
	cmp r0, #0x00
	bne _0800ACF2
	adds r0, r5, #0x0
	bl sub_0800B8A8
	.global _0800ACF2
_0800ACF2:
	ldr r0, _0800AD3C @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AD48
	ldr r0, _0800AD40 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r6, r0
	bne _0800AD6A
	adds r0, r6, #0x0
	bl sub_08009B20
	ldr r0, _0800AD44 @ =0x0202A550
	lsls r1, r6, #0x01
	adds r1, r1, r6
	lsls r1, r1, #0x03
	adds r1, r1, r6
	lsls r1, r1, #0x04
	adds r1, r1, r0
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AD6A
	cmp r0, #0x63
	beq _0800AD6A
	movs r0, #0xB3
	lsls r0, r0, #0x01
	adds r1, r1, r0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	b _0800AD6A
	.byte 0x00, 0x00
	.global _0800AD34
_0800AD34: .4byte 0x00011940
	.global _0800AD38
_0800AD38: .4byte 0x0200209C
	.global _0800AD3C
_0800AD3C: .4byte 0x020020DC
	.global _0800AD40
_0800AD40: .4byte 0x0202EF90
	.global _0800AD44
_0800AD44: .4byte 0x0202A550
	.global _0800AD48
_0800AD48:
	cmp r6, #0x00
	bne _0800AD6A
	movs r0, #0x00
	bl sub_08009B20
	ldr r1, _0800AD7C @ =0x0202A550
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AD6A
	cmp r0, #0x63
	beq _0800AD6A
	adds r2, #0x16
	adds r0, r1, r2
	strb r6, [r0, #0x00]
	.global _0800AD6A
_0800AD6A:
	movs r0, #0xAE
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r0, [r1, #0x00]
	adds r0, #0x01
	str r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _0800AD7C
_0800AD7C: .4byte 0x0202A550
