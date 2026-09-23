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
	thumb_func_start sub_0800592C
sub_0800592C:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x020
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	adds r4, r3, #0x0
	ldr r5, [sp, #0x034]
	movs r0, #0x0A
	str r0, [sp, #0x004]
	str r0, [sp, #0x010]
	str r2, [sp, #0x000]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_080172C8
	str r0, [sp, #0x00C]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08017230
	str r0, [sp, #0x008]
	adds r0, r5, #0x0
	movs r1, #0x64
	bl sub_080172C8
	movs r1, #0x0A
	bl sub_08017230
	str r0, [sp, #0x018]
	adds r0, r5, #0x0
	movs r1, #0x64
	bl sub_08017230
	str r0, [sp, #0x014]
	movs r0, #0x00
	str r0, [sp, #0x01C]
	movs r4, #0x00
	movs r0, #0xFF
	ands r7, r0
	mov r5, sp
_0800597A:
	ldr r0, _080059A4 @ =0x000001FF
	ands r0, r6
	lsls r0, r0, #0x10
	orrs r0, r7
	ldm r5!, {r1}
	movs r2, #0xF5
	lsls r2, r2, #0x02
	adds r1, r1, r2
	movs r2, #0xC0
	lsls r2, r2, #0x06
	orrs r1, r2
	bl sub_080044A4
	adds r6, #0x04
	adds r4, #0x01
	cmp r4, #0x08
	bne _0800597A
	add sp, #0x020
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080059A4: .4byte 0x000001FF
	thumb_func_start sub_080059A8
sub_080059A8:
	push {r4, r5, r6, lr}
	ldr r5, _08005A1C @ =0x0202525C
	ldr r0, _08005A20 @ =0x0202521C
	ldr r4, [r0, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_080172C8
	strb r0, [r5, #0x01]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08017230
	strb r0, [r5, #0x00]
	ldr r4, _08005A24 @ =0x08364B08
	ldr r0, [r4, #0x00]
	adds r0, #0x82
	ldrb r1, [r5, #0x00]
	bl sub_08005870
	ldr r0, [r4, #0x00]
	adds r0, #0x86
	ldrb r1, [r5, #0x01]
	bl sub_08005870
	ldr r0, _08005A28 @ =0x020253C0
	ldr r6, [r0, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl sub_08017230
	movs r1, #0x0A
	bl sub_080172C8
	strb r0, [r5, #0x01]
	adds r0, r6, #0x0
	movs r1, #0x64
	bl sub_08017230
	strb r0, [r5, #0x00]
	ldr r0, [r4, #0x00]
	adds r0, #0xCA
	movs r1, #0x0A
	bl sub_080058CC
	ldr r0, [r4, #0x00]
	adds r0, #0xCC
	ldrb r1, [r5, #0x00]
	bl sub_080058CC
	ldr r0, [r4, #0x00]
	adds r0, #0xCE
	ldrb r1, [r5, #0x01]
	bl sub_080058CC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08005A1C: .4byte 0x0202525C
_08005A20: .4byte 0x0202521C
_08005A24: .4byte 0x08364B08
_08005A28: .4byte 0x020253C0
