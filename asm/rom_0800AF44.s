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
	thumb_func_start sub_0800AF44
sub_0800AF44:
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _0800AF80 @ =0x02022E14
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800AFDC
	ldr r0, _0800AF84 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800AFA0
	ldr r0, _0800AF88 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	subs r0, #0x0A
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _0800AF90
	ldr r0, _0800AF8C @ =0x02002098
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800AFA0
	movs r0, #0x8E
	bl sub_08016558
	movs r1, #0x0A
	movs r2, #0x03
	movs r3, #0x01
	bl sub_0800649C
	b _0800AFA0
_0800AF80: .4byte 0x02022E14
_0800AF84: .4byte 0x020020DC
_0800AF88: .4byte 0x0200215C
_0800AF8C: .4byte 0x02002098
_0800AF90:
	movs r0, #0x97
	bl sub_08016558
	movs r1, #0x0A
	movs r2, #0x03
	movs r3, #0x01
	bl sub_0800649C
_0800AFA0:
	ldr r0, [r4, #0x18]
	subs r0, #0x01
	str r0, [r4, #0x18]
	cmp r0, #0x00
	bne _0800AFDC
	adds r0, r4, #0x0
	bl sub_08007950
	adds r0, r4, #0x0
	bl sub_0800792C
	ldr r0, _0800AFE4 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x04
	beq _0800AFD6
	movs r0, #0x0A
	movs r1, #0x00
	bl sub_08003F84
	bl sub_08000458
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2, #0x00]
	ldr r0, _0800AFE8 @ =0x0000EFFF
	ands r0, r1
	strh r0, [r2, #0x00]
_0800AFD6:
	ldr r1, _0800AFEC @ =0x020021E0
	movs r0, #0x02
	strb r0, [r1, #0x00]
_0800AFDC:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800AFE4: .4byte 0x0200215C
_0800AFE8: .4byte 0x0000EFFF
_0800AFEC: .4byte 0x020021E0
