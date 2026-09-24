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
	thumb_func_start sub_08003E28
sub_08003E28:
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r3, r1, #0x0
	movs r6, #0x00
	movs r5, #0x1F
_08003E32:
	ldm r4!, {r0}
	ldm r4!, {r1}
	ldm r4!, {r2}
	asrs r0, r0, #0x10
	asrs r1, r1, #0x10
	asrs r2, r2, #0x10
	ands r0, r5
	ands r1, r5
	ands r2, r5
	lsls r1, r1, #0x05
	orrs r0, r1
	lsls r2, r2, #0x0A
	orrs r0, r2
	strh r0, [r3, #0x00]
	adds r3, #0x02
	adds r6, #0x01
	cmp r6, #0x10
	bne _08003E32
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_start sub_08003E5C
sub_08003E5C:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldm r4!, {r2}
	asrs r2, r2, #0x10
	movs r5, #0x06
	ldsh r3, [r0, r5]
	movs r0, #0x06
	ldsh r4, [r4, r0]
	movs r0, #0x1F
	ands r2, r0
	ands r3, r0
	ands r4, r0
	lsls r3, r3, #0x05
	orrs r2, r3
	lsls r4, r4, #0x0A
	orrs r2, r4
	strh r2, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_start sub_08003E84
sub_08003E84:
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	adds r4, r2, #0x0
	adds r5, r1, #0x0
	movs r0, #0x00
	mov r12, r0
	movs r7, #0x1F
_08003E92:
	ldrh r3, [r5, #0x00]
	adds r5, #0x02
	adds r1, r3, #0x0
	ands r3, r7
	asrs r2, r1, #0x05
	ands r2, r7
	asrs r1, r1, #0x0A
	ands r1, r7
	lsls r3, r3, #0x10
	lsls r2, r2, #0x10
	lsls r1, r1, #0x10
	ldm r6!, {r0}
	subs r0, r3, r0
	adds r3, r4, #0x0
	adds r4, #0x04
	cmp r0, #0x00
	bge _08003EB6
	adds r0, #0x0F
_08003EB6:
	asrs r0, r0, #0x04
	str r0, [r3, #0x00]
	ldm r6!, {r0}
	subs r0, r2, r0
	adds r2, r4, #0x0
	adds r4, #0x04
	cmp r0, #0x00
	bge _08003EC8
	adds r0, #0x0F
_08003EC8:
	asrs r0, r0, #0x04
	str r0, [r2, #0x00]
	ldm r6!, {r0}
	subs r0, r1, r0
	adds r3, r4, #0x0
	adds r4, r3, #0x4
	cmp r0, #0x00
	bge _08003EDA
	adds r0, #0x0F
_08003EDA:
	asrs r0, r0, #0x04
	str r0, [r3, #0x00]
	movs r0, #0x01
	add r12, r0
	mov r0, r12
	cmp r0, #0x10
	bne _08003E92
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start sub_08003EF0
sub_08003EF0:
	push {r4, lr}
	adds r2, r0, #0x0
	adds r4, r1, #0x0
	movs r3, #0x00
_08003EF8:
	ldr r0, [r2, #0x00]
	ldm r4!, {r1}
	adds r0, r0, r1
	stm r2!, {r0}
	adds r3, #0x01
	cmp r3, #0x30
	bne _08003EF8
	pop {r4}
	pop {r0}
	bx r0
