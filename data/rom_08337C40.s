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
	.global gUnk_08337C40
gUnk_08337C40:
	.incbin "build/assets/graphics/rl_08337C40.bin"
	.global gUnk_08337CC0
gUnk_08337CC0:
	.incbin "build/assets/graphics/rl_08337CC0.bin"
	.global gUnk_08337D40
gUnk_08337D40:
	.incbin "build/assets/graphics/rl_08337D40.bin"
	.global gUnk_08337DC0
gUnk_08337DC0:
	.incbin "build/assets/graphics/rl_08337DC0.bin"
	.global gUnk_08337E40
gUnk_08337E40:
	.incbin "build/assets/graphics/rl_08337E40.bin"
	.global gUnk_08337EC0
gUnk_08337EC0:
	.incbin "build/assets/graphics/rl_08337EC0.bin"
	.global gUnk_08337F40
gUnk_08337F40:
	.incbin "build/assets/graphics/rl_08337F40.bin"
	.incbin "build/assets/graphics/palettes/pal_08337FC0.pal.bin"
	.global gUnk_08337FE0
gUnk_08337FE0:
	.incbin "build/assets/graphics/rl_08337FE0.bin"
	.global gUnk_08338060
gUnk_08338060:
	.incbin "build/assets/graphics/rl_08338060.bin"
	.global gUnk_083380E0
gUnk_083380E0:
	.incbin "build/assets/graphics/rl_083380E0.bin"
	.global gUnk_08338160
gUnk_08338160:
	.incbin "build/assets/graphics/rl_08338160.bin"
	.global gUnk_083381E0
gUnk_083381E0:
	.incbin "build/assets/graphics/rl_083381E0.bin"
	.global gUnk_08338260
gUnk_08338260:
	.incbin "build/assets/graphics/rl_08338260.bin"
	.global gUnk_083382E0
gUnk_083382E0:
	.incbin "build/assets/graphics/rl_083382E0.bin"
	.incbin "build/assets/graphics/palettes/pal_08338360.pal.bin"
	.global gUnk_08338380
gUnk_08338380:
	.incbin "build/assets/graphics/rl_08338380.bin"
	.global gUnk_08338400
gUnk_08338400:
	.incbin "build/assets/graphics/rl_08338400.bin"
	.global gUnk_08338480
gUnk_08338480:
	.incbin "build/assets/graphics/rl_08338480.bin"
	.global gUnk_08338500
gUnk_08338500:
	.incbin "build/assets/graphics/rl_08338500.bin"
	.global gUnk_08338580
gUnk_08338580:
	.incbin "build/assets/graphics/rl_08338580.bin"
	.global gUnk_08338600
gUnk_08338600:
	.incbin "build/assets/graphics/rl_08338600.bin"
	.global gUnk_08338680
gUnk_08338680:
	.incbin "build/assets/graphics/rl_08338680.bin"
	.incbin "build/assets/graphics/palettes/pal_08338700.pal.bin"
	.global gSpeedNeedleGfx
gSpeedNeedleGfx:
	cSym gSpeedNeedleGfx
	.incbin "build/assets/graphics/rl_08338720.bin"
