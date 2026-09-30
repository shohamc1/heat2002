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
@ The last 512 bytes of track 6's (crawfish_raceway) bg2Tiles: in the main
@ program that sheet ends where track 7's blobs begin, and the module's
@ copy of track 7's data starts 512 bytes early. Nothing reads them.
	.incbin "build/assets/tracks/crawfish_raceway/bg2Tiles.bin", 32192, 512
	.global gUnk_0200D378
gUnk_0200D378:
	.incbin "build/assets/tracks/purley_park/module_bg3Map.bin"
	.global gUnk_0201044C
gUnk_0201044C:
	.incbin "build/assets/tracks/purley_park/bg3Metatiles.bin"
	.global gUnk_0201242C
gUnk_0201242C:
	.incbin "build/assets/tracks/purley_park/bg3Tiles.bin"
	.global gUnk_02013DAC
gUnk_02013DAC:
	.incbin "build/assets/tracks/purley_park/palette.bin"
	.global gUnk_02013FAC
gUnk_02013FAC:
	.incbin "build/assets/tracks/purley_park/module_bg2Map.bin"
	.global gUnk_02017080
gUnk_02017080:
	.incbin "build/assets/tracks/purley_park/bg2Metatiles.bin"
	.global gUnk_02018DA0
gUnk_02018DA0:
	.incbin "build/assets/tracks/purley_park/bg2Tiles.bin"
