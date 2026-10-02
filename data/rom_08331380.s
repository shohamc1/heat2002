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
	.global gUnk_08331380
gUnk_08331380:
	cSym gUnk_08331380
	.incbin "build/assets/graphics/rl_08331380.bin"
	.align 2, 0
	.global gUnk_083313A0
gUnk_083313A0:
	cSym gUnk_083313A0
	.incbin "build/assets/graphics/rl_083313A0.bin"
	.align 2, 0
	.global gUnk_083313C8
gUnk_083313C8:
	cSym gUnk_083313C8
	.incbin "build/assets/graphics/rl_083313C8.bin"
	.align 2, 0
	.global gUnk_083313F8
gUnk_083313F8:
	cSym gUnk_083313F8
	.incbin "build/assets/graphics/rl_083313F8.bin"
	.align 2, 0
	.global gUnk_08331438
gUnk_08331438:
	cSym gUnk_08331438
	.incbin "build/assets/graphics/rl_08331438.bin"
	.align 2, 0
	.global gUnk_08331480
gUnk_08331480:
	cSym gUnk_08331480
	.incbin "build/assets/graphics/rl_08331480.bin"
	.align 2, 0
	.global gUnk_083314CC
gUnk_083314CC:
	cSym gUnk_083314CC
	.incbin "build/assets/graphics/rl_083314CC.bin"
	.align 2, 0
	.global gUnk_08331520
gUnk_08331520:
	cSym gUnk_08331520
	.incbin "build/assets/graphics/rl_08331520.bin"
	.align 2, 0
	.global gUnk_08331574
gUnk_08331574:
	cSym gUnk_08331574
	.incbin "build/assets/graphics/rl_08331574.bin"
	.align 2, 0
	.global gUnk_083315D0
gUnk_083315D0:
	cSym gUnk_083315D0
	.incbin "build/assets/graphics/rl_083315D0.bin"
	.align 2, 0
	.global gUnk_08331638
gUnk_08331638:
	cSym gUnk_08331638
	.incbin "build/assets/graphics/rl_08331638.bin"
	.align 2, 0
	.global gUnk_083316A8
gUnk_083316A8:
	cSym gUnk_083316A8
	.incbin "build/assets/graphics/rl_083316A8.bin"
	.align 2, 0
	.global gUnk_0833171C
gUnk_0833171C:
	cSym gUnk_0833171C
	.incbin "build/assets/graphics/rl_0833171C.bin"
	.align 2, 0
	.global gUnk_08331798
gUnk_08331798:
	cSym gUnk_08331798
	.incbin "build/assets/graphics/rl_08331798.bin"
	.align 2, 0
	.global gUnk_0833181C
gUnk_0833181C:
	cSym gUnk_0833181C
	.incbin "build/assets/graphics/rl_0833181C.bin"
	.align 2, 0
	.global gUnk_083318A0
gUnk_083318A0:
	cSym gUnk_083318A0
	.incbin "build/assets/graphics/rl_083318A0.bin"
	.align 2, 0
	.global gUnk_08331924
gUnk_08331924:
	cSym gUnk_08331924
	.incbin "build/assets/graphics/rl_08331924.bin"
	.align 2, 0
	.global gUnk_083319A8
gUnk_083319A8:
	cSym gUnk_083319A8
	.incbin "build/assets/graphics/rl_083319A8.bin"
	.align 2, 0
	.global gUnk_08331A28
gUnk_08331A28:
	cSym gUnk_08331A28
	.incbin "build/assets/graphics/rl_08331A28.bin"
	.align 2, 0
	.global gUnk_08331AA8
gUnk_08331AA8:
	cSym gUnk_08331AA8
	.incbin "build/assets/graphics/rl_08331AA8.bin"
	.align 2, 0
	.global gUnk_08331B20
gUnk_08331B20:
	cSym gUnk_08331B20
	.incbin "build/assets/graphics/rl_08331B20.bin"
	.global gUnk_08331B94
gUnk_08331B94:
	cSym gUnk_08331B94
	.incbin "build/assets/graphics/rl_08331B94.bin"
	.global gUnk_08331C08
gUnk_08331C08:
	cSym gUnk_08331C08
	.incbin "build/assets/graphics/rl_08331C08.bin"
	.align 2, 0
	.global gUnk_08331C7C
gUnk_08331C7C:
	cSym gUnk_08331C7C
	.incbin "build/assets/graphics/rl_08331C7C.bin"
	.align 2, 0
	.global gUnk_08331CEC
gUnk_08331CEC:
	cSym gUnk_08331CEC
	.incbin "build/assets/graphics/rl_08331CEC.bin"
	.global gUnk_08331D54
gUnk_08331D54:
	cSym gUnk_08331D54
	.incbin "build/assets/graphics/rl_08331D54.bin"
	.align 2, 0
	.global gUnk_08331DBC
gUnk_08331DBC:
	cSym gUnk_08331DBC
	.incbin "build/assets/graphics/rl_08331DBC.bin"
	.align 2, 0
	.global gUnk_08331E1C
gUnk_08331E1C:
	cSym gUnk_08331E1C
	.incbin "build/assets/graphics/rl_08331E1C.bin"
	.align 2, 0
	.global gUnk_08331E74
gUnk_08331E74:
	cSym gUnk_08331E74
	.incbin "build/assets/graphics/rl_08331E74.bin"
	.align 2, 0
	.global gUnk_08331EC4
gUnk_08331EC4:
	cSym gUnk_08331EC4
	.incbin "build/assets/graphics/rl_08331EC4.bin"
	.align 2, 0
	.global gUnk_08331F0C
gUnk_08331F0C:
	cSym gUnk_08331F0C
	.incbin "build/assets/graphics/rl_08331F0C.bin"
	.align 2, 0
	.global gUnk_08331F4C
gUnk_08331F4C:
	cSym gUnk_08331F4C
	.incbin "build/assets/graphics/rl_08331F4C.bin"
	.align 2, 0
