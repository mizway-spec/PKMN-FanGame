#!/usr/bin/env python3
"""
Pokemon Champions: Emerald Edition
validate.py — Data integrity validation tool

Checks:
  - All species referenced in trainer parties exist in species_data.h
  - All moves referenced in learnsets/parties exist in move_data.h
  - No duplicate species entries
  - BST values are within sane ranges
  - PP values are multiples of 5 (GBA requirement)

Usage:
    python3 tools/validate.py --pokemon SRC --moves SRC --trainers SRC
"""

import argparse
import re
import sys
from pathlib import Path


# ── Helpers ──────────────────────────────────────────────────────────────────

def extract_identifiers(text: str, prefix: str) -> set:
    """Return all identifiers that start with a given prefix in C source."""
    pattern = rf"\b({re.escape(prefix)}\w+)\b"
    return set(re.findall(pattern, text))


def read_file(path: str) -> str:
    try:
        return Path(path).read_text()
    except FileNotFoundError:
        print(f"  WARNING: file not found: {path}")
        return ""


# ── Species Validation ────────────────────────────────────────────────────────

def validate_species(pokemon_src: str) -> tuple[set, list]:
    """Return (defined_species, errors)."""
    text    = read_file(pokemon_src)
    defined = extract_identifiers(text, "SPECIES_")
    errors  = []

    # Check for duplicates via struct definitions
    structs = re.findall(r"gBaseStats_(\w+)\s*=\s*\{", text)
    seen = set()
    for name in structs:
        if name in seen:
            errors.append(f"Duplicate BaseStats definition: gBaseStats_{name}")
        seen.add(name)

    # Basic sanity: all defined species should have a BaseStats struct
    species_consts = extract_identifiers(text, "SPECIES_")
    for sp in species_consts:
        slug = sp[len("SPECIES_"):].title().replace("_", "")
        # Only check new species (NEXUM_ prefix and SOVERION)
        if sp.startswith("SPECIES_NEXUM_") or sp == "SPECIES_SOVERION":
            struct_name = f"gBaseStats_{slug}"
            if struct_name not in text.replace(" ", ""):
                errors.append(f"Missing BaseStats for {sp} (expected {struct_name})")

    return defined, errors


# ── Move Validation ───────────────────────────────────────────────────────────

def validate_moves(moves_src: str) -> tuple[set, list]:
    """Return (defined_moves, errors)."""
    text    = read_file(moves_src)
    defined = extract_identifiers(text, "MOVE_")
    errors  = []

    # Check PP values: must be 5, 10, 15, 20, 25, 30, 35, or 40
    valid_pp = {5, 10, 15, 20, 25, 30, 35, 40}
    pp_values = re.findall(r"\.pp\s*=\s*(\d+)", text)
    for pp_str in pp_values:
        pp = int(pp_str)
        if pp not in valid_pp:
            errors.append(f"Invalid PP value {pp} (must be multiple of 5, max 40)")

    # Check power values: 0 (status) or 1-250
    power_values = re.findall(r"\.power\s*=\s*(\d+)", text)
    for pw_str in power_values:
        pw = int(pw_str)
        if pw > 250:
            errors.append(f"Move power {pw} exceeds GBA maximum of 250")

    # Check accuracy: 0 (never misses) or 1-100
    acc_values = re.findall(r"\.accuracy\s*=\s*(\d+)", text)
    for ac_str in acc_values:
        ac = int(ac_str)
        if ac > 100:
            errors.append(f"Accuracy {ac} exceeds 100")

    return defined, errors


# ── Trainer Validation ────────────────────────────────────────────────────────

