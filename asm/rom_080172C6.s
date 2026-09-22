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
	thumb_func_start sub_080172C8
sub_080172C8:
	movs r3, #0x01
	cmp r1, #0x00
	beq _0801738C
	bpl _080172D2
	negs r1, r1
	.global _080172D2
_080172D2:
	push {r4}
	push {r0}
	cmp r0, #0x00
	bpl _080172DC
	negs r0, r0
	.global _080172DC
_080172DC:
	cmp r0, r1
	bcc _08017380
	movs r4, #0x01
	lsls r4, r4, #0x1C
	.global _080172E4
_080172E4:
	cmp r1, r4
	bcs _080172F2
	cmp r1, r0
	bcs _080172F2
	lsls r1, r1, #0x04
	lsls r3, r3, #0x04
	b _080172E4
	.global _080172F2
_080172F2:
	lsls r4, r4, #0x03
	.global _080172F4
_080172F4:
	cmp r1, r4
	bcs _08017302
	cmp r1, r0
	bcs _08017302
	lsls r1, r1, #0x01
	lsls r3, r3, #0x01
	b _080172F4
	.global _08017302
_08017302:
	movs r2, #0x00
	cmp r0, r1
	bcc _0801730A
	subs r0, r0, r1
	.global _0801730A
_0801730A:
	lsrs r4, r1, #0x01
	cmp r0, r4
	bcc _0801731C
	subs r0, r0, r4
	mov r12, r3
	movs r4, #0x01
	rors r3, r4
	orrs r2, r3
	mov r3, r12
	.global _0801731C
_0801731C:
	lsrs r4, r1, #0x02
	cmp r0, r4
	bcc _0801732E
	subs r0, r0, r4
	mov r12, r3
	movs r4, #0x02
	rors r3, r4
	orrs r2, r3
	mov r3, r12
	.global _0801732E
_0801732E:
	lsrs r4, r1, #0x03
	cmp r0, r4
	bcc _08017340
	subs r0, r0, r4
	mov r12, r3
	movs r4, #0x03
	rors r3, r4
	orrs r2, r3
	mov r3, r12
	.global _08017340
_08017340:
	mov r12, r3
	cmp r0, #0x00
	beq _0801734E
	lsrs r3, r3, #0x04
	beq _0801734E
	lsrs r1, r1, #0x04
	b _08017302
	.global _0801734E
_0801734E:
	movs r4, #0x0E
	lsls r4, r4, #0x1C
	ands r2, r4
	beq _08017380
	mov r3, r12
	movs r4, #0x03
	rors r3, r4
	tst r2, r3
	beq _08017364
	lsrs r4, r1, #0x03
	adds r0, r0, r4
	.global _08017364
_08017364:
	mov r3, r12
	movs r4, #0x02
	rors r3, r4
	tst r2, r3
	beq _08017372
	lsrs r4, r1, #0x02
	adds r0, r0, r4
	.global _08017372
_08017372:
	mov r3, r12
	movs r4, #0x01
	rors r3, r4
	tst r2, r3
	beq _08017380
	lsrs r4, r1, #0x01
	adds r0, r0, r4
	.global _08017380
_08017380:
	pop {r4}
	cmp r4, #0x00
	bpl _08017388
	negs r0, r0
	.global _08017388
_08017388:
	pop {r4}
	mov pc, lr
	.global _0801738C
_0801738C:
	push {lr}
	bl sub_080172C4
	movs r0, #0x00
	pop {pc}
	.byte 0x00, 0x00
	thumb_func_start sub_08017398
