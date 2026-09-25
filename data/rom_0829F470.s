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
	.global gUnk_0829F470
gUnk_0829F470:
	.incbin "build/assets/unknown/data_0829F470.bin"
	.global gUnk_0829F484
gUnk_0829F484:
	.incbin "build/assets/unknown/data_0829F484.bin"
	.global gUnk_0829F490
gUnk_0829F490:
	.incbin "build/assets/unknown/data_0829F490.bin"
	.global gUnk_0829F4A0
gUnk_0829F4A0:
	.incbin "build/assets/unknown/data_0829F4A0.bin"
	.global gUnk_0829F4B4
gUnk_0829F4B4:
	.incbin "build/assets/unknown/data_0829F4B4.bin"
	.global gUnk_0829F4C4
gUnk_0829F4C4:
	.incbin "build/assets/unknown/data_0829F4C4.bin"
	.global gUnk_0829F4DC
gUnk_0829F4DC:
	.incbin "build/assets/unknown/data_0829F4DC.bin"
