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
	thumb_func_start sub_0800C21C
sub_0800C21C:
	push {r4, r5, r6, lr}
	add sp, #-0x008
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	mov r2, sp
	bl sub_08009BB4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800C274
	ldr r0, [sp, #0x000]
	subs r0, #0x10
	str r0, [sp, #0x000]
	ldr r0, [sp, #0x004]
	subs r0, #0x10
	str r0, [sp, #0x004]
	ldr r0, _0800C27C @ =0x083FEF04
	bl sub_0800767C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0800C274
	ldr r0, _0800C280 @ =0x02002148
	ldr r0, [r0, #0x00]
	cmp r0, #0xFF
	ble _0800C26C
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	ldr r1, _0800C284 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x01
	orrs r4, r0
	lsls r0, r6, #0x0C
	ldr r5, [r2, #0x10]
	orrs r5, r0
	.global _0800C26C
_0800C26C:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_080044A4
	.global _0800C274
_0800C274:
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _0800C27C
_0800C27C: .4byte 0x083FEF04
	.global _0800C280
_0800C280: .4byte 0x02002148
	.global _0800C284
_0800C284: .4byte 0x000001FF
	.byte 0x70, 0x47, 0x00, 0x00
