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
	thumb_func_start sub_0800E70C
sub_0800E70C:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800E710
sub_0800E710:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800E714
sub_0800E714:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800E718
sub_0800E718:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800E71C
sub_0800E71C:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800E720
sub_0800E720:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800E724
sub_0800E724:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800E728
sub_0800E728:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0800E72C
sub_0800E72C:
	bx lr
	.byte 0x00, 0x00
