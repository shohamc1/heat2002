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
	.incbin "build/assets/graphics/rl_08337C40.bin"
	.incbin "build/assets/graphics/rl_08337CC0.bin"
	.incbin "build/assets/graphics/rl_08337D40.bin"
	.incbin "build/assets/graphics/rl_08337DC0.bin"
	.incbin "build/assets/graphics/rl_08337E40.bin"
	.incbin "build/assets/graphics/rl_08337EC0.bin"
	.incbin "build/assets/graphics/rl_08337F40.bin"
	.incbin "build/assets/unknown/data_08337FC0.bin"
	.incbin "build/assets/graphics/rl_08337FE0.bin"
	.incbin "build/assets/graphics/rl_08338060.bin"
	.incbin "build/assets/graphics/rl_083380E0.bin"
	.incbin "build/assets/graphics/rl_08338160.bin"
	.incbin "build/assets/graphics/rl_083381E0.bin"
	.incbin "build/assets/graphics/rl_08338260.bin"
	.incbin "build/assets/graphics/rl_083382E0.bin"
	.incbin "build/assets/unknown/data_08338360.bin"
	.incbin "build/assets/graphics/rl_08338380.bin"
	.incbin "build/assets/graphics/rl_08338400.bin"
	.incbin "build/assets/graphics/rl_08338480.bin"
	.incbin "build/assets/graphics/rl_08338500.bin"
	.incbin "build/assets/graphics/rl_08338580.bin"
	.incbin "build/assets/graphics/rl_08338600.bin"
	.incbin "build/assets/graphics/rl_08338680.bin"
	.incbin "build/assets/unknown/data_08338700.bin"
	.incbin "build/assets/graphics/rl_08338720.bin"
