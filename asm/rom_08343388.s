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
	thumb_func_start sub_08343388
sub_08343388:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0x0
	ldr r0, [r7, #0x08]
	mov r9, r0
	mov r2, r9
	lsls r2, r2, #0x14
	mov r9, r2
	asrs r2, r2, #0x14
	mov r8, r2
	str r2, [r7, #0x08]
	ldr r0, _08343414 @ =0x0202780C
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	asrs r1, r2, #0x1F
	ldr r4, [r7, #0x00]
	mov r10, r4
	mov r2, r10
	asrs r3, r2, #0x1F
	ldr r6, [r7, #0x04]
	adds r4, r6, #0x0
	asrs r5, r6, #0x1F
	subs r2, r2, r4
	sbcs r3, r5
	bl sub_08344D20
	bl sub_08344D90
	adds r5, r1, #0x0
	adds r4, r0, #0x0
	lsls r1, r5, #0x18
	lsrs r0, r4, #0x08
	adds r4, r1, #0x0
	orrs r4, r0
	ldr r0, _08343418 @ =0x02027808
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	asrs r1, r2, #0x1F
	mov r2, r8
	mov r6, r9
	asrs r3, r6, #0x1F
	bl sub_08344D20
	bl sub_08344D90
	lsls r3, r1, #0x18
	lsrs r2, r0, #0x08
	adds r0, r3, #0x0
	orrs r0, r2
	adds r4, r4, r0
	asrs r4, r4, #0x01
	add r8, r4
	mov r0, r8
	lsls r0, r0, #0x14
	asrs r0, r0, #0x14
	mov r8, r0
	str r0, [r7, #0x08]
	add r10, r8
	mov r2, r10
	str r2, [r7, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08343414: .4byte 0x0202780C
_08343418: .4byte 0x02027808
