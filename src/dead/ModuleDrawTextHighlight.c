#include "global.h"
#include "variables.h"
#include "data.h"

void ModuleDrawTextHighlight(const u8 *text, u32 x, u32 y, u8 highlight)
{
    u16 *out;
    u32 off;
    u16 color;
    u8 t;
    u16 *e;
    u16 idx;
    u32 c;

        out = &(*(u16 **)&gModule_TextLayerMapPtr)[y * 0x20 + x];
    color = 0xE0 << 8; /* tilemap entry: palette bank 14 */
    if (highlight != 0)
        color = 0xF0 << 8; /* tilemap entry: palette bank 15 */
    c = *text++;
    while (c != 0) {
        t = c - ' ';
        idx = (u16)(((((t >> 5) << 22) + 0x600000u) >> 16));
        idx = idx + (t & 0x1F);
        e = &gUnk_0201F590[idx];
        out[0] = color | gModule_TextGlyphTileIndices[e[0]];
        out[1] = color | gModule_TextGlyphTileIndices[e[1]];
        out[0x20] = color | gModule_TextGlyphTileIndices[e[0x20]];
        out[0x21] = color | gModule_TextGlyphTileIndices[e[0x21]];
        out += 1;
        c = *text++;
    }
}

void ModuleDrawBigText(const u8 *text)
{
  u16 *dest;
  const u8 *p;
  const u8 *q;
  s32 len;
  u8 i;
  u16 color;
  u32 idx;
  u8 t;
  u16 *e;
  u32 c;
  dest = (u16 *) (gModule_TextLayerMapPtr[0] + 2 * 32) /* text row 2 */;
  do
  {
    color = 0xF0 << 8; /* tilemap entry: palette bank 15 */
  }
  while (0);
  i = 0;
  q = text;
  len = 0;
  while ((*q) != 0)
  {
    q++;
    len++;
  }

  for (; i < ((30 - len) / 2); i++, dest++)
  {
    c = (*gUnk_02025230) - ' ';
    t = c;
    idx = (((t >> 5) << 22) + 0x600000u) >> 16;
    e = &gUnk_0201F590[idx + (t & 0x1F)];
    dest[0] = color | gModule_TextGlyphTileIndices[e[0]];
    dest[32] = color | gModule_TextGlyphTileIndices[e[0x20]];
  }

  c = *text;
  p = text + 1;
  if (c != 0)
  {
    do
    {
      t = c - ' ';
      idx = (((t >> 5) << 22) + 0x600000u) >> 16;
      e = &gUnk_0201F590[idx + (t & 0x1F)];
      dest[0] = color | gModule_TextGlyphTileIndices[e[0]];
      dest[32] = color | gModule_TextGlyphTileIndices[e[0x20]];
      dest++;
      i++;
      c = *p;
      p++;
    }
    while (c != 0);
  }
  for (; i < 0x20; i++, dest++)
  {
    t = (*gUnk_02025230) - ' ';
    idx = (((t >> 5) << 22) + 0x600000u) >> 16;
    e = &gUnk_0201F590[idx + (t & 0x1F)];
    dest[0] = color | gModule_TextGlyphTileIndices[e[0]];
    dest[32] = color | gModule_TextGlyphTileIndices[e[0x20]];
  }

}

void sub_0833F1A4(void)
{
}

extern u8 *gModule_0202522C;
extern u8 *gUnk_02025234;

void sub_0833F1A8(u8 *str)
{
    vu16 *vp;
    u16 pal;
    u8 i;
    u8 j;
    u8 c;
    u8 ch;
    u16 base;
    u16 *tile;

    vp = (vu16 *)0x06008040;
    pal = 0xF000;
    i = 0;
    while ((c = *str++) != 0) {
        ch = c - 0x20;
        base = (ch >> 5) * 64 + 0x60;
        tile = &gUnk_0201F590[base + (ch & 0x1F)];
        vp[0] = pal | gModule_TextGlyphTileIndices[tile[0]];
        vp[0x20] = pal | gModule_TextGlyphTileIndices[tile[0x20]];
        vp++;
        i++;
    }
    str = gModule_0202522C;
    while ((c = *str++) != 0) {
        ch = c - 0x20;
        base = (ch >> 5) * 64 + 0x60;
        tile = &gUnk_0201F590[base + (ch & 0x1F)];
        vp[0] = pal | gModule_TextGlyphTileIndices[tile[0]];
        vp[0x20] = pal | gModule_TextGlyphTileIndices[tile[0x20]];
        vp++;
        i++;
    }
    while (i < 32) {
        c = *gUnk_02025230;
        ch = c - 0x20;
        base = (ch >> 5) * 64 + 0x60;
        tile = &gUnk_0201F590[base + (ch & 0x1F)];
        vp[0] = pal | gModule_TextGlyphTileIndices[tile[0]];
        vp[0x20] = pal | gModule_TextGlyphTileIndices[tile[0x20]];
        i++;
        vp++;
    }
    str = gUnk_02025234;
    vp = (vu16 *)0x06008440;
    while ((c = *str++) != 0) {
        /* The space glyph, set inside the loop: the index stays a
           register sum off the table base, as in the ROM. */
        ch = ' ' - 0x20;
        base = (ch >> 5) * 64 + 0x60;
        tile = &gUnk_0201F590[base + (ch & 0x1F)];
        vp[0] = pal | gModule_TextGlyphTileIndices[tile[0]];
        vp[0x20] = pal | gModule_TextGlyphTileIndices[tile[0x20]];
        vp[0x40] = pal | gModule_TextGlyphTileIndices[tile[0x20]];
        vp[0x60] = pal | gModule_TextGlyphTileIndices[tile[0x20]];
        vp++;
    }
    vp = (vu16 *)0x06008000;
    for (j = 0; j != 32; j++) {
        *vp = pal | gModule_TextGlyphTileIndices[tile[0x20]];
        vp++;
    }
}

void sub_0833F3C0(u8 *str, u32 y, u8 shade)
{
    u8 *cursor;
    u8 len;
    u8 c;
    u8 w;
    u16 gw;
    u16 *dest;
    u32 e;

    cursor = str;
    len = 0;
    while (*cursor != 0)
    {
        cursor++;
        len++;
    }
    w = (u8)((0x1E - len) / 2);
    dest = (u16 *)(*(u32 *)&gModule_TextLayerMapPtr);
    dest = (u16 *)((u32)dest + (((y << 5) + w) << 1));
    e = 0xE0 << 8;
    if (shade != 0)
        e = 0xF0 << 8;
    c = *str;
    str++;
    if (c != 0)
    {
        do
        {
            gw = gUnk_0201F590[(u8)(c - 0x20)];
            *dest = e | gModule_TextGlyphTileIndices[gw];
            dest++;
            c = *str;
            str++;
        } while (c != 0);
    }
}
