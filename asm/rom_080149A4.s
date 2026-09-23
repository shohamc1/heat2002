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
	thumb_func_start sub_080149A4
sub_080149A4:
	push {r4, r5, r6, r7, lr}
	ldr r4, _08014A2C @ =0xFFFFFE00
	add sp, r4
	movs r4, #0x00
	movs r0, #0x05
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_08014944
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r6, #0x40
	ldr r7, _08014A30 @ =0x020005CC
_080149C6:
	bl sub_0800048C
	lsls r5, r4, #0x18
	lsrs r4, r5, #0x18
	adds r0, r4, #0x0
	bl sub_08014944
	movs r0, #0x01
	ldrh r1, [r7, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080149E0
	adds r6, r4, #0x0
_080149E0:
	ldrh r0, [r7, #0x00]
	asrs r1, r5, #0x18
	movs r2, #0x00
	movs r3, #0x02
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0x02
	ldrh r1, [r7, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080149FC
	movs r6, #0x00
_080149FC:
	bl sub_08000458
	lsls r5, r6, #0x18
	cmp r6, #0x40
	beq _080149C6
	ldr r0, _08014A34 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08014A14
	movs r0, #0x09
	bl sub_08001208
_08014A14:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r5, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08014A2C: .4byte 0xFFFFFE00
_08014A30: .4byte 0x020005CC
_08014A34: .4byte 0x0202EF00
