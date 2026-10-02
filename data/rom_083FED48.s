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
	.global gUnk_083FED48
gUnk_083FED48:
	cSym gUnk_083FED48
	mPtr gUnk_082BA310
	.global gUnk_083FED4C
gUnk_083FED4C:
	cSym gUnk_083FED4C
	mPtr gUnk_082BACD8
	.global gUnk_083FED50
gUnk_083FED50:
	cSym gUnk_083FED50
	mPtr gUnk_082BB83C
	.global gUnk_083FED54
gUnk_083FED54:
	cSym gUnk_083FED54
	mPtr gUnk_082BC440
	.global gUnk_083FED58
gUnk_083FED58:
	cSym gUnk_083FED58
	mPtr gUnk_082BCF60
	.global gUnk_083FED5C
gUnk_083FED5C:
	cSym gUnk_083FED5C
	mPtr gUnk_082BD948
	.global gUnk_083FED60
gUnk_083FED60:
	cSym gUnk_083FED60
	mPtr gUnk_082BE3BC
	.global gUnk_083FED64
gUnk_083FED64:
	cSym gUnk_083FED64
	mPtr gUnk_082BEEC4
	.global gUnk_083FED68
gUnk_083FED68:
	cSym gUnk_083FED68
	mPtr gUnk_082BFB3C
	.global gUnk_083FED6C
gUnk_083FED6C:
	cSym gUnk_083FED6C
	mPtr gUnk_082C0654
	.global gUnk_083FED70
gUnk_083FED70:
	cSym gUnk_083FED70
	mPtr gUnk_082C1164
	.global gUnk_083FED74
gUnk_083FED74:
	cSym gUnk_083FED74
	mPtr gUnk_082C1CE0
	.global gUnk_083FED78
gUnk_083FED78:
	cSym gUnk_083FED78
	mPtr gUnk_082C2810
	.global gUnk_083FED7C
gUnk_083FED7C:
	cSym gUnk_083FED7C
	mPtr gUnk_082C3350
	.global gUnk_083FED80
gUnk_083FED80:
	cSym gUnk_083FED80
	mPtr gUnk_082C3ED4
	.global gUnk_083FED84
gUnk_083FED84:
	cSym gUnk_083FED84
	mPtr gUnk_082C492C
	.global gUnk_083FED88
gUnk_083FED88:
	cSym gUnk_083FED88
	mPtr gUnk_082C5578
	.global gUnk_083FED8C
gUnk_083FED8C:
	cSym gUnk_083FED8C
	mPtr gUnk_082C6194
	.global gUnk_083FED90
gUnk_083FED90:
	cSym gUnk_083FED90
	mPtr gUnk_082C6D34
	.global gUnk_083FED94
gUnk_083FED94:
	cSym gUnk_083FED94
	mPtr gUnk_082C78A4
	.global gUnk_083FED98
gUnk_083FED98:
	cSym gUnk_083FED98
	mPtr gUnk_082C8428
	.global gUnk_083FED9C
gUnk_083FED9C:
	cSym gUnk_083FED9C
	mPtr gUnk_082C9000
	.global gUnk_083FEDA0
gUnk_083FEDA0:
	cSym gUnk_083FEDA0
	mPtr gUnk_082C9B24
	.global gUnk_083FEDA4
gUnk_083FEDA4:
	cSym gUnk_083FEDA4
	mPtr gUnk_082CA624
	.global gUnk_083FEDA8
gUnk_083FEDA8:
	cSym gUnk_083FEDA8
	mPtr gUnk_082CB11C
	.global gUnk_083FEDAC
gUnk_083FEDAC:
	cSym gUnk_083FEDAC
	mPtr gUnk_082CBC48
	.global gUnk_083FEDB0
gUnk_083FEDB0:
	cSym gUnk_083FEDB0
	mPtr gUnk_082CC7D8
	.global gUnk_083FEDB4
gUnk_083FEDB4:
	cSym gUnk_083FEDB4
	mPtr gUnk_082CD340
	.global gUnk_083FEDB8
gUnk_083FEDB8:
	cSym gUnk_083FEDB8
	mPtr gUnk_082CDF00
	.global gUnk_083FEDBC
