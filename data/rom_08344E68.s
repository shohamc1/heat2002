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
	.incbin "build/assets/unknown/data_08344E68.bin"
	.incbin "build/assets/unknown/data_08349780.bin"
	.incbin "build/assets/unknown/data_0835041C.bin"
	.incbin "build/assets/unknown/data_08350528.bin"
	.incbin "build/assets/unknown/data_0835081C.bin"
	.incbin "build/assets/unknown/data_08350830.bin"
	.incbin "build/assets/unknown/data_08350834.bin"
	.incbin "build/assets/unknown/data_0835085C.bin"
	.incbin "build/assets/unknown/data_08350C20.bin"
	.incbin "build/assets/unknown/data_08351780.bin"
	.incbin "build/assets/unknown/data_08358070.bin"
	.incbin "build/assets/unknown/data_08359780.bin"
	.incbin "build/assets/unknown/data_08360000.bin"
	.incbin "build/assets/unknown/data_0836019C.bin"
	.incbin "build/assets/unknown/data_08360860.bin"
	.incbin "build/assets/unknown/data_08360888.bin"
	.incbin "build/assets/unknown/data_083608F8.bin"
	.incbin "build/assets/unknown/data_08360C2C.bin"
	.incbin "build/assets/unknown/data_08361780.bin"
