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
	thumb_func_start sub_08016ED8
sub_08016ED8:
	push {r4, r5, lr}
	ldr r2, _08016F20 @ =0x020004A0
	ldr r3, _08016F24 @ =0x04000208
	ldrh r1, [r3, #0x00]
	strh r1, [r2, #0x00]
	movs r5, #0x00
	strh r5, [r3, #0x00]
	ldr r4, _08016F28 @ =0x04000200
	ldr r1, _08016F2C @ =0x02000494
	ldrb r1, [r1, #0x00]
	movs r2, #0x08
	lsls r2, r1
	ldrh r1, [r4, #0x00]
	orrs r1, r2
	strh r1, [r4, #0x00]
	movs r1, #0x01
	strh r1, [r3, #0x00]
	ldr r1, _08016F30 @ =0x02000498
	strb r5, [r1, #0x00]
	ldr r2, _08016F34 @ =0x02000496
	ldrh r1, [r0, #0x00]
	strh r1, [r2, #0x00]
	adds r0, #0x02
	ldr r3, _08016F38 @ =0x0200049C
	ldr r1, [r3, #0x00]
	ldrh r2, [r0, #0x00]
	strh r2, [r1, #0x00]
	adds r1, #0x02
	str r1, [r3, #0x00]
	ldrh r0, [r0, #0x02]
	strh r0, [r1, #0x00]
	subs r1, #0x02
	str r1, [r3, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08016F20
_08016F20: .4byte 0x020004A0
	.global _08016F24
_08016F24: .4byte 0x04000208
	.global _08016F28
_08016F28: .4byte 0x04000200
	.global _08016F2C
_08016F2C: .4byte 0x02000494
	.global _08016F30
_08016F30: .4byte 0x02000498
	.global _08016F34
_08016F34: .4byte 0x02000496
	.global _08016F38
_08016F38: .4byte 0x0200049C
