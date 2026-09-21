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
	thumb_func_start sub_0800D124
sub_0800D124:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x048
	adds r7, r0, #0x0
	ldr r0, _0800D1A8 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x07
	beq _0800D1A2
	ldr r1, [r7, #0x00]
	asrs r4, r1, #0x10
	str r4, [sp, #0x004]
	ldr r2, [r7, #0x08]
	asrs r6, r2, #0x10
	str r6, [sp, #0x008]
	ldr r3, [r7, #0x28]
	adds r1, r1, r3
	asrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	ldr r0, [r7, #0x30]
	adds r2, r2, r0
	asrs r2, r2, #0x10
	str r2, [sp, #0x010]
	asrs r3, r3, #0x08
	str r3, [sp, #0x014]
	asrs r0, r0, #0x08
	str r0, [sp, #0x018]
	cmp r4, r1
	bge _0800D160
	adds r1, r4, #0x0
	.global _0800D160
_0800D160:
	add r5, sp, #0x01C
	str r1, [sp, #0x01C]
	cmp r6, r2
	bge _0800D16A
	adds r2, r6, #0x0
	.global _0800D16A
_0800D16A:
	str r2, [r5, #0x08]
	ldr r1, [sp, #0x004]
	ldr r0, [sp, #0x00C]
	cmp r1, r0
	ble _0800D176
	adds r0, r1, #0x0
	.global _0800D176
_0800D176:
	str r0, [r5, #0x04]
	ldr r1, [sp, #0x008]
	ldr r0, [sp, #0x010]
	cmp r1, r0
	ble _0800D182
	adds r0, r1, #0x0
	.global _0800D182
_0800D182:
	str r0, [r5, #0x0C]
	ldr r0, [sp, #0x004]
	ldr r1, [sp, #0x008]
	bl sub_0800CC98
	add r4, sp, #0x02C
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r5, #0x0
	adds r2, r5, #0x0
	adds r3, r4, #0x0
	bl sub_0800CF7C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0800D1AC
	.global _0800D1A2
_0800D1A2:
	movs r0, #0x00
	b _0800D23A
	.byte 0x00, 0x00
	.global _0800D1A8
_0800D1A8: .4byte 0x0200215C
	.global _0800D1AC
_0800D1AC:
	ldr r0, [sp, #0x014]
	ldr r2, [r4, #0x04]
	adds r1, r0, #0x0
	muls r1, r2
	mov r8, r1
	ldr r0, [sp, #0x018]
	ldr r6, [r4, #0x08]
	muls r0, r6
	add r8, r0
	adds r0, r2, #0x0
	asrs r1, r2, #0x1F
	mov r4, r8
	asrs r5, r4, #0x1F
	adds r3, r5, #0x0
	adds r2, r4, #0x0
	bl sub_08017398
	lsls r3, r1, #0x0B
	lsrs r2, r0, #0x15
	orrs r3, r2
	str r3, [sp, #0x040]
	asrs r0, r1, #0x15
	str r0, [sp, #0x044]
	adds r0, r6, #0x0
	asrs r1, r6, #0x1F
	adds r3, r5, #0x0
	adds r2, r4, #0x0
	bl sub_08017398
	lsls r3, r1, #0x0B
	lsrs r2, r0, #0x15
	adds r4, r3, #0x0
	orrs r4, r2
	asrs r5, r1, #0x15
	ldr r2, [sp, #0x040]
	lsrs r3, r2, #0x1F
	ldr r0, [sp, #0x044]
	lsls r2, r0, #0x01
	adds r1, r3, #0x0
	orrs r1, r2
	ldr r2, [sp, #0x040]
	lsls r0, r2, #0x01
	ldr r2, [sp, #0x040]
	ldr r3, [sp, #0x044]
	adds r0, r0, r2
	adcs r1, r3
	lsls r3, r1, #0x1E
	lsrs r2, r0, #0x02
	orrs r3, r2
	str r3, [sp, #0x040]
	asrs r0, r1, #0x02
	str r0, [sp, #0x044]
	lsrs r3, r4, #0x1F
	lsls r2, r5, #0x01
	adds r1, r3, #0x0
	orrs r1, r2
	lsls r0, r4, #0x01
	adds r0, r0, r4
	adcs r1, r5
	lsls r3, r1, #0x1E
	lsrs r2, r0, #0x02
	adds r4, r3, #0x0
	orrs r4, r2
	ldr r0, [r7, #0x28]
	ldr r3, [sp, #0x040]
	subs r0, r0, r3
	str r0, [r7, #0x28]
	ldr r0, [r7, #0x30]
	subs r0, r0, r4
	str r0, [r7, #0x30]
	mov r0, r8
	.global _0800D23A
_0800D23A:
	add sp, #0x048
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0800D248
sub_0800D248:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x118
	mov r10, r0
	adds r0, #0x7C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0800D260
	b _0800D5A8
	.global _0800D260
_0800D260:
	movs r0, #0x00
	mov r12, r0
	mov r1, r10
	adds r1, #0xA4
	str r1, [sp, #0x114]
	mov r2, sp
	adds r2, #0x0C
	str r2, [sp, #0x0D8]
	mov r3, r10
	adds r3, #0xB4
	str r3, [sp, #0x0E4]
	mov r6, sp
	adds r6, #0x10
	str r6, [sp, #0x0DC]
	mov r7, r10
	adds r7, #0xC4
	str r7, [sp, #0x0F4]
	mov r0, sp
	adds r0, #0x14
	str r0, [sp, #0x0E0]
	adds r1, #0x30
	str r1, [sp, #0x0F8]
	adds r2, #0x0C
	str r2, [sp, #0x0E8]
	mov r3, sp
	adds r3, #0x1C
	str r3, [sp, #0x0F0]
	adds r6, #0x58
	str r6, [sp, #0x0FC]
	mov r7, sp
	adds r7, #0x70
	str r7, [sp, #0x104]
	adds r0, #0x58
	str r0, [sp, #0x100]
	mov r1, sp
	adds r1, #0x74
	str r1, [sp, #0x108]
	adds r2, #0x90
	str r2, [sp, #0x10C]
	adds r3, #0xB0
	str r3, [sp, #0x0EC]
	adds r6, #0x50
	str r6, [sp, #0x110]
	add r7, sp, #0x008
	mov r8, r7
	movs r0, #0x00
	mov r9, r0
	.global _0800D2BE
_0800D2BE:
	mov r2, r12
	lsls r1, r2, #0x02
	ldr r3, [sp, #0x114]
	adds r0, r3, r1
	ldr r4, [r0, #0x00]
	mov r6, r8
	str r4, [r6, #0x00]
	ldr r7, [sp, #0x0D8]
	add r7, r9
	ldr r2, [sp, #0x0E4]
	adds r0, r2, r1
	ldr r3, [r0, #0x00]
	str r3, [r7, #0x00]
	ldr r5, [sp, #0x0DC]
	add r5, r9
	ldr r6, [sp, #0x0F4]
	adds r0, r6, r1
	ldr r2, [r0, #0x00]
	str r2, [r5, #0x00]
	ldr r6, [sp, #0x0E0]
	add r6, r9
	ldr r0, [sp, #0x0F8]
	adds r1, r0, r1
	ldr r0, [r1, #0x00]
	str r0, [r6, #0x00]
	ldr r1, [sp, #0x0E8]
	add r1, r9
	subs r2, r2, r4
	str r2, [r1, #0x00]
	ldr r1, [sp, #0x0F0]
	add r1, r9
	subs r0, r0, r3
	str r0, [r1, #0x00]
	mov r2, r8
	ldr r1, [r2, #0x00]
	ldr r0, [r5, #0x00]
	cmp r1, r0
	bge _0800D30C
	adds r0, r1, #0x0
	.global _0800D30C
_0800D30C:
	mov r3, r12
	lsls r2, r3, #0x04
	ldr r3, [sp, #0x0FC]
	adds r1, r3, r2
	asrs r0, r0, #0x10
	str r0, [r1, #0x00]
	ldr r1, [r7, #0x00]
	ldr r0, [r6, #0x00]
	cmp r1, r0
	bge _0800D322
	adds r0, r1, #0x0
	.global _0800D322
_0800D322:
	ldr r3, [sp, #0x104]
	adds r1, r3, r2
	asrs r0, r0, #0x10
	str r0, [r1, #0x00]
	mov r0, r8
	ldr r1, [r0, #0x00]
	ldr r0, [r5, #0x00]
	cmp r1, r0
	ble _0800D336
	adds r0, r1, #0x0
	.global _0800D336
_0800D336:
	ldr r3, [sp, #0x100]
	adds r1, r3, r2
	asrs r0, r0, #0x10
	str r0, [r1, #0x00]
	ldr r1, [r7, #0x00]
	ldr r0, [r6, #0x00]
	cmp r1, r0
	ble _0800D348
	adds r0, r1, #0x0
	.global _0800D348
_0800D348:
	ldr r6, [sp, #0x108]
	adds r1, r6, r2
	asrs r0, r0, #0x10
	str r0, [r1, #0x00]
	movs r7, #0x18
	add r8, r7
	movs r0, #0x18
	add r9, r0
	movs r1, #0x01
	add r12, r1
	mov r2, r12
	cmp r2, #0x04
	bne _0800D2BE
	ldr r6, [sp, #0x0FC]
	ldr r1, [sp, #0x068]
	ldr r0, [r6, #0x10]
	cmp r1, r0
	bge _0800D36E
	adds r0, r1, #0x0
	.global _0800D36E
_0800D36E:
	ldr r7, [sp, #0x10C]
	str r0, [r7, #0x00]
	ldr r1, [r6, #0x20]
	cmp r0, r1
	bge _0800D37A
	adds r1, r0, #0x0
	.global _0800D37A
_0800D37A:
	str r1, [r7, #0x00]
	ldr r0, [r6, #0x30]
	cmp r1, r0
	bge _0800D384
	adds r0, r1, #0x0
	.global _0800D384
_0800D384:
	str r0, [r7, #0x00]
	ldr r1, [r6, #0x08]
	ldr r0, [r6, #0x18]
	cmp r1, r0
	bge _0800D390
	adds r0, r1, #0x0
	.global _0800D390
_0800D390:
	str r0, [r7, #0x08]
	ldr r1, [r6, #0x28]
	cmp r0, r1
	bge _0800D39A
	adds r1, r0, #0x0
	.global _0800D39A
_0800D39A:
	str r1, [r7, #0x08]
	ldr r0, [r6, #0x38]
	cmp r1, r0
	bge _0800D3A4
	adds r0, r1, #0x0
	.global _0800D3A4
_0800D3A4:
	str r0, [r7, #0x08]
	ldr r1, [r6, #0x04]
	ldr r0, [r6, #0x14]
	cmp r1, r0
	ble _0800D3B0
	adds r0, r1, #0x0
	.global _0800D3B0
_0800D3B0:
	str r0, [r7, #0x04]
	ldr r1, [r6, #0x24]
	cmp r0, r1
	ble _0800D3BA
	adds r1, r0, #0x0
	.global _0800D3BA
_0800D3BA:
	str r1, [r7, #0x04]
	ldr r0, [r6, #0x34]
	cmp r1, r0
	ble _0800D3C4
	adds r0, r1, #0x0
	.global _0800D3C4
_0800D3C4:
	str r0, [r7, #0x04]
	ldr r1, [r6, #0x0C]
	ldr r0, [r6, #0x1C]
	cmp r1, r0
	ble _0800D3D0
	adds r0, r1, #0x0
	.global _0800D3D0
_0800D3D0:
	str r0, [r7, #0x0C]
	ldr r1, [r6, #0x2C]
	cmp r0, r1
	ble _0800D3DA
	adds r1, r0, #0x0
	.global _0800D3DA
_0800D3DA:
	str r1, [r7, #0x0C]
	ldr r0, [r6, #0x3C]
	cmp r1, r0
	ble _0800D3E4
	adds r0, r1, #0x0
	.global _0800D3E4
_0800D3E4:
	str r0, [r7, #0x0C]
	ldr r0, [sp, #0x008]
	asrs r0, r0, #0x10
	ldr r1, [sp, #0x00C]
	asrs r1, r1, #0x10
	bl sub_0800CC98
	ldr r5, _0800D588 @ =0x0001869F
	ldr r3, [sp, #0x0EC]
	str r5, [r3, #0x00]
	str r0, [sp, #0x000]
	add r4, sp, #0x0CC
	str r4, [sp, #0x004]
	add r0, sp, #0x008
	adds r1, r7, #0x0
	adds r2, r6, #0x0
	ldr r3, [sp, #0x110]
	bl sub_0800CD38
	ldr r0, [r4, #0x00]
	cmp r0, r5
	bne _0800D412
	b _0800D5A8
	.global _0800D412
_0800D412:
	ldr r6, [sp, #0x110]
	ldrb r6, [r6, #0x0C]
	lsls r4, r6, #0x01
	ldr r7, [sp, #0x110]
	ldrb r7, [r7, #0x0C]
	adds r4, r4, r7
	lsls r4, r4, #0x03
	ldr r1, [sp, #0x0E8]
	adds r0, r1, r4
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	asrs r1, r2, #0x1F
	ldr r2, [sp, #0x110]
	ldr r5, [r2, #0x04]
	adds r2, r5, #0x0
	asrs r3, r5, #0x1F
	bl sub_08017398
	str r0, [sp, #0x0D0]
	str r1, [sp, #0x0D4]
	ldr r3, [sp, #0x0F0]
	adds r4, r3, r4
	ldr r2, [r4, #0x00]
	adds r0, r2, #0x0
	asrs r1, r2, #0x1F
	ldr r6, [sp, #0x110]
	ldr r4, [r6, #0x08]
	adds r2, r4, #0x0
	asrs r3, r4, #0x1F
	bl sub_08017398
	ldr r2, [sp, #0x0D0]
	ldr r3, [sp, #0x0D4]
	adds r2, r2, r0
	adcs r3, r1
	str r2, [sp, #0x0D0]
	str r3, [sp, #0x0D4]
	lsrs r3, r2, #0x1F
	ldr r6, [sp, #0x0D4]
	lsls r2, r6, #0x01
	adds r1, r3, #0x0
	orrs r1, r2
	ldr r7, [sp, #0x0D0]
	lsls r0, r7, #0x01
	ldr r2, [sp, #0x0D0]
	ldr r3, [sp, #0x0D4]
	adds r0, r0, r2
	adcs r1, r3
	lsrs r5, r0, #0x1A
	lsls r4, r1, #0x06
	adds r3, r5, #0x0
	orrs r3, r4
	lsls r2, r0, #0x06
	lsls r1, r3, #0x18
	lsrs r0, r2, #0x08
	orrs r1, r0
	str r1, [sp, #0x0D0]
	asrs r2, r3, #0x08
	str r2, [sp, #0x0D4]
	movs r0, #0x01
	negs r0, r0
	cmp r2, r0
	bgt _0800D49E
	cmp r2, r0
	bne _0800D4A6
	movs r0, #0x80
	lsls r0, r0, #0x18
	adds r3, r1, #0x0
	cmp r3, r0
	bls _0800D4A6
	.global _0800D49E
_0800D49E:
	ldr r6, _0800D58C @ =0x80000000
	ldr r7, _0800D590 @ =0xFFFFFFFF
	str r6, [sp, #0x0D0]
	str r7, [sp, #0x0D4]
	.global _0800D4A6
_0800D4A6:
	ldr r7, [sp, #0x110]
	ldr r7, [r7, #0x04]
	mov r9, r7
	mov r0, r9
	asrs r1, r0, #0x1F
	ldr r2, [sp, #0x0D0]
	ldr r3, [sp, #0x0D4]
	bl sub_08017398
	adds r5, r1, #0x0
	adds r4, r0, #0x0
	lsls r1, r5, #0x03
	lsrs r0, r4, #0x1D
	adds r4, r1, #0x0
	orrs r4, r0
	ldr r0, [sp, #0x110]
	ldr r0, [r0, #0x08]
	mov r8, r0
	asrs r1, r0, #0x1F
	ldr r2, [sp, #0x0D0]
	ldr r3, [sp, #0x0D4]
	bl sub_08017398
	lsls r3, r1, #0x03
	lsrs r2, r0, #0x1D
	adds r0, r3, #0x0
	orrs r0, r2
	ldr r2, _0800D594 @ =0x0202CC70
	mov r3, r10
	ldr r6, [r3, #0x0C]
	str r6, [r2, #0x00]
	ldr r2, _0800D598 @ =0x0202CC64
	ldr r3, [r3, #0x14]
	str r3, [r2, #0x00]
	ldr r2, _0800D59C @ =0x0202CC4C
	ldr r7, [sp, #0x0D0]
	str r7, [r2, #0x00]
	ldr r2, _0800D5A0 @ =0x0202CC50
	mov r7, r9
	str r7, [r2, #0x04]
	mov r7, r8
	str r7, [r2, #0x08]
	subs r6, r6, r4
	mov r2, r10
	str r6, [r2, #0x0C]
	subs r3, r3, r0
	str r3, [r2, #0x14]
	ldr r3, [sp, #0x110]
	ldrb r3, [r3, #0x0C]
	lsls r1, r3, #0x02
	ldr r6, [sp, #0x114]
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	ldr r7, [sp, #0x0E4]
	adds r1, r7, r1
	ldr r1, [r1, #0x00]
	bl sub_0800B614
	ldr r2, _0800D5A4 @ =0x0801CD08
	ldr r0, [sp, #0x110]
	ldrb r3, [r0, #0x0D]
	lsls r0, r3, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r5, [r0, r1]
	adds r0, r3, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r6, #0x00
	ldsh r4, [r0, r6]
	mov r7, r10
	ldrh r7, [r7, #0x34]
	lsrs r1, r7, #0x08
	lsls r0, r1, #0x01
	adds r0, r0, r2
	movs r6, #0x00
	ldsh r0, [r0, r6]
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r2
	movs r7, #0x00
	ldsh r1, [r1, r7]
	muls r0, r5
	muls r1, r4
	adds r0, r0, r1
	cmp r0, #0x00
	bgt _0800D55A
	ldr r0, [sp, #0x110]
	ldrb r3, [r0, #0x0E]
	.global _0800D55A
_0800D55A:
	movs r1, #0x96
	lsls r1, r1, #0x01
	add r1, r10
	lsls r0, r3, #0x08
	str r0, [r1, #0x00]
	mov r1, r10
	ldrh r1, [r1, #0x34]
	subs r0, r0, r1
	lsls r3, r0, #0x10
	asrs r3, r3, #0x14
	mov r2, r10
	ldrh r2, [r2, #0x3C]
	adds r0, r2, r3
	mov r3, r10
	strh r0, [r3, #0x3C]
	ldr r6, [sp, #0x0D4]
	lsls r3, r6, #0x19
	ldr r7, [sp, #0x0D0]
	lsrs r2, r7, #0x07
	adds r0, r3, #0x0
	orrs r0, r2
	b _0800D5AA
	.byte 0x00, 0x00
	.global _0800D588
_0800D588: .4byte 0x0001869F
	.global _0800D58C
_0800D58C: .4byte 0x80000000
	.global _0800D590
_0800D590: .4byte 0xFFFFFFFF
	.global _0800D594
_0800D594: .4byte 0x0202CC70
	.global _0800D598
_0800D598: .4byte 0x0202CC64
	.global _0800D59C
_0800D59C: .4byte 0x0202CC4C
	.global _0800D5A0
_0800D5A0: .4byte 0x0202CC50
	.global _0800D5A4
_0800D5A4: .4byte 0x0801CD08
	.global _0800D5A8
_0800D5A8:
	movs r0, #0x00
	.global _0800D5AA
_0800D5AA:
	add sp, #0x118
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x02, 0x1C, 0x08, 0x1C, 0x82, 0x42, 0x00, 0xDA, 0x10, 0x1C, 0x70, 0x47, 0x02, 0x1C
	.byte 0x08, 0x1C, 0x82, 0x42, 0x00, 0xDD, 0x10, 0x1C, 0x70, 0x47
