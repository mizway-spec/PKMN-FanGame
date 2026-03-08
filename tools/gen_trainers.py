#!/usr/bin/env python3
"""
Pokemon Champions: Emerald Edition
gen_trainers.py — Trainer party IPS patch generator

Reads champion_parties.h and generates an IPS patch that overwrites
the trainer data table in the base Pokemon Emerald ROM.

Trainer data memory map (Pokemon Emerald US):
  Trainer table base: 0x310030  (from pokeemerald symbols)
  Each trainer entry: 40 bytes header + variable party data

Usage:
    python3 tools/gen_trainers.py --src src/data/trainers --out patches/data/trainers.ips
"""

import argparse
import os
import re
import struct
from pathlib import Path


# ── GBA / Emerald Constants ──────────────────────────────────────────────────

GBA_ROM_BASE        = 0x08000000
TRAINER_TABLE_ADDR  = 0x310030     # ROM offset (not GBA address)
TRAINER_ENTRY_SIZE  = 40

# Trainer flags
FLAG_DOUBLE         = 0x01
FLAG_CUSTOM_MOVES   = 0x08
FLAG_HELD_ITEM      = 0x02

# Party member sizes (bytes, GBA struct)
PARTY_MON_BASE_SIZE     = 8     # iv, level, species
PARTY_MON_ITEM_SIZE     = 10    # + held item
PARTY_MON_MOVES_SIZE    = 16    # + 4 moves
PARTY_MON_ITEM_MOVES    = 18    # + held item + 4 moves


# ── IPS Writer ────────────────────────────────────────────────────────────────

class IPSWriter:
    def __init__(self):
        self.records = []

    def add_record(self, offset: int, data: bytes):
        """Add a patch record at the given ROM offset."""
        if len(data) == 0:
            return
        self.records.append((offset, data))

    def write(self, path: str):
        with open(path, "wb") as f:
            f.write(b"PATCH")
            for offset, data in self.records:
                f.write(struct.pack(">I", offset)[1:])  # 3-byte big-endian offset
                f.write(struct.pack(">H", len(data)))
                f.write(data)
            f.write(b"EOF")
        print(f"[IPS] Written: {path} ({len(self.records)} records)")


# ── Trainer Data Encoder ──────────────────────────────────────────────────────

# Maps species name → Emerald dex number (partial — new species get IDs above 386)
SPECIES_MAP = {
    # Partial list; full list would be loaded from a symbol table
    "SPECIES_BLASTOISE":    9,
    "SPECIES_PIDGEOT":      18,
    "SPECIES_RHYDON":       112,
    "SPECIES_ARCANINE":     59,
    "SPECIES_GYARADOS":     130,
    "SPECIES_ALAKAZAM":     65,
    "SPECIES_AERODACTYL":   142,
    "SPECIES_DRAGONAIR":    148,
    "SPECIES_DRAGONITE":    149,
    "SPECIES_METAGROSS":    376,
    "SPECIES_SKARMORY":     227,
    "SPECIES_CRADILY":      346,
    "SPECIES_ARMALDO":      348,
    "SPECIES_AGGRON":       306,
    "SPECIES_CLAYDOL":      344,
    "SPECIES_SPIRITOMB":    442,
    "SPECIES_ROSERADE":     407,
    "SPECIES_TOGEKISS":     468,
    "SPECIES_LUCARIO":      448,
    "SPECIES_MILOTIC":      350,
    "SPECIES_GARCHOMP":     445,
    # New species (IDs above 493)
    "SPECIES_SOVERION":     500,
    "SPECIES_NEXUM_ARCANINE": 501,
    "SPECIES_NEXUM_MANTINE":  502,
    "SPECIES_NEXUM_ABSOL":    503,
    "SPECIES_NEXUM_BRELOOM":  504,
    "SPECIES_NEXUM_AGGRON":   505,
}

# Maps move name → Emerald move ID (partial)
MOVE_MAP = {
    "MOVE_POUND":           1,
    "MOVE_BITE":            44,
    "MOVE_SURF":            57,
    "MOVE_EARTHQUAKE":      89,
    "MOVE_PSYCHIC":         94,
    "MOVE_AGILITY":         97,
    "MOVE_HYDRO_PUMP":      56,
    "MOVE_FLAMETHROWER":    53,
    "MOVE_FIRE_BLAST":      126,
    "MOVE_ICE_BEAM":        58,
    "MOVE_OUTRAGE":         200,
    "MOVE_DRAGON_DANCE":    349,
    "MOVE_DRAGON_PULSE":    406,
    "MOVE_WATERFALL":       127,
    "MOVE_CRUNCH":          242,
    "MOVE_METEOR_MASH":     309,
    # New moves
    "MOVE_TITAN_STRIKE":    560,
    "MOVE_CROWN_BEAM":      561,
    "MOVE_NEXUM_SURGE":     562,
    "MOVE_ETERNAL_ROAR":    563,
    "MOVE_CHAMPIONS_AURA":  564,
    "MOVE_TIDAL_CLASH":     565,
    "MOVE_CHAMPIONS_FIST":  566,
}

