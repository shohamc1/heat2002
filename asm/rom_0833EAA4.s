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
	thumb_func_start sub_0833EAA4
sub_0833EAA4:
	push {r4, r5, lr}
	bl sub_0833E1F4
	ldr r0, _0833EB10 @ =0x020251B8
	ldr r4, [r0, #0x00]
	movs r0, #0x89
	lsls r0, r0, #0x03
	adds r5, r4, r0
	ldr r0, _0833EB14 @ =0x0203B6C8
	ldrh r1, [r0, #0x00]
	ldr r0, _0833EB18 @ =0x0203B6A8
	ldrh r2, [r0, #0x00]
	ldr r0, _0833EB1C @ =0x0203B858
	ldrh r3, [r0, #0x00]
	adds r0, r5, #0x0
	bl sub_0833DDB8
	movs r0, #0x91
	lsls r0, r0, #0x03
	adds r5, r4, r0
	ldr r0, _0833EB20 @ =0x0203E1E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833EAF2
	ldr r0, _0833EB24 @ =0x0203B810
	ldr r1, _0833EB28 @ =0x020390DC
	ldrb r1, [r1, #0x00]
	lsls r3, r1, #0x01
	adds r0, r3, r0
	ldrh r1, [r0, #0x00]
	ldr r0, _0833EB2C @ =0x0203B6B0
	adds r0, r3, r0
	ldrh r2, [r0, #0x00]
	ldr r0, _0833EB30 @ =0x0203B830
	adds r3, r3, r0
	ldrh r3, [r3, #0x00]
	adds r0, r5, #0x0
	bl sub_0833DDB8
_0833EAF2:
	ldr r0, _0833EB34 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833EB40
	ldr r0, _0833EB38 @ =0x0203E1B0
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _0833EB3C @ =0x0203D520
	adds r4, r0, r1
	b _0833EB42
	.byte 0x00, 0x00
_0833EB10: .4byte 0x020251B8
_0833EB14: .4byte 0x0203B6C8
_0833EB18: .4byte 0x0203B6A8
_0833EB1C: .4byte 0x0203B858
_0833EB20: .4byte 0x0203E1E0
_0833EB24: .4byte 0x0203B810
_0833EB28: .4byte 0x020390DC
_0833EB2C: .4byte 0x0203B6B0
_0833EB30: .4byte 0x0203B830
_0833EB34: .4byte 0x020390EC
_0833EB38: .4byte 0x0203E1B0
_0833EB3C: .4byte 0x0203D520
_0833EB40:
	ldr r4, _0833EB88 @ =0x0203D520
_0833EB42:
	ldr r0, [r4, #0x2C]
	negs r0, r0
	asrs r1, r0, #0x0D
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r1, r0, #0x01
	cmp r1, #0x00
	bge _0833EB58
	movs r1, #0x00
_0833EB58:
	adds r0, r1, #0x0
	bl sub_0833E528
	adds r0, r4, #0x0
	adds r0, #0x9C
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	bl sub_0833E5EC
	adds r0, r4, #0x0
	bl sub_0833E94C
	adds r0, r4, #0x0
	bl sub_0833E59C
	adds r0, r4, #0x0
	bl sub_0833E5E8
	adds r0, r4, #0x0
	bl sub_0833D9EC
	pop {r4, r5}
	pop {r0}
	bx r0
_0833EB88: .4byte 0x0203D520
