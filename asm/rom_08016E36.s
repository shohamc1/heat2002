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
	thumb_func_start sub_08016E38
sub_08016E38:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0x00
	cmp r0, #0x04
	bne _08016E54
	ldr r1, _08016E4C @ =0x0202F240
	ldr r0, _08016E50 @ =0x083393EC
	str r0, [r1, #0x00]
	b _08016E70
	.byte 0x00, 0x00
	.global _08016E4C
_08016E4C: .4byte 0x0202F240
	.global _08016E50
_08016E50: .4byte 0x083393EC
	.global _08016E54
_08016E54:
	cmp r0, #0x40
	bne _08016E68
	ldr r1, _08016E60 @ =0x0202F240
	ldr r0, _08016E64 @ =0x083393F8
	str r0, [r1, #0x00]
	b _08016E70
	.global _08016E60
_08016E60: .4byte 0x0202F240
	.global _08016E64
_08016E64: .4byte 0x083393F8
	.global _08016E68
_08016E68:
	ldr r1, _08016E74 @ =0x0202F240
	ldr r0, _08016E78 @ =0x083393EC
	str r0, [r1, #0x00]
	movs r2, #0x01
	.global _08016E70
_08016E70:
	adds r0, r2, #0x0
	bx lr
	.global _08016E74
_08016E74: .4byte 0x0202F240
	.global _08016E78
_08016E78: .4byte 0x083393EC
	.byte 0x06, 0x49, 0x08, 0x88, 0x00, 0x28, 0x08, 0xD0, 0x08, 0x88, 0x01, 0x38, 0x08, 0x80, 0x00, 0x04
	.byte 0x00, 0x28, 0x02, 0xD1, 0x02, 0x49, 0x01, 0x20, 0x08, 0x70, 0x70, 0x47, 0x96, 0x04, 0x00, 0x02
	.byte 0x98, 0x04, 0x00, 0x02
	thumb_func_start sub_08016EA0
sub_08016EA0:
	adds r2, r1, #0x0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x03
	bhi _08016ED4
	ldr r0, _08016EC4 @ =0x02000494
	strb r1, [r0, #0x00]
	ldr r1, _08016EC8 @ =0x0200049C
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	ldr r3, _08016ECC @ =0x04000100
	adds r0, r0, r3
	str r0, [r1, #0x00]
	ldr r0, _08016ED0 @ =0x08016E7D
	str r0, [r2, #0x00]
	movs r0, #0x00
	b _08016ED6
	.byte 0x00, 0x00
	.global _08016EC4
_08016EC4: .4byte 0x02000494
	.global _08016EC8
_08016EC8: .4byte 0x0200049C
	.global _08016ECC
_08016ECC: .4byte 0x04000100
	.global _08016ED0
_08016ED0: .4byte 0x08016E7D
	.global _08016ED4
_08016ED4:
	movs r0, #0x01
	.global _08016ED6
_08016ED6:
	bx lr
	thumb_func_start sub_08016ED8
sub_08016ED8:
	push {r4, r5, lr}
	ldr r2, _08016F20 @ =0x020004A0
	ldr r3, _08016F24 @ =0x04000208
	ldrh r1, [r3, #0x00]
	strh r1, [r2, #0x00]
	movs r5, #0x00
	strh r5, [r3, #0x00]
	ldr r4, _08016F28 @ =0x04000200
	ldr r1, _08016F2C @ =0x02000494
	ldrb r1, [r1, #0x00]
	movs r2, #0x08
	lsls r2, r1
	ldrh r1, [r4, #0x00]
	orrs r1, r2
	strh r1, [r4, #0x00]
	movs r1, #0x01
	strh r1, [r3, #0x00]
	ldr r1, _08016F30 @ =0x02000498
	strb r5, [r1, #0x00]
	ldr r2, _08016F34 @ =0x02000496
	ldrh r1, [r0, #0x00]
	strh r1, [r2, #0x00]
	adds r0, #0x02
	ldr r3, _08016F38 @ =0x0200049C
	ldr r1, [r3, #0x00]
	ldrh r2, [r0, #0x00]
	strh r2, [r1, #0x00]
	adds r1, #0x02
	str r1, [r3, #0x00]
	ldrh r0, [r0, #0x02]
	strh r0, [r1, #0x00]
	subs r1, #0x02
	str r1, [r3, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08016F20
_08016F20: .4byte 0x020004A0
	.global _08016F24
_08016F24: .4byte 0x04000208
	.global _08016F28
_08016F28: .4byte 0x04000200
	.global _08016F2C
_08016F2C: .4byte 0x02000494
	.global _08016F30
_08016F30: .4byte 0x02000498
	.global _08016F34
_08016F34: .4byte 0x02000496
	.global _08016F38
_08016F38: .4byte 0x0200049C
	thumb_func_start sub_08016F3C
sub_08016F3C:
	ldr r1, _08016F6C @ =0x0200049C
	ldr r0, [r1, #0x00]
	movs r2, #0x00
	strh r2, [r0, #0x00]
	adds r0, #0x02
	str r0, [r1, #0x00]
	strh r2, [r0, #0x00]
	subs r0, #0x02
	str r0, [r1, #0x00]
	ldr r3, _08016F70 @ =0x04000208
	strh r2, [r3, #0x00]
	ldr r2, _08016F74 @ =0x04000200
	ldr r0, _08016F78 @ =0x02000494
	ldrb r0, [r0, #0x00]
	movs r1, #0x08
	lsls r1, r0
	ldrh r0, [r2, #0x00]
	bics r0, r1
	strh r0, [r2, #0x00]
	ldr r0, _08016F7C @ =0x020004A0
	ldrh r0, [r0, #0x00]
	strh r0, [r3, #0x00]
	bx lr
	.byte 0x00, 0x00
	.global _08016F6C
_08016F6C: .4byte 0x0200049C
	.global _08016F70
_08016F70: .4byte 0x04000208
	.global _08016F74
_08016F74: .4byte 0x04000200
	.global _08016F78
_08016F78: .4byte 0x02000494
	.global _08016F7C
_08016F7C: .4byte 0x020004A0
	thumb_func_start sub_08016F80
sub_08016F80:
	push {r4, r5, r6, lr}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r4, _08016FE0 @ =0x04000208
	ldrh r3, [r4, #0x00]
	adds r6, r3, #0x0
	movs r3, #0x00
	strh r3, [r4, #0x00]
	ldr r5, _08016FE4 @ =0x04000204
	ldrh r4, [r5, #0x00]
	ldr r3, _08016FE8 @ =0x0000F8FF
	ands r4, r3
	ldr r3, _08016FEC @ =0x0202F240
	ldr r3, [r3, #0x00]
	ldrh r3, [r3, #0x06]
	orrs r3, r4
	strh r3, [r5, #0x00]
	ldr r3, _08016FF0 @ =0x040000D4
	str r0, [r3, #0x00]
	ldr r0, _08016FF4 @ =0x040000D8
	str r1, [r0, #0x00]
	ldr r1, _08016FF8 @ =0x040000DC
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r2, r0
	str r2, [r1, #0x00]
	adds r1, #0x02
	movs r2, #0x80
	lsls r2, r2, #0x08
	adds r0, r2, #0x0
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08016FD4
	ldr r2, _08016FFC @ =0x040000DE
	movs r0, #0x80
	lsls r0, r0, #0x08
	adds r1, r0, #0x0
	.global _08016FCC
_08016FCC:
	ldrh r0, [r2, #0x00]
	ands r0, r1
	cmp r0, #0x00
	bne _08016FCC
	.global _08016FD4
_08016FD4:
	ldr r0, _08016FE0 @ =0x04000208
	strh r6, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08016FE0
_08016FE0: .4byte 0x04000208
	.global _08016FE4
_08016FE4: .4byte 0x04000204
	.global _08016FE8
_08016FE8: .4byte 0x0000F8FF
	.global _08016FEC
_08016FEC: .4byte 0x0202F240
	.global _08016FF0
_08016FF0: .4byte 0x040000D4
	.global _08016FF4
_08016FF4: .4byte 0x040000D8
	.global _08016FF8
_08016FF8: .4byte 0x040000DC
	.global _08016FFC
_08016FFC: .4byte 0x040000DE
	thumb_func_start sub_08017000
sub_08017000:
	push {r4, r5, r6, lr}
	add sp, #-0x088
	adds r5, r1, #0x0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, _08017018 @ =0x0202F240
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x04]
	cmp r3, r0
	bcc _08017020
	ldr r0, _0801701C @ =0x000080FF
	b _080170AA
	.global _08017018
_08017018: .4byte 0x0202F240
	.global _0801701C
_0801701C: .4byte 0x000080FF
	.global _08017020
_08017020:
	ldr r0, _080170B4 @ =0x0202F240
	adds r6, r0, #0x0
	ldr r0, [r0, #0x00]
	ldrb r1, [r0, #0x08]
	lsls r0, r1, #0x01
	mov r4, sp
	adds r2, r0, r4
	adds r2, #0x02
	movs r4, #0x00
	cmp r4, r1
	bcs _0801704A
	.global _08017036
_08017036:
	strh r3, [r2, #0x00]
	subs r2, #0x02
	lsrs r3, r3, #0x01
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, [r6, #0x00]
	ldrb r0, [r0, #0x08]
	cmp r4, r0
	bcc _08017036
	.global _0801704A
_0801704A:
	movs r0, #0x01
	strh r0, [r2, #0x00]
	subs r2, #0x02
	strh r0, [r2, #0x00]
	movs r4, #0xD0
	lsls r4, r4, #0x14
	ldr r0, _080170B4 @ =0x0202F240
	ldr r0, [r0, #0x00]
	ldrb r0, [r0, #0x08]
	lsls r2, r0, #0x10
	movs r0, #0xC0
	lsls r0, r0, #0x0A
	adds r2, r2, r0
	lsrs r2, r2, #0x10
	mov r0, sp
	adds r1, r4, #0x0
	bl sub_08016F80
	adds r0, r4, #0x0
	mov r1, sp
	movs r2, #0x44
	bl sub_08016F80
	add r2, sp, #0x008
	adds r5, #0x06
	movs r4, #0x00
	movs r6, #0x01
	.global _08017080
_08017080:
	movs r1, #0x00
	movs r3, #0x00
	.global _08017084
_08017084:
	lsls r1, r1, #0x11
	ldrh r0, [r2, #0x00]
	ands r0, r6
	lsrs r1, r1, #0x10
	orrs r1, r0
	adds r2, #0x02
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x0F
	bls _08017084
	strh r1, [r5, #0x00]
	subs r5, #0x02
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x03
	bls _08017080
	movs r0, #0x00
	.global _080170AA
_080170AA:
	add sp, #0x088
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _080170B4
_080170B4: .4byte 0x0202F240
	thumb_func_start sub_080170B8
sub_080170B8:
	push {r4, r5, lr}
	add sp, #-0x0A4
	adds r5, r1, #0x0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _080170D0 @ =0x0202F240
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x04]
	cmp r4, r0
	bcc _080170D8
	ldr r0, _080170D4 @ =0x000080FF
	b _08017184
	.global _080170D0
_080170D0: .4byte 0x0202F240
	.global _080170D4
_080170D4: .4byte 0x000080FF
	.global _080170D8
_080170D8:
	ldr r0, _08017118 @ =0x0202F240
	ldr r0, [r0, #0x00]
	ldrb r0, [r0, #0x08]
	lsls r0, r0, #0x01
	mov r1, sp
	adds r3, r0, r1
	adds r3, #0x84
	movs r0, #0x00
	strh r0, [r3, #0x00]
	subs r3, #0x02
	movs r1, #0x00
	.global _080170EE
_080170EE:
	ldrh r2, [r5, #0x00]
	adds r5, #0x02
	movs r0, #0x00
	.global _080170F4
_080170F4:
	strh r2, [r3, #0x00]
	subs r3, #0x02
	lsrs r2, r2, #0x01
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x0F
	bls _080170F4
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x03
	bls _080170EE
	movs r1, #0x00
	ldr r0, _08017118 @ =0x0202F240
	adds r2, r0, #0x0
	ldr r0, [r0, #0x00]
	b _0801712A
	.global _08017118
_08017118: .4byte 0x0202F240
	.global _0801711C
_0801711C:
	strh r4, [r3, #0x00]
	subs r3, #0x02
	lsrs r4, r4, #0x01
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r0, [r2, #0x00]
	.global _0801712A
_0801712A:
	ldrb r0, [r0, #0x08]
	cmp r1, r0
	bcc _0801711C
	movs r0, #0x00
	strh r0, [r3, #0x00]
	subs r3, #0x02
	movs r0, #0x01
	strh r0, [r3, #0x00]
	movs r1, #0xD0
	lsls r1, r1, #0x14
	ldr r0, _0801718C @ =0x0202F240
	ldr r0, [r0, #0x00]
	ldrb r0, [r0, #0x08]
	lsls r2, r0, #0x10
	movs r0, #0x86
	lsls r0, r0, #0x0F
	adds r2, r2, r0
	lsrs r2, r2, #0x10
	mov r0, sp
	bl sub_08016F80
	ldr r0, _08017190 @ =0x08339404
	bl sub_08016ED8
	movs r4, #0x00
	movs r1, #0xD0
	lsls r1, r1, #0x14
	movs r3, #0x01
	ldr r2, _08017194 @ =0x02000498
	.global _08017164
_08017164:
	ldrh r0, [r1, #0x00]
	ands r0, r3
	cmp r0, #0x00
	bne _0801717E
	ldrb r0, [r2, #0x00]
	cmp r0, #0x00
	beq _08017164
	ldrh r0, [r1, #0x00]
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _0801717E
	ldr r4, _08017198 @ =0x0000C001
	.global _0801717E
_0801717E:
	bl sub_08016F3C
	adds r0, r4, #0x0
	.global _08017184
_08017184:
	add sp, #0x0A4
	pop {r4, r5}
	pop {r1}
	bx r1
	.global _0801718C
_0801718C: .4byte 0x0202F240
	.global _08017190
_08017190: .4byte 0x08339404
	.global _08017194
_08017194: .4byte 0x02000498
	.global _08017198
_08017198: .4byte 0x0000C001
	thumb_func_start sub_0801719C
sub_0801719C:
	push {r4, r5, lr}
	add sp, #-0x008
	adds r4, r1, #0x0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r5, #0x00
	ldr r0, _080171B8 @ =0x0202F240
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x04]
	cmp r1, r0
	bcc _080171C0
	ldr r0, _080171BC @ =0x000080FF
	b _080171EA
	.byte 0x00, 0x00
	.global _080171B8
_080171B8: .4byte 0x0202F240
	.global _080171BC
_080171BC: .4byte 0x000080FF
	.global _080171C0
_080171C0:
	adds r0, r1, #0x0
	mov r1, sp
	bl sub_08017000
	mov r2, sp
	movs r3, #0x00
	b _080171D8
	.global _080171CE
_080171CE:
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x03
	bhi _080171E8
	.global _080171D8
_080171D8:
	ldrh r1, [r4, #0x00]
	ldrh r0, [r2, #0x00]
	adds r2, #0x02
	adds r4, #0x02
	cmp r1, r0
	beq _080171CE
	movs r5, #0x80
	lsls r5, r5, #0x08
	.global _080171E8
_080171E8:
	adds r0, r5, #0x0
	.global _080171EA
_080171EA:
	add sp, #0x008
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x00, 0x47, 0xC0, 0x46
	.global _080171F8
_080171F8:
	.byte 0x08, 0x47, 0xC0, 0x46, 0x10, 0x47, 0xC0, 0x46
	.global _08017200
_08017200:
	.byte 0x18, 0x47, 0xC0, 0x46, 0x20, 0x47, 0xC0, 0x46, 0x28, 0x47, 0xC0, 0x46, 0x30, 0x47, 0xC0, 0x46
	.byte 0x38, 0x47, 0xC0, 0x46
	.global _08017214
_08017214:
	.byte 0x40, 0x47, 0xC0, 0x46, 0x48, 0x47, 0xC0, 0x46, 0x50, 0x47, 0xC0, 0x46, 0x58, 0x47, 0xC0, 0x46
	.byte 0x60, 0x47, 0xC0, 0x46, 0x68, 0x47, 0xC0, 0x46, 0x70, 0x47, 0xC0, 0x46
	thumb_func_start sub_08017230
sub_08017230:
	cmp r1, #0x00
	beq _080172B8
	push {r4}
	adds r4, r0, #0x0
	eors r4, r1
	mov r12, r4
	movs r3, #0x01
	movs r2, #0x00
	cmp r1, #0x00
	bpl _08017246
	negs r1, r1
	.global _08017246
_08017246:
	cmp r0, #0x00
	bpl _0801724C
	negs r0, r0
	.global _0801724C
_0801724C:
	cmp r0, r1
	bcc _080172AA
	movs r4, #0x01
	lsls r4, r4, #0x1C
	.global _08017254
_08017254:
	cmp r1, r4
	bcs _08017262
	cmp r1, r0
	bcs _08017262
	lsls r1, r1, #0x04
	lsls r3, r3, #0x04
	b _08017254
	.global _08017262
_08017262:
	lsls r4, r4, #0x03
	.global _08017264
_08017264:
	cmp r1, r4
	bcs _08017272
	cmp r1, r0
	bcs _08017272
	lsls r1, r1, #0x01
	lsls r3, r3, #0x01
	b _08017264
	.global _08017272
_08017272:
	cmp r0, r1
	bcc _0801727A
	subs r0, r0, r1
	orrs r2, r3
	.global _0801727A
_0801727A:
	lsrs r4, r1, #0x01
	cmp r0, r4
	bcc _08017286
	subs r0, r0, r4
	lsrs r4, r3, #0x01
	orrs r2, r4
	.global _08017286
_08017286:
	lsrs r4, r1, #0x02
	cmp r0, r4
	bcc _08017292
	subs r0, r0, r4
	lsrs r4, r3, #0x02
	orrs r2, r4
	.global _08017292
_08017292:
	lsrs r4, r1, #0x03
	cmp r0, r4
	bcc _0801729E
	subs r0, r0, r4
	lsrs r4, r3, #0x03
	orrs r2, r4
	.global _0801729E
_0801729E:
	cmp r0, #0x00
	beq _080172AA
	lsrs r3, r3, #0x04
	beq _080172AA
	lsrs r1, r1, #0x04
	b _08017272
	.global _080172AA
_080172AA:
	adds r0, r2, #0x0
	mov r4, r12
	cmp r4, #0x00
	bpl _080172B4
	negs r0, r0
	.global _080172B4
_080172B4:
	pop {r4}
	mov pc, lr
	.global _080172B8
_080172B8:
	push {lr}
	bl sub_080172C4
	movs r0, #0x00
	pop {pc}
	.byte 0x00, 0x00
