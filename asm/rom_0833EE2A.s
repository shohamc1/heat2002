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
	thumb_func_start sub_0833EE2C
sub_0833EE2C:
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	lsls r3, r3, #0x18
	ldr r0, _0833EE7C @ =0x020251B8
	ldr r4, [r0, #0x00]
	lsls r2, r2, #0x05
	adds r2, r2, r1
	lsls r2, r2, #0x01
	adds r4, r4, r2
	movs r2, #0xE0
	lsls r2, r2, #0x08
	cmp r3, #0x00
	beq _0833EE4A
	movs r2, #0xF0
	lsls r2, r2, #0x08
_0833EE4A:
	ldrb r0, [r5, #0x00]
	adds r5, #0x01
	cmp r0, #0x00
	beq _0833EE76
	ldr r6, _0833EE80 @ =0x0201F590
	ldr r3, _0833EE84 @ =0x0201F9D0
_0833EE56:
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r3
	adds r0, r2, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrb r0, [r5, #0x00]
	adds r5, #0x01
	cmp r0, #0x00
	bne _0833EE56
_0833EE76:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0833EE7C: .4byte 0x020251B8
_0833EE80: .4byte 0x0201F590
_0833EE84: .4byte 0x0201F9D0
