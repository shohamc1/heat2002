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
	thumb_func_start sub_08014104
sub_08014104:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x028
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r9, r0
	lsls r4, r0, #0x04
	subs r4, r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _08014178 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x32
	bl sub_08016558
	bl sub_080065A8
	lsls r4, r4, #0x02
	ldr r0, _0801417C @ =0x0202EFC0
	adds r7, r4, r0
	movs r0, #0x00
	mov r8, r0
	mov r5, sp
	mov r10, r0
	.global _0801413E
_0801413E:
	mov r4, r8
	adds r4, #0x04
	ldr r0, _08014180 @ =0x0829F44C
	movs r1, #0x01
	adds r2, r4, #0x0
	movs r3, #0x01
	bl sub_080063BC
	ldr r0, _08014184 @ =0x0202F020
	adds r6, r4, #0x0
	cmp r7, r0
	bcs _08014212
	ldr r4, [r7, #0x00]
	ldr r0, _08014188 @ =0x0202A550
	cmp r4, r0
	bne _08014194
	ldr r1, _0801418C @ =0x0202539C
	movs r0, #0x10
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08014194
	ldr r0, _08014190 @ =0x0829F2AC
	movs r1, #0x01
	adds r2, r6, #0x0
	movs r3, #0x01
	bl sub_080063BC
	b _08014210
	.global _08014178
_08014178: .4byte 0x083FDE18
	.global _0801417C
_0801417C: .4byte 0x0202EFC0
	.global _08014180
_08014180: .4byte 0x0829F44C
	.global _08014184
_08014184: .4byte 0x0202F020
	.global _08014188
_08014188: .4byte 0x0202A550
	.global _0801418C
_0801418C: .4byte 0x0202539C
	.global _08014190
_08014190: .4byte 0x0829F2AC
	.global _08014194
_08014194:
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	bl sub_0800F110
	movs r1, #0x01
	adds r2, r6, #0x0
	movs r3, #0x01
	bl sub_080063BC
	movs r0, #0xB2
	lsls r0, r0, #0x01
	adds r4, r4, r0
	ldrh r0, [r4, #0x00]
	movs r1, #0xFA
	lsls r1, r1, #0x02
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x00]
	ldrh r0, [r4, #0x00]
	movs r1, #0x64
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x01]
	ldrh r0, [r4, #0x00]
	movs r1, #0x0A
	bl _08017420
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x02]
	ldrh r0, [r4, #0x00]
	movs r1, #0x0A
	bl sub_08017498
	adds r0, #0x30
	strb r0, [r5, #0x03]
	mov r1, r10
	strb r1, [r5, #0x04]
	mov r0, sp
	movs r1, #0x1A
	adds r2, r6, #0x0
	movs r3, #0x01
	bl sub_080063BC
	.global _08014210
_08014210:
	adds r7, #0x04
	.global _08014212
_08014212:
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0x0F
	bne _0801413E
	ldr r0, _0801423C @ =0x0202539C
	ldrb r1, [r0, #0x00]
	adds r1, #0x01
	strb r1, [r0, #0x00]
	movs r0, #0x08
	ands r1, r0
	cmp r1, #0x00
	beq _08014258
	mov r0, r9
	cmp r0, #0x00
	bne _08014244
	ldr r0, _08014240 @ =0x0829F440
	b _08014246
	.byte 0x00, 0x00
	.global _0801423C
_0801423C: .4byte 0x0202539C
	.global _08014240
_08014240: .4byte 0x0829F440
	.global _08014244
_08014244:
	ldr r0, _08014254 @ =0x0829F444
	.global _08014246
_08014246:
	movs r1, #0x1A
	movs r2, #0x13
	movs r3, #0x01
	bl sub_080063BC
	b _08014264
	.byte 0x00, 0x00
	.global _08014254
_08014254: .4byte 0x0829F444
	.global _08014258
_08014258:
	ldr r0, _08014274 @ =0x0829F448
	movs r1, #0x1A
	movs r2, #0x13
	movs r3, #0x01
	bl sub_080063BC
	.global _08014264
_08014264:
	add sp, #0x028
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08014274
_08014274: .4byte 0x0829F448
