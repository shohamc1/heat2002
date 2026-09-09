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
	thumb_func_start sub_0801A570
sub_0801A570:
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, [r4, #0x4C]
	cmp r0, #0x00
	bne _0801A58C
	adds r0, r4, #0x0
	movs r1, #0x04
	movs r2, #0x10
	bl sub_0801B4A8
	str r0, [r4, #0x4C]
	cmp r0, #0x00
	beq _0801A5B4
	.global _0801A58C
_0801A58C:
	ldr r1, [r4, #0x4C]
	lsls r0, r6, #0x02
	adds r2, r0, r1
	ldr r1, [r2, #0x00]
	cmp r1, #0x00
	beq _0801A59E
	ldr r0, [r1, #0x00]
	str r0, [r2, #0x00]
	b _0801A5BC
	.global _0801A59E
_0801A59E:
	movs r5, #0x01
	lsls r5, r6
	lsls r2, r5, #0x02
	adds r2, #0x14
	adds r0, r4, #0x0
	movs r1, #0x01
	bl sub_0801B4A8
	adds r1, r0, #0x0
	cmp r1, #0x00
	bne _0801A5B8
	.global _0801A5B4
_0801A5B4:
	movs r0, #0x00
	b _0801A5C4
	.global _0801A5B8
_0801A5B8:
	str r6, [r1, #0x04]
	str r5, [r1, #0x08]
	.global _0801A5BC
_0801A5BC:
	movs r0, #0x00
	str r0, [r1, #0x10]
	str r0, [r1, #0x0C]
	adds r0, r1, #0x0
	.global _0801A5C4
_0801A5C4:
	pop {r4, r5, r6, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_0801A5C8
sub_0801A5C8:
	adds r3, r0, #0x0
	adds r2, r1, #0x0
	cmp r2, #0x00
	beq _0801A5DE
	ldr r0, [r2, #0x04]
	ldr r1, [r3, #0x4C]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r1, [r0, #0x00]
	str r1, [r2, #0x00]
	str r2, [r0, #0x00]
	.global _0801A5DE
_0801A5DE:
	bx lr
	thumb_func_start sub_0801A5E0
sub_0801A5E0:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r9, r0
	adds r5, r1, #0x0
	adds r4, r2, #0x0
	mov r8, r3
	ldr r6, [r5, #0x10]
	adds r3, r5, #0x0
	adds r3, #0x14
	movs r7, #0x00
	ldr r0, _0801A674 @ =0x0000FFFF
	mov r12, r0
	.global _0801A5FC
_0801A5FC:
	ldr r1, [r3, #0x00]
	adds r0, r1, #0x0
	mov r2, r12
	ands r0, r2
	adds r2, r0, #0x0
	muls r2, r4
	add r2, r8
	lsrs r1, r1, #0x10
	adds r0, r1, #0x0
	muls r0, r4
	lsrs r1, r2, #0x10
	adds r0, r0, r1
	lsrs r1, r0, #0x10
	mov r8, r1
	lsls r0, r0, #0x10
	mov r1, r12
	ands r2, r1
	adds r0, r0, r2
	stm r3!, {r0}
	adds r7, #0x01
	cmp r7, r6
	blt _0801A5FC
	mov r2, r8
	cmp r2, #0x00
	beq _0801A66A
	ldr r0, [r5, #0x08]
	cmp r6, r0
	blt _0801A65A
	ldr r1, [r5, #0x04]
	adds r1, #0x01
	mov r0, r9
	bl sub_0801A570
	adds r4, r0, #0x0
	adds r0, #0x0C
	adds r1, r5, #0x0
	adds r1, #0x0C
	ldr r2, [r5, #0x10]
	lsls r2, r2, #0x02
	adds r2, #0x08
	bl sub_0801A42C
	mov r0, r9
	adds r1, r5, #0x0
	bl sub_0801A5C8
	adds r5, r4, #0x0
	.global _0801A65A
_0801A65A:
	lsls r1, r6, #0x02
	adds r0, r5, #0x0
	adds r0, #0x14
	adds r0, r0, r1
	mov r1, r8
	str r1, [r0, #0x00]
	adds r6, #0x01
	str r6, [r5, #0x10]
	.global _0801A66A
_0801A66A:
	adds r0, r5, #0x0
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7, pc}
	.global _0801A674
_0801A674: .4byte 0x0000FFFF
	.byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x07, 0x1C, 0x0C, 0x1C, 0x16, 0x1C, 0x98, 0x46, 0x40, 0x46
	.byte 0x08, 0x30, 0x09, 0x21, 0xFC, 0xF7, 0xD0, 0xFD, 0x00, 0x21, 0x01, 0x22, 0x01, 0x28, 0x03, 0xDD
	.byte 0x52, 0x00, 0x01, 0x31, 0x90, 0x42, 0xFB, 0xDC, 0x38, 0x1C, 0xFF, 0xF7, 0x65, 0xFF, 0x01, 0x1C
	.byte 0x06, 0x98, 0x48, 0x61, 0x01, 0x20, 0x08, 0x61, 0x09, 0x25, 0x09, 0x2E, 0x0D, 0xDD, 0x09, 0x34
	.byte 0x23, 0x78, 0x30, 0x3B, 0x01, 0x34, 0x38, 0x1C, 0x0A, 0x22, 0xFF, 0xF7, 0x8D, 0xFF, 0x01, 0x1C
	.byte 0x01, 0x35, 0xB5, 0x42, 0xF4, 0xDB, 0x01, 0x34, 0x00, 0xE0, 0x0A, 0x34, 0x45, 0x45, 0x0C, 0xDA
	.byte 0x40, 0x46, 0x45, 0x1B, 0x23, 0x78, 0x30, 0x3B, 0x01, 0x34, 0x38, 0x1C, 0x0A, 0x22, 0xFF, 0xF7
	.byte 0x7B, 0xFF, 0x01, 0x1C, 0x01, 0x3D, 0x00, 0x2D, 0xF4, 0xD1, 0x08, 0x1C, 0x08, 0xBC, 0x98, 0x46
	.byte 0xF0, 0xBD, 0x00, 0x00
	thumb_func_start sub_0801A6FC
sub_0801A6FC:
	adds r1, r0, #0x0
	movs r2, #0x00
	ldr r0, _0801A74C @ =0xFFFF0000
	ands r0, r1
	cmp r0, #0x00
	bne _0801A70C
	movs r2, #0x10
	lsls r1, r1, #0x10
	.global _0801A70C
_0801A70C:
	movs r0, #0xFF
	lsls r0, r0, #0x18
	ands r0, r1
	cmp r0, #0x00
	bne _0801A71A
	adds r2, #0x08
	lsls r1, r1, #0x08
	.global _0801A71A
_0801A71A:
	movs r0, #0xF0
	lsls r0, r0, #0x18
	ands r0, r1
	cmp r0, #0x00
	bne _0801A728
	adds r2, #0x04
	lsls r1, r1, #0x04
	.global _0801A728
_0801A728:
	movs r0, #0xC0
	lsls r0, r0, #0x18
	ands r0, r1
	cmp r0, #0x00
	bne _0801A736
	adds r2, #0x02
	lsls r1, r1, #0x02
	.global _0801A736
_0801A736:
	cmp r1, #0x00
	blt _0801A750
	adds r2, #0x01
	movs r0, #0x80
	lsls r0, r0, #0x17
	ands r0, r1
	cmp r0, #0x00
	bne _0801A750
	movs r0, #0x20
	b _0801A752
	.byte 0x00, 0x00
	.global _0801A74C
_0801A74C: .4byte 0xFFFF0000
	.global _0801A750
_0801A750:
	adds r0, r2, #0x0
	.global _0801A752
_0801A752:
	bx lr
	thumb_func_start sub_0801A754
sub_0801A754:
	adds r3, r0, #0x0
	ldr r1, [r3, #0x00]
	movs r0, #0x07
	ands r0, r1
	cmp r0, #0x00
	beq _0801A784
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0801A76C
	movs r0, #0x00
	b _0801A7D4
	.global _0801A76C
_0801A76C:
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _0801A77C
	lsrs r0, r1, #0x01
	str r0, [r3, #0x00]
	movs r0, #0x01
	b _0801A7D4
	.global _0801A77C
_0801A77C:
	lsrs r0, r1, #0x02
	str r0, [r3, #0x00]
	movs r0, #0x02
	b _0801A7D4
	.global _0801A784
_0801A784:
	movs r2, #0x00
	ldr r0, _0801A7CC @ =0x0000FFFF
	ands r0, r1
	cmp r0, #0x00
	bne _0801A792
	movs r2, #0x10
	lsrs r1, r1, #0x10
	.global _0801A792
_0801A792:
	movs r0, #0xFF
	ands r0, r1
	cmp r0, #0x00
	bne _0801A79E
	adds r2, #0x08
	lsrs r1, r1, #0x08
	.global _0801A79E
_0801A79E:
	movs r0, #0x0F
	ands r0, r1
	cmp r0, #0x00
	bne _0801A7AA
	adds r2, #0x04
	lsrs r1, r1, #0x04
	.global _0801A7AA
_0801A7AA:
	movs r0, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0801A7B6
	adds r2, #0x02
	lsrs r1, r1, #0x02
	.global _0801A7B6
_0801A7B6:
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _0801A7D0
	adds r2, #0x01
	lsrs r1, r1, #0x01
	cmp r1, #0x00
	bne _0801A7D0
	movs r0, #0x20
	b _0801A7D4
	.byte 0x00, 0x00
	.global _0801A7CC
_0801A7CC: .4byte 0x0000FFFF
	.global _0801A7D0
_0801A7D0:
	str r1, [r3, #0x00]
	adds r0, r2, #0x0
	.global _0801A7D4
_0801A7D4:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0801A7D8
sub_0801A7D8:
	push {r4, lr}
	adds r4, r1, #0x0
	movs r1, #0x01
	bl sub_0801A570
	str r4, [r0, #0x14]
	movs r1, #0x01
	str r1, [r0, #0x10]
	pop {r4, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_0801A7EC
sub_0801A7EC:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x024
	adds r3, r0, #0x0
	adds r4, r1, #0x0
	adds r5, r2, #0x0
	ldr r1, [r4, #0x10]
	ldr r0, [r5, #0x10]
	cmp r1, r0
	bge _0801A80C
	str r4, [sp, #0x000]
	adds r4, r5, #0x0
	ldr r5, [sp, #0x000]
	.global _0801A80C
_0801A80C:
	ldr r1, [r4, #0x04]
	ldr r6, [r4, #0x10]
	ldr r0, [r5, #0x10]
	mov r8, r0
	mov r2, r8
	adds r2, r6, r2
	str r2, [sp, #0x004]
	ldr r0, [r4, #0x08]
	cmp r2, r0
	ble _0801A822
	adds r1, #0x01
	.global _0801A822
_0801A822:
	adds r0, r3, #0x0
	bl sub_0801A570
	str r0, [sp, #0x000]
	adds r7, r0, #0x0
	adds r7, #0x14
	ldr r1, [sp, #0x004]
	lsls r0, r1, #0x02
	adds r2, r7, r0
	str r2, [sp, #0x008]
	str r0, [sp, #0x018]
	adds r1, r4, #0x0
	adds r1, #0x14
	lsls r3, r6, #0x02
	adds r2, r5, #0x0
	adds r2, #0x14
	mov r5, r8
	lsls r4, r5, #0x02
	ldr r0, [sp, #0x008]
	cmp r7, r0
	bcs _0801A856
	movs r0, #0x00
	.global _0801A84E
_0801A84E:
	stm r7!, {r0}
	ldr r5, [sp, #0x008]
	cmp r7, r5
	bcc _0801A84E
	.global _0801A856
_0801A856:
	str r1, [sp, #0x008]
	adds r3, r1, r3
	str r3, [sp, #0x00C]
	mov r8, r2
	add r4, r8
	str r4, [sp, #0x010]
	ldr r0, [sp, #0x000]
	adds r0, #0x14
	mov r9, r0
	mov r1, r9
	str r1, [sp, #0x020]
	cmp r8, r4
	bcs _0801A91E
	.global _0801A870
_0801A870:
	mov r2, r8
	ldm r2!, {r6}
	str r2, [sp, #0x014]
	ldr r0, _0801A92C @ =0x0000FFFF
	ands r6, r0
	mov r4, r9
	adds r4, #0x04
	str r4, [sp, #0x01C]
	cmp r6, #0x00
	beq _0801A8C8
	ldr r7, [sp, #0x008]
	mov r5, r9
	movs r1, #0x00
	mov r12, r1
	mov r10, r0
	.global _0801A88E
_0801A88E:
	ldm r7!, {r3}
	adds r0, r3, #0x0
	mov r2, r10
	ands r0, r2
	adds r1, r0, #0x0
	muls r1, r6
	ldr r2, [r5, #0x00]
	adds r0, r2, #0x0
	mov r4, r10
	ands r0, r4
	adds r1, r1, r0
	mov r0, r12
	adds r4, r1, r0
	lsrs r1, r4, #0x10
	lsrs r3, r3, #0x10
	adds r0, r3, #0x0
	muls r0, r6
	lsrs r2, r2, #0x10
	adds r0, r0, r2
	adds r2, r0, r1
	lsrs r0, r2, #0x10
	mov r12, r0
	strh r2, [r5, #0x00]
	strh r4, [r5, #0x02]
	adds r5, #0x04
	ldr r1, [sp, #0x00C]
	cmp r7, r1
	bcc _0801A88E
	str r0, [r5, #0x00]
	.global _0801A8C8
_0801A8C8:
	mov r2, r8
	ldrh r6, [r2, #0x02]
	cmp r6, #0x00
	beq _0801A910
	ldr r7, [sp, #0x008]
	mov r5, r9
	movs r4, #0x00
	mov r12, r4
	ldr r2, [r5, #0x00]
	ldr r3, _0801A92C @ =0x0000FFFF
	.global _0801A8DC
_0801A8DC:
	ldm r7!, {r1}
	adds r0, r1, #0x0
	ands r0, r3
	muls r0, r6
	ldrh r4, [r5, #0x02]
	adds r4, r4, r0
	mov r8, r4
	add r4, r12
	lsrs r0, r4, #0x10
	mov r12, r0
	strh r4, [r5, #0x00]
	strh r2, [r5, #0x02]
	adds r5, #0x04
	lsrs r1, r1, #0x10
	muls r1, r6
	ldr r0, [r5, #0x00]
	ands r0, r3
	adds r1, r1, r0
	mov r4, r12
	adds r2, r1, r4
	lsrs r0, r2, #0x10
	mov r12, r0
	ldr r1, [sp, #0x00C]
	cmp r7, r1
	bcc _0801A8DC
	str r2, [r5, #0x00]
	.global _0801A910
_0801A910:
	ldr r2, [sp, #0x014]
	mov r8, r2
	ldr r4, [sp, #0x01C]
	mov r9, r4
	ldr r5, [sp, #0x010]
	cmp r8, r5
	bcc _0801A870
	.global _0801A91E
_0801A91E:
	ldr r0, [sp, #0x020]
	ldr r1, [sp, #0x018]
	adds r5, r0, r1
	ldr r2, [sp, #0x004]
	cmp r2, #0x00
	ble _0801A942
	b _0801A93A
	.global _0801A92C
_0801A92C: .4byte 0x0000FFFF
	.global _0801A930
_0801A930:
	ldr r4, [sp, #0x004]
	subs r4, #0x01
	str r4, [sp, #0x004]
	cmp r4, #0x00
	ble _0801A942
	.global _0801A93A
_0801A93A:
	subs r5, #0x04
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _0801A930
	.global _0801A942
_0801A942:
	ldr r5, [sp, #0x004]
	ldr r0, [sp, #0x000]
	str r5, [r0, #0x10]
	ldr r0, [sp, #0x000]
	add sp, #0x024
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_0801A958
sub_0801A958:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0x0
	adds r6, r2, #0x0
	movs r1, #0x03
	ands r1, r6
	cmp r1, #0x00
	beq _0801A982
	ldr r0, _0801A9A4 @ =0x08339534
	subs r1, #0x01
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldr r2, [r1, #0x00]
	mov r0, r8
	adds r1, r7, #0x0
	movs r3, #0x00
	bl sub_0801A5E0
	adds r7, r0, #0x0
	.global _0801A982
_0801A982:
	asrs r6, r6, #0x02
	cmp r6, #0x00
	beq _0801A9E8
	mov r0, r8
	ldr r5, [r0, #0x48]
	adds r4, r5, #0x0
	cmp r5, #0x00
	bne _0801A9C4
	ldr r1, _0801A9A8 @ =0x00000271
	bl sub_0801A7D8
	mov r1, r8
	str r0, [r1, #0x48]
	adds r5, r0, #0x0
	str r4, [r5, #0x00]
	b _0801A9C4
	.byte 0x00, 0x00
	.global _0801A9A4
_0801A9A4: .4byte 0x08339534
	.global _0801A9A8
_0801A9A8: .4byte 0x00000271
	.global _0801A9AC
_0801A9AC:
	ldr r0, [r5, #0x00]
	adds r4, r0, #0x0
	cmp r0, #0x00
	bne _0801A9C2
	mov r0, r8
	adds r1, r5, #0x0
	adds r2, r5, #0x0
	bl sub_0801A7EC
	str r0, [r5, #0x00]
	str r4, [r0, #0x00]
	.global _0801A9C2
_0801A9C2:
	adds r5, r0, #0x0
	.global _0801A9C4
_0801A9C4:
	movs r0, #0x01
	ands r0, r6
	cmp r0, #0x00
	beq _0801A9E2
	mov r0, r8
	adds r1, r7, #0x0
	adds r2, r5, #0x0
	bl sub_0801A7EC
	adds r4, r0, #0x0
	mov r0, r8
	adds r1, r7, #0x0
	bl sub_0801A5C8
	adds r7, r4, #0x0
	.global _0801A9E2
_0801A9E2:
	asrs r6, r6, #0x01
	cmp r6, #0x00
	bne _0801A9AC
	.global _0801A9E8
_0801A9E8:
	adds r0, r7, #0x0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	thumb_func_start sub_0801A9F0
sub_0801A9F0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	mov r10, r0
	mov r8, r1
	adds r5, r2, #0x0
	asrs r6, r5, #0x05
	ldr r1, [r1, #0x04]
	mov r2, r8
	ldr r0, [r2, #0x10]
	adds r0, r6, r0
	adds r7, r0, #0x1
	ldr r2, [r2, #0x08]
	cmp r7, r2
	ble _0801AA1A
	.global _0801AA12
_0801AA12:
	adds r1, #0x01
	lsls r2, r2, #0x01
	cmp r7, r2
	bgt _0801AA12
	.global _0801AA1A
_0801AA1A:
	mov r0, r10
	bl sub_0801A570
	mov r9, r0
	mov r4, r9
	adds r4, #0x14
	mov r0, r8
	adds r0, #0x14
	cmp r6, #0x00
	ble _0801AA3A
	movs r1, #0x00
	adds r2, r6, #0x0
	.global _0801AA32
_0801AA32:
	stm r4!, {r1}
	subs r2, #0x01
	cmp r2, #0x00
	bne _0801AA32
	.global _0801AA3A
_0801AA3A:
	adds r3, r0, #0x0
	mov r1, r8
	ldr r0, [r1, #0x10]
	lsls r0, r0, #0x02
	adds r6, r3, r0
	movs r0, #0x1F
	ands r5, r0
	cmp r5, #0x00
	beq _0801AA6C
	movs r0, #0x20
	subs r1, r0, r5
	movs r2, #0x00
	.global _0801AA52
_0801AA52:
	ldr r0, [r3, #0x00]
	lsls r0, r5
	orrs r0, r2
	stm r4!, {r0}
	ldm r3!, {r2}
	lsrs r2, r1
	cmp r3, r6
	bcc _0801AA52
	str r2, [r4, #0x00]
	cmp r2, #0x00
	beq _0801AA74
	adds r7, #0x01
	b _0801AA74
	.global _0801AA6C
_0801AA6C:
	ldm r3!, {r0}
	stm r4!, {r0}
	cmp r3, r6
	bcc _0801AA6C
	.global _0801AA74
_0801AA74:
	subs r0, r7, #0x1
	mov r2, r9
	str r0, [r2, #0x10]
	mov r0, r10
	mov r1, r8
	bl sub_0801A5C8
	mov r0, r9
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_0801AA90
sub_0801AA90:
	push {r4, r5, lr}
	adds r2, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, [r2, #0x10]
	ldr r1, [r5, #0x10]
	subs r0, r0, r1
	cmp r0, #0x00
	bne _0801AACC
	adds r4, r2, #0x0
	adds r4, #0x14
	lsls r1, r1, #0x02
	adds r3, r4, r1
	adds r0, r5, #0x0
	adds r0, #0x14
	adds r1, r0, r1
	.global _0801AAAE
_0801AAAE:
	subs r3, #0x04
	subs r1, #0x04
	ldr r0, [r3, #0x00]
	ldr r2, [r1, #0x00]
	cmp r0, r2
	beq _0801AAC6
	movs r1, #0x01
	cmp r0, r2
	bcs _0801AAC2
	subs r1, #0x02
	.global _0801AAC2
_0801AAC2:
	adds r0, r1, #0x0
	b _0801AACC
	.global _0801AAC6
_0801AAC6:
	cmp r3, r4
	bhi _0801AAAE
	movs r0, #0x00
	.global _0801AACC
_0801AACC:
	pop {r4, r5, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_0801AAD0
sub_0801AAD0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	mov r8, r2
	adds r0, r5, #0x0
	mov r1, r8
	bl sub_0801AA90
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _0801AB02
	adds r0, r6, #0x0
	movs r1, #0x00
	bl sub_0801A570
	adds r7, r0, #0x0
	movs r0, #0x01
	str r0, [r7, #0x10]
	str r4, [r7, #0x14]
	b _0801ABB2
	.global _0801AB02
_0801AB02:
	cmp r4, #0x00
	bge _0801AB10
	adds r7, r5, #0x0
	mov r5, r8
	mov r8, r7
	movs r4, #0x01
	b _0801AB12
	.global _0801AB10
_0801AB10:
	movs r4, #0x00
	.global _0801AB12
_0801AB12:
	ldr r1, [r5, #0x04]
	adds r0, r6, #0x0
	bl sub_0801A570
	adds r7, r0, #0x0
	str r4, [r7, #0x0C]
	ldr r0, [r5, #0x10]
	mov r9, r0
	adds r6, r5, #0x0
	adds r6, #0x14
	lsls r0, r0, #0x02
	adds r0, r0, r6
	mov r10, r0
	mov r1, r8
	ldr r0, [r1, #0x10]
	movs r3, #0x14
	add r3, r8
	mov r12, r3
	lsls r0, r0, #0x02
	add r0, r12
	str r0, [sp, #0x000]
	adds r4, r7, #0x0
	adds r4, #0x14
	movs r5, #0x00
	ldr r0, _0801AB9C @ =0x0000FFFF
	mov r8, r0
	.global _0801AB46
_0801AB46:
	ldm r6!, {r1}
	str r1, [sp, #0x004]
	mov r3, r8
	ands r1, r3
	mov r0, r12
	adds r0, #0x04
	mov r12, r0
	subs r0, #0x04
	ldm r0!, {r2}
	adds r0, r2, #0x0
	ands r0, r3
	subs r1, r1, r0
	adds r0, r1, r5
	asrs r5, r0, #0x10
	ldr r1, [sp, #0x004]
	lsrs r3, r1, #0x10
	lsrs r2, r2, #0x10
	subs r3, r3, r2
	adds r1, r3, r5
	asrs r5, r1, #0x10
	strh r1, [r4, #0x00]
	strh r0, [r4, #0x02]
	adds r4, #0x04
	ldr r3, [sp, #0x000]
	cmp r12, r3
	bcc _0801AB46
	cmp r6, r10
	bcs _0801ABA6
	ldr r2, _0801AB9C @ =0x0000FFFF
	.global _0801AB80
_0801AB80:
	ldm r6!, {r1}
	adds r0, r1, #0x0
	ands r0, r2
	adds r0, r0, r5
	asrs r5, r0, #0x10
	lsrs r1, r1, #0x10
	adds r1, r1, r5
	asrs r5, r1, #0x10
	strh r1, [r4, #0x00]
	strh r0, [r4, #0x02]
	adds r4, #0x04
	cmp r6, r10
	bcc _0801AB80
	b _0801ABA6
	.global _0801AB9C
_0801AB9C: .4byte 0x0000FFFF
	.global _0801ABA0
_0801ABA0:
	movs r0, #0x01
	negs r0, r0
	add r9, r0
	.global _0801ABA6
_0801ABA6:
	subs r4, #0x04
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0801ABA0
	mov r1, r9
	str r1, [r7, #0x10]
	.global _0801ABB2
_0801ABB2:
	adds r0, r7, #0x0
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7, pc}
	.byte 0x10, 0xB5, 0x04, 0x4A, 0x02, 0x40, 0x04, 0x48, 0x12, 0x18, 0x00, 0x2A, 0x06, 0xDD, 0x13, 0x1C
	.byte 0x00, 0x24, 0x18, 0xE0, 0x00, 0x00, 0xF0, 0x7F, 0x00, 0x00, 0xC0, 0xFC, 0x50, 0x42, 0x02, 0x15
	.byte 0x13, 0x2A, 0x05, 0xDC, 0x80, 0x20, 0x00, 0x03, 0x03, 0x1C, 0x13, 0x41, 0x00, 0x24, 0x0A, 0xE0
	.byte 0x00, 0x23, 0x14, 0x3A, 0x1E, 0x2A, 0x04, 0xDC, 0x1F, 0x20, 0x80, 0x1A, 0x01, 0x21, 0x81, 0x40
	.byte 0x00, 0xE0, 0x01, 0x21, 0x0C, 0x1C, 0x21, 0x1C, 0x18, 0x1C, 0x10, 0xBD
	thumb_func_start sub_0801AC0C
sub_0801AC0C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	adds r4, r1, #0x0
	movs r1, #0x14
	adds r1, r1, r0
	mov r8, r1
	ldr r0, [r0, #0x10]
	lsls r0, r0, #0x02
	adds r5, r1, r0
	subs r5, #0x04
	ldr r2, [r5, #0x00]
	adds r0, r2, #0x0
	str r2, [sp, #0x000]
	bl sub_0801A6FC
	adds r3, r0, #0x0
	movs r0, #0x20
	subs r0, r0, r3
	str r0, [r4, #0x00]
	ldr r2, [sp, #0x000]
	cmp r3, #0x0A
	bgt _0801AC6C
	movs r0, #0x0B
	subs r0, r0, r3
	adds r1, r2, #0x0
	lsrs r1, r0
	ldr r0, _0801AC54 @ =0x3FF00000
	adds r6, r1, #0x0
	orrs r6, r0
	cmp r5, r8
	bls _0801AC58
	subs r5, #0x04
	ldr r1, [r5, #0x00]
	b _0801AC5A
	.global _0801AC54
_0801AC54: .4byte 0x3FF00000
	.global _0801AC58
_0801AC58:
	movs r1, #0x00
	.global _0801AC5A
_0801AC5A:
	adds r0, r3, #0x0
	adds r0, #0x15
	lsls r2, r0
	movs r0, #0x0B
	subs r0, r0, r3
	lsrs r1, r0
	adds r7, r2, #0x0
	orrs r7, r1
	b _0801ACB8
	.global _0801AC6C
_0801AC6C:
	cmp r5, r8
	bls _0801AC76
	subs r5, #0x04
	ldr r4, [r5, #0x00]
	b _0801AC78
	.global _0801AC76
_0801AC76:
	movs r4, #0x00
	.global _0801AC78
_0801AC78:
	subs r3, #0x0B
	cmp r3, #0x00
	beq _0801ACB0
	lsls r2, r3
	movs r0, #0x20
	subs r0, r0, r3
	adds r1, r4, #0x0
	lsrs r1, r0
	ldr r0, _0801AC9C @ =0x3FF00000
	orrs r1, r0
	adds r6, r2, #0x0
	orrs r6, r1
	cmp r5, r8
	bls _0801ACA0
	subs r5, #0x04
	ldr r2, [r5, #0x00]
	b _0801ACA2
	.byte 0x00, 0x00
	.global _0801AC9C
_0801AC9C: .4byte 0x3FF00000
	.global _0801ACA0
_0801ACA0:
	movs r2, #0x00
	.global _0801ACA2
_0801ACA2:
	lsls r4, r3
	movs r0, #0x20
	subs r0, r0, r3
	lsrs r2, r0
	adds r7, r4, #0x0
	orrs r7, r2
	b _0801ACB8
	.global _0801ACB0
_0801ACB0:
	ldr r0, _0801ACC4 @ =0x3FF00000
	adds r6, r2, #0x0
	orrs r6, r0
	adds r7, r4, #0x0
	.global _0801ACB8
_0801ACB8:
	adds r1, r7, #0x0
	adds r0, r6, #0x0
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.global _0801ACC4
_0801ACC4: .4byte 0x3FF00000
	thumb_func_start sub_0801ACC8
sub_0801ACC8:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	mov r9, r3
	ldr r3, [sp, #0x028]
	mov r10, r3
	adds r5, r2, #0x0
	adds r4, r1, #0x0
	movs r1, #0x01
	bl sub_0801A570
	adds r6, r0, #0x0
	movs r0, #0x14
	adds r0, r0, r6
	mov r8, r0
	ldr r2, _0801AD30 @ =0x000FFFFF
	adds r1, r4, #0x0
	ands r2, r1
	str r2, [sp, #0x004]
	ldr r0, _0801AD34 @ =0x7FFFFFFF
	ands r4, r0
	lsrs r7, r4, #0x14
	cmp r7, #0x00
	beq _0801AD06
	movs r0, #0x80
	lsls r0, r0, #0x0D
	orrs r0, r2
	str r0, [sp, #0x004]
	.global _0801AD06
_0801AD06:
	str r5, [sp, #0x000]
	cmp r5, #0x00
	beq _0801AD50
	mov r0, sp
	bl sub_0801A754
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0801AD38
	movs r0, #0x20
	subs r0, r0, r2
	ldr r1, [sp, #0x004]
	lsls r1, r0
	ldr r0, [sp, #0x000]
	orrs r0, r1
	str r0, [r6, #0x14]
	ldr r0, [sp, #0x004]
	lsrs r0, r2
	str r0, [sp, #0x004]
	b _0801AD3C
	.byte 0x00, 0x00
	.global _0801AD30
_0801AD30: .4byte 0x000FFFFF
	.global _0801AD34
_0801AD34: .4byte 0x7FFFFFFF
	.global _0801AD38
_0801AD38:
	ldr r0, [sp, #0x000]
	str r0, [r6, #0x14]
	.global _0801AD3C
_0801AD3C:
	ldr r0, [sp, #0x004]
	mov r1, r8
	str r0, [r1, #0x04]
	movs r1, #0x01
	cmp r0, #0x00
	beq _0801AD4A
	movs r1, #0x02
	.global _0801AD4A
_0801AD4A:
	str r1, [r6, #0x10]
	adds r4, r1, #0x0
	b _0801AD64
	.global _0801AD50
_0801AD50:
	add r0, sp, #0x004
	bl sub_0801A754
	adds r2, r0, #0x0
	ldr r0, [sp, #0x004]
	str r0, [r6, #0x14]
	movs r0, #0x01
	str r0, [r6, #0x10]
	movs r4, #0x01
	adds r2, #0x20
	.global _0801AD64
_0801AD64:
	cmp r7, #0x00
	beq _0801AD80
	ldr r3, _0801AD7C @ =0xFFFFFBCD
	adds r0, r2, r3
	adds r0, r7, r0
	mov r1, r9
	str r0, [r1, #0x00]
	movs r0, #0x35
	subs r0, r0, r2
	mov r3, r10
	str r0, [r3, #0x00]
	b _0801AD9C
	.global _0801AD7C
_0801AD7C: .4byte 0xFFFFFBCD
	.global _0801AD80
_0801AD80:
	ldr r1, _0801ADAC @ =0xFFFFFBCE
	adds r0, r2, r1
	mov r3, r9
	str r0, [r3, #0x00]
	lsls r0, r4, #0x02
	add r0, r8
	subs r0, #0x04
	ldr r0, [r0, #0x00]
	bl sub_0801A6FC
	lsls r1, r4, #0x05
	subs r1, r1, r0
	mov r0, r10
	str r1, [r0, #0x00]
	.global _0801AD9C
_0801AD9C:
	adds r0, r6, #0x0
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
	.global _0801ADAC
_0801ADAC: .4byte 0xFFFFFBCE
	.byte 0xF0, 0xB5, 0x84, 0xB0, 0x04, 0x1C, 0x0D, 0x1C, 0x69, 0x46, 0xFF, 0xF7, 0x27, 0xFF, 0x02, 0x90
	.byte 0x03, 0x91, 0x01, 0xA9, 0x28, 0x1C, 0xFF, 0xF7, 0x21, 0xFF, 0x0F, 0x1C, 0x06, 0x1C, 0x00, 0x9A
	.byte 0x01, 0x98, 0x12, 0x1A, 0x20, 0x69, 0x29, 0x69, 0x40, 0x1A, 0x40, 0x01, 0x10, 0x18, 0x00, 0x28
	.byte 0x04, 0xDD, 0x00, 0x05, 0x02, 0x99, 0x08, 0x18, 0x02, 0x90, 0x01, 0xE0, 0x00, 0x05, 0x36, 0x1A
	.byte 0x02, 0x98, 0x03, 0x99, 0x3B, 0x1C, 0x32, 0x1C, 0x00, 0xF0, 0xC6, 0xFF, 0x04, 0xB0, 0xF0, 0xBD
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x05, 0x49, 0x04, 0x48, 0x17, 0x2C, 0x0B, 0xDC, 0x04, 0x48, 0xE1, 0x00
	.byte 0x09, 0x18, 0x08, 0x68, 0x49, 0x68, 0x0E, 0xE0, 0x00, 0x00, 0xF0, 0x3F, 0x00, 0x00, 0x00, 0x00
	.byte 0x40, 0x95, 0x33, 0x08, 0x00, 0x2C, 0x06, 0xDD, 0x04, 0x4B, 0x03, 0x4A, 0x00, 0xF0, 0x58, 0xFE
	.byte 0x01, 0x3C, 0x00, 0x2C, 0xF8, 0xDC, 0x10, 0xBD, 0x00, 0x00, 0x24, 0x40, 0x00, 0x00, 0x00, 0x00
	.byte 0x06, 0x4B, 0x03, 0x40, 0x4A, 0x42, 0x0A, 0x43, 0xD2, 0x0F, 0x13, 0x43, 0x04, 0x48, 0xC3, 0x1A
	.byte 0x58, 0x42, 0x03, 0x43, 0xDB, 0x0F, 0x01, 0x20, 0xC0, 0x1A, 0x70, 0x47, 0xFF, 0xFF, 0xFF, 0x7F
	.byte 0x00, 0x00, 0xF0, 0x7F, 0x05, 0x4B, 0x03, 0x40, 0x4A, 0x42, 0x0A, 0x43, 0xD2, 0x0F, 0x13, 0x43
	.byte 0x03, 0x48, 0xC3, 0x1A, 0xDB, 0x0F, 0x18, 0x1C, 0x70, 0x47, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x7F
	.byte 0x00, 0x00, 0xF0, 0x7F
	thumb_func_start sub_0801AE84
sub_0801AE84:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r0, r1, #0x0
	ldr r4, _0801AEAC @ =0x0202F244
	movs r1, #0x00
	str r1, [r4, #0x00]
	bl sub_0801B3D4
	adds r1, r0, #0x0
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	bne _0801AEA6
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0801AEA6
	str r0, [r5, #0x00]
	.global _0801AEA6
_0801AEA6:
	adds r0, r1, #0x0
	pop {r4, r5, pc}
	.byte 0x00, 0x00
	.global _0801AEAC
_0801AEAC: .4byte 0x0202F244
	.byte 0x30, 0xB5, 0x05, 0x1C, 0x0C, 0x1C, 0x13, 0x1C, 0x68, 0x6D, 0x0E, 0x22, 0xA9, 0x5E, 0x22, 0x1C
	.byte 0x00, 0xF0, 0x7C, 0xFB, 0x01, 0x1C, 0x00, 0x29, 0x03, 0xDB, 0x28, 0x6D, 0x40, 0x18, 0x28, 0x65
	.byte 0x03, 0xE0, 0x03, 0x48, 0xAA, 0x89, 0x10, 0x40, 0xA8, 0x81, 0x08, 0x1C, 0x30, 0xBD, 0x00, 0x00
	.byte 0xFF, 0xEF, 0xFF, 0xFF, 0x70, 0xB5, 0x04, 0x1C, 0x0D, 0x1C, 0x16, 0x1C, 0x80, 0x20, 0x40, 0x00
	.byte 0xA1, 0x89, 0x08, 0x40, 0x00, 0x28, 0x06, 0xD0, 0x60, 0x6D, 0x0E, 0x22, 0xA1, 0x5E, 0x00, 0x22
	.byte 0x02, 0x23, 0x00, 0xF0, 0x43, 0xFB, 0x06, 0x48, 0xA1, 0x89, 0x08, 0x40, 0xA0, 0x81, 0x60, 0x6D
	.byte 0x0E, 0x22, 0xA1, 0x5E, 0x2A, 0x1C, 0x33, 0x1C, 0x00, 0xF0, 0xAE, 0xFA, 0x70, 0xBD, 0x00, 0x00
	.byte 0xFF, 0xEF, 0xFF, 0xFF, 0x30, 0xB5, 0x05, 0x1C, 0x0C, 0x1C, 0x13, 0x1C, 0x68, 0x6D, 0x0E, 0x22
	.byte 0xA9, 0x5E, 0x22, 0x1C, 0x00, 0xF0, 0x2A, 0xFB, 0x01, 0x1C, 0x01, 0x20, 0x40, 0x42, 0x81, 0x42
	.byte 0x06, 0xD1, 0x02, 0x48, 0xAA, 0x89, 0x10, 0x40, 0xA8, 0x81, 0x08, 0xE0, 0xFF, 0xEF, 0xFF, 0xFF
	.byte 0x80, 0x22, 0x52, 0x01, 0x10, 0x1C, 0xAA, 0x89, 0x10, 0x43, 0xA8, 0x81, 0x29, 0x65, 0x08, 0x1C
	.byte 0x30, 0xBD, 0x00, 0x00, 0x00, 0xB5, 0x42, 0x6D, 0x0E, 0x23, 0xC1, 0x5E, 0x10, 0x1C, 0x00, 0xF0
	.byte 0xC7, 0xFA, 0x00, 0xBD
	thumb_func_start sub_0801AF74
sub_0801AF74:
	push {r4, r5, lr}
	adds r2, r0, #0x0
	adds r3, r1, #0x0
	orrs r0, r3
	movs r1, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0801AFBA
	ldr r1, [r2, #0x00]
	ldr r0, [r3, #0x00]
	cmp r1, r0
	bne _0801AFBA
	ldr r5, _0801AFA0 @ =0xFEFEFEFF
	ldr r4, _0801AFA4 @ =0x80808080
	.global _0801AF90
_0801AF90:
	ldr r1, [r2, #0x00]
	adds r0, r1, r5
	bics r0, r1
	ands r0, r4
	cmp r0, #0x00
	beq _0801AFA8
	movs r0, #0x00
	b _0801AFCC
	.global _0801AFA0
_0801AFA0: .4byte 0xFEFEFEFF
	.global _0801AFA4
_0801AFA4: .4byte 0x80808080
	.global _0801AFA8
_0801AFA8:
	adds r2, #0x04
	adds r3, #0x04
	ldr r1, [r2, #0x00]
	ldr r0, [r3, #0x00]
	cmp r1, r0
	beq _0801AF90
	b _0801AFBA
	.global _0801AFB6
_0801AFB6:
	adds r2, #0x01
	adds r3, #0x01
	.global _0801AFBA
_0801AFBA:
	ldrb r0, [r2, #0x00]
	cmp r0, #0x00
	beq _0801AFC6
	ldrb r1, [r3, #0x00]
	cmp r0, r1
	beq _0801AFB6
	.global _0801AFC6
_0801AFC6:
	ldrb r2, [r2, #0x00]
	ldrb r3, [r3, #0x00]
	subs r0, r2, r3
	.global _0801AFCC
_0801AFCC:
	pop {r4, r5, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_0801AFD0
sub_0801AFD0:
	push {r4, r5, lr}
	adds r1, r0, #0x0
	adds r5, r1, #0x0
	movs r0, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0801B008
	adds r2, r1, #0x0
	ldr r1, [r2, #0x00]
	ldr r4, _0801AFEC @ =0xFEFEFEFF
	adds r0, r1, r4
	bics r0, r1
	ldr r3, _0801AFF0 @ =0x80808080
	b _0801AFFC
	.global _0801AFEC
_0801AFEC: .4byte 0xFEFEFEFF
	.global _0801AFF0
_0801AFF0: .4byte 0x80808080
	.global _0801AFF4
_0801AFF4:
	adds r2, #0x04
	ldr r1, [r2, #0x00]
	adds r0, r1, r4
	bics r0, r1
	.global _0801AFFC
_0801AFFC:
	ands r0, r3
	cmp r0, #0x00
	beq _0801AFF4
	adds r1, r2, #0x0
	b _0801B008
	.global _0801B006
_0801B006:
	adds r1, #0x01
	.global _0801B008
_0801B008:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0801B006
	subs r0, r1, r5
	pop {r4, r5, pc}
	.byte 0x00, 0x00
