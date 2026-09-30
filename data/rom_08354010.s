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
	.incbin "build/assets/graphics/rl_0832975C.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08329890.bin"
	.space 3
	.incbin "build/assets/graphics/rl_083299BC.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08329AF4.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08329C28.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08329D4C.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08329E6C.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08329F78.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832A084.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832A198.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832A2AC.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832A3BC.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832A4C8.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832A5D4.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832A6E0.bin"
	.incbin "build/assets/graphics/rl_0832A7E8.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832A8F0.bin"
	.incbin "build/assets/graphics/rl_0832A9F8.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832AAFC.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832AC04.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832AD18.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832AE30.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832AF40.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832B050.bin"
	.incbin "build/assets/graphics/rl_0832B168.bin"
	.incbin "build/assets/graphics/rl_0832B27C.bin"
	.incbin "build/assets/graphics/rl_0832B390.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832B4A0.bin"
	.incbin "build/assets/graphics/rl_0832B5A4.bin"
	.incbin "build/assets/graphics/rl_0832B6A4.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832B7A4.bin"
	.incbin "build/assets/graphics/rl_0832B89C.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832B994.bin"
	.space 2
	.incbin "build/assets/graphics/palettes/pal_0832BA88.pal.bin"
	.incbin "build/assets/graphics/rl_0832BAA8.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832BB04.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832BB50.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832BBA0.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832BBF4.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832BC58.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832BCE0.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832BD74.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832BE08.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832BE9C.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832BF30.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832BFC4.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832C054.bin"
	.incbin "build/assets/graphics/rl_0832C0E0.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C168.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C1EC.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832C270.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832C2F0.bin"
	.incbin "build/assets/graphics/rl_0832C36C.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832C3EC.bin"
	.incbin "build/assets/graphics/rl_0832C464.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832C4DC.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C550.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C5BC.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832C628.bin"
	.incbin "build/assets/graphics/rl_0832C690.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C6F0.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C734.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832C778.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832C7BC.bin"
	.incbin "build/assets/graphics/rl_0832C7FC.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C83C.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832C890.bin"
	.space 2
	.incbin "build/assets/graphics/palettes/pal_0832C8D4.pal.bin"
	.incbin "build/assets/graphics/palettes/pal_08330D38.pal.bin"
	.incbin "build/assets/graphics/rl_08331380.bin"
	.space 2
	.incbin "build/assets/graphics/rl_083313A0.bin"
	.space 1
	.incbin "build/assets/graphics/rl_083313C8.bin"
	.space 1
	.incbin "build/assets/graphics/rl_083313F8.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331438.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331480.bin"
	.space 2
	.incbin "build/assets/graphics/rl_083314CC.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331520.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08331574.bin"
	.space 2
	.incbin "build/assets/graphics/rl_083315D0.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08331638.bin"
	.space 1
	.incbin "build/assets/graphics/rl_083316A8.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0833171C.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08331798.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0833181C.bin"
	.space 1
	.incbin "build/assets/graphics/rl_083318A0.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331924.bin"
	.space 2
	.incbin "build/assets/graphics/rl_083319A8.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08331A28.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331AA8.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08331B20.bin"
	.incbin "build/assets/graphics/rl_08331B94.bin"
	.incbin "build/assets/graphics/rl_08331C08.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08331C7C.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331CEC.bin"
	.incbin "build/assets/graphics/rl_08331D54.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331DBC.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08331E1C.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08331E74.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08331EC4.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08331F0C.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08331F4C.bin"
	.space 1
	.global gUnk_0201F370
gUnk_0201F370:
	.incbin "build/assets/graphics/palettes/skid_smoke.pal.bin"
	.global gUnk_0201F390
gUnk_0201F390:
	.incbin "build/assets/graphics/palettes/font.pal.bin"

