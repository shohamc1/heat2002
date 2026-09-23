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
	thumb_func_start sub_08000410
sub_08000410:
	push {lr}
	ldr r0, _08000428 @ =0x02000580
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800041E
	bl _call_via_r0
_0800041E:
	bl sub_08000444
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08000428: .4byte 0x02000580
	thumb_func_start sub_0800042C
sub_0800042C:
	bx lr
	.byte 0x00, 0x00
