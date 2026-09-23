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
	thumb_func_start sub_080132F8
sub_080132F8:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r4, _080133C0 @ =0xFFFFFE00
	add sp, r4
	movs r6, #0x00
	ldr r0, _080133C4 @ =0x0202EF78
	strb r6, [r0, #0x00]
	strb r6, [r0, #0x01]
	strb r6, [r0, #0x02]
	strb r6, [r0, #0x03]
	strb r6, [r0, #0x04]
	movs r0, #0x06
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_080131F8
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	ldr r0, _080133C8 @ =0x0202EEB4
	strb r6, [r0, #0x00]
	movs r0, #0x40
	mov r9, r0
	movs r7, #0x01
	ldr r1, _080133CC @ =0x0202EEC0
	mov r8, r1
_08013336:
	bl sub_0800048C
	lsls r4, r6, #0x18
	lsrs r0, r4, #0x18
	bl sub_080131F8
	ldr r1, _080133D0 @ =0x020005CC
	movs r0, #0x01
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _0801342E
	bl sub_0801319C
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	beq _08013414
	cmp r1, #0x04
	bne _080133E4
	mov r0, r8
	strb r7, [r0, #0x00]
	strb r7, [r0, #0x01]
	strb r7, [r0, #0x02]
	strb r7, [r0, #0x03]
	strb r7, [r0, #0x04]
	strb r7, [r0, #0x05]
	strb r7, [r0, #0x06]
	strb r7, [r0, #0x07]
	movs r1, #0x00
	ldr r3, _080133D4 @ =0x0202EF80
	movs r2, #0x01
_0801337A:
	adds r0, r1, r3
	strb r2, [r0, #0x00]
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x0A
	bne _0801337A
	movs r1, #0x00
	ldr r3, _080133D8 @ =0x0202EDC8
	movs r2, #0x01
_0801338E:
	adds r0, r1, r3
	strb r2, [r0, #0x00]
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x04
	bne _0801338E
	movs r1, #0x00
	ldr r3, _080133DC @ =0x0202ED80
	movs r2, #0x00
_080133A2:
	adds r0, r1, r3
	strb r2, [r0, #0x00]
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x04
	bne _080133A2
	ldr r1, _080133E0 @ =0x0202EF00
	movs r0, #0x5B
	strb r0, [r1, #0x04]
	movs r0, #0x03
	bl sub_08016330
	b _080133EE
	.byte 0x00, 0x00
_080133C0: .4byte 0xFFFFFE00
_080133C4: .4byte 0x0202EF78
_080133C8: .4byte 0x0202EEB4
_080133CC: .4byte 0x0202EEC0
_080133D0: .4byte 0x020005CC
_080133D4: .4byte 0x0202EF80
_080133D8: .4byte 0x0202EDC8
_080133DC: .4byte 0x0202ED80
_080133E0: .4byte 0x0202EF00
_080133E4:
	adds r0, r1, #0x4
	add r0, r8
	strb r7, [r0, #0x00]
	bl sub_0801692C
_080133EE:
	ldr r0, _08013408 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _080133FC
	movs r0, #0x18
	bl sub_08001208
_080133FC:
	ldr r0, _0801340C @ =0x0202EEB4
	movs r1, #0x40
	strb r1, [r0, #0x00]
	ldr r0, _08013410 @ =0x0202EDB0
	strb r7, [r0, #0x00]
	b _0801342E
_08013408: .4byte 0x0202EF00
_0801340C: .4byte 0x0202EEB4
_08013410: .4byte 0x0202EDB0
_08013414:
	ldr r0, _080134D4 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08013422
	movs r0, #0x19
	bl sub_08001208
_08013422:
	ldr r1, _080134D8 @ =0x0202EEB4
	movs r0, #0x40
	strb r0, [r1, #0x00]
	ldr r1, _080134DC @ =0x0202EDB0
	movs r0, #0x00
	strb r0, [r1, #0x00]
_0801342E:
	ldr r5, _080134E0 @ =0x020005CC
	movs r0, #0x02
	ldrh r1, [r5, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _0801343E
	movs r0, #0xFF
	mov r9, r0
_0801343E:
	ldrh r0, [r5, #0x00]
	asrs r1, r4, #0x18
	movs r2, #0x00
	movs r3, #0x04
	bl sub_08011E00
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	ldrh r0, [r5, #0x00]
	ldr r1, _080134E4 @ =0x0202EF78
	lsrs r6, r4, #0x18
	asrs r4, r4, #0x18
	adds r4, r4, r1
	ldrb r1, [r4, #0x00]
	movs r2, #0x00
	movs r3, #0x09
	bl sub_08011D38
	adds r1, r0, #0x0
	strb r0, [r4, #0x00]
	movs r0, #0xC0
	ldrh r5, [r5, #0x00]
	ands r0, r5
	cmp r0, #0x00
	beq _080134A0
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x41
	beq _08013488
	cmp r0, #0x45
	beq _08013488
	cmp r0, #0x49
	beq _08013488
	cmp r0, #0x4F
	beq _08013488
	cmp r0, #0x55
	bne _080134A0
_08013488:
	ldr r0, _080134E0 @ =0x020005CC
	ldrh r0, [r0, #0x00]
	ldr r1, _080134E4 @ =0x0202EF78
	lsls r4, r6, #0x18
	asrs r4, r4, #0x18
	adds r4, r4, r1
	ldrb r1, [r4, #0x00]
	movs r2, #0x41
	movs r3, #0x5A
	bl sub_08011D38
	strb r0, [r4, #0x00]
_080134A0:
	bl sub_08000458
	mov r1, r9
	cmp r1, #0x40
	bne _080134AC
	b _08013336
_080134AC:
	ldr r0, _080134D4 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _080134BA
	movs r0, #0x09
	bl sub_08001208
_080134BA:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080134D4: .4byte 0x0202EF00
_080134D8: .4byte 0x0202EEB4
_080134DC: .4byte 0x0202EDB0
_080134E0: .4byte 0x020005CC
_080134E4: .4byte 0x0202EF78
