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
	thumb_func_start sub_0800E75C
sub_0800E75C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0800E870 @ =0x0801CD08
	mov r8, r0
	ldr r5, _0800E874 @ =0x02024F40
	ldrh r0, [r5, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	add r0, r8
	movs r1, #0x00
	ldsh r4, [r0, r1]
	ldr r6, _0800E878 @ =0x0202E948
	movs r3, #0x00
	ldsh r0, [r6, r3]
	bl sub_08000358
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl sub_08000328
	ldr r4, _0800E87C @ =0x0202ED68
	strh r0, [r4, #0x00]
	ldr r7, _0800E880 @ =0x0202E91C
	ldrh r1, [r5, #0x00]
	lsls r0, r1, #0x01
	add r0, r8
	movs r3, #0x00
	ldsh r4, [r0, r3]
	movs r1, #0x00
	ldsh r0, [r6, r1]
	bl sub_08000358
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl sub_08000328
	strh r0, [r7, #0x00]
	ldr r3, _0800E884 @ =0x0202E950
	mov r10, r3
	ldrh r4, [r5, #0x00]
	lsls r0, r4, #0x01
	add r0, r8
	ldrh r0, [r0, #0x00]
	negs r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r6, _0800E888 @ =0x0202E930
	movs r1, #0x00
	ldsh r0, [r6, r1]
	bl sub_08000358
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl sub_08000328
	mov r3, r10
	strh r0, [r3, #0x00]
	ldr r4, _0800E88C @ =0x0202E928
	mov r9, r4
	ldrh r0, [r5, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	add r0, r8
	movs r1, #0x00
	ldsh r4, [r0, r1]
	movs r3, #0x00
	ldsh r0, [r6, r3]
	bl sub_08000358
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl sub_08000328
	mov r4, r9
	strh r0, [r4, #0x00]
	ldr r2, _0800E890 @ =0x0202E960
	ldr r3, _0800E87C @ =0x0202ED68
	ldrh r1, [r3, #0x00]
	strh r1, [r2, #0x06]
	ldrh r1, [r7, #0x00]
	strh r1, [r2, #0x0E]
	mov r4, r10
	ldrh r1, [r4, #0x00]
	strh r1, [r2, #0x16]
	strh r0, [r2, #0x1E]
	ldr r0, _0800E894 @ =0xFFFFFE00
	ldrh r1, [r2, #0x12]
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r2, #0x12]
	movs r0, #0x54
	strb r0, [r2, #0x10]
	movs r3, #0xC0
	ldrb r4, [r2, #0x13]
	orrs r3, r4
	movs r0, #0x0F
	ldrb r1, [r2, #0x15]
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	strb r0, [r2, #0x15]
	ldr r0, _0800E898 @ =0xFFFFFC00
	ldrh r4, [r2, #0x14]
	ands r0, r4
	ldr r4, _0800E89C @ =0x000002E2
	adds r1, r4, #0x0
	orrs r0, r1
	strh r0, [r2, #0x14]
	movs r0, #0x04
	negs r0, r0
	ldrb r1, [r2, #0x11]
	ands r0, r1
	movs r1, #0x01
	orrs r0, r1
	strb r0, [r2, #0x11]
	movs r0, #0x0F
	negs r0, r0
	ands r3, r0
	strb r3, [r2, #0x13]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0800E870: .4byte 0x0801CD08
_0800E874: .4byte 0x02024F40
_0800E878: .4byte 0x0202E948
_0800E87C: .4byte 0x0202ED68
_0800E880: .4byte 0x0202E91C
_0800E884: .4byte 0x0202E950
_0800E888: .4byte 0x0202E930
_0800E88C: .4byte 0x0202E928
_0800E890: .4byte 0x0202E960
_0800E894: .4byte 0xFFFFFE00
_0800E898: .4byte 0xFFFFFC00
_0800E89C: .4byte 0x000002E2
	thumb_func_start sub_0800E8A0
sub_0800E8A0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0800E9B8 @ =0x0801CD08
	mov r8, r0
	ldr r5, _0800E9BC @ =0x0202E938
	ldrh r0, [r5, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	add r0, r8
	movs r1, #0x00
	ldsh r4, [r0, r1]
	ldr r6, _0800E9C0 @ =0x0202E948
	movs r3, #0x00
	ldsh r0, [r6, r3]
	bl sub_08000358
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl sub_08000328
	ldr r4, _0800E9C4 @ =0x0202CEF0
	strh r0, [r4, #0x00]
	ldr r7, _0800E9C8 @ =0x0202E918
	ldrh r1, [r5, #0x00]
	lsls r0, r1, #0x01
	add r0, r8
	movs r3, #0x00
	ldsh r4, [r0, r3]
	movs r1, #0x00
	ldsh r0, [r6, r1]
	bl sub_08000358
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl sub_08000328
	strh r0, [r7, #0x00]
	ldr r3, _0800E9CC @ =0x0202E924
	mov r10, r3
	ldrh r4, [r5, #0x00]
	lsls r0, r4, #0x01
	add r0, r8
	ldrh r0, [r0, #0x00]
	negs r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r6, _0800E9D0 @ =0x0202E930
	movs r1, #0x00
	ldsh r0, [r6, r1]
	bl sub_08000358
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl sub_08000328
	mov r3, r10
	strh r0, [r3, #0x00]
	ldr r4, _0800E9D4 @ =0x0202E900
	mov r9, r4
	ldrh r0, [r5, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	add r0, r8
	movs r1, #0x00
	ldsh r4, [r0, r1]
	movs r3, #0x00
	ldsh r0, [r6, r3]
	bl sub_08000358
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl sub_08000328
	mov r4, r9
	strh r0, [r4, #0x00]
	ldr r2, _0800E9D8 @ =0x0202E960
	ldr r3, _0800E9C4 @ =0x0202CEF0
	ldrh r1, [r3, #0x00]
	strh r1, [r2, #0x26]
	ldrh r1, [r7, #0x00]
	strh r1, [r2, #0x2E]
	mov r4, r10
	ldrh r1, [r4, #0x00]
	strh r1, [r2, #0x36]
	strh r0, [r2, #0x3E]
	ldr r0, _0800E9DC @ =0xFFFFFE00
	ldrh r1, [r2, #0x1A]
	ands r0, r1
	movs r1, #0x90
	orrs r0, r1
	strh r0, [r2, #0x1A]
	movs r0, #0x54
	strb r0, [r2, #0x18]
	movs r3, #0xC0
	ldrb r4, [r2, #0x1B]
	orrs r3, r4
	movs r0, #0x0F
	ldrb r1, [r2, #0x1D]
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	strb r0, [r2, #0x1D]
	ldr r0, _0800E9E0 @ =0xFFFFFC00
	ldrh r4, [r2, #0x1C]
	ands r0, r4
	ldr r4, _0800E9E4 @ =0x000002E2
	adds r1, r4, #0x0
	orrs r0, r1
	strh r0, [r2, #0x1C]
	movs r0, #0x04
	negs r0, r0
	ldrb r1, [r2, #0x19]
	ands r0, r1
	movs r1, #0x01
	orrs r0, r1
	strb r0, [r2, #0x19]
	movs r0, #0x0F
	negs r0, r0
	ands r3, r0
	movs r0, #0x02
	orrs r3, r0
	strb r3, [r2, #0x1B]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0800E9B8: .4byte 0x0801CD08
_0800E9BC: .4byte 0x0202E938
_0800E9C0: .4byte 0x0202E948
_0800E9C4: .4byte 0x0202CEF0
_0800E9C8: .4byte 0x0202E918
_0800E9CC: .4byte 0x0202E924
_0800E9D0: .4byte 0x0202E930
_0800E9D4: .4byte 0x0202E900
_0800E9D8: .4byte 0x0202E960
_0800E9DC: .4byte 0xFFFFFE00
_0800E9E0: .4byte 0xFFFFFC00
_0800E9E4: .4byte 0x000002E2
