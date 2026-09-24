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
	thumb_func_start sub_0800A4D4
sub_0800A4D4:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, _0800A50C @ =0x020020CC
	adds r5, r0, #0x0
	ldrb r0, [r5, #0x00]
	ldr r0, _0800A510 @ =0x020253D0
	ldrh r2, [r4, #0x38]
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x03
	ldr r0, [r0, #0x00]
	adds r2, r0, r1
	ldr r0, [r2, #0x00]
	ldr r1, [r2, #0x08]
	adds r0, r0, r1
	lsls r0, r0, #0x0F
	str r0, [r4, #0x00]
	ldr r0, [r2, #0x04]
	ldr r1, [r2, #0x0C]
	adds r0, r0, r1
	lsls r0, r0, #0x0F
	str r0, [r4, #0x08]
	ldrh r0, [r2, #0x10]
	cmp r0, #0x01
	bne _0800A514
	ldr r0, _0800A510 @ =0x020253D0
	ldr r2, [r0, #0x00]
	b _0800A516
_0800A50C: .4byte 0x020020CC
_0800A510: .4byte 0x020253D0
_0800A514:
	adds r2, #0x18
_0800A516:
	ldr r0, [r2, #0x00]
	ldr r1, [r2, #0x08]
	adds r0, r0, r1
	lsls r3, r0, #0x0F
	ldr r0, [r2, #0x04]
	ldr r1, [r2, #0x0C]
	adds r0, r0, r1
	lsls r1, r0, #0x0F
	ldr r0, [r4, #0x00]
	subs r3, r3, r0
	ldr r0, [r4, #0x08]
	subs r1, r1, r0
	ldrb r5, [r5, #0x00]
	cmp r5, #0x07
	beq _0800A54C
	asrs r0, r3, #0x04
	asrs r1, r1, #0x04
	bl Atan2
	lsls r0, r0, #0x08
	ldr r2, _0800A548 @ =0xFFFF8400
	adds r1, r2, #0x0
	subs r1, r1, r0
	strh r1, [r4, #0x34]
	b _0800A550
_0800A548: .4byte 0xFFFF8400
_0800A54C:
	ldrh r0, [r4, #0x36]
	strh r0, [r4, #0x34]
_0800A550:
	movs r2, #0x00
	strh r2, [r4, #0x3C]
	movs r1, #0x9E
	lsls r1, r1, #0x01
	adds r0, r4, r1
	str r2, [r0, #0x00]
	adds r1, #0x0C
	adds r0, r4, r1
	str r2, [r0, #0x00]
	str r2, [r4, #0x0C]
	str r2, [r4, #0x14]
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldrh r0, [r4, #0x34]
	str r0, [r1, #0x00]
	movs r0, #0x94
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldrh r0, [r4, #0x34]
	str r0, [r1, #0x00]
	movs r1, #0x98
	lsls r1, r1, #0x01
	adds r0, r4, r1
	str r2, [r0, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x4E
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _0800A5A8 @ =0x020253D0
	ldrh r3, [r4, #0x38]
	lsls r0, r3, #0x01
	adds r0, r0, r3
	lsls r0, r0, #0x03
	ldr r1, [r1, #0x00]
	adds r2, r1, r0
	ldrh r2, [r2, #0x10]
	cmp r2, #0x01
	bne _0800A5AC
	adds r1, r4, #0x0
	adds r1, #0x4D
	movs r0, #0x00
	strb r0, [r1, #0x00]
	b _0800A5B4
_0800A5A8: .4byte 0x020253D0
_0800A5AC:
	adds r1, r3, #0x1
	adds r0, r4, #0x0
	adds r0, #0x4D
	strb r1, [r0, #0x00]
_0800A5B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
