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
	.global gUnk_0829EF78
gUnk_0829EF78:
	.incbin "build/assets/unknown/data_0829EF78.bin"
	.global gUnk_0829EFD8
gUnk_0829EFD8:
	.incbin "build/assets/unknown/data_0829EFD8.bin"
	.global gUnk_0829F038
gUnk_0829F038:
	.incbin "build/assets/unknown/data_0829F038.bin"
	.global gUnk_0829F088
gUnk_0829F088:
	.incbin "build/assets/unknown/data_0829F088.bin"
	.global gUnk_0829F0D8
gUnk_0829F0D8:
	.incbin "build/assets/unknown/data_0829F0D8.bin"
	.global gUnk_0829F128
gUnk_0829F128:
	.incbin "build/assets/unknown/data_0829F128.bin"
	.global gUnk_0829F138
gUnk_0829F138:
	.incbin "build/assets/unknown/data_0829F138.bin"
	.global gUnk_0829F140
gUnk_0829F140:
	.incbin "build/assets/unknown/data_0829F140.bin"
	.global gUnk_0829F15C
gUnk_0829F15C:
	.incbin "build/assets/unknown/data_0829F15C.bin"
	.global gUnk_0829F174
gUnk_0829F174:
	.incbin "build/assets/unknown/data_0829F174.bin"
	.global gUnk_0829F180
gUnk_0829F180:
	.incbin "build/assets/unknown/data_0829F180.bin"
	.global gUnk_0829F190
gUnk_0829F190:
	.incbin "build/assets/unknown/data_0829F190.bin"
	.global gUnk_0829F1A0
gUnk_0829F1A0:
	.incbin "build/assets/unknown/data_0829F1A0.bin"
	.global gUnk_0829F1B8
gUnk_0829F1B8:
	.incbin "build/assets/unknown/data_0829F1B8.bin"
	.global gUnk_0829F1C8
gUnk_0829F1C8:
	.incbin "build/assets/unknown/data_0829F1C8.bin"
	.global gUnk_0829F1D0
gUnk_0829F1D0:
	.incbin "build/assets/unknown/data_0829F1D0.bin"
	.global gUnk_0829F1E0
gUnk_0829F1E0:
	.incbin "build/assets/unknown/data_0829F1E0.bin"
	.global gUnk_0829F1F4
gUnk_0829F1F4:
	.incbin "build/assets/unknown/data_0829F1F4.bin"
	.global gUnk_0829F208
gUnk_0829F208:
	.incbin "build/assets/unknown/data_0829F208.bin"
	.global gUnk_0829F220
gUnk_0829F220:
	.incbin "build/assets/unknown/data_0829F220.bin"
	.global gUnk_0829F224
gUnk_0829F224:
	.incbin "build/assets/unknown/data_0829F224.bin"
	.global gUnk_0829F228
gUnk_0829F228:
	.incbin "build/assets/unknown/data_0829F228.bin"
	.global gUnk_0829F22C
gUnk_0829F22C:
	.incbin "build/assets/unknown/data_0829F22C.bin"
