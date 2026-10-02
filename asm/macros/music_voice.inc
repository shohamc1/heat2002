@ The portable twin of tools/tmc/asm/macros/music_voice.inc, which the
@ build must not edit. The macro set and the GBA emission are verbatim
@ tmc's (mPtr widens to .4byte there, so the bytes are identical); the
@ hosted build emits host-width, aligned pointers through mPtr and
@ mAlignPtr instead. data/sound/voicegroups.s and module_sound.s include
@ this file in place of tmc's on both builds.
@
@ Hosted record layout (issue 5 step 4): every voice macro emits exactly
@ one 24-byte struct ToneData record (include/gba/m4a_internal.h) so a
@ voice group is a plain array -- head bytes 0-3, duty/period at 4 where
@ the GBA record keeps it (wav's first byte), pad to 8, pointer(s) at 8
@ and 16, envelope at 16-19 for the non-keysplit forms, pad to 24. The
@ pads are mAlignPtr: each record is a multiple of 8 and starts 8-aligned
@ (the group label aligns to the pointer width in the data files), so
@ the one before a pointer pads 4-7 and the trailing one pads 20-23.
@
@ The :req argument markers are dropped (as sa2's copy does): LLVM's
@ assembler rejects them when it assembles the hosted build.

	.include "asm/macros/portable.inc"

	.macro voice_directsound base_midi_key, pan, sample_data_pointer, attack, decay, sustain, release
	.byte 0
	_voice_directsound \base_midi_key, \pan, \sample_data_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro voice_directsound_no_resample base_midi_key, pan, sample_data_pointer, attack, decay, sustain, release
	.byte 8
	_voice_directsound \base_midi_key, \pan, \sample_data_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro voice_directsound_alt base_midi_key, pan, sample_data_pointer, attack, decay, sustain, release
	.byte 16
	_voice_directsound \base_midi_key, \pan, \sample_data_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_directsound base_midi_key, pan, sample_data_pointer, attack, decay, sustain, release
	.byte \base_midi_key
	.byte 0
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	mAlignPtr
	mPtr \sample_data_pointer
	.byte \attack
	.byte \decay
	.byte \sustain
	.byte \release
#if !PLATFORM_GBA
	mAlignPtr
#endif
	.endm

	.macro voice_square_1 base_midi_key, pan, sweep, duty_cycle, attack, decay, sustain, release
	_voice_square_1 1, \base_midi_key, \pan, \sweep, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro voice_square_1_alt base_midi_key, pan, sweep, duty_cycle, attack, decay, sustain, release
	_voice_square_1 9, \base_midi_key, \pan, \sweep, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_square_1 type, base_midi_key, pan, sweep, duty_cycle, attack, decay, sustain, release
#if PLATFORM_GBA
	.byte \type
	.byte \base_midi_key
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	.byte \sweep
	.byte (\duty_cycle & 0x3)
	.byte 0, 0, 0
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
#else
	@ Hosted: the wav slot at 8 exists but is zero, and the envelope
	@ sits at the struct's 16-19.
	.byte \type
	.byte \base_midi_key
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	.byte \sweep
	.byte (\duty_cycle & 0x3)
	.byte 0, 0, 0
	mPtr 0
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
	mAlignPtr
#endif
	.endm

	.macro voice_square_2 base_midi_key, pan, duty_cycle, attack, decay, sustain, release
	_voice_square_2 2, \base_midi_key, \pan, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro voice_square_2_alt base_midi_key, pan, duty_cycle, attack, decay, sustain, release
	_voice_square_2 10, \base_midi_key, \pan, \duty_cycle, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_square_2 type, base_midi_key, pan, duty_cycle, attack, decay, sustain, release
#if PLATFORM_GBA
	.byte \type
	.byte \base_midi_key
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	.byte 0
	.byte (\duty_cycle & 0x3)
	.byte 0, 0, 0
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
#else
	@ Hosted: as _voice_square_1's hosted branch.
	.byte \type
	.byte \base_midi_key
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	.byte 0
	.byte (\duty_cycle & 0x3)
	.byte 0, 0, 0
	mPtr 0
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
	mAlignPtr
#endif
	.endm

	.macro voice_programmable_wave base_midi_key, pan, wave_samples_pointer, attack, decay, sustain, release
	_voice_programmable_wave 3, \base_midi_key, \pan, \wave_samples_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro voice_programmable_wave_alt base_midi_key, pan, wave_samples_pointer, attack, decay, sustain, release
	_voice_programmable_wave 11, \base_midi_key, \pan, \wave_samples_pointer, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_programmable_wave type, base_midi_key, pan, wave_samples_pointer, attack, decay, sustain, release
	.byte \type
	.byte \base_midi_key
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	.byte 0
	mAlignPtr
	mPtr \wave_samples_pointer
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
#if !PLATFORM_GBA
	mAlignPtr
#endif
	.endm

	.macro voice_noise base_midi_key, pan, period, attack, decay, sustain, release
	_voice_noise 4, \base_midi_key, \pan, \period, \attack, \decay, \sustain, \release
	.endm

	.macro voice_noise_alt base_midi_key, pan, period, attack, decay, sustain, release
	_voice_noise 12, \base_midi_key, \pan, \period, \attack, \decay, \sustain, \release
	.endm

	.macro _voice_noise type, base_midi_key, pan, period, attack, decay, sustain, release
#if PLATFORM_GBA
	.byte \type
	.byte \base_midi_key
	.byte 0
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	.byte (\period & 0x1)
	.byte 0, 0, 0
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
#else
	@ Hosted: as _voice_square_1's hosted branch, with the period bit
	@ riding at 4.
	.byte \type
	.byte \base_midi_key
	.byte 0
	.if \pan != 0
	.byte (0x80 | \pan)
	.else
	.byte 0
	.endif
	.byte (\period & 0x1)
	.byte 0, 0, 0
	mPtr 0
	.byte (\attack  & 0x7)
	.byte (\decay   & 0x7)
	.byte (\sustain & 0xF)
	.byte (\release & 0x7)
	mAlignPtr
#endif
	.endm

	.macro voice_keysplit voice_group_pointer, keysplit_table_pointer
	.byte 0x40, 0, 0, 0
#if !PLATFORM_GBA
	mAlignPtr
#endif
	mPtr \voice_group_pointer
	mPtr \keysplit_table_pointer
	.endm

	.macro voice_keysplit_all voice_group_pointer
	.byte 0x80, 0, 0, 0
#if !PLATFORM_GBA
	mAlignPtr
#endif
	mPtr \voice_group_pointer
	mPtr 0
	.endm
