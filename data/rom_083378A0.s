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
	.global gUnk_083378A0
gUnk_083378A0:
	.incbin "build/assets/graphics/rl_083378A0.bin"
	.global gUnk_08337920
gUnk_08337920:
	.incbin "build/assets/graphics/rl_08337920.bin"
	.global gUnk_083379A0
gUnk_083379A0:
	.incbin "build/assets/graphics/rl_083379A0.bin"
	.global gUnk_08337A20
gUnk_08337A20:
	.incbin "build/assets/graphics/rl_08337A20.bin"
	.global gUnk_08337AA0
gUnk_08337AA0:
	.incbin "build/assets/graphics/rl_08337AA0.bin"
	.global gUnk_08337B20
gUnk_08337B20:
	.incbin "build/assets/graphics/rl_08337B20.bin"
	.global gUnk_08337BA0
gUnk_08337BA0:
	.incbin "build/assets/graphics/rl_08337BA0.bin"
