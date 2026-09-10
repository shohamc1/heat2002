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
	thumb_func_start sub_080123F8
sub_080123F8:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, _08012520 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x34
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x35
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x00
	bne _0801241C
	movs r3, #0x01
	.global _0801241C
_0801241C:
	movs r1, #0x03
	movs r2, #0x05
	bl sub_080063BC
	movs r0, #0x38
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x01
	bne _08012432
	movs r3, #0x01
	.global _08012432
_08012432:
	movs r1, #0x03
	movs r2, #0x07
	bl sub_080063BC
	movs r0, #0x3A
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x02
	bne _08012448
	movs r3, #0x01
	.global _08012448
_08012448:
	movs r1, #0x03
	movs r2, #0x09
	bl sub_080063BC
	movs r0, #0x3B
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x03
	bne _0801245E
	movs r3, #0x01
	.global _0801245E
_0801245E:
	movs r1, #0x03
	movs r2, #0x0B
	bl sub_080063BC
	movs r0, #0xBF
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x04
	bne _08012474
	movs r3, #0x01
	.global _08012474
_08012474:
	movs r1, #0x03
	movs r2, #0x0D
	bl sub_080063BC
	ldr r0, _08012524 @ =0x0829F354
	movs r3, #0x00
	cmp r4, #0x05
	bne _08012486
	movs r3, #0x01
	.global _08012486
_08012486:
	movs r1, #0x03
	movs r2, #0x0F
	bl sub_080063BC
	ldr r0, _08012528 @ =0x0829F368
	movs r3, #0x00
	cmp r4, #0x00
	bne _08012498
	movs r3, #0x01
	.global _08012498
_08012498:
	movs r1, #0x15
	movs r2, #0x05
	bl sub_080063BC
	ldr r5, _0801252C @ =0x0202EF00
	ldrb r0, [r5, #0x00]
	adds r0, #0x3D
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x00
	bne _080124B2
	movs r3, #0x01
	.global _080124B2
_080124B2:
	movs r1, #0x15
	movs r2, #0x05
	bl sub_080063BC
	ldrb r0, [r5, #0x01]
	adds r0, #0xB6
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x01
	bne _080124CA
	movs r3, #0x01
	.global _080124CA
_080124CA:
	movs r1, #0x15
	movs r2, #0x07
	bl sub_080063BC
	ldrb r0, [r5, #0x02]
	adds r0, #0x41
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x02
	bne _080124E2
	movs r3, #0x01
	.global _080124E2
_080124E2:
	movs r1, #0x15
	movs r2, #0x09
	bl sub_080063BC
	ldrb r0, [r5, #0x03]
	adds r0, #0x41
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x03
	bne _080124FA
	movs r3, #0x01
	.global _080124FA
_080124FA:
	movs r1, #0x15
	movs r2, #0x0B
	bl sub_080063BC
	ldrb r0, [r5, #0x04]
	adds r0, #0x41
	bl sub_08016558
	movs r3, #0x00
	cmp r4, #0x04
	bne _08012512
	movs r3, #0x01
	.global _08012512
_08012512:
	movs r1, #0x15
	movs r2, #0x0D
	bl sub_080063BC
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08012520
_08012520: .4byte 0x083FDE18
	.global _08012524
_08012524: .4byte 0x0829F354
	.global _08012528
_08012528: .4byte 0x0829F368
	.global _0801252C
_0801252C: .4byte 0x0202EF00
