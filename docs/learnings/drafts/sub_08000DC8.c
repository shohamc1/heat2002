/*
 * sub_08000DC8 -- BLOCKED (60 bytes @ 0x08000DC8, epilogue is interwork form)
 *
 * Target (asm/rom_080004B8.s:217-261):
 *   push {r4,r5,r6,lr}
 *   adds r5, r1, #0
 *   ldrb r1, [r5]
 *   movs r0, #0x80
 *   tst  r0, r1          ; 0x4208  -- UNREACHABLE
 *   beq  _08000E00
 *   ldr  r4, [r5,#0x20]
 *   cmp  r4, #0
 *   beq  _08000DFE
 *   movs r6, #0
 * _08000DDC:                 ; do..while over the linked list
 *   ldrb r0, [r4]
 *   cmp  r0, #0
 *   beq  _08000DF6
 *   ldrb r0, [r4,#1]
 *   movs r3, #7
 *   ands r0, r3          ; flags reused by the beq below -- also unreachable
 *   beq  _08000DF4
 *   ldr  r3, =0x03007FF0
 *   ldr  r3, [r3]
 *   ldr  r3, [r3,#0x2C]
 *   bl   _08000DB8       ; bx r3 veneer = _call_via_r3 @ 0x08000DB8
 * _08000DF4: strb r6, [r4]
 * _08000DF6: str  r6, [r4,#0x2C] ; ldr r4,[r4,#0x34] ; bne _08000DDC
 * _08000DFE: str  r4, [r5,#0x20]
 *
 * Blocker: `tst r0, r1`. agbcc's thumb tstsi pattern is literally
 * "cmp %0, #0" (tools/agbcc/gcc/thumb.md:818) -- a register-vs-register
 * TST cannot be emitted from any C. Additionally the `ands r0,r3; beq`
 * relies on flag reuse from the ANDS (no intervening cmp), which no
 * matched function in the corpus exhibits either (same class as the 112
 * unmatched ands+bcc sites). This function is therefore outside agbcc's
 * reach, like F0BC's subs+bgt loop.
 *
 * Semantics worked out for the record (compile-ready if the wall falls):
 *
 *     struct Node { u8 b0; u8 b1; u8 pad[0x2A]; u32 f2C;
 *                   u8 pad2[4]; struct Node *next; };
 *     struct Head { u8 flags; u8 pad[0x1F]; struct Node *list; };
 *
 *     void sub_08000DC8(u32 unused, struct Head *head)
 *     {
 *         struct Node *node;
 *         if (head->flags & 0x80) {
 *             node = head->list;
 *             if (node != NULL) {
 *                 do {
 *                     if (node->b0 != 0) {
 *                         if (node->b1 & 7)
 *                             ((void (*)(u32))*(u32 *)(gUnk_03007FF0[0] + 0x2C))(
 *                                 node->b1 & 7);
 *                         node->b0 = 0;
 *                     }
 *                     node->f2C = 0;
 *                     node = node->next;
 *                 } while (node != NULL);
 *             }
 *             head->list = node;      / * NULL * /
 *         }
 *     }
 *
 * The call is 1-arg (r1 still holding `flags` at the bl is dead garbage,
 * not a second argument -- a live 2nd arg would need a reload inside the
 * loop; there is none). To link the veneer, symbols.ld needs
 * `_call_via_r3 = 0x08000DB8;` (absent as of 2026-09-13; _call_via_r1/r2
 * already exist there). My test compile of the body above reproduces every
 * instruction except the two flagged sites (it emits and+cmp where the ROM
 * has tst / bare ands) and picks _call_via_r1 for the indirect call.
 */
