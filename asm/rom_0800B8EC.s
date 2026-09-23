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
	thumb_func_start sub_0800B8EC
sub_0800B8EC:
	push {r4, r5, r6, lr}
	add sp, #-0x008
	adds r5, r0, #0x0
	ldr r0, [r5, #0x00]
	ldr r1, [r5, #0x08]
	mov r2, sp
	bl sub_08009BB4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800B9CC
	ldr r2, [sp, #0x000]
	adds r0, r2, #0x0
	subs r0, #0x08
	str r0, [sp, #0x000]
	ldr r1, [sp, #0x004]
	subs r1, #0x08
	ldr r0, [r5, #0x04]
	asrs r0, r0, #0x01
	adds r1, r1, r0
	str r1, [sp, #0x004]
	adds r2, #0x17
	movs r0, #0x87
	lsls r0, r0, #0x01
	cmp r2, r0
	bhi _0800B9CC
	cmp r1, #0x9F
	bgt _0800B9CC
	movs r0, #0x10
	negs r0, r0
	cmp r1, r0
	ble _0800B9CC
	ldr r2, _0800B990 @ =0x083FF6A4
	ldr r0, [r5, #0x18]
	movs r1, #0x1F
	ands r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	bl sub_0800754C
	adds r6, r0, #0x0
	cmp r6, #0x00
	beq _0800B9CC
	ldr r0, [r5, #0x00]
	asrs r0, r0, #0x13
	ldr r1, [r5, #0x08]
	asrs r1, r1, #0x13
	bl sub_0800CBB8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0800B99C
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	ldr r1, _0800B994 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r4, r0
	ldr r0, _0800B998 @ =0x08331F88
	bl sub_08007714
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	movs r1, #0x80
	lsls r1, r1, #0x04
	orrs r0, r1
	ldr r1, [r6, #0x10]
	orrs r1, r0
	adds r0, r4, #0x0
	bl sub_080044A4
	b _0800B9CC
	.byte 0x00, 0x00
_0800B990: .4byte 0x083FF6A4
_0800B994: .4byte 0x000001FF
_0800B998: .4byte 0x08331F88
_0800B99C:
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	ldr r1, _0800BA04 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r4, r0
	ldr r0, _0800BA08 @ =0x08331F88
	bl sub_08007714
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	movs r1, #0x80
	lsls r1, r1, #0x03
	orrs r0, r1
	ldr r1, [r6, #0x10]
	orrs r1, r0
	adds r0, r4, #0x0
	bl sub_080044A4
_0800B9CC:
	ldr r2, [r5, #0x18]
	adds r2, #0x01
	str r2, [r5, #0x18]
	ldr r0, [r5, #0x04]
	ldr r1, [r5, #0x1C]
	subs r0, r0, r1
	str r0, [r5, #0x04]
	ldr r0, [r5, #0x00]
	ldr r1, [r5, #0x28]
	adds r0, r0, r1
	str r0, [r5, #0x00]
	ldr r0, [r5, #0x08]
	ldr r1, [r5, #0x30]
	adds r0, r0, r1
	str r0, [r5, #0x08]
	cmp r2, #0x20
	bne _0800B9FA
	adds r0, r5, #0x0
	bl sub_08007950
	adds r0, r5, #0x0
	bl sub_0800792C
_0800B9FA:
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800BA04: .4byte 0x000001FF
_0800BA08: .4byte 0x08331F88
	thumb_func_start sub_0800BA0C
sub_0800BA0C:
	push {r4, lr}
	adds r4, r0, #0x0
	bl sub_0800D124
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x28]
	adds r0, r0, r1
	str r0, [r4, #0x00]
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x2C]
	adds r0, r0, r1
	str r0, [r4, #0x04]
	ldr r0, [r4, #0x08]
	ldr r1, [r4, #0x30]
	adds r0, r0, r1
	str r0, [r4, #0x08]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