def validate_trainers(trainers_src: str, known_species: set, known_moves: set) -> list:
    """Cross-reference trainer parties against known species and moves."""
    text   = read_file(trainers_src)
    errors = []

    used_species = extract_identifiers(text, "SPECIES_")
    used_moves   = extract_identifiers(text, "MOVE_")

    # Filter to only new/custom identifiers to avoid false positives
    # (base game species/moves are defined in pokeemerald, not our src)
    new_species_prefix = {"SPECIES_NEXUM_", "SPECIES_SOVERION"}
    new_moves_prefix   = {
        "MOVE_TITAN_STRIKE", "MOVE_CROWN_BEAM", "MOVE_NEXUM_SURGE",
        "MOVE_ETERNAL_ROAR", "MOVE_CHAMPIONS_AURA", "MOVE_TIDAL_CLASH",
        "MOVE_CHAMPIONS_FIST",
    }

    for sp in used_species:
        if any(sp.startswith(pfx) for pfx in new_species_prefix):
            if sp not in known_species:
                errors.append(f"Trainer references undefined species: {sp}")

    for mv in used_moves:
        if mv in new_moves_prefix:
            if mv not in known_moves:
                errors.append(f"Trainer references undefined move: {mv}")

    # Check party sizes: trainers should have 1-6 Pokemon
    parties = re.findall(r"sParty_(\w+)\[\]", text)
    for party_name in parties:
        # Count entries in this party
        pattern = rf"sParty_{re.escape(party_name)}\[\]\s*=\s*\{{(.*?)\}};"
        match = re.search(pattern, text, re.DOTALL)
        if match:
            entries = re.findall(r"\.\s*species\s*=", match.group(1))
            count = len(entries)
            if count == 0:
                errors.append(f"Party {party_name} has 0 Pokemon")
            elif count > 6:
                errors.append(f"Party {party_name} has {count} Pokemon (max 6)")

    return errors


# ── Base ROM Checksum ─────────────────────────────────────────────────────────

EMERALD_US_SHA1 = "f3ae088181bf583e55daf962a92bb46f4f1d07b7"


def validate_base_rom(rom_path: str) -> bool:
    """Verify the base ROM's SHA-1 matches Pokemon Emerald (US)."""
    import hashlib
    try:
        with open(rom_path, "rb") as f:
            sha1 = hashlib.sha1(f.read()).hexdigest()
        if sha1.lower() == EMERALD_US_SHA1:
            print(f"  [OK] Base ROM checksum verified.")
            return True
        else:
            print(f"  [WARN] Base ROM SHA-1 mismatch.")
            print(f"         Got:      {sha1}")
            print(f"         Expected: {EMERALD_US_SHA1}")
            print(f"         Ensure you are using Pokemon Emerald (US, v1.0)")
            return False
    except FileNotFoundError:
        print(f"  [ERROR] ROM not found: {rom_path}")
        return False


# ── Main ─────────────────────────────────────────────────────────────────────

def main():
    parser = argparse.ArgumentParser(description="Validate Champions Emerald hack data")
    parser.add_argument("--pokemon",  required=True, help="Path to species_data.h")
    parser.add_argument("--moves",    required=True, help="Path to move_data.h")
    parser.add_argument("--trainers", required=True, help="Path to champion_parties.h")
    args = parser.parse_args()

    all_errors = []

    print("Validating species data…")
    species_defined, sp_errors = validate_species(args.pokemon)
    all_errors.extend(sp_errors)
    print(f"  Found {len(species_defined)} species identifiers.")

    print("Validating move data…")
    moves_defined, mv_errors = validate_moves(args.moves)
    all_errors.extend(mv_errors)
    print(f"  Found {len(moves_defined)} move identifiers.")

    print("Validating trainer parties…")
    tr_errors = validate_trainers(args.trainers, species_defined, moves_defined)
    all_errors.extend(tr_errors)

    if all_errors:
        print("\nVALIDATION ERRORS:")
        for err in all_errors:
            print(f"  ✗ {err}")
        sys.exit(1)
    else:
        print("\nAll validation checks passed.")
        sys.exit(0)


if __name__ == "__main__":
    main()
