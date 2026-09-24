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
	.4byte gUnk_082BA310
	.global gUnk_083FED4C
gUnk_083FED4C:
	.4byte gUnk_082BACD8
	.global gUnk_083FED50
gUnk_083FED50:
	.4byte gUnk_082BB83C
	.global gUnk_083FED54
gUnk_083FED54:
	.4byte gUnk_082BC440
	.global gUnk_083FED58
gUnk_083FED58:
	.4byte gUnk_082BCF60
	.global gUnk_083FED5C
gUnk_083FED5C:
	.4byte gUnk_082BD948
	.global gUnk_083FED60
gUnk_083FED60:
	.4byte gUnk_082BE3BC
	.global gUnk_083FED64
gUnk_083FED64:
	.4byte gUnk_082BEEC4
	.global gUnk_083FED68
gUnk_083FED68:
	.4byte gUnk_082BFB3C
	.global gUnk_083FED6C
gUnk_083FED6C:
	.4byte gUnk_082C0654
	.global gUnk_083FED70
gUnk_083FED70:
	.4byte gUnk_082C1164
	.global gUnk_083FED74
gUnk_083FED74:
	.4byte gUnk_082C1CE0
	.global gUnk_083FED78
gUnk_083FED78:
	.4byte gUnk_082C2810
	.global gUnk_083FED7C
gUnk_083FED7C:
	.4byte gUnk_082C3350
	.global gUnk_083FED80
gUnk_083FED80:
	.4byte gUnk_082C3ED4
	.global gUnk_083FED84
gUnk_083FED84:
	.4byte gUnk_082C492C
	.global gUnk_083FED88
gUnk_083FED88:
	.4byte gUnk_082C5578
	.global gUnk_083FED8C
gUnk_083FED8C:
	.4byte gUnk_082C6194
	.global gUnk_083FED90
gUnk_083FED90:
	.4byte gUnk_082C6D34
	.global gUnk_083FED94
gUnk_083FED94:
	.4byte gUnk_082C78A4
	.global gUnk_083FED98
gUnk_083FED98:
	.4byte gUnk_082C8428
	.global gUnk_083FED9C
gUnk_083FED9C:
	.4byte gUnk_082C9000
	.global gUnk_083FEDA0
gUnk_083FEDA0:
	.4byte gUnk_082C9B24
	.global gUnk_083FEDA4
gUnk_083FEDA4:
	.4byte gUnk_082CA624
	.global gUnk_083FEDA8
gUnk_083FEDA8:
	.4byte gUnk_082CB11C
	.global gUnk_083FEDAC
gUnk_083FEDAC:
	.4byte gUnk_082CBC48
	.global gUnk_083FEDB0
gUnk_083FEDB0:
	.4byte gUnk_082CC7D8
	.global gUnk_083FEDB4
gUnk_083FEDB4:
	.4byte gUnk_082CD340
	.global gUnk_083FEDB8
gUnk_083FEDB8:
	.4byte gUnk_082CDF00
	.global gUnk_083FEDBC
gUnk_083FEDBC:
	.4byte gUnk_082CEB44
	.global gUnk_083FEDC0
gUnk_083FEDC0:
	.4byte gUnk_082CF5FC
	.global gUnk_083FEDC4
gUnk_083FEDC4:
	.4byte gUnk_082D00F0
	.global gUnk_083FEDC8
gUnk_083FEDC8:
	.4byte gUnk_082D0C4C
	.global gUnk_083FEDCC
gUnk_083FEDCC:
	.4byte gUnk_082D17BC
	.global gUnk_083FEDD0
gUnk_083FEDD0:
	.4byte gUnk_082D22C8
	.global gUnk_083FEDD4
gUnk_083FEDD4:
	.4byte gUnk_082D2DEC
	.global gUnk_083FEDD8
gUnk_083FEDD8:
	.4byte gUnk_082D38FC
	.global gUnk_083FEDDC
gUnk_083FEDDC:
	.4byte gUnk_082D4410
	.global gUnk_083FEDE0
gUnk_083FEDE0:
	.4byte gUnk_082D4E88
	.global gUnk_083FEDE4
gUnk_083FEDE4:
	.4byte gUnk_082D59E8
	.global gUnk_083FEDE8
gUnk_083FEDE8:
	.4byte gUnk_082D64F8
	.global gUnk_083FEDEC
gUnk_083FEDEC:
	.4byte gUnk_082D703C
	.global gUnk_083FEDF0
gUnk_083FEDF0:
	.4byte gUnk_082D7B6C
	.global gUnk_083FEDF4
