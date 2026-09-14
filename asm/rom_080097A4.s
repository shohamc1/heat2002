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
	thumb_func_start sub_080097A4
sub_080097A4:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r5, r1, #0x0
	adds r4, r2, #0x0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, _08009854 @ =0x0200215C
	mov r9, r0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x04
	bne _080097CE
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x00
	strb r0, [r1, #0x00]
	.global _080097CE
_080097CE:
	movs r1, #0xC7
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r2, _08009858 @ =0x00000175
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	ldr r0, _0800985C @ =0x0202CAD0
	strb r1, [r0, #0x00]
	adds r2, #0x0B
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	subs r2, #0x0A
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	movs r0, #0xBE
	lsls r0, r0, #0x01
	adds r2, r5, r0
	ldr r0, _08009860 @ =0x020253B8
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	ldr r0, _08009864 @ =0x0202A51C
	strb r1, [r0, #0x00]
	movs r0, #0xB3
	lsls r0, r0, #0x01
	adds r2, r5, r0
	movs r0, #0x01
	strb r0, [r2, #0x00]
	ldr r2, _08009868 @ =0x00000167
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	str r4, [r5, #0x00]
	str r3, [r5, #0x08]
	movs r2, #0x00
	mov r3, sp
	ldrh r3, [r3, #0x24]
	strh r3, [r5, #0x34]
	str r1, [r5, #0x2C]
	str r1, [r5, #0x28]
	adds r0, r5, #0x0
	adds r0, #0x40
	strh r1, [r0, #0x00]
	subs r0, #0x02
	strb r2, [r0, #0x00]
	adds r0, #0x17
	strb r2, [r0, #0x00]
	subs r0, #0x08
	strb r2, [r0, #0x00]
	movs r1, #0xBA
	lsls r1, r1, #0x01
	adds r0, r5, r1
	strb r2, [r0, #0x00]
	mov r2, r9
	ldrb r2, [r2, #0x00]
	cmp r2, #0x04
	bne _08009870
	ldr r0, _0800986C @ =0x08367730
	mov r3, r8
	lsls r1, r3, #0x01
	add r1, r8
	b _0800987A
	.byte 0x00, 0x00
	.global _08009854
_08009854: .4byte 0x0200215C
	.global _08009858
_08009858: .4byte 0x00000175
	.global _0800985C
_0800985C: .4byte 0x0202CAD0
	.global _08009860
_08009860: .4byte 0x020253B8
	.global _08009864
_08009864: .4byte 0x0202A51C
	.global _08009868
_08009868: .4byte 0x00000167
	.global _0800986C
_0800986C: .4byte 0x08367730
	.global _08009870
_08009870:
	ldr r0, _08009988 @ =0x08367730
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldrb r1, [r1, #0x00]
	.global _0800987A
_0800987A:
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	str r0, [r5, #0x58]
	adds r0, r5, #0x0
	adds r0, #0x7C
	movs r1, #0x00
	strb r1, [r0, #0x00]
	adds r2, r5, #0x0
	adds r2, #0x84
	movs r0, #0x01
	strb r0, [r2, #0x00]
	str r1, [r5, #0x30]
	adds r0, r5, #0x0
	adds r0, #0x88
	str r1, [r0, #0x00]
	adds r0, #0x1A
	strh r1, [r0, #0x00]
	subs r0, #0x16
	str r1, [r0, #0x00]
	adds r0, #0x04
	str r1, [r0, #0x00]
	adds r0, #0x04
	str r1, [r0, #0x00]
	adds r0, #0x04
	str r1, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x9C
	movs r0, #0xB4
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	mov r3, r9
	ldrb r3, [r3, #0x00]
	cmp r3, #0x0F
	bne _080098D4
	ldr r0, _0800998C @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _080098D4
	ldr r0, _08009990 @ =0x0202A550
	cmp r5, r0
	bne _080098D4
	movs r0, #0xA0
	lsls r0, r0, #0x07
	str r0, [r1, #0x00]
	.global _080098D4
_080098D4:
	ldr r4, _08009994 @ =0x0200215C
	ldrb r0, [r4, #0x00]
	cmp r0, #0x04
	beq _080098E4
	adds r0, r5, #0x0
	mov r1, r8
	bl sub_0800C0E8
	.global _080098E4
_080098E4:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x05
	beq _080098F8
	cmp r0, #0x11
	beq _080098F8
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x00
	str r0, [r1, #0x00]
	.global _080098F8
_080098F8:
	movs r3, #0xB8
	lsls r3, r3, #0x01
	adds r0, r5, r3
	movs r4, #0x00
	strb r4, [r0, #0x00]
	ldr r0, _08009998 @ =0x00000171
	adds r6, r5, r0
	strb r4, [r6, #0x00]
	movs r1, #0xB9
	lsls r1, r1, #0x01
	adds r0, r5, r1
	strb r4, [r0, #0x00]
	movs r2, #0x94
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r1, [sp, #0x024]
	bl sub_0800C984
	movs r3, #0x9A
	lsls r3, r3, #0x01
	adds r0, r5, r3
	str r4, [r0, #0x00]
	movs r0, #0x9C
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x01
	negs r0, r0
	str r0, [r1, #0x00]
	ldr r1, _0800999C @ =0x00000173
	adds r0, r5, r1
	strb r4, [r0, #0x00]
	strb r4, [r6, #0x00]
	movs r1, #0x00
	adds r2, r5, #0x0
	adds r2, #0x4C
	adds r6, r5, #0x0
	adds r6, #0xE4
	adds r7, r5, #0x0
	adds r7, #0xE8
	movs r3, #0xEC
	adds r3, r3, r5
	mov r12, r3
	movs r0, #0x7D
	adds r0, r0, r5
	mov r10, r0
	adds r3, r5, #0x0
	adds r3, #0x4E
	str r3, [sp, #0x000]
	ldr r4, _080099A0 @ =0x0202CBC8
	movs r3, #0x00
	.global _0800995C
_0800995C:
	adds r0, r1, r4
	strb r3, [r0, #0x00]
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x08
	bne _0800995C
	ldr r0, _08009994 @ =0x0200215C
	mov r9, r0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0F
	bne _08009A14
	ldr r0, _0800998C @ =0x0202ED70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0F
	bhi _08009A14
	lsls r0, r0, #0x02
	ldr r1, _080099A4 @ =0x080099A8
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
	.global _08009988
_08009988: .4byte 0x08367730
	.global _0800998C
_0800998C: .4byte 0x0202ED70
	.global _08009990
_08009990: .4byte 0x0202A550
	.global _08009994
_08009994: .4byte 0x0200215C
	.global _08009998
_08009998: .4byte 0x00000171
	.global _0800999C
_0800999C: .4byte 0x00000173
	.global _080099A0
_080099A0: .4byte 0x0202CBC8
	.global _080099A4
_080099A4: .4byte 0x080099A8
	.byte 0xE8, 0x99, 0x00, 0x08, 0xEC, 0x99, 0x00, 0x08, 0xF0, 0x99, 0x00, 0x08, 0xF4, 0x99, 0x00, 0x08
	.byte 0x14, 0x9A, 0x00, 0x08, 0x14, 0x9A, 0x00, 0x08, 0xF8, 0x99, 0x00, 0x08, 0x14, 0x9A, 0x00, 0x08
	.byte 0x14, 0x9A, 0x00, 0x08, 0x14, 0x9A, 0x00, 0x08, 0xFC, 0x99, 0x00, 0x08, 0x00, 0x9A, 0x00, 0x08
	.byte 0x04, 0x9A, 0x00, 0x08, 0x08, 0x9A, 0x00, 0x08, 0x0C, 0x9A, 0x00, 0x08, 0x10, 0x9A, 0x00, 0x08
	.byte 0x01, 0x20, 0x14, 0xE0, 0x04, 0x20, 0x12, 0xE0, 0x05, 0x20, 0x10, 0xE0, 0x28, 0x20, 0x0E, 0xE0
	.byte 0x28, 0x20, 0x0C, 0xE0, 0x0F, 0x20, 0x0A, 0xE0, 0x0F, 0x20, 0x08, 0xE0, 0x55, 0x20, 0x06, 0xE0
	.byte 0x12, 0x20, 0x04, 0xE0, 0x05, 0x20, 0x02, 0xE0, 0x14, 0x20, 0x00, 0xE0
	.global _08009A14
_08009A14:
	movs r0, #0x00
	strb r0, [r2, #0x00]
	mov r1, r9
	ldrb r0, [r1, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bls _08009A2C
	ldrb r0, [r2, #0x00]
	subs r0, #0x01
	strb r0, [r2, #0x00]
	.global _08009A2C
_08009A2C:
	movs r1, #0x00
	str r1, [r5, #0x50]
	movs r3, #0xAE
	lsls r3, r3, #0x01
	adds r2, r5, r3
	movs r0, #0x96
	lsls r0, r0, #0x01
	str r0, [r2, #0x00]
	str r1, [r5, #0x0C]
	str r1, [r5, #0x14]
	movs r2, #0x88
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	subs r3, #0x1C
	adds r0, r5, r3
	str r1, [r0, #0x00]
	adds r2, #0x34
	adds r0, r5, r2
	str r1, [r0, #0x00]
	subs r3, #0x04
	adds r0, r5, r3
	str r1, [r0, #0x00]
	adds r2, #0x04
	adds r0, r5, r2
	str r1, [r0, #0x00]
	adds r3, #0x10
	adds r0, r5, r3
	str r1, [r0, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x63
	strb r0, [r1, #0x00]
	ldr r4, _08009B00 @ =0x08367FBC
	adds r2, #0x1A
	adds r1, r5, r2
	ldrb r3, [r1, #0x00]
	lsls r0, r3, #0x02
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x00]
	ldr r3, _08009B04 @ =0x08368034
	ldrb r2, [r1, #0x00]
	lsls r0, r2, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x00]
	ldr r2, _08009B08 @ =0x083680AC
	ldrb r1, [r1, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	mov r1, r12
	str r0, [r1, #0x00]
	ldr r0, _08009B0C @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08009ACA
	mov r0, r8
	cmp r0, #0x00
	beq _08009ACA
	mov r1, r9
	ldrb r1, [r1, #0x00]
	cmp r1, #0x02
	beq _08009ACA
	ldr r0, _08009B10 @ =0x08367BFA
	str r0, [r6, #0x00]
	ldr r0, _08009B14 @ =0x08367C06
	str r0, [r7, #0x00]
	ldr r0, _08009B18 @ =0x08367C10
	mov r1, r12
	str r0, [r1, #0x00]
	ldr r0, [r4, #0x00]
	str r0, [r6, #0x00]
	ldr r0, [r3, #0x00]
	str r0, [r7, #0x00]
	ldr r0, [r2, #0x00]
	str r0, [r1, #0x00]
	.global _08009ACA
_08009ACA:
	movs r2, #0xAC
	lsls r2, r2, #0x01
	adds r0, r5, r2
	movs r1, #0x00
	str r1, [r0, #0x00]
	mov r3, r10
	strb r1, [r3, #0x00]
	movs r2, #0x00
	mov r0, sp
	ldrh r0, [r0, #0x24]
	strh r0, [r5, #0x36]
	strh r1, [r5, #0x38]
	movs r3, #0xB0
	lsls r3, r3, #0x01
	adds r0, r5, r3
	strh r1, [r0, #0x00]
	ldr r0, [sp, #0x000]
	strb r2, [r0, #0x00]
	strh r1, [r5, #0x3C]
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08009B00
_08009B00: .4byte 0x08367FBC
	.global _08009B04
_08009B04: .4byte 0x08368034
	.global _08009B08
_08009B08: .4byte 0x083680AC
	.global _08009B0C
_08009B0C: .4byte 0x020020DC
	.global _08009B10
_08009B10: .4byte 0x08367BFA
	.global _08009B14
_08009B14: .4byte 0x08367C06
	.global _08009B18
_08009B18: .4byte 0x08367C10
	.byte 0x70, 0x47, 0x00, 0x00