gUnk_083FEDBC:
	cSym gUnk_083FEDBC
	mPtr gUnk_082CEB44
	.global gUnk_083FEDC0
gUnk_083FEDC0:
	cSym gUnk_083FEDC0
	mPtr gUnk_082CF5FC
	.global gUnk_083FEDC4
gUnk_083FEDC4:
	cSym gUnk_083FEDC4
	mPtr gUnk_082D00F0
	.global gUnk_083FEDC8
gUnk_083FEDC8:
	cSym gUnk_083FEDC8
	mPtr gUnk_082D0C4C
	.global gUnk_083FEDCC
gUnk_083FEDCC:
	cSym gUnk_083FEDCC
	mPtr gUnk_082D17BC
	.global gUnk_083FEDD0
gUnk_083FEDD0:
	cSym gUnk_083FEDD0
	mPtr gUnk_082D22C8
	.global gUnk_083FEDD4
gUnk_083FEDD4:
	cSym gUnk_083FEDD4
	mPtr gUnk_082D2DEC
	.global gUnk_083FEDD8
gUnk_083FEDD8:
	cSym gUnk_083FEDD8
	mPtr gUnk_082D38FC
	.global gUnk_083FEDDC
gUnk_083FEDDC:
	cSym gUnk_083FEDDC
	mPtr gUnk_082D4410
	.global gUnk_083FEDE0
gUnk_083FEDE0:
	cSym gUnk_083FEDE0
	mPtr gUnk_082D4E88
	.global gUnk_083FEDE4
gUnk_083FEDE4:
	cSym gUnk_083FEDE4
	mPtr gUnk_082D59E8
	.global gUnk_083FEDE8
gUnk_083FEDE8:
	cSym gUnk_083FEDE8
	mPtr gUnk_082D64F8
	.global gUnk_083FEDEC
gUnk_083FEDEC:
	cSym gUnk_083FEDEC
	mPtr gUnk_082D703C
	.global gUnk_083FEDF0
gUnk_083FEDF0:
	cSym gUnk_083FEDF0
	mPtr gUnk_082D7B6C
	.global gUnk_083FEDF4
gUnk_083FEDF4:
	cSym gUnk_083FEDF4
	mPtr gUnk_082D86A0
	.global gUnk_083FEDF8
gUnk_083FEDF8:
	cSym gUnk_083FEDF8
	mPtr gUnk_082D91F4
	.global gUnk_083FEDFC
gUnk_083FEDFC:
	cSym gUnk_083FEDFC
	mPtr gUnk_082D9D0C
	.global gUnk_083FEE00
gUnk_083FEE00:
	cSym gUnk_083FEE00
	mPtr gUnk_082DA774
	.global gUnk_083FEE04
gUnk_083FEE04:
	cSym gUnk_083FEE04
	mPtr gUnk_082DB1B4
	.global gUnk_083FEE08
gUnk_083FEE08:
	cSym gUnk_083FEE08
	mPtr gUnk_082DBCC4
	.global gUnk_083FEE0C
gUnk_083FEE0C:
	cSym gUnk_083FEE0C
	mPtr gUnk_082DC814
	.global gUnk_083FEE10
gUnk_083FEE10:
	cSym gUnk_083FEE10
	mPtr gUnk_082DD344
	.global gUnk_083FEE14
gUnk_083FEE14:
	cSym gUnk_083FEE14
	mPtr gUnk_082DDE98
	.global gUnk_083FEE18
gUnk_083FEE18:
	cSym gUnk_083FEE18
	mPtr gUnk_082DE9C4
	.global gUnk_083FEE1C
gUnk_083FEE1C:
	cSym gUnk_083FEE1C
	mPtr gUnk_082DF4E0
	.global gUnk_083FEE20
gUnk_083FEE20:
	cSym gUnk_083FEE20
	mPtr gUnk_082E0014
	.global gUnk_083FEE24
gUnk_083FEE24:
	cSym gUnk_083FEE24
	mPtr gUnk_082E0B6C
	.global gUnk_083FEE28
gUnk_083FEE28:
	cSym gUnk_083FEE28
	mPtr gUnk_082E1688
	.global gUnk_083FEE2C
