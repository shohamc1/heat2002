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
	thumb_func_start sub_0800DE9C
sub_0800DE9C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r0, _0800DF44 @ =0x0202E960
	mov r12, r0
	mov r1, r12
	adds r1, #0x4A
	ldr r4, _0800DF48 @ =0xFFFFFE00
	adds r0, r4, #0x0
	ldrh r2, [r1, #0x00]
	ands r0, r2
	strh r0, [r1, #0x00]
	mov r0, r12
	adds r0, #0x48
	strb r6, [r0, #0x00]
	mov r2, r12
	adds r2, #0x4B
	movs r0, #0x3F
	ldrb r7, [r2, #0x00]
	ands r0, r7
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #0x00]
	mov r1, r12
	adds r1, #0x4D
	movs r0, #0x0F
	ldrb r2, [r1, #0x00]
	ands r0, r2
	strb r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x4C
	ldr r3, _0800DF4C @ =0xFFFFFC00
	adds r0, r3, #0x0
	ldrh r7, [r2, #0x00]
	ands r0, r7
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r5, #0x00
	mov r10, r12
	mov r9, r4
	adds r4, r3, #0x0
	.global _0800DEFE
_0800DEFE:
	adds r0, r5, #0x0
	adds r0, #0x0A
	lsls r0, r0, #0x03
	mov r1, r10
	adds r3, r0, r1
	lsls r2, r5, #0x05
	adds r2, #0x20
	ldr r7, _0800DF50 @ =0x000001FF
	adds r0, r7, #0x0
	adds r1, r2, #0x0
	ands r1, r0
	mov r0, r9
	ldrh r7, [r3, #0x02]
	ands r0, r7
	orrs r0, r1
	strh r0, [r3, #0x02]
	strb r6, [r3, #0x00]
	movs r0, #0x3F
	ldrb r1, [r3, #0x03]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r3, #0x03]
	movs r0, #0x0F
	ldrb r7, [r3, #0x05]
	ands r0, r7
	strb r0, [r3, #0x05]
	cmp r8, r2
	bge _0800DF54
	adds r0, r4, #0x0
	ldrh r1, [r3, #0x04]
	ands r0, r1
	movs r1, #0x20
	b _0800DF5C
	.byte 0x00, 0x00
	.global _0800DF44
_0800DF44: .4byte 0x0202E960
	.global _0800DF48
_0800DF48: .4byte 0xFFFFFE00
	.global _0800DF4C
_0800DF4C: .4byte 0xFFFFFC00
	.global _0800DF50
_0800DF50: .4byte 0x000001FF
	.global _0800DF54
_0800DF54:
	adds r0, r4, #0x0
	ldrh r2, [r3, #0x04]
	ands r0, r2
	movs r1, #0x10
	.global _0800DF5C
_0800DF5C:
	orrs r0, r1
	strh r0, [r3, #0x04]
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x07
	bls _0800DEFE
	mov r2, r12
	adds r2, #0x82
	ldr r0, _0800DFB8 @ =0xFFFFFE00
	ldrh r7, [r2, #0x00]
	ands r0, r7
	movs r1, #0xD0
	orrs r0, r1
	strh r0, [r2, #0x00]
	mov r0, r12
	adds r0, #0x80
	strb r6, [r0, #0x00]
	adds r2, #0x01
	movs r0, #0x3F
	ldrb r1, [r2, #0x00]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #0x00]
	mov r1, r12
	adds r1, #0x85
	movs r0, #0x0F
	ldrb r2, [r1, #0x00]
	ands r0, r2
	strb r0, [r1, #0x00]
	mov r2, r12
	adds r2, #0x84
	ldr r0, _0800DFBC @ =0xFFFFFC00
	ldrh r7, [r2, #0x00]
	ands r0, r7
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r2, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800DFB8
_0800DFB8: .4byte 0xFFFFFE00
	.global _0800DFBC
_0800DFBC: .4byte 0xFFFFFC00
	.byte 0x01, 0x49, 0x01, 0x20, 0x08, 0x80, 0x70, 0x47, 0xF8, 0x7F, 0x00, 0x03
