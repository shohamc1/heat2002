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
	thumb_func_start sub_0833E4A4
sub_0833E4A4:
	push {r4, r5, r6, lr}
	ldr r5, _0833E518 @ =0x0203B700
	ldr r0, _0833E51C @ =0x0203B6CC
	ldr r4, [r0, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08344C50
	strb r0, [r5, #0x01]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08344BB8
	strb r0, [r5, #0x00]
	ldr r4, _0833E520 @ =0x020251B8
	ldr r0, [r4, #0x00]
	adds r0, #0x82
	ldrb r1, [r5, #0x00]
	bl sub_0833E36C
	ldr r0, [r4, #0x00]
	adds r0, #0x86
	ldrb r1, [r5, #0x01]
	bl sub_0833E36C
	ldr r0, _0833E524 @ =0x0203B84C
	ldr r6, [r0, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl sub_08344BB8
	movs r1, #0x0A
	bl sub_08344C50
	strb r0, [r5, #0x01]
	adds r0, r6, #0x0
	movs r1, #0x64
	bl sub_08344BB8
	strb r0, [r5, #0x00]
	ldr r0, [r4, #0x00]
	adds r0, #0xCA
	movs r1, #0x0A
	bl sub_0833E3C8
	ldr r0, [r4, #0x00]
	adds r0, #0xCC
	ldrb r1, [r5, #0x00]
	bl sub_0833E3C8
	ldr r0, [r4, #0x00]
	adds r0, #0xCE
	ldrb r1, [r5, #0x01]
	bl sub_0833E3C8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0833E518: .4byte 0x0203B700
_0833E51C: .4byte 0x0203B6CC
_0833E520: .4byte 0x020251B8
_0833E524: .4byte 0x0203B84C
