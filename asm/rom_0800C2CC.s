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
	thumb_func_start sub_0800C2CC
sub_0800C2CC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r12, r0
	mov r8, r1
	ldrb r1, [r3, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r2
	ldrh r4, [r0, #0x00]
	ldrh r5, [r0, #0x02]
	ldrb r7, [r3, #0x01]
	lsls r0, r7, #0x02
	adds r0, r0, r2
	mov r2, r12
	subs r1, r2, r4
	ldrh r7, [r0, #0x00]
	subs r6, r7, r4
	muls r1, r6
	mov r7, r8
	subs r2, r7, r5
	ldrh r0, [r0, #0x02]
	subs r7, r0, r5
	adds r0, r2, #0x0
	muls r0, r7
	adds r1, r1, r0
	ldrb r3, [r3, #0x02]
	muls r1, r3
	cmp r1, #0x00
	bge _0800C308
	movs r1, #0x00
	.global _0800C308
_0800C308:
	ldr r0, _0800C34C @ =0x0000FFFF
	cmp r1, r0
	ble _0800C310
	adds r1, r0, #0x0
	.global _0800C310
_0800C310:
	adds r0, r6, #0x0
	muls r0, r1
	asrs r0, r0, #0x10
	adds r3, r4, r0
	adds r0, r7, #0x0
	muls r0, r1
	asrs r0, r0, #0x10
	adds r2, r5, r0
	ldr r0, _0800C350 @ =0x0202CC24
	str r3, [r0, #0x00]
	ldr r0, _0800C354 @ =0x0202CC38
	str r2, [r0, #0x00]
	mov r1, r12
	subs r0, r1, r3
	asrs r3, r0, #0x02
	mov r7, r8
	subs r0, r7, r2
	asrs r2, r0, #0x02
	adds r1, r3, #0x0
	muls r1, r3
	adds r0, r2, #0x0
	muls r0, r2
	adds r1, r1, r0
	adds r0, r1, #0x0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _0800C34C
_0800C34C: .4byte 0x0000FFFF
	.global _0800C350
_0800C350: .4byte 0x0202CC24
	.global _0800C354
_0800C354: .4byte 0x0202CC38
	thumb_func_start sub_0800C358
sub_0800C358:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	adds r3, r0, #0x0
	adds r0, #0xF8
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	adds r0, r3, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	mov r10, r0
	movs r7, #0x01
	negs r7, r7
	ldr r0, _0800C3C4 @ =0x0202CC3C
	str r6, [r0, #0x00]
	ldr r1, [r3, #0x18]
	asrs r0, r1, #0x10
	mov r9, r0
	ldr r0, [r3, #0x1C]
	asrs r2, r0, #0x10
	mov r8, r2
	asrs r1, r1, #0x17
	asrs r2, r0, #0x17
	cmp r1, #0x00
	bge _0800C392
	movs r1, #0x00
	.global _0800C392
_0800C392:
	cmp r2, #0x00
	bge _0800C398
	movs r2, #0x00
	.global _0800C398
_0800C398:
	cmp r1, #0x2F
	ble _0800C39E
	movs r1, #0x2F
	.global _0800C39E
_0800C39E:
	cmp r2, #0x2F
	ble _0800C3A4
	movs r2, #0x2F
	.global _0800C3A4
_0800C3A4:
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x04
	adds r0, r0, r1
	movs r2, #0x80
	lsls r2, r2, #0x01
	adds r1, r3, r2
	ldr r1, [r1, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	adds r1, r3, #0x0
	adds r1, #0xFC
	ldr r1, [r1, #0x00]
	ldrh r0, [r0, #0x00]
	adds r5, r0, r1
	b _0800C3FC
	.global _0800C3C4
_0800C3C4: .4byte 0x0202CC3C
	.global _0800C3C8
_0800C3C8:
	ldrb r4, [r5, #0x00]
	lsls r0, r4, #0x02
	adds r0, r0, r4
	lsls r0, r0, #0x02
	ldr r1, [sp, #0x000]
	adds r6, r1, r0
	mov r0, r9
	mov r1, r8
	mov r2, r10
	adds r3, r6, #0x0
	bl sub_0800C2CC
	cmp r0, r7
	bhi _0800C3FA
	adds r7, r0, #0x0
	ldr r0, _0800C420 @ =0x0202CC3C
	str r6, [r0, #0x00]
	ldr r0, _0800C424 @ =0x0202CC34
	str r4, [r0, #0x00]
	ldr r0, _0800C428 @ =0x0202CC24
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x004]
	ldr r0, _0800C42C @ =0x0202CC38
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x008]
	.global _0800C3FA
_0800C3FA:
	adds r5, #0x01
	.global _0800C3FC
_0800C3FC:
	ldrb r0, [r5, #0x00]
	cmp r0, #0xFF
	bne _0800C3C8
	ldr r0, _0800C428 @ =0x0202CC24
	ldr r2, [sp, #0x004]
	str r2, [r0, #0x00]
	ldr r0, _0800C42C @ =0x0202CC38
	ldr r1, [sp, #0x008]
	str r1, [r0, #0x00]
	adds r0, r7, #0x0
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _0800C420
_0800C420: .4byte 0x0202CC3C
	.global _0800C424
_0800C424: .4byte 0x0202CC34
	.global _0800C428
_0800C428: .4byte 0x0202CC24
	.global _0800C42C
_0800C42C: .4byte 0x0202CC38
	thumb_func_start sub_0800C430
sub_0800C430:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r4, r0, #0x0
	ldr r5, _0800C4B0 @ =0x0202A550
	ldr r2, _0800C4B4 @ =0x0202CC28
	movs r0, #0x00
	strb r0, [r2, #0x00]
	ldr r1, _0800C4B8 @ =0x0202CC2C
	strb r0, [r1, #0x00]
	movs r6, #0x00
	ldr r0, _0800C4BC @ =0x02002090
	ldrb r0, [r0, #0x00]
	cmp r6, r0
	beq _0800C4D4
	adds r7, r2, #0x0
	.global _0800C44E
_0800C44E:
	cmp r4, r5
	beq _0800C4C4
	ldr r1, [r5, #0x00]
	ldr r0, [r4, #0x00]
	subs r0, r1, r0
	cmp r0, #0x00
	bge _0800C45E
	negs r0, r0
	.global _0800C45E
_0800C45E:
	movs r3, #0xFA
	lsls r3, r3, #0x10
	cmp r0, r3
	bgt _0800C4C4
	ldr r2, [r5, #0x08]
	ldr r0, [r4, #0x08]
	subs r0, r2, r0
	cmp r0, #0x00
	bge _0800C472
	negs r0, r0
	.global _0800C472
_0800C472:
	cmp r0, r3
	bgt _0800C4C4
	adds r0, r4, #0x0
	mov r3, sp
	bl sub_0800C0FC
	ldr r1, [sp, #0x004]
	movs r0, #0x10
	negs r0, r0
	cmp r1, r0
	bgt _0800C4C4
	ldr r2, [sp, #0x000]
	cmp r2, r0
	blt _0800C4C4
	cmp r2, #0x10
	bgt _0800C4C4
	subs r0, #0x70
	cmp r1, r0
	ble _0800C49E
	ldr r1, _0800C4B8 @ =0x0202CC2C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0800C49E
_0800C49E:
	ldr r1, [sp, #0x004]
	movs r0, #0x40
	negs r0, r0
	cmp r1, r0
	blt _0800C4C4
	cmp r2, #0x00
	bge _0800C4C0
	movs r0, #0x01
	b _0800C4C2
	.global _0800C4B0
_0800C4B0: .4byte 0x0202A550
	.global _0800C4B4
_0800C4B4: .4byte 0x0202CC28
	.global _0800C4B8
_0800C4B8: .4byte 0x0202CC2C
	.global _0800C4BC
_0800C4BC: .4byte 0x02002090
	.global _0800C4C0
_0800C4C0:
	movs r0, #0x02
	.global _0800C4C2
_0800C4C2:
	strb r0, [r7, #0x00]
	.global _0800C4C4
_0800C4C4:
	adds r6, #0x01
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r5, r5, r0
	ldr r0, _0800C4DC @ =0x02002090
	ldrb r0, [r0, #0x00]
	cmp r6, r0
	bne _0800C44E
	.global _0800C4D4
_0800C4D4:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800C4DC
_0800C4DC: .4byte 0x02002090
