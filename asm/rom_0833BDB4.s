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
	thumb_func_start sub_0833BDB4
sub_0833BDB4:
	push {r4, r5, r6, lr}
	mov r6, r9
	mov r5, r8
	push {r5, r6}
	ldr r0, _0833BEBC @ =0x04000128
	movs r1, #0x00
	mov r9, r1
	movs r2, #0x00
	mov r8, r2
	mov r1, r8
	strh r1, [r0, #0x02]
	bl sub_08339A40
	ldr r6, _0833BEC0 @ =0x04000200
	mov r2, r8
	strh r2, [r6, #0x00]
	ldr r1, _0833BEC4 @ =0x04000208
	movs r0, #0x01
	strh r0, [r1, #0x00]
	ldr r5, _0833BEC8 @ =0x04000004
	movs r4, #0x08
	strh r4, [r5, #0x00]
	bl sub_08339B4C
	ldr r0, _0833BECC @ =0x020390C4
	mov r1, r9
	strb r1, [r0, #0x00]
	ldr r0, _0833BED0 @ =0x02003B31
	bl sub_08339AB8
	ldr r2, _0833BED4 @ =0x00002001
	adds r0, r2, #0x0
	strh r0, [r6, #0x00]
	strh r4, [r5, #0x00]
	ldr r0, _0833BED8 @ =0x00007FFF
	bl sub_0833D250
	movs r0, #0x00
	movs r1, #0x32
	bl sub_0833D510
	bl sub_08339B18
	ldr r1, _0833BEDC @ =0x0400000E
	ldr r2, _0833BEE0 @ =0x00003D0B
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	subs r1, #0x02
	ldr r2, _0833BEE4 @ =0x00001E01
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	subs r1, #0x02
	ldr r2, _0833BEE8 @ =0x00001F02
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	subs r1, #0x02
	ldr r2, _0833BEEC @ =0x00001C0C
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	adds r1, #0x4A
	ldr r2, _0833BEF0 @ =0x00000808
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	subs r1, #0x02
	subs r2, #0xC8
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	subs r1, #0x50
	movs r2, #0xEA
	lsls r2, r2, #0x05
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	bl sub_0833A830
	bl sub_0833AF0C
	ldr r0, _0833BEF4 @ =0x02039134
	mov r1, r8
	strh r1, [r0, #0x00]
	.global _0833BE52
_0833BE52:
	ldr r1, _0833BEF8 @ =0x02039194
	movs r0, #0x03
	strb r0, [r1, #0x00]
	bl sub_08344A20
	ldr r1, _0833BEFC @ =0x020390EC
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _0833BF00 @ =0x02039190
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x0A
	bl sub_0833D510
	movs r0, #0x00
	movs r1, #0x04
	movs r2, #0x00
	bl sub_0833BF80
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0833BF14
	movs r0, #0x00
	bl sub_0833BD94
	movs r1, #0x0A
	movs r2, #0x01
	bl sub_0833EE88
	ldr r0, _0833BF04 @ =0x0200CEC0
	movs r1, #0x0C
	movs r2, #0x01
	bl sub_0833EE88
	ldr r0, _0833BF08 @ =0x0200CED8
	movs r1, #0x0D
	movs r2, #0x01
	bl sub_0833EE88
	ldr r0, _0833BF0C @ =0x02038F70
	bl sub_0833B074
	ldr r0, _0833BF10 @ =0x02038FB0
	bl sub_0833B074
	bl sub_0833AE90
	.global _0833BEB2
_0833BEB2:
	bl sub_0833D9D8
	bl sub_08344B74
	b _0833BEB2
	.global _0833BEBC
_0833BEBC: .4byte 0x04000128
	.global _0833BEC0
_0833BEC0: .4byte 0x04000200
	.global _0833BEC4
_0833BEC4: .4byte 0x04000208
	.global _0833BEC8
_0833BEC8: .4byte 0x04000004
	.global _0833BECC
_0833BECC: .4byte 0x020390C4
	.global _0833BED0
_0833BED0: .4byte 0x02003B31
	.global _0833BED4
_0833BED4: .4byte 0x00002001
	.global _0833BED8
_0833BED8: .4byte 0x00007FFF
	.global _0833BEDC
_0833BEDC: .4byte 0x0400000E
	.global _0833BEE0
_0833BEE0: .4byte 0x00003D0B
	.global _0833BEE4
_0833BEE4: .4byte 0x00001E01
	.global _0833BEE8
_0833BEE8: .4byte 0x00001F02
	.global _0833BEEC
_0833BEEC: .4byte 0x00001C0C
	.global _0833BEF0
_0833BEF0: .4byte 0x00000808
	.global _0833BEF4
_0833BEF4: .4byte 0x02039134
	.global _0833BEF8
_0833BEF8: .4byte 0x02039194
	.global _0833BEFC
_0833BEFC: .4byte 0x020390EC
	.global _0833BF00
_0833BF00: .4byte 0x02039190
	.global _0833BF04
_0833BF04: .4byte 0x0200CEC0
	.global _0833BF08
_0833BF08: .4byte 0x0200CED8
	.global _0833BF0C
_0833BF0C: .4byte 0x02038F70
	.global _0833BF10
_0833BF10: .4byte 0x02038FB0
	.global _0833BF14
_0833BF14:
	bl sub_0833BCF8
	bl sub_0833DE98
	b _0833BE52
	.byte 0x00, 0x00
