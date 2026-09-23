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
	thumb_func_start sub_08001B28
sub_08001B28:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r12, r2
	cmp r0, #0x04
	bne _08001B60
	cmp r5, #0x14
	bhi _08001B44
	movs r5, #0x00
	b _08001B52
_08001B44:
	adds r0, r5, #0x0
	subs r0, #0x15
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x3B
	bls _08001B52
	movs r5, #0x3B
_08001B52:
	ldr r0, _08001B5C @ =0x0801D1B0
	adds r0, r5, r0
	ldrb r0, [r0, #0x00]
	b _08001BC2
	.byte 0x00, 0x00
_08001B5C: .4byte 0x0801D1B0
_08001B60:
	cmp r5, #0x23
	bhi _08001B6C
	movs r0, #0x00
	mov r12, r0
	movs r5, #0x00
	b _08001B7E
_08001B6C:
	adds r0, r5, #0x0
	subs r0, #0x24
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x82
	bls _08001B7E
	movs r5, #0x82
	movs r1, #0xFF
	mov r12, r1
_08001B7E:
	ldr r3, _08001BC8 @ =0x0801D114
	adds r0, r5, r3
	ldrb r6, [r0, #0x00]
	ldr r4, _08001BCC @ =0x0801D198
	movs r2, #0x0F
	adds r0, r6, #0x0
	ands r0, r2
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r7, #0x00
	ldsh r1, [r0, r7]
	asrs r0, r6, #0x04
	adds r6, r1, #0x0
	asrs r6, r0
	adds r0, r5, #0x1
	adds r0, r0, r3
	ldrb r1, [r0, #0x00]
	adds r0, r1, #0x0
	ands r0, r2
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r2, #0x00
	ldsh r0, [r0, r2]
	asrs r1, r1, #0x04
	asrs r0, r1
	subs r0, r0, r6
	mov r7, r12
	muls r7, r0
	adds r0, r7, #0x0
	asrs r0, r0, #0x08
	adds r0, r6, r0
	movs r1, #0x80
	lsls r1, r1, #0x04
	adds r0, r0, r1
_08001BC2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08001BC8: .4byte 0x0801D114
_08001BCC: .4byte 0x0801D198
	thumb_func_start sub_08001BD0
sub_08001BD0:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0x0
	cmp r0, #0x02
	beq _08001BF8
	cmp r0, #0x02
	bgt _08001BE4
	cmp r0, #0x01
	beq _08001BEA
	b _08001C0C
_08001BE4:
	cmp r1, #0x03
	beq _08001C00
	b _08001C0C
_08001BEA:
	ldr r1, _08001BF4 @ =0x04000063
	movs r0, #0x08
	strb r0, [r1, #0x00]
	adds r1, #0x02
	b _08001C14
_08001BF4: .4byte 0x04000063
_08001BF8:
	ldr r1, _08001BFC @ =0x04000069
	b _08001C0E
_08001BFC: .4byte 0x04000069
_08001C00:
	ldr r1, _08001C08 @ =0x04000070
	movs r0, #0x00
	b _08001C16
	.byte 0x00, 0x00
_08001C08: .4byte 0x04000070
_08001C0C:
	ldr r1, _08001C1C @ =0x04000079
_08001C0E:
	movs r0, #0x08
	strb r0, [r1, #0x00]
	adds r1, #0x04
_08001C14:
	movs r0, #0x80
_08001C16:
	strb r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_08001C1C: .4byte 0x04000079
