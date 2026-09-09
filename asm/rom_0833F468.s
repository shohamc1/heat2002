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
	thumb_func_start sub_0833F468
sub_0833F468:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x094
	adds r7, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x054]
	ldr r1, _0833F4A0 @ =0x0203E120
	movs r0, #0x03
	ldrb r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x058]
	ldr r2, _0833F4A4 @ =0x020390CC
	movs r0, #0x00
	strb r0, [r2, #0x00]
	ldr r0, _0833F4A8 @ =0x020390EC
	ldrb r1, [r0, #0x00]
	adds r2, r0, #0x0
	cmp r1, #0x00
	beq _0833F4B0
	ldr r0, _0833F4AC @ =0x0203E1B0
	ldrb r0, [r0, #0x00]
	b _0833F4B2
	.global _0833F4A0
_0833F4A0: .4byte 0x0203E120
	.global _0833F4A4
_0833F4A4: .4byte 0x020390CC
	.global _0833F4A8
_0833F4A8: .4byte 0x020390EC
	.global _0833F4AC
_0833F4AC: .4byte 0x0203E1B0
	.global _0833F4B0
_0833F4B0:
	movs r0, #0x00
	.global _0833F4B2
_0833F4B2:
	str r0, [sp, #0x06C]
	ldrb r0, [r2, #0x00]
	cmp r0, #0x00
	beq _0833F4C4
	ldr r0, _0833F4C0 @ =0x020390BC
	b _0833F4C6
	.byte 0x00, 0x00
	.global _0833F4C0
_0833F4C0: .4byte 0x020390BC
	.global _0833F4C4
_0833F4C4:
	ldr r0, _0833F5F8 @ =0x020390A0
	.global _0833F4C6
_0833F4C6:
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x068]
	ldr r2, _0833F5FC @ =0x0203B860
	adds r1, r7, #0x0
	adds r1, #0x4D
	ldrb r3, [r1, #0x00]
	lsls r0, r3, #0x01
	adds r0, r0, r3
	lsls r0, r0, #0x03
	ldr r2, [r2, #0x00]
	adds r0, r2, r0
	str r0, [sp, #0x064]
	adds r3, r0, #0x0
	adds r3, #0x18
	str r1, [sp, #0x07C]
	ldrh r4, [r0, #0x10]
	cmp r4, #0x01
	bne _0833F4EC
	adds r3, r2, #0x0
	.global _0833F4EC
_0833F4EC:
	add r1, sp, #0x028
	ldr r5, [r7, #0x00]
	asrs r0, r5, #0x10
	str r0, [sp, #0x028]
	ldr r6, [r7, #0x08]
	asrs r0, r6, #0x10
	mov r12, r0
	str r0, [r1, #0x04]
	ldr r0, [r7, #0x0C]
	adds r5, r5, r0
	asrs r5, r5, #0x10
	str r5, [r1, #0x08]
	ldr r0, [r7, #0x14]
	adds r6, r6, r0
	asrs r6, r6, #0x10
	str r6, [sp, #0x090]
	str r6, [r1, #0x0C]
	ldr r1, [sp, #0x064]
	ldr r0, [r1, #0x00]
	ldr r2, [r1, #0x04]
	str r2, [sp, #0x084]
	ldr r4, [r1, #0x08]
	ldr r6, [r1, #0x0C]
	str r6, [sp, #0x088]
	ldr r1, [r3, #0x00]
	ldr r2, [r3, #0x04]
	mov r9, r2
	ldr r6, [r3, #0x08]
	mov r8, r6
	ldr r3, [r3, #0x0C]
	mov r10, r3
	adds r2, r7, #0x0
	adds r2, #0x4E
	str r2, [sp, #0x070]
	ldrb r3, [r2, #0x00]
	movs r2, #0x10
	subs r2, r2, r3
	muls r0, r2
	muls r1, r3
	adds r0, r0, r1
	asrs r0, r0, #0x04
	str r0, [sp, #0x05C]
	muls r4, r2
	mov r0, r8
	muls r0, r3
	adds r4, r4, r0
	asrs r4, r4, #0x04
	str r4, [sp, #0x08C]
	ldr r4, [sp, #0x084]
	adds r0, r4, #0x0
	muls r0, r2
	mov r1, r9
	muls r1, r3
	adds r0, r0, r1
	asrs r0, r0, #0x04
	str r0, [sp, #0x060]
	ldr r6, [sp, #0x088]
	muls r2, r6
	mov r0, r10
	muls r0, r3
	adds r2, r2, r0
	asrs r2, r2, #0x04
	movs r0, #0x4C
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	ldr r4, [sp, #0x07C]
	ldrb r4, [r4, #0x00]
	lsls r1, r4, #0x04
	adds r0, r0, r1
	adds r0, r0, r3
	str r0, [r7, #0x50]
	ldr r6, [sp, #0x028]
	mov r9, r6
	mov r0, r9
	subs r0, r5, r0
	str r0, [sp, #0x074]
	ldr r1, [sp, #0x060]
	subs r2, r2, r1
	adds r1, r0, #0x0
	muls r1, r2
	ldr r3, [sp, #0x090]
	mov r4, r12
	subs r3, r3, r4
	mov r10, r3
	ldr r6, [sp, #0x08C]
	ldr r0, [sp, #0x05C]
	subs r3, r6, r0
	mov r0, r10
	muls r0, r3
	subs r4, r1, r0
	ldr r1, [sp, #0x070]
	str r1, [sp, #0x080]
	mov r6, r8
	str r6, [sp, #0x078]
	cmp r4, #0x00
	beq _0833F5F4
	mov r0, r12
	ldr r1, [sp, #0x060]
	subs r6, r0, r1
	adds r0, r6, #0x0
	muls r0, r3
	mov r3, r9
	ldr r1, [sp, #0x05C]
	subs r5, r3, r1
	adds r1, r5, #0x0
	muls r1, r2
	subs r0, r0, r1
	lsls r0, r0, #0x08
	adds r1, r4, #0x0
	bl sub_08344BB8
	movs r2, #0x80
	lsls r2, r2, #0x01
	mov r8, r2
	cmp r0, r8
	bhi _0833F5F4
	ldr r3, [sp, #0x074]
	adds r0, r6, #0x0
	muls r0, r3
	mov r1, r10
	muls r1, r5
	subs r0, r0, r1
	lsls r0, r0, #0x08
	adds r1, r4, #0x0
	bl sub_08344BB8
	cmp r0, r8
	bls _0833F600
	.global _0833F5F4
_0833F5F4:
	movs r0, #0x00
	b _0833F930
	.global _0833F5F8
_0833F5F8: .4byte 0x020390A0
	.global _0833F5FC
_0833F5FC: .4byte 0x0203B860
	.global _0833F600
_0833F600:
	movs r4, #0xBA
	lsls r4, r4, #0x01
	adds r1, r7, r4
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0833F618
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _0833F844 @ =0x0203DD10
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	.global _0833F618
_0833F618:
	ldr r6, [sp, #0x080]
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	strb r0, [r6, #0x00]
	movs r0, #0x01
	ldr r1, _0833F848 @ =0x020390CC
	strb r0, [r1, #0x00]
	ldr r2, [sp, #0x078]
	movs r0, #0x00
	ldsb r0, [r2, r0]
	lsls r0, r0, #0x10
	ldr r3, [sp, #0x07C]
	ldrb r3, [r3, #0x00]
	lsls r1, r3, #0x04
	adds r0, r0, r1
	ldrb r4, [r6, #0x00]
	adds r0, r4, r0
	str r0, [r7, #0x50]
	ldrb r6, [r6, #0x00]
	cmp r6, #0x10
	beq _0833F644
	b _0833F92E
	.global _0833F644
_0833F644:
	movs r0, #0x00
	ldr r1, [sp, #0x080]
	strb r0, [r1, #0x00]
	ldrh r0, [r7, #0x34]
	strh r0, [r7, #0x36]
	ldr r2, [sp, #0x07C]
	ldrb r0, [r2, #0x00]
	strh r0, [r7, #0x38]
	ldr r4, [sp, #0x064]
	ldrh r3, [r4, #0x10]
	cmp r3, #0x01
	beq _0833F65E
	b _0833F8BC
	.global _0833F65E
_0833F65E:
	ldr r0, _0833F84C @ =0x0203916C
	adds r4, r0, #0x0
	ldrb r6, [r4, #0x00]
	cmp r6, #0x0C
	bne _0833F694
	ldr r1, _0833F850 @ =0x0203B6C8
	ldr r0, _0833F854 @ =0x0000EA60
	ldrh r1, [r1, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	ldr r0, _0833F858 @ =0x0203B6A8
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, r2, r0
	ldr r0, _0833F85C @ =0x0203B858
	ldrh r0, [r0, #0x00]
	adds r1, r0, r2
	ldr r0, _0833F860 @ =0x0203DFC4
	ldr r0, [r0, #0x00]
	cmp r1, r0
	bcs _0833F694
	ldr r0, _0833F864 @ =0x0203E104
	strb r3, [r0, #0x00]
	.global _0833F694
_0833F694:
	ldr r0, [sp, #0x054]
	ldr r1, [sp, #0x06C]
	cmp r0, r1
	bne _0833F6C2
	ldrb r4, [r4, #0x00]
	cmp r4, #0x0C
	beq _0833F6C2
	movs r2, #0xB3
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833F6C2
	ldr r3, _0833F868 @ =0x00000167
	adds r1, r7, r3
	movs r0, #0x1E
	strb r0, [r1, #0x00]
	movs r4, #0xB4
	lsls r4, r4, #0x01
	adds r1, r7, r4
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	.global _0833F6C2
_0833F6C2:
	ldr r6, [sp, #0x078]
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	movs r1, #0x00
	strb r0, [r6, #0x00]
	subs r0, r1, #0x1
	ldr r2, [sp, #0x07C]
	strb r0, [r2, #0x00]
	ldr r3, [sp, #0x080]
	strb r1, [r3, #0x00]
	movs r0, #0x00
	ldsb r0, [r6, r0]
	lsls r0, r0, #0x10
	ldrb r4, [r2, #0x00]
	lsls r1, r4, #0x04
	adds r0, r0, r1
	str r0, [r7, #0x50]
	ldr r6, [sp, #0x054]
	ldr r0, [sp, #0x06C]
	cmp r6, r0
	bne _0833F710
	ldr r0, _0833F86C @ =0x0203E1E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833F710
	movs r1, #0xC7
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833F710
	ldr r0, _0833F850 @ =0x0203B6C8
	ldrh r0, [r0, #0x00]
	ldr r1, _0833F858 @ =0x0203B6A8
	ldrh r1, [r1, #0x00]
	ldr r2, _0833F85C @ =0x0203B858
	ldrh r2, [r2, #0x00]
	bl sub_0833E160
	.global _0833F710
_0833F710:
	movs r2, #0xB3
	lsls r2, r2, #0x01
	adds r1, r7, r2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _0833F870 @ =0x0203D520
	cmp r7, r0
	bne _0833F762
	ldr r0, _0833F84C @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x05
	bne _0833F762
	movs r3, #0xC7
	lsls r3, r3, #0x01
	adds r0, r7, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833F762
	ldr r1, _0833F850 @ =0x0203B6C8
	ldr r0, _0833F854 @ =0x0000EA60
	ldrh r1, [r1, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	ldr r0, _0833F858 @ =0x0203B6A8
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, r2, r0
	ldr r0, _0833F85C @ =0x0203B858
	ldrh r0, [r0, #0x00]
	adds r1, r0, r2
	movs r4, #0xB6
	lsls r4, r4, #0x01
	adds r2, r7, r4
	ldr r0, [r2, #0x00]
	cmp r1, r0
	bcs _0833F762
	str r1, [r2, #0x00]
	.global _0833F762
_0833F762:
	ldr r6, [sp, #0x078]
	movs r1, #0x00
	ldsb r1, [r6, r1]
	ldr r0, _0833F874 @ =0x02039194
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	beq _0833F772
	b _0833F88C
	.global _0833F772
_0833F772:
	ldr r0, _0833F84C @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833F782
	cmp r0, #0x06
	beq _0833F782
	cmp r0, #0x01
	bne _0833F7AA
	.global _0833F782
_0833F782:
	movs r0, #0xB6
	lsls r0, r0, #0x01
	adds r3, r7, r0
	ldr r1, _0833F878 @ =0x0203B704
	ldr r0, _0833F854 @ =0x0000EA60
	ldrh r1, [r1, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	ldr r0, _0833F87C @ =0x0203B6D0
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, r2, r0
	ldr r0, _0833F880 @ =0x0203B6D4
	ldrh r0, [r0, #0x00]
	adds r2, r0, r2
	str r2, [r3, #0x00]
	.global _0833F7AA
_0833F7AA:
	ldr r1, [sp, #0x054]
	ldr r2, [sp, #0x06C]
	cmp r1, r2
	bne _0833F7CE
	movs r3, #0xC7
	lsls r3, r3, #0x01
	adds r0, r7, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833F7CE
	ldr r0, _0833F850 @ =0x0203B6C8
	ldrh r0, [r0, #0x00]
	ldr r1, _0833F858 @ =0x0203B6A8
	ldrh r1, [r1, #0x00]
	ldr r2, _0833F85C @ =0x0203B858
	ldrh r2, [r2, #0x00]
	bl sub_08342BA4
	.global _0833F7CE
_0833F7CE:
	ldr r5, _0833F84C @ =0x0203916C
	ldrb r4, [r5, #0x00]
	cmp r4, #0x02
	beq _0833F8B0
	adds r0, r7, #0x0
	bl sub_08341EC8
	ldr r0, _0833F884 @ =0x0203B868
	ldr r4, _0833F888 @ =0x0203B864
	ldrb r6, [r4, #0x00]
	adds r0, r6, r0
	add r1, sp, #0x054
	ldrb r1, [r1, #0x00]
	strb r1, [r0, #0x00]
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	strb r0, [r4, #0x00]
	ldrb r0, [r5, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _0833F824
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r3, r7, r2
	ldr r1, _0833F878 @ =0x0203B704
	ldr r0, _0833F854 @ =0x0000EA60
	ldrh r1, [r1, #0x00]
	adds r2, r1, #0x0
	muls r2, r0
	ldr r0, _0833F87C @ =0x0203B6D0
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, r2, r0
	ldr r0, _0833F880 @ =0x0203B6D4
	ldrh r0, [r0, #0x00]
	adds r2, r0, r2
	str r2, [r3, #0x00]
	.global _0833F824
_0833F824:
	ldrb r4, [r4, #0x00]
	ldr r3, [sp, #0x068]
	cmp r4, r3
	bne _0833F8B0
	ldrb r0, [r5, #0x00]
	cmp r0, #0x10
	beq _0833F8B0
	cmp r0, #0x0F
	beq _0833F8B0
	cmp r0, #0x02
	beq _0833F8B0
	cmp r0, #0x0E
	beq _0833F8B0
	bl sub_08342908
	b _0833F8B0
	.global _0833F844
_0833F844: .4byte 0x0203DD10
	.global _0833F848
_0833F848: .4byte 0x020390CC
	.global _0833F84C
_0833F84C: .4byte 0x0203916C
	.global _0833F850
_0833F850: .4byte 0x0203B6C8
	.global _0833F854
_0833F854: .4byte 0x0000EA60
	.global _0833F858
_0833F858: .4byte 0x0203B6A8
	.global _0833F85C
_0833F85C: .4byte 0x0203B858
	.global _0833F860
_0833F860: .4byte 0x0203DFC4
	.global _0833F864
_0833F864: .4byte 0x0203E104
	.global _0833F868
_0833F868: .4byte 0x00000167
	.global _0833F86C
_0833F86C: .4byte 0x0203E1E0
	.global _0833F870
_0833F870: .4byte 0x0203D520
	.global _0833F874
_0833F874: .4byte 0x02039194
	.global _0833F878
_0833F878: .4byte 0x0203B704
	.global _0833F87C
_0833F87C: .4byte 0x0203B6D0
	.global _0833F880
_0833F880: .4byte 0x0203B6D4
	.global _0833F884
_0833F884: .4byte 0x0203B868
	.global _0833F888
_0833F888: .4byte 0x0203B864
	.global _0833F88C
_0833F88C:
	ldr r4, [sp, #0x054]
	ldr r6, [sp, #0x06C]
	cmp r4, r6
	bne _0833F8BC
	movs r1, #0xC7
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833F8B0
	ldr r0, _0833F940 @ =0x0203B6C8
	ldrh r0, [r0, #0x00]
	ldr r1, _0833F944 @ =0x0203B6A8
	ldrh r1, [r1, #0x00]
	ldr r2, _0833F948 @ =0x0203B858
	ldrh r2, [r2, #0x00]
	bl sub_08342BA4
	.global _0833F8B0
_0833F8B0:
	ldr r2, [sp, #0x054]
	ldr r3, [sp, #0x06C]
	cmp r2, r3
	bne _0833F8BC
	bl sub_0833E05C
	.global _0833F8BC
_0833F8BC:
	ldr r4, [sp, #0x064]
	ldrh r2, [r4, #0x10]
	subs r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	bhi _0833F926
	ldr r6, [sp, #0x054]
	ldr r0, [sp, #0x06C]
	cmp r6, r0
	bne _0833F906
	ldr r1, _0833F94C @ =0x0203DE40
	movs r3, #0xAE
	lsls r3, r3, #0x01
	adds r0, r7, r3
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	beq _0833F8EA
	bl sub_08342D10
	.global _0833F8EA
_0833F8EA:
	ldr r0, _0833F950 @ =0x0203916C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x0A
	beq _0833F906
	ldr r4, [sp, #0x058]
	lsrs r0, r4, #0x01
	adds r0, #0x06
	ldr r6, [sp, #0x064]
	ldrb r6, [r6, #0x14]
	adds r0, r6, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_0833E094
	.global _0833F906
_0833F906:
	ldr r0, [sp, #0x064]
	ldrh r5, [r0, #0x10]
	cmp r5, #0x01
	bne _0833F926
	movs r1, #0xC7
	lsls r1, r1, #0x01
	adds r4, r7, r1
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _0833F926
	ldr r0, _0833F954 @ =0x0203D520
	cmp r7, r0
	bne _0833F924
	bl sub_08342A94
	.global _0833F924
_0833F924:
	strb r5, [r4, #0x00]
	.global _0833F926
_0833F926:
	ldr r2, [sp, #0x07C]
	ldrb r0, [r2, #0x00]
	adds r0, #0x01
	strb r0, [r2, #0x00]
	.global _0833F92E
_0833F92E:
	movs r0, #0x01
	.global _0833F930
_0833F930:
	add sp, #0x094
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.global _0833F940
_0833F940: .4byte 0x0203B6C8
	.global _0833F944
_0833F944: .4byte 0x0203B6A8
	.global _0833F948
_0833F948: .4byte 0x0203B858
	.global _0833F94C
_0833F94C: .4byte 0x0203DE40
	.global _0833F950
_0833F950: .4byte 0x0203916C
	.global _0833F954
_0833F954: .4byte 0x0203D520
