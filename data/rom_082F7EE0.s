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
	.global gUnk_082F7EE0
gUnk_082F7EE0:
	.incbin "build/assets/graphics/rl_082F7EE0.bin"
	.align 2, 0
	.global gUnk_082F8828
gUnk_082F8828:
	.incbin "build/assets/graphics/rl_082F8828.bin"
	.global gUnk_082F8F6C
gUnk_082F8F6C:
	.incbin "build/assets/graphics/rl_082F8F6C.bin"
	.align 2, 0
	.global gUnk_082F9360
gUnk_082F9360:
	.incbin "build/assets/graphics/rl_082F9360.bin"
	.align 2, 0
	.global gUnk_082F98C0
gUnk_082F98C0:
	.incbin "build/assets/graphics/palettes/pal_082F98C0.pal.bin"
	.global gUnk_082F9AC0
gUnk_082F9AC0:
	.incbin "build/assets/graphics/rl_082F9AC0.bin"
	.align 2, 0
	.global gUnk_082FA444
gUnk_082FA444:
	.incbin "build/assets/graphics/rl_082FA444.bin"
	.align 2, 0
	.global gUnk_082FAE24
gUnk_082FAE24:
	.incbin "build/assets/graphics/rl_082FAE24.bin"
	.align 2, 0
	.global gUnk_082FB3FC
gUnk_082FB3FC:
	.incbin "build/assets/graphics/rl_082FB3FC.bin"
	.align 2, 0
	.global gUnk_082FB6AC
gUnk_082FB6AC:
	.incbin "build/assets/graphics/palettes/pal_082FB6AC.pal.bin"
	.global gUnk_082FB8AC
gUnk_082FB8AC:
	.incbin "build/assets/graphics/rl_082FB8AC.bin"
	.global gUnk_082FC150
gUnk_082FC150:
	.incbin "build/assets/graphics/rl_082FC150.bin"
	.align 2, 0
	.global gUnk_082FCA94
gUnk_082FCA94:
	.incbin "build/assets/graphics/rl_082FCA94.bin"
	.global gUnk_082FCAD8
gUnk_082FCAD8:
	.incbin "build/assets/graphics/rl_082FCAD8.bin"
	.align 2, 0
	.global gUnk_082FD0F8
gUnk_082FD0F8:
	.incbin "build/assets/graphics/palettes/pal_082FD0F8.pal.bin"
	.global gUnk_082FD2F8
gUnk_082FD2F8:
	.incbin "build/assets/graphics/rl_082FD2F8.bin"
	.global gUnk_082FDFE0
gUnk_082FDFE0:
	.incbin "build/assets/graphics/rl_082FDFE0.bin"
	.global gUnk_082FEB60
gUnk_082FEB60:
	.incbin "build/assets/graphics/rl_082FEB60.bin"
	.align 2, 0
	.global gUnk_082FEDC4
gUnk_082FEDC4:
	.incbin "build/assets/graphics/rl_082FEDC4.bin"
	.align 2, 0
	.global gUnk_082FF41C
gUnk_082FF41C:
	.incbin "build/assets/graphics/palettes/pal_082FF41C.pal.bin"
	.global gUnk_082FF61C
gUnk_082FF61C:
	.incbin "build/assets/graphics/rl_082FF61C.bin"
	.align 2, 0
	.global gUnk_082FFD38
gUnk_082FFD38:
	.incbin "build/assets/graphics/rl_082FFD38.bin"
	.global gUnk_083004A4
gUnk_083004A4:
	.incbin "build/assets/graphics/rl_083004A4.bin"
	.align 2, 0
	.global gUnk_0830076C
gUnk_0830076C:
	.incbin "build/assets/graphics/rl_0830076C.bin"
	.align 2, 0
	.global gUnk_08300BCC
gUnk_08300BCC:
	.incbin "build/assets/graphics/palettes/pal_08300BCC.pal.bin"
	.global gUnk_08300DCC
gUnk_08300DCC:
	.incbin "build/assets/graphics/rl_08300DCC.bin"
	.align 2, 0
	.global gUnk_083017E8
gUnk_083017E8:
	.incbin "build/assets/graphics/rl_083017E8.bin"
	.align 2, 0
	.global gUnk_083024A8
gUnk_083024A8:
	.incbin "build/assets/graphics/rl_083024A8.bin"
	.global gUnk_08302764
gUnk_08302764:
	.incbin "build/assets/graphics/rl_08302764.bin"
	.align 2, 0
	.global gUnk_08302E00
gUnk_08302E00:
	.incbin "build/assets/graphics/palettes/pal_08302E00.pal.bin"
	.global gUnk_08303000
