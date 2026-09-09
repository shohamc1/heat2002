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
	thumb_func_start sub_08016C50
sub_08016C50:
	push {r4, r5, r6, lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4, r5, r6}
	adds r4, r0, #0x0
	mov r10, r1
	mov r9, r2
	mov r8, r3
	ldr r6, _08016CAC @ =0x0000EA60
	adds r1, r6, #0x0
	bl sub_08017230
	adds r5, r0, #0x0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r0, r5, #0x0
	muls r0, r6
	subs r4, r4, r0
	movs r1, #0xFA
	lsls r1, r1, #0x02
	adds r0, r4, #0x0
	bl sub_08017230
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #0x05
	subs r1, r1, r0
	lsls r1, r1, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x03
	subs r4, r4, r1
	mov r1, r8
	strh r4, [r1, #0x00]
	mov r1, r9
	strh r0, [r1, #0x00]
	mov r0, r10
	strh r5, [r0, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08016CAC
_08016CAC: .4byte 0x0000EA60
	thumb_func_start sub_08016CB0
sub_08016CB0:
	push {r4, r5, r6, r7, lr}
	ldr r2, _08016CEC @ =0x083FECB8
	ldr r0, _08016CF0 @ =0x020020CC
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x03
	adds r1, r0, r2
	ldr r7, [r1, #0x00]
	adds r2, #0x04
	adds r0, r0, r2
	ldr r6, [r0, #0x00]
	ldr r4, _08016CF4 @ =0x0202A6E0
	movs r5, #0x00
	.global _08016CC8
_08016CC8:
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	bl sub_08016C30
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r1, r4, r2
	str r0, [r1, #0x00]
	adds r5, #0x01
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r4, r4, r0
	cmp r5, #0x17
	bne _08016CC8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08016CEC
_08016CEC: .4byte 0x083FECB8
	.global _08016CF0
_08016CF0: .4byte 0x020020CC
	.global _08016CF4
_08016CF4: .4byte 0x0202A6E0
	.byte 0x00, 0xB5, 0xEB, 0xF7, 0x7F, 0xFC, 0x00, 0x06, 0xC0, 0x0D, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
