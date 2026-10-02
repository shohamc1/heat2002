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
	.global gMPlayJumpTableTemplate
gMPlayJumpTableTemplate:
	mPtr C_DECL(ply_fine)
	mPtr C_DECL(ply_goto)
	.global gUnk_0801CF90
gUnk_0801CF90:
	mPtr C_DECL(ply_patt)
	mPtr C_DECL(ply_pend)
	mPtr C_DECL(ply_rept)
	mPtr C_DECL(ply_fine)
	mPtr C_DECL(ply_fine)
	mPtr C_DECL(ply_fine)
	mPtr C_DECL(ply_fine)
	mPtr C_DECL(ply_prio)
	mPtr C_DECL(ply_tempo)
	mPtr C_DECL(ply_keysh)
	mPtr C_DECL(ply_voice)
	mPtr C_DECL(ply_vol)
	mPtr C_DECL(ply_pan)
	mPtr C_DECL(ply_bend)
	mPtr C_DECL(ply_bendr)
	mPtr C_DECL(ply_lfos)
	mPtr C_DECL(ply_lfodl)
	mPtr C_DECL(ply_mod)
	mPtr C_DECL(ply_modt)
	mPtr C_DECL(ply_fine)
	mPtr C_DECL(ply_fine)
	mPtr C_DECL(ply_tune)
	mPtr C_DECL(ply_fine)
	mPtr C_DECL(ply_fine)
	mPtr C_DECL(ply_fine)
	mPtr C_DECL(ply_port)
	mPtr C_DECL(ply_fine)
	mPtr C_DECL(ply_endtie)
	mPtr C_DECL(SampleFreqSet)
	mPtr C_DECL(TrackStop)
	mPtr C_DECL(FadeOutBody)
	mPtr C_DECL(TrkVolPitSet)
	mPtr C_DECL(RealClearChain)
	mPtr C_DECL(SoundMainBTM)
