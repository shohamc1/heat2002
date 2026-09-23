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
	thumb_func_start sub_0833A8F4
sub_0833A8F4:
	push {lr}
	lsls r0, r0, #0x10
	ldr r2, _0833A920 @ =0x0200CA74
	ldr r1, _0833A924 @ =0x0200CAA4
	lsrs r0, r0, #0x0D
	adds r0, r0, r1
	ldrh r3, [r0, #0x04]
	lsls r1, r3, #0x01
	adds r1, r1, r3
	lsls r1, r1, #0x02
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldr r3, [r1, #0x00]
	ldr r2, [r0, #0x00]
	cmp r3, r2
	beq _0833A928
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	bl sub_0833AFC0
	b _0833A93C
	.byte 0x00, 0x00
_0833A920: .4byte 0x0200CA74
_0833A924: .4byte 0x0200CAA4
_0833A928:
	ldr r2, [r1, #0x04]
	ldrh r0, [r1, #0x04]
	cmp r0, #0x00
	beq _0833A934
	cmp r2, #0x00
	bge _0833A93C
_0833A934:
	adds r0, r1, #0x0
	adds r1, r3, #0x0
	bl sub_0833AFC0
_0833A93C:
	pop {r0}
	bx r0
	thumb_func_start sub_0833A940
sub_0833A940:
	push {lr}
	lsls r0, r0, #0x10
	ldr r2, _0833A96C @ =0x0200CA74
	ldr r1, _0833A970 @ =0x0200CAA4
	lsrs r0, r0, #0x0D
	adds r0, r0, r1
	ldrh r3, [r0, #0x04]
	lsls r1, r3, #0x01
	adds r1, r1, r3
	lsls r1, r1, #0x02
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldr r3, [r1, #0x00]
	ldr r2, [r0, #0x00]
	cmp r3, r2
	beq _0833A974
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	bl sub_0833AFC0
	b _0833A990
	.byte 0x00, 0x00
_0833A96C: .4byte 0x0200CA74
_0833A970: .4byte 0x0200CAA4
_0833A974:
	ldr r2, [r1, #0x04]
	ldrh r0, [r1, #0x04]
	cmp r0, #0x00
	bne _0833A986
	adds r0, r1, #0x0
	adds r1, r3, #0x0
	bl sub_0833AFC0
	b _0833A990
_0833A986:
	cmp r2, #0x00
	bge _0833A990
	adds r0, r1, #0x0
	bl sub_0833A7F4
_0833A990:
	pop {r0}
	bx r0
	thumb_func_start sub_0833A994
sub_0833A994:
	push {lr}
	lsls r0, r0, #0x10
	ldr r2, _0833A9C0 @ =0x0200CA74
	ldr r1, _0833A9C4 @ =0x0200CAA4
	lsrs r0, r0, #0x0D
	adds r0, r0, r1
	ldrh r3, [r0, #0x04]
	lsls r1, r3, #0x01
	adds r1, r1, r3
	lsls r1, r1, #0x02
	adds r1, r1, r2
	ldr r2, [r1, #0x00]
	ldr r1, [r2, #0x00]
	ldr r0, [r0, #0x00]
	cmp r1, r0
	bne _0833A9BA
	adds r0, r2, #0x0
	bl sub_0833B074
_0833A9BA:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0833A9C0: .4byte 0x0200CA74
_0833A9C4: .4byte 0x0200CAA4
	thumb_func_start sub_0833A9C8
sub_0833A9C8:
	push {lr}
	lsls r0, r0, #0x10
	ldr r2, _0833A9F4 @ =0x0200CA74
	ldr r1, _0833A9F8 @ =0x0200CAA4
	lsrs r0, r0, #0x0D
	adds r0, r0, r1
	ldrh r3, [r0, #0x04]
	lsls r1, r3, #0x01
	adds r1, r1, r3
	lsls r1, r1, #0x02
	adds r1, r1, r2
	ldr r2, [r1, #0x00]
	ldr r1, [r2, #0x00]
	ldr r0, [r0, #0x00]
	cmp r1, r0
	bne _0833A9EE
	adds r0, r2, #0x0
	bl sub_0833A7F4
_0833A9EE:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0833A9F4: .4byte 0x0200CA74
_0833A9F8: .4byte 0x0200CAA4
	thumb_func_start sub_0833A9FC
sub_0833A9FC:
	push {r4, r5, lr}
	ldr r0, _0833AA20 @ =0x00000004
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _0833AA1A
	ldr r5, _0833AA24 @ =0x0200CA74
	adds r4, r0, #0x0
_0833AA0C:
	ldr r0, [r5, #0x00]
	bl sub_0833B074
	adds r5, #0x0C
	subs r4, #0x01
	cmp r4, #0x00
	bne _0833AA0C
_0833AA1A:
	pop {r4, r5}
	pop {r0}
	bx r0
_0833AA20: .4byte 0x00000004
_0833AA24: .4byte 0x0200CA74
	thumb_func_start sub_0833AA28
sub_0833AA28:
	push {lr}
	bl sub_0833A7F4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start sub_0833AA34
sub_0833AA34:
	push {r4, r5, lr}
	ldr r0, _0833AA58 @ =0x00000004
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _0833AA52
	ldr r5, _0833AA5C @ =0x0200CA74
	adds r4, r0, #0x0
_0833AA44:
	ldr r0, [r5, #0x00]
	bl sub_0833A7F4
	adds r5, #0x0C
	subs r4, #0x01
	cmp r4, #0x00
	bne _0833AA44
_0833AA52:
	pop {r4, r5}
	pop {r0}
	bx r0
_0833AA58: .4byte 0x00000004
_0833AA5C: .4byte 0x0200CA74
