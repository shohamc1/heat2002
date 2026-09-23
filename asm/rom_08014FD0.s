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
	thumb_func_start sub_08014FD0
sub_08014FD0:
	push {lr}
	ldr r0, _08014FE4 @ =0x0829F534
	movs r1, #0x30
	movs r2, #0x4C
	bl sub_08012384
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_08014FE4: .4byte 0x0829F534
	thumb_func_start sub_08014FE8
sub_08014FE8:
	push {lr}
	ldr r0, _08014FFC @ =0x0829F548
	movs r1, #0x6C
	movs r2, #0x4C
	bl sub_08012384
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_08014FFC: .4byte 0x0829F548
