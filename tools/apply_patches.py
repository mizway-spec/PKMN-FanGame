#!/usr/bin/env python3
"""
Pokemon Champions: Emerald Edition
apply_patches.py — Master IPS/UPS patch application script

Applies all patches in the patches/ directory to the base ROM in order:
  1. patches/base/     — Core engine modifications
  2. patches/data/     — Pokemon, move, trainer, map data
  3. patches/scripts/  — Event scripts and NPC dialogue

Usage:
    python3 tools/apply_patches.py [--base BASE_ROM] [--patches DIR] [--output OUT]
"""

import argparse
import os
import sys
import shutil
import struct
from pathlib import Path


# ── IPS Patch Application ──────────────────────────────────────────────────

IPS_MAGIC  = b"PATCH"
IPS_EOF    = b"EOF"
IPS_TRUNC  = 5      # RLE record has 5 bytes before count


def apply_ips(rom_data: bytearray, patch_path: str) -> bytearray:
    """Apply a single IPS patch file to rom_data. Returns modified bytearray."""
    with open(patch_path, "rb") as f:
        data = f.read()

    if data[:5] != IPS_MAGIC:
        raise ValueError(f"{patch_path}: Not a valid IPS patch (bad magic)")

    offset = 5
    while offset < len(data):
        # Check for EOF marker
        if data[offset:offset + 3] == IPS_EOF:
            break

        # Read record: 3-byte offset, 2-byte size
        rec_offset = struct.unpack(">I", b"\x00" + data[offset:offset + 3])[0]
        rec_size   = struct.unpack(">H", data[offset + 3:offset + 5])[0]
        offset += 5

        if rec_size == 0:
            # RLE record: 2-byte count + 1-byte fill value
            rle_count = struct.unpack(">H", data[offset:offset + 2])[0]
            rle_byte  = data[offset + 2]
            offset += 3
            # Extend ROM if necessary
            needed = rec_offset + rle_count
            if len(rom_data) < needed:
                rom_data.extend(b"\xff" * (needed - len(rom_data)))
            rom_data[rec_offset:rec_offset + rle_count] = bytes([rle_byte] * rle_count)
        else:
            # Normal record
            payload = data[offset:offset + rec_size]
            offset += rec_size
            needed = rec_offset + rec_size
            if len(rom_data) < needed:
                rom_data.extend(b"\xff" * (needed - len(rom_data)))
            rom_data[rec_offset:rec_offset + rec_size] = payload

    return rom_data


# ── UPS Patch Application ──────────────────────────────────────────────────

def apply_ups(rom_data: bytearray, patch_path: str) -> bytearray:
    """Apply a UPS patch. Used for larger binary diffs."""
    with open(patch_path, "rb") as f:
        patch = f.read()

    if patch[:4] != b"UPS1":
        raise ValueError(f"{patch_path}: Not a valid UPS patch")

    offset = 4

    def read_vuint():
        nonlocal offset
        result = 0
        shift  = 0
        while True:
            byte = patch[offset]
            offset += 1
            if byte & 0x80:
                result += (byte & 0x7F) << shift
                break
            result += (byte | 0x80) << shift
            shift += 7
        return result

    _src_size = read_vuint()  # noqa: source size (we trust the base ROM check)
    _dst_size = read_vuint()  # noqa: destination size

    out = bytearray(rom_data)
    out_offset = 0

    while offset < len(patch) - 12:   # last 12 bytes are CRC32 checksums
        skip = read_vuint()
        out_offset += skip
        while patch[offset] != 0x00:
            if out_offset < len(out):
                out[out_offset] ^= patch[offset]
            else:
                out.append(patch[offset])
            out_offset += 1
            offset += 1
        offset += 1  # consume the 0x00 terminator
        out_offset += 1

    return out


# ── Patch Application Order ─────────────────────────────────────────────────

PATCH_ORDER = [
    "base",
    "data",
    "scripts",
]


def collect_patches(patches_dir: str) -> list:
    """Return ordered list of (patch_type, path) tuples."""
    result = []
    for category in PATCH_ORDER:
        cat_dir = Path(patches_dir) / category
        if not cat_dir.exists():
            continue
        # Sort within category so patches apply deterministically
        for patch_file in sorted(cat_dir.iterdir()):
            if patch_file.suffix in (".ips", ".ups"):
                result.append((patch_file.suffix[1:], str(patch_file)))
    return result


def apply_all(base_rom: str, patches_dir: str, output: str):
    print(f"[PATCH] Loading base ROM: {base_rom}")
    with open(base_rom, "rb") as f:
        rom = bytearray(f.read())

    patches = collect_patches(patches_dir)
    if not patches:
        print("[PATCH] Warning: no patch files found. Output = copy of base ROM.")

    for patch_type, patch_path in patches:
        name = Path(patch_path).name
        print(f"[PATCH]   Applying {patch_type.upper()}: {name}")
        if patch_type == "ips":
            rom = apply_ips(rom, patch_path)
        elif patch_type == "ups":
            rom = apply_ups(rom, patch_path)
        else:
            print(f"[PATCH]   WARNING: Unknown patch type '{patch_type}', skipping.")

    with open(output, "wb") as f:
        f.write(rom)
    print(f"[PATCH] Output written: {output} ({len(rom):,} bytes)")


# ── Entry Point ──────────────────────────────────────────────────────────────

def main():
    parser = argparse.ArgumentParser(
        description="Apply IPS/UPS patches to Pokemon Emerald base ROM"
    )
    parser.add_argument(
        "--base",
        default="base_rom/pokemon_emerald.gba",
        help="Path to base ROM (default: base_rom/pokemon_emerald.gba)",
    )
    parser.add_argument(
        "--patches",
        default="patches",
        help="Directory containing patch subdirectories (default: patches/)",
    )
    parser.add_argument(
        "--output",
        default="champions_emerald.gba",
        help="Output ROM path (default: champions_emerald.gba)",
    )
    args = parser.parse_args()

    if not os.path.isfile(args.base):
        print(f"ERROR: Base ROM not found: {args.base}", file=sys.stderr)
        sys.exit(1)

    os.makedirs(os.path.dirname(args.output) or ".", exist_ok=True)
    apply_all(args.base, args.patches, args.output)


if __name__ == "__main__":
    main()
