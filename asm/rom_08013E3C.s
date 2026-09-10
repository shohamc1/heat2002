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
	thumb_func_start sub_08013E3C
sub_08013E3C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x038
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x030]
	lsls r4, r0, #0x04
	subs r4, r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _08013ED4 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x2F
	bl sub_08016558
	bl sub_080065A8
	lsls r4, r4, #0x02
	ldr r0, _08013ED8 @ =0x0202EFC0
	adds r4, r4, r0
	mov r9, r4
	movs r0, #0x00
	str r0, [sp, #0x034]
	mov r5, sp
	.global _08013E76
_08013E76:
	ldr r4, [sp, #0x034]
	adds r4, #0x04
	ldr r0, _08013EDC @ =0x0829F44C
	movs r1, #0x01
	adds r2, r4, #0x0
	movs r3, #0x01
	bl sub_080063BC
	ldr r0, _08013EE0 @ =0x0202F020
	adds r7, r4, #0x0
	cmp r9, r0
	bcc _08013E90
	b _08013F96
	.global _08013E90
_08013E90:
	mov r1, r9
	ldr r4, [r1, #0x00]
	movs r1, #0xB6
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	add r1, sp, #0x028
	mov r2, sp
	adds r2, #0x2A
	add r3, sp, #0x02C
	bl sub_08016C50
	ldr r0, _08013EE4 @ =0x0202A550
	add r6, sp, #0x028
	movs r1, #0x2A
	add r1, sp
	mov r8, r1
	add r1, sp, #0x02C
	mov r10, r1
	cmp r4, r0
	bne _08013EEC
	ldr r1, _08013EE8 @ =0x0202539C
	movs r0, #0x10
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08013EEC
	ldr r0, _08013EDC @ =0x0829F44C
	movs r1, #0x01
	adds r2, r7, #0x0
	movs r3, #0x01
	bl sub_080063BC
	b _08013F92
	.global _08013ED4
_08013ED4: .4byte 0x083FDE18
	.global _08013ED8
_08013ED8: .4byte 0x0202EFC0
	.global _08013EDC
_08013EDC: .4byte 0x0829F44C
	.global _08013EE0
_08013EE0: .4byte 0x0202F020
	.global _08013EE4
_08013EE4: .4byte 0x0202A550
	.global _08013EE8
_08013EE8: .4byte 0x0202539C
	.global _08013EEC
_08013EEC:
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	bl sub_0800F110
	movs r1, #0x01
	adds r2, r7, #0x0
	movs r3, #0x01
	bl sub_080063BC
	ldrh r0, [r6, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x00]
	ldrh r0, [r6, #0x00]
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x01]
	movs r0, #0x3A
	strb r0, [r5, #0x02]
	mov r1, r8
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x03]
	mov r1, r8
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x04]
	movs r0, #0x3A
	strb r0, [r5, #0x05]
	mov r1, r10
	ldrh r0, [r1, #0x00]
	movs r1, #0x64
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x06]
	mov r1, r10
	ldrh r0, [r1, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x07]
	movs r0, #0x00
	strb r0, [r5, #0x08]
	mov r0, sp
	movs r1, #0x14
	adds r2, r7, #0x0
	movs r3, #0x01
	bl sub_080063BC
	.global _08013F92
_08013F92:
	movs r1, #0x04
	add r9, r1
	.global _08013F96
_08013F96:
	ldr r0, [sp, #0x034]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x034]
	cmp r0, #0x0F
	beq _08013FA6
	b _08013E76
	.global _08013FA6
_08013FA6:
	ldr r1, _08013FBC @ =0x0202539C
	movs r0, #0x08
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08013FD8
	ldr r0, [sp, #0x030]
	cmp r0, #0x00
	bne _08013FC4
	ldr r0, _08013FC0 @ =0x0829F440
	b _08013FC6
	.global _08013FBC
_08013FBC: .4byte 0x0202539C
	.global _08013FC0
_08013FC0: .4byte 0x0829F440
	.global _08013FC4
_08013FC4:
	ldr r0, _08013FD4 @ =0x0829F444
	.global _08013FC6
_08013FC6:
	movs r1, #0x1A
	movs r2, #0x13
	movs r3, #0x01
	bl sub_080063BC
	b _08013FE4
	.byte 0x00, 0x00
	.global _08013FD4
_08013FD4: .4byte 0x0829F444
	.global _08013FD8
_08013FD8:
	ldr r0, _08013FFC @ =0x0829F448
	movs r1, #0x1A
	movs r2, #0x13
	movs r3, #0x01
	bl sub_080063BC
	.global _08013FE4
_08013FE4:
	ldr r1, _08014000 @ =0x0202539C
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	add sp, #0x038
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08013FFC
_08013FFC: .4byte 0x0829F448
	.global _08014000
_08014000: .4byte 0x0202539C
	thumb_func_start sub_08014004
sub_08014004:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _080140CC @ =0xFFFFFE00
	add sp, r4
	movs r6, #0x00
	movs r4, #0x00
	bl sub_0800F3C0
	movs r0, #0x06
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_08013E3C
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r0, #0x40
	mov r8, r0
	ldr r7, _080140D0 @ =0x020005CC
	.global _08014032
_08014032:
	bl sub_0800048C
	adds r0, r6, #0x0
	bl sub_08013E3C
	ldrh r1, [r7, #0x00]
	movs r0, #0x01
	ands r0, r1
	lsls r4, r4, #0x18
	cmp r0, #0x00
	beq _0801404C
	lsrs r0, r4, #0x18
	mov r8, r0
	.global _0801404C
_0801404C:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0x00
	beq _08014068
	cmp r6, #0x01
	bne _08014068
	movs r6, #0x00
	ldr r0, _080140D4 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08014068
	movs r0, #0x08
	bl sub_08001208
	.global _08014068
_08014068:
	movs r0, #0x80
	ldrh r1, [r7, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08014086
	cmp r6, #0x00
	bne _08014086
	movs r6, #0x01
	ldr r0, _080140D4 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08014086
	movs r0, #0x08
	bl sub_08001208
	.global _08014086
_08014086:
	ldrh r0, [r7, #0x00]
	asrs r1, r4, #0x18
	movs r2, #0x00
	movs r3, #0x00
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_08000458
	mov r0, r8
	lsls r5, r0, #0x18
	cmp r0, #0x40
	beq _08014032
	ldr r0, _080140D4 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _080140B0
	movs r0, #0x09
	bl sub_08001208
	.global _080140B0
_080140B0:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r5, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _080140CC
_080140CC: .4byte 0xFFFFFE00
	.global _080140D0
_080140D0: .4byte 0x020005CC
	.global _080140D4
_080140D4: .4byte 0x0202EF00
