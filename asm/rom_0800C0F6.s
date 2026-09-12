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
	thumb_func_start sub_0800C0FC
sub_0800C0FC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r5, #0x96
	lsls r5, r5, #0x01
	adds r4, r0, r5
	ldr r4, [r4, #0x00]
	asrs r4, r4, #0x0B
	negs r4, r4
	movs r5, #0x1F
	ands r4, r5
	lsls r4, r4, #0x03
	ldr r6, _0800C160 @ =0x0801CD08
	lsls r5, r4, #0x01
	adds r5, r5, r6
	mov r8, r5
	movs r7, #0x00
	ldsh r5, [r5, r7]
	mov r8, r5
	adds r4, #0x40
	lsls r4, r4, #0x01
	adds r4, r4, r6
	movs r6, #0x00
	ldsh r5, [r4, r6]
	ldr r4, [r0, #0x00]
	subs r1, r1, r4
	asrs r1, r1, #0x10
	ldr r0, [r0, #0x08]
	subs r2, r2, r0
	asrs r2, r2, #0x10
	adds r0, r1, #0x0
	muls r0, r5
	mov r4, r8
	muls r4, r2
	subs r0, r0, r4
	asrs r0, r0, #0x08
	str r0, [r3, #0x00]
	mov r0, r8
	muls r0, r1
	adds r1, r2, #0x0
	muls r1, r5
	adds r0, r0, r1
	asrs r0, r0, #0x08
	str r0, [r3, #0x04]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800C160
_0800C160: .4byte 0x0801CD08
	thumb_func_start sub_0800C164
sub_0800C164:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r0, _0800C1E8 @ =0x02002090
	ldrb r0, [r0, #0x00]
	mov r9, r0
	ldr r0, _0800C1EC @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800C186
	ldr r0, _0800C1F0 @ =0x020020AC
	ldrb r0, [r0, #0x00]
	mov r9, r0
	.global _0800C186
_0800C186:
	ldr r5, _0800C1F4 @ =0x0202A550
	movs r7, #0x00
	cmp r7, r9
	beq _0800C208
	mov r10, sp
	add r0, sp, #0x008
	mov r8, r0
	.global _0800C194
_0800C194:
	cmp r5, r4
	beq _0800C1F8
	ldr r1, [r5, #0x00]
	ldr r2, [r5, #0x08]
	adds r0, r4, #0x0
	mov r3, sp
	bl sub_0800C0FC
	mov r1, r10
	ldr r0, [r1, #0x04]
	adds r0, #0x64
	cmp r0, #0x64
	bhi _0800C1F8
	ldr r0, [sp, #0x000]
	movs r6, #0x10
	negs r6, r6
	cmp r0, r6
	blt _0800C1F8
	cmp r0, #0x10
	bgt _0800C1F8
	ldr r1, [r4, #0x00]
	ldr r2, [r4, #0x08]
	adds r0, r5, #0x0
	mov r3, r8
	bl sub_0800C0FC
	mov r1, r8
	ldr r0, [r1, #0x04]
	cmp r0, #0x00
	blt _0800C1F8
	ldr r0, [sp, #0x008]
	cmp r0, r6
	blt _0800C1F8
	cmp r0, #0x10
	bgt _0800C1F8
	movs r0, #0xBB
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x0F
	strb r0, [r1, #0x00]
	movs r0, #0x01
	b _0800C20A
	.global _0800C1E8
_0800C1E8: .4byte 0x02002090
	.global _0800C1EC
_0800C1EC: .4byte 0x020020DC
	.global _0800C1F0
_0800C1F0: .4byte 0x020020AC
	.global _0800C1F4
_0800C1F4: .4byte 0x0202A550
	.global _0800C1F8
_0800C1F8:
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r1, #0xC8
	lsls r1, r1, #0x01
	adds r5, r5, r1
	cmp r7, r9
	bne _0800C194
	.global _0800C208
_0800C208:
	movs r0, #0x00
	.global _0800C20A
_0800C20A:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start sub_0800C21C
sub_0800C21C:
	push {r4, r5, r6, lr}
	add sp, #-0x008
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	mov r2, sp
	bl sub_08009BB4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800C274
	ldr r0, [sp, #0x000]
	subs r0, #0x10
	str r0, [sp, #0x000]
	ldr r0, [sp, #0x004]
	subs r0, #0x10
	str r0, [sp, #0x004]
	ldr r0, _0800C27C @ =0x083FEF04
	bl sub_0800767C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0800C274
	ldr r0, _0800C280 @ =0x02002148
	ldr r0, [r0, #0x00]
	cmp r0, #0xFF
	ble _0800C26C
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	ldr r1, _0800C284 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x01
	orrs r4, r0
	lsls r0, r6, #0x0C
	ldr r5, [r2, #0x10]
	orrs r5, r0
	.global _0800C26C
_0800C26C:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_080044A4
	.global _0800C274
_0800C274:
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _0800C27C
_0800C27C: .4byte 0x083FEF04
	.global _0800C280
_0800C280: .4byte 0x02002148
	.global _0800C284
_0800C284: .4byte 0x000001FF
	.byte 0x70, 0x47, 0x00, 0x00
