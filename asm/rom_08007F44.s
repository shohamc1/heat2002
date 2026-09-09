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
	thumb_func_start sub_08007F44
sub_08007F44:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _08007F88 @ =0x0806C894
	movs r1, #0x0B
	movs r2, #0x07
	bl sub_0800649C
	cmp r4, #0x00
	bne _08007F64
	ldr r1, _08007F8C @ =0x0202A524
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08007F9C
	.global _08007F64
_08007F64:
	ldr r0, _08007F90 @ =0x0836813C
	ldr r0, [r0, #0x00]
	movs r1, #0x06
	movs r2, #0x09
	bl sub_0800649C
	ldr r1, _08007F94 @ =0x0836814C
	ldr r0, _08007F98 @ =0x0202CBC0
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x0D
	movs r2, #0x09
	bl sub_0800649C
	b _08007FA6
	.byte 0x00, 0x00
	.global _08007F88
_08007F88: .4byte 0x0806C894
	.global _08007F8C
_08007F8C: .4byte 0x0202A524
	.global _08007F90
_08007F90: .4byte 0x0836813C
	.global _08007F94
_08007F94: .4byte 0x0836814C
	.global _08007F98
_08007F98: .4byte 0x0202CBC0
	.global _08007F9C
_08007F9C:
	ldr r0, _08007FD8 @ =0x0806C8A0
	movs r1, #0x06
	movs r2, #0x09
	bl sub_0800649C
	.global _08007FA6
_08007FA6:
	cmp r4, #0x01
	bne _08007FB6
	ldr r1, _08007FDC @ =0x0202A524
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08007FEC
	.global _08007FB6
_08007FB6:
	ldr r0, _08007FE0 @ =0x0836813C
	ldr r0, [r0, #0x04]
	movs r1, #0x06
	movs r2, #0x0A
	bl sub_0800649C
	ldr r1, _08007FE4 @ =0x0836815C
	ldr r0, _08007FE8 @ =0x0202CBC0
	ldrb r0, [r0, #0x01]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x0D
	movs r2, #0x0A
	bl sub_0800649C
	b _08007FF6
	.global _08007FD8
_08007FD8: .4byte 0x0806C8A0
	.global _08007FDC
_08007FDC: .4byte 0x0202A524
	.global _08007FE0
_08007FE0: .4byte 0x0836813C
	.global _08007FE4
_08007FE4: .4byte 0x0836815C
	.global _08007FE8
_08007FE8: .4byte 0x0202CBC0
	.global _08007FEC
_08007FEC:
	ldr r0, _08008028 @ =0x0806C878
	movs r1, #0x06
	movs r2, #0x0A
	bl sub_0800649C
	.global _08007FF6
_08007FF6:
	cmp r4, #0x02
	bne _08008006
	ldr r1, _0800802C @ =0x0202A524
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _0800803C
	.global _08008006
_08008006:
	ldr r0, _08008030 @ =0x0836813C
	ldr r0, [r0, #0x08]
	movs r1, #0x06
	movs r2, #0x0B
	bl sub_0800649C
	ldr r1, _08008034 @ =0x08368168
	ldr r0, _08008038 @ =0x0202CBC0
	ldrb r0, [r0, #0x02]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x0D
	movs r2, #0x0B
	bl sub_0800649C
	b _08008046
	.global _08008028
_08008028: .4byte 0x0806C878
	.global _0800802C
_0800802C: .4byte 0x0202A524
	.global _08008030
_08008030: .4byte 0x0836813C
	.global _08008034
_08008034: .4byte 0x08368168
	.global _08008038
_08008038: .4byte 0x0202CBC0
	.global _0800803C
_0800803C:
	ldr r0, _08008064 @ =0x0806C878
	movs r1, #0x06
	movs r2, #0x0B
	bl sub_0800649C
	.global _08008046
_08008046:
	cmp r4, #0x03
	bne _08008056
	ldr r1, _08008068 @ =0x0202A524
	movs r0, #0x04
	ldrb r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08008070
	.global _08008056
_08008056:
	ldr r0, _0800806C @ =0x0836813C
	ldr r0, [r0, #0x0C]
	movs r1, #0x0D
	movs r2, #0x0C
	bl sub_0800649C
	b _0800807A
	.global _08008064
_08008064: .4byte 0x0806C878
	.global _08008068
_08008068: .4byte 0x0202A524
	.global _0800806C
_0800806C: .4byte 0x0836813C
	.global _08008070
_08008070:
	ldr r0, _08008088 @ =0x0806C8A0
	movs r1, #0x0A
	movs r2, #0x0C
	bl sub_0800649C
	.global _0800807A
_0800807A:
	ldr r1, _0800808C @ =0x0202A524
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.global _08008088
_08008088: .4byte 0x0806C8A0
	.global _0800808C
_0800808C: .4byte 0x0202A524
