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
	thumb_func_start sub_08342FF0
sub_08342FF0:
	push {r4, r5, r6, lr}
	add sp, #-0x008
	adds r5, r0, #0x0
	ldr r0, [r5, #0x00]
	ldr r1, [r5, #0x08]
	mov r2, sp
	bl sub_08341644
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _083430D0
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
	bhi _083430D0
	cmp r1, #0x9F
	bgt _083430D0
	movs r0, #0x10
	negs r0, r0
	cmp r1, r0
	ble _083430D0
	ldr r2, _08343094 @ =0x0202B370
	ldr r0, [r5, #0x18]
	movs r1, #0x1F
	ands r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	bl sub_0833FBB0
	adds r6, r0, #0x0
	cmp r6, #0x00
	beq _083430D0
	ldr r0, [r5, #0x00]
	asrs r0, r0, #0x13
	ldr r1, [r5, #0x08]
	asrs r1, r1, #0x13
	bl sub_08343464
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _083430A0
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	ldr r1, _08343098 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r4, r0
	ldr r0, _0834309C @ =0x0201F370
	bl sub_0833FD78
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	movs r1, #0x80
	lsls r1, r1, #0x04
	orrs r0, r1
	ldr r1, [r6, #0x10]
	orrs r1, r0
	adds r0, r4, #0x0
	bl sub_0833D6A0
	b _083430D0
	.byte 0x00, 0x00
_08343094: .4byte 0x0202B370
_08343098: .4byte 0x000001FF
_0834309C: .4byte 0x0201F370
_083430A0:
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	ldr r1, _08343108 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r4, r0
	ldr r0, _0834310C @ =0x0201F370
	bl sub_0833FD78
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	movs r1, #0x80
	lsls r1, r1, #0x03
	orrs r0, r1
	ldr r1, [r6, #0x10]
	orrs r1, r0
	adds r0, r4, #0x0
	bl sub_0833D6A0
_083430D0:
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
	bne _083430FE
	adds r0, r5, #0x0
	bl sub_0833FFA8
	adds r0, r5, #0x0
	bl sub_0833FF84
_083430FE:
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08343108: .4byte 0x000001FF
_0834310C: .4byte 0x0201F370
	thumb_func_start sub_08343110
sub_08343110:
	push {r4, lr}
	adds r4, r0, #0x0
	bl sub_08343948
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
