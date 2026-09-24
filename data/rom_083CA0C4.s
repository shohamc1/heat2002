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
	.global gUnk_083CA0C4
gUnk_083CA0C4:
	.incbin "build/assets/unknown/data_083CA0C4.bin"
	.global gUnk_083CA9DC
gUnk_083CA9DC:
	.incbin "build/assets/unknown/data_083CA9DC.bin"
	.global gUnk_083CCDDC
gUnk_083CCDDC:
	.incbin "build/assets/unknown/data_083CCDDC.bin"
	.global gUnk_083CDA98
gUnk_083CDA98:
	.incbin "build/assets/unknown/data_083CDA98.bin"
	.global gUnk_083CEC98
gUnk_083CEC98:
	.incbin "build/assets/unknown/data_083CEC98.bin"
	.global gUnk_083CF7D0
gUnk_083CF7D0:
	.incbin "build/assets/unknown/data_083CF7D0.bin"
	.incbin "build/assets/unknown/data_083D07EC.bin"
	.incbin "build/assets/unknown/data_083D083C.bin"
	.global gUnk_083D2430
gUnk_083D2430:
	.incbin "build/assets/unknown/data_083D2430.bin"
	.global gUnk_083D32A8
gUnk_083D32A8:
	.incbin "build/assets/unknown/data_083D32A8.bin"
	.global gUnk_083D44A8
gUnk_083D44A8:
	.incbin "build/assets/unknown/data_083D44A8.bin"
	.global gUnk_083D4A28
gUnk_083D4A28:
	.incbin "build/assets/unknown/data_083D4A28.bin"
	.global gUnk_083D5FA8
gUnk_083D5FA8:
	.incbin "build/assets/unknown/data_083D5FA8.bin"
	.global gUnk_083D669E
gUnk_083D669E:
	.incbin "build/assets/unknown/data_083D669E.bin"
	.global gUnk_083D78A0
gUnk_083D78A0:
	.incbin "build/assets/unknown/data_083D78A0.bin"
	.global gUnk_083D7FE0
gUnk_083D7FE0:
	.incbin "build/assets/unknown/data_083D7FE0.bin"
	.global gUnk_083D9C80
gUnk_083D9C80:
	.incbin "build/assets/unknown/data_083D9C80.bin"
	.global gUnk_083DA5D0
gUnk_083DA5D0:
	.incbin "build/assets/unknown/data_083DA5D0.bin"
	.global gUnk_083DB7D0
gUnk_083DB7D0:
	.incbin "build/assets/unknown/data_083DB7D0.bin"
	.global gUnk_083DC1C0
gUnk_083DC1C0:
	.incbin "build/assets/unknown/data_083DC1C0.bin"
	.global gUnk_083DE920
gUnk_083DE920:
	.incbin "build/assets/unknown/data_083DE920.bin"
	.global gUnk_083DF630
gUnk_083DF630:
	.incbin "build/assets/unknown/data_083DF630.bin"
	.global gUnk_083E0830
gUnk_083E0830:
	.incbin "build/assets/unknown/data_083E0830.bin"
	.incbin "build/assets/unknown/data_083E083C.bin"
	.incbin "build/assets/unknown/data_083E0CEC.bin"
	.global gUnk_083E1290
gUnk_083E1290:
	.incbin "build/assets/unknown/data_083E1290.bin"
	.global gUnk_083E3BB0
gUnk_083E3BB0:
	.incbin "build/assets/unknown/data_083E3BB0.bin"
	.global gUnk_083E4A40
gUnk_083E4A40:
	.incbin "build/assets/unknown/data_083E4A40.bin"
	.global gUnk_083E5C40
gUnk_083E5C40:
	.incbin "build/assets/unknown/data_083E5C40.bin"
	.global gUnk_083E6218
gUnk_083E6218:
	.incbin "build/assets/unknown/data_083E6218.bin"
	.global gUnk_083E7918
gUnk_083E7918:
	.incbin "build/assets/unknown/data_083E7918.bin"
	.global gUnk_083E81CA
gUnk_083E81CA:
	.incbin "build/assets/unknown/data_083E81CA.bin"
	.global gUnk_083E93CC
gUnk_083E93CC:
	.incbin "build/assets/unknown/data_083E93CC.bin"
	.global gUnk_083E996C
gUnk_083E996C:
	.incbin "build/assets/unknown/data_083E996C.bin"
	.global gUnk_083EAFAC
gUnk_083EAFAC:
	.incbin "build/assets/unknown/data_083EAFAC.bin"
	.global gUnk_083EB890
gUnk_083EB890:
	.incbin "build/assets/unknown/data_083EB890.bin"
	.global gUnk_083ECA90
gUnk_083ECA90:
	.incbin "build/assets/unknown/data_083ECA90.bin"
	.global gUnk_083ED040
gUnk_083ED040:
	.incbin "build/assets/unknown/data_083ED040.bin"
	.global gUnk_083EE6A0
gUnk_083EE6A0:
	.incbin "build/assets/unknown/data_083EE6A0.bin"
	.global gUnk_083EEE84
gUnk_083EEE84:
	.incbin "build/assets/unknown/data_083EEE84.bin"
	.global gUnk_083F0084
gUnk_083F0084:
	.incbin "build/assets/unknown/data_083F0084.bin"
	.incbin "build/assets/unknown/data_083F0C48.bin"
	.global gUnk_083F0CC4
gUnk_083F0CC4:
	.incbin "build/assets/unknown/data_083F0CC4.bin"
	.global gUnk_083F3D64
gUnk_083F3D64:
	.incbin "build/assets/unknown/data_083F3D64.bin"
	.global gUnk_083F4D42
gUnk_083F4D42:
	.incbin "build/assets/unknown/data_083F4D42.bin"
	.global gUnk_083F5F44
gUnk_083F5F44:
	.incbin "build/assets/unknown/data_083F5F44.bin"
	.global gUnk_083F64A4
gUnk_083F64A4:
	.incbin "build/assets/unknown/data_083F64A4.bin"
	.global gUnk_083F79C4
gUnk_083F79C4:
	.incbin "build/assets/unknown/data_083F79C4.bin"
	.global gUnk_083F80C4
gUnk_083F80C4:
	.incbin "build/assets/unknown/data_083F80C4.bin"
	.global gUnk_083F92C4
gUnk_083F92C4:
	.incbin "build/assets/unknown/data_083F92C4.bin"
	.global gUnk_083F9B14
gUnk_083F9B14:
	.incbin "build/assets/unknown/data_083F9B14.bin"
	.global gUnk_083FBBF4
gUnk_083FBBF4:
	.incbin "build/assets/unknown/data_083FBBF4.bin"
	.global gUnk_083FC71C
gUnk_083FC71C:
	.incbin "build/assets/unknown/data_083FC71C.bin"
