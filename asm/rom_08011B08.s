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
	thumb_func_start sub_08011B08
sub_08011B08:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	bl sub_08011A50
	movs r0, #0x00
	mov r8, r0
	ldr r1, _08011B34 @ =0x0202ED78
	mov r10, r1
	movs r2, #0xFF
	mov r9, r2
	.global _08011B22
_08011B22:
	ldr r1, _08011B38 @ =0x04000128
	movs r0, #0x30
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08011B3C
	bl sub_08016E30
	b _08011B44
	.global _08011B34
_08011B34: .4byte 0x0202ED78
	.global _08011B38
_08011B38: .4byte 0x04000128
	.global _08011B3C
_08011B3C:
	movs r0, #0x01
	movs r1, #0x80
	bl sub_08016E14
	.global _08011B44
_08011B44:
	bl sub_0800048C
	ldr r7, _08011C28 @ =0x04000128
	ldr r1, [r7, #0x00]
	lsls r1, r1, #0x1A
	lsrs r1, r1, #0x1E
	adds r1, #0x01
	lsls r1, r1, #0x0C
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r0, r3, #0x0
	orrs r1, r0
	ldr r6, _08011C2C @ =0x0202EDD0
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	mov r2, r9
	ands r0, r2
	orrs r1, r0
	mov r3, r10
	strh r1, [r3, #0x00]
	ldrh r0, [r3, #0x00]
	bl sub_0800F818
	ldr r2, _08011C30 @ =0x0202EFA0
	mov r0, r9
	ldrb r1, [r2, #0x02]
	orrs r0, r1
	strb r0, [r2, #0x02]
	mov r0, r9
	ldrb r3, [r2, #0x06]
	orrs r0, r3
	strb r0, [r2, #0x06]
	mov r0, r9
	ldrb r1, [r2, #0x0A]
	orrs r0, r1
	strb r0, [r2, #0x0A]
	mov r0, r9
	ldrb r3, [r2, #0x0E]
	orrs r0, r3
	strb r0, [r2, #0x0E]
	ldr r5, _08011C34 @ =0x0202EEF4
	movs r0, #0x00
	strb r0, [r5, #0x00]
	ldr r4, _08011C38 @ =0x0202EF40
	ldrh r3, [r4, #0x00]
	lsrs r1, r3, #0x0C
	cmp r1, #0x01
	bne _08011BDA
	strb r1, [r2, #0x02]
	strb r1, [r5, #0x00]
	movs r0, #0x30
	ldrb r7, [r7, #0x00]
	ands r0, r7
	cmp r0, #0x00
	beq _08011BB6
	subs r0, r3, #0x1
	strb r0, [r6, #0x00]
	.global _08011BB6
_08011BB6:
	ldrh r3, [r4, #0x08]
	lsrs r0, r3, #0x0C
	cmp r0, #0x02
	bne _08011BDA
	strb r1, [r2, #0x06]
	strb r0, [r5, #0x00]
	ldrh r3, [r4, #0x10]
	lsrs r0, r3, #0x0C
	cmp r0, #0x03
	bne _08011BDA
	strb r1, [r2, #0x0A]
	strb r0, [r5, #0x00]
	ldrh r4, [r4, #0x18]
	lsrs r0, r4, #0x0C
	cmp r0, #0x04
	bne _08011BDA
	strb r1, [r2, #0x0E]
	strb r0, [r5, #0x00]
	.global _08011BDA
_08011BDA:
	ldr r1, _08011C3C @ =0x0202EF90
	ldr r0, _08011C28 @ =0x04000128
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x1A
	lsrs r0, r0, #0x1E
	strb r0, [r1, #0x00]
	ldr r1, _08011C40 @ =0x020020AC
	ldr r0, _08011C34 @ =0x0202EEF4
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _08011C00
	mov r0, r8
	subs r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	.global _08011C00
_08011C00:
	ldr r1, _08011C38 @ =0x0202EF40
	movs r0, #0x00
	strh r0, [r1, #0x00]
	strh r0, [r1, #0x08]
	strh r0, [r1, #0x10]
	strh r0, [r1, #0x18]
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0x05
	bne _08011B22
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08011C28
_08011C28: .4byte 0x04000128
	.global _08011C2C
_08011C2C: .4byte 0x0202EDD0
	.global _08011C30
_08011C30: .4byte 0x0202EFA0
	.global _08011C34
_08011C34: .4byte 0x0202EEF4
	.global _08011C38
_08011C38: .4byte 0x0202EF40
	.global _08011C3C
_08011C3C: .4byte 0x0202EF90
	.global _08011C40
_08011C40: .4byte 0x020020AC
