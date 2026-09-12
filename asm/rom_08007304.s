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
	thumb_func_start sub_08007304
sub_08007304:
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	movs r3, #0x00
	cmp r3, r5
	beq _08007336
	ldr r0, _0800733C @ =0x0000FFFF
	mov r12, r0
	movs r4, #0x00
	ldr r6, _08007340 @ =0x06010000
	.global _08007316
_08007316:
	mov r7, r12
	str r7, [r2, #0x08]
	str r4, [r2, #0x00]
	strb r4, [r2, #0x04]
	ldrh r0, [r1, #0x00]
	str r0, [r2, #0x10]
	ldrh r7, [r1, #0x00]
	lsls r0, r7, #0x05
	adds r0, r0, r6
	str r0, [r2, #0x0C]
	strb r4, [r2, #0x06]
	adds r3, #0x01
	adds r2, #0x14
	adds r1, #0x02
	cmp r3, r5
	bne _08007316
	.global _08007336
_08007336:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800733C
_0800733C: .4byte 0x0000FFFF
	.global _08007340
_08007340: .4byte 0x06010000
	thumb_func_start sub_08007344
sub_08007344:
	push {r4, r5, r6, lr}
	ldr r1, _080073A0 @ =0x083671F0
	ldr r2, _080073A4 @ =0x02025DB0
	movs r0, #0x04
	bl sub_08007304
	ldr r1, _080073A8 @ =0x083671F8
	ldr r2, _080073AC @ =0x02025400
	movs r0, #0x18
	bl sub_08007304
	ldr r1, _080073B0 @ =0x08367228
	ldr r2, _080073B4 @ =0x020255E0
	movs r0, #0x20
	bl sub_08007304
	ldr r1, _080073B8 @ =0x08367268
	ldr r2, _080073BC @ =0x02025AE0
	movs r0, #0x14
	bl sub_08007304
	ldr r1, _080073C0 @ =0x08367290
	ldr r2, _080073C4 @ =0x02025C70
	movs r0, #0x10
	bl sub_08007304
	ldr r1, _080073C8 @ =0x083672B0
	ldr r2, _080073CC @ =0x02025860
	movs r0, #0x20
	bl sub_08007304
	movs r6, #0x00
	ldr r5, _080073D0 @ =0x05000200
	ldr r4, _080073D4 @ =0x02025E00
	.global _08007388
_08007388:
	adds r0, r4, #0x0
	bl sub_080072F4
	str r5, [r4, #0x08]
	adds r5, #0x20
	adds r4, #0x0C
	adds r6, #0x01
	cmp r6, #0x10
	bne _08007388
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _080073A0
_080073A0: .4byte 0x083671F0
	.global _080073A4
_080073A4: .4byte 0x02025DB0
	.global _080073A8
_080073A8: .4byte 0x083671F8
	.global _080073AC
_080073AC: .4byte 0x02025400
	.global _080073B0
_080073B0: .4byte 0x08367228
	.global _080073B4
_080073B4: .4byte 0x020255E0
	.global _080073B8
_080073B8: .4byte 0x08367268
	.global _080073BC
_080073BC: .4byte 0x02025AE0
	.global _080073C0
_080073C0: .4byte 0x08367290
	.global _080073C4
_080073C4: .4byte 0x02025C70
	.global _080073C8
_080073C8: .4byte 0x083672B0
	.global _080073CC
_080073CC: .4byte 0x02025860
	.global _080073D0
_080073D0: .4byte 0x05000200
	.global _080073D4
_080073D4: .4byte 0x02025E00
