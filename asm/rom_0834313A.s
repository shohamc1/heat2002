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
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_08343148
sub_08343148:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0x0
	adds r6, r0, #0x0
	ldrb r1, [r6, #0x00]
	adds r6, #0x01
	cmp r1, #0x00
	beq _083431AE
	movs r0, #0xFF
	mov r8, r0
	ands r0, r2
	mov r8, r0
	.global _08343162
_08343162:
	cmp r1, #0x20
	beq _083431A4
	lsls r1, r1, #0x01
	ldr r0, _083431B8 @ =0x0201F550
	adds r1, r1, r0
	ldr r2, _083431BC @ =0x0201F9D0
	ldrh r1, [r1, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x05
	ldr r1, _083431C0 @ =0x0201FB54
	adds r0, r0, r1
	bl sub_0833FCE0
	adds r5, r0, #0x0
	cmp r5, #0x00
	beq _083431A4
	ldr r4, _083431C4 @ =0x000001FF
	ands r4, r7
	lsls r4, r4, #0x10
	mov r0, r8
	orrs r4, r0
	ldr r0, _083431C8 @ =0x0201F390
	bl sub_0833FD78
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	ldr r1, [r5, #0x10]
	orrs r1, r0
	adds r0, r4, #0x0
	bl sub_0833D6A0
	.global _083431A4
_083431A4:
	adds r7, #0x08
	ldrb r1, [r6, #0x00]
	adds r6, #0x01
	cmp r1, #0x00
	bne _08343162
	.global _083431AE
_083431AE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _083431B8
_083431B8: .4byte 0x0201F550
	.global _083431BC
_083431BC: .4byte 0x0201F9D0
	.global _083431C0
_083431C0: .4byte 0x0201FB54
	.global _083431C4
_083431C4: .4byte 0x000001FF
	.global _083431C8
_083431C8: .4byte 0x0201F390
	thumb_func_start sub_083431CC
sub_083431CC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r5, #0x96
	lsls r5, r5, #0x01
	adds r4, r0, r5
	ldr r4, [r4, #0x00]
	asrs r4, r4, #0x0B
	negs r4, r4
	movs r5, #0x1F
	ands r4, r5
	lsls r4, r4, #0x03
	ldr r6, _08343230 @ =0x0200C3E8
	lsls r5, r4, #0x01
	adds r5, r5, r6
	mov r8, r5
	movs r7, #0x00
	ldsh r5, [r5, r7]
	mov r8, r5
	adds r4, #0x40
	lsls r4, r4, #0x01
	adds r4, r4, r6
	movs r6, #0x00
	ldsh r5, [r4, r6]
	ldr r4, [r0, #0x00]
	subs r1, r1, r4
	asrs r1, r1, #0x10
	ldr r0, [r0, #0x08]
	subs r2, r2, r0
	asrs r2, r2, #0x10
	adds r0, r1, #0x0
	muls r0, r5
	mov r4, r8
	muls r4, r2
	subs r0, r0, r4
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	mov r0, r8
	muls r0, r1
	adds r1, r2, #0x0
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x04]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08343230
_08343230: .4byte 0x0200C3E8
	thumb_func_start sub_08343234
sub_08343234:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r0, _083432B8 @ =0x020390A0
	ldrb r0, [r0, #0x00]
	mov r9, r0
	ldr r0, _083432BC @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08343256
	ldr r0, _083432C0 @ =0x020390BC
	ldrb r0, [r0, #0x00]
	mov r9, r0
	.global _08343256
_08343256:
	ldr r5, _083432C4 @ =0x0203D520
	movs r7, #0x00
	cmp r7, r9
	beq _083432D8
	mov r10, sp
	add r0, sp, #0x008
	mov r8, r0
	.global _08343264
_08343264:
	cmp r5, r4
	beq _083432C8
	ldr r1, [r5, #0x00]
	ldr r2, [r5, #0x08]
	adds r0, r4, #0x0
	mov r3, sp
	bl sub_083431CC
	mov r1, r10
	ldr r0, [r1, #0x04]
	adds r0, #0x64
	cmp r0, #0x64
	bhi _083432C8
	ldr r0, [sp, #0x000]
	movs r6, #0x10
	negs r6, r6
	cmp r0, r6
	blt _083432C8
	cmp r0, #0x10
	bgt _083432C8
	ldr r1, [r4, #0x00]
	ldr r2, [r4, #0x08]
	adds r0, r5, #0x0
	mov r3, r8
	bl sub_083431CC
	mov r1, r8
	ldr r0, [r1, #0x04]
	cmp r0, #0x00
	blt _083432C8
	ldr r0, [sp, #0x008]
	cmp r0, r6
	blt _083432C8
	cmp r0, #0x10
	bgt _083432C8
	movs r0, #0xBB
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x0F
	strb r0, [r1, #0x00]
	movs r0, #0x01
	b _083432DA
	.global _083432B8
_083432B8: .4byte 0x020390A0
	.global _083432BC
_083432BC: .4byte 0x020390EC
	.global _083432C0
_083432C0: .4byte 0x020390BC
	.global _083432C4
_083432C4: .4byte 0x0203D520
	.global _083432C8
_083432C8:
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r1, #0xC8
	lsls r1, r1, #0x01
	adds r5, r5, r1
	cmp r7, r9
	bne _08343264
	.global _083432D8
_083432D8:
	movs r0, #0x00
	.global _083432DA
_083432DA:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
