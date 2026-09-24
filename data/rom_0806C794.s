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
	.incbin "build/assets/unknown/data_0806C794.bin"
	.incbin "build/assets/unknown/data_0806C79C.bin"
	.incbin "build/assets/unknown/data_0806C7A0.bin"
	.incbin "build/assets/unknown/data_0806C7C0.bin"
	.incbin "build/assets/unknown/data_0806C7C4.bin"
	.incbin "build/assets/unknown/data_0806C7CC.bin"
	.incbin "build/assets/unknown/data_0806C7D4.bin"
	.incbin "build/assets/unknown/data_0806C7DC.bin"
	.incbin "build/assets/unknown/data_0806C7E8.bin"
	.incbin "build/assets/unknown/data_0806C7F4.bin"
	.incbin "build/assets/unknown/data_0806C800.bin"
	.incbin "build/assets/unknown/data_0806C80C.bin"
	.incbin "build/assets/unknown/data_0806C81C.bin"
	.incbin "build/assets/unknown/data_0806C82C.bin"
	.incbin "build/assets/unknown/data_0806C83C.bin"
	.incbin "build/assets/unknown/data_0806C848.bin"
