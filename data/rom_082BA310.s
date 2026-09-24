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
	.incbin "build/assets/graphics/rl_082BA310.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082BAAD8.bin"
	.incbin "build/assets/graphics/rl_082BACD8.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082BB63C.bin"
	.incbin "build/assets/graphics/rl_082BB83C.bin"
	.incbin "build/assets/unknown/data_082BC240.bin"
	.incbin "build/assets/graphics/rl_082BC440.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082BCD60.bin"
	.incbin "build/assets/graphics/rl_082BCF60.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082BD748.bin"
	.incbin "build/assets/graphics/rl_082BD948.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082BE1BC.bin"
	.incbin "build/assets/graphics/rl_082BE3BC.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082BECC4.bin"
	.incbin "build/assets/graphics/rl_082BEEC4.bin"
	.incbin "build/assets/unknown/data_082BF93C.bin"
	.incbin "build/assets/graphics/rl_082BFB3C.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082C0454.bin"
	.incbin "build/assets/unknown/data_082C045C.bin"
	.incbin "build/assets/graphics/rl_082C0654.bin"
	.incbin "build/assets/unknown/data_082C0F64.bin"
	.incbin "build/assets/graphics/rl_082C1164.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082C1AE0.bin"
	.incbin "build/assets/graphics/rl_082C1CE0.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082C2610.bin"
	.incbin "build/assets/graphics/rl_082C2810.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082C3150.bin"
	.incbin "build/assets/graphics/rl_082C3350.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082C3CD4.bin"
	.incbin "build/assets/graphics/rl_082C3ED4.bin"
	.incbin "build/assets/unknown/data_082C472C.bin"
	.incbin "build/assets/graphics/rl_082C492C.bin"
	.incbin "build/assets/unknown/data_082C5378.bin"
	.incbin "build/assets/graphics/rl_082C5578.bin"
	.incbin "build/assets/unknown/data_082C5F94.bin"
	.incbin "build/assets/graphics/rl_082C6194.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082C6B34.bin"
	.incbin "build/assets/graphics/rl_082C6D34.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082C76A4.bin"
	.incbin "build/assets/graphics/rl_082C78A4.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082C8228.bin"
	.incbin "build/assets/graphics/rl_082C8428.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082C8E00.bin"
	.incbin "build/assets/graphics/rl_082C9000.bin"
	.incbin "build/assets/unknown/data_082C9924.bin"
	.incbin "build/assets/graphics/rl_082C9B24.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082CA424.bin"
	.incbin "build/assets/graphics/rl_082CA624.bin"
	.incbin "build/assets/unknown/data_082CAF1C.bin"
	.incbin "build/assets/graphics/rl_082CB11C.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082CBA48.bin"
	.incbin "build/assets/graphics/rl_082CBC48.bin"
	.align 2, 0
	.global gUnk_082CC5D8
gUnk_082CC5D8:
	.incbin "build/assets/unknown/data_082CC5D8.bin"
	.incbin "build/assets/graphics/rl_082CC7D8.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082CD140.bin"
	.incbin "build/assets/graphics/rl_082CD340.bin"
	.incbin "build/assets/unknown/data_082CDD00.bin"
	.incbin "build/assets/graphics/rl_082CDF00.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082CE944.bin"
	.incbin "build/assets/graphics/rl_082CEB44.bin"
	.incbin "build/assets/unknown/data_082CF3FC.bin"
	.incbin "build/assets/graphics/rl_082CF5FC.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082CFEF0.bin"
	.incbin "build/assets/graphics/rl_082D00F0.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082D0A4C.bin"
	.incbin "build/assets/graphics/rl_082D0C4C.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082D15BC.bin"
	.incbin "build/assets/graphics/rl_082D17BC.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082D20C8.bin"
	.incbin "build/assets/graphics/rl_082D22C8.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082D2BEC.bin"
	.incbin "build/assets/graphics/rl_082D2DEC.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082D36FC.bin"
	.incbin "build/assets/graphics/rl_082D38FC.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082D4210.bin"
	.incbin "build/assets/graphics/rl_082D4410.bin"
	.incbin "build/assets/unknown/data_082D4C88.bin"
	.incbin "build/assets/graphics/rl_082D4E88.bin"
	.incbin "build/assets/unknown/data_082D57E8.bin"
	.incbin "build/assets/graphics/rl_082D59E8.bin"
	.incbin "build/assets/unknown/data_082D62F8.bin"
	.incbin "build/assets/graphics/rl_082D64F8.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082D6E3C.bin"
	.incbin "build/assets/graphics/rl_082D703C.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082D796C.bin"
	.incbin "build/assets/graphics/rl_082D7B6C.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082D84A0.bin"
	.incbin "build/assets/graphics/rl_082D86A0.bin"
	.incbin "build/assets/unknown/data_082D8FF4.bin"
	.incbin "build/assets/graphics/rl_082D91F4.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082D9B0C.bin"
	.incbin "build/assets/graphics/rl_082D9D0C.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082DA574.bin"
	.incbin "build/assets/graphics/rl_082DA774.bin"
	.incbin "build/assets/unknown/data_082DAFB4.bin"
	.incbin "build/assets/unknown/data_082DB118.bin"
	.incbin "build/assets/graphics/rl_082DB1B4.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082DBAC4.bin"
	.incbin "build/assets/graphics/rl_082DBCC4.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082DC614.bin"
	.incbin "build/assets/graphics/rl_082DC814.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082DD144.bin"
	.incbin "build/assets/graphics/rl_082DD344.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082DDC98.bin"
	.incbin "build/assets/graphics/rl_082DDE98.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082DE7C4.bin"
	.incbin "build/assets/graphics/rl_082DE9C4.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082DF2E0.bin"
	.incbin "build/assets/graphics/rl_082DF4E0.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082DFE14.bin"
	.incbin "build/assets/graphics/rl_082E0014.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082E096C.bin"
	.incbin "build/assets/graphics/rl_082E0B6C.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082E1488.bin"
	.incbin "build/assets/graphics/rl_082E1688.bin"
	.incbin "build/assets/unknown/data_082E1F90.bin"
	.incbin "build/assets/graphics/rl_082E2190.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082E2AEC.bin"
	.incbin "build/assets/graphics/rl_082E2CEC.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_082E3640.bin"
	.incbin "build/assets/graphics/rl_082E3840.bin"
	.incbin "build/assets/unknown/data_082E4128.bin"
