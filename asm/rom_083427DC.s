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
	thumb_func_start sub_083427DC
sub_083427DC:
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x18]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _083427FC
	ldr r0, _083427F8 @ =0x0200D0F4
	movs r1, #0x0B
	movs r2, #0x0A
	bl sub_0833EF0C
	b _08342806
	.byte 0x00, 0x00
_083427F8: .4byte 0x0200D0F4
_083427FC:
	ldr r0, _08342854 @ =0x0200D100
	movs r1, #0x0B
	movs r2, #0x0A
	bl sub_0833EF0C
_08342806:
	ldr r0, [r4, #0x18]
	subs r0, #0x01
	str r0, [r4, #0x18]
	bl sub_08339B4C
	ldr r1, _08342858 @ =0x02037618
	ldr r0, _0834285C @ =0x000003FF
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08342822
	ldr r0, [r4, #0x18]
	cmp r0, #0x00
	bne _0834284C
_08342822:
	movs r0, #0x0A
	movs r1, #0x00
	bl sub_0833D288
	bl sub_08339B18
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2, #0x00]
	ldr r0, _08342860 @ =0x0000EFFF
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r1, _08342864 @ =0x020391F0
	movs r0, #0x02
	strb r0, [r1, #0x00]
	adds r0, r4, #0x0
	bl sub_0833FFA8
	adds r0, r4, #0x0
	bl sub_0833FF84
_0834284C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08342854: .4byte 0x0200D100
_08342858: .4byte 0x02037618
_0834285C: .4byte 0x000003FF
_08342860: .4byte 0x0000EFFF
_08342864: .4byte 0x020391F0
