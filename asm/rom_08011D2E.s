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
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_08011D38
sub_08011D38:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	movs r0, #0x40
	ands r0, r5
	cmp r0, #0x00
	beq _08011D70
	ldr r0, _08011DA4 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011D60
	movs r0, #0x08
	bl sub_08001208
	.global _08011D60
_08011D60:
	lsls r0, r4, #0x10
	ldr r1, _08011DA8 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r1, r7, #0x10
	cmp r0, r1
	bge _08011D70
	adds r4, r6, #0x0
	.global _08011D70
_08011D70:
	movs r0, #0x80
	ands r0, r5
	cmp r0, #0x00
	beq _08011D98
	ldr r0, _08011DA4 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011D86
	movs r0, #0x08
	bl sub_08001208
	.global _08011D86
_08011D86:
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r1, r6, #0x10
	cmp r0, r1
	ble _08011D98
	adds r4, r7, #0x0
	.global _08011D98
_08011D98:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08011DA4
_08011DA4: .4byte 0x0202EF00
	.global _08011DA8
_08011DA8: .4byte 0xFFFF0000
	thumb_func_start sub_08011DAC
sub_08011DAC:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0x40
	ands r0, r5
	cmp r0, #0x00
	beq _08011DD6
	lsls r0, r4, #0x10
	ldr r1, _08011DFC @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r1, r2, #0x10
	cmp r0, r1
	bge _08011DD6
	adds r4, r3, #0x0
	.global _08011DD6
_08011DD6:
	movs r0, #0x80
	ands r0, r5
	cmp r0, #0x00
	beq _08011DF0
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r1, r3, #0x10
	cmp r0, r1
	ble _08011DF0
	adds r4, r2, #0x0
	.global _08011DF0
_08011DF0:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08011DFC
_08011DFC: .4byte 0xFFFF0000
	thumb_func_start sub_08011E00
sub_08011E00:
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0x00
	beq _08011E3E
	ldr r1, _08011E78 @ =0x0202EFB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _08011E7C @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011E2E
	movs r0, #0x08
	bl sub_08001208
	.global _08011E2E
_08011E2E:
	lsls r0, r4, #0x10
	ldr r1, _08011E80 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r1, r7, #0x10
	cmp r0, r1
	bge _08011E3E
	adds r4, r6, #0x0
	.global _08011E3E
_08011E3E:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0x00
	beq _08011E6C
	ldr r1, _08011E78 @ =0x0202EFB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _08011E7C @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011E5A
	movs r0, #0x08
	bl sub_08001208
	.global _08011E5A
_08011E5A:
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r1, r6, #0x10
	cmp r0, r1
	ble _08011E6C
	adds r4, r7, #0x0
	.global _08011E6C
_08011E6C:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08011E78
_08011E78: .4byte 0x0202EFB0
	.global _08011E7C
_08011E7C: .4byte 0x0202EF00
	.global _08011E80
_08011E80: .4byte 0xFFFF0000
	thumb_func_start sub_08011E84
sub_08011E84:
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0x00
	beq _08011EB4
	ldr r1, _08011EE0 @ =0x0202EFB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r4, #0x10
	ldr r1, _08011EE4 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r1, r2, #0x10
	cmp r0, r1
	bge _08011EB4
	adds r4, r3, #0x0
	.global _08011EB4
_08011EB4:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0x00
	beq _08011ED4
	ldr r1, _08011EE0 @ =0x0202EFB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r1, r3, #0x10
	cmp r0, r1
	ble _08011ED4
	adds r4, r2, #0x0
	.global _08011ED4
_08011ED4:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08011EE0
_08011EE0: .4byte 0x0202EFB0
	.global _08011EE4
_08011EE4: .4byte 0xFFFF0000
	thumb_func_start sub_08011EE8
sub_08011EE8:
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0x00
	beq _08011F32
	ldr r1, _08011F1C @ =0x0202EFB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r4, #0x10
	ldr r1, _08011F20 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r2, r2, #0x10
	cmp r0, r2
	bge _08011F24
	lsrs r4, r2, #0x10
	b _08011F32
	.byte 0x00, 0x00
	.global _08011F1C
_08011F1C: .4byte 0x0202EFB0
	.global _08011F20
_08011F20: .4byte 0xFFFF0000
	.global _08011F24
_08011F24:
	ldr r0, _08011F54 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011F32
	movs r0, #0x08
	bl sub_08001208
	.global _08011F32
