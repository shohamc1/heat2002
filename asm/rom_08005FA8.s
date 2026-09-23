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
	thumb_func_start sub_08005FA8
sub_08005FA8:
	push {r4, r5, lr}
	bl sub_080056F8
	ldr r0, _08006014 @ =0x08364B08
	ldr r4, [r0, #0x00]
	movs r0, #0x89
	lsls r0, r0, #0x03
	adds r5, r4, r0
	ldr r0, _08006018 @ =0x02025218
	ldrh r1, [r0, #0x00]
	ldr r0, _0800601C @ =0x020251FC
	ldrh r2, [r0, #0x00]
	ldr r0, _08006020 @ =0x020253CC
	ldrh r3, [r0, #0x00]
	adds r0, r5, #0x0
	bl sub_08005338
	movs r0, #0x91
	lsls r0, r0, #0x03
	adds r5, r4, r0
	ldr r0, _08006024 @ =0x0202F030
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08005FF6
	ldr r0, _08006028 @ =0x02025380
	ldr r1, _0800602C @ =0x020020CC
	ldrb r1, [r1, #0x00]
	lsls r3, r1, #0x01
	adds r0, r3, r0
	ldrh r1, [r0, #0x00]
	ldr r0, _08006030 @ =0x02025200
	adds r0, r3, r0
	ldrh r2, [r0, #0x00]
	ldr r0, _08006034 @ =0x020253A0
	adds r3, r3, r0
	ldrh r3, [r3, #0x00]
	adds r0, r5, #0x0
	bl sub_08005338
_08005FF6:
	ldr r0, _08006038 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08006044
	ldr r0, _0800603C @ =0x0202EF90
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _08006040 @ =0x0202A550
	adds r4, r0, r1
	b _08006046
	.byte 0x00, 0x00
_08006014: .4byte 0x08364B08
_08006018: .4byte 0x02025218
_0800601C: .4byte 0x020251FC
_08006020: .4byte 0x020253CC
_08006024: .4byte 0x0202F030
_08006028: .4byte 0x02025380
_0800602C: .4byte 0x020020CC
_08006030: .4byte 0x02025200
_08006034: .4byte 0x020253A0
_08006038: .4byte 0x020020DC
_0800603C: .4byte 0x0202EF90
_08006040: .4byte 0x0202A550
_08006044:
	ldr r4, _0800608C @ =0x0202A550
_08006046:
	ldr r0, [r4, #0x2C]
	negs r0, r0
	asrs r1, r0, #0x0D
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r1, r0, #0x01
	cmp r1, #0x00
	bge _0800605C
	movs r1, #0x00
_0800605C:
	adds r0, r1, #0x0
	bl sub_08005A2C
	adds r0, r4, #0x0
	adds r0, #0x9C
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	bl sub_08005AF0
	adds r0, r4, #0x0
	bl sub_08005E50
	adds r0, r4, #0x0
	bl sub_08005AA0
	adds r0, r4, #0x0
	bl sub_08005AEC
	adds r0, r4, #0x0
	bl sub_08004980
	pop {r4, r5}
	pop {r0}
	bx r0
_0800608C: .4byte 0x0202A550
