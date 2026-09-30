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
	.global gModule_02025220
gModule_02025220:
	.incbin "build/assets/unknown/data_0835DCA0.bin"
	.global gModule_0202522C
gModule_0202522C:
	.incbin "build/assets/unknown/data_0835DCAC.bin"
	.global gUnk_02025230
gUnk_02025230:
	.incbin "build/assets/unknown/data_0835DCB0.bin"
	.global gUnk_02025234
gUnk_02025234:
	.incbin "build/assets/unknown/data_0835DCB4.bin", 0, 0xBEC
	.global gUnk_02025E20
gUnk_02025E20:
	.incbin "build/assets/unknown/data_0835DCB4.bin", 0xBEC, 0xBA0
