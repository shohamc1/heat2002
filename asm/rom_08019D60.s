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
	.byte 0x00, 0xB5, 0x03, 0x1C, 0x0A, 0x1C, 0x03, 0x48, 0x00, 0x68, 0x19, 0x1C, 0xFF, 0xF7, 0xD6, 0xFF
	.byte 0x00, 0xBD, 0x00, 0x00, 0xA8, 0xFA, 0x3F, 0x08
	thumb_func_start sub_08019D78
sub_08019D78:
	push {lr}
	ldr r0, _08019D84 @ =0x083FFAA8
	ldr r0, [r0, #0x00]
	bl sub_08019D58
	pop {pc}
	.global _08019D84
_08019D84: .4byte 0x083FFAA8
	thumb_func_start sub_08019D88
sub_08019D88:
	push {r4, r5, r6, r7, lr}
	add sp, #-0x03C
	adds r4, r0, #0x0
	movs r0, #0x02
	ldrh r1, [r4, #0x0C]
	ands r0, r1
	cmp r0, #0x00
	bne _08019E1E
	movs r2, #0x0E
	ldsh r0, [r4, r2]
	cmp r0, #0x00
	blt _08019DB0
	ldr r0, [r4, #0x54]
	movs r2, #0x0E
	ldsh r1, [r4, r2]
	mov r2, sp
	bl sub_0801B538
	cmp r0, #0x00
	bge _08019DC2
	.global _08019DB0
_08019DB0:
	movs r7, #0x00
	movs r6, #0x80
	lsls r6, r6, #0x03
	movs r1, #0x80
	lsls r1, r1, #0x04
	adds r0, r1, #0x0
	ldrh r2, [r4, #0x0C]
	orrs r0, r2
	b _08019E06
	.global _08019DC2
_08019DC2:
	movs r7, #0x00
	ldr r1, [sp, #0x004]
	movs r0, #0xF0
	lsls r0, r0, #0x08
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x06
	cmp r1, r0
	bne _08019DD6
	movs r7, #0x01
	.global _08019DD6
_08019DD6:
	movs r6, #0x80
	lsls r6, r6, #0x03
	movs r0, #0x80
	lsls r0, r0, #0x08
	cmp r1, r0
	bne _08019DFC
	ldr r1, [r4, #0x28]
	ldr r0, _08019DF8 @ =0x0801AF25
	cmp r1, r0
	bne _08019DFC
	adds r0, r6, #0x0
	ldrh r1, [r4, #0x0C]
	orrs r0, r1
	strh r0, [r4, #0x0C]
	str r6, [r4, #0x4C]
	b _08019E08
	.byte 0x00, 0x00
	.global _08019DF8
_08019DF8: .4byte 0x0801AF25
	.global _08019DFC
_08019DFC:
	movs r2, #0x80
	lsls r2, r2, #0x04
	adds r0, r2, #0x0
	ldrh r1, [r4, #0x0C]
	orrs r0, r1
	.global _08019E06
_08019E06:
	strh r0, [r4, #0x0C]
	.global _08019E08
_08019E08:
	ldr r0, [r4, #0x54]
	adds r1, r6, #0x0
	bl sub_08019FC0
	adds r2, r0, #0x0
	cmp r2, #0x00
	bne _08019E2C
	movs r0, #0x02
	ldrh r2, [r4, #0x0C]
	orrs r0, r2
	strh r0, [r4, #0x0C]
	.global _08019E1E
_08019E1E:
	adds r0, r4, #0x0
	adds r0, #0x43
	str r0, [r4, #0x00]
	str r0, [r4, #0x10]
	movs r0, #0x01
	str r0, [r4, #0x14]
	b _08019E5A
	.global _08019E2C
_08019E2C:
	ldr r1, [r4, #0x54]
	ldr r0, _08019E60 @ =0x080197B1
	str r0, [r1, #0x3C]
	movs r0, #0x80
	movs r5, #0x00
	ldrh r1, [r4, #0x0C]
	orrs r0, r1
	strh r0, [r4, #0x0C]
	str r2, [r4, #0x00]
	str r2, [r4, #0x10]
	str r6, [r4, #0x14]
	cmp r7, #0x00
	beq _08019E5A
	movs r2, #0x0E
	ldsh r0, [r4, r2]
	bl sub_0801B584
	cmp r0, #0x00
	beq _08019E5A
	movs r0, #0x01
	ldrh r1, [r4, #0x0C]
	orrs r0, r1
	strh r0, [r4, #0x0C]
	.global _08019E5A
_08019E5A:
	add sp, #0x03C
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
	.global _08019E60
_08019E60: .4byte sub_080197B0
	thumb_func_start sub_08019E64
sub_08019E64:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	str r0, [sp, #0x000]
	ldr r0, _08019ED8 @ =0x083FFAC0
	ldr r0, [r0, #0x08]
	mov r8, r0
	ldr r7, [r0, #0x04]
	movs r0, #0x04
	negs r0, r0
	ands r7, r0
	mov r2, r8
	adds r4, r2, r7
	ldr r0, _08019EDC @ =0x083FFECC
	ldr r0, [r0, #0x00]
	adds r1, r1, r0
	adds r6, r1, #0x0
	adds r6, #0x10
	ldr r3, _08019EE0 @ =0x083FFED0
	mov r10, r3
	ldr r0, [r3, #0x00]
	movs r2, #0x01
	negs r2, r2
	mov r9, r2
	cmp r0, r9
	beq _08019EA6
	ldr r3, _08019EE4 @ =0x0000100F
	adds r6, r1, r3
	ldr r0, _08019EE8 @ =0xFFFFF000
	ands r6, r0
	.global _08019EA6
_08019EA6:
	ldr r0, [sp, #0x000]
	adds r1, r6, #0x0
	bl sub_0801AE84
	adds r5, r0, #0x0
	cmp r5, r9
	beq _08019FA8
	cmp r5, r4
	bcs _08019EBE
	ldr r0, _08019ED8 @ =0x083FFAC0
	cmp r8, r0
	bne _08019FA8
	.global _08019EBE
_08019EBE:
	ldr r1, _08019EEC @ =0x083FFEDC
	ldr r0, [r1, #0x00]
	adds r2, r0, r6
	str r2, [r1, #0x00]
	cmp r5, r4
	bne _08019EF0
	adds r2, r6, r7
	ldr r3, _08019ED8 @ =0x083FFAC0
	ldr r1, [r3, #0x08]
	movs r0, #0x01
	orrs r2, r0
	str r2, [r1, #0x04]
	b _08019F90
	.global _08019ED8
_08019ED8: .4byte 0x083FFAC0
	.global _08019EDC
_08019EDC: .4byte 0x083FFECC
	.global _08019EE0
_08019EE0: .4byte 0x083FFED0
	.global _08019EE4
_08019EE4: .4byte 0x0000100F
	.global _08019EE8
_08019EE8: .4byte 0xFFFFF000
	.global _08019EEC
_08019EEC: .4byte 0x083FFEDC
	.global _08019EF0
_08019EF0:
	mov r3, r10
	ldr r0, [r3, #0x00]
	cmp r0, r9
	bne _08019EFC
	str r5, [r3, #0x00]
	b _08019F02
	.global _08019EFC
_08019EFC:
	subs r0, r5, r4
	adds r0, r2, r0
	str r0, [r1, #0x00]
	.global _08019F02
_08019F02:
	adds r1, r5, #0x0
	adds r1, #0x08
	movs r0, #0x07
	ands r1, r0
	cmp r1, #0x00
	beq _08019F16
	movs r0, #0x08
	subs r4, r0, r1
	adds r5, r5, r4
	b _08019F18
	.global _08019F16
_08019F16:
	movs r4, #0x00
	.global _08019F18
_08019F18:
	adds r0, r5, r6
	movs r1, #0x80
	lsls r1, r1, #0x05
	subs r1, #0x01
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x05
	subs r0, r1, r0
	adds r4, r4, r0
	ldr r0, [sp, #0x000]
	adds r1, r4, #0x0
	bl sub_0801AE84
	adds r2, r0, #0x0
	movs r0, #0x01
	negs r0, r0
	cmp r2, r0
	beq _08019FA8
	ldr r1, _08019F60 @ =0x083FFEDC
	ldr r0, [r1, #0x00]
	adds r0, r0, r4
	str r0, [r1, #0x00]
	ldr r1, _08019F64 @ =0x083FFAC0
	str r5, [r1, #0x08]
	subs r0, r2, r5
	adds r2, r0, r4
	movs r3, #0x01
	orrs r2, r3
	str r2, [r5, #0x04]
	cmp r8, r1
	beq _08019F90
	cmp r7, #0x0F
	bhi _08019F68
	str r3, [r5, #0x04]
	b _08019FA8
	.byte 0x00, 0x00
	.global _08019F60
_08019F60: .4byte 0x083FFEDC
	.global _08019F64
_08019F64: .4byte 0x083FFAC0
	.global _08019F68
_08019F68:
	subs r7, #0x0C
	movs r0, #0x08
	negs r0, r0
	ands r7, r0
	mov r2, r8
	ldr r0, [r2, #0x04]
	ands r0, r3
	orrs r0, r7
	str r0, [r2, #0x04]
	adds r1, r2, r7
	movs r0, #0x05
	str r0, [r1, #0x04]
	str r0, [r1, #0x08]
	cmp r7, #0x0F
	bls _08019F90
	mov r1, r8
	adds r1, #0x08
	ldr r0, [sp, #0x000]
	bl sub_08019830
	.global _08019F90
_08019F90:
	ldr r0, _08019FB4 @ =0x083FFEDC
	ldr r2, _08019FB8 @ =0x083FFED4
	ldr r1, [r0, #0x00]
	ldr r0, [r2, #0x00]
	cmp r1, r0
	bls _08019F9E
	str r1, [r2, #0x00]
	.global _08019F9E
_08019F9E:
	ldr r2, _08019FBC @ =0x083FFED8
	ldr r0, [r2, #0x00]
	cmp r1, r0
	bls _08019FA8
	str r1, [r2, #0x00]
	.global _08019FA8
_08019FA8:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7, pc}
	.global _08019FB4
_08019FB4: .4byte 0x083FFEDC
	.global _08019FB8
_08019FB8: .4byte 0x083FFED4
	.global _08019FBC
_08019FBC: .4byte 0x083FFED8
	thumb_func_start sub_08019FC0
sub_08019FC0:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	str r0, [sp, #0x000]
	adds r1, #0x0B
	cmp r1, #0x16
	ble _08019FE2
	movs r0, #0x08
	negs r0, r0
	mov r8, r0
	mov r2, r8
	ands r2, r1
	mov r8, r2
	b _08019FE6
	.global _08019FE2
_08019FE2:
	movs r3, #0x10
	mov r8, r3
	.global _08019FE6
_08019FE6:
	ldr r0, [sp, #0x000]
	bl sub_0801A568
	ldr r0, _0801A02C @ =0x000001F7
	cmp r8, r0
	bhi _0801A03A
	mov r4, r8
	lsrs r4, r4, #0x03
	mov r12, r4
	ldr r0, _0801A030 @ =0x083FFAC0
	mov r7, r8
	adds r2, r7, r0
	ldr r5, [r2, #0x0C]
	cmp r5, r2
	bne _0801A00E
	adds r2, r5, #0x0
	adds r2, #0x08
	ldr r5, [r2, #0x0C]
	cmp r5, r2
	beq _0801A034
	.global _0801A00E
_0801A00E:
	ldr r2, [r5, #0x04]
	movs r0, #0x04
	negs r0, r0
	ands r2, r0
	ldr r6, [r5, #0x0C]
	ldr r4, [r5, #0x08]
	str r6, [r4, #0x0C]
	str r4, [r6, #0x08]
	adds r2, r5, r2
	ldr r0, [r2, #0x04]
	movs r1, #0x01
	orrs r0, r1
	str r0, [r2, #0x04]
	b _0801A366
	.byte 0x00, 0x00
	.global _0801A02C
_0801A02C: .4byte 0x000001F7
	.global _0801A030
_0801A030: .4byte 0x083FFAC0
	.global _0801A034
_0801A034:
	movs r0, #0x02
	add r12, r0
	b _0801A0E6
	.global _0801A03A
_0801A03A:
	mov r2, r8
	lsrs r1, r2, #0x09
	cmp r1, #0x00
	bne _0801A046
	lsrs r2, r2, #0x03
	b _0801A096
	.global _0801A046
_0801A046:
	cmp r1, #0x04
	bhi _0801A054
	mov r3, r8
	lsrs r0, r3, #0x06
	adds r0, #0x38
	mov r12, r0
	b _0801A098
	.global _0801A054
_0801A054:
	cmp r1, #0x14
	bhi _0801A05E
	adds r1, #0x5B
	mov r12, r1
	b _0801A098
	.global _0801A05E
_0801A05E:
	cmp r1, #0x54
	bhi _0801A06C
	mov r4, r8
	lsrs r0, r4, #0x0C
	adds r0, #0x6E
	mov r12, r0
	b _0801A098
	.global _0801A06C
_0801A06C:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	cmp r1, r0
	bhi _0801A07E
	mov r7, r8
	lsrs r0, r7, #0x0F
	adds r0, #0x77
	mov r12, r0
	b _0801A098
	.global _0801A07E
_0801A07E:
	ldr r0, _0801A090 @ =0x00000554
	cmp r1, r0
	bhi _0801A094
	mov r1, r8
	lsrs r0, r1, #0x12
	adds r0, #0x7C
	mov r12, r0
	b _0801A098
	.byte 0x00, 0x00
	.global _0801A090
_0801A090: .4byte 0x00000554
	.global _0801A094
_0801A094:
	movs r2, #0x7E
	.global _0801A096
_0801A096:
	mov r12, r2
	.global _0801A098
_0801A098:
	mov r3, r12
	lsls r0, r3, #0x03
	ldr r1, _0801A0BC @ =0x083FFAC0
	adds r4, r0, r1
	ldr r5, [r4, #0x0C]
	cmp r5, r4
	beq _0801A0E2
	ldr r1, [r5, #0x04]
	movs r0, #0x04
	negs r0, r0
	ands r1, r0
	mov r7, r8
	subs r3, r1, r7
	cmp r3, #0x0F
	ble _0801A0C0
	adds r0, #0x03
	add r12, r0
	b _0801A0E2
	.global _0801A0BC
_0801A0BC: .4byte 0x083FFAC0
	.global _0801A0C0
_0801A0C0:
	cmp r3, #0x00
	blt _0801A0C6
	b _0801A300
	.global _0801A0C6
_0801A0C6:
	ldr r5, [r5, #0x0C]
	cmp r5, r4
	beq _0801A0E2
	ldr r1, [r5, #0x04]
	movs r0, #0x04
	negs r0, r0
	ands r1, r0
	mov r2, r8
	subs r3, r1, r2
	cmp r3, #0x0F
	ble _0801A0C0
	movs r3, #0x01
	negs r3, r3
	add r12, r3
	.global _0801A0E2
_0801A0E2:
	movs r4, #0x01
	add r12, r4
	.global _0801A0E6
_0801A0E6:
	ldr r0, _0801A124 @ =0x083FFAC8
	ldr r5, [r0, #0x08]
	mov r10, r0
	cmp r5, r10
	bne _0801A0F2
	b _0801A1F4
	.global _0801A0F2
_0801A0F2:
	ldr r1, [r5, #0x04]
	movs r0, #0x04
	negs r0, r0
	ands r1, r0
	mov r7, r8
	subs r3, r1, r7
	cmp r3, #0x0F
	ble _0801A128
	adds r2, r5, r7
	movs r1, #0x01
	adds r0, r7, #0x0
	orrs r0, r1
	str r0, [r5, #0x04]
	mov r4, r10
	str r2, [r4, #0x0C]
	str r2, [r4, #0x08]
	str r4, [r2, #0x0C]
	str r4, [r2, #0x08]
	adds r0, r3, #0x0
	orrs r0, r1
	str r0, [r2, #0x04]
	adds r0, r2, r3
	str r3, [r0, #0x00]
	b _0801A366
	.byte 0x00, 0x00
	.global _0801A124
_0801A124: .4byte 0x083FFAC8
	.global _0801A128
_0801A128:
	mov r7, r10
	str r7, [r7, #0x0C]
	str r7, [r7, #0x08]
	cmp r3, #0x00
	blt _0801A13E
	adds r2, r5, r1
	ldr r0, [r2, #0x04]
	movs r1, #0x01
	orrs r0, r1
	str r0, [r2, #0x04]
	b _0801A366
	.global _0801A13E
_0801A13E:
	ldr r0, _0801A160 @ =0x000001FF
	cmp r1, r0
	bhi _0801A164
	lsrs r2, r1, #0x03
	mov r3, r10
	subs r3, #0x08
	adds r0, r2, #0x0
	asrs r0, r0, #0x02
	movs r1, #0x01
	lsls r1, r0
	ldr r0, [r3, #0x04]
	orrs r0, r1
	str r0, [r3, #0x04]
	lsls r0, r2, #0x03
	adds r6, r0, r3
	ldr r4, [r6, #0x08]
	b _0801A1EC
	.global _0801A160
_0801A160: .4byte 0x000001FF
	.global _0801A164
_0801A164:
	lsrs r2, r1, #0x09
	cmp r2, #0x00
	bne _0801A16E
	lsrs r2, r1, #0x03
	b _0801A1B2
	.global _0801A16E
_0801A16E:
	cmp r2, #0x04
	bhi _0801A17A
	lsrs r0, r1, #0x06
	adds r2, r0, #0x0
	adds r2, #0x38
	b _0801A1B2
	.global _0801A17A
_0801A17A:
	cmp r2, #0x14
	bhi _0801A182
	adds r2, #0x5B
	b _0801A1B2
	.global _0801A182
_0801A182:
	cmp r2, #0x54
	bhi _0801A18E
	lsrs r0, r1, #0x0C
	adds r2, r0, #0x0
	adds r2, #0x6E
	b _0801A1B2
	.global _0801A18E
_0801A18E:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	cmp r2, r0
	bhi _0801A19E
	lsrs r0, r1, #0x0F
	adds r2, r0, #0x0
	adds r2, #0x77
	b _0801A1B2
	.global _0801A19E
_0801A19E:
	ldr r0, _0801A1AC @ =0x00000554
	cmp r2, r0
	bhi _0801A1B0
	lsrs r0, r1, #0x12
	adds r2, r0, #0x0
	adds r2, #0x7C
	b _0801A1B2
	.global _0801A1AC
_0801A1AC: .4byte 0x00000554
	.global _0801A1B0
_0801A1B0:
	movs r2, #0x7E
	.global _0801A1B2
_0801A1B2:
	lsls r0, r2, #0x03
	ldr r3, _0801A1D0 @ =0x083FFAC0
	adds r6, r0, r3
	ldr r4, [r6, #0x08]
	cmp r4, r6
	bne _0801A1D4
	adds r0, r2, #0x0
	asrs r0, r0, #0x02
	movs r1, #0x01
	lsls r1, r0
	ldr r7, _0801A1D0 @ =0x083FFAC0
	ldr r0, [r7, #0x04]
	orrs r0, r1
	str r0, [r7, #0x04]
	b _0801A1EC
	.global _0801A1D0
_0801A1D0: .4byte 0x083FFAC0
	.global _0801A1D4
_0801A1D4:
	ldr r0, [r4, #0x04]
	movs r2, #0x04
	negs r2, r2
	b _0801A1E4
	.global _0801A1DC
_0801A1DC:
	ldr r4, [r4, #0x08]
	cmp r4, r6
	beq _0801A1EA
	ldr r0, [r4, #0x04]
	.global _0801A1E4
_0801A1E4:
	ands r0, r2
	cmp r1, r0
	bcc _0801A1DC
	.global _0801A1EA
_0801A1EA:
	ldr r6, [r4, #0x0C]
	.global _0801A1EC
_0801A1EC:
	str r6, [r5, #0x0C]
	str r4, [r5, #0x08]
	str r5, [r6, #0x08]
	str r5, [r4, #0x0C]
	.global _0801A1F4
_0801A1F4:
	mov r0, r12
	cmp r0, #0x00
	bge _0801A1FC
	adds r0, #0x03
	.global _0801A1FC
_0801A1FC:
	asrs r0, r0, #0x02
	movs r6, #0x01
	lsls r6, r0
	ldr r0, _0801A220 @ =0x083FFAC0
	ldr r1, [r0, #0x04]
	cmp r6, r1
	bhi _0801A2BE
	adds r0, r6, #0x0
	ands r0, r1
	cmp r0, #0x00
	bne _0801A232
	movs r0, #0x04
	negs r0, r0
	mov r2, r12
	ands r0, r2
	adds r0, #0x04
	mov r12, r0
	b _0801A228
	.global _0801A220
_0801A220: .4byte 0x083FFAC0
	.global _0801A224
_0801A224:
	movs r3, #0x04
	add r12, r3
	.global _0801A228
_0801A228:
	lsls r6, r6, #0x01
	adds r0, r6, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _0801A224
	.global _0801A232
_0801A232:
	ldr r4, _0801A2B0 @ =0x083FFAC0
	mov r9, r4
	.global _0801A236
_0801A236:
	mov r7, r12
	str r7, [sp, #0x004]
	mov r1, r12
	lsls r0, r1, #0x03
	mov r3, r9
	adds r2, r0, r3
	adds r4, r2, #0x0
	.global _0801A244
_0801A244:
	ldr r5, [r4, #0x0C]
	cmp r5, r4
	beq _0801A264
	movs r0, #0x04
	negs r0, r0
	.global _0801A24E
_0801A24E:
	ldr r1, [r5, #0x04]
	ands r1, r0
	mov r7, r8
	subs r3, r1, r7
	cmp r3, #0x0F
	bgt _0801A314
	cmp r3, #0x00
	bge _0801A33C
	ldr r5, [r5, #0x0C]
	cmp r5, r4
	bne _0801A24E
	.global _0801A264
_0801A264:
	adds r4, #0x08
	movs r0, #0x01
	add r12, r0
	mov r0, r12
	movs r1, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0801A244
	.global _0801A274
_0801A274:
	ldr r0, [sp, #0x004]
	ands r0, r1
	cmp r0, #0x00
	beq _0801A2B4
	ldr r3, [sp, #0x004]
	subs r3, #0x01
	str r3, [sp, #0x004]
	subs r2, #0x08
	ldr r0, [r2, #0x08]
	cmp r0, r2
	beq _0801A274
	.global _0801A28A
_0801A28A:
	lsls r6, r6, #0x01
	mov r4, r9
	ldr r1, [r4, #0x04]
	cmp r6, r1
	bhi _0801A2BE
	cmp r6, #0x00
	beq _0801A2BE
	adds r0, r6, #0x0
	ands r0, r1
	cmp r0, #0x00
	bne _0801A236
	.global _0801A2A0
_0801A2A0:
	movs r7, #0x04
	add r12, r7
	lsls r6, r6, #0x01
	adds r0, r6, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _0801A2A0
	b _0801A236
	.global _0801A2B0
_0801A2B0: .4byte 0x083FFAC0
	.global _0801A2B4
_0801A2B4:
	mov r1, r9
	ldr r0, [r1, #0x04]
	bics r0, r6
	str r0, [r1, #0x04]
	b _0801A28A
	.global _0801A2BE
_0801A2BE:
	ldr r2, _0801A2FC @ =0x083FFAC0
	ldr r0, [r2, #0x08]
	ldr r0, [r0, #0x04]
	movs r4, #0x04
	negs r4, r4
	ands r0, r4
	mov r7, r8
	subs r3, r0, r7
	cmp r0, r8
	bcc _0801A2D6
	cmp r3, #0x0F
	bgt _0801A350
	.global _0801A2D6
_0801A2D6:
	ldr r0, [sp, #0x000]
	mov r1, r8
	bl sub_08019E64
	ldr r1, _0801A2FC @ =0x083FFAC0
	ldr r0, [r1, #0x08]
	ldr r0, [r0, #0x04]
	ands r0, r4
	mov r2, r8
	subs r3, r0, r2
	cmp r0, r8
	bcc _0801A2F2
	cmp r3, #0x0F
	bgt _0801A350
	.global _0801A2F2
_0801A2F2:
	ldr r0, [sp, #0x000]
	bl sub_0801A56C
	movs r0, #0x00
	b _0801A370
	.global _0801A2FC
_0801A2FC: .4byte 0x083FFAC0
	.global _0801A300
_0801A300:
	ldr r6, [r5, #0x0C]
	ldr r4, [r5, #0x08]
	str r6, [r4, #0x0C]
	str r4, [r6, #0x08]
	adds r2, r5, r1
	ldr r0, [r2, #0x04]
	movs r1, #0x01
	orrs r0, r1
	str r0, [r2, #0x04]
	b _0801A366
	.global _0801A314
_0801A314:
	mov r4, r8
	adds r2, r5, r4
	movs r1, #0x01
	orrs r4, r1
	str r4, [r5, #0x04]
	ldr r6, [r5, #0x0C]
	ldr r4, [r5, #0x08]
	str r6, [r4, #0x0C]
	str r4, [r6, #0x08]
	mov r7, r10
	str r2, [r7, #0x0C]
	str r2, [r7, #0x08]
	str r7, [r2, #0x0C]
	str r7, [r2, #0x08]
	adds r0, r3, #0x0
	orrs r0, r1
	str r0, [r2, #0x04]
	adds r0, r2, r3
	str r3, [r0, #0x00]
	b _0801A366
	.global _0801A33C
_0801A33C:
	adds r2, r5, r1
	ldr r0, [r2, #0x04]
	movs r1, #0x01
	orrs r0, r1
	str r0, [r2, #0x04]
	ldr r6, [r5, #0x0C]
	ldr r4, [r5, #0x08]
	str r6, [r4, #0x0C]
	str r4, [r6, #0x08]
	b _0801A366
	.global _0801A350
_0801A350:
	ldr r2, _0801A37C @ =0x083FFAC0
	ldr r5, [r2, #0x08]
	movs r1, #0x01
	mov r0, r8
	orrs r0, r1
	str r0, [r5, #0x04]
	mov r4, r8
	adds r0, r5, r4
	str r0, [r2, #0x08]
	orrs r3, r1
	str r3, [r0, #0x04]
	.global _0801A366
_0801A366:
	ldr r0, [sp, #0x000]
	bl sub_0801A56C
	adds r0, r5, #0x0
	adds r0, #0x08
	.global _0801A370
_0801A370:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7, pc}
	.global _0801A37C
_0801A37C: .4byte 0x083FFAC0
	thumb_func_start sub_0801A380
sub_0801A380:
	add sp, #-0x004
	cmp r1, #0x00
	bne _0801A388
	mov r1, sp
	.global _0801A388
_0801A388:
	cmp r2, #0x00
	beq _0801A3A4
	cmp r3, #0x00
	bne _0801A396
	movs r0, #0x01
	negs r0, r0
	b _0801A3A6
	.global _0801A396
_0801A396:
	ldrb r0, [r2, #0x00]
	str r0, [r1, #0x00]
	ldrb r0, [r2, #0x00]
	cmp r0, #0x00
	beq _0801A3A4
	movs r0, #0x01
	b _0801A3A6
	.global _0801A3A4
_0801A3A4:
	movs r0, #0x00
	.global _0801A3A6
_0801A3A6:
	add sp, #0x004
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0801A3AC
sub_0801A3AC:
	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0x0
	adds r1, r0, #0x0
	movs r0, #0xFF
	ands r5, r0
	cmp r2, #0x03
	bls _0801A420
	movs r0, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0801A420
	adds r4, r1, #0x0
	movs r6, #0x00
	movs r1, #0x00
	.global _0801A3C8
_0801A3C8:
	lsls r0, r6, #0x08
	adds r6, r0, r5
	adds r1, #0x01
	cmp r1, #0x03
	bls _0801A3C8
	cmp r2, #0x03
	bls _0801A406
	ldr r0, _0801A40C @ =0xFEFEFEFF
	mov r12, r0
	ldr r7, _0801A410 @ =0x80808080
	.global _0801A3DC
_0801A3DC:
	ldr r1, [r4, #0x00]
	eors r1, r6
	mov r3, r12
	adds r0, r1, r3
	bics r0, r1
	ands r0, r7
	cmp r0, #0x00
	beq _0801A3FE
	adds r1, r4, #0x0
	movs r3, #0x00
	.global _0801A3F0
_0801A3F0:
	ldrb r0, [r1, #0x00]
	cmp r0, r5
	beq _0801A41A
	adds r1, #0x01
	adds r3, #0x01
	cmp r3, #0x03
	bls _0801A3F0
	.global _0801A3FE
_0801A3FE:
	subs r2, #0x04
	adds r4, #0x04
	cmp r2, #0x03
	bhi _0801A3DC
	.global _0801A406
_0801A406:
	adds r1, r4, #0x0
	b _0801A420
	.byte 0x00, 0x00
	.global _0801A40C
_0801A40C: .4byte 0xFEFEFEFF
	.global _0801A410
_0801A410: .4byte 0x80808080
	.global _0801A414
_0801A414:
	ldrb r0, [r1, #0x00]
	cmp r0, r5
	bne _0801A41E
	.global _0801A41A
_0801A41A:
	adds r0, r1, #0x0
	b _0801A42A
	.global _0801A41E
_0801A41E:
	adds r1, #0x01
	.global _0801A420
_0801A420:
	adds r0, r2, #0x0
	subs r2, #0x01
	cmp r0, #0x00
	bne _0801A414
	movs r0, #0x00
	.global _0801A42A
_0801A42A:
	pop {r4, r5, r6, r7, pc}
	thumb_func_start sub_0801A42C
sub_0801A42C:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	adds r3, r1, #0x0
	cmp r2, #0x0F
	bls _0801A46C
	adds r0, r3, #0x0
	orrs r0, r5
	movs r1, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0801A46C
	adds r1, r5, #0x0
	.global _0801A446
_0801A446:
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, #0x10
	cmp r2, #0x0F
	bhi _0801A446
	cmp r2, #0x03
	bls _0801A46A
	.global _0801A460
_0801A460:
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, #0x04
	cmp r2, #0x03
	bhi _0801A460
	.global _0801A46A
_0801A46A:
	adds r4, r1, #0x0
	.global _0801A46C
_0801A46C:
	subs r2, #0x01
	movs r0, #0x01
	negs r0, r0
	cmp r2, r0
	beq _0801A486
	adds r1, r0, #0x0
	.global _0801A478
_0801A478:
	ldrb r0, [r3, #0x00]
	strb r0, [r4, #0x00]
	adds r3, #0x01
	adds r4, #0x01
	subs r2, #0x01
	cmp r2, r1
	bne _0801A478
	.global _0801A486
_0801A486:
	adds r0, r5, #0x0
	pop {r4, r5, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_0801A48C
sub_0801A48C:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	adds r3, r1, #0x0
	cmp r3, r5
	bcs _0801A4BE
	adds r0, r3, r2
	cmp r5, r0
	bcs _0801A4BE
	adds r3, r0, #0x0
	adds r4, r5, r2
	subs r2, #0x01
	movs r0, #0x01
	negs r0, r0
	cmp r2, r0
	beq _0801A510
	adds r1, r0, #0x0
	.global _0801A4AE
_0801A4AE:
	subs r4, #0x01
	subs r3, #0x01
	ldrb r0, [r3, #0x00]
	strb r0, [r4, #0x00]
	subs r2, #0x01
	cmp r2, r1
	bne _0801A4AE
	b _0801A510
	.global _0801A4BE
_0801A4BE:
	cmp r2, #0x0F
	bls _0801A4F6
	adds r0, r3, #0x0
	orrs r0, r4
	movs r1, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0801A4F6
	adds r1, r3, #0x0
	.global _0801A4D0
_0801A4D0:
	ldm r1!, {r0}
	stm r4!, {r0}
	ldm r1!, {r0}
	stm r4!, {r0}
	ldm r1!, {r0}
	stm r4!, {r0}
	ldm r1!, {r0}
	stm r4!, {r0}
	subs r2, #0x10
	cmp r2, #0x0F
	bhi _0801A4D0
	cmp r2, #0x03
	bls _0801A4F4
	.global _0801A4EA
_0801A4EA:
	ldm r1!, {r0}
	stm r4!, {r0}
	subs r2, #0x04
	cmp r2, #0x03
	bhi _0801A4EA
	.global _0801A4F4
_0801A4F4:
	adds r3, r1, #0x0
	.global _0801A4F6
_0801A4F6:
	subs r2, #0x01
	movs r0, #0x01
	negs r0, r0
	cmp r2, r0
	beq _0801A510
	adds r1, r0, #0x0
	.global _0801A502
_0801A502:
	ldrb r0, [r3, #0x00]
	strb r0, [r4, #0x00]
	adds r3, #0x01
	adds r4, #0x01
	subs r2, #0x01
	cmp r2, r1
	bne _0801A502
	.global _0801A510
_0801A510:
	adds r0, r5, #0x0
	pop {r4, r5, pc}
	thumb_func_start sub_0801A514
sub_0801A514:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	adds r3, r5, #0x0
	cmp r2, #0x03
	bls _0801A55A
	movs r0, #0x03
	ands r0, r5
	cmp r0, #0x00
	bne _0801A55A
	adds r1, r5, #0x0
	movs r0, #0xFF
	ands r4, r0
	lsls r3, r4, #0x08
	orrs r3, r4
	lsls r0, r3, #0x10
	orrs r3, r0
	cmp r2, #0x0F
	bls _0801A54E
	.global _0801A53A
_0801A53A:
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	subs r2, #0x10
	cmp r2, #0x0F
	bhi _0801A53A
	b _0801A54E
	.global _0801A54A
_0801A54A:
	stm r1!, {r3}
	subs r2, #0x04
	.global _0801A54E
_0801A54E:
	cmp r2, #0x03
	bhi _0801A54A
	adds r3, r1, #0x0
	b _0801A55A
	.global _0801A556
_0801A556:
	strb r4, [r3, #0x00]
	adds r3, #0x01
	.global _0801A55A
_0801A55A:
	adds r0, r2, #0x0
	subs r2, #0x01
	cmp r0, #0x00
	bne _0801A556
	adds r0, r5, #0x0
	pop {r4, r5, pc}
	.byte 0x00, 0x00
