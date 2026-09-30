"""The track geometry: lanes, waypoints and walls (issue #4 part 2).

Three regions of the ROM hold the per-track geometry the AI and
collision code reads, all of it built from the editable files of the
"track" asset type (scripts/assets.py):

- 0x08365348-0x083671C0  struct TrackSeg per track (the waypoint gates)
- 0x083682BC-0x083C9574  lane groups (u16 points, LaneSeg tables, cell
                         indexes) + per-track length words; 42 distinct
                         groups — tracks share them (track 7 uses 6's)
- 0x083CA0C4-0x083FD91C  walls per track (vertices, WallRec tables, cell
                         indexes), in ROM order T0, T2, T1, T3..T11

Each track's .tmx carries three object layers over the same map as its
tiles, in world coordinates (one unit = one pixel; the collision grid is
48x48 cells of 128 units):

- "waypoints": one 2-point polyline per struct TrackSeg, in order, with
  a "kind" property (0 plain, 1 start/finish — the last record, 2
  checkpoint) and a "countdown" property (0 everywhere in the retail
  ROM; the game adds its own at runtime).
- "lanes": one polyline per distinct lane the track owns, named by its
  lane slot; the points are the lane's u16 (x, z) list, including the
  trailing lap-start point no segment references. A "skips" property
  (e.g. "101-103") records the one authored non-sequential link.
- "walls": one polyline per wall chain. The wall records are the
  chain's consecutive point pairs, in order; the vertex list is the
  chains' points concatenated (the authoring tool restarted it at every
  chain, keeping duplicate coordinates — verified on all 12 tracks). A
  "steer" property holds the per-record steerAngle bytes,
  comma-separated.

Everything else regenerates at build time — the derivations and their
roundings are the ones `verify` checks against baserom.gba, byte-exact
on every record of every track:

- WallRec: the 1.15 unit normal trunc_toward_zero(32767*(dz,-dx)/sqrt)
  with sqrt in double precision, its side fixed by the authored vertex
  order (the rotation whose quantised angle sits nearer the authored
  steerAngle); the AABB of the two vertices; steerAngleOpp = steer+0x80
  and edgeAngle (unk1E) = steer+0x40; a zero pad byte.
- LaneSeg: the point chain (each point to the next, the last wrapping
  to 0), cumulative startDist/endDist over isqrt(len2),
  invLen = 65536/isqrt(len2), scaleX/Z = C-trunc(65536/d) (0 when the
  component is 0), projScale = min(255, 65536//len2) — except three
  records the authoring tool wrote differently, kept in the per-track
  "lane_fixups" file of (record, value) pairs the build applies after
  the formula. The terminator record's leading 16 bytes are a constant
  and its last u32 an opaque authoring-tool pointer, kept per lane in
  the "lane_terms" file. Each lane's total length also lands in its
  word of "lane_lengths", the word gLaneLengthPtrs points at.
- The spatial indexes (cellGrid + cellLists, walls and lanes): a 48x48
  grid of 128-unit cells, each the offset of a terminated list of wall
  or lane-segment indices. The retail membership rules aren't
  recoverable exactly, so "wall_cells" and "lane_cells_N" keep the
  retail indexes, and "cell_index_crc" records the CRC-32 of the
  geometry each was built for. When the geometry still matches, the
  build uses the retail index; when it changed, the build rebuilds it:
  walls by bounding box grown 64 units (a superset of every retail wall
  index), lanes by nearest segment (see lane_cell_index).

Usage:
    python3 scripts/track_geometry.py verify
"""

import json
import math
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ROM_BASE = 0x08000000

LANE_TERM = bytes.fromhex("ffffff00ff00ff00ff000000ff000000")


def trunc_div(n, d):
    """C integer division: truncate toward zero (Python // floors)."""
    q = abs(n) // abs(d)
    return -q if (n < 0) != (d < 0) else q


def atan_index(x, z):
    """The direction (x, z) quantised the way gAtan2Table's builder did:
    1/256 turns. Only the wall normal's side test uses it."""
    return int(math.atan2(z, x) * 128 / math.pi) & 0xFF


def circ_dist(a, b):
    d = abs((a - b) & 0xFF)
    return min(d, 256 - d)


