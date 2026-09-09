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
	thumb_func_start sub_080079D0
sub_080079D0:
	adds r2, r0, #0x0
	ldr r0, _080079F4 @ =0x0202A550
	cmp r2, r0
	beq _080079FC
	movs r3, #0x00
	adds r0, r2, #0x0
	adds r0, #0x9C
	ldr r1, [r0, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x06
	cmp r1, r0
	bgt _080079EA
	movs r3, #0x01
	.global _080079EA
_080079EA:
	adds r0, r2, #0x0
	adds r0, #0x8C
	ldr r0, [r0, #0x00]
	ldr r1, _080079F8 @ =0x0003E7FF
	b _08007A16
	.global _080079F4
_080079F4: .4byte 0x0202A550
	.global _080079F8
_080079F8: .4byte 0x0003E7FF
	.global _080079FC
_080079FC:
	movs r3, #0x00
	adds r0, r2, #0x0
	adds r0, #0x9C
	ldr r1, [r0, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x06
	cmp r1, r0
	bgt _08007A0E
	movs r3, #0x01
	.global _08007A0E
_08007A0E:
	adds r0, r2, #0x0
	adds r0, #0x8C
	ldr r0, [r0, #0x00]
	ldr r1, _08007A40 @ =0x0005DBFF
	.global _08007A16
_08007A16:
	cmp r0, r1
	bgt _08007A38
	adds r0, r2, #0x0
	adds r0, #0x90
	ldr r0, [r0, #0x00]
	cmp r0, r1
	bgt _08007A38
	adds r0, r2, #0x0
	adds r0, #0x94
	ldr r0, [r0, #0x00]
	cmp r0, r1
	bgt _08007A38
	adds r0, r2, #0x0
	adds r0, #0x98
	ldr r0, [r0, #0x00]
	cmp r0, r1
	ble _08007A3A
	.global _08007A38
_08007A38:
	movs r3, #0x01
	.global _08007A3A
_08007A3A:
	adds r0, r3, #0x0
	bx lr
	.byte 0x00, 0x00
	.global _08007A40
_08007A40: .4byte 0x0005DBFF
	.byte 0x30, 0xB5, 0x00, 0x23, 0x0A, 0x49, 0x0B, 0x4D, 0xC8, 0x24, 0x64, 0x00, 0x48, 0x19, 0x00, 0x78
	.byte 0x00, 0x28, 0x02, 0xD0, 0x50, 0x1C, 0x00, 0x06, 0x02, 0x0E, 0x09, 0x19, 0x58, 0x1C, 0x00, 0x06
	.byte 0x03, 0x0E, 0x09, 0x19, 0x18, 0x2B, 0xF1, 0xD1, 0x10, 0x1C, 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47
	.byte 0x50, 0xA5, 0x02, 0x02, 0x75, 0x01, 0x00, 0x00
	thumb_func_start sub_08007A7C
sub_08007A7C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r2, #0x0
	adds r7, r3, #0x0
	ldr r2, [sp, #0x018]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	asrs r0, r0, #0x10
	ldr r3, _08007B08 @ =0x02002100
	ldr r2, [r3, #0x18]
	subs r5, r0, r2
	asrs r1, r1, #0x10
	ldr r0, [r3, #0x1C]
	subs r4, r1, r0
	adds r4, #0x40
	adds r5, #0x70
	adds r1, r5, #0x0
	adds r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bhi _08007AFC
	cmp r4, #0xA0
	bgt _08007AFC
	movs r0, #0x10
	negs r0, r0
	cmp r4, r0
	blt _08007AFC
	adds r0, r6, #0x0
	bl sub_08007630
	adds r6, r0, #0x0
	cmp r6, #0x00
	beq _08007AFC
	adds r0, r7, #0x0
	bl sub_08007714
	lsls r0, r0, #0x18
	movs r2, #0xFF
	ands r2, r4
	ldr r1, _08007B0C @ =0x000001FF
	ands r5, r1
	lsls r1, r5, #0x10
	orrs r2, r1
	movs r1, #0x80
	lsls r1, r1, #0x17
	orrs r2, r1
	lsrs r0, r0, #0x0C
	movs r1, #0x80
	lsls r1, r1, #0x04
	orrs r0, r1
	ldr r1, [r6, #0x10]
	orrs r1, r0
	mov r0, r8
	cmp r0, #0x00
	beq _08007AF6
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r2, r0
	.global _08007AF6
_08007AF6:
	adds r0, r2, #0x0
	bl sub_080044A4
	.global _08007AFC
_08007AFC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08007B08
_08007B08: .4byte 0x02002100
	.global _08007B0C
_08007B0C: .4byte 0x000001FF
