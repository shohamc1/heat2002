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
	.incbin "build/assets/unknown/data_082F0000.bin"
	.incbin "build/assets/unknown/data_082F0024.bin"
	.incbin "build/assets/unknown/data_082F0108.bin"
	.incbin "build/assets/unknown/data_082F01DC.bin"
	.incbin "build/assets/unknown/data_082F01E4.bin"
	.incbin "build/assets/unknown/data_082F0428.bin"
	.incbin "build/assets/unknown/data_082F0430.bin"
	.incbin "build/assets/unknown/data_082F0434.bin"
	.incbin "build/assets/unknown/data_082F04B0.bin"
	.incbin "build/assets/unknown/data_082F05C0.bin"
	.incbin "build/assets/unknown/data_082F0828.bin"
	.incbin "build/assets/unknown/data_082F082C.bin"
	.incbin "build/assets/unknown/data_082F0830.bin"
	.incbin "build/assets/unknown/data_082F0834.bin"
	.incbin "build/assets/unknown/data_082F0CBC.bin"
	.incbin "build/assets/unknown/data_082F0D30.bin"
	.incbin "build/assets/graphics/rl_082F7EE0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_082F8828.bin"
	.incbin "build/assets/graphics/rl_082F8F6C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_082F9360.bin"
	.align 2, 0
	.global gUnk_082F98C0
gUnk_082F98C0:
	.incbin "build/assets/unknown/data_082F98C0.bin"
	.incbin "build/assets/graphics/rl_082F9AC0.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_082FA444.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_082FAE24.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_082FB3FC.bin"
	.align 2, 0
	.global gUnk_082FB6AC
gUnk_082FB6AC:
	.incbin "build/assets/unknown/data_082FB6AC.bin"
	.incbin "build/assets/graphics/rl_082FB8AC.bin"
	.incbin "build/assets/graphics/rl_082FC150.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_082FCA94.bin"
	.incbin "build/assets/graphics/rl_082FCAD8.bin"
	.align 2, 0
	.global gUnk_082FD0F8
gUnk_082FD0F8:
	.incbin "build/assets/unknown/data_082FD0F8.bin"
	.incbin "build/assets/graphics/rl_082FD2F8.bin"
	.incbin "build/assets/graphics/rl_082FDFE0.bin"
	.incbin "build/assets/graphics/rl_082FEB60.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_082FEDC4.bin"
	.align 2, 0
	.global gUnk_082FF41C
gUnk_082FF41C:
	.incbin "build/assets/unknown/data_082FF41C.bin"
	.incbin "build/assets/graphics/rl_082FF61C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_082FFD38.bin"
	.incbin "build/assets/graphics/rl_083004A4.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0830076C.bin"
	.align 2, 0
	.global gUnk_08300BCC
gUnk_08300BCC:
	.incbin "build/assets/unknown/data_08300BCC.bin"
	.incbin "build/assets/graphics/rl_08300DCC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083017E8.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083024A8.bin"
	.incbin "build/assets/graphics/rl_08302764.bin"
	.align 2, 0
	.global gUnk_08302E00
gUnk_08302E00:
	.incbin "build/assets/unknown/data_08302E00.bin"
	.incbin "build/assets/graphics/rl_08303000.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08303638.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_083040FC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08304558.bin"
	.global gUnk_083049FC
gUnk_083049FC:
	.incbin "build/assets/unknown/data_083049FC.bin"
	.incbin "build/assets/graphics/rl_08304BFC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0830531C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08305A8C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08305D8C.bin"
	.align 2, 0
	.global gUnk_08306238
gUnk_08306238:
	.incbin "build/assets/unknown/data_08306238.bin"
	.incbin "build/assets/graphics/rl_08306438.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08306D38.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08307ACC.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_08308110.bin"
	.align 2, 0
	.global gUnk_0830877C
gUnk_0830877C:
	.incbin "build/assets/unknown/data_0830877C.bin"
	.incbin "build/assets/graphics/rl_0830897C.bin"
	.incbin "build/assets/graphics/rl_083091D8.bin"
	.incbin "build/assets/graphics/rl_08309D28.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0830A550.bin"
	.align 2, 0
	.global gUnk_0830AB68
gUnk_0830AB68:
	.incbin "build/assets/unknown/data_0830AB68.bin"
	.incbin "build/assets/graphics/rl_0830AD68.bin"
	.incbin "build/assets/graphics/rl_0830B484.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0830BDF0.bin"
	.incbin "build/assets/graphics/rl_0830C23C.bin"
	.align 2, 0
	.global gUnk_0830CA10
gUnk_0830CA10:
	.incbin "build/assets/unknown/data_0830CA10.bin"
	.incbin "build/assets/graphics/rl_0830CC10.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0830D358.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0830DE8C.bin"
	.align 2, 0
	.incbin "build/assets/graphics/rl_0830E358.bin"
	.align 2, 0
	.global gUnk_0830E418
gUnk_0830E418:
	.incbin "build/assets/unknown/data_0830E418.bin"
	.incbin "build/assets/graphics/rl_0830E618.bin"
	.incbin "build/assets/unknown/data_0830E670.bin"
	.incbin "build/assets/graphics/rl_0830E690.bin"
	.align 2, 0
	.incbin "build/assets/unknown/data_0830E6EC.bin"
	.global gUnk_0830E70C
gUnk_0830E70C:
	.incbin "build/assets/graphics/rl_0830E70C.bin"
	.align 2, 0
