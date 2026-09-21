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
	thumb_func_start sub_0833CD2C
sub_0833CD2C:
	push {r4, r5, r6, lr}
	ldr r4, _0833CEBC @ =0xFFFFFDF8
	add sp, r4
	adds r6, r0, #0x0
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl sub_0833CCD4
	ldr r0, _0833CEC0 @ =0x02022428
	ldr r1, _0833CEC4 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08344B64
	ldr r5, _0833CEC8 @ =0x020251BC
	movs r0, #0x64
	adds r4, r6, #0x0
	muls r4, r0
	adds r0, r5, #0x0
	adds r0, #0x18
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x01
	add r1, sp, #0x008
	bl sub_08344B64
	ldr r0, _0833CECC @ =0x02021394
	add r1, sp, #0x1C8
	movs r2, #0x10
	bl sub_08344B64
	movs r0, #0x1E
	add r1, sp, #0x008
	bl sub_0833D31C
	ldr r1, _0833CED0 @ =0x02039244
	adds r0, r5, #0x0
	adds r0, #0x2C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CED4 @ =0x02039288
	adds r0, r5, #0x0
	adds r0, #0x34
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CED8 @ =0x02039228
	adds r0, r5, #0x0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEDC @ =0x02039268
	adds r0, r5, #0x0
	adds r0, #0x24
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEE0 @ =0x02039224
	adds r0, r5, #0x0
	adds r0, #0x28
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEE4 @ =0x02039238
	adds r0, r5, #0x0
	adds r0, #0x0C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEE8 @ =0x0203922C
	adds r0, r5, #0x0
	adds r0, #0x10
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEEC @ =0x020392A0
	adds r0, r5, #0x0
	adds r0, #0x3C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEF0 @ =0x02039280
	adds r0, r5, #0x0
	adds r0, #0x40
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _0833CEF4 @ =0x0203929C
	adds r0, r5, #0x0
	adds r0, #0x48
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	str r0, [r1, #0x00]
	cmp r6, #0x00
	bne _0833CDF6
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CDF6
_0833CDF6:
	cmp r6, #0x01
	bne _0833CE00
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x70
	str r0, [r1, #0x00]
	.global _0833CE00
_0833CE00:
	cmp r6, #0x02
	bne _0833CE0A
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0xA8
	str r0, [r1, #0x00]
	.global _0833CE0A
_0833CE0A:
	cmp r6, #0x03
	bne _0833CE14
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x6B
	str r0, [r1, #0x00]
	.global _0833CE14
_0833CE14:
	cmp r6, #0x04
	bne _0833CE1E
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0xA3
	str r0, [r1, #0x00]
	.global _0833CE1E
_0833CE1E:
	cmp r6, #0x05
	bne _0833CE28
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0xA6
	str r0, [r1, #0x00]
	.global _0833CE28
_0833CE28:
	cmp r6, #0x06
	bne _0833CE32
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CE32
_0833CE32:
	cmp r6, #0x08
	bne _0833CE3C
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CE3C
_0833CE3C:
	cmp r6, #0x09
	bne _0833CE46
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CE46
_0833CE46:
	cmp r6, #0x0A
	bne _0833CE50
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x5E
	str r0, [r1, #0x00]
	.global _0833CE50
_0833CE50:
	cmp r6, #0x0B
	bne _0833CE5A
	ldr r1, _0833CEF8 @ =0x02039220
	movs r0, #0x7D
	str r0, [r1, #0x00]
	.global _0833CE5A
_0833CE5A:
	ldr r0, _0833CED8 @ =0x02039228
	ldr r2, [r0, #0x00]
	ldr r3, _0833CEFC @ =0x03000800
	ldr r0, _0833CEE4 @ =0x02039238
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _0833CF00 @ =0x02039294
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x00
	movs r1, #0x00
	bl sub_0833CFC8
	ldr r0, _0833CEDC @ =0x02039268
	ldr r2, [r0, #0x00]
	ldr r3, _0833CF04 @ =0x03001000
	ldr r0, _0833CEE8 @ =0x0203922C
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	ldr r0, _0833CF08 @ =0x02039248
	ldrh r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x00
	movs r1, #0x00
	bl sub_0833CFC8
	bl sub_0833D094
	movs r0, #0x00
	movs r1, #0x00
	bl sub_0833D564
	adds r0, r6, #0x0
	bl sub_0834108C
	bl sub_0833E05C
	bl sub_0833E078
	ldr r1, _0833CF0C @ =0x0203B864
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r3, #0x82
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0833CEBC
_0833CEBC: .4byte 0xFFFFFDF8
	.global _0833CEC0
_0833CEC0: .4byte 0x02022428
	.global _0833CEC4
_0833CEC4: .4byte 0x0600C000
	.global _0833CEC8
_0833CEC8: .4byte 0x020251BC
	.global _0833CECC
_0833CECC: .4byte 0x02021394
	.global _0833CED0
_0833CED0: .4byte 0x02039244
	.global _0833CED4
_0833CED4: .4byte 0x02039288
	.global _0833CED8
_0833CED8: .4byte 0x02039228
	.global _0833CEDC
_0833CEDC: .4byte 0x02039268
	.global _0833CEE0
_0833CEE0: .4byte 0x02039224
	.global _0833CEE4
_0833CEE4: .4byte 0x02039238
	.global _0833CEE8
_0833CEE8: .4byte 0x0203922C
	.global _0833CEEC
_0833CEEC: .4byte 0x020392A0
	.global _0833CEF0
_0833CEF0: .4byte 0x02039280
	.global _0833CEF4
_0833CEF4: .4byte 0x0203929C
	.global _0833CEF8
_0833CEF8: .4byte 0x02039220
	.global _0833CEFC
_0833CEFC: .4byte 0x03000800
	.global _0833CF00
_0833CF00: .4byte 0x02039294
	.global _0833CF04
_0833CF04: .4byte 0x03001000
	.global _0833CF08
_0833CF08: .4byte 0x02039248
	.global _0833CF0C
_0833CF0C: .4byte 0x0203B864
