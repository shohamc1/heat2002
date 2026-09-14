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
	thumb_func_start sub_080050F0
sub_080050F0:
	push {r4, r5, r6, r7, lr}
	ldr r4, _0800511C @ =0xFFFFFE00
	add sp, r4
	ldr r1, _08005120 @ =0x020253C4
	movs r0, #0xFF
	strb r0, [r1, #0x00]
	ldr r4, _08005124 @ =0x02025248
	movs r0, #0x00
	strb r0, [r4, #0x00]
	bl sub_08004DB4
	ldr r1, _08005128 @ =0x02025258
	movs r0, #0x08
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080051D0
	bl sub_08010094
	adds r7, r4, #0x0
	ldr r6, _0800512C @ =0x0202539C
	b _080051C6
	.global _0800511C
_0800511C: .4byte 0xFFFFFE00
	.global _08005120
_08005120: .4byte 0x020253C4
	.global _08005124
_08005124: .4byte 0x02025248
	.global _08005128
_08005128: .4byte 0x02025258
	.global _0800512C
_0800512C: .4byte 0x0202539C
	.global _08005130
_08005130:
	bl sub_08004DB4
	ldr r1, _08005164 @ =0x02025258
	movs r0, #0xC0
	ldrh r2, [r1, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _08005148
	movs r0, #0x01
	ldrb r2, [r7, #0x00]
	eors r0, r2
	strb r0, [r7, #0x00]
	.global _08005148
_08005148:
	ldrh r1, [r1, #0x00]
	movs r0, #0x08
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _08005168
	strb r4, [r6, #0x00]
	movs r0, #0x03
	bl sub_08004C44
	movs r0, #0x01
	b _080051D2
	.byte 0x00, 0x00
	.global _08005164
_08005164: .4byte 0x02025258
	.global _08005168
_08005168:
	movs r4, #0x01
	ands r4, r1
	cmp r4, #0x00
	beq _08005194
	strb r0, [r6, #0x00]
	movs r0, #0x03
	bl sub_08004C44
	ldr r4, _08005190 @ =0x02025248
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08005184
	bl sub_08005024
	.global _08005184
_08005184:
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080051D2
	.byte 0x00, 0x00
	.global _08005190
_08005190: .4byte 0x02025248
	.global _08005194
_08005194:
	movs r0, #0x02
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x00
	beq _080051AE
	strb r4, [r6, #0x00]
	movs r0, #0x03
	bl sub_08004C44
	strb r4, [r7, #0x00]
	movs r0, #0x01
	b _080051D2
	.global _080051AE
_080051AE:
	ldrb r0, [r7, #0x00]
	bl sub_08004C44
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	strb r0, [r6, #0x00]
	ldr r0, _080051E0 @ =0x020020C0
	strb r5, [r0, #0x00]
	.global _080051BE
_080051BE:
	ldr r0, _080051E0 @ =0x020020C0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080051BE
	.global _080051C6
_080051C6:
	bl sub_08003330
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _08005130
	.global _080051D0
_080051D0:
	movs r0, #0x00
	.global _080051D2
_080051D2:
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _080051E0
_080051E0: .4byte 0x020020C0
