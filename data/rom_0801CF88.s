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
	.global gMPlayJumpTableTemplate
gMPlayJumpTableTemplate:
	.4byte ply_fine
	.4byte ply_goto
	.global gUnk_0801CF90
gUnk_0801CF90:
	.4byte ply_patt
	.4byte ply_pend
	.4byte ply_rept
	.4byte ply_fine
	.4byte ply_fine
	.4byte ply_fine
	.4byte ply_fine
	.4byte ply_prio
	.4byte ply_tempo
	.4byte ply_keysh
	.4byte ply_voice
	.4byte ply_vol
	.4byte ply_pan
	.4byte ply_bend
	.4byte ply_bendr
	.4byte ply_lfos
	.4byte ply_lfodl
	.4byte ply_mod
	.4byte ply_modt
	.4byte ply_fine
	.4byte ply_fine
	.4byte ply_tune
	.4byte ply_fine
	.4byte ply_fine
	.4byte ply_fine
	.4byte ply_port
	.4byte ply_fine
	.4byte ply_endtie
	.4byte sub_08001640
	.4byte TrackStop
	.4byte FadeOutBody
	.4byte TrkVolPitSet
	.4byte RealClearChain
	.4byte SoundMainBTM
