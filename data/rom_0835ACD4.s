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
	.global gModule_FontTileEntries
gModule_FontTileEntries:
	.incbin "build/assets/unknown/data_0835ACD4.bin"
	.global gUnk_02022428
gUnk_02022428:
	.incbin "build/assets/graphics/tiles/race_hud_bg.tiles.bin", 0, 7232
	.incbin "build/assets/graphics/rl_083378A0.bin"
	.incbin "build/assets/graphics/rl_08337920.bin"
	.incbin "build/assets/graphics/rl_083379A0.bin"
	.incbin "build/assets/graphics/rl_08337A20.bin"
	.incbin "build/assets/graphics/rl_08337AA0.bin"
	.incbin "build/assets/graphics/rl_08337B20.bin"
	.incbin "build/assets/graphics/rl_08337BA0.bin"
	.global gUnk_020243E8
gUnk_020243E8:
	.incbin "build/assets/graphics/palettes/link_marker.pal.bin"
	.incbin "build/assets/graphics/rl_08337C40.bin"
	.incbin "build/assets/graphics/rl_08337CC0.bin"
	.incbin "build/assets/graphics/rl_08337D40.bin"
	.incbin "build/assets/graphics/rl_08337DC0.bin"
	.incbin "build/assets/graphics/rl_08337E40.bin"
	.incbin "build/assets/graphics/rl_08337EC0.bin"
	.incbin "build/assets/graphics/rl_08337F40.bin"
	.incbin "build/assets/graphics/palettes/pal_08337FC0.pal.bin"
	.incbin "build/assets/graphics/rl_08337FE0.bin"
	.incbin "build/assets/graphics/rl_08338060.bin"
	.incbin "build/assets/graphics/rl_083380E0.bin"
	.incbin "build/assets/graphics/rl_08338160.bin"
	.incbin "build/assets/graphics/rl_083381E0.bin"
	.incbin "build/assets/graphics/rl_08338260.bin"
	.incbin "build/assets/graphics/rl_083382E0.bin"
	.incbin "build/assets/graphics/palettes/pal_08338360.pal.bin"
	.incbin "build/assets/graphics/rl_08338380.bin"
	.incbin "build/assets/graphics/rl_08338400.bin"
	.incbin "build/assets/graphics/rl_08338480.bin"
	.incbin "build/assets/graphics/rl_08338500.bin"
	.incbin "build/assets/graphics/rl_08338580.bin"
	.incbin "build/assets/graphics/rl_08338600.bin"
	.incbin "build/assets/graphics/rl_08338680.bin"
	.incbin "build/assets/graphics/palettes/pal_08338700.pal.bin"
	.global gUnk_02024EE8
gUnk_02024EE8:
	.incbin "build/assets/graphics/rl_08338720.bin"
	.global gUnk_02024F50
gUnk_02024F50:
	.incbin "build/assets/graphics/palettes/track_select_arrow.pal.bin"
	.global gUnk_02024F70
gUnk_02024F70:
	.incbin "build/assets/unknown/data_0835D9F0.bin"
	.global gUnk_020250EC
gUnk_020250EC:
	.incbin "build/assets/unknown/data_0835DB6C.bin"
