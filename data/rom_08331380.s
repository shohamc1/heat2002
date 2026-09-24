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
	.incbin "build/assets/graphics/rl_08331380.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083313A0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083313C8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083313F8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331438.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331480.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083314CC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331520.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331574.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083315D0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331638.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083316A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0833171C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331798.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0833181C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083318A0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331924.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083319A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331A28.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331AA8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331B20.bin"
	.incbin "build/assets/graphics/rl_08331B94.bin"
	.incbin "build/assets/graphics/rl_08331C08.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331C7C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331CEC.bin"
	.incbin "build/assets/graphics/rl_08331D54.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331DBC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331E1C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331E74.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331EC4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331F0C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331F4C.bin"
	.align 2, 0
