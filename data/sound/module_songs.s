@ Generated with Luvdis v0.9.0
.syntax unified
.text
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
	.include "tools/tmc/sound/MPlayDef.s"
	.thumb
	@ 0x083456EC-0x08345730 (EWRAM 0x0200CC6C-0x0200CCB0): the three
	@ songs the second GBA plays, hand-written as pokeemerald keeps its
	@ hand-written songs (MPlayDef.s commands). 55 of gModule_SongTable's
	@ 57 rows point at the empty module_song_dummy; the beep module_song_48
	@ and the held tone module_song_56 are the two real ones. The tone
	@ loops: its GOTO returns to its own TIE, holding the note forever.
	.global module_song_dummy
	.align 2, 0
module_song_dummy:
	.byte	0	@ NumTrks
	.byte	0	@ NumBlks
	.byte	0	@ Priority
	.byte	0	@ Reverb.

	.global module_song_48
	.align 2, 0

@**************** Track 1 ****************@
module_song_48_1:
	.byte		VOL   , 127
	.byte		KEYSH , 0
	.byte		TEMPO , 60
	.byte		VOICE , 2
	.byte		N24   , Cn3 , v127
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*************************************@
	.align 2, 0
module_song_48:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	0	@ Priority
	.byte	reverb_set+50	@ Reverb.

	.word	voicegroup_083453C0
	.word	module_song_48_1

	.global module_song_56
	.align 2, 0

@**************** Track 1 ****************@
module_song_56_1:
	.byte		VOL   , 127
	.byte		KEYSH , 0
	.byte		TEMPO , 60
	.byte		VOICE , 0
module_song_56_loop:
	.byte		TIE   , Cn3 , v072
	.byte	W96
	.byte	W96
	.byte	EOT
	.byte	GOTO
	 .word	module_song_56_loop
	.byte	W96
	.byte	W96
	.byte	FINE

@*************************************@
	.align 2, 0
module_song_56:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	0	@ Priority
	.byte	reverb_set+50	@ Reverb.

	.word	voicegroup_083453C0
	.word	module_song_56_1
