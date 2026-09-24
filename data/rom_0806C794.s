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
	.global gUnk_0806C794
gUnk_0806C794:
	.incbin "build/assets/unknown/data_0806C794.bin"
	.global gUnk_0806C79C
gUnk_0806C79C:
	.incbin "build/assets/unknown/data_0806C79C.bin"
	.global gUnk_0806C7A0
gUnk_0806C7A0:
	.incbin "build/assets/unknown/data_0806C7A0.bin"
	.global gUnk_0806C7C0
gUnk_0806C7C0:
	.incbin "build/assets/unknown/data_0806C7C0.bin"
	.global gUnk_0806C7C4
gUnk_0806C7C4:
	.incbin "build/assets/unknown/data_0806C7C4.bin"
	.global gUnk_0806C7CC
gUnk_0806C7CC:
	.incbin "build/assets/unknown/data_0806C7CC.bin"
	.global gUnk_0806C7D4
gUnk_0806C7D4:
	.incbin "build/assets/unknown/data_0806C7D4.bin"
	.global gUnk_0806C7DC
gUnk_0806C7DC:
	.incbin "build/assets/unknown/data_0806C7DC.bin"
	.global gUnk_0806C7E8
gUnk_0806C7E8:
	.incbin "build/assets/unknown/data_0806C7E8.bin"
	.global gUnk_0806C7F4
gUnk_0806C7F4:
	.incbin "build/assets/unknown/data_0806C7F4.bin"
	.global gUnk_0806C800
gUnk_0806C800:
	.incbin "build/assets/unknown/data_0806C800.bin"
	.global gUnk_0806C80C
gUnk_0806C80C:
	.incbin "build/assets/unknown/data_0806C80C.bin"
	.global gUnk_0806C81C
gUnk_0806C81C:
	.incbin "build/assets/unknown/data_0806C81C.bin"
	.global gUnk_0806C82C
gUnk_0806C82C:
	.incbin "build/assets/unknown/data_0806C82C.bin"
	.global gUnk_0806C83C
gUnk_0806C83C:
	.incbin "build/assets/unknown/data_0806C83C.bin"
	.global gUnk_0806C848
gUnk_0806C848:
	.incbin "build/assets/unknown/data_0806C848.bin"
