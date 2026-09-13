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
	thumb_func_start sub_08004980
sub_08004980:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x028
	adds r5, r0, #0x0
	ldr r0, _08004A00 @ =0x02025244
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080049F6
	movs r1, #0xBE
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r4, [r0, #0x00]
	ldr r1, [r5, #0x50]
	ldr r0, _08004A04 @ =0x0000FFFF
	ands r1, r0
	ldr r0, _08004A08 @ =0x02025254
	ldrh r0, [r0, #0x00]
	cmp r1, r0
	bls _080049A8
	cmp r0, #0x00
	bne _080049C8
	.global _080049A8
_080049A8:
	ldr r2, _08004A0C @ =0x0202524C
	movs r1, #0x00
	ldsb r1, [r2, r1]
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	beq _080049C8
	ldr r0, _08004A10 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080049C8
	ldrb r0, [r2, #0x00]
	ldr r1, _08004A14 @ =0x020251F8
	ldrh r1, [r1, #0x00]
	bl sub_080047E8
	.global _080049C8
_080049C8:
	ldr r1, [r5, #0x50]
	ldr r0, _08004A04 @ =0x0000FFFF
	ands r1, r0
	ldrh r0, [r4, #0x00]
	cmp r1, r0
	bcc _080049F6
	ldr r7, _08004A0C @ =0x0202524C
	ldr r6, _08004A14 @ =0x020251F8
	ldr r3, _08004A08 @ =0x02025254
	movs r0, #0xBE
	lsls r0, r0, #0x01
	adds r2, r5, r0
	.global _080049E0
_080049E0:
	ldrb r0, [r4, #0x02]
	strb r0, [r7, #0x00]
	ldrh r0, [r4, #0x04]
	strh r0, [r6, #0x00]
	ldrh r0, [r4, #0x06]
	strh r0, [r3, #0x00]
	adds r4, #0x08
	str r4, [r2, #0x00]
	ldrh r0, [r4, #0x00]
	cmp r1, r0
	bcs _080049E0
	.global _080049F6
_080049F6:
	add sp, #0x028
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08004A00
_08004A00: .4byte 0x02025244
	.global _08004A04
_08004A04: .4byte 0x0000FFFF
	.global _08004A08
_08004A08: .4byte 0x02025254
	.global _08004A0C
_08004A0C: .4byte 0x0202524C
	.global _08004A10
_08004A10: .4byte 0x020021E0
	.global _08004A14
_08004A14: .4byte 0x020251F8
