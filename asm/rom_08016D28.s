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
	thumb_func_start sub_08016D28
sub_08016D28:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	ldr r5, _08016DFC @ =0x0202A550
	ldr r1, _08016E00 @ =0x083FED18
	mov r8, r1
	ldr r7, _08016E04 @ =0x020020CC
	cmp r0, #0x00
	beq _08016D8C
	adds r4, r5, #0x0
	movs r6, #0x00
	.global _08016D42
_08016D42:
	adds r0, r4, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08016D80
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r3, r4, r2
	movs r0, #0x82
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, _08016E08 @ =0x0000EA60
	ldrh r1, [r1, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	movs r1, #0x83
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, r2, r0
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrh r0, [r0, #0x00]
	adds r2, r0, r2
	str r2, [r3, #0x00]
	.global _08016D80
_08016D80:
	adds r6, #0x01
	movs r2, #0xC8
	lsls r2, r2, #0x01
	adds r4, r4, r2
	cmp r6, #0x18
	bne _08016D42
	.global _08016D8C
_08016D8C:
	adds r0, r5, #0x0
	adds r0, #0x4C
	movs r1, #0x00
	ldsb r1, [r0, r1]
	ldrb r7, [r7, #0x00]
	lsls r0, r7, #0x02
	add r0, r8
	ldr r0, [r0, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	mov r8, r2
	movs r1, #0xB6
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r7, [r0, #0x00]
	adds r0, r7, #0x0
	mov r1, r8
	bl sub_08017230
	mov r9, r0
	adds r4, r5, #0x0
	movs r6, #0x00
	.global _08016DB8
_08016DB8:
	adds r5, r4, #0x0
	adds r5, #0x7D
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	bne _08016DE4
	ldr r0, [r4, #0x50]
	ldr r1, _08016E04 @ =0x020020CC
	ldrb r1, [r1, #0x00]
	bl sub_08016D08
	mov r2, r8
	subs r0, r2, r0
	mov r1, r9
	muls r1, r0
	adds r0, r1, #0x0
	adds r0, r0, r7
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r1, r4, r2
	str r0, [r1, #0x00]
	movs r0, #0x01
	strb r0, [r5, #0x00]
	.global _08016DE4
_08016DE4:
	adds r6, #0x01
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r4, r4, r0
	cmp r6, #0x18
	bne _08016DB8
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08016DFC
_08016DFC: .4byte 0x0202A550
	.global _08016E00
_08016E00: .4byte 0x083FED18
	.global _08016E04
_08016E04: .4byte 0x020020CC
	.global _08016E08
_08016E08: .4byte 0x0000EA60
