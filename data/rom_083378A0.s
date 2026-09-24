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
	.incbin "build/assets/graphics/rl_083378A0.bin"
	.incbin "build/assets/graphics/rl_08337920.bin"
	.incbin "build/assets/graphics/rl_083379A0.bin"
	.incbin "build/assets/graphics/rl_08337A20.bin"
	.incbin "build/assets/graphics/rl_08337AA0.bin"
	.incbin "build/assets/graphics/rl_08337B20.bin"
	.incbin "build/assets/graphics/rl_08337BA0.bin"
