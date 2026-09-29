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
	@ 0x08345390-0x083453C0 (EWRAM 0x0200C910): the high module's m4a
	@ ply_xcmd dispatch table, the twin of the low copy in rom_0801CF88.s;
	@ module_ply_xcmd.c reads it as gUnk_0200C910 (symbols.ld alias).
	.global gUnk_08345390
gUnk_08345390:
	.4byte ModulePlyXxx
	.4byte ModulePlyXwave
	.4byte ModulePlyXtype
	.4byte ModulePlyXxx
	.4byte ModulePlyXatta
	.4byte ModulePlyXdeca
	.4byte ModulePlyXsust
	.4byte ModulePlyXrele
	.4byte ModulePlyXiecv
	.4byte ModulePlyXiecl
	.4byte ModulePlyXleng
	.4byte ModulePlyXswee
