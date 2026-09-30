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
	.global gUnk_02027800
gUnk_02027800:
	.incbin "build/assets/unknown/data_08360280.bin"
	.global gUnk_02027804
gUnk_02027804:
	.incbin "build/assets/unknown/data_08360284.bin"
	.global gUnk_02027808
gUnk_02027808:
	.incbin "build/assets/unknown/data_08360288.bin"
	.global gUnk_0202780C
gUnk_0202780C:
	.incbin "build/assets/unknown/data_0836028C.bin", 0, 4
	.global gUnk_02027810
gUnk_02027810:
	.incbin "build/assets/unknown/data_0836028C.bin", 4, 0x5A0
	.global gUnk_02027DB0
gUnk_02027DB0:
	.incbin "build/assets/unknown/data_0836028C.bin", 0x5A4, 0x30
	.incbin "build/assets/unknown/data_08360860.bin"
	.incbin "build/assets/unknown/data_08360888.bin"
	.incbin "build/assets/unknown/data_083608F8.bin"
	.incbin "build/assets/unknown/data_08360C2C.bin"
	.incbin "build/assets/unknown/data_08361780.bin", 0, 0x6F0
	.global gUnk_020293F0
gUnk_020293F0:
	.incbin "build/assets/unknown/data_08361780.bin", 0x6F0, 0x8E4
	.global gUnk_02029CD4
gUnk_02029CD4:
	.incbin "build/assets/unknown/data_08361780.bin", 0xFD4, 0x1200
