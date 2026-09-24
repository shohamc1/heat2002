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
	thumb_func_start sub_0833A940
sub_0833A940:
	push {lr}
	lsls r0, r0, #0x10
	ldr r2, _0833A96C @ =0x0200CA74
	ldr r1, _0833A970 @ =0x0200CAA4
	lsrs r0, r0, #0x0D
	adds r0, r0, r1
	ldrh r3, [r0, #0x04]
	lsls r1, r3, #0x01
	adds r1, r1, r3
	lsls r1, r1, #0x02
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldr r3, [r1, #0x00]
	ldr r2, [r0, #0x00]
	cmp r3, r2
	beq _0833A974
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	bl sub_0833AFC0
	b _0833A990
	.byte 0x00, 0x00
_0833A96C: .4byte 0x0200CA74
_0833A970: .4byte 0x0200CAA4
_0833A974:
	ldr r2, [r1, #0x04]
	ldrh r0, [r1, #0x04]
	cmp r0, #0x00
	bne _0833A986
	adds r0, r1, #0x0
	adds r1, r3, #0x0
	bl sub_0833AFC0
	b _0833A990
_0833A986:
	cmp r2, #0x00
	bge _0833A990
	adds r0, r1, #0x0
	bl sub_0833A7F4
_0833A990:
	pop {r0}
	bx r0
