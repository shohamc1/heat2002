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
	.global gUnk_0836484C
gUnk_0836484C:
	@ where each 32 KB chunk of the high module lands
	.4byte gHighModule
	.4byte gHighModule + 0x8000
	.4byte gHighModule + 0x10000
	.4byte gHighModule + 0x18000
	.4byte gHighModule + 0x20000
	.4byte gHighModule + 0x28000
	.4byte gHighModule + 0x30000
	.4byte sub_08364190
	.4byte sub_0836418C
	.4byte sub_0836418C
	.4byte sub_0836418C
	.4byte sub_0836418C
	.4byte sub_0836418C
	.4byte sub_08364730
	.4byte sub_08364730
	.4byte sub_0836418C
	.4byte sub_0836418C
	.4byte sub_0836418C
	.4byte sub_0836418C
	.4byte sub_0836418C
	.4byte sub_0836418C
	.4byte 0x4A424741
	.4byte 0
	.incbin "build/assets/graphics/lz_083648A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/lz_083648F4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/lz_08364940.bin"
	.incbin "build/assets/unknown/data_08364984.bin"