_08011F32:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0x00
	beq _08011F6A
	ldr r1, _08011F58 @ =0x0202EFB0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	lsls r3, r6, #0x10
	cmp r0, r3
	ble _08011F5C
	lsrs r4, r3, #0x10
	b _08011F6A
	.global _08011F54
_08011F54: .4byte 0x0202EF00
	.global _08011F58
_08011F58: .4byte 0x0202EFB0
	.global _08011F5C
_08011F5C:
	ldr r0, _08011F74 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08011F6A
	movs r0, #0x08
	bl sub_08001208
	.global _08011F6A
_08011F6A:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.global _08011F74
_08011F74: .4byte 0x0202EF00
	thumb_func_start sub_08011F78
sub_08011F78:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0x0
	ldr r0, _08011FC0 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x5A
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x51
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _08011FA0
	movs r2, #0x01
	.global _08011FA0
_08011FA0:
	movs r1, #0x09
	bl sub_08006950
	movs r0, #0x52
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _08011FB4
	movs r2, #0x01
	.global _08011FB4
_08011FB4:
	movs r1, #0x0B
	bl sub_08006950
	pop {r4}
	pop {r0}
	bx r0
	.global _08011FC0
_08011FC0: .4byte 0x083FDE18
	thumb_func_start sub_08011FC4
sub_08011FC4:
	push {r4, r5, r6, lr}
	ldr r4, _08012068 @ =0xFFFFFE00
	add sp, r4
	movs r5, #0x00
	movs r6, #0x00
	movs r0, #0x04
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_08011F78
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	.global _08011FE4
_08011FE4:
	bl sub_0800048C
	adds r0, r5, #0x0
	bl sub_08011F78
	ldr r1, _0801206C @ =0x020005CC
	movs r0, #0xC0
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _0801200C
	movs r0, #0x01
	eors r5, r0
	ldr r0, _08012070 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0801200C
	movs r0, #0x08
	bl sub_08001208
	.global _0801200C
