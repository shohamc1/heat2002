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
	.incbin "build/assets/unknown/data_08365348.bin"
	.incbin "build/assets/unknown/data_08365618.bin"
	.incbin "build/assets/unknown/data_08365798.bin"
	.incbin "build/assets/unknown/data_08365A38.bin"
	.incbin "build/assets/unknown/data_08365CC0.bin"
	.incbin "build/assets/unknown/data_08365D38.bin"
	.incbin "build/assets/unknown/data_08366140.bin"
	.incbin "build/assets/unknown/data_08366470.bin"
	.incbin "build/assets/unknown/data_08366620.bin"
	.incbin "build/assets/unknown/data_083668A8.bin"
	.incbin "build/assets/unknown/data_08366A58.bin"
	.incbin "build/assets/unknown/data_08366DE8.bin"
	.incbin "build/assets/unknown/data_08366F38.bin"
