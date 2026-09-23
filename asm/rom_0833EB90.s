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
	thumb_func_start sub_0833EB90
sub_0833EB90:
	push {r4, r5, r6, lr}
	ldr r0, _0833EBB0 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833EBBC
	ldr r0, _0833EBB4 @ =0x0203E1B0
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _0833EBB8 @ =0x0203D520
	adds r5, r0, r1
	b _0833EBBE
	.byte 0x00, 0x00
_0833EBB0: .4byte 0x020390EC
_0833EBB4: .4byte 0x0203E1B0
_0833EBB8: .4byte 0x0203D520
_0833EBBC:
	ldr r5, _0833EC78 @ =0x0203D520
_0833EBBE:
	bl sub_0833E1F4
	ldr r6, _0833EC7C @ =0x020251B8
	ldr r0, [r6, #0x00]
	ldr r1, _0833EC80 @ =0x000004C6
	adds r4, r0, r1
	ldr r0, _0833EC84 @ =0x0203B6C8
	ldrh r1, [r0, #0x00]
	ldr r0, _0833EC88 @ =0x0203B6A8
	ldrh r2, [r0, #0x00]
	ldr r0, _0833EC8C @ =0x0203B858
	ldrh r3, [r0, #0x00]
	adds r0, r4, #0x0
	bl sub_0833DDB8
	ldr r0, _0833EC90 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0E
	beq _0833EBE8
	cmp r0, #0x02
	bne _0833EC14
_0833EBE8:
	ldr r0, [r6, #0x00]
	ldr r1, _0833EC94 @ =0x00000486
	adds r4, r0, r1
	ldr r0, _0833EC98 @ =0x0203E1E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833EC14
	ldr r0, _0833EC9C @ =0x0203B810
	ldr r1, _0833ECA0 @ =0x020390DC
	ldrb r1, [r1, #0x00]
	lsls r3, r1, #0x01
	adds r0, r3, r0
	ldrh r1, [r0, #0x00]
	ldr r0, _0833ECA4 @ =0x0203B6B0
	adds r0, r3, r0
	ldrh r2, [r0, #0x00]
	ldr r0, _0833ECA8 @ =0x0203B830
	adds r3, r3, r0
	ldrh r3, [r3, #0x00]
	adds r0, r4, #0x0
	bl sub_0833DDB8
_0833EC14:
	ldr r0, [r5, #0x2C]
	negs r0, r0
	asrs r1, r0, #0x0D
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r1, r0, #0x01
	cmp r1, #0x00
	bge _0833EC2A
	movs r1, #0x00
_0833EC2A:
	adds r0, r1, #0x0
	bl sub_0833E528
	ldr r4, _0833EC90 @ =0x0203916C
	ldrb r0, [r4, #0x00]
	cmp r0, #0x02
	beq _0833ECD8
	cmp r0, #0x0E
	beq _0833ECD8
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	adds r0, #0x01
	bl sub_0833E714
	movs r1, #0xC7
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833EC62
	ldrb r0, [r4, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _0833ECB0
_0833EC62:
	adds r0, r5, #0x0
	adds r0, #0x4C
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x01
	ldr r1, _0833ECAC @ =0x02039194
	ldrb r1, [r1, #0x00]
	bl sub_0833E7FC
	b _0833ECBA
_0833EC78: .4byte 0x0203D520
_0833EC7C: .4byte 0x020251B8
_0833EC80: .4byte 0x000004C6
_0833EC84: .4byte 0x0203B6C8
_0833EC88: .4byte 0x0203B6A8
_0833EC8C: .4byte 0x0203B858
_0833EC90: .4byte 0x0203916C
_0833EC94: .4byte 0x00000486
_0833EC98: .4byte 0x0203E1E0
_0833EC9C: .4byte 0x0203B810
_0833ECA0: .4byte 0x020390DC
_0833ECA4: .4byte 0x0203B6B0
_0833ECA8: .4byte 0x0203B830
_0833ECAC: .4byte 0x02039194
_0833ECB0:
	ldr r0, _0833ECE4 @ =0x000003E7
	ldr r1, _0833ECE8 @ =0x02039194
	ldrb r1, [r1, #0x00]
	bl sub_0833E7FC
_0833ECBA:
	adds r0, r5, #0x0
	adds r0, #0x9C
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	bl sub_0833E5EC
	adds r0, r5, #0x0
	bl sub_0833E94C
	adds r0, r5, #0x0
	bl sub_0833E59C
	adds r0, r5, #0x0
	bl sub_0833E5E8
_0833ECD8:
	adds r0, r5, #0x0
	bl sub_0833D9EC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0833ECE4: .4byte 0x000003E7
_0833ECE8: .4byte 0x02039194
