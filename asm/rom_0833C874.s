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
	thumb_func_start sub_0833C874
sub_0833C874:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x020
	ldr r0, _0833C8FC @ =0x04000130
	ldrh r0, [r0, #0x00]
	mvns r0, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0x0
	bl sub_0833C70C
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r3, _0833C900 @ =0x020390BC
	ldr r0, [sp, #0x008]
	ldrb r2, [r3, #0x00]
	cmp r0, r2
	bge _0833C8C6
	ldr r5, _0833C904 @ =0x0203E160
	movs r2, #0x00
	ldr r4, _0833C908 @ =0x02039188
	.global _0833C8A8
_0833C8A8:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x03
	adds r0, r0, r5
	strh r2, [r0, #0x00]
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	adds r0, r0, r4
	strh r2, [r0, #0x00]
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldrb r6, [r3, #0x00]
	cmp r0, r6
	blt _0833C8A8
	.global _0833C8C6
_0833C8C6:
	movs r0, #0x00
	mov r10, r0
	movs r2, #0x00
	str r2, [sp, #0x018]
	movs r3, #0x00
	str r3, [sp, #0x01C]
	movs r4, #0x7F
	mov r9, r4
	adds r5, r1, #0x0
	ands r5, r4
	movs r6, #0x0F
	mov r8, r6
	ands r1, r6
	lsls r0, r1, #0x07
	orrs r5, r0
	.global _0833C8E4
_0833C8E4:
	ldr r0, _0833C900 @ =0x020390BC
	ldr r1, [sp, #0x01C]
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bls _0833C924
	ldr r0, _0833C90C @ =0x0203917C
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldr r0, _0833C910 @ =0x02039180
	strh r1, [r0, #0x00]
	movs r0, #0x01
	b _0833CC5A
	.global _0833C8FC
_0833C8FC: .4byte 0x04000130
	.global _0833C900
_0833C900: .4byte 0x020390BC
	.global _0833C904
_0833C904: .4byte 0x0203E160
	.global _0833C908
_0833C908: .4byte 0x02039188
	.global _0833C90C
_0833C90C: .4byte 0x0203917C
	.global _0833C910
_0833C910: .4byte 0x02039180
	.global _0833C914
_0833C914:
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r0, [sp, #0x01C]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x01C]
	b _0833C8E4
	.global _0833C924
_0833C924:
	mov r2, r10
	cmp r2, #0x00
	bne _0833C94C
	ldr r0, _0833C940 @ =0x02039180
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x0B
	orrs r0, r5
	ldr r3, _0833C944 @ =0xFFFF8000
	adds r1, r3, #0x0
	orrs r0, r1
	ldr r4, _0833C948 @ =0x0203DFB8
	strh r0, [r4, #0x00]
	adds r0, r4, #0x0
	b _0833C962
	.global _0833C940
_0833C940: .4byte 0x02039180
	.global _0833C944
_0833C944: .4byte 0xFFFF8000
	.global _0833C948
_0833C948: .4byte 0x0203DFB8
	.global _0833C94C
_0833C94C:
	ldr r0, _0833C97C @ =0x02039180
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x0B
	orrs r0, r5
	movs r6, #0x80
	lsls r6, r6, #0x07
	adds r1, r6, #0x0
	orrs r0, r1
	ldr r1, _0833C980 @ =0x0203DFB8
	strh r0, [r1, #0x00]
	adds r0, r1, #0x0
	.global _0833C962
_0833C962:
	ldrh r0, [r0, #0x00]
	bl sub_083448B0
	ldr r2, _0833C984 @ =0x03007FF8
	movs r0, #0x80
	ldrh r3, [r2, #0x00]
	ands r0, r3
	cmp r0, #0x00
	beq _0833C98C
	ldrh r0, [r2, #0x00]
	ldr r4, _0833C988 @ =0x0000FF7F
	adds r1, r4, #0x0
	b _0833C9A6
	.global _0833C97C
_0833C97C: .4byte 0x02039180
	.global _0833C980
_0833C980: .4byte 0x0203DFB8
	.global _0833C984
_0833C984: .4byte 0x03007FF8
	.global _0833C988
_0833C988: .4byte 0x0000FF7F
	.global _0833C98C
_0833C98C:
	ldr r1, _0833CAF0 @ =0x0203917C
	ldrh r0, [r1, #0x00]
	cmp r0, #0x64
	bhi _0833C914
	ldr r2, _0833CAF4 @ =0x03007FF8
	movs r0, #0x80
	ldrh r6, [r2, #0x00]
	ands r0, r6
	cmp r0, #0x00
	beq _0833C98C
	ldrh r0, [r2, #0x00]
	ldr r3, _0833CAF8 @ =0x0000FF7F
	adds r1, r3, #0x0
	.global _0833C9A6
_0833C9A6:
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r0, _0833CAFC @ =0x0203E1B0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833C9C8
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r1, _0833CB00 @ =0x00000257
	cmp r0, r1
	bgt _0833C9C8
	.global _0833C9BC
_0833C9BC:
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	cmp r0, r1
	ble _0833C9BC
	.global _0833C9C8
_0833C9C8:
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r3, _0833CB04 @ =0x020390BC
	ldr r0, [sp, #0x008]
	ldrb r4, [r3, #0x00]
	cmp r0, r4
	bge _0833C9F8
	ldr r2, _0833CB08 @ =0x0203E160
	.global _0833C9D8
_0833C9D8:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r6, sp
	adds r1, r6, r0
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x03
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldrb r1, [r3, #0x00]
	cmp r0, r1
	blt _0833C9D8
	.global _0833C9F8
_0833C9F8:
	mov r2, r10
	cmp r2, #0x00
	beq _0833CA00
	b _0833CB14
	.global _0833CA00
_0833CA00:
	movs r4, #0x00
	str r2, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r3, _0833CB04 @ =0x020390BC
	ldrb r3, [r3, #0x00]
	cmp r0, r3
	bge _0833CAAC
	movs r7, #0x0F
	ldr r6, _0833CB0C @ =0x0000FFFF
	.global _0833CA12
_0833CA12:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r1, sp
	adds r2, r1, r0
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r1, r0, #0x07
	mov r0, r8
	ldrh r2, [r2, #0x00]
	ands r0, r2
	ands r1, r7
	cmp r0, r1
	bne _0833CA9C
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	cmp r0, r6
	beq _0833CA9C
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833CA9C
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0E
	cmp r0, #0x02
	beq _0833CA64
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0E
	cmp r0, #0x01
	bne _0833CA9C
	.global _0833CA64
_0833CA64:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0B
	movs r1, #0x07
	ands r0, r1
	movs r1, #0x00
	bl sub_0833C828
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0833CA9C
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r2, sp
	adds r1, r2, r0
	mov r0, r9
	ldrh r1, [r1, #0x00]
	ands r0, r1
	bl sub_0833C858
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0833CA9C
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	.global _0833CA9C
_0833CA9C:
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r1, _0833CB04 @ =0x020390BC
	ldr r0, [sp, #0x008]
	ldrb r1, [r1, #0x00]
	cmp r0, r1
	blt _0833CA12
	.global _0833CAAC
_0833CAAC:
	ldr r3, _0833CB04 @ =0x020390BC
	ldrb r3, [r3, #0x00]
	cmp r4, r3
	beq _0833CAB6
	b _0833CC44
	.global _0833CAB6
_0833CAB6:
	movs r4, #0x01
	mov r10, r4
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r6, _0833CB04 @ =0x020390BC
	ldrb r6, [r6, #0x00]
	cmp r0, r6
	blt _0833CACA
	b _0833CC44
	.global _0833CACA
_0833CACA:
	ldr r3, _0833CB10 @ =0x02039188
	ldr r2, _0833CB04 @ =0x020390BC
	.global _0833CACE
_0833CACE:
	ldr r1, [sp, #0x008]
	lsls r1, r1, #0x01
	adds r1, r1, r3
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldrb r1, [r2, #0x00]
	cmp r0, r1
	blt _0833CACE
	b _0833CC44
	.byte 0x00, 0x00
	.global _0833CAF0
_0833CAF0: .4byte 0x0203917C
	.global _0833CAF4
_0833CAF4: .4byte 0x03007FF8
	.global _0833CAF8
_0833CAF8: .4byte 0x0000FF7F
	.global _0833CAFC
_0833CAFC: .4byte 0x0203E1B0
	.global _0833CB00
_0833CB00: .4byte 0x00000257
	.global _0833CB04
_0833CB04: .4byte 0x020390BC
	.global _0833CB08
_0833CB08: .4byte 0x0203E160
	.global _0833CB0C
_0833CB0C: .4byte 0x0000FFFF
	.global _0833CB10
_0833CB10: .4byte 0x02039188
	.global _0833CB14
_0833CB14:
	movs r4, #0x00
	str r4, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r2, _0833CBA4 @ =0x020390BC
	ldrb r2, [r2, #0x00]
	cmp r0, r2
	bge _0833CBFE
	.global _0833CB22
_0833CB22:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r3, sp
	adds r2, r3, r0
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r1, r0, #0x07
	mov r0, r8
	ldrh r2, [r2, #0x00]
	ands r0, r2
	mov r6, r8
	ands r1, r6
	cmp r0, r1
	bne _0833CBEE
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldr r0, _0833CBA8 @ =0x0000FFFF
	ldrh r1, [r1, #0x00]
	cmp r1, r0
	beq _0833CBEE
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833CBEE
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	adds r1, r3, r0
	mov r0, r9
	ldrh r1, [r1, #0x00]
	ands r0, r1
	bl sub_0833C858
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0833CBEE
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0E
	cmp r0, #0x01
	bne _0833CBAC
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0B
	movs r1, #0x07
	ands r0, r1
	movs r1, #0x00
	bl sub_0833C828
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0833CBAC
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	b _0833CBEE
	.byte 0x00, 0x00
	.global _0833CBA4
_0833CBA4: .4byte 0x020390BC
	.global _0833CBA8
_0833CBA8: .4byte 0x0000FFFF
	.global _0833CBAC
_0833CBAC:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0E
	cmp r0, #0x02
	bne _0833CBEE
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	add r0, sp
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x0B
	movs r1, #0x07
	ands r0, r1
	movs r1, #0x01
	bl sub_0833C828
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0833CBEE
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r1, sp
	adds r2, r1, r0
	ldr r1, _0833CC6C @ =0x02039188
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	strh r0, [r2, #0x00]
	.global _0833CBEE
_0833CBEE:
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r1, _0833CC70 @ =0x020390BC
	ldr r0, [sp, #0x008]
	ldrb r1, [r1, #0x00]
	cmp r0, r1
	blt _0833CB22
	.global _0833CBFE
_0833CBFE:
	ldr r2, _0833CC70 @ =0x020390BC
	ldrb r2, [r2, #0x00]
	cmp r4, r2
	bne _0833CC44
	movs r0, #0x00
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x008]
	ldr r3, _0833CC70 @ =0x020390BC
	ldrb r3, [r3, #0x00]
	cmp r0, r3
	bge _0833CC40
	ldr r4, _0833CC74 @ =0x020390B0
	.global _0833CC16
_0833CC16:
	ldr r0, [sp, #0x008]
	lsls r0, r0, #0x01
	mov r6, sp
	adds r1, r6, r0
	mov r0, r9
	ldrh r1, [r1, #0x00]
	ands r0, r1
	bl sub_0833C77C
	ldr r1, [sp, #0x008]
	lsls r1, r1, #0x01
	adds r1, r1, r4
	strh r0, [r1, #0x00]
	ldr r0, [sp, #0x008]
	adds r0, #0x01
	str r0, [sp, #0x008]
	ldr r1, _0833CC70 @ =0x020390BC
	ldr r0, [sp, #0x008]
	ldrb r1, [r1, #0x00]
	cmp r0, r1
	blt _0833CC16
	.global _0833CC40
_0833CC40:
	movs r0, #0x01
	str r0, [sp, #0x018]
	.global _0833CC44
_0833CC44:
	ldr r1, [sp, #0x018]
	cmp r1, #0x00
	bne _0833CC4C
	b _0833C8E4
	.global _0833CC4C
_0833CC4C:
	ldr r0, _0833CC78 @ =0x02039180
	ldrh r1, [r0, #0x00]
	adds r1, #0x01
	movs r2, #0x07
	ands r1, r2
	strh r1, [r0, #0x00]
	movs r0, #0x00
	.global _0833CC5A
_0833CC5A:
	add sp, #0x020
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _0833CC6C
_0833CC6C: .4byte 0x02039188
	.global _0833CC70
_0833CC70: .4byte 0x020390BC
	.global _0833CC74
_0833CC74: .4byte 0x020390B0
	.global _0833CC78
_0833CC78: .4byte 0x02039180
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0xB5, 0x12, 0x04, 0x16, 0x0C, 0x12, 0x4B, 0x02, 0x1C, 0x14, 0x88
	.byte 0x02, 0x32, 0x01, 0x25, 0xB5, 0x42, 0x19, 0xD2, 0x0C, 0x80, 0x02, 0x31, 0x9C, 0x42, 0x0D, 0xD1
	.byte 0x13, 0x88, 0x02, 0x32, 0x68, 0x1C, 0x00, 0x04, 0x05, 0x0C, 0x00, 0x2B, 0x06, 0xD0, 0x0C, 0x80
	.byte 0x02, 0x31, 0x58, 0x1E, 0x00, 0x04, 0x03, 0x0C, 0x00, 0x2B, 0xF8, 0xD1, 0x23, 0x1C, 0x14, 0x88
	.byte 0x02, 0x32, 0x68, 0x1C, 0x00, 0x04, 0x05, 0x0C, 0xB5, 0x42, 0xE5, 0xD3, 0x70, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00
	thumb_func_start sub_0833CCD4
sub_0833CCD4:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _0833CD18 @ =0x020251BC
	movs r1, #0x64
	adds r4, r0, #0x0
	muls r4, r1
	adds r0, r5, #0x4
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x07
	bl sub_08344B64
	adds r4, r4, r5
	ldr r0, [r4, #0x00]
	ldr r1, _0833CD1C @ =0x06008000
	movs r2, #0x80
	lsls r2, r2, #0x06
	bl sub_08344B64
	ldr r0, _0833CD20 @ =0x02039294
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldr r0, _0833CD24 @ =0x02039248
	strh r1, [r0, #0x00]
	ldr r0, _0833CD28 @ =0x020392A4
	strh r1, [r0, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833CD18
_0833CD18: .4byte 0x020251BC
	.global _0833CD1C
_0833CD1C: .4byte 0x06008000
	.global _0833CD20
_0833CD20: .4byte 0x02039294
	.global _0833CD24
_0833CD24: .4byte 0x02039248
	.global _0833CD28
_0833CD28: .4byte 0x020392A4
	thumb_func_start sub_0833CD2C
sub_0833CD2C:
	push {r4, r5, r6, lr}
	ldr r4, _0833CEBC @ =0xFFFFFDF8
	add sp, r4
	adds r6, r0, #0x0
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl sub_0833CCD4
	ldr r0, _0833CEC0 @ =0x02022428
	ldr r1, _0833CEC4 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08344B64
	ldr r5, _0833CEC8 @ =0x020251BC
	movs r0, #0x64
	adds r4, r6, #0x0
	muls r4, r0
	adds r0, r5, #0x0
	adds r0, #0x18
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x01
	add r1, sp, #0x008
	bl sub_08344B64
	ldr r0, _0833CECC @ =0x02021394
	add r1, sp, #0x1C8
	movs r2, #0x10
	bl sub_08344B64
	movs r0, #0x1E
	add r1, sp, #0x008
	bl sub_0833D31C
	ldr r1, _0833CED0 @ =0x02039244
	adds r0, r5, #0x0
	adds r0, #0x2C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CED4 @ =0x02039288
	adds r0, r5, #0x0
	adds r0, #0x34
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CED8 @ =0x02039228
	adds r0, r5, #0x0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEDC @ =0x02039268
	adds r0, r5, #0x0
	adds r0, #0x24
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEE0 @ =0x02039224
	adds r0, r5, #0x0
	adds r0, #0x28
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEE4 @ =0x02039238
	adds r0, r5, #0x0
	adds r0, #0x0C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEE8 @ =0x0203922C
	adds r0, r5, #0x0
	adds r0, #0x10
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEEC @ =0x020392A0
	adds r0, r5, #0x0
	adds r0, #0x3C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEF0 @ =0x02039280
	adds r0, r5, #0x0
	adds r0, #0x40
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEF4 @ =0x0203929C
	adds r0, r5, #0x0
	adds r0, #0x48
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	str r0, [r1, #0x00]
	cmp r6, #0x00
	bne _0833CDF6
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CDF6
_0833CDF6:
	cmp r6, #0x01
	bne _0833CE00
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x70
	str r0, [r1, #0x00]
	.global _0833CE00
_0833CE00:
	cmp r6, #0x02
	bne _0833CE0A
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0xA8
	str r0, [r1, #0x00]
	.global _0833CE0A
_0833CE0A:
	cmp r6, #0x03
	bne _0833CE14
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x6B
	str r0, [r1, #0x00]
	.global _0833CE14
_0833CE14:
	cmp r6, #0x04
	bne _0833CE1E
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0xA3
	str r0, [r1, #0x00]
	.global _0833CE1E
_0833CE1E:
	cmp r6, #0x05
	bne _0833CE28
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0xA6
	str r0, [r1, #0x00]
	.global _0833CE28
_0833CE28:
	cmp r6, #0x06
	bne _0833CE32
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CE32
_0833CE32:
	cmp r6, #0x08
	bne _0833CE3C
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CE3C
_0833CE3C:
	cmp r6, #0x09
	bne _0833CE46
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CE46
_0833CE46:
	cmp r6, #0x0A
	bne _0833CE50
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x5E
	str r0, [r1, #0x00]
	.global _0833CE50
_0833CE50:
	cmp r6, #0x0B
	bne _0833CE5A
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CE5A
_0833CE5A:
	ldr r0, _0833CED8 @ =0x02039228
	ldr r2, [r0, #0x00]
	ldr r3, _0833CEFC @ =0x03000800
	ldr r0, _0833CEE4 @ =0x02039238
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _0833CF00 @ =0x02039294
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x00
	movs r1, #0x00
	bl sub_0833CFC8
	ldr r0, _0833CEDC @ =0x02039268
	ldr r2, [r0, #0x00]
	ldr r3, _0833CF04 @ =0x03001000
	ldr r0, _0833CEE8 @ =0x0203922C
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _0833CF08 @ =0x02039248
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x00
	movs r1, #0x00
	bl sub_0833CFC8
	bl sub_0833D094
	movs r0, #0x00
	movs r1, #0x00
	bl sub_0833D564
	adds r0, r6, #0x0
	bl sub_0834108C
	bl sub_0833E05C
	bl sub_0833E078
	ldr r1, _0833CF0C @ =0x0203B864
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r3, #0x82
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833CEBC
_0833CEBC: .4byte 0xFFFFFDF8
	.global _0833CEC0
_0833CEC0: .4byte 0x02022428
	.global _0833CEC4
_0833CEC4: .4byte 0x0600C000
	.global _0833CEC8
_0833CEC8: .4byte 0x020251BC
	.global _0833CECC
_0833CECC: .4byte 0x02021394
	.global _0833CED0
_0833CED0: .4byte 0x02039244
	.global _0833CED4
_0833CED4: .4byte 0x02039288
	.global _0833CED8
_0833CED8: .4byte 0x02039228
	.global _0833CEDC
_0833CEDC: .4byte 0x02039268
	.global _0833CEE0
_0833CEE0: .4byte 0x02039224
	.global _0833CEE4
_0833CEE4: .4byte 0x02039238
	.global _0833CEE8
_0833CEE8: .4byte 0x0203922C
	.global _0833CEEC
_0833CEEC: .4byte 0x020392A0
	.global _0833CEF0
_0833CEF0: .4byte 0x02039280
	.global _0833CEF4
_0833CEF4: .4byte 0x0203929C
	.global _0833CEF8
_0833CEF8: .4byte 0x02039220
	.global _0833CEFC
_0833CEFC: .4byte 0x03000800
	.global _0833CF00
_0833CF00: .4byte 0x02039294
	.global _0833CF04
_0833CF04: .4byte 0x03001000
	.global _0833CF08
_0833CF08: .4byte 0x02039248
	.global _0833CF0C
_0833CF0C: .4byte 0x0203B864
	thumb_func_start sub_0833CF10
sub_0833CF10:
	push {r4, r5, lr}
	add sp, #-0x008
	ldr r0, _0833CF8C @ =0x02039110
	ldr r4, [r0, #0x18]
	subs r4, #0x78
	ldr r5, [r0, #0x1C]
	subs r5, #0x50
	ldr r0, _0833CF90 @ =0x0203925C
	movs r2, #0x0F
	ands r2, r4
	str r2, [r0, #0x00]
	ldr r0, _0833CF94 @ =0x02039260
	movs r1, #0x1F
	ands r1, r5
	str r1, [r0, #0x00]
	ldr r0, _0833CF98 @ =0x020392A8
	str r2, [r0, #0x00]
	ldr r0, _0833CF9C @ =0x02039240
	str r1, [r0, #0x00]
	ldr r0, _0833CFA0 @ =0x02039290
	str r2, [r0, #0x00]
	ldr r0, _0833CFA4 @ =0x02039298
	str r1, [r0, #0x00]
	ldr r2, _0833CFA8 @ =0x02039234
	movs r1, #0x10
	adds r0, r4, #0x0
	ands r0, r1
	strb r0, [r2, #0x00]
	asrs r4, r4, #0x05
	asrs r5, r5, #0x05
	ldr r0, _0833CFAC @ =0x02039228
	ldr r2, [r0, #0x00]
	movs r3, #0xC0
	lsls r3, r3, #0x12
	ldr r0, _0833CFB0 @ =0x02039238
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _0833CFB4 @ =0x02039248
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_0833CFC8
	ldr r0, _0833CFB8 @ =0x02039268
	ldr r2, [r0, #0x00]
	ldr r3, _0833CFBC @ =0x03000800
	ldr r0, _0833CFC0 @ =0x0203922C
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _0833CFC4 @ =0x020392A4
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_0833CFC8
	add sp, #0x008
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833CF8C
_0833CF8C: .4byte 0x02039110
	.global _0833CF90
_0833CF90: .4byte 0x0203925C
	.global _0833CF94
_0833CF94: .4byte 0x02039260
	.global _0833CF98
_0833CF98: .4byte 0x020392A8
	.global _0833CF9C
_0833CF9C: .4byte 0x02039240
	.global _0833CFA0
_0833CFA0: .4byte 0x02039290
	.global _0833CFA4
_0833CFA4: .4byte 0x02039298
	.global _0833CFA8
_0833CFA8: .4byte 0x02039234
	.global _0833CFAC
_0833CFAC: .4byte 0x02039228
	.global _0833CFB0
_0833CFB0: .4byte 0x02039238
	.global _0833CFB4
_0833CFB4: .4byte 0x02039248
	.global _0833CFB8
_0833CFB8: .4byte 0x02039268
	.global _0833CFBC
_0833CFBC: .4byte 0x03000800
	.global _0833CFC0
_0833CFC0: .4byte 0x0203922C
	.global _0833CFC4
_0833CFC4: .4byte 0x020392A4
	thumb_func_start sub_0833CFC8
sub_0833CFC8:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r12, r3
	ldr r6, [sp, #0x018]
	ldr r4, _0833D03C @ =0x02039244
	ldr r3, [r4, #0x00]
	muls r1, r3
	adds r2, r2, r1
	adds r2, r2, r0
	movs r0, #0x00
	mov r8, r4
	.global _0833CFE0
_0833CFE0:
	movs r4, #0x00
	adds r5, r0, #0x4
	mov r3, r12
	adds r3, #0x90
	.global _0833CFE8
_0833CFE8:
	ldrb r1, [r2, #0x00]
	adds r2, #0x01
	lsls r1, r1, #0x05
	adds r1, r6, r1
	ldm r1!, {r0}
	mov r7, r12
	str r0, [r7, #0x00]
	ldm r1!, {r0}
	str r0, [r7, #0x04]
	ldm r1!, {r0}
	str r0, [r7, #0x48]
	ldm r1!, {r0}
	str r0, [r7, #0x4C]
	ldm r1!, {r0}
	str r0, [r3, #0x00]
	ldm r1!, {r0}
	str r0, [r3, #0x04]
	ldm r1!, {r0}
	str r0, [r3, #0x48]
	ldr r0, [r1, #0x00]
	str r0, [r3, #0x4C]
	adds r3, #0x08
	movs r0, #0x08
	add r12, r0
	adds r4, #0x01
	cmp r4, #0x09
	bne _0833CFE8
	movs r1, #0xD8
	add r12, r1
	mov r7, r8
	ldr r0, [r7, #0x00]
	subs r0, #0x09
	adds r2, r2, r0
	adds r0, r5, #0x0
	cmp r0, #0x18
	bne _0833CFE0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833D03C
_0833D03C: .4byte 0x02039244
