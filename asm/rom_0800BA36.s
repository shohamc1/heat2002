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
	thumb_func_start sub_0800BA38
sub_0800BA38:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x08]
	mov r2, sp
	bl sub_08009BB4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800BA70
	ldr r1, [sp, #0x000]
	subs r1, #0x78
	ldr r2, _0800BAF0 @ =0x02002100
	ldr r0, [r2, #0x18]
	adds r1, r1, r0
	ldr r0, [sp, #0x004]
	subs r0, #0x50
	ldr r2, [r2, #0x1C]
	adds r0, r0, r2
	lsls r1, r1, #0x10
	str r1, [sp, #0x000]
	lsls r0, r0, #0x10
	str r0, [sp, #0x004]
_0800BA70:
	ldr r0, [r4, #0x00]
	ldr r1, _0800BAF4 @ =0xFFF40000
	adds r1, r1, r0
	mov r10, r1
	movs r1, #0xC0
	lsls r1, r1, #0x0C
	adds r6, r0, r1
	ldr r0, [r4, #0x08]
	ldr r2, _0800BAF4 @ =0xFFF40000
	adds r5, r0, r2
	adds r3, r0, r1
	ldr r1, _0800BAF8 @ =0x0202A550
	movs r2, #0x00
	movs r7, #0x7C
	adds r7, r7, r1
	mov r9, r7
	movs r0, #0xB0
	lsls r0, r0, #0x01
	adds r0, r0, r1
	mov r8, r0
	movs r7, #0x32
	mov r12, r7
_0800BA9C:
	mov r7, r9
	ldrb r0, [r7, #0x00]
	cmp r0, #0x00
	bne _0800BABE
	ldr r0, [r1, #0x00]
	cmp r0, r10
	ble _0800BABE
	cmp r0, r6
	bge _0800BABE
	ldr r0, [r1, #0x08]
	cmp r0, r5
	ble _0800BABE
	cmp r0, r3
	bge _0800BABE
	mov r7, r12
	mov r0, r8
	strh r7, [r0, #0x00]
_0800BABE:
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x08
	bne _0800BA9C
	ldr r0, [r4, #0x18]
	subs r0, #0x01
	str r0, [r4, #0x18]
	cmp r0, #0x00
	bne _0800BADE
	adds r0, r4, #0x0
	bl sub_08007950
	adds r0, r4, #0x0
	bl sub_0800792C
_0800BADE:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800BAF0: .4byte 0x02002100
_0800BAF4: .4byte 0xFFF40000
_0800BAF8: .4byte 0x0202A550
	thumb_func_start sub_0800BAFC
sub_0800BAFC:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _0800BB34 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	beq _0800BB2E
	cmp r0, #0x0A
	beq _0800BB2E
	bl sub_080078E4
	adds r1, r0, #0x0
	cmp r1, #0x00
	beq _0800BB2E
	movs r0, #0xF0
	str r0, [r1, #0x18]
	str r4, [r1, #0x00]
	movs r0, #0x00
	str r0, [r1, #0x04]
	str r5, [r1, #0x08]
	ldr r0, _0800BB38 @ =0x0800BA39
	str r0, [r1, #0x0C]
	adds r0, r1, #0x0
	bl sub_0800793C
_0800BB2E:
	pop {r4, r5}
	pop {r0}
	bx r0
_0800BB34: .4byte 0x0200215C
_0800BB38: .4byte sub_0800BA38
	thumb_func_start sub_0800BB3C
sub_0800BB3C:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800BB40
sub_0800BB40:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800BB44
sub_0800BB44:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800BB48
sub_0800BB48:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800BB4C
sub_0800BB4C:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800BB50
sub_0800BB50:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800BB54
sub_0800BB54:
	bx lr
	.byte 0x00, 0x00
