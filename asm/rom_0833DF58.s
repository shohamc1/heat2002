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
	thumb_func_start sub_0833DF58
sub_0833DF58:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r0, _0833DFC8 @ =0x0203B864
	ldrb r4, [r0, #0x00]
	cmp r4, #0x00
	beq _0833E044
	ldr r2, _0833DFCC @ =0x0203D520
	ldr r0, _0833DFD0 @ =0x020390EC
	ldrb r3, [r0, #0x00]
	cmp r3, #0x00
	beq _0833DF82
	ldr r0, _0833DFD4 @ =0x0203E1B0
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r2, r0, r2
	.global _0833DF82
_0833DF82:
	adds r0, r2, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833E044
	movs r7, #0x05
	cmp r3, #0x00
	beq _0833DF94
	movs r7, #0x02
	.global _0833DF94
_0833DF94:
	movs r0, #0x01
	mov r8, r0
	movs r6, #0x00
	cmp r6, r4
	beq _0833E044
	ldr r1, _0833DFD8 @ =0x020251B8
	mov r9, r1
	.global _0833DFA2
_0833DFA2:
	ldr r0, _0833DFDC @ =0x0203B868
	adds r0, r6, r0
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _0833DFCC @ =0x0203D520
	adds r5, r0, r1
	ldr r0, _0833DFD0 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833DFE0
	lsls r0, r7, #0x07
	adds r0, #0x14
	mov r2, r9
	ldr r1, [r2, #0x00]
	b _0833DFE8
	.global _0833DFC8
_0833DFC8: .4byte 0x0203B864
	.global _0833DFCC
_0833DFCC: .4byte 0x0203D520
	.global _0833DFD0
_0833DFD0: .4byte 0x020390EC
	.global _0833DFD4
_0833DFD4: .4byte 0x0203E1B0
	.global _0833DFD8
_0833DFD8: .4byte 0x020251B8
	.global _0833DFDC
_0833DFDC: .4byte 0x0203B868
	.global _0833DFE0
_0833DFE0:
	lsls r0, r7, #0x06
	adds r0, #0x14
	mov r3, r9
	ldr r1, [r3, #0x00]
	.global _0833DFE8
_0833DFE8:
	adds r4, r1, r0
	adds r0, r4, #0x0
	mov r1, r8
	bl sub_0833E3C8
	movs r1, #0x82
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrh r1, [r0, #0x00]
	movs r2, #0x83
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrh r2, [r0, #0x00]
	movs r3, #0x84
	lsls r3, r3, #0x01
	adds r0, r5, r3
	ldrh r3, [r0, #0x00]
	adds r0, r4, #0x0
	bl sub_0833DDB8
	ldr r0, _0833E050 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833E026
	lsls r1, r7, #0x04
	ldr r0, _0833E054 @ =0x0203B868
	adds r0, r6, r0
	ldrb r2, [r0, #0x00]
	movs r0, #0x40
	bl sub_08341A30
	.global _0833E026
_0833E026:
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _0833E058 @ =0x0203B864
	ldrb r0, [r0, #0x00]
	cmp r6, r0
	bne _0833DFA2
	.global _0833E044
_0833E044:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0833E050
_0833E050: .4byte 0x020390EC
	.global _0833E054
_0833E054: .4byte 0x0203B868
	.global _0833E058
_0833E058: .4byte 0x0203B864
