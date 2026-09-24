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
	.global gUnk_083FEF08
gUnk_083FEF08:
	.incbin "build/assets/unknown/data_083FEF08.bin"
	.global gUnk_083FEF0C
gUnk_083FEF0C:
	.incbin "build/assets/unknown/data_083FEF0C.bin"
	.global gUnk_083FEF10
gUnk_083FEF10:
	.incbin "build/assets/unknown/data_083FEF10.bin"
	.global gUnk_083FEF14
gUnk_083FEF14:
	.incbin "build/assets/unknown/data_083FEF14.bin"
	.global gUnk_083FEF18
gUnk_083FEF18:
	.incbin "build/assets/unknown/data_083FEF18.bin"
	.global gUnk_083FEF1C
gUnk_083FEF1C:
	.incbin "build/assets/unknown/data_083FEF1C.bin"
	.global gUnk_083FEF20
gUnk_083FEF20:
	.incbin "build/assets/unknown/data_083FEF20.bin"
	.global gUnk_083FEF24
gUnk_083FEF24:
	.incbin "build/assets/unknown/data_083FEF24.bin"
	.global gUnk_083FEF28
gUnk_083FEF28:
	.incbin "build/assets/unknown/data_083FEF28.bin"
	.global gUnk_083FEF2C
gUnk_083FEF2C:
	.incbin "build/assets/unknown/data_083FEF2C.bin"
	.global gUnk_083FEF30
gUnk_083FEF30:
	.incbin "build/assets/unknown/data_083FEF30.bin"
	.global gUnk_083FEF34
gUnk_083FEF34:
	.incbin "build/assets/unknown/data_083FEF34.bin"
	.global gUnk_083FEF38
gUnk_083FEF38:
	.incbin "build/assets/unknown/data_083FEF38.bin"
	.global gUnk_083FEF3C
gUnk_083FEF3C:
	.incbin "build/assets/unknown/data_083FEF3C.bin"
	.global gUnk_083FEF40
gUnk_083FEF40:
	.incbin "build/assets/unknown/data_083FEF40.bin"
	.global gUnk_083FEF44
gUnk_083FEF44:
	.incbin "build/assets/unknown/data_083FEF44.bin"
	.global gUnk_083FEF48
gUnk_083FEF48:
	.incbin "build/assets/unknown/data_083FEF48.bin"
	.global gUnk_083FEF4C
gUnk_083FEF4C:
	.incbin "build/assets/unknown/data_083FEF4C.bin"
	.global gUnk_083FEF50
gUnk_083FEF50:
	.incbin "build/assets/unknown/data_083FEF50.bin"
	.global gUnk_083FEF54
gUnk_083FEF54:
	.incbin "build/assets/unknown/data_083FEF54.bin"
	.global gUnk_083FEF58
gUnk_083FEF58:
	.incbin "build/assets/unknown/data_083FEF58.bin"
	.global gUnk_083FEF5C
gUnk_083FEF5C:
	.incbin "build/assets/unknown/data_083FEF5C.bin"
	.global gUnk_083FEF60
gUnk_083FEF60:
	.incbin "build/assets/unknown/data_083FEF60.bin"
	.global gUnk_083FEF64
gUnk_083FEF64:
	.incbin "build/assets/unknown/data_083FEF64.bin"
	.global gUnk_083FEF68
gUnk_083FEF68:
	.incbin "build/assets/unknown/data_083FEF68.bin"
	.global gUnk_083FEF6C
gUnk_083FEF6C:
	.incbin "build/assets/unknown/data_083FEF6C.bin"
	.global gUnk_083FEF70
gUnk_083FEF70:
	.incbin "build/assets/unknown/data_083FEF70.bin"
	.global gUnk_083FEF74
gUnk_083FEF74:
	.incbin "build/assets/unknown/data_083FEF74.bin"
	.global gUnk_083FEF78
gUnk_083FEF78:
	.incbin "build/assets/unknown/data_083FEF78.bin"
	.global gUnk_083FEF7C
gUnk_083FEF7C:
	.incbin "build/assets/unknown/data_083FEF7C.bin"
	.global gUnk_083FEF80
gUnk_083FEF80:
	.incbin "build/assets/unknown/data_083FEF80.bin"
	.global gUnk_083FF004
gUnk_083FF004:
	.incbin "build/assets/unknown/data_083FF004.bin"
	.global gUnk_083FF088
gUnk_083FF088:
	.incbin "build/assets/unknown/data_083FF088.bin"
	.global gUnk_083FF10C
gUnk_083FF10C:
	.incbin "build/assets/unknown/data_083FF10C.bin"
	.global gUnk_083FF190
gUnk_083FF190:
	.incbin "build/assets/unknown/data_083FF190.bin"
	.global gUnk_083FF214
gUnk_083FF214:
	.incbin "build/assets/unknown/data_083FF214.bin"
	.global gUnk_083FF298
gUnk_083FF298:
	.incbin "build/assets/unknown/data_083FF298.bin"
	.global gUnk_083FF31C
gUnk_083FF31C:
	.incbin "build/assets/unknown/data_083FF31C.bin"
	.global gUnk_083FF3A0
gUnk_083FF3A0:
	.incbin "build/assets/unknown/data_083FF3A0.bin"
	.global gUnk_083FF424
gUnk_083FF424:
	.incbin "build/assets/unknown/data_083FF424.bin"
	.global gUnk_083FF4A8
gUnk_083FF4A8:
	.incbin "build/assets/unknown/data_083FF4A8.bin"
	.global gUnk_083FF52C
gUnk_083FF52C:
	.incbin "build/assets/unknown/data_083FF52C.bin"
