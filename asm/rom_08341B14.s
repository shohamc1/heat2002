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
	thumb_func_start sub_08341B14
sub_08341B14:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x028
	adds r4, r0, #0x0
	mov r8, r1
	movs r7, #0x00
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _08341C00
	ldr r0, _08341BA4 @ =0x0203E0E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341B4E
	ldr r1, _08341BA8 @ =0x00000175
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08341B4E
	adds r1, r4, #0x0
	adds r1, #0x9C
	ldr r0, [r1, #0x00]
	subs r0, #0x0A
	str r0, [r1, #0x00]
	cmp r0, #0x00
	bge _08341B4E
	str r7, [r1, #0x00]
	.global _08341B4E
_08341B4E:
	adds r0, r4, #0x0
	adds r0, #0xA2
	movs r1, #0x80
	lsls r1, r1, #0x01
	strh r1, [r0, #0x00]
	ldr r1, _08341BAC @ =0x0203D520
	mov r12, r0
	cmp r4, r1
	bne _08341B78
	subs r0, #0x06
	ldr r2, [r0, #0x00]
	cmp r2, #0x00
	bne _08341B78
	ldr r1, _08341BB0 @ =0x0203D4E8
	movs r0, #0x08
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08341B78
	mov r3, r12
	strh r2, [r3, #0x00]
	.global _08341B78
_08341B78:
	ldr r0, _08341BB4 @ =0x020390B8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341BB8
	adds r2, r4, #0x0
	adds r2, #0x3E
	movs r5, #0xE4
	adds r5, r5, r4
	mov r9, r5
	ldr r1, [r5, #0x00]
	ldrb r6, [r2, #0x00]
	lsls r0, r6, #0x01
	adds r0, r0, r1
	mov r1, r12
	ldrh r1, [r1, #0x00]
	ldrh r5, [r0, #0x00]
	adds r3, r1, #0x0
	muls r3, r5
	adds r0, r3, #0x0
	asrs r0, r0, #0x06
	b _08341BD8
	.byte 0x00, 0x00
	.global _08341BA4
_08341BA4: .4byte 0x0203E0E0
	.global _08341BA8
_08341BA8: .4byte 0x00000175
	.global _08341BAC
_08341BAC: .4byte 0x0203D520
	.global _08341BB0
_08341BB0: .4byte 0x0203D4E8
	.global _08341BB4
_08341BB4: .4byte 0x020390B8
	.global _08341BB8
_08341BB8:
	adds r2, r4, #0x0
	adds r2, #0x3E
	movs r6, #0xE4
	adds r6, r6, r4
	mov r9, r6
	ldr r1, [r6, #0x00]
	ldrb r3, [r2, #0x00]
	lsls r0, r3, #0x01
	adds r0, r0, r1
	mov r5, r12
	ldrh r5, [r5, #0x00]
	ldrh r1, [r0, #0x00]
	adds r6, r5, #0x0
	muls r6, r1
	adds r0, r6, #0x0
	asrs r0, r0, #0x08
	.global _08341BD8
_08341BD8:
	adds r7, r7, r0
	adds r6, r2, #0x0
	mov r3, r9
	ldr r0, [r4, #0x2C]
	adds r5, r4, #0x0
	adds r5, #0x40
	cmp r0, #0x00
	ble _08341C68
	ldr r0, [r3, #0x00]
	ldrb r2, [r6, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r0
	mov r3, r12
	ldrh r3, [r3, #0x00]
	ldrh r1, [r1, #0x00]
	adds r0, r3, #0x0
	muls r0, r1
	asrs r0, r0, #0x05
	adds r7, r7, r0
	b _08341C68
	.global _08341C00
_08341C00:
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	ble _08341C18
	movs r5, #0xA6
	lsls r5, r5, #0x01
	adds r1, r4, r5
	negs r0, r0
	asrs r0, r0, #0x02
	str r0, [r1, #0x00]
	adds r6, r4, #0x0
	adds r6, #0x3E
	b _08341C50
	.global _08341C18
_08341C18:
	adds r3, r4, #0x0
	adds r3, #0xA2
	ldrh r0, [r3, #0x00]
	cmp r0, #0x00
	beq _08341C56
	subs r0, #0x20
	strh r0, [r3, #0x00]
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, r1
	bls _08341C32
	strh r7, [r3, #0x00]
	.global _08341C32
_08341C32:
	adds r2, r4, #0x0
	adds r2, #0x3E
	adds r0, r4, #0x0
	adds r0, #0xE4
	ldr r1, [r0, #0x00]
	ldrb r6, [r2, #0x00]
	lsls r0, r6, #0x01
	adds r0, r0, r1
	ldrh r3, [r3, #0x00]
	ldrh r5, [r0, #0x00]
	adds r1, r3, #0x0
	muls r1, r5
	adds r0, r1, #0x0
	asrs r7, r0, #0x08
	adds r6, r2, #0x0
	.global _08341C50
_08341C50:
	adds r5, r4, #0x0
	adds r5, #0x40
	b _08341C68
	.global _08341C56
_08341C56:
	adds r1, r4, #0x0
	adds r1, #0x40
	ldrh r6, [r1, #0x00]
	lsls r0, r6, #0x02
	negs r0, r0
	asrs r7, r0, #0x10
	adds r6, r4, #0x0
	adds r6, #0x3E
	adds r5, r1, #0x0
	.global _08341C68
_08341C68:
	movs r0, #0x02
	mov r1, r8
	ands r0, r1
	cmp r0, #0x00
	beq _08341CD4
	ldrh r2, [r5, #0x00]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x01
	negs r0, r0
	asrs r0, r0, #0x08
	adds r7, r7, r0
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r1, r4, r3
	ldr r0, [r1, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x09
	adds r0, r0, r2
	str r0, [r1, #0x00]
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	ble _08341CD4
	ldr r0, _08341CB8 @ =0x020391F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08341CB0
	ldr r0, _08341CBC @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341CC0
	adds r0, r4, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341CC0
	.global _08341CB0
_08341CB0:
	adds r0, r4, #0x0
	bl sub_08342008
	b _08341CD4
	.global _08341CB8
_08341CB8: .4byte 0x020391F0
	.global _08341CBC
_08341CBC: .4byte 0x020390EC
	.global _08341CC0
_08341CC0:
	ldr r0, [r4, #0x2C]
	movs r2, #0xFA
	lsls r2, r2, #0x0A
	cmp r0, r2
	ble _08341CD4
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r1, r4, r3
	subs r0, r2, r0
	str r0, [r1, #0x00]
	.global _08341CD4
_08341CD4:
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	bge _08341CF8
	ldrh r1, [r5, #0x00]
	adds r0, r1, r7
	ldr r2, _08341CF4 @ =0x000032C8
	cmp r0, r2
	ble _08341CE6
	subs r7, r2, r1
	.global _08341CE6
_08341CE6:
	adds r0, r1, r7
	cmp r0, #0x00
	bge _08341CEE
	negs r7, r1
	.global _08341CEE
_08341CEE:
	adds r0, r1, r7
	b _08341CFA
	.byte 0x00, 0x00
	.global _08341CF4
_08341CF4: .4byte 0x000032C8
	.global _08341CF8
_08341CF8:
	movs r0, #0x00
	.global _08341CFA
_08341CFA:
	strh r0, [r5, #0x00]
	ldr r1, [r4, #0x2C]
	cmp r1, #0x00
	bgt _08341D0E
	adds r0, r4, #0x0
	bl sub_08341AC4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	b _08341D10
	.global _08341D0E
_08341D0E:
	movs r3, #0x00
	.global _08341D10
_08341D10:
	movs r0, #0x9E
	lsls r0, r0, #0x01
	adds r0, r0, r4
	mov r8, r0
	adds r0, r4, #0x0
	adds r0, #0xE8
	ldr r1, [r0, #0x00]
	ldrb r2, [r6, #0x00]
	lsls r0, r2, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	negs r0, r0
	muls r0, r7
	negs r0, r0
	asrs r0, r0, #0x08
	mov r1, r8
	str r0, [r1, #0x00]
	ldr r2, [r4, #0x2C]
	cmp r2, #0x00
	bgt _08341D50
	adds r0, r4, #0x0
	adds r0, #0xEC
	ldr r1, [r0, #0x00]
	lsls r0, r3, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	negs r0, r0
	muls r0, r2
	asrs r0, r0, #0x08
	strh r0, [r5, #0x00]
	strb r3, [r6, #0x00]
	b _08341D56
	.global _08341D50
_08341D50:
	movs r0, #0x00
	strb r0, [r6, #0x00]
	strh r0, [r5, #0x00]
	.global _08341D56
_08341D56:
	add sp, #0x028
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start sub_08341D64
sub_08341D64:
	push {r4, r5, lr}
	ldrh r1, [r0, #0x34]
	lsrs r2, r1, #0x0B
	negs r2, r2
	movs r1, #0x1F
	ands r2, r1
	lsls r2, r2, #0x03
	ldr r3, _08341D9C @ =0x0200C3E8
	lsls r1, r2, #0x01
	adds r1, r1, r3
	movs r5, #0x00
	ldsh r4, [r1, r5]
	adds r2, #0x40
	lsls r2, r2, #0x01
	adds r2, r2, r3
	movs r1, #0x00
	ldsh r3, [r2, r1]
	ldr r1, [r0, #0x0C]
	ldr r2, [r0, #0x14]
	muls r1, r4
	muls r2, r3
	adds r1, r1, r2
	asrs r1, r1, #0x08
	str r1, [r0, #0x2C]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08341D9C
_08341D9C: .4byte 0x0200C3E8
	thumb_func_start sub_08341DA0
sub_08341DA0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	mov r12, r0
	ldrh r0, [r0, #0x34]
	lsrs r2, r0, #0x08
	ldr r0, _08341EBC @ =0x0200C3E8
	lsls r1, r2, #0x01
	adds r1, r1, r0
	movs r4, #0x00
	ldsh r3, [r1, r4]
	mov r9, r3
	adds r1, r2, #0x0
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r0
	movs r2, #0x00
	ldsh r5, [r1, r2]
	mov r8, r5
	movs r7, #0x00
	ldr r3, _08341EC0 @ =0x020277B4
	mov r10, r3
	.global _08341DD2
_08341DD2:
	lsls r4, r7, #0x02
	mov r5, r10
	adds r5, #0x04
	mov r10, r5
	subs r5, #0x04
	ldm r5!, {r6}
	ldr r1, _08341EC4 @ =0x020277C4
	adds r0, r4, r1
	ldr r5, [r0, #0x00]
	mov r3, r12
	adds r3, #0xA4
	adds r3, r3, r4
	mov r0, r8
	muls r0, r6
	mov r1, r9
	muls r1, r5
	subs r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	mov r2, r12
	adds r2, #0xB4
	adds r2, r2, r4
	mov r0, r9
	muls r0, r6
	mov r1, r8
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r2, #0x00]
	ldr r0, [r3, #0x00]
	mov r4, r12
	ldr r1, [r4, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	ldr r0, [r2, #0x00]
	ldr r1, [r4, #0x08]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r7, #0x01
	cmp r7, #0x04
	bne _08341DD2
	movs r5, #0x3C
	ldsh r0, [r4, r5]
	ldrh r1, [r4, #0x34]
	adds r0, r1, r0
	asrs r2, r0, #0x08
	movs r0, #0xFF
	ands r2, r0
	lsls r0, r2, #0x01
	ldr r3, _08341EBC @ =0x0200C3E8
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r4, [r0, r5]
	mov r9, r4
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r2, #0x00
	ldsh r1, [r0, r2]
	mov r8, r1
	movs r7, #0x00
	movs r3, #0xC4
	add r3, r12
	mov r10, r3
	mov r4, r12
	adds r4, #0xD4
	ldr r5, _08341EC0 @ =0x020277B4
	str r5, [sp, #0x000]
	.global _08341E5C
_08341E5C:
	lsls r2, r7, #0x02
	ldr r0, [sp, #0x000]
	ldm r0!, {r6}
	str r0, [sp, #0x000]
	ldr r1, _08341EC4 @ =0x020277C4
	adds r0, r2, r1
	ldr r5, [r0, #0x00]
	mov r0, r10
	adds r3, r0, r2
	mov r0, r8
	muls r0, r6
	mov r1, r9
	muls r1, r5
	subs r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	adds r2, r4, r2
	mov r0, r9
	muls r0, r6
	mov r1, r8
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r2, #0x00]
	mov r5, r12
	ldr r1, [r5, #0x00]
	ldr r0, [r5, #0x0C]
	adds r1, r1, r0
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	ldr r1, [r5, #0x08]
	ldr r0, [r5, #0x14]
	adds r1, r1, r0
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r7, #0x01
	cmp r7, #0x04
	bne _08341E5C
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08341EBC
_08341EBC: .4byte 0x0200C3E8
	.global _08341EC0
_08341EC0: .4byte 0x020277B4
	.global _08341EC4
_08341EC4: .4byte 0x020277C4
