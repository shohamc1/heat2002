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
	.incbin "build/assets/unknown/data_083CA0C4.bin"
	.incbin "build/assets/unknown/data_083CA9DC.bin"
	.incbin "build/assets/unknown/data_083CCDDC.bin"
	.incbin "build/assets/unknown/data_083CDA98.bin"
	.incbin "build/assets/unknown/data_083CEC98.bin"
	.incbin "build/assets/unknown/data_083CF7D0.bin"
	.incbin "build/assets/unknown/data_083D07EC.bin"
	.incbin "build/assets/unknown/data_083D083C.bin"
	.incbin "build/assets/unknown/data_083D2430.bin"
	.incbin "build/assets/unknown/data_083D32A8.bin"
	.incbin "build/assets/unknown/data_083D44A8.bin"
	.incbin "build/assets/unknown/data_083D4A28.bin"
	.incbin "build/assets/unknown/data_083D5FA8.bin"
	.incbin "build/assets/unknown/data_083D78A0.bin"
	.incbin "build/assets/unknown/data_083D7FE0.bin"
	.incbin "build/assets/unknown/data_083D9C80.bin"
	.incbin "build/assets/unknown/data_083DA5D0.bin"
	.incbin "build/assets/unknown/data_083DB7D0.bin"
	.incbin "build/assets/unknown/data_083DC1C0.bin"
	.incbin "build/assets/unknown/data_083DE920.bin"
	.incbin "build/assets/unknown/data_083DF630.bin"
	.incbin "build/assets/unknown/data_083E0830.bin"
	.incbin "build/assets/unknown/data_083E083C.bin"
	.incbin "build/assets/unknown/data_083E0CEC.bin"
	.incbin "build/assets/unknown/data_083E1290.bin"
	.incbin "build/assets/unknown/data_083E3BB0.bin"
	.incbin "build/assets/unknown/data_083E4A40.bin"
	.incbin "build/assets/unknown/data_083E5C40.bin"
	.incbin "build/assets/unknown/data_083E6218.bin"
	.incbin "build/assets/unknown/data_083E7918.bin"
	.incbin "build/assets/unknown/data_083E93CC.bin"
	.incbin "build/assets/unknown/data_083E996C.bin"
	.incbin "build/assets/unknown/data_083EAFAC.bin"
	.incbin "build/assets/unknown/data_083EB890.bin"
	.incbin "build/assets/unknown/data_083ECA90.bin"
	.incbin "build/assets/unknown/data_083ED040.bin"
	.incbin "build/assets/unknown/data_083EE6A0.bin"
	.incbin "build/assets/unknown/data_083EEE84.bin"
	.incbin "build/assets/unknown/data_083F0084.bin"
	.incbin "build/assets/unknown/data_083F0C48.bin"
	.incbin "build/assets/unknown/data_083F0CC4.bin"
	.incbin "build/assets/unknown/data_083F3D64.bin"
	.incbin "build/assets/unknown/data_083F5F44.bin"
	.incbin "build/assets/unknown/data_083F64A4.bin"
	.incbin "build/assets/unknown/data_083F79C4.bin"
	.incbin "build/assets/unknown/data_083F80C4.bin"
	.incbin "build/assets/unknown/data_083F92C4.bin"
	.incbin "build/assets/unknown/data_083F9B14.bin"
	.incbin "build/assets/unknown/data_083FBBF4.bin"
	.incbin "build/assets/unknown/data_083FC71C.bin"