# Maps item name → Emerald item ID (partial)
ITEM_MAP = {
    "ITEM_NONE":            0,
    "ITEM_SHARP_BEAK":      222,
    "ITEM_SITRUS_BERRY":    253,
    "ITEM_CHOICE_BAND":     220,
    "ITEM_LUM_BERRY":       240,
    "ITEM_LIFE_ORB":        264,
    "ITEM_BLASTOISINITE":   600,   # Mega Stone — custom ID
    "ITEM_FOCUS_SASH":      273,
    "ITEM_EVIOLITE":        538,
    "ITEM_CHOICE_SCARF":    287,
    "ITEM_METAGROSSITE":    610,
    "ITEM_LEFTOVERS":       234,
    "ITEM_ASSAULT_VEST":    579,
    "ITEM_ROCKY_HELMET":    541,
    "ITEM_CHOICE_SPECS":    270,
    "ITEM_YACHE_BERRY":     188,
    "ITEM_GOLDEN_CROWN":    700,   # New item — custom ID
}


def encode_party_member(mon: dict) -> bytes:
    """Encode a single party member to GBA binary (item + custom moves format)."""
    iv      = mon.get("iv", 0) & 0xFF
    level   = mon.get("lvl", 50) & 0xFF
    species = SPECIES_MAP.get(mon.get("species", "SPECIES_NONE"), 0)
    item    = ITEM_MAP.get(mon.get("heldItem", "ITEM_NONE"), 0)
    moves   = [MOVE_MAP.get(m, 0) for m in mon.get("moves", [0, 0, 0, 0])]

    # Pad to 4 moves
    while len(moves) < 4:
        moves.append(0)

    # struct TrainerMonItemCustomMoves layout (pokeemerald):
    #   u16 iv, u8 level, u16 species, u16 heldItem, u16 move[4], u8 padding
    return struct.pack("<HBHHHHHH",
        iv, level, species, item,
        moves[0], moves[1], moves[2], moves[3],
    )


def parse_party_header(src_text: str) -> list:
    """
    Very naive parser: extracts the first TrainerMonItemCustomMoves array
    and returns a list of dicts. Real implementation would use a proper C parser.
    This is suitable for the structured format we use in champion_parties.h.
    """
    parties = []
    # Find all party arrays
    party_blocks = re.finditer(
        r"sParty_(\w+)\[\]\s*=\s*\{(.*?)\};",
        src_text,
        re.DOTALL
    )
    for match in party_blocks:
        name    = match.group(1)
        body    = match.group(2)
        members = []
        # Extract each { .iv=..., .lvl=..., ... } block
        mon_blocks = re.finditer(r"\{([^}]+)\}", body, re.DOTALL)
        for mb in mon_blocks:
            fields = {}
            for field in re.finditer(r"\.(iv|lvl|species|heldItem)\s*=\s*(\S+?),", mb.group(1)):
                key, val = field.group(1), field.group(2)
                fields[key] = val
            # Extract moves array
            moves_match = re.search(r"\.moves\s*=\s*\{([^}]+)\}", mb.group(1))
            if moves_match:
                fields["moves"] = [m.strip() for m in moves_match.group(1).split(",") if m.strip()]
            if "species" in fields:
                members.append(fields)
        parties.append({"name": name, "members": members})
    return parties


def encode_party(members: list) -> bytes:
    return b"".join(encode_party_member(m) for m in members)


# ── Main ─────────────────────────────────────────────────────────────────────

def main():
    parser = argparse.ArgumentParser(description="Generate trainer party IPS patch")
    parser.add_argument("--src", required=True, help="Directory containing champion_parties.h")
    parser.add_argument("--out", required=True, help="Output IPS patch path")
    args = parser.parse_args()

    src_file = Path(args.src) / "champion_parties.h"
    if not src_file.exists():
        print(f"ERROR: {src_file} not found")
        return 1

    src_text = src_file.read_text()
    parties  = parse_party_header(src_text)

    ips = IPSWriter()
    current_offset = TRAINER_TABLE_ADDR

    print(f"[GEN_TRAINERS] Encoding {len(parties)} trainer parties…")
    for party in parties:
        party_bytes = encode_party(party["members"])
        ips.add_record(current_offset, party_bytes)
        print(f"  {party['name']}: {len(party['members'])} Pokemon, {len(party_bytes)} bytes @ 0x{current_offset:06X}")
        current_offset += len(party_bytes) + 4  # +4 alignment padding

    os.makedirs(os.path.dirname(args.out) or ".", exist_ok=True)
    ips.write(args.out)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
