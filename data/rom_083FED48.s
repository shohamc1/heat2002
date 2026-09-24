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
	.incbin "build/assets/unknown/data_083FED48.bin"
	.incbin "build/assets/unknown/data_083FED4C.bin"
	.incbin "build/assets/unknown/data_083FED50.bin"
	.incbin "build/assets/unknown/data_083FED54.bin"
	.incbin "build/assets/unknown/data_083FED58.bin"
	.incbin "build/assets/unknown/data_083FED5C.bin"
	.incbin "build/assets/unknown/data_083FED60.bin"
	.incbin "build/assets/unknown/data_083FED64.bin"
	.incbin "build/assets/unknown/data_083FED68.bin"
	.incbin "build/assets/unknown/data_083FED6C.bin"
	.incbin "build/assets/unknown/data_083FED70.bin"
	.incbin "build/assets/unknown/data_083FED74.bin"
	.incbin "build/assets/unknown/data_083FED78.bin"
	.incbin "build/assets/unknown/data_083FED7C.bin"
	.incbin "build/assets/unknown/data_083FED80.bin"
	.incbin "build/assets/unknown/data_083FED84.bin"
	.incbin "build/assets/unknown/data_083FED88.bin"
	.incbin "build/assets/unknown/data_083FED8C.bin"
	.incbin "build/assets/unknown/data_083FED90.bin"
	.incbin "build/assets/unknown/data_083FED94.bin"
	.incbin "build/assets/unknown/data_083FED98.bin"
	.incbin "build/assets/unknown/data_083FED9C.bin"
	.incbin "build/assets/unknown/data_083FEDA0.bin"
	.incbin "build/assets/unknown/data_083FEDA4.bin"
	.incbin "build/assets/unknown/data_083FEDA8.bin"
	.incbin "build/assets/unknown/data_083FEDAC.bin"
	.incbin "build/assets/unknown/data_083FEDB0.bin"
	.incbin "build/assets/unknown/data_083FEDB4.bin"
	.incbin "build/assets/unknown/data_083FEDB8.bin"
	.incbin "build/assets/unknown/data_083FEDBC.bin"
	.incbin "build/assets/unknown/data_083FEDC0.bin"
	.incbin "build/assets/unknown/data_083FEDC4.bin"
	.incbin "build/assets/unknown/data_083FEDC8.bin"
	.incbin "build/assets/unknown/data_083FEDCC.bin"
	.incbin "build/assets/unknown/data_083FEDD0.bin"
	.incbin "build/assets/unknown/data_083FEDD4.bin"
	.incbin "build/assets/unknown/data_083FEDD8.bin"
	.incbin "build/assets/unknown/data_083FEDDC.bin"
	.incbin "build/assets/unknown/data_083FEDE0.bin"
	.incbin "build/assets/unknown/data_083FEDE4.bin"
	.incbin "build/assets/unknown/data_083FEDE8.bin"
	.incbin "build/assets/unknown/data_083FEDEC.bin"
	.incbin "build/assets/unknown/data_083FEDF0.bin"
	.incbin "build/assets/unknown/data_083FEDF4.bin"
	.incbin "build/assets/unknown/data_083FEDF8.bin"
	.incbin "build/assets/unknown/data_083FEDFC.bin"
	.incbin "build/assets/unknown/data_083FEE00.bin"
	.incbin "build/assets/unknown/data_083FEE04.bin"
	.incbin "build/assets/unknown/data_083FEE08.bin"
	.incbin "build/assets/unknown/data_083FEE0C.bin"
	.incbin "build/assets/unknown/data_083FEE10.bin"
	.incbin "build/assets/unknown/data_083FEE14.bin"
	.incbin "build/assets/unknown/data_083FEE18.bin"
	.incbin "build/assets/unknown/data_083FEE1C.bin"
	.incbin "build/assets/unknown/data_083FEE20.bin"
	.incbin "build/assets/unknown/data_083FEE24.bin"
	.incbin "build/assets/unknown/data_083FEE28.bin"
	.incbin "build/assets/unknown/data_083FEE2C.bin"
	.incbin "build/assets/unknown/data_083FEE30.bin"
	.incbin "build/assets/unknown/data_083FEE34.bin"
	.incbin "build/assets/unknown/data_083FEE38.bin"
	.incbin "build/assets/unknown/data_083FEE48.bin"
	.incbin "build/assets/unknown/data_083FEE58.bin"
	.incbin "build/assets/unknown/data_083FEE68.bin"
	.incbin "build/assets/unknown/data_083FEE78.bin"
	.incbin "build/assets/unknown/data_083FEE88.bin"
	.incbin "build/assets/unknown/data_083FEE98.bin"
	.incbin "build/assets/unknown/data_083FEEA8.bin"
	.incbin "build/assets/unknown/data_083FEEB8.bin"
	.incbin "build/assets/unknown/data_083FEEC8.bin"
	.incbin "build/assets/unknown/data_083FEED8.bin"
	.incbin "build/assets/unknown/data_083FEEE8.bin"
