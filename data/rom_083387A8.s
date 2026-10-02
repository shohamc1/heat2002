@ Generated with Luvdis v0.9.0
@ Both builds preprocess this file (preproc inlines the .include files,
@ cpp resolves the switch below). The GBA keeps the exact luvdis layout;
@ the hosted build switches to a writable data section, because its mPtr
@ pointer fields carry relocations the host linker must be able to write.
	.include "asm/macros/portable.inc"
#if PLATFORM_GBA
.syntax unified
.text
#else
mSectionData
#endif
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
#if PLATFORM_GBA
	.thumb
#endif
	.global gLowFuelWarningGfx
gLowFuelWarningGfx:
	cSym gLowFuelWarningGfx
	.incbin "build/assets/graphics/rl_083387A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_083387F0.pal.bin"
	.global gUnk_08338810
gUnk_08338810:
	cSym gUnk_08338810
	.incbin "build/assets/graphics/rl_08338810.bin"
	.align 2, 0
	.global gUnk_08338980
gUnk_08338980:
	cSym gUnk_08338980
	.incbin "build/assets/graphics/rl_08338980.bin"
	.align 2, 0
	.global gUnk_08338AFC
gUnk_08338AFC:
	cSym gUnk_08338AFC
	.incbin "build/assets/graphics/rl_08338AFC.bin"
	.align 2, 0
	.global gUnk_08338C6C
gUnk_08338C6C:
	cSym gUnk_08338C6C
	.incbin "build/assets/graphics/rl_08338C6C.bin"
	.align 2, 0
	.global gUnk_08338DF0
gUnk_08338DF0:
	cSym gUnk_08338DF0
	.incbin "build/assets/graphics/rl_08338DF0.bin"
	.align 2, 0
	.global gUnk_08338F5C
gUnk_08338F5C:
	cSym gUnk_08338F5C
	.incbin "build/assets/graphics/rl_08338F5C.bin"
	.align 2, 0
	.global gUnk_083390C8
gUnk_083390C8:
	cSym gUnk_083390C8
	.incbin "build/assets/graphics/rl_083390C8.bin"
	.align 2, 0
	.global gUnk_0833923C
gUnk_0833923C:
	cSym gUnk_0833923C
	.incbin "build/assets/graphics/rl_0833923C.bin"
	.align 2, 0
