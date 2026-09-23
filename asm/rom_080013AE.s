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
	thumb_func_start sub_080013B0
sub_080013B0:
	push {r4, r5, r6, r7, lr}
	ldrb r5, [r0, #0x08]
	ldr r4, [r0, #0x2C]
	cmp r5, #0x00
	ble _080013F2
	movs r7, #0x80
_080013BC:
	ldrb r1, [r4, #0x00]
	adds r0, r7, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _080013EA
	movs r6, #0x40
	adds r0, r6, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _080013EA
	adds r0, r4, #0x0
	bl sub_08001534
	strb r7, [r4, #0x00]
	movs r0, #0x02
	strb r0, [r4, #0x0F]
	strb r6, [r4, #0x13]
	movs r0, #0x16
	strb r0, [r4, #0x19]
	adds r1, r4, #0x0
	adds r1, #0x24
	movs r0, #0x01
	strb r0, [r1, #0x00]
_080013EA:
	subs r5, #0x01
	adds r4, #0x50
	cmp r5, #0x00
	bgt _080013BC
_080013F2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
