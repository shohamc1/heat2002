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
	thumb_func_start sub_08016888
sub_08016888:
	push {r4, lr}
	bl sub_08010074
	movs r0, #0x10
	movs r1, #0x30
	bl sub_080165E0
	ldr r3, _08016910 @ =0x0202F050
	movs r2, #0x00
	ldr r4, _08016914 @ =0x0202EF80
	.global _0801689C
_0801689C:
	adds r1, r2, r4
	ldrb r0, [r3, #0x00]
	strb r0, [r1, #0x00]
	adds r3, #0x01
	adds r2, #0x01
	cmp r2, #0x0A
	bne _0801689C
	movs r2, #0x00
	ldr r4, _08016918 @ =0x0202EF08
	.global _080168AE
_080168AE:
	adds r1, r2, r4
	ldrb r0, [r3, #0x00]
	strb r0, [r1, #0x00]
	adds r3, #0x01
	adds r2, #0x01
	cmp r2, #0x04
	bne _080168AE
	movs r2, #0x00
	ldr r4, _0801691C @ =0x0202EF60
	.global _080168C0
_080168C0:
	adds r1, r2, r4
	ldrb r0, [r3, #0x00]
	strb r0, [r1, #0x00]
	adds r3, #0x01
	adds r2, #0x01
	cmp r2, #0x10
	bne _080168C0
	movs r2, #0x00
	ldr r4, _08016920 @ =0x0202EEC0
	.global _080168D2
_080168D2:
	adds r1, r2, r4
	ldrb r0, [r3, #0x00]
	strb r0, [r1, #0x00]
	adds r3, #0x01
	adds r2, #0x01
	cmp r2, #0x08
	bne _080168D2
	movs r2, #0x00
	ldr r4, _08016924 @ =0x0202EDC8
	.global _080168E4
_080168E4:
	adds r1, r2, r4
	ldrb r0, [r3, #0x00]
	strb r0, [r1, #0x00]
	adds r3, #0x01
	adds r2, #0x01
	cmp r2, #0x04
	bne _080168E4
	movs r2, #0x00
	ldr r4, _08016928 @ =0x0202ED80
	.global _080168F6
_080168F6:
	adds r1, r2, r4
	ldrb r0, [r3, #0x00]
	strb r0, [r1, #0x00]
	adds r3, #0x01
	adds r2, #0x01
	cmp r2, #0x04
	bne _080168F6
	bl sub_080100B0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08016910
_08016910: .4byte 0x0202F050
	.global _08016914
_08016914: .4byte 0x0202EF80
	.global _08016918
_08016918: .4byte 0x0202EF08
	.global _0801691C
_0801691C: .4byte 0x0202EF60
	.global _08016920
_08016920: .4byte 0x0202EEC0
	.global _08016924
_08016924: .4byte 0x0202EDC8
	.global _08016928
_08016928: .4byte 0x0202ED80
	thumb_func_start sub_0801692C
sub_0801692C:
	push {lr}
	bl sub_08010074
	ldr r2, _080169B0 @ =0x0202F050
	movs r1, #0x00
	ldr r3, _080169B4 @ =0x0202EF80
	.global _08016938
_08016938:
	adds r0, r1, r3
	ldrb r0, [r0, #0x00]
	strb r0, [r2, #0x00]
	adds r2, #0x01
	adds r1, #0x01
	cmp r1, #0x0A
	bne _08016938
	movs r1, #0x00
	ldr r3, _080169B8 @ =0x0202EF08
	.global _0801694A
_0801694A:
	adds r0, r1, r3
	ldrb r0, [r0, #0x00]
	strb r0, [r2, #0x00]
	adds r2, #0x01
	adds r1, #0x01
	cmp r1, #0x04
	bne _0801694A
	movs r1, #0x00
	ldr r3, _080169BC @ =0x0202EF60
	.global _0801695C
_0801695C:
	adds r0, r1, r3
	ldrb r0, [r0, #0x00]
	strb r0, [r2, #0x00]
	adds r2, #0x01
	adds r1, #0x01
	cmp r1, #0x10
	bne _0801695C
	movs r1, #0x00
	ldr r3, _080169C0 @ =0x0202EEC0
	.global _0801696E
_0801696E:
	adds r0, r1, r3
	ldrb r0, [r0, #0x00]
	strb r0, [r2, #0x00]
	adds r2, #0x01
	adds r1, #0x01
	cmp r1, #0x08
	bne _0801696E
	movs r1, #0x00
	ldr r3, _080169C4 @ =0x0202EDC8
	.global _08016980
_08016980:
	adds r0, r1, r3
	ldrb r0, [r0, #0x00]
	strb r0, [r2, #0x00]
	adds r2, #0x01
	adds r1, #0x01
	cmp r1, #0x04
	bne _08016980
	movs r1, #0x00
	ldr r3, _080169C8 @ =0x0202ED80
	.global _08016992
_08016992:
	adds r0, r1, r3
	ldrb r0, [r0, #0x00]
	strb r0, [r2, #0x00]
	adds r2, #0x01
	adds r1, #0x01
	cmp r1, #0x04
	bne _08016992
	movs r0, #0x10
	movs r1, #0x30
	bl sub_0801659C
	bl sub_080100B0
	pop {r0}
	bx r0
	.global _080169B0
_080169B0: .4byte 0x0202F050
	.global _080169B4
_080169B4: .4byte 0x0202EF80
	.global _080169B8
_080169B8: .4byte 0x0202EF08
	.global _080169BC
_080169BC: .4byte 0x0202EF60
	.global _080169C0
_080169C0: .4byte 0x0202EEC0
	.global _080169C4
_080169C4: .4byte 0x0202EDC8
	.global _080169C8
_080169C8: .4byte 0x0202ED80
