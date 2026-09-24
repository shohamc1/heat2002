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
	.incbin "build/assets/unknown/data_0829EF78.bin"
	.incbin "build/assets/unknown/data_0829EFD8.bin"
	.incbin "build/assets/unknown/data_0829F038.bin"
	.incbin "build/assets/unknown/data_0829F088.bin"
	.incbin "build/assets/unknown/data_0829F0D8.bin"
	.incbin "build/assets/unknown/data_0829F128.bin"
	.incbin "build/assets/unknown/data_0829F138.bin"
	.incbin "build/assets/unknown/data_0829F140.bin"
	.incbin "build/assets/unknown/data_0829F15C.bin"
	.incbin "build/assets/unknown/data_0829F174.bin"
	.incbin "build/assets/unknown/data_0829F180.bin"
	.incbin "build/assets/unknown/data_0829F190.bin"
	.incbin "build/assets/unknown/data_0829F1A0.bin"
	.incbin "build/assets/unknown/data_0829F1B8.bin"
	.incbin "build/assets/unknown/data_0829F1C8.bin"
	.incbin "build/assets/unknown/data_0829F1D0.bin"
	.incbin "build/assets/unknown/data_0829F1E0.bin"
	.incbin "build/assets/unknown/data_0829F1F4.bin"
	.incbin "build/assets/unknown/data_0829F208.bin"
	.incbin "build/assets/unknown/data_0829F220.bin"
	.incbin "build/assets/unknown/data_0829F224.bin"
	.incbin "build/assets/unknown/data_0829F228.bin"
	.incbin "build/assets/unknown/data_0829F22C.bin"
