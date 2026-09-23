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
	thumb_func_start sub_0800B030
sub_0800B030:
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _0800B08C @ =0x0202EDCC
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _0800B090 @ =0x02022E14
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800B084
	movs r0, #0x9B
	bl sub_08016558
	movs r1, #0x4C
	movs r2, #0x18
	bl sub_0800BB58
	ldr r0, [r4, #0x18]
	subs r0, #0x01
	str r0, [r4, #0x18]
	cmp r0, #0x00
	bne _0800B084
	adds r0, r4, #0x0
	bl sub_08007950
	adds r0, r4, #0x0
	bl sub_0800792C
	movs r0, #0x0A
	movs r1, #0x00
	bl sub_08003F84
	bl sub_08000458
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2, #0x00]
	ldr r0, _0800B094 @ =0x0000EFFF
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r1, _0800B098 @ =0x020021E0
	movs r0, #0x02
	strb r0, [r1, #0x00]
_0800B084:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800B08C: .4byte 0x0202EDCC
_0800B090: .4byte 0x02022E14
_0800B094: .4byte 0x0000EFFF
_0800B098: .4byte 0x020021E0
