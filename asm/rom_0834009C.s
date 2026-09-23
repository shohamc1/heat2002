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
	thumb_func_start sub_0834009C
sub_0834009C:
	push {r4, r5, lr}
	movs r3, #0x00
	ldr r1, _083400CC @ =0x0203D520
	ldr r5, _083400D0 @ =0x00000175
	movs r4, #0xC8
	lsls r4, r4, #0x01
_083400A8:
	adds r0, r1, r5
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _083400B6
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_083400B6:
	adds r1, r1, r4
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r1, r4
	cmp r3, #0x05
	bne _083400A8
	adds r0, r2, #0x0
	pop {r4, r5}
	pop {r1}
	bx r1
_083400CC: .4byte 0x0203D520
_083400D0: .4byte 0x00000175
	thumb_func_start sub_083400D4
sub_083400D4:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r2, #0x0
	adds r7, r3, #0x0
	ldr r2, [sp, #0x018]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	asrs r0, r0, #0x10
	ldr r3, _08340160 @ =0x02039110
	ldr r2, [r3, #0x18]
	subs r5, r0, r2
	asrs r1, r1, #0x10
	ldr r0, [r3, #0x1C]
	subs r4, r1, r0
	adds r4, #0x40
	adds r5, #0x70
	adds r1, r5, #0x0
	adds r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bhi _08340154
	cmp r4, #0xA0
	bgt _08340154
	movs r0, #0x10
	negs r0, r0
	cmp r4, r0
	blt _08340154
	adds r0, r6, #0x0
	bl sub_0833FC94
	adds r6, r0, #0x0
	cmp r6, #0x00
	beq _08340154
	adds r0, r7, #0x0
	bl sub_0833FD78
	lsls r0, r0, #0x18
	movs r2, #0xFF
	ands r2, r4
	ldr r1, _08340164 @ =0x000001FF
	ands r5, r1
	lsls r1, r5, #0x10
	orrs r2, r1
	movs r1, #0x80
	lsls r1, r1, #0x17
	orrs r2, r1
	lsrs r0, r0, #0x0C
	movs r1, #0x80
	lsls r1, r1, #0x04
	orrs r0, r1
	ldr r1, [r6, #0x10]
	orrs r1, r0
	mov r0, r8
	cmp r0, #0x00
	beq _0834014E
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r2, r0
_0834014E:
	adds r0, r2, #0x0
	bl sub_0833D6A0
_08340154:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08340160: .4byte 0x02039110
_08340164: .4byte 0x000001FF
	thumb_func_start sub_08340168
sub_08340168:
	adds r3, r0, #0x0
	ldr r2, _08340178 @ =0x02039200
	movs r1, #0x00
_0834016E:
	ldr r0, [r2, #0x00]
	cmp r0, r3
	bne _0834017C
	adds r0, r1, #0x0
	b _0834018A
_08340178: .4byte 0x02039200
_0834017C:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r2, #0x04
	cmp r1, #0x05
	bne _0834016E
	movs r0, #0x05
_0834018A:
	bx lr
	thumb_func_start sub_0834018C
sub_0834018C:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl sub_083415B0
	adds r0, r4, #0x0
	bl sub_08340168
	movs r1, #0xB2
	lsls r1, r1, #0x01
	adds r2, r4, r1
	ldr r1, _08340208 @ =0x02026DF4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r1
	ldrh r3, [r2, #0x00]
	ldrb r0, [r0, #0x00]
	adds r1, r3, r0
	strh r1, [r2, #0x00]
	movs r5, #0xB4
	lsls r5, r5, #0x01
	adds r3, r4, r5
	ldrb r0, [r3, #0x00]
	cmp r0, #0x00
	beq _083401C4
	adds r0, r1, #0x5
	strh r0, [r2, #0x00]
_083401C4:
	movs r2, #0x01
	movs r1, #0x00
	ldr r6, _0834020C @ =0x0203D520
_083401CA:
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r0, r0, r6
	cmp r4, r0
	beq _083401E6
	adds r0, r0, r5
	ldrb r0, [r0, #0x00]
	ldrb r7, [r3, #0x00]
	cmp r0, r7
	bls _083401E6
	movs r2, #0x00
_083401E6:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x05
	bne _083401CA
	cmp r2, #0x00
	beq _08340200
	movs r0, #0xB2
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x0A
	strh r0, [r1, #0x00]
_08340200:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08340208: .4byte 0x02026DF4
_0834020C: .4byte 0x0203D520
