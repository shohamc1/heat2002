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
	thumb_func_start sub_08014708
sub_08014708:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r9, r1
	ldr r0, _08014858 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	adds r0, r4, #0x0
	adds r0, #0xAE
	bl sub_08016558
	bl sub_080065A8
	lsls r4, r4, #0x1A
	lsrs r4, r4, #0x18
	mov r10, r4
	movs r6, #0x03
	movs r4, #0x00
	mov r7, r9
	ands r7, r6
	ldr r0, _0801485C @ =0x0202EF60
	mov r8, r0
	.global _08014744
_08014744:
	ldr r0, _08014860 @ =0x083FE9EC
	mov r1, r10
	adds r2, r1, r4
	lsls r1, r2, #0x02
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	movs r3, #0x00
	adds r5, r2, #0x0
	cmp r4, r7
	bne _0801475A
	movs r3, #0x01
	.global _0801475A
_0801475A:
	movs r1, #0x00
	adds r2, r6, #0x0
	bl sub_080063BC
	mov r2, r8
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0801477E
	ldr r0, _08014864 @ =0x0829F4EC
	movs r3, #0x00
	cmp r4, r7
	bne _08014776
	movs r3, #0x01
	.global _08014776
_08014776:
	movs r1, #0x16
	adds r2, r6, #0x0
	bl sub_080063BC
	.global _0801477E
_0801477E:
	mov r1, r8
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _0801479A
	ldr r0, _08014864 @ =0x0829F4EC
	movs r3, #0x00
	cmp r4, r7
	bne _08014792
	movs r3, #0x01
	.global _08014792
_08014792:
	movs r1, #0x16
	adds r2, r6, #0x0
	bl sub_080063BC
	.global _0801479A
_0801479A:
	mov r2, r8
	adds r0, r5, r2
	movs r1, #0x00
	ldsb r1, [r0, r1]
	cmp r1, #0x03
	bne _080147BC
	ldr r0, _08014864 @ =0x0829F4EC
	movs r3, #0x00
	mov r2, r9
	ands r1, r2
	cmp r4, r1
	bne _080147B4
	movs r3, #0x01
	.global _080147B4
_080147B4:
	movs r1, #0x16
	adds r2, r6, #0x0
	bl sub_080063BC
	.global _080147BC
_080147BC:
	mov r1, r8
	adds r0, r5, r1
	movs r1, #0x00
	ldsb r1, [r0, r1]
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	bne _080147DE
	ldr r0, _08014868 @ =0x0829F4F4
	movs r3, #0x00
	cmp r4, r7
	bne _080147D6
	movs r3, #0x01
	.global _080147D6
_080147D6:
	movs r1, #0x16
	adds r2, r6, #0x0
	bl sub_080063BC
	.global _080147DE
_080147DE:
	mov r2, r8
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bne _080147FE
	ldr r0, _0801486C @ =0x0829F4FC
	movs r3, #0x00
	cmp r4, r7
	bne _080147F6
	movs r3, #0x01
	.global _080147F6
_080147F6:
	movs r1, #0x16
	adds r2, r6, #0x0
	bl sub_080063BC
	.global _080147FE
_080147FE:
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x04
	bne _08014744
	movs r6, #0x08
	mov r1, r9
	lsls r0, r1, #0x02
	add r0, r9
	lsls r0, r0, #0x19
	lsrs r4, r0, #0x18
	mov r10, r4
	adds r0, r4, #0x0
	adds r0, #0x0A
	cmp r4, r0
	beq _0801484A
	ldr r5, _08014870 @ =0x083FEA2C
	.global _08014826
_08014826:
	lsls r0, r4, #0x02
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	movs r1, #0x00
	adds r2, r6, #0x0
	movs r3, #0x01
	bl sub_080063BC
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r0, r10
	adds r0, #0x0A
	cmp r4, r0
	bne _08014826
	.global _0801484A
_0801484A:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08014858
_08014858: .4byte 0x083FDE18
	.global _0801485C
_0801485C: .4byte 0x0202EF60
	.global _08014860
_08014860: .4byte 0x083FE9EC
	.global _08014864
_08014864: .4byte 0x0829F4EC
	.global _08014868
_08014868: .4byte 0x0829F4F4
	.global _0801486C
_0801486C: .4byte 0x0829F4FC
	.global _08014870
_08014870: .4byte 0x083FEA2C
