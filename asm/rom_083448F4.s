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
	thumb_func_start sub_083448F4
sub_083448F4:
	ldr r0, _0834491C @ =0x04000128
	ldrh r1, [r0, #0x00]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0x00
	bne _08344934
	ldr r1, _08344920 @ =0x0203E160
	ldr r0, _08344924 @ =0x04000120
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	ldr r0, _08344928 @ =0x04000122
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x08]
	ldr r0, _0834492C @ =0x04000124
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x10]
	ldr r0, _08344930 @ =0x04000126
	ldrh r0, [r0, #0x00]
	b _0834493E
	.byte 0x00, 0x00
_0834491C: .4byte 0x04000128
_08344920: .4byte 0x0203E160
_08344924: .4byte 0x04000120
_08344928: .4byte 0x04000122
_0834492C: .4byte 0x04000124
_08344930: .4byte 0x04000126
_08344934:
	ldr r1, _08344958 @ =0x0203E160
	movs r0, #0x00
	strh r0, [r1, #0x00]
	strh r0, [r1, #0x08]
	strh r0, [r1, #0x10]
_0834493E:
	strh r0, [r1, #0x18]
	ldr r2, _0834495C @ =0x04000208
	movs r0, #0x00
	strh r0, [r2, #0x00]
	ldr r1, _08344960 @ =0x03007FF8
	movs r0, #0x80
	ldrh r3, [r1, #0x00]
	orrs r0, r3
	strh r0, [r1, #0x00]
	movs r0, #0x01
	strh r0, [r2, #0x00]
	bx lr
	.byte 0x00, 0x00
_08344958: .4byte 0x0203E160
_0834495C: .4byte 0x04000208
_08344960: .4byte 0x03007FF8
	thumb_func_start sub_08344964
sub_08344964:
	bx lr
	.byte 0x00, 0x00
