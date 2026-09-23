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
	thumb_func_start sub_080069D8
sub_080069D8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r5, r0, #0x10
	lsls r4, r1, #0x10
	lsls r2, r2, #0x10
	lsls r3, r3, #0x10
	subs r2, r2, r5
	asrs r2, r2, #0x04
	mov r8, r2
	subs r3, r3, r4
	asrs r7, r3, #0x04
	movs r6, #0x00
_080069F2:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x02
	bl sub_0800C21C
	add r5, r8
	adds r4, r4, r7
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x10
	bne _080069F2
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
