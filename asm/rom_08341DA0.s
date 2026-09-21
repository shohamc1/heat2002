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
	thumb_func_start sub_08341DA0
sub_08341DA0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	mov r12, r0
	ldrh r0, [r0, #0x34]
	lsrs r2, r0, #0x08
	ldr r0, _08341EBC @ =0x0200C3E8
	lsls r1, r2, #0x01
	adds r1, r1, r0
	movs r4, #0x00
	ldsh r3, [r1, r4]
	mov r9, r3
	adds r1, r2, #0x0
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r0
	movs r2, #0x00
	ldsh r5, [r1, r2]
	mov r8, r5
	movs r7, #0x00
	ldr r3, _08341EC0 @ =0x020277B4
	mov r10, r3
	.global _08341DD2
_08341DD2:
	lsls r4, r7, #0x02
	mov r5, r10
	adds r5, #0x04
	mov r10, r5
	subs r5, #0x04
	ldm r5!, {r6}
	ldr r1, _08341EC4 @ =0x020277C4
	adds r0, r4, r1
	ldr r5, [r0, #0x00]
	mov r3, r12
	adds r3, #0xA4
	adds r3, r3, r4
	mov r0, r8
	muls r0, r6
	mov r1, r9
	muls r1, r5
	subs r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	mov r2, r12
	adds r2, #0xB4
	adds r2, r2, r4
	mov r0, r9
	muls r0, r6
	mov r1, r8
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r2, #0x00]
	ldr r0, [r3, #0x00]
	mov r4, r12
	ldr r1, [r4, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	ldr r0, [r2, #0x00]
	ldr r1, [r4, #0x08]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r7, #0x01
	cmp r7, #0x04
	bne _08341DD2
	movs r5, #0x3C
	ldsh r0, [r4, r5]
	ldrh r1, [r4, #0x34]
	adds r0, r1, r0
	asrs r2, r0, #0x08
	movs r0, #0xFF
	ands r2, r0
	lsls r0, r2, #0x01
	ldr r3, _08341EBC @ =0x0200C3E8
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r4, [r0, r5]
	mov r9, r4
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r2, #0x00
	ldsh r1, [r0, r2]
	mov r8, r1
	movs r7, #0x00
	movs r3, #0xC4
	add r3, r12
	mov r10, r3
	mov r4, r12
	adds r4, #0xD4
	ldr r5, _08341EC0 @ =0x020277B4
	str r5, [sp, #0x000]
	.global _08341E5C
_08341E5C:
	lsls r2, r7, #0x02
	ldr r0, [sp, #0x000]
	ldm r0!, {r6}
	str r0, [sp, #0x000]
	ldr r1, _08341EC4 @ =0x020277C4
	adds r0, r2, r1
	ldr r5, [r0, #0x00]
	mov r0, r10
	adds r3, r0, r2
	mov r0, r8
	muls r0, r6
	mov r1, r9
	muls r1, r5
	subs r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	adds r2, r4, r2
	mov r0, r9
	muls r0, r6
	mov r1, r8
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r2, #0x00]
	mov r5, r12
	ldr r1, [r5, #0x00]
	ldr r0, [r5, #0x0C]
	adds r1, r1, r0
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	ldr r1, [r5, #0x08]
	ldr r0, [r5, #0x14]
	adds r1, r1, r0
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r7, #0x01
	cmp r7, #0x04
	bne _08341E5C
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08341EBC
_08341EBC: .4byte 0x0200C3E8
	.global _08341EC0
_08341EC0: .4byte 0x020277B4
	.global _08341EC4
_08341EC4: .4byte 0x020277C4
