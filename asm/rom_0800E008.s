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
	thumb_func_start sub_0800E008
sub_0800E008:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	movs r0, #0x00
	str r0, [sp, #0x004]
	movs r5, #0x00
	ldr r3, _0800E164 @ =0x04000200
	movs r0, #0x01
	strh r0, [r3, #0x00]
	ldr r0, _0800E168 @ =0x080000B2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x96
	bne _0800E03E
	ldr r0, _0800E16C @ =0x080000AC
	ldr r1, _0800E170 @ =0x0807C9E8
	ldr r2, [r0, #0x00]
	ldr r0, [r1, #0x00]
	cmp r2, r0
	bne _0800E03E
	ldrh r0, [r3, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x06
	adds r1, r2, #0x0
	orrs r0, r1
	strh r0, [r3, #0x00]
	.global _0800E03E
_0800E03E:
	ldr r1, _0800E174 @ =0x04000004
	movs r0, #0x08
	strh r0, [r1, #0x00]
	ldr r1, _0800E178 @ =0x04000208
	movs r0, #0x01
	strh r0, [r1, #0x00]
	ldr r1, _0800E17C @ =0x02000590
	ldr r0, _0800E180 @ =0x0800DFC1
	str r0, [r1, #0x04]
	ldr r0, _0800E184 @ =0x0800E641
	str r0, [r1, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2, #0x00]
	ldr r0, _0800E188 @ =0x0000EFFF
	ands r0, r1
	strh r0, [r2, #0x00]
	movs r4, #0x00
	lsls r3, r5, #0x02
	mov r8, r3
	lsls r7, r5, #0x0F
	add r0, sp, #0x004
	mov r9, r0
	adds r6, r5, #0x1
	ldr r5, _0800E18C @ =0x083FDA50
	.global _0800E070
_0800E070:
	lsls r0, r4, #0x02
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	lsls r1, r4, #0x09
	ldr r2, _0800E190 @ =0x06010000
	adds r1, r1, r2
	bl LZ77UnCompVram
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x02
	bls _0800E070
	ldr r2, _0800E194 @ =0x040000D4
	ldr r0, _0800E198 @ =0x0807CB58
	str r0, [r2, #0x00]
	ldr r0, _0800E19C @ =0x05000200
	str r0, [r2, #0x04]
	ldr r0, _0800E1A0 @ =0x84000028
	str r0, [r2, #0x08]
	ldr r0, [r2, #0x08]
	movs r0, #0xA0
	str r0, [sp, #0x000]
	mov r3, sp
	str r3, [r2, #0x00]
	ldr r0, _0800E1A4 @ =0x0202E960
	str r0, [r2, #0x04]
	ldr r1, _0800E1A8 @ =0x85000100
	str r1, [r2, #0x08]
	ldr r1, [r2, #0x08]
	movs r1, #0xE0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x01
	bl CpuFastSet
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2, #0x00]
	movs r3, #0x82
	lsls r3, r3, #0x05
	adds r1, r3, #0x0
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r0, _0800E1AC @ =0x0807C9CC
	add r0, r8
	ldr r1, [r0, #0x00]
	movs r0, #0x01
	bl sub_0800E3C4
	movs r4, #0x00
	.global _0800E0D6
_0800E0D6:
	adds r1, r4, #0x0
	adds r1, #0x08
	ldr r0, _0800E1B0 @ =0x0807C9F0
	movs r2, #0x01
	bl sub_08006950
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x03
	bls _0800E0D6
	.global _0800E0EC
_0800E0EC:
	ldr r4, [sp, #0x004]
	lsls r4, r4, #0x02
	adds r4, r7, r4
	lsrs r4, r4, #0x0A
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0x0
	movs r1, #0x64
	bl sub_0800DE9C
	adds r0, r4, #0x0
	movs r1, #0x64
	bl sub_0800DE60
	ldr r0, _0800E1B4 @ =0x0807CA08
	movs r1, #0x08
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _0800E1B8 @ =0x0807CA20
	movs r1, #0x09
	movs r2, #0x01
	bl sub_08006950
	ldr r0, _0800E1BC @ =0x0807CA34
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_08006950
	mov r0, r9
	bl sub_0800E460
	cmp r0, #0x00
	beq _0800E14E
	lsls r0, r6, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x07
	beq _0800E1C0
	ldr r1, _0800E1AC @ =0x0807C9CC
	lsls r0, r5, #0x02
	adds r0, r0, r1
	ldr r1, [r0, #0x00]
	movs r0, #0x01
	bl sub_0800E3C4
	movs r0, #0x00
	str r0, [sp, #0x004]
	lsls r7, r5, #0x0F
	adds r6, r5, #0x1
	.global _0800E14E
_0800E14E:
	ldr r0, _0800E1A4 @ =0x0202E960
	movs r1, #0xE0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x01
	bl CpuFastSet
	bl VBlankIntrWait
	b _0800E0EC
	.byte 0x00, 0x00
	.global _0800E164
_0800E164: .4byte 0x04000200
	.global _0800E168
_0800E168: .4byte 0x080000B2
	.global _0800E16C
_0800E16C: .4byte 0x080000AC
	.global _0800E170
_0800E170: .4byte 0x0807C9E8
	.global _0800E174
_0800E174: .4byte 0x04000004
	.global _0800E178
_0800E178: .4byte 0x04000208
	.global _0800E17C
_0800E17C: .4byte 0x02000590
	.global _0800E180
_0800E180: .4byte 0x0800DFC1
	.global _0800E184
_0800E184: .4byte 0x0800E641
	.global _0800E188
_0800E188: .4byte 0x0000EFFF
	.global _0800E18C
_0800E18C: .4byte 0x083FDA50
	.global _0800E190
_0800E190: .4byte 0x06010000
	.global _0800E194
_0800E194: .4byte 0x040000D4
	.global _0800E198
_0800E198: .4byte 0x0807CB58
	.global _0800E19C
_0800E19C: .4byte 0x05000200
	.global _0800E1A0
_0800E1A0: .4byte 0x84000028
	.global _0800E1A4
_0800E1A4: .4byte 0x0202E960
	.global _0800E1A8
_0800E1A8: .4byte 0x85000100
	.global _0800E1AC
_0800E1AC: .4byte 0x0807C9CC
	.global _0800E1B0
_0800E1B0: .4byte 0x0807C9F0
	.global _0800E1B4
_0800E1B4: .4byte 0x0807CA08
	.global _0800E1B8
_0800E1B8: .4byte 0x0807CA20
	.global _0800E1BC
_0800E1BC: .4byte 0x0807CA34
	.global _0800E1C0
_0800E1C0:
	movs r0, #0xA0
	str r0, [sp, #0x000]
	ldr r2, _0800E1F4 @ =0x040000D4
	mov r0, sp
	str r0, [r2, #0x00]
	ldr r0, _0800E1F8 @ =0x0202E960
	str r0, [r2, #0x04]
	ldr r1, _0800E1FC @ =0x85000100
	str r1, [r2, #0x08]
	ldr r1, [r2, #0x08]
	movs r1, #0xE0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x01
	bl CpuFastSet
	bl sub_0800DFCC
	movs r0, #0x00
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _0800E1F4
_0800E1F4: .4byte 0x040000D4
	.global _0800E1F8
_0800E1F8: .4byte 0x0202E960
	.global _0800E1FC
_0800E1FC: .4byte 0x85000100
