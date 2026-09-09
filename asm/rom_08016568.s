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
	.byte 0x30, 0xB5, 0x00, 0x04, 0x00, 0x0C, 0x09, 0x06, 0x09, 0x0E, 0x08, 0x4C, 0x46, 0x22, 0x42, 0x43
	.byte 0x07, 0x4B, 0x1D, 0x78, 0xE8, 0x00, 0x40, 0x1B, 0x40, 0x00, 0x12, 0x18, 0x52, 0x18, 0x92, 0x00
	.byte 0x12, 0x19, 0x10, 0x68, 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0xAC, 0xEC, 0x3F, 0x08
	.byte 0xD0, 0xED, 0x02, 0x02
	thumb_func_start sub_0801659C
sub_0801659C:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r2, r0, #0x11
	lsls r2, r2, #0x01
	ldr r3, _080165DC @ =0x0202F040
	adds r6, r2, r3
	lsrs r5, r1, #0x13
	lsrs r4, r0, #0x13
	cmp r5, #0x00
	beq _080165D4
	.global _080165B2
_080165B2:
	adds r0, r4, #0x0
	adds r1, r6, #0x0
	bl sub_080170B8
	adds r0, r4, #0x0
	adds r1, r6, #0x0
	bl sub_0801719C
	adds r6, #0x08
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	subs r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x00
	bne _080165B2
	.global _080165D4
_080165D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _080165DC
_080165DC: .4byte 0x0202F040
