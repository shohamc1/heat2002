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
	.global gModule_TrackStartGrids
gModule_TrackStartGrids:
	.incbin "build/assets/unknown/data_0835FB0C.bin"
	.global gUnk_020270C6
gUnk_020270C6:
	.incbin "build/assets/unknown/data_0835FB46.bin"
	.global gUnk_020270D0
gUnk_020270D0:
	.incbin "build/assets/unknown/data_0835FB50.bin"
	.global gUnk_0202713E
gUnk_0202713E:
	.incbin "build/assets/unknown/data_0835FBBE.bin"
	.global gUnk_0202714A
gUnk_0202714A:
	.incbin "build/assets/unknown/data_0835FBCA.bin"
	.global gUnk_02027154
gUnk_02027154:
	.incbin "build/assets/unknown/data_0835FBD4.bin", 0, 40
