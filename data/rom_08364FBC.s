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
	.global gUnk_08364FBC
gUnk_08364FBC:
	.incbin "build/assets/unknown/data_08364FBC.bin"
	.global gUnk_0836500C
gUnk_0836500C:
	.incbin "build/assets/unknown/data_0836500C.bin"
	.global gUnk_0836509C
gUnk_0836509C:
	.incbin "build/assets/unknown/data_0836509C.bin"
	.global gUnk_08365114
gUnk_08365114:
	.incbin "build/assets/unknown/data_08365114.bin"
	.global gUnk_08365174
gUnk_08365174:
	.incbin "build/assets/unknown/data_08365174.bin"
	.global gUnk_083651C4
gUnk_083651C4:
	.incbin "build/assets/unknown/data_083651C4.bin"
