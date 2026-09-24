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
	thumb_func_start sub_080059A8
sub_080059A8:
	push {r4, r5, r6, lr}
	ldr r5, _08005A1C @ =0x0202525C
	ldr r0, _08005A20 @ =0x0202521C
	ldr r4, [r0, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_080172C8
	strb r0, [r5, #0x01]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08017230
	strb r0, [r5, #0x00]
	ldr r4, _08005A24 @ =0x08364B08
	ldr r0, [r4, #0x00]
	adds r0, #0x82
	ldrb r1, [r5, #0x00]
	bl sub_08005870
	ldr r0, [r4, #0x00]
	adds r0, #0x86
	ldrb r1, [r5, #0x01]
	bl sub_08005870
	ldr r0, _08005A28 @ =0x020253C0
	ldr r6, [r0, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl sub_08017230
	movs r1, #0x0A
	bl sub_080172C8
	strb r0, [r5, #0x01]
	adds r0, r6, #0x0
	movs r1, #0x64
	bl sub_08017230
	strb r0, [r5, #0x00]
	ldr r0, [r4, #0x00]
	adds r0, #0xCA
	movs r1, #0x0A
	bl sub_080058CC
	ldr r0, [r4, #0x00]
	adds r0, #0xCC
	ldrb r1, [r5, #0x00]
	bl sub_080058CC
	ldr r0, [r4, #0x00]
	adds r0, #0xCE
	ldrb r1, [r5, #0x01]
	bl sub_080058CC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08005A1C: .4byte 0x0202525C
_08005A20: .4byte 0x0202521C
_08005A24: .4byte 0x08364B08
_08005A28: .4byte 0x020253C0
