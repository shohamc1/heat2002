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
