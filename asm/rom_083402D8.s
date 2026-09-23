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
	thumb_func_start sub_083402D8
sub_083402D8:
	push {r4, lr}
	ldr r0, _08340318 @ =0x0200D058
	movs r1, #0x0B
	movs r2, #0x07
	bl sub_0833EF0C
	ldr r4, _0834031C @ =0x0200D064
	adds r0, r4, #0x0
	movs r1, #0x06
	movs r2, #0x09
	bl sub_0833EF0C
	adds r0, r4, #0x0
	movs r1, #0x06
	movs r2, #0x0A
	bl sub_0833EF0C
	ldr r4, _08340320 @ =0x0200D07C
	adds r0, r4, #0x0
	movs r1, #0x06
	movs r2, #0x0B
	bl sub_0833EF0C
	adds r0, r4, #0x0
	movs r1, #0x0A
	movs r2, #0x0C
	bl sub_0833EF0C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08340318: .4byte 0x0200D058
_0834031C: .4byte 0x0200D064
_08340320: .4byte 0x0200D07C
	thumb_func_start sub_08340324
sub_08340324:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _08340368 @ =0x0200D098
	movs r1, #0x0B
	movs r2, #0x07
	bl sub_0833EF0C
	cmp r4, #0x00
	bne _08340344
	ldr r1, _0834036C @ =0x0203D4F0
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _0834037C
_08340344:
	ldr r0, _08340370 @ =0x02027680
	ldr r0, [r0, #0x00]
	movs r1, #0x06
	movs r2, #0x09
	bl sub_0833EF0C
	ldr r1, _08340374 @ =0x02027690
	ldr r0, _08340378 @ =0x0203DDE0
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x0D
	movs r2, #0x09
	bl sub_0833EF0C
	b _08340386
	.byte 0x00, 0x00
_08340368: .4byte 0x0200D098
_0834036C: .4byte 0x0203D4F0
_08340370: .4byte 0x02027680
_08340374: .4byte 0x02027690
_08340378: .4byte 0x0203DDE0
_0834037C:
	ldr r0, _083403B8 @ =0x0200D0A4
	movs r1, #0x06
	movs r2, #0x09
	bl sub_0833EF0C
_08340386:
	cmp r4, #0x01
	bne _08340396
	ldr r1, _083403BC @ =0x0203D4F0
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _083403CC
_08340396:
	ldr r0, _083403C0 @ =0x02027680
	ldr r0, [r0, #0x04]
	movs r1, #0x06
	movs r2, #0x0A
	bl sub_0833EF0C
	ldr r1, _083403C4 @ =0x020276A0
	ldr r0, _083403C8 @ =0x0203DDE0
	ldrb r0, [r0, #0x01]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x0D
	movs r2, #0x0A
	bl sub_0833EF0C
	b _083403D6
_083403B8: .4byte 0x0200D0A4
_083403BC: .4byte 0x0203D4F0
_083403C0: .4byte 0x02027680
_083403C4: .4byte 0x020276A0
_083403C8: .4byte 0x0203DDE0
_083403CC:
	ldr r0, _08340408 @ =0x0200D07C
	movs r1, #0x06
	movs r2, #0x0A
	bl sub_0833EF0C
_083403D6:
	cmp r4, #0x02
	bne _083403E6
	ldr r1, _0834040C @ =0x0203D4F0
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _0834041C
_083403E6:
	ldr r0, _08340410 @ =0x02027680
	ldr r0, [r0, #0x08]
	movs r1, #0x06
	movs r2, #0x0B
	bl sub_0833EF0C
	ldr r1, _08340414 @ =0x020276AC
	ldr r0, _08340418 @ =0x0203DDE0
	ldrb r0, [r0, #0x02]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x0D
	movs r2, #0x0B
	bl sub_0833EF0C
	b _08340426
_08340408: .4byte 0x0200D07C
_0834040C: .4byte 0x0203D4F0
_08340410: .4byte 0x02027680
_08340414: .4byte 0x020276AC
_08340418: .4byte 0x0203DDE0
_0834041C:
	ldr r0, _08340444 @ =0x0200D07C
	movs r1, #0x06
	movs r2, #0x0B
	bl sub_0833EF0C
_08340426:
	cmp r4, #0x03
	bne _08340436
	ldr r1, _08340448 @ =0x0203D4F0
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08340450
_08340436:
	ldr r0, _0834044C @ =0x02027680
	ldr r0, [r0, #0x0C]
	movs r1, #0x0D
	movs r2, #0x0C
	bl sub_0833EF0C
	b _0834045A
_08340444: .4byte 0x0200D07C
_08340448: .4byte 0x0203D4F0
_0834044C: .4byte 0x02027680
_08340450:
	ldr r0, _08340468 @ =0x0200D0A4
	movs r1, #0x0A
	movs r2, #0x0C
	bl sub_0833EF0C
_0834045A:
	ldr r1, _0834046C @ =0x0203D4F0
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_08340468: .4byte 0x0200D0A4
_0834046C: .4byte 0x0203D4F0
	thumb_func_start sub_08340470
sub_08340470:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08340474
sub_08340474:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08340478
sub_08340478:
	bx lr
	.byte 0x00, 0x00
