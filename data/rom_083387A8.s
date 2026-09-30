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
	.global gLowFuelWarningGfx
gLowFuelWarningGfx:
	.incbin "build/assets/graphics/rl_083387A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_083387F0.pal.bin"
	.global gUnk_08338810
gUnk_08338810:
	.incbin "build/assets/graphics/rl_08338810.bin"
	.align 2, 0
	.global gUnk_08338980
gUnk_08338980:
	.incbin "build/assets/graphics/rl_08338980.bin"
	.align 2, 0
	.global gUnk_08338AFC
gUnk_08338AFC:
	.incbin "build/assets/graphics/rl_08338AFC.bin"
	.align 2, 0
	.global gUnk_08338C6C
gUnk_08338C6C:
	.incbin "build/assets/graphics/rl_08338C6C.bin"
	.align 2, 0
	.global gUnk_08338DF0
gUnk_08338DF0:
	.incbin "build/assets/graphics/rl_08338DF0.bin"
	.align 2, 0
	.global gUnk_08338F5C
gUnk_08338F5C:
	.incbin "build/assets/graphics/rl_08338F5C.bin"
	.align 2, 0
	.global gUnk_083390C8
gUnk_083390C8:
	.incbin "build/assets/graphics/rl_083390C8.bin"
	.align 2, 0
	.global gUnk_0833923C
gUnk_0833923C:
	.incbin "build/assets/graphics/rl_0833923C.bin"
	.align 2, 0
