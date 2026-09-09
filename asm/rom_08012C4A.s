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
	thumb_func_start sub_08012C4C
sub_08012C4C:
	push {r4, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	ldr r0, _08012C78 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x8F
	bl sub_08016558
	bl sub_080065A8
	cmp r4, #0x02
	bhi _08012C7C
	movs r0, #0x91
	bl sub_08016558
	movs r1, #0x04
	movs r2, #0x01
	bl sub_08006950
	b _08012C90
	.global _08012C78
_08012C78: .4byte 0x083FDE18
	.global _08012C7C
_08012C7C:
	ldr r0, _08012D0C @ =0x0829F374
	movs r1, #0x06
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _08012D10 @ =0x0829F388
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006950
	.global _08012C90
_08012C90:
	cmp r4, #0x02
	bhi _08012C9E
	ldr r0, _08012D14 @ =0x083FEF00
	ldr r0, [r0, #0x00]
	ldr r1, _08012D18 @ =0x06010000
	bl sub_08016E28
	.global _08012C9E
_08012C9E:
	cmp r4, #0x00
	bne _08012CB0
	ldr r3, _08012D1C @ =0x08310160
	str r4, [sp, #0x000]
	movs r0, #0x58
	movs r1, #0x40
	movs r2, #0x00
	bl sub_080100CC
	.global _08012CB0
_08012CB0:
	cmp r4, #0x01
	bne _08012CC4
	ldr r3, _08012D20 @ =0x0830EC58
	movs r0, #0x00
	str r0, [sp, #0x000]
	movs r0, #0x58
	movs r1, #0x40
	movs r2, #0x00
	bl sub_080100CC
	.global _08012CC4
_08012CC4:
	cmp r4, #0x02
	bne _08012CD8
	ldr r3, _08012D24 @ =0x08310140
	movs r0, #0x00
	str r0, [sp, #0x000]
	movs r0, #0x58
	movs r1, #0x40
	movs r2, #0x00
	bl sub_080100CC
	.global _08012CD8
_08012CD8:
	cmp r4, #0x00
	bne _08012CE6
	ldr r0, _08012D28 @ =0x0829F3A4
	movs r1, #0x12
	movs r2, #0x01
	bl sub_08006950
	.global _08012CE6
_08012CE6:
	cmp r4, #0x01
	bne _08012CF4
	ldr r0, _08012D2C @ =0x0829F3AC
	movs r1, #0x12
	movs r2, #0x01
	bl sub_08006950
	.global _08012CF4
_08012CF4:
	cmp r4, #0x02
	bne _08012D02
	ldr r0, _08012D30 @ =0x0829F3B4
	movs r1, #0x12
	movs r2, #0x01
	bl sub_08006950
	.global _08012D02
_08012D02:
	add sp, #0x004
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08012D0C
_08012D0C: .4byte 0x0829F374
	.global _08012D10
_08012D10: .4byte 0x0829F388
	.global _08012D14
_08012D14: .4byte 0x083FEF00
	.global _08012D18
_08012D18: .4byte 0x06010000
	.global _08012D1C
_08012D1C: .4byte 0x08310160
	.global _08012D20
_08012D20: .4byte 0x0830EC58
	.global _08012D24
_08012D24: .4byte 0x08310140
	.global _08012D28
_08012D28: .4byte 0x0829F3A4
	.global _08012D2C
_08012D2C: .4byte 0x0829F3AC
	.global _08012D30
_08012D30: .4byte 0x0829F3B4
	thumb_func_start sub_08012D34
sub_08012D34:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08012DD8 @ =0xFFFFFE00
	add sp, r4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #0x00
	mov r8, r0
	bl sub_080045D8
	bl sub_08007344
	bl sub_080073D8
	movs r0, #0x06
	mov r1, sp
	bl sub_08011C9C
	bl sub_08004484
	adds r0, r6, #0x0
	bl sub_08012C4C
	bl sub_080047DC
	ldr r4, _08012DDC @ =0x020020C0
	mov r2, r8
	strb r2, [r4, #0x00]
	bl sub_08000458
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xAA
	lsls r2, r2, #0x05
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	movs r5, #0x40
	adds r7, r4, #0x0
	.global _08012D8E
_08012D8E:
	bl sub_08004484
	bl sub_0800048C
	adds r0, r6, #0x0
	bl sub_08012C4C
	ldr r1, _08012DE0 @ =0x020005CC
	movs r0, #0x01
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08012DAA
	movs r5, #0x00
	.global _08012DAA
_08012DAA:
	bl sub_080047DC
	movs r0, #0x00
	strb r0, [r7, #0x00]
	bl sub_08000458
	lsls r4, r5, #0x18
	cmp r4, #0x00
	bne _08012D8E
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
	.global _08012DD8
_08012DD8: .4byte 0xFFFFFE00
	.global _08012DDC
_08012DDC: .4byte 0x020020C0
	.global _08012DE0
_08012DE0: .4byte 0x020005CC
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_08012DEC
sub_08012DEC:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0x0
	ldr r0, _08012E44 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x08
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x66
	bl sub_08016558
	movs r1, #0x07
	movs r2, #0x01
	bl sub_08006950
	movs r0, #0x67
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _08012E22
	movs r2, #0x01
	.global _08012E22
_08012E22:
	movs r1, #0x09
	bl sub_08006950
	movs r0, #0x68
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _08012E36
	movs r2, #0x01
	.global _08012E36
_08012E36:
	movs r1, #0x0B
	bl sub_08006950
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08012E44
_08012E44: .4byte 0x083FDE18
	.byte 0xF0, 0xB5, 0x23, 0x4C, 0xA5, 0x44, 0x00, 0x25, 0xED, 0xF7, 0x02, 0xFB, 0x03, 0x20, 0x69, 0x46
	.byte 0xFE, 0xF7, 0x20, 0xFF, 0x1F, 0x48, 0x01, 0x78, 0x00, 0x20, 0xFF, 0xF7, 0xC3, 0xFF, 0x68, 0x46
	.byte 0x0F, 0x21, 0xF1, 0xF7, 0xE5, 0xF9, 0x40, 0x27, 0x1B, 0x4E, 0xED, 0xF7, 0x0B, 0xFB, 0x2D, 0x06
	.byte 0x2C, 0x0E, 0x18, 0x48, 0x01, 0x78, 0x20, 0x1C, 0xFF, 0xF7, 0xB4, 0xFF, 0x01, 0x20, 0x31, 0x88
	.byte 0x08, 0x40, 0x00, 0x28, 0x00, 0xD0, 0x27, 0x1C, 0x30, 0x88, 0x29, 0x16, 0x00, 0x22, 0x01, 0x23
	.byte 0xFE, 0xF7, 0x4E, 0xFF, 0x00, 0x06, 0x05, 0x0E, 0xED, 0xF7, 0xDA, 0xFA, 0x38, 0x06, 0x04, 0x16
	.byte 0x40, 0x2C, 0xE2, 0xD0, 0x0D, 0x48, 0xC0, 0x78, 0x00, 0x28, 0x02, 0xD0, 0x09, 0x20, 0xEE, 0xF7
	.byte 0xA7, 0xF9, 0x00, 0x20, 0x0F, 0x21, 0xF1, 0xF7, 0xA5, 0xF9, 0x01, 0x21, 0x20, 0x1C, 0x48, 0x40
	.byte 0x00, 0x06, 0x00, 0x0E, 0x80, 0x23, 0x9B, 0x00, 0x9D, 0x44, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47
	.byte 0x00, 0xFE, 0xFF, 0xFF, 0x70, 0xED, 0x02, 0x02, 0xCC, 0x05, 0x00, 0x02, 0x00, 0xEF, 0x02, 0x02
