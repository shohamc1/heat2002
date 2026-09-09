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
	thumb_func_start sub_08016724
sub_08016724:
	push {r4, r5, r6, r7, lr}
	bl sub_08010074
	movs r0, #0x40
	movs r1, #0xF0
	bl sub_080165E0
	ldr r2, _080167BC @ =0x0202F080
	ldr r1, _080167C0 @ =0x0202F020
	ldrh r0, [r2, #0x00]
	strb r0, [r1, #0x00]
	adds r2, #0x02
	ldr r1, _080167C4 @ =0x0202F024
	ldrh r3, [r2, #0x00]
	lsrs r0, r3, #0x08
	strb r0, [r1, #0x00]
	ldr r1, _080167C8 @ =0x0202EEC8
	ldrh r0, [r2, #0x00]
	strb r0, [r1, #0x00]
	adds r2, #0x02
	ldr r1, _080167CC @ =0x0202F034
	ldrh r0, [r2, #0x00]
	strb r0, [r1, #0x00]
	adds r2, #0x02
	ldr r1, _080167D0 @ =0x0202EDD8
	ldrh r0, [r2, #0x00]
	strb r0, [r1, #0x00]
	adds r2, #0x02
	ldr r4, _080167D4 @ =0x0202A550
	movs r3, #0x00
	movs r6, #0xB1
	lsls r6, r6, #0x01
	movs r5, #0xB2
	lsls r5, r5, #0x01
	.global _08016768
_08016768:
	ldrh r1, [r2, #0x00]
	adds r0, r4, r6
	strb r1, [r0, #0x00]
	adds r2, #0x02
	ldrh r1, [r2, #0x00]
	adds r0, r4, r5
	strh r1, [r0, #0x00]
	adds r2, #0x02
	movs r7, #0xB6
	lsls r7, r7, #0x01
	adds r1, r4, r7
	ldrh r7, [r2, #0x00]
	lsls r0, r7, #0x10
	adds r2, #0x02
	ldrh r7, [r2, #0x00]
	orrs r0, r7
	str r0, [r1, #0x00]
	adds r2, #0x02
	adds r3, #0x01
	movs r0, #0xC8
	lsls r0, r0, #0x01
	adds r4, r4, r0
	cmp r3, #0x18
	bne _08016768
	movs r3, #0x00
	ldr r5, _080167D8 @ =0x0202EF10
	ldr r4, _080167DC @ =0x0202EF20
	.global _0801679E
_0801679E:
	adds r1, r3, r4
	ldrh r0, [r2, #0x00]
	strb r0, [r1, #0x00]
	adds r2, #0x02
	adds r3, #0x01
	cmp r3, #0x11
	bne _0801679E
	ldrh r0, [r2, #0x00]
	strb r0, [r5, #0x00]
	bl sub_080100B0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _080167BC
_080167BC: .4byte 0x0202F080
	.global _080167C0
_080167C0: .4byte 0x0202F020
	.global _080167C4
_080167C4: .4byte 0x0202F024
	.global _080167C8
_080167C8: .4byte 0x0202EEC8
	.global _080167CC
_080167CC: .4byte 0x0202F034
	.global _080167D0
_080167D0: .4byte 0x0202EDD8
	.global _080167D4
_080167D4: .4byte 0x0202A550
	.global _080167D8
_080167D8: .4byte 0x0202EF10
	.global _080167DC
_080167DC: .4byte 0x0202EF20
	thumb_func_start sub_080167E0
sub_080167E0:
	push {r4, r5, lr}
	bl sub_08010074
	movs r0, #0x98
	lsls r0, r0, #0x01
	movs r1, #0x48
	bl sub_080165E0
	ldr r1, _08016824 @ =0x0202F170
	movs r5, #0x00
	ldr r4, _08016828 @ =0x020253A0
	ldr r3, _0801682C @ =0x02025200
	ldr r2, _08016830 @ =0x02025380
	.global _080167FA
_080167FA:
	ldrh r0, [r1, #0x00]
	strh r0, [r2, #0x00]
	adds r1, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r3, #0x00]
	adds r1, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r1, #0x02
	adds r4, #0x02
	adds r3, #0x02
	adds r2, #0x02
	adds r5, #0x01
	cmp r5, #0x0C
	bne _080167FA
	bl sub_080100B0
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08016824
_08016824: .4byte 0x0202F170
	.global _08016828
_08016828: .4byte 0x020253A0
	.global _0801682C
_0801682C: .4byte 0x02025200
	.global _08016830
_08016830: .4byte 0x02025380
	thumb_func_start sub_08016834
sub_08016834:
	push {r4, r5, lr}
	bl sub_08010074
	ldr r1, _08016878 @ =0x0202F170
	movs r5, #0x00
	ldr r4, _0801687C @ =0x020253A0
	ldr r3, _08016880 @ =0x02025200
	ldr r2, _08016884 @ =0x02025380
	.global _08016844
_08016844:
	ldrh r0, [r2, #0x00]
	strh r0, [r1, #0x00]
	adds r1, #0x02
	ldrh r0, [r3, #0x00]
	strh r0, [r1, #0x00]
	adds r1, #0x02
	ldrh r0, [r4, #0x00]
	strh r0, [r1, #0x00]
	adds r1, #0x02
	adds r4, #0x02
	adds r3, #0x02
	adds r2, #0x02
	adds r5, #0x01
	cmp r5, #0x0C
	bne _08016844
	movs r0, #0x98
	lsls r0, r0, #0x01
	movs r1, #0x48
	bl sub_0801659C
	bl sub_080100B0
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08016878
_08016878: .4byte 0x0202F170
	.global _0801687C
_0801687C: .4byte 0x020253A0
	.global _08016880
_08016880: .4byte 0x02025200
	.global _08016884
_08016884: .4byte 0x02025380
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
