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
