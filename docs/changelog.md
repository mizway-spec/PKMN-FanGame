# Changelog

## v0.1.0 — Initial Development Release

### Added
- Full project structure (src/, tools/, patches/, docs/)
- README with complete feature overview, champions roster, and build instructions
- `src/data/pokemon/species_data.h` — BaseStats for Soverion + 5 Nexum Regional Forms
- `src/data/pokemon/learnsets.h` — Full level-up learnsets for all new Pokemon
- `src/data/moves/move_data.h` — 7 new moves (Titan Strike, Crown Beam, Nexum Surge,
  Eternal Roar, Champion's Aura, Tidal Clash, Champion's Fist)
- `src/data/trainers/champion_parties.h` — Full 6-Pokemon teams for all 9 Champions
  + Eternal Champion Vance Kael with legendary ace party
- `src/scripts/intro_sequence.pory` — Full opening cutscene, bedroom scene,
  Prof. Opal meeting, and Nexum Harbor intro scripts
- `src/scripts/champion_battles.pory` — Pre/post-battle dialogue for Blue, Cynthia,
  Leon, and Vance Kael; Soverion legendary encounter sequence
- `src/scripts/rivals.pory` — Three rival arcs: Kira (revenge arc), Milo (ally arc),
  Serena (betrayal/redemption arc) with multiple battle encounters each
- `src/data/maps/nexum_archipelago.h` — Map headers, connections, and wild encounter
  tables for Nexum Harbor, Valor Isle, Frost Isle, Crown Isle, Grand Arena,
  and Nexum Wilds (post-game)
- `Makefile` — Full build system with targets: all, data, scripts, tools, validate,
  run, clean
- `tools/apply_patches.py` — IPS and UPS patch applicator with ordered patch loading
- `tools/validate.py` — Data integrity checker (species, moves, trainer cross-refs,
  PP/power/accuracy validation)
- `tools/gen_trainers.py` — Trainer party binary encoder and IPS patch generator
- `docs/design.md` — Full design document (engine mods, progression, difficulty
  modes, abilities, items, post-game, music, map layout)

### Known Limitations (v0.1.0)
- Build tools (gen_pokemon_data.py, gen_move_data.py, gen_map_data.py,
  gen_script_patch.py) are stubs — full implementations pending
- Sprite assets not yet created (using base game placeholders)
- Custom music tracks not yet composed
- Poryscript compile step requires Go toolchain to build poryscript binary
- No base ROM validation hash check yet (validate_base_rom.py is a stub reference)

### Next Steps (v0.2.0)
- [ ] Implement remaining data patch generators
- [ ] Create Nexum Form sprite sheets (front/back, shiny variants)
- [ ] Create Soverion sprite and cry
- [ ] Implement custom ability effects (Sovereign's Will, Champion's Heart,
      Aerial Current, Nexum Aura) in C
- [ ] Add Tidal Clash and Titan Strike battle effect handlers
- [ ] Compose or source custom music for Grand Arena and Soverion encounter
- [ ] Create all 9 Champion arena tilesets
- [ ] Write remaining champion battle scripts (Steven, Lance, Iris, Diantha,
      Hau, Geeta)
- [ ] Implement difficulty mode selection screen
- [ ] Add post-game Tournament Mode bracket logic
