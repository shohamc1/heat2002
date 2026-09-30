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
	.incbin "build/assets/unknown/data_083639A8.bin"
	.global gUnk_0202AF44
gUnk_0202AF44:
	.incbin "build/assets/unknown/data_083639C4.bin"
	.global gUnk_0202B078
gUnk_0202B078:
	.incbin "build/assets/unknown/data_08363AF8.bin"
	.global gUnk_0202B089
gUnk_0202B089:
	.incbin "build/assets/unknown/data_08363B09.bin"
	.global gUnk_0202B370
gUnk_0202B370:
	.incbin "build/assets/unknown/data_08363DF0.bin"





