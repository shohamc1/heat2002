
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef u8 bool8;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
extern u16 gUnk_020251F0;
extern u32 gUnk_083FF79C[];
extern u8 gUnk_0202523C;
extern u8 gUnk_020253C8;
extern u8 gUnk_083393C0[];
u32 *sub_0800754C(u32 a);
u8 sub_08007714(u32 a);
u32 sub_080044A4(u32 a, u32 b);
void sub_080047E8(u8 a, u16 b)
{
  u16 cmd[2];
  u32 *res;
  u32 attr;
  u32 arg1;
  u8 x;
  u8 y;
  u8 z;
  u8 w;
  u16 *c;
  if (b != 0)
  {
    gUnk_020251F0 = b;
    c = cmd;
    z = 0;
    w = 0;
    c[0] = 0x68;
    cmd[1] = w;
    res = sub_0800754C(gUnk_083FF79C[a & 7]);
    x = (a & 8) >> 3;
    y = (a & 0x10) >> 4;
    if (res == 0)
    {
      return;
    }
    gUnk_020251F0 = b;
    attr = ((cmd[1] & 0xFF) | ((cmd[0] & 0x1FF) << 16)) | 0x80000000;
    arg1 = res[4] | (sub_08007714((u32) gUnk_083393C0) << 12);
    attr |= 0x04000100;
    gUnk_0202523C = z;
    gUnk_020253C8 = z;
    if (x != 0)
    {
      gUnk_0202523C = 1;
    }
    if (y != 0)
    {
      gUnk_020253C8 = 1;
    }
    sub_080044A4(attr, arg1);
  }
  else
  {
    cmd[0] = 0x68;
    cmd[1] = b;
    res = sub_0800754C(gUnk_083FF79C[a & 7]);
    x = (a & 8) >> 3;
    y = (a & 0x10) >> 4;
    if (res == 0)
    {
      return;
    }
    attr = ((cmd[1] & 0xFF) | ((cmd[0] & 0x1FF) << 16)) | 0x80000000;
    arg1 = res[4] | (sub_08007714((u32) gUnk_083393C0) << 12);
    if (x != 0)
    {
      attr |= 0x10000000;
    }
    if (y != 0)
    {
      attr |= 0x20000000;
    }
    sub_080044A4(attr, arg1);
  }
}
