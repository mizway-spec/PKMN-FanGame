/*
 * Pokemon Champions: Emerald Edition
 * Master Constants Header
 *
 * Defines all new IDs that extend the base Emerald game.
 * Include this after all base pokeemerald headers.
 */

#ifndef GUARD_CONSTANTS_CHAMPIONS_EMERALD_H
#define GUARD_CONSTANTS_CHAMPIONS_EMERALD_H

/* ── New Species IDs ─────────────────────────────────────────────────────── */
/* Appended after Gen III dex (386) and all Gen IV–IX additions up to 493    */
#define SPECIES_SOVERION            500
#define SPECIES_NEXUM_ARCANINE      501
#define SPECIES_NEXUM_MANTINE       502
#define SPECIES_NEXUM_ABSOL         503
#define SPECIES_NEXUM_BRELOOM       504
#define SPECIES_NEXUM_AGGRON        505

/* ── New Move IDs ────────────────────────────────────────────────────────── */
/* Appended after highest base Emerald move ID                               */
#define MOVE_TITAN_STRIKE           560
#define MOVE_CROWN_BEAM             561
#define MOVE_NEXUM_SURGE            562
#define MOVE_ETERNAL_ROAR           563
#define MOVE_CHAMPIONS_AURA         564
#define MOVE_TIDAL_CLASH            565
#define MOVE_CHAMPIONS_FIST         566

/* ── New Ability IDs ─────────────────────────────────────────────────────── */
#define ABILITY_SOVEREIGNS_WILL     165
#define ABILITY_CHAMPIONS_HEART     166
#define ABILITY_AERIAL_CURRENT      167
#define ABILITY_NEXUM_AURA          168

/* ── New Item IDs ────────────────────────────────────────────────────────── */
#define ITEM_GOLDEN_CROWN           700
#define ITEM_CHAMPIONS_SASH         701
#define ITEM_NEXUM_STONE            702
#define ITEM_NEXUM_POKEDEX          703     /* key item */

/* Mega Stones (custom IDs for stones not in Emerald) */
#define ITEM_BLASTOISINITE          600
#define ITEM_METAGROSSITE           601
#define ITEM_GARDEVOIRITE           602
#define ITEM_AGGRONITE              603
#define ITEM_CHARIZARDITE_X         604
#define ITEM_CHARIZARDITE_Y         605

/* ── Story Variables ─────────────────────────────────────────────────────── */
#define VAR_GAME_CHAPTER            0x4080
#define VAR_INVITATION_READ         0x4081
#define VAR_INVITATION_OPENED       0x4082
#define VAR_STORY_STAGE             0x4083
#define VAR_MEDALS_COUNT            0x4084
#define VAR_SOVERION_STAGE          0x4085

/* Champion defeat flags */
#define VAR_BLUE_DEFEATED           0x4090
#define VAR_LANCE_DEFEATED          0x4091
#define VAR_STEVEN_DEFEATED         0x4092
#define VAR_CYNTHIA_DEFEATED        0x4093
#define VAR_IRIS_DEFEATED           0x4094
#define VAR_DIANTHA_DEFEATED        0x4095
#define VAR_HAU_DEFEATED            0x4096
#define VAR_LEON_DEFEATED           0x4097
#define VAR_GEETA_DEFEATED          0x4098
#define VAR_ETERNAL_DEFEATED        0x4099

/* Rival stage trackers */
#define VAR_KIRA_STAGE              0x40A0
#define VAR_MILO_STAGE              0x40A1
#define VAR_SERENA_STAGE            0x40A2

/* ── Story Stage Constants ───────────────────────────────────────────────── */
#define STAGE_START                 0
#define STAGE_RECEIVED_INVITATION   1
#define STAGE_MET_OPAL              2
#define STAGE_QUALIFIERS_DONE       3
#define STAGE_FIRST_MEDAL           4
#define STAGE_CONSPIRACY_REVEALED   5
#define STAGE_KIRA_ALLY             6
#define STAGE_MILO_ALLY             7
#define STAGE_SERENA_ALLY           8
#define STAGE_ALL_MEDALS            9
#define STAGE_ETERNAL_DEFEATED      10
#define STAGE_SOVERION_RISING       11
#define STAGE_COMPLETE              12

