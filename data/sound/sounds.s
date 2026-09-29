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
	.thumb
	@ 0x0806AA64-0x0806C664: the 25 songs, mid2agb's assembly of
	@ assets/sound/songs/*.mid (scripts/assets.py song), included in
	@ place so their voicegroup and track pointers resolve where they
	@ link. Each file defines its own global header label, song_NN.
	.include "build/assets/sound/songs/song_01.s"
	.include "build/assets/sound/songs/song_02.s"
	.include "build/assets/sound/songs/song_03.s"
	.include "build/assets/sound/songs/song_08.s"
	.include "build/assets/sound/songs/song_09.s"
	.include "build/assets/sound/songs/song_10.s"
	.include "build/assets/sound/songs/song_11.s"
	.include "build/assets/sound/songs/song_12.s"
	.include "build/assets/sound/songs/song_13.s"
	.include "build/assets/sound/songs/song_14.s"
	.include "build/assets/sound/songs/song_15.s"
	.include "build/assets/sound/songs/song_16.s"
	.include "build/assets/sound/songs/song_17.s"
	.include "build/assets/sound/songs/song_18.s"
	.include "build/assets/sound/songs/song_19.s"
	.include "build/assets/sound/songs/song_20.s"
	.include "build/assets/sound/songs/song_21.s"
	.include "build/assets/sound/songs/song_22.s"
	.include "build/assets/sound/songs/song_23.s"
	.include "build/assets/sound/songs/song_24.s"
	.include "build/assets/sound/songs/song_25.s"
	.include "build/assets/sound/songs/song_26.s"
	.include "build/assets/sound/songs/song_27.s"
	.include "build/assets/sound/songs/song_28.s"
	.include "build/assets/sound/songs/song_29.s"
