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
	thumb_func_start sub_0833D4A4
sub_0833D4A4:
	push {r4, r5, r6, r7, lr}
	ldr r6, _0833D4DC @ =0x020392D0
	ldr r5, _0833D4E0 @ =0x0203AAD0
	movs r4, #0x00
	movs r3, #0x1F
	movs r7, #0x80
	lsls r7, r7, #0x01
	.global _0833D4B2
_0833D4B2:
	ldm r6!, {r0}
	ldm r6!, {r1}
	ldm r6!, {r2}
	asrs r0, r0, #0x10
	asrs r1, r1, #0x10
	asrs r2, r2, #0x10
	ands r0, r3
	ands r1, r3
	ands r2, r3
	lsls r1, r1, #0x05
	orrs r0, r1
	lsls r2, r2, #0x0A
	orrs r0, r2
	strh r0, [r5, #0x00]
	adds r5, #0x02
	adds r4, #0x01
	cmp r4, r7
	bne _0833D4B2
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0833D4DC
_0833D4DC: .4byte 0x020392D0
	.global _0833D4E0
_0833D4E0: .4byte 0x0203AAD0
