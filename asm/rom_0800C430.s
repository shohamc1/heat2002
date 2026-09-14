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
	thumb_func_start sub_0800C430
sub_0800C430:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r4, r0, #0x0
	ldr r5, _0800C4B0 @ =0x0202A550
	ldr r2, _0800C4B4 @ =0x0202CC28
	movs r0, #0x00
	strb r0, [r2, #0x00]
	ldr r1, _0800C4B8 @ =0x0202CC2C
	strb r0, [r1, #0x00]
	movs r6, #0x00
	ldr r0, _0800C4BC @ =0x02002090
	ldrb r0, [r0, #0x00]
	cmp r6, r0
	beq _0800C4D4
	adds r7, r2, #0x0
	.global _0800C44E
_0800C44E:
	cmp r4, r5
	beq _0800C4C4
	ldr r1, [r5, #0x00]
	ldr r0, [r4, #0x00]
	subs r0, r1, r0
	cmp r0, #0x00
	bge _0800C45E
	negs r0, r0
	.global _0800C45E
_0800C45E:
	movs r3, #0xFA
	lsls r3, r3, #0x10
	cmp r0, r3
	bgt _0800C4C4
	ldr r2, [r5, #0x08]
	ldr r0, [r4, #0x08]
	subs r0, r2, r0
	cmp r0, #0x00
	bge _0800C472
	negs r0, r0
	.global _0800C472
_0800C472:
	cmp r0, r3
	bgt _0800C4C4
	adds r0, r4, #0x0
	mov r3, sp
	bl sub_0800C0FC
	ldr r1, [sp, #0x004]
	movs r0, #0x10
	negs r0, r0
	cmp r1, r0
	bgt _0800C4C4
	ldr r2, [sp, #0x000]
	cmp r2, r0
	blt _0800C4C4
	cmp r2, #0x10
	bgt _0800C4C4
	subs r0, #0x70
	cmp r1, r0
	ble _0800C49E
	ldr r1, _0800C4B8 @ =0x0202CC2C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	.global _0800C49E
_0800C49E:
	ldr r1, [sp, #0x004]
	movs r0, #0x40
	negs r0, r0
	cmp r1, r0
	blt _0800C4C4
	cmp r2, #0x00
	bge _0800C4C0
	movs r0, #0x01
	b _0800C4C2
	.global _0800C4B0
_0800C4B0: .4byte 0x0202A550
	.global _0800C4B4
_0800C4B4: .4byte 0x0202CC28
	.global _0800C4B8
_0800C4B8: .4byte 0x0202CC2C
	.global _0800C4BC
_0800C4BC: .4byte 0x02002090
	.global _0800C4C0
_0800C4C0:
	movs r0, #0x02
	.global _0800C4C2
_0800C4C2:
	strb r0, [r7, #0x00]
	.global _0800C4C4
_0800C4C4:
	adds r6, #0x01
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r5, r5, r0
	ldr r0, _0800C4DC @ =0x02002090
	ldrb r0, [r0, #0x00]
	cmp r6, r0
	bne _0800C44E
	.global _0800C4D4
_0800C4D4:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800C4DC
_0800C4DC: .4byte 0x02002090
