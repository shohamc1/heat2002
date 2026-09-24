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
	.global gUnk_083FED48
gUnk_083FED48:
	.incbin "build/assets/unknown/data_083FED48.bin"
	.global gUnk_083FED4C
gUnk_083FED4C:
	.incbin "build/assets/unknown/data_083FED4C.bin"
	.global gUnk_083FED50
gUnk_083FED50:
	.incbin "build/assets/unknown/data_083FED50.bin"
	.global gUnk_083FED54
gUnk_083FED54:
	.incbin "build/assets/unknown/data_083FED54.bin"
	.global gUnk_083FED58
gUnk_083FED58:
	.incbin "build/assets/unknown/data_083FED58.bin"
	.global gUnk_083FED5C
gUnk_083FED5C:
	.incbin "build/assets/unknown/data_083FED5C.bin"
	.global gUnk_083FED60
gUnk_083FED60:
	.incbin "build/assets/unknown/data_083FED60.bin"
	.global gUnk_083FED64
gUnk_083FED64:
	.incbin "build/assets/unknown/data_083FED64.bin"
	.global gUnk_083FED68
gUnk_083FED68:
	.incbin "build/assets/unknown/data_083FED68.bin"
	.global gUnk_083FED6C
gUnk_083FED6C:
	.incbin "build/assets/unknown/data_083FED6C.bin"
	.global gUnk_083FED70
gUnk_083FED70:
	.incbin "build/assets/unknown/data_083FED70.bin"
	.global gUnk_083FED74
gUnk_083FED74:
	.incbin "build/assets/unknown/data_083FED74.bin"
	.global gUnk_083FED78
gUnk_083FED78:
	.incbin "build/assets/unknown/data_083FED78.bin"
	.global gUnk_083FED7C
gUnk_083FED7C:
	.incbin "build/assets/unknown/data_083FED7C.bin"
	.global gUnk_083FED80
gUnk_083FED80:
	.incbin "build/assets/unknown/data_083FED80.bin"
	.global gUnk_083FED84
gUnk_083FED84:
	.incbin "build/assets/unknown/data_083FED84.bin"
	.global gUnk_083FED88
gUnk_083FED88:
	.incbin "build/assets/unknown/data_083FED88.bin"
	.global gUnk_083FED8C
gUnk_083FED8C:
	.incbin "build/assets/unknown/data_083FED8C.bin"
	.global gUnk_083FED90
gUnk_083FED90:
	.incbin "build/assets/unknown/data_083FED90.bin"
	.global gUnk_083FED94
gUnk_083FED94:
	.incbin "build/assets/unknown/data_083FED94.bin"
	.global gUnk_083FED98
gUnk_083FED98:
	.incbin "build/assets/unknown/data_083FED98.bin"
	.global gUnk_083FED9C
gUnk_083FED9C:
	.incbin "build/assets/unknown/data_083FED9C.bin"
	.global gUnk_083FEDA0
gUnk_083FEDA0:
	.incbin "build/assets/unknown/data_083FEDA0.bin"
	.global gUnk_083FEDA4
gUnk_083FEDA4:
	.incbin "build/assets/unknown/data_083FEDA4.bin"
	.global gUnk_083FEDA8
gUnk_083FEDA8:
	.incbin "build/assets/unknown/data_083FEDA8.bin"
	.global gUnk_083FEDAC
gUnk_083FEDAC:
	.incbin "build/assets/unknown/data_083FEDAC.bin"
	.global gUnk_083FEDB0
gUnk_083FEDB0:
	.incbin "build/assets/unknown/data_083FEDB0.bin"
	.global gUnk_083FEDB4
gUnk_083FEDB4:
	.incbin "build/assets/unknown/data_083FEDB4.bin"
	.global gUnk_083FEDB8
gUnk_083FEDB8:
	.incbin "build/assets/unknown/data_083FEDB8.bin"
	.global gUnk_083FEDBC
gUnk_083FEDBC:
	.incbin "build/assets/unknown/data_083FEDBC.bin"
	.global gUnk_083FEDC0
gUnk_083FEDC0:
	.incbin "build/assets/unknown/data_083FEDC0.bin"
	.global gUnk_083FEDC4
gUnk_083FEDC4:
	.incbin "build/assets/unknown/data_083FEDC4.bin"
	.global gUnk_083FEDC8
gUnk_083FEDC8:
	.incbin "build/assets/unknown/data_083FEDC8.bin"
	.global gUnk_083FEDCC
gUnk_083FEDCC:
	.incbin "build/assets/unknown/data_083FEDCC.bin"
	.global gUnk_083FEDD0
gUnk_083FEDD0:
	.incbin "build/assets/unknown/data_083FEDD0.bin"
	.global gUnk_083FEDD4
gUnk_083FEDD4:
	.incbin "build/assets/unknown/data_083FEDD4.bin"
	.global gUnk_083FEDD8
