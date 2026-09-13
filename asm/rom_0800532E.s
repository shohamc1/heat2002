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
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_08005338
sub_08005338:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x020
	adds r6, r0, #0x0
	adds r4, r1, #0x0
	adds r5, r2, #0x0
	adds r7, r3, #0x0
	cmp r4, #0x63
	ble _0800534E
	movs r4, #0x63
	movs r5, #0x3B
	movs r7, #0x00
	.global _0800534E
_0800534E:
	movs r0, #0x0A
	str r0, [sp, #0x008]
	str r0, [sp, #0x014]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08017230
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_080172C8
	str r0, [sp, #0x004]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl sub_08017230
	str r0, [sp, #0x00C]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl sub_080172C8
	str r0, [sp, #0x010]
	adds r0, r7, #0x0
	movs r1, #0x64
	bl sub_080172C8
	movs r1, #0x0A
	bl sub_08017230
	str r0, [sp, #0x01C]
	adds r0, r7, #0x0
	movs r1, #0x64
	bl sub_08017230
	str r0, [sp, #0x018]
	movs r4, #0x00
	mov r5, sp
	.global _0800539A
_0800539A:
	adds r0, r6, #0x4
	ldm r5!, {r1}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_080058CC
	adds r6, #0x02
	adds r4, #0x01
	cmp r4, #0x08
	bne _0800539A
	add sp, #0x020
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
