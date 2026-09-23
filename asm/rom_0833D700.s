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
	thumb_func_start sub_0833D700
sub_0833D700:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov r12, r1
	adds r5, r2, #0x0
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	ldr r4, _0833D74C @ =0x0203B600
	movs r0, #0x00
	ldsb r0, [r4, r0]
	cmp r0, #0x00
	blt _0833D758
	ldr r3, _0833D750 @ =0x0203B604
	ldrb r0, [r3, #0x00]
	cmp r0, #0x1E
	bhi _0833D758
	ldr r2, _0833D754 @ =0x0203B0E0
	ldr r1, [r2, #0x00]
	lsls r0, r0, #0x19
	mov r7, r8
	orrs r0, r7
	str r0, [r1, #0x00]
	mov r0, r12
	str r0, [r1, #0x04]
	strh r5, [r1, #0x08]
	strh r5, [r1, #0x0A]
	strh r6, [r1, #0x0C]
	adds r1, #0x10
	str r1, [r2, #0x00]
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	strb r0, [r4, #0x00]
	ldrb r0, [r3, #0x00]
	adds r0, #0x01
	strb r0, [r3, #0x00]
	movs r0, #0x01
	b _0833D75A
_0833D74C: .4byte 0x0203B600
_0833D750: .4byte 0x0203B604
_0833D754: .4byte 0x0203B0E0
_0833D758:
	movs r0, #0x00
_0833D75A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start sub_0833D764
sub_0833D764:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0x0
	mov r12, r1
	adds r5, r2, #0x0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	ldr r4, _0833D7B4 @ =0x0203B600
	movs r0, #0x00
	ldsb r0, [r4, r0]
	cmp r0, #0x00
	blt _0833D7C0
	ldr r3, _0833D7B8 @ =0x0203B604
	ldrb r0, [r3, #0x00]
	cmp r0, #0x1E
	bhi _0833D7C0
	ldr r2, _0833D7BC @ =0x0203B0E0
	ldr r1, [r2, #0x00]
	lsls r0, r0, #0x19
	orrs r0, r6
	str r0, [r1, #0x00]
	mov r7, r12
	str r7, [r1, #0x04]
	negs r0, r5
	strh r0, [r1, #0x08]
	strh r5, [r1, #0x0A]
	mov r0, r8
	strh r0, [r1, #0x0C]
	adds r1, #0x10
	str r1, [r2, #0x00]
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	strb r0, [r4, #0x00]
	ldrb r0, [r3, #0x00]
	adds r0, #0x01
	strb r0, [r3, #0x00]
	movs r0, #0x01
	b _0833D7C2
_0833D7B4: .4byte 0x0203B600
_0833D7B8: .4byte 0x0203B604
_0833D7BC: .4byte 0x0203B0E0
_0833D7C0:
	movs r0, #0x00
_0833D7C2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start sub_0833D7CC
sub_0833D7CC:
	add sp, #-0x028
	add sp, #0x028
	bx lr
	.byte 0x00, 0x00
