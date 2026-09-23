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
	thumb_func_start sub_0833CC7C
sub_0833CC7C:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833CC80
sub_0833CC80:
	push {r4, r5, r6, lr}
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r3, _0833CCD0 @ =0x0000FFFF
	adds r2, r0, #0x0
	ldrh r4, [r2, #0x00]
	adds r2, #0x02
	movs r5, #0x01
	cmp r5, r6
	bcs _0833CCC8
_0833CC94:
	strh r4, [r1, #0x00]
	adds r1, #0x02
	cmp r4, r3
	bne _0833CCB8
	ldrh r3, [r2, #0x00]
	adds r2, #0x02
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r3, #0x00
	beq _0833CCB8
_0833CCAA:
	strh r4, [r1, #0x00]
	adds r1, #0x02
	subs r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x00
	bne _0833CCAA
_0833CCB8:
	adds r3, r4, #0x0
	ldrh r4, [r2, #0x00]
	adds r2, #0x02
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, r6
	bcc _0833CC94
_0833CCC8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0833CCD0: .4byte 0x0000FFFF
