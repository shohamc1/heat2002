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
	thumb_func_start sub_0800177C
sub_0800177C:
	push {r4, r5, r6, r7, lr}
	ldr r0, _080017C8 @ =0x03007FF0
	ldr r6, [r0, #0x00]
	ldr r1, [r6, #0x00]
	ldr r0, _080017CC @ =0x68736D53
	cmp r1, r0
	bne _080017C2
	adds r0, r1, #0x1
	str r0, [r6, #0x00]
	movs r5, #0x0C
	adds r4, r6, #0x0
	adds r4, #0x50
	movs r0, #0x00
_08001796:
	strb r0, [r4, #0x00]
	subs r5, #0x01
	adds r4, #0x40
	cmp r5, #0x00
	bgt _08001796
	ldr r4, [r6, #0x1C]
	cmp r4, #0x00
	beq _080017BE
	movs r5, #0x01
	movs r7, #0x00
_080017AA:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [r6, #0x2C]
	bl _call_via_r1
	strb r7, [r4, #0x00]
	adds r5, #0x01
	adds r4, #0x40
	cmp r5, #0x04
	ble _080017AA
_080017BE:
	ldr r0, _080017CC @ =0x68736D53
	str r0, [r6, #0x00]
_080017C2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080017C8: .4byte 0x03007FF0
_080017CC: .4byte 0x68736D53
