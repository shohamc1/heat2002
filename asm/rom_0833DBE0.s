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
	.byte 0xA4, 0x46, 0x03, 0x4C, 0xA5, 0x44, 0x64, 0x46, 0x80, 0x23, 0x9B, 0x00, 0x9D, 0x44, 0x70, 0x47
	.byte 0x00, 0xFE, 0xFF, 0xFF
	thumb_func_start sub_0833DBF4
sub_0833DBF4:
	mov r12, r4
	ldr r4, _0833DC0C @ =0xFFFFFE00
	add sp, r4
	mov r4, r12
	ldr r1, _0833DC10 @ =0x0203B850
	movs r0, #0xFF
	strb r0, [r1, #0x00]
	movs r0, #0x00
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	bx lr
	.global _0833DC0C
_0833DC0C: .4byte 0xFFFFFE00
	.global _0833DC10
_0833DC10: .4byte 0x0203B850
	thumb_func_start sub_0833DC14
sub_0833DC14:
	push {lr}
	movs r0, #0x03
	bl sub_0833BD94
	movs r1, #0x08
	movs r2, #0x01
	bl sub_0833EE88
	ldr r0, _0833DC38 @ =0x0203B850
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _0833DC50
	cmp r0, #0x01
	bgt _0833DC3C
	cmp r0, #0x00
	beq _0833DC46
	b _0833DC72
	.byte 0x00, 0x00
	.global _0833DC38
_0833DC38: .4byte 0x0203B850
	.global _0833DC3C
_0833DC3C:
	cmp r0, #0x02
	beq _0833DC58
	cmp r0, #0x03
	beq _0833DC68
	b _0833DC72
	.global _0833DC46
_0833DC46:
	ldr r0, _0833DC4C @ =0x0200CEEC
	b _0833DC5A
	.byte 0x00, 0x00
	.global _0833DC4C
_0833DC4C: .4byte 0x0200CEEC
	.global _0833DC50
_0833DC50:
	ldr r0, _0833DC54 @ =0x0200CEF8
	b _0833DC5A
	.global _0833DC54
_0833DC54: .4byte 0x0200CEF8
	.global _0833DC58
_0833DC58:
	ldr r0, _0833DC64 @ =0x0200CF04
	.global _0833DC5A
_0833DC5A:
	movs r1, #0x09
	movs r2, #0x01
	bl sub_0833EE88
	b _0833DC72
	.global _0833DC64
_0833DC64: .4byte 0x0200CF04
	.global _0833DC68
_0833DC68:
	ldr r0, _0833DC78 @ =0x0200CF10
	movs r1, #0x09
	movs r2, #0x01
	bl sub_0833EE88
	.global _0833DC72
_0833DC72:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833DC78
_0833DC78: .4byte 0x0200CF10
	thumb_func_start sub_0833DC7C
sub_0833DC7C:
	push {r4, r5, r6, lr}
	movs r2, #0x00
	ldr r6, _0833DCAC @ =0x020251B8
	movs r5, #0x80
	lsls r5, r5, #0x02
	movs r3, #0x47
	movs r4, #0x90
	lsls r4, r4, #0x02
	.global _0833DC8C
_0833DC8C:
	ldr r1, [r6, #0x00]
	lsls r0, r2, #0x01
	adds r0, r0, r1
	adds r1, r0, r5
	strh r3, [r1, #0x00]
	adds r0, r0, r4
	strh r3, [r0, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x1B
	bne _0833DC8C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833DCAC
_0833DCAC: .4byte 0x020251B8
	thumb_func_start sub_0833DCB0
sub_0833DCB0:
	push {r4, r5, lr}
	ldr r4, _0833DD28 @ =0xFFFFFE00
	add sp, r4
	ldr r1, _0833DD2C @ =0x0203B850
	movs r0, #0xFF
	strb r0, [r1, #0x00]
	bl sub_0833DA34
	ldr r1, _0833DD30 @ =0x0203B6FC
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _0833DDA0
	ldr r0, _0833DD34 @ =0x02038F70
	bl sub_0833B074
	ldr r0, _0833DD38 @ =0x02038FB0
	bl sub_0833B074
	ldr r0, _0833DD3C @ =0x02038FF0
	bl sub_0833B074
	ldr r0, _0833DD40 @ =0x02039040
	bl sub_0833B074
	.global _0833DCE4
_0833DCE4:
	ldr r0, _0833DD44 @ =0x02039134
	movs r1, #0x00
	strh r1, [r0, #0x00]
	bl sub_0833C874
	cmp r0, #0x00
	beq _0833DD5C
	movs r0, #0x00
	bl sub_0833BD94
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_0833EE88
	ldr r0, _0833DD48 @ =0x0200CF1C
	movs r1, #0x0C
	movs r2, #0x01
	bl sub_0833EE88
	ldr r0, _0833DD4C @ =0x0200CF34
	movs r1, #0x0D
	movs r2, #0x01
	bl sub_0833EE88
	bl sub_0833AE90
	movs r5, #0x00
	ldr r4, _0833DD50 @ =0x0203E1B0
	.global _0833DD1C
_0833DD1C:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _0833DD54
	movs r0, #0x27
	b _0833DDA2
	.byte 0x00, 0x00
	.global _0833DD28
_0833DD28: .4byte 0xFFFFFE00
	.global _0833DD2C
_0833DD2C: .4byte 0x0203B850
	.global _0833DD30
_0833DD30: .4byte 0x0203B6FC
	.global _0833DD34
_0833DD34: .4byte 0x02038F70
	.global _0833DD38
_0833DD38: .4byte 0x02038FB0
	.global _0833DD3C
_0833DD3C: .4byte 0x02038FF0
	.global _0833DD40
_0833DD40: .4byte 0x02039040
	.global _0833DD44
_0833DD44: .4byte 0x02039134
	.global _0833DD48
_0833DD48: .4byte 0x0200CF1C
	.global _0833DD4C
_0833DD4C: .4byte 0x0200CF34
	.global _0833DD50
_0833DD50: .4byte 0x0203E1B0
	.global _0833DD54
_0833DD54:
	bl sub_08344B74
	cmp r5, #0x00
	beq _0833DD1C
	.global _0833DD5C
_0833DD5C:
	bl sub_0833DA34
	ldr r1, _0833DD78 @ =0x0203B6FC
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x00
	beq _0833DD7C
	bl sub_0833DC7C
	movs r0, #0x01
	b _0833DDA2
	.global _0833DD78
_0833DD78: .4byte 0x0203B6FC
	.global _0833DD7C
_0833DD7C:
	bl sub_0833DC14
	ldr r0, _0833DD98 @ =0x020390AC
	ldr r1, [r0, #0x00]
	adds r1, #0x01
	str r1, [r0, #0x00]
	ldr r0, _0833DD9C @ =0x020390D0
	strb r4, [r0, #0x00]
	.global _0833DD8C
_0833DD8C:
	ldr r0, _0833DD9C @ =0x020390D0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833DD8C
	b _0833DCE4
	.byte 0x00, 0x00
	.global _0833DD98
_0833DD98: .4byte 0x020390AC
	.global _0833DD9C
_0833DD9C: .4byte 0x020390D0
	.global _0833DDA0
_0833DDA0:
	movs r0, #0x00
	.global _0833DDA2
_0833DDA2:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00
	thumb_func_start sub_0833DDB8
sub_0833DDB8:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x020
	adds r6, r0, #0x0
	adds r4, r1, #0x0
	adds r5, r2, #0x0
	adds r7, r3, #0x0
	cmp r4, #0x63
	ble _0833DDCE
	movs r4, #0x63
	movs r5, #0x3B
	movs r7, #0x00
	.global _0833DDCE
_0833DDCE:
	movs r0, #0x0A
	str r0, [sp, #0x008]
	str r0, [sp, #0x014]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08344BB8
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl sub_08344C50
	str r0, [sp, #0x004]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl sub_08344BB8
	str r0, [sp, #0x00C]
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl sub_08344C50
	str r0, [sp, #0x010]
	adds r0, r7, #0x0
	movs r1, #0x64
	bl sub_08344C50
	movs r1, #0x0A
	bl sub_08344BB8
	str r0, [sp, #0x01C]
	adds r0, r7, #0x0
	movs r1, #0x64
	bl sub_08344BB8
	str r0, [sp, #0x018]
	movs r4, #0x00
	mov r5, sp
	.global _0833DE1A
_0833DE1A:
	adds r0, r6, #0x4
	ldm r5!, {r1}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_0833E3C8
	adds r6, #0x02
	adds r4, #0x01
	cmp r4, #0x08
	bne _0833DE1A
	add sp, #0x020
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x70, 0xB5, 0x56, 0x46, 0x4D, 0x46, 0x44, 0x46, 0x70, 0xB4, 0x04, 0x1C, 0x8A, 0x46
	.byte 0x91, 0x46, 0x98, 0x46, 0x12, 0x4E, 0x31, 0x1C, 0x06, 0xF0, 0xB3, 0xFE, 0x05, 0x1C, 0x2D, 0x04
	.byte 0x2D, 0x0C, 0x28, 0x1C, 0x70, 0x43, 0x24, 0x1A, 0xFA, 0x21, 0x89, 0x00, 0x20, 0x1C, 0x06, 0xF0
	.byte 0xA8, 0xFE, 0x00, 0x04, 0x00, 0x0C, 0x41, 0x01, 0x09, 0x1A, 0x89, 0x00, 0x09, 0x18, 0xC9, 0x00
	.byte 0x64, 0x1A, 0x41, 0x46, 0x0C, 0x80, 0x49, 0x46, 0x08, 0x80, 0x50, 0x46, 0x05, 0x80, 0x38, 0xBC
	.byte 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x60, 0xEA
	.byte 0x00, 0x00
	thumb_func_start sub_0833DE98
sub_0833DE98:
	push {r4, r5, lr}
	bl sub_0833FA3C
	bl sub_0833D680
	.global _0833DEA2
_0833DEA2:
	ldr r0, _0833DEF4 @ =0x02039134
	movs r1, #0x00
	strh r1, [r0, #0x00]
	bl sub_0833C874
	cmp r0, #0x00
	beq _0833DF10
	movs r0, #0x00
	bl sub_0833BD94
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_0833EE88
	ldr r0, _0833DEF8 @ =0x0200CF1C
	movs r1, #0x0C
	movs r2, #0x01
	bl sub_0833EE88
	ldr r0, _0833DEFC @ =0x0200CF34
	movs r1, #0x0D
	movs r2, #0x01
	bl sub_0833EE88
	ldr r0, _0833DF00 @ =0x02038F70
	bl sub_0833B074
	ldr r0, _0833DF04 @ =0x02038FB0
	bl sub_0833B074
	bl sub_0833AE90
	ldr r5, _0833DF08 @ =0x0203E1B0
	ldr r4, _0833DF0C @ =0x04000130
	.global _0833DEE6
_0833DEE6:
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	bne _0833DEEE
	ldrh r0, [r4, #0x00]
	.global _0833DEEE
_0833DEEE:
	bl sub_08344B74
	b _0833DEE6
	.global _0833DEF4
_0833DEF4: .4byte 0x02039134
	.global _0833DEF8
_0833DEF8: .4byte 0x0200CF1C
	.global _0833DEFC
_0833DEFC: .4byte 0x0200CF34
	.global _0833DF00
_0833DF00: .4byte 0x02038F70
	.global _0833DF04
_0833DF04: .4byte 0x02038FB0
	.global _0833DF08
_0833DF08: .4byte 0x0203E1B0
	.global _0833DF0C
_0833DF0C: .4byte 0x04000130
	.global _0833DF10
_0833DF10:
	ldr r0, _0833DF28 @ =0x0203E1B0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833DF2C
	movs r0, #0x01
	bl sub_0833BD94
	movs r1, #0x0E
	movs r2, #0x01
	bl sub_0833EE88
	b _0833DF3A
	.global _0833DF28
_0833DF28: .4byte 0x0203E1B0
	.global _0833DF2C
_0833DF2C:
	movs r0, #0x02
	bl sub_0833BD94
	movs r1, #0x0E
	movs r2, #0x01
	bl sub_0833EE88
	.global _0833DF3A
_0833DF3A:
	bl sub_0833DA34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _0833DEA2
	movs r0, #0x00
	movs r1, #0x32
	bl sub_0833D510
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_start sub_0833DF58
sub_0833DF58:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r0, _0833DFC8 @ =0x0203B864
	ldrb r4, [r0, #0x00]
	cmp r4, #0x00
	beq _0833E044
	ldr r2, _0833DFCC @ =0x0203D520
	ldr r0, _0833DFD0 @ =0x020390EC
	ldrb r3, [r0, #0x00]
	cmp r3, #0x00
	beq _0833DF82
	ldr r0, _0833DFD4 @ =0x0203E1B0
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r2, r0, r2
	.global _0833DF82
_0833DF82:
	adds r0, r2, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833E044
	movs r7, #0x05
	cmp r3, #0x00
	beq _0833DF94
	movs r7, #0x02
	.global _0833DF94
_0833DF94:
	movs r0, #0x01
	mov r8, r0
	movs r6, #0x00
	cmp r6, r4
	beq _0833E044
	ldr r1, _0833DFD8 @ =0x020251B8
	mov r9, r1
	.global _0833DFA2
_0833DFA2:
	ldr r0, _0833DFDC @ =0x0203B868
	adds r0, r6, r0
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _0833DFCC @ =0x0203D520
	adds r5, r0, r1
	ldr r0, _0833DFD0 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833DFE0
	lsls r0, r7, #0x07
	adds r0, #0x14
	mov r2, r9
	ldr r1, [r2, #0x00]
	b _0833DFE8
	.global _0833DFC8
_0833DFC8: .4byte 0x0203B864
	.global _0833DFCC
_0833DFCC: .4byte 0x0203D520
	.global _0833DFD0
_0833DFD0: .4byte 0x020390EC
	.global _0833DFD4
_0833DFD4: .4byte 0x0203E1B0
	.global _0833DFD8
_0833DFD8: .4byte 0x020251B8
	.global _0833DFDC
_0833DFDC: .4byte 0x0203B868
	.global _0833DFE0
_0833DFE0:
	lsls r0, r7, #0x06
	adds r0, #0x14
	mov r3, r9
	ldr r1, [r3, #0x00]
	.global _0833DFE8
_0833DFE8:
	adds r4, r1, r0
	adds r0, r4, #0x0
	mov r1, r8
	bl sub_0833E3C8
	movs r1, #0x82
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrh r1, [r0, #0x00]
	movs r2, #0x83
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrh r2, [r0, #0x00]
	movs r3, #0x84
	lsls r3, r3, #0x01
	adds r0, r5, r3
	ldrh r3, [r0, #0x00]
	adds r0, r4, #0x0
	bl sub_0833DDB8
	ldr r0, _0833E050 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833E026
	lsls r1, r7, #0x04
	ldr r0, _0833E054 @ =0x0203B868
	adds r0, r6, r0
	ldrb r2, [r0, #0x00]
	movs r0, #0x40
	bl sub_08341A30
	.global _0833E026
_0833E026:
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _0833E058 @ =0x0203B864
	ldrb r0, [r0, #0x00]
	cmp r6, r0
	bne _0833DFA2
	.global _0833E044
_0833E044:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0833E050
_0833E050: .4byte 0x020390EC
	.global _0833E054
_0833E054: .4byte 0x0203B868
	.global _0833E058
_0833E058: .4byte 0x0203B864
