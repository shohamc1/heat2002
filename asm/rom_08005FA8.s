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
	thumb_func_start sub_08006090
sub_08006090:
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_08006094
sub_08006094:
	push {r4, r5, r6, lr}
	ldr r0, _080060B4 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080060C0
	ldr r0, _080060B8 @ =0x0202EF90
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x04
	ldr r1, _080060BC @ =0x0202A550
	adds r5, r0, r1
	b _080060C2
	.byte 0x00, 0x00
_080060B4: .4byte 0x020020DC
_080060B8: .4byte 0x0202EF90
_080060BC: .4byte 0x0202A550
_080060C0:
	ldr r5, _0800617C @ =0x0202A550
_080060C2:
	bl sub_080056F8
	ldr r6, _08006180 @ =0x08364B08
	ldr r0, [r6, #0x00]
	ldr r1, _08006184 @ =0x000004C6
	adds r4, r0, r1
	ldr r0, _08006188 @ =0x02025218
	ldrh r1, [r0, #0x00]
	ldr r0, _0800618C @ =0x020251FC
	ldrh r2, [r0, #0x00]
	ldr r0, _08006190 @ =0x020253CC
	ldrh r3, [r0, #0x00]
	adds r0, r4, #0x0
	bl sub_08005338
	ldr r0, _08006194 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0E
	beq _080060EC
	cmp r0, #0x02
	bne _08006118
_080060EC:
	ldr r0, [r6, #0x00]
	ldr r1, _08006198 @ =0x00000486
	adds r4, r0, r1
	ldr r0, _0800619C @ =0x0202F030
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08006118
	ldr r0, _080061A0 @ =0x02025380
	ldr r1, _080061A4 @ =0x020020CC
	ldrb r1, [r1, #0x00]
	lsls r3, r1, #0x01
	adds r0, r3, r0
	ldrh r1, [r0, #0x00]
	ldr r0, _080061A8 @ =0x02025200
	adds r0, r3, r0
	ldrh r2, [r0, #0x00]
	ldr r0, _080061AC @ =0x020253A0
	adds r3, r3, r0
	ldrh r3, [r3, #0x00]
	adds r0, r4, #0x0
	bl sub_08005338
_08006118:
	ldr r0, [r5, #0x2C]
	negs r0, r0
	asrs r1, r0, #0x0D
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r1, r0, #0x01
	cmp r1, #0x00
	bge _0800612E
	movs r1, #0x00
_0800612E:
	adds r0, r1, #0x0
	bl sub_08005A2C
	ldr r4, _08006194 @ =0x0200215C
	ldrb r0, [r4, #0x00]
	cmp r0, #0x02
	beq _080061DC
	cmp r0, #0x0E
	beq _080061DC
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	adds r0, #0x01
	bl sub_08005C18
	movs r1, #0xC7
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08006166
	ldrb r0, [r4, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _080061B4
_08006166:
	adds r0, r5, #0x0
	adds r0, #0x4C
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x01
	ldr r1, _080061B0 @ =0x02002184
	ldrb r1, [r1, #0x00]
	bl sub_08005D00
	b _080061BE
_0800617C: .4byte 0x0202A550
_08006180: .4byte 0x08364B08
_08006184: .4byte 0x000004C6
_08006188: .4byte 0x02025218
_0800618C: .4byte 0x020251FC
_08006190: .4byte 0x020253CC
_08006194: .4byte 0x0200215C
_08006198: .4byte 0x00000486
_0800619C: .4byte 0x0202F030
_080061A0: .4byte 0x02025380
_080061A4: .4byte 0x020020CC
_080061A8: .4byte 0x02025200
_080061AC: .4byte 0x020253A0
_080061B0: .4byte 0x02002184
_080061B4:
	ldr r0, _080061E8 @ =0x000003E7
	ldr r1, _080061EC @ =0x02002184
	ldrb r1, [r1, #0x00]
	bl sub_08005D00
_080061BE:
	adds r0, r5, #0x0
	adds r0, #0x9C
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	bl sub_08005AF0
	adds r0, r5, #0x0
	bl sub_08005E50
	adds r0, r5, #0x0
	bl sub_08005AA0
	adds r0, r5, #0x0
	bl sub_08005AEC
_080061DC:
	adds r0, r5, #0x0
	bl sub_08004980
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080061E8: .4byte 0x000003E7
_080061EC: .4byte 0x02002184
