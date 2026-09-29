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
	.global gUnk_082BA310
gUnk_082BA310:
	.incbin "build/assets/graphics/rl_082BA310.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082BAAD8.pal.bin"
	.global gUnk_082BACD8
gUnk_082BACD8:
	.incbin "build/assets/graphics/rl_082BACD8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082BB63C.pal.bin"
	.global gUnk_082BB83C
gUnk_082BB83C:
	.incbin "build/assets/graphics/rl_082BB83C.bin"
	.incbin "build/assets/graphics/palettes/pal_082BC240.pal.bin"
	.global gUnk_082BC440
gUnk_082BC440:
	.incbin "build/assets/graphics/rl_082BC440.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082BCD60.pal.bin"
	.global gUnk_082BCF60
gUnk_082BCF60:
	.incbin "build/assets/graphics/rl_082BCF60.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082BD748.pal.bin"
	.global gUnk_082BD948
gUnk_082BD948:
	.incbin "build/assets/graphics/rl_082BD948.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082BE1BC.pal.bin"
	.global gUnk_082BE3BC
gUnk_082BE3BC:
	.incbin "build/assets/graphics/rl_082BE3BC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082BECC4.pal.bin"
	.global gUnk_082BEEC4
gUnk_082BEEC4:
	.incbin "build/assets/graphics/rl_082BEEC4.bin"
	.incbin "build/assets/graphics/palettes/pal_082BF93C.pal.bin"
	.global gUnk_082BFB3C
gUnk_082BFB3C:
	.incbin "build/assets/graphics/rl_082BFB3C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082C0454.pal.bin"
	.global gUnk_082C0654
gUnk_082C0654:
	.incbin "build/assets/graphics/rl_082C0654.bin"
	.incbin "build/assets/graphics/palettes/pal_082C0F64.pal.bin"
	.global gUnk_082C1164
gUnk_082C1164:
	.incbin "build/assets/graphics/rl_082C1164.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082C1AE0.pal.bin"
	.global gUnk_082C1CE0
gUnk_082C1CE0:
	.incbin "build/assets/graphics/rl_082C1CE0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082C2610.pal.bin"
	.global gUnk_082C2810
gUnk_082C2810:
	.incbin "build/assets/graphics/rl_082C2810.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082C3150.pal.bin"
	.global gUnk_082C3350
gUnk_082C3350:
	.incbin "build/assets/graphics/rl_082C3350.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082C3CD4.pal.bin"
	.global gUnk_082C3ED4
gUnk_082C3ED4:
	.incbin "build/assets/graphics/rl_082C3ED4.bin"
	.incbin "build/assets/graphics/palettes/pal_082C472C.pal.bin"
	.global gUnk_082C492C
gUnk_082C492C:
	.incbin "build/assets/graphics/rl_082C492C.bin"
	.incbin "build/assets/graphics/palettes/pal_082C5378.pal.bin"
	.global gUnk_082C5578
gUnk_082C5578:
	.incbin "build/assets/graphics/rl_082C5578.bin"
	.incbin "build/assets/graphics/palettes/pal_082C5F94.pal.bin"
	.global gUnk_082C6194
gUnk_082C6194:
	.incbin "build/assets/graphics/rl_082C6194.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082C6B34.pal.bin"
	.global gUnk_082C6D34
gUnk_082C6D34:
	.incbin "build/assets/graphics/rl_082C6D34.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082C76A4.pal.bin"
	.global gUnk_082C78A4
gUnk_082C78A4:
	.incbin "build/assets/graphics/rl_082C78A4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082C8228.pal.bin"
	.global gUnk_082C8428
gUnk_082C8428:
	.incbin "build/assets/graphics/rl_082C8428.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082C8E00.pal.bin"
	.global gUnk_082C9000
gUnk_082C9000:
	.incbin "build/assets/graphics/rl_082C9000.bin"
	.incbin "build/assets/graphics/palettes/pal_082C9924.pal.bin"
	.global gUnk_082C9B24
gUnk_082C9B24:
	.incbin "build/assets/graphics/rl_082C9B24.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082CA424.pal.bin"
	.global gUnk_082CA624
gUnk_082CA624:
	.incbin "build/assets/graphics/rl_082CA624.bin"
	.incbin "build/assets/graphics/palettes/pal_082CAF1C.pal.bin"
	.global gUnk_082CB11C
gUnk_082CB11C:
	.incbin "build/assets/graphics/rl_082CB11C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082CBA48.pal.bin"
	.global gUnk_082CBC48
gUnk_082CBC48:
	.incbin "build/assets/graphics/rl_082CBC48.bin"
	.align 2, 0
	.global gUnk_082CC5D8
gUnk_082CC5D8:
	.incbin "build/assets/graphics/palettes/driver_car.pal.bin"
	.global gUnk_082CC7D8
gUnk_082CC7D8:
	.incbin "build/assets/graphics/rl_082CC7D8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082CD140.pal.bin"
	.global gUnk_082CD340
gUnk_082CD340:
	.incbin "build/assets/graphics/rl_082CD340.bin"
	.incbin "build/assets/graphics/palettes/pal_082CDD00.pal.bin"
	.global gUnk_082CDF00
gUnk_082CDF00:
	.incbin "build/assets/graphics/rl_082CDF00.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082CE944.pal.bin"
	.global gUnk_082CEB44
