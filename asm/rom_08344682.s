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
	thumb_func_start sub_08344684
sub_08344684:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08344688
sub_08344688:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0834468C
sub_0834468C:
	lsls r0, r0, #0x18
	ldr r1, _08344698 @ =0x0202AF44
	lsrs r0, r0, #0x15
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bx lr
_08344698: .4byte 0x0202AF44
	thumb_func_start sub_0834469C
sub_0834469C:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r1, #0x00
	ldr r3, _083446B4 @ =0x0202AF44
_083446A4:
	lsls r0, r1, #0x03
	adds r0, r0, r3
	ldrb r0, [r0, #0x04]
	cmp r0, r2
	bne _083446B8
	adds r0, r1, #0x0
	b _083446C4
	.byte 0x00, 0x00
_083446B4: .4byte 0x0202AF44
_083446B8:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x1E
	bne _083446A4
	movs r0, #0x00
_083446C4:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_083446C8
sub_083446C8:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, r2, #0x0
	cmp r2, #0x00
	bne _083446E4
	ldr r1, _08344708 @ =0x0203E140
	movs r0, #0x01
	strb r0, [r1, #0x00]
	strb r0, [r1, #0x01]
	strb r0, [r1, #0x02]
	strb r0, [r1, #0x03]
	strb r0, [r1, #0x04]
	strb r0, [r1, #0x05]
	strb r0, [r1, #0x06]
_083446E4:
	cmp r2, #0x01
	bne _083446F4
	ldr r0, _08344708 @ =0x0203E140
	strb r2, [r0, #0x07]
	strb r2, [r0, #0x08]
	strb r2, [r0, #0x09]
	strb r2, [r0, #0x0A]
	strb r2, [r0, #0x0B]
_083446F4:
	cmp r3, #0x02
	bne _08344706
	ldr r1, _08344708 @ =0x0203E140
	movs r0, #0x01
	strb r0, [r1, #0x0C]
	strb r0, [r1, #0x0D]
	strb r0, [r1, #0x0E]
	strb r0, [r1, #0x0F]
	strb r0, [r1, #0x10]
_08344706:
	bx lr
_08344708: .4byte 0x0203E140
	thumb_func_start sub_0834470C
sub_0834470C:
	movs r1, #0x00
	ldr r2, _0834471C @ =0x0203E140
_08344710:
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08344720
	movs r0, #0x01
	b _0834472C
_0834471C: .4byte 0x0203E140
_08344720:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x11
	bne _08344710
	movs r0, #0x00
_0834472C:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08344730
sub_08344730:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08344734
sub_08344734:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08344738
sub_08344738:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0x0
	ldr r0, _0834476C @ =0x0201AA30
	bl sub_0833F018
	ldr r0, _08344770 @ =0x0201AA40
	movs r2, #0x00
	cmp r4, #0x00
	bne _08344750
	movs r2, #0x01
_08344750:
	movs r1, #0x08
	bl sub_0833F3C0
	ldr r0, _08344774 @ =0x0201AA54
	movs r2, #0x00
	cmp r4, #0x01
	bne _08344760
	movs r2, #0x01
_08344760:
	movs r1, #0x0A
	bl sub_0833F3C0
	pop {r4}
	pop {r0}
	bx r0
_0834476C: .4byte 0x0201AA30
_08344770: .4byte 0x0201AA40
_08344774: .4byte 0x0201AA54
	thumb_func_start sub_08344778
sub_08344778:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0834477C
sub_0834477C:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _083447A4 @ =0x0202B089
	adds r0, r4, r3
	ldrb r0, [r0, #0x00]
	subs r0, #0x01
	cmp r1, r0
	blt _083447AC
	bl sub_08344730
	ldr r0, _083447A8 @ =0x0203E140
	adds r0, r4, r0
	movs r1, #0x00
	strb r1, [r0, #0x00]
	movs r0, #0x01
	b _083447DA
	.byte 0x00, 0x00
_083447A4: .4byte 0x0202B089
_083447A8: .4byte 0x0203E140
_083447AC:
	movs r2, #0x00
	adds r6, r3, #0x0
	ldr r5, _083447E0 @ =0x0203E140
	movs r3, #0x01
_083447B4:
	adds r0, r2, r6
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bcs _083447C0
	adds r0, r2, r5
	strb r3, [r0, #0x00]
_083447C0:
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x11
	bne _083447B4
	bl sub_08344734
	ldr r0, _083447E4 @ =0x0202B078
	adds r0, r4, r0
	ldrb r0, [r0, #0x00]
	bl sub_083446C8
	movs r0, #0x00
_083447DA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_083447E0: .4byte 0x0203E140
_083447E4: .4byte 0x0202B078
	thumb_func_start sub_083447E8
sub_083447E8:
	ldr r0, _08344800 @ =0x020251B8
	ldr r0, [r0, #0x00]
	movs r1, #0x00
	movs r3, #0x00
	movs r2, #0xA0
	lsls r2, r2, #0x01
_083447F4:
	stm r0!, {r3}
	adds r1, #0x01
	cmp r1, r2
	bne _083447F4
	bx lr
	.byte 0x00, 0x00
_08344800: .4byte 0x020251B8
	thumb_func_start sub_08344804
sub_08344804:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r4, #0x00
	ldr r0, _08344870 @ =0x02039200
	mov r8, r0
	mov r3, r8
	ldr r2, _08344874 @ =0x0203D520
_08344814:
	lsls r0, r4, #0x02
	adds r0, r0, r3
	lsls r1, r4, #0x01
	adds r1, r1, r4
	lsls r1, r1, #0x03
	adds r1, r1, r4
	lsls r1, r1, #0x04
	adds r1, r1, r2
	str r1, [r0, #0x00]
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x05
	bne _08344814
_08344830:
	movs r0, #0x00
	mov r12, r0
	mov r6, r8
	movs r4, #0x00
	movs r7, #0xB6
	lsls r7, r7, #0x01
_0834483C:
	ldr r5, [r6, #0x00]
	ldr r3, [r6, #0x04]
	adds r0, r5, r7
	adds r1, r3, r7
	ldr r2, [r0, #0x00]
	ldr r0, [r1, #0x00]
	cmp r2, r0
	bls _08344854
	str r3, [r6, #0x00]
	str r5, [r6, #0x04]
	movs r0, #0x01
	mov r12, r0
_08344854:
	adds r6, #0x04
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x04
	bne _0834483C
	mov r0, r12
	cmp r0, #0x00
	bne _08344830
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08344870: .4byte 0x02039200
_08344874: .4byte 0x0203D520
