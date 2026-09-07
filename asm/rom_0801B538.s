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
	thumb_func_start sub_0801B538
sub_0801B538:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	ldr r4, _0801B560 @ =0x0202F244
	movs r2, #0x00
	str r2, [r4, #0x00]
	bl sub_0801B410
	adds r1, r0, #0x0
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	bne _0801B55C
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0801B55C
	str r0, [r5, #0x00]
	.global _0801B55C
_0801B55C:
	adds r0, r1, #0x0
	pop {r4, r5, pc}
	.global _0801B560
_0801B560: .4byte 0x0202F244
	thumb_func_start sub_0801B564
sub_0801B564:
	mov r12, r3
	mov r3, r8
	push {r3}
	mov r3, r12
	movs r2, #0x18
	ldr r3, _0801B580 @ =0x00020022
	adds r0, r2, #0x0
	adds r1, r3, #0x0
	swi #171
	mov r8, r0
	pop {r3}
	mov r8, r3
	bx lr
	.byte 0x00, 0x00
	.global _0801B580
_0801B580: .4byte 0x00020022
