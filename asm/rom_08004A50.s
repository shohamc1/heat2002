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
	thumb_func_start sub_08004A50
sub_08004A50:
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r3, r3, #0x18
	cmp r3, #0x00
	beq _08004A68
	ldr r1, _08004A78 @ =0x02025370
	movs r0, #0x08
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08004A70
	.global _08004A68
_08004A68:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_0800BB58
	.global _08004A70
_08004A70:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08004A78
_08004A78: .4byte 0x02025370
	thumb_func_start sub_08004A7C
sub_08004A7C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r5, #0x00
	ldr r6, _08004B08 @ =0x02025270
	ldr r0, _08004B0C @ =0x0202A540
	mov r8, r0
	.global _08004A8E
_08004A8E:
	lsls r4, r5, #0x02
	mov r1, r8
	adds r0, r4, r1
	ldr r3, [r0, #0x00]
	adds r0, r6, #0x0
	ldr r1, _08004B10 @ =0x0806C6A0
	adds r2, r5, #0x0
	bl sub_08017594
	adds r4, r4, r5
	lsls r4, r4, #0x01
	adds r2, r4, #0x0
	adds r2, #0x28
	movs r3, #0x00
	cmp r7, r5
	bne _08004AB0
	movs r3, #0x01
	.global _08004AB0
_08004AB0:
	adds r0, r6, #0x0
	movs r1, #0x10
	bl sub_08004A50
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x05
	bne _08004A8E
	movs r5, #0x00
	ldr r6, _08004B08 @ =0x02025270
	.global _08004AC6
_08004AC6:
	ldr r0, _08004B14 @ =0x0202CB20
	lsls r4, r5, #0x02
	adds r0, r4, r0
	ldr r3, [r0, #0x00]
	adds r0, r6, #0x0
	ldr r1, _08004B18 @ =0x0806C6A8
	adds r2, r5, #0x0
	bl sub_08017594
	adds r4, r4, r5
	lsls r4, r4, #0x01
	adds r2, r4, #0x0
	adds r2, #0x28
	movs r3, #0x00
	adds r0, r5, #0x5
	cmp r7, r0
	bne _08004AEA
	movs r3, #0x01
	.global _08004AEA
_08004AEA:
	adds r0, r6, #0x0
	movs r1, #0x78
	bl sub_08004A50
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x05
	bne _08004AC6
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08004B08
_08004B08: .4byte 0x02025270
	.global _08004B0C
_08004B0C: .4byte 0x0202A540
	.global _08004B10
_08004B10: .4byte 0x0806C6A0
	.global _08004B14
_08004B14: .4byte 0x0202CB20
	.global _08004B18
_08004B18: .4byte 0x0806C6A8
	thumb_func_start sub_08004B1C
sub_08004B1C:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x04
	bhi _08004B3C
	ldr r1, _08004B34 @ =0x0202A540
	lsls r0, r4, #0x02
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	ldr r6, _08004B38 @ =0x0202CB20
	b _08004B48
	.byte 0x00, 0x00
	.global _08004B34
_08004B34: .4byte 0x0202A540
	.global _08004B38
_08004B38: .4byte 0x0202CB20
	.global _08004B3C
_08004B3C:
	ldr r1, _08004B98 @ =0x0202CB20
	subs r0, r4, #0x5
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	adds r6, r1, #0x0
	.global _08004B48
_08004B48:
	ldr r1, _08004B9C @ =0x020005CC
	movs r0, #0x20
	ldrh r5, [r1, #0x00]
	ands r0, r5
	adds r5, r1, #0x0
	cmp r0, #0x00
	beq _08004B6C
	ldr r0, _08004BA0 @ =0x08365308
	lsls r1, r3, #0x02
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	subs r2, r2, r0
	ldr r0, _08004BA4 @ =0x083652B8
	adds r1, r1, r0
	ldr r1, [r1, #0x00]
	cmp r2, r1
	bge _08004B6C
	adds r2, r1, #0x0
	.global _08004B6C
_08004B6C:
	movs r0, #0x10
	ldrh r5, [r5, #0x00]
	ands r0, r5
	cmp r0, #0x00
	beq _08004B8C
	ldr r0, _08004BA0 @ =0x08365308
	lsls r1, r3, #0x02
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	adds r2, r2, r0
	ldr r0, _08004BA8 @ =0x083652E0
	adds r1, r1, r0
	ldr r1, [r1, #0x00]
	cmp r2, r1
	ble _08004B8C
	adds r2, r1, #0x0
	.global _08004B8C
_08004B8C:
	cmp r3, #0x04
	bhi _08004BB0
	ldr r1, _08004BAC @ =0x0202A540
	lsls r0, r4, #0x02
	adds r0, r0, r1
	b _08004BB6
	.global _08004B98
_08004B98: .4byte 0x0202CB20
	.global _08004B9C
_08004B9C: .4byte 0x020005CC
	.global _08004BA0
_08004BA0: .4byte 0x08365308
	.global _08004BA4
_08004BA4: .4byte 0x083652B8
	.global _08004BA8
_08004BA8: .4byte 0x083652E0
	.global _08004BAC
_08004BAC: .4byte 0x0202A540
	.global _08004BB0
_08004BB0:
	subs r0, r4, #0x5
	lsls r0, r0, #0x02
	adds r0, r0, r6
	.global _08004BB6
_08004BB6:
	str r2, [r0, #0x00]
	ldr r1, _08004BC8 @ =0x0202CB00
	adds r0, r6, #0x0
	bl sub_0800830C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08004BC8
_08004BC8: .4byte 0x0202CB00
	.byte 0x30, 0xB5, 0x18, 0x49, 0x04, 0x20, 0x09, 0x88, 0x08, 0x40, 0x00, 0x28, 0x30, 0xD0, 0x00, 0x24
	.byte 0xFF, 0xF7, 0xFE, 0xFD, 0xFB, 0xF7, 0x54, 0xFC, 0x12, 0x49, 0x04, 0x20, 0x0A, 0x88, 0x10, 0x40
	.byte 0x00, 0x04, 0x05, 0x0C, 0x00, 0x2D, 0x23, 0xD1, 0x08, 0x88, 0x21, 0x1C, 0x00, 0x22, 0x09, 0x23
	.byte 0x0D, 0xF0, 0x9C, 0xF8, 0x00, 0x06, 0x04, 0x0E, 0x20, 0x1C, 0xFF, 0xF7, 0x89, 0xFF, 0x02, 0xF0
	.byte 0xE5, 0xFB, 0xFF, 0xF7, 0x39, 0xFC, 0x20, 0x1C, 0xFF, 0xF7, 0x32, 0xFF, 0xFF, 0xF7, 0xE0, 0xFD
	.byte 0x05, 0x48, 0x05, 0x70, 0x05, 0x49, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0xFB, 0xF7, 0x16, 0xFC
	.byte 0xD8, 0xE7, 0x00, 0x00, 0xCC, 0x05, 0x00, 0x02, 0xC0, 0x20, 0x00, 0x02, 0x70, 0x53, 0x02, 0x02
	.byte 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
