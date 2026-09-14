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
	thumb_func_start sub_080112E0
sub_080112E0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	movs r5, #0x00
	ldr r2, _08011370 @ =0x020020AC
	mov r10, r2
	ldr r0, _08011374 @ =0x0202EFC0
	mov r9, r0
	ldrb r1, [r2, #0x00]
	cmp r5, r1
	beq _0801131C
	mov r4, r9
	ldr r3, _08011378 @ =0x0202A550
	.global _080112FE
_080112FE:
	lsls r0, r5, #0x02
	adds r0, r0, r4
	lsls r1, r5, #0x01
	adds r1, r1, r5
	lsls r1, r1, #0x03
	adds r1, r1, r5
	lsls r1, r1, #0x04
	adds r1, r1, r3
	str r1, [r0, #0x00]
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r0, [r2, #0x00]
	cmp r5, r0
	bne _080112FE
	.global _0801131C
_0801131C:
	mov r6, r9
	movs r5, #0x00
	movs r7, #0x00
	mov r1, r10
	ldrb r1, [r1, #0x00]
	cmp r1, #0x01
	beq _0801135C
	movs r2, #0xB6
	lsls r2, r2, #0x01
	mov r12, r2
	mov r8, r10
	.global _08011332
_08011332:
	ldr r4, [r6, #0x00]
	ldr r3, [r6, #0x04]
	mov r1, r12
	adds r0, r4, r1
	adds r1, r3, r1
	ldr r2, [r0, #0x00]
	ldr r0, [r1, #0x00]
	cmp r2, r0
	bls _0801134A
	str r3, [r6, #0x00]
	str r4, [r6, #0x04]
	movs r7, #0x01
	.global _0801134A
_0801134A:
	adds r6, #0x04
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r2, r8
	ldrb r0, [r2, #0x00]
	subs r0, #0x01
	cmp r5, r0
	bne _08011332
	.global _0801135C
_0801135C:
	cmp r7, #0x00
	bne _0801131C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08011370
_08011370: .4byte 0x020020AC
	.global _08011374
_08011374: .4byte 0x0202EFC0
	.global _08011378
_08011378: .4byte 0x0202A550
