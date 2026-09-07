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
	.byte 0x41, 0x69, 0x02, 0x69, 0x00, 0x2A, 0x01, 0xD0, 0x51, 0x61, 0x01, 0xE0, 0x02, 0x48, 0x01, 0x60
	.byte 0x00, 0x29, 0x00, 0xD0, 0x0A, 0x61, 0x70, 0x47, 0xD0, 0x5F, 0x02, 0x02
	thumb_func_start sub_0800796C
sub_0800796C:
	push {r4, r5, lr}
	ldr r1, _08007998 @ =0x0202A3E0
	movs r0, #0x00
	str r0, [r1, #0x00]
	ldr r0, _0800799C @ =0x02025FD0
	ldr r4, [r0, #0x00]
	cmp r4, #0x00
	beq _08007992
	adds r5, r1, #0x0
	.global _0800797E
_0800797E:
	ldr r0, [r5, #0x00]
	adds r0, #0x01
	str r0, [r5, #0x00]
	ldr r1, [r4, #0x0C]
	adds r0, r4, #0x0
	bl _080171F8
	ldr r4, [r4, #0x14]
	cmp r4, #0x00
	bne _0800797E
	.global _08007992
_08007992:
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08007998
_08007998: .4byte 0x0202A3E0
	.global _0800799C
_0800799C: .4byte 0x02025FD0
	.byte 0x00, 0xB5, 0xC1, 0x68, 0x0F, 0xF0, 0x28, 0xFC, 0x01, 0xBC, 0x00, 0x47
	thumb_func_start sub_080079AC
sub_080079AC:
	movs r1, #0x01
	ldr r2, _080079BC @ =0x0202CBC8
	.global _080079B0
_080079B0:
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080079C0
	adds r0, r1, #0x0
	b _080079CC
	.global _080079BC
_080079BC: .4byte 0x0202CBC8
	.global _080079C0
_080079C0:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x08
	bne _080079B0
	movs r0, #0x63
	.global _080079CC
_080079CC:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_080079D0
sub_080079D0:
	adds r2, r0, #0x0
	ldr r0, _080079F4 @ =0x0202A550
	cmp r2, r0
	beq _080079FC
	movs r3, #0x00
	adds r0, r2, #0x0
	adds r0, #0x9C
	ldr r1, [r0, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x06
	cmp r1, r0
	bgt _080079EA
	movs r3, #0x01
	.global _080079EA
_080079EA:
	adds r0, r2, #0x0
	adds r0, #0x8C
	ldr r0, [r0, #0x00]
	ldr r1, _080079F8 @ =0x0003E7FF
	b _08007A16
	.global _080079F4
_080079F4: .4byte 0x0202A550
	.global _080079F8
_080079F8: .4byte 0x0003E7FF
	.global _080079FC
_080079FC:
	movs r3, #0x00
	adds r0, r2, #0x0
	adds r0, #0x9C
	ldr r1, [r0, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x06
	cmp r1, r0
	bgt _08007A0E
	movs r3, #0x01
	.global _08007A0E
_08007A0E:
	adds r0, r2, #0x0
	adds r0, #0x8C
	ldr r0, [r0, #0x00]
	ldr r1, _08007A40 @ =0x0005DBFF
	.global _08007A16
_08007A16:
	cmp r0, r1
	bgt _08007A38
	adds r0, r2, #0x0
	adds r0, #0x90
	ldr r0, [r0, #0x00]
	cmp r0, r1
	bgt _08007A38
	adds r0, r2, #0x0
	adds r0, #0x94
	ldr r0, [r0, #0x00]
	cmp r0, r1
	bgt _08007A38
	adds r0, r2, #0x0
	adds r0, #0x98
	ldr r0, [r0, #0x00]
	cmp r0, r1
	ble _08007A3A
	.global _08007A38
_08007A38:
	movs r3, #0x01
	.global _08007A3A
_08007A3A:
	adds r0, r3, #0x0
	bx lr
	.byte 0x00, 0x00
	.global _08007A40
_08007A40: .4byte 0x0005DBFF
	.byte 0x30, 0xB5, 0x00, 0x23, 0x0A, 0x49, 0x0B, 0x4D, 0xC8, 0x24, 0x64, 0x00, 0x48, 0x19, 0x00, 0x78
	.byte 0x00, 0x28, 0x02, 0xD0, 0x50, 0x1C, 0x00, 0x06, 0x02, 0x0E, 0x09, 0x19, 0x58, 0x1C, 0x00, 0x06
	.byte 0x03, 0x0E, 0x09, 0x19, 0x18, 0x2B, 0xF1, 0xD1, 0x10, 0x1C, 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47
	.byte 0x50, 0xA5, 0x02, 0x02, 0x75, 0x01, 0x00, 0x00
	thumb_func_start sub_08007A7C
sub_08007A7C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r2, #0x0
	adds r7, r3, #0x0
	ldr r2, [sp, #0x018]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	asrs r0, r0, #0x10
	ldr r3, _08007B08 @ =0x02002100
	ldr r2, [r3, #0x18]
	subs r5, r0, r2
	asrs r1, r1, #0x10
	ldr r0, [r3, #0x1C]
	subs r4, r1, r0
	adds r4, #0x40
	adds r5, #0x70
	adds r1, r5, #0x0
	adds r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bhi _08007AFC
	cmp r4, #0xA0
	bgt _08007AFC
	movs r0, #0x10
	negs r0, r0
	cmp r4, r0
	blt _08007AFC
	adds r0, r6, #0x0
	bl sub_08007630
	adds r6, r0, #0x0
	cmp r6, #0x00
	beq _08007AFC
	adds r0, r7, #0x0
	bl sub_08007714
	lsls r0, r0, #0x18
	movs r2, #0xFF
	ands r2, r4
	ldr r1, _08007B0C @ =0x000001FF
	ands r5, r1
	lsls r1, r5, #0x10
	orrs r2, r1
	movs r1, #0x80
	lsls r1, r1, #0x17
	orrs r2, r1
	lsrs r0, r0, #0x0C
	movs r1, #0x80
	lsls r1, r1, #0x04
	orrs r0, r1
	ldr r1, [r6, #0x10]
	orrs r1, r0
	mov r0, r8
	cmp r0, #0x00
	beq _08007AF6
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r2, r0
	.global _08007AF6
_08007AF6:
	adds r0, r2, #0x0
	bl sub_080044A4
	.global _08007AFC
_08007AFC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08007B08
_08007B08: .4byte 0x02002100
	.global _08007B0C
_08007B0C: .4byte 0x000001FF
	thumb_func_start sub_08007B10
sub_08007B10:
	adds r3, r0, #0x0
	ldr r2, _08007B20 @ =0x0202EFC0
	movs r1, #0x00
	.global _08007B16
_08007B16:
	ldr r0, [r2, #0x00]
	cmp r0, r3
	bne _08007B24
	adds r0, r1, #0x0
	b _08007B32
	.global _08007B20
_08007B20: .4byte 0x0202EFC0
	.global _08007B24
_08007B24:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r2, #0x04
	cmp r1, #0x18
	bne _08007B16
	movs r0, #0x18
	.global _08007B32
_08007B32:
	bx lr
	thumb_func_start sub_08007B34
sub_08007B34:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl sub_08009B20
	adds r0, r4, #0x0
	bl sub_08007B10
	movs r1, #0xB2
	lsls r1, r1, #0x01
	adds r2, r4, r1
	ldr r1, _08007BB0 @ =0x08367620
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r1
	ldrh r3, [r2, #0x00]
	ldrb r0, [r0, #0x00]
	adds r1, r3, r0
	strh r1, [r2, #0x00]
	movs r5, #0xB4
	lsls r5, r5, #0x01
	adds r3, r4, r5
	ldrb r0, [r3, #0x00]
	cmp r0, #0x00
	beq _08007B6C
	adds r0, r1, #0x5
	strh r0, [r2, #0x00]
	.global _08007B6C
_08007B6C:
	movs r2, #0x01
	movs r1, #0x00
	ldr r6, _08007BB4 @ =0x0202A550
	.global _08007B72
_08007B72:
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r0, r0, r6
	cmp r4, r0
	beq _08007B8E
	adds r0, r0, r5
	ldrb r0, [r0, #0x00]
	ldrb r7, [r3, #0x00]
	cmp r0, r7
	bls _08007B8E
	movs r2, #0x00
	.global _08007B8E
_08007B8E:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x18
	bne _08007B72
	cmp r2, #0x00
	beq _08007BA8
	movs r0, #0xB2
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x0A
	strh r0, [r1, #0x00]
	.global _08007BA8
_08007BA8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08007BB0
_08007BB0: .4byte 0x08367620
	.global _08007BB4
_08007BB4: .4byte 0x0202A550
	thumb_func_start sub_08007BB8
sub_08007BB8:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _08007C3C @ =0x08367A14
	lsls r1, r0, #0x03
	subs r1, r1, r0
	lsls r1, r1, #0x02
	adds r0, r1, r2
	ldr r5, [r0, #0x00]
	adds r0, r2, #0x4
	adds r0, r1, r0
	ldr r4, [r0, #0x00]
	ldr r3, _08007C40 @ =0x0202A3F0
	movs r7, #0x00
	adds r0, r2, #0x0
	adds r0, #0x18
	adds r6, r1, r0
	subs r0, #0x0C
	adds r0, r0, r1
	mov r9, r0
	adds r0, r2, #0x0
	adds r0, #0x10
	adds r0, r0, r1
	mov r8, r0
	adds r0, r2, #0x0
	adds r0, #0x14
	adds r0, r0, r1
	mov r12, r0
	adds r0, r2, #0x0
	adds r0, #0x08
	adds r1, r1, r0
	.global _08007BFC
_08007BFC:
	str r5, [r3, #0x00]
	str r4, [r3, #0x04]
	ldr r0, [r6, #0x00]
	str r0, [r3, #0x08]
	adds r3, #0x0C
	mov r2, r8
	ldr r0, [r2, #0x00]
	adds r0, r5, r0
	str r0, [r3, #0x00]
	mov r2, r12
	ldr r0, [r2, #0x00]
	adds r0, r4, r0
	str r0, [r3, #0x04]
	ldr r0, [r6, #0x00]
	str r0, [r3, #0x08]
	adds r3, #0x0C
	ldr r0, [r1, #0x00]
	adds r5, r5, r0
	mov r2, r9
	ldr r0, [r2, #0x00]
	adds r4, r4, r0
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0x0C
	bne _08007BFC
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08007C3C
_08007C3C: .4byte 0x08367A14
	.global _08007C40
_08007C40: .4byte 0x0202A3F0
	thumb_func_start sub_08007C44
sub_08007C44:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x040
	adds r6, r0, #0x0
	movs r0, #0xB8
	lsls r0, r0, #0x01
	adds r0, r0, r6
	mov r8, r0
	movs r4, #0x00
	strb r4, [r0, #0x00]
	ldr r1, _08007EB8 @ =0x00000171
	adds r3, r6, r1
	ldrb r0, [r3, #0x00]
	ldr r2, _08007EBC @ =0x00000173
	adds r1, r6, r2
	strb r0, [r1, #0x00]
	strb r4, [r3, #0x00]
	movs r7, #0xB9
	lsls r7, r7, #0x01
	adds r5, r6, r7
	strb r4, [r5, #0x00]
	ldr r0, _08007EC0 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x04
	bne _08007C7E
	b _08007EA8
	.global _08007C7E
_08007C7E:
	ldr r0, _08007EC4 @ =0x020020CC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x07
	bne _08007C88
	b _08007EA8
	.global _08007C88
_08007C88:
	movs r0, #0x00
	str r0, [sp, #0x028]
	ldr r0, _08007EC8 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08007C9A
	ldr r0, _08007ECC @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x028]
	.global _08007C9A
_08007C9A:
	ldr r0, [r6, #0x00]
	ldr r1, [r6, #0x08]
	asrs r0, r0, #0x13
	asrs r2, r1, #0x13
	adds r2, #0x02
	adds r0, #0x01
	str r0, [sp, #0x03C]
	mov r1, r8
	strb r4, [r1, #0x00]
	strb r4, [r3, #0x00]
	strb r4, [r5, #0x00]
	movs r7, #0x00
	mov r8, r7
	subs r5, r2, #0x1
	adds r0, r2, #0x2
	ldr r1, [sp, #0x028]
	lsls r1, r1, #0x01
	str r1, [sp, #0x030]
	cmp r5, r0
	beq _08007D6E
	ldr r7, [sp, #0x03C]
	adds r7, #0x02
	mov r9, r7
	str r0, [sp, #0x02C]
	.global _08007CCA
_08007CCA:
	ldr r4, [sp, #0x03C]
	subs r4, #0x01
	adds r0, r5, #0x1
	mov r10, r0
	cmp r4, r9
	beq _08007D66
	movs r3, #0x01
	.global _08007CD8
_08007CD8:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	str r2, [sp, #0x034]
	str r3, [sp, #0x038]
	bl sub_0800CBB8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r0, r1, #0x0
	ldr r3, [sp, #0x038]
	ands r0, r3
	ldr r2, [sp, #0x034]
	cmp r0, #0x00
	beq _08007CFC
	movs r7, #0xB9
	lsls r7, r7, #0x01
	adds r0, r6, r7
	strb r3, [r0, #0x00]
	.global _08007CFC
_08007CFC:
	subs r0, r1, #0x2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _08007D18
	ldr r0, [sp, #0x03C]
	cmp r4, r0
	bne _08007D18
	cmp r5, r2
	bne _08007D18
	movs r7, #0xB8
	lsls r7, r7, #0x01
	adds r0, r6, r7
	strb r3, [r0, #0x00]
	.global _08007D18
_08007D18:
	subs r0, r1, #0x4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _08007D32
	ldr r0, [sp, #0x03C]
	cmp r4, r0
	bne _08007D32
	cmp r5, r2
	bne _08007D32
	ldr r7, _08007EB8 @ =0x00000171
	adds r0, r6, r7
	strb r3, [r0, #0x00]
	.global _08007D32
_08007D32:
	cmp r1, #0x06
	bne _08007D40
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	.global _08007D40
_08007D40:
	adds r0, r1, #0x0
	subs r0, #0x08
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _08007D60
	ldr r1, _08007ED0 @ =0x00000175
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x06
	bne _08007D60
	movs r7, #0xC1
	lsls r7, r7, #0x01
	adds r1, r6, r7
	movs r0, #0x00
	strh r0, [r1, #0x00]
	.global _08007D60
_08007D60:
	adds r4, #0x01
	cmp r4, r9
	bne _08007CD8
	.global _08007D66
_08007D66:
	mov r5, r10
	ldr r0, [sp, #0x02C]
	cmp r5, r0
	bne _08007CCA
	.global _08007D6E
_08007D6E:
	mov r1, r8
	cmp r1, #0x04
	bhi _08007D90
	cmp r1, #0x00
	beq _08007DA6
	ldr r0, _08007EC4 @ =0x020020CC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	beq _08007D90
	cmp r0, #0x05
	beq _08007D90
	cmp r0, #0x08
	beq _08007D90
	cmp r0, #0x0B
	beq _08007D90
	cmp r0, #0x02
	bne _08007DA6
	.global _08007D90
_08007D90:
	ldr r0, _08007EC8 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08007DA6
	ldr r0, _08007ED4 @ =0x0202A550
	cmp r6, r0
	bne _08007DA6
	adds r0, r6, #0x0
	movs r1, #0x00
	bl sub_0800930C
	.global _08007DA6
_08007DA6:
	movs r4, #0x00
	ldr r0, _08007EC0 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	subs r0, #0x0F
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _08007DC0
	ldr r0, _08007ED8 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0C
	bne _08007DC0
	movs r4, #0x01
	.global _08007DC0
_08007DC0:
	ldr r2, [sp, #0x030]
	ldr r7, [sp, #0x028]
	adds r0, r2, r7
	lsls r0, r0, #0x03
	adds r0, r0, r7
	lsls r0, r0, #0x04
	ldr r1, _08007ED4 @ =0x0202A550
	adds r0, r0, r1
	cmp r6, r0
	bne _08007E90
	ldr r1, _08007EB8 @ =0x00000171
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08007E0A
	ldr r2, _08007EBC @ =0x00000173
	adds r0, r6, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08007E0A
	cmp r4, #0x00
	bne _08007E0A
	ldr r0, _08007EDC @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08007E0A
	ldr r0, _08007EE0 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08007E0A
	ldr r0, _08007EE4 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08007E0A
	movs r0, #0x1C
	bl sub_08001208
	.global _08007E0A
_08007E0A:
	ldr r7, [sp, #0x030]
	ldr r1, [sp, #0x028]
	adds r0, r7, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _08007ED4 @ =0x0202A550
	adds r0, r0, r1
	cmp r6, r0
	bne _08007E90
	ldr r2, _08007EB8 @ =0x00000171
	adds r0, r6, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08007E56
	bl sub_080025FC
	movs r1, #0x1F
	ands r1, r0
	cmp r1, #0x00
	bne _08007E56
	ldr r0, _08007EDC @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08007E56
	ldr r0, _08007EE0 @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08007E56
	ldr r0, _08007EE4 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08007E56
	cmp r4, #0x00
	bne _08007E56
	movs r0, #0x1D
	bl sub_08001208
	.global _08007E56
_08007E56:
	ldr r7, [sp, #0x030]
	ldr r1, [sp, #0x028]
	adds r0, r7, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _08007ED4 @ =0x0202A550
	adds r0, r0, r1
	cmp r6, r0
	bne _08007E90
	movs r2, #0xB8
	lsls r2, r2, #0x01
	adds r0, r6, r2
	ldr r0, [r0, #0x00]
	ldr r1, _08007EE8 @ =0xFF00FF00
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	cmp r0, r1
	bne _08007E90
	ldr r0, _08007EEC @ =0x02001FA0
	bl sub_080019B4
	ldr r0, _08007EF0 @ =0x02002030
	bl sub_080019B4
	ldr r0, _08007EF4 @ =0x02001FE0
	bl sub_080019B4
	.global _08007E90
_08007E90:
	ldr r0, _08007EC0 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x10
	bne _08007EA8
	ldr r0, _08007ED8 @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0C
	bne _08007EA8
	ldr r7, _08007EB8 @ =0x00000171
	adds r1, r6, r7
	movs r0, #0x00
	strb r0, [r1, #0x00]
	.global _08007EA8
_08007EA8:
	add sp, #0x040
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08007EB8
_08007EB8: .4byte 0x00000171
	.global _08007EBC
_08007EBC: .4byte 0x00000173
	.global _08007EC0
_08007EC0: .4byte 0x0200215C
	.global _08007EC4
_08007EC4: .4byte 0x020020CC
	.global _08007EC8
_08007EC8: .4byte 0x020020DC
	.global _08007ECC
_08007ECC: .4byte 0x0202EF90
	.global _08007ED0
_08007ED0: .4byte 0x00000175
	.global _08007ED4
_08007ED4: .4byte 0x0202A550
	.global _08007ED8
_08007ED8: .4byte 0x0202ED70
	.global _08007EDC
_08007EDC: .4byte 0x0202EF00
	.global _08007EE0
_08007EE0: .4byte 0x020020E0
	.global _08007EE4
_08007EE4: .4byte 0x020021E0
	.global _08007EE8
_08007EE8: .4byte 0xFF00FF00
	.global _08007EEC
_08007EEC: .4byte 0x02001FA0
	.global _08007EF0
_08007EF0: .4byte 0x02002030
	.global _08007EF4
_08007EF4: .4byte 0x02001FE0
	thumb_func_start sub_08007EF8
sub_08007EF8:
	push {r4, lr}
	ldr r0, _08007F38 @ =0x0806C854
	movs r1, #0x0B
	movs r2, #0x07
	bl sub_0800649C
	ldr r4, _08007F3C @ =0x0806C860
	adds r0, r4, #0x0
	movs r1, #0x06
	movs r2, #0x09
	bl sub_0800649C
	adds r0, r4, #0x0
	movs r1, #0x06
	movs r2, #0x0A
	bl sub_0800649C
	ldr r4, _08007F40 @ =0x0806C878
	adds r0, r4, #0x0
	movs r1, #0x06
	movs r2, #0x0B
	bl sub_0800649C
	adds r0, r4, #0x0
	movs r1, #0x0A
	movs r2, #0x0C
	bl sub_0800649C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08007F38
_08007F38: .4byte 0x0806C854
	.global _08007F3C
_08007F3C: .4byte 0x0806C860
	.global _08007F40
_08007F40: .4byte 0x0806C878
	thumb_func_start sub_08007F44
sub_08007F44:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _08007F88 @ =0x0806C894
	movs r1, #0x0B
	movs r2, #0x07
	bl sub_0800649C
	cmp r4, #0x00
	bne _08007F64
	ldr r1, _08007F8C @ =0x0202A524
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08007F9C
	.global _08007F64
_08007F64:
	ldr r0, _08007F90 @ =0x0836813C
	ldr r0, [r0, #0x00]
	movs r1, #0x06
	movs r2, #0x09
	bl sub_0800649C
	ldr r1, _08007F94 @ =0x0836814C
	ldr r0, _08007F98 @ =0x0202CBC0
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x0D
	movs r2, #0x09
	bl sub_0800649C
	b _08007FA6
	.byte 0x00, 0x00
	.global _08007F88
_08007F88: .4byte 0x0806C894
	.global _08007F8C
_08007F8C: .4byte 0x0202A524
	.global _08007F90
_08007F90: .4byte 0x0836813C
	.global _08007F94
_08007F94: .4byte 0x0836814C
	.global _08007F98
_08007F98: .4byte 0x0202CBC0
	.global _08007F9C
_08007F9C:
	ldr r0, _08007FD8 @ =0x0806C8A0
	movs r1, #0x06
	movs r2, #0x09
	bl sub_0800649C
	.global _08007FA6
_08007FA6:
	cmp r4, #0x01
	bne _08007FB6
	ldr r1, _08007FDC @ =0x0202A524
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08007FEC
	.global _08007FB6
_08007FB6:
	ldr r0, _08007FE0 @ =0x0836813C
	ldr r0, [r0, #0x04]
	movs r1, #0x06
	movs r2, #0x0A
	bl sub_0800649C
	ldr r1, _08007FE4 @ =0x0836815C
	ldr r0, _08007FE8 @ =0x0202CBC0
	ldrb r0, [r0, #0x01]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x0D
	movs r2, #0x0A
	bl sub_0800649C
	b _08007FF6
	.global _08007FD8
_08007FD8: .4byte 0x0806C8A0
	.global _08007FDC
_08007FDC: .4byte 0x0202A524
	.global _08007FE0
_08007FE0: .4byte 0x0836813C
	.global _08007FE4
_08007FE4: .4byte 0x0836815C
	.global _08007FE8
_08007FE8: .4byte 0x0202CBC0
	.global _08007FEC
_08007FEC:
	ldr r0, _08008028 @ =0x0806C878
	movs r1, #0x06
	movs r2, #0x0A
	bl sub_0800649C
	.global _08007FF6
_08007FF6:
	cmp r4, #0x02
	bne _08008006
	ldr r1, _0800802C @ =0x0202A524
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _0800803C
	.global _08008006
_08008006:
	ldr r0, _08008030 @ =0x0836813C
	ldr r0, [r0, #0x08]
	movs r1, #0x06
	movs r2, #0x0B
	bl sub_0800649C
	ldr r1, _08008034 @ =0x08368168
	ldr r0, _08008038 @ =0x0202CBC0
	ldrb r0, [r0, #0x02]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x0D
	movs r2, #0x0B
	bl sub_0800649C
	b _08008046
	.global _08008028
_08008028: .4byte 0x0806C878
	.global _0800802C
_0800802C: .4byte 0x0202A524
	.global _08008030
_08008030: .4byte 0x0836813C
	.global _08008034
_08008034: .4byte 0x08368168
	.global _08008038
_08008038: .4byte 0x0202CBC0
	.global _0800803C
_0800803C:
	ldr r0, _08008064 @ =0x0806C878
	movs r1, #0x06
	movs r2, #0x0B
	bl sub_0800649C
	.global _08008046
_08008046:
	cmp r4, #0x03
	bne _08008056
	ldr r1, _08008068 @ =0x0202A524
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08008070
	.global _08008056
_08008056:
	ldr r0, _0800806C @ =0x0836813C
	ldr r0, [r0, #0x0C]
	movs r1, #0x0D
	movs r2, #0x0C
	bl sub_0800649C
	b _0800807A
	.global _08008064
_08008064: .4byte 0x0806C878
	.global _08008068
_08008068: .4byte 0x0202A524
	.global _0800806C
_0800806C: .4byte 0x0836813C
	.global _08008070
_08008070:
	ldr r0, _08008088 @ =0x0806C8A0
	movs r1, #0x0A
	movs r2, #0x0C
	bl sub_0800649C
	.global _0800807A
_0800807A:
	ldr r1, _0800808C @ =0x0202A524
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.global _08008088
_08008088: .4byte 0x0806C8A0
	.global _0800808C
_0800808C: .4byte 0x0202A524
	thumb_func_start sub_08008090
sub_08008090:
	ldr r1, _080080A8 @ =0x0202CBE0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r1, _080080AC @ =0x0202CBC0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	strb r0, [r1, #0x01]
	strb r0, [r1, #0x02]
	ldr r1, _080080B0 @ =0x0202CAD0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bx lr
	.global _080080A8
_080080A8: .4byte 0x0202CBE0
	.global _080080AC
_080080AC: .4byte 0x0202CBC0
	.global _080080B0
_080080B0: .4byte 0x0202CAD0
	thumb_func_start sub_080080B4
sub_080080B4:
	push {r4, r5, r6, lr}
	ldr r5, _0800814C @ =0x0202CBE0
	ldrb r0, [r5, #0x00]
	bl sub_08007F44
	ldr r6, _08008150 @ =0x020005CC
	ldrh r0, [r6, #0x00]
	ldrb r1, [r5, #0x00]
	movs r2, #0x00
	movs r3, #0x03
	bl sub_08011DAC
	strb r0, [r5, #0x00]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080080E4
	ldrh r0, [r6, #0x00]
	ldr r4, _08008154 @ =0x0202CBC0
	ldrb r1, [r4, #0x00]
	movs r2, #0x00
	movs r3, #0x03
	bl sub_08011E84
	strb r0, [r4, #0x00]
	.global _080080E4
_080080E4:
	ldrb r0, [r5, #0x00]
	cmp r0, #0x01
	bne _080080FA
	ldrh r0, [r6, #0x00]
	ldr r4, _08008154 @ =0x0202CBC0
	ldrb r1, [r4, #0x01]
	movs r2, #0x00
	movs r3, #0x02
	bl sub_08011E84
	strb r0, [r4, #0x01]
	.global _080080FA
_080080FA:
	ldrb r3, [r5, #0x00]
	cmp r3, #0x02
	bne _08008110
	ldrh r0, [r6, #0x00]
	ldr r4, _08008154 @ =0x0202CBC0
	ldrb r1, [r4, #0x02]
	movs r2, #0x00
	movs r3, #0x01
	bl sub_08011E84
	strb r0, [r4, #0x02]
	.global _08008110
_08008110:
	ldrb r5, [r5, #0x00]
	cmp r5, #0x03
	bne _08008146
	movs r0, #0x01
	ldrh r6, [r6, #0x00]
	ands r0, r6
	cmp r0, #0x00
	beq _08008146
	ldr r0, _08008158 @ =0x0202CAD0
	movs r2, #0x00
	strb r2, [r0, #0x00]
	ldr r1, _0800815C @ =0x0202A53C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _08008154 @ =0x0202CBC0
	ldrb r3, [r0, #0x00]
	cmp r3, #0x03
	bne _08008142
	ldrb r3, [r0, #0x01]
	cmp r3, #0x02
	bne _08008142
	ldrb r0, [r0, #0x02]
	cmp r0, #0x01
	bne _08008142
	strb r2, [r1, #0x00]
	.global _08008142
_08008142:
	bl sub_08007EF8
	.global _08008146
_08008146:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _0800814C
_0800814C: .4byte 0x0202CBE0
	.global _08008150
_08008150: .4byte 0x020005CC
	.global _08008154
_08008154: .4byte 0x0202CBC0
	.global _08008158
_08008158: .4byte 0x0202CAD0
	.global _0800815C
_0800815C: .4byte 0x0202A53C
	.byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x93, 0xB0, 0x4E, 0x48, 0x01, 0x68
	.byte 0x80, 0x68, 0xC9, 0x14, 0x88, 0x46, 0xC0, 0x14, 0x81, 0x46, 0x02, 0x20, 0x81, 0x44, 0x01, 0x21
	.byte 0x88, 0x44, 0x00, 0x20, 0x0E, 0x90, 0x00, 0x21, 0x0D, 0x91, 0x0F, 0x90, 0x4D, 0x46, 0x03, 0x3D
	.byte 0x48, 0x46, 0x04, 0x30, 0x85, 0x42, 0x62, 0xD0, 0x41, 0x46, 0x04, 0x31, 0x10, 0x91, 0x12, 0x90
	.byte 0x44, 0x46, 0x03, 0x3C, 0x68, 0x1C, 0x11, 0x90, 0x10, 0x99, 0x8C, 0x42, 0x53, 0xD0, 0x0B, 0xAE
	.byte 0x20, 0x1C, 0x29, 0x1C, 0x04, 0xF0, 0x00, 0xFD, 0x00, 0x06, 0x07, 0x0E, 0xBA, 0x46, 0xE0, 0x04
	.byte 0xE9, 0x04, 0x32, 0x1C, 0x01, 0xF0, 0xF6, 0xFC, 0x00, 0x06, 0x00, 0x28, 0x3F, 0xD0, 0x0B, 0x98
	.byte 0x78, 0x38, 0x36, 0x4A, 0x91, 0x69, 0x40, 0x18, 0x0B, 0x90, 0x70, 0x68, 0x50, 0x38, 0xD1, 0x69
	.byte 0x40, 0x18, 0x70, 0x60, 0x0B, 0x98, 0x0A, 0x30, 0x0B, 0x90, 0x71, 0x68, 0x08, 0x31, 0x71, 0x60
	.byte 0x0B, 0x98, 0x00, 0x04, 0x09, 0x04, 0x2E, 0x4B, 0xBA, 0x00, 0xD2, 0x18, 0x12, 0x68, 0x00, 0x23
	.byte 0x00, 0x93, 0x2C, 0x4B, 0xFF, 0xF7, 0x3A, 0xFC, 0x40, 0x46, 0x02, 0x38, 0x84, 0x42, 0x1E, 0xDD
	.byte 0x04, 0x30, 0x84, 0x42, 0x1B, 0xDA, 0x48, 0x46, 0x02, 0x38, 0x85, 0x42, 0x17, 0xDD, 0x04, 0x30
	.byte 0x85, 0x42, 0x14, 0xDA, 0x01, 0x20, 0x38, 0x40, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x20, 0x0F, 0x90
	.byte 0xB8, 0x1E, 0x00, 0x06, 0x00, 0x0E, 0x01, 0x28, 0x01, 0xD8, 0x01, 0x21, 0x0D, 0x91, 0x50, 0x46
	.byte 0x04, 0x38, 0x00, 0x06, 0x00, 0x0E, 0x01, 0x28, 0x01, 0xD8, 0x01, 0x20, 0x0E, 0x90, 0x01, 0x34
	.byte 0x10, 0x99, 0x8C, 0x42, 0xAC, 0xD1, 0x11, 0x9D, 0x12, 0x98, 0x85, 0x42, 0xA0, 0xD1, 0x0E, 0x99
	.byte 0x00, 0x29, 0x04, 0xD0, 0x14, 0x48, 0x64, 0x21, 0x64, 0x22, 0x03, 0xF0, 0x75, 0xFC, 0x0D, 0x98
	.byte 0x00, 0x28, 0x04, 0xD0, 0x11, 0x48, 0x64, 0x21, 0x64, 0x22, 0x03, 0xF0, 0x6D, 0xFC, 0x0E, 0x99
	.byte 0x00, 0x29, 0x07, 0xD1, 0x0D, 0x98, 0x00, 0x28, 0x04, 0xD1, 0x0D, 0x48, 0x64, 0x21, 0x64, 0x22
	.byte 0x03, 0xF0, 0x62, 0xFC, 0x0F, 0x99, 0x00, 0x29, 0x16, 0xD0, 0x0A, 0x48, 0x64, 0x21, 0x6E, 0x22
	.byte 0x03, 0xF0, 0x5A, 0xFC, 0x15, 0xE0, 0x00, 0x00, 0x50, 0xA5, 0x02, 0x02, 0x00, 0x21, 0x00, 0x02
	.byte 0x8C, 0xF6, 0x3F, 0x08, 0x60, 0x13, 0x33, 0x08, 0xB4, 0xC8, 0x06, 0x08, 0xBC, 0xC8, 0x06, 0x08
	.byte 0xC4, 0xC8, 0x06, 0x08, 0xCC, 0xC8, 0x06, 0x08, 0x0D, 0x48, 0x64, 0x21, 0x6E, 0x22, 0x03, 0xF0
	.byte 0x43, 0xFC, 0x0C, 0x49, 0x0C, 0x48, 0x02, 0x68, 0xD2, 0x14, 0x83, 0x68, 0xDB, 0x14, 0x01, 0xA8
	.byte 0x0F, 0xF0, 0x58, 0xF9, 0x01, 0xA8, 0x64, 0x21, 0x78, 0x22, 0x03, 0xF0, 0x35, 0xFC, 0x13, 0xB0
	.byte 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0xD4, 0xC8, 0x06, 0x08, 0xDC, 0xC8, 0x06, 0x08, 0x50, 0xA5, 0x02, 0x02
	thumb_func_start sub_0800830C
sub_0800830C:
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	adds r6, r1, #0x0
	movs r5, #0x00
	.global _08008314
_08008314:
	lsls r0, r5, #0x01
	adds r4, r0, r6
	adds r0, r0, r7
	ldrh r1, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x09
	bl sub_08017230
	strh r0, [r4, #0x00]
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x05
	bne _08008314
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start sub_08008338
sub_08008338:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r3, #0x00
	ldr r0, _08008380 @ =0x0202CB20
	mov r12, r0
	ldr r0, _08008384 @ =0x0202CB00
	mov r8, r0
	ldr r7, _08008388 @ =0x0202A540
	ldr r6, _0800838C @ =0x08367B82
	mov r5, r12
	ldr r4, _08008390 @ =0x08367B8C
	.global _08008350
_08008350:
	lsls r1, r3, #0x01
	adds r2, r1, r7
	adds r0, r1, r6
	ldrh r0, [r0, #0x00]
	strh r0, [r2, #0x00]
	adds r2, r1, r5
	adds r1, r1, r4
	ldrh r0, [r1, #0x00]
	strh r0, [r2, #0x00]
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x05
	bne _08008350
	mov r0, r12
	mov r1, r8
	bl sub_0800830C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08008380
_08008380: .4byte 0x0202CB20
	.global _08008384
_08008384: .4byte 0x0202CB00
	.global _08008388
_08008388: .4byte 0x0202A540
	.global _0800838C
_0800838C: .4byte 0x08367B82
	.global _08008390
_08008390: .4byte 0x08367B8C
	thumb_func_start sub_08008394
sub_08008394:
	adds r2, r0, #0x0
	ldr r0, _080083B0 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xE4
	ldr r0, _080083B4 @ =0x08367BFA
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _080083B8 @ =0x08367C06
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _080083BC @ =0x08367C10
	str r0, [r1, #0x00]
	bx lr
	.global _080083B0
_080083B0: .4byte 0x0200215C
	.global _080083B4
_080083B4: .4byte 0x08367BFA
	.global _080083B8
_080083B8: .4byte 0x08367C06
	.global _080083BC
_080083BC: .4byte 0x08367C10
	thumb_func_start sub_080083C0
sub_080083C0:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _080083EC @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08008408
	ldr r1, _080083F0 @ =0x0202CAD4
	ldr r2, _080083F4 @ =0x083677A8
	ldr r0, [r2, #0x00]
	strb r0, [r1, #0x00]
	ldr r1, _080083F8 @ =0x0202A514
	ldr r0, [r2, #0x04]
	strb r0, [r1, #0x00]
	ldr r1, _080083FC @ =0x0202CBC4
	ldr r0, [r2, #0x08]
	strb r0, [r1, #0x00]
	ldr r1, _08008400 @ =0x0202CBDC
	ldr r0, [r2, #0x0C]
	strb r0, [r1, #0x00]
	ldr r1, _08008404 @ =0x0202A510
	ldr r0, [r2, #0x10]
	b _0800845E
	.global _080083EC
_080083EC: .4byte 0x020020DC
	.global _080083F0
_080083F0: .4byte 0x0202CAD4
	.global _080083F4
_080083F4: .4byte 0x083677A8
	.global _080083F8
_080083F8: .4byte 0x0202A514
	.global _080083FC
_080083FC: .4byte 0x0202CBC4
	.global _08008400
_08008400: .4byte 0x0202CBDC
	.global _08008404
_08008404: .4byte 0x0202A510
	.global _08008408
_08008408:
	cmp r1, #0x00
	bne _08008444
	ldr r1, _0800842C @ =0x0202CAD4
	ldr r2, _08008430 @ =0x083677A8
	ldr r0, [r2, #0x00]
	strb r0, [r1, #0x00]
	ldr r1, _08008434 @ =0x0202A514
	ldr r0, [r2, #0x04]
	strb r0, [r1, #0x00]
	ldr r1, _08008438 @ =0x0202CBC4
	ldr r0, [r2, #0x08]
	strb r0, [r1, #0x00]
	ldr r1, _0800843C @ =0x0202CBDC
	ldr r0, [r2, #0x0C]
	strb r0, [r1, #0x00]
	ldr r1, _08008440 @ =0x0202A510
	ldr r0, [r2, #0x10]
	b _0800845E
	.global _0800842C
_0800842C: .4byte 0x0202CAD4
	.global _08008430
_08008430: .4byte 0x083677A8
	.global _08008434
_08008434: .4byte 0x0202A514
	.global _08008438
_08008438: .4byte 0x0202CBC4
	.global _0800843C
_0800843C: .4byte 0x0202CBDC
	.global _08008440
_08008440: .4byte 0x0202A510
	.global _08008444
_08008444:
	ldr r1, _08008464 @ =0x0202CAD4
	movs r0, #0xA0
	strb r0, [r1, #0x00]
	ldr r1, _08008468 @ =0x0202A514
	movs r0, #0xFF
	strb r0, [r1, #0x00]
	ldr r0, _0800846C @ =0x0202CBC4
	movs r1, #0x80
	strb r1, [r0, #0x00]
	ldr r0, _08008470 @ =0x0202CBDC
	strb r1, [r0, #0x00]
	ldr r1, _08008474 @ =0x0202A510
	ldr r0, _08008478 @ =0x0000B060
	.global _0800845E
_0800845E:
	str r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
	.global _08008464
_08008464: .4byte 0x0202CAD4
	.global _08008468
_08008468: .4byte 0x0202A514
	.global _0800846C
_0800846C: .4byte 0x0202CBC4
	.global _08008470
_08008470: .4byte 0x0202CBDC
	.global _08008474
_08008474: .4byte 0x0202A510
	.global _08008478
_08008478: .4byte 0x0000B060
	.byte 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_08008480
sub_08008480:
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r0, _080084DC @ =0x0202CB18
	strb r6, [r0, #0x00]
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl sub_080083C0
	ldr r0, _080084E0 @ =0x0202A550
	cmp r5, r0
	bne _080084F4
	adds r0, r5, #0x0
	adds r0, #0x8C
	ldr r0, [r0, #0x00]
	movs r1, #0xFA
	lsls r1, r1, #0x0B
	cmp r0, r1
	bgt _080084C6
	adds r0, r5, #0x0
	adds r0, #0x90
	ldr r0, [r0, #0x00]
	cmp r0, r1
	bgt _080084C6
	adds r0, r5, #0x0
	adds r0, #0x94
	ldr r0, [r0, #0x00]
	cmp r0, r1
	bgt _080084C6
	adds r0, r5, #0x0
	adds r0, #0x98
	ldr r0, [r0, #0x00]
	cmp r0, r1
	ble _080084F4
	.global _080084C6
_080084C6:
	ldr r1, _080084E4 @ =0x0202CB2C
	movs r0, #0x40
	str r0, [r1, #0x00]
	ldr r2, _080084E8 @ =0x0202CAEC
	movs r0, #0x80
	str r0, [r2, #0x00]
	ldr r1, _080084EC @ =0x0202A518
	ldr r0, _080084F0 @ =0x00011F40
	str r0, [r1, #0x00]
	mov r12, r2
	b _0800857A
	.global _080084DC
_080084DC: .4byte 0x0202CB18
	.global _080084E0
_080084E0: .4byte 0x0202A550
	.global _080084E4
_080084E4: .4byte 0x0202CB2C
	.global _080084E8
_080084E8: .4byte 0x0202CAEC
	.global _080084EC
_080084EC: .4byte 0x0202A518
	.global _080084F0
_080084F0: .4byte 0x00011F40
	.global _080084F4
_080084F4:
	ldr r0, [r5, #0x2C]
	negs r0, r0
	asrs r4, r0, #0x0C
	cmp r4, #0x00
	bge _08008500
	movs r4, #0x00
	.global _08008500
_08008500:
	cmp r6, #0x00
	beq _08008544
	ldr r0, _08008528 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08008544
	ldr r1, _0800852C @ =0x0202CB2C
	ldr r0, _08008530 @ =0x0202A514
	ldrb r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r2, _08008534 @ =0x0202CAEC
	ldr r0, _08008538 @ =0x0202CBDC
	ldrb r0, [r0, #0x00]
	str r0, [r2, #0x00]
	ldr r1, _0800853C @ =0x0202A518
	ldr r0, _08008540 @ =0x0202A510
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	mov r12, r2
	b _0800857A
	.global _08008528
_08008528: .4byte 0x020020DC
	.global _0800852C
_0800852C: .4byte 0x0202CB2C
	.global _08008530
_08008530: .4byte 0x0202A514
	.global _08008534
_08008534: .4byte 0x0202CAEC
	.global _08008538
_08008538: .4byte 0x0202CBDC
	.global _0800853C
_0800853C: .4byte 0x0202A518
	.global _08008540
_08008540: .4byte 0x0202A510
	.global _08008544
_08008544:
	ldr r3, _08008624 @ =0x0202CB2C
	ldr r0, _08008628 @ =0x0202CAD4
	movs r2, #0xFF
	subs r2, r2, r4
	ldrb r0, [r0, #0x00]
	muls r0, r2
	ldr r1, _0800862C @ =0x0202A514
	ldrb r1, [r1, #0x00]
	muls r1, r4
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	ldr r3, _08008630 @ =0x0202CAEC
	ldr r0, _08008634 @ =0x0202CBC4
	ldrb r0, [r0, #0x00]
	muls r0, r2
	ldr r1, _08008638 @ =0x0202CBDC
	ldrb r1, [r1, #0x00]
	muls r1, r4
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	ldr r1, _0800863C @ =0x0202A518
	ldr r0, _08008640 @ =0x0202A510
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	mov r12, r3
	.global _0800857A
_0800857A:
	adds r2, r1, #0x0
	ldr r0, _08008644 @ =0x0202A550
	cmp r5, r0
	beq _0800858A
	ldr r0, _08008648 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080085BE
	.global _0800858A
_0800858A:
	movs r1, #0xB8
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080085AC
	ldr r1, _08008624 @ =0x0202CB2C
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
	.global _080085AC
_080085AC:
	ldr r4, _0800864C @ =0x00000171
	adds r0, r5, r4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080085BE
	mov r6, r12
	ldr r0, [r6, #0x00]
	asrs r0, r0, #0x01
	str r0, [r6, #0x00]
	.global _080085BE
_080085BE:
	ldr r2, _08008650 @ =0x0202CBE4
	ldrh r7, [r5, #0x34]
	lsrs r1, r7, #0x08
	subs r1, #0x40
	movs r0, #0xFF
	ands r1, r0
	str r1, [r2, #0x00]
	ldr r0, _08008654 @ =0x0202CAD8
	movs r3, #0x3C
	ldsh r2, [r5, r3]
	lsls r2, r2, #0x07
	str r2, [r0, #0x00]
	ldr r3, _08008658 @ =0x0202CBE8
	ldr r4, _0800865C @ =0x0801CD08
	lsls r0, r1, #0x01
	adds r0, r0, r4
	movs r6, #0x00
	ldsh r0, [r0, r6]
	negs r0, r0
	adds r6, r2, #0x0
	muls r6, r0
	asrs r7, r6, #0x08
	str r7, [r3, #0x00]
	ldr r3, _08008660 @ =0x0202CBEC
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
	beq _0800866C
	ldr r2, _08008664 @ =0x0202A54C
	asrs r1, r6, #0x09
	ldr r0, [r5, #0x0C]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	ldr r2, _08008668 @ =0x0202A528
	asrs r1, r4, #0x09
	ldr r0, [r5, #0x14]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	b _0800867C
	.byte 0x00, 0x00
	.global _08008624
_08008624: .4byte 0x0202CB2C
	.global _08008628
_08008628: .4byte 0x0202CAD4
	.global _0800862C
_0800862C: .4byte 0x0202A514
	.global _08008630
_08008630: .4byte 0x0202CAEC
	.global _08008634
_08008634: .4byte 0x0202CBC4
	.global _08008638
_08008638: .4byte 0x0202CBDC
	.global _0800863C
_0800863C: .4byte 0x0202A518
	.global _08008640
_08008640: .4byte 0x0202A510
	.global _08008644
_08008644: .4byte 0x0202A550
	.global _08008648
_08008648: .4byte 0x020020DC
	.global _0800864C
_0800864C: .4byte 0x00000171
	.global _08008650
_08008650: .4byte 0x0202CBE4
	.global _08008654
_08008654: .4byte 0x0202CAD8
	.global _08008658
_08008658: .4byte 0x0202CBE8
	.global _0800865C
_0800865C: .4byte 0x0801CD08
	.global _08008660
_08008660: .4byte 0x0202CBEC
	.global _08008664
_08008664: .4byte 0x0202A54C
	.global _08008668
_08008668: .4byte 0x0202A528
	.global _0800866C
_0800866C:
	ldr r1, _080086D4 @ =0x0202A54C
	ldr r0, [r5, #0x0C]
	adds r0, r0, r7
	str r0, [r1, #0x00]
	ldr r1, _080086D8 @ =0x0202A528
	ldr r0, [r5, #0x14]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _0800867C
_0800867C:
	ldr r1, _080086DC @ =0x0202CBD4
	mov r2, r12
	ldr r0, [r2, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _080086E0 @ =0x0202CB0C
	ldr r0, _080086E4 @ =0x0202CBE4
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r2, _080086E8 @ =0x0202CBF0
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
	bl sub_080087F4
	movs r4, #0xB0
	lsls r4, r4, #0x01
	adds r0, r5, r4
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080086F4
	ldr r2, _080086D4 @ =0x0202A54C
	ldr r0, _080086EC @ =0x0202CBE8
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x01
	ldr r0, [r5, #0x0C]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	ldr r2, _080086D8 @ =0x0202A528
	ldr r0, _080086F0 @ =0x0202CBEC
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x01
	ldr r0, [r5, #0x14]
	b _08008708
	.byte 0x00, 0x00
	.global _080086D4
_080086D4: .4byte 0x0202A54C
	.global _080086D8
_080086D8: .4byte 0x0202A528
	.global _080086DC
_080086DC: .4byte 0x0202CBD4
	.global _080086E0
_080086E0: .4byte 0x0202CB0C
	.global _080086E4
_080086E4: .4byte 0x0202CBE4
	.global _080086E8
_080086E8: .4byte 0x0202CBF0
	.global _080086EC
_080086EC: .4byte 0x0202CBE8
	.global _080086F0
_080086F0: .4byte 0x0202CBEC
	.global _080086F4
_080086F4:
	ldr r2, _080087CC @ =0x0202A54C
	ldr r1, _080087D0 @ =0x0202CBE8
	ldr r0, [r5, #0x0C]
	ldr r1, [r1, #0x00]
	subs r0, r0, r1
	str r0, [r2, #0x00]
	ldr r2, _080087D4 @ =0x0202A528
	ldr r1, _080087D8 @ =0x0202CBEC
	ldr r0, [r5, #0x14]
	ldr r1, [r1, #0x00]
	.global _08008708
_08008708:
	subs r0, r0, r1
	str r0, [r2, #0x00]
	ldr r1, _080087DC @ =0x0202CBD4
	ldr r0, _080087E0 @ =0x0202CB2C
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r3, _080087E4 @ =0x0202CB0C
	ldr r7, _080087E8 @ =0x0202CBE4
	ldr r1, [r7, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x80
	movs r2, #0xFF
	ands r0, r2
	str r0, [r3, #0x00]
	ldr r0, _080087EC @ =0x0202CBF0
	ands r1, r2
	str r1, [r0, #0x00]
	movs r0, #0x01
	adds r1, r5, #0x0
	bl sub_080087F4
	movs r6, #0x9E
	lsls r6, r6, #0x01
	adds r6, r6, r5
	mov r12, r6
	ldr r1, [r6, #0x00]
	cmp r1, #0x00
	beq _0800877C
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r3, r5, r0
	asrs r1, r1, #0x08
	ldr r4, _080087F0 @ =0x0801CD08
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
	.global _0800877C
_0800877C:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r6, r5, r0
	ldr r1, [r6, #0x00]
	cmp r1, #0x00
	beq _080087C6
	movs r2, #0xA0
	lsls r2, r2, #0x01
	adds r3, r5, r2
	asrs r1, r1, #0x08
	ldr r4, _080087F0 @ =0x0801CD08
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
	.global _080087C6
_080087C6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _080087CC
_080087CC: .4byte 0x0202A54C
	.global _080087D0
_080087D0: .4byte 0x0202CBE8
	.global _080087D4
_080087D4: .4byte 0x0202A528
	.global _080087D8
_080087D8: .4byte 0x0202CBEC
	.global _080087DC
_080087DC: .4byte 0x0202CBD4
	.global _080087E0
_080087E0: .4byte 0x0202CB2C
	.global _080087E4
_080087E4: .4byte 0x0202CB0C
	.global _080087E8
_080087E8: .4byte 0x0202CBE4
	.global _080087EC
_080087EC: .4byte 0x0202CBF0
	.global _080087F0
_080087F0: .4byte 0x0801CD08
	thumb_func_start sub_080087F4
sub_080087F4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r1, #0x0
	lsls r0, r0, #0x18
	ldr r3, _0800888C @ =0x0801CD08
	ldr r1, _08008890 @ =0x0202CBF0
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
	ldr r1, _08008894 @ =0x0202A54C
	ldr r1, [r1, #0x00]
	adds r2, r7, #0x0
	muls r2, r1
	ldr r1, _08008898 @ =0x0202A528
	ldr r1, [r1, #0x00]
	mov r4, r8
	muls r4, r1
	adds r1, r4, #0x0
	adds r2, r2, r1
	asrs r6, r2, #0x08
	cmp r0, #0x00
	beq _08008914
	ldr r0, _0800889C @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08008866
	adds r3, r5, #0x0
	adds r3, #0x8C
	asrs r2, r2, #0x11
	adds r1, r2, #0x0
	cmp r2, #0x00
	bge _08008850
	negs r1, r2
	.global _08008850
_08008850:
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x90
	cmp r2, #0x00
	bge _08008860
	negs r2, r2
	.global _08008860
_08008860:
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _08008866
_08008866:
	ldr r0, _080088A0 @ =0x0202A518
	ldr r2, [r0, #0x00]
	negs r1, r2
	cmp r6, r1
	bge _080088AC
	lsrs r0, r1, #0x1F
	adds r0, r1, r0
	asrs r6, r0, #0x01
	ldr r4, _080088A4 @ =0x0202CB18
	ldrb r0, [r4, #0x00]
	movs r1, #0x02
	bl sub_0800B764
	ldr r0, _080088A8 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080088C8
	b _080088D8
	.byte 0x00, 0x00
	.global _0800888C
_0800888C: .4byte 0x0801CD08
	.global _08008890
_08008890: .4byte 0x0202CBF0
	.global _08008894
_08008894: .4byte 0x0202A54C
	.global _08008898
_08008898: .4byte 0x0202A528
	.global _0800889C
_0800889C: .4byte 0x0202EEB0
	.global _080088A0
_080088A0: .4byte 0x0202A518
	.global _080088A4
_080088A4: .4byte 0x0202CB18
	.global _080088A8
_080088A8: .4byte 0x020020DC
	.global _080088AC
_080088AC:
	cmp r6, r2
	ble _08008940
	lsrs r0, r2, #0x1F
	adds r0, r2, r0
	asrs r6, r0, #0x01
	ldr r4, _080088D0 @ =0x0202CB18
	ldrb r0, [r4, #0x00]
	movs r1, #0x03
	bl sub_0800B764
	ldr r0, _080088D4 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080088D8
	.global _080088C8
_080088C8:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080088E2
	b _08008940
	.global _080088D0
_080088D0: .4byte 0x0202CB18
	.global _080088D4
_080088D4: .4byte 0x020020DC
	.global _080088D8
_080088D8:
	ldr r0, _08008904 @ =0x0202EF90
	ldrb r4, [r4, #0x00]
	ldrb r0, [r0, #0x00]
	cmp r4, r0
	bne _08008940
	.global _080088E2
_080088E2:
	ldr r0, _08008908 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08008940
	ldr r0, _0800890C @ =0x020020E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08008940
	ldr r0, _08008910 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08008940
	movs r0, #0x0B
	bl sub_08001208
	b _08008940
	.byte 0x00, 0x00
	.global _08008904
_08008904: .4byte 0x0202EF90
	.global _08008908
_08008908: .4byte 0x0202EF00
	.global _0800890C
_0800890C: .4byte 0x020020E0
	.global _08008910
_08008910: .4byte 0x020021E0
	.global _08008914
_08008914:
	ldr r0, _080089BC @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08008940
	adds r3, r5, #0x0
	adds r3, #0x94
	asrs r2, r2, #0x11
	adds r1, r2, #0x0
	cmp r2, #0x00
	bge _0800892A
	negs r1, r2
	.global _0800892A
_0800892A:
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x98
	cmp r2, #0x00
	bge _0800893A
	negs r2, r2
	.global _0800893A
_0800893A:
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _08008940
_08008940:
	ldr r0, _080089C0 @ =0x0202CBD4
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
	ldr r0, _080089C4 @ =0x0202CBF0
	ldr r0, [r0, #0x00]
	adds r0, #0x40
	ldr r1, _080089C8 @ =0x0202CB0C
	ldr r1, [r1, #0x00]
	subs r0, r0, r1
	movs r1, #0xFF
	ands r0, r1
	ldr r1, _080089CC @ =0x0801CD08
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r3, #0x00
	ldsh r0, [r0, r3]
	muls r0, r2
	asrs r2, r0, #0x08
	lsls r2, r2, #0x07
	adds r1, r2, #0x0
	cmp r2, #0x00
	bge _0800899A
	ldr r4, _080089D0 @ =0x00007FFF
	adds r1, r2, r4
	.global _0800899A
_0800899A:
	asrs r2, r1, #0x0F
	movs r0, #0xC0
	lsls r0, r0, #0x01
	adds r3, r5, r0
	ldrb r0, [r3, #0x00]
	cmp r0, #0x00
	beq _080089D4
	subs r0, #0x01
	strb r0, [r3, #0x00]
	movs r3, #0xA4
	lsls r3, r3, #0x01
	adds r2, r5, r3
	asrs r1, r1, #0x10
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	b _080089E0
	.global _080089BC
_080089BC: .4byte 0x0202EEB0
	.global _080089C0
_080089C0: .4byte 0x0202CBD4
	.global _080089C4
_080089C4: .4byte 0x0202CBF0
	.global _080089C8
_080089C8: .4byte 0x0202CB0C
	.global _080089CC
_080089CC: .4byte 0x0801CD08
	.global _080089D0
_080089D0: .4byte 0x00007FFF
	.global _080089D4
_080089D4:
	movs r4, #0xA4
	lsls r4, r4, #0x01
	adds r1, r5, r4
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _080089E0
_080089E0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x30, 0xB5, 0x02, 0x1C, 0x00, 0x24, 0x00, 0x25, 0x00, 0x2A, 0x02, 0xDA, 0x52, 0x42
	.byte 0x01, 0x24, 0x80, 0x25, 0x00, 0x29, 0x02, 0xDA, 0x49, 0x42, 0x01, 0x20, 0x44, 0x40, 0x88, 0x01
	.byte 0x51, 0x18, 0x0E, 0xF0, 0x10, 0xFC, 0x00, 0x2C, 0x00, 0xD0, 0x40, 0x42, 0x28, 0x18, 0x30, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	thumb_func_start sub_08008A20
sub_08008A20:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r4, #0x01
	ldr r0, _08008AA8 @ =0x0202A550
	mov r8, r0
	movs r2, #0x63
	ldr r0, _08008AAC @ =0x000002F2
	add r0, r8
	movs r1, #0xC8
	lsls r1, r1, #0x01
	.global _08008A36
_08008A36:
	strb r2, [r0, #0x00]
	adds r0, r0, r1
	adds r4, #0x01
	cmp r4, #0x18
	bne _08008A36
	movs r4, #0x01
	.global _08008A42
_08008A42:
	bl sub_080025FC
	movs r2, #0x1F
	ands r2, r0
	cmp r2, #0x1D
	bhi _08008A42
	movs r5, #0x00
	movs r1, #0x00
	ldr r0, _08008AA8 @ =0x0202A550
	mov r8, r0
	lsls r3, r4, #0x01
	adds r7, r4, #0x1
	mov r12, r8
	movs r6, #0xB1
	lsls r6, r6, #0x01
	.global _08008A60
_08008A60:
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	add r0, r12
	adds r0, r0, r6
	ldrb r0, [r0, #0x00]
	cmp r2, r0
	bne _08008A76
	movs r5, #0x01
	.global _08008A76
_08008A76:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x18
	bne _08008A60
	cmp r5, #0x00
	bne _08008A42
	adds r0, r3, r4
	lsls r0, r0, #0x03
	adds r0, r0, r4
	lsls r0, r0, #0x04
	add r0, r8
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r0, r0, r1
	strb r2, [r0, #0x00]
	adds r4, r7, #0x0
	cmp r4, #0x18
	bne _08008A42
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08008AA8
_08008AA8: .4byte 0x0202A550
	.global _08008AAC
_08008AAC: .4byte 0x000002F2
	thumb_func_start sub_08008AB0
sub_08008AB0:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r4, #0x01
	ldr r0, _08008B3C @ =0x0202A550
	mov r12, r0
	.global _08008ABC
_08008ABC:
	lsls r1, r4, #0x01
	adds r0, r1, r4
	lsls r0, r0, #0x03
	adds r0, r0, r4
	lsls r0, r0, #0x04
	add r0, r12
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r0, r0, r2
	adds r7, r1, #0x0
	adds r1, r4, #0x1
	mov r8, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x63
	bne _08008B2A
	.global _08008ADA
_08008ADA:
	bl sub_080025FC
	movs r2, #0x1F
	ands r2, r0
	cmp r2, #0x1D
	bhi _08008ADA
	movs r3, #0x00
	movs r1, #0x00
	ldr r0, _08008B3C @ =0x0202A550
	mov r12, r0
	mov r6, r12
	movs r5, #0xB1
	lsls r5, r5, #0x01
	.global _08008AF4
_08008AF4:
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r0, r0, r6
	adds r0, r0, r5
	ldrb r0, [r0, #0x00]
	cmp r2, r0
	bne _08008B0A
	movs r3, #0x01
	.global _08008B0A
_08008B0A:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x18
	bne _08008AF4
	cmp r3, #0x00
	bne _08008ADA
	adds r0, r7, r4
	lsls r0, r0, #0x03
	adds r0, r0, r4
	lsls r0, r0, #0x04
	add r0, r12
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r0, r0, r1
	strb r2, [r0, #0x00]
	.global _08008B2A
_08008B2A:
	mov r4, r8
	cmp r4, #0x18
	bne _08008ABC
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08008B3C
_08008B3C: .4byte 0x0202A550
	.byte 0x02, 0x1C, 0x06, 0x48, 0x00, 0x68, 0x90, 0x42, 0x0E, 0xDC, 0x05, 0x48, 0x00, 0x6D, 0x05, 0x49
	.byte 0x08, 0x40, 0x90, 0x42, 0x08, 0xD3, 0x01, 0x20, 0x07, 0xE0, 0x00, 0x00, 0x14, 0xCB, 0x02, 0x02
	.byte 0x50, 0xA5, 0x02, 0x02, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x20, 0x70, 0x47, 0x06, 0x49, 0x0A, 0x68
	.byte 0x51, 0x01, 0x89, 0x1A, 0x89, 0x00, 0x89, 0x18, 0xC9, 0x00, 0x04, 0x4A, 0x12, 0x68, 0x89, 0x18
	.byte 0x81, 0x42, 0x05, 0xDD, 0x00, 0x20, 0x04, 0xE0, 0xDC, 0xCA, 0x02, 0x02, 0x34, 0xA5, 0x02, 0x02
	.byte 0x01, 0x20, 0x70, 0x47
	thumb_func_start sub_08008B94
sub_08008B94:
	push {r4, r5, r6, lr}
	ldr r0, _08008C2C @ =0x08364B08
	ldr r6, [r0, #0x00]
	movs r0, #0x94
	lsls r0, r0, #0x02
	adds r5, r6, r0
	ldr r0, _08008C30 @ =0x0806C8E4
	movs r1, #0x08
	movs r2, #0x08
	bl sub_0800649C
	adds r0, r5, #0x0
	movs r1, #0x00
	bl sub_08005870
	movs r0, #0x95
	lsls r0, r0, #0x02
	adds r5, r6, r0
	ldr r0, _08008C34 @ =0x0202CAE4
	ldr r1, [r0, #0x00]
	adds r0, r5, #0x0
	bl sub_08005870
	ldr r0, _08008C38 @ =0x0000025A
	adds r5, r6, r0
	ldr r4, _08008C3C @ =0x0202CADC
	ldr r0, [r4, #0x00]
	movs r1, #0x0A
	bl sub_08017230
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	ldr r0, _08008C40 @ =0x0000025E
	adds r5, r6, r0
	ldr r0, [r4, #0x00]
	movs r1, #0x0A
	bl sub_080172C8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	movs r0, #0x99
	lsls r0, r0, #0x02
	adds r5, r6, r0
	ldr r4, _08008C44 @ =0x0202A534
	ldr r0, [r4, #0x00]
	movs r1, #0x64
	bl sub_08017230
	movs r1, #0x0A
	bl sub_080172C8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	movs r0, #0x9A
	lsls r0, r0, #0x02
	adds r5, r6, r0
	ldr r0, [r4, #0x00]
	movs r1, #0x0A
	bl sub_08017230
	movs r1, #0x0A
	bl sub_080172C8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _08008C2C
_08008C2C: .4byte 0x08364B08
	.global _08008C30
_08008C30: .4byte 0x0806C8E4
	.global _08008C34
_08008C34: .4byte 0x0202CAE4
	.global _08008C38
_08008C38: .4byte 0x0000025A
	.global _08008C3C
_08008C3C: .4byte 0x0202CADC
	.global _08008C40
_08008C40: .4byte 0x0000025E
	.global _08008C44
_08008C44: .4byte 0x0202A534
	thumb_func_start sub_08008C48
sub_08008C48:
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	ldr r0, _08008CB0 @ =0x08364B08
	ldr r6, [r0, #0x00]
	movs r0, #0xE5
	lsls r0, r0, #0x02
	adds r5, r6, r0
	adds r0, r4, #0x0
	movs r1, #0x64
	bl sub_08017230
	movs r1, #0x0A
	bl sub_080172C8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	movs r0, #0xE6
	lsls r0, r0, #0x02
	adds r5, r6, r0
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08017230
	movs r1, #0x0A
	bl sub_080172C8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	movs r0, #0xE7
	lsls r0, r0, #0x02
	adds r5, r6, r0
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_080172C8
	adds r1, r0, #0x0
	adds r0, r5, #0x0
	bl sub_08005870
	ldr r0, _08008CB4 @ =0x0806C8EC
	movs r1, #0x10
	movs r2, #0x0F
	bl sub_0800649C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08008CB0
_08008CB0: .4byte 0x08364B08
	.global _08008CB4
_08008CB4: .4byte 0x0806C8EC
	thumb_func_start sub_08008CB8
sub_08008CB8:
	push {lr}
	ldr r0, _08008CD4 @ =0x0806C8F0
	movs r1, #0x0A
	movs r2, #0x0E
	bl sub_0800649C
	ldr r0, _08008CD8 @ =0x0806C8F8
	movs r1, #0x0A
	movs r2, #0x0F
	bl sub_0800649C
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08008CD4
_08008CD4: .4byte 0x0806C8F0
	.global _08008CD8
_08008CD8: .4byte 0x0806C8F8
	thumb_func_start sub_08008CDC
sub_08008CDC:
	ldr r2, _08008D0C @ =0x0202A534
	ldr r3, [r2, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x28
	str r1, [r2, #0x00]
	ldr r0, _08008D10 @ =0x000003E7
	cmp r1, r0
	ble _08008D0A
	ldr r1, _08008D14 @ =0xFFFFFC40
	adds r0, r3, r1
	str r0, [r2, #0x00]
	ldr r1, _08008D18 @ =0x0202CADC
	ldr r2, [r1, #0x00]
	adds r0, r2, #0x1
	str r0, [r1, #0x00]
	cmp r0, #0x3B
	ble _08008D0A
	subs r0, #0x3C
	str r0, [r1, #0x00]
	ldr r1, _08008D1C @ =0x0202CAE4
	ldr r0, [r1, #0x00]
	adds r0, #0x01
	str r0, [r1, #0x00]
	.global _08008D0A
_08008D0A:
	bx lr
	.global _08008D0C
_08008D0C: .4byte 0x0202A534
	.global _08008D10
_08008D10: .4byte 0x000003E7
	.global _08008D14
_08008D14: .4byte 0xFFFFFC40
	.global _08008D18
_08008D18: .4byte 0x0202CADC
	.global _08008D1C
_08008D1C: .4byte 0x0202CAE4
