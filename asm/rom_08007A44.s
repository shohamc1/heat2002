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
	thumb_func_start sub_08007A44
sub_08007A44:
	push {r4, r5, lr}
	movs r3, #0x00
	ldr r1, _08007A74 @ =0x0202A550
	ldr r5, _08007A78 @ =0x00000175
	movs r4, #0xC8
	lsls r4, r4, #0x01
_08007A50:
	adds r0, r1, r5
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08007A5E
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_08007A5E:
	adds r1, r1, r4
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r1, r4
	cmp r3, #0x18
	bne _08007A50
	adds r0, r2, #0x0
	pop {r4, r5}
	pop {r1}
	bx r1
_08007A74: .4byte 0x0202A550
_08007A78: .4byte 0x00000175
