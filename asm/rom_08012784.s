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
	.byte 0x70, 0xB5, 0x15, 0x4C, 0xA5, 0x44, 0x00, 0x20, 0x69, 0x46, 0xFF, 0xF7, 0x85, 0xFA, 0x00, 0x20
	.byte 0xFF, 0xF7, 0xE0, 0xFF, 0x68, 0x46, 0x0F, 0x21, 0xF1, 0xF7, 0x4C, 0xFD, 0x40, 0x26, 0x00, 0x25
	.byte 0xED, 0xF7, 0x72, 0xFE, 0x28, 0x16, 0xFF, 0xF7, 0xD5, 0xFF, 0x0C, 0x49, 0x01, 0x20, 0x09, 0x88
	.byte 0x08, 0x40, 0x00, 0x28, 0x00, 0xD0, 0x2E, 0x0E, 0xED, 0xF7, 0x4C, 0xFE, 0x34, 0x06, 0x00, 0x2C
	.byte 0xEE, 0xD1, 0x00, 0x20, 0x0F, 0x21, 0xF1, 0xF7, 0x1F, 0xFD, 0x20, 0x0E, 0x80, 0x23, 0x9B, 0x00
	.byte 0x9D, 0x44, 0x70, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0xFE, 0xFF, 0xFF, 0xCC, 0x05, 0x00, 0x02
	thumb_func_start sub_080127E4
sub_080127E4:
	push {r4, lr}
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0x14
	bl sub_08016558
	bl sub_080065A8
	cmp r4, #0x00
	beq _0801284C
	movs r0, #0x17
	bl sub_08016558
	movs r1, #0x00
	movs r2, #0x09
	movs r3, #0x01
	bl sub_080063BC
	movs r0, #0x18
	bl sub_08016558
	movs r1, #0x00
	movs r2, #0x0A
	movs r3, #0x01
	bl sub_080063BC
	movs r0, #0x19
	bl sub_08016558
	movs r1, #0x00
	movs r2, #0x0B
	movs r3, #0x01
	bl sub_080063BC
	ldr r1, _08012844 @ =0x083FDD8C
	ldr r0, _08012848 @ =0x0202EDD8
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x00
	movs r2, #0x0D
	movs r3, #0x01
	bl sub_080063BC
	b _0801286C
	.byte 0x00, 0x00
	.global _08012844
_08012844: .4byte 0x083FDD8C
	.global _08012848
_08012848: .4byte 0x0202EDD8
	.global _0801284C
_0801284C:
	movs r0, #0x15
	bl sub_08016558
	movs r1, #0x00
	movs r2, #0x0D
	movs r3, #0x01
	bl sub_080063BC
	movs r0, #0x16
	bl sub_08016558
	movs r1, #0x00
	movs r2, #0x0E
	movs r3, #0x01
	bl sub_080063BC
	.global _0801286C
_0801286C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start sub_08012874
sub_08012874:
	push {r4, r5, lr}
	ldr r4, _080128D4 @ =0xFFFFFE00
	add sp, r4
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl sub_0800F3A4
	bl sub_0800F498
	ldr r0, _080128D8 @ =0x082EE104
	mov r1, sp
	bl sub_0800F328
	adds r0, r4, #0x0
	bl sub_080127E4
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r5, #0x40
	.global _080128A0
_080128A0:
	bl sub_0800048C
	adds r0, r4, #0x0
	bl sub_080127E4
	ldr r1, _080128DC @ =0x020005CC
	movs r0, #0x01
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080128B8
	adds r5, r4, #0x0
	.global _080128B8
_080128B8:
	bl sub_08000458
	cmp r5, #0x40
	beq _080128A0
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _080128D4
_080128D4: .4byte 0xFFFFFE00
	.global _080128D8
_080128D8: .4byte 0x082EE104
	.global _080128DC
_080128DC: .4byte 0x020005CC
	thumb_func_start sub_080128E0
