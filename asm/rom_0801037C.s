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
	.byte 0x30, 0xB5, 0x22, 0x4C, 0xA5, 0x44, 0x22, 0x48, 0x22, 0x49, 0x80, 0x22, 0x52, 0x01, 0x06, 0xF0
	.byte 0x41, 0xFD, 0xF0, 0xF7, 0x63, 0xF8, 0x20, 0x49, 0x20, 0x4A, 0x10, 0x1C, 0x08, 0x80, 0x04, 0x39
	.byte 0x1F, 0x4A, 0x10, 0x1C, 0x08, 0x80, 0x08, 0x39, 0xA8, 0x22, 0xD2, 0x00, 0x10, 0x1C, 0x08, 0x80
	.byte 0x1C, 0x48, 0xC0, 0x21, 0xC9, 0x04, 0x80, 0x22, 0xD2, 0x01, 0x06, 0xF0, 0x2B, 0xFD, 0x00, 0xF0
	.byte 0xAB, 0xF9, 0x00, 0x22, 0x18, 0x4D, 0x00, 0x24, 0xE0, 0x23, 0x9B, 0x00, 0x28, 0x68, 0x51, 0x00
	.byte 0x09, 0x18, 0x0C, 0x80, 0x50, 0x1C, 0x00, 0x04, 0x02, 0x0C, 0x9A, 0x42, 0xF6, 0xD1, 0x13, 0x48
	.byte 0x80, 0x22, 0x52, 0x00, 0x69, 0x46, 0x06, 0xF0, 0x15, 0xFD, 0x68, 0x46, 0x0F, 0x21, 0xF3, 0xF7
	.byte 0x25, 0xFF, 0xB4, 0x20, 0xFF, 0xF7, 0x58, 0xFF, 0x00, 0x20, 0x0F, 0x21, 0xF3, 0xF7, 0x08, 0xFF
	.byte 0x80, 0x23, 0x9B, 0x00, 0x9D, 0x44, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0xFE, 0xFF, 0xFF
	.byte 0x8C, 0x33, 0x33, 0x08, 0x00, 0xC0, 0x00, 0x06, 0x0C, 0x00, 0x00, 0x04, 0x81, 0x10, 0x00, 0x00
	.byte 0x0D, 0x1C, 0x00, 0x00, 0xF0, 0x76, 0x2B, 0x08, 0x08, 0x4B, 0x36, 0x08, 0x1C, 0x73, 0x2B, 0x08
	thumb_func_start sub_0801042C
