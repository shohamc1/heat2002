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
	.thumb
	.incbin "build/assets/unknown/data_08310828.bin"
	.incbin "build/assets/unknown/data_0831082C.bin"
	.incbin "build/assets/unknown/data_08310830.bin"
	.incbin "build/assets/unknown/data_08310834.bin"
	.incbin "build/assets/unknown/data_08310C30.bin"
	.incbin "build/assets/unknown/data_08310C70.bin"
