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
	.incbin "build/assets/unknown/data_083FEF08.bin"
	.incbin "build/assets/unknown/data_083FEF0C.bin"
	.incbin "build/assets/unknown/data_083FEF10.bin"
	.incbin "build/assets/unknown/data_083FEF14.bin"
	.incbin "build/assets/unknown/data_083FEF18.bin"
	.incbin "build/assets/unknown/data_083FEF1C.bin"
	.incbin "build/assets/unknown/data_083FEF20.bin"
	.incbin "build/assets/unknown/data_083FEF24.bin"
	.incbin "build/assets/unknown/data_083FEF28.bin"
	.incbin "build/assets/unknown/data_083FEF2C.bin"
	.incbin "build/assets/unknown/data_083FEF30.bin"
	.incbin "build/assets/unknown/data_083FEF34.bin"
	.incbin "build/assets/unknown/data_083FEF38.bin"
	.incbin "build/assets/unknown/data_083FEF3C.bin"
	.incbin "build/assets/unknown/data_083FEF40.bin"
	.incbin "build/assets/unknown/data_083FEF44.bin"
	.incbin "build/assets/unknown/data_083FEF48.bin"
	.incbin "build/assets/unknown/data_083FEF4C.bin"
	.incbin "build/assets/unknown/data_083FEF50.bin"
	.incbin "build/assets/unknown/data_083FEF54.bin"
	.incbin "build/assets/unknown/data_083FEF58.bin"
	.incbin "build/assets/unknown/data_083FEF5C.bin"
	.incbin "build/assets/unknown/data_083FEF60.bin"
	.incbin "build/assets/unknown/data_083FEF64.bin"
	.incbin "build/assets/unknown/data_083FEF68.bin"
	.incbin "build/assets/unknown/data_083FEF6C.bin"
	.incbin "build/assets/unknown/data_083FEF70.bin"
	.incbin "build/assets/unknown/data_083FEF74.bin"
	.incbin "build/assets/unknown/data_083FEF78.bin"
	.incbin "build/assets/unknown/data_083FEF7C.bin"
	.incbin "build/assets/unknown/data_083FEF80.bin"
	.incbin "build/assets/unknown/data_083FF004.bin"
	.incbin "build/assets/unknown/data_083FF088.bin"
	.incbin "build/assets/unknown/data_083FF10C.bin"
	.incbin "build/assets/unknown/data_083FF190.bin"
	.incbin "build/assets/unknown/data_083FF214.bin"
	.incbin "build/assets/unknown/data_083FF298.bin"
	.incbin "build/assets/unknown/data_083FF31C.bin"
	.incbin "build/assets/unknown/data_083FF3A0.bin"
	.incbin "build/assets/unknown/data_083FF424.bin"
	.incbin "build/assets/unknown/data_083FF4A8.bin"
	.incbin "build/assets/unknown/data_083FF52C.bin"
