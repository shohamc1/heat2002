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
	.global gLinkMarkerP1FrameList
gLinkMarkerP1FrameList:
	cSym gLinkMarkerP1FrameList
	mPtr gUnk_083378A0
	mPtr gUnk_08337920
	mPtr gUnk_083379A0
	mPtr gUnk_08337A20
	mPtr gUnk_08337AA0
	mPtr gUnk_08337B20
	mPtr gUnk_08337BA0
	.global gLinkMarkerP2FrameList
gLinkMarkerP2FrameList:
	cSym gLinkMarkerP2FrameList
	mPtr gUnk_08337C40
	mPtr gUnk_08337CC0
	mPtr gUnk_08337D40
	mPtr gUnk_08337DC0
	mPtr gUnk_08337E40
	mPtr gUnk_08337EC0
	mPtr gUnk_08337F40
	.global gLinkMarkerP3FrameList
gLinkMarkerP3FrameList:
	cSym gLinkMarkerP3FrameList
	mPtr gUnk_08337FE0
	mPtr gUnk_08338060
	mPtr gUnk_083380E0
	mPtr gUnk_08338160
	mPtr gUnk_083381E0
	mPtr gUnk_08338260
	mPtr gUnk_083382E0
	.global gLinkMarkerP4FrameList
gLinkMarkerP4FrameList:
	cSym gLinkMarkerP4FrameList
	mPtr gUnk_08338380
	mPtr gUnk_08338400
	mPtr gUnk_08338480
	mPtr gUnk_08338500
	mPtr gUnk_08338580
	mPtr gUnk_08338600
	mPtr gUnk_08338680
	mPtr gSpeedNeedleGfx
	mPtr gLowFuelWarningGfx
