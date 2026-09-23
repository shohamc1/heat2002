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
	thumb_func_start sub_080032AC
sub_080032AC:
	push {lr}
	add sp, #-0x004
	ldr r0, _080032C0 @ =0x0202EF90
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080032C4
	bl VBlankIntrWait
	b _080032D2
	.byte 0x00, 0x00
_080032C0: .4byte 0x0202EF90
_080032C4:
	ldr r2, _080032D8 @ =0x03007FF8
	movs r3, #0x80
_080032C8:
	ldrh r1, [r2, #0x00]
	adds r0, r3, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _080032C8
_080032D2:
	add sp, #0x004
	pop {r0}
	bx r0
_080032D8: .4byte 0x03007FF8
	thumb_func_start sub_080032DC
sub_080032DC:
	add sp, #-0x028
	add sp, #0x028
	bx lr
	.byte 0x00, 0x00
