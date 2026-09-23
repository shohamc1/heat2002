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
	thumb_func_start sub_0800CC00
sub_0800CC00:
	push {lr}
	adds r3, r0, #0x0
	ldr r0, _0800CC38 @ =0x020020CC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	beq _0800CC44
	ldr r0, _0800CC3C @ =0xFFC00000
	adds r1, r1, r0
	ldr r0, _0800CC40 @ =0xFFC80000
	adds r2, r2, r0
	adds r0, r3, #0x0
	bl sub_0800CB70
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	movs r0, #0xFF
	lsls r0, r0, #0x18
	adds r1, r1, r0
	movs r0, #0xC0
	lsls r0, r0, #0x12
	ands r0, r1
	lsrs r0, r0, #0x18
	movs r1, #0x01
	ands r0, r1
	movs r1, #0x02
	orrs r0, r1
	lsls r0, r0, #0x0A
	b _0800CC48
_0800CC38: .4byte 0x020020CC
_0800CC3C: .4byte 0xFFC00000
_0800CC40: .4byte 0xFFC80000
_0800CC44:
	movs r0, #0xC0
	lsls r0, r0, #0x04
_0800CC48:
	pop {r1}
	bx r1
	thumb_func_start sub_0800CC4C
sub_0800CC4C:
	push {lr}
	adds r2, r0, #0x0
	ldr r0, _0800CC84 @ =0x020020CC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	beq _0800CC90
	ldr r3, _0800CC88 @ =0xFFC00000
	adds r0, r2, r3
	ldr r2, _0800CC8C @ =0xFFA00000
	adds r1, r1, r2
	bl sub_0800CBB8
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	movs r3, #0xFF
	lsls r3, r3, #0x18
	adds r1, r1, r3
	movs r0, #0xC0
	lsls r0, r0, #0x12
	ands r0, r1
	lsrs r0, r0, #0x18
	movs r1, #0x01
	ands r0, r1
	movs r1, #0x02
	orrs r0, r1
	lsls r0, r0, #0x0A
	b _0800CC94
	.byte 0x00, 0x00
_0800CC84: .4byte 0x020020CC
_0800CC88: .4byte 0xFFC00000
_0800CC8C: .4byte 0xFFA00000
_0800CC90:
	movs r0, #0xC0
	lsls r0, r0, #0x04
_0800CC94:
	pop {r1}
	bx r1
