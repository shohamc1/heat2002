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
	thumb_func_start sub_0800545C
sub_0800545C:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r0, _080054CC @ =0x020253D4
	ldrb r4, [r0, #0x00]
	cmp r4, #0x00
	beq _08005548
	ldr r2, _080054D0 @ =0x0202A550
	ldr r0, _080054D4 @ =0x020020DC
	ldrb r3, [r0, #0x00]
	cmp r3, #0x00
	beq _08005486
	ldr r0, _080054D8 @ =0x0202EF90
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r2, r0, r2
	.global _08005486
_08005486:
	adds r0, r2, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08005548
	movs r7, #0x05
	cmp r3, #0x00
	beq _08005498
	movs r7, #0x02
	.global _08005498
_08005498:
	movs r0, #0x01
	mov r8, r0
	movs r6, #0x00
	cmp r6, r4
	beq _08005548
	ldr r1, _080054DC @ =0x08364B08
	mov r9, r1
	.global _080054A6
_080054A6:
	ldr r0, _080054E0 @ =0x020253E0
	adds r0, r6, r0
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _080054D0 @ =0x0202A550
	adds r5, r0, r1
	ldr r0, _080054D4 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080054E4
	lsls r0, r7, #0x07
	adds r0, #0x14
	mov r2, r9
	ldr r1, [r2, #0x00]
	b _080054EC
	.global _080054CC
_080054CC: .4byte 0x020253D4
	.global _080054D0
_080054D0: .4byte 0x0202A550
	.global _080054D4
_080054D4: .4byte 0x020020DC
	.global _080054D8
_080054D8: .4byte 0x0202EF90
	.global _080054DC
_080054DC: .4byte 0x08364B08
	.global _080054E0
_080054E0: .4byte 0x020253E0
	.global _080054E4
_080054E4:
	lsls r0, r7, #0x06
	adds r0, #0x14
	mov r3, r9
	ldr r1, [r3, #0x00]
	.global _080054EC
_080054EC:
	adds r4, r1, r0
	adds r0, r4, #0x0
	mov r1, r8
	bl sub_080058CC
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
	bl sub_08005338
	ldr r0, _08005554 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800552A
	lsls r1, r7, #0x04
	ldr r0, _08005558 @ =0x020253E0
	adds r0, r6, r0
	ldrb r2, [r0, #0x00]
	movs r0, #0x40
	bl sub_08009FA0
	.global _0800552A
_0800552A:
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
	ldr r0, _0800555C @ =0x020253D4
	ldrb r0, [r0, #0x00]
	cmp r6, r0
	bne _080054A6
	.global _08005548
_08005548:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08005554
_08005554: .4byte 0x020020DC
	.global _08005558
_08005558: .4byte 0x020253E0
	.global _0800555C
_0800555C: .4byte 0x020253D4
