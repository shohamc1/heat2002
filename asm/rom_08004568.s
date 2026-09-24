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
	thumb_func_start sub_08004568
sub_08004568:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0x0
	mov r12, r1
	adds r5, r2, #0x0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	ldr r4, _080045B8 @ =0x02025150
	movs r0, #0x00
	ldsb r0, [r4, r0]
	cmp r0, #0x00
	blt _080045C4
	ldr r3, _080045BC @ =0x02025154
	ldrb r0, [r3, #0x00]
	cmp r0, #0x1E
	bhi _080045C4
	ldr r2, _080045C0 @ =0x02024C30
	ldr r1, [r2, #0x00]
	lsls r0, r0, #0x19
	orrs r0, r6
	str r0, [r1, #0x00]
	mov r7, r12
	str r7, [r1, #0x04]
	negs r0, r5
	strh r0, [r1, #0x08]
	strh r5, [r1, #0x0A]
	mov r0, r8
	strh r0, [r1, #0x0C]
	adds r1, #0x10
	str r1, [r2, #0x00]
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	strb r0, [r4, #0x00]
	ldrb r0, [r3, #0x00]
	adds r0, #0x01
	strb r0, [r3, #0x00]
	movs r0, #0x01
	b _080045C6
_080045B8: .4byte 0x02025150
_080045BC: .4byte 0x02025154
_080045C0: .4byte 0x02024C30
_080045C4:
	movs r0, #0x00
_080045C6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
