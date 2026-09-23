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
	thumb_func_start sub_0800B658
sub_0800B658:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r6, r0, #0x0
	adds r0, #0x34
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _0800B74C @ =0x0202A550
	adds r3, r0, r1
	ldr r2, [r6, #0x1C]
	adds r2, #0x02
	lsls r2, r2, #0x02
	adds r0, r3, #0x0
	adds r0, #0xC4
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xD4
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldrh r3, [r3, #0x34]
	lsrs r3, r3, #0x08
	ldr r4, _0800B750 @ =0x0801CD08
	lsls r2, r3, #0x01
	adds r2, r2, r4
	movs r7, #0x00
	ldsh r5, [r2, r7]
	adds r3, #0x40
	lsls r3, r3, #0x01
	adds r3, r3, r4
	movs r2, #0x00
	ldsh r3, [r3, r2]
	ldr r2, [r6, #0x08]
	ldr r7, _0800B754 @ =0xFFF60000
	adds r4, r2, r7
	adds r2, r4, #0x0
	muls r2, r5
	negs r2, r2
	asrs r2, r2, #0x08
	muls r3, r4
	asrs r4, r3, #0x08
	adds r0, r0, r2
	adds r1, r1, r4
	mov r2, sp
	bl sub_08009BB4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800B724
	ldr r1, [sp, #0x000]
	subs r0, r1, #0x4
	str r0, [sp, #0x000]
	ldr r0, [sp, #0x004]
	subs r2, r0, #0x6
	str r2, [sp, #0x004]
	adds r1, #0x1B
	movs r0, #0x87
	lsls r0, r0, #0x01
	cmp r1, r0
	bhi _0800B724
	cmp r2, #0x9F
	bgt _0800B724
	movs r0, #0x20
	negs r0, r0
	cmp r2, r0
	ble _0800B724
	ldr r2, _0800B758 @ =0x083FF64C
	ldr r0, [r6, #0x18]
	movs r1, #0x0F
	ands r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	bl sub_080076C8
	adds r5, r0, #0x0
	cmp r5, #0x00
	beq _0800B724
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	ldr r1, _0800B75C @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	ldr r0, _0800B760 @ =0x08331188
	bl sub_08007714
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	movs r1, #0x80
	lsls r1, r1, #0x04
	orrs r0, r1
	ldr r1, [r5, #0x10]
	orrs r1, r0
	adds r0, r4, #0x0
	bl sub_080044A4
_0800B724:
	ldr r1, [r6, #0x18]
	adds r1, #0x01
	str r1, [r6, #0x18]
	ldr r0, [r6, #0x08]
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	str r0, [r6, #0x08]
	cmp r1, #0x10
	bne _0800B744
	adds r0, r6, #0x0
	bl sub_08007950
	adds r0, r6, #0x0
	bl sub_0800792C
_0800B744:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0800B74C: .4byte 0x0202A550
_0800B750: .4byte 0x0801CD08
_0800B754: .4byte 0xFFF60000
_0800B758: .4byte 0x083FF64C
_0800B75C: .4byte 0x000001FF
_0800B760: .4byte 0x08331188
