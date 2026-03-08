/*
 * Pokemon Champions: Emerald Edition
 * Map Headers — Nexum Archipelago
 *
 * Maps follow pokeemerald MapHeader struct format.
 * Each island is a self-contained map group.
 * See docs/design.md for full layout diagrams.
 */

#ifndef GUARD_NEXUM_ARCHIPELAGO_H
#define GUARD_NEXUM_ARCHIPELAGO_H

#include "global.h"
#include "map.h"

/* =========================================================
 * MAP GROUP ASSIGNMENTS
 * MAP_GROUP_NEXUM_*  = map group IDs beyond Hoenn's groups
 * ========================================================= */
#define MAP_GROUP_NEXUM_HARBOR      40
#define MAP_GROUP_VALOR_ISLE        41
#define MAP_GROUP_CINDER_ISLE       42
#define MAP_GROUP_CRYSTAL_ISLE      43
#define MAP_GROUP_FROST_ISLE        44
#define MAP_GROUP_TEMPEST_ISLE      45
#define MAP_GROUP_BLOOM_ISLE        46
#define MAP_GROUP_SOL_ISLE          47
#define MAP_GROUP_CROWN_ISLE        48
#define MAP_GROUP_OBSIDIAN_ISLE     49
#define MAP_GROUP_GRAND_ARENA       50
#define MAP_GROUP_NEXUM_WILDS       51  /* post-game roaming area */

/* =========================================================
 * NEXUM HARBOR — Starting hub, connects to all islands
 * ========================================================= */
static const struct MapConnection sMapConnections_NexumHarbor[] = {
    { CONNECT_SOUTH, MAP_GROUP_NEXUM_WILDS, 0 },
};

static const struct MapHeader gMapHeader_NexumHarbor = {
    .mapLayoutId    = LAYOUT_NEXUM_HARBOR,
    .musicDefault   = MUS_NEXUM_HARBOR,
    .regionMapSectionId = MAPSEC_NEXUM_HARBOR,
    .cave           = FALSE,
    .weather        = WEATHER_SUNNY,
    .mapType        = MAP_TYPE_TOWN,
    .allowBiking    = FALSE,
    .allowEscaping  = FALSE,
    .allowRunning   = TRUE,
    .battleScene    = MAP_BATTLE_SCENE_NORMAL,
    .connections    = sMapConnections_NexumHarbor,
    .name           = gMapName_NexumHarbor,
};

/* =========================================================
 * VALOR ISLE — Blue (Kanto Champion)
 * Volcanic cliffs, warm ocean. Blue's Arena is at summit.
 * Wild: Arcanine, Charizard, Rapidash, Ponyta, Growlithe
 * ========================================================= */
static const struct MapHeader gMapHeader_ValorIsle_Exterior = {
    .mapLayoutId    = LAYOUT_VALOR_ISLE,
    .musicDefault   = MUS_VALOR_ISLE,
    .regionMapSectionId = MAPSEC_VALOR_ISLE,
    .cave           = FALSE,
    .weather        = WEATHER_SUNNY,
    .mapType        = MAP_TYPE_ROUTE,
    .allowBiking    = FALSE,
    .allowEscaping  = FALSE,
    .allowRunning   = TRUE,
    .battleScene    = MAP_BATTLE_SCENE_NORMAL,
    .connections    = NULL,
    .name           = gMapName_ValorIsle,
};

static const struct MapHeader gMapHeader_ValorIsle_Arena = {
    .mapLayoutId    = LAYOUT_VALOR_ARENA,
    .musicDefault   = MUS_CHAMPION_ARENA,
    .regionMapSectionId = MAPSEC_VALOR_ISLE,
    .cave           = FALSE,
    .weather        = WEATHER_NONE,
    .mapType        = MAP_TYPE_INDOOR,
    .allowBiking    = FALSE,
    .allowEscaping  = FALSE,
    .allowRunning   = FALSE,
    .battleScene    = MAP_BATTLE_SCENE_NORMAL,
    .connections    = NULL,
    .name           = gMapName_ValorArena,
};

/* =========================================================
 * FROST ISLE — Cynthia (Sinnoh Champion)
 * Snow-capped mountains, icy caves. Cynthia studies ruins here.
 * Wild: Garchomp, Sneasel, Weavile, Abomasnow, Glalie
 * ========================================================= */
