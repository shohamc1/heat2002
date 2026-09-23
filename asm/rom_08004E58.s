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
	thumb_func_start sub_08004E58
sub_08004E58:
	push {r4, r5, r6, lr}
	movs r2, #0x00
	movs r1, #0x00
	ldr r0, _08004E94 @ =0x020020AC
	ldrb r0, [r0, #0x00]
	ldr r6, _08004E98 @ =0x02025258
	ldr r5, _08004E9C @ =0x020253BC
	cmp r2, r0
	beq _08004E80
	ldr r4, _08004EA0 @ =0x020020A0
	adds r3, r0, #0x0
_08004E6E:
	lsls r0, r1, #0x01
	adds r0, r0, r4
	ldrh r0, [r0, #0x00]
	orrs r2, r0
	adds r0, r1, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r3
	bne _08004E6E
_08004E80:
	adds r0, r2, #0x0
	ldrh r1, [r5, #0x00]
	bics r0, r1
	strh r0, [r6, #0x00]
	strh r2, [r5, #0x00]
	ldrh r0, [r6, #0x00]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08004E94: .4byte 0x020020AC
_08004E98: .4byte 0x02025258
_08004E9C: .4byte 0x020253BC
_08004EA0: .4byte 0x020020A0