def wall_normal(v0, v1, steer):
    """The 1.15 unit normal of the wall v0->v1, its side fixed by the
    authored vertex order: of the two rotations, the one whose
    quantised angle sits nearer the authored steerAngle is the stored
    one (the tool authored steerAngle from the normal it stored)."""
    dx, dz = v1[0] - v0[0], v1[1] - v0[1]
    root = math.sqrt(dx * dx + dz * dz)
    # the tool divided the real 32767*(dz, -dx) by the double sqrt and
    # truncated toward zero (integer division of the scaled values,
    # or floor/round, all fail — see the report)
    nx = int(32767 * dz / root) if root else 0
    nz = int(32767 * -dx / root) if root else 0
    d0 = circ_dist(atan_index(nx, nz), steer)
    d1 = circ_dist(atan_index(-nx, -nz), steer)
    return (-nx, -nz) if d1 < d0 else (nx, nz)


def pack_wall_rec(i0, i1, v0, v1, steer, nx, nz):
    """One 0x20-byte WallRec: the vertex indices and steerAngle are the
    data, the other 18 bytes derive from the vertices."""
    x0, z0 = v0
    x1, z1 = v1
    return struct.pack("<HH2i4i4B", i0, i1, nx, nz,
                       min(x0, x1), max(x0, x1), min(z0, z1), max(z0, z1),
                       steer, (steer + 0x80) & 0xFF, (steer + 0x40) & 0xFF,
                       0)


def lane_chain(n, skips):
    """A lane's (a, b) links from its skips — pairs (from, to) of an
    authored jump: each point 0..n-2 that no jump bypasses links to the
    next such point, the last linking back to point 0. A bypassed point
    appears in no record; the trailing lap-start point n-1 never links."""
    jumps = dict(skips)
    bypassed = {p for f, t in skips for p in range(f + 1, t)}
    visited = [a for a in range(n - 1) if a not in bypassed]
    out = []
    for i, a in enumerate(visited):
        if a in jumps:
            out.append((a, jumps[a]))
        else:
            out.append((a, visited[i + 1] if i + 1 < len(visited) else 0))
    return out


