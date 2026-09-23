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
	thumb_func_start sub_0833B1E8
sub_0833B1E8:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r12, r2
	cmp r0, #0x04
	bne _0833B220
	cmp r5, #0x14
	bhi _0833B204
	movs r5, #0x00
	b _0833B212
_0833B204:
	adds r0, r5, #0x0
	subs r0, #0x15
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x3B
	bls _0833B212
	movs r5, #0x3B
_0833B212:
	ldr r0, _0833B21C @ =0x0200C890
	adds r0, r5, r0
	ldrb r0, [r0, #0x00]
	b _0833B282
	.byte 0x00, 0x00
_0833B21C: .4byte 0x0200C890
_0833B220:
	cmp r5, #0x23
	bhi _0833B22C
	movs r0, #0x00
	mov r12, r0
	movs r5, #0x00
	b _0833B23E
_0833B22C:
	adds r0, r5, #0x0
	subs r0, #0x24
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x82
	bls _0833B23E
	movs r5, #0x82
	movs r1, #0xFF
	mov r12, r1
_0833B23E:
	ldr r3, _0833B288 @ =0x0200C7F4
	adds r0, r5, r3
	ldrb r6, [r0, #0x00]
	ldr r4, _0833B28C @ =0x0200C878
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
_0833B282:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_0833B288: .4byte 0x0200C7F4
_0833B28C: .4byte 0x0200C878
	thumb_func_start sub_0833B290
sub_0833B290:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0x0
	cmp r0, #0x02
	beq _0833B2B8
	cmp r0, #0x02
	bgt _0833B2A4
	cmp r0, #0x01
	beq _0833B2AA
	b _0833B2CC
_0833B2A4:
	cmp r1, #0x03
	beq _0833B2C0
	b _0833B2CC
_0833B2AA:
	ldr r1, _0833B2B4 @ =0x04000063
	movs r0, #0x08
	strb r0, [r1, #0x00]
	adds r1, #0x02
	b _0833B2D4
_0833B2B4: .4byte 0x04000063
_0833B2B8:
	ldr r1, _0833B2BC @ =0x04000069
	b _0833B2CE
_0833B2BC: .4byte 0x04000069
_0833B2C0:
	ldr r1, _0833B2C8 @ =0x04000070
	movs r0, #0x00
	b _0833B2D6
	.byte 0x00, 0x00
_0833B2C8: .4byte 0x04000070
_0833B2CC:
	ldr r1, _0833B2DC @ =0x04000079
_0833B2CE:
	movs r0, #0x08
	strb r0, [r1, #0x00]
	adds r1, #0x04
_0833B2D4:
	movs r0, #0x80
_0833B2D6:
	strb r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_0833B2DC: .4byte 0x04000079
