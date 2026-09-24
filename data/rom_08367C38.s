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
	.incbin "build/assets/unknown/data_08367C38.bin"
	.incbin "build/assets/unknown/data_08367C4C.bin"
	.incbin "build/assets/unknown/data_08367C60.bin"
	.incbin "build/assets/unknown/data_08367C74.bin"
	.incbin "build/assets/unknown/data_08367C88.bin"
	.incbin "build/assets/unknown/data_08367C9C.bin"
	.incbin "build/assets/unknown/data_08367CB0.bin"
	.incbin "build/assets/unknown/data_08367CC4.bin"
	.incbin "build/assets/unknown/data_08367CD8.bin"
	.incbin "build/assets/unknown/data_08367CEC.bin"
	.incbin "build/assets/unknown/data_08367D00.bin"
	.incbin "build/assets/unknown/data_08367D14.bin"
	.incbin "build/assets/unknown/data_08367D28.bin"
	.incbin "build/assets/unknown/data_08367D3C.bin"
	.incbin "build/assets/unknown/data_08367D50.bin"
	.incbin "build/assets/unknown/data_08367D64.bin"
	.incbin "build/assets/unknown/data_08367D78.bin"
	.incbin "build/assets/unknown/data_08367D8C.bin"
	.incbin "build/assets/unknown/data_08367DA0.bin"
	.incbin "build/assets/unknown/data_08367DB4.bin"
	.incbin "build/assets/unknown/data_08367DC8.bin"
	.incbin "build/assets/unknown/data_08367DDC.bin"
	.incbin "build/assets/unknown/data_08367DF0.bin"
	.incbin "build/assets/unknown/data_08367E04.bin"
	.incbin "build/assets/unknown/data_08367E18.bin"
	.incbin "build/assets/unknown/data_08367E2C.bin"
	.incbin "build/assets/unknown/data_08367E40.bin"
	.incbin "build/assets/unknown/data_08367E54.bin"
	.incbin "build/assets/unknown/data_08367E68.bin"
	.incbin "build/assets/unknown/data_08367E7C.bin"
	.incbin "build/assets/unknown/data_08367E90.bin"
	.incbin "build/assets/unknown/data_08367EA4.bin"
	.incbin "build/assets/unknown/data_08367EB8.bin"
	.incbin "build/assets/unknown/data_08367ECC.bin"
	.incbin "build/assets/unknown/data_08367EE0.bin"
	.incbin "build/assets/unknown/data_08367EF4.bin"
	.incbin "build/assets/unknown/data_08367F08.bin"
	.incbin "build/assets/unknown/data_08367F1C.bin"
	.incbin "build/assets/unknown/data_08367F30.bin"
	.incbin "build/assets/unknown/data_08367F44.bin"
	.incbin "build/assets/unknown/data_08367F58.bin"
	.incbin "build/assets/unknown/data_08367F6C.bin"
	.incbin "build/assets/unknown/data_08367F80.bin"
	.incbin "build/assets/unknown/data_08367F94.bin"
	.incbin "build/assets/unknown/data_08367FA8.bin"
