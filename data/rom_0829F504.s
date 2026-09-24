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
	.incbin "build/assets/unknown/data_0829F504.bin"
	.incbin "build/assets/unknown/data_0829F518.bin"
	.incbin "build/assets/unknown/data_0829F534.bin"
	.incbin "build/assets/unknown/data_0829F548.bin"
	.incbin "build/assets/unknown/data_0829F558.bin"
	.incbin "build/assets/unknown/data_0829F570.bin"
	.incbin "build/assets/unknown/data_0829F580.bin"
	.incbin "build/assets/unknown/data_0829F590.bin"
	.incbin "build/assets/unknown/data_0829F59C.bin"
	.incbin "build/assets/unknown/data_0829F5B4.bin"
	.incbin "build/assets/unknown/data_0829F5CC.bin"
	.incbin "build/assets/unknown/data_0829F5DC.bin"
	.incbin "build/assets/unknown/data_0829F5EC.bin"
	.incbin "build/assets/unknown/data_0829F5FC.bin"
	.incbin "build/assets/unknown/data_0829F60C.bin"
	.incbin "build/assets/unknown/data_0829F624.bin"
	.incbin "build/assets/unknown/data_0829F630.bin"
	.incbin "build/assets/unknown/data_0829F64C.bin"
	.incbin "build/assets/unknown/data_0829F65C.bin"
	.incbin "build/assets/unknown/data_0829F668.bin"
	.incbin "build/assets/unknown/data_0829F674.bin"
	.incbin "build/assets/unknown/data_0829F684.bin"
	.incbin "build/assets/unknown/data_0829F694.bin"
	.incbin "build/assets/unknown/data_0829F6A0.bin"
	.incbin "build/assets/unknown/data_0829F6B8.bin"
	.incbin "build/assets/unknown/data_0829F6D0.bin"
	.incbin "build/assets/unknown/data_0829F6DC.bin"
	.incbin "build/assets/unknown/data_0829F6F0.bin"
	.incbin "build/assets/unknown/data_0829F6FC.bin"
	.incbin "build/assets/unknown/data_0829F710.bin"
	.incbin "build/assets/unknown/data_0829F720.bin"
	.incbin "build/assets/unknown/data_0829F738.bin"
	.incbin "build/assets/unknown/data_0829F748.bin"
	.incbin "build/assets/unknown/data_0829F758.bin"
	.incbin "build/assets/unknown/data_0829F764.bin"
	.incbin "build/assets/unknown/data_0829F784.bin"
	.incbin "build/assets/unknown/data_0829F798.bin"
	.incbin "build/assets/unknown/data_0829F7B8.bin"
	.incbin "build/assets/unknown/data_0829F7C4.bin"
	.incbin "build/assets/unknown/data_0829F7D0.bin"
	.incbin "build/assets/unknown/data_0829F7E4.bin"
	.incbin "build/assets/unknown/data_0829F7F4.bin"
	.incbin "build/assets/unknown/data_0829F800.bin"
	.incbin "build/assets/unknown/data_0829F814.bin"
	.incbin "build/assets/unknown/data_0829F824.bin"
	.incbin "build/assets/unknown/data_0829F838.bin"
	.incbin "build/assets/unknown/data_0829F850.bin"
	.incbin "build/assets/unknown/data_0829F860.bin"
	.incbin "build/assets/unknown/data_0829F874.bin"
	.incbin "build/assets/unknown/data_0829F88C.bin"
	.incbin "build/assets/unknown/data_0829F8A0.bin"
	.incbin "build/assets/unknown/data_0829F8B0.bin"
	.incbin "build/assets/unknown/data_0829F8BC.bin"
	.incbin "build/assets/unknown/data_0829F8C8.bin"
	.incbin "build/assets/unknown/data_0829F8D8.bin"
	.incbin "build/assets/unknown/data_0829F8E4.bin"
	.incbin "build/assets/unknown/data_0829F8F4.bin"
	.incbin "build/assets/unknown/data_0829F908.bin"
	.incbin "build/assets/unknown/data_0829F920.bin"
	.incbin "build/assets/unknown/data_0829F930.bin"
	.incbin "build/assets/unknown/data_0829F948.bin"
