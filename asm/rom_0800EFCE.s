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
	thumb_func_start sub_0800EFD0
sub_0800EFD0:
	push {r4, r5, r6, lr}
	adds r3, r0, #0x0
	ldrb r0, [r3, #0x18]
	cmp r0, #0xE0
	beq _0800EFEC
	cmp r0, #0xE0
	blt _0800EFFC
	cmp r0, #0xE8
	bgt _0800EFFC
	cmp r0, #0xE7
	blt _0800EFFC
	movs r4, #0x03
	ldrb r5, [r3, #0x1E]
	b _0800F05C
	.global _0800EFEC
_0800EFEC:
	movs r1, #0x00
	movs r0, #0xE1
	strb r0, [r3, #0x18]
	str r1, [r3, #0x04]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	str r0, [r3, #0x00]
	b _0800F04E
	.global _0800EFFC
_0800EFFC:
	movs r4, #0x03
	ldrb r5, [r3, #0x1E]
	movs r6, #0x01
	ldr r1, _0800F058 @ =0x04000126
	.global _0800F004
_0800F004:
	ldrh r0, [r1, #0x00]
	adds r2, r0, #0x0
	adds r0, r5, #0x0
	asrs r0, r4
	ands r0, r6
	cmp r0, #0x00
	beq _0800F018
	ldr r0, [r3, #0x04]
	cmp r2, r0
	bne _0800EFEC
	.global _0800F018
_0800F018:
	subs r1, #0x02
	subs r4, #0x01
	cmp r4, #0x00
	bne _0800F004
	ldrb r0, [r3, #0x18]
	adds r0, #0x01
	strb r0, [r3, #0x18]
	ldr r1, [r3, #0x00]
	ldrh r0, [r3, #0x00]
	str r0, [r3, #0x04]
	cmp r1, #0x00
	bne _0800F046
	ldr r0, [r3, #0x28]
	adds r1, r0, #0x0
	adds r1, #0xAC
	adds r0, #0xAD
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x08
	ldrb r1, [r1, #0x00]
	orrs r0, r1
	str r0, [r3, #0x04]
	lsls r0, r0, #0x05
	str r0, [r3, #0x00]
	.global _0800F046
_0800F046:
	ldr r0, [r3, #0x00]
	lsrs r0, r0, #0x05
	str r0, [r3, #0x00]
	.global _0800F04C
_0800F04C:
	ldrh r1, [r3, #0x00]
	.global _0800F04E
_0800F04E:
	adds r0, r3, #0x0
	bl sub_0800EE8C
	b _0800F0B4
	.byte 0x00, 0x00
	.global _0800F058
_0800F058: .4byte 0x04000126
	.global _0800F05C
_0800F05C:
	lsls r0, r4, #0x01
	ldr r1, _0800F0A4 @ =0x04000120
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	adds r2, r0, #0x0
	adds r0, r5, #0x0
	asrs r0, r4
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0800F078
	ldr r0, [r3, #0x04]
	cmp r2, r0
	bne _0800F0A8
	.global _0800F078
_0800F078:
	subs r4, #0x01
	cmp r4, #0x00
	bne _0800F05C
	ldrb r0, [r3, #0x18]
	adds r0, #0x01
	strb r0, [r3, #0x18]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xE9
	beq _0800F0B2
	ldr r0, [r3, #0x28]
	adds r1, r0, #0x0
	adds r1, #0xAE
	adds r0, #0xAF
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x08
	ldrb r1, [r1, #0x00]
	orrs r0, r1
	str r0, [r3, #0x00]
	str r0, [r3, #0x04]
	b _0800F04C
	.byte 0x00, 0x00
	.global _0800F0A4
_0800F0A4: .4byte 0x04000120
	.global _0800F0A8
_0800F0A8:
	adds r0, r3, #0x0
	bl sub_0800EA64
	movs r0, #0x71
	b _0800F0B4
	.global _0800F0B2
_0800F0B2:
	movs r0, #0x00
	.global _0800F0B4
_0800F0B4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0800F0BC
sub_0800F0BC:
	mov r2, pc
	lsrs r2, r2, #0x18
	movs r1, #0x0C
	cmp r2, #0x02
	beq _0800F0CE
	movs r1, #0x0D
	cmp r2, #0x08
	beq _0800F0CE
	movs r1, #0x04
	.global _0800F0CE
_0800F0CE:
	subs r0, r0, r1
	bgt _0800F0CE
	bx lr
