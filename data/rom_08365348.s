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
	.global gUnk_08365348
gUnk_08365348:
	.incbin "build/assets/unknown/data_08365348.bin"
	.global gUnk_08365618
gUnk_08365618:
	.incbin "build/assets/unknown/data_08365618.bin"
	.global gUnk_08365798
gUnk_08365798:
	.incbin "build/assets/unknown/data_08365798.bin"
	.global gUnk_08365A38
gUnk_08365A38:
	.incbin "build/assets/unknown/data_08365A38.bin"
	.global gUnk_08365CC0
gUnk_08365CC0:
	.incbin "build/assets/unknown/data_08365CC0.bin"
	.incbin "build/assets/unknown/data_08365D38.bin"
	.global gUnk_08366140
gUnk_08366140:
	.incbin "build/assets/unknown/data_08366140.bin"
	.global gUnk_08366470
gUnk_08366470:
	.incbin "build/assets/unknown/data_08366470.bin"
	.global gUnk_08366620
gUnk_08366620:
	.incbin "build/assets/unknown/data_08366620.bin"
	.global gUnk_083668A8
gUnk_083668A8:
	.incbin "build/assets/unknown/data_083668A8.bin"
	.global gUnk_08366A58
gUnk_08366A58:
	.incbin "build/assets/unknown/data_08366A58.bin"
	.global gUnk_08366DE8
gUnk_08366DE8:
	.incbin "build/assets/unknown/data_08366DE8.bin"
	.global gUnk_08366F38
gUnk_08366F38:
	.incbin "build/assets/unknown/data_08366F38.bin"
