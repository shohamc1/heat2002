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
	.global gUnk_083311A8
gUnk_083311A8:
	cSym gUnk_083311A8
	.incbin "build/assets/graphics/palettes/pal_083311A8.pal.bin"
	.global gUnk_083311C8
gUnk_083311C8:
	cSym gUnk_083311C8
	.incbin "build/assets/graphics/palettes/pal_083311C8.pal.bin"
	.global gUnk_083311E8
gUnk_083311E8:
	cSym gUnk_083311E8
	.incbin "build/assets/graphics/rl_083311E8.bin"
	.align 2, 0
	.global gUnk_08331224
gUnk_08331224:
	cSym gUnk_08331224
	.incbin "build/assets/graphics/rl_08331224.bin"
	.align 2, 0
	.global gUnk_08331260
gUnk_08331260:
	cSym gUnk_08331260
	.incbin "build/assets/graphics/rl_08331260.bin"
	.align 2, 0
	.global gUnk_083312A0
gUnk_083312A0:
	cSym gUnk_083312A0
	.incbin "build/assets/graphics/rl_083312A0.bin"
	.align 2, 0
	.global gUnk_083312E0
gUnk_083312E0:
	cSym gUnk_083312E0
	.incbin "build/assets/graphics/rl_083312E0.bin"
	.align 2, 0
	.global gUnk_08331320
gUnk_08331320:
	cSym gUnk_08331320
	.incbin "build/assets/graphics/rl_08331320.bin"
	.align 2, 0
