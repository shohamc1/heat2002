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
	.byte 0x00, 0x47, 0xC0, 0x46
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
