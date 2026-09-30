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
	.incbin "build/assets/graphics/rl_0831C898.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0831C8D4.bin"
	.incbin "build/assets/graphics/rl_0831C918.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0831C960.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0831C9A8.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0831C9F0.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0831CA38.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CA80.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CAC8.bin"
	.incbin "build/assets/graphics/rl_0831CB04.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0831CB4C.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CB94.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CBDC.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CC24.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CC6C.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CCB4.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CCFC.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CD44.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CD8C.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CDD4.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CE1C.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CE64.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CEAC.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CEF4.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CF3C.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CF84.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831CFCC.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831D014.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831D05C.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0831D0A4.bin"
	.space 3
