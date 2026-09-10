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
	thumb_func_start sub_080123F8
sub_080123F8:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, _08012520 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x34
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x35
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x00
	bne _0801241C
	movs r3, #0x01
	.global _0801241C
_0801241C:
	movs r1, #0x03
	movs r2, #0x05
	bl sub_080063BC
	movs r0, #0x38
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x01
	bne _08012432
	movs r3, #0x01
	.global _08012432
_08012432:
	movs r1, #0x03
	movs r2, #0x07
	bl sub_080063BC
	movs r0, #0x3A
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x02
	bne _08012448
	movs r3, #0x01
	.global _08012448
_08012448:
	movs r1, #0x03
	movs r2, #0x09
	bl sub_080063BC
	movs r0, #0x3B
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x03
	bne _0801245E
	movs r3, #0x01
	.global _0801245E
_0801245E:
	movs r1, #0x03
	movs r2, #0x0B
	bl sub_080063BC
	movs r0, #0xBF
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x04
	bne _08012474
	movs r3, #0x01
	.global _08012474
_08012474:
	movs r1, #0x03
	movs r2, #0x0D
	bl sub_080063BC
	ldr r0, _08012524 @ =0x0829F354
	movs r3, #0x00
	cmp r4, #0x05
	bne _08012486
	movs r3, #0x01
	.global _08012486
_08012486:
	movs r1, #0x03
	movs r2, #0x0F
	bl sub_080063BC
	ldr r0, _08012528 @ =0x0829F368
	movs r3, #0x00
	cmp r4, #0x00
	bne _08012498
	movs r3, #0x01
	.global _08012498
