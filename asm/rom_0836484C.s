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
	.incbin "build/assets/unknown/data_0836484C.bin"
	.incbin "build/assets/graphics/lz_083648A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/lz_083648F4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/lz_08364940.bin"
	.incbin "build/assets/unknown/data_08364984.bin"
