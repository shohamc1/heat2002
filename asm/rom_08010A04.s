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
	thumb_func_start sub_08010A04
sub_08010A04:
	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r7, r4, #0x0
	cmp r4, #0x01
	bne _08010A1A
	ldr r0, _08010A84 @ =0x0829F2A0
	bl sub_080109C0
_08010A1A:
	cmp r4, #0x02
	bne _08010A28
	ldr r0, _08010A88 @ =0x0829F294
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl sub_080109C0
_08010A28:
	cmp r4, #0x03
	bne _08010A36
	ldr r0, _08010A8C @ =0x0829F288
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl sub_080109C0
_08010A36:
	cmp r4, #0x04
	bne _08010A44
	ldr r0, _08010A90 @ =0x0829F27C
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl sub_080109C0
_08010A44:
	cmp r4, #0x05
	bne _08010A52
	ldr r0, _08010A94 @ =0x0829F270
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl sub_080109C0
_08010A52:
	cmp r4, #0x06
	bne _08010A60
	ldr r0, _08010A98 @ =0x0829F264
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl sub_080109C0
_08010A60:
	cmp r4, #0x07
	bne _08010A6E
	ldr r0, _08010A9C @ =0x0829F258
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl sub_080109C0
_08010A6E:
	cmp r7, #0x08
	bne _08010A7C
	ldr r0, _08010AA0 @ =0x0829F24C
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl sub_080109C0
_08010A7C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08010A84: .4byte 0x0829F2A0
_08010A88: .4byte 0x0829F294
_08010A8C: .4byte 0x0829F288
_08010A90: .4byte 0x0829F27C
_08010A94: .4byte 0x0829F270
_08010A98: .4byte 0x0829F264
_08010A9C: .4byte 0x0829F258
_08010AA0: .4byte 0x0829F24C