gUnk_08303000:
	.incbin "build/assets/graphics/rl_08303000.bin"
	.align 2, 0
	.global gUnk_08303638
gUnk_08303638:
	.incbin "build/assets/graphics/rl_08303638.bin"
	.align 2, 0
	.global gUnk_083040FC
gUnk_083040FC:
	.incbin "build/assets/graphics/rl_083040FC.bin"
	.align 2, 0
	.global gUnk_08304558
gUnk_08304558:
	.incbin "build/assets/graphics/rl_08304558.bin"
	.global gUnk_083049FC
gUnk_083049FC:
	.incbin "build/assets/graphics/palettes/pal_083049FC.pal.bin"
	.global gUnk_08304BFC
gUnk_08304BFC:
	.incbin "build/assets/graphics/rl_08304BFC.bin"
	.align 2, 0
	.global gUnk_0830531C
gUnk_0830531C:
	.incbin "build/assets/graphics/rl_0830531C.bin"
	.align 2, 0
	.global gUnk_08305A8C
gUnk_08305A8C:
	.incbin "build/assets/graphics/rl_08305A8C.bin"
	.align 2, 0
	.global gUnk_08305D8C
gUnk_08305D8C:
	.incbin "build/assets/graphics/rl_08305D8C.bin"
	.align 2, 0
	.global gUnk_08306238
gUnk_08306238:
	.incbin "build/assets/graphics/palettes/pal_08306238.pal.bin"
	.global gUnk_08306438
gUnk_08306438:
	.incbin "build/assets/graphics/rl_08306438.bin"
	.align 2, 0
	.global gUnk_08306D38
gUnk_08306D38:
	.incbin "build/assets/graphics/rl_08306D38.bin"
	.align 2, 0
	.global gUnk_08307ACC
gUnk_08307ACC:
	.incbin "build/assets/graphics/rl_08307ACC.bin"
	.align 2, 0
	.global gUnk_08308110
gUnk_08308110:
	.incbin "build/assets/graphics/rl_08308110.bin"
	.align 2, 0
	.global gUnk_0830877C
gUnk_0830877C:
	.incbin "build/assets/graphics/palettes/pal_0830877C.pal.bin"
	.global gUnk_0830897C
gUnk_0830897C:
	.incbin "build/assets/graphics/rl_0830897C.bin"
	.global gUnk_083091D8
gUnk_083091D8:
	.incbin "build/assets/graphics/rl_083091D8.bin"
	.global gUnk_08309D28
gUnk_08309D28:
	.incbin "build/assets/graphics/rl_08309D28.bin"
	.align 2, 0
	.global gUnk_0830A550
gUnk_0830A550:
	.incbin "build/assets/graphics/rl_0830A550.bin"
	.align 2, 0
	.global gUnk_0830AB68
gUnk_0830AB68:
	.incbin "build/assets/graphics/palettes/pal_0830AB68.pal.bin"
	.global gUnk_0830AD68
gUnk_0830AD68:
	.incbin "build/assets/graphics/rl_0830AD68.bin"
	.global gUnk_0830B484
gUnk_0830B484:
	.incbin "build/assets/graphics/rl_0830B484.bin"
	.align 2, 0
	.global gUnk_0830BDF0
gUnk_0830BDF0:
	.incbin "build/assets/graphics/rl_0830BDF0.bin"
	.global gUnk_0830C23C
gUnk_0830C23C:
	.incbin "build/assets/graphics/rl_0830C23C.bin"
	.align 2, 0
	.global gUnk_0830CA10
gUnk_0830CA10:
	.incbin "build/assets/graphics/palettes/pal_0830CA10.pal.bin"
	.global gUnk_0830CC10
gUnk_0830CC10:
	.incbin "build/assets/graphics/rl_0830CC10.bin"
	.align 2, 0
	.global gUnk_0830D358
gUnk_0830D358:
	.incbin "build/assets/graphics/rl_0830D358.bin"
	.align 2, 0
	.global gUnk_0830DE8C
gUnk_0830DE8C:
	.incbin "build/assets/graphics/rl_0830DE8C.bin"
	.align 2, 0
	.global gUnk_0830E358
gUnk_0830E358:
	.incbin "build/assets/graphics/rl_0830E358.bin"
	.align 2, 0
	.global gUnk_0830E418
gUnk_0830E418:
	.incbin "build/assets/graphics/palettes/pal_0830E418.pal.bin"
	.global gTrackSelectLeftArrowGfx
gTrackSelectLeftArrowGfx:
	.incbin "build/assets/graphics/rl_0830E618.bin"
