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
	.global gModule_TextGlyphTileIndices
gModule_TextGlyphTileIndices:
	.incbin "build/assets/unknown/data_08358450.bin"
	.global gUnk_0201FB54
gUnk_0201FB54:
	.incbin "build/assets/graphics/tiles/text_layer.tiles.bin", 0, 4524
	.incbin "build/assets/graphics/tiles/text_layer.tiles.bin", 4524, 1684
	.global gUnk_02021394
gUnk_02021394:
	.incbin "build/assets/graphics/palettes/race_hud_bg.pal.bin"
	.global gUnk_02021594
gUnk_02021594:
	.incbin "build/assets/unknown/data_0835A014.bin"
	.global gModule_BigDigitGlyphs
gModule_BigDigitGlyphs:
	.incbin "build/assets/unknown/data_0835A02A.bin"
	.global gUnk_020215D2
gUnk_020215D2:
	.incbin "build/assets/unknown/data_0835A052.bin"
	.global gUnk_020215EA
gUnk_020215EA:
	.incbin "build/assets/unknown/data_0835A06A.bin"
