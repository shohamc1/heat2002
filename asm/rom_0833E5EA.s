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
	thumb_func_start sub_0833E5EC
sub_0833E5EC:
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	ldr r0, _0833E6A4 @ =0x0203E0E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833E5FC
	b _0833E6FE
	.global _0833E5FC
_0833E5FC:
	ldr r1, _0833E6A8 @ =0x0203B6D8
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	mov r1, sp
	movs r0, #0xAA
	strh r0, [r1, #0x00]
	movs r0, #0x89
	strh r0, [r1, #0x02]
	ldr r0, _0833E6AC @ =0x02024F70
	bl sub_0833FC94
	adds r5, r0, #0x0
	cmp r5, #0x00
	beq _0833E64C
	mov r0, sp
	ldrh r0, [r0, #0x02]
	movs r4, #0xFF
	ands r4, r0
	mov r1, sp
	ldr r0, _0833E6B0 @ =0x000001FF
	ldrh r1, [r1, #0x00]
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r4, r0
	ldr r0, _0833E6B4 @ =0x02024F50
	bl sub_0833FD78
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	ldr r1, [r5, #0x10]
	orrs r1, r0
	ldr r0, _0833E6B8 @ =0x02000100
	orrs r4, r0
	adds r0, r4, #0x0
	bl sub_0833D6A0
	.global _0833E64C
_0833E64C:
	ldr r2, _0833E6BC @ =0x0203B828
	asrs r0, r6, #0x10
	adds r0, #0xBE
	movs r1, #0xFF
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r0, _0833E6C0 @ =0x020251B8
	ldr r0, [r0, #0x00]
	ldr r1, _0833E6C4 @ =0x000004EE
	adds r3, r0, r1
	ldr r0, _0833E6C8 @ =0x000031FF
	cmp r6, r0
	bgt _0833E6E4
	ldr r0, _0833E6CC @ =0x020390AC
	ldr r0, [r0, #0x00]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _0833E6E4
	ldr r2, _0833E6D0 @ =0x02022254
	ldr r0, _0833E6D4 @ =0x02021594
	ldr r1, _0833E6D8 @ =0x000005B2
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r2
	movs r2, #0xE0
	lsls r2, r2, #0x08
	adds r0, r2, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r3, #0x00]
	ldr r0, _0833E6DC @ =0x0203E120
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0833E6FE
	ldr r0, _0833E6E0 @ =0x020390F0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833E6FE
	movs r0, #0x1B
	bl sub_0833A8C8
	b _0833E6FE
	.global _0833E6A4
_0833E6A4: .4byte 0x0203E0E0
	.global _0833E6A8
_0833E6A8: .4byte 0x0203B6D8
	.global _0833E6AC
_0833E6AC: .4byte 0x02024F70
	.global _0833E6B0
_0833E6B0: .4byte 0x000001FF
	.global _0833E6B4
_0833E6B4: .4byte 0x02024F50
	.global _0833E6B8
_0833E6B8: .4byte 0x02000100
	.global _0833E6BC
_0833E6BC: .4byte 0x0203B828
	.global _0833E6C0
_0833E6C0: .4byte 0x020251B8
	.global _0833E6C4
_0833E6C4: .4byte 0x000004EE
	.global _0833E6C8
_0833E6C8: .4byte 0x000031FF
	.global _0833E6CC
_0833E6CC: .4byte 0x020390AC
	.global _0833E6D0
_0833E6D0: .4byte 0x02022254
	.global _0833E6D4
_0833E6D4: .4byte 0x02021594
	.global _0833E6D8
_0833E6D8: .4byte 0x000005B2
	.global _0833E6DC
_0833E6DC: .4byte 0x0203E120
	.global _0833E6E0
_0833E6E0: .4byte 0x020390F0
	.global _0833E6E4
_0833E6E4:
	ldr r2, _0833E708 @ =0x02022254
	ldr r0, _0833E70C @ =0x02021594
	ldr r1, _0833E710 @ =0x000005B4
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r2
	movs r2, #0xE0
	lsls r2, r2, #0x08
	adds r0, r2, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r3, #0x00]
	.global _0833E6FE
_0833E6FE:
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833E708
_0833E708: .4byte 0x02022254
	.global _0833E70C
_0833E70C: .4byte 0x02021594
	.global _0833E710
_0833E710: .4byte 0x000005B4
