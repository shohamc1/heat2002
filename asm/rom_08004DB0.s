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
	thumb_func_start sub_08004DB4
sub_08004DB4:
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r4, _08004E10 @ =0x020253C4
	ldrb r0, [r4, #0x00]
	cmp r0, #0xFF
	bne _08004E24
	movs r3, #0x00
	movs r2, #0x00
	ldr r0, _08004E14 @ =0x020020AC
	ldrb r0, [r0, #0x00]
	ldr r1, _08004E18 @ =0x02025258
	mov r8, r1
	ldr r7, _08004E1C @ =0x020253BC
	mov r12, r7
	cmp r3, r0
	beq _08004DFC
	ldr r6, _08004E20 @ =0x020020A0
	movs r1, #0x08
	mov r9, r1
	adds r5, r0, #0x0
	.global _08004DE0
_08004DE0:
	lsls r0, r2, #0x01
	adds r1, r0, r6
	mov r0, r9
	ldrh r7, [r1, #0x00]
	ands r0, r7
	cmp r0, #0x00
	beq _08004DF2
	strb r2, [r4, #0x00]
	ldrh r3, [r1, #0x00]
	.global _08004DF2
_08004DF2:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r5
	bne _08004DE0
	.global _08004DFC
_08004DFC:
	adds r0, r3, #0x0
	mov r1, r12
	ldrh r1, [r1, #0x00]
	bics r0, r1
	mov r2, r8
	strh r0, [r2, #0x00]
	mov r4, r12
	strh r3, [r4, #0x00]
	b _08004E3C
	.byte 0x00, 0x00
	.global _08004E10
_08004E10: .4byte 0x020253C4
	.global _08004E14
_08004E14: .4byte 0x020020AC
	.global _08004E18
_08004E18: .4byte 0x02025258
	.global _08004E1C
_08004E1C: .4byte 0x020253BC
	.global _08004E20
_08004E20: .4byte 0x020020A0
	.global _08004E24
_08004E24:
	ldr r1, _08004E4C @ =0x020020A0
	ldrb r4, [r4, #0x00]
	lsls r0, r4, #0x01
	adds r0, r0, r1
	ldrh r3, [r0, #0x00]
	ldr r2, _08004E50 @ =0x02025258
	ldr r1, _08004E54 @ =0x020253BC
	adds r0, r3, #0x0
	ldrh r7, [r1, #0x00]
	bics r0, r7
	strh r0, [r2, #0x00]
	strh r3, [r1, #0x00]
	.global _08004E3C
_08004E3C:
	ldrh r0, [r2, #0x00]
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08004E4C
_08004E4C: .4byte 0x020020A0
	.global _08004E50
_08004E50: .4byte 0x02025258
	.global _08004E54
_08004E54: .4byte 0x020253BC
	.byte 0x70, 0xB5, 0x00, 0x22, 0x00, 0x21, 0x0D, 0x48, 0x00, 0x78, 0x0D, 0x4E, 0x0D, 0x4D, 0x82, 0x42
	.byte 0x0A, 0xD0, 0x0D, 0x4C, 0x03, 0x1C, 0x48, 0x00, 0x00, 0x19, 0x00, 0x88, 0x02, 0x43, 0x48, 0x1C
	.byte 0x00, 0x04, 0x01, 0x0C, 0x99, 0x42, 0xF6, 0xD1, 0x10, 0x1C, 0x29, 0x88, 0x88, 0x43, 0x30, 0x80
	.byte 0x2A, 0x80, 0x30, 0x88, 0x70, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0xAC, 0x20, 0x00, 0x02
	.byte 0x58, 0x52, 0x02, 0x02, 0xBC, 0x53, 0x02, 0x02, 0xA0, 0x20, 0x00, 0x02
