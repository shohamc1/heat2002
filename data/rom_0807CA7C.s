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
	.global gUnk_0807CA7C
gUnk_0807CA7C:
	.incbin "build/assets/graphics/lz_0807CA7C.bin"
	.align 2, 0
	.global gUnk_0807CAC8
gUnk_0807CAC8:
	.incbin "build/assets/graphics/lz_0807CAC8.bin"
	.align 2, 0
	.global gUnk_0807CB14
gUnk_0807CB14:
	.incbin "build/assets/graphics/lz_0807CB14.bin"
