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
	thumb_func_start sub_0800B7E0
sub_0800B7E0:
	push {r4, r5, r6, lr}
	add sp, #-0x008
	adds r5, r0, #0x0
	ldr r0, [r5, #0x00]
	ldr r1, [r5, #0x08]
	mov r2, sp
	bl sub_08009BB4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800B864
	ldr r2, [sp, #0x000]
	subs r0, r2, #0x4
	str r0, [sp, #0x000]
	ldr r1, [sp, #0x004]
	subs r1, #0x04
	ldr r0, [r5, #0x04]
	asrs r0, r0, #0x02
	adds r1, r1, r0
	str r1, [sp, #0x004]
	adds r2, #0x1B
	movs r0, #0x87
	lsls r0, r0, #0x01
	cmp r2, r0
	bhi _0800B864
	cmp r1, #0x9F
	bgt _0800B864
	movs r0, #0x20
	negs r0, r0
	cmp r1, r0
	ble _0800B864
	ldr r2, _0800B89C @ =0x083FF60C
	ldr r0, [r5, #0x18]
	adds r0, #0x08
	movs r1, #0x07
	ands r0, r1
	adds r0, #0x08
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	bl sub_080076C8
	adds r6, r0, #0x0
	cmp r6, #0x00
	beq _0800B864
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	ldr r1, _0800B8A0 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	ldr r0, _0800B8A4 @ =0x08330D18
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
_0800B864:
	ldr r2, [r5, #0x18]
	adds r2, #0x02
	str r2, [r5, #0x18]
	ldr r0, [r5, #0x04]
	subs r0, #0x01
	str r0, [r5, #0x04]
	ldr r1, [r5, #0x28]
	asrs r1, r1, #0x01
	ldr r0, [r5, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x00]
	ldr r1, [r5, #0x30]
	asrs r1, r1, #0x01
	ldr r0, [r5, #0x08]
	adds r0, r0, r1
	str r0, [r5, #0x08]
	cmp r2, #0x10
	bne _0800B894
	adds r0, r5, #0x0
	bl sub_08007950
	adds r0, r5, #0x0
	bl sub_0800792C
_0800B894:
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0800B89C: .4byte 0x083FF60C
_0800B8A0: .4byte 0x000001FF
_0800B8A4: .4byte 0x08330D18
