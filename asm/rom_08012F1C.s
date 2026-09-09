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
	.byte 0xF0, 0xB5, 0x20, 0x4C, 0xA5, 0x44, 0x00, 0x24, 0x03, 0x20, 0x69, 0x46, 0xFE, 0xF7, 0xB8, 0xFE
	.byte 0x1D, 0x48, 0x01, 0x78, 0x00, 0x20, 0xFF, 0xF7, 0xD9, 0xFF, 0x68, 0x46, 0x0F, 0x21, 0xF1, 0xF7
	.byte 0x7D, 0xF9, 0x40, 0x26, 0x19, 0x4F, 0xED, 0xF7, 0xA3, 0xFA, 0x25, 0x06, 0x2C, 0x0E, 0x16, 0x48
	.byte 0x01, 0x78, 0x20, 0x1C, 0xFF, 0xF7, 0xCA, 0xFF, 0x01, 0x20, 0x39, 0x88, 0x08, 0x40, 0x00, 0x28
	.byte 0x00, 0xD0, 0x26, 0x1C, 0x38, 0x88, 0x29, 0x16, 0x00, 0x22, 0x03, 0x23, 0xFE, 0xF7, 0xE6, 0xFE
	.byte 0x00, 0x06, 0x04, 0x0E, 0xED, 0xF7, 0x72, 0xFA, 0x35, 0x06, 0x40, 0x2E, 0xE3, 0xD0, 0x0C, 0x48
	.byte 0xC0, 0x78, 0x00, 0x28, 0x02, 0xD0, 0x09, 0x20, 0xEE, 0xF7, 0x40, 0xF9, 0x00, 0x20, 0x0F, 0x21
	.byte 0xF1, 0xF7, 0x3E, 0xF9, 0x28, 0x0E, 0x80, 0x23, 0x9B, 0x00, 0x9D, 0x44, 0xF0, 0xBC, 0x02, 0xBC
	.byte 0x08, 0x47, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x70, 0xED, 0x02, 0x02, 0xCC, 0x05, 0x00, 0x02
	.byte 0x00, 0xEF, 0x02, 0x02
	thumb_func_start sub_08012FB0
sub_08012FB0:
	push {lr}
	ldr r0, _08013038 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x23
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x07
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x08
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x09
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x0B
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x0C
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x0D
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x0E
	movs r2, #0x01
	bl sub_08006950
	pop {r0}
	bx r0
	.global _08013038
_08013038: .4byte 0x083FDE18
	.byte 0xF0, 0xB5, 0x1C, 0x4C, 0xA5, 0x44, 0x00, 0x25, 0x03, 0x20, 0x69, 0x46, 0xFE, 0xF7, 0x28, 0xFE
	.byte 0xFF, 0xF7, 0xB0, 0xFF, 0x68, 0x46, 0x0F, 0x21, 0xF1, 0xF7, 0xF0, 0xF8, 0x40, 0x24, 0x16, 0x4F
	.byte 0xED, 0xF7, 0x16, 0xFA, 0xFF, 0xF7, 0xA6, 0xFF, 0x01, 0x20, 0x39, 0x88, 0x08, 0x40, 0x29, 0x06
	.byte 0x00, 0x28, 0x00, 0xD0, 0x0C, 0x0E, 0x38, 0x88, 0x09, 0x16, 0x00, 0x22, 0x00, 0x23, 0xFE, 0xF7
	.byte 0x5D, 0xFE, 0x00, 0x06, 0x05, 0x0E, 0xED, 0xF7, 0xE9, 0xF9, 0x26, 0x06, 0x40, 0x2C, 0xE7, 0xD0
	.byte 0x0A, 0x48, 0xC0, 0x78, 0x00, 0x28, 0x02, 0xD0, 0x09, 0x20, 0xEE, 0xF7, 0xB7, 0xF8, 0x00, 0x20
	.byte 0x0F, 0x21, 0xF1, 0xF7, 0xB5, 0xF8, 0x30, 0x0E, 0x80, 0x23, 0x9B, 0x00, 0x9D, 0x44, 0xF0, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47, 0x00, 0xFE, 0xFF, 0xFF, 0xCC, 0x05, 0x00, 0x02, 0x00, 0xEF, 0x02, 0x02
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_080130C8
sub_080130C8:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0x0
	ldr r0, _08013110 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x0B
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x05
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _080130F0
	movs r2, #0x01
	.global _080130F0
_080130F0:
	movs r1, #0x08
	bl sub_08006950
	movs r0, #0x08
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _08013104
	movs r2, #0x01
	.global _08013104
_08013104:
	movs r1, #0x0B
	bl sub_08006950
	pop {r4}
	pop {r0}
	bx r0
	.global _08013110
_08013110: .4byte 0x083FDE18
	.byte 0xF0, 0xB5, 0x1E, 0x4C, 0xA5, 0x44, 0x00, 0x24, 0x03, 0x20, 0x69, 0x46, 0xFE, 0xF7, 0xBC, 0xFD
	.byte 0x00, 0x20, 0xFF, 0xF7, 0xCF, 0xFF, 0x68, 0x46, 0x0F, 0x21, 0xF1, 0xF7, 0x83, 0xF8, 0x40, 0x26
	.byte 0x17, 0x4F, 0xED, 0xF7, 0xA9, 0xF9, 0x25, 0x06, 0x2C, 0x0E, 0x20, 0x1C, 0xFF, 0xF7, 0xC2, 0xFF
	.byte 0x01, 0x20, 0x39, 0x88, 0x08, 0x40, 0x00, 0x28, 0x00, 0xD0, 0x26, 0x1C, 0x38, 0x88, 0x29, 0x16
	.byte 0x00, 0x22, 0x01, 0x23, 0xFE, 0xF7, 0xEE, 0xFD, 0x00, 0x06, 0x04, 0x0E, 0xED, 0xF7, 0x7A, 0xF9
	.byte 0x35, 0x06, 0x40, 0x2E, 0xE5, 0xD0, 0x0B, 0x48, 0xC0, 0x78, 0x00, 0x28, 0x02, 0xD0, 0x09, 0x20
	.byte 0xEE, 0xF7, 0x48, 0xF8, 0x00, 0x20, 0x0F, 0x21, 0xF1, 0xF7, 0x46, 0xF8, 0x28, 0x0E, 0x80, 0x23
	.byte 0x9B, 0x00, 0x9D, 0x44, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF
	.byte 0xCC, 0x05, 0x00, 0x02, 0x00, 0xEF, 0x02, 0x02
	thumb_func_start sub_0801319C
