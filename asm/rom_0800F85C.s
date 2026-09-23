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
	thumb_func_start sub_0800F85C
sub_0800F85C:
	ldr r0, _0800F884 @ =0x04000128
	ldrh r1, [r0, #0x00]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0x00
	bne _0800F89C
	ldr r1, _0800F888 @ =0x0202EF40
	ldr r0, _0800F88C @ =0x04000120
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	ldr r0, _0800F890 @ =0x04000122
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x08]
	ldr r0, _0800F894 @ =0x04000124
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x10]
	ldr r0, _0800F898 @ =0x04000126
	ldrh r0, [r0, #0x00]
	b _0800F8A6
	.byte 0x00, 0x00
_0800F884: .4byte 0x04000128
_0800F888: .4byte 0x0202EF40
_0800F88C: .4byte 0x04000120
_0800F890: .4byte 0x04000122
_0800F894: .4byte 0x04000124
_0800F898: .4byte 0x04000126
_0800F89C:
	ldr r1, _0800F8C0 @ =0x0202EF40
	movs r0, #0x00
	strh r0, [r1, #0x00]
	strh r0, [r1, #0x08]
	strh r0, [r1, #0x10]
_0800F8A6:
	strh r0, [r1, #0x18]
	ldr r2, _0800F8C4 @ =0x04000208
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r1, _0800F8C8 @ =0x03007FF8
	movs r0, #0x80
	ldrh r3, [r1, #0x00]
	orrs r0, r3
	strh r0, [r1, #0x00]
	movs r0, #0x01
	strh r0, [r2, #0x00]
	bx lr
	.byte 0x00, 0x00
_0800F8C0: .4byte 0x0202EF40
_0800F8C4: .4byte 0x04000208
_0800F8C8: .4byte 0x03007FF8
