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
	thumb_func_start sub_08010E04
sub_08010E04:
	push {r4, lr}
	add sp, #-0x00C
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0x9C
	bl sub_08016558
	bl sub_080065A8
	ldr r0, _08010E80 @ =0x0829F2AC
	movs r1, #0x00
	movs r2, #0x06
	movs r3, #0x00
	bl sub_080063BC
	ldr r1, _08010E84 @ =0x083FDB98
	lsls r0, r4, #0x03
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x06
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _08010E88 @ =0x083FDEF4
	lsls r4, r4, #0x02
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	ldr r1, _08010E8C @ =0x05000200
	movs r2, #0x80
	lsls r2, r2, #0x01
	bl sub_08016E10
	ldr r0, _08010E90 @ =0x083FDF74
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	ldr r1, _08010E94 @ =0x06010000
	bl sub_08016E28
	ldr r0, _08010E98 @ =0x083FDFEC
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x00]
	ldr r1, _08010E9C @ =0x06011000
	bl sub_08016E28
	movs r0, #0x38
	movs r1, #0x40
	movs r2, #0x00
	bl sub_08010194
	movs r0, #0x78
	movs r1, #0x40
	movs r2, #0x80
	bl sub_08010194
	add sp, #0x00C
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08010E80
_08010E80: .4byte 0x0829F2AC
	.global _08010E84
_08010E84: .4byte 0x083FDB98
	.global _08010E88
_08010E88: .4byte 0x083FDEF4
	.global _08010E8C
_08010E8C: .4byte 0x05000200
	.global _08010E90
_08010E90: .4byte 0x083FDF74
	.global _08010E94
_08010E94: .4byte 0x06010000
	.global _08010E98
_08010E98: .4byte 0x083FDFEC
	.global _08010E9C
_08010E9C: .4byte 0x06011000
