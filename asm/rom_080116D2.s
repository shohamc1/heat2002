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
	thumb_func_start sub_080116D4
sub_080116D4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, [sp, #0x01C]
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0x20
	ands r0, r6
	cmp r0, #0x00
	beq _08011728
	ldr r0, _0801176C @ =0x0202EFB0
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, _08011770 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r0, r4
	bne _08011716
	ldr r0, _08011774 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011716
	movs r0, #0x08
	bl sub_08001208
	.global _08011716
_08011716:
	lsls r0, r5, #0x10
	ldr r1, _08011778 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	mov r2, r8
	lsls r1, r2, #0x10
	cmp r0, r1
	bge _08011728
	adds r5, r7, #0x0
	.global _08011728
_08011728:
	movs r0, #0x10
	ands r0, r6
	cmp r0, #0x00
	beq _0801175E
	ldr r0, _0801176C @ =0x0202EFB0
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, _08011770 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r0, r4
	bne _0801174C
	ldr r0, _08011774 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0801174C
	movs r0, #0x08
	bl sub_08001208
	.global _0801174C
_0801174C:
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	lsls r1, r7, #0x10
	cmp r0, r1
	ble _0801175E
	mov r5, r8
	.global _0801175E
_0801175E:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _0801176C
_0801176C: .4byte 0x0202EFB0
	.global _08011770
_08011770: .4byte 0x0202EF90
	.global _08011774
_08011774: .4byte 0x0202EF00
	.global _08011778
_08011778: .4byte 0xFFFF0000
