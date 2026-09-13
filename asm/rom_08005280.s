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
	thumb_func_start sub_08005280
sub_08005280:
	push {r4, r5, r6, lr}
	ldr r4, _080052C4 @ =0xFFFFFE00
	add sp, r4
	ldr r1, _080052C8 @ =0x020253C4
	movs r0, #0xFF
	strb r0, [r1, #0x00]
	bl sub_08004DB4
	ldr r1, _080052CC @ =0x02025258
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08005320
	bl sub_08010094
	ldr r6, _080052D0 @ =0x020020C0
	.global _080052A2
_080052A2:
	ldr r0, _080052D4 @ =0x02002124
	movs r1, #0x00
	strh r1, [r0, #0x00]
	bl sub_08003330
	cmp r0, #0x00
	beq _080052E4
	bl sub_080017D0
	movs r5, #0x00
	ldr r4, _080052D8 @ =0x0202EF90
	.global _080052B8
_080052B8:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _080052DC
	movs r0, #0x27
	b _08005322
	.byte 0x00, 0x00
	.global _080052C4
_080052C4: .4byte 0xFFFFFE00
	.global _080052C8
_080052C8: .4byte 0x020253C4
	.global _080052CC
_080052CC: .4byte 0x02025258
	.global _080052D0
_080052D0: .4byte 0x020020C0
	.global _080052D4
_080052D4: .4byte 0x02002124
	.global _080052D8
_080052D8: .4byte 0x0202EF90
	.global _080052DC
_080052DC:
	bl sub_08016E30
	cmp r5, #0x00
	beq _080052B8
	.global _080052E4
_080052E4:
	bl sub_08004DB4
	ldr r1, _08005300 @ =0x02025258
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x00
	beq _08005304
	bl sub_0800524C
	movs r0, #0x01
	b _08005322
	.global _08005300
_08005300: .4byte 0x02025258
	.global _08005304
_08005304:
	bl sub_080051E4
	ldr r1, _0800531C @ =0x0200209C
	ldr r0, [r1, #0x00]
	adds r0, #0x01
	str r0, [r1, #0x00]
	strb r4, [r6, #0x00]
	.global _08005312
_08005312:
	ldrb r0, [r6, #0x00]
	cmp r0, #0x00
	beq _08005312
	b _080052A2
	.byte 0x00, 0x00
	.global _0800531C
_0800531C: .4byte 0x0200209C
	.global _08005320
_08005320:
	movs r0, #0x00
	.global _08005322
_08005322:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_08005338
sub_08005338:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x020
	adds r6, r0, #0x0
	adds r4, r1, #0x0
	adds r5, r2, #0x0
	adds r7, r3, #0x0
	cmp r4, #0x63
	ble _0800534E
	movs r4, #0x63
	movs r5, #0x3B
	movs r7, #0x00
	.global _0800534E
_0800534E:
	movs r0, #0x0A
	str r0, [sp, #0x008]
	str r0, [sp, #0x014]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08017230
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_080172C8
	str r0, [sp, #0x004]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl sub_08017230
	str r0, [sp, #0x00C]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl sub_080172C8
	str r0, [sp, #0x010]
	adds r0, r7, #0x0
	movs r1, #0x64
	bl sub_080172C8
	movs r1, #0x0A
	bl sub_08017230
	str r0, [sp, #0x01C]
	adds r0, r7, #0x0
	movs r1, #0x64
	bl sub_08017230
	str r0, [sp, #0x018]
	movs r4, #0x00
	mov r5, sp
	.global _0800539A
_0800539A:
	adds r0, r6, #0x4
	ldm r5!, {r1}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_080058CC
	adds r6, #0x02
	adds r4, #0x01
	cmp r4, #0x08
	bne _0800539A
	add sp, #0x020
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
