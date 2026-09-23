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
	thumb_func_start sub_08342E28
sub_08342E28:
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
	ldr r1, _08342EC4 @ =0x0203D520
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
	ldr r4, _08342EC8 @ =0x0200C3E8
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
	ldr r7, _08342ECC @ =0xFFF60000
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
	bl sub_08341644
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08342E9C
	ldr r0, [sp, #0x000]
	subs r0, #0x04
	str r0, [sp, #0x000]
	ldr r0, [sp, #0x004]
	subs r0, #0x06
	str r0, [sp, #0x004]
_08342E9C:
	ldr r1, [r6, #0x18]
	adds r1, #0x01
	str r1, [r6, #0x18]
	ldr r0, [r6, #0x08]
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	str r0, [r6, #0x08]
	cmp r1, #0x10
	bne _08342EBC
	adds r0, r6, #0x0
	bl sub_0833FFA8
	adds r0, r6, #0x0
	bl sub_0833FF84
_08342EBC:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08342EC4: .4byte 0x0203D520
_08342EC8: .4byte 0x0200C3E8
_08342ECC: .4byte 0xFFF60000
