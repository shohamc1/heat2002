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
	thumb_func_start sub_0800EEFC
sub_0800EEFC:
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, [sp, #0x014]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrb r0, [r5, #0x18]
	cmp r0, #0x00
	bne _0800EF36
	ldrb r0, [r5, #0x1E]
	cmp r0, #0x00
	beq _0800EF36
	adds r0, r5, #0x0
	adds r0, #0x4A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800EF36
	str r6, [r5, #0x20]
	adds r2, #0x0F
	movs r0, #0x10
	negs r0, r0
	ands r2, r0
	subs r0, #0xF0
	adds r1, r2, r0
	ldr r0, _0800EF40 @ =0x0003FF00
	cmp r1, r0
	bls _0800EF44
	.global _0800EF36
_0800EF36:
	adds r0, r5, #0x0
	bl sub_0800EA64
	b _0800EFB8
	.byte 0x00, 0x00
	.global _0800EF40
_0800EF40: .4byte 0x0003FF00
	.global _0800EF44
_0800EF44:
	adds r0, r6, r2
	str r0, [r5, #0x24]
	lsls r1, r7, #0x18
	movs r2, #0x80
	lsls r2, r2, #0x13
	adds r0, r1, r2
	asrs r0, r0, #0x18
	adds r2, r1, #0x0
	cmp r0, #0x08
	bhi _0800EFA4
	lsls r0, r0, #0x02
	ldr r1, _0800EF64 @ =0x0800EF68
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
	.global _0800EF64
_0800EF64: .4byte 0x0800EF68
	.byte 0x8C, 0xEF, 0x00, 0x08, 0x8C, 0xEF, 0x00, 0x08, 0x8C, 0xEF, 0x00, 0x08, 0x8C, 0xEF, 0x00, 0x08
	.byte 0x96, 0xEF, 0x00, 0x08, 0x9C, 0xEF, 0x00, 0x08, 0x9C, 0xEF, 0x00, 0x08, 0x9C, 0xEF, 0x00, 0x08
	.byte 0x9C, 0xEF, 0x00, 0x08, 0xDC, 0x00, 0x11, 0x16, 0x03, 0x20, 0x40, 0x1A, 0x05, 0xE0, 0x38, 0x20
	.byte 0x1C, 0x1C, 0x02, 0xE0, 0xDC, 0x00, 0x10, 0x16, 0x01, 0x38, 0x04, 0x43
	.global _0800EFA4
_0800EFA4:
	movs r0, #0x3F
	ands r4, r0
	lsls r0, r4, #0x01
	movs r2, #0x7F
	negs r2, r2
	adds r1, r2, #0x0
	orrs r0, r1
	strb r0, [r5, #0x1C]
	movs r0, #0xD0
	strb r0, [r5, #0x18]
	.global _0800EFB8
_0800EFB8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
