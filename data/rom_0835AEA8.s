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
	.global gUnk_02022428
gUnk_02022428:
	.incbin "build/assets/graphics/tiles/race_hud_bg.tiles.bin", 0, 7232
	.global gModule_02024068
gModule_02024068:
	.incbin "build/assets/graphics/rl_083378A0.bin"
	.global gModule_020240E8
gModule_020240E8:
	.incbin "build/assets/graphics/rl_08337920.bin"
	.global gModule_02024168
gModule_02024168:
	.incbin "build/assets/graphics/rl_083379A0.bin"
	.global gModule_020241E8
gModule_020241E8:
	.incbin "build/assets/graphics/rl_08337A20.bin"
	.global gModule_02024268
gModule_02024268:
	.incbin "build/assets/graphics/rl_08337AA0.bin"
	.global gModule_020242E8
gModule_020242E8:
	.incbin "build/assets/graphics/rl_08337B20.bin"
	.global gModule_02024368
gModule_02024368:
	.incbin "build/assets/graphics/rl_08337BA0.bin"
	.global gUnk_020243E8
gUnk_020243E8:
	.incbin "build/assets/graphics/palettes/link_marker.pal.bin"
	.global gModule_02024408
gModule_02024408:
	.incbin "build/assets/graphics/rl_08337C40.bin"
	.global gModule_02024488
gModule_02024488:
	.incbin "build/assets/graphics/rl_08337CC0.bin"
	.global gModule_02024508
gModule_02024508:
	.incbin "build/assets/graphics/rl_08337D40.bin"
	.global gModule_02024588
gModule_02024588:
	.incbin "build/assets/graphics/rl_08337DC0.bin"
	.global gModule_02024608
gModule_02024608:
	.incbin "build/assets/graphics/rl_08337E40.bin"
	.global gModule_02024688
gModule_02024688:
	.incbin "build/assets/graphics/rl_08337EC0.bin"
	.global gModule_02024708
gModule_02024708:
	.incbin "build/assets/graphics/rl_08337F40.bin"
	.incbin "build/assets/graphics/palettes/pal_08337FC0.pal.bin"
	.global gModule_020247A8
gModule_020247A8:
	.incbin "build/assets/graphics/rl_08337FE0.bin"
	.global gModule_02024828
gModule_02024828:
	.incbin "build/assets/graphics/rl_08338060.bin"
	.global gModule_020248A8
gModule_020248A8:
	.incbin "build/assets/graphics/rl_083380E0.bin"
	.global gModule_02024928
gModule_02024928:
	.incbin "build/assets/graphics/rl_08338160.bin"
	.global gModule_020249A8
gModule_020249A8:
	.incbin "build/assets/graphics/rl_083381E0.bin"
	.global gModule_02024A28
gModule_02024A28:
	.incbin "build/assets/graphics/rl_08338260.bin"
	.global gModule_02024AA8
gModule_02024AA8:
	.incbin "build/assets/graphics/rl_083382E0.bin"
	.incbin "build/assets/graphics/palettes/pal_08338360.pal.bin"
	.global gModule_02024B48
gModule_02024B48:
	.incbin "build/assets/graphics/rl_08338380.bin"
	.global gModule_02024BC8
gModule_02024BC8:
	.incbin "build/assets/graphics/rl_08338400.bin"
	.global gModule_02024C48
gModule_02024C48:
	.incbin "build/assets/graphics/rl_08338480.bin"
	.global gModule_02024CC8
gModule_02024CC8:
	.incbin "build/assets/graphics/rl_08338500.bin"
	.global gModule_02024D48
gModule_02024D48:
	.incbin "build/assets/graphics/rl_08338580.bin"
	.global gModule_02024DC8
gModule_02024DC8:
	.incbin "build/assets/graphics/rl_08338600.bin"
	.global gModule_02024E48
gModule_02024E48:
	.incbin "build/assets/graphics/rl_08338680.bin"
	.incbin "build/assets/graphics/palettes/pal_08338700.pal.bin"
	.global gModule_SpeedNeedleGfx
gModule_SpeedNeedleGfx:
	.incbin "build/assets/graphics/rl_08338720.bin"
	.global gUnk_02024F50
gUnk_02024F50:
	.incbin "build/assets/graphics/palettes/track_select_arrow.pal.bin"
	.global gModule_LowFuelWarningGfx
gModule_LowFuelWarningGfx:
	.incbin "build/assets/graphics/rl_083387A8.bin"
	.space 2
	.incbin "build/assets/graphics/palettes/pal_083387F0.pal.bin"
	.incbin "build/assets/graphics/palettes/pal_082F98C0.pal.bin", 256, 256