/* ── Flags ───────────────────────────────────────────────────────────────── */
#define FLAG_VALOR_ISLE_CLEARED     0x0900
#define FLAG_CINDER_ISLE_CLEARED    0x0901
#define FLAG_CRYSTAL_ISLE_CLEARED   0x0902
#define FLAG_FROST_ISLE_CLEARED     0x0903
#define FLAG_TEMPEST_ISLE_CLEARED   0x0904
#define FLAG_BLOOM_ISLE_CLEARED     0x0905
#define FLAG_SOL_ISLE_CLEARED       0x0906
#define FLAG_CROWN_ISLE_CLEARED     0x0907
#define FLAG_OBSIDIAN_ISLE_CLEARED  0x0908
#define FLAG_GRAND_ARENA_CLEARED    0x0909
#define FLAG_KIRA_ALLY              0x0910
#define FLAG_MILO_ALLY              0x0911
#define FLAG_SERENA_ALLY            0x0912
#define FLAG_SOVERION_ROAMING       0x0920

/* ── Trainer IDs ─────────────────────────────────────────────────────────── */
#define TRAINER_CHAMPION_BLUE           855
#define TRAINER_CHAMPION_BLUE_2         856
#define TRAINER_CHAMPION_LANCE          857
#define TRAINER_CHAMPION_LANCE_2        858
#define TRAINER_CHAMPION_STEVEN         859
#define TRAINER_CHAMPION_STEVEN_2       860
#define TRAINER_CHAMPION_CYNTHIA        861
#define TRAINER_CHAMPION_CYNTHIA_2      862
#define TRAINER_CHAMPION_IRIS           863
#define TRAINER_CHAMPION_IRIS_2         864
#define TRAINER_CHAMPION_DIANTHA        865
#define TRAINER_CHAMPION_DIANTHA_2      866
#define TRAINER_CHAMPION_HAU            867
#define TRAINER_CHAMPION_HAU_2          868
#define TRAINER_CHAMPION_LEON           869
#define TRAINER_CHAMPION_LEON_2         870
#define TRAINER_CHAMPION_GEETA          871
#define TRAINER_CHAMPION_GEETA_2        872
#define TRAINER_ETERNAL_CHAMPION        873
#define TRAINER_ETERNAL_CHAMPION_2      874

#define TRAINER_RIVAL_KIRA_1            880
#define TRAINER_RIVAL_KIRA_FINAL        881
#define TRAINER_RIVAL_MILO_1            882
#define TRAINER_RIVAL_MILO_FINAL        883
#define TRAINER_RIVAL_SERENA_1          884
#define TRAINER_RIVAL_SERENA_FINAL      885

/* ── Map Constants ───────────────────────────────────────────────────────── */
#define MAPSEC_NEXUM_HARBOR         220
#define MAPSEC_VALOR_ISLE           221
#define MAPSEC_CINDER_ISLE          222
#define MAPSEC_CRYSTAL_ISLE         223
#define MAPSEC_FROST_ISLE           224
#define MAPSEC_TEMPEST_ISLE         225
#define MAPSEC_BLOOM_ISLE           226
#define MAPSEC_SOL_ISLE             227
#define MAPSEC_CROWN_ISLE           228
#define MAPSEC_OBSIDIAN_ISLE        229
#define MAPSEC_GRAND_ARENA          230
#define MAPSEC_NEXUM_WILDS          231

/* ── Music Track IDs ─────────────────────────────────────────────────────── */
#define MUS_NEXUM_HARBOR            0xA0
#define MUS_VALOR_ISLE              0xA1
#define MUS_FROST_ISLE              0xA2
#define MUS_CROWN_ISLE              0xA3
#define MUS_GRAND_ARENA             0xA4
#define MUS_CHAMPION_ARENA          0xA5
#define MUS_CHAMPION_ARENA_GALAR    0xA6
#define MUS_ETERNAL_CHAMPION_BATTLE 0xA7
#define MUS_SOVERION_AWAKENING      0xA8
#define MUS_ANCIENT_RUINS           0xA9
#define MUS_SEAL_CHAMBER            0xAA
#define MUS_NEXUM_WILDS             0xAB

/* ── Sound Effects ───────────────────────────────────────────────────────── */
#define SE_TV_FLICKER               0x80
#define SE_THUNDER_STORM            0x81
#define SE_FIREWORKS                0x82

#endif /* GUARD_CONSTANTS_CHAMPIONS_EMERALD_H */
