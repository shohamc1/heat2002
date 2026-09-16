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
	thumb_func_start sub_080047E8
sub_080047E8:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r5, #0x00
	beq _080048B0
	ldr r0, _08004894 @ =0x020251F0
	mov r9, r0
	strh r5, [r0, #0x00]
	mov r1, sp
	movs r0, #0x00
	mov r10, r0
	movs r2, #0x00
	movs r0, #0x68
	strh r0, [r1, #0x00]
	mov r0, sp
	strh r2, [r0, #0x02]
	ldr r1, _08004898 @ =0x083FF79C
	movs r0, #0x07
	ands r0, r4
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl sub_0800754C
	adds r6, r0, #0x0
	movs r0, #0x08
	ands r0, r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1B
	mov r8, r0
	movs r0, #0x10
	ands r0, r4
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x1C
	cmp r6, #0x00
	beq _08004926
	mov r0, r9
	strh r5, [r0, #0x00]
	mov r0, sp
	ldrh r0, [r0, #0x02]
	movs r4, #0xFF
	ands r4, r0
	mov r1, sp
	ldr r0, _0800489C @ =0x000001FF
	ldrh r1, [r1, #0x00]
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r4, r0
	ldr r0, _080048A0 @ =0x083393C0
	bl sub_08007714
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	ldr r1, [r6, #0x10]
	orrs r1, r0
	ldr r0, _080048A4 @ =0x04000100
	orrs r4, r0
	ldr r2, _080048A8 @ =0x0202523C
	mov r0, r10
	strb r0, [r2, #0x00]
	ldr r3, _080048AC @ =0x020253C8
	strb r0, [r3, #0x00]
	mov r0, r8
	cmp r0, #0x00
	beq _08004882
	movs r0, #0x01
	strb r0, [r2, #0x00]
	.global _08004882
_08004882:
	cmp r7, #0x00
	beq _0800488A
	movs r0, #0x01
	strb r0, [r3, #0x00]
	.global _0800488A
_0800488A:
	adds r0, r4, #0x0
	bl sub_080044A4
	b _08004926
	.byte 0x00, 0x00
	.global _08004894
_08004894: .4byte 0x020251F0
	.global _08004898
_08004898: .4byte 0x083FF79C
	.global _0800489C
_0800489C: .4byte 0x000001FF
	.global _080048A0
_080048A0: .4byte 0x083393C0
	.global _080048A4
_080048A4: .4byte 0x04000100
	.global _080048A8
_080048A8: .4byte 0x0202523C
	.global _080048AC
_080048AC: .4byte 0x020253C8
	.global _080048B0
_080048B0:
	mov r1, sp
	movs r0, #0x68
	strh r0, [r1, #0x00]
	mov r0, sp
	strh r5, [r0, #0x02]
	ldr r1, _08004938 @ =0x083FF79C
	movs r0, #0x07
	ands r0, r4
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl sub_0800754C
	adds r6, r0, #0x0
	movs r0, #0x08
	ands r0, r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1B
	mov r8, r0
	movs r0, #0x10
	ands r0, r4
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x1C
	cmp r6, #0x00
	beq _08004926
	mov r0, sp
	ldrh r0, [r0, #0x02]
	movs r4, #0xFF
	ands r4, r0
	mov r1, sp
	ldr r0, _0800493C @ =0x000001FF
	ldrh r1, [r1, #0x00]
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r4, r0
	ldr r0, _08004940 @ =0x083393C0
	bl sub_08007714
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	ldr r1, [r6, #0x10]
	orrs r1, r0
	mov r0, r8
	cmp r0, #0x00
	beq _08004916
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r4, r0
	.global _08004916
_08004916:
	cmp r7, #0x00
	beq _08004920
	movs r0, #0x80
	lsls r0, r0, #0x16
	orrs r4, r0
	.global _08004920
_08004920:
	adds r0, r4, #0x0
	bl sub_080044A4
	.global _08004926
_08004926:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08004938
_08004938: .4byte 0x083FF79C
	.global _0800493C
_0800493C: .4byte 0x000001FF
	.global _08004940
_08004940: .4byte 0x083393C0
