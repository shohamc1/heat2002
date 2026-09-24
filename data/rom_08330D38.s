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
	.incbin "build/assets/unknown/data_08330D38.bin"
	.incbin "build/assets/unknown/data_08330D58.bin"
	.incbin "build/assets/unknown/data_08330D78.bin"
	.incbin "build/assets/unknown/data_08330D98.bin"
	.incbin "build/assets/unknown/data_08330DB8.bin"
	.incbin "build/assets/unknown/data_08330DD8.bin"
	.incbin "build/assets/unknown/data_08330DF8.bin"
	.incbin "build/assets/unknown/data_08330E18.bin"
	.incbin "build/assets/unknown/data_08330E38.bin"
	.incbin "build/assets/unknown/data_08330E58.bin"
	.incbin "build/assets/unknown/data_08330E78.bin"
	.incbin "build/assets/unknown/data_08330E98.bin"
	.incbin "build/assets/unknown/data_08330EB8.bin"
	.incbin "build/assets/unknown/data_08330ED8.bin"
	.incbin "build/assets/unknown/data_08330EF8.bin"
	.incbin "build/assets/unknown/data_08330F18.bin"
	.incbin "build/assets/unknown/data_08330F38.bin"
	.incbin "build/assets/unknown/data_08330F58.bin"
	.incbin "build/assets/unknown/data_08330F78.bin"
	.incbin "build/assets/unknown/data_08330F98.bin"
	.incbin "build/assets/unknown/data_08330FB8.bin"
	.incbin "build/assets/unknown/data_08330FD8.bin"
	.incbin "build/assets/unknown/data_08330FF8.bin"
	.incbin "build/assets/unknown/data_08331018.bin"
	.incbin "build/assets/unknown/data_08331038.bin"
	.incbin "build/assets/unknown/data_08331058.bin"
	.incbin "build/assets/unknown/data_08331078.bin"
	.incbin "build/assets/graphics/rl_08331098.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083310A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083310B8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083310C8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083310D8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083310E8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083310F8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331108.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331118.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331128.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331138.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331148.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331158.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331164.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08331170.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0833117C.bin"
	.align 2, 0
