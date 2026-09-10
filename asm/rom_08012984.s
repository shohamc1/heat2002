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
