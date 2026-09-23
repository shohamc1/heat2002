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
	thumb_func_start sub_0833E3F8
sub_0833E3F8:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	ldr r2, _0833E41C @ =0x020215EA
	adds r1, r1, r2
	ldr r3, _0833E420 @ =0x02022254
	ldrh r1, [r1, #0x00]
	lsls r2, r1, #0x01
	adds r2, r2, r3
	ldr r1, _0833E424 @ =0x00000FFF
	ldrh r2, [r2, #0x00]
	ands r1, r2
	movs r3, #0xE0
	lsls r3, r3, #0x08
	adds r2, r3, #0x0
	orrs r1, r2
	strh r1, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_0833E41C: .4byte 0x020215EA
_0833E420: .4byte 0x02022254
_0833E424: .4byte 0x00000FFF
	thumb_func_start sub_0833E428
sub_0833E428:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x020
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	adds r4, r3, #0x0
	ldr r5, [sp, #0x034]
	movs r0, #0x0A
	str r0, [sp, #0x004]
	str r0, [sp, #0x010]
	str r2, [sp, #0x000]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08344C50
	str r0, [sp, #0x00C]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08344BB8
	str r0, [sp, #0x008]
	adds r0, r5, #0x0
	movs r1, #0x64
	bl sub_08344C50
	movs r1, #0x0A
	bl sub_08344BB8
	str r0, [sp, #0x018]
	adds r0, r5, #0x0
	movs r1, #0x64
	bl sub_08344BB8
	str r0, [sp, #0x014]
	movs r0, #0x00
	str r0, [sp, #0x01C]
	movs r4, #0x00
	movs r0, #0xFF
	ands r7, r0
	mov r5, sp
_0833E476:
	ldr r0, _0833E4A0 @ =0x000001FF
	ands r0, r6
	lsls r0, r0, #0x10
	orrs r0, r7
	ldm r5!, {r1}
	movs r2, #0xF5
	lsls r2, r2, #0x02
	adds r1, r1, r2
	movs r2, #0xC0
	lsls r2, r2, #0x06
	orrs r1, r2
	bl sub_0833D6A0
	adds r6, #0x04
	adds r4, #0x01
	cmp r4, #0x08
	bne _0833E476
	add sp, #0x020
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0833E4A0: .4byte 0x000001FF
	thumb_func_start sub_0833E4A4
sub_0833E4A4:
	push {r4, r5, r6, lr}
	ldr r5, _0833E518 @ =0x0203B700
	ldr r0, _0833E51C @ =0x0203B6CC
	ldr r4, [r0, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08344C50
	strb r0, [r5, #0x01]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08344BB8
	strb r0, [r5, #0x00]
	ldr r4, _0833E520 @ =0x020251B8
	ldr r0, [r4, #0x00]
	adds r0, #0x82
	ldrb r1, [r5, #0x00]
	bl sub_0833E36C
	ldr r0, [r4, #0x00]
	adds r0, #0x86
	ldrb r1, [r5, #0x01]
	bl sub_0833E36C
	ldr r0, _0833E524 @ =0x0203B84C
	ldr r6, [r0, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl sub_08344BB8
	movs r1, #0x0A
	bl sub_08344C50
	strb r0, [r5, #0x01]
	adds r0, r6, #0x0
	movs r1, #0x64
	bl sub_08344BB8
	strb r0, [r5, #0x00]
	ldr r0, [r4, #0x00]
	adds r0, #0xCA
	movs r1, #0x0A
	bl sub_0833E3C8
	ldr r0, [r4, #0x00]
	adds r0, #0xCC
	ldrb r1, [r5, #0x00]
	bl sub_0833E3C8
	ldr r0, [r4, #0x00]
	adds r0, #0xCE
	ldrb r1, [r5, #0x01]
	bl sub_0833E3C8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0833E518: .4byte 0x0203B700
_0833E51C: .4byte 0x0203B6CC
_0833E520: .4byte 0x020251B8
_0833E524: .4byte 0x0203B84C