_0801200C:
	ldr r0, _0801206C @ =0x020005CC
	ldrh r1, [r0, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _0801201A
	movs r6, #0xFF
	.global _0801201A
_0801201A:
	movs r0, #0x09
	ands r0, r1
	cmp r0, #0x00
	beq _08012036
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _08012070 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08012036
	movs r0, #0x09
	bl sub_08001208
	.global _08012036
_08012036:
	bl sub_08000458
	lsls r0, r6, #0x18
	asrs r4, r0, #0x18
	cmp r4, #0x00
	beq _08011FE4
	ldr r0, _08012070 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08012050
	movs r0, #0x09
	bl sub_08001208
	.global _08012050
_08012050:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	adds r0, r4, #0x0
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08012068
_08012068: .4byte 0xFFFFFE00
	.global _0801206C
_0801206C: .4byte 0x020005CC
	.global _08012070
_08012070: .4byte 0x0202EF00
	thumb_func_start sub_08012074
sub_08012074:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x01C
	ldr r1, _0801208C @ =0x04000128
	movs r0, #0x30
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08012090
	bl sub_08016E30
	b _080120AE
	.byte 0x00, 0x00
	.global _0801208C
_0801208C: .4byte 0x04000128
	.global _08012090
_08012090:
	bl sub_0800048C
	ldr r1, _080121C0 @ =0x020005CC
	movs r0, #0x02
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080120A2
	b _08012218
	.global _080120A2
_080120A2:
	ldr r1, _080121C4 @ =0x03007FF8
	movs r0, #0x80
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08012090
	.global _080120AE
_080120AE:
	bl sub_0800048C
	ldr r2, _080121C8 @ =0x0202ED78
	ldr r0, _080121CC @ =0x04000128
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x1A
	lsrs r0, r0, #0x1E
	adds r0, #0x01
	lsls r0, r0, #0x0C
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r1, r3, #0x0
	orrs r0, r1
	ldr r1, _080121D0 @ =0x020005C8
	ldrb r1, [r1, #0x00]
	orrs r0, r1
	movs r4, #0x00
	strh r0, [r2, #0x00]
	ldrh r0, [r2, #0x00]
	bl sub_0800F818
	ldr r0, _080121D4 @ =0x0202EFA0
	movs r2, #0xFF
	ldrb r1, [r0, #0x02]
	orrs r1, r2
	strb r1, [r0, #0x02]
	ldrb r1, [r0, #0x06]
	orrs r1, r2
	strb r1, [r0, #0x06]
	ldrb r1, [r0, #0x0A]
	orrs r1, r2
	strb r1, [r0, #0x0A]
	ldrb r6, [r0, #0x0E]
	orrs r2, r6
	strb r2, [r0, #0x0E]
	ldr r0, _080121D8 @ =0x0202EEF4
	strb r4, [r0, #0x00]
	movs r3, #0x00
	add r4, sp, #0x014
	adds r5, r4, #0x0
	ldr r2, _080121DC @ =0x0202EF40
	.global _08012100
_08012100:
	lsls r1, r3, #0x01
	adds r1, r5, r1
	lsls r0, r3, #0x03
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x03
	bls _08012100
	ldrh r0, [r4, #0x00]
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x18
	movs r1, #0x0F
	ands r0, r1
	cmp r0, #0x01
	bne _08012160
	lsrs r1, r2, #0x1C
	cmp r1, #0x01
	bne _08012160
	ldr r5, _080121D4 @ =0x0202EFA0
	strb r1, [r5, #0x02]
	ldr r3, _080121D8 @ =0x0202EEF4
	ldrb r2, [r3, #0x00]
	adds r2, #0x01
	strb r2, [r3, #0x00]
	ldrh r0, [r4, #0x02]
	lsrs r0, r0, #0x0C
	cmp r0, #0x02
	bne _08012160
	strb r1, [r5, #0x06]
	adds r2, #0x01
	strb r2, [r3, #0x00]
	ldrh r6, [r4, #0x04]
	lsrs r0, r6, #0x0C
	cmp r0, #0x03
	bne _08012160
	strb r1, [r5, #0x0A]
	adds r2, #0x01
	strb r2, [r3, #0x00]
	ldrh r6, [r4, #0x06]
	lsrs r0, r6, #0x0C
	cmp r0, #0x04
	bne _08012160
	strb r1, [r5, #0x0E]
	adds r0, r2, #0x1
	strb r0, [r3, #0x00]
	.global _08012160
_08012160:
	movs r5, #0x00
	movs r3, #0x00
	ldr r7, _080121E0 @ =0x0202EF90
	movs r6, #0x0F
	.global _08012168
_08012168:
	lsls r0, r3, #0x01
	adds r0, r4, r0
	ldrh r0, [r0, #0x00]
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x1C
	adds r1, r3, #0x1
	cmp r0, r1
	bne _08012186
	lsrs r0, r2, #0x18
	ands r0, r6
	cmp r0, #0x01
	bne _08012186
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	.global _08012186
_08012186:
	lsls r0, r1, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x03
	bls _08012168
	ldr r0, _080121CC @ =0x04000128
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x1A
	lsrs r1, r1, #0x1E
	strb r1, [r7, #0x00]
	movs r1, #0x30
	ldrb r0, [r0, #0x00]
	ands r1, r0
	cmp r1, #0x00
	bne _080121EE
	ldr r0, _080121D8 @ =0x0202EEF4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bls _080121E4
	cmp r0, r5
	bne _080121E4
	movs r0, #0x0F
	bl sub_08016558
	movs r1, #0x0F
	movs r2, #0x01
	bl sub_08006950
	b _080121EE
	.byte 0x00, 0x00
	.global _080121C0
_080121C0: .4byte 0x020005CC
	.global _080121C4
_080121C4: .4byte 0x03007FF8
	.global _080121C8
_080121C8: .4byte 0x0202ED78
	.global _080121CC
_080121CC: .4byte 0x04000128
	.global _080121D0
_080121D0: .4byte 0x020005C8
	.global _080121D4
_080121D4: .4byte 0x0202EFA0
	.global _080121D8
_080121D8: .4byte 0x0202EEF4
	.global _080121DC
_080121DC: .4byte 0x0202EF40
	.global _080121E0
_080121E0: .4byte 0x0202EF90
	.global _080121E4
_080121E4:
	ldr r0, _08012208 @ =0x0829F32C
	movs r1, #0x0F
	movs r2, #0x01
	bl sub_08006950
	.global _080121EE
_080121EE:
	ldr r1, _0801220C @ =0x0202EF40
	ldr r0, _08012210 @ =0x00001108
	ldrh r1, [r1, #0x00]
	cmp r1, r0
	bne _0801221E
	ldr r0, _08012214 @ =0x0202EEF4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bls _0801221E
	cmp r0, r5
	bne _0801221E
	movs r0, #0x01
	b _08012220
	.global _08012208
_08012208: .4byte 0x0829F32C
	.global _0801220C
_0801220C: .4byte 0x0202EF40
	.global _08012210
_08012210: .4byte 0x00001108
	.global _08012214
_08012214: .4byte 0x0202EEF4
	.global _08012218
_08012218:
	movs r0, #0x01
	negs r0, r0
	b _08012220
	.global _0801221E
_0801221E:
	movs r0, #0x00
	.global _08012220
_08012220:
	add sp, #0x01C
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start sub_08012228
sub_08012228:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x028
	ldr r0, _08012274 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0xC4
	bl sub_08016558
	bl sub_080065A8
	movs r7, #0x00
	.global _08012240
_08012240:
	ldr r0, _08012278 @ =0x0202EFA0
	lsls r4, r7, #0x02
	adds r4, r4, r0
	movs r1, #0x02
	ldsb r1, [r4, r1]
	mvns r1, r1
	negs r0, r1
	orrs r0, r1
	lsrs r6, r0, #0x1F
	adds r0, r7, #0x0
	adds r0, #0x53
	bl sub_08016558
	lsls r1, r7, #0x01
	adds r5, r1, #0x7
	movs r1, #0x01
	adds r2, r5, #0x0
	adds r3, r6, #0x0
	bl sub_080063BC
	movs r0, #0x02
	ldsb r0, [r4, r0]
	cmp r0, #0x00
	bne _0801227C
	movs r0, #0x58
	b _08012282
	.global _08012274
_08012274: .4byte 0x083FDE18
	.global _08012278
_08012278: .4byte 0x0202EFA0
	.global _0801227C
_0801227C:
	cmp r0, #0x01
	bne _08012292
	movs r0, #0x57
	.global _08012282
_08012282:
	bl sub_08016558
	movs r1, #0x14
	adds r2, r5, #0x0
	adds r3, r6, #0x0
	bl sub_080063BC
	b _0801229E
	.global _08012292
_08012292:
	ldr r0, _080122B0 @ =0x0829F348
	movs r1, #0x14
	adds r2, r5, #0x0
	adds r3, r6, #0x0
	bl sub_080063BC
	.global _0801229E
_0801229E:
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0x04
	bne _08012240
	add sp, #0x028
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _080122B0
_080122B0: .4byte 0x0829F348
	thumb_func_start sub_080122B4
sub_080122B4:
	push {r4, r5, lr}
	ldr r4, _08012308 @ =0xFFFFFE00
	add sp, r4
	movs r5, #0x00
	movs r4, #0x40
	bl sub_08011A50
	bl sub_0800F3A4
	bl sub_0800F4FC
	ldr r0, _0801230C @ =0x082E4328
	mov r1, sp
	bl sub_0800F328
	movs r0, #0x00
	bl sub_08012228
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	ldr r0, _08012310 @ =0x020020B8
	strh r5, [r0, #0x00]
	.global _080122E4
_080122E4:
	bl sub_0800048C
	adds r0, r5, #0x0
	bl sub_08012228
	bl sub_08012074
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	beq _08012314
	cmp r1, #0x01
	bne _08012316
	movs r4, #0x01
	b _08012316
	.byte 0x00, 0x00
	.global _08012308
_08012308: .4byte 0xFFFFFE00
	.global _0801230C
_0801230C: .4byte 0x082E4328
	.global _08012310
_08012310: .4byte 0x020020B8
	.global _08012314
_08012314:
	movs r4, #0x00
	.global _08012316
_08012316:
	ldr r1, _0801234C @ =0x020005CC
	movs r0, #0x02
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08012324
	movs r4, #0x00
	.global _08012324
_08012324:
	cmp r4, #0x40
	beq _080122E4
	ldr r0, _08012350 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08012336
	movs r0, #0x09
	bl sub_08001208
	.global _08012336
_08012336:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	adds r0, r4, #0x0
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5}
	pop {r1}
	bx r1
	.global _0801234C
_0801234C: .4byte 0x020005CC
	.global _08012350
_08012350: .4byte 0x0202EF00
	.byte 0x00, 0xB5, 0xA4, 0x46, 0x09, 0x4C, 0xA5, 0x44, 0x64, 0x46, 0x04, 0x20, 0x69, 0x46, 0xFF, 0xF7
	.byte 0x9B, 0xFC, 0x00, 0x20, 0xFF, 0xF7, 0x06, 0xFE, 0x68, 0x46, 0x0F, 0x21, 0xF1, 0xF7, 0x62, 0xFF
	.byte 0x80, 0x23, 0x9B, 0x00, 0x9D, 0x44, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF
