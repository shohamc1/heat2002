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
	.incbin "build/assets/unknown/data_0831017C.bin"
	.global gUnk_08310180
gUnk_08310180:
	.incbin "build/assets/unknown/data_08310180.bin"
	.incbin "build/assets/unknown/data_083101CC.bin"
	.incbin "build/assets/unknown/data_083101DC.bin"
	.incbin "build/assets/unknown/data_083101E4.bin"
	.global gUnk_08310380
gUnk_08310380:
	.incbin "build/assets/unknown/data_08310380.bin"
	.incbin "build/assets/unknown/data_08310428.bin"
	.incbin "build/assets/unknown/data_0831042C.bin"
	.incbin "build/assets/unknown/data_0831045C.bin"
	.global gUnk_083104AC
gUnk_083104AC:
	.incbin "build/assets/unknown/data_083104AC.bin"
	.incbin "build/assets/unknown/data_083105C0.bin"
	.incbin "build/assets/unknown/data_083107F4.bin"
	.global gUnk_083107FC
gUnk_083107FC:
	.incbin "build/assets/unknown/data_083107FC.bin"
	.incbin "build/assets/unknown/data_08310828.bin"
	.incbin "build/assets/unknown/data_0831082C.bin"
	.incbin "build/assets/unknown/data_08310830.bin"
	.incbin "build/assets/unknown/data_08310834.bin"
	.incbin "build/assets/unknown/data_08310C30.bin"
	.incbin "build/assets/unknown/data_08310C70.bin"
	.global gUnk_0831377C
gUnk_0831377C:
	.incbin "build/assets/unknown/data_0831377C.bin"
	.global gUnk_0831397C
gUnk_0831397C:
	.incbin "build/assets/unknown/data_0831397C.bin"
	.global gUnk_08313AA8
gUnk_08313AA8:
	.incbin "build/assets/unknown/data_08313AA8.bin"
	.global gUnk_08313DF0
gUnk_08313DF0:
	.incbin "build/assets/unknown/data_08313DF0.bin"
	.global gUnk_08316B30
gUnk_08316B30:
	.incbin "build/assets/unknown/data_08316B30.bin"
	.global gUnk_08316D30
gUnk_08316D30:
	.incbin "build/assets/unknown/data_08316D30.bin"
	.global gUnk_08316E5C
gUnk_08316E5C:
	.incbin "build/assets/unknown/data_08316E5C.bin"
	.global gUnk_083171A4
gUnk_083171A4:
	.incbin "build/assets/unknown/data_083171A4.bin"
	.global gUnk_08319EE4
gUnk_08319EE4:
	.incbin "build/assets/unknown/data_08319EE4.bin"
	.global gUnk_0831A0E4
gUnk_0831A0E4:
	.incbin "build/assets/unknown/data_0831A0E4.bin"
	.global gUnk_0831A210
gUnk_0831A210:
	.incbin "build/assets/unknown/data_0831A210.bin"
	.global gUnk_0831A450
gUnk_0831A450:
	.incbin "build/assets/unknown/data_0831A450.bin"
	.global gUnk_0831C850
gUnk_0831C850:
	.incbin "build/assets/graphics/rl_0831C850.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_0831C878.bin"
	.global gUnk_0831C898
gUnk_0831C898:
	.incbin "build/assets/graphics/rl_0831C898.bin"
	.align 2, 0
	.global gUnk_0831C8D4
gUnk_0831C8D4:
	.incbin "build/assets/graphics/rl_0831C8D4.bin"
	.global gUnk_0831C918
gUnk_0831C918:
	.incbin "build/assets/graphics/rl_0831C918.bin"
	.align 2, 0
	.global gUnk_0831C960
gUnk_0831C960:
	.incbin "build/assets/graphics/rl_0831C960.bin"
	.align 2, 0
	.global gUnk_0831C9A8
gUnk_0831C9A8:
	.incbin "build/assets/graphics/rl_0831C9A8.bin"
	.align 2, 0
	.global gUnk_0831C9F0
