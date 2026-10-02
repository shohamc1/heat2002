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
	@ 0x0801D29C-0x0801DA10: the two voice groups the songs play through
	@ (each song header names its group by label, and so does the
	@ "voicegroup" option in assets/sound.json). Both labels are global:
	@ the songs that data/sound/sounds.s includes reference them from
	@ another object.
	.global voicegroup_0801D29C
#if !PLATFORM_GBA
	@ Hosted: the group label is an array of 24-byte struct ToneData
	@ records (asm/macros/music_voice.inc), so it aligns to the pointer
	@ width; every record then keeps the 8-mod-24 tiling by itself.
	mAlignPtr
	@ Hosted stand-in for the ROM's rhythm group, which the last voice
	@ below points at 0x0801CF90 -- the jump-table template's words
	@ (every address is readable on the GBA, so the drum track's junk
	@ voices resolve to open-bus samples there; a host would fault).
	@ 128 empty records: every drum note lands on a silent voice.
hostedRhythmGroupDummy:
	.fill 128 * 24, 1, 0
	mAlignPtr
#endif
voicegroup_0801D29C:
	voice_directsound 60, 0, sample_080242E0, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08025900, 255, 0, 218, 0
	voice_directsound 60, 0, sample_080263D8, 255, 0, 255, 0
	voice_directsound 60, 0, sample_080299FC, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0802B6B8, 255, 0, 218, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 4, 0
	voice_directsound 60, 0, sample_08031B04, 255, 0, 244, 0
	voice_directsound 60, 0, sample_080354F8, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08039D34, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0803B058, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0803CDAC, 255, 0, 255, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 6, 0
	voice_directsound 60, 0, sample_0803E700, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0803F198, 255, 0, 229, 0
	voice_directsound 60, 0, sample_08040540, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08049278, 255, 0, 255, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 0, 7, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
#if PLATFORM_GBA
	voice_keysplit_all gMPlayJumpTableTemplate + 8
#else
	@ Hosted: the group pointer names the dummy records above.
	voice_keysplit_all hostedRhythmGroupDummy
#endif
	.global voicegroup_0801D89C
#if !PLATFORM_GBA
	mAlignPtr
#endif
voicegroup_0801D89C:
	voice_directsound 60, 0, sample_0804BC44, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0804D870, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0804F2B4, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08050C70, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08051F88, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, sample_08053E3C, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08053E3C, 15, 0, 255, 0
	voice_directsound 60, 0, sample_08059848, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0805B51C, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0805D390, 255, 0, 255, 0
	voice_directsound 60, 0, sample_0805F85C, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08061320, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08061844, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08062A24, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08064318, 255, 0, 255, 0
	voice_directsound 60, 0, sample_080661AC, 255, 0, 255, 0
	voice_directsound 60, 0, sample_08066D20, 255, 0, 255, 0
	voice_directsound 60, 0, sample_080694E0, 255, 0, 255, 0
	@ The last 12 entries hold runs of 0 and 1, not voices.
#if PLATFORM_GBA
	.fill 36, 1, 0
	.fill 36, 1, 1
	.fill 36, 1, 0
	.fill 36, 1, 1
#else
	@ Hosted: the same 12 dummy entries, zeroed, at the 24-byte record
	@ stride so no key can land between records.
	.fill 12 * 24, 1, 0
#endif
