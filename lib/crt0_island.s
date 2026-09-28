@ The multiboot island's start routine and interrupt dispatcher. The same
@ SDK crt0 template as lib/crt0.s, preceded by a link-cable handshake with
@ the main program: wait for the parent to send 0, then 0x8000, 0x400, 0x20,
@ 1 and 0, echoing each one. Then send each half of the island's game code;
@ if the parent doesn't send it back, hang.
@ The island's multiboot header branches to sub_08363FF4. Labels keep
@ their luvdis names, as the other copies outside the main program do.

	.include "function.inc"

	.syntax unified

	.set PSR_IRQ_MODE, 0x12
	.set PSR_SYS_MODE, 0x1F

	.set REG_BASE, 0x4000000
	.set OFFSET_REG_IE, 0x200
	.set OFFSET_REG_IF, 0x202
	.set REG_SIOMULTI0, 0x4000120
	.set OFFSET_REG_SIOCNT, 0x8
	.set OFFSET_REG_SIOMLT_SEND, 0xA
	.set SIO_START, 0x80
	.set SIO_ERROR, 0x40

	.set IWRAM_END, 0x3008000
	.set INTR_VECTOR, 0x3007FFC

	.text

@ Waits for one multi-player transfer to finish. Returns with Z clear if
@ the transfer failed, else with Z set and the parent's halfword in r1.
	arm_func_start sub_08363FC8
sub_08363FC8:
	ldrh r1, [r0, #OFFSET_REG_SIOCNT]
	tst r1, #SIO_START
	beq sub_08363FC8
1:
	ldrh r1, [r0, #OFFSET_REG_SIOCNT]
	tst r1, #SIO_START
	bne 1b
	ldrh r1, [r0, #OFFSET_REG_SIOCNT]
	tst r1, #SIO_ERROR
	bxne lr
	ldrh r1, [r0]
	bx lr
	arm_func_end sub_08363FC8

	arm_func_start sub_08363FF4
sub_08363FF4:
	ldr r0, =REG_SIOMULTI0
.Lrestart:
	bl sub_08363FC8
	bne .Lrestart
	mov r2, #0
	strh r2, [r0, #OFFSET_REG_SIOMLT_SEND]
	cmp r1, #0
	bne .Lrestart
	mov r2, #0x8000
.Lexpect:
	mov r1, #0
.Lsend:
	strh r1, [r0, #OFFSET_REG_SIOMLT_SEND]
	bl sub_08363FC8
	bne .Lrestart
	cmp r1, r2
	bne .Lexpect
	lsr r2, r2, #5
	cmp r1, #0
	bne .Lsend
	ldr r3, =gUnk_020000AC
	ldrh r2, [r3]
	strh r2, [r0, #OFFSET_REG_SIOMLT_SEND]
	bl sub_08363FC8
.Lhang:
	bne .Lhang @ spin: a failed or wrong reply hangs the island
	cmp r1, r2
	bne .Lhang
	ldrh r2, [r3, #2]
	strh r2, [r0, #OFFSET_REG_SIOMLT_SEND]
	bl sub_08363FC8
	bne .Lhang
	cmp r1, r2
	bne .Lhang
	mov r1, #0
	strh r1, [r0, #OFFSET_REG_SIOMLT_SEND]
.Linit:
	mov r0, #PSR_IRQ_MODE
	msr cpsr_fc, r0
	ldr sp, sp_irq
	mov r0, #PSR_SYS_MODE
	msr cpsr_fc, r0
	ldr sp, sp_sys
	ldr r1, =INTR_VECTOR
	adr r0, sub_083640B0
	str r0, [r1]
	ldr r1, =IslandAgbMain + 1
	mov lr, pc
	bx r1
	b .Linit

sp_sys: .word IWRAM_END - 0x100
sp_irq: .word IWRAM_END - 0x60
	arm_func_end sub_08363FF4

@ Interrupts in plain bit order. It never re-enables interrupts, so
@ handlers don't nest, and the handler returns straight to the BIOS.
	arm_func_start sub_083640B0
sub_083640B0:
	mov r3, #REG_BASE
	add r3, r3, #OFFSET_REG_IE
	ldr r2, [r3]
	and r1, r2, r2, lsr #16
	mov r2, #0
	.irp bit, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
	ands r0, r1, #1 << \bit
	bne .Lfound
	add r2, r2, #4
	.endr
	ands r0, r1, #1 << 13
.Lfound:
	strh r0, [r3, #OFFSET_REG_IF - OFFSET_REG_IE]
	ldr r1, =gUnk_02000980
	add r1, r1, r2
	ldr r0, [r1]
	bx r0

	.pool
	arm_func_end sub_083640B0
