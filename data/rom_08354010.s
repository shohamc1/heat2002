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
	.global gUnk_0201B590
gUnk_0201B590:
	.incbin "build/assets/graphics/palettes/driver_number.pal.bin"
	.global gModule_0201B5B0
gModule_0201B5B0:
	.incbin "build/assets/graphics/rl_0832975C.bin"
	.space 1
	.global gModule_0201B6E4
gModule_0201B6E4:
	.incbin "build/assets/graphics/rl_08329890.bin"
	.space 3
	.global gModule_0201B810
gModule_0201B810:
	.incbin "build/assets/graphics/rl_083299BC.bin"
	.space 2
	.global gModule_0201B948
gModule_0201B948:
	.incbin "build/assets/graphics/rl_08329AF4.bin"
	.space 1
	.global gModule_0201BA7C
gModule_0201BA7C:
	.incbin "build/assets/graphics/rl_08329C28.bin"
	.space 3
	.global gModule_0201BBA0
gModule_0201BBA0:
	.incbin "build/assets/graphics/rl_08329D4C.bin"
	.space 3
	.global gModule_0201BCC0
gModule_0201BCC0:
	.incbin "build/assets/graphics/rl_08329E6C.bin"
	.space 2
	.global gModule_0201BDCC
gModule_0201BDCC:
	.incbin "build/assets/graphics/rl_08329F78.bin"
	.space 2
	.global gModule_0201BED8
gModule_0201BED8:
	.incbin "build/assets/graphics/rl_0832A084.bin"
	.space 3
	.global gModule_0201BFEC
gModule_0201BFEC:
	.incbin "build/assets/graphics/rl_0832A198.bin"
	.space 1
	.global gModule_0201C100
gModule_0201C100:
	.incbin "build/assets/graphics/rl_0832A2AC.bin"
	.space 3
	.global gModule_0201C210
gModule_0201C210:
	.incbin "build/assets/graphics/rl_0832A3BC.bin"
	.space 2
	.global gModule_0201C31C
gModule_0201C31C:
	.incbin "build/assets/graphics/rl_0832A4C8.bin"
	.space 1
	.global gModule_0201C428
gModule_0201C428:
	.incbin "build/assets/graphics/rl_0832A5D4.bin"
	.space 3
	.global gModule_0201C534
gModule_0201C534:
	.incbin "build/assets/graphics/rl_0832A6E0.bin"
	.global gModule_0201C63C
gModule_0201C63C:
	.incbin "build/assets/graphics/rl_0832A7E8.bin"
	.space 1
	.global gModule_0201C744
gModule_0201C744:
	.incbin "build/assets/graphics/rl_0832A8F0.bin"
	.global gModule_0201C84C
gModule_0201C84C:
	.incbin "build/assets/graphics/rl_0832A9F8.bin"
	.space 1
	.global gModule_0201C950
gModule_0201C950:
	.incbin "build/assets/graphics/rl_0832AAFC.bin"
	.space 3
	.global gModule_0201CA58
gModule_0201CA58:
	.incbin "build/assets/graphics/rl_0832AC04.bin"
	.space 3
	.global gModule_0201CB6C
gModule_0201CB6C:
	.incbin "build/assets/graphics/rl_0832AD18.bin"
	.space 3
	.global gModule_0201CC84
gModule_0201CC84:
	.incbin "build/assets/graphics/rl_0832AE30.bin"
	.space 2
	.global gModule_0201CD94
gModule_0201CD94:
	.incbin "build/assets/graphics/rl_0832AF40.bin"
	.space 2
	.global gModule_0201CEA4
gModule_0201CEA4:
	.incbin "build/assets/graphics/rl_0832B050.bin"
	.global gModule_0201CFBC
gModule_0201CFBC:
	.incbin "build/assets/graphics/rl_0832B168.bin"
	.global gModule_0201D0D0
gModule_0201D0D0:
	.incbin "build/assets/graphics/rl_0832B27C.bin"
	.global gModule_0201D1E4
gModule_0201D1E4:
	.incbin "build/assets/graphics/rl_0832B390.bin"
	.space 2
	.global gModule_0201D2F4
gModule_0201D2F4:
	.incbin "build/assets/graphics/rl_0832B4A0.bin"
	.global gModule_0201D3F8
gModule_0201D3F8:
	.incbin "build/assets/graphics/rl_0832B5A4.bin"
	.global gModule_0201D4F8
gModule_0201D4F8:
	.incbin "build/assets/graphics/rl_0832B6A4.bin"
	.space 3
	.global gModule_0201D5F8
gModule_0201D5F8:
	.incbin "build/assets/graphics/rl_0832B7A4.bin"
	.global gModule_0201D6F0
gModule_0201D6F0:
	.incbin "build/assets/graphics/rl_0832B89C.bin"
	.space 3
	.global gModule_0201D7E8
