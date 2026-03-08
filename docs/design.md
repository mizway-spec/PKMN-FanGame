# Pokemon Champions: Emerald Edition — Design Document

## Overview

This document describes the full design of the ROM hack, including system
changes, progression flow, difficulty tuning, and post-game content.

---

## Engine Modifications (Base Patches)

### Physical / Special Split
The base Emerald engine uses Gen III move category (type determines
physical/special). We apply the Gen IV Physical/Special split so that
each move has an explicit category field.

**Implementation**: `patches/base/phys_spec_split.ips`

### Updated Type Chart
- Steel no longer resists Ghost or Dark.
- Fairy type added (Gen VI rules).
- Psychic deals neutral to Dark.

**Implementation**: `patches/base/type_chart.ips`

### Reusable TMs
TMs are not consumed on use. HMs can be forgotten via the Move Reminder.

### Exp. Share (All Party)
The Exp. Share item now distributes experience to all party members (Gen VI
behavior), not just the holder.

### Auto-Run
By default, the player runs. Holding B walks.

### Move Reminder
The Move Reminder NPC accepts any non-egg move for any Pokemon that can
legally learn it (including level-up moves from any prior evolution stage).

---

## Progression

### Island Order (Recommended)

| Island        | Champion     | Recommended Level |
|---------------|--------------|-------------------|
| Valor Isle    | Blue         | 55–60             |
| Cinder Isle   | Lance        | 58–62             |
| Crystal Isle  | Steven       | 60–64             |
| Frost Isle    | Cynthia      | 62–66             |
| Tempest Isle  | Iris         | 63–67             |
| Bloom Isle    | Diantha      | 64–68             |
| Sol Isle      | Hau          | 65–69             |
| Crown Isle    | Leon         | 67–71             |
| Obsidian Isle | Geeta        | 68–72             |
| Grand Arena   | Eternal Chmp | 74–80             |

### Wild Card Qualifiers
Before reaching the Champions, the player must complete 3 Wild Card
qualifier battles on Nexum Harbor against random trainers (Lv. 45–52).
These serve as a tutorial for the new mechanics.

### Medal Gating
The boat to the Grand Arena is locked until the player holds all 9 Champion
Medals. Each medal is delivered by the defeated champion with unique dialogue.

---

## Difficulty Modes

Selected at the start of a new game:

| Mode         | AI Level | Trainer Items | Player Items | Set/Switch |
|--------------|----------|---------------|--------------|------------|
| Casual       | 2/8      | No            | Yes          | Switch     |
| Standard     | 4/8      | Yes (full)    | Yes          | Switch     |
| Championship | 7/8      | Yes (full)    | No in battle | Set        |

Championship Mode also enables:
- Champions use optimized EV spreads
- Champions have 31 IVs in all stats (not just attack)
- Final boss Soverion has +10% speed to always outpace level-80 sweepers

---

## New Abilities

### Sovereign's Will
- All status moves used by the ability holder have +1 priority.
- The holder is immune to Intimidate.
- Exclusive to Soverion.

### Champion's Heart
- When the holder's HP drops to or below 50%, all stats raise by 1 stage.
- Triggers once per battle.
- Available to: Nexum Absol, Nexum Breloom.

### Aerial Current
- In sunny weather or during strong winds (weather set by trainer AI): Speed +1.5x.
- Exclusive to Nexum Mantine.

### Nexum Aura
- When sent out, all allies' Special Attack raises by 1 stage.
- Doubles power of Nexum Surge.
- Available to: Nexum Form Pokemon.

---

## New Items

### Golden Crown
- Held item.
- Raises Special Attack by 20% (like Choice Specs, but without locking).
- Cannot be removed by Knock Off or Trick.
- Exclusive to Soverion (given by Eternal Champion after post-game).

### Champion's Sash
- Like Focus Sash, but also prevents one-hit KO moves.
- Craftable from 3x Focus Sashes at the Nexum Craft Shop.

### Nexum Stone
- Evolves Pokemon specific to this hack (e.g., Growlithe → Nexum Arcanine).
- Found in the Nexum Wilds post-game.

---

## Post-Game Content

### Nexum Wilds
An open-world route accessible after defeating the Eternal Champion.
Contains:
- All Nexum Form encounters
- Rare Gen 1–9 Pokemon (Lv. 60–70)
- Soverion encounter (if not caught at Grand Arena)
- Daily gift items from NPCs
- Legendary Pokemon at fixed overworld spots:
  - Regice, Registeel, Regirock (Ice Cave, Lava Den, Rock Quarry sub-areas)
  - Heatran (Valor Volcano basement)
  - Rayquaza (Sky Pillar replica at island center)

### Post-Game Rivals
All three rivals can be re-battled daily with updated Lv. 75–80 teams.
Serena upgrades to 3 Nexum Forms after post-game storyline.

### Tournament Mode
After completing the story, the player can enter a randomized bracket
tournament featuring all 9 Champions + 7 random strong trainers.
Rewards: Battle Points exchangeable for rare items and Nexum Stones.

---

## Music

| Track Name                 | Source / Base           | Used In                        |
|----------------------------|-------------------------|--------------------------------|
| Nexum Harbor               | RSE Slateport remix     | Harbor town                    |
| Champion Arena             | HG/SS Champion music    | All Champion pre-battles       |
| Eternal Champion Battle    | Original composition    | Vance Kael final fight         |
| Soverion Awakening         | Original composition    | Soverion encounter             |
| Nexum Wilds                | RSE Sootopolis remix    | Post-game open world           |
| Ancient Ruins              | DPPt Lost Tower remix   | Frost Isle ruins               |

All custom music is composed in GBA .s tracker format compatible with
pokeemerald's sound driver.

---

## Map Layout Notes

### Nexum Archipelago (Overview)

```
                    [GRAND ARENA]
                         |
     [SOL]---[CROWN]---[HUB]---[OBSIDIAN]---[BLOOM]
               |         |          |
            [TEMPEST]  [HARBOR]  [CINDER]
               |         |          |
            [FROST]   [VALOR]    [CRYSTAL]
```

The Hub (Nexum Harbor) connects to every island via ferry.
Ferries to individual Champion islands are unlocked in order
as the player progresses through the story.

### Grand Arena Architecture

```
Floor 1: Lobby, healing station, rival NPCs
Floor 2: Gauntlet Hall (8 pre-boss trainers)
Floor 3: Vance Kael's Chamber (final boss arena)
Basement: Grand Seal Chamber (Soverion encounter)
```
