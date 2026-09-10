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
