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
	.thumb
	.incbin "build/assets/unknown/data_0806FFF4.bin"
	.incbin "build/assets/unknown/data_08070004.bin"
	.incbin "build/assets/unknown/data_0807000C.bin"
	.incbin "build/assets/unknown/data_0807017C.bin"
	.incbin "build/assets/unknown/data_0807035C.bin"
	.incbin "build/assets/unknown/data_08070410.bin"
	.incbin "build/assets/unknown/data_08070504.bin"
	.incbin "build/assets/unknown/data_08070558.bin"
	.incbin "build/assets/unknown/data_08070604.bin"
	.incbin "build/assets/unknown/data_08070700.bin"
	.incbin "build/assets/unknown/data_08070808.bin"
	.incbin "build/assets/unknown/data_0807080C.bin"
	.incbin "build/assets/unknown/data_08070810.bin"
	.incbin "build/assets/unknown/data_08070814.bin"
	.incbin "build/assets/unknown/data_08070818.bin"
	.incbin "build/assets/unknown/data_08070C14.bin"
	.incbin "build/assets/unknown/data_08071124.bin"
	.incbin "build/assets/unknown/data_08071880.bin"
	.incbin "build/assets/unknown/data_08072AB0.bin"
	.incbin "build/assets/unknown/data_08075C5C.bin"
	.global gUnk_0807C97C
gUnk_0807C97C:
	.incbin "build/assets/unknown/data_0807C97C.bin"
	.global gUnk_0807C988
gUnk_0807C988:
	.incbin "build/assets/unknown/data_0807C988.bin"
	.global gUnk_0807C994
gUnk_0807C994:
	.incbin "build/assets/unknown/data_0807C994.bin"
	.global gUnk_0807C9A0
gUnk_0807C9A0:
	.incbin "build/assets/unknown/data_0807C9A0.bin"
	.global gUnk_0807C9AC
gUnk_0807C9AC:
	.incbin "build/assets/unknown/data_0807C9AC.bin"
	.global gUnk_0807C9B4
gUnk_0807C9B4:
	.incbin "build/assets/unknown/data_0807C9B4.bin"
	.global gUnk_0807C9BC
gUnk_0807C9BC:
	.incbin "build/assets/unknown/data_0807C9BC.bin"
	.global gUnk_0807C9C4
gUnk_0807C9C4:
	.incbin "build/assets/unknown/data_0807C9C4.bin"
