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
