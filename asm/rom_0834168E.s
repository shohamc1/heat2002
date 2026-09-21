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
	.byte 0x10, 0xB5, 0x14, 0x1C, 0x0D, 0x4B, 0x1A, 0x68, 0x80, 0x1A, 0x5A, 0x68, 0x89, 0x1A
	.byte 0x42, 0x1A, 0x52, 0x00, 0x40, 0x18, 0xF1, 0x21, 0x09, 0x04, 0x52, 0x18, 0xA1, 0x21, 0x09, 0x04
	.byte 0x43, 0x18, 0x52, 0x14, 0x5B, 0x14, 0x11, 0x1C, 0x10, 0x31, 0x88, 0x20, 0x40, 0x00, 0x81, 0x42
	.byte 0x03, 0xD8, 0x18, 0x1C, 0x20, 0x30, 0xC0, 0x28, 0x03, 0xD9, 0x00, 0x20, 0x03, 0xE0, 0x10, 0x91
	.byte 0x03, 0x02, 0x22, 0x60, 0x63, 0x60, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	thumb_func_start sub_083416DC
sub_083416DC:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r6, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r10, r1
	ldr r0, [r6, #0x00]
	ldr r1, [r6, #0x08]
	mov r2, sp
	bl sub_08341644
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08341702
	b _083419BA
	.global _08341702
_08341702:
	ldr r1, [sp, #0x004]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	ldr r0, [sp, #0x000]
	subs r0, #0x18
	str r0, [sp, #0x000]
	subs r1, #0x10
	str r1, [sp, #0x004]
	adds r0, r6, #0x0
	adds r0, #0x7D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341734
	ldr r0, _08341784 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341734
	ldr r0, _08341788 @ =0x020390AC
	ldr r0, [r0, #0x00]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _08341734
	b _083419BA
	.global _08341734
_08341734:
	ldrh r1, [r6, #0x34]
	movs r2, #0x80
	lsls r2, r2, #0x02
	adds r0, r1, r2
	asrs r4, r0, #0x0A
	adds r4, #0x28
	movs r0, #0x3F
	ands r4, r0
	movs r1, #0x20
	adds r0, r4, #0x0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r0, #0x1F
	ands r4, r0
	cmp r7, #0x00
	beq _0834175A
	movs r0, #0x20
	subs r4, r0, r4
	.global _0834175A
_0834175A:
	ldr r1, _0834178C @ =0x02026E1C
	movs r3, #0xB1
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl sub_0833FD78
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x0C
	movs r1, #0xB9
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08341790
	movs r0, #0x80
	lsls r0, r0, #0x04
	b _08341794
	.global _08341784
_08341784: .4byte 0x020390EC
	.global _08341788
_08341788: .4byte 0x020390AC
	.global _0834178C
_0834178C: .4byte 0x02026E1C
	.global _08341790
_08341790:
	movs r0, #0x80
	lsls r0, r0, #0x03
	.global _08341794
_08341794:
	orrs r5, r0
	cmp r7, #0x00
	bne _08341830
	ldr r1, _08341820 @ =0x02026E14
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r7, r6, r2
	ldrb r3, [r7, #0x00]
	lsls r0, r3, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	lsls r4, r4, #0x02
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	bl sub_0833FC48
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _083417DE
	ldr r0, [sp, #0x004]
	movs r1, #0xFF
	ands r0, r1
	ldr r1, [sp, #0x000]
	ldr r2, _08341824 @ =0x000001FF
	ands r1, r2
	lsls r1, r1, #0x10
	orrs r0, r1
	ldr r1, _08341828 @ =0x80008000
	orrs r0, r1
	ldr r1, [r3, #0x10]
	orrs r1, r5
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl sub_0833D6D8
	.global _083417DE
_083417DE:
	ldr r1, _0834182C @ =0x02026E18
	ldrb r7, [r7, #0x00]
	lsls r0, r7, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	bl sub_0833FBB0
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _083418C8
	ldr r0, [sp, #0x004]
	movs r1, #0xFF
	ands r0, r1
	ldr r1, [sp, #0x000]
	adds r1, #0x10
	ldr r2, _08341824 @ =0x000001FF
	ands r1, r2
	lsls r1, r1, #0x10
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	ldr r1, [r3, #0x10]
	orrs r1, r5
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl sub_0833D6D8
	b _083418C8
	.global _08341820
_08341820: .4byte 0x02026E14
	.global _08341824
_08341824: .4byte 0x000001FF
	.global _08341828
_08341828: .4byte 0x80008000
	.global _0834182C
_0834182C: .4byte 0x02026E18
	.global _08341830
_08341830:
	ldr r1, _0834193C @ =0x02026E18
	movs r0, #0xB1
	lsls r0, r0, #0x01
	adds r0, r0, r6
	mov r8, r0
	ldrb r2, [r0, #0x00]
	lsls r0, r2, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	lsls r7, r4, #0x02
	adds r0, r7, r0
	ldr r0, [r0, #0x00]
	bl sub_0833FBB0
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _08341880
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	ldr r1, _08341940 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r4, r0
	ldr r1, [r3, #0x10]
	orrs r1, r5
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r4, r0
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	bl sub_0833D6D8
	.global _08341880
_08341880:
	ldr r1, _08341944 @ =0x02026E14
	mov r3, r8
	ldrb r3, [r3, #0x00]
	lsls r0, r3, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	adds r0, r7, r0
	ldr r0, [r0, #0x00]
	bl sub_0833FC48
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _083418C8
	ldr r4, [sp, #0x004]
	movs r0, #0xFF
	ands r4, r0
	ldr r0, [sp, #0x000]
	adds r0, #0x20
	ldr r1, _08341940 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	ldr r0, _08341948 @ =0x80008000
	orrs r4, r0
	ldr r1, [r3, #0x10]
	orrs r1, r5
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r4, r0
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	bl sub_0833D6D8
	.global _083418C8
_083418C8:
	ldr r0, _0834194C @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0834195C
	ldr r1, _08341950 @ =0x0202772C
	mov r2, r10
	lsls r0, r2, #0x02
	adds r0, r0, r1
	ldr r5, [r0, #0x00]
	ldr r0, _08341954 @ =0x020390AC
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x01
	movs r1, #0x07
	bl sub_08344C50
	lsls r0, r0, #0x02
	adds r5, r5, r0
	ldr r1, [sp, #0x004]
	subs r1, #0x0C
	str r1, [sp, #0x004]
	ldr r0, [sp, #0x000]
	adds r0, #0x10
	str r0, [sp, #0x000]
	movs r4, #0xFF
	ands r4, r1
	ldr r1, _08341940 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r4, r0
	ldr r0, [r5, #0x00]
	bl sub_0833FC94
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _083419BA
	ldr r5, [r3, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x03
	orrs r5, r0
	ldr r0, _08341958 @ =0x020243E8
	bl sub_0833FD78
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	orrs r5, r0
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_0833D6D8
	b _083419BA
	.byte 0x00, 0x00
	.global _0834193C
_0834193C: .4byte 0x02026E18
	.global _08341940
_08341940: .4byte 0x000001FF
	.global _08341944
_08341944: .4byte 0x02026E14
	.global _08341948
_08341948: .4byte 0x80008000
	.global _0834194C
_0834194C: .4byte 0x020390EC
	.global _08341950
_08341950: .4byte 0x0202772C
	.global _08341954
_08341954: .4byte 0x020390AC
	.global _08341958
_08341958: .4byte 0x020243E8
	.global _0834195C
_0834195C:
	ldr r1, _083419CC @ =0x0202773C
	movs r3, #0xB1
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r5, [r0, #0x00]
	ldr r1, [sp, #0x004]
	subs r1, #0x08
	str r1, [sp, #0x004]
	ldr r0, [sp, #0x000]
	adds r0, #0x10
	str r0, [sp, #0x000]
	movs r4, #0xFF
	ands r4, r1
	ldr r1, _083419D0 @ =0x000001FF
	ands r0, r1
	lsls r0, r0, #0x10
	orrs r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x07
	orrs r4, r0
	ldr r0, [r5, #0x00]
	bl sub_0833FBFC
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _083419BA
	ldr r5, [r3, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x03
	orrs r5, r0
	ldr r0, _083419D4 @ =0x0201B590
	bl sub_0833FD78
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x0C
	orrs r5, r0
	mov r2, r9
	adds r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl sub_0833D6D8
	.global _083419BA
_083419BA:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _083419CC
_083419CC: .4byte 0x0202773C
	.global _083419D0
_083419D0: .4byte 0x000001FF
	.global _083419D4
_083419D4: .4byte 0x0201B590
