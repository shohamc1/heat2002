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
	thumb_func_start sub_080078E4
sub_080078E4:
	push {r4, r5, r6, r7, lr}
	movs r2, #0x00
	ldr r7, _08007910 @ =0x02025ED0
	movs r0, #0x01
	mov r12, r0
	ldr r3, _08007914 @ =0x02025FE0
	movs r4, #0x00
	adds r6, r3, #0x0
	adds r6, #0x3C
	movs r5, #0x80
	lsls r5, r5, #0x01
	.global _080078FA
_080078FA:
	adds r1, r2, r7
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08007918
	mov r0, r12
	strb r0, [r1, #0x00]
	adds r0, r4, r6
	str r2, [r0, #0x00]
	adds r0, r3, #0x0
	b _08007924
	.byte 0x00, 0x00
	.global _08007910
_08007910: .4byte 0x02025ED0
	.global _08007914
_08007914: .4byte 0x02025FE0
	.global _08007918
_08007918:
	adds r3, #0x44
	adds r4, #0x44
	adds r2, #0x01
	cmp r2, r5
	bne _080078FA
	movs r0, #0x00
	.global _08007924
_08007924:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x02, 0x49, 0xC0, 0x6B, 0x40, 0x18, 0x00, 0x21, 0x01, 0x70, 0x70, 0x47, 0xD0, 0x5E
	.byte 0x02, 0x02
