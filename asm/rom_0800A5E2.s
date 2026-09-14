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
	.byte 0x70, 0xB5, 0x03, 0x1C, 0x98, 0x8E, 0x01, 0x0A, 0x96, 0x20, 0x40, 0x00, 0x1E, 0x18
	.byte 0x30, 0x68, 0x02, 0x12, 0x0D, 0x1C, 0x30, 0x3D, 0x0C, 0x1C, 0x30, 0x34, 0x8A, 0x42, 0x08, 0xDD
	.byte 0x08, 0x1C, 0x80, 0x30, 0x82, 0x42, 0x04, 0xDA, 0xA2, 0x42, 0x09, 0xDD, 0x20, 0x02, 0x30, 0x60
	.byte 0x06, 0xE0, 0xAA, 0x42, 0x04, 0xDA, 0x96, 0x20, 0x40, 0x00, 0x19, 0x18, 0x28, 0x02, 0x08, 0x60
	.byte 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47
	thumb_func_start sub_0800A628
sub_0800A628:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r12, r0
	ldrh r1, [r0, #0x34]
	lsrs r0, r1, #0x0A
	lsls r0, r0, #0x10
	mov r9, r0
	lsrs r2, r0, #0x0E
	ldr r7, _0800A6D8 @ =0x0801CD08
	lsls r0, r2, #0x01
	adds r0, r0, r7
	movs r1, #0x00
	ldsh r3, [r0, r1]
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r7
	movs r1, #0x00
	ldsh r2, [r0, r1]
	ldr r1, _0800A6DC @ =0xFFFFFF00
	adds r0, r3, #0x0
	muls r0, r1
	negs r0, r0
	asrs r5, r0, #0x08
	adds r0, r2, #0x0
	muls r0, r1
	asrs r4, r0, #0x08
	movs r6, #0x96
	lsls r6, r6, #0x01
	add r6, r12
	ldr r0, [r6, #0x00]
	asrs r2, r0, #0x0A
	movs r0, #0x3F
	ands r2, r0
	lsls r2, r2, #0x02
	lsls r0, r2, #0x01
	adds r3, r0, r7
	movs r0, #0x00
	ldsh r3, [r3, r0]
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r2, r0, r7
	movs r0, #0x00
	ldsh r2, [r2, r0]
	adds r0, r3, #0x0
	muls r0, r1
	negs r0, r0
	asrs r0, r0, #0x08
	mov r8, r0
	adds r0, r2, #0x0
	muls r0, r1
	asrs r3, r0, #0x08
	mov r0, r8
	muls r0, r5
	adds r1, r4, #0x0
	muls r1, r3
	adds r0, r0, r1
	asrs r0, r0, #0x08
	cmp r0, #0x8D
	bgt _0800A6FA
	mov r1, r9
	lsrs r2, r1, #0x0E
	lsls r1, r2, #0x01
	adds r1, r1, r7
	adds r0, r2, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r7
	movs r2, #0x00
	ldsh r5, [r0, r2]
	movs r0, #0x00
	ldsh r4, [r1, r0]
	mov r0, r8
	muls r0, r5
	adds r1, r4, #0x0
	muls r1, r3
	adds r0, r0, r1
	cmp r0, #0x00
	bge _0800A6E4
	mov r1, r12
	ldrh r1, [r1, #0x34]
	ldr r2, _0800A6E0 @ =0xFFFFD800
	adds r0, r1, r2
	b _0800A6EE
	.byte 0x00, 0x00
	.global _0800A6D8
_0800A6D8: .4byte 0x0801CD08
	.global _0800A6DC
_0800A6DC: .4byte 0xFFFFFF00
	.global _0800A6E0
_0800A6E0: .4byte 0xFFFFD800
	.global _0800A6E4
_0800A6E4:
	mov r3, r12
	ldrh r3, [r3, #0x34]
	movs r1, #0xA0
	lsls r1, r1, #0x06
	adds r0, r3, r1
	.global _0800A6EE
_0800A6EE:
	str r0, [r6, #0x00]
	movs r1, #0x96
	lsls r1, r1, #0x01
	add r1, r12
	ldrh r0, [r1, #0x00]
	str r0, [r1, #0x00]
	.global _0800A6FA
_0800A6FA:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
