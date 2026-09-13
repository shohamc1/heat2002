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
	thumb_func_start sub_08009FA0
sub_08009FA0:
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, _08009FF8 @ =0x083681E8
	lsls r2, r2, #0x02
	adds r2, r2, r0
	ldr r4, [r2, #0x00]
	ldr r0, _08009FFC @ =0x0200209C
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x01
	movs r1, #0x07
	bl sub_080172C8
	lsls r0, r0, #0x02
	adds r4, r4, r0
	movs r0, #0xFF
	ands r6, r0
	ldr r0, _0800A000 @ =0x000001FF
	ands r0, r5
	lsls r0, r0, #0x10
	orrs r6, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r6, r0
	ldr r0, [r4, #0x00]
	bl sub_08007630
	cmp r0, #0x00
	beq _08009FF0
	ldr r4, [r0, #0x10]
	ldr r0, _0800A004 @ =0x08337C20
	bl sub_08007714
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	orrs r4, r0
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl sub_080044A4
	.global _08009FF0
_08009FF0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08009FF8
_08009FF8: .4byte 0x083681E8
	.global _08009FFC
_08009FFC: .4byte 0x0200209C
	.global _0800A000
_0800A000: .4byte 0x000001FF
	.global _0800A004
_0800A004: .4byte 0x08337C20
	.byte 0x10, 0xB5, 0x02, 0x9C, 0x8A, 0x42, 0x01, 0xDD, 0x20, 0x1C, 0x0B, 0xE0, 0x11, 0x1A, 0x00, 0x29
	.byte 0x07, 0xDB, 0x80, 0x20, 0xC0, 0x01, 0x40, 0x1A, 0x58, 0x43, 0x61, 0x43, 0x40, 0x18, 0x80, 0x13
	.byte 0x00, 0xE0, 0x18, 0x1C, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	thumb_func_start sub_0800A034
sub_0800A034:
	push {r4, r5, lr}
	movs r2, #0x00
	adds r0, #0xEC
	ldr r3, [r0, #0x00]
	ldr r5, _0800A06C @ =0xFFFFF82F
	ldr r4, _0800A070 @ =0x00002326
	.global _0800A040
_0800A040:
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	lsls r0, r2, #0x01
	adds r0, r0, r3
	ldrh r0, [r0, #0x00]
	negs r0, r0
	muls r0, r1
	asrs r0, r0, #0x08
	adds r0, r0, r5
	cmp r0, r4
	bls _0800A078
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x05
	bne _0800A040
	ldr r0, _0800A074 @ =0xFFFDB610
	cmp r1, r0
	bgt _0800A07C
	movs r0, #0x04
	b _0800A07E
	.global _0800A06C
_0800A06C: .4byte 0xFFFFF82F
	.global _0800A070
_0800A070: .4byte 0x00002326
	.global _0800A074
_0800A074: .4byte 0xFFFDB610
	.global _0800A078
_0800A078:
	adds r0, r2, #0x0
	b _0800A07E
	.global _0800A07C
_0800A07C:
	movs r0, #0x00
	.global _0800A07E
_0800A07E:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_start sub_0800A084
sub_0800A084:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x028
	adds r4, r0, #0x0
	mov r8, r1
	movs r7, #0x00
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0800A170
	ldr r0, _0800A114 @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A0BE
	ldr r1, _0800A118 @ =0x00000175
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800A0BE
	adds r1, r4, #0x0
	adds r1, #0x9C
	ldr r0, [r1, #0x00]
	subs r0, #0x0A
	str r0, [r1, #0x00]
	cmp r0, #0x00
	bge _0800A0BE
	str r7, [r1, #0x00]
	.global _0800A0BE
_0800A0BE:
	adds r0, r4, #0x0
	adds r0, #0xA2
	movs r1, #0x80
	lsls r1, r1, #0x01
	strh r1, [r0, #0x00]
	ldr r1, _0800A11C @ =0x0202A550
	mov r12, r0
	cmp r4, r1
	bne _0800A0E8
	subs r0, #0x06
	ldr r2, [r0, #0x00]
	cmp r2, #0x00
	bne _0800A0E8
	ldr r1, _0800A120 @ =0x0202A51C
	movs r0, #0x08
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _0800A0E8
	mov r3, r12
	strh r2, [r3, #0x00]
	.global _0800A0E8
_0800A0E8:
	ldr r0, _0800A124 @ =0x020020A8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A128
	adds r2, r4, #0x0
	adds r2, #0x3E
	movs r5, #0xE4
	adds r5, r5, r4
	mov r9, r5
	ldr r1, [r5, #0x00]
	ldrb r6, [r2, #0x00]
	lsls r0, r6, #0x01
	adds r0, r0, r1
	mov r1, r12
	ldrh r1, [r1, #0x00]
	ldrh r5, [r0, #0x00]
	adds r3, r1, #0x0
	muls r3, r5
	adds r0, r3, #0x0
	asrs r0, r0, #0x06
	b _0800A148
	.byte 0x00, 0x00
	.global _0800A114
_0800A114: .4byte 0x0202EEB0
	.global _0800A118
_0800A118: .4byte 0x00000175
	.global _0800A11C
_0800A11C: .4byte 0x0202A550
	.global _0800A120
_0800A120: .4byte 0x0202A51C
	.global _0800A124
_0800A124: .4byte 0x020020A8
	.global _0800A128
_0800A128:
	adds r2, r4, #0x0
	adds r2, #0x3E
	movs r6, #0xE4
	adds r6, r6, r4
	mov r9, r6
	ldr r1, [r6, #0x00]
	ldrb r3, [r2, #0x00]
	lsls r0, r3, #0x01
	adds r0, r0, r1
	mov r5, r12
	ldrh r5, [r5, #0x00]
	ldrh r1, [r0, #0x00]
	adds r6, r5, #0x0
	muls r6, r1
	adds r0, r6, #0x0
	asrs r0, r0, #0x08
	.global _0800A148
_0800A148:
	adds r7, r7, r0
	adds r6, r2, #0x0
	mov r3, r9
	ldr r0, [r4, #0x2C]
	adds r5, r4, #0x0
	adds r5, #0x40
	cmp r0, #0x00
	ble _0800A1D8
	ldr r0, [r3, #0x00]
	ldrb r2, [r6, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r0
	mov r3, r12
	ldrh r3, [r3, #0x00]
	ldrh r1, [r1, #0x00]
	adds r0, r3, #0x0
	muls r0, r1
	asrs r0, r0, #0x05
	adds r7, r7, r0
	b _0800A1D8
	.global _0800A170
_0800A170:
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	ble _0800A188
	movs r5, #0xA6
	lsls r5, r5, #0x01
	adds r1, r4, r5
	negs r0, r0
	asrs r0, r0, #0x02
	str r0, [r1, #0x00]
	adds r6, r4, #0x0
	adds r6, #0x3E
	b _0800A1C0
	.global _0800A188
_0800A188:
	adds r3, r4, #0x0
	adds r3, #0xA2
	ldrh r0, [r3, #0x00]
	cmp r0, #0x00
	beq _0800A1C6
	subs r0, #0x20
	strh r0, [r3, #0x00]
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x18
	cmp r0, r1
	bls _0800A1A2
	strh r7, [r3, #0x00]
	.global _0800A1A2
_0800A1A2:
	adds r2, r4, #0x0
	adds r2, #0x3E
	adds r0, r4, #0x0
	adds r0, #0xE4
	ldr r1, [r0, #0x00]
	ldrb r6, [r2, #0x00]
	lsls r0, r6, #0x01
	adds r0, r0, r1
	ldrh r3, [r3, #0x00]
	ldrh r5, [r0, #0x00]
	adds r1, r3, #0x0
	muls r1, r5
	adds r0, r1, #0x0
	asrs r7, r0, #0x08
	adds r6, r2, #0x0
	.global _0800A1C0
_0800A1C0:
	adds r5, r4, #0x0
	adds r5, #0x40
	b _0800A1D8
	.global _0800A1C6
_0800A1C6:
	adds r1, r4, #0x0
	adds r1, #0x40
	ldrh r6, [r1, #0x00]
	lsls r0, r6, #0x02
	negs r0, r0
	asrs r7, r0, #0x10
	adds r6, r4, #0x0
	adds r6, #0x3E
	adds r5, r1, #0x0
	.global _0800A1D8
_0800A1D8:
	movs r0, #0x02
	mov r1, r8
	ands r0, r1
	cmp r0, #0x00
	beq _0800A244
	ldrh r2, [r5, #0x00]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x01
	negs r0, r0
	asrs r0, r0, #0x08
	adds r7, r7, r0
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r1, r4, r3
	ldr r0, [r1, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x09
	adds r0, r0, r2
	str r0, [r1, #0x00]
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	ble _0800A244
	ldr r0, _0800A228 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800A220
	ldr r0, _0800A22C @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A230
	adds r0, r4, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800A230
	.global _0800A220
_0800A220:
	adds r0, r4, #0x0
	bl sub_0800A5BC
	b _0800A244
	.global _0800A228
_0800A228: .4byte 0x020021E0
	.global _0800A22C
_0800A22C: .4byte 0x020020DC
	.global _0800A230
_0800A230:
	ldr r0, [r4, #0x2C]
	movs r2, #0xFA
	lsls r2, r2, #0x0A
	cmp r0, r2
	ble _0800A244
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r1, r4, r3
	subs r0, r2, r0
	str r0, [r1, #0x00]
	.global _0800A244
_0800A244:
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	bge _0800A268
	ldrh r1, [r5, #0x00]
	adds r0, r1, r7
	ldr r2, _0800A264 @ =0x000032C8
	cmp r0, r2
	ble _0800A256
	subs r7, r2, r1
	.global _0800A256
_0800A256:
	adds r0, r1, r7
	cmp r0, #0x00
	bge _0800A25E
	negs r7, r1
	.global _0800A25E
_0800A25E:
	adds r0, r1, r7
	b _0800A26A
	.byte 0x00, 0x00
	.global _0800A264
_0800A264: .4byte 0x000032C8
	.global _0800A268
_0800A268:
	movs r0, #0x00
	.global _0800A26A
_0800A26A:
	strh r0, [r5, #0x00]
	ldr r1, [r4, #0x2C]
	cmp r1, #0x00
	bgt _0800A27E
	adds r0, r4, #0x0
	bl sub_0800A034
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	b _0800A280
	.global _0800A27E
_0800A27E:
	movs r3, #0x00
	.global _0800A280
_0800A280:
	movs r0, #0x9E
	lsls r0, r0, #0x01
	adds r0, r0, r4
	mov r8, r0
	adds r0, r4, #0x0
	adds r0, #0xE8
	ldr r1, [r0, #0x00]
	ldrb r2, [r6, #0x00]
	lsls r0, r2, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	negs r0, r0
	muls r0, r7
	negs r0, r0
	asrs r0, r0, #0x08
	mov r1, r8
	str r0, [r1, #0x00]
	ldr r2, [r4, #0x2C]
	cmp r2, #0x00
	bgt _0800A2C0
	adds r0, r4, #0x0
	adds r0, #0xEC
	ldr r1, [r0, #0x00]
	lsls r0, r3, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	negs r0, r0
	muls r0, r2
	asrs r0, r0, #0x08
	strh r0, [r5, #0x00]
	strb r3, [r6, #0x00]
	b _0800A2C6
	.global _0800A2C0
_0800A2C0:
	movs r0, #0x00
	strb r0, [r6, #0x00]
	strh r0, [r5, #0x00]
	.global _0800A2C6
_0800A2C6:
	add sp, #0x028
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
