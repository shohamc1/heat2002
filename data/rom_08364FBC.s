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
	.global gTrack0Cues
gTrack0Cues:
	cSym gTrack0Cues
	.incbin "build/assets/unknown/data_08364FBC.bin"
	.global gTrack2Cues
gTrack2Cues:
	cSym gTrack2Cues
	.incbin "build/assets/unknown/data_0836500C.bin"
	.global gTrack4Cues
gTrack4Cues:
	cSym gTrack4Cues
	.incbin "build/assets/unknown/data_0836509C.bin"
	.global gTrack5Cues
gTrack5Cues:
	cSym gTrack5Cues
	.incbin "build/assets/unknown/data_08365114.bin"
	.global gTrack11Cues
gTrack11Cues:
	cSym gTrack11Cues
	.incbin "build/assets/unknown/data_08365174.bin"
	.global gTrack9Cues
gTrack9Cues:
	cSym gTrack9Cues
	.incbin "build/assets/unknown/data_083651C4.bin"