gUnk_083FEE2C:
	cSym gUnk_083FEE2C
	mPtr gUnk_082E2190
	.global gUnk_083FEE30
gUnk_083FEE30:
	cSym gUnk_083FEE30
	mPtr gUnk_082E2CEC
	.global gUnk_083FEE34
gUnk_083FEE34:
	cSym gUnk_083FEE34
	mPtr gUnk_082E3840
	.global gTrackPreviewGfx_Track2
gTrackPreviewGfx_Track2:
	cSym gTrackPreviewGfx_Track2
	mPtr gUnk_082F7EE0
	mPtr gUnk_082F8828
	mPtr gUnk_082F8F6C
	mPtr gUnk_082F9360
	.global gTrackPreviewGfx_Track3
gTrackPreviewGfx_Track3:
	cSym gTrackPreviewGfx_Track3
	mPtr gUnk_082F9AC0
	mPtr gUnk_082FA444
	mPtr gUnk_082FAE24
	mPtr gUnk_082FB3FC
	.global gTrackPreviewGfx_Track5
gTrackPreviewGfx_Track5:
	cSym gTrackPreviewGfx_Track5
	mPtr gUnk_082FB8AC
	mPtr gUnk_082FC150
	mPtr gUnk_082FCA94
	mPtr gUnk_082FCAD8
	.global gTrackPreviewGfx_Track1
gTrackPreviewGfx_Track1:
	cSym gTrackPreviewGfx_Track1
	mPtr gUnk_082FD2F8
	mPtr gUnk_082FDFE0
	mPtr gUnk_082FEB60
	mPtr gUnk_082FEDC4
	.global gTrackPreviewGfx_Track4
gTrackPreviewGfx_Track4:
	cSym gTrackPreviewGfx_Track4
	mPtr gUnk_082FF61C
	mPtr gUnk_082FFD38
	mPtr gUnk_083004A4
	mPtr gUnk_0830076C
	.global gTrackPreviewGfx_Track0
gTrackPreviewGfx_Track0:
	cSym gTrackPreviewGfx_Track0
	mPtr gUnk_08300DCC
	mPtr gUnk_083017E8
	mPtr gUnk_083024A8
	mPtr gUnk_08302764
	.global gTrackPreviewGfx_Track6
gTrackPreviewGfx_Track6:
	cSym gTrackPreviewGfx_Track6
	mPtr gUnk_08303000
	mPtr gUnk_08303638
	mPtr gUnk_083040FC
	mPtr gUnk_08304558
	.global gTrackPreviewGfx_Track7
gTrackPreviewGfx_Track7:
	cSym gTrackPreviewGfx_Track7
	mPtr gUnk_08304BFC
	mPtr gUnk_0830531C
	mPtr gUnk_08305A8C
	mPtr gUnk_08305D8C
	.global gTrackPreviewGfx_Track8
gTrackPreviewGfx_Track8:
	cSym gTrackPreviewGfx_Track8
	mPtr gUnk_08306438
	mPtr gUnk_08306D38
	mPtr gUnk_08307ACC
	mPtr gUnk_08308110
	.global gTrackPreviewGfx_Track10
gTrackPreviewGfx_Track10:
	cSym gTrackPreviewGfx_Track10
	mPtr gUnk_0830897C
	mPtr gUnk_083091D8
	mPtr gUnk_08309D28
	mPtr gUnk_0830A550
	.global gTrackPreviewGfx_Track11
gTrackPreviewGfx_Track11:
	cSym gTrackPreviewGfx_Track11
	mPtr gUnk_0830AD68
	mPtr gUnk_0830B484
	mPtr gUnk_0830BDF0
	mPtr gUnk_0830C23C
	.global gTrackPreviewGfx_Track9
gTrackPreviewGfx_Track9:
	cSym gTrackPreviewGfx_Track9
	mPtr gUnk_0830CC10
	mPtr gUnk_0830D358
	mPtr gUnk_0830DE8C
	mPtr gUnk_0830E358
	mPtr gTrackSelectLeftArrowGfx
	mPtr gTrackSelectRightArrowGfx
