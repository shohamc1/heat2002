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
	.global gUnk_08367C38
gUnk_08367C38:
	.incbin "build/assets/unknown/data_08367C38.bin"
	.global gUnk_08367C42
gUnk_08367C42:
	.incbin "build/assets/unknown/data_08367C42.bin"
	.global gUnk_08367C4C
gUnk_08367C4C:
	.incbin "build/assets/unknown/data_08367C4C.bin"
	.global gUnk_08367C56
gUnk_08367C56:
	.incbin "build/assets/unknown/data_08367C56.bin"
	.global gUnk_08367C60
gUnk_08367C60:
	.incbin "build/assets/unknown/data_08367C60.bin"
	.global gUnk_08367C6A
gUnk_08367C6A:
	.incbin "build/assets/unknown/data_08367C6A.bin"
	.global gUnk_08367C74
gUnk_08367C74:
	.incbin "build/assets/unknown/data_08367C74.bin"
	.global gUnk_08367C7E
gUnk_08367C7E:
	.incbin "build/assets/unknown/data_08367C7E.bin"
	.global gUnk_08367C88
gUnk_08367C88:
	.incbin "build/assets/unknown/data_08367C88.bin"
	.global gUnk_08367C92
gUnk_08367C92:
	.incbin "build/assets/unknown/data_08367C92.bin"
	.global gUnk_08367C9C
gUnk_08367C9C:
	.incbin "build/assets/unknown/data_08367C9C.bin"
	.global gUnk_08367CA6
gUnk_08367CA6:
	.incbin "build/assets/unknown/data_08367CA6.bin"
	.global gUnk_08367CB0
gUnk_08367CB0:
	.incbin "build/assets/unknown/data_08367CB0.bin"
	.global gUnk_08367CBA
gUnk_08367CBA:
	.incbin "build/assets/unknown/data_08367CBA.bin"
	.global gUnk_08367CC4
gUnk_08367CC4:
	.incbin "build/assets/unknown/data_08367CC4.bin"
	.global gUnk_08367CCE
gUnk_08367CCE:
	.incbin "build/assets/unknown/data_08367CCE.bin"
	.global gUnk_08367CD8
gUnk_08367CD8:
	.incbin "build/assets/unknown/data_08367CD8.bin"
	.global gUnk_08367CE2
gUnk_08367CE2:
	.incbin "build/assets/unknown/data_08367CE2.bin"
	.global gUnk_08367CEC
gUnk_08367CEC:
	.incbin "build/assets/unknown/data_08367CEC.bin"
	.global gUnk_08367CF6
gUnk_08367CF6:
	.incbin "build/assets/unknown/data_08367CF6.bin"
	.global gUnk_08367D00
gUnk_08367D00:
	.incbin "build/assets/unknown/data_08367D00.bin"
	.global gUnk_08367D0A
gUnk_08367D0A:
	.incbin "build/assets/unknown/data_08367D0A.bin"
	.global gUnk_08367D14
gUnk_08367D14:
	.incbin "build/assets/unknown/data_08367D14.bin"
	.global gUnk_08367D1E
gUnk_08367D1E:
	.incbin "build/assets/unknown/data_08367D1E.bin"
	.global gUnk_08367D28
gUnk_08367D28:
	.incbin "build/assets/unknown/data_08367D28.bin"
	.global gUnk_08367D32
gUnk_08367D32:
	.incbin "build/assets/unknown/data_08367D32.bin"
	.global gUnk_08367D3C
gUnk_08367D3C:
	.incbin "build/assets/unknown/data_08367D3C.bin"
	.global gUnk_08367D46
gUnk_08367D46:
	.incbin "build/assets/unknown/data_08367D46.bin"
	.global gUnk_08367D50
gUnk_08367D50:
	.incbin "build/assets/unknown/data_08367D50.bin"
	.global gUnk_08367D5A
gUnk_08367D5A:
	.incbin "build/assets/unknown/data_08367D5A.bin"
	.global gUnk_08367D64
