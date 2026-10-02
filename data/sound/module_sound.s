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
	.include "asm/macros/music_voice.inc"
#if PLATFORM_GBA
	.thumb
#endif
	@ 0x083453C0-0x083454F4 (EWRAM 0x0200C940-0x0200CA74): the high
	@ module's one voice group, which both its songs play through, then
	@ the same tail voicegroup_0801D89C carries (zero entries and runs of
	@ 0 and 1, not voices) and the module's copy of the eight CGB waves
	@ (0x08345474, a "copy" asset: the same files data/sound/
	@ programmable_wave_samples.s incbins). Voice 0's wave is the one at
	@ cgb wave 6.
	.global voicegroup_083453C0
#if !PLATFORM_GBA
	@ Hosted: as voicegroup_0801D29C in voicegroups.s -- pointer-width
	@ alignment for the 24-byte record array.
	mAlignPtr
#endif
voicegroup_083453C0:
	voice_programmable_wave_alt 60, 0, gUnk_083454D4, 0, 0, 13, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 0, 15, 0
	@ The last two entries hold zeros, not voices.
	.fill 24, 1, 0
	@ The tail runs of voicegroup_0801D89C, bytes 0x18-0x90 of its fill
	@ block: 12 zeros then the same 36/36/36 of 0 and 1.
	.fill 12, 1, 0
	.fill 36, 1, 1
	.fill 36, 1, 0
	.fill 36, 1, 1
	.incbin "build/assets/sound/waves/wave_0801DA10.bin"
	.incbin "build/assets/sound/waves/wave_0801DA20.bin"
	.incbin "build/assets/sound/waves/wave_0801DA30.bin"
	.incbin "build/assets/sound/waves/wave_0801DA40.bin"
	.incbin "build/assets/sound/waves/wave_0801DA50.bin"
	.incbin "build/assets/sound/waves/wave_0801DA60.bin"
	.global gUnk_083454D4
gUnk_083454D4:
	.incbin "build/assets/sound/waves/wave_0801DA70.bin"
	.incbin "build/assets/sound/waves/wave_0801DA80.bin"