sub_08017398:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	str r2, [sp, #0x008]
	str r3, [sp, #0x00C]
	ldr r3, [sp, #0x000]
	ldr r0, _08017404 @ =0x0000FFFF
	mov r12, r0
	adds r2, r3, #0x0
	ands r2, r0
	lsrs r3, r3, #0x10
	ldr r1, [sp, #0x008]
	adds r0, r1, #0x0
	mov r4, r12
	ands r0, r4
	lsrs r1, r1, #0x10
	adds r5, r2, #0x0
	muls r5, r0
	adds r4, r2, #0x0
	muls r4, r1
	adds r2, r3, #0x0
	muls r2, r0
	muls r3, r1
	lsrs r0, r5, #0x10
	adds r4, r4, r0
	adds r4, r4, r2
	cmp r4, r2
	bcs _080173D8
	movs r0, #0x80
	lsls r0, r0, #0x09
	adds r3, r3, r0
	.global _080173D8
_080173D8:
	lsrs r0, r4, #0x10
	adds r7, r3, r0
	mov r1, r12
	ands r4, r1
	lsls r0, r4, #0x10
	ands r5, r1
	adds r6, r0, #0x0
	orrs r6, r5
	adds r1, r7, #0x0
	adds r0, r6, #0x0
	ldr r3, [sp, #0x000]
	ldr r4, [sp, #0x00C]
	adds r2, r3, #0x0
	muls r2, r4
	ldr r5, [sp, #0x004]
	ldr r4, [sp, #0x008]
	adds r3, r5, #0x0
	muls r3, r4
	adds r2, r2, r3
	adds r1, r7, r2
	add sp, #0x010
	pop {r4, r5, r6, r7, pc}
	.global _08017404
_08017404: .4byte 0x0000FFFF
	thumb_func_start sub_08017408
sub_08017408:
	push {r4, lr}
	negs r2, r0
	adds r3, r2, #0x0
	negs r1, r1
	cmp r2, #0x00
	beq _08017416
	subs r1, #0x01
	.global _08017416
_08017416:
	adds r4, r1, #0x0
	adds r1, r4, #0x0
	adds r0, r3, #0x0
	pop {r4, pc}
	.byte 0x00, 0x00
	.global _08017420
_08017420:
	.byte 0x00, 0x29, 0x34, 0xD0, 0x01, 0x23, 0x00, 0x22, 0x10, 0xB4, 0x88, 0x42, 0x2C, 0xD3, 0x01, 0x24
	.byte 0x24, 0x07, 0xA1, 0x42, 0x04, 0xD2, 0x81, 0x42, 0x02, 0xD2, 0x09, 0x01, 0x1B, 0x01, 0xF8, 0xE7
	.byte 0xE4, 0x00, 0xA1, 0x42, 0x04, 0xD2, 0x81, 0x42, 0x02, 0xD2, 0x49, 0x00, 0x5B, 0x00, 0xF8, 0xE7
	.byte 0x88, 0x42, 0x01, 0xD3, 0x40, 0x1A, 0x1A, 0x43, 0x4C, 0x08, 0xA0, 0x42, 0x02, 0xD3, 0x00, 0x1B
	.byte 0x5C, 0x08, 0x22, 0x43, 0x8C, 0x08, 0xA0, 0x42, 0x02, 0xD3, 0x00, 0x1B, 0x9C, 0x08, 0x22, 0x43
	.byte 0xCC, 0x08, 0xA0, 0x42, 0x02, 0xD3, 0x00, 0x1B, 0xDC, 0x08, 0x22, 0x43, 0x00, 0x28, 0x03, 0xD0
	.byte 0x1B, 0x09, 0x01, 0xD0, 0x09, 0x09, 0xE3, 0xE7, 0x10, 0x1C, 0x10, 0xBC, 0xF7, 0x46, 0x00, 0xB5
	.byte 0xFF, 0xF7, 0x18, 0xFF, 0x00, 0x20, 0x00, 0xBD
	thumb_func_start sub_08017498
sub_08017498:
	cmp r1, #0x00
	beq _0801754E
	movs r3, #0x01
	cmp r0, r1
	bcs _080174A4
	mov pc, lr
	.global _080174A4
_080174A4:
	push {r4}
	movs r4, #0x01
	lsls r4, r4, #0x1C
	.global _080174AA
_080174AA:
	cmp r1, r4
	bcs _080174B8
	cmp r1, r0
	bcs _080174B8
	lsls r1, r1, #0x04
	lsls r3, r3, #0x04
	b _080174AA
	.global _080174B8
_080174B8:
	lsls r4, r4, #0x03
	.global _080174BA
_080174BA:
	cmp r1, r4
	bcs _080174C8
	cmp r1, r0
	bcs _080174C8
	lsls r1, r1, #0x01
	lsls r3, r3, #0x01
	b _080174BA
	.global _080174C8
_080174C8:
	movs r2, #0x00
	cmp r0, r1
	bcc _080174D0
	subs r0, r0, r1
	.global _080174D0
_080174D0:
	lsrs r4, r1, #0x01
	cmp r0, r4
	bcc _080174E2
	subs r0, r0, r4
	mov r12, r3
	movs r4, #0x01
	rors r3, r4
	orrs r2, r3
	mov r3, r12
	.global _080174E2
_080174E2:
	lsrs r4, r1, #0x02
	cmp r0, r4
	bcc _080174F4
	subs r0, r0, r4
	mov r12, r3
	movs r4, #0x02
	rors r3, r4
	orrs r2, r3
	mov r3, r12
	.global _080174F4
_080174F4:
	lsrs r4, r1, #0x03
	cmp r0, r4
	bcc _08017506
	subs r0, r0, r4
	mov r12, r3
	movs r4, #0x03
	rors r3, r4
	orrs r2, r3
	mov r3, r12
	.global _08017506
_08017506:
	mov r12, r3
	cmp r0, #0x00
	beq _08017514
	lsrs r3, r3, #0x04
	beq _08017514
	lsrs r1, r1, #0x04
	b _080174C8
	.global _08017514
_08017514:
	movs r4, #0x0E
	lsls r4, r4, #0x1C
	ands r2, r4
	bne _08017520
	pop {r4}
	mov pc, lr
	.global _08017520
_08017520:
	mov r3, r12
	movs r4, #0x03
	rors r3, r4
	tst r2, r3
	beq _0801752E
	lsrs r4, r1, #0x03
	adds r0, r0, r4
	.global _0801752E
_0801752E:
	mov r3, r12
	movs r4, #0x02
	rors r3, r4
	tst r2, r3
	beq _0801753C
	lsrs r4, r1, #0x02
	adds r0, r0, r4
	.global _0801753C
_0801753C:
	mov r3, r12
	movs r4, #0x01
	rors r3, r4
	tst r2, r3
	beq _0801754A
	lsrs r4, r1, #0x01
	adds r0, r0, r4
	.global _0801754A
_0801754A:
	pop {r4}
	mov pc, lr
	.global _0801754E
_0801754E:
	push {lr}
	bl sub_080172C4
	movs r0, #0x00
	pop {pc}
