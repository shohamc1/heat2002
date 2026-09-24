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
	.incbin "build/assets/unknown/data_08310180.bin"
	.incbin "build/assets/unknown/data_083101CC.bin"
	.incbin "build/assets/unknown/data_083101DC.bin"
	.incbin "build/assets/unknown/data_083101E4.bin"
	.incbin "build/assets/unknown/data_08310380.bin"
	.incbin "build/assets/unknown/data_08310428.bin"
	.incbin "build/assets/unknown/data_0831042C.bin"
	.incbin "build/assets/unknown/data_0831045C.bin"
	.incbin "build/assets/unknown/data_083104AC.bin"
	.incbin "build/assets/unknown/data_083105C0.bin"
	.incbin "build/assets/unknown/data_083107F4.bin"
	.incbin "build/assets/unknown/data_083107FC.bin"
	.incbin "build/assets/unknown/data_08310828.bin"
	.incbin "build/assets/unknown/data_0831082C.bin"
	.incbin "build/assets/unknown/data_08310830.bin"
	.incbin "build/assets/unknown/data_08310834.bin"
	.incbin "build/assets/unknown/data_08310C30.bin"
	.incbin "build/assets/unknown/data_08310C70.bin"
	.incbin "build/assets/unknown/data_0831377C.bin"
	.incbin "build/assets/unknown/data_0831397C.bin"
	.incbin "build/assets/unknown/data_08313AA8.bin"
	.incbin "build/assets/unknown/data_08313DF0.bin"
	.incbin "build/assets/unknown/data_08316B30.bin"
	.incbin "build/assets/unknown/data_08316D30.bin"
	.incbin "build/assets/unknown/data_08316E5C.bin"
	.incbin "build/assets/unknown/data_083171A4.bin"
	.incbin "build/assets/unknown/data_08319EE4.bin"
	.incbin "build/assets/unknown/data_0831A0E4.bin"
	.incbin "build/assets/unknown/data_0831A210.bin"
	.incbin "build/assets/unknown/data_0831A450.bin"
	.global gUnk_0831C850
gUnk_0831C850:
	.incbin "build/assets/graphics/rl_0831C850.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_0831C878.bin"
	.incbin "build/assets/graphics/rl_0831C898.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831C8D4.bin"
	.incbin "build/assets/graphics/rl_0831C918.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831C960.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831C9A8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831C9F0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CA38.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CA80.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CAC8.bin"
	.incbin "build/assets/graphics/rl_0831CB04.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CB4C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CB94.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CBDC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CC24.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CC6C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CCB4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CCFC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CD44.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CD8C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CDD4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CE1C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CE64.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CEAC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CEF4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CF3C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CF84.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831CFCC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831D014.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831D05C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0831D0A4.bin"
	.align 2, 0