def pack_lane_segs(points, skips, fixups, term):
    """A lane's 0x14-byte records from its point list, plus the
    terminator record (constant head, authored u32). `fixups` maps a
    record index to its authored projScale."""
    out = bytearray()
    dist = 0
    for a, b in lane_chain(len(points), skips):
        dx = points[b][0] - points[a][0]
        dz = points[b][1] - points[a][1]
        len2 = dx * dx + dz * dz
        length = math.isqrt(len2)
        proj = fixups.get(len(out) // 0x14, min(255, 65536 // len2))
        out += struct.pack("<4BHH3i", a, b, proj, 0,
                           dist, (dist + length) & 0xFFFF,
                           (65536 // length) if length else 0,
                           trunc_div(65536, dx) if dx else 0,
                           trunc_div(65536, dz) if dz else 0)
        dist += length
    out += LANE_TERM + struct.pack("<I", term)
    return bytes(out), dist & 0xFFFF


def pack_seg(c1, c2, kind, countdown):
    """One 0x18-byte struct TrackSeg from its two corners."""
    return struct.pack("<4iH2xB3x", c1[0], c1[1], c2[0], c2[1], kind,
                       countdown)


# The cell indexes: a 48x48 grid of 128-unit cells, each holding the
# offset of a terminated index list in a pool of shared lists. The retail
# membership rules aren't recoverable exactly, so an edited track's
# indexes are rebuilt with rules that list at least what the game needs.
CELL, GRID = 128, 48


def seg_rect_dist(a, b, x0, y0, x1, y1):
    """Euclidean distance from segment ab to the rectangle [x0,x1]x[y0,y1]."""
    def inside(p):
        return x0 <= p[0] <= x1 and y0 <= p[1] <= y1

    def orient(p, q, r):
        return (q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0])

    def cross(p, q, r, t):
        return (orient(p, q, r) * orient(p, q, t) <= 0
                and orient(r, t, p) * orient(r, t, q) <= 0)

    def pt_seg(p, a, b):
        dx, dy = b[0] - a[0], b[1] - a[1]
        n = dx * dx + dy * dy
        t = max(0.0, min(1.0, ((p[0] - a[0]) * dx + (p[1] - a[1]) * dy) / n)) if n else 0.0
        return math.hypot(p[0] - a[0] - t * dx, p[1] - a[1] - t * dy)

    if inside(a) or inside(b):
        return 0.0
    corners = [(x0, y0), (x1, y0), (x1, y1), (x0, y1)]
    if any(cross(a, b, corners[i], corners[(i + 1) % 4]) for i in range(4)):
        return 0.0
    return min(min(pt_seg(c, a, b) for c in corners),
               min(math.hypot(max(x0 - p[0], 0, p[0] - x1),
                              max(y0 - p[1], 0, p[1] - y1)) for p in (a, b)))


def pack_cell_index(cells, fmt, end):
    """(lists, grid) for per-cell index lists: each distinct list stored
    once in the pool with its terminator, the grid giving each cell's
    offset in pool units (fmt's size: u16 for walls, bytes for lanes)."""
    pool, at, grid = [], {}, []
    for lst in cells:
        key = tuple(lst)
        if key not in at:
            at[key] = len(pool)
            pool += list(key) + [end]
        grid.append(at[key])
    if len(pool) > 0xFFFF:
        sys.exit("a cell index pool outgrew its u16 offsets")
    return (struct.pack(f"<{len(pool)}{fmt}", *pool),
            struct.pack(f"<{len(grid)}H", *grid))


def wall_cell_index(verts, pairs):
    """Every wall whose bounding box, grown by 64 units, touches the cell:
    a superset of every retail wall index (checked on all 12 tracks)."""
    cells = []
    for c in range(GRID * GRID):
        x0, y0 = (c % GRID) * CELL, (c // GRID) * CELL
        cells.append([i for i, (a, b) in enumerate(pairs)
                      if min(verts[a][0], verts[b][0]) - 64 <= x0 + CELL
                      and max(verts[a][0], verts[b][0]) + 64 >= x0
                      and min(verts[a][1], verts[b][1]) - 64 <= y0 + CELL
                      and max(verts[a][1], verts[b][1]) + 64 >= y0])
    return pack_cell_index(cells, "H", 0xFFFF)


def lane_cell_index(points, pairs):
    """For each cell, every lane segment that can be the nearest one to
    some point in the cell, which is what the AI's lookup needs: a 5x5
    grid of samples 32 units apart, each keeping the segments within
    32*sqrt(2) of its own nearest distance. Any point in the cell lies
    within 16*sqrt(2) of a sample, so its nearest segment is at most
    twice that further from the sample than the sample's own nearest,
    and is always kept. Lists are never empty, as in retail."""
    if len(pairs) > 0xFF:
        sys.exit(f"a lane has {len(pairs)} segments; its cell lists hold "
                 "u8 indices, so 255 is the most")
    def pt_seg(p, a, b):
        dx, dy = b[0] - a[0], b[1] - a[1]
        n = dx * dx + dy * dy
        t = max(0.0, min(1.0, ((p[0] - a[0]) * dx + (p[1] - a[1]) * dy) / n)) if n else 0.0
        return math.hypot(p[0] - a[0] - t * dx, p[1] - a[1] - t * dy)
    segs = [(points[a], points[b]) for a, b in pairs]
    step = CELL // 4
    slack = math.ceil(step * math.sqrt(2)) + 1
    reach = math.ceil(CELL * math.sqrt(2)) + 1
    cells = []
    for c in range(GRID * GRID):
        x0, y0 = (c % GRID) * CELL, (c // GRID) * CELL
        d = [seg_rect_dist(a, b, x0, y0, x0 + CELL, y0 + CELL) for a, b in segs]
        near = min(d)
        # candidates: a segment beyond the cell's nearest plus one diagonal
        # is never the nearest for any point in the cell
        cand = [i for i, v in enumerate(d) if v <= near + reach]
        keep = set()
        for sy in range(5):
            for sx in range(5):
                q = (x0 + sx * step, y0 + sy * step)
                dq = {i: pt_seg(q, *segs[i]) for i in cand}
                best = min(dq.values())
                keep.update(i for i, v in dq.items() if v <= best + slack)
        cells.append(sorted(keep))
    return pack_cell_index(cells, "B", 0xFF)


def verify():
    """Check every derivation against baserom.gba, record by record."""
    rom = (ROOT / "baserom.gba").read_bytes()

    def at(addr, size):
        return rom[addr - ROM_BASE:addr - ROM_BASE + size]

    layout = json.loads((ROOT / "assets" / "tracks.json").read_text())
    # {track index: {part: (ROM address, size)}}, the build's own layout
    parts = {}
    for a in layout["assets"]:
        opts = a.get("options", {})
        if "part" in opts:
            track = layout["tracks"][opts["track"]]["index"]
            parts.setdefault(track, {})[opts["part"]] = \
                (int(a["start"], 16), a["size"])

    bad = []
    fixups_all = {}
    # walls
    for track, p in sorted(parts.items()):
        if "wall_recs" not in p:
            continue
        verts_at, verts_size = p["wall_verts"]
        words = struct.unpack_from(f"<{verts_size // 4}i", rom,
                                   verts_at - ROM_BASE)
        verts = list(zip(words[::2], words[1::2]))
        recs = at(*p["wall_recs"])
        nc = len(recs) // 0x20
        for i in range(nc):
            v0, v1, steer = (struct.unpack_from("<2H", recs, i * 0x20)
                             + (recs[i * 0x20 + 0x1C],))
            want = recs[i * 0x20:(i + 1) * 0x20]
            got = pack_wall_rec(v0, v1, verts[v0], verts[v1], steer,
                                *wall_normal(verts[v0], verts[v1], steer))
            if got != want:
                bad.append(("wall", track, i, want.hex(), got.hex()))
    # lanes
    for track, slot, p in sorted((track, int(k[len("lane_segs_"):]), p)
                                 for track, p in parts.items()
                                 for k in p if k.startswith("lane_segs_")):
        points_at, points_size = p[f"lane_points_{slot}"]
        n = points_size // 4
        words = struct.unpack_from(f"<{n * 2}H", rom, points_at - ROM_BASE)
        points = list(zip(words[::2], words[1::2]))
        want = at(*p[f"lane_segs_{slot}"])
        nrec = len(want) // 0x14 - 1  # minus the terminator
        # the ROM's own chain: the record pairs, from which the skips
        # come (a link whose b is not the next visited point)
        pairs = [struct.unpack_from("<2B", want, i * 0x14)
                 for i in range(nrec)]
        skips = [(a, b) for a, b in pairs
                 if b != a + 1 and b != 0 and a + 1 < n - 1]
        fixups = {}
        term = struct.unpack_from("<I", want, nrec * 0x14 + 16)[0]
        got, length = pack_lane_segs(points, skips, fixups, term)
        for i in range(nrec):
            w = want[i * 0x14:(i + 1) * 0x14]
            gg = got[i * 0x14:(i + 1) * 0x14]
            if w[:2] == gg[:2] and w[2] != gg[2]:
                fixups[i] = w[2]  # the authored projScale exceptions
        got, _ = pack_lane_segs(points, skips, fixups, term)
        if got != want:
            for i in range(len(want) // 0x14):
                if got[i * 0x14:(i + 1) * 0x14] != \
                        want[i * 0x14:(i + 1) * 0x14]:
                    bad.append(("lane", track, slot, i,
                                want[i * 0x14:(i + 1) * 0x14].hex(),
                                got[i * 0x14:(i + 1) * 0x14].hex()))
        if skips:
            print(f"  lane skips track {track} slot {slot}: {skips}")
        if fixups:
            fixups_all.setdefault(track, []).append((slot, fixups))
    # segments
    for track, p in sorted(parts.items()):
        if "segs" not in p:
            continue
        want = at(*p["segs"])
        got = b""
        for i in range(len(want) // 0x18):
            w = want[i * 0x18:(i + 1) * 0x18]
            got += pack_seg(struct.unpack_from("<2i", w, 0),
                            struct.unpack_from("<2i", w, 8),
                            struct.unpack_from("<H", w, 16)[0], w[0x14])
        if got != want:
            bad.append(("segs", track, len(want)))
    if bad:
        for b in bad[:10]:
            print("MISMATCH", b)
        sys.exit(f"{len(bad)} mismatches")
    print("every derivation matches the ROM byte for byte")
    for track, groups in sorted(fixups_all.items()):
        for slot, fx in groups:
            print(f"  lane fixups track {track} slot {slot}: {fx}")


if __name__ == "__main__":
    if len(sys.argv) == 2 and sys.argv[1] == "verify":
        verify()
    else:
        sys.exit(__doc__)
