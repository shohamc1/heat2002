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
	thumb_func_start sub_0800383C
sub_0800383C:
	push {r4, r5, r6, lr}
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r3, _0800388C @ =0x0000FFFF
	adds r2, r0, #0x0
	ldrh r4, [r2, #0x00]
	adds r2, #0x02
	movs r5, #0x01
	cmp r5, r6
	bcs _08003884
	.global _08003850
_08003850:
	strh r4, [r1, #0x00]
	adds r1, #0x02
	cmp r4, r3
	bne _08003874
	ldrh r3, [r2, #0x00]
	adds r2, #0x02
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r3, #0x00
	beq _08003874
	.global _08003866
_08003866:
	strh r4, [r1, #0x00]
	adds r1, #0x02
	subs r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x00
	bne _08003866
	.global _08003874
_08003874:
	adds r3, r4, #0x0
	ldrh r4, [r2, #0x00]
	adds r2, #0x02
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, r6
	bcc _08003850
	.global _08003884
_08003884:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800388C
_0800388C: .4byte 0x0000FFFF
