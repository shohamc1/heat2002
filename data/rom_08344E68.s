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
	.global gModule_SinTable
gModule_SinTable:
	.incbin "build/assets/unknown/data_08344E68.bin"
	.global gUnk_0200C668
gUnk_0200C668:
	.4byte sub_08339FE8
	.4byte sub_0833A058
	.4byte sub_0833A078
	.4byte sub_0833A094
	.4byte sub_0833A0A8
	.4byte sub_08339FE8
	.4byte sub_08339FE8
	.4byte sub_08339FE8
	.4byte sub_08339FE8
	.4byte sub_0833A0D8
	.4byte sub_0833A0E4
	.4byte sub_0833A0F8
	.4byte sub_0833A10C
	.4byte sub_0833A13C
	.4byte sub_0833A150
	.4byte sub_0833A164
	.4byte sub_0833A178
	.4byte sub_0833A764
	.4byte sub_0833A18C
	.4byte sub_0833A778
	.4byte sub_0833A198
	.4byte sub_08339FE8
	.4byte sub_08339FE8
	.4byte sub_0833A1B0
	.4byte sub_08339FE8
	.4byte sub_08339FE8
	.4byte sub_08339FE8
	.4byte sub_0833A1C4
	.4byte sub_08339FE8
	.4byte sub_0833A6FC
	.4byte ModuleSampleFreqSet
	.4byte sub_0833A488
	.4byte ModuleFadeOutBody
	.4byte ModuleTrkVolPitSet
	.4byte sub_08339FC8
	.4byte sub_08339FB0
