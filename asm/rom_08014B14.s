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
	thumb_func_start sub_08014B14
sub_08014B14:
	push {r4, r5, r6, lr}
	ldr r1, _08014B84 @ =0x0202EDB4
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r0, _08014B88 @ =0x0202EDC0
	movs r1, #0x00
	str r1, [r0, #0x00]
	ldr r4, _08014B8C @ =0x0202F02C
	ldr r3, _08014B90 @ =0x0202EEE0
	ldr r2, _08014B94 @ =0x0202EEF0
	ldr r0, _08014B98 @ =0x0202EDE0
	strb r1, [r0, #0x00]
	strb r1, [r2, #0x00]
	strb r1, [r3, #0x00]
	strb r1, [r4, #0x00]
	ldr r5, _08014B9C @ =0x0202CDB0
	movs r6, #0x64
	ldrb r1, [r5, #0x00]
	adds r0, r1, #0x0
	muls r0, r6
	ldrb r1, [r5, #0x01]
	bl sub_08017230
	adds r4, r0, #0x0
	strb r4, [r5, #0x02]
	ldrb r2, [r5, #0x03]
	adds r0, r2, #0x0
	muls r0, r6
	ldrb r1, [r5, #0x04]
	bl sub_08017230
	strb r0, [r5, #0x05]
	ldrb r1, [r5, #0x06]
	adds r0, r1, #0x0
	muls r0, r6
	ldrb r1, [r5, #0x07]
	bl sub_08017230
	strb r0, [r5, #0x08]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	cmp r4, #0x64
	bls _08014B6C
	strb r6, [r5, #0x02]
	.global _08014B6C
_08014B6C:
	ldrb r2, [r5, #0x05]
	ldrb r1, [r5, #0x02]
	adds r0, r2, r1
	ldrb r2, [r5, #0x08]
	adds r0, r2, r0
	ldrb r1, [r5, #0x09]
	adds r0, r1, r0
	asrs r0, r0, #0x02
	str r0, [r5, #0x0C]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _08014B84
_08014B84: .4byte 0x0202EDB4
	.global _08014B88
_08014B88: .4byte 0x0202EDC0
	.global _08014B8C
_08014B8C: .4byte 0x0202F02C
	.global _08014B90
_08014B90: .4byte 0x0202EEE0
	.global _08014B94
_08014B94: .4byte 0x0202EEF0
	.global _08014B98
_08014B98: .4byte 0x0202EDE0
	.global _08014B9C
_08014B9C: .4byte 0x0202CDB0