gUnk_08367D64:
	.incbin "build/assets/unknown/data_08367D64.bin"
	.global gUnk_08367D6E
gUnk_08367D6E:
	.incbin "build/assets/unknown/data_08367D6E.bin"
	.global gUnk_08367D78
gUnk_08367D78:
	.incbin "build/assets/unknown/data_08367D78.bin"
	.global gUnk_08367D82
gUnk_08367D82:
	.incbin "build/assets/unknown/data_08367D82.bin"
	.global gUnk_08367D8C
gUnk_08367D8C:
	.incbin "build/assets/unknown/data_08367D8C.bin"
	.global gUnk_08367D96
gUnk_08367D96:
	.incbin "build/assets/unknown/data_08367D96.bin"
	.global gUnk_08367DA0
gUnk_08367DA0:
	.incbin "build/assets/unknown/data_08367DA0.bin"
	.global gUnk_08367DAA
gUnk_08367DAA:
	.incbin "build/assets/unknown/data_08367DAA.bin"
	.global gUnk_08367DB4
gUnk_08367DB4:
	.incbin "build/assets/unknown/data_08367DB4.bin"
	.global gUnk_08367DBE
gUnk_08367DBE:
	.incbin "build/assets/unknown/data_08367DBE.bin"
	.global gUnk_08367DC8
gUnk_08367DC8:
	.incbin "build/assets/unknown/data_08367DC8.bin"
	.global gUnk_08367DD2
gUnk_08367DD2:
	.incbin "build/assets/unknown/data_08367DD2.bin"
	.global gUnk_08367DDC
gUnk_08367DDC:
	.incbin "build/assets/unknown/data_08367DDC.bin"
	.global gUnk_08367DE6
gUnk_08367DE6:
	.incbin "build/assets/unknown/data_08367DE6.bin"
	.global gUnk_08367DF0
gUnk_08367DF0:
	.incbin "build/assets/unknown/data_08367DF0.bin"
	.global gUnk_08367DFA
gUnk_08367DFA:
	.incbin "build/assets/unknown/data_08367DFA.bin"
	.global gUnk_08367E04
gUnk_08367E04:
	.incbin "build/assets/unknown/data_08367E04.bin"
	.global gUnk_08367E0E
gUnk_08367E0E:
	.incbin "build/assets/unknown/data_08367E0E.bin"
	.global gUnk_08367E18
gUnk_08367E18:
	.incbin "build/assets/unknown/data_08367E18.bin"
	.global gUnk_08367E22
gUnk_08367E22:
	.incbin "build/assets/unknown/data_08367E22.bin"
	.global gUnk_08367E2C
gUnk_08367E2C:
	.incbin "build/assets/unknown/data_08367E2C.bin"
	.global gUnk_08367E36
gUnk_08367E36:
	.incbin "build/assets/unknown/data_08367E36.bin"
	.global gUnk_08367E40
gUnk_08367E40:
	.incbin "build/assets/unknown/data_08367E40.bin"
	.global gUnk_08367E4A
gUnk_08367E4A:
	.incbin "build/assets/unknown/data_08367E4A.bin"
	.global gUnk_08367E54
gUnk_08367E54:
	.incbin "build/assets/unknown/data_08367E54.bin"
	.global gUnk_08367E5E
gUnk_08367E5E:
	.incbin "build/assets/unknown/data_08367E5E.bin"
	.global gUnk_08367E68
gUnk_08367E68:
	.incbin "build/assets/unknown/data_08367E68.bin"
	.global gUnk_08367E72
gUnk_08367E72:
	.incbin "build/assets/unknown/data_08367E72.bin"
	.global gUnk_08367E7C
gUnk_08367E7C:
	.incbin "build/assets/unknown/data_08367E7C.bin"
	.global gUnk_08367E86
gUnk_08367E86:
	.incbin "build/assets/unknown/data_08367E86.bin"
	.global gUnk_08367E90
