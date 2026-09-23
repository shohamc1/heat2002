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
	thumb_func_start sub_0833B78C
sub_0833B78C:
	push {r4, lr}
	adds r2, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, [r2, #0x34]
	ldr r0, _0833B7B0 @ =0x68736D53
	cmp r3, r0
	bne _0833B7A8
	strh r1, [r2, #0x1E]
	ldrh r4, [r2, #0x1C]
	adds r0, r1, #0x0
	muls r0, r4
	asrs r0, r0, #0x08
	strh r0, [r2, #0x20]
_0833B7A8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0833B7B0: .4byte 0x68736D53
	thumb_func_start sub_0833B7B4
sub_0833B7B4:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r6, r2, #0x10
	ldr r3, [r4, #0x34]
	ldr r0, _0833B818 @ =0x68736D53
	cmp r3, r0
	bne _0833B80C
	adds r0, r3, #0x1
	str r0, [r4, #0x34]
	ldrb r2, [r4, #0x08]
	ldr r1, [r4, #0x2C]
	movs r5, #0x01
	cmp r2, #0x00
	ble _0833B808
	movs r0, #0x80
	mov r8, r0
	lsrs r6, r6, #0x12
	movs r0, #0x03
	mov r12, r0
_0833B7E4:
	adds r0, r7, #0x0
	ands r0, r5
	cmp r0, #0x00
	beq _0833B7FE
	ldrb r3, [r1, #0x00]
	mov r0, r8
	ands r0, r3
	cmp r0, #0x00
	beq _0833B7FE
	strb r6, [r1, #0x13]
	mov r0, r12
	orrs r0, r3
	strb r0, [r1, #0x00]
_0833B7FE:
	subs r2, #0x01
	adds r1, #0x50
	lsls r5, r5, #0x01
	cmp r2, #0x00
	bgt _0833B7E4
_0833B808:
	ldr r0, _0833B818 @ =0x68736D53
	str r0, [r4, #0x34]
_0833B80C:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0833B818: .4byte 0x68736D53
