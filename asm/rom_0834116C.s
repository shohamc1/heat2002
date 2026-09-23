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
	thumb_func_start sub_0834116C
sub_0834116C:
	push {lr}
	ldr r0, _0834117C @ =0x0200D0D8
	movs r1, #0x07
	movs r2, #0x0A
	bl sub_0833EF0C
	pop {r0}
	bx r0
_0834117C: .4byte 0x0200D0D8
	thumb_func_start sub_08341180
sub_08341180:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x02C
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _083411F8 @ =0x020251B8
	ldr r1, [r0, #0x00]
	movs r0, #0xA4
	lsls r0, r0, #0x02
	adds r5, r1, r0
	ldr r2, _083411FC @ =0x02022254
	ldr r3, _08341200 @ =0x02021594
	movs r4, #0xE6
	lsls r4, r4, #0x03
	adds r0, r3, r4
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r7, #0xE0
	lsls r7, r7, #0x08
	adds r4, r7, #0x0
	ldrh r0, [r0, #0x00]
	orrs r0, r4
	strh r0, [r5, #0x00]
	ldr r0, _08341204 @ =0x00000292
	adds r5, r1, r0
	movs r7, #0x00
	movs r1, #0x00
	mov r12, r1
	mov r10, r3
	ldr r0, _08341208 @ =0x00000742
	adds r0, r0, r3
	mov r9, r0
	ldr r1, _0834120C @ =0x00000732
	adds r1, r1, r3
	mov r8, r1
_083411CE:
	adds r0, r7, #0x7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0x0
	cmp r6, r1
	bls _083411EC
	mov r3, r9
	ldrh r3, [r3, #0x00]
	lsls r3, r3, #0x01
	str r3, [sp, #0x028]
	adds r0, r3, r2
	ldrh r0, [r0, #0x00]
	orrs r0, r4
	strh r0, [r5, #0x00]
	adds r5, #0x02
_083411EC:
	cmp r6, r7
	bcs _08341210
	mov r1, r8
	ldrh r1, [r1, #0x00]
	lsls r0, r1, #0x01
	b _08341224
_083411F8: .4byte 0x020251B8
_083411FC: .4byte 0x02022254
_08341200: .4byte 0x02021594
_08341204: .4byte 0x00000292
_08341208: .4byte 0x00000742
_0834120C: .4byte 0x00000732
_08341210:
	cmp r6, r1
	bhi _0834122E
	subs r0, r6, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	ldr r3, _08341270 @ =0x00000734
	adds r0, r0, r3
	add r0, r10
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
_08341224:
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	orrs r0, r4
	strh r0, [r5, #0x00]
	adds r5, #0x02
_0834122E:
	adds r0, r7, #0x0
	adds r0, #0x08
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r0, r12
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r12, r0
	cmp r0, #0x0C
	bne _083411CE
	ldr r4, _08341274 @ =0x02021594
	ldr r7, _08341278 @ =0x00000744
	adds r0, r4, r7
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	ldr r0, _0834127C @ =0x02022254
	adds r1, r1, r0
	movs r2, #0xE0
	lsls r2, r2, #0x08
	adds r0, r2, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r5, #0x00]
	add sp, #0x02C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08341270: .4byte 0x00000734
_08341274: .4byte 0x02021594
_08341278: .4byte 0x00000744
_0834127C: .4byte 0x02022254