sub_0801319C:
	push {r4, r5, r6, r7, lr}
	movs r1, #0x00
	ldr r2, _080131DC @ =0x0202EF78
	adds r5, r2, #0x0
	ldrb r3, [r2, #0x00]
	ldr r4, _080131E0 @ =0x083FE080
	.global _080131A8
_080131A8:
	lsls r0, r1, #0x02
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	ldrb r6, [r0, #0x00]
	cmp r6, r3
	bne _080131E4
	ldrb r7, [r0, #0x01]
	ldrb r6, [r5, #0x01]
	cmp r7, r6
	bne _080131E4
	ldrb r7, [r0, #0x02]
	ldrb r6, [r2, #0x02]
	cmp r7, r6
	bne _080131E4
	ldrb r7, [r0, #0x03]
	ldrb r6, [r2, #0x03]
	cmp r7, r6
	bne _080131E4
	ldrb r0, [r0, #0x04]
	ldrb r7, [r2, #0x04]
	cmp r0, r7
	bne _080131E4
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	b _080131F2
	.byte 0x00, 0x00
	.global _080131DC
_080131DC: .4byte 0x0202EF78
	.global _080131E0
_080131E0: .4byte 0x083FE080
	.global _080131E4
_080131E4:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x05
	bne _080131A8
	movs r0, #0x01
	negs r0, r0
	.global _080131F2
_080131F2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start sub_080131F8
sub_080131F8:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x014
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r7, r5, #0x0
	add r4, sp, #0x010
	movs r0, #0x00
	strb r0, [r4, #0x01]
	ldr r0, _080132C4 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x6B
	bl sub_08016558
	bl sub_080065A8
	ldr r6, _080132C8 @ =0x0202EF78
	ldrb r1, [r6, #0x00]
	lsls r0, r1, #0x01
	subs r0, #0x80
	strb r0, [r4, #0x00]
	movs r3, #0x00
	cmp r5, #0x00
	bne _0801322C
	movs r3, #0x01
	.global _0801322C
_0801322C:
	adds r0, r4, #0x0
	movs r1, #0x04
	movs r2, #0x07
	bl sub_080064F8
	ldrb r1, [r6, #0x01]
	lsls r0, r1, #0x01
	subs r0, #0x80
	strb r0, [r4, #0x00]
	movs r3, #0x00
	cmp r5, #0x01
	bne _08013246
	movs r3, #0x01
	.global _08013246
_08013246:
	adds r0, r4, #0x0
	movs r1, #0x09
	movs r2, #0x07
	bl sub_080064F8
	ldrb r1, [r6, #0x02]
	lsls r0, r1, #0x01
	subs r0, #0x80
	strb r0, [r4, #0x00]
	movs r3, #0x00
	cmp r5, #0x02
	bne _08013260
	movs r3, #0x01
	.global _08013260
_08013260:
	adds r0, r4, #0x0
	movs r1, #0x0E
	movs r2, #0x07
	bl sub_080064F8
	ldrb r1, [r6, #0x03]
	lsls r0, r1, #0x01
	subs r0, #0x80
	strb r0, [r4, #0x00]
	movs r3, #0x00
	cmp r5, #0x03
	bne _0801327A
	movs r3, #0x01
	.global _0801327A
_0801327A:
	adds r0, r4, #0x0
	movs r1, #0x13
	movs r2, #0x07
	bl sub_080064F8
	ldrb r6, [r6, #0x04]
	lsls r0, r6, #0x01
	subs r0, #0x80
	strb r0, [r4, #0x00]
	movs r3, #0x00
	cmp r7, #0x04
	bne _08013294
	movs r3, #0x01
	.global _08013294
_08013294:
	adds r0, r4, #0x0
	movs r1, #0x18
	movs r2, #0x07
	bl sub_080064F8
	ldr r0, _080132CC @ =0x0202EEB4
	ldrb r1, [r0, #0x00]
	cmp r1, #0x00
	beq _080132E8
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _080132D4
	ldr r0, _080132D0 @ =0x0202EDB0
	ldrb r0, [r0, #0x00]
	adds r0, #0x6C
	bl sub_08016558
	movs r1, #0x0F
	movs r2, #0x01
	bl sub_08006950
	b _080132E0
	.byte 0x00, 0x00
	.global _080132C4
_080132C4: .4byte 0x083FDE18
	.global _080132C8
_080132C8: .4byte 0x0202EF78
	.global _080132CC
_080132CC: .4byte 0x0202EEB4
	.global _080132D0
_080132D0: .4byte 0x0202EDB0
	.global _080132D4
_080132D4:
	ldr r0, _080132F0 @ =0x0829F2AC
	movs r1, #0x00
	movs r2, #0x0F
	movs r3, #0x00
	bl sub_080063BC
	.global _080132E0
_080132E0:
	ldr r1, _080132F4 @ =0x0202EEB4
	ldrb r0, [r1, #0x00]
	subs r0, #0x01
	strb r0, [r1, #0x00]
	.global _080132E8
_080132E8:
	add sp, #0x014
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _080132F0
_080132F0: .4byte 0x0829F2AC
	.global _080132F4
_080132F4: .4byte 0x0202EEB4
	.byte 0xF0, 0xB5, 0x4F, 0x46, 0x46, 0x46, 0xC0, 0xB4, 0x2F, 0x4C, 0xA5, 0x44, 0x00, 0x26, 0x2F, 0x48
	.byte 0x06, 0x70, 0x46, 0x70, 0x86, 0x70, 0xC6, 0x70, 0x06, 0x71, 0x06, 0x20, 0x69, 0x46, 0xFE, 0xF7
	.byte 0xC1, 0xFC, 0x00, 0x20, 0xFF, 0xF7, 0x6C, 0xFF, 0x68, 0x46, 0x0F, 0x21, 0xF0, 0xF7, 0x88, 0xFF
	.byte 0x27, 0x48, 0x06, 0x70, 0x40, 0x20, 0x81, 0x46, 0x01, 0x27, 0x26, 0x49, 0x88, 0x46, 0xED, 0xF7
	.byte 0xA9, 0xF8, 0x34, 0x06, 0x20, 0x0E, 0xFF, 0xF7, 0x5B, 0xFF, 0x23, 0x49, 0x01, 0x20, 0x09, 0x88
	.byte 0x08, 0x40, 0x00, 0x28, 0x6F, 0xD0, 0xFF, 0xF7, 0x25, 0xFF, 0x00, 0x06, 0x01, 0x16, 0x01, 0x20
	.byte 0x40, 0x42, 0x81, 0x42, 0x5A, 0xD0, 0x04, 0x29, 0x40, 0xD1, 0x40, 0x46, 0x07, 0x70, 0x47, 0x70
	.byte 0x87, 0x70, 0xC7, 0x70, 0x07, 0x71, 0x47, 0x71, 0x87, 0x71, 0xC7, 0x71, 0x00, 0x21, 0x17, 0x4B
	.byte 0x01, 0x22, 0xC8, 0x18, 0x02, 0x70, 0x48, 0x1C, 0x00, 0x06, 0x01, 0x0E, 0x0A, 0x29, 0xF8, 0xD1
	.byte 0x00, 0x21, 0x13, 0x4B, 0x01, 0x22, 0xC8, 0x18, 0x02, 0x70, 0x48, 0x1C, 0x00, 0x06, 0x01, 0x0E
	.byte 0x04, 0x29, 0xF8, 0xD1, 0x00, 0x21, 0x0F, 0x4B, 0x00, 0x22, 0xC8, 0x18, 0x02, 0x70, 0x48, 0x1C
	.byte 0x00, 0x06, 0x01, 0x0E, 0x04, 0x29, 0xF8, 0xD1, 0x0B, 0x49, 0x5B, 0x20, 0x08, 0x71, 0x03, 0x20
	.byte 0x02, 0xF0, 0xBA, 0xFF, 0x17, 0xE0, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x78, 0xEF, 0x02, 0x02
	.byte 0xB4, 0xEE, 0x02, 0x02, 0xC0, 0xEE, 0x02, 0x02, 0xCC, 0x05, 0x00, 0x02, 0x80, 0xEF, 0x02, 0x02
	.byte 0xC8, 0xED, 0x02, 0x02, 0x80, 0xED, 0x02, 0x02, 0x00, 0xEF, 0x02, 0x02, 0x08, 0x1D, 0x40, 0x44
	.byte 0x07, 0x70, 0x03, 0xF0, 0x9F, 0xFA, 0x06, 0x48, 0xC0, 0x78, 0x00, 0x28, 0x02, 0xD0, 0x18, 0x20
	.byte 0xED, 0xF7, 0x06, 0xFF, 0x03, 0x48, 0x40, 0x21, 0x01, 0x70, 0x03, 0x48, 0x07, 0x70, 0x12, 0xE0
	.byte 0x00, 0xEF, 0x02, 0x02, 0xB4, 0xEE, 0x02, 0x02, 0xB0, 0xED, 0x02, 0x02, 0x2F, 0x48, 0xC0, 0x78
	.byte 0x00, 0x28, 0x02, 0xD0, 0x19, 0x20, 0xED, 0xF7, 0xF3, 0xFE, 0x2D, 0x49, 0x40, 0x20, 0x08, 0x70
	.byte 0x2C, 0x49, 0x00, 0x20, 0x08, 0x70, 0x2C, 0x4D, 0x02, 0x20, 0x29, 0x88, 0x08, 0x40, 0x00, 0x28
	.byte 0x01, 0xD0, 0xFF, 0x20, 0x81, 0x46, 0x28, 0x88, 0x21, 0x16, 0x00, 0x22, 0x04, 0x23, 0xFE, 0xF7
	.byte 0xDB, 0xFC, 0x04, 0x1C, 0x24, 0x06, 0x28, 0x88, 0x24, 0x49, 0x26, 0x0E, 0x24, 0x16, 0x64, 0x18
	.byte 0x21, 0x78, 0x00, 0x22, 0x09, 0x23, 0xFE, 0xF7, 0x6B, 0xFC, 0x01, 0x1C, 0x20, 0x70, 0xC0, 0x20
	.byte 0x2D, 0x88, 0x28, 0x40, 0x00, 0x28, 0x17, 0xD0, 0x08, 0x06, 0x00, 0x0E, 0x41, 0x28, 0x07, 0xD0
	.byte 0x45, 0x28, 0x05, 0xD0, 0x49, 0x28, 0x03, 0xD0, 0x4F, 0x28, 0x01, 0xD0, 0x55, 0x28, 0x0B, 0xD1
	.byte 0x15, 0x48, 0x00, 0x88, 0x15, 0x49, 0x34, 0x06, 0x24, 0x16, 0x64, 0x18, 0x21, 0x78, 0x41, 0x22
	.byte 0x5A, 0x23, 0xFE, 0xF7, 0x4D, 0xFC, 0x20, 0x70, 0xEC, 0xF7, 0xDA, 0xFF, 0x49, 0x46, 0x40, 0x29
	.byte 0x00, 0xD1, 0x44, 0xE7, 0x09, 0x48, 0xC0, 0x78, 0x00, 0x28, 0x02, 0xD0, 0x09, 0x20, 0xED, 0xF7
	.byte 0xA7, 0xFE, 0x00, 0x20, 0x0F, 0x21, 0xF0, 0xF7, 0xA5, 0xFE, 0x80, 0x23, 0x9B, 0x00, 0x9D, 0x44
	.byte 0x18, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0xEF, 0x02, 0x02
	.byte 0xB4, 0xEE, 0x02, 0x02, 0xB0, 0xED, 0x02, 0x02, 0xCC, 0x05, 0x00, 0x02, 0x78, 0xEF, 0x02, 0x02
	thumb_func_start sub_080134E8
sub_080134E8:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0x0
	ldr r0, _08013568 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x00
	bl sub_08016558
	bl sub_080065A8
	ldr r0, _0801356C @ =0x0829F3BC
	movs r2, #0x00
	cmp r4, #0x00
	bne _0801350C
	movs r2, #0x01
	.global _0801350C
_0801350C:
	movs r1, #0x06
	bl sub_08006950
	movs r0, #0x02
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _08013520
	movs r2, #0x01
	.global _08013520
_08013520:
	movs r1, #0x08
	bl sub_08006950
	movs r0, #0x03
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x02
	bne _08013534
	movs r2, #0x01
	.global _08013534
_08013534:
	movs r1, #0x0A
	bl sub_08006950
	movs r0, #0x60
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x03
	bne _08013548
	movs r2, #0x01
	.global _08013548
_08013548:
	movs r1, #0x0C
	bl sub_08006950
	movs r0, #0x08
	bl sub_08016558
	movs r2, #0x00
	cmp r5, #0x04
	bne _0801355C
	movs r2, #0x01
	.global _0801355C
_0801355C:
	movs r1, #0x0E
	bl sub_08006950
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08013568
_08013568: .4byte 0x083FDE18
	.global _0801356C
_0801356C: .4byte 0x0829F3BC
	thumb_func_start sub_08013570
sub_08013570:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r4, _08013630 @ =0xFFFFFE00
	add sp, r4
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	movs r6, #0x00
	movs r0, #0x06
	mov r1, sp
	bl sub_08011C9C
	mov r2, r8
	orrs r2, r7
	movs r0, #0x00
	adds r1, r7, #0x0
	bl sub_080134E8
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r0, #0x40
	mov r9, r0
	.global _080135A8
_080135A8:
	bl sub_0800048C
	lsls r4, r6, #0x18
	lsrs r5, r4, #0x18
	adds r0, r5, #0x0
	adds r1, r7, #0x0
	mov r2, r8
	bl sub_080134E8
	ldr r1, _08013634 @ =0x020005CC
	movs r0, #0x09
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080135DC
	mov r1, r8
	cmp r1, #0x00
	beq _080135D0
	cmp r4, #0x00
	beq _080135DC
	.global _080135D0
_080135D0:
	cmp r7, #0x00
	beq _080135DA
	asrs r0, r4, #0x18
	cmp r0, #0x01
	beq _080135DC
	.global _080135DA
_080135DA:
	mov r9, r5
	.global _080135DC
_080135DC:
	ldr r1, _08013634 @ =0x020005CC
	movs r0, #0x02
	ldrh r2, [r1, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _080135EC
	movs r0, #0xFF
	mov r9, r0
	.global _080135EC
_080135EC:
	ldrh r0, [r1, #0x00]
	lsls r1, r6, #0x18
	asrs r1, r1, #0x18
	movs r2, #0x00
	movs r3, #0x04
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	mov r1, r9
	lsls r4, r1, #0x18
	.global _08013602
_08013602:
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bne _08013614
	cmp r7, #0x00
	bne _0801361C
	mov r2, r8
	cmp r2, #0x00
	bne _0801361C
	.global _08013614
_08013614:
	cmp r0, #0x01
	bne _0801364C
	cmp r7, #0x00
	beq _0801364C
	.global _0801361C
_0801361C:
	ldr r1, _08013634 @ =0x020005CC
	movs r0, #0xC0
	ldrh r2, [r1, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _08013638
	ldrh r0, [r1, #0x00]
	lsls r1, r6, #0x18
	asrs r1, r1, #0x18
	b _0801363E
	.global _08013630
_08013630: .4byte 0xFFFFFE00
	.global _08013634
_08013634: .4byte 0x020005CC
	.global _08013638
_08013638:
	lsls r1, r6, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x80
	.global _0801363E
_0801363E:
	movs r2, #0x00
	movs r3, #0x04
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	b _08013602
	.global _0801364C
_0801364C:
	bl sub_08000458
	asrs r4, r4, #0x18
	cmp r4, #0x40
	beq _080135A8
	ldr r0, _08013680 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08013664
	movs r0, #0x09
	bl sub_08001208
	.global _08013664
_08013664:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	adds r0, r4, #0x0
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _08013680
_08013680: .4byte 0x0202EF00
	thumb_func_start sub_08013684
sub_08013684:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0x0
	ldr r0, _080136F4 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x00
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x01
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _080136AC
	movs r2, #0x01
	.global _080136AC
_080136AC:
	movs r1, #0x06
	bl sub_08006950
	movs r0, #0x02
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _080136C0
	movs r2, #0x01
	.global _080136C0
_080136C0:
	movs r1, #0x08
	bl sub_08006950
	movs r0, #0x03
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x02
	bne _080136D4
	movs r2, #0x01
	.global _080136D4
_080136D4:
	movs r1, #0x0A
	bl sub_08006950
	movs r0, #0x08
	bl sub_08016558
	movs r2, #0x00
	cmp r5, #0x03
	bne _080136E8
	movs r2, #0x01
	.global _080136E8
_080136E8:
	movs r1, #0x0C
	bl sub_08006950
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _080136F4
_080136F4: .4byte 0x083FDE18
	thumb_func_start sub_080136F8
sub_080136F8:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r4, _080137B8 @ =0xFFFFFE00
	add sp, r4
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	movs r6, #0x00
	movs r0, #0x06
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	adds r1, r7, #0x0
	mov r2, r8
	bl sub_08013684
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r0, #0x40
	mov r9, r0
	.global _0801372E
_0801372E:
	bl sub_0800048C
	lsls r4, r6, #0x18
	lsrs r5, r4, #0x18
	adds r0, r5, #0x0
	adds r1, r7, #0x0
	mov r2, r8
	bl sub_08013684
	ldr r1, _080137BC @ =0x020005CC
	movs r0, #0x09
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08013762
	mov r1, r8
	cmp r1, #0x00
	beq _08013756
	cmp r4, #0x00
	beq _08013762
	.global _08013756
_08013756:
	cmp r7, #0x00
	beq _08013760
	asrs r0, r4, #0x18
	cmp r0, #0x01
	beq _08013762
	.global _08013760
_08013760:
	mov r9, r5
	.global _08013762
_08013762:
	ldr r1, _080137BC @ =0x020005CC
	movs r0, #0x02
	ldrh r2, [r1, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _08013772
	movs r0, #0xFF
	mov r9, r0
	.global _08013772
_08013772:
	ldrh r0, [r1, #0x00]
	lsls r1, r6, #0x18
	asrs r1, r1, #0x18
	movs r2, #0x00
	movs r3, #0x03
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	mov r1, r9
	lsls r4, r1, #0x18
	.global _08013788
_08013788:
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bne _0801379A
	cmp r7, #0x00
	bne _080137A2
	mov r2, r8
	cmp r2, #0x00
	bne _080137A2
	.global _0801379A
_0801379A:
	cmp r0, #0x01
	bne _080137D4
	cmp r7, #0x00
	beq _080137D4
	.global _080137A2
_080137A2:
	ldr r1, _080137BC @ =0x020005CC
	movs r0, #0xC0
	ldrh r2, [r1, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _080137C0
	ldrh r0, [r1, #0x00]
	lsls r1, r6, #0x18
	asrs r1, r1, #0x18
	b _080137C6
	.byte 0x00, 0x00
	.global _080137B8
_080137B8: .4byte 0xFFFFFE00
	.global _080137BC
_080137BC: .4byte 0x020005CC
	.global _080137C0
_080137C0:
	lsls r1, r6, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x80
	.global _080137C6
_080137C6:
	movs r2, #0x00
	movs r3, #0x03
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	b _08013788
	.global _080137D4
_080137D4:
	bl sub_08000458
	asrs r4, r4, #0x18
	cmp r4, #0x40
	beq _0801372E
	ldr r0, _08013808 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _080137EC
	movs r0, #0x09
	bl sub_08001208
	.global _080137EC
_080137EC:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	adds r0, r4, #0x0
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _08013808
_08013808: .4byte 0x0202EF00
	thumb_func_start sub_0801380C
sub_0801380C:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0x0
	ldr r0, _08013860 @ =0x0829F3C8
	bl sub_08006734
	ldr r0, _08013864 @ =0x0829F3D4
	movs r1, #0x07
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _08013868 @ =0x0829F3E8
	movs r1, #0x08
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _0801386C @ =0x0829F404
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _08013870 @ =0x0829F414
	movs r2, #0x00
	cmp r4, #0x00
	bne _08013842
	movs r2, #0x01
	.global _08013842
_08013842:
	movs r1, #0x0C
	bl sub_08006950
	ldr r0, _08013874 @ =0x0829F418
	movs r2, #0x00
	cmp r4, #0x01
	bne _08013852
	movs r2, #0x01
	.global _08013852
_08013852:
	movs r1, #0x0E
	bl sub_08006950
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08013860
_08013860: .4byte 0x0829F3C8
	.global _08013864
_08013864: .4byte 0x0829F3D4
	.global _08013868
_08013868: .4byte 0x0829F3E8
	.global _0801386C
_0801386C: .4byte 0x0829F404
	.global _08013870
_08013870: .4byte 0x0829F414
	.global _08013874
_08013874: .4byte 0x0829F418
	thumb_func_start sub_08013878
sub_08013878:
	push {r4, r5, r6, r7, lr}
	ldr r4, _080138FC @ =0xFFFFFE00
	add sp, r4
	movs r5, #0x00
	movs r0, #0x06
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_0801380C
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r4, #0x40
	ldr r7, _08013900 @ =0x020005CC
	.global _0801389A
_0801389A:
	bl sub_0800048C
	ldrh r2, [r7, #0x00]
	movs r0, #0x09
	ands r0, r2
	lsls r1, r5, #0x18
	cmp r0, #0x00
	beq _080138AC
	lsrs r4, r1, #0x18
	.global _080138AC
_080138AC:
	movs r0, #0x02
	ands r0, r2
	cmp r0, #0x00
	beq _080138B6
	movs r4, #0x00
	.global _080138B6
_080138B6:
	ldrh r0, [r7, #0x00]
	asrs r1, r1, #0x18
	movs r2, #0x00
	movs r3, #0x01
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r5, #0x0
	bl sub_0801380C
	bl sub_08000458
	lsls r6, r4, #0x18
	cmp r4, #0x40
	beq _0801389A
	ldr r0, _08013904 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _080138E4
	movs r0, #0x09
	bl sub_08001208
	.global _080138E4
_080138E4:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r6, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _080138FC
_080138FC: .4byte 0xFFFFFE00
	.global _08013900
_08013900: .4byte 0x020005CC
	.global _08013904
_08013904: .4byte 0x0202EF00
	thumb_func_start sub_08013908
sub_08013908:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0x0
	ldr r0, _08013960 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x60
	bl sub_08016558
	bl sub_080065A8
	cmp r4, #0x00
	bne _08013934
	movs r0, #0x63
	bl sub_08016558
	movs r1, #0x09
	movs r2, #0x01
	bl sub_08006950
	.global _08013934
_08013934:
	cmp r4, #0x01
	bne _08013946
	movs r0, #0x61
	bl sub_08016558
	movs r1, #0x09
	movs r2, #0x01
	bl sub_08006950
	.global _08013946
_08013946:
	cmp r5, #0x02
	bne _08013958
	movs r0, #0x62
	bl sub_08016558
	movs r1, #0x09
	movs r2, #0x01
	bl sub_08006950
	.global _08013958
_08013958:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08013960
_08013960: .4byte 0x083FDE18
	thumb_func_start sub_08013964
sub_08013964:
	push {r4, r5, r6, lr}
	ldr r4, _080139E4 @ =0xFFFFFE00
	add sp, r4
	bl sub_08016634
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0801397E
	bl sub_08013878
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080139D6
	.global _0801397E
_0801397E:
	movs r0, #0x06
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_08013908
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	bl sub_08016658
	movs r0, #0x01
	bl sub_08013908
	movs r5, #0x40
	.global _080139A0
_080139A0:
	bl sub_0800048C
	ldr r1, _080139E8 @ =0x020005CC
	movs r0, #0x09
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080139B2
	movs r5, #0x00
	.global _080139B2
_080139B2:
	bl sub_08000458
	lsls r0, r5, #0x18
	asrs r4, r0, #0x18
	cmp r4, #0x40
	beq _080139A0
	ldr r0, _080139EC @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _080139CC
	movs r0, #0x09
	bl sub_08001208
	.global _080139CC
_080139CC:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	adds r0, r4, #0x0
	.global _080139D6
_080139D6:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _080139E4
_080139E4: .4byte 0xFFFFFE00
	.global _080139E8
_080139E8: .4byte 0x020005CC
	.global _080139EC
_080139EC: .4byte 0x0202EF00
	thumb_func_start sub_080139F0
sub_080139F0:
	push {lr}
	ldr r0, _08013A78 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x30
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x07
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x08
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x09
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x0B
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x0C
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x0D
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x11
	bl sub_08016558
	movs r1, #0x0E
	movs r2, #0x01
	bl sub_08006950
	pop {r0}
	bx r0
	.global _08013A78
_08013A78: .4byte 0x083FDE18
	.byte 0xF0, 0xB5, 0x1C, 0x4C, 0xA5, 0x44, 0x00, 0x25, 0x06, 0x20, 0x69, 0x46, 0xFE, 0xF7, 0x08, 0xF9
	.byte 0xFF, 0xF7, 0xB0, 0xFF, 0x68, 0x46, 0x0F, 0x21, 0xF0, 0xF7, 0xD0, 0xFB, 0x40, 0x24, 0x16, 0x4F
	.byte 0xEC, 0xF7, 0xF6, 0xFC, 0xFF, 0xF7, 0xA6, 0xFF, 0x01, 0x20, 0x39, 0x88, 0x08, 0x40, 0x29, 0x06
	.byte 0x00, 0x28, 0x00, 0xD0, 0x0C, 0x0E, 0x38, 0x88, 0x09, 0x16, 0x00, 0x22, 0x00, 0x23, 0xFE, 0xF7
	.byte 0x3D, 0xF9, 0x00, 0x06, 0x05, 0x0E, 0xEC, 0xF7, 0xC9, 0xFC, 0x26, 0x06, 0x40, 0x2C, 0xE7, 0xD0
	.byte 0x0A, 0x48, 0xC0, 0x78, 0x00, 0x28, 0x02, 0xD0, 0x09, 0x20, 0xED, 0xF7, 0x97, 0xFB, 0x00, 0x20
	.byte 0x0F, 0x21, 0xF0, 0xF7, 0x95, 0xFB, 0x30, 0x0E, 0x80, 0x23, 0x9B, 0x00, 0x9D, 0x44, 0xF0, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47, 0x00, 0xFE, 0xFF, 0xFF, 0xCC, 0x05, 0x00, 0x02, 0x00, 0xEF, 0x02, 0x02
	thumb_func_start sub_08013AFC
sub_08013AFC:
	push {r4, r5, r6, r7, lr}
	movs r2, #0x00
	ldr r0, _08013B5C @ =0x0202EFC0
	mov r12, r0
	mov r4, r12
	ldr r3, _08013B60 @ =0x0202A550
	.global _08013B08
_08013B08:
	lsls r0, r2, #0x02
	adds r0, r0, r4
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x03
	adds r1, r1, r2
	lsls r1, r1, #0x04
	adds r1, r1, r3
	str r1, [r0, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x18
	bne _08013B08
	.global _08013B24
_08013B24:
	movs r7, #0x00
	mov r5, r12
	movs r2, #0x00
	movs r6, #0xB2
	lsls r6, r6, #0x01
	.global _08013B2E
_08013B2E:
	ldr r4, [r5, #0x00]
	ldr r3, [r5, #0x04]
	adds r1, r4, r6
	adds r0, r3, r6
	ldrh r1, [r1, #0x00]
	ldrh r0, [r0, #0x00]
	cmp r1, r0
	bcs _08013B44
	str r3, [r5, #0x00]
	str r4, [r5, #0x04]
	movs r7, #0x01
	.global _08013B44
_08013B44:
	adds r5, #0x04
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x17
	bne _08013B2E
	cmp r7, #0x00
	bne _08013B24
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08013B5C
_08013B5C: .4byte 0x0202EFC0
	.global _08013B60
_08013B60: .4byte 0x0202A550
	thumb_func_start sub_08013B64
sub_08013B64:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x040
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x030]
	lsls r0, r0, #0x04
	ldr r1, [sp, #0x030]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x03C]
	ldr r0, _08013D00 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x31
	bl sub_08016558
	bl sub_080065A8
	ldr r0, [sp, #0x03C]
	lsls r1, r0, #0x02
	ldr r0, _08013D04 @ =0x0202EFC0
	adds r1, r1, r0
	str r1, [sp, #0x038]
	movs r1, #0x00
	str r1, [sp, #0x034]
	mov r5, sp
	.global _08013BA4
_08013BA4:
	ldr r0, [sp, #0x038]
	ldr r6, [r0, #0x00]
	ldr r1, [sp, #0x034]
	adds r1, #0x04
	mov r10, r1
	ldr r0, _08013D08 @ =0x0829F41C
	movs r1, #0x00
	mov r2, r10
	movs r3, #0x01
	bl sub_080063BC
	ldr r0, _08013D0C @ =0x0202F020
	ldr r1, [sp, #0x038]
	cmp r1, r0
	bcc _08013BC4
	b _08013CDA
	.global _08013BC4
_08013BC4:
	movs r1, #0xB6
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	add r7, sp, #0x028
	movs r1, #0x2A
	add r1, sp
	mov r8, r1
	add r1, sp, #0x02C
	mov r9, r1
	adds r1, r7, #0x0
	mov r2, r8
	mov r3, r9
	bl sub_08016C50
	ldr r0, _08013D10 @ =0x0202A550
	cmp r6, r0
	bne _08013BF4
	ldr r1, _08013D14 @ =0x0202539C
	movs r0, #0x10
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08013CD4
	.global _08013BF4
_08013BF4:
	ldr r0, [sp, #0x034]
	ldr r1, [sp, #0x03C]
	adds r4, r0, r1
	adds r4, #0x01
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08017230
	movs r1, #0x0A
	bl sub_080172C8
	adds r0, #0x30
	strb r0, [r5, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_080172C8
	adds r0, #0x30
	strb r0, [r5, #0x01]
	movs r0, #0x2E
	strb r0, [r5, #0x02]
	movs r0, #0x00
	strb r0, [r5, #0x03]
	mov r0, sp
	movs r1, #0x00
	mov r2, r10
	movs r3, #0x01
	bl sub_080063BC
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	bl sub_0800F110
	movs r1, #0x03
	mov r2, r10
	movs r3, #0x01
	bl sub_080063BC
	ldrh r0, [r7, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x00]
	ldrh r0, [r7, #0x00]
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x01]
	movs r0, #0x3A
	strb r0, [r5, #0x02]
	mov r1, r8
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x03]
	mov r1, r8
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x04]
	movs r0, #0x3A
	strb r0, [r5, #0x05]
	mov r1, r9
	ldrh r0, [r1, #0x00]
	movs r1, #0x64
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x06]
	mov r1, r9
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x07]
	movs r0, #0x00
	strb r0, [r5, #0x08]
	mov r0, sp
	movs r1, #0x16
	mov r2, r10
	movs r3, #0x01
	bl sub_080063BC
	.global _08013CD4
_08013CD4:
	ldr r1, [sp, #0x038]
	adds r1, #0x04
	str r1, [sp, #0x038]
	.global _08013CDA
_08013CDA:
	ldr r0, [sp, #0x034]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x034]
	cmp r0, #0x0F
	beq _08013CEA
	b _08013BA4
	.global _08013CEA
_08013CEA:
	ldr r1, _08013D14 @ =0x0202539C
	movs r0, #0x08
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08013D30
	ldr r0, [sp, #0x030]
	cmp r0, #0x00
	bne _08013D1C
	ldr r0, _08013D18 @ =0x0829F440
	b _08013D1E
	.global _08013D00
_08013D00: .4byte 0x083FDE18
	.global _08013D04
_08013D04: .4byte 0x0202EFC0
	.global _08013D08
_08013D08: .4byte 0x0829F41C
	.global _08013D0C
_08013D0C: .4byte 0x0202F020
	.global _08013D10
_08013D10: .4byte 0x0202A550
	.global _08013D14
_08013D14: .4byte 0x0202539C
	.global _08013D18
_08013D18: .4byte 0x0829F440
	.global _08013D1C
_08013D1C:
	ldr r0, _08013D2C @ =0x0829F444
	.global _08013D1E
_08013D1E:
	movs r1, #0x1A
	movs r2, #0x13
	movs r3, #0x01
	bl sub_080063BC
	b _08013D3C
	.byte 0x00, 0x00
	.global _08013D2C
_08013D2C: .4byte 0x0829F444
	.global _08013D30
_08013D30:
	ldr r0, _08013D54 @ =0x0829F448
	movs r1, #0x1A
	movs r2, #0x13
	movs r3, #0x01
	bl sub_080063BC
	.global _08013D3C
_08013D3C:
	ldr r1, _08013D58 @ =0x0202539C
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	add sp, #0x040
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08013D54
_08013D54: .4byte 0x0829F448
	.global _08013D58
_08013D58: .4byte 0x0202539C
	thumb_func_start sub_08013D5C
sub_08013D5C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08013E2C @ =0xFFFFFE00
	add sp, r4
	movs r5, #0x00
	mov r8, r5
	bl sub_0800F3A4
	bl sub_0800F498
	ldr r0, _08013E30 @ =0x082EE104
	mov r1, sp
	bl sub_0800F328
	bl sub_0800F3C0
	movs r0, #0x00
	bl sub_08013B64
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r7, #0x40
	ldr r6, _08013E34 @ =0x020005CC
	.global _08013D90
_08013D90:
	bl sub_0800048C
	mov r0, r8
	bl sub_08013B64
	ldrh r1, [r6, #0x00]
	movs r0, #0x01
	ands r0, r1
	lsls r4, r5, #0x18
	cmp r0, #0x00
	beq _08013DA8
	lsrs r7, r4, #0x18
	.global _08013DA8
_08013DA8:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0x00
	beq _08013DC8
	mov r0, r8
	cmp r0, #0x01
	bne _08013DC8
	movs r1, #0x00
	mov r8, r1
	ldr r0, _08013E38 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08013DC8
	movs r0, #0x08
	bl sub_08001208
	.global _08013DC8
_08013DC8:
	movs r0, #0x80
	ldrh r1, [r6, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08013DEA
	mov r0, r8
	cmp r0, #0x00
	bne _08013DEA
	movs r1, #0x01
	mov r8, r1
	ldr r0, _08013E38 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08013DEA
	movs r0, #0x08
	bl sub_08001208
	.global _08013DEA
_08013DEA:
	ldrh r0, [r6, #0x00]
	asrs r1, r4, #0x18
	movs r2, #0x00
	movs r3, #0x00
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl sub_08000458
	lsls r4, r7, #0x18
	cmp r7, #0x40
	beq _08013D90
	ldr r0, _08013E38 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08013E12
	movs r0, #0x09
	bl sub_08001208
	.global _08013E12
_08013E12:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r4, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _08013E2C
_08013E2C: .4byte 0xFFFFFE00
	.global _08013E30
_08013E30: .4byte 0x082EE104
	.global _08013E34
_08013E34: .4byte 0x020005CC
	.global _08013E38
_08013E38: .4byte 0x0202EF00
	thumb_func_start sub_08013E3C
sub_08013E3C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x038
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x030]
	lsls r4, r0, #0x04
	subs r4, r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _08013ED4 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x2F
	bl sub_08016558
	bl sub_080065A8
	lsls r4, r4, #0x02
	ldr r0, _08013ED8 @ =0x0202EFC0
	adds r4, r4, r0
	mov r9, r4
	movs r0, #0x00
	str r0, [sp, #0x034]
	mov r5, sp
	.global _08013E76
_08013E76:
	ldr r4, [sp, #0x034]
	adds r4, #0x04
	ldr r0, _08013EDC @ =0x0829F44C
	movs r1, #0x01
	adds r2, r4, #0x0
	movs r3, #0x01
	bl sub_080063BC
	ldr r0, _08013EE0 @ =0x0202F020
	adds r7, r4, #0x0
	cmp r9, r0
	bcc _08013E90
	b _08013F96
	.global _08013E90
_08013E90:
	mov r1, r9
	ldr r4, [r1, #0x00]
	movs r1, #0xB6
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	add r1, sp, #0x028
	mov r2, sp
	adds r2, #0x2A
	add r3, sp, #0x02C
	bl sub_08016C50
	ldr r0, _08013EE4 @ =0x0202A550
	add r6, sp, #0x028
	movs r1, #0x2A
	add r1, sp
	mov r8, r1
	add r1, sp, #0x02C
	mov r10, r1
	cmp r4, r0
	bne _08013EEC
	ldr r1, _08013EE8 @ =0x0202539C
	movs r0, #0x10
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08013EEC
	ldr r0, _08013EDC @ =0x0829F44C
	movs r1, #0x01
	adds r2, r7, #0x0
	movs r3, #0x01
	bl sub_080063BC
	b _08013F92
	.global _08013ED4
_08013ED4: .4byte 0x083FDE18
	.global _08013ED8
_08013ED8: .4byte 0x0202EFC0
	.global _08013EDC
_08013EDC: .4byte 0x0829F44C
	.global _08013EE0
_08013EE0: .4byte 0x0202F020
	.global _08013EE4
_08013EE4: .4byte 0x0202A550
	.global _08013EE8
_08013EE8: .4byte 0x0202539C
	.global _08013EEC
_08013EEC:
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	bl sub_0800F110
	movs r1, #0x01
	adds r2, r7, #0x0
	movs r3, #0x01
	bl sub_080063BC
	ldrh r0, [r6, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x00]
	ldrh r0, [r6, #0x00]
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x01]
	movs r0, #0x3A
	strb r0, [r5, #0x02]
	mov r1, r8
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x03]
	mov r1, r8
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x04]
	movs r0, #0x3A
	strb r0, [r5, #0x05]
	mov r1, r10
	ldrh r0, [r1, #0x00]
	movs r1, #0x64
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x06]
	mov r1, r10
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x07]
	movs r0, #0x00
	strb r0, [r5, #0x08]
	mov r0, sp
	movs r1, #0x14
	adds r2, r7, #0x0
	movs r3, #0x01
	bl sub_080063BC
	.global _08013F92
_08013F92:
	movs r1, #0x04
	add r9, r1
	.global _08013F96
_08013F96:
	ldr r0, [sp, #0x034]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x034]
	cmp r0, #0x0F
	beq _08013FA6
	b _08013E76
	.global _08013FA6
_08013FA6:
	ldr r1, _08013FBC @ =0x0202539C
	movs r0, #0x08
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08013FD8
	ldr r0, [sp, #0x030]
	cmp r0, #0x00
	bne _08013FC4
	ldr r0, _08013FC0 @ =0x0829F440
	b _08013FC6
	.global _08013FBC
_08013FBC: .4byte 0x0202539C
	.global _08013FC0
_08013FC0: .4byte 0x0829F440
	.global _08013FC4
_08013FC4:
	ldr r0, _08013FD4 @ =0x0829F444
	.global _08013FC6
_08013FC6:
	movs r1, #0x1A
	movs r2, #0x13
	movs r3, #0x01
	bl sub_080063BC
	b _08013FE4
	.byte 0x00, 0x00
	.global _08013FD4
_08013FD4: .4byte 0x0829F444
	.global _08013FD8
_08013FD8:
	ldr r0, _08013FFC @ =0x0829F448
	movs r1, #0x1A
	movs r2, #0x13
	movs r3, #0x01
	bl sub_080063BC
	.global _08013FE4
_08013FE4:
	ldr r1, _08014000 @ =0x0202539C
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	add sp, #0x038
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08013FFC
_08013FFC: .4byte 0x0829F448
	.global _08014000
_08014000: .4byte 0x0202539C
	thumb_func_start sub_08014004
sub_08014004:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _080140CC @ =0xFFFFFE00
	add sp, r4
	movs r6, #0x00
	movs r4, #0x00
	bl sub_0800F3C0
	movs r0, #0x06
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_08013E3C
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r0, #0x40
	mov r8, r0
	ldr r7, _080140D0 @ =0x020005CC
	.global _08014032
_08014032:
	bl sub_0800048C
	adds r0, r6, #0x0
	bl sub_08013E3C
	ldrh r1, [r7, #0x00]
	movs r0, #0x01
	ands r0, r1
	lsls r4, r4, #0x18
	cmp r0, #0x00
	beq _0801404C
	lsrs r0, r4, #0x18
	mov r8, r0
	.global _0801404C
_0801404C:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0x00
	beq _08014068
	cmp r6, #0x01
	bne _08014068
	movs r6, #0x00
	ldr r0, _080140D4 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08014068
	movs r0, #0x08
	bl sub_08001208
	.global _08014068
_08014068:
	movs r0, #0x80
	ldrh r1, [r7, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08014086
	cmp r6, #0x00
	bne _08014086
	movs r6, #0x01
	ldr r0, _080140D4 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08014086
	movs r0, #0x08
	bl sub_08001208
	.global _08014086
_08014086:
	ldrh r0, [r7, #0x00]
	asrs r1, r4, #0x18
	movs r2, #0x00
	movs r3, #0x00
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_08000458
	mov r0, r8
	lsls r5, r0, #0x18
	cmp r0, #0x40
	beq _08014032
	ldr r0, _080140D4 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _080140B0
	movs r0, #0x09
	bl sub_08001208
	.global _080140B0
_080140B0:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r5, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _080140CC
_080140CC: .4byte 0xFFFFFE00
	.global _080140D0
_080140D0: .4byte 0x020005CC
	.global _080140D4
_080140D4: .4byte 0x0202EF00
	thumb_func_start sub_080140D8
sub_080140D8:
	push {r4, lr}
	movs r4, #0x00
	.global _080140DC
_080140DC:
	lsls r0, r4, #0x01
	adds r0, r0, r4
	lsls r0, r0, #0x03
	adds r0, r0, r4
	lsls r0, r0, #0x04
	ldr r1, _08014100 @ =0x0202A550
	adds r0, r0, r1
	adds r1, r4, #0x0
	bl sub_08007B34
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x18
	bne _080140DC
	pop {r4}
	pop {r1}
	bx r1
	.global _08014100
_08014100: .4byte 0x0202A550
	thumb_func_start sub_08014104
sub_08014104:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x028
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r9, r0
	lsls r4, r0, #0x04
	subs r4, r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _08014178 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x32
	bl sub_08016558
	bl sub_080065A8
	lsls r4, r4, #0x02
	ldr r0, _0801417C @ =0x0202EFC0
	adds r7, r4, r0
	movs r0, #0x00
	mov r8, r0
	mov r5, sp
	mov r10, r0
	.global _0801413E
_0801413E:
	mov r4, r8
	adds r4, #0x04
	ldr r0, _08014180 @ =0x0829F44C
	movs r1, #0x01
	adds r2, r4, #0x0
	movs r3, #0x01
	bl sub_080063BC
	ldr r0, _08014184 @ =0x0202F020
	adds r6, r4, #0x0
	cmp r7, r0
	bcs _08014212
	ldr r4, [r7, #0x00]
	ldr r0, _08014188 @ =0x0202A550
	cmp r4, r0
	bne _08014194
	ldr r1, _0801418C @ =0x0202539C
	movs r0, #0x10
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08014194
	ldr r0, _08014190 @ =0x0829F2AC
	movs r1, #0x01
	adds r2, r6, #0x0
	movs r3, #0x01
	bl sub_080063BC
	b _08014210
	.global _08014178
_08014178: .4byte 0x083FDE18
	.global _0801417C
_0801417C: .4byte 0x0202EFC0
	.global _08014180
_08014180: .4byte 0x0829F44C
	.global _08014184
_08014184: .4byte 0x0202F020
	.global _08014188
_08014188: .4byte 0x0202A550
	.global _0801418C
_0801418C: .4byte 0x0202539C
	.global _08014190
_08014190: .4byte 0x0829F2AC
	.global _08014194
_08014194:
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	bl sub_0800F110
	movs r1, #0x01
	adds r2, r6, #0x0
	movs r3, #0x01
	bl sub_080063BC
	movs r0, #0xB2
	lsls r0, r0, #0x01
	adds r4, r4, r0
	ldrh r0, [r4, #0x00]
	movs r1, #0xFA
	lsls r1, r1, #0x02
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x00]
	ldrh r0, [r4, #0x00]
	movs r1, #0x64
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x01]
	ldrh r0, [r4, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x02]
	ldrh r0, [r4, #0x00]
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x03]
	mov r1, r10
	strb r1, [r5, #0x04]
	mov r0, sp
	movs r1, #0x1A
	adds r2, r6, #0x0
	movs r3, #0x01
	bl sub_080063BC
	.global _08014210
_08014210:
	adds r7, #0x04
	.global _08014212
_08014212:
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0x0F
	bne _0801413E
	ldr r0, _0801423C @ =0x0202539C
	ldrb r1, [r0, #0x00]
	adds r1, #0x01
	strb r1, [r0, #0x00]
	movs r0, #0x08
	ands r1, r0
	cmp r1, #0x00
	beq _08014258
	mov r0, r9
	cmp r0, #0x00
	bne _08014244
	ldr r0, _08014240 @ =0x0829F440
	b _08014246
	.byte 0x00, 0x00
	.global _0801423C
_0801423C: .4byte 0x0202539C
	.global _08014240
_08014240: .4byte 0x0829F440
	.global _08014244
_08014244:
	ldr r0, _08014254 @ =0x0829F444
	.global _08014246
_08014246:
	movs r1, #0x1A
	movs r2, #0x13
	movs r3, #0x01
	bl sub_080063BC
	b _08014264
	.byte 0x00, 0x00
	.global _08014254
_08014254: .4byte 0x0829F444
	.global _08014258
_08014258:
	ldr r0, _08014274 @ =0x0829F448
	movs r1, #0x1A
	movs r2, #0x13
	movs r3, #0x01
	bl sub_080063BC
	.global _08014264
_08014264:
	add sp, #0x028
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08014274
_08014274: .4byte 0x0829F448
	thumb_func_start sub_08014278
sub_08014278:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _0801434C @ =0xFFFFFE00
	add sp, r4
	movs r0, #0x00
	mov r8, r0
	bl sub_08013AFC
	movs r5, #0x00
	bl sub_0800F3A4
	bl sub_0800F498
	ldr r0, _08014350 @ =0x082EE104
	mov r1, sp
	bl sub_0800F328
	movs r0, #0x00
	bl sub_08014104
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r7, #0x40
	ldr r6, _08014354 @ =0x020005CC
	.global _080142AE
_080142AE:
	bl sub_0800048C
	mov r0, r8
	bl sub_08014104
	ldrh r1, [r6, #0x00]
	movs r0, #0x01
	ands r0, r1
	lsls r4, r5, #0x18
	cmp r0, #0x00
	beq _080142C6
	lsrs r7, r4, #0x18
	.global _080142C6
_080142C6:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0x00
	beq _080142E6
	mov r1, r8
	cmp r1, #0x01
	bne _080142E6
	movs r0, #0x00
	mov r8, r0
	ldr r0, _08014358 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _080142E6
	movs r0, #0x08
	bl sub_08001208
	.global _080142E6
_080142E6:
	movs r0, #0x80
	ldrh r1, [r6, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08014308
	mov r0, r8
	cmp r0, #0x00
	bne _08014308
	movs r1, #0x01
	mov r8, r1
	ldr r0, _08014358 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08014308
	movs r0, #0x08
	bl sub_08001208
	.global _08014308
_08014308:
	ldrh r0, [r6, #0x00]
	asrs r1, r4, #0x18
	movs r2, #0x00
	movs r3, #0x00
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl sub_08000458
	lsls r4, r7, #0x18
	cmp r7, #0x40
	beq _080142AE
	ldr r0, _08014358 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08014330
	movs r0, #0x09
	bl sub_08001208
	.global _08014330
_08014330:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r4, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _0801434C
_0801434C: .4byte 0xFFFFFE00
	.global _08014350
_08014350: .4byte 0x082EE104
	.global _08014354
_08014354: .4byte 0x020005CC
	.global _08014358
_08014358: .4byte 0x0202EF00
