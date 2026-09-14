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
