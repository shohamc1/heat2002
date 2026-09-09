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
	thumb_func_start sub_0833DC14
sub_0833DC14:
	push {lr}
	movs r0, #0x03
	bl sub_0833BD94
	movs r1, #0x08
	movs r2, #0x01
	bl sub_0833EE88
	ldr r0, _0833DC38 @ =0x0203B850
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _0833DC50
	cmp r0, #0x01
	bgt _0833DC3C
	cmp r0, #0x00
	beq _0833DC46
	b _0833DC72
	.byte 0x00, 0x00
	.global _0833DC38
_0833DC38: .4byte 0x0203B850
	.global _0833DC3C
_0833DC3C:
	cmp r0, #0x02
	beq _0833DC58
	cmp r0, #0x03
	beq _0833DC68
	b _0833DC72
	.global _0833DC46
_0833DC46:
	ldr r0, _0833DC4C @ =0x0200CEEC
	b _0833DC5A
	.byte 0x00, 0x00
	.global _0833DC4C
_0833DC4C: .4byte 0x0200CEEC
	.global _0833DC50
_0833DC50:
	ldr r0, _0833DC54 @ =0x0200CEF8
	b _0833DC5A
	.global _0833DC54
_0833DC54: .4byte 0x0200CEF8
	.global _0833DC58
_0833DC58:
	ldr r0, _0833DC64 @ =0x0200CF04
	.global _0833DC5A
_0833DC5A:
	movs r1, #0x09
	movs r2, #0x01
	bl sub_0833EE88
	b _0833DC72
	.global _0833DC64
_0833DC64: .4byte 0x0200CF04
	.global _0833DC68
_0833DC68:
	ldr r0, _0833DC78 @ =0x0200CF10
	movs r1, #0x09
	movs r2, #0x01
	bl sub_0833EE88
	.global _0833DC72
_0833DC72:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833DC78
_0833DC78: .4byte 0x0200CF10
