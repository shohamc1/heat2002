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
.include "asm/macros/portable.inc"
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
	@ 0x0801DA10-0x0801DA90: the eight Game Boy wave channel patterns,
	@ 16 bytes (32 4-bit samples) each. No main-program voice uses one,
	@ but the high module's voice group does: data/sound/module_sound.s
	@ .incbins the same files for its own copy at 0x08345474.
wave_0801DA10:
	.incbin "build/assets/sound/waves/wave_0801DA10.bin"
wave_0801DA20:
	.incbin "build/assets/sound/waves/wave_0801DA20.bin"
wave_0801DA30:
	.incbin "build/assets/sound/waves/wave_0801DA30.bin"
wave_0801DA40:
	.incbin "build/assets/sound/waves/wave_0801DA40.bin"
wave_0801DA50:
	.incbin "build/assets/sound/waves/wave_0801DA50.bin"
wave_0801DA60:
	.incbin "build/assets/sound/waves/wave_0801DA60.bin"
wave_0801DA70:
	.incbin "build/assets/sound/waves/wave_0801DA70.bin"
wave_0801DA80:
	.incbin "build/assets/sound/waves/wave_0801DA80.bin"
