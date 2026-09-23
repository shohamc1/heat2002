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
	thumb_func_start sub_0833DAD8
sub_0833DAD8:
	push {r4, r5, r6, lr}
	movs r2, #0x00
	movs r1, #0x00
	ldr r0, _0833DB14 @ =0x020390BC
	ldrb r0, [r0, #0x00]
	ldr r6, _0833DB18 @ =0x0203B6FC
	ldr r5, _0833DB1C @ =0x0203B848
	cmp r2, r0
	beq _0833DB00
	ldr r4, _0833DB20 @ =0x020390B0
	adds r3, r0, #0x0
_0833DAEE:
	lsls r0, r1, #0x01
	adds r0, r0, r4
	ldrh r0, [r0, #0x00]
	orrs r2, r0
	adds r0, r1, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r3
	bne _0833DAEE
_0833DB00:
	adds r0, r2, #0x0
	ldrh r1, [r5, #0x00]
	bics r0, r1
	strh r0, [r6, #0x00]
	strh r2, [r5, #0x00]
	ldrh r0, [r6, #0x00]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_0833DB14: .4byte 0x020390BC
_0833DB18: .4byte 0x0203B6FC
_0833DB1C: .4byte 0x0203B848
_0833DB20: .4byte 0x020390B0
	thumb_func_start sub_0833DB24
sub_0833DB24:
	push {r4, r5, r6, r7, lr}
	ldr r4, _0833DB68 @ =0xFFFFFE00
	add sp, r4
	ldr r4, _0833DB6C @ =0x0203B6F4
	movs r0, #0x00
	strb r0, [r4, #0x00]
	bl sub_08339B4C
	ldr r7, _0833DB70 @ =0x0203761C
	adds r6, r4, #0x0
	ldr r5, _0833DB74 @ =0x0203B82C
_0833DB3A:
	movs r0, #0xC0
	ldrh r1, [r7, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _0833DB4C
	movs r0, #0x01
	ldrb r1, [r6, #0x00]
	eors r0, r1
	strb r0, [r6, #0x00]
_0833DB4C:
	ldrh r1, [r7, #0x00]
	movs r0, #0x08
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _0833DB78
	movs r0, #0x00
	strb r0, [r5, #0x00]
	movs r0, #0x03
	bl sub_0833DA2C
	movs r0, #0x00
	b _0833DBBC
_0833DB68: .4byte 0xFFFFFE00
_0833DB6C: .4byte 0x0203B6F4
_0833DB70: .4byte 0x0203761C
_0833DB74: .4byte 0x0203B82C
_0833DB78:
	movs r4, #0x01
	ands r4, r1
	cmp r4, #0x00
	beq _0833DB92
	strb r0, [r5, #0x00]
	movs r0, #0x03
	bl sub_0833DA2C
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0833DBBC
_0833DB92:
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	bne _0833DBB0
	ldrb r0, [r6, #0x00]
	bl sub_0833DA2C
	bl sub_08339B18
	ldrb r0, [r5, #0x00]
	adds r0, #0x01
	strb r0, [r5, #0x00]
	bl sub_08339B4C
	b _0833DB3A
_0833DBB0:
	strb r4, [r5, #0x00]
	movs r0, #0x03
	bl sub_0833DA2C
	strb r4, [r6, #0x00]
	movs r0, #0x01
_0833DBBC:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