gUnk_0831C9F0:
	.incbin "build/assets/graphics/rl_0831C9F0.bin"
	.align 2, 0
	.global gUnk_0831CA38
gUnk_0831CA38:
	.incbin "build/assets/graphics/rl_0831CA38.bin"
	.align 2, 0
	.global gUnk_0831CA80
gUnk_0831CA80:
	.incbin "build/assets/graphics/rl_0831CA80.bin"
	.align 2, 0
	.global gUnk_0831CAC8
gUnk_0831CAC8:
	.incbin "build/assets/graphics/rl_0831CAC8.bin"
	.global gUnk_0831CB04
gUnk_0831CB04:
	.incbin "build/assets/graphics/rl_0831CB04.bin"
	.align 2, 0
	.global gUnk_0831CB4C
gUnk_0831CB4C:
	.incbin "build/assets/graphics/rl_0831CB4C.bin"
	.align 2, 0
	.global gUnk_0831CB94
gUnk_0831CB94:
	.incbin "build/assets/graphics/rl_0831CB94.bin"
	.align 2, 0
	.global gUnk_0831CBDC
gUnk_0831CBDC:
	.incbin "build/assets/graphics/rl_0831CBDC.bin"
	.align 2, 0
	.global gUnk_0831CC24
gUnk_0831CC24:
	.incbin "build/assets/graphics/rl_0831CC24.bin"
	.align 2, 0
	.global gUnk_0831CC6C
gUnk_0831CC6C:
	.incbin "build/assets/graphics/rl_0831CC6C.bin"
	.align 2, 0
	.global gUnk_0831CCB4
gUnk_0831CCB4:
	.incbin "build/assets/graphics/rl_0831CCB4.bin"
	.align 2, 0
	.global gUnk_0831CCFC
gUnk_0831CCFC:
	.incbin "build/assets/graphics/rl_0831CCFC.bin"
	.align 2, 0
	.global gUnk_0831CD44
gUnk_0831CD44:
	.incbin "build/assets/graphics/rl_0831CD44.bin"
	.align 2, 0
	.global gUnk_0831CD8C
gUnk_0831CD8C:
	.incbin "build/assets/graphics/rl_0831CD8C.bin"
	.align 2, 0
	.global gUnk_0831CDD4
gUnk_0831CDD4:
	.incbin "build/assets/graphics/rl_0831CDD4.bin"
	.align 2, 0
	.global gUnk_0831CE1C
gUnk_0831CE1C:
	.incbin "build/assets/graphics/rl_0831CE1C.bin"
	.align 2, 0
	.global gUnk_0831CE64
gUnk_0831CE64:
	.incbin "build/assets/graphics/rl_0831CE64.bin"
	.align 2, 0
	.global gUnk_0831CEAC
gUnk_0831CEAC:
	.incbin "build/assets/graphics/rl_0831CEAC.bin"
	.align 2, 0
	.global gUnk_0831CEF4
gUnk_0831CEF4:
	.incbin "build/assets/graphics/rl_0831CEF4.bin"
	.align 2, 0
	.global gUnk_0831CF3C
gUnk_0831CF3C:
	.incbin "build/assets/graphics/rl_0831CF3C.bin"
	.align 2, 0
	.global gUnk_0831CF84
gUnk_0831CF84:
	.incbin "build/assets/graphics/rl_0831CF84.bin"
	.align 2, 0
	.global gUnk_0831CFCC
gUnk_0831CFCC:
	.incbin "build/assets/graphics/rl_0831CFCC.bin"
	.align 2, 0
	.global gUnk_0831D014
gUnk_0831D014:
	.incbin "build/assets/graphics/rl_0831D014.bin"
	.align 2, 0
	.global gUnk_0831D05C
gUnk_0831D05C:
	.incbin "build/assets/graphics/rl_0831D05C.bin"
	.align 2, 0
	.global gUnk_0831D0A4
gUnk_0831D0A4:
	.incbin "build/assets/graphics/rl_0831D0A4.bin"
	.align 2, 0
