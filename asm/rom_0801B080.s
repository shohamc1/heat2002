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
	.byte 0x30, 0xB5, 0x83, 0xB0, 0x15, 0x4C, 0x00, 0x94, 0x03, 0x23, 0x02, 0x93, 0x00, 0x20, 0x01, 0x90
	.byte 0x01, 0x25, 0x28, 0x1C, 0x69, 0x46, 0xAB, 0xDF, 0x02, 0x1C, 0x11, 0x4D, 0x2A, 0x60, 0x00, 0x94
	.byte 0x02, 0x93, 0x04, 0x20, 0x01, 0x90, 0x0F, 0x4B, 0x01, 0x24, 0x20, 0x1C, 0x69, 0x46, 0xAB, 0xDF
	.byte 0x02, 0x1C, 0x0D, 0x48, 0x02, 0x60, 0x1A, 0x60, 0x0C, 0x4A, 0x11, 0x1C, 0x02, 0x3C, 0x10, 0x1C
	.byte 0x98, 0x30, 0x04, 0x60, 0x08, 0x38, 0x88, 0x42, 0xFB, 0xDA, 0x00, 0x20, 0x29, 0x68, 0x11, 0x60
	.byte 0x50, 0x60, 0x19, 0x68, 0x91, 0x60, 0xD0, 0x60, 0x03, 0xB0, 0x30, 0xBD, 0x58, 0x96, 0x33, 0x08
	.byte 0xAC, 0x04, 0x00, 0x02, 0xB0, 0x04, 0x00, 0x02, 0xB4, 0x04, 0x00, 0x02, 0xB8, 0x04, 0x00, 0x02
	thumb_func_start sub_0801B0F0
