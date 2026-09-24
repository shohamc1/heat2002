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
	.global gUnk_083FF724
gUnk_083FF724:
	.incbin "build/assets/unknown/data_083FF724.bin"
	.global gUnk_083FF740
gUnk_083FF740:
	.incbin "build/assets/unknown/data_083FF740.bin"
	.global gUnk_083FF75C
gUnk_083FF75C:
	.incbin "build/assets/unknown/data_083FF75C.bin"
	.global gUnk_083FF778
gUnk_083FF778:
	.incbin "build/assets/unknown/data_083FF778.bin"
