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
	thumb_func_start sub_0800BEA4
sub_0800BEA4:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	str r0, [sp, #0x00C]
	adds r5, r3, #0x0
	ldr r0, [sp, #0x038]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x010]
	ldr r0, [sp, #0x00C]
	ldr r6, [r0, #0x00]
	movs r1, #0x00
	mov r8, r1
	.global _0800BEC4
_0800BEC4:
	ldr r2, [sp, #0x010]
	cmp r2, #0x00
	bne _0800BEEC
	movs r0, #0x01
	mov r1, r8
	ands r0, r1
	cmp r0, #0x00
	beq _0800BEE0
	adds r0, r6, #0x0
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl sub_0800BE00
	b _0800BEF6
	.global _0800BEE0
_0800BEE0:
	adds r0, r6, #0x0
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl sub_0800BE00
	b _0800BEF6
	.global _0800BEEC
_0800BEEC:
	adds r0, r6, #0x0
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl sub_0800BE00
	.global _0800BEF6
_0800BEF6:
	movs r2, #0x01
	add r8, r2
	mov r0, r8
	cmp r0, #0x18
	bne _0800BEC4
	ldr r1, [sp, #0x00C]
	ldr r6, [r1, #0x00]
	movs r0, #0x00
	str r0, [r6, #0x2C]
	adds r0, r6, #0x0
	bl sub_0800C28C
	ldr r0, [r6, #0x00]
	str r0, [r6, #0x18]
	ldr r0, [r6, #0x08]
	str r0, [r6, #0x1C]
	adds r0, r6, #0x0
	movs r1, #0x00
	bl sub_0800C358
	movs r1, #0x01
	negs r1, r1
	cmp r0, r1
	bne _0800BF28
	b _0800C0C2
	.global _0800BF28
_0800BF28:
	ldr r0, _0800BF94 @ =0x0202CC24
	ldr r0, [r0, #0x00]
	ldr r1, _0800BF98 @ =0x0202CC38
	ldr r1, [r1, #0x00]
	adds r2, r6, #0x0
	adds r2, #0xF4
	ldr r2, [r2, #0x00]
	ldr r3, _0800BF9C @ =0x0202CC3C
	ldr r3, [r3, #0x00]
	ldr r4, _0800BFA0 @ =0x0202CC34
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	bl sub_0800BBFC
	adds r7, r0, #0x0
	ldr r2, _0800BFA4 @ =0xFFFFEC78
	adds r7, r7, r2
	cmp r7, #0x00
	bge _0800BF58
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	adds r7, r7, r0
	.global _0800BF58
_0800BF58:
	ldr r2, [sp, #0x00C]
	mov r9, r2
	movs r0, #0x00
	mov r8, r0
	ldr r0, _0800BFA8 @ =0x02002090
	ldrb r0, [r0, #0x00]
	cmp r8, r0
	bne _0800BF6A
	b _0800C086
	.global _0800BF6A
_0800BF6A:
	mov r1, sp
	adds r1, #0x04
	str r1, [sp, #0x014]
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r0, r0, #0x01
	mov r10, r0
	.global _0800BF7C
_0800BF7C:
	mov r2, r9
	ldr r6, [r2, #0x00]
	ldr r0, [sp, #0x010]
	cmp r0, #0x00
	beq _0800BFAC
	adds r0, r6, #0x0
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl sub_0800BE00
	b _0800BFCC
	.byte 0x00, 0x00
	.global _0800BF94
_0800BF94: .4byte 0x0202CC24
	.global _0800BF98
_0800BF98: .4byte 0x0202CC38
	.global _0800BF9C
_0800BF9C: .4byte 0x0202CC3C
	.global _0800BFA0
_0800BFA0: .4byte 0x0202CC34
	.global _0800BFA4
_0800BFA4: .4byte 0xFFFFEC78
	.global _0800BFA8
_0800BFA8: .4byte 0x02002090
	.global _0800BFAC
_0800BFAC:
	movs r0, #0x01
	mov r1, r8
	ands r0, r1
	cmp r0, #0x00
	beq _0800BFC2
	adds r0, r6, #0x0
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl sub_0800BE00
	b _0800BFCC
	.global _0800BFC2
_0800BFC2:
	adds r0, r6, #0x0
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl sub_0800BE00
	.global _0800BFCC
_0800BFCC:
	adds r5, r6, #0x0
	adds r5, #0xF4
	ldr r1, [r5, #0x00]
	adds r4, r6, #0x0
	adds r4, #0xF8
	ldr r2, [r4, #0x00]
	adds r0, r7, #0x0
	adds r3, r6, #0x0
	bl sub_0800BD44
	ldr r2, [r5, #0x00]
	ldr r3, [r4, #0x00]
	adds r0, r7, #0x0
	add r1, sp, #0x004
	bl sub_0800BD98
	ldr r0, [sp, #0x004]
	lsls r0, r0, #0x10
	str r0, [r6, #0x00]
	ldr r2, [sp, #0x014]
	ldr r0, [r2, #0x04]
	lsls r0, r0, #0x10
	str r0, [r6, #0x08]
	adds r0, r7, #0x0
	adds r0, #0x32
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r1, [r1, #0x00]
	bl sub_080172C8
	ldr r2, [r5, #0x00]
	ldr r3, [r4, #0x00]
	add r1, sp, #0x004
	bl sub_0800BD98
	ldr r0, [sp, #0x004]
	lsls r0, r0, #0x10
	ldr r1, [r6, #0x00]
	subs r0, r0, r1
	ldr r2, [sp, #0x014]
	ldr r1, [r2, #0x04]
	lsls r1, r1, #0x10
	ldr r2, [r6, #0x08]
	subs r1, r1, r2
	asrs r0, r0, #0x05
	asrs r1, r1, #0x05
	bl sub_0800CB18
	lsls r0, r0, #0x08
	ldr r2, _0800C0D4 @ =0xFFFF8400
	adds r1, r2, #0x0
	subs r1, r1, r0
	strh r1, [r6, #0x34]
	ldr r0, _0800C0D8 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0F
	bne _0800C052
	mov r0, r8
	cmp r0, #0x00
	bne _0800C052
	ldr r0, _0800C0DC @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _0800C052
	ldr r1, _0800C0E0 @ =0xFFFFFE0C
	adds r7, r7, r1
	.global _0800C052
_0800C052:
	ldr r2, [sp, #0x010]
	cmp r2, #0x00
	bne _0800C062
	movs r0, #0x01
	mov r2, r8
	ands r0, r2
	cmp r0, #0x00
	beq _0800C074
	.global _0800C062
_0800C062:
	mov r0, r10
	subs r7, r7, r0
	cmp r7, #0x00
	bge _0800C074
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	adds r7, r7, r0
	.global _0800C074
_0800C074:
	movs r2, #0x01
	add r8, r2
	movs r0, #0x04
	add r9, r0
	ldr r0, _0800C0E4 @ =0x02002090
	ldrb r0, [r0, #0x00]
	cmp r8, r0
	beq _0800C086
	b _0800BF7C
	.global _0800C086
_0800C086:
	movs r1, #0x00
	.global _0800C088
_0800C088:
	ldr r2, [sp, #0x00C]
	mov r9, r2
	movs r0, #0x00
	mov r8, r0
	ldr r0, _0800C0E4 @ =0x02002090
	adds r4, r1, #0x1
	ldrb r1, [r0, #0x00]
	cmp r8, r1
	beq _0800C0BC
	adds r5, r0, #0x0
	.global _0800C09C
_0800C09C:
	mov r2, r9
	adds r2, #0x04
	mov r9, r2
	subs r2, #0x04
	ldm r2!, {r6}
	mov r0, r8
	lsls r1, r0, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0x0
	bl sub_0800C534
	movs r1, #0x01
	add r8, r1
	ldrb r2, [r5, #0x00]
	cmp r8, r2
	bne _0800C09C
	.global _0800C0BC
_0800C0BC:
	adds r1, r4, #0x0
	cmp r1, #0x32
	bne _0800C088
	.global _0800C0C2
_0800C0C2:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800C0D4
_0800C0D4: .4byte 0xFFFF8400
	.global _0800C0D8
_0800C0D8: .4byte 0x0200215C
	.global _0800C0DC
_0800C0DC: .4byte 0x0202ED70
	.global _0800C0E0
_0800C0E0: .4byte 0xFFFFFE0C
	.global _0800C0E4
_0800C0E4: .4byte 0x02002090
