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
	thumb_func_start sub_0800BC4C
sub_0800BC4C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x030
	ldr r3, _0800BD18 @ =0x083671C0
	ldr r2, _0800BD1C @ =0x020020CC
	ldrb r2, [r2, #0x00]
	lsls r2, r2, #0x02
	adds r2, r2, r3
	ldr r7, [r2, #0x00]
	ldrb r3, [r1, #0x00]
	lsls r2, r3, #0x02
	adds r2, r2, r0
	ldrh r4, [r2, #0x00]
	str r4, [sp, #0x000]
	ldrb r5, [r1, #0x00]
	lsls r2, r5, #0x02
	adds r2, r2, r0
	ldrh r3, [r2, #0x02]
	str r3, [sp, #0x004]
	ldrb r5, [r1, #0x01]
	lsls r2, r5, #0x02
	adds r2, r2, r0
	ldrh r2, [r2, #0x00]
	str r2, [sp, #0x008]
	ldrb r1, [r1, #0x01]
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldrh r0, [r1, #0x02]
	str r0, [sp, #0x00C]
	str r4, [sp, #0x018]
	mov r10, r3
	str r2, [sp, #0x01C]
	str r0, [sp, #0x020]
	movs r0, #0x00
	str r0, [sp, #0x024]
	movs r1, #0x00
	str r1, [sp, #0x028]
	.global _0800BC9C
_0800BC9C:
	ldr r2, [r7, #0x00]
	mov r12, r2
	ldr r5, [r7, #0x04]
	ldr r2, [r7, #0x08]
	ldr r0, [r7, #0x0C]
	ldrh r3, [r7, #0x10]
	cmp r3, #0x01
	bne _0800BCB0
	movs r4, #0x01
	str r4, [sp, #0x024]
	.global _0800BCB0
_0800BCB0:
	ldr r1, [sp, #0x01C]
	ldr r3, [sp, #0x018]
	subs r1, r1, r3
	mov r9, r1
	subs r3, r0, r5
	mov r1, r9
	muls r1, r3
	ldr r4, [sp, #0x020]
	mov r0, r10
	subs r4, r4, r0
	mov r8, r4
	mov r4, r12
	subs r2, r2, r4
	mov r0, r8
	muls r0, r2
	subs r4, r1, r0
	cmp r4, #0x00
	beq _0800BD20
	mov r0, r10
	subs r6, r0, r5
	adds r0, r6, #0x0
	muls r0, r2
	ldr r1, [sp, #0x018]
	mov r2, r12
	subs r5, r1, r2
	adds r1, r5, #0x0
	muls r1, r3
	subs r0, r0, r1
	lsls r0, r0, #0x08
	adds r1, r4, #0x0
	bl sub_08017230
	movs r2, #0x80
	lsls r2, r2, #0x01
	cmp r0, r2
	bhi _0800BD20
	mov r0, r9
	muls r0, r6
	mov r1, r8
	muls r1, r5
	subs r0, r0, r1
	lsls r0, r0, #0x08
	adds r1, r4, #0x0
	str r2, [sp, #0x02C]
	bl sub_08017230
	ldr r2, [sp, #0x02C]
	cmp r0, r2
	bhi _0800BD20
	ldr r0, [sp, #0x028]
	b _0800BD32
	.byte 0x00, 0x00
	.global _0800BD18
_0800BD18: .4byte 0x083671C0
	.global _0800BD1C
_0800BD1C: .4byte 0x020020CC
	.global _0800BD20
_0800BD20:
	adds r7, #0x18
	ldr r3, [sp, #0x028]
	adds r3, #0x01
	str r3, [sp, #0x028]
	ldr r4, [sp, #0x024]
	cmp r4, #0x00
	beq _0800BC9C
	movs r0, #0x01
	negs r0, r0
	.global _0800BD32
_0800BD32:
	add sp, #0x030
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0800BD44
sub_0800BD44:
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0x0
	adds r5, r2, #0x0
	adds r6, r3, #0x0
	adds r4, r5, #0x0
	ldrh r1, [r5, #0x06]
	cmp r1, r0
	bge _0800BD5C
	.global _0800BD54
_0800BD54:
	adds r4, #0x14
	ldrh r1, [r4, #0x06]
	cmp r1, r0
	blt _0800BD54
	.global _0800BD5C
_0800BD5C:
	adds r0, r7, #0x0
	adds r1, r4, #0x0
	bl sub_0800BC4C
	adds r1, r0, #0x0
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	bne _0800BD84
	adds r4, #0x14
	ldrb r0, [r4, #0x01]
	cmp r0, #0xFF
	bne _0800BD5C
	adds r1, r6, #0x0
	adds r1, #0x4C
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	adds r4, r5, #0x0
	b _0800BD5C
	.global _0800BD84
_0800BD84:
	adds r0, r6, #0x0
	adds r0, #0x4D
	strb r1, [r0, #0x00]
	adds r1, r6, #0x0
	adds r1, #0x4E
	movs r0, #0x0F
	strb r0, [r1, #0x00]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start sub_0800BD98
sub_0800BD98:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r6, r2, #0x0
	adds r4, r3, #0x0
	ldrh r1, [r4, #0x06]
	cmp r1, r0
	bge _0800BDB2
	.global _0800BDAA
_0800BDAA:
	adds r4, #0x14
	ldrh r2, [r4, #0x06]
	cmp r2, r0
	blt _0800BDAA
	.global _0800BDB2
_0800BDB2:
	ldrh r1, [r4, #0x04]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r3, [r4, #0x06]
	subs r1, r3, r1
	bl sub_08017230
	ldrb r7, [r4, #0x01]
	lsls r2, r7, #0x02
	adds r2, r2, r6
	ldrb r3, [r4, #0x00]
	lsls r1, r3, #0x02
	adds r1, r1, r6
	ldrh r3, [r1, #0x00]
	ldrh r7, [r2, #0x00]
	subs r5, r7, r3
	ldrh r2, [r2, #0x02]
	ldrh r1, [r1, #0x02]
	subs r2, r2, r1
	adds r1, r5, #0x0
	muls r1, r0
	asrs r5, r1, #0x10
	muls r0, r2
	asrs r2, r0, #0x10
	adds r3, r3, r5
	mov r0, r8
	str r3, [r0, #0x00]
	ldrb r4, [r4, #0x00]
	lsls r0, r4, #0x02
	adds r0, r0, r6
	ldrh r0, [r0, #0x02]
	adds r0, r0, r2
	mov r1, r8
	str r0, [r1, #0x04]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