gModule_0201D7E8:
	.incbin "build/assets/graphics/rl_0832B994.bin"
	.space 2
	.incbin "build/assets/graphics/palettes/pal_0832BA88.pal.bin"
	.global gModule_0201D8FC
gModule_0201D8FC:
	.incbin "build/assets/graphics/rl_0832BAA8.bin"
	.space 2
	.global gModule_0201D958
gModule_0201D958:
	.incbin "build/assets/graphics/rl_0832BB04.bin"
	.space 1
	.global gModule_0201D9A4
gModule_0201D9A4:
	.incbin "build/assets/graphics/rl_0832BB50.bin"
	.space 3
	.global gModule_0201D9F4
gModule_0201D9F4:
	.incbin "build/assets/graphics/rl_0832BBA0.bin"
	.space 1
	.global gModule_0201DA48
gModule_0201DA48:
	.incbin "build/assets/graphics/rl_0832BBF4.bin"
	.space 3
	.global gModule_0201DAAC
gModule_0201DAAC:
	.incbin "build/assets/graphics/rl_0832BC58.bin"
	.space 3
	.global gModule_0201DB34
gModule_0201DB34:
	.incbin "build/assets/graphics/rl_0832BCE0.bin"
	.space 3
	.global gModule_0201DBC8
gModule_0201DBC8:
	.incbin "build/assets/graphics/rl_0832BD74.bin"
	.space 3
	.global gModule_0201DC5C
gModule_0201DC5C:
	.incbin "build/assets/graphics/rl_0832BE08.bin"
	.space 3
	.global gModule_0201DCF0
gModule_0201DCF0:
	.incbin "build/assets/graphics/rl_0832BE9C.bin"
	.space 2
	.global gModule_0201DD84
gModule_0201DD84:
	.incbin "build/assets/graphics/rl_0832BF30.bin"
	.space 2
	.global gModule_0201DE18
gModule_0201DE18:
	.incbin "build/assets/graphics/rl_0832BFC4.bin"
	.space 3
	.global gModule_0201DEA8
gModule_0201DEA8:
	.incbin "build/assets/graphics/rl_0832C054.bin"
	.global gModule_0201DF34
gModule_0201DF34:
	.incbin "build/assets/graphics/rl_0832C0E0.bin"
	.space 1
	.global gModule_0201DFBC
gModule_0201DFBC:
	.incbin "build/assets/graphics/rl_0832C168.bin"
	.space 1
	.global gModule_0201E040
gModule_0201E040:
	.incbin "build/assets/graphics/rl_0832C1EC.bin"
	.space 3
	.global gModule_0201E0C4
gModule_0201E0C4:
	.incbin "build/assets/graphics/rl_0832C270.bin"
	.space 3
	.global gModule_0201E144
gModule_0201E144:
	.incbin "build/assets/graphics/rl_0832C2F0.bin"
	.global gModule_0201E1C0
gModule_0201E1C0:
	.incbin "build/assets/graphics/rl_0832C36C.bin"
	.space 2
	.global gModule_0201E240
gModule_0201E240:
	.incbin "build/assets/graphics/rl_0832C3EC.bin"
	.global gModule_0201E2B8
gModule_0201E2B8:
	.incbin "build/assets/graphics/rl_0832C464.bin"
	.space 3
	.global gModule_0201E330
gModule_0201E330:
	.incbin "build/assets/graphics/rl_0832C4DC.bin"
	.space 1
	.global gModule_0201E3A4
gModule_0201E3A4:
	.incbin "build/assets/graphics/rl_0832C550.bin"
	.space 1
	.global gModule_0201E410
gModule_0201E410:
	.incbin "build/assets/graphics/rl_0832C5BC.bin"
	.space 2
	.global gModule_0201E47C
gModule_0201E47C:
	.incbin "build/assets/graphics/rl_0832C628.bin"
	.global gModule_0201E4E4
gModule_0201E4E4:
	.incbin "build/assets/graphics/rl_0832C690.bin"
	.space 1
	.global gModule_0201E544
gModule_0201E544:
	.incbin "build/assets/graphics/rl_0832C6F0.bin"
	.space 1
	.global gModule_0201E588
gModule_0201E588:
	.incbin "build/assets/graphics/rl_0832C734.bin"
	.space 2
	.global gModule_0201E5CC
gModule_0201E5CC:
	.incbin "build/assets/graphics/rl_0832C778.bin"
	.space 3
	.global gModule_0201E610
gModule_0201E610:
	.incbin "build/assets/graphics/rl_0832C7BC.bin"
	.global gModule_0201E650
gModule_0201E650:
	.incbin "build/assets/graphics/rl_0832C7FC.bin"
	.space 1
	.global gModule_0201E690
gModule_0201E690:
	.incbin "build/assets/graphics/rl_0832C83C.bin"
	.space 2
	.global gModule_0201E6E4
gModule_0201E6E4:
	.incbin "build/assets/graphics/rl_0832C890.bin"
	.space 2
	.incbin "build/assets/graphics/palettes/pal_0832C8D4.pal.bin"
	.incbin "build/assets/graphics/palettes/pal_08330D38.pal.bin"
	.global gModule_0201E768
