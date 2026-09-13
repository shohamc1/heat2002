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
