@ Nintendo SDK start routine and interrupt dispatcher (crt0.s), this ROM's
@ revision. Derived from src/crt0.s in pret/pokeemerald at 5eff786: the same
@ SDK template, with this ROM's system stack, interrupt priority order and
@ IME handling. The main program and the high 0x0834 module each link a
@ copy; the Makefile renames the high copy's symbols to its luvdis names and
@ points AgbMain and the interrupt table at the module's own.

	.include "function.inc"

	.syntax unified

	.set PSR_IRQ_MODE, 0x12
	.set PSR_SYS_MODE, 0x1F
	.set PSR_I_BIT, 0x80
	.set PSR_F_BIT, 0x40
	.set PSR_MODE_MASK, 0x1F

	.set REG_BASE, 0x4000000
	.set OFFSET_REG_IE, 0x200
	.set OFFSET_REG_IF, 0x202
	.set OFFSET_REG_IME, 0x208
	.set OFFSET_REG_SOUNDCNT_X, 0x84

	.set INTR_FLAG_VBLANK, 1 << 0
	.set INTR_FLAG_HBLANK, 1 << 1
	.set INTR_FLAG_VCOUNT, 1 << 2
	.set INTR_FLAG_TIMER3, 1 << 6
	.set INTR_FLAG_SERIAL, 1 << 7
	.set INTR_FLAG_DMA0, 1 << 8
	.set INTR_FLAG_DMA1, 1 << 9
	.set INTR_FLAG_DMA2, 1 << 10
	.set INTR_FLAG_DMA3, 1 << 11
	.set INTR_FLAG_KEYPAD, 1 << 12
	.set INTR_FLAG_GAMEPAK, 1 << 13

	.set IWRAM_END, 0x3008000
	.set INTR_VECTOR, 0x3007FFC

	.text

	arm_func_start Init
Init:
	mov r0, #PSR_IRQ_MODE
	msr cpsr_fc, r0
	ldr sp, sp_irq
	mov r0, #PSR_SYS_MODE
	msr cpsr_fc, r0
	ldr sp, sp_sys
	ldr r1, =INTR_VECTOR
	adr r0, IntrMain
	str r0, [r1]
	ldr r1, =AgbMain + 1
	mov lr, pc
	bx r1
	b Init

sp_sys: .word IWRAM_END - 0x200
sp_irq: .word IWRAM_END - 0x60

	.pool
	arm_func_end Init

@ Serial and timer 3 first, together, then the rest in bit order. IME stays
@ set while a handler runs, and only those two and the Game Pak interrupt
@ stay enabled during it.
	arm_func_start IntrMain
IntrMain:
	mov r3, #REG_BASE
	add r3, r3, #OFFSET_REG_IE
	ldr r2, [r3]
	ldrh r1, [r3, #OFFSET_REG_IME - OFFSET_REG_IE]
	mrs r0, spsr
	stmfd sp!, {r0-r3, lr}
	mov r0, #1
	strh r0, [r3, #OFFSET_REG_IME - OFFSET_REG_IE]
	and r1, r2, r2, lsr #16
	mov r12, #0
	ands r0, r1, #INTR_FLAG_SERIAL | INTR_FLAG_TIMER3
	bne IntrMain_FoundIntr
	add r12, r12, #4
	ands r0, r1, #INTR_FLAG_VBLANK
	bne IntrMain_FoundIntr
	add r12, r12, #4
	ands r0, r1, #INTR_FLAG_VCOUNT
	bne IntrMain_FoundIntr
	add r12, r12, #4
	ands r0, r1, #INTR_FLAG_HBLANK
	bne IntrMain_FoundIntr
	add r12, r12, #4
	ands r0, r1, #INTR_FLAG_DMA0
	bne IntrMain_FoundIntr
	add r12, r12, #4
	ands r0, r1, #INTR_FLAG_DMA1
	bne IntrMain_FoundIntr
	add r12, r12, #4
	ands r0, r1, #INTR_FLAG_DMA2
	bne IntrMain_FoundIntr
	add r12, r12, #4
	ands r0, r1, #INTR_FLAG_DMA3
	bne IntrMain_FoundIntr
	add r12, r12, #4
	ands r0, r1, #INTR_FLAG_KEYPAD
	bne IntrMain_FoundIntr
	add r12, r12, #4
	ands r0, r1, #INTR_FLAG_GAMEPAK
	strbne r0, [r3, #OFFSET_REG_SOUNDCNT_X - OFFSET_REG_IE]
	bne . @ spin
IntrMain_FoundIntr:
	strh r0, [r3, #OFFSET_REG_IF - OFFSET_REG_IE]
	mov r1, #INTR_FLAG_GAMEPAK | INTR_FLAG_SERIAL | INTR_FLAG_TIMER3
	bic r2, r2, r0
	and r1, r1, r2
	strh r1, [r3]
	mrs r3, cpsr
	bic r3, r3, #PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK
	orr r3, r3, #PSR_SYS_MODE
	msr cpsr_fc, r3
	ldr r1, =gIntrTable
	add r1, r1, r12
	ldr r0, [r1]
	stmfd sp!, {lr}
	adr lr, IntrMain_RetAddr
	bx r0
IntrMain_RetAddr:
	ldmfd sp!, {lr}
	mrs r3, cpsr
	bic r3, r3, #PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK
	orr r3, r3, #PSR_I_BIT | PSR_IRQ_MODE
	msr cpsr_fc, r3
	ldmia sp!, {r0-r3, lr}
	strh r2, [r3]
	strh r1, [r3, #OFFSET_REG_IME - OFFSET_REG_IE]
	msr spsr_fc, r0
	bx lr

	.pool
	arm_func_end IntrMain
