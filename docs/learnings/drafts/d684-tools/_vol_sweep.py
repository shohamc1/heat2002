#!/usr/bin/env python3
"""volatile-qualifier experiments on the globals/pointers of sub_0800D684."""
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, "docs/learnings/drafts/d684-tools")
import filediff  # noqa: E402

BASE = pathlib.Path("src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/vol")
E = [
    ("cc_vol_ptr", "    struct Unk0802CC90 *cc;", "    struct Unk0802CC90 * volatile cc;"),
    ("pa_pb_vol", "    s32 *pa, *pb;", "    s32 * volatile pa, * volatile pb;"),
    ("allptr_vol", "    s32 *pa, *pb;", "    s32 * volatile pa;\n    s32 * volatile pb;"),
    ("ccobj_vol", "extern struct Unk0802CC90 gUnk_0202CC90;", "extern volatile struct Unk0802CC90 gUnk_0202CC90;"),
    ("ccobj_vol_ptr", "    struct Unk0802CC90 *cc;", "    volatile struct Unk0802CC90 *cc;"),
    ("ccb0_vol", "extern s32 gUnk_0202CCB0[];", "extern volatile s32 gUnk_0202CCB0[];"),
    ("ccd30_vol", "extern s32 gUnk_0202CD30[];", "extern volatile s32 gUnk_0202CD30[];"),
    ("a550_vol", "extern u8 gUnk_0202A550[][0x190];", "extern volatile u8 gUnk_0202A550[][0x190];"),
    ("fda2c_vol", "extern struct Pt2 gUnk_083FDA2C[];", "extern volatile struct Pt2 gUnk_083FDA2C[];"),
    ("cd08_vol", "extern s16 gUnk_0801CD08[];", "extern volatile s16 gUnk_0801CD08[];"),
]


def work(item):
    name, old, new = item
    if BASE.count(old) != 1:
        return {"name": name, "note": f"pattern={BASE.count(old)}"}
    d = OUT / name
    d.mkdir(parents=True, exist_ok=True)
    f = d / "v.c"
    f.write_text(BASE.replace(old, new))
    r = filediff.report(str(f), str(d))
    r["name"] = name
    return r


if __name__ == "__main__":
    with ProcessPoolExecutor(max_workers=6) as ex:
        rows = list(ex.map(work, E))
    for r in sorted(rows, key=lambda r: (r.get("hunks", 99), r.get("sdiff", 99999))):
        print(f"{r['name']:16s} size={str(r.get('size','-')):>5} hunks={str(r.get('hunks','-')):>2} sdiff={str(r.get('sdiff','-')):>5} {r.get('note','')}")