sub_080128E0:
	push {r4, r5, lr}
	ldr r1, _0801295C @ =0x02002184
	movs r0, #0x02
	strb r0, [r1, #0x00]
	ldr r3, _08012960 @ =0x0202ED84
	ldr r1, _08012964 @ =0x083FDD48
	ldr r2, _08012968 @ =0x0202EDD8
	ldrb r4, [r2, #0x00]
	lsls r0, r4, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r3, #0x00]
	ldr r4, _0801296C @ =0x020020CC
	ldr r0, _08012970 @ =0x083FDD34
	ldrb r2, [r2, #0x00]
	adds r0, r2, r0
	ldrb r0, [r0, #0x00]
	strb r0, [r4, #0x00]
	ldr r5, _08012974 @ =0x0202EEE4
	movs r0, #0x00
	strb r0, [r5, #0x00]
	ldr r1, _08012978 @ =0x0202A550
	movs r0, #0xB6
	lsls r0, r0, #0x01
	adds r2, r1, r0
	movs r0, #0x00
	str r0, [r2, #0x00]
	adds r1, #0x7D
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bl sub_08008A20
	movs r0, #0x01
	bl sub_08016D28
	bl sub_0800F3C0
	ldrb r1, [r4, #0x00]
	movs r0, #0x00
	bl sub_08011168
	ldr r2, _0801297C @ =0x0202CDA8
	movs r0, #0x00
	movs r1, #0x0D
	bl sub_0800295C
	ldr r0, _08012980 @ =0x0202EF00
	ldrb r0, [r0, #0x02]
	cmp r0, #0x00
	beq _0801294A
	movs r0, #0x03
	bl sub_08001208
	.global _0801294A
_0801294A:
	bl sub_08015304
	ldrb r0, [r5, #0x00]
	bl sub_08012874
	ldrb r0, [r5, #0x00]
	pop {r4, r5}
	pop {r1}
	bx r1
	.global _0801295C
_0801295C: .4byte 0x02002184
	.global _08012960
_08012960: .4byte 0x0202ED84
	.global _08012964
_08012964: .4byte 0x083FDD48
	.global _08012968
_08012968: .4byte 0x0202EDD8
	.global _0801296C
_0801296C: .4byte 0x020020CC
	.global _08012970
_08012970: .4byte 0x083FDD34
	.global _08012974
_08012974: .4byte 0x0202EEE4
	.global _08012978
_08012978: .4byte 0x0202A550
	.global _0801297C
_0801297C: .4byte 0x0202CDA8
	.global _08012980
_08012980: .4byte 0x0202EF00
	thumb_func_start sub_08012984
sub_08012984:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080129D0 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0xA9
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0xC5
	bl sub_08016558
	movs r1, #0x06
	movs r2, #0x01
	bl sub_08006950
	adds r0, r4, #0x0
	adds r0, #0xC5
	bl sub_08016558
	movs r1, #0x07
	movs r2, #0x01
	bl sub_08006950
	cmp r4, #0x04
	beq _080129D4
	adds r0, r4, #0x0
	adds r0, #0xAA
	bl sub_08016558
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006950
	b _080129E2
	.global _080129D0
_080129D0: .4byte 0x083FDE18
	.global _080129D4
_080129D4:
	movs r0, #0xB3
	bl sub_08016558
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006950
	.global _080129E2
_080129E2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_start sub_080129E8
sub_080129E8:
	push {r4, r5, r6, r7, lr}
	ldr r4, _08012A44 @ =0xFFFFFE00
	add sp, r4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r7, #0x00
	movs r0, #0x03
	mov r1, sp
	bl sub_08011C9C
	adds r0, r6, #0x0
	bl sub_08012984
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r5, #0x40
	.global _08012A0C
_08012A0C:
	bl sub_0800048C
	adds r0, r6, #0x0
	bl sub_08012984
	ldr r1, _08012A48 @ =0x020005CC
	movs r0, #0x01
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08012A24
	movs r5, #0x00
	.global _08012A24
_08012A24:
	bl sub_08000458
	lsls r4, r5, #0x18
	cmp r4, #0x00
	bne _08012A0C
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r4, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _08012A44
_08012A44: .4byte 0xFFFFFE00
	.global _08012A48
_08012A48: .4byte 0x020005CC
