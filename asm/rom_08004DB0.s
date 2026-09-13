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
	.byte 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_08004DB4
sub_08004DB4:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r4, _08004E10 @ =0x020253C4
	ldrb r0, [r4, #0x00]
	cmp r0, #0xFF
	bne _08004E24
	movs r3, #0x00
	movs r2, #0x00
	ldr r0, _08004E14 @ =0x020020AC
	ldrb r0, [r0, #0x00]
	ldr r1, _08004E18 @ =0x02025258
	mov r8, r1
	ldr r7, _08004E1C @ =0x020253BC
	mov r12, r7
	cmp r3, r0
	beq _08004DFC
	ldr r6, _08004E20 @ =0x020020A0
	movs r1, #0x08
	mov r9, r1
	adds r5, r0, #0x0
	.global _08004DE0
_08004DE0:
	lsls r0, r2, #0x01
	adds r1, r0, r6
	mov r0, r9
	ldrh r7, [r1, #0x00]
	ands r0, r7
	cmp r0, #0x00
	beq _08004DF2
	strb r2, [r4, #0x00]
	ldrh r3, [r1, #0x00]
	.global _08004DF2
_08004DF2:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r5
	bne _08004DE0
	.global _08004DFC
_08004DFC:
	adds r0, r3, #0x0
	mov r1, r12
	ldrh r1, [r1, #0x00]
	bics r0, r1
	mov r2, r8
	strh r0, [r2, #0x00]
	mov r4, r12
	strh r3, [r4, #0x00]
	b _08004E3C
	.byte 0x00, 0x00
	.global _08004E10
_08004E10: .4byte 0x020253C4
	.global _08004E14
_08004E14: .4byte 0x020020AC
	.global _08004E18
_08004E18: .4byte 0x02025258
	.global _08004E1C
_08004E1C: .4byte 0x020253BC
	.global _08004E20
_08004E20: .4byte 0x020020A0
	.global _08004E24
_08004E24:
	ldr r1, _08004E4C @ =0x020020A0
	ldrb r4, [r4, #0x00]
	lsls r0, r4, #0x01
	adds r0, r0, r1
	ldrh r3, [r0, #0x00]
	ldr r2, _08004E50 @ =0x02025258
	ldr r1, _08004E54 @ =0x020253BC
	adds r0, r3, #0x0
	ldrh r7, [r1, #0x00]
	bics r0, r7
	strh r0, [r2, #0x00]
	strh r3, [r1, #0x00]
	.global _08004E3C
_08004E3C:
	ldrh r0, [r2, #0x00]
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08004E4C
_08004E4C: .4byte 0x020020A0
	.global _08004E50
_08004E50: .4byte 0x02025258
	.global _08004E54
_08004E54: .4byte 0x020253BC
	.byte 0x70, 0xB5, 0x00, 0x22, 0x00, 0x21, 0x0D, 0x48, 0x00, 0x78, 0x0D, 0x4E, 0x0D, 0x4D, 0x82, 0x42
	.byte 0x0A, 0xD0, 0x0D, 0x4C, 0x03, 0x1C, 0x48, 0x00, 0x00, 0x19, 0x00, 0x88, 0x02, 0x43, 0x48, 0x1C
	.byte 0x00, 0x04, 0x01, 0x0C, 0x99, 0x42, 0xF6, 0xD1, 0x10, 0x1C, 0x29, 0x88, 0x88, 0x43, 0x30, 0x80
	.byte 0x2A, 0x80, 0x30, 0x88, 0x70, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0xAC, 0x20, 0x00, 0x02
	.byte 0x58, 0x52, 0x02, 0x02, 0xBC, 0x53, 0x02, 0x02, 0xA0, 0x20, 0x00, 0x02
	thumb_func_start sub_08004EA4
sub_08004EA4:
	push {r4, r5, r6, r7, lr}
	ldr r4, _08004EE8 @ =0xFFFFFE00
	add sp, r4
	ldr r4, _08004EEC @ =0x02025248
	movs r0, #0x00
	strb r0, [r4, #0x00]
	bl sub_0800048C
	ldr r7, _08004EF0 @ =0x020005CC
	adds r6, r4, #0x0
	ldr r5, _08004EF4 @ =0x0202539C
	.global _08004EBA
_08004EBA:
	movs r0, #0xC0
	ldrh r1, [r7, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08004ECC
	movs r0, #0x01
	ldrb r1, [r6, #0x00]
	eors r0, r1
	strb r0, [r6, #0x00]
	.global _08004ECC
_08004ECC:
	ldrh r1, [r7, #0x00]
	movs r0, #0x08
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _08004EF8
	movs r0, #0x00
	strb r0, [r5, #0x00]
	movs r0, #0x03
	bl sub_08004D1C
	movs r0, #0x00
	b _08004F3C
	.global _08004EE8
_08004EE8: .4byte 0xFFFFFE00
	.global _08004EEC
_08004EEC: .4byte 0x02025248
	.global _08004EF0
_08004EF0: .4byte 0x020005CC
	.global _08004EF4
_08004EF4: .4byte 0x0202539C
	.global _08004EF8
_08004EF8:
	movs r4, #0x01
	ands r4, r1
	cmp r4, #0x00
	beq _08004F12
	strb r0, [r5, #0x00]
	movs r0, #0x03
	bl sub_08004D1C
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _08004F3C
	.global _08004F12
_08004F12:
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	bne _08004F30
	ldrb r0, [r6, #0x00]
	bl sub_08004D1C
	bl sub_08000458
	ldrb r0, [r5, #0x00]
	adds r0, #0x01
	strb r0, [r5, #0x00]
	bl sub_0800048C
	b _08004EBA
	.global _08004F30
_08004F30:
	strb r4, [r5, #0x00]
	movs r0, #0x03
	bl sub_08004D1C
	strb r4, [r6, #0x00]
	movs r0, #0x01
	.global _08004F3C
_08004F3C:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start sub_08004F48
sub_08004F48:
	push {r4, r5, r6, r7, lr}
	ldr r4, _08004FA8 @ =0xFFFFFE00
	add sp, r4
	ldr r5, _08004FAC @ =0x02025248
	movs r0, #0x00
	strb r0, [r5, #0x00]
	ldr r4, _08004FB0 @ =0x020005CC
	movs r0, #0x08
	ldrh r1, [r4, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08005016
	bl sub_08007EF8
	bl sub_08004A18
	bl sub_08010094
	bl sub_0800048C
	adds r7, r4, #0x0
	adds r6, r5, #0x0
	ldr r5, _08004FB4 @ =0x0202539C
	.global _08004F76
_08004F76:
	movs r0, #0xC0
	ldrh r1, [r7, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08004F88
	movs r0, #0x01
	ldrb r1, [r6, #0x00]
	eors r0, r1
	strb r0, [r6, #0x00]
	.global _08004F88
_08004F88:
	ldrh r1, [r7, #0x00]
	movs r0, #0x08
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _08004FB8
	movs r0, #0x00
	strb r0, [r5, #0x00]
	movs r0, #0x03
	bl sub_08004C44
	bl sub_08004A18
	movs r0, #0x01
	b _08005018
	.global _08004FA8
_08004FA8: .4byte 0xFFFFFE00
	.global _08004FAC
_08004FAC: .4byte 0x02025248
	.global _08004FB0
_08004FB0: .4byte 0x020005CC
	.global _08004FB4
_08004FB4: .4byte 0x0202539C
	.global _08004FB8
_08004FB8:
	movs r4, #0x01
	ands r4, r1
	cmp r4, #0x00
	beq _08004FE0
	strb r0, [r5, #0x00]
	movs r0, #0x03
	bl sub_08004C44
	ldr r4, _08004FDC @ =0x02025248
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08004FD4
	bl sub_08004EA4
	.global _08004FD4
_08004FD4:
	bl sub_08004A18
	ldrb r0, [r4, #0x00]
	b _08004FF8
	.global _08004FDC
_08004FDC: .4byte 0x02025248
	.global _08004FE0
_08004FE0:
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _08005000
	strb r4, [r5, #0x00]
	movs r0, #0x03
	bl sub_08004C44
	strb r4, [r6, #0x00]
	bl sub_08004A18
	ldrb r0, [r6, #0x00]
	.global _08004FF8
_08004FF8:
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _08005018
	.global _08005000
_08005000:
	ldrb r0, [r6, #0x00]
	bl sub_08004C44
	bl sub_08000458
	ldrb r0, [r5, #0x00]
	adds r0, #0x01
	strb r0, [r5, #0x00]
	bl sub_0800048C
	b _08004F76
	.global _08005016
_08005016:
	movs r0, #0x00
	.global _08005018
_08005018:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start sub_08005024
sub_08005024:
	push {r4, r5, r6, r7, lr}
	ldr r4, _08005040 @ =0xFFFFFE00
	add sp, r4
	ldr r4, _08005044 @ =0x02025248
	movs r0, #0x00
	strb r0, [r4, #0x00]
	bl sub_0800048C
	bl sub_08004DB4
	adds r7, r4, #0x0
	ldr r6, _08005048 @ =0x0202539C
	b _080050D4
	.byte 0x00, 0x00
	.global _08005040
_08005040: .4byte 0xFFFFFE00
	.global _08005044
_08005044: .4byte 0x02025248
	.global _08005048
_08005048: .4byte 0x0202539C
	.global _0800504C
_0800504C:
	bl sub_08004DB4
	ldr r1, _08005080 @ =0x02025258
	movs r0, #0xC0
	ldrh r2, [r1, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _08005064
	movs r0, #0x01
	ldrb r2, [r7, #0x00]
	eors r0, r2
	strb r0, [r7, #0x00]
	.global _08005064
_08005064:
	ldrh r1, [r1, #0x00]
	movs r0, #0x08
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _08005084
	strb r5, [r6, #0x00]
	movs r0, #0x03
	bl sub_08004D1C
	movs r0, #0x00
	b _080050DE
	.byte 0x00, 0x00
	.global _08005080
_08005080: .4byte 0x02025258
	.global _08005084
_08005084:
	movs r5, #0x01
	ands r5, r1
	cmp r5, #0x00
	beq _0800509E
	strb r0, [r6, #0x00]
	movs r0, #0x03
	bl sub_08004D1C
	ldrb r0, [r7, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080050DE
	.global _0800509E
_0800509E:
	movs r0, #0x02
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x00
	beq _080050B8
	strb r5, [r6, #0x00]
	movs r0, #0x03
	bl sub_08004D1C
	strb r5, [r7, #0x00]
	movs r0, #0x01
	b _080050DE
	.global _080050B8
_080050B8:
	ldrb r0, [r7, #0x00]
	bl sub_08004D1C
	ldr r0, _080050EC @ =0x020020C0
	strb r4, [r0, #0x00]
	.global _080050C2
_080050C2:
	ldr r0, _080050EC @ =0x020020C0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080050C2
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	strb r0, [r6, #0x00]
	bl sub_0800048C
	.global _080050D4
_080050D4:
	bl sub_08003330
	adds r5, r0, #0x0
	cmp r5, #0x00
	beq _0800504C
	.global _080050DE
_080050DE:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _080050EC
_080050EC: .4byte 0x020020C0
	thumb_func_start sub_080050F0
sub_080050F0:
	push {r4, r5, r6, r7, lr}
	ldr r4, _0800511C @ =0xFFFFFE00
	add sp, r4
	ldr r1, _08005120 @ =0x020253C4
	movs r0, #0xFF
	strb r0, [r1, #0x00]
	ldr r4, _08005124 @ =0x02025248
	movs r0, #0x00
	strb r0, [r4, #0x00]
	bl sub_08004DB4
	ldr r1, _08005128 @ =0x02025258
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080051D0
	bl sub_08010094
	adds r7, r4, #0x0
	ldr r6, _0800512C @ =0x0202539C
	b _080051C6
	.global _0800511C
_0800511C: .4byte 0xFFFFFE00
	.global _08005120
_08005120: .4byte 0x020253C4
	.global _08005124
_08005124: .4byte 0x02025248
	.global _08005128
_08005128: .4byte 0x02025258
	.global _0800512C
_0800512C: .4byte 0x0202539C
	.global _08005130
_08005130:
	bl sub_08004DB4
	ldr r1, _08005164 @ =0x02025258
	movs r0, #0xC0
	ldrh r2, [r1, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _08005148
	movs r0, #0x01
	ldrb r2, [r7, #0x00]
	eors r0, r2
	strb r0, [r7, #0x00]
	.global _08005148
_08005148:
	ldrh r1, [r1, #0x00]
	movs r0, #0x08
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _08005168
	strb r4, [r6, #0x00]
	movs r0, #0x03
	bl sub_08004C44
	movs r0, #0x01
	b _080051D2
	.byte 0x00, 0x00
	.global _08005164
_08005164: .4byte 0x02025258
	.global _08005168
_08005168:
	movs r4, #0x01
	ands r4, r1
	cmp r4, #0x00
	beq _08005194
	strb r0, [r6, #0x00]
	movs r0, #0x03
	bl sub_08004C44
	ldr r4, _08005190 @ =0x02025248
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08005184
	bl sub_08005024
	.global _08005184
_08005184:
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080051D2
	.byte 0x00, 0x00
	.global _08005190
_08005190: .4byte 0x02025248
	.global _08005194
_08005194:
	movs r0, #0x02
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x00
	beq _080051AE
	strb r4, [r6, #0x00]
	movs r0, #0x03
	bl sub_08004C44
	strb r4, [r7, #0x00]
	movs r0, #0x01
	b _080051D2
	.global _080051AE
_080051AE:
	ldrb r0, [r7, #0x00]
	bl sub_08004C44
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	strb r0, [r6, #0x00]
	ldr r0, _080051E0 @ =0x020020C0
	strb r5, [r0, #0x00]
	.global _080051BE
_080051BE:
	ldr r0, _080051E0 @ =0x020020C0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080051BE
	.global _080051C6
_080051C6:
	bl sub_08003330
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _08005130
	.global _080051D0
_080051D0:
	movs r0, #0x00
	.global _080051D2
_080051D2:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _080051E0
_080051E0: .4byte 0x020020C0
	thumb_func_start sub_080051E4
sub_080051E4:
	push {lr}
	movs r0, #0x96
	bl sub_08016558
	movs r1, #0x08
	movs r2, #0x01
	bl sub_08006418
	ldr r0, _08005208 @ =0x020253C4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _08005220
	cmp r0, #0x01
	bgt _0800520C
	cmp r0, #0x00
	beq _08005216
	b _08005242
	.byte 0x00, 0x00
	.global _08005208
_08005208: .4byte 0x020253C4
	.global _0800520C
_0800520C:
	cmp r0, #0x02
	beq _08005228
	cmp r0, #0x03
	beq _08005238
	b _08005242
	.global _08005216
_08005216:
	ldr r0, _0800521C @ =0x0806C714
	b _0800522A
	.byte 0x00, 0x00
	.global _0800521C
_0800521C: .4byte 0x0806C714
	.global _08005220
_08005220:
	ldr r0, _08005224 @ =0x0806C720
	b _0800522A
	.global _08005224
_08005224: .4byte 0x0806C720
	.global _08005228
_08005228:
	ldr r0, _08005234 @ =0x0806C72C
	.global _0800522A
_0800522A:
	movs r1, #0x09
	movs r2, #0x01
	bl sub_08006418
	b _08005242
	.global _08005234
_08005234: .4byte 0x0806C72C
	.global _08005238
_08005238:
	ldr r0, _08005248 @ =0x0806C738
	movs r1, #0x09
	movs r2, #0x01
	bl sub_08006418
	.global _08005242
_08005242:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08005248
_08005248: .4byte 0x0806C738
