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
