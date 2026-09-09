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
	thumb_func_start sub_0833ED10
sub_0833ED10:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _0833EDA8 @ =0x020251B8
	ldr r0, [r1, #0x00]
	movs r3, #0xEA
	lsls r3, r3, #0x02
	adds r2, r0, r3
	movs r0, #0x00
	mov r12, r1
	ldr r1, _0833EDAC @ =0x0203E0E0
	mov r8, r1
	ldr r7, _0833EDB0 @ =0x02022254
	ldr r6, _0833EDB4 @ =0x02021594
	movs r3, #0xE0
	lsls r3, r3, #0x08
	adds r5, r3, #0x0
	.global _0833ED32
_0833ED32:
	movs r3, #0x00
	adds r1, r0, #0x0
	adds r1, #0x08
	adds r4, r0, #0x1
	lsls r0, r1, #0x04
	adds r0, r0, r1
	lsls r1, r0, #0x02
	.global _0833ED40
_0833ED40:
	adds r0, r1, r3
	adds r0, #0x33
	lsls r0, r0, #0x01
	adds r0, r0, r6
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r7
	ldrh r0, [r0, #0x00]
	orrs r0, r5
	strh r0, [r2, #0x00]
	adds r2, #0x02
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x0A
	bne _0833ED40
	adds r2, #0x2C
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x06
	bne _0833ED32
	mov r1, r12
	ldr r0, [r1, #0x00]
	movs r3, #0xEA
	lsls r3, r3, #0x02
	adds r2, r0, r3
	mov r1, r8
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833ED9C
	movs r0, #0x00
	movs r1, #0x47
	.global _0833ED80
_0833ED80:
	movs r3, #0x00
	adds r4, r0, #0x1
	.global _0833ED84
_0833ED84:
	strh r1, [r2, #0x00]
	adds r2, #0x02
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x04
	bne _0833ED84
	adds r2, #0x38
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x06
	bne _0833ED80
	.global _0833ED9C
_0833ED9C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833EDA8
_0833EDA8: .4byte 0x020251B8
	.global _0833EDAC
_0833EDAC: .4byte 0x0203E0E0
	.global _0833EDB0
_0833EDB0: .4byte 0x02022254
	.global _0833EDB4
_0833EDB4: .4byte 0x02021594
