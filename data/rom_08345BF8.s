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
@ The last 512 bytes of track 6's (crawfish_raceway) bg2Tiles: in the main
@ program that sheet ends where track 7's blobs begin, and the module's
@ copy of track 7's data starts 512 bytes early. Nothing reads them.
	.incbin "build/assets/tracks/crawfish_raceway/bg2Tiles_tail.bin"
	.global gModule_Track7Bg3Map
gModule_Track7Bg3Map:
	.incbin "build/assets/tracks/purley_park/module_bg3Map.bin"
	.global gModule_Track7Bg3Metatiles
gModule_Track7Bg3Metatiles:
	.incbin "build/assets/tracks/purley_park/bg3Metatiles.bin"
	.global gModule_Track7Bg3Tiles
gModule_Track7Bg3Tiles:
	.incbin "build/assets/tracks/purley_park/bg3Tiles.bin"
	.global gModule_Track7Palette
gModule_Track7Palette:
	.incbin "build/assets/tracks/purley_park/palette.bin"
	.global gModule_Track7Bg2Map
gModule_Track7Bg2Map:
	.incbin "build/assets/tracks/purley_park/module_bg2Map.bin"
	.global gModule_Track7Bg2Metatiles
gModule_Track7Bg2Metatiles:
	.incbin "build/assets/tracks/purley_park/bg2Metatiles.bin"
	.global gModule_Track7Bg2Tiles
gModule_Track7Bg2Tiles:
	.incbin "build/assets/tracks/purley_park/bg2Tiles.bin"
