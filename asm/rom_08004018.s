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
	thumb_func_start sub_08004018
sub_08004018:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0x0
	mov r9, r1
	movs r0, #0x00
	mov r10, r0
	ldr r1, _080040D0 @ =0x02022E20
	mov r8, r1
	ldr r7, _080040D4 @ =0x02023A20
	.global _08004030
_08004030:
	mov r0, r9
	ldrh r2, [r0, #0x00]
	movs r1, #0x02
	add r9, r1
	adds r4, r2, #0x0
	movs r0, #0x1F
	ands r2, r0
	asrs r5, r4, #0x05
	ands r5, r0
	asrs r4, r4, #0x0A
	ands r4, r0
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r2, r0, #0x01
	cmp r2, #0x1F
	ble _08004056
	movs r2, #0x1F
	.global _08004056
_08004056:
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r5, r0, #0x01
	cmp r5, #0x1F
	ble _08004066
	movs r5, #0x1F
	.global _08004066
_08004066:
	lsls r0, r4, #0x01
	adds r0, r0, r4
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r4, r0, #0x01
	cmp r4, #0x1F
	ble _08004076
	movs r4, #0x1F
	.global _08004076
_08004076:
	lsls r2, r2, #0x10
	lsls r5, r5, #0x10
	lsls r4, r4, #0x10
	mov r1, r8
	ldr r0, [r1, #0x00]
	subs r0, r2, r0
	adds r1, r6, #0x0
	bl sub_08017230
	str r0, [r7, #0x00]
	mov r1, r8
	ldr r0, [r1, #0x04]
	subs r0, r5, r0
	adds r1, r6, #0x0
	bl sub_08017230
	str r0, [r7, #0x04]
	mov r1, r8
	ldr r0, [r1, #0x08]
	subs r0, r4, r0
	adds r1, r6, #0x0
	bl sub_08017230
	str r0, [r7, #0x08]
	movs r0, #0x0C
	add r8, r0
	adds r7, #0x0C
	movs r1, #0x01
	add r10, r1
	adds r0, #0xF4
	cmp r10, r0
	bne _08004030
	ldr r0, _080040D8 @ =0x02022E18
	strh r6, [r0, #0x00]
	movs r0, #0x01
	ldr r1, _080040DC @ =0x02022E14
	strb r0, [r1, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _080040D0
_080040D0: .4byte 0x02022E20
	.global _080040D4
_080040D4: .4byte 0x02023A20
	.global _080040D8
_080040D8: .4byte 0x02022E18
	.global _080040DC
_080040DC: .4byte 0x02022E14