_08012498:
	movs r1, #0x15
	movs r2, #0x05
	bl sub_080063BC
	ldr r5, _0801252C @ =0x0202EF00
	ldrb r0, [r5, #0x00]
	adds r0, #0x3D
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x00
	bne _080124B2
	movs r3, #0x01
	.global _080124B2
_080124B2:
	movs r1, #0x15
	movs r2, #0x05
	bl sub_080063BC
	ldrb r0, [r5, #0x01]
	adds r0, #0xB6
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x01
	bne _080124CA
	movs r3, #0x01
	.global _080124CA
_080124CA:
	movs r1, #0x15
	movs r2, #0x07
	bl sub_080063BC
	ldrb r0, [r5, #0x02]
	adds r0, #0x41
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x02
	bne _080124E2
	movs r3, #0x01
	.global _080124E2
_080124E2:
	movs r1, #0x15
	movs r2, #0x09
	bl sub_080063BC
	ldrb r0, [r5, #0x03]
	adds r0, #0x41
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x03
	bne _080124FA
	movs r3, #0x01
	.global _080124FA
_080124FA:
	movs r1, #0x15
	movs r2, #0x0B
	bl sub_080063BC
	ldrb r0, [r5, #0x04]
	adds r0, #0x41
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x04
	bne _08012512
	movs r3, #0x01
	.global _08012512
_08012512:
	movs r1, #0x15
	movs r2, #0x0D
	bl sub_080063BC
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08012520
_08012520: .4byte 0x083FDE18
	.global _08012524
_08012524: .4byte 0x0829F354
	.global _08012528
_08012528: .4byte 0x0829F368
	.global _0801252C
_0801252C: .4byte 0x0202EF00
	thumb_func_start sub_08012530
sub_08012530:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r4, _0801258C @ =0xFFFFFE00
	add sp, r4
	movs r0, #0x00
	mov r9, r0
	movs r0, #0x07
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_080123F8
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r1, #0x40
	mov r8, r1
	.global _0801255A
_0801255A:
	bl sub_0800048C
	mov r0, r9
	lsls r4, r0, #0x18
	asrs r5, r4, #0x18
	adds r0, r5, #0x0
	bl sub_080123F8
	ldr r1, _08012590 @ =0x020005CC
	movs r0, #0x01
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08012598
	cmp r5, #0x05
	bne _08012594
	bl sub_0800F600
	bl sub_0800F6A0
	bl sub_0800F740
	mov r0, r8
	b _0801262A
	.byte 0x00, 0x00
	.global _0801258C
_0801258C: .4byte 0xFFFFFE00
	.global _08012590
_08012590: .4byte 0x020005CC
	.global _08012594
_08012594:
	lsrs r1, r4, #0x18
	mov r8, r1
	.global _08012598
_08012598:
	ldr r6, _0801263C @ =0x020005CC
	movs r0, #0x02
	ldrh r1, [r6, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080125A8
	movs r0, #0x01
	mov r8, r0
	.global _080125A8
_080125A8:
	ldrh r0, [r6, #0x00]
	asrs r1, r4, #0x18
	movs r2, #0x00
	movs r3, #0x05
	bl sub_08011D38
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	ldrh r0, [r6, #0x00]
	ldr r7, _08012640 @ =0x0202EF00
	lsrs r1, r4, #0x18
	mov r9, r1
	asrs r4, r4, #0x18
	adds r5, r4, r7
	ldrb r1, [r5, #0x00]
	ldr r2, _08012644 @ =0x083FDA60
	adds r2, r4, r2
	ldrb r2, [r2, #0x00]
	ldr r3, _08012648 @ =0x083FDA67
	adds r3, r4, r3
	ldrb r3, [r3, #0x00]
	bl sub_08011E00
	strb r0, [r5, #0x00]
	cmp r4, #0x02
	bne _08012606
	movs r4, #0x30
	adds r0, r4, #0x0
	ldrh r1, [r6, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08012606
	ldrb r0, [r7, #0x02]
	cmp r0, #0x00
	beq _080125F2
	bl sub_080100B0
	.global _080125F2
_080125F2:
	adds r0, r4, #0x0
	ldrh r6, [r6, #0x00]
	ands r0, r6
	cmp r0, #0x00
	beq _08012606
	ldrb r0, [r7, #0x02]
	cmp r0, #0x00
	bne _08012606
	bl sub_08010094
	.global _08012606
_08012606:
	bl sub_08000458
	mov r0, r8
	lsls r4, r0, #0x18
	cmp r0, #0x40
	beq _0801255A
	ldr r0, _08012640 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08012620
	movs r0, #0x09
	bl sub_08001208
	.global _08012620
_08012620:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r4, #0x18
	.global _0801262A
_0801262A:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _0801263C
_0801263C: .4byte 0x020005CC
	.global _08012640
_08012640: .4byte 0x0202EF00
	.global _08012644
_08012644: .4byte 0x083FDA60
	.global _08012648
_08012648: .4byte 0x083FDA67
	thumb_func_start sub_0801264C
sub_0801264C:
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _080126B8 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x14
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x15
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _08012670
	movs r2, #0x01
	.global _08012670
_08012670:
	movs r1, #0x08
	bl sub_08006950
	movs r0, #0x16
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _08012684
	movs r2, #0x01
	.global _08012684
_08012684:
	movs r1, #0x0A
	bl sub_08006950
	movs r0, #0x17
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x02
	bne _08012698
	movs r2, #0x01
	.global _08012698
_08012698:
	movs r1, #0x0C
	bl sub_08006950
	movs r0, #0x18
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x03
	bne _080126AC
	movs r2, #0x01
	.global _080126AC
_080126AC:
	movs r1, #0x0E
	bl sub_08006950
	pop {r4}
	pop {r0}
	bx r0
	.global _080126B8
_080126B8: .4byte 0x083FDE18
	.byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x21, 0x4C, 0xA5, 0x44, 0x00, 0x26, 0x03, 0x20, 0x69, 0x46
	.byte 0xFF, 0xF7, 0xE6, 0xFA, 0x00, 0x20, 0xFF, 0xF7, 0xBB, 0xFF, 0x68, 0x46, 0x0F, 0x21, 0xF1, 0xF7
	.byte 0xAD, 0xFD, 0x40, 0x27, 0x1A, 0x48, 0x80, 0x46, 0xED, 0xF7, 0xD2, 0xFE, 0x34, 0x06, 0x25, 0x16
	.byte 0x28, 0x1C, 0xFF, 0xF7, 0xAD, 0xFF, 0x01, 0x20, 0x41, 0x46, 0x09, 0x88, 0x08, 0x40, 0x00, 0x28
	.byte 0x02, 0xD0, 0x27, 0x0E, 0x13, 0x48, 0x06, 0x70, 0x42, 0x46, 0x10, 0x88, 0x29, 0x1C, 0x00, 0x22
	.byte 0x03, 0x23, 0xFF, 0xF7, 0x13, 0xFB, 0x00, 0x06, 0x06, 0x0E, 0xED, 0xF7, 0x9F, 0xFE, 0x3C, 0x06
	.byte 0x40, 0x2F, 0xE1, 0xD0, 0x0C, 0x48, 0xC0, 0x78, 0x00, 0x28, 0x02, 0xD0, 0x09, 0x20, 0xEE, 0xF7
	.byte 0x6D, 0xFD, 0x00, 0x20, 0x0F, 0x21, 0xF1, 0xF7, 0x6B, 0xFD, 0x20, 0x0E, 0x80, 0x23, 0x9B, 0x00
	.byte 0x9D, 0x44, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0xFE, 0xFF, 0xFF
	.byte 0xCC, 0x05, 0x00, 0x02, 0x70, 0xED, 0x02, 0x02, 0x00, 0xEF, 0x02, 0x02
