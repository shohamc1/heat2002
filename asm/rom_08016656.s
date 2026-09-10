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
	thumb_func_start sub_08016658
sub_08016658:
	push {r4, r5, r6, r7, lr}
	bl sub_08010074
	ldr r2, _08016700 @ =0x0202F04A
	movs r0, #0x01
	strh r0, [r2, #0x00]
	adds r2, #0x36
	ldr r0, _08016704 @ =0x0202F020
	ldrb r0, [r0, #0x00]
	strh r0, [r2, #0x00]
	adds r2, #0x02
	ldr r0, _08016708 @ =0x0202F024
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x08
	ldr r1, _0801670C @ =0x0202EEC8
	ldrb r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r2, #0x00]
	adds r2, #0x02
	ldr r0, _08016710 @ =0x0202F034
	ldrb r0, [r0, #0x00]
	strh r0, [r2, #0x00]
	adds r2, #0x02
	ldr r0, _08016714 @ =0x0202EDD8
	ldrb r0, [r0, #0x00]
	strh r0, [r2, #0x00]
	adds r2, #0x02
	ldr r4, _08016718 @ =0x0202A550
	movs r3, #0x00
	movs r0, #0xB1
	lsls r0, r0, #0x01
	mov r12, r0
	movs r7, #0xB2
	lsls r7, r7, #0x01
	movs r6, #0xB6
	lsls r6, r6, #0x01
	movs r5, #0xC8
	lsls r5, r5, #0x01
	.global _080166A4
_080166A4:
	mov r1, r12
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	strh r0, [r2, #0x00]
	adds r2, #0x02
	adds r0, r4, r7
	ldrh r0, [r0, #0x00]
	strh r0, [r2, #0x00]
	adds r2, #0x02
	adds r0, r4, r6
	ldr r1, [r0, #0x00]
	lsrs r0, r1, #0x10
	strh r0, [r2, #0x00]
	adds r2, #0x02
	strh r1, [r2, #0x00]
	adds r2, #0x02
	adds r3, #0x01
	adds r4, r4, r5
	cmp r3, #0x18
	bne _080166A4
	movs r3, #0x00
	ldr r4, _0801671C @ =0x0202EF10
	ldr r1, _08016720 @ =0x0202EF20
	.global _080166D2
_080166D2:
	adds r0, r3, r1
	ldrb r0, [r0, #0x00]
	strh r0, [r2, #0x00]
	adds r2, #0x02
	adds r3, #0x01
	cmp r3, #0x11
	bne _080166D2
	ldrb r0, [r4, #0x00]
	strh r0, [r2, #0x00]
	movs r0, #0x40
	movs r1, #0xF0
	bl sub_0801659C
	movs r0, #0x08
	movs r1, #0x08
	bl sub_0801659C
	bl sub_080100B0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08016700
_08016700: .4byte 0x0202F04A
	.global _08016704
_08016704: .4byte 0x0202F020
	.global _08016708
_08016708: .4byte 0x0202F024
	.global _0801670C
_0801670C: .4byte 0x0202EEC8
	.global _08016710
_08016710: .4byte 0x0202F034
	.global _08016714
_08016714: .4byte 0x0202EDD8
	.global _08016718
_08016718: .4byte 0x0202A550
	.global _0801671C
_0801671C: .4byte 0x0202EF10
	.global _08016720
_08016720: .4byte 0x0202EF20