sub_0801B0F0:
	push {r4, lr}
	movs r3, #0x13
	movs r4, #0x00
	adds r0, r3, #0x0
	adds r1, r4, #0x0
	swi #171
	adds r2, r0, #0x0
	adds r0, r2, #0x0
	pop {r4, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_0801B104
sub_0801B104:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	bl sub_0801B52C
	adds r4, r0, #0x0
	bl sub_0801B0F0
	str r0, [r4, #0x00]
	adds r0, r5, #0x0
	pop {r4, r5, pc}
	thumb_func_start sub_0801B118
sub_0801B118:
	push {lr}
	adds r1, r0, #0x0
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	beq _0801B128
	adds r0, r1, #0x0
	b _0801B12E
	.global _0801B128
_0801B128:
	adds r0, r1, #0x0
	bl sub_0801B104
	.global _0801B12E
_0801B12E:
	pop {pc}
	thumb_func_start sub_0801B130
sub_0801B130:
	push {r4, r5, lr}
	add sp, #-0x00C
	adds r4, r1, #0x0
	adds r5, r2, #0x0
	bl sub_0801B034
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r3, #0x06
	adds r0, r3, #0x0
	mov r1, sp
	swi #171
	adds r2, r0, #0x0
	adds r0, r2, #0x0
	add sp, #0x00C
	pop {r4, r5, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_0801B154
sub_0801B154:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	adds r7, r2, #0x0
	bl sub_0801B034
	bl sub_0801B014
	adds r6, r0, #0x0
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r7, #0x0
	bl sub_0801B130
	cmp r0, #0x00
	bge _0801B17E
	movs r0, #0x01
	negs r0, r0
	bl sub_0801B104
	b _0801B194
	.global _0801B17E
_0801B17E:
	subs r2, r7, r0
	cmp r6, #0x14
	beq _0801B192
	ldr r0, _0801B198 @ =0x020004B8
	lsls r1, r6, #0x03
	adds r0, #0x04
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _0801B192
_0801B192:
	adds r0, r2, #0x0
	.global _0801B194
_0801B194:
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00
	.global _0801B198
_0801B198: .4byte 0x020004B8
	thumb_func_start sub_0801B19C
sub_0801B19C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	mov r8, r0
	adds r5, r1, #0x0
	adds r4, r2, #0x0
	bl sub_0801B034
	adds r7, r0, #0x0
	bl sub_0801B014
	adds r6, r0, #0x0
	cmp r4, #0x01
	bne _0801B1D2
	cmp r6, #0x14
	bne _0801B1C4
	movs r0, #0x01
	negs r0, r0
	b _0801B214
	.global _0801B1C4
_0801B1C4:
	ldr r0, _0801B21C @ =0x020004B8
	lsls r1, r6, #0x03
	adds r0, #0x04
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	adds r5, r5, r0
	movs r4, #0x00
	.global _0801B1D2
_0801B1D2:
	cmp r4, #0x02
	bne _0801B1E4
	str r7, [sp, #0x000]
	movs r3, #0x0C
	adds r0, r3, #0x0
	mov r1, sp
	swi #171
	adds r2, r0, #0x0
	adds r5, r5, r2
	.global _0801B1E4
_0801B1E4:
	mov r0, r8
	bl sub_0801B034
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r3, #0x0A
	adds r0, r3, #0x0
	mov r1, sp
	swi #171
	adds r2, r0, #0x0
	cmp r6, #0x14
	beq _0801B20A
	cmp r2, #0x00
	bne _0801B20A
	ldr r0, _0801B21C @ =0x020004B8
	lsls r1, r6, #0x03
	adds r0, #0x04
	adds r1, r1, r0
	str r5, [r1, #0x00]
	.global _0801B20A
_0801B20A:
	movs r0, #0x01
	negs r0, r0
	cmp r2, #0x00
	bne _0801B214
	adds r0, r5, #0x0
	.global _0801B214
_0801B214:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.global _0801B21C
_0801B21C: .4byte 0x020004B8
	thumb_func_start sub_0801B220
sub_0801B220:
	push {lr}
	bl sub_0801B19C
	bl sub_0801B118
	pop {pc}
	thumb_func_start sub_0801B22C
sub_0801B22C:
	push {r4, r5, lr}
	add sp, #-0x00C
	adds r4, r1, #0x0
	adds r5, r2, #0x0
	bl sub_0801B034
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r3, #0x05
	adds r0, r3, #0x0
	mov r1, sp
	swi #171
	adds r2, r0, #0x0
	adds r0, r2, #0x0
	add sp, #0x00C
	pop {r4, r5, pc}
	.byte 0x00, 0x00
	thumb_func_start sub_0801B250
sub_0801B250:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	bl sub_0801B034
	bl sub_0801B014
	adds r7, r0, #0x0
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl sub_0801B22C
	movs r1, #0x01
	negs r1, r1
	cmp r0, r1
	beq _0801B278
	cmp r0, r6
	bne _0801B280
	.global _0801B278
_0801B278:
	adds r0, r1, #0x0
	bl sub_0801B104
	b _0801B296
	.global _0801B280
_0801B280:
	subs r2, r6, r0
	cmp r7, #0x14
	beq _0801B294
	ldr r0, _0801B298 @ =0x020004B8
	lsls r1, r7, #0x03
	adds r0, #0x04
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	.global _0801B294
_0801B294:
	adds r0, r2, #0x0
	.global _0801B296
_0801B296:
	pop {r4, r5, r6, r7, pc}
	.global _0801B298
_0801B298: .4byte 0x020004B8
	thumb_func_start sub_0801B29C
sub_0801B29C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x00C
	adds r7, r0, #0x0
	adds r4, r1, #0x0
	movs r5, #0x00
	movs r6, #0x01
	negs r6, r6
	adds r0, r6, #0x0
	bl sub_0801B014
	mov r8, r0
	cmp r0, #0x14
	bne _0801B2BE
	adds r0, r6, #0x0
	b _0801B332
	.global _0801B2BE
_0801B2BE:
	movs r0, #0x02
	ands r0, r4
	cmp r0, #0x00
	beq _0801B2C8
	movs r5, #0x02
	.global _0801B2C8
_0801B2C8:
	movs r0, #0x80
	lsls r0, r0, #0x02
	ands r0, r4
	cmp r0, #0x00
	beq _0801B2D6
	movs r0, #0x04
	orrs r5, r0
	.global _0801B2D6
_0801B2D6:
	movs r0, #0x80
	lsls r0, r0, #0x03
	ands r0, r4
	cmp r0, #0x00
	beq _0801B2E4
	movs r0, #0x04
	orrs r5, r0
	.global _0801B2E4
_0801B2E4:
	movs r1, #0x08
	ands r4, r1
	cmp r4, #0x00
	beq _0801B2F4
	movs r0, #0x05
	negs r0, r0
	ands r5, r0
	orrs r5, r1
	.global _0801B2F4
_0801B2F4:
	str r7, [sp, #0x000]
	adds r0, r7, #0x0
	bl sub_0801AFD0
	str r0, [sp, #0x008]
	str r5, [sp, #0x004]
	movs r2, #0x01
	adds r0, r2, #0x0
	mov r1, sp
	swi #171
	adds r3, r0, #0x0
	cmp r3, #0x00
	blt _0801B32C
	ldr r0, _0801B328 @ =0x020004B8
	mov r1, r8
	lsls r2, r1, #0x03
	adds r1, r2, r0
	str r3, [r1, #0x00]
	adds r0, #0x04
	adds r2, r2, r0
	movs r0, #0x00
	str r0, [r2, #0x00]
	adds r0, r3, #0x0
	adds r0, #0x20
	b _0801B332
	.byte 0x00, 0x00
	.global _0801B328
_0801B328: .4byte 0x020004B8
	.global _0801B32C
_0801B32C:
	adds r0, r3, #0x0
	bl sub_0801B104
	.global _0801B332
_0801B332:
	add sp, #0x00C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.byte 0x00, 0x00, 0x0E, 0xB4, 0x00, 0xB5, 0x01, 0x99, 0xFF, 0xF7, 0xAB, 0xFF, 0xFF, 0xF7, 0xE7, 0xFE
	.byte 0x08, 0xBC, 0x03, 0xB0, 0x18, 0x47
	thumb_func_start sub_0801B350
sub_0801B350:
	push {lr}
	add sp, #-0x004
	bl sub_0801B034
	str r0, [sp, #0x000]
	bl sub_0801B014
	adds r1, r0, #0x0
	cmp r1, #0x14
	beq _0801B370
	ldr r0, _0801B380 @ =0x020004B8
	lsls r1, r1, #0x03
	adds r1, r1, r0
	movs r0, #0x01
	negs r0, r0
	str r0, [r1, #0x00]
	.global _0801B370
_0801B370:
	movs r3, #0x02
	adds r0, r3, #0x0
	mov r1, sp
	swi #171
	adds r2, r0, #0x0
	adds r0, r2, #0x0
	add sp, #0x004
	pop {pc}
	.global _0801B380
_0801B380: .4byte 0x020004B8
	thumb_func_start sub_0801B384
sub_0801B384:
	push {lr}
	bl sub_0801B350
	bl sub_0801B118
	pop {pc}
	.byte 0x9C, 0x46, 0x43, 0x46, 0x08, 0xB4, 0x63, 0x46, 0x18, 0x22, 0x04, 0x4B, 0x10, 0x1C, 0x19, 0x1C
	.byte 0xAB, 0xDF, 0x80, 0x46, 0x08, 0xBC, 0x98, 0x46, 0x70, 0x47, 0x00, 0x00, 0x26, 0x00, 0x02, 0x00
	.byte 0x9C, 0x46, 0x43, 0x46, 0x08, 0xB4, 0x63, 0x46, 0x18, 0x22, 0x04, 0x4B, 0x10, 0x1C, 0x19, 0x1C
	.byte 0xAB, 0xDF, 0x80, 0x46, 0x08, 0xBC, 0x98, 0x46, 0x70, 0x47, 0x00, 0x00, 0x26, 0x00, 0x02, 0x00
	.byte 0x01, 0x20, 0x70, 0x47
	thumb_func_start sub_0801B3D4
sub_0801B3D4:
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldr r4, _0801B404 @ =0x020004A8
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	bne _0801B3E4
	ldr r0, _0801B408 @ =0x0202F248
	str r0, [r4, #0x00]
	.global _0801B3E4
_0801B3E4:
	ldr r5, [r4, #0x00]
	adds r0, r5, r6
	cmp r0, sp
	bls _0801B3FA
	ldr r1, _0801B40C @ =0x0833965C
	movs r0, #0x01
	movs r2, #0x20
	bl sub_0801B250
	bl sub_0801B564
	.global _0801B3FA
_0801B3FA:
	ldr r0, [r4, #0x00]
	adds r0, r0, r6
	str r0, [r4, #0x00]
	adds r0, r5, #0x0
	pop {r4, r5, r6, pc}
	.global _0801B404
_0801B404: .4byte 0x020004A8
	.global _0801B408
_0801B408: .4byte 0x0202F248
	.global _0801B40C
_0801B40C: .4byte 0x0833965C