gModule_0201E768:
	.incbin "build/assets/graphics/rl_08331380.bin"
	.space 2
	.global gModule_0201E788
gModule_0201E788:
	.incbin "build/assets/graphics/rl_083313A0.bin"
	.space 1
	.global gModule_0201E7B0
gModule_0201E7B0:
	.incbin "build/assets/graphics/rl_083313C8.bin"
	.space 1
	.global gModule_0201E7E0
gModule_0201E7E0:
	.incbin "build/assets/graphics/rl_083313F8.bin"
	.space 3
	.global gModule_0201E820
gModule_0201E820:
	.incbin "build/assets/graphics/rl_08331438.bin"
	.space 3
	.global gModule_0201E868
gModule_0201E868:
	.incbin "build/assets/graphics/rl_08331480.bin"
	.space 2
	.global gModule_0201E8B4
gModule_0201E8B4:
	.incbin "build/assets/graphics/rl_083314CC.bin"
	.space 3
	.global gModule_0201E908
gModule_0201E908:
	.incbin "build/assets/graphics/rl_08331520.bin"
	.space 2
	.global gModule_0201E95C
gModule_0201E95C:
	.incbin "build/assets/graphics/rl_08331574.bin"
	.space 2
	.global gModule_0201E9B8
gModule_0201E9B8:
	.incbin "build/assets/graphics/rl_083315D0.bin"
	.space 1
	.global gModule_0201EA20
gModule_0201EA20:
	.incbin "build/assets/graphics/rl_08331638.bin"
	.space 1
	.global gModule_0201EA90
gModule_0201EA90:
	.incbin "build/assets/graphics/rl_083316A8.bin"
	.space 1
	.global gModule_0201EB04
gModule_0201EB04:
	.incbin "build/assets/graphics/rl_0833171C.bin"
	.space 1
	.global gModule_0201EB80
gModule_0201EB80:
	.incbin "build/assets/graphics/rl_08331798.bin"
	.space 1
	.global gModule_0201EC04
gModule_0201EC04:
	.incbin "build/assets/graphics/rl_0833181C.bin"
	.space 1
	.global gModule_0201EC88
gModule_0201EC88:
	.incbin "build/assets/graphics/rl_083318A0.bin"
	.space 3
	.global gModule_0201ED0C
gModule_0201ED0C:
	.incbin "build/assets/graphics/rl_08331924.bin"
	.space 2
	.global gModule_0201ED90
gModule_0201ED90:
	.incbin "build/assets/graphics/rl_083319A8.bin"
	.space 2
	.global gModule_0201EE10
gModule_0201EE10:
	.incbin "build/assets/graphics/rl_08331A28.bin"
	.space 3
	.global gModule_0201EE90
gModule_0201EE90:
	.incbin "build/assets/graphics/rl_08331AA8.bin"
	.space 1
	.global gModule_0201EF08
gModule_0201EF08:
	.incbin "build/assets/graphics/rl_08331B20.bin"
	.global gModule_0201EF7C
gModule_0201EF7C:
	.incbin "build/assets/graphics/rl_08331B94.bin"
	.global gModule_0201EFF0
gModule_0201EFF0:
	.incbin "build/assets/graphics/rl_08331C08.bin"
	.space 1
	.global gModule_0201F064
gModule_0201F064:
	.incbin "build/assets/graphics/rl_08331C7C.bin"
	.space 3
	.global gModule_0201F0D4
gModule_0201F0D4:
	.incbin "build/assets/graphics/rl_08331CEC.bin"
	.global gModule_0201F13C
gModule_0201F13C:
	.incbin "build/assets/graphics/rl_08331D54.bin"
	.space 3
	.global gModule_0201F1A4
gModule_0201F1A4:
	.incbin "build/assets/graphics/rl_08331DBC.bin"
	.space 1
	.global gModule_0201F204
gModule_0201F204:
	.incbin "build/assets/graphics/rl_08331E1C.bin"
	.space 1
	.global gModule_0201F25C
gModule_0201F25C:
	.incbin "build/assets/graphics/rl_08331E74.bin"
	.space 2
	.global gModule_0201F2AC
gModule_0201F2AC:
	.incbin "build/assets/graphics/rl_08331EC4.bin"
	.space 2
	.global gModule_0201F2F4
gModule_0201F2F4:
	.incbin "build/assets/graphics/rl_08331F0C.bin"
	.space 2
	.global gModule_0201F334
gModule_0201F334:
	.incbin "build/assets/graphics/rl_08331F4C.bin"
	.space 1
	.global gUnk_0201F370
gUnk_0201F370:
	.incbin "build/assets/graphics/palettes/skid_smoke.pal.bin"
	.global gUnk_0201F390
gUnk_0201F390:
	.incbin "build/assets/graphics/palettes/font.pal.bin"

