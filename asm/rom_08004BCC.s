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
	thumb_func_start sub_08004BCC
sub_08004BCC:
	push {r4, r5, lr}
	ldr r1, _08004C30 @ =0x020005CC
	movs r0, #0x04
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08004C3C
	movs r4, #0x00
	bl sub_080047DC
_08004BE0:
	bl ReadKeys
	ldr r1, _08004C30 @ =0x020005CC
	movs r0, #0x04
	ldrh r2, [r1, #0x00]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x00
	bne _08004C3C
	ldrh r0, [r1, #0x00]
	adds r1, r4, #0x0
	movs r2, #0x00
	movs r3, #0x09
	bl MenuMoveVertical
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0x0
	bl sub_08004B1C
	bl AgeGfxCaches
	bl ClearOamBuffer
	adds r0, r4, #0x0
	bl sub_08004A7C
	bl sub_080047DC
	ldr r0, _08004C34 @ =0x020020C0
	strb r5, [r0, #0x00]
	ldr r1, _08004C38 @ =0x02025370
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	bl WaitForVBlank
	b _08004BE0
	.byte 0x00, 0x00
_08004C30: .4byte 0x020005CC
_08004C34: .4byte 0x020020C0
_08004C38: .4byte 0x02025370
_08004C3C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