sub_0801042C:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r4, _080105B4 @ =0xFFFFFE00
	add sp, r4
	ldr r6, _080105B8 @ =0x00000BB8
	ldr r0, _080105BC @ =0x0202EF00
	ldrb r0, [r0, #0x02]
	cmp r0, #0x00
	beq _08010448
	movs r0, #0x01
	bl sub_08001208
	.global _08010448
_08010448:
	ldr r1, _080105C0 @ =0x020020B4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bl sub_08000458
	ldr r1, _080105C4 @ =0x0400000C
	ldr r2, _080105C8 @ =0x00001F81
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	subs r1, #0x04
	ldr r2, _080105CC @ =0x00001C0D
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	subs r1, #0x08
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _080105D0 @ =0x082A0130
	movs r1, #0xC0
	lsls r1, r1, #0x13
	ldr r2, _080105D4 @ =0x00005140
	bl sub_08016E10
	ldr r0, _080105D8 @ =0x0833338C
	ldr r1, _080105DC @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	ldr r0, _080105E0 @ =0x0829FB54
	bl sub_08010680
	movs r2, #0x00
	ldr r5, _080105E4 @ =0x08364B08
	movs r4, #0x00
	movs r3, #0xE0
	lsls r3, r3, #0x02
	.global _08010494
_08010494:
	ldr r0, [r5, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r0
	strh r4, [r1, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r3
	bne _08010494
	ldr r0, _080105E8 @ =0x0829F954
	movs r2, #0x80
	lsls r2, r2, #0x01
	mov r1, sp
	bl sub_08016E10
	ldr r4, _080105EC @ =0x08332BC8
	add r1, sp, #0x1E0
	adds r0, r4, #0x0
	movs r2, #0x10
	bl sub_08016E10
	add r1, sp, #0x1C0
	adds r0, r4, #0x0
	movs r2, #0x10
	bl sub_08016E10
	movs r0, #0x34
	movs r1, #0x34
	movs r2, #0x34
	bl sub_08011C44
	add r1, sp, #0x1D4
	strh r0, [r1, #0x00]
	movs r0, #0x24
	movs r1, #0x24
	movs r2, #0x24
	bl sub_08011C44
	movs r1, #0xEB
	lsls r1, r1, #0x01
	add r1, sp
	strh r0, [r1, #0x00]
	movs r0, #0x0E
	movs r1, #0x0E
	movs r2, #0x0E
	bl sub_08011C44
	add r1, sp, #0x1D8
	strh r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl sub_08011C44
	movs r1, #0xED
	lsls r1, r1, #0x01
	add r1, sp
	strh r0, [r1, #0x00]
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r5, #0x00
	ldr r1, _080105F0 @ =0x020005C8
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08010596
	cmp r6, #0x00
	beq _0801059A
	ldr r0, _080105E4 @ =0x08364B08
	mov r9, r0
	movs r1, #0x00
	mov r8, r1
	movs r7, #0xE0
	lsls r7, r7, #0x02
	.global _0801052E
_0801052E:
	bl sub_0800048C
	movs r2, #0x00
	adds r4, r5, #0x1
	subs r6, #0x01
	.global _08010538
_08010538:
	mov r1, r9
	ldr r0, [r1, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r0
	mov r0, r8
	strh r0, [r1, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r7
	bne _08010538
	movs r0, #0x1F
	ands r5, r0
	cmp r5, #0x0E
	bhi _08010564
	movs r0, #0x0F
	bl sub_08016558
	movs r1, #0x10
	movs r2, #0x01
	bl sub_08006950
	.global _08010564
_08010564:
	lsls r0, r4, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _080105F0 @ =0x020005C8
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08010582
	ldr r0, _080105BC @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08010582
	movs r0, #0x09
	bl sub_08001208
	.global _08010582
_08010582:
	bl sub_08000458
	ldr r1, _080105F0 @ =0x020005C8
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08010596
	cmp r6, #0x00
	bne _0801052E
	.global _08010596
_08010596:
	cmp r6, #0x00
	bne _080105A2
	.global _0801059A
_0801059A:
	ldr r0, _080105F4 @ =0x02001F20
	movs r1, #0x02
	bl sub_080013A0
	.global _080105A2
_080105A2:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	cmp r6, #0x00
	beq _080105F8
	movs r0, #0x00
	b _080105FA
	.byte 0x00, 0x00
	.global _080105B4
_080105B4: .4byte 0xFFFFFE00
	.global _080105B8
_080105B8: .4byte 0x00000BB8
	.global _080105BC
_080105BC: .4byte 0x0202EF00
	.global _080105C0
_080105C0: .4byte 0x020020B4
	.global _080105C4
_080105C4: .4byte 0x0400000C
	.global _080105C8
_080105C8: .4byte 0x00001F81
	.global _080105CC
_080105CC: .4byte 0x00001C0D
	.global _080105D0
_080105D0: .4byte 0x082A0130
	.global _080105D4
_080105D4: .4byte 0x00005140
	.global _080105D8
_080105D8: .4byte 0x0833338C
	.global _080105DC
_080105DC: .4byte 0x0600C000
	.global _080105E0
_080105E0: .4byte 0x0829FB54
	.global _080105E4
_080105E4: .4byte 0x08364B08
	.global _080105E8
_080105E8: .4byte 0x0829F954
	.global _080105EC
_080105EC: .4byte 0x08332BC8
	.global _080105F0
_080105F0: .4byte 0x020005C8
	.global _080105F4
_080105F4: .4byte 0x02001F20
	.global _080105F8
_080105F8:
	movs r0, #0x01
	.global _080105FA
_080105FA:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start sub_0801060C
sub_0801060C:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r4, _08010658 @ =0x0202EEFC
	bl sub_0800E730
	strb r0, [r4, #0x00]
	ldr r0, _0801065C @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x59
	bl sub_08016558
	bl sub_080065A8
	movs r4, #0x00
	movs r6, #0x05
	ldr r5, _08010660 @ =0x083FDE5E
	.global _08010632
_08010632:
	ldrh r0, [r5, #0x00]
	bl sub_08016558
	movs r2, #0x00
	cmp r7, r4
	bne _08010640
	movs r2, #0x01
	.global _08010640
_08010640:
	adds r1, r6, #0x0
	bl sub_08006950
	adds r6, #0x02
	adds r5, #0x02
	adds r4, #0x01
	cmp r4, #0x07
	bne _08010632
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08010658
_08010658: .4byte 0x0202EEFC
	.global _0801065C
_0801065C: .4byte 0x083FDE18
	.global _08010660
_08010660: .4byte 0x083FDE5E
