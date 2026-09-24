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
	thumb_func_start sub_08341F64
sub_08341F64:
	push {r4, lr}
	mov r12, r0
	ldr r2, _08341FF4 @ =0x0203B860
	ldrh r1, [r0, #0x38]
	lsls r0, r1, #0x01
	mov r3, r12
	ldrh r3, [r3, #0x38]
	adds r0, r0, r3
	lsls r0, r0, #0x03
	ldr r1, [r2, #0x00]
	adds r3, r1, r0
	ldr r0, [r3, #0x00]
	ldr r1, [r3, #0x08]
	adds r0, r0, r1
	lsls r0, r0, #0x0F
	mov r1, r12
	str r0, [r1, #0x00]
	ldr r0, [r3, #0x04]
	ldr r1, [r3, #0x0C]
	adds r0, r0, r1
	lsls r0, r0, #0x0F
	mov r1, r12
	str r0, [r1, #0x08]
	adds r4, r2, #0x0
	ldrh r3, [r3, #0x10]
	mov r3, r12
	ldrh r0, [r3, #0x36]
	movs r2, #0x00
	strh r0, [r3, #0x34]
	strh r2, [r3, #0x3C]
	movs r0, #0x9E
	lsls r0, r0, #0x01
	add r0, r12
	str r2, [r0, #0x00]
	movs r0, #0xA4
	lsls r0, r0, #0x01
	add r0, r12
	str r2, [r0, #0x00]
	str r2, [r3, #0x0C]
	str r2, [r3, #0x14]
	movs r1, #0x96
	lsls r1, r1, #0x01
	add r1, r12
	ldrh r0, [r3, #0x34]
	str r0, [r1, #0x00]
	movs r1, #0x94
	lsls r1, r1, #0x01
	add r1, r12
	ldrh r0, [r3, #0x34]
	str r0, [r1, #0x00]
	movs r0, #0x98
	lsls r0, r0, #0x01
	add r0, r12
	str r2, [r0, #0x00]
	mov r1, r12
	adds r1, #0x4E
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldrh r2, [r3, #0x38]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x03
	ldr r1, [r4, #0x00]
	adds r3, r1, r0
	ldrh r3, [r3, #0x10]
	cmp r3, #0x01
	bne _08341FF8
	mov r1, r12
	adds r1, #0x4D
	movs r0, #0x00
	strb r0, [r1, #0x00]
	b _08342000
_08341FF4: .4byte 0x0203B860
_08341FF8:
	adds r1, r2, #0x1
	mov r0, r12
	adds r0, #0x4D
	strb r1, [r0, #0x00]
_08342000:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
