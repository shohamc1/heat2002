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
	thumb_func_start sub_08014BA4
sub_08014BA4:
	push {r4, r5, r6, r7, lr}
	ldr r4, _08014C38 @ =0xFFFFFE00
	add sp, r4
	movs r5, #0x00
	movs r0, #0x0C
	mov r1, sp
	bl sub_08011C9C
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r2, _08014C3C @ =0x00001341
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	bl sub_08014B14
	bl sub_080045D8
	bl sub_08007344
	bl sub_080073D8
	bl sub_08004484
	movs r0, #0x00
	bl sub_08014BA0
	bl sub_080047DC
	ldr r4, _08014C40 @ =0x020020C0
	strb r5, [r4, #0x00]
	bl sub_08000458
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r7, #0x40
	movs r6, #0x00
_08014BF0:
	bl sub_080073D8
	bl sub_08004484
	adds r0, r6, #0x0
	bl sub_08014BA0
	bl sub_080047DC
	bl sub_0800048C
	ldr r1, _08014C44 @ =0x020005CC
	movs r0, #0x01
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08014C14
	adds r7, r6, #0x0
_08014C14:
	movs r0, #0x00
	strb r0, [r4, #0x00]
	bl sub_08000458
	lsls r5, r7, #0x18
	cmp r5, #0x00
	bne _08014BF0
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r5, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08014C38: .4byte 0xFFFFFE00
_08014C3C: .4byte 0x00001341
_08014C40: .4byte 0x020020C0
_08014C44: .4byte 0x020005CC
	thumb_func_start sub_08014C48
sub_08014C48:
	push {lr}
	ldr r0, _08014C5C @ =0x0829F504
	movs r1, #0x38
	movs r2, #0x4C
	bl sub_08012384
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_08014C5C: .4byte 0x0829F504
