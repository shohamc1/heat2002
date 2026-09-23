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
	thumb_func_start sub_08342C3C
sub_08342C3C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x060
	adds r7, r0, #0x0
	mov r4, sp
	ldr r0, _08342D04 @ =0x0203DE28
	ldr r5, [r0, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl sub_08344BB8
	movs r1, #0x0A
	bl sub_08344C50
	adds r0, #0x30
	movs r1, #0x00
	mov r8, r1
	strb r0, [r4, #0x00]
	mov r4, sp
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl sub_08344C50
	adds r0, #0x30
	strb r0, [r4, #0x01]
	mov r0, sp
	movs r6, #0x3A
	strb r6, [r0, #0x02]
	mov r4, sp
	ldr r0, _08342D08 @ =0x0203DE3C
	ldr r5, [r0, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl sub_08344BB8
	movs r1, #0x0A
	bl sub_08344C50
	adds r0, #0x30
	strb r0, [r4, #0x03]
	mov r4, sp
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl sub_08344C50
	adds r0, #0x30
	strb r0, [r4, #0x04]
	mov r0, sp
	strb r6, [r0, #0x05]
	mov r5, sp
	ldr r0, _08342D0C @ =0x0203DE20
	ldr r4, [r0, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x64
	bl sub_08344BB8
	movs r1, #0x0A
	bl sub_08344C50
	adds r0, #0x30
	strb r0, [r5, #0x06]
	mov r5, sp
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08344BB8
	movs r1, #0x0A
	bl sub_08344C50
	adds r0, #0x30
	strb r0, [r5, #0x07]
	mov r5, sp
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08344C50
	adds r0, #0x30
	strb r0, [r5, #0x08]
	mov r0, sp
	mov r1, r8
	strb r1, [r0, #0x09]
	ldr r0, [r7, #0x18]
	subs r0, #0x02
	str r0, [r7, #0x18]
	cmp r0, #0x00
	bne _08342CF6
	adds r0, r7, #0x0
	bl sub_0833FFA8
	adds r0, r7, #0x0
	bl sub_0833FF84
_08342CF6:
	add sp, #0x060
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08342D04: .4byte 0x0203DE28
_08342D08: .4byte 0x0203DE3C
_08342D0C: .4byte 0x0203DE20
