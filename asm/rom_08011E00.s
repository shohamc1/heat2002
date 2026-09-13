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
	thumb_func_start sub_08011E00
sub_08011E00:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0x00
	beq _08011E3E
	ldr r1, _08011E78 @ =0x0202EFB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _08011E7C @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011E2E
	movs r0, #0x08
	bl sub_08001208
	.global _08011E2E
_08011E2E:
	lsls r0, r4, #0x10
	ldr r1, _08011E80 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r1, r7, #0x10
	cmp r0, r1
	bge _08011E3E
	adds r4, r6, #0x0
	.global _08011E3E
_08011E3E:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0x00
	beq _08011E6C
	ldr r1, _08011E78 @ =0x0202EFB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _08011E7C @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011E5A
	movs r0, #0x08
	bl sub_08001208
	.global _08011E5A
_08011E5A:
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r1, r6, #0x10
	cmp r0, r1
	ble _08011E6C
	adds r4, r7, #0x0
	.global _08011E6C
_08011E6C:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08011E78
_08011E78: .4byte 0x0202EFB0
	.global _08011E7C
_08011E7C: .4byte 0x0202EF00
	.global _08011E80
_08011E80: .4byte 0xFFFF0000
	thumb_func_start sub_08011E84
sub_08011E84:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0x00
	beq _08011EB4
	ldr r1, _08011EE0 @ =0x0202EFB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r4, #0x10
	ldr r1, _08011EE4 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r1, r2, #0x10
	cmp r0, r1
	bge _08011EB4
	adds r4, r3, #0x0
	.global _08011EB4
_08011EB4:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0x00
	beq _08011ED4
	ldr r1, _08011EE0 @ =0x0202EFB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r1, r3, #0x10
	cmp r0, r1
	ble _08011ED4
	adds r4, r2, #0x0
	.global _08011ED4
_08011ED4:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08011EE0
_08011EE0: .4byte 0x0202EFB0
	.global _08011EE4
_08011EE4: .4byte 0xFFFF0000
	thumb_func_start sub_08011EE8
sub_08011EE8:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0x00
	beq _08011F32
	ldr r1, _08011F1C @ =0x0202EFB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r4, #0x10
	ldr r1, _08011F20 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r2, r2, #0x10
	cmp r0, r2
	bge _08011F24
	lsrs r4, r2, #0x10
	b _08011F32
	.byte 0x00, 0x00
	.global _08011F1C
_08011F1C: .4byte 0x0202EFB0
	.global _08011F20
_08011F20: .4byte 0xFFFF0000
	.global _08011F24
_08011F24:
	ldr r0, _08011F54 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011F32
	movs r0, #0x08
	bl sub_08001208
	.global _08011F32
_08011F32:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0x00
	beq _08011F6A
	ldr r1, _08011F58 @ =0x0202EFB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r3, r6, #0x10
	cmp r0, r3
	ble _08011F5C
	lsrs r4, r3, #0x10
	b _08011F6A
	.global _08011F54
_08011F54: .4byte 0x0202EF00
	.global _08011F58
_08011F58: .4byte 0x0202EFB0
	.global _08011F5C
_08011F5C:
	ldr r0, _08011F74 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011F6A
	movs r0, #0x08
	bl sub_08001208
	.global _08011F6A
_08011F6A:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.global _08011F74
_08011F74: .4byte 0x0202EF00
	thumb_func_start sub_08011F78
sub_08011F78:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0x0
	ldr r0, _08011FC0 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x5A
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x51
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _08011FA0
	movs r2, #0x01
	.global _08011FA0
_08011FA0:
	movs r1, #0x09
	bl sub_08006950
	movs r0, #0x52
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _08011FB4
	movs r2, #0x01
	.global _08011FB4
_08011FB4:
	movs r1, #0x0B
	bl sub_08006950
	pop {r4}
	pop {r0}
	bx r0
	.global _08011FC0
_08011FC0: .4byte 0x083FDE18
