#!/usr/bin/env python3
"""Pre-loop check spellings: try to flip the 0x18F constant's register (index 36)."""
import pathlib
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, "docs/learnings/drafts/d684-tools")
import filediff  # noqa: E402

BASE = pathlib.Path("src/sub_0800D684.c").read_text()
OUT = pathlib.Path("/tmp/mylane_v0/pre_spell")
OLD = """    if (a1_175 != 0) {
        if (a1 == base)
            return 0;
        if (a1->unk18F == 0)
            return 0;
    }
"""
E = [
    ("bang", OLD, """    if (a1_175 != 0) {
        if (a1 == base)
            return 0;
        if (!a1->unk18F)
            return 0;
    }
"""),
    ("swap_checks", OLD, """    if (a1_175 != 0) {
        if (a1->unk18F == 0)
            return 0;
        if (a1 == base)
            return 0;
    }
"""),
    ("ptr_local", OLD, """    if (a1_175 != 0) {
        struct Ent *p = a1;
        if (p == base)
            return 0;
        if (p->unk18F == 0)
            return 0;
    }
"""),
    ("byte_cast", OLD, """    if (a1_175 != 0) {
        if (a1 == base)
            return 0;
        if (*(u8 *)((u8 *)a1 + 0x18F) == 0)
            return 0;
    }
"""),
    ("u32_cast", OLD, """    if (a1_175 != 0) {
        if (a1 == base)
            return 0;
        if (*((u8 *)a1 + 0x18F) == 0)
            return 0;
    }
"""),
    ("flag_or", OLD, """    if (a1_175 != 0) {
        if (a1 == base)
            return 0;
        if (a1->unk18F == 0)
            return 0;
    }
    if (0) return 0;
"""),
    ("nested_if", OLD, """    if (a1_175 != 0) {
        if (a1 == base) {
            return 0;
        }
        if (a1->unk18F == 0) {
            return 0;
        }
    }
"""),
    ("a1_175_cond", """    if (a1_175 != 0) {""", """    if (a1_175) {"""),
    ("cd24_after_flag", """    gUnk_0202CD24 = 0x200000;
    flag = 0;""", """    flag = 0;
    gUnk_0202CD24 = 0x200000;"""),
    ("base_after_a1_175", """    a1_175 = a1->unk175;
    base = (struct Ent *)gUnk_0202A550;""", """    base = (struct Ent *)gUnk_0202A550;
    a1_175 = a1->unk175;"""),
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
        print(f"{r['name']:18s} size={str(r.get('size','-')):>5} hunks={str(r.get('hunks','-')):>2} sdiff={str(r.get('sdiff','-')):>5} {r.get('note','')}")