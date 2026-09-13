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
	thumb_func_start sub_0800383C
sub_0800383C:
	push {r4, r5, r6, lr}
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r3, _0800388C @ =0x0000FFFF
	adds r2, r0, #0x0
	ldrh r4, [r2, #0x00]
	adds r2, #0x02
	movs r5, #0x01
	cmp r5, r6
	bcs _08003884
	.global _08003850
_08003850:
	strh r4, [r1, #0x00]
	adds r1, #0x02
	cmp r4, r3
	bne _08003874
	ldrh r3, [r2, #0x00]
	adds r2, #0x02
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r3, #0x00
	beq _08003874
	.global _08003866
_08003866:
	strh r4, [r1, #0x00]
	adds r1, #0x02
	subs r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x00
	bne _08003866
	.global _08003874
_08003874:
	adds r3, r4, #0x0
	ldrh r4, [r2, #0x00]
	adds r2, #0x02
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, r6
	bcc _08003850
	.global _08003884
_08003884:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800388C
_0800388C: .4byte 0x0000FFFF
	thumb_func_start sub_08003890
sub_08003890:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x0B
	bhi _0800390C
	lsls r0, r4, #0x02
	ldr r1, _080038A4 @ =0x080038A8
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.global _080038A4
_080038A4: .4byte 0x080038A8
	.byte 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08
	.byte 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08
	.byte 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08, 0xD8, 0x38, 0x00, 0x08
	.byte 0x0E, 0x4D, 0x64, 0x20, 0x44, 0x43, 0x28, 0x1D, 0x20, 0x18, 0x00, 0x68, 0xC0, 0x21, 0xC9, 0x04
	.byte 0x80, 0x22, 0xD2, 0x01, 0x13, 0xF0, 0x90, 0xFA, 0x64, 0x19, 0x20, 0x68, 0x08, 0x49, 0x80, 0x22
	.byte 0x92, 0x01, 0x13, 0xF0, 0x89, 0xFA, 0x07, 0x48, 0x00, 0x21, 0x01, 0x80, 0x06, 0x48, 0x01, 0x80
	.byte 0x06, 0x48, 0x01, 0x80
	.global _0800390C
_0800390C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x0C, 0x4B, 0x36, 0x08, 0x00, 0x80, 0x00, 0x06, 0xE4, 0x2D, 0x02, 0x02, 0x34, 0xBC
	.byte 0x00, 0x02, 0xF4, 0x2D, 0x02, 0x02
	thumb_func_start sub_08003928
sub_08003928:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08003AE8 @ =0xFFFFFDF8
	add sp, r4
	adds r7, r0, #0x0
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	bl sub_08003890
	ldr r0, _08003AEC @ =0x08335C60
	ldr r1, _08003AF0 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	ldr r6, _08003AF4 @ =0x08364B0C
	movs r0, #0x64
	adds r4, r7, #0x0
	muls r4, r0
	adds r0, r6, #0x0
	adds r0, #0x18
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x01
	add r1, sp, #0x008
	bl sub_08016E10
	ldr r0, _08003AF8 @ =0x08334BCC
	add r1, sp, #0x1C8
	movs r2, #0x10
	bl sub_08016E10
	movs r0, #0x1E
	add r1, sp, #0x008
	bl sub_08004018
	ldr r1, _08003AFC @ =0x0200BC30
	adds r0, r6, #0x0
	adds r0, #0x2C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _08003B00 @ =0x02022DD8
	adds r0, r6, #0x0
	adds r0, #0x34
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, _08003B04 @ =0x02002208
	ldr r1, _08003B08 @ =0x02002220
	str r1, [r0, #0x00]
	ldr r0, _08003B0C @ =0x0200BC54
	ldr r5, _08003B10 @ =0x0200BC70
	str r5, [r0, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	adds r2, r4, r6
	mov r8, r2
	adds r2, #0x5C
	ldrh r2, [r2, #0x00]
	bl sub_0800383C
	adds r0, r6, #0x0
	adds r0, #0x24
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	mov r1, r8
	adds r1, #0x5E
	ldrh r2, [r1, #0x00]
	adds r1, r5, #0x0
	bl sub_0800383C
	ldr r1, _08003B14 @ =0x0200221C
	adds r0, r6, #0x0
	adds r0, #0x0C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _08003B18 @ =0x02002210
	adds r0, r6, #0x0
	adds r0, #0x10
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _08003B1C @ =0x02022DF0
	adds r0, r6, #0x0
	adds r0, #0x3C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _08003B20 @ =0x0201567C
	adds r0, r6, #0x0
	adds r0, #0x40
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, _08003B24 @ =0x0200BC50
	ldr r1, _08003B28 @ =0x02015690
	str r1, [r0, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x44
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	mov r2, r8
	adds r2, #0x60
	ldrh r2, [r2, #0x00]
	bl sub_0800383C
	ldr r1, _08003B2C @ =0x02022DEC
	adds r0, r6, #0x0
	adds r0, #0x48
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	str r0, [r1, #0x00]
	cmp r7, #0x00
	bne _08003A1E
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _08003A1E
_08003A1E:
	cmp r7, #0x01
	bne _08003A28
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x70
	str r0, [r1, #0x00]
	.global _08003A28
_08003A28:
	cmp r7, #0x02
	bne _08003A32
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0xA8
	str r0, [r1, #0x00]
	.global _08003A32
_08003A32:
	cmp r7, #0x03
	bne _08003A3C
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x6B
	str r0, [r1, #0x00]
	.global _08003A3C
_08003A3C:
	cmp r7, #0x04
	bne _08003A46
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0xA3
	str r0, [r1, #0x00]
	.global _08003A46
_08003A46:
	cmp r7, #0x05
	bne _08003A50
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0xA6
	str r0, [r1, #0x00]
	.global _08003A50
_08003A50:
	cmp r7, #0x06
	bne _08003A5A
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _08003A5A
_08003A5A:
	cmp r7, #0x08
	bne _08003A64
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _08003A64
_08003A64:
	cmp r7, #0x09
	bne _08003A6E
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _08003A6E
_08003A6E:
	cmp r7, #0x0A
	bne _08003A78
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x5E
	str r0, [r1, #0x00]
	.global _08003A78
_08003A78:
	cmp r7, #0x0B
	bne _08003A82
	ldr r1, _08003B30 @ =0x02002200
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _08003A82
_08003A82:
	ldr r0, _08003B04 @ =0x02002208
	ldr r2, [r0, #0x00]
	movs r3, #0xC0
	lsls r3, r3, #0x12
	ldr r0, _08003B14 @ =0x0200221C
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _08003B34 @ =0x02022DE4
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x00
	movs r1, #0x00
	bl sub_08003BFC
	ldr r0, _08003B0C @ =0x0200BC54
	ldr r2, [r0, #0x00]
	ldr r3, _08003B38 @ =0x03000800
	ldr r0, _08003B18 @ =0x02002210
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _08003B3C @ =0x0200BC34
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x00
	movs r1, #0x00
	bl sub_08003BFC
	bl sub_08003D90
	movs r0, #0x00
	movs r1, #0x00
	bl sub_08004260
	adds r0, r7, #0x0
	bl sub_08008F1C
	bl sub_08005560
	bl sub_0800557C
	ldr r1, _08003B40 @ =0x020253D4
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r3, #0x82
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08003AE8
_08003AE8: .4byte 0xFFFFFDF8
	.global _08003AEC
_08003AEC: .4byte 0x08335C60
	.global _08003AF0
_08003AF0: .4byte 0x0600C000
	.global _08003AF4
_08003AF4: .4byte 0x08364B0C
	.global _08003AF8
_08003AF8: .4byte 0x08334BCC
	.global _08003AFC
_08003AFC: .4byte 0x0200BC30
	.global _08003B00
_08003B00: .4byte 0x02022DD8
	.global _08003B04
_08003B04: .4byte 0x02002208
	.global _08003B08
_08003B08: .4byte 0x02002220
	.global _08003B0C
_08003B0C: .4byte 0x0200BC54
	.global _08003B10
_08003B10: .4byte 0x0200BC70
	.global _08003B14
_08003B14: .4byte 0x0200221C
	.global _08003B18
_08003B18: .4byte 0x02002210
	.global _08003B1C
_08003B1C: .4byte 0x02022DF0
	.global _08003B20
_08003B20: .4byte 0x0201567C
	.global _08003B24
_08003B24: .4byte 0x0200BC50
	.global _08003B28
_08003B28: .4byte 0x02015690
	.global _08003B2C
_08003B2C: .4byte 0x02022DEC
	.global _08003B30
_08003B30: .4byte 0x02002200
	.global _08003B34
_08003B34: .4byte 0x02022DE4
	.global _08003B38
_08003B38: .4byte 0x03000800
	.global _08003B3C
_08003B3C: .4byte 0x0200BC34
	.global _08003B40
_08003B40: .4byte 0x020253D4
	thumb_func_start sub_08003B44
sub_08003B44:
	push {r4, r5, lr}
	add sp, #-0x008
	ldr r0, _08003BC0 @ =0x02002100
	ldr r4, [r0, #0x18]
	subs r4, #0x78
	ldr r5, [r0, #0x1C]
	subs r5, #0x50
	ldr r0, _08003BC4 @ =0x0200BC48
	movs r2, #0x0F
	ands r2, r4
	str r2, [r0, #0x00]
	ldr r0, _08003BC8 @ =0x0200BC4C
	movs r1, #0x1F
	ands r1, r5
	str r1, [r0, #0x00]
	ldr r0, _08003BCC @ =0x02022DF8
	str r2, [r0, #0x00]
	ldr r0, _08003BD0 @ =0x0200BC2C
	str r1, [r0, #0x00]
	ldr r0, _08003BD4 @ =0x02022DE0
	str r2, [r0, #0x00]
	ldr r0, _08003BD8 @ =0x02022DE8
	str r1, [r0, #0x00]
	ldr r2, _08003BDC @ =0x02002218
	movs r1, #0x10
	adds r0, r4, #0x0
	ands r0, r1
	strb r0, [r2, #0x00]
	asrs r4, r4, #0x05
	asrs r5, r5, #0x05
	ldr r0, _08003BE0 @ =0x02002208
	ldr r2, [r0, #0x00]
	movs r3, #0xC0
	lsls r3, r3, #0x12
	ldr r0, _08003BE4 @ =0x0200221C
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _08003BE8 @ =0x02022DE4
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_08003BFC
	ldr r0, _08003BEC @ =0x0200BC54
	ldr r2, [r0, #0x00]
	ldr r3, _08003BF0 @ =0x03000800
	ldr r0, _08003BF4 @ =0x02002210
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _08003BF8 @ =0x0200BC34
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_08003BFC
	add sp, #0x008
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08003BC0
_08003BC0: .4byte 0x02002100
	.global _08003BC4
_08003BC4: .4byte 0x0200BC48
	.global _08003BC8
_08003BC8: .4byte 0x0200BC4C
	.global _08003BCC
_08003BCC: .4byte 0x02022DF8
	.global _08003BD0
_08003BD0: .4byte 0x0200BC2C
	.global _08003BD4
_08003BD4: .4byte 0x02022DE0
	.global _08003BD8
_08003BD8: .4byte 0x02022DE8
	.global _08003BDC
_08003BDC: .4byte 0x02002218
	.global _08003BE0
_08003BE0: .4byte 0x02002208
	.global _08003BE4
_08003BE4: .4byte 0x0200221C
	.global _08003BE8
_08003BE8: .4byte 0x02022DE4
	.global _08003BEC
_08003BEC: .4byte 0x0200BC54
	.global _08003BF0
_08003BF0: .4byte 0x03000800
	.global _08003BF4
_08003BF4: .4byte 0x02002210
	.global _08003BF8
_08003BF8: .4byte 0x0200BC34
