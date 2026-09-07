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
	thumb_func_start sub_08339A40
sub_08339A40:
	push {lr}
	bl sub_08339AF0
	ldr r0, _08339A8C @ =0x020375D0
	ldr r2, _08339A90 @ =0x0200106D
	str r2, [r0, #0x00]
	ldr r1, _08339A94 @ =0x040000D4
	ldr r0, _08339A98 @ =0x02000D44
	str r0, [r1, #0x00]
	ldr r3, _08339A9C @ =0x02037620
	str r3, [r1, #0x04]
	ldr r0, _08339AA0 @ =0x80000400
	str r0, [r1, #0x08]
	ldr r0, [r1, #0x08]
	ldr r0, _08339AA4 @ =0x03007FFC
	str r3, [r0, #0x00]
	ldr r1, _08339AA8 @ =0x04000204
	ldr r3, _08339AAC @ =0x00004014
	adds r0, r3, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _08339AB0 @ =0x020375E0
	ldr r1, _08339AB4 @ =0x02001051
	str r1, [r0, #0x04]
	str r2, [r0, #0x00]
	str r2, [r0, #0x08]
	str r2, [r0, #0x0C]
	str r2, [r0, #0x10]
	str r2, [r0, #0x14]
	str r2, [r0, #0x18]
	str r2, [r0, #0x1C]
	str r2, [r0, #0x20]
	str r2, [r0, #0x24]
	str r2, [r0, #0x28]
	str r2, [r0, #0x2C]
	str r2, [r0, #0x30]
	str r2, [r0, #0x34]
	pop {r0}
	bx r0
	.global _08339A8C
_08339A8C: .4byte 0x020375D0
	.global _08339A90
_08339A90: .4byte 0x0200106D
	.global _08339A94
_08339A94: .4byte 0x040000D4
	.global _08339A98
_08339A98: .4byte 0x02000D44
	.global _08339A9C
_08339A9C: .4byte 0x02037620
	.global _08339AA0
_08339AA0: .4byte 0x80000400
	.global _08339AA4
_08339AA4: .4byte 0x03007FFC
	.global _08339AA8
_08339AA8: .4byte 0x04000204
	.global _08339AAC
_08339AAC: .4byte 0x00004014
	.global _08339AB0
_08339AB0: .4byte 0x020375E0
	.global _08339AB4
_08339AB4: .4byte 0x02001051
