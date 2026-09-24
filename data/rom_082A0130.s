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
	.incbin "build/assets/unknown/data_082A0130.bin"
	.incbin "build/assets/unknown/data_082A0820.bin"
	.incbin "build/assets/unknown/data_082A5C08.bin"
	.incbin "build/assets/unknown/data_082A5C5C.bin"
	.incbin "build/assets/unknown/data_082A9730.bin"
	.incbin "build/assets/unknown/data_082A9930.bin"
	.incbin "build/assets/unknown/data_082A9F0C.bin"
	.incbin "build/assets/unknown/data_082B0028.bin"
	.incbin "build/assets/unknown/data_082B0034.bin"
	.incbin "build/assets/unknown/data_082B01DC.bin"
	.incbin "build/assets/unknown/data_082B042C.bin"
	.incbin "build/assets/unknown/data_082B0554.bin"
	.incbin "build/assets/unknown/data_082B0574.bin"
	.incbin "build/assets/unknown/data_082B0828.bin"
	.incbin "build/assets/unknown/data_082B0834.bin"
	.incbin "build/assets/unknown/data_082B09AC.bin"