static const struct MapHeader gMapHeader_FrostIsle_Exterior = {
    .mapLayoutId    = LAYOUT_FROST_ISLE,
    .musicDefault   = MUS_FROST_ISLE,
    .regionMapSectionId = MAPSEC_FROST_ISLE,
    .cave           = FALSE,
    .weather        = WEATHER_SNOW,
    .mapType        = MAP_TYPE_ROUTE,
    .allowBiking    = FALSE,
    .allowEscaping  = FALSE,
    .allowRunning   = TRUE,
    .battleScene    = MAP_BATTLE_SCENE_NORMAL,
    .connections    = NULL,
    .name           = gMapName_FrostIsle,
};

static const struct MapHeader gMapHeader_FrostIsle_Ruins = {
    .mapLayoutId    = LAYOUT_FROST_RUINS,
    .musicDefault   = MUS_ANCIENT_RUINS,
    .regionMapSectionId = MAPSEC_FROST_ISLE,
    .cave           = TRUE,
    .weather        = WEATHER_NONE,
    .mapType        = MAP_TYPE_INDOOR,
    .allowBiking    = FALSE,
    .allowEscaping  = FALSE,
    .allowRunning   = FALSE,
    .battleScene    = MAP_BATTLE_SCENE_NORMAL,
    .connections    = NULL,
    .name           = gMapName_FrostRuins,
};

/* =========================================================
 * CROWN ISLE — Leon (Galar Champion)
 * Medieval architecture, rolling fields, castle stadium.
 * Wild: Haxorus, Corviknight, Grimmsnarl, Dragapult
 * ========================================================= */
static const struct MapHeader gMapHeader_CrownIsle_Exterior = {
    .mapLayoutId    = LAYOUT_CROWN_ISLE,
    .musicDefault   = MUS_CROWN_ISLE,
    .regionMapSectionId = MAPSEC_CROWN_ISLE,
    .cave           = FALSE,
    .weather        = WEATHER_OVERCAST,
    .mapType        = MAP_TYPE_ROUTE,
    .allowBiking    = TRUE,
    .allowEscaping  = FALSE,
    .allowRunning   = TRUE,
    .battleScene    = MAP_BATTLE_SCENE_NORMAL,
    .connections    = NULL,
    .name           = gMapName_CrownIsle,
};

static const struct MapHeader gMapHeader_CrownIsle_Stadium = {
    .mapLayoutId    = LAYOUT_CROWN_STADIUM,
    .musicDefault   = MUS_CHAMPION_ARENA_GALAR,
    .regionMapSectionId = MAPSEC_CROWN_ISLE,
    .cave           = FALSE,
    .weather        = WEATHER_NONE,
    .mapType        = MAP_TYPE_INDOOR,
    .allowBiking    = FALSE,
    .allowEscaping  = FALSE,
    .allowRunning   = FALSE,
    .battleScene    = MAP_BATTLE_SCENE_NORMAL,
    .connections    = NULL,
    .name           = gMapName_CrownStadium,
};

/* =========================================================
 * GRAND ARENA — Final destination; Vance Kael's fortress
 * Floating island held aloft by Soverion's ancient power.
 * Wild (post-game): Soverion (roaming), Nexum Forms
 * ========================================================= */
static const struct MapHeader gMapHeader_GrandArena_Exterior = {
    .mapLayoutId    = LAYOUT_GRAND_ARENA_EXT,
    .musicDefault   = MUS_GRAND_ARENA,
    .regionMapSectionId = MAPSEC_GRAND_ARENA,
    .cave           = FALSE,
    .weather        = WEATHER_LIGHTNING,
    .mapType        = MAP_TYPE_ROUTE,
    .allowBiking    = FALSE,
    .allowEscaping  = FALSE,
    .allowRunning   = TRUE,
    .battleScene    = MAP_BATTLE_SCENE_NORMAL,
    .connections    = NULL,
    .name           = gMapName_GrandArena,
};

static const struct MapHeader gMapHeader_GrandArena_SealChamber = {
    .mapLayoutId    = LAYOUT_SEAL_CHAMBER,
    .musicDefault   = MUS_SEAL_CHAMBER,
    .regionMapSectionId = MAPSEC_GRAND_ARENA,
    .cave           = TRUE,
    .weather        = WEATHER_NONE,
    .mapType        = MAP_TYPE_INDOOR,
    .allowBiking    = FALSE,
    .allowEscaping  = FALSE,
    .allowRunning   = FALSE,
    .battleScene    = MAP_BATTLE_SCENE_NORMAL,
    .connections    = NULL,
    .name           = gMapName_SealChamber,
};

