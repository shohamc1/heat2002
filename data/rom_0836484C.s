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
	.4byte IslandVBlankIntr
	.4byte IslandDummyIntr
	.4byte IslandDummyIntr
	.4byte IslandDummyIntr
	.4byte IslandDummyIntr
	.4byte IslandDummyIntr
	.4byte sub_08364730
	.4byte sub_08364730
	.4byte IslandDummyIntr
	.4byte IslandDummyIntr
	.4byte IslandDummyIntr
	.4byte IslandDummyIntr
	.4byte IslandDummyIntr
	.4byte IslandDummyIntr
	.4byte 0x4A424741
	.4byte 0
	.global gUnk_083648A8
gUnk_083648A8:
	.incbin "build/assets/graphics/lz_083648A8.bin"
	.align 2, 0
	.global gUnk_083648F4
gUnk_083648F4:
	.incbin "build/assets/graphics/lz_083648F4.bin"
	.align 2, 0
	.global gUnk_08364940
gUnk_08364940:
	.incbin "build/assets/graphics/lz_08364940.bin"
	.global gUnk_02000A9C
gUnk_02000A9C:
	.incbin "build/assets/unknown/data_08364984.bin"
	.global gUnk_08364ABC
gUnk_08364ABC:
	.4byte gUnk_083648A8
	.4byte gUnk_083648F4
	.4byte gUnk_08364940
