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
	.byte 0x0C, 0xB4, 0x30, 0xB5, 0x96, 0xB0, 0x19, 0x9C, 0x6B, 0x46, 0x00, 0x25, 0x82, 0x22, 0x92, 0x00
	.byte 0x9A, 0x81, 0x00, 0x91, 0x04, 0x91, 0x08, 0x49, 0x02, 0x91, 0x05, 0x91, 0x15, 0x90, 0x1A, 0xAA
	.byte 0x68, 0x46, 0x21, 0x1C, 0x00, 0xF0, 0x74, 0xF8, 0x00, 0x99, 0x0D, 0x70, 0x16, 0xB0, 0x30, 0xBC
	.byte 0x08, 0xBC, 0x02, 0xB0, 0x18, 0x47, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x7F
	thumb_func_start sub_08017594
sub_08017594:
	push {r1, r2, r3}
	push {r4, lr}
	add sp, #-0x058
	ldr r1, [sp, #0x060]
	mov r3, sp
	movs r4, #0x00
	movs r2, #0x82
	lsls r2, r2, #0x02
	strh r2, [r3, #0x0C]
	str r0, [sp, #0x000]
	str r0, [sp, #0x010]
	ldr r0, _080175CC @ =0x7FFFFFFF
	str r0, [sp, #0x008]
	str r0, [sp, #0x014]
	ldr r0, _080175D0 @ =0x083FFAA8
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x054]
	add r2, sp, #0x064
	mov r0, sp
	bl sub_08017668
	ldr r1, [sp, #0x000]
	strb r4, [r1, #0x00]
	add sp, #0x058
	pop {r4}
	pop {r3}
	add sp, #0x00C
	bx r3
	.global _080175CC
_080175CC: .4byte 0x7FFFFFFF
	.global _080175D0
_080175D0: .4byte 0x083FFAA8
	thumb_func_start sub_080175D4
sub_080175D4:
	push {r4, lr}
	adds r4, r1, #0x0
	ldr r1, [r4, #0x08]
	cmp r1, #0x00
	beq _080175EC
	adds r1, r4, #0x0
	bl sub_08019AB0
	movs r1, #0x00
	str r1, [r4, #0x08]
	str r1, [r4, #0x04]
	b _080175F0
	.global _080175EC
_080175EC:
	str r1, [r4, #0x04]
	movs r0, #0x00
	.global _080175F0
_080175F0:
	pop {r4, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_080175F4
sub_080175F4:
	push {r4, r5, lr}
	ldr r4, _08017664 @ =0xFFFFFBA8
	add sp, r4
	adds r5, r0, #0x0
	ldr r0, [r5, #0x54]
	str r0, [sp, #0x054]
	mov r3, sp
	movs r0, #0x03
	negs r0, r0
	ldrh r4, [r5, #0x0C]
	ands r0, r4
	movs r4, #0x00
	strh r0, [r3, #0x0C]
	ldrh r0, [r5, #0x0E]
	strh r0, [r3, #0x0E]
	ldr r0, [r5, #0x1C]
	str r0, [sp, #0x01C]
	ldr r0, [r5, #0x24]
	str r0, [sp, #0x024]
	add r0, sp, #0x058
	str r0, [sp, #0x000]
	str r0, [sp, #0x010]
	movs r0, #0x80
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	str r0, [sp, #0x014]
	str r4, [sp, #0x018]
	mov r0, sp
	bl sub_08017668
	adds r4, r0, #0x0
	cmp r4, #0x00
	blt _08017644
	mov r0, sp
	bl sub_08019640
	cmp r0, #0x00
	beq _08017644
	movs r4, #0x01
	negs r4, r4
	.global _08017644
_08017644:
	mov r1, sp
	movs r0, #0x40
	ldrh r1, [r1, #0x0C]
	ands r0, r1
	cmp r0, #0x00
	beq _08017658
	movs r0, #0x40
	ldrh r1, [r5, #0x0C]
	orrs r0, r1
	strh r0, [r5, #0x0C]
	.global _08017658
_08017658:
	adds r0, r4, #0x0
	movs r3, #0x8B
	lsls r3, r3, #0x03
	add sp, r3
	pop {r4, r5, pc}
	.byte 0x00, 0x00
	.global _08017664
_08017664: .4byte 0xFFFFFBA8
	thumb_func_start sub_08017668
sub_08017668:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	adds r3, r2, #0x0
	ldr r0, [r4, #0x54]
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	bl sub_0801767C
	pop {r4, r5, pc}
	thumb_func_start sub_0801767C
sub_0801767C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _080176E4 @ =0xFFFFFDE0
	add sp, r4
	str r0, [sp, #0x1DC]
	str r1, [sp, #0x1E0]
	adds r4, r2, #0x0
	mov r10, r3
	bl sub_08019D78
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x1F8]
	movs r1, #0x00
	add r0, sp, #0x1D0
	str r1, [r0, #0x00]
	ldr r1, [sp, #0x1E0]
	ldr r0, [r1, #0x54]
	cmp r0, #0x00
	bne _080176AE
	ldr r0, _080176E8 @ =0x083FFAA8
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x54]
	.global _080176AE
_080176AE:
	ldr r2, [sp, #0x1E0]
	ldr r1, [r2, #0x54]
	ldr r0, [r1, #0x38]
	cmp r0, #0x00
	bne _080176BE
	adds r0, r1, #0x0
	bl sub_080197D0
	.global _080176BE
_080176BE:
	movs r0, #0x08
	ldr r1, [sp, #0x1E0]
	ldrh r1, [r1, #0x0C]
	ands r0, r1
	cmp r0, #0x00
	beq _080176D2
	ldr r2, [sp, #0x1E0]
	ldr r0, [r2, #0x10]
	cmp r0, #0x00
	bne _080176EC
	.global _080176D2
_080176D2:
	ldr r0, [sp, #0x1E0]
	bl sub_08018740
	cmp r0, #0x00
	beq _080176EC
	movs r0, #0x01
	negs r0, r0
	bl _080185CC
	.global _080176E4
_080176E4:
	.2byte 0xFDE0 @ bl lr+3008
	.2byte 0xFFFF @ bl lr+4094
	.global _080176E8
_080176E8:
	.2byte 0xFAA8 @ bl lr+1360
	lsrs r7, r7, #0x20
	.global _080176EC
_080176EC:
	movs r0, #0x1A
	ldr r1, [sp, #0x1E0]
	ldrh r1, [r1, #0x0C]
	ands r0, r1
	cmp r0, #0x0A
	bne _08017710
	ldr r2, [sp, #0x1E0]
	movs r1, #0x0E
	ldsh r0, [r2, r1]
	cmp r0, #0x00
	blt _08017710
	adds r0, r2, #0x0
	adds r1, r4, #0x0
	mov r2, r10
	bl sub_080175F4
	bl _080185CC
	.global _08017710
_08017710:
	str r4, [sp, #0x1E4]
	add r1, sp, #0x01C
	add r5, sp, #0x028
	str r5, [sp, #0x01C]
	movs r0, #0x00
	str r0, [r1, #0x08]
	str r0, [r1, #0x04]
	movs r2, #0x00
	str r2, [sp, #0x1F0]
	mov r9, r1
	movs r4, #0xE6
	lsls r4, r4, #0x01
	add r4, sp
	str r4, [sp, #0x214]
	movs r0, #0xE8
	lsls r0, r0, #0x01
	add r0, sp
	str r0, [sp, #0x218]
	.global _08017734
_08017734:
	ldr r1, [sp, #0x1E4]
	mov r8, r1
	.global _08017738
_08017738:
	ldr r0, _080177E4 @ =0x083FFAA8
	ldr r0, [r0, #0x00]
	ldr r1, _080177E8 @ =0x083FFAAC
	ldr r3, [r1, #0x00]
	ldr r2, [sp, #0x218]
	str r2, [sp, #0x000]
	ldr r1, [sp, #0x214]
	ldr r2, [sp, #0x1E4]
	bl sub_0801A380
	adds r4, r0, #0x0
	cmp r4, #0x00
	ble _08017766
	ldr r0, [sp, #0x1E4]
	adds r0, r0, r4
	str r0, [sp, #0x1E4]
	add r0, sp, #0x1CC
	ldr r0, [r0, #0x00]
	cmp r0, #0x25
	bne _08017738
	ldr r1, [sp, #0x1E4]
	subs r1, #0x01
	str r1, [sp, #0x1E4]
	.global _08017766
_08017766:
	ldr r2, [sp, #0x1E4]
	mov r0, r8
	subs r6, r2, r0
	cmp r6, #0x00
	beq _0801779E
	str r0, [r5, #0x00]
	str r6, [r5, #0x04]
	mov r1, r9
	ldr r0, [r1, #0x08]
	adds r0, r0, r6
	str r0, [r1, #0x08]
	adds r5, #0x08
	ldr r0, [r1, #0x04]
	adds r0, #0x01
	str r0, [r1, #0x04]
	cmp r0, #0x07
	ble _08017798
	ldr r0, [sp, #0x1E0]
	bl sub_080175D4
	cmp r0, #0x00
	beq _08017796
	bl _080185B8
	.global _08017796
_08017796:
	add r5, sp, #0x028
	.global _08017798
_08017798:
	ldr r2, [sp, #0x1F0]
	adds r2, r2, r6
	str r2, [sp, #0x1F0]
	.global _0801779E
_0801779E:
	cmp r4, #0x00
	bgt _080177A6
	bl _080185A0
	.global _080177A6
_080177A6:
	ldr r4, [sp, #0x1E4]
	adds r4, #0x01
	str r4, [sp, #0x1E4]
	movs r0, #0x00
	str r0, [sp, #0x1EC]
	movs r1, #0x00
	str r1, [sp, #0x208]
	movs r2, #0x00
	str r2, [sp, #0x1F4]
	movs r6, #0x01
	negs r6, r6
	ldr r0, _080177EC @ =0x000001C9
	add r0, sp
	strb r2, [r0, #0x00]
	ldr r0, [sp, #0x1E4]
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x1E8]
	ldr r1, [sp, #0x1E4]
	adds r1, #0x01
	str r1, [sp, #0x1E4]
	ldr r0, [sp, #0x1E8]
	subs r0, #0x20
	cmp r0, #0x58
	bls _080177D8
	b _08017E8A
	.global _080177D8
_080177D8:
	lsls r0, r0, #0x02
	ldr r1, _080177F0 @ =0x080177F4
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
	.global _080177E4
_080177E4: .4byte 0x083FFAA8
	.global _080177E8
_080177E8: .4byte 0x083FFAAC
	.global _080177EC
_080177EC: .4byte 0x000001C9
	.global _080177F0
_080177F0: .4byte 0x080177F4
	.byte 0x58, 0x79, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x70, 0x79, 0x01, 0x08
	.byte 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08
	.byte 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x74, 0x79, 0x01, 0x08, 0x8E, 0x79, 0x01, 0x08
	.byte 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x79, 0x01, 0x08, 0x9C, 0x79, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08
	.byte 0xFC, 0x79, 0x01, 0x08, 0x00, 0x7A, 0x01, 0x08, 0x00, 0x7A, 0x01, 0x08, 0x00, 0x7A, 0x01, 0x08
	.byte 0x00, 0x7A, 0x01, 0x08, 0x00, 0x7A, 0x01, 0x08, 0x00, 0x7A, 0x01, 0x08, 0x00, 0x7A, 0x01, 0x08
	.byte 0x00, 0x7A, 0x01, 0x08, 0x00, 0x7A, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08
	.byte 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08
	.byte 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08
	.byte 0x6A, 0x7A, 0x01, 0x08, 0xBC, 0x7A, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0xBC, 0x7A, 0x01, 0x08
	.byte 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08
	.byte 0x24, 0x7A, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x72, 0x7C, 0x01, 0x08
	.byte 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08
	.byte 0x8A, 0x7E, 0x01, 0x08, 0x0A, 0x7D, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08
	.byte 0x46, 0x7D, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08
	.byte 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08
	.byte 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x58, 0x7A, 0x01, 0x08
	.byte 0x72, 0x7A, 0x01, 0x08, 0xBC, 0x7A, 0x01, 0x08, 0xBC, 0x7A, 0x01, 0x08, 0xBC, 0x7A, 0x01, 0x08
	.byte 0x28, 0x7A, 0x01, 0x08, 0x72, 0x7A, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08
	.byte 0x2C, 0x7A, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x2C, 0x7C, 0x01, 0x08, 0x7A, 0x7C, 0x01, 0x08
	.byte 0xA8, 0x7C, 0x01, 0x08, 0x4E, 0x7A, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0xC8, 0x7C, 0x01, 0x08
	.byte 0x8A, 0x7E, 0x01, 0x08, 0x12, 0x7D, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08, 0x8A, 0x7E, 0x01, 0x08
	.byte 0x50, 0x7D, 0x01, 0x08, 0x04, 0x49, 0x69, 0x44, 0x08, 0x78, 0x00, 0x28, 0x00, 0xD0, 0x2E, 0xE7
	.byte 0x20, 0x20, 0x08, 0x70, 0x2B, 0xE7, 0x00, 0x00, 0xC9, 0x01, 0x00, 0x00, 0x01, 0x20, 0x63, 0xE0
	.byte 0x04, 0x24, 0xA2, 0x44, 0x50, 0x46, 0x04, 0x38, 0x00, 0x68, 0x7D, 0x90, 0x00, 0x28, 0x00, 0xDB
	.byte 0x1D, 0xE7, 0x40, 0x42, 0x7D, 0x90, 0x04, 0x20, 0x60, 0xE0, 0x02, 0x49, 0x69, 0x44, 0x2B, 0x20
	.byte 0x08, 0x70, 0x14, 0xE7, 0xC9, 0x01, 0x00, 0x00, 0x79, 0x9A, 0x12, 0x78, 0x7A, 0x92, 0x79, 0x9C
	.byte 0x01, 0x34, 0x79, 0x94, 0x2A, 0x2A, 0x0C, 0xD1, 0x04, 0x20, 0x82, 0x44, 0x50, 0x46, 0x04, 0x38
	.byte 0x04, 0x68, 0x26, 0x1C, 0x01, 0x20, 0x40, 0x42, 0x86, 0x42, 0x00, 0xDB, 0xFF, 0xE6, 0x06, 0x1C
	.byte 0xFD, 0xE6, 0x00, 0x24, 0x7A, 0x98, 0x0C, 0xE0, 0xA0, 0x00, 0x00, 0x19, 0x40, 0x00, 0x30, 0x38
	.byte 0x7A, 0x99, 0x44, 0x18, 0x79, 0x9A, 0x12, 0x78, 0x7A, 0x92, 0x79, 0x98, 0x01, 0x30, 0x79, 0x90
	.byte 0x10, 0x1C, 0x30, 0x38, 0x09, 0x28, 0xEF, 0xD9, 0x26, 0x1C, 0x01, 0x20, 0x40, 0x42, 0x86, 0x42
	.byte 0x00, 0xDB, 0xEA, 0xE6, 0x06, 0x1C, 0xE8, 0xE6, 0x80, 0x20, 0x27, 0xE0, 0x00, 0x24, 0xA0, 0x00
	.byte 0x00, 0x19, 0x40, 0x00, 0x30, 0x38, 0x7A, 0x9A, 0x84, 0x18, 0x79, 0x98, 0x00, 0x78, 0x7A, 0x90
	.byte 0x79, 0x99, 0x01, 0x31, 0x79, 0x91, 0x30, 0x38, 0x09, 0x28, 0xF0, 0xD9, 0x7D, 0x94, 0xD4, 0xE6
	.byte 0x08, 0x20, 0x09, 0xE0, 0x40, 0x20, 0x0C, 0xE0, 0x79, 0x98, 0x00, 0x78, 0x6C, 0x28, 0x07, 0xD1
	.byte 0x79, 0x99, 0x01, 0x31, 0x79, 0x91, 0x20, 0x20, 0x7B, 0x9A, 0x02, 0x43, 0x7B, 0x92, 0xBE, 0xE6
	.byte 0x10, 0x20, 0x7B, 0x9C, 0x04, 0x43, 0x7B, 0x94, 0xB9, 0xE6, 0x20, 0x20, 0x7B, 0x99, 0x01, 0x43
	.byte 0x7B, 0x91, 0xB4, 0xE6, 0x1A, 0xAA, 0x90, 0x46, 0x04, 0x24, 0xA2, 0x44, 0x50, 0x46, 0x04, 0x38
	.byte 0x00, 0x68, 0x10, 0x70, 0x16, 0xE2, 0x10, 0x20, 0x7B, 0x99, 0x01, 0x43, 0x7B, 0x91, 0x10, 0x20
	.byte 0x7B, 0x9A, 0x10, 0x40, 0x00, 0x28, 0x02, 0xD0, 0x04, 0x24, 0xA2, 0x44, 0x0D, 0xE0, 0x40, 0x20
	.byte 0x7B, 0x99, 0x08, 0x40, 0x00, 0x28, 0x06, 0xD0, 0x04, 0x22, 0x92, 0x44, 0x50, 0x46, 0x04, 0x38
	.byte 0x00, 0x21, 0x44, 0x5E, 0x04, 0xE0, 0x04, 0x22, 0x92, 0x44, 0x50, 0x46, 0x04, 0x38, 0x04, 0x68
	.byte 0x00, 0x2C, 0x04, 0xDA, 0x64, 0x42, 0x03, 0x49, 0x69, 0x44, 0x2D, 0x20, 0x08, 0x70, 0x01, 0x22
	.byte 0x73, 0xE1, 0x00, 0x00, 0xC9, 0x01, 0x00, 0x00, 0x01, 0x20, 0x40, 0x42, 0x86, 0x42, 0x01, 0xD1
	.byte 0x06, 0x26, 0x07, 0xE0, 0x7A, 0x9C, 0x67, 0x2C, 0x01, 0xD0, 0x47, 0x2C, 0x02, 0xD1, 0x00, 0x2E
	.byte 0x00, 0xD1, 0x01, 0x26, 0x08, 0x20, 0x7B, 0x99, 0x08, 0x40, 0x08, 0x22, 0x92, 0x44, 0x50, 0x46
	.byte 0x08, 0x38, 0x01, 0x68, 0x42, 0x68, 0x7F, 0x91, 0x80, 0x92, 0x7F, 0x98, 0x80, 0x99, 0x03, 0xF0
	.byte 0xA5, 0xF9, 0x00, 0x28, 0x18, 0xD0, 0x09, 0x4B, 0x07, 0x4A, 0x7F, 0x98, 0x80, 0x99, 0x04, 0xF0
	.byte 0x33, 0xFB, 0x00, 0x28, 0x03, 0xDA, 0x06, 0x49, 0x69, 0x44, 0x2D, 0x20, 0x08, 0x70, 0x05, 0x4A
	.byte 0x90, 0x46, 0x03, 0x23, 0xC3, 0xE1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0xC9, 0x01, 0x00, 0x00, 0x84, 0x94, 0x33, 0x08, 0x7F, 0x98, 0x80, 0x99, 0x03, 0xF0, 0x98, 0xF9
	.byte 0x00, 0x28, 0x05, 0xD0, 0x01, 0x4C, 0xA0, 0x46, 0x03, 0x23, 0xB0, 0xE1, 0x88, 0x94, 0x33, 0x08
	.byte 0x80, 0x20, 0x40, 0x00, 0x7B, 0x99, 0x01, 0x43, 0x7B, 0x91, 0x00, 0x91, 0x72, 0xA8, 0x01, 0x90
	.byte 0x75, 0xA8, 0x02, 0x90, 0x7A, 0x9A, 0x03, 0x92, 0x76, 0xA8, 0x04, 0x90, 0x77, 0x98, 0x7F, 0x99
	.byte 0x80, 0x9A, 0x33, 0x1C, 0x00, 0xF0, 0x38, 0xFD, 0x80, 0x46, 0x7A, 0x9C, 0x67, 0x2C, 0x01, 0xD0
	.byte 0x47, 0x2C, 0x10, 0xD1, 0x75, 0xA8, 0x01, 0x68, 0x04, 0x20, 0x40, 0x42, 0x81, 0x42, 0x01, 0xDD
	.byte 0xB1, 0x42, 0x06, 0xDD, 0x45, 0x20, 0x7A, 0x99, 0x67, 0x29, 0x00, 0xD1, 0x65, 0x20, 0x7A, 0x90
	.byte 0x01, 0xE0, 0x67, 0x22, 0x7A, 0x92, 0x7A, 0x9C, 0x65, 0x2C, 0x0F, 0xDC, 0x75, 0xA8, 0x01, 0x68
	.byte 0x01, 0x39, 0x01, 0x60, 0x05, 0xA8, 0x7A, 0x9A, 0x00, 0xF0, 0x90, 0xFD, 0x81, 0x90, 0x76, 0xA8
	.byte 0x00, 0x68, 0x81, 0x99, 0x0B, 0x18, 0x01, 0x28, 0x20, 0xDC, 0x1A, 0xE0, 0x7A, 0x9C, 0x66, 0x2C
	.byte 0x10, 0xD1, 0x75, 0xA8, 0x00, 0x68, 0x00, 0x28, 0x0A, 0xDD, 0x03, 0x1C, 0x00, 0x2E, 0x04, 0xD1
	.byte 0x01, 0x20, 0x7B, 0x99, 0x08, 0x40, 0x00, 0x28, 0x18, 0xD0, 0x58, 0x1C, 0x83, 0x19, 0x15, 0xE0
	.byte 0xB3, 0x1C, 0x13, 0xE0, 0x75, 0xA8, 0x01, 0x68, 0x76, 0xA8, 0x00, 0x68, 0x81, 0x42, 0x07, 0xDB
	.byte 0x0B, 0x1C, 0x01, 0x20, 0x7B, 0x9A, 0x10, 0x40, 0x00, 0x28, 0x07, 0xD0, 0x01, 0x33, 0x05, 0xE0
	.byte 0x00, 0x29, 0x02, 0xDC, 0x02, 0x30, 0x43, 0x1A, 0x00, 0xE0, 0x43, 0x1C, 0x72, 0xA8, 0x00, 0x78
	.byte 0x2F, 0x1C, 0x08, 0x37, 0x00, 0x28, 0x00, 0xD1, 0x43, 0xE1, 0x02, 0x49, 0x69, 0x44, 0x2D, 0x20
	.byte 0x08, 0x70, 0x3E, 0xE1, 0xC9, 0x01, 0x00, 0x00, 0x10, 0x20, 0x7B, 0x9C, 0x20, 0x40, 0x00, 0x28
	.byte 0x07, 0xD0, 0x04, 0x20, 0x82, 0x44, 0x50, 0x46, 0x04, 0x38, 0x00, 0x68, 0x7C, 0x99, 0x01, 0x60
	.byte 0x76, 0xE5, 0x40, 0x20, 0x7B, 0x9A, 0x02, 0x40, 0x00, 0x2A, 0x08, 0xD0, 0x04, 0x24, 0xA2, 0x44
	.byte 0x50, 0x46, 0x04, 0x38, 0x00, 0x68, 0x7C, 0xA9, 0x09, 0x88, 0x01, 0x80, 0x68, 0xE5, 0x04, 0x22
	.byte 0x92, 0x44, 0x50, 0x46, 0x04, 0x38, 0x00, 0x68, 0x7C, 0x9C, 0x04, 0x60, 0x60, 0xE5, 0x10, 0x20
	.byte 0x7B, 0x99, 0x01, 0x43, 0x7B, 0x91, 0x10, 0x20, 0x7B, 0x9A, 0x10, 0x40, 0x00, 0x28, 0x0A, 0xD1
	.byte 0x40, 0x20, 0x7B, 0x99, 0x08, 0x40, 0x00, 0x28, 0x05, 0xD0, 0x04, 0x22, 0x92, 0x44, 0x50, 0x46
	.byte 0x04, 0x38, 0x04, 0x88, 0x04, 0xE0, 0x04, 0x24, 0xA2, 0x44, 0x50, 0x46, 0x04, 0x38, 0x04, 0x68
	.byte 0x00, 0x22, 0x76, 0xE0, 0x04, 0x20, 0x82, 0x44, 0x50, 0x46, 0x04, 0x38, 0x04, 0x68, 0x02, 0x22
	.byte 0x03, 0x49, 0x84, 0x91, 0x7B, 0x98, 0x10, 0x43, 0x7B, 0x90, 0x78, 0x21, 0x7A, 0x91, 0x68, 0xE0
	.byte 0x8C, 0x94, 0x33, 0x08, 0x04, 0x22, 0x92, 0x44, 0x50, 0x46, 0x04, 0x38, 0x00, 0x68, 0x80, 0x46
	.byte 0x00, 0x28, 0x01, 0xD1, 0x08, 0x4C, 0xA0, 0x46, 0x00, 0x2E, 0x0F, 0xDB, 0x40, 0x46, 0x00, 0x21
	.byte 0x32, 0x1C, 0x02, 0xF0, 0x61, 0xFB, 0x00, 0x28, 0x04, 0xD0, 0x41, 0x46, 0x43, 0x1A, 0xB3, 0x42
	.byte 0x00, 0xDC, 0xD0, 0xE0, 0x33, 0x1C, 0xCE, 0xE0, 0xA0, 0x94, 0x33, 0x08, 0x40, 0x46, 0x03, 0xF0
	.byte 0x65, 0xF9, 0x03, 0x1C, 0xC7, 0xE0, 0x10, 0x20, 0x7B, 0x9A, 0x02, 0x43, 0x7B, 0x92, 0x10, 0x20
	.byte 0x7B, 0x9C, 0x20, 0x40, 0x00, 0x28, 0x02, 0xD0, 0x04, 0x20, 0x82, 0x44, 0x0C, 0xE0, 0x40, 0x20
	.byte 0x7B, 0x99, 0x08, 0x40, 0x00, 0x28, 0x05, 0xD0, 0x04, 0x22, 0x92, 0x44, 0x50, 0x46, 0x04, 0x38
	.byte 0x04, 0x88, 0x04, 0xE0, 0x04, 0x24, 0xA2, 0x44, 0x50, 0x46, 0x04, 0x38, 0x04, 0x68, 0x01, 0x22
	.byte 0x27, 0xE0, 0x01, 0x48, 0x84, 0x90, 0x03, 0xE0, 0xA8, 0x94, 0x33, 0x08, 0x08, 0x49, 0x84, 0x91
	.byte 0x10, 0x20, 0x7B, 0x9A, 0x10, 0x40, 0x00, 0x28, 0x0C, 0xD1, 0x40, 0x20, 0x7B, 0x99, 0x08, 0x40
	.byte 0x00, 0x28, 0x07, 0xD0, 0x04, 0x22, 0x92, 0x44, 0x50, 0x46, 0x04, 0x38, 0x04, 0x88, 0x06, 0xE0
	.byte 0x8C, 0x94, 0x33, 0x08, 0x04, 0x24, 0xA2, 0x44, 0x50, 0x46, 0x04, 0x38, 0x04, 0x68, 0x02, 0x22
	.byte 0x01, 0x20, 0x7B, 0x99, 0x08, 0x40, 0x00, 0x28, 0x03, 0xD0, 0x00, 0x2C, 0x01, 0xD0, 0x11, 0x43
	.byte 0x7B, 0x91, 0x12, 0x49, 0x69, 0x44, 0x00, 0x20, 0x08, 0x70, 0x82, 0x96, 0x00, 0x2E, 0x04, 0xDB
	.byte 0x81, 0x20, 0x40, 0x42, 0x7B, 0x99, 0x01, 0x40, 0x7B, 0x91, 0xE2, 0x20, 0x40, 0x00, 0x68, 0x44
	.byte 0x80, 0x46, 0x00, 0x2C, 0x04, 0xD1, 0x2F, 0x1C, 0x08, 0x37, 0x82, 0x99, 0x00, 0x29, 0x5B, 0xD0
	.byte 0x01, 0x2A, 0x2C, 0xD0, 0x01, 0x2A, 0x0D, 0xD3, 0x02, 0x2A, 0x45, 0xD0, 0x04, 0x4A, 0x90, 0x46
	.byte 0x40, 0x46, 0x03, 0xF0, 0xFB, 0xF8, 0x03, 0x1C, 0x61, 0xE0, 0x00, 0x00, 0xC9, 0x01, 0x00, 0x00
	.byte 0xBC, 0x94, 0x33, 0x08, 0x2F, 0x1C, 0x08, 0x37, 0x07, 0x22, 0x01, 0x20, 0x40, 0x42, 0x80, 0x44
	.byte 0x20, 0x1C, 0x10, 0x40, 0x01, 0x1C, 0x30, 0x31, 0x40, 0x46, 0x01, 0x70, 0xE4, 0x08, 0x00, 0x2C
	.byte 0xF3, 0xD1, 0x01, 0x20, 0x7B, 0x9A, 0x10, 0x40, 0x00, 0x28, 0x35, 0xD0, 0x30, 0x29, 0x33, 0xD0
	.byte 0x01, 0x24, 0x64, 0x42, 0xA0, 0x44, 0x30, 0x20, 0x41, 0x46, 0x08, 0x70, 0x2C, 0xE0, 0x2F, 0x1C
	.byte 0x08, 0x37, 0x09, 0x2C, 0x10, 0xD9, 0x01, 0x22, 0x52, 0x42, 0x90, 0x44, 0x20, 0x1C, 0x0A, 0x21
	.byte 0xFF, 0xF7, 0x30, 0xFB, 0x30, 0x30, 0x41, 0x46, 0x08, 0x70, 0x20, 0x1C, 0x0A, 0x21, 0xFF, 0xF7
	.byte 0xED, 0xFA, 0x04, 0x1C, 0x09, 0x2C, 0xEE, 0xD8, 0x01, 0x22, 0x52, 0x42, 0x90, 0x44, 0x20, 0x1C
	.byte 0x30, 0x30, 0x44, 0x46, 0x20, 0x70, 0x0F, 0xE0, 0x2F, 0x1C, 0x08, 0x37, 0x0F, 0x21, 0x01, 0x20
	.byte 0x40, 0x42, 0x80, 0x44, 0x20, 0x1C, 0x08, 0x40, 0x84, 0x9A, 0x10, 0x18, 0x00, 0x78, 0x42, 0x46
	.byte 0x10, 0x70, 0x24, 0x09, 0x00, 0x2C, 0xF2, 0xD1, 0x05, 0xAC, 0x41, 0x46, 0x60, 0x1A, 0xD8, 0x22
	.byte 0x52, 0x00, 0x83, 0x18, 0x0D, 0xE0
	.global _08017E8A
_08017E8A:
	ldr r4, [sp, #0x1E8]
	cmp r4, #0x00
	bne _08017E92
	b _080185A0
	.global _08017E92
_08017E92:
	add r0, sp, #0x068
	mov r8, r0
	strb r4, [r0, #0x00]
	movs r3, #0x01
	ldr r1, _08017EC4 @ =0x000001C9
	add r1, sp
	movs r0, #0x00
	strb r0, [r1, #0x00]
	adds r7, r5, #0x0
	adds r7, #0x08
	str r3, [sp, #0x20C]
	ldr r2, [sp, #0x208]
	cmp r3, r2
	bge _08017EB0
	str r2, [sp, #0x20C]
	.global _08017EB0
_08017EB0:
	ldr r0, _08017EC4 @ =0x000001C9
	add r0, sp
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08017EC8
	ldr r4, [sp, #0x20C]
	adds r4, #0x01
	str r4, [sp, #0x20C]
	b _08017ED8
	.byte 0x00, 0x00
	.global _08017EC4
_08017EC4: .4byte 0x000001C9
	.global _08017EC8
_08017EC8:
	movs r0, #0x02
	ldr r1, [sp, #0x1EC]
	ands r0, r1
	cmp r0, #0x00
	beq _08017ED8
	ldr r2, [sp, #0x20C]
	adds r2, #0x02
	str r2, [sp, #0x20C]
	.global _08017ED8
_08017ED8:
	movs r0, #0x84
	ldr r4, [sp, #0x1EC]
	ands r0, r4
	cmp r0, #0x00
	bne _08017F58
	ldr r0, [sp, #0x1F4]
	ldr r1, [sp, #0x20C]
	subs r4, r0, r1
	cmp r4, #0x00
	ble _08017F58
	ldr r1, _08017F84 @ =0x08339464
	cmp r4, #0x10
	ble _08017F2C
	mov r6, r9
	.global _08017EF4
_08017EF4:
	str r1, [r5, #0x00]
	movs r0, #0x10
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	adds r0, #0x10
	str r0, [r6, #0x08]
	adds r5, r7, #0x0
	ldr r0, [r6, #0x04]
	adds r0, #0x01
	str r0, [r6, #0x04]
	cmp r0, #0x07
	ble _08017F22
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	str r3, [sp, #0x21C]
	bl sub_080175D4
	ldr r3, [sp, #0x21C]
	cmp r0, #0x00
	beq _08017F1E
	b _080185B8
	.global _08017F1E
_08017F1E:
	add r5, sp, #0x028
	ldr r1, _08017F84 @ =0x08339464
	.global _08017F22
_08017F22:
	subs r4, #0x10
	adds r7, r5, #0x0
	adds r7, #0x08
	cmp r4, #0x10
	bgt _08017EF4
	.global _08017F2C
_08017F2C:
	str r1, [r5, #0x00]
	str r4, [r5, #0x04]
	mov r2, r9
	ldr r0, [r2, #0x08]
	adds r0, r0, r4
	str r0, [r2, #0x08]
	adds r5, r7, #0x0
	ldr r0, [r2, #0x04]
	adds r0, #0x01
	str r0, [r2, #0x04]
	cmp r0, #0x07
	ble _08017F58
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	str r3, [sp, #0x21C]
	bl sub_080175D4
	ldr r3, [sp, #0x21C]
	cmp r0, #0x00
	beq _08017F56
	b _080185B8
	.global _08017F56
_08017F56:
	add r5, sp, #0x028
	.global _08017F58
_08017F58:
	ldr r1, _08017F88 @ =0x000001C9
	add r1, sp
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08017F8C
	str r1, [r5, #0x00]
	movs r0, #0x01
	str r0, [r5, #0x04]
	mov r4, r9
	ldr r0, [r4, #0x08]
	adds r0, #0x01
	str r0, [r4, #0x08]
	adds r5, #0x08
	ldr r0, [r4, #0x04]
	adds r0, #0x01
	str r0, [r4, #0x04]
	cmp r0, #0x07
	ble _08017FCC
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	b _08017FBC
	.byte 0x00, 0x00
	.global _08017F84
_08017F84: .4byte 0x08339464
	.global _08017F88
_08017F88: .4byte 0x000001C9
	.global _08017F8C
_08017F8C:
	movs r2, #0x02
	ldr r0, [sp, #0x1EC]
	ands r0, r2
	cmp r0, #0x00
	beq _08017FCC
	add r1, sp, #0x1C4
	movs r0, #0x30
	strb r0, [r1, #0x00]
	add r0, sp, #0x1E8
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x01]
	str r1, [r5, #0x00]
	str r2, [r5, #0x04]
	mov r1, r9
	ldr r0, [r1, #0x08]
	adds r0, #0x02
	str r0, [r1, #0x08]
	adds r5, #0x08
	ldr r0, [r1, #0x04]
	adds r0, #0x01
	str r0, [r1, #0x04]
	cmp r0, #0x07
	ble _08017FCC
	ldr r0, [sp, #0x1E0]
	.global _08017FBC
_08017FBC:
	str r3, [sp, #0x21C]
	bl sub_080175D4
	ldr r3, [sp, #0x21C]
	cmp r0, #0x00
	beq _08017FCA
	b _080185B8
	.global _08017FCA
_08017FCA:
	add r5, sp, #0x028
	.global _08017FCC
_08017FCC:
	movs r0, #0x84
	ldr r2, [sp, #0x1EC]
	ands r0, r2
	cmp r0, #0x80
	bne _08018048
	ldr r0, [sp, #0x1F4]
	ldr r1, [sp, #0x20C]
	subs r4, r0, r1
	cmp r4, #0x00
	ble _08018048
	ldr r1, _080180E4 @ =0x08339474
	cmp r4, #0x10
	ble _0801801C
	mov r6, r9
	.global _08017FE8
_08017FE8:
	str r1, [r5, #0x00]
	movs r0, #0x10
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	adds r0, #0x10
	str r0, [r6, #0x08]
	adds r5, #0x08
	ldr r0, [r6, #0x04]
	adds r0, #0x01
	str r0, [r6, #0x04]
	cmp r0, #0x07
	ble _08018016
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	str r3, [sp, #0x21C]
	bl sub_080175D4
	ldr r3, [sp, #0x21C]
	cmp r0, #0x00
	beq _08018012
	b _080185B8
	.global _08018012
_08018012:
	add r5, sp, #0x028
	ldr r1, _080180E4 @ =0x08339474
	.global _08018016
_08018016:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _08017FE8
	.global _0801801C
_0801801C:
	str r1, [r5, #0x00]
	str r4, [r5, #0x04]
	mov r2, r9
	ldr r0, [r2, #0x08]
	adds r0, r0, r4
	str r0, [r2, #0x08]
	adds r5, #0x08
	ldr r0, [r2, #0x04]
	adds r0, #0x01
	str r0, [r2, #0x04]
	cmp r0, #0x07
	ble _08018048
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	str r3, [sp, #0x21C]
	bl sub_080175D4
	ldr r3, [sp, #0x21C]
	cmp r0, #0x00
	beq _08018046
	b _080185B8
	.global _08018046
_08018046:
	add r5, sp, #0x028
	.global _08018048
_08018048:
	ldr r0, [sp, #0x208]
	subs r4, r0, r3
	cmp r4, #0x00
	ble _080180B6
	ldr r1, _080180E4 @ =0x08339474
	cmp r4, #0x10
	ble _0801808C
	mov r6, r9
	.global _08018058
_08018058:
	str r1, [r5, #0x00]
	movs r0, #0x10
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	adds r0, #0x10
	str r0, [r6, #0x08]
	adds r5, #0x08
	ldr r0, [r6, #0x04]
	adds r0, #0x01
	str r0, [r6, #0x04]
	cmp r0, #0x07
	ble _08018086
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	str r3, [sp, #0x21C]
	bl sub_080175D4
	ldr r3, [sp, #0x21C]
	cmp r0, #0x00
	beq _08018082
	b _080185B8
	.global _08018082
_08018082:
	add r5, sp, #0x028
	ldr r1, _080180E4 @ =0x08339474
	.global _08018086
_08018086:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _08018058
	.global _0801808C
_0801808C:
	str r1, [r5, #0x00]
	str r4, [r5, #0x04]
	mov r1, r9
	ldr r0, [r1, #0x08]
	adds r0, r0, r4
	str r0, [r1, #0x08]
	adds r5, #0x08
	ldr r0, [r1, #0x04]
	adds r0, #0x01
	str r0, [r1, #0x04]
	cmp r0, #0x07
	ble _080180B6
	ldr r0, [sp, #0x1E0]
	str r3, [sp, #0x21C]
	bl sub_080175D4
	ldr r3, [sp, #0x21C]
	cmp r0, #0x00
	beq _080180B4
	b _080185B8
	.global _080180B4
_080180B4:
	add r5, sp, #0x028
	.global _080180B6
_080180B6:
	movs r0, #0x80
	lsls r0, r0, #0x01
	ldr r2, [sp, #0x1EC]
	ands r0, r2
	cmp r0, #0x00
	bne _080180E8
	mov r4, r8
	str r4, [r5, #0x00]
	str r3, [r5, #0x04]
	mov r1, r9
	ldr r0, [r1, #0x08]
	adds r0, r0, r3
	str r0, [r1, #0x08]
	adds r5, #0x08
	ldr r0, [r1, #0x04]
	adds r0, #0x01
	str r0, [r1, #0x04]
	cmp r0, #0x07
	bgt _080180DE
	b _080184FE
	.global _080180DE
_080180DE:
	ldr r0, [sp, #0x1E0]
	b _080184F4
	.byte 0x00, 0x00
	.global _080180E4
_080180E4: .4byte 0x08339474
	.global _080180E8
_080180E8:
	ldr r2, [sp, #0x1E8]
	cmp r2, #0x65
	bgt _080180F0
	b _080183D4
	.global _080180F0
_080180F0:
	ldr r3, _080181BC @ =0x00000000
	ldr r2, _080181B8 @ =0x00000000
	ldr r0, [sp, #0x1FC]
	ldr r1, [sp, #0x200]
	bl sub_0801C03C
	cmp r0, #0x00
	bne _080181C8
	ldr r0, _080181C0 @ =0x083394D8
	str r0, [r5, #0x00]
	movs r6, #0x01
	str r6, [r5, #0x04]
	mov r4, r9
	ldr r0, [r4, #0x08]
	adds r0, #0x01
	str r0, [r4, #0x08]
	adds r5, #0x08
	ldr r0, [r4, #0x04]
	adds r0, #0x01
	str r0, [r4, #0x04]
	cmp r0, #0x07
	ble _0801812C
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	bl sub_080175D4
	cmp r0, #0x00
	beq _0801812A
	b _080185B8
	.global _0801812A
_0801812A:
	add r5, sp, #0x028
	.global _0801812C
_0801812C:
	add r0, sp, #0x1D4
	ldr r1, [r0, #0x00]
	add r4, sp, #0x1D8
	ldr r0, [r4, #0x00]
	cmp r1, r0
	blt _08018142
	ldr r0, [sp, #0x1EC]
	ands r0, r6
	cmp r0, #0x00
	bne _08018142
	b _080184FE
	.global _08018142
_08018142:
	ldr r0, [sp, #0x1F8]
	str r0, [r5, #0x00]
	str r6, [r5, #0x04]
	mov r1, r9
	ldr r0, [r1, #0x08]
	adds r0, #0x01
	str r0, [r1, #0x08]
	adds r5, #0x08
	ldr r0, [r1, #0x04]
	adds r0, #0x01
	str r0, [r1, #0x04]
	cmp r0, #0x07
	ble _0801816A
	ldr r0, [sp, #0x1E0]
	bl sub_080175D4
	cmp r0, #0x00
	beq _08018168
	b _080185B8
	.global _08018168
_08018168:
	add r5, sp, #0x028
	.global _0801816A
_0801816A:
	ldr r0, [r4, #0x00]
	subs r4, r0, #0x1
	cmp r4, #0x00
	bgt _08018174
	b _080184FE
	.global _08018174
_08018174:
	ldr r1, _080181C4 @ =0x08339474
	cmp r4, #0x10
	ble _080181AC
	mov r6, r9
	.global _0801817C
_0801817C:
	str r1, [r5, #0x00]
	movs r0, #0x10
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	adds r0, #0x10
	str r0, [r6, #0x08]
	adds r5, #0x08
	ldr r0, [r6, #0x04]
	adds r0, #0x01
	str r0, [r6, #0x04]
	cmp r0, #0x07
	ble _080181A6
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	bl sub_080175D4
	cmp r0, #0x00
	beq _080181A2
	b _080185B8
	.global _080181A2
_080181A2:
	add r5, sp, #0x028
	ldr r1, _080181C4 @ =0x08339474
	.global _080181A6
_080181A6:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _0801817C
	.global _080181AC
_080181AC:
	str r1, [r5, #0x00]
	str r4, [r5, #0x04]
	mov r2, r9
	ldr r0, [r2, #0x08]
	adds r0, r0, r4
	b _080184E2
	.global _080181B8
_080181B8: .4byte 0x00000000
	.global _080181BC
_080181BC: .4byte 0x00000000
	.global _080181C0
_080181C0: .4byte 0x083394D8
	.global _080181C4
_080181C4: .4byte 0x08339474
	.global _080181C8
_080181C8:
	add r6, sp, #0x1D4
	ldr r2, [r6, #0x00]
	cmp r2, #0x00
	bgt _080182B0
	ldr r0, _080182A8 @ =0x083394D8
	str r0, [r5, #0x00]
	movs r4, #0x01
	str r4, [r5, #0x04]
	mov r1, r9
	ldr r0, [r1, #0x08]
	adds r0, #0x01
	str r0, [r1, #0x08]
	adds r5, #0x08
	ldr r0, [r1, #0x04]
	adds r0, #0x01
	str r0, [r1, #0x04]
	cmp r0, #0x07
	ble _080181FA
	ldr r0, [sp, #0x1E0]
	bl sub_080175D4
	cmp r0, #0x00
	beq _080181F8
	b _080185B8
	.global _080181F8
_080181F8:
	add r5, sp, #0x028
	.global _080181FA
_080181FA:
	ldr r2, [sp, #0x1F8]
	str r2, [r5, #0x00]
	str r4, [r5, #0x04]
	mov r4, r9
	ldr r0, [r4, #0x08]
	adds r0, #0x01
	str r0, [r4, #0x08]
	adds r5, #0x08
	ldr r0, [r4, #0x04]
	adds r0, #0x01
	str r0, [r4, #0x04]
	cmp r0, #0x07
	ble _08018224
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	bl sub_080175D4
	cmp r0, #0x00
	beq _08018222
	b _080185B8
	.global _08018222
_08018222:
	add r5, sp, #0x028
	.global _08018224
_08018224:
	ldr r0, [r6, #0x00]
	negs r4, r0
	cmp r4, #0x00
	ble _0801828A
	ldr r1, _080182AC @ =0x08339474
	cmp r4, #0x10
	ble _08018264
	mov r6, r9
	.global _08018234
_08018234:
	str r1, [r5, #0x00]
	movs r0, #0x10
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	adds r0, #0x10
	str r0, [r6, #0x08]
	adds r5, #0x08
	ldr r0, [r6, #0x04]
	adds r0, #0x01
	str r0, [r6, #0x04]
	cmp r0, #0x07
	ble _0801825E
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	bl sub_080175D4
	cmp r0, #0x00
	beq _0801825A
	b _080185B8
	.global _0801825A
_0801825A:
	add r5, sp, #0x028
	ldr r1, _080182AC @ =0x08339474
	.global _0801825E
_0801825E:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _08018234
	.global _08018264
_08018264:
	str r1, [r5, #0x00]
	str r4, [r5, #0x04]
	mov r1, r9
	ldr r0, [r1, #0x08]
	adds r0, r0, r4
	str r0, [r1, #0x08]
	adds r5, #0x08
	ldr r0, [r1, #0x04]
	adds r0, #0x01
	str r0, [r1, #0x04]
	cmp r0, #0x07
	ble _0801828A
	ldr r0, [sp, #0x1E0]
	bl sub_080175D4
	cmp r0, #0x00
	beq _08018288
	b _080185B8
	.global _08018288
_08018288:
	add r5, sp, #0x028
	.global _0801828A
_0801828A:
	mov r2, r8
	str r2, [r5, #0x00]
	add r0, sp, #0x1D8
	ldr r1, [r0, #0x00]
	str r1, [r5, #0x04]
	mov r4, r9
	ldr r0, [r4, #0x08]
	adds r0, r0, r1
	str r0, [r4, #0x08]
	adds r5, #0x08
	ldr r0, [r4, #0x04]
	adds r0, #0x01
	str r0, [r4, #0x04]
	b _080184EC
	.byte 0x00, 0x00
	.global _080182A8
_080182A8: .4byte 0x083394D8
	.global _080182AC
_080182AC: .4byte 0x08339474
	.global _080182B0
_080182B0:
	add r4, sp, #0x1D8
	ldr r1, [r4, #0x00]
	cmp r2, r1
	blt _0801836C
	mov r0, r8
	str r0, [r5, #0x00]
	str r1, [r5, #0x04]
	mov r2, r9
	ldr r0, [r2, #0x08]
	adds r0, r0, r1
	str r0, [r2, #0x08]
	adds r5, #0x08
	ldr r0, [r2, #0x04]
	adds r0, #0x01
	str r0, [r2, #0x04]
	cmp r0, #0x07
	ble _080182E2
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	bl sub_080175D4
	cmp r0, #0x00
	beq _080182E0
	b _080185B8
	.global _080182E0
_080182E0:
	add r5, sp, #0x028
	.global _080182E2
_080182E2:
	ldr r1, [r6, #0x00]
	ldr r0, [r4, #0x00]
	subs r4, r1, r0
	cmp r4, #0x00
	ble _0801834A
	ldr r1, _08018364 @ =0x08339474
	cmp r4, #0x10
	ble _08018324
	mov r6, r9
	.global _080182F4
_080182F4:
	str r1, [r5, #0x00]
	movs r0, #0x10
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	adds r0, #0x10
	str r0, [r6, #0x08]
	adds r5, #0x08
	ldr r0, [r6, #0x04]
	adds r0, #0x01
	str r0, [r6, #0x04]
	cmp r0, #0x07
	ble _0801831E
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	bl sub_080175D4
	cmp r0, #0x00
	beq _0801831A
	b _080185B8
	.global _0801831A
_0801831A:
	add r5, sp, #0x028
	ldr r1, _08018364 @ =0x08339474
	.global _0801831E
_0801831E:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _080182F4
	.global _08018324
_08018324:
	str r1, [r5, #0x00]
	str r4, [r5, #0x04]
	mov r1, r9
	ldr r0, [r1, #0x08]
	adds r0, r0, r4
	str r0, [r1, #0x08]
	adds r5, #0x08
	ldr r0, [r1, #0x04]
	adds r0, #0x01
	str r0, [r1, #0x04]
	cmp r0, #0x07
	ble _0801834A
	ldr r0, [sp, #0x1E0]
	bl sub_080175D4
	cmp r0, #0x00
	beq _08018348
	b _080185B8
	.global _08018348
_08018348:
	add r5, sp, #0x028
	.global _0801834A
_0801834A:
	movs r1, #0x01
	ldr r0, [sp, #0x1EC]
	ands r0, r1
	cmp r0, #0x00
	bne _08018356
	b _080184FE
	.global _08018356
_08018356:
	ldr r0, _08018368 @ =0x083394DC
	str r0, [r5, #0x00]
	str r1, [r5, #0x04]
	mov r2, r9
	ldr r0, [r2, #0x08]
	adds r0, #0x01
	b _080184E2
	.global _08018364
_08018364: .4byte 0x08339474
	.global _08018368
_08018368: .4byte 0x083394DC
	.global _0801836C
_0801836C:
	mov r0, r8
	str r0, [r5, #0x00]
	str r2, [r5, #0x04]
	mov r1, r9
	ldr r0, [r1, #0x08]
	adds r0, r0, r2
	str r0, [r1, #0x08]
	adds r5, #0x08
	ldr r0, [r1, #0x04]
	adds r0, #0x01
	str r0, [r1, #0x04]
	cmp r0, #0x07
	ble _08018394
	ldr r0, [sp, #0x1E0]
	bl sub_080175D4
	cmp r0, #0x00
	beq _08018392
	b _080185B8
	.global _08018392
_08018392:
	add r5, sp, #0x028
	.global _08018394
_08018394:
	ldr r0, [r6, #0x00]
	add r8, r0
	ldr r0, _080183D0 @ =0x083394DC
	str r0, [r5, #0x00]
	movs r0, #0x01
	str r0, [r5, #0x04]
	mov r2, r9
	ldr r0, [r2, #0x08]
	adds r0, #0x01
	str r0, [r2, #0x08]
	adds r5, #0x08
	ldr r0, [r2, #0x04]
	adds r0, #0x01
	str r0, [r2, #0x04]
	cmp r0, #0x07
	ble _080183C4
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	bl sub_080175D4
	cmp r0, #0x00
	beq _080183C2
	b _080185B8
	.global _080183C2
_080183C2:
	add r5, sp, #0x028
	.global _080183C4
_080183C4:
	mov r0, r8
	str r0, [r5, #0x00]
	ldr r1, [r4, #0x00]
	ldr r0, [r6, #0x00]
	subs r1, r1, r0
	b _080184DA
	.global _080183D0
_080183D0: .4byte 0x083394DC
	.global _080183D4
_080183D4:
	add r4, sp, #0x1D8
	ldr r0, [r4, #0x00]
	cmp r0, #0x01
	bgt _080183E6
	movs r1, #0x01
	ldr r0, [sp, #0x1EC]
	ands r0, r1
	cmp r0, #0x00
	beq _080184AC
	.global _080183E6
_080183E6:
	add r1, sp, #0x1C4
	mov r2, r8
	ldrb r0, [r2, #0x00]
	strb r0, [r1, #0x00]
	movs r0, #0x01
	add r8, r0
	movs r0, #0x2E
	strb r0, [r1, #0x01]
	str r1, [r5, #0x00]
	movs r0, #0x02
	str r0, [r5, #0x04]
	mov r1, r9
	ldr r0, [r1, #0x08]
	adds r0, #0x02
	str r0, [r1, #0x08]
	adds r5, #0x08
	ldr r0, [r1, #0x04]
	adds r0, #0x01
	str r0, [r1, #0x04]
	cmp r0, #0x07
	ble _0801841E
	ldr r0, [sp, #0x1E0]
	bl sub_080175D4
	cmp r0, #0x00
	beq _0801841C
	b _080185B8
	.global _0801841C
_0801841C:
	add r5, sp, #0x028
	.global _0801841E
_0801841E:
	ldr r3, _08018448 @ =0x00000000
	ldr r2, _08018444 @ =0x00000000
	ldr r0, [sp, #0x1FC]
	ldr r1, [sp, #0x200]
	bl sub_0801C088
	cmp r0, #0x00
	beq _0801844C
	mov r2, r8
	str r2, [r5, #0x00]
	ldr r1, [r4, #0x00]
	subs r0, r1, #0x1
	str r0, [r5, #0x04]
	mov r4, r9
	ldr r0, [r4, #0x08]
	subs r0, #0x01
	adds r0, r0, r1
	b _080184B8
	.byte 0x00, 0x00
	.global _08018444
_08018444: .4byte 0x00000000
	.global _08018448
_08018448: .4byte 0x00000000
	.global _0801844C
_0801844C:
	ldr r0, [r4, #0x00]
	subs r4, r0, #0x1
	cmp r4, #0x00
	ble _080184D4
	ldr r1, _080184A8 @ =0x08339474
	cmp r4, #0x10
	ble _0801848C
	mov r6, r9
	.global _0801845C
_0801845C:
	str r1, [r5, #0x00]
	movs r0, #0x10
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	adds r0, #0x10
	str r0, [r6, #0x08]
	adds r5, #0x08
	ldr r0, [r6, #0x04]
	adds r0, #0x01
	str r0, [r6, #0x04]
	cmp r0, #0x07
	ble _08018486
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	bl sub_080175D4
	cmp r0, #0x00
	beq _08018482
	b _080185B8
	.global _08018482
_08018482:
	add r5, sp, #0x028
	ldr r1, _080184A8 @ =0x08339474
	.global _08018486
_08018486:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _0801845C
	.global _0801848C
_0801848C:
	str r1, [r5, #0x00]
	str r4, [r5, #0x04]
	mov r1, r9
	ldr r0, [r1, #0x08]
	adds r0, r0, r4
	str r0, [r1, #0x08]
	adds r5, #0x08
	ldr r0, [r1, #0x04]
	adds r0, #0x01
	str r0, [r1, #0x04]
	cmp r0, #0x07
	ble _080184D4
	ldr r0, [sp, #0x1E0]
	b _080184CA
	.global _080184A8
_080184A8: .4byte 0x08339474
	.global _080184AC
_080184AC:
	mov r2, r8
	str r2, [r5, #0x00]
	str r1, [r5, #0x04]
	mov r4, r9
	ldr r0, [r4, #0x08]
	adds r0, #0x01
	.global _080184B8
_080184B8:
	str r0, [r4, #0x08]
	adds r5, #0x08
	ldr r0, [r4, #0x04]
	adds r0, #0x01
	str r0, [r4, #0x04]
	cmp r0, #0x07
	ble _080184D4
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	.global _080184CA
_080184CA:
	bl sub_080175D4
	cmp r0, #0x00
	bne _080185B8
	add r5, sp, #0x028
	.global _080184D4
_080184D4:
	add r0, sp, #0x014
	str r0, [r5, #0x00]
	ldr r1, [sp, #0x204]
	.global _080184DA
_080184DA:
	str r1, [r5, #0x04]
	mov r2, r9
	ldr r0, [r2, #0x08]
	adds r0, r0, r1
	.global _080184E2
_080184E2:
	str r0, [r2, #0x08]
	adds r5, #0x08
	ldr r0, [r2, #0x04]
	adds r0, #0x01
	str r0, [r2, #0x04]
	.global _080184EC
_080184EC:
	cmp r0, #0x07
	ble _080184FE
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	.global _080184F4
_080184F4:
	bl sub_080175D4
	cmp r0, #0x00
	bne _080185B8
	add r5, sp, #0x028
	.global _080184FE
_080184FE:
	movs r0, #0x04
	ldr r4, [sp, #0x1EC]
	ands r4, r0
	cmp r4, #0x00
	beq _0801856A
	ldr r0, [sp, #0x1F4]
	ldr r1, [sp, #0x20C]
	subs r4, r0, r1
	cmp r4, #0x00
	ble _0801856A
	ldr r1, _0801859C @ =0x08339464
	cmp r4, #0x10
	ble _08018548
	mov r6, r9
	.global _0801851A
_0801851A:
	str r1, [r5, #0x00]
	movs r0, #0x10
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	adds r0, #0x10
	str r0, [r6, #0x08]
	adds r5, #0x08
	ldr r0, [r6, #0x04]
	adds r0, #0x01
	str r0, [r6, #0x04]
	cmp r0, #0x07
	ble _08018542
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	bl sub_080175D4
	cmp r0, #0x00
	bne _080185B8
	add r5, sp, #0x028
	ldr r1, _0801859C @ =0x08339464
	.global _08018542
_08018542:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _0801851A
	.global _08018548
_08018548:
	str r1, [r5, #0x00]
	str r4, [r5, #0x04]
	mov r2, r9
	ldr r0, [r2, #0x08]
	adds r0, r0, r4
	str r0, [r2, #0x08]
	ldr r0, [r2, #0x04]
	adds r0, #0x01
	str r0, [r2, #0x04]
	cmp r0, #0x07
	ble _0801856A
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	bl sub_080175D4
	cmp r0, #0x00
	bne _080185B8
	.global _0801856A
_0801856A:
	ldr r0, [sp, #0x20C]
	ldr r4, [sp, #0x1F4]
	cmp r0, r4
	bge _08018574
	adds r0, r4, #0x0
	.global _08018574
_08018574:
	ldr r1, [sp, #0x1F0]
	adds r1, r1, r0
	str r1, [sp, #0x1F0]
	mov r2, r9
	ldr r0, [r2, #0x08]
	cmp r0, #0x00
	beq _0801858E
	ldr r0, [sp, #0x1E0]
	mov r1, r9
	bl sub_080175D4
	cmp r0, #0x00
	bne _080185B8
	.global _0801858E
_0801858E:
	movs r0, #0x00
	mov r4, r9
	str r0, [r4, #0x04]
	add r5, sp, #0x028
	bl _08017734
	lsls r0, r0, #0x00
	.global _0801859C
_0801859C:
	str r4, [sp, #0x190]
	lsrs r3, r6, #0x20
	.global _080185A0
_080185A0:
	mov r1, r9
	ldr r0, [r1, #0x08]
	cmp r0, #0x00
	beq _080185B2
	ldr r0, [sp, #0x1E0]
	bl sub_080175D4
	cmp r0, #0x00
	bne _080185B8
	.global _080185B2
_080185B2:
	movs r0, #0x00
	mov r1, r9
	str r0, [r1, #0x04]
	.global _080185B8
_080185B8:
	movs r0, #0x40
	ldr r2, [sp, #0x1E0]
	ldrh r2, [r2, #0x0C]
	ands r0, r2
	movs r1, #0x01
	negs r1, r1
	cmp r0, #0x00
	bne _080185CA
	ldr r1, [sp, #0x1F0]
	.global _080185CA
_080185CA:
	adds r0, r1, #0x0
	.global _080185CC
_080185CC:
	movs r3, #0x88
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7, pc}
	thumb_func_start sub_080185DC
sub_080185DC:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x01C
	str r0, [sp, #0x018]
	adds r5, r2, #0x0
	adds r4, r1, #0x0
	mov r8, r3
	ldr r6, [sp, #0x03C]
	ldr r0, [sp, #0x044]
	mov r10, r0
	ldr r1, [sp, #0x048]
	mov r9, r1
	cmp r1, #0x66
	bne _08018602
	movs r7, #0x03
	b _08018612
	.global _08018602
_08018602:
	mov r0, r9
	cmp r0, #0x65
	beq _0801860C
	cmp r0, #0x45
	bne _08018610
	.global _0801860C
_0801860C:
	movs r1, #0x01
	add r8, r1
	.global _08018610
_08018610:
	movs r7, #0x02
	.global _08018612
_08018612:
	lsls r0, r4, #0x1F
	lsrs r0, r0, #0x1F
	cmp r0, #0x00
	beq _08018628
	adds r1, r5, #0x0
	adds r0, r4, #0x0
	bl sub_0801C2F4
	adds r5, r1, #0x0
	adds r4, r0, #0x0
	movs r0, #0x2D
	.global _08018628
_08018628:
	ldr r1, [sp, #0x040]
	strb r0, [r1, #0x00]
	mov r0, r8
	str r0, [sp, #0x000]
	mov r1, r10
	str r1, [sp, #0x004]
	add r0, sp, #0x010
	str r0, [sp, #0x008]
	add r0, sp, #0x014
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x018]
	adds r2, r5, #0x0
	adds r1, r4, #0x0
	adds r3, r7, #0x0
	bl sub_08018948
	adds r7, r0, #0x0
	mov r1, r9
	cmp r1, #0x67
	beq _08018654
	cmp r1, #0x47
	bne _0801865C
	.global _08018654
_08018654:
	movs r0, #0x01
	ands r6, r0
	cmp r6, #0x00
	beq _080186B0
	.global _0801865C
_0801865C:
	mov r0, r8
	adds r6, r7, r0
	mov r1, r9
	cmp r1, #0x66
	bne _0801868C
	ldrb r0, [r7, #0x00]
	cmp r0, #0x30
	bne _08018686
	ldr r3, _080186CC @ =0x00000000
	ldr r2, _080186C8 @ =0x00000000
	adds r1, r5, #0x0
	adds r0, r4, #0x0
	bl sub_0801C088
	cmp r0, #0x00
	beq _08018686
	mov r1, r8
	negs r0, r1
	adds r0, #0x01
	mov r1, r10
	str r0, [r1, #0x00]
	.global _08018686
_08018686:
	mov r1, r10
	ldr r0, [r1, #0x00]
	adds r6, r6, r0
	.global _0801868C
_0801868C:
	ldr r3, _080186CC @ =0x00000000
	ldr r2, _080186C8 @ =0x00000000
	adds r1, r5, #0x0
	adds r0, r4, #0x0
	bl sub_0801C03C
	cmp r0, #0x00
	bne _0801869E
	str r6, [sp, #0x014]
	.global _0801869E
_0801869E:
	ldr r0, [sp, #0x014]
	cmp r0, r6
	bcs _080186B0
	movs r1, #0x30
	.global _080186A6
_080186A6:
	strb r1, [r0, #0x00]
	adds r0, #0x01
	str r0, [sp, #0x014]
	cmp r0, r6
	bcc _080186A6
	.global _080186B0
_080186B0:
	ldr r0, [sp, #0x014]
	subs r0, r0, r7
	ldr r1, [sp, #0x04C]
	str r0, [r1, #0x00]
	adds r0, r7, #0x0
	add sp, #0x01C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
	.global _080186C8
_080186C8: .4byte 0x00000000
	.global _080186CC
_080186CC: .4byte 0x00000000
	thumb_func_start sub_080186D0
sub_080186D0:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x134
	adds r7, r0, #0x0
	adds r6, r1, #0x0
	strb r2, [r7, #0x00]
	adds r5, r7, #0x1
	cmp r6, #0x00
	bge _080186E6
	negs r6, r6
	movs r0, #0x2D
	b _080186E8
	.global _080186E6
_080186E6:
	movs r0, #0x2B
	.global _080186E8
_080186E8:
	strb r0, [r7, #0x01]
	adds r5, #0x01
	add r4, sp, #0x134
	cmp r6, #0x09
	ble _0801872A
	.global _080186F2
_080186F2:
	subs r4, #0x01
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl sub_080172C8
	adds r0, #0x30
	strb r0, [r4, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl sub_08017230
	adds r6, r0, #0x0
	cmp r6, #0x09
	bgt _080186F2
	subs r4, #0x01
	adds r0, #0x30
	strb r0, [r4, #0x00]
	add r0, sp, #0x134
	cmp r4, r0
	bcs _08018738
	adds r1, r0, #0x0
	.global _0801871C
_0801871C:
	ldrb r0, [r4, #0x00]
	strb r0, [r5, #0x00]
	adds r4, #0x01
	adds r5, #0x01
	cmp r4, r1
	bcc _0801871C
	b _08018738
	.global _0801872A
_0801872A:
	movs r0, #0x30
	strb r0, [r5, #0x00]
	adds r5, #0x01
	adds r0, r6, #0x0
	adds r0, #0x30
	strb r0, [r5, #0x00]
	adds r5, #0x01
	.global _08018738
_08018738:
	subs r0, r5, r7
	add sp, #0x134
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_08018740
sub_08018740:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x54]
	cmp r0, #0x00
	bne _08018750
	ldr r0, _0801877C @ =0x083FFAA8
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x54]
	.global _08018750
_08018750:
	ldr r1, [r4, #0x54]
	ldr r0, [r1, #0x38]
	cmp r0, #0x00
	bne _0801875E
	adds r0, r1, #0x0
	bl sub_080197D0
	.global _0801875E
_0801875E:
	ldrh r1, [r4, #0x0C]
	movs r0, #0x08
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0x00
	bne _080187B8
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	bne _08018780
	movs r0, #0x01
	negs r0, r0
	b _080187EA
	.byte 0x00, 0x00
	.global _0801877C
_0801877C: .4byte 0x083FFAA8
	.global _08018780
_08018780:
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _080187B0
	ldr r1, [r4, #0x30]
	cmp r1, #0x00
	beq _0801879E
	adds r0, r4, #0x0
	adds r0, #0x40
	cmp r1, r0
	beq _0801879C
	ldr r0, [r4, #0x54]
	bl sub_08019830
	.global _0801879C
_0801879C:
	str r5, [r4, #0x30]
	.global _0801879E
_0801879E:
	movs r0, #0x25
	negs r0, r0
	ldrh r1, [r4, #0x0C]
	ands r0, r1
	movs r1, #0x00
	strh r0, [r4, #0x0C]
	str r1, [r4, #0x04]
	ldr r0, [r4, #0x10]
	str r0, [r4, #0x00]
	.global _080187B0
_080187B0:
	movs r0, #0x08
	ldrh r1, [r4, #0x0C]
	orrs r0, r1
	strh r0, [r4, #0x0C]
	.global _080187B8
_080187B8:
	ldr r0, [r4, #0x10]
	cmp r0, #0x00
	bne _080187C4
	adds r0, r4, #0x0
	bl sub_08019D88
	.global _080187C4
_080187C4:
	ldrh r1, [r4, #0x0C]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080187DA
	movs r0, #0x00
	str r0, [r4, #0x08]
	ldr r0, [r4, #0x14]
	negs r0, r0
	str r0, [r4, #0x18]
	b _080187E8
	.global _080187DA
_080187DA:
	movs r0, #0x02
	ands r0, r1
	movs r1, #0x00
	cmp r0, #0x00
	bne _080187E6
	ldr r1, [r4, #0x14]
	.global _080187E6
_080187E6:
	str r1, [r4, #0x08]
	.global _080187E8
_080187E8:
	movs r0, #0x00
	.global _080187EA
_080187EA:
	pop {r4, r5, pc}
	thumb_func_start sub_080187EC
sub_080187EC:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	ldr r7, [r1, #0x10]
	ldr r0, [r0, #0x10]
	cmp r0, r7
	bge _08018808
	movs r0, #0x00
	b _0801893C
	.global _08018808
_08018808:
	ldr r0, [sp, #0x004]
	adds r0, #0x14
	mov r8, r0
	subs r7, #0x01
	lsls r0, r7, #0x02
	mov r1, r8
	adds r1, r1, r0
	str r1, [sp, #0x00C]
	ldr r4, [sp, #0x000]
	adds r4, #0x14
	adds r5, r4, r0
	ldr r1, [r1, #0x00]
	adds r1, #0x01
	ldr r2, [r5, #0x00]
	mov r10, r2
	mov r0, r10
	bl _08017420
	str r0, [sp, #0x008]
	mov r3, r8
	str r3, [sp, #0x014]
	str r4, [sp, #0x010]
	cmp r0, #0x00
	beq _080188B2
	movs r6, #0x00
	mov r9, r6
	ldr r0, _0801889C @ =0x0000FFFF
	mov r12, r0
	.global _08018840
_08018840:
	mov r2, r8
	adds r2, #0x04
	mov r8, r2
	subs r2, #0x04
	ldm r2!, {r1}
	adds r0, r1, #0x0
	mov r3, r12
	ands r0, r3
	ldr r2, [sp, #0x008]
	muls r0, r2
	mov r3, r9
	adds r2, r0, r3
	lsrs r0, r1, #0x10
	ldr r3, [sp, #0x008]
	adds r1, r0, #0x0
	muls r1, r3
	lsrs r0, r2, #0x10
	adds r3, r1, r0
	lsrs r0, r3, #0x10
	mov r9, r0
	ldr r0, [r4, #0x00]
	mov r1, r12
	ands r0, r1
	ands r2, r1
	subs r0, r0, r2
	adds r2, r0, r6
	asrs r6, r2, #0x10
	ldr r0, [r4, #0x00]
	lsrs r1, r0, #0x10
	mov r0, r12
	ands r3, r0
	subs r1, r1, r3
	adds r0, r1, r6
	asrs r6, r0, #0x10
	strh r0, [r4, #0x00]
	strh r2, [r4, #0x02]
	adds r4, #0x04
	ldr r1, [sp, #0x00C]
	cmp r8, r1
	bls _08018840
	mov r2, r10
	cmp r2, #0x00
	bne _080188B2
	ldr r4, [sp, #0x010]
	b _080188A2
	.byte 0x00, 0x00
	.global _0801889C
_0801889C: .4byte 0x0000FFFF
	.global _080188A0
_080188A0:
	subs r7, #0x01
	.global _080188A2
_080188A2:
	subs r5, #0x04
	cmp r5, r4
	bls _080188AE
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080188A0
	.global _080188AE
_080188AE:
	ldr r3, [sp, #0x000]
	str r7, [r3, #0x10]
	.global _080188B2
_080188B2:
	ldr r0, [sp, #0x000]
	ldr r1, [sp, #0x004]
	bl sub_0801AA90
	cmp r0, #0x00
	blt _0801893A
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	movs r6, #0x00
	mov r9, r6
	ldr r4, [sp, #0x010]
	ldr r1, [sp, #0x014]
	mov r8, r1
	lsls r2, r7, #0x02
	mov r10, r2
	ldr r5, _08018924 @ =0x0000FFFF
	.global _080188D4
_080188D4:
	mov r3, r8
	adds r3, #0x04
	mov r8, r3
	subs r3, #0x04
	ldm r3!, {r1}
	adds r0, r1, #0x0
	ands r0, r5
	mov r3, r9
	adds r2, r0, r3
	lsrs r1, r1, #0x10
	lsrs r0, r2, #0x10
	adds r3, r1, r0
	lsrs r0, r3, #0x10
	mov r9, r0
	ldr r1, [r4, #0x00]
	adds r0, r1, #0x0
	ands r0, r5
	ands r2, r5
	subs r0, r0, r2
	adds r2, r0, r6
	asrs r6, r2, #0x10
	lsrs r1, r1, #0x10
	ands r3, r5
	subs r1, r1, r3
	adds r0, r1, r6
	asrs r6, r0, #0x10
	strh r0, [r4, #0x00]
	strh r2, [r4, #0x02]
	adds r4, #0x04
	ldr r1, [sp, #0x00C]
	cmp r8, r1
	bls _080188D4
	ldr r4, [sp, #0x010]
	mov r2, r10
	adds r5, r4, r2
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	bne _0801893A
	b _0801892A
	.byte 0x00, 0x00
	.global _08018924
_08018924: .4byte 0x0000FFFF
	.global _08018928
_08018928:
	subs r7, #0x01
	.global _0801892A
_0801892A:
	subs r5, #0x04
	cmp r5, r4
	bls _08018936
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _08018928
	.global _08018936
_08018936:
	ldr r3, [sp, #0x000]
	str r7, [r3, #0x10]
	.global _0801893A
_0801893A:
	ldr r0, [sp, #0x008]
	.global _0801893C
_0801893C:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7, pc}
	thumb_func_start sub_08018948
sub_08018948:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x084
	mov r10, r0
	str r3, [sp, #0x00C]
	ldr r4, [sp, #0x0AC]
	str r1, [sp, #0x040]
	str r2, [sp, #0x044]
	ldr r2, [r0, #0x40]
	cmp r2, #0x00
	beq _08018980
	ldr r0, [r0, #0x44]
	str r0, [r2, #0x04]
	mov r0, r10
	ldr r1, [r0, #0x44]
	movs r0, #0x01
	lsls r0, r1
	str r0, [r2, #0x08]
	mov r0, r10
	adds r1, r2, #0x0
	bl sub_0801A5C8
	movs r0, #0x00
	mov r1, r10
	str r0, [r1, #0x40]
	.global _08018980
_08018980:
	movs r0, #0x80
	lsls r0, r0, #0x18
	ldr r1, [sp, #0x040]
	ands r0, r1
	cmp r0, #0x00
	beq _0801899C
	movs r0, #0x01
	str r0, [r4, #0x00]
	ldr r0, _08018998 @ =0x7FFFFFFF
	ands r1, r0
	str r1, [sp, #0x040]
	b _0801899E
	.global _08018998
_08018998: .4byte 0x7FFFFFFF
	.global _0801899C
_0801899C:
	str r0, [r4, #0x00]
	.global _0801899E
_0801899E:
	ldr r1, _080189E0 @ =0x7FF00000
	ldr r2, [sp, #0x040]
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, r1
	bne _080189F4
	ldr r0, _080189E4 @ =0x0000270F
	ldr r3, [sp, #0x0A8]
	str r0, [r3, #0x00]
	ldr r0, _080189E8 @ =0x083394EC
	mov r9, r0
	ldr r1, [sp, #0x044]
	cmp r1, #0x00
	bne _080189C6
	ldr r0, _080189EC @ =0x000FFFFF
	ands r2, r0
	cmp r2, #0x00
	bne _080189C6
	ldr r2, _080189F0 @ =0x083394E0
	mov r9, r2
	.global _080189C6
_080189C6:
	ldr r3, [sp, #0x0B0]
	cmp r3, #0x00
	beq _08018A18
	mov r1, r9
	ldrb r0, [r1, #0x03]
	adds r1, #0x03
	cmp r0, #0x00
	beq _080189D8
	adds r1, #0x05
	.global _080189D8
_080189D8:
	ldr r2, [sp, #0x0B0]
	str r1, [r2, #0x00]
	b _08018A18
	.byte 0x00, 0x00
	.global _080189E0
_080189E0: .4byte 0x7FF00000
	.global _080189E4
_080189E4: .4byte 0x0000270F
	.global _080189E8
_080189E8: .4byte 0x083394EC
	.global _080189EC
_080189EC: .4byte 0x000FFFFF
	.global _080189F0
_080189F0: .4byte 0x083394E0
	.global _080189F4
_080189F4:
	ldr r3, _08018A24 @ =0x00000000
	ldr r2, _08018A20 @ =0x00000000
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	bl sub_0801C03C
	cmp r0, #0x00
	bne _08018A2C
	movs r0, #0x01
	ldr r3, [sp, #0x0A8]
	str r0, [r3, #0x00]
	ldr r0, _08018A28 @ =0x083394F0
	mov r9, r0
	ldr r1, [sp, #0x0B0]
	cmp r1, #0x00
	beq _08018A18
	adds r0, #0x01
	str r0, [r1, #0x00]
	.global _08018A18
_08018A18:
	mov r0, r9
	bl _08019632
	lsls r0, r0, #0x00
	.global _08018A20
_08018A20:
	lsls r0, r0, #0x00
	lsls r0, r0, #0x00
	.global _08018A24
_08018A24:
	lsls r0, r0, #0x00
	lsls r0, r0, #0x00
	.global _08018A28
_08018A28:
	str r4, [sp, #0x3C0]
	lsrs r3, r6, #0x20
	.global _08018A2C
_08018A2C:
	add r0, sp, #0x008
	str r0, [sp, #0x000]
	mov r0, r10
	ldr r1, [sp, #0x040]
	ldr r2, [sp, #0x044]
	add r3, sp, #0x004
	bl sub_0801ACC8
	str r0, [sp, #0x05C]
	ldr r2, [sp, #0x040]
	lsls r0, r2, #0x01
	lsrs r0, r0, #0x15
	mov r8, r0
	cmp r0, #0x00
	beq _08018A7C
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	str r0, [sp, #0x048]
	str r1, [sp, #0x04C]
	ldr r0, _08018A70 @ =0x000FFFFF
	ldr r1, [sp, #0x048]
	ands r1, r0
	str r1, [sp, #0x048]
	ldr r0, _08018A74 @ =0x3FF00000
	adds r2, r1, #0x0
	orrs r2, r0
	str r2, [sp, #0x048]
	ldr r3, _08018A78 @ =0xFFFFFC01
	add r8, r3
	movs r0, #0x00
	str r0, [sp, #0x058]
	ldr r6, [sp, #0x008]
	b _08018ADC
	.byte 0x00, 0x00
	.global _08018A70
_08018A70: .4byte 0x000FFFFF
	.global _08018A74
_08018A74: .4byte 0x3FF00000
	.global _08018A78
_08018A78: .4byte 0xFFFFFC01
	.global _08018A7C
_08018A7C:
	ldr r1, [sp, #0x008]
	ldr r0, [sp, #0x004]
	adds r2, r1, r0
	ldr r3, _08018AA4 @ =0x00000432
	adds r3, r3, r2
	mov r8, r3
	adds r6, r1, #0x0
	cmp r3, #0x20
	ble _08018AAC
	movs r0, #0x40
	subs r0, r0, r3
	ldr r4, [sp, #0x040]
	lsls r4, r0
	ldr r1, _08018AA8 @ =0x00000412
	adds r0, r2, r1
	ldr r2, [sp, #0x044]
	lsrs r2, r0
	adds r0, r2, #0x0
	orrs r4, r0
	b _08018AB6
	.global _08018AA4
_08018AA4: .4byte 0x00000432
	.global _08018AA8
_08018AA8: .4byte 0x00000412
	.global _08018AAC
_08018AAC:
	movs r0, #0x20
	mov r3, r8
	subs r0, r0, r3
	ldr r4, [sp, #0x044]
	lsls r4, r0
	.global _08018AB6
_08018AB6:
	adds r0, r4, #0x0
	bl sub_0801C204
	cmp r4, #0x00
	bge _08018AC8
	ldr r3, _08018B8C @ =0x00000000
	ldr r2, _08018B88 @ =0x41F00000
	bl sub_0801BA78
	.global _08018AC8
_08018AC8:
	str r0, [sp, #0x048]
	str r1, [sp, #0x04C]
	ldr r1, _08018B90 @ =0xFE100000
	ldr r0, [sp, #0x048]
	adds r1, r0, r1
	str r1, [sp, #0x048]
	ldr r2, _08018B94 @ =0xFFFFFBCD
	add r8, r2
	movs r3, #0x01
	str r3, [sp, #0x058]
	.global _08018ADC
_08018ADC:
	ldr r2, _08018B98 @ =0x3FF80000
	ldr r3, _08018B9C @ =0x00000000
	ldr r0, [sp, #0x048]
	ldr r1, [sp, #0x04C]
	bl sub_0801BAA8
	ldr r2, _08018BA0 @ =0x3FD287A7
	ldr r3, _08018BA4 @ =0x636F4361
	bl sub_0801BAE0
	ldr r2, _08018BA8 @ =0x3FC68A28
	ldr r3, _08018BAC @ =0x8B60C8B3
	bl sub_0801BA78
	adds r5, r1, #0x0
	adds r4, r0, #0x0
	mov r0, r8
	bl sub_0801C204
	ldr r2, _08018BB0 @ =0x3FD34413
	ldr r3, _08018BB4 @ =0x509F79FB
	bl sub_0801BAE0
	adds r3, r1, #0x0
	adds r2, r0, #0x0
	adds r1, r5, #0x0
	adds r0, r4, #0x0
	bl sub_0801BA78
	str r0, [sp, #0x06C]
	str r1, [sp, #0x070]
	bl sub_0801C280
	str r0, [sp, #0x024]
	ldr r2, _08018BB8 @ =0x00000000
	ldr r3, _08018BBC @ =0x00000000
	ldr r0, [sp, #0x06C]
	ldr r1, [sp, #0x070]
	bl sub_0801C16C
	cmp r0, #0x00
	bge _08018B4C
	ldr r0, [sp, #0x024]
	bl sub_0801C204
	adds r3, r1, #0x0
	adds r2, r0, #0x0
	ldr r0, [sp, #0x06C]
	ldr r1, [sp, #0x070]
	bl sub_0801C088
	cmp r0, #0x00
	beq _08018B4C
	ldr r0, [sp, #0x024]
	subs r0, #0x01
	str r0, [sp, #0x024]
	.global _08018B4C
_08018B4C:
	movs r1, #0x01
	str r1, [sp, #0x02C]
	ldr r2, [sp, #0x024]
	cmp r2, #0x16
	bhi _08018B76
	ldr r1, _08018BC0 @ =0x08339540
	lsls r0, r2, #0x03
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	ldr r3, [r0, #0x04]
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	bl sub_0801C16C
	cmp r0, #0x00
	bge _08018B72
	ldr r3, [sp, #0x024]
	subs r3, #0x01
	str r3, [sp, #0x024]
	.global _08018B72
_08018B72:
	movs r0, #0x00
	str r0, [sp, #0x02C]
	.global _08018B76
_08018B76:
	mov r1, r8
	subs r0, r6, r1
	subs r4, r0, #0x1
	cmp r4, #0x00
	blt _08018BC4
	movs r2, #0x00
	str r2, [sp, #0x010]
	str r4, [sp, #0x034]
	b _08018BCC
	.global _08018B88
_08018B88: .4byte 0x41F00000
	.global _08018B8C
_08018B8C: .4byte 0x00000000
	.global _08018B90
_08018B90: .4byte 0xFE100000
	.global _08018B94
_08018B94: .4byte 0xFFFFFBCD
	.global _08018B98
_08018B98: .4byte 0x3FF80000
	.global _08018B9C
_08018B9C: .4byte 0x00000000
	.global _08018BA0
_08018BA0: .4byte 0x3FD287A7
	.global _08018BA4
_08018BA4: .4byte 0x636F4361
	.global _08018BA8
_08018BA8: .4byte 0x3FC68A28
	.global _08018BAC
_08018BAC: .4byte 0x8B60C8B3
	.global _08018BB0
_08018BB0: .4byte 0x3FD34413
	.global _08018BB4
_08018BB4: .4byte 0x509F79FB
	.global _08018BB8
_08018BB8: .4byte 0x00000000
	.global _08018BBC
_08018BBC: .4byte 0x00000000
	.global _08018BC0
_08018BC0: .4byte 0x08339540
	.global _08018BC4
_08018BC4:
	negs r4, r4
	str r4, [sp, #0x010]
	movs r3, #0x00
	str r3, [sp, #0x034]
	.global _08018BCC
_08018BCC:
	ldr r0, [sp, #0x024]
	cmp r0, #0x00
	blt _08018BE0
	movs r1, #0x00
	str r1, [sp, #0x014]
	str r0, [sp, #0x038]
	ldr r2, [sp, #0x034]
	adds r2, r2, r0
	str r2, [sp, #0x034]
	b _08018BF0
	.global _08018BE0
_08018BE0:
	ldr r3, [sp, #0x010]
	ldr r0, [sp, #0x024]
	subs r3, r3, r0
	str r3, [sp, #0x010]
	negs r1, r0
	str r1, [sp, #0x014]
	movs r2, #0x00
	str r2, [sp, #0x038]
	.global _08018BF0
_08018BF0:
	ldr r3, [sp, #0x00C]
	cmp r3, #0x09
	bls _08018BFA
	movs r0, #0x00
	str r0, [sp, #0x00C]
	.global _08018BFA
_08018BFA:
	movs r5, #0x01
	ldr r1, [sp, #0x00C]
	cmp r1, #0x05
	ble _08018C08
	subs r1, #0x04
	str r1, [sp, #0x00C]
	movs r5, #0x00
	.global _08018C08
_08018C08:
	movs r2, #0x01
	str r2, [sp, #0x030]
	ldr r3, [sp, #0x00C]
	cmp r3, #0x05
	bhi _08018C82
	lsls r0, r3, #0x02
	ldr r1, _08018C1C @ =0x08018C20
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.global _08018C1C
_08018C1C: .4byte 0x08018C20
	.byte 0x38, 0x8C, 0x01, 0x08, 0x38, 0x8C, 0x01, 0x08, 0x4A, 0x8C, 0x01, 0x08, 0x66, 0x8C, 0x01, 0x08
	.byte 0x4E, 0x8C, 0x01, 0x08, 0x6A, 0x8C, 0x01, 0x08, 0x01, 0x20, 0x40, 0x42, 0x06, 0x90, 0x08, 0x90
	.byte 0x12, 0x21, 0x88, 0x46, 0x00, 0x22, 0x29, 0x92, 0x1B, 0xE0, 0x00, 0x23, 0x0C, 0x93, 0x29, 0x98
	.byte 0x00, 0x28, 0x01, 0xDC, 0x01, 0x21, 0x29, 0x91, 0x29, 0x9A, 0x90, 0x46, 0x43, 0x46, 0x08, 0x93
	.byte 0x40, 0x46, 0x06, 0x90, 0x0D, 0xE0, 0x00, 0x21, 0x0C, 0x91, 0x29, 0x9A, 0x09, 0x9B, 0xD0, 0x18
	.byte 0x41, 0x1C, 0x88, 0x46, 0x42, 0x46, 0x06, 0x92, 0x08, 0x90, 0x00, 0x29, 0x01, 0xDC, 0x01, 0x23
	.byte 0x98, 0x46
	.global _08018C82
_08018C82:
	movs r4, #0x04
	movs r0, #0x00
	mov r1, r10
	str r0, [r1, #0x44]
	mov r2, r8
	cmp r2, #0x17
	bls _08018CA2
	movs r1, #0x00
	.global _08018C92
_08018C92:
	adds r1, #0x01
	lsls r4, r4, #0x01
	adds r0, r4, #0x0
	adds r0, #0x14
	cmp r0, r8
	bls _08018C92
	mov r3, r10
	str r1, [r3, #0x44]
	.global _08018CA2
_08018CA2:
	mov r0, r10
	ldr r1, [r0, #0x44]
	bl sub_0801A570
	mov r1, r10
	str r0, [r1, #0x40]
	str r0, [sp, #0x074]
	mov r9, r0
	ldr r2, [sp, #0x018]
	cmp r2, #0x0E
	bls _08018CBA
	b _0801902C
	.global _08018CBA
_08018CBA:
	cmp r5, #0x00
	bne _08018CC0
	b _0801902C
	.global _08018CC0
_08018CC0:
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	str r0, [sp, #0x078]
	str r1, [sp, #0x07C]
	str r0, [sp, #0x048]
	str r1, [sp, #0x04C]
	ldr r1, [sp, #0x024]
	str r1, [sp, #0x028]
	str r2, [sp, #0x01C]
	movs r7, #0x02
	cmp r1, #0x00
	ble _08018D50
	ldr r0, _08018D48 @ =0x08339540
	movs r2, #0x0F
	ands r1, r2
	lsls r1, r1, #0x03
	adds r3, r1, r0
	ldr r0, [r3, #0x00]
	ldr r1, [r3, #0x04]
	str r0, [sp, #0x06C]
	str r1, [sp, #0x070]
	ldr r1, [sp, #0x024]
	asrs r4, r1, #0x04
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0x00
	beq _08018D0C
	ands r4, r2
	ldr r0, _08018D4C @ =0x08339608
	ldr r2, [r0, #0x20]
	ldr r3, [r0, #0x24]
	ldr r0, [sp, #0x078]
	ldr r1, [sp, #0x07C]
	bl sub_0801BD88
	str r0, [sp, #0x040]
	str r1, [sp, #0x044]
	movs r7, #0x03
	.global _08018D0C
_08018D0C:
	cmp r4, #0x00
	beq _08018D34
	ldr r5, _08018D4C @ =0x08339608
	.global _08018D12
_08018D12:
	movs r0, #0x01
	ands r0, r4
	cmp r0, #0x00
	beq _08018D2C
	adds r7, #0x01
	ldr r2, [r5, #0x00]
	ldr r3, [r5, #0x04]
	ldr r0, [sp, #0x06C]
	ldr r1, [sp, #0x070]
	bl sub_0801BAE0
	str r0, [sp, #0x06C]
	str r1, [sp, #0x070]
	.global _08018D2C
_08018D2C:
	asrs r4, r4, #0x01
	adds r5, #0x08
	cmp r4, #0x00
	bne _08018D12
	.global _08018D34
_08018D34:
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	ldr r2, [sp, #0x06C]
	ldr r3, [sp, #0x070]
	bl sub_0801BD88
	str r0, [sp, #0x040]
	str r1, [sp, #0x044]
	b _08018D9C
	.byte 0x00, 0x00
	.global _08018D48
_08018D48: .4byte 0x08339540
	.global _08018D4C
_08018D4C: .4byte 0x08339608
	.global _08018D50
_08018D50:
	ldr r2, [sp, #0x024]
	negs r6, r2
	cmp r6, #0x00
	beq _08018D9C
	ldr r1, _08018E44 @ =0x08339540
	movs r0, #0x0F
	ands r0, r6
	lsls r0, r0, #0x03
	adds r0, r0, r1
	ldr r1, [r0, #0x04]
	ldr r0, [r0, #0x00]
	ldr r2, [sp, #0x078]
	ldr r3, [sp, #0x07C]
	bl sub_0801BAE0
	str r0, [sp, #0x040]
	str r1, [sp, #0x044]
	asrs r4, r6, #0x04
	cmp r4, #0x00
	beq _08018D9C
	ldr r5, _08018E48 @ =0x08339608
	.global _08018D7A
_08018D7A:
	movs r0, #0x01
	ands r0, r4
	cmp r0, #0x00
	beq _08018D94
	adds r7, #0x01
	ldr r0, [r5, #0x00]
	ldr r1, [r5, #0x04]
	ldr r2, [sp, #0x040]
	ldr r3, [sp, #0x044]
	bl sub_0801BAE0
	str r0, [sp, #0x040]
	str r1, [sp, #0x044]
	.global _08018D94
_08018D94:
	asrs r4, r4, #0x01
	adds r5, #0x08
	cmp r4, #0x00
	bne _08018D7A
	.global _08018D9C
_08018D9C:
	ldr r3, [sp, #0x02C]
	cmp r3, #0x00
	beq _08018DDA
	ldr r2, _08018E4C @ =0x3FF00000
	ldr r3, _08018E50 @ =0x00000000
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	bl sub_0801C16C
	cmp r0, #0x00
	bge _08018DDA
	ldr r0, [sp, #0x018]
	cmp r0, #0x00
	ble _08018DDA
	ldr r1, [sp, #0x020]
	cmp r1, #0x00
	bgt _08018DC0
	b _08019018
	.global _08018DC0
_08018DC0:
	str r1, [sp, #0x018]
	ldr r2, [sp, #0x024]
	subs r2, #0x01
	str r2, [sp, #0x024]
	ldr r0, _08018E54 @ =0x40240000
	ldr r1, _08018E58 @ =0x00000000
	ldr r2, [sp, #0x040]
	ldr r3, [sp, #0x044]
	bl sub_0801BAE0
	str r0, [sp, #0x040]
	str r1, [sp, #0x044]
	adds r7, #0x01
	.global _08018DDA
_08018DDA:
	adds r0, r7, #0x0
	bl sub_0801C204
	ldr r2, [sp, #0x040]
	ldr r3, [sp, #0x044]
	bl sub_0801BAE0
	ldr r2, _08018E5C @ =0x401C0000
	ldr r3, _08018E60 @ =0x00000000
	bl sub_0801BA78
	str r0, [sp, #0x050]
	str r1, [sp, #0x054]
	ldr r0, _08018E64 @ =0xFCC00000
	ldr r3, [sp, #0x050]
	adds r0, r3, r0
	str r0, [sp, #0x050]
	ldr r1, [sp, #0x018]
	cmp r1, #0x00
	bne _08018E70
	movs r2, #0x00
	str r2, [sp, #0x064]
	movs r3, #0x00
	str r3, [sp, #0x068]
	ldr r2, _08018E68 @ =0x40140000
	ldr r3, _08018E6C @ =0x00000000
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	bl sub_0801BAA8
	adds r5, r1, #0x0
	adds r4, r0, #0x0
	ldr r2, [sp, #0x050]
	ldr r3, [sp, #0x054]
	bl sub_0801C0D4
	cmp r0, #0x00
	ble _08018E28
	b _080193A2
	.global _08018E28
_08018E28:
	ldr r0, [sp, #0x050]
	ldr r1, [sp, #0x054]
	bl sub_0801C2F4
	adds r3, r1, #0x0
	adds r2, r0, #0x0
	adds r1, r5, #0x0
	adds r0, r4, #0x0
	bl sub_0801C16C
	cmp r0, #0x00
	bge _08018E42
	b _0801939A
	.global _08018E42
_08018E42:
	b _08019018
	.global _08018E44
_08018E44: .4byte 0x08339540
	.global _08018E48
_08018E48: .4byte 0x08339608
	.global _08018E4C
_08018E4C: .4byte 0x3FF00000
	.global _08018E50
_08018E50: .4byte 0x00000000
	.global _08018E54
_08018E54: .4byte 0x40240000
	.global _08018E58
_08018E58: .4byte 0x00000000
	.global _08018E5C
_08018E5C: .4byte 0x401C0000
	.global _08018E60
_08018E60: .4byte 0x00000000
	.global _08018E64
_08018E64: .4byte 0xFCC00000
	.global _08018E68
_08018E68: .4byte 0x40140000
	.global _08018E6C
_08018E6C: .4byte 0x00000000
	.global _08018E70
_08018E70:
	ldr r0, [sp, #0x030]
	cmp r0, #0x00
	beq _08018F40
	ldr r1, _08018EA0 @ =0x08339540
	ldr r0, [sp, #0x018]
	subs r0, #0x01
	lsls r0, r0, #0x03
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	ldr r3, [r0, #0x04]
	ldr r0, _08018EA4 @ =0x3FE00000
	ldr r1, _08018EA8 @ =0x00000000
	bl sub_0801BD88
	ldr r2, [sp, #0x050]
	ldr r3, [sp, #0x054]
	bl sub_0801BAA8
	str r0, [sp, #0x050]
	str r1, [sp, #0x054]
	movs r1, #0x00
	mov r8, r1
	b _08018ECC
	.byte 0x00, 0x00
	.global _08018EA0
_08018EA0: .4byte 0x08339540
	.global _08018EA4
_08018EA4: .4byte 0x3FE00000
	.global _08018EA8
_08018EA8: .4byte 0x00000000
	.global _08018EAC
_08018EAC:
	ldr r1, _08018F34 @ =0x00000000
	ldr r0, _08018F30 @ =0x40240000
	ldr r2, [sp, #0x050]
	ldr r3, [sp, #0x054]
	bl sub_0801BAE0
	str r0, [sp, #0x050]
	str r1, [sp, #0x054]
	ldr r1, _08018F34 @ =0x00000000
	ldr r0, _08018F30 @ =0x40240000
	adds r3, r5, #0x0
	adds r2, r4, #0x0
	bl sub_0801BAE0
	str r0, [sp, #0x040]
	str r1, [sp, #0x044]
	.global _08018ECC
_08018ECC:
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	bl sub_0801C280
	adds r6, r0, #0x0
	bl sub_0801C204
	adds r3, r1, #0x0
	adds r2, r0, #0x0
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	bl sub_0801BAA8
	adds r5, r1, #0x0
	adds r4, r0, #0x0
	adds r0, r6, #0x0
	adds r0, #0x30
	mov r2, r9
	strb r0, [r2, #0x00]
	movs r3, #0x01
	add r9, r3
	adds r1, r5, #0x0
	adds r0, r4, #0x0
	ldr r2, [sp, #0x050]
	ldr r3, [sp, #0x054]
	bl sub_0801C16C
	cmp r0, #0x00
	bge _08018F08
	b _08019612
	.global _08018F08
_08018F08:
	ldr r0, _08018F38 @ =0x3FF00000
	ldr r1, _08018F3C @ =0x00000000
	adds r3, r5, #0x0
	adds r2, r4, #0x0
	bl sub_0801BAA8
	ldr r2, [sp, #0x050]
	ldr r3, [sp, #0x054]
	bl sub_0801C16C
	cmp r0, #0x00
	bge _08018F22
	b _0801912C
	.global _08018F22
_08018F22:
	movs r0, #0x01
	add r8, r0
	ldr r1, [sp, #0x018]
	cmp r8, r1
	blt _08018EAC
	b _08019018
	.byte 0x00, 0x00
	.global _08018F30
_08018F30: .4byte 0x40240000
	.global _08018F34
_08018F34: .4byte 0x00000000
	.global _08018F38
_08018F38: .4byte 0x3FF00000
	.global _08018F3C
_08018F3C: .4byte 0x00000000
	.global _08018F40
_08018F40:
	ldr r1, _08018F60 @ =0x08339540
	ldr r0, [sp, #0x018]
	subs r0, #0x01
	lsls r0, r0, #0x03
	adds r0, r0, r1
	ldr r1, [r0, #0x04]
	ldr r0, [r0, #0x00]
	ldr r2, [sp, #0x050]
	ldr r3, [sp, #0x054]
	bl sub_0801BAE0
	str r0, [sp, #0x050]
	str r1, [sp, #0x054]
	movs r2, #0x01
	mov r8, r2
	b _08018F78
	.global _08018F60
_08018F60: .4byte 0x08339540
	.global _08018F64
_08018F64:
	movs r3, #0x01
	add r8, r3
	ldr r1, _0801900C @ =0x00000000
	ldr r0, _08019008 @ =0x40240000
	adds r3, r5, #0x0
	adds r2, r4, #0x0
	bl sub_0801BAE0
	str r0, [sp, #0x040]
	str r1, [sp, #0x044]
	.global _08018F78
_08018F78:
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	bl sub_0801C280
	adds r6, r0, #0x0
	bl sub_0801C204
	adds r3, r1, #0x0
	adds r2, r0, #0x0
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	bl sub_0801BAA8
	adds r5, r1, #0x0
	adds r4, r0, #0x0
	adds r0, r6, #0x0
	adds r0, #0x30
	mov r1, r9
	strb r0, [r1, #0x00]
	movs r2, #0x01
	add r9, r2
	ldr r3, [sp, #0x018]
	cmp r8, r3
	bne _08018F64
	ldr r6, _08019010 @ =0x3FE00000
	ldr r7, _08019014 @ =0x00000000
	adds r1, r7, #0x0
	adds r0, r6, #0x0
	ldr r2, [sp, #0x050]
	ldr r3, [sp, #0x054]
	bl sub_0801BA78
	adds r3, r1, #0x0
	adds r2, r0, #0x0
	adds r1, r5, #0x0
	adds r0, r4, #0x0
	bl sub_0801C0D4
	cmp r0, #0x00
	ble _08018FCA
	b _0801912C
	.global _08018FCA
_08018FCA:
	adds r1, r7, #0x0
	adds r0, r6, #0x0
	ldr r2, [sp, #0x050]
	ldr r3, [sp, #0x054]
	bl sub_0801BAA8
	adds r3, r1, #0x0
	adds r2, r0, #0x0
	adds r1, r5, #0x0
	adds r0, r4, #0x0
	bl sub_0801C16C
	cmp r0, #0x00
	bge _08019018
	movs r0, #0x01
	negs r0, r0
	add r9, r0
	mov r1, r9
	ldrb r1, [r1, #0x00]
	cmp r1, #0x30
	beq _08018FF6
	b _08019152
	.global _08018FF6
_08018FF6:
	movs r2, #0x01
	negs r2, r2
	add r9, r2
	mov r3, r9
	ldrb r3, [r3, #0x00]
	cmp r3, #0x30
	beq _08018FF6
	b _08019152
	.byte 0x00, 0x00
	.global _08019008
_08019008: .4byte 0x40240000
	.global _0801900C
_0801900C: .4byte 0x00000000
	.global _08019010
_08019010: .4byte 0x3FE00000
	.global _08019014
_08019014: .4byte 0x00000000
	.global _08019018
_08019018:
	ldr r1, [sp, #0x074]
	mov r9, r1
	ldr r2, [sp, #0x048]
	ldr r3, [sp, #0x04C]
	str r2, [sp, #0x040]
	str r3, [sp, #0x044]
	ldr r3, [sp, #0x028]
	str r3, [sp, #0x024]
	ldr r0, [sp, #0x01C]
	str r0, [sp, #0x018]
	.global _0801902C
_0801902C:
	ldr r0, [sp, #0x004]
	cmp r0, #0x00
	bge _08019034
	b _08019168
	.global _08019034
_08019034:
	ldr r1, [sp, #0x024]
	cmp r1, #0x0E
	ble _0801903C
	b _08019168
	.global _0801903C
_0801903C:
	ldr r1, _08019088 @ =0x08339540
	ldr r2, [sp, #0x024]
	lsls r0, r2, #0x03
	adds r0, r0, r1
	ldr r1, [r0, #0x00]
	ldr r2, [r0, #0x04]
	str r1, [sp, #0x06C]
	str r2, [sp, #0x070]
	ldr r2, [sp, #0x0A4]
	cmp r2, #0x00
	bge _08019094
	ldr r3, [sp, #0x018]
	cmp r3, #0x00
	bgt _08019094
	movs r0, #0x00
	str r0, [sp, #0x064]
	movs r1, #0x00
	str r1, [sp, #0x068]
	cmp r3, #0x00
	bge _08019066
	b _0801939A
	.global _08019066
_08019066:
	ldr r2, _0801908C @ =0x40140000
	ldr r3, _08019090 @ =0x00000000
	ldr r0, [sp, #0x06C]
	ldr r1, [sp, #0x070]
	bl sub_0801BAE0
	adds r3, r1, #0x0
	adds r2, r0, #0x0
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	bl sub_0801C1B8
	cmp r0, #0x00
	bgt _08019084
	b _0801939A
	.global _08019084
_08019084:
	b _080193A2
	.byte 0x00, 0x00
	.global _08019088
_08019088: .4byte 0x08339540
	.global _0801908C
_0801908C: .4byte 0x40140000
	.global _08019090
_08019090: .4byte 0x00000000
	.global _08019094
_08019094:
	movs r2, #0x01
	mov r8, r2
	b _080190B8
	.global _0801909A
_0801909A:
	ldr r1, _0801915C @ =0x00000000
	ldr r0, _08019158 @ =0x40240000
	bl sub_0801BAE0
	str r0, [sp, #0x040]
	str r1, [sp, #0x044]
	ldr r2, _08019160 @ =0x00000000
	ldr r3, _08019164 @ =0x00000000
	bl sub_0801C03C
	cmp r0, #0x00
	bne _080190B4
	b _08019612
	.global _080190B4
_080190B4:
	movs r3, #0x01
	add r8, r3
	.global _080190B8
_080190B8:
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	ldr r2, [sp, #0x06C]
	ldr r3, [sp, #0x070]
	bl sub_0801BD88
	bl sub_0801C280
	adds r6, r0, #0x0
	bl sub_0801C204
	ldr r2, [sp, #0x06C]
	ldr r3, [sp, #0x070]
	bl sub_0801BAE0
	adds r3, r1, #0x0
	adds r2, r0, #0x0
	ldr r0, [sp, #0x040]
	ldr r1, [sp, #0x044]
	bl sub_0801BAA8
	adds r3, r1, #0x0
	adds r2, r0, #0x0
	adds r0, r6, #0x0
	adds r0, #0x30
	mov r1, r9
	strb r0, [r1, #0x00]
	movs r0, #0x01
	add r9, r0
	ldr r1, [sp, #0x018]
	cmp r8, r1
	bne _0801909A
	adds r1, r3, #0x0
	adds r0, r2, #0x0
	bl sub_0801BA78
	adds r5, r1, #0x0
	adds r4, r0, #0x0
	ldr r2, [sp, #0x06C]
	ldr r3, [sp, #0x070]
	bl sub_0801C0D4
	cmp r0, #0x00
	bgt _0801912C
	adds r1, r5, #0x0
	adds r0, r4, #0x0
	ldr r2, [sp, #0x06C]
	ldr r3, [sp, #0x070]
	bl sub_0801C03C
	cmp r0, #0x00
	beq _08019122
	b _08019612
	.global _08019122
_08019122:
	movs r0, #0x01
	ands r0, r6
	cmp r0, #0x00
	bne _0801912C
	b _08019612
	.global _0801912C
_0801912C:
	movs r0, #0x30
	.global _0801912E
_0801912E:
	movs r2, #0x01
	negs r2, r2
	add r9, r2
	mov r3, r9
	ldrb r3, [r3, #0x00]
	cmp r3, #0x39
	bne _0801914A
	ldr r1, [sp, #0x074]
	cmp r9, r1
	bne _0801912E
	ldr r2, [sp, #0x024]
	adds r2, #0x01
	str r2, [sp, #0x024]
	strb r0, [r1, #0x00]
	.global _0801914A
_0801914A:
	mov r3, r9
	ldrb r0, [r3, #0x00]
	adds r0, #0x01
	strb r0, [r3, #0x00]
	.global _08019152
_08019152:
	movs r0, #0x01
	add r9, r0
	b _08019612
	.global _08019158
_08019158: .4byte 0x40240000
	.global _0801915C
_0801915C: .4byte 0x00000000
	.global _08019160
_08019160: .4byte 0x00000000
	.global _08019164
_08019164: .4byte 0x00000000
	.global _08019168
_08019168:
	ldr r5, [sp, #0x010]
	ldr r6, [sp, #0x014]
	movs r1, #0x00
	str r1, [sp, #0x060]
	movs r2, #0x00
	str r2, [sp, #0x064]
	ldr r3, [sp, #0x030]
	cmp r3, #0x00
	beq _080191DE
	ldr r1, [sp, #0x00C]
	cmp r1, #0x01
	bgt _0801919C
	ldr r2, [sp, #0x058]
	cmp r2, #0x00
	beq _08019194
	ldr r3, _08019190 @ =0x00000433
	adds r3, r3, r0
	mov r8, r3
	b _080191C8
	.byte 0x00, 0x00
	.global _08019190
_08019190: .4byte 0x00000433
	.global _08019194
_08019194:
	ldr r1, [sp, #0x008]
	movs r0, #0x36
	subs r0, r0, r1
	b _080191C6
	.global _0801919C
_0801919C:
	ldr r4, [sp, #0x018]
	subs r4, #0x01
	ldr r0, [sp, #0x014]
	cmp r0, r4
	blt _080191AA
	subs r6, r0, r4
	b _080191BA
	.global _080191AA
_080191AA:
	ldr r1, [sp, #0x014]
	subs r4, r4, r1
	ldr r2, [sp, #0x038]
	adds r2, r2, r4
	str r2, [sp, #0x038]
	adds r1, r1, r4
	str r1, [sp, #0x014]
	movs r6, #0x00
	.global _080191BA
_080191BA:
	ldr r3, [sp, #0x018]
	mov r8, r3
	cmp r3, #0x00
	bge _080191C8
	subs r5, r5, r3
	movs r0, #0x00
	.global _080191C6
_080191C6:
	mov r8, r0
	.global _080191C8
_080191C8:
	ldr r1, [sp, #0x010]
	add r1, r8
	str r1, [sp, #0x010]
	ldr r2, [sp, #0x034]
	add r2, r8
	str r2, [sp, #0x034]
	mov r0, r10
	movs r1, #0x01
	bl sub_0801A7D8
	str r0, [sp, #0x064]
	.global _080191DE
_080191DE:
	cmp r5, #0x00
	ble _08019200
	ldr r3, [sp, #0x034]
	cmp r3, #0x00
	ble _08019200
	mov r8, r3
	cmp r8, r5
	ble _080191F0
	mov r8, r5
	.global _080191F0
_080191F0:
	ldr r0, [sp, #0x010]
	mov r1, r8
	subs r0, r0, r1
	str r0, [sp, #0x010]
	subs r5, r5, r1
	ldr r2, [sp, #0x034]
	subs r2, r2, r1
	str r2, [sp, #0x034]
	.global _08019200
_08019200:
	ldr r3, [sp, #0x014]
	cmp r3, #0x00
	ble _0801924E
	ldr r0, [sp, #0x030]
	cmp r0, #0x00
	beq _08019242
	cmp r6, #0x00
	ble _08019232
	mov r0, r10
	ldr r1, [sp, #0x064]
	adds r2, r6, #0x0
	bl sub_0801A958
	str r0, [sp, #0x064]
	mov r0, r10
	ldr r1, [sp, #0x064]
	ldr r2, [sp, #0x05C]
	bl sub_0801A7EC
	adds r4, r0, #0x0
	mov r0, r10
	ldr r1, [sp, #0x05C]
	bl sub_0801A5C8
	str r4, [sp, #0x05C]
	.global _08019232
_08019232:
	ldr r1, [sp, #0x014]
	subs r4, r1, r6
	cmp r4, #0x00
	beq _0801924E
	mov r0, r10
	ldr r1, [sp, #0x05C]
	adds r2, r4, #0x0
	b _08019248
	.global _08019242
_08019242:
	mov r0, r10
	ldr r1, [sp, #0x05C]
	ldr r2, [sp, #0x014]
	.global _08019248
_08019248:
	bl sub_0801A958
	str r0, [sp, #0x05C]
	.global _0801924E
_0801924E:
	mov r0, r10
	movs r1, #0x01
	bl sub_0801A7D8
	str r0, [sp, #0x068]
	ldr r2, [sp, #0x038]
	cmp r2, #0x00
	ble _08019268
	mov r0, r10
	ldr r1, [sp, #0x068]
	bl sub_0801A958
	str r0, [sp, #0x068]
	.global _08019268
_08019268:
	ldr r3, [sp, #0x00C]
	cmp r3, #0x01
	bgt _080192A4
	ldr r0, [sp, #0x044]
	cmp r0, #0x00
	bne _080192A0
	ldr r0, _08019298 @ =0x000FFFFF
	ldr r1, [sp, #0x040]
	ands r0, r1
	cmp r0, #0x00
	bne _080192A0
	ldr r0, _0801929C @ =0x7FF00000
	ands r1, r0
	cmp r1, #0x00
	beq _080192A0
	ldr r1, [sp, #0x010]
	adds r1, #0x01
	str r1, [sp, #0x010]
	ldr r2, [sp, #0x034]
	adds r2, #0x01
	str r2, [sp, #0x034]
	movs r3, #0x01
	str r3, [sp, #0x03C]
	b _080192A4
	.global _08019298
_08019298: .4byte 0x000FFFFF
	.global _0801929C
_0801929C: .4byte 0x7FF00000
	.global _080192A0
_080192A0:
	movs r0, #0x00
	str r0, [sp, #0x03C]
	.global _080192A4
_080192A4:
	ldr r1, [sp, #0x038]
	cmp r1, #0x00
	beq _080192D0
	ldr r2, [sp, #0x068]
	ldr r1, [r2, #0x10]
	subs r1, #0x01
	lsls r1, r1, #0x02
	adds r0, r2, #0x0
	adds r0, #0x14
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl sub_0801A6FC
	ldr r1, [sp, #0x034]
	adds r1, #0x20
	subs r1, r1, r0
	mov r8, r1
	movs r0, #0x1F
	mov r3, r8
	ands r3, r0
	mov r8, r3
	b _080192DE
	.global _080192D0
_080192D0:
	ldr r0, [sp, #0x034]
	adds r0, #0x01
	mov r8, r0
	movs r0, #0x1F
	mov r1, r8
	ands r1, r0
	mov r8, r1
	.global _080192DE
_080192DE:
	mov r2, r8
	cmp r2, #0x00
	beq _080192EA
	movs r0, #0x20
	subs r2, r0, r2
	mov r8, r2
	.global _080192EA
_080192EA:
	mov r3, r8
	cmp r3, #0x04
	ble _080192F6
	movs r0, #0x04
	negs r0, r0
	b _080192FE
	.global _080192F6
_080192F6:
	mov r3, r8
	cmp r3, #0x03
	bgt _0801930E
	movs r0, #0x1C
	.global _080192FE
_080192FE:
	add r8, r0
	ldr r1, [sp, #0x010]
	add r1, r8
	str r1, [sp, #0x010]
	add r5, r8
	ldr r2, [sp, #0x034]
	add r2, r8
	str r2, [sp, #0x034]
	.global _0801930E
_0801930E:
	ldr r3, [sp, #0x010]
	cmp r3, #0x00
	ble _08019320
	mov r0, r10
	ldr r1, [sp, #0x05C]
	adds r2, r3, #0x0
	bl sub_0801A9F0
	str r0, [sp, #0x05C]
	.global _08019320
_08019320:
	ldr r0, [sp, #0x034]
	cmp r0, #0x00
	ble _08019332
	mov r0, r10
	ldr r1, [sp, #0x068]
	ldr r2, [sp, #0x034]
	bl sub_0801A9F0
	str r0, [sp, #0x068]
	.global _08019332
_08019332:
	ldr r1, [sp, #0x02C]
	cmp r1, #0x00
	beq _08019370
	ldr r0, [sp, #0x05C]
	ldr r1, [sp, #0x068]
	bl sub_0801AA90
	cmp r0, #0x00
	bge _08019370
	ldr r2, [sp, #0x024]
	subs r2, #0x01
	str r2, [sp, #0x024]
	mov r0, r10
	ldr r1, [sp, #0x05C]
	movs r2, #0x0A
	movs r3, #0x00
	bl sub_0801A5E0
	str r0, [sp, #0x05C]
	ldr r3, [sp, #0x030]
	cmp r3, #0x00
	beq _0801936C
	mov r0, r10
	ldr r1, [sp, #0x064]
	movs r2, #0x0A
	movs r3, #0x00
	bl sub_0801A5E0
	str r0, [sp, #0x064]
	.global _0801936C
_0801936C:
	ldr r0, [sp, #0x020]
	str r0, [sp, #0x018]
	.global _08019370
_08019370:
	ldr r1, [sp, #0x018]
	cmp r1, #0x00
	bgt _080193B4
	ldr r2, [sp, #0x00C]
	cmp r2, #0x02
	ble _080193B4
	cmp r1, #0x00
	blt _0801939A
	mov r0, r10
	ldr r1, [sp, #0x068]
	movs r2, #0x05
	movs r3, #0x00
	bl sub_0801A5E0
	str r0, [sp, #0x068]
	ldr r0, [sp, #0x05C]
	ldr r1, [sp, #0x068]
	bl sub_0801AA90
	cmp r0, #0x00
	bgt _080193A2
	.global _0801939A
_0801939A:
	ldr r3, [sp, #0x0A4]
	mvns r3, r3
	str r3, [sp, #0x024]
	b _080195EA
	.global _080193A2
_080193A2:
	movs r0, #0x31
	mov r1, r9
	strb r0, [r1, #0x00]
	movs r2, #0x01
	add r9, r2
	ldr r3, [sp, #0x024]
	adds r3, #0x01
	str r3, [sp, #0x024]
	b _080195EA
	.global _080193B4
_080193B4:
	ldr r0, [sp, #0x030]
	cmp r0, #0x00
	bne _080193BC
	b _08019532
	.global _080193BC
_080193BC:
	cmp r5, #0x00
	ble _080193CC
	mov r0, r10
	ldr r1, [sp, #0x064]
	adds r2, r5, #0x0
	bl sub_0801A9F0
	str r0, [sp, #0x064]
	.global _080193CC
_080193CC:
	ldr r1, [sp, #0x064]
	str r1, [sp, #0x060]
	ldr r2, [sp, #0x03C]
	cmp r2, #0x00
	beq _080193FE
	ldr r1, [r1, #0x04]
	mov r0, r10
	bl sub_0801A570
	str r0, [sp, #0x064]
	adds r0, #0x0C
	ldr r1, [sp, #0x060]
	adds r1, #0x0C
	ldr r3, [sp, #0x060]
	ldr r2, [r3, #0x10]
	lsls r2, r2, #0x02
	adds r2, #0x08
	bl sub_0801A42C
	mov r0, r10
	ldr r1, [sp, #0x064]
	movs r2, #0x01
	bl sub_0801A9F0
	str r0, [sp, #0x064]
	.global _080193FE
_080193FE:
	movs r0, #0x01
	mov r8, r0
	mov r1, r8
	ldr r2, [sp, #0x044]
	ands r2, r1
	str r2, [sp, #0x080]
	b _08019454
	.global _0801940C
_0801940C:
	mov r0, r10
	ldr r1, [sp, #0x05C]
	movs r2, #0x0A
	movs r3, #0x00
	bl sub_0801A5E0
	str r0, [sp, #0x05C]
	ldr r3, [sp, #0x060]
	ldr r0, [sp, #0x064]
	cmp r3, r0
	bne _08019434
	mov r0, r10
	ldr r1, [sp, #0x064]
	movs r2, #0x0A
	movs r3, #0x00
	bl sub_0801A5E0
	str r0, [sp, #0x064]
	str r0, [sp, #0x060]
	b _08019450
	.global _08019434
_08019434:
	mov r0, r10
	ldr r1, [sp, #0x060]
	movs r2, #0x0A
	movs r3, #0x00
	bl sub_0801A5E0
	str r0, [sp, #0x060]
	mov r0, r10
	ldr r1, [sp, #0x064]
	movs r2, #0x0A
	movs r3, #0x00
	bl sub_0801A5E0
	str r0, [sp, #0x064]
	.global _08019450
_08019450:
	movs r1, #0x01
	add r8, r1
	.global _08019454
_08019454:
	ldr r0, [sp, #0x05C]
	ldr r1, [sp, #0x068]
	bl sub_080187EC
	adds r7, r0, #0x0
	adds r7, #0x30
	ldr r0, [sp, #0x05C]
	ldr r1, [sp, #0x060]
	bl sub_0801AA90
	adds r4, r0, #0x0
	mov r0, r10
	ldr r1, [sp, #0x068]
	ldr r2, [sp, #0x064]
	bl sub_0801AAD0
	adds r5, r0, #0x0
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	bne _08019488
	ldr r0, [sp, #0x05C]
	adds r1, r5, #0x0
	bl sub_0801AA90
	adds r6, r0, #0x0
	b _0801948A
	.global _08019488
_08019488:
	movs r6, #0x01
	.global _0801948A
_0801948A:
	mov r0, r10
	adds r1, r5, #0x0
	bl sub_0801A5C8
	cmp r6, #0x00
	bne _080194B6
	ldr r2, [sp, #0x00C]
	cmp r2, #0x00
	bne _080194B6
	ldr r3, [sp, #0x080]
	cmp r3, #0x00
	bne _080194B6
	cmp r7, #0x39
	beq _08019508
	cmp r4, #0x00
	ble _080194AC
	adds r7, #0x01
	.global _080194AC
_080194AC:
	mov r0, r9
	strb r7, [r0, #0x00]
	movs r1, #0x01
	add r9, r1
	b _080195EA
	.global _080194B6
_080194B6:
	cmp r4, #0x00
	blt _080194CA
	cmp r4, #0x00
	bne _08019500
	ldr r2, [sp, #0x00C]
	cmp r2, #0x00
	bne _08019500
	ldr r3, [sp, #0x080]
	cmp r3, #0x00
	bne _08019500
	.global _080194CA
_080194CA:
	cmp r6, #0x00
	ble _080194FA
	mov r0, r10
	ldr r1, [sp, #0x05C]
	movs r2, #0x01
	bl sub_0801A9F0
	str r0, [sp, #0x05C]
	ldr r1, [sp, #0x068]
	bl sub_0801AA90
	adds r6, r0, #0x0
	cmp r6, #0x00
	bgt _080194F4
	cmp r6, #0x00
	bne _080194FA
	adds r0, r7, #0x0
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080194FA
	.global _080194F4
_080194F4:
	adds r7, #0x01
	cmp r7, #0x3A
	beq _08019508
	.global _080194FA
_080194FA:
	mov r2, r9
	strb r7, [r2, #0x00]
	b _080195B2
	.global _08019500
_08019500:
	cmp r6, #0x00
	ble _08019520
	cmp r7, #0x39
	bne _08019514
	.global _08019508
_08019508:
	movs r0, #0x39
	mov r1, r9
	strb r0, [r1, #0x00]
	movs r2, #0x01
	add r9, r2
	b _08019588
	.global _08019514
_08019514:
	adds r0, r7, #0x1
	mov r3, r9
	strb r0, [r3, #0x00]
	movs r0, #0x01
	add r9, r0
	b _080195EA
	.global _08019520
_08019520:
	mov r1, r9
	strb r7, [r1, #0x00]
	movs r2, #0x01
	add r9, r2
	ldr r3, [sp, #0x018]
	cmp r8, r3
	beq _08019530
	b _0801940C
	.global _08019530
_08019530:
	b _08019564
	.global _08019532
_08019532:
	movs r0, #0x01
	mov r8, r0
	b _0801954A
	.global _08019538
_08019538:
	mov r0, r10
	ldr r1, [sp, #0x05C]
	movs r2, #0x0A
	movs r3, #0x00
	bl sub_0801A5E0
	str r0, [sp, #0x05C]
	movs r1, #0x01
	add r8, r1
	.global _0801954A
_0801954A:
	ldr r0, [sp, #0x05C]
	ldr r1, [sp, #0x068]
	bl sub_080187EC
	adds r7, r0, #0x0
	adds r7, #0x30
	mov r2, r9
	strb r7, [r2, #0x00]
	movs r3, #0x01
	add r9, r3
	ldr r0, [sp, #0x018]
	cmp r8, r0
	blt _08019538
	.global _08019564
_08019564:
	mov r0, r10
	ldr r1, [sp, #0x05C]
	movs r2, #0x01
	bl sub_0801A9F0
	str r0, [sp, #0x05C]
	ldr r1, [sp, #0x068]
	bl sub_0801AA90
	adds r4, r0, #0x0
	cmp r4, #0x00
	bgt _08019588
	cmp r4, #0x00
	bne _080195CA
	movs r0, #0x01
	ands r7, r0
	cmp r7, #0x00
	beq _080195CA
	.global _08019588
_08019588:
	movs r1, #0x01
	negs r1, r1
	add r9, r1
	mov r2, r9
	ldrb r2, [r2, #0x00]
	cmp r2, #0x39
	bne _080195AA
	.global _08019596
_08019596:
	ldr r3, [sp, #0x074]
	cmp r9, r3
	beq _080195B8
	movs r0, #0x01
	negs r0, r0
	add r9, r0
	mov r1, r9
	ldrb r1, [r1, #0x00]
	cmp r1, #0x39
	beq _08019596
	.global _080195AA
_080195AA:
	mov r2, r9
	ldrb r0, [r2, #0x00]
	adds r0, #0x01
	strb r0, [r2, #0x00]
	.global _080195B2
_080195B2:
	movs r3, #0x01
	add r9, r3
	b _080195EA
	.global _080195B8
_080195B8:
	ldr r0, [sp, #0x024]
	adds r0, #0x01
	str r0, [sp, #0x024]
	movs r0, #0x31
	ldr r1, [sp, #0x074]
	strb r0, [r1, #0x00]
	adds r1, #0x01
	mov r9, r1
	b _080195EA
	.global _080195CA
_080195CA:
	movs r2, #0x01
	negs r2, r2
	add r9, r2
	mov r3, r9
	ldrb r3, [r3, #0x00]
	cmp r3, #0x30
	bne _080195E6
	.global _080195D8
_080195D8:
	movs r0, #0x01
	negs r0, r0
	add r9, r0
	mov r1, r9
	ldrb r1, [r1, #0x00]
	cmp r1, #0x30
	beq _080195D8
	.global _080195E6
_080195E6:
	movs r2, #0x01
	add r9, r2
	.global _080195EA
_080195EA:
	mov r0, r10
	ldr r1, [sp, #0x068]
	bl sub_0801A5C8
	ldr r3, [sp, #0x064]
	cmp r3, #0x00
	beq _08019612
	ldr r0, [sp, #0x060]
	cmp r0, #0x00
	beq _0801960A
	cmp r0, r3
	beq _0801960A
	mov r0, r10
	ldr r1, [sp, #0x060]
	bl sub_0801A5C8
	.global _0801960A
_0801960A:
	mov r0, r10
	ldr r1, [sp, #0x064]
	bl sub_0801A5C8
	.global _08019612
_08019612:
	mov r0, r10
	ldr r1, [sp, #0x05C]
	bl sub_0801A5C8
	movs r0, #0x00
	mov r1, r9
	strb r0, [r1, #0x00]
	ldr r0, [sp, #0x024]
	adds r0, #0x01
	ldr r2, [sp, #0x0A8]
	str r0, [r2, #0x00]
	ldr r3, [sp, #0x0B0]
	cmp r3, #0x00
	beq _08019630
	str r1, [r3, #0x00]
	.global _08019630
_08019630:
	ldr r0, [sp, #0x074]
	.global _08019632
_08019632:
	add sp, #0x084
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_08019640
sub_08019640:
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _0801965C
	ldr r0, _08019654 @ =0x083FFAA8
	ldr r0, [r0, #0x00]
	ldr r1, _08019658 @ =0x08019641
	bl sub_08019CDC
	b _080196D2
	.global _08019654
_08019654: .4byte 0x083FFAA8
	.global _08019658
_08019658: .4byte sub_08019640
	.global _0801965C
_0801965C:
	ldr r0, [r4, #0x54]
	cmp r0, #0x00
	bne _08019668
	ldr r0, _0801969C @ =0x083FFAA8
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x54]
	.global _08019668
_08019668:
	ldr r1, [r4, #0x54]
	ldr r0, [r1, #0x38]
	cmp r0, #0x00
	bne _08019676
	adds r0, r1, #0x0
	bl sub_080197D0
	.global _08019676
_08019676:
	movs r0, #0x0C
	ldsh r1, [r4, r0]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080196D0
	ldr r6, [r4, #0x10]
	cmp r6, #0x00
	beq _080196D0
	ldr r0, [r4, #0x00]
	subs r5, r0, r6
	str r6, [r4, #0x00]
	movs r0, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _080196AE
	ldr r0, [r4, #0x14]
	b _080196B0
	.byte 0x00, 0x00
	.global _0801969C
_0801969C: .4byte 0x083FFAA8
	.global _080196A0
_080196A0:
	movs r0, #0x40
	ldrh r1, [r4, #0x0C]
	orrs r0, r1
	strh r0, [r4, #0x0C]
	movs r0, #0x01
	negs r0, r0
	b _080196D2
	.global _080196AE
_080196AE:
	movs r0, #0x00
	.global _080196B0
_080196B0:
	str r0, [r4, #0x08]
	cmp r5, #0x00
	ble _080196D0
	.global _080196B6
_080196B6:
	ldr r0, [r4, #0x1C]
	ldr r3, [r4, #0x24]
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	bl _08017200
	adds r1, r0, #0x0
	cmp r1, #0x00
	ble _080196A0
	adds r6, r6, r1
	subs r5, r5, r1
	cmp r5, #0x00
	bgt _080196B6
	.global _080196D0
_080196D0:
	movs r0, #0x00
	.global _080196D2
_080196D2:
	pop {r4, r5, r6, pc}
	thumb_func_start sub_080196D4
sub_080196D4:
	push {r4, lr}
	movs r4, #0x00
	str r4, [r0, #0x00]
	str r4, [r0, #0x04]
	str r4, [r0, #0x08]
	strh r1, [r0, #0x0C]
	strh r2, [r0, #0x0E]
	str r4, [r0, #0x10]
	str r4, [r0, #0x18]
	str r0, [r0, #0x1C]
	ldr r1, _080196FC @ =0x0801AEB1
	str r1, [r0, #0x20]
	ldr r1, _08019700 @ =0x0801AEE5
	str r1, [r0, #0x24]
	ldr r1, _08019704 @ =0x0801AF25
	str r1, [r0, #0x28]
	ldr r1, _08019708 @ =0x0801AF65
	str r1, [r0, #0x2C]
	str r3, [r0, #0x54]
	pop {r4, pc}
	.global _080196FC
_080196FC: .4byte 0x0801AEB1
	.global _08019700
_08019700: .4byte 0x0801AEE5
	.global _08019704
_08019704: .4byte 0x0801AF25
	.global _08019708
_08019708: .4byte 0x0801AF65
	thumb_func_start sub_0801970C
sub_0801970C:
	push {r4, r5, r6, lr}
	adds r5, r1, #0x0
	movs r1, #0x58
	adds r6, r5, #0x0
	muls r6, r1
	adds r1, r6, #0x0
	adds r1, #0x0C
	bl sub_08019FC0
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _08019738
	adds r0, #0x0C
	movs r1, #0x00
	str r1, [r4, #0x00]
	str r5, [r4, #0x04]
	str r0, [r4, #0x08]
	adds r2, r6, #0x0
	bl sub_0801A514
	adds r0, r4, #0x0
	b _0801973A
	.global _08019738
_08019738:
	movs r0, #0x00
	.global _0801973A
_0801973A:
	pop {r4, r5, r6, pc}
	.byte 0x30, 0xB5, 0x05, 0x1C, 0xA8, 0x6B, 0x00, 0x28, 0x02, 0xD1, 0x28, 0x1C, 0x00, 0xF0, 0x42, 0xF8
	.byte 0xEC, 0x20, 0x40, 0x00, 0x2C, 0x18, 0x00, 0xE0, 0x24, 0x68, 0xA2, 0x68, 0x60, 0x68, 0x04, 0xE0
	.byte 0x0C, 0x23, 0xD1, 0x5E, 0x00, 0x29, 0x11, 0xD0, 0x58, 0x32, 0x01, 0x38, 0x00, 0x28, 0xF7, 0xDA
	.byte 0x20, 0x68, 0x00, 0x28, 0xF0, 0xD1, 0x28, 0x1C, 0x04, 0x21, 0xFF, 0xF7, 0xC9, 0xFF, 0x20, 0x60
	.byte 0x00, 0x28, 0xE9, 0xD1, 0x0C, 0x20, 0x28, 0x60, 0x00, 0x20, 0x0F, 0xE0, 0x01, 0x20, 0x90, 0x81
	.byte 0x11, 0x60, 0x91, 0x60, 0x51, 0x60, 0x11, 0x61, 0x51, 0x61, 0x91, 0x61, 0x04, 0x48, 0xD0, 0x81
	.byte 0x11, 0x63, 0x51, 0x63, 0x51, 0x64, 0x91, 0x64, 0x55, 0x65, 0x10, 0x1C, 0x30, 0xBD, 0x00, 0x00
	.byte 0xFF, 0xFF, 0x00, 0x00
	thumb_func_start sub_080197B0
sub_080197B0:
	push {lr}
	ldr r1, _080197BC @ =0x08019641
	bl sub_08019CDC
	pop {pc}
	.byte 0x00, 0x00
	.global _080197BC
_080197BC: .4byte sub_08019640
	.byte 0x00, 0xB5, 0x02, 0x48, 0x00, 0x68, 0xFF, 0xF7, 0xF3, 0xFF, 0x00, 0xBD, 0xA8, 0xFA, 0x3F, 0x08
	thumb_func_start sub_080197D0
sub_080197D0:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r0, _0801982C @ =0x080197B1
	str r0, [r5, #0x3C]
	movs r0, #0x01
	str r0, [r5, #0x38]
	movs r0, #0xF2
	lsls r0, r0, #0x01
	adds r4, r5, r0
	adds r0, r4, #0x0
	movs r1, #0x04
	movs r2, #0x00
	adds r3, r5, #0x0
	bl sub_080196D4
	movs r1, #0x8F
	lsls r1, r1, #0x02
	adds r0, r5, r1
	movs r1, #0x09
	movs r2, #0x01
	adds r3, r5, #0x0
	bl sub_080196D4
	movs r1, #0xA5
	lsls r1, r1, #0x02
	adds r0, r5, r1
	movs r1, #0x0A
	movs r2, #0x02
	adds r3, r5, #0x0
	bl sub_080196D4
	movs r0, #0xEC
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x00
	str r0, [r1, #0x00]
	movs r0, #0xEE
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x03
	str r0, [r1, #0x00]
	movs r1, #0xF0
	lsls r1, r1, #0x01
	adds r0, r5, r1
	str r4, [r0, #0x00]
	pop {r4, r5, pc}
	.global _0801982C
_0801982C: .4byte sub_080197B0
	thumb_func_start sub_08019830
sub_08019830:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r9, r0
	adds r4, r1, #0x0
	cmp r4, #0x00
	bne _08019842
	b _080199E6
	.global _08019842
_08019842:
	bl sub_0801A568
	adds r5, r4, #0x0
	subs r5, #0x08
	ldr r1, [r5, #0x04]
	movs r6, #0x02
	negs r6, r6
	ands r6, r1
	adds r7, r5, r6
	ldr r4, [r7, #0x04]
	movs r0, #0x04
	negs r0, r0
	ands r4, r0
	ldr r0, _080198A4 @ =0x083FFAC0
	mov r12, r0
	ldr r0, [r0, #0x08]
	cmp r7, r0
	bne _080198B0
	adds r6, r6, r4
	movs r4, #0x01
	ands r1, r4
	cmp r1, #0x00
	bne _0801987E
	ldr r0, [r5, #0x00]
	subs r5, r5, r0
	adds r6, r6, r0
	ldr r3, [r5, #0x0C]
	ldr r2, [r5, #0x08]
	str r3, [r2, #0x0C]
	str r2, [r3, #0x08]
	.global _0801987E
_0801987E:
	adds r0, r6, #0x0
	orrs r0, r4
	str r0, [r5, #0x04]
	mov r2, r12
	str r5, [r2, #0x08]
	ldr r0, _080198A8 @ =0x083FFEC8
	ldr r0, [r0, #0x00]
	cmp r6, r0
	bcc _0801989A
	ldr r0, _080198AC @ =0x083FFECC
	ldr r1, [r0, #0x00]
	mov r0, r9
	bl sub_080199F0
	.global _0801989A
_0801989A:
	mov r0, r9
	bl sub_0801A56C
	b _080199E6
	.byte 0x00, 0x00
	.global _080198A4
_080198A4: .4byte 0x083FFAC0
	.global _080198A8
_080198A8: .4byte 0x083FFEC8
	.global _080198AC
_080198AC: .4byte 0x083FFECC
	.global _080198B0
_080198B0:
	str r4, [r7, #0x04]
	movs r0, #0x00
	mov r8, r0
	movs r0, #0x01
	ands r1, r0
	cmp r1, #0x00
	bne _080198DC
	ldr r0, [r5, #0x00]
	subs r5, r5, r0
	adds r6, r6, r0
	ldr r1, [r5, #0x08]
	mov r0, r12
	adds r0, #0x08
	cmp r1, r0
	bne _080198D4
	movs r2, #0x01
	mov r8, r2
	b _080198DC
	.global _080198D4
_080198D4:
	ldr r3, [r5, #0x0C]
	adds r2, r1, #0x0
	str r3, [r2, #0x0C]
	str r2, [r3, #0x08]
	.global _080198DC
_080198DC:
	adds r0, r7, r4
	ldr r0, [r0, #0x04]
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _08019914
	adds r6, r6, r4
	ldr r1, [r7, #0x08]
	mov r0, r8
	cmp r0, #0x00
	bne _0801990C
	ldr r0, _08019908 @ =0x083FFAC8
	cmp r1, r0
	bne _0801990C
	movs r2, #0x01
	mov r8, r2
	str r5, [r1, #0x0C]
	str r5, [r1, #0x08]
	str r1, [r5, #0x0C]
	str r1, [r5, #0x08]
	b _08019914
	.byte 0x00, 0x00
	.global _08019908
_08019908: .4byte 0x083FFAC8
	.global _0801990C
_0801990C:
	ldr r3, [r7, #0x0C]
	adds r2, r1, #0x0
	str r3, [r2, #0x0C]
	str r2, [r3, #0x08]
	.global _08019914
_08019914:
	movs r1, #0x01
	adds r0, r6, #0x0
	orrs r0, r1
	str r0, [r5, #0x04]
	adds r0, r5, r6
	str r6, [r0, #0x00]
	mov r0, r8
	cmp r0, #0x00
	bne _080199E0
	ldr r0, _08019944 @ =0x000001FF
	cmp r6, r0
	bhi _0801994C
	lsrs r4, r6, #0x03
	ldr r2, _08019948 @ =0x083FFAC0
	adds r0, r4, #0x0
	asrs r0, r0, #0x02
	lsls r1, r0
	ldr r0, [r2, #0x04]
	orrs r0, r1
	str r0, [r2, #0x04]
	lsls r0, r4, #0x03
	adds r3, r0, r2
	ldr r2, [r3, #0x08]
	b _080199D8
	.global _08019944
_08019944: .4byte 0x000001FF
	.global _08019948
_08019948: .4byte 0x083FFAC0
	.global _0801994C
_0801994C:
	lsrs r1, r6, #0x09
	cmp r1, #0x00
	bne _08019956
	lsrs r4, r6, #0x03
	b _0801999E
	.global _08019956
_08019956:
	cmp r1, #0x04
	bhi _08019962
	lsrs r0, r6, #0x06
	adds r4, r0, #0x0
	adds r4, #0x38
	b _0801999E
	.global _08019962
_08019962:
	cmp r1, #0x14
	bhi _0801996C
	adds r4, r1, #0x0
	adds r4, #0x5B
	b _0801999E
	.global _0801996C
_0801996C:
	cmp r1, #0x54
	bhi _08019978
	lsrs r0, r6, #0x0C
	adds r4, r0, #0x0
	adds r4, #0x6E
	b _0801999E
	.global _08019978
_08019978:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	cmp r1, r0
	bhi _08019988
	lsrs r0, r6, #0x0F
	adds r4, r0, #0x0
	adds r4, #0x77
	b _0801999E
	.global _08019988
_08019988:
	ldr r0, _08019998 @ =0x00000554
	cmp r1, r0
	bhi _0801999C
	lsrs r0, r6, #0x12
	adds r4, r0, #0x0
	adds r4, #0x7C
	b _0801999E
	.byte 0x00, 0x00
	.global _08019998
_08019998: .4byte 0x00000554
	.global _0801999C
_0801999C:
	movs r4, #0x7E
	.global _0801999E
_0801999E:
	lsls r0, r4, #0x03
	ldr r7, _080199BC @ =0x083FFAC0
	adds r3, r0, r7
	ldr r2, [r3, #0x08]
	cmp r2, r3
	bne _080199C0
	adds r0, r4, #0x0
	asrs r0, r0, #0x02
	movs r1, #0x01
	lsls r1, r0
	ldr r0, [r7, #0x04]
	orrs r0, r1
	str r0, [r7, #0x04]
	b _080199D8
	.byte 0x00, 0x00
	.global _080199BC
_080199BC: .4byte 0x083FFAC0
	.global _080199C0
_080199C0:
	ldr r0, [r2, #0x04]
	movs r1, #0x04
	negs r1, r1
	b _080199D0
	.global _080199C8
_080199C8:
	ldr r2, [r2, #0x08]
	cmp r2, r3
	beq _080199D6
	ldr r0, [r2, #0x04]
	.global _080199D0
_080199D0:
	ands r0, r1
	cmp r6, r0
	bcc _080199C8
	.global _080199D6
_080199D6:
	ldr r3, [r2, #0x0C]
	.global _080199D8
_080199D8:
	str r3, [r5, #0x0C]
	str r2, [r5, #0x08]
	str r5, [r3, #0x08]
	str r5, [r2, #0x0C]
	.global _080199E0
_080199E0:
	mov r0, r9
	bl sub_0801A56C
	.global _080199E6
_080199E6:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_080199F0
sub_080199F0:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	adds r4, r1, #0x0
	bl sub_0801A568
	ldr r0, _08019A78 @ =0x083FFAC0
	mov r8, r0
	ldr r0, [r0, #0x08]
	ldr r6, [r0, #0x04]
	movs r0, #0x04
	negs r0, r0
	ands r6, r0
	subs r4, r6, r4
	movs r5, #0x80
	lsls r5, r5, #0x05
	ldr r1, _08019A7C @ =0x00000FEF
	adds r4, r4, r1
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl _08017420
	subs r0, #0x01
	lsls r4, r0, #0x0C
	cmp r4, r5
	blt _08019A6E
	adds r0, r7, #0x0
	movs r1, #0x00
	bl sub_0801AE84
	adds r2, r0, #0x0
	mov r1, r8
	ldr r0, [r1, #0x08]
	adds r0, r0, r6
	cmp r2, r0
	bne _08019A6E
	negs r1, r4
	adds r0, r7, #0x0
	bl sub_0801AE84
	movs r1, #0x01
	negs r1, r1
	cmp r0, r1
	bne _08019A88
	adds r0, r7, #0x0
	movs r1, #0x00
	bl sub_0801AE84
	adds r2, r0, #0x0
	mov r0, r8
	ldr r3, [r0, #0x08]
	subs r6, r2, r3
	cmp r6, #0x0F
	ble _08019A6E
	ldr r1, _08019A80 @ =0x083FFEDC
	ldr r0, _08019A84 @ =0x083FFED0
	ldr r0, [r0, #0x00]
	subs r0, r2, r0
	str r0, [r1, #0x00]
	movs r0, #0x01
	orrs r6, r0
	str r6, [r3, #0x04]
	.global _08019A6E
_08019A6E:
	adds r0, r7, #0x0
	bl sub_0801A56C
	movs r0, #0x00
	b _08019AA4
	.global _08019A78
_08019A78: .4byte 0x083FFAC0
	.global _08019A7C
_08019A7C: .4byte 0x00000FEF
	.global _08019A80
_08019A80: .4byte 0x083FFEDC
	.global _08019A84
_08019A84: .4byte 0x083FFED0
	.global _08019A88
_08019A88:
	mov r1, r8
	ldr r2, [r1, #0x08]
	subs r0, r6, r4
	movs r1, #0x01
	orrs r0, r1
	str r0, [r2, #0x04]
	ldr r1, _08019AAC @ =0x083FFEDC
	ldr r0, [r1, #0x00]
	subs r0, r0, r4
	str r0, [r1, #0x00]
	adds r0, r7, #0x0
	bl sub_0801A56C
	movs r0, #0x01
	.global _08019AA4
_08019AA4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
	.global _08019AAC
_08019AAC: .4byte 0x083FFEDC
	thumb_func_start sub_08019AB0
sub_08019AB0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r5, r0, #0x0
	mov r10, r1
	ldr r6, [r1, #0x08]
	cmp r6, #0x00
	bne _08019AC8
	b _08019CBE
	.global _08019AC8
_08019AC8:
	movs r0, #0x08
	ldrh r1, [r5, #0x0C]
	ands r0, r1
	cmp r0, #0x00
	beq _08019AD8
	ldr r0, [r5, #0x10]
	cmp r0, #0x00
	bne _08019AE4
	.global _08019AD8
_08019AD8:
	adds r0, r5, #0x0
	bl sub_08018740
	cmp r0, #0x00
	beq _08019AE4
	b _08019CCA
	.global _08019AE4
_08019AE4:
	mov r2, r10
	ldr r2, [r2, #0x00]
	mov r8, r2
	movs r6, #0x00
	ldrh r1, [r5, #0x0C]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _08019B38
	.global _08019AF6
_08019AF6:
	ldr r0, [r5, #0x1C]
	ldr r3, [r5, #0x24]
	cmp r6, #0x00
	bne _08019B0C
	.global _08019AFE
_08019AFE:
	mov r1, r8
	ldr r7, [r1, #0x00]
	ldr r6, [r1, #0x04]
	movs r2, #0x08
	add r8, r2
	cmp r6, #0x00
	beq _08019AFE
	.global _08019B0C
_08019B0C:
	adds r2, r6, #0x0
	movs r1, #0x80
	lsls r1, r1, #0x03
	cmp r6, r1
	bls _08019B18
	adds r2, r1, #0x0
	.global _08019B18
_08019B18:
	adds r1, r7, #0x0
	bl _08017200
	adds r4, r0, #0x0
	cmp r4, #0x00
	bgt _08019B26
	b _08019CC2
	.global _08019B26
_08019B26:
	adds r7, r7, r4
	subs r6, r6, r4
	mov r1, r10
	ldr r0, [r1, #0x08]
	subs r0, r0, r4
	str r0, [r1, #0x08]
	cmp r0, #0x00
	bne _08019AF6
	b _08019CBE
	.global _08019B38
_08019B38:
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _08019BF2
	.global _08019B40
_08019B40:
	ldrh r1, [r5, #0x0C]
	ldr r0, [r5, #0x08]
	ldr r3, [r5, #0x00]
	cmp r6, #0x00
	bne _08019B58
	.global _08019B4A
_08019B4A:
	mov r2, r8
	ldr r7, [r2, #0x00]
	ldr r6, [r2, #0x04]
	movs r2, #0x08
	add r8, r2
	cmp r6, #0x00
	beq _08019B4A
	.global _08019B58
_08019B58:
	adds r4, r0, #0x0
	movs r2, #0x80
	lsls r2, r2, #0x02
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08019B86
	cmp r6, r4
	bcs _08019B6C
	adds r4, r6, #0x0
	.global _08019B6C
_08019B6C:
	adds r0, r3, #0x0
	adds r1, r7, #0x0
	adds r2, r4, #0x0
	bl sub_0801A48C
	ldr r0, [r5, #0x08]
	subs r0, r0, r4
	str r0, [r5, #0x08]
	ldr r0, [r5, #0x00]
	adds r0, r0, r4
	str r0, [r5, #0x00]
	adds r4, r6, #0x0
	b _08019BE0
	.global _08019B86
_08019B86:
	ldr r0, [r5, #0x10]
	cmp r3, r0
	bls _08019BAE
	cmp r6, r4
	bls _08019BAE
	adds r0, r3, #0x0
	adds r1, r7, #0x0
	adds r2, r4, #0x0
	bl sub_0801A48C
	ldr r0, [r5, #0x00]
	adds r0, r0, r4
	str r0, [r5, #0x00]
	adds r0, r5, #0x0
	bl sub_08019640
	cmp r0, #0x00
	beq _08019BAC
	b _08019CC2
	.global _08019BAC
_08019BAC:
	b _08019BE0
	.global _08019BAE
_08019BAE:
	ldr r4, [r5, #0x14]
	cmp r6, r4
	bcc _08019BC8
	ldr r0, [r5, #0x1C]
	ldr r3, [r5, #0x24]
	adds r1, r7, #0x0
	adds r2, r4, #0x0
	bl _08017200
	adds r4, r0, #0x0
	cmp r4, #0x00
	ble _08019CC2
	b _08019BE0
	.global _08019BC8
_08019BC8:
	adds r4, r6, #0x0
	adds r0, r3, #0x0
	adds r1, r7, #0x0
	adds r2, r4, #0x0
	bl sub_0801A48C
	ldr r0, [r5, #0x08]
	subs r0, r0, r4
	str r0, [r5, #0x08]
	ldr r0, [r5, #0x00]
	adds r0, r0, r4
	str r0, [r5, #0x00]
	.global _08019BE0
_08019BE0:
	adds r7, r7, r4
	subs r6, r6, r4
	mov r1, r10
	ldr r0, [r1, #0x08]
	subs r0, r0, r4
	str r0, [r1, #0x08]
	cmp r0, #0x00
	bne _08019B40
	b _08019CBE
	.global _08019BF2
_08019BF2:
	movs r2, #0x00
	str r2, [sp, #0x000]
	.global _08019BF6
_08019BF6:
	cmp r6, #0x00
	bne _08019C0C
	movs r0, #0x00
	str r0, [sp, #0x000]
	.global _08019BFE
_08019BFE:
	mov r1, r8
	ldr r7, [r1, #0x00]
	ldr r6, [r1, #0x04]
	movs r2, #0x08
	add r8, r2
	cmp r6, #0x00
	beq _08019BFE
	.global _08019C0C
_08019C0C:
	ldr r0, [sp, #0x000]
	cmp r0, #0x00
	bne _08019C30
	adds r0, r7, #0x0
	movs r1, #0x0A
	adds r2, r6, #0x0
	bl sub_0801A3AC
	adds r1, r0, #0x0
	cmp r1, #0x00
	beq _08019C28
	subs r0, r7, #0x1
	subs r1, r1, r0
	b _08019C2A
	.global _08019C28
_08019C28:
	adds r1, r6, #0x1
	.global _08019C2A
_08019C2A:
	mov r9, r1
	movs r2, #0x01
	str r2, [sp, #0x000]
	.global _08019C30
_08019C30:
	mov r2, r9
	cmp r9, r6
	bls _08019C38
	adds r2, r6, #0x0
	.global _08019C38
_08019C38:
	ldr r0, [r5, #0x08]
	ldr r1, [r5, #0x14]
	adds r4, r0, r1
	ldr r0, [r5, #0x10]
	ldr r3, [r5, #0x00]
	cmp r3, r0
	bls _08019C66
	cmp r2, r4
	ble _08019C66
	adds r0, r3, #0x0
	adds r1, r7, #0x0
	adds r2, r4, #0x0
	bl sub_0801A48C
	ldr r0, [r5, #0x00]
	adds r0, r0, r4
	str r0, [r5, #0x00]
	adds r0, r5, #0x0
	bl sub_08019640
	cmp r0, #0x00
	bne _08019CC2
	b _08019C96
	.global _08019C66
_08019C66:
	adds r4, r1, #0x0
	cmp r2, r4
	blt _08019C80
	ldr r0, [r5, #0x1C]
	ldr r3, [r5, #0x24]
	adds r1, r7, #0x0
	adds r2, r4, #0x0
	bl _08017200
	adds r4, r0, #0x0
	cmp r4, #0x00
	ble _08019CC2
	b _08019C96
	.global _08019C80
_08019C80:
	adds r4, r2, #0x0
	adds r0, r3, #0x0
	adds r1, r7, #0x0
	bl sub_0801A48C
	ldr r0, [r5, #0x08]
	subs r0, r0, r4
	str r0, [r5, #0x08]
	ldr r0, [r5, #0x00]
	adds r0, r0, r4
	str r0, [r5, #0x00]
	.global _08019C96
_08019C96:
	mov r0, r9
	subs r0, r0, r4
	mov r9, r0
	cmp r0, #0x00
	bne _08019CAE
	adds r0, r5, #0x0
	bl sub_08019640
	cmp r0, #0x00
	bne _08019CC2
	movs r1, #0x00
	str r1, [sp, #0x000]
	.global _08019CAE
_08019CAE:
	adds r7, r7, r4
	subs r6, r6, r4
	mov r2, r10
	ldr r0, [r2, #0x08]
	subs r0, r0, r4
	str r0, [r2, #0x08]
	cmp r0, #0x00
	bne _08019BF6
	.global _08019CBE
_08019CBE:
	movs r0, #0x00
	b _08019CCE
	.global _08019CC2
_08019CC2:
	movs r0, #0x40
	ldrh r1, [r5, #0x0C]
	orrs r0, r1
	strh r0, [r5, #0x0C]
	.global _08019CCA
_08019CCA:
	movs r0, #0x01
	negs r0, r0
	.global _08019CCE
_08019CCE:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_08019CDC
sub_08019CDC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	movs r7, #0x00
	movs r1, #0xEC
	lsls r1, r1, #0x01
	adds r6, r0, r1
	cmp r6, #0x00
	beq _08019D14
	.global _08019CF0
_08019CF0:
	ldr r5, [r6, #0x08]
	ldr r4, [r6, #0x04]
	b _08019D08
	.global _08019CF6
_08019CF6:
	movs r1, #0x0C
	ldsh r0, [r5, r1]
	cmp r0, #0x00
	beq _08019D06
	adds r0, r5, #0x0
	bl _08017214
	orrs r7, r0
	.global _08019D06
_08019D06:
	adds r5, #0x58
	.global _08019D08
_08019D08:
	subs r4, #0x01
	cmp r4, #0x00
	bge _08019CF6
	ldr r6, [r6, #0x00]
	cmp r6, #0x00
	bne _08019CF0
	.global _08019D14
_08019D14:
	adds r0, r7, #0x0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	thumb_func_start sub_08019D1C
sub_08019D1C:
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	adds r4, r2, #0x0
	cmp r4, #0x00
	beq _08019D50
	ldr r1, _08019D44 @ =0x08339530
	adds r0, r4, #0x0
	bl sub_0801AF74
	cmp r0, #0x00
	beq _08019D4C
	ldr r1, _08019D48 @ =0x08339528
	adds r0, r4, #0x0
	bl sub_0801AF74
	cmp r0, #0x00
	beq _08019D4C
	movs r0, #0x00
	b _08019D52
	.global _08019D44
_08019D44: .4byte 0x08339530
	.global _08019D48
_08019D48: .4byte 0x08339528
	.global _08019D4C
_08019D4C:
	str r6, [r5, #0x30]
	str r4, [r5, #0x34]
	.global _08019D50
_08019D50:
	ldr r0, _08019D54 @ =0x08339530
	.global _08019D52
_08019D52:
	pop {r4, r5, r6, pc}
	.global _08019D54
_08019D54: .4byte 0x08339530
