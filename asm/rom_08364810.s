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
	.global _08364810
_08364810:
	.byte 0x00, 0x47, 0xC0, 0x46, 0x08, 0x47, 0xC0, 0x46, 0x10, 0x47, 0xC0, 0x46, 0x18, 0x47, 0xC0, 0x46
	.byte 0x20, 0x47, 0xC0, 0x46, 0x28, 0x47, 0xC0, 0x46, 0x30, 0x47, 0xC0, 0x46, 0x38, 0x47, 0xC0, 0x46
	.byte 0x40, 0x47, 0xC0, 0x46, 0x48, 0x47, 0xC0, 0x46, 0x50, 0x47, 0xC0, 0x46, 0x58, 0x47, 0xC0, 0x46
	.byte 0x60, 0x47, 0xC0, 0x46, 0x68, 0x47, 0xC0, 0x46, 0x70, 0x47, 0xC0, 0x46
	.incbin "build/assets/unknown/data_0836484C.bin"
	.incbin "build/assets/graphics/lz_083648A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/lz_083648F4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/lz_08364940.bin"
	.incbin "build/assets/unknown/data_08364984.bin"
