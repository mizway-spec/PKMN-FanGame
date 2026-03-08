# Pokemon Champions: Emerald Edition

> A ROM hack of Pokemon Emerald based on the world of **Pokemon Champions**

---

## Overview

**Pokemon Champions: Emerald Edition** is a ROM hack built on the
[pokeemerald](https://github.com/pret/pokeemerald) decompilation project.
The story takes place in the **Nexum Archipelago** — a floating chain of islands
that hosts the World Pokemon Champions Tournament, where the greatest trainers
from every known region gather to determine the one true World Champion.

---

## Story

You are **Nex** (or your chosen name), a wild-card trainer who receives a
mysterious invitation to the Champions Tournament. No one knows who sent it.
As you battle through the bracket and defeat champions from every region, you
uncover a conspiracy: the tournament is being used to harvest championship
energy — raw power emitted when elite trainers clash — to revive an ancient
Pokemon known only as **Soverion**, the Eternal Sovereign, who once ruled all
Pokemon as their undisputed king.

### Act Structure

| Act | Focus |
|-----|-------|
| I   | Arrival at Nexum; Wild Card Qualifiers; meet rival trainers |
| II  | Round of Champions — battle champions from Kanto → Galar |
| III | Conspiracy revealed; battle the Tournament Director |
| IV  | Soverion awakens; legendary showdown |
| V   | Epilogue — become the first true World Champion |

---

## Features

- **New region**: The Nexum Archipelago (8 islands + central arena)
- **Champion Gauntlet**: Battle story-accurate Champions from every mainline region
- **All Pokemon**: Every species from Gen 1–9 available (wild/trade/gift)
- **New Pokemon**: Nexum Regional Forms + the Legendary **Soverion**
- **New Moves**: Championship-exclusive moves (Titan Strike, Crown Beam, etc.)
- **New Abilities**: Sovereign's Will, Champion's Heart, Nexum Aura
- **Difficulty Modes**: Casual, Standard, Championship (no items in battle)
- **Rival System**: 3 rival wild-card trainers with full story arcs
- **Quality-of-Life**: Physical/Special split, updated type chart, reusable TMs

---

## Champions Roster

| Region  | Champion       | Signature Pokemon  | Arena Island     |
|---------|----------------|--------------------|------------------|
| Kanto   | Blue           | Mega Blastoise     | Valor Isle       |
| Johto   | Lance          | Dragonite          | Cinder Isle      |
| Hoenn   | Steven Stone   | Mega Metagross     | Crystal Isle     |
| Sinnoh  | Cynthia        | Garchomp           | Frost Isle       |
| Unova   | Iris           | Haxorus            | Tempest Isle     |
| Kalos   | Diantha        | Mega Gardevoir     | Bloom Isle       |
| Alola   | Hau            | Alolan Raichu      | Sol Isle         |
| Galar   | Leon           | Charizard          | Crown Isle       |
| Paldea  | Geeta          | Glimmora           | Obsidian Isle    |
| Nexum   | ??? (Eternal)  | Soverion           | Grand Arena      |

---

## New Pokemon

### Soverion (Legendary)

```
Type:    Psychic / Dragon
BST:     720
Ability: Sovereign's Will (all status moves used by Soverion have +1 priority;
         immune to Intimidate)
Notable: Cannot be caught until post-game; full legendary encounter sequence
```

### Nexum Regional Forms

| Pokemon       | Type Change          | Notable Change                        |
|---------------|----------------------|---------------------------------------|
| Nexum-Arcanine| Fire / Dragon        | Gains Dragon Rush; higher Sp. Atk     |
| Nexum-Mantine | Water / Flying (unchanged) | New ability: Aerial Current (boosts Speed in sun/wind) |
| Nexum-Absol   | Dark / Psychic       | Gains Calm Mind; higher Sp. Atk       |
| Nexum-Breloom | Grass / Fighting (unchanged) | New move: Champion's Fist (High Jump Kick clone, 110BP) |
| Nexum-Aggron  | Steel / Water        | Loses Rock typing; high HP, Iron Defense |

---

## New Moves

| Move            | Type     | Category | BP  | PP | Effect                                      |
|-----------------|----------|----------|-----|----|---------------------------------------------|
| Titan Strike    | Fighting | Physical | 120 | 5  | User takes 1/4 recoil; breaks screens       |
| Crown Beam      | Psychic  | Special  | 95  | 10 | 30% chance to raise user's Sp. Atk by 1    |
| Nexum Surge     | Electric | Special  | 85  | 10 | Sets Electric Terrain for 5 turns          |
| Eternal Roar    | Dragon   | Special  | 110 | 5  | Soverion's signature move; bypasses protect|
| Champion's Aura | Normal   | Status  | —   | 5  | Raises all stats by 1 (like Geomancy but all)|
| Tidal Clash     | Water    | Physical | 80  | 15 | Double power if opponent used special move  |

---

## Build Instructions

### Prerequisites

```bash
# Ubuntu / Debian
sudo apt install build-essential binutils-arm-none-eabi git libpng-dev

# macOS (Homebrew)
brew install --cask gcc-arm-embedded
brew install libpng

# Windows
# Use WSL2 with Ubuntu and follow the Ubuntu instructions above
```

### Setup

```bash
# 1. Clone this repository
git clone https://github.com/YOUR_USERNAME/PKMN-FanGame.git
cd PKMN-FanGame

# 2. Initialize pokeemerald submodule
git submodule update --init --recursive

# 3. Place your legally-obtained Pokemon Emerald ROM in the project root
#    as: pokemon_emerald.gba
cp /path/to/your/pokemon_emerald.gba ./base_rom/pokemon_emerald.gba

# 4. Install build tools
make tools

# 5. Apply hack patches
python3 tools/apply_patches.py

# 6. Build the ROM
make -j$(nproc)

# Output: champions_emerald.gba
```

### Development

```bash
# Apply only data changes (faster iteration)
make data

# Apply only script changes
make scripts

# Run in mGBA (if installed)
make run
```

---

## Project Structure

```
PKMN-FanGame/
├── README.md
├── Makefile
├── base_rom/               # Place base Pokemon Emerald ROM here
├── src/
│   ├── data/
│   │   ├── pokemon/        # Species data, base stats, learnsets
│   │   ├── trainers/       # Trainer parties and AI scripts
│   │   ├── moves/          # Move data and effects
│   │   ├── items/          # Item definitions
│   │   └── maps/           # Map headers and connections
│   ├── scripts/            # MapScript .inc files (NPC dialogue, events)
│   ├── graphics/
│   │   ├── sprites/        # Pokemon and trainer sprites
│   │   ├── tilesets/       # Map tilesets
│   │   └── ui/             # Title screen, menus
│   └── audio/              # Music and sound effects
├── include/                # Header files
├── tools/
│   ├── apply_patches.py    # Master patch application script
│   ├── validate.py         # Data validation tool
│   └── gen_trainers.py     # Trainer party generator
├── patches/
│   ├── base/               # Core engine patches
│   ├── data/               # Data patches (auto-generated)
│   └── scripts/            # Script patches
└── docs/
    ├── design.md           # Full design document
    ├── lore.md             # World lore and story details
    ├── champions.md        # Champion battle strategies
    └── changelog.md        # Version history
```

---

## Credits

- **Base Engine**: pokeemerald decompilation project (pret team)
- **Hack Design**: Pokemon Champions: Emerald Edition team
- **Inspiration**: Pokemon Champions (Nintendo/Game Freak, upcoming)
- **Tools Used**: Porymap, Poryscript, pretmap

---

## Legal

This project is a fan-made, non-commercial ROM hack for educational and
entertainment purposes. It requires a legally-obtained copy of Pokemon Emerald
(GBA) to build. No ROM files are distributed. Pokemon and all related names are
trademarks of Nintendo / Creatures Inc. / GAME FREAK inc.
