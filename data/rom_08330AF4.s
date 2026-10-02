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
	.global gUnk_08330AF4
gUnk_08330AF4:
	cSym gUnk_08330AF4
	.incbin "build/assets/graphics/rl_08330AF4.bin"
	.align 2, 0
	.global gUnk_08330B0C
gUnk_08330B0C:
	cSym gUnk_08330B0C
	.incbin "build/assets/graphics/rl_08330B0C.bin"
	.align 2, 0
	.global gUnk_08330B24
gUnk_08330B24:
	cSym gUnk_08330B24
	.incbin "build/assets/graphics/rl_08330B24.bin"
	.align 2, 0
	.global gUnk_08330B40
gUnk_08330B40:
	cSym gUnk_08330B40
	.incbin "build/assets/graphics/rl_08330B40.bin"
	.align 2, 0
	.global gUnk_08330B5C
gUnk_08330B5C:
	cSym gUnk_08330B5C
	.incbin "build/assets/graphics/rl_08330B5C.bin"
	.global gUnk_08330B7C
gUnk_08330B7C:
	cSym gUnk_08330B7C
	.incbin "build/assets/graphics/rl_08330B7C.bin"
	.align 2, 0
	.global gUnk_08330BA4
gUnk_08330BA4:
	cSym gUnk_08330BA4
	.incbin "build/assets/graphics/rl_08330BA4.bin"
	.align 2, 0
	.global gUnk_08330BCC
gUnk_08330BCC:
	cSym gUnk_08330BCC
	.incbin "build/assets/graphics/rl_08330BCC.bin"
	.align 2, 0
	.global gUnk_08330BF4
gUnk_08330BF4:
	cSym gUnk_08330BF4
	.incbin "build/assets/graphics/rl_08330BF4.bin"
	.align 2, 0
	.global gUnk_08330C1C
gUnk_08330C1C:
	cSym gUnk_08330C1C
	.incbin "build/assets/graphics/rl_08330C1C.bin"
	.global gUnk_08330C40
gUnk_08330C40:
	cSym gUnk_08330C40
	.incbin "build/assets/graphics/rl_08330C40.bin"
	.align 2, 0
	.global gUnk_08330C68
gUnk_08330C68:
	cSym gUnk_08330C68
	.incbin "build/assets/graphics/rl_08330C68.bin"
	.align 2, 0
	.global gUnk_08330C90
gUnk_08330C90:
	cSym gUnk_08330C90
	.incbin "build/assets/graphics/rl_08330C90.bin"
	.align 2, 0
	.global gUnk_08330CB8
gUnk_08330CB8:
	cSym gUnk_08330CB8
	.incbin "build/assets/graphics/rl_08330CB8.bin"
	.align 2, 0
	.global gUnk_08330CDC
gUnk_08330CDC:
	cSym gUnk_08330CDC
	.incbin "build/assets/graphics/rl_08330CDC.bin"
	.align 2, 0
	.global gUnk_08330CFC
gUnk_08330CFC:
	cSym gUnk_08330CFC
	.incbin "build/assets/graphics/rl_08330CFC.bin"
