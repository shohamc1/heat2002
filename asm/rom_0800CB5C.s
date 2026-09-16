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
	.byte 0x00, 0xB5, 0x02, 0x1C, 0x42, 0x43, 0x08, 0x1C, 0x48, 0x43, 0x10, 0x18, 0xFF, 0xF7, 0xA4, 0xFF
	.byte 0x02, 0xBC, 0x08, 0x47
	thumb_func_start sub_0800CB70
sub_0800CB70:
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r3, r1, #0x0
	ldr r6, _0800CBA4 @ =0x0200209C
	movs r0, #0x9C
	lsls r0, r0, #0x01
	adds r5, r4, r0
	ldr r1, [r6, #0x00]
	ldr r0, [r5, #0x00]
	cmp r1, r0
	beq _0800CBA8
	adds r0, r3, #0x0
	adds r1, r2, #0x0
	bl sub_0800CBB8
	movs r2, #0x9A
	lsls r2, r2, #0x01
	adds r1, r4, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1, #0x00]
	ldr r0, [r6, #0x00]
	str r0, [r5, #0x00]
	ldrb r0, [r1, #0x00]
	b _0800CBB0
	.byte 0x00, 0x00
	.global _0800CBA4
_0800CBA4: .4byte 0x0200209C
	.global _0800CBA8
_0800CBA8:
	movs r1, #0x9A
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	.global _0800CBB0
_0800CBB0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
