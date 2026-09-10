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
