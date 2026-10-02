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
	.global gUnk_0807CA7C
gUnk_0807CA7C:
	cSym gUnk_0807CA7C
	.incbin "build/assets/graphics/lz_0807CA7C.bin"
	.align 2, 0
	.global gUnk_0807CAC8
gUnk_0807CAC8:
	cSym gUnk_0807CAC8
	.incbin "build/assets/graphics/lz_0807CAC8.bin"
	.align 2, 0
	.global gUnk_0807CB14
gUnk_0807CB14:
	cSym gUnk_0807CB14
	.incbin "build/assets/graphics/lz_0807CB14.bin"