static const struct MapHeader gMapHeader_GrandArena_BattleFloor = {
    .mapLayoutId    = LAYOUT_GRAND_ARENA_BATTLE,
    .musicDefault   = MUS_ETERNAL_CHAMPION_BATTLE,
    .regionMapSectionId = MAPSEC_GRAND_ARENA,
    .cave           = FALSE,
    .weather        = WEATHER_NONE,
    .mapType        = MAP_TYPE_INDOOR,
    .allowBiking    = FALSE,
    .allowEscaping  = FALSE,
    .allowRunning   = FALSE,
    .battleScene    = MAP_BATTLE_SCENE_GYM,
    .connections    = NULL,
    .name           = gMapName_GrandArenaBattle,
};

/* =========================================================
 * NEXUM WILDS — Post-game open area, all biomes
 * Accessible after defeating Eternal Champion.
 * Wild (post-game): All Nexum Forms, rare Gen 1-9 Pokemon
 * Soverion roams here if not caught at Grand Arena.
 * ========================================================= */
static const struct MapHeader gMapHeader_NexumWilds = {
    .mapLayoutId    = LAYOUT_NEXUM_WILDS,
    .musicDefault   = MUS_NEXUM_WILDS,
    .regionMapSectionId = MAPSEC_NEXUM_WILDS,
    .cave           = FALSE,
    .weather        = WEATHER_DYNAMIC,     /* custom: changes by time of day */
    .mapType        = MAP_TYPE_ROUTE,
    .allowBiking    = TRUE,
    .allowEscaping  = TRUE,
    .allowRunning   = TRUE,
    .battleScene    = MAP_BATTLE_SCENE_NORMAL,
    .connections    = NULL,
    .name           = gMapName_NexumWilds,
};

/* =========================================================
 * WILD ENCOUNTER TABLES (selected maps)
 * ========================================================= */

/* Valor Isle — Land encounters */
static const struct WildPokemonInfo sValorIsle_LandMons_Info = {10, sValorIsle_LandMons};
static const struct WildPokemon sValorIsle_LandMons[] = {
    {45, 50, SPECIES_GROWLITHE},
    {45, 50, SPECIES_PONYTA},
    {48, 53, SPECIES_ARCANINE},
    {48, 53, SPECIES_RAPIDASH},
    {50, 55, SPECIES_CHARIZARD},
    {42, 47, SPECIES_MAGMAR},
    {44, 49, SPECIES_FLAREON},
    {46, 51, SPECIES_NINETALES},
    {52, 57, SPECIES_NEXUM_ARCANINE},   /* rare */
    {55, 60, SPECIES_HEATRAN},          /* very rare post-game */
    {44, 49, SPECIES_CAMERUPT},
    {43, 48, SPECIES_NUMEL},
};

/* Frost Isle — Land encounters */
static const struct WildPokemonInfo sFrostIsle_LandMons_Info = {10, sFrostIsle_LandMons};
static const struct WildPokemon sFrostIsle_LandMons[] = {
    {44, 49, SPECIES_SNEASEL},
    {46, 51, SPECIES_WEAVILE},
    {47, 52, SPECIES_SNOVER},
    {49, 54, SPECIES_ABOMASNOW},
    {47, 52, SPECIES_SNORUNT},
    {49, 54, SPECIES_GLALIE},
    {50, 55, SPECIES_FROSLASS},
    {51, 56, SPECIES_BEARTIC},
    {53, 58, SPECIES_GARCHOMP},         /* rare */
    {44, 49, SPECIES_SWINUB},
    {48, 53, SPECIES_MAMOSWINE},
    {55, 60, SPECIES_REGICE},           /* very rare post-game */
};

/* Nexum Wilds — All-biome encounter pool (post-game) */
static const struct WildPokemonInfo sNexumWilds_LandMons_Info = {10, sNexumWilds_LandMons};
static const struct WildPokemon sNexumWilds_LandMons[] = {
    {60, 65, SPECIES_NEXUM_ARCANINE},
    {60, 65, SPECIES_NEXUM_ABSOL},
    {60, 65, SPECIES_NEXUM_BRELOOM},
    {60, 65, SPECIES_NEXUM_AGGRON},
    {58, 63, SPECIES_DRAGONITE},
    {58, 63, SPECIES_TYRANITAR},
    {58, 63, SPECIES_SALAMENCE},
    {58, 63, SPECIES_METAGROSS},
    {62, 67, SPECIES_GARCHOMP},
    {62, 67, SPECIES_LUCARIO},
    {65, 70, SPECIES_KOMMO_O},
    {70, 75, SPECIES_SOVERION},         /* roaming if not caught */
};

#endif /* GUARD_NEXUM_ARCHIPELAGO_H */