gUnk_08367E90:
	.incbin "build/assets/unknown/data_08367E90.bin"
	.global gUnk_08367E9A
gUnk_08367E9A:
	.incbin "build/assets/unknown/data_08367E9A.bin"
	.global gUnk_08367EA4
gUnk_08367EA4:
	.incbin "build/assets/unknown/data_08367EA4.bin"
	.global gUnk_08367EAE
gUnk_08367EAE:
	.incbin "build/assets/unknown/data_08367EAE.bin"
	.global gUnk_08367EB8
gUnk_08367EB8:
	.incbin "build/assets/unknown/data_08367EB8.bin"
	.global gUnk_08367EC2
gUnk_08367EC2:
	.incbin "build/assets/unknown/data_08367EC2.bin"
	.global gUnk_08367ECC
gUnk_08367ECC:
	.incbin "build/assets/unknown/data_08367ECC.bin"
	.global gUnk_08367ED6
gUnk_08367ED6:
	.incbin "build/assets/unknown/data_08367ED6.bin"
	.global gUnk_08367EE0
gUnk_08367EE0:
	.incbin "build/assets/unknown/data_08367EE0.bin"
	.global gUnk_08367EEA
gUnk_08367EEA:
	.incbin "build/assets/unknown/data_08367EEA.bin"
	.global gUnk_08367EF4
gUnk_08367EF4:
	.incbin "build/assets/unknown/data_08367EF4.bin"
	.global gUnk_08367EFE
gUnk_08367EFE:
	.incbin "build/assets/unknown/data_08367EFE.bin"
	.global gUnk_08367F08
gUnk_08367F08:
	.incbin "build/assets/unknown/data_08367F08.bin"
	.global gUnk_08367F12
gUnk_08367F12:
	.incbin "build/assets/unknown/data_08367F12.bin"
	.global gUnk_08367F1C
gUnk_08367F1C:
	.incbin "build/assets/unknown/data_08367F1C.bin"
	.global gUnk_08367F26
gUnk_08367F26:
	.incbin "build/assets/unknown/data_08367F26.bin"
	.global gUnk_08367F30
gUnk_08367F30:
	.incbin "build/assets/unknown/data_08367F30.bin"
	.global gUnk_08367F3A
gUnk_08367F3A:
	.incbin "build/assets/unknown/data_08367F3A.bin"
	.global gUnk_08367F44
gUnk_08367F44:
	.incbin "build/assets/unknown/data_08367F44.bin"
	.global gUnk_08367F4E
gUnk_08367F4E:
	.incbin "build/assets/unknown/data_08367F4E.bin"
	.global gUnk_08367F58
gUnk_08367F58:
	.incbin "build/assets/unknown/data_08367F58.bin"
	.global gUnk_08367F62
gUnk_08367F62:
	.incbin "build/assets/unknown/data_08367F62.bin"
	.global gUnk_08367F6C
gUnk_08367F6C:
	.incbin "build/assets/unknown/data_08367F6C.bin"
	.global gUnk_08367F76
gUnk_08367F76:
	.incbin "build/assets/unknown/data_08367F76.bin"
	.global gUnk_08367F80
gUnk_08367F80:
	.incbin "build/assets/unknown/data_08367F80.bin"
	.global gUnk_08367F8A
gUnk_08367F8A:
	.incbin "build/assets/unknown/data_08367F8A.bin"
	.global gUnk_08367F94
gUnk_08367F94:
	.incbin "build/assets/unknown/data_08367F94.bin"
	.global gUnk_08367F9E
gUnk_08367F9E:
	.incbin "build/assets/unknown/data_08367F9E.bin"
	.global gUnk_08367FA8
gUnk_08367FA8:
	.incbin "build/assets/unknown/data_08367FA8.bin"
	.global gUnk_08367FB2
gUnk_08367FB2:
	.incbin "build/assets/unknown/data_08367FB2.bin"