gUnk_083FEDD8:
	.incbin "build/assets/unknown/data_083FEDD8.bin"
	.global gUnk_083FEDDC
gUnk_083FEDDC:
	.incbin "build/assets/unknown/data_083FEDDC.bin"
	.global gUnk_083FEDE0
gUnk_083FEDE0:
	.incbin "build/assets/unknown/data_083FEDE0.bin"
	.global gUnk_083FEDE4
gUnk_083FEDE4:
	.incbin "build/assets/unknown/data_083FEDE4.bin"
	.global gUnk_083FEDE8
gUnk_083FEDE8:
	.incbin "build/assets/unknown/data_083FEDE8.bin"
	.global gUnk_083FEDEC
gUnk_083FEDEC:
	.incbin "build/assets/unknown/data_083FEDEC.bin"
	.global gUnk_083FEDF0
gUnk_083FEDF0:
	.incbin "build/assets/unknown/data_083FEDF0.bin"
	.global gUnk_083FEDF4
gUnk_083FEDF4:
	.incbin "build/assets/unknown/data_083FEDF4.bin"
	.global gUnk_083FEDF8
gUnk_083FEDF8:
	.incbin "build/assets/unknown/data_083FEDF8.bin"
	.global gUnk_083FEDFC
gUnk_083FEDFC:
	.incbin "build/assets/unknown/data_083FEDFC.bin"
	.global gUnk_083FEE00
gUnk_083FEE00:
	.incbin "build/assets/unknown/data_083FEE00.bin"
	.global gUnk_083FEE04
gUnk_083FEE04:
	.incbin "build/assets/unknown/data_083FEE04.bin"
	.global gUnk_083FEE08
gUnk_083FEE08:
	.incbin "build/assets/unknown/data_083FEE08.bin"
	.global gUnk_083FEE0C
gUnk_083FEE0C:
	.incbin "build/assets/unknown/data_083FEE0C.bin"
	.global gUnk_083FEE10
gUnk_083FEE10:
	.incbin "build/assets/unknown/data_083FEE10.bin"
	.global gUnk_083FEE14
gUnk_083FEE14:
	.incbin "build/assets/unknown/data_083FEE14.bin"
	.global gUnk_083FEE18
gUnk_083FEE18:
	.incbin "build/assets/unknown/data_083FEE18.bin"
	.global gUnk_083FEE1C
gUnk_083FEE1C:
	.incbin "build/assets/unknown/data_083FEE1C.bin"
	.global gUnk_083FEE20
gUnk_083FEE20:
	.incbin "build/assets/unknown/data_083FEE20.bin"
	.global gUnk_083FEE24
gUnk_083FEE24:
	.incbin "build/assets/unknown/data_083FEE24.bin"
	.global gUnk_083FEE28
gUnk_083FEE28:
	.incbin "build/assets/unknown/data_083FEE28.bin"
	.global gUnk_083FEE2C
gUnk_083FEE2C:
	.incbin "build/assets/unknown/data_083FEE2C.bin"
	.global gUnk_083FEE30
gUnk_083FEE30:
	.incbin "build/assets/unknown/data_083FEE30.bin"
	.global gUnk_083FEE34
gUnk_083FEE34:
	.incbin "build/assets/unknown/data_083FEE34.bin"
	.global gUnk_083FEE38
gUnk_083FEE38:
	.incbin "build/assets/unknown/data_083FEE38.bin"
	.global gUnk_083FEE48
gUnk_083FEE48:
	.incbin "build/assets/unknown/data_083FEE48.bin"
	.global gUnk_083FEE58
gUnk_083FEE58:
	.incbin "build/assets/unknown/data_083FEE58.bin"
	.global gUnk_083FEE68
gUnk_083FEE68:
	.incbin "build/assets/unknown/data_083FEE68.bin"
	.global gUnk_083FEE78
gUnk_083FEE78:
	.incbin "build/assets/unknown/data_083FEE78.bin"
	.global gUnk_083FEE88
gUnk_083FEE88:
	.incbin "build/assets/unknown/data_083FEE88.bin"
	.global gUnk_083FEE98
gUnk_083FEE98:
	.incbin "build/assets/unknown/data_083FEE98.bin"
	.global gUnk_083FEEA8
gUnk_083FEEA8:
	.incbin "build/assets/unknown/data_083FEEA8.bin"
	.global gUnk_083FEEB8
gUnk_083FEEB8:
	.incbin "build/assets/unknown/data_083FEEB8.bin"
	.global gUnk_083FEEC8
gUnk_083FEEC8:
	.incbin "build/assets/unknown/data_083FEEC8.bin"
	.global gUnk_083FEED8
gUnk_083FEED8:
	.incbin "build/assets/unknown/data_083FEED8.bin"
	.global gUnk_083FEEE8
gUnk_083FEEE8:
	.incbin "build/assets/unknown/data_083FEEE8.bin"
