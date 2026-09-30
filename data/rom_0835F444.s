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
	.global gUnk_020269C4
gUnk_020269C4:
	.incbin "build/assets/unknown/data_0835F444.bin"
	.global gUnk_020269CC
gUnk_020269CC:
	.incbin "build/assets/unknown/data_0835F44C.bin"
	.global gUnk_020269FC
gUnk_020269FC:
	.incbin "build/assets/unknown/data_0835F47C.bin"
	.global gUnk_02026A3C
gUnk_02026A3C:
	.incbin "build/assets/unknown/data_0835F4BC.bin"
	.global gUnk_02026A64
gUnk_02026A64:
	.incbin "build/assets/unknown/data_0835F4E4.bin"
	.global gUnk_02026A84
gUnk_02026A84:
	.incbin "build/assets/unknown/data_0835F504.bin"
	.global gUnk_02026DC4
gUnk_02026DC4:
	.incbin "build/assets/unknown/data_0835F844.bin"
	.global gUnk_02026DDC
gUnk_02026DDC:
	.incbin "build/assets/unknown/data_0835F85C.bin"
	.global gUnk_02026DF4
gUnk_02026DF4:
	.incbin "build/assets/unknown/data_0835F874.bin"
	.global gUnk_02026E14
gUnk_02026E14:
	.incbin "build/assets/unknown/data_0835F894.bin"
	.global gUnk_02026E18
gUnk_02026E18:
	.incbin "build/assets/unknown/data_0835F898.bin"
	.global gUnk_02026E1C
gUnk_02026E1C:
	.incbin "build/assets/unknown/data_0835F89C.bin"


