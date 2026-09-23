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
	thumb_func_start sub_08010764
sub_08010764:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08010768
sub_08010768:
	push {r4, lr}
	negs r1, r0
	adds r0, r1, #0x0
	movs r1, #0x06
	bl sub_080172C8
	adds r1, r0, #0x0
	cmp r1, #0x00
	bge _0801077C
	adds r1, #0x06
_0801077C:
	ldr r0, _0801079C @ =0x0202EED0
	strb r1, [r0, #0x00]
	ldr r4, _080107A0 @ =0x0202EDF0
	adds r0, r4, #0x0
	bl sub_08003DB4
	movs r1, #0xA0
	lsls r1, r1, #0x13
	adds r0, r4, #0x0
	movs r2, #0x40
	bl sub_08016E10
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801079C: .4byte 0x0202EED0
_080107A0: .4byte 0x0202EDF0
	thumb_func_start sub_080107A4
sub_080107A4:
	push {lr}
	add sp, #-0x004
	ldr r2, _080107D4 @ =0x0202EDE4
	ldr r0, [r2, #0x00]
	adds r0, #0x01
	movs r1, #0x1F
	ands r0, r1
	str r0, [r2, #0x00]
	lsls r0, r0, #0x05
	movs r2, #0xD0
	lsls r2, r2, #0x07
	adds r1, r2, #0x0
	orrs r0, r1
	mov r1, sp
	strh r0, [r1, #0x00]
	ldr r1, _080107D8 @ =0x0500013C
	mov r0, sp
	movs r2, #0x01
	bl sub_08016E10
	add sp, #0x004
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080107D4: .4byte 0x0202EDE4
_080107D8: .4byte 0x0500013C
	thumb_func_start sub_080107DC
sub_080107DC:
	bx lr
	.byte 0x00, 0x00
