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
	.global gUnk_083FF724
gUnk_083FF724:
	.4byte gUnk_083378A0
	.4byte gUnk_08337920
	.4byte gUnk_083379A0
	.4byte gUnk_08337A20
	.4byte gUnk_08337AA0
	.4byte gUnk_08337B20
	.4byte gUnk_08337BA0
	.global gUnk_083FF740
gUnk_083FF740:
	.4byte gUnk_08337C40
	.4byte gUnk_08337CC0
	.4byte gUnk_08337D40
	.4byte gUnk_08337DC0
	.4byte gUnk_08337E40
	.4byte gUnk_08337EC0
	.4byte gUnk_08337F40
	.global gUnk_083FF75C
gUnk_083FF75C:
	.4byte gUnk_08337FE0
	.4byte gUnk_08338060
	.4byte gUnk_083380E0
	.4byte gUnk_08338160
	.4byte gUnk_083381E0
	.4byte gUnk_08338260
	.4byte gUnk_083382E0
	.global gUnk_083FF778
gUnk_083FF778:
	.4byte gUnk_08338380
	.4byte gUnk_08338400
	.4byte gUnk_08338480
	.4byte gUnk_08338500
	.4byte gUnk_08338580
	.4byte gUnk_08338600
	.4byte gUnk_08338680
	.4byte gUnk_08338720
	.4byte gUnk_083387A8
