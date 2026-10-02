/* ROM/RAM data addresses referenced from C. One line per symbol. */
gSoundInfoPtr = 0x03007FF0;
gUnk_02025370 = 0x02025370;
gIntrVector = 0x03007FFC;
gSmallDigitGlyphs = gFontGlyphGrid + 0x3E;
gBigDigitGlyphs = gFontGlyphGrid + 0x16;
gModule_VBlankCallback = 0x020375D0;
gUnk_02037E20 = 0x02037E20;
gModule_IntrTable = 0x020375E0;
gUnk_02037618 = 0x02037618;
gUnk_0203761C = 0x0203761C;
/* MP2K build-configuration constants. Not addresses: the code takes the
   symbol's address to materialise a small constant. The two engine copies
   are configured with different player counts. */
gNumMusicPlayersLow = 0x00000005;
gDriverSelectGfxDest = 0x06016000;
gNumMusicPlayersHigh = 0x00000004;

gUnk_083FDE2D = gChampionshipTrackOrder + 0x11;
gUnk_0600F800 = 0x0600F800;
/* Two absolute aliases point inside the track map buffers that
   src/system/globals.c defines (gUnk_0200CAD0 inside gBg2MapBuffer and
   gUnk_02022823 inside gCellMapBuffer); no code references either, so they
   keep their addresses here instead of carving the buffers apart. */
gUnk_02022823 = 0x02022823;
gMaxLines = 0x00000000;   /* shared by both engine copies */
gUnk_0200CAD0 = 0x0200CAD0;
gUnk_02037000 = 0x02037000;
gUnk_02037280 = 0x02037280;
gUnk_02037460 = 0x02037460;
gUnk_02037500 = 0x02037500;
gUnk_02025270 = 0x02025270;
gUnk_020375A0 = 0x020375A0;
gUnk_020375A4 = 0x020375A4;
gUnk_020375A8 = 0x020375A8;
gUnk_020375AC = 0x020375AC;
gUnk_020375B0 = 0x020375B0;
gUnk_020375B4 = 0x020375B4;
gUnk_020375B8 = 0x020375B8;
gUnk_020375BC = 0x020375BC;
gUnk_020375C0 = 0x020375C0;
gUnk_020375C4 = 0x020375C4;
gUnk_020375C8 = 0x020375C8;
gUnk_08334E22 = gFontGlyphGrid + 0x56;
gModule_BigDigitGlyphs = gModule_FontGlyphGrid + 0x16;
gModule_SmallDigitGlyphs = gModule_FontGlyphGrid + 0x3E;
gUnk_020215EA = gModule_FontGlyphGrid + 0x56;
gUnk_0200C910 = gUnk_08345390;
/* Rows inside gModule_PitLabelBlock (src/data/high_module_text.c) the
 * module's pit-menu option tables name (src/data/module_race_setup.c). */
gUnk_0200CFC4 = gModule_PitLabelBlock + 0x34;
gUnk_0200CFC8 = gModule_PitLabelBlock + 0x38;
gUnk_0200CFD0 = gModule_PitLabelBlock + 0x40;
gUnk_0200CF98 = gModule_PitLabelBlock + 0x8;
gUnk_0200CFA0 = gModule_PitLabelBlock + 0x10;
gUnk_0200CFA4 = gModule_PitLabelBlock + 0x14;
gUnk_0200CFD8 = gModule_PitLabelBlock + 0x48;
gUnk_0200CFE0 = gModule_PitLabelBlock + 0x50;
gUnk_0200CFEC = gModule_PitLabelBlock + 0x5C;
gUnk_0200CFF8 = gModule_PitLabelBlock + 0x68;
gUnk_0200D004 = gModule_PitLabelBlock + 0x74;
gUnk_0200D010 = gModule_PitLabelBlock + 0x80;
gUnk_0200D020 = gModule_PitLabelBlock + 0x90;
gUnk_0200D030 = gModule_PitLabelBlock + 0xA0;
gUnk_0200D040 = gModule_PitLabelBlock + 0xB0;
gUnk_0200D04C = gModule_PitLabelBlock + 0xBC;
gUnk_0200D0EC = gModule_Demo + 0x14;
gUnk_0200D10C = gModule_OutOfTime + 0xC;
gUnk_0202E948 = 0x0202E948;
gUnk_0202ED68 = 0x0202ED68;
gUnk_0202E91C = 0x0202E91C;
gUnk_0202E950 = 0x0202E950;
gUnk_0202E930 = 0x0202E930;
gUnk_0202E928 = 0x0202E928;
gUnk_0202E938 = 0x0202E938;
gUnk_0202CEF0 = 0x0202CEF0;
gUnk_0202E918 = 0x0202E918;
gUnk_0202E924 = 0x0202E924;
gUnk_0202E900 = 0x0202E900;
gUnk_02000964 = gUnk_0836484C;
gUnk_02000980 = gUnk_0836484C + 0x1C;
gUnk_020009B8 = gUnk_0836484C + 0x54;
gUnk_02000BD4 = gUnk_08364ABC;
gUnk_02000D00 = 0x02000D00;
gUnk_0202E94C = 0x0202E94C;
gUnk_0500013C = 0x0500013C;
gUnk_05000200 = 0x05000200;
gUnk_0600C000 = 0x0600C000;
