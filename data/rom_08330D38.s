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
	.global gUnk_08330D38
gUnk_08330D38:
	.incbin "build/assets/graphics/palettes/pal_08330D38.pal.bin"
	.global gUnk_08330D58
gUnk_08330D58:
	.incbin "build/assets/graphics/palettes/pal_08330D58.pal.bin"
	.global gUnk_08330D78
gUnk_08330D78:
	.incbin "build/assets/graphics/palettes/pal_08330D78.pal.bin"
	.global gUnk_08330D98
gUnk_08330D98:
	.incbin "build/assets/graphics/palettes/pal_08330D98.pal.bin"
	.global gUnk_08330DB8
gUnk_08330DB8:
	.incbin "build/assets/graphics/palettes/pal_08330DB8.pal.bin"
	.global gUnk_08330DD8
gUnk_08330DD8:
	.incbin "build/assets/graphics/palettes/pal_08330DD8.pal.bin"
	.global gUnk_08330DF8
gUnk_08330DF8:
	.incbin "build/assets/graphics/palettes/pal_08330DF8.pal.bin"
	.global gUnk_08330E18
gUnk_08330E18:
	.incbin "build/assets/graphics/palettes/pal_08330E18.pal.bin"
	.global gUnk_08330E38
gUnk_08330E38:
	.incbin "build/assets/graphics/palettes/pal_08330E38.pal.bin"
	.global gUnk_08330E58
gUnk_08330E58:
	.incbin "build/assets/graphics/palettes/pal_08330E58.pal.bin"
	.global gUnk_08330E78
gUnk_08330E78:
	.incbin "build/assets/graphics/palettes/pal_08330E78.pal.bin"
	.global gUnk_08330E98
gUnk_08330E98:
	.incbin "build/assets/graphics/palettes/pal_08330E98.pal.bin"
	.global gUnk_08330EB8
gUnk_08330EB8:
	.incbin "build/assets/graphics/palettes/pal_08330EB8.pal.bin"
	.global gUnk_08330ED8
gUnk_08330ED8:
	.incbin "build/assets/graphics/palettes/pal_08330ED8.pal.bin"
	.global gUnk_08330EF8
gUnk_08330EF8:
	.incbin "build/assets/graphics/palettes/pal_08330EF8.pal.bin"
	.global gUnk_08330F18
gUnk_08330F18:
	.incbin "build/assets/graphics/palettes/pal_08330F18.pal.bin"
	.global gUnk_08330F38
gUnk_08330F38:
	.incbin "build/assets/graphics/palettes/pal_08330F38.pal.bin"
	.global gUnk_08330F58
gUnk_08330F58:
	.incbin "build/assets/graphics/palettes/pal_08330F58.pal.bin"
	.global gUnk_08330F78
gUnk_08330F78:
	.incbin "build/assets/graphics/palettes/pal_08330F78.pal.bin"
	.global gUnk_08330F98
gUnk_08330F98:
	.incbin "build/assets/graphics/palettes/pal_08330F98.pal.bin"
	.global gUnk_08330FB8
gUnk_08330FB8:
	.incbin "build/assets/graphics/palettes/pal_08330FB8.pal.bin"
	.global gUnk_08330FD8
gUnk_08330FD8:
	.incbin "build/assets/graphics/palettes/pal_08330FD8.pal.bin"
	.global gUnk_08330FF8
gUnk_08330FF8:
	.incbin "build/assets/graphics/palettes/pal_08330FF8.pal.bin"
	.global gUnk_08331018
gUnk_08331018:
	.incbin "build/assets/graphics/palettes/pal_08331018.pal.bin"
	.global gUnk_08331038
gUnk_08331038:
	.incbin "build/assets/graphics/palettes/pal_08331038.pal.bin"
	.global gUnk_08331058
gUnk_08331058:
	.incbin "build/assets/graphics/palettes/pal_08331058.pal.bin"
	.global gUnk_08331078
gUnk_08331078:
	.incbin "build/assets/graphics/palettes/pal_08331078.pal.bin"
	.global gUnk_08331098
gUnk_08331098:
	.incbin "build/assets/graphics/rl_08331098.bin"
	.align 2, 0
	.global gUnk_083310A8
gUnk_083310A8:
	.incbin "build/assets/graphics/rl_083310A8.bin"
	.align 2, 0
	.global gUnk_083310B8
gUnk_083310B8:
	.incbin "build/assets/graphics/rl_083310B8.bin"
	.align 2, 0
	.global gUnk_083310C8
gUnk_083310C8:
	.incbin "build/assets/graphics/rl_083310C8.bin"
	.align 2, 0
	.global gUnk_083310D8
gUnk_083310D8:
	.incbin "build/assets/graphics/rl_083310D8.bin"
	.align 2, 0
	.global gUnk_083310E8
gUnk_083310E8:
	.incbin "build/assets/graphics/rl_083310E8.bin"
	.align 2, 0
	.global gUnk_083310F8
gUnk_083310F8:
	.incbin "build/assets/graphics/rl_083310F8.bin"
	.align 2, 0
	.global gUnk_08331108
gUnk_08331108:
	.incbin "build/assets/graphics/rl_08331108.bin"
	.align 2, 0
	.global gUnk_08331118
gUnk_08331118:
	.incbin "build/assets/graphics/rl_08331118.bin"
	.align 2, 0
	.global gUnk_08331128
gUnk_08331128:
	.incbin "build/assets/graphics/rl_08331128.bin"
	.align 2, 0
	.global gUnk_08331138
gUnk_08331138:
	.incbin "build/assets/graphics/rl_08331138.bin"
	.align 2, 0
	.global gUnk_08331148
gUnk_08331148:
	.incbin "build/assets/graphics/rl_08331148.bin"
	.align 2, 0
	.global gUnk_08331158
gUnk_08331158:
	.incbin "build/assets/graphics/rl_08331158.bin"
	.align 2, 0
	.global gUnk_08331164
gUnk_08331164:
	.incbin "build/assets/graphics/rl_08331164.bin"
	.align 2, 0
	.global gUnk_08331170
gUnk_08331170:
	.incbin "build/assets/graphics/rl_08331170.bin"
	.align 2, 0
	.global gUnk_0833117C
gUnk_0833117C:
	.incbin "build/assets/graphics/rl_0833117C.bin"
	.align 2, 0
