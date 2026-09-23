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
	thumb_func_start sub_0801303C
sub_0801303C:
	push {r4, r5, r6, r7, lr}
	ldr r4, _080130B0 @ =0xFFFFFE00
	add sp, r4
	movs r5, #0x00
	movs r0, #0x03
	mov r1, sp
	bl sub_08011C9C
	bl sub_08012FB0
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r4, #0x40
	ldr r7, _080130B4 @ =0x020005CC
_0801305C:
	bl sub_0800048C
	bl sub_08012FB0
	movs r0, #0x01
	ldrh r1, [r7, #0x00]
	ands r0, r1
	lsls r1, r5, #0x18
	cmp r0, #0x00
	beq _08013072
	lsrs r4, r1, #0x18
_08013072:
	ldrh r0, [r7, #0x00]
	asrs r1, r1, #0x18
	movs r2, #0x00
	movs r3, #0x00
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl sub_08000458
	lsls r6, r4, #0x18
	cmp r4, #0x40
	beq _0801305C
	ldr r0, _080130B8 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0801309A
	movs r0, #0x09
	bl sub_08001208
_0801309A:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r6, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080130B0: .4byte 0xFFFFFE00
_080130B4: .4byte 0x020005CC
_080130B8: .4byte 0x0202EF00
