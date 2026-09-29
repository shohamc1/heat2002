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
	.global gUnk_083311A8
gUnk_083311A8:
	.incbin "build/assets/graphics/palettes/pal_083311A8.pal.bin"
	.global gUnk_083311C8
gUnk_083311C8:
	.incbin "build/assets/graphics/palettes/pal_083311C8.pal.bin"
	.global gUnk_083311E8
gUnk_083311E8:
	.incbin "build/assets/graphics/rl_083311E8.bin"
	.align 2, 0
	.global gUnk_08331224
gUnk_08331224:
	.incbin "build/assets/graphics/rl_08331224.bin"
	.align 2, 0
	.global gUnk_08331260
gUnk_08331260:
	.incbin "build/assets/graphics/rl_08331260.bin"
	.align 2, 0
	.global gUnk_083312A0
gUnk_083312A0:
	.incbin "build/assets/graphics/rl_083312A0.bin"
	.align 2, 0
	.global gUnk_083312E0
gUnk_083312E0:
	.incbin "build/assets/graphics/rl_083312E0.bin"
	.align 2, 0
	.global gUnk_08331320
gUnk_08331320:
	.incbin "build/assets/graphics/rl_08331320.bin"
	.align 2, 0
