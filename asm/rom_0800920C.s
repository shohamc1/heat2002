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
	thumb_func_start sub_0800920C
sub_0800920C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x02C
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _08009284 @ =0x08364B08
	ldr r1, [r0, #0x00]
	movs r0, #0xA4
	lsls r0, r0, #0x02
	adds r5, r1, r0
	ldr r2, _08009288 @ =0x08335A8C
	ldr r3, _0800928C @ =0x08334DCC
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
	ldr r0, _08009290 @ =0x00000292
	adds r5, r1, r0
	movs r7, #0x00
	movs r1, #0x00
	mov r12, r1
	mov r10, r3
	ldr r0, _08009294 @ =0x00000742
	adds r0, r0, r3
	mov r9, r0
	ldr r1, _08009298 @ =0x00000732
	adds r1, r1, r3
	mov r8, r1
	.global _0800925A
_0800925A:
	adds r0, r7, #0x7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0x0
	cmp r6, r1
	bls _08009278
	mov r3, r9
	ldrh r3, [r3, #0x00]
	lsls r3, r3, #0x01
	str r3, [sp, #0x028]
	adds r0, r3, r2
	ldrh r0, [r0, #0x00]
	orrs r0, r4
	strh r0, [r5, #0x00]
	adds r5, #0x02
	.global _08009278
_08009278:
	cmp r6, r7
	bcs _0800929C
	mov r1, r8
	ldrh r1, [r1, #0x00]
	lsls r0, r1, #0x01
	b _080092B0
	.global _08009284
_08009284: .4byte 0x08364B08
	.global _08009288
_08009288: .4byte 0x08335A8C
	.global _0800928C
_0800928C: .4byte 0x08334DCC
	.global _08009290
_08009290: .4byte 0x00000292
	.global _08009294
_08009294: .4byte 0x00000742
	.global _08009298
_08009298: .4byte 0x00000732
	.global _0800929C
_0800929C:
	cmp r6, r1
	bhi _080092BA
	subs r0, r6, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	ldr r3, _080092FC @ =0x00000734
	adds r0, r0, r3
	add r0, r10
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
	.global _080092B0
_080092B0:
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	orrs r0, r4
	strh r0, [r5, #0x00]
	adds r5, #0x02
	.global _080092BA
_080092BA:
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
	bne _0800925A
	ldr r4, _08009300 @ =0x08334DCC
	ldr r7, _08009304 @ =0x00000744
	adds r0, r4, r7
	ldrh r0, [r0, #0x00]
	lsls r1, r0, #0x01
	ldr r0, _08009308 @ =0x08335A8C
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
	.global _080092FC
_080092FC: .4byte 0x00000734
	.global _08009300
_08009300: .4byte 0x08334DCC
	.global _08009304
_08009304: .4byte 0x00000744
	.global _08009308
_08009308: .4byte 0x08335A8C
