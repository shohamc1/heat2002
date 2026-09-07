# What can be done before the decomp is finished

The claim "nothing works until 743/743" is wrong, and it conflates two things:

- **A native port** genuinely does need all 743 functions, because a native
  target cannot link Thumb assembly. That gate is real.
- **Everything else** — asset research, tooling, naming, documentation — needs
  none of them, and some of it is *better* done first.

## The 96% is available right now

The ROM is 96% data. That data is readable today, with zero functions
decompiled, because reading it requires a parser rather than a matching build.

A first pass over `baserom.gba` already recovers:

**Track names** at `0x0829EA00`:

```
INFOGRAMES SUPER SPEEDWAY   PHOENIX INTERNATIONAL RACEWAY
KANSAS SPEEDWAY             DARLINGTON RACEWAY
MICHIGAN INTERNATIONAL SPEEDWAY   CRAWFISH RACEWAY
ASPHALT CITY   PURLEY PARK   FUJI PORT   GREAT CANYON
GREEN VALLEY   HOOLEY DOWNS
```

**Drivers** — licensed NASCAR names (`STERLING MARLIN`, `RUSTY WALLACE`,
`JEFF GORDON`, `DALE JARRETT`, `DALE EARNHARDT JR.`, `KEVIN HARVICK`,
`RICKY RUDD`, `STEVE PARK`) alongside what are evidently Crawfish staff
(`CAMERON SHEPPARD`, `MIKE MERREN`, `DARREN JACKSON`, …).

**Teams**: `HENDRICK MOTORSPORTS`, `CHIP GANASSI`, `PENSKE`, `TEAM CRAWFISH`.

**UI and game state** at `0x0806C700`: `PIT STOP NEEDED!`, `ALL TIRES`,
`SPLASH AND DASH`, `DAMAGE:`, `TIRES :`, `GRAVEL`/`GRASS`/`TARMAC`,
`QUALIFYING RESULTS`, `CAREER DECISION`, `YOU'VE BEEN KICKED OFF THE TEAM!`.

Those strings alone establish the career-mode structure, the pit-stop model,
the surface types, and the full track and roster list.

**Compressed assets**: scanning for GBA BIOS decompression headers finds
~1,900 LZ77 (`0x10`) and ~1,900 RLE (`0x30`) candidate blocks outside the code
regions, several decompressing to 60–190 KB. Those are the graphics. The
header scan is heuristic and will include false positives — validating them by
actually decompressing is exactly the kind of work that does not need a single
matched function.

## Why this is worth doing early

Naming is the reason. Right now every function is `sub_08006734` — an address.
A function that loads a table at `0x0829EA00` is unremarkable until you know
that table is the track list; then it is `LoadTrackNames`, and its callers
start to make sense. Asset knowledge turns matching from a mechanical exercise
into something that produces *readable* source.

The recon report is careful to call its `__divsi3`/`memcpy` labels behavioral
inference. Data structure knowledge is how those guesses become facts.

## What genuinely is gated

| Work | Needs full decomp? |
|---|---|
| Asset extraction, format research | no |
| Naming functions from data they touch | no |
| Tooling, tests, docs | no |
| Rewriting individual functions in C | no — one at a time |
| A playable native port | **yes** |
| Modifying game behavior in the matching build | **yes**, by definition |

The last row is worth stating plainly: while the build matches, it *is* retail,
byte for byte. Changing behavior means giving up the match. That is a
deliberate fork, not something to do accidentally.

## Suggested parallel tracks

1. **Matching** — `docs/tickets/`, one function per commit. Currently 0/743.
2. **Asset research** — decompress the LZ77/RLE blocks, map the string tables,
   work out the track/car/audio formats. Feeds names back into track 1.
3. **Native port** — genuinely blocked until track 1 completes.

Tracks 1 and 2 are independent and can run at the same time. Nothing about
track 2 can break `make check`, because it only reads the ROM.
