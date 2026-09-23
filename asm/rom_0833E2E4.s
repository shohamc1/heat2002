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
	thumb_func_start sub_0833E2E4
sub_0833E2E4:
	ldr r0, _0833E2F8 @ =0x0203B6CC
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833E300
	ldr r0, _0833E2FC @ =0x0203B84C
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833E300
	movs r0, #0x00
	b _0833E302
_0833E2F8: .4byte 0x0203B6CC
_0833E2FC: .4byte 0x0203B84C
_0833E300:
	movs r0, #0x01
_0833E302:
	bx lr
	thumb_func_start sub_0833E304
sub_0833E304:
	push {r4, r5, lr}
	ldr r0, _0833E354 @ =0x020390D4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833E34E
	ldr r0, _0833E358 @ =0x020391F0
	ldrb r4, [r0, #0x00]
	cmp r4, #0x00
	bne _0833E34E
	ldr r5, _0833E35C @ =0x0203B84C
	ldr r1, [r5, #0x00]
	adds r0, r1, #0x0
	subs r0, #0x18
	str r0, [r5, #0x00]
	cmp r0, #0x00
	bge _0833E34E
	movs r2, #0xF4
	lsls r2, r2, #0x02
	adds r0, r1, r2
	str r0, [r5, #0x00]
	ldr r3, _0833E360 @ =0x0203B6CC
	ldr r1, [r3, #0x00]
	subs r1, #0x01
	str r1, [r3, #0x00]
	ldr r2, _0833E364 @ =0x0203B6E8
	movs r0, #0x01
	strb r0, [r2, #0x00]
	cmp r1, #0x00
	bge _0833E34E
	str r4, [r3, #0x00]
	str r4, [r5, #0x00]
	ldr r0, _0833E368 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833E34E
	bl sub_083429B4
_0833E34E:
	pop {r4, r5}
	pop {r0}
	bx r0
_0833E354: .4byte 0x020390D4
_0833E358: .4byte 0x020391F0
_0833E35C: .4byte 0x0203B84C
_0833E360: .4byte 0x0203B6CC
_0833E364: .4byte 0x0203B6E8
_0833E368: .4byte 0x0203916C