gUnk_082CEB44:
	.incbin "build/assets/graphics/rl_082CEB44.bin"
	.incbin "build/assets/graphics/palettes/pal_082CF3FC.pal.bin"
	.global gUnk_082CF5FC
gUnk_082CF5FC:
	.incbin "build/assets/graphics/rl_082CF5FC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082CFEF0.pal.bin"
	.global gUnk_082D00F0
gUnk_082D00F0:
	.incbin "build/assets/graphics/rl_082D00F0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082D0A4C.pal.bin"
	.global gUnk_082D0C4C
gUnk_082D0C4C:
	.incbin "build/assets/graphics/rl_082D0C4C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082D15BC.pal.bin"
	.global gUnk_082D17BC
gUnk_082D17BC:
	.incbin "build/assets/graphics/rl_082D17BC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082D20C8.pal.bin"
	.global gUnk_082D22C8
gUnk_082D22C8:
	.incbin "build/assets/graphics/rl_082D22C8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082D2BEC.pal.bin"
	.global gUnk_082D2DEC
gUnk_082D2DEC:
	.incbin "build/assets/graphics/rl_082D2DEC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082D36FC.pal.bin"
	.global gUnk_082D38FC
gUnk_082D38FC:
	.incbin "build/assets/graphics/rl_082D38FC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082D4210.pal.bin"
	.global gUnk_082D4410
gUnk_082D4410:
	.incbin "build/assets/graphics/rl_082D4410.bin"
	.incbin "build/assets/graphics/palettes/pal_082D4C88.pal.bin"
	.global gUnk_082D4E88
gUnk_082D4E88:
	.incbin "build/assets/graphics/rl_082D4E88.bin"
	.incbin "build/assets/graphics/palettes/pal_082D57E8.pal.bin"
	.global gUnk_082D59E8
gUnk_082D59E8:
	.incbin "build/assets/graphics/rl_082D59E8.bin"
	.incbin "build/assets/graphics/palettes/pal_082D62F8.pal.bin"
	.global gUnk_082D64F8
gUnk_082D64F8:
	.incbin "build/assets/graphics/rl_082D64F8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082D6E3C.pal.bin"
	.global gUnk_082D703C
gUnk_082D703C:
	.incbin "build/assets/graphics/rl_082D703C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082D796C.pal.bin"
	.global gUnk_082D7B6C
gUnk_082D7B6C:
	.incbin "build/assets/graphics/rl_082D7B6C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082D84A0.pal.bin"
	.global gUnk_082D86A0
gUnk_082D86A0:
	.incbin "build/assets/graphics/rl_082D86A0.bin"
	.incbin "build/assets/graphics/palettes/pal_082D8FF4.pal.bin"
	.global gUnk_082D91F4
gUnk_082D91F4:
	.incbin "build/assets/graphics/rl_082D91F4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082D9B0C.pal.bin"
	.global gUnk_082D9D0C
gUnk_082D9D0C:
	.incbin "build/assets/graphics/rl_082D9D0C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082DA574.pal.bin"
	.global gUnk_082DA774
gUnk_082DA774:
	.incbin "build/assets/graphics/rl_082DA774.bin"
	.incbin "build/assets/graphics/palettes/pal_082DAFB4.pal.bin"
	.global gUnk_082DB1B4
gUnk_082DB1B4:
	.incbin "build/assets/graphics/rl_082DB1B4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082DBAC4.pal.bin"
	.global gUnk_082DBCC4
gUnk_082DBCC4:
	.incbin "build/assets/graphics/rl_082DBCC4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082DC614.pal.bin"
	.global gUnk_082DC814
gUnk_082DC814:
	.incbin "build/assets/graphics/rl_082DC814.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082DD144.pal.bin"
	.global gUnk_082DD344
gUnk_082DD344:
	.incbin "build/assets/graphics/rl_082DD344.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082DDC98.pal.bin"
	.global gUnk_082DDE98
gUnk_082DDE98:
	.incbin "build/assets/graphics/rl_082DDE98.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082DE7C4.pal.bin"
	.global gUnk_082DE9C4
gUnk_082DE9C4:
	.incbin "build/assets/graphics/rl_082DE9C4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082DF2E0.pal.bin"
	.global gUnk_082DF4E0
gUnk_082DF4E0:
	.incbin "build/assets/graphics/rl_082DF4E0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082DFE14.pal.bin"
	.global gUnk_082E0014
gUnk_082E0014:
	.incbin "build/assets/graphics/rl_082E0014.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082E096C.pal.bin"
	.global gUnk_082E0B6C
gUnk_082E0B6C:
	.incbin "build/assets/graphics/rl_082E0B6C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082E1488.pal.bin"
	.global gUnk_082E1688
gUnk_082E1688:
	.incbin "build/assets/graphics/rl_082E1688.bin"
	.incbin "build/assets/graphics/palettes/pal_082E1F90.pal.bin"
	.global gUnk_082E2190
gUnk_082E2190:
	.incbin "build/assets/graphics/rl_082E2190.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082E2AEC.pal.bin"
	.global gUnk_082E2CEC
gUnk_082E2CEC:
	.incbin "build/assets/graphics/rl_082E2CEC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/palettes/pal_082E3640.pal.bin"
	.global gUnk_082E3840
gUnk_082E3840:
	.incbin "build/assets/graphics/rl_082E3840.bin"
	.incbin "build/assets/graphics/palettes/pal_082E4128.pal.bin"