gUnk_083FEDF4:
	.4byte gUnk_082D86A0
	.global gUnk_083FEDF8
gUnk_083FEDF8:
	.4byte gUnk_082D91F4
	.global gUnk_083FEDFC
gUnk_083FEDFC:
	.4byte gUnk_082D9D0C
	.global gUnk_083FEE00
gUnk_083FEE00:
	.4byte gUnk_082DA774
	.global gUnk_083FEE04
gUnk_083FEE04:
	.4byte gUnk_082DB1B4
	.global gUnk_083FEE08
gUnk_083FEE08:
	.4byte gUnk_082DBCC4
	.global gUnk_083FEE0C
gUnk_083FEE0C:
	.4byte gUnk_082DC814
	.global gUnk_083FEE10
gUnk_083FEE10:
	.4byte gUnk_082DD344
	.global gUnk_083FEE14
gUnk_083FEE14:
	.4byte gUnk_082DDE98
	.global gUnk_083FEE18
gUnk_083FEE18:
	.4byte gUnk_082DE9C4
	.global gUnk_083FEE1C
gUnk_083FEE1C:
	.4byte gUnk_082DF4E0
	.global gUnk_083FEE20
gUnk_083FEE20:
	.4byte gUnk_082E0014
	.global gUnk_083FEE24
gUnk_083FEE24:
	.4byte gUnk_082E0B6C
	.global gUnk_083FEE28
gUnk_083FEE28:
	.4byte gUnk_082E1688
	.global gUnk_083FEE2C
gUnk_083FEE2C:
	.4byte gUnk_082E2190
	.global gUnk_083FEE30
gUnk_083FEE30:
	.4byte gUnk_082E2CEC
	.global gUnk_083FEE34
gUnk_083FEE34:
	.4byte gUnk_082E3840
	.global gUnk_083FEE38
gUnk_083FEE38:
	.4byte gUnk_082F7EE0
	.4byte gUnk_082F8828
	.4byte gUnk_082F8F6C
	.4byte gUnk_082F9360
	.global gUnk_083FEE48
gUnk_083FEE48:
	.4byte gUnk_082F9AC0
	.4byte gUnk_082FA444
	.4byte gUnk_082FAE24
	.4byte gUnk_082FB3FC
	.global gUnk_083FEE58
gUnk_083FEE58:
	.4byte gUnk_082FB8AC
	.4byte gUnk_082FC150
	.4byte gUnk_082FCA94
	.4byte gUnk_082FCAD8
	.global gUnk_083FEE68
gUnk_083FEE68:
	.4byte gUnk_082FD2F8
	.4byte gUnk_082FDFE0
	.4byte gUnk_082FEB60
	.4byte gUnk_082FEDC4
	.global gUnk_083FEE78
gUnk_083FEE78:
	.4byte gUnk_082FF61C
	.4byte gUnk_082FFD38
	.4byte gUnk_083004A4
	.4byte gUnk_0830076C
	.global gUnk_083FEE88
gUnk_083FEE88:
	.4byte gUnk_08300DCC
	.4byte gUnk_083017E8
	.4byte gUnk_083024A8
	.4byte gUnk_08302764
	.global gUnk_083FEE98
gUnk_083FEE98:
	.4byte gUnk_08303000
	.4byte gUnk_08303638
	.4byte gUnk_083040FC
	.4byte gUnk_08304558
	.global gUnk_083FEEA8
gUnk_083FEEA8:
	.4byte gUnk_08304BFC
	.4byte gUnk_0830531C
	.4byte gUnk_08305A8C
	.4byte gUnk_08305D8C
	.global gUnk_083FEEB8
gUnk_083FEEB8:
	.4byte gUnk_08306438
	.4byte gUnk_08306D38
	.4byte gUnk_08307ACC
	.4byte gUnk_08308110
	.global gUnk_083FEEC8
gUnk_083FEEC8:
	.4byte gUnk_0830897C
	.4byte gUnk_083091D8
	.4byte gUnk_08309D28
	.4byte gUnk_0830A550
	.global gUnk_083FEED8
gUnk_083FEED8:
	.4byte gUnk_0830AD68
	.4byte gUnk_0830B484
	.4byte gUnk_0830BDF0
	.4byte gUnk_0830C23C
	.global gUnk_083FEEE8
gUnk_083FEEE8:
	.4byte gUnk_0830CC10
	.4byte gUnk_0830D358
	.4byte gUnk_0830DE8C
	.4byte gUnk_0830E358
	.4byte gUnk_0830E618
	.4byte gUnk_0830E690
