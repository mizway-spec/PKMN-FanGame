/*
 * Pokemon Champions: Emerald Edition
 * Champion Party Data
 *
 * All champions carry full 6-Pokemon teams with held items,
 * custom movesets, and optimized EVs.
 * Uses TrainerMonItemDefaultMoves / TrainerMonItemCustomMoves structs.
 */

#ifndef GUARD_CHAMPION_PARTIES_H
#define GUARD_CHAMPION_PARTIES_H

#include "global.h"
#include "trainer.h"

/* =========================================================
 * BLUE — Kanto Champion (Valor Isle)
 * Specializes in well-balanced, offensive teams.
 * ========================================================= */
static const struct TrainerMonItemCustomMoves sParty_Blue[] = {
    {
        .iv = 31, .lvl = 65, .species = SPECIES_PIDGEOT,
        .heldItem = ITEM_SHARP_BEAK,
        .moves = { MOVE_BRAVE_BIRD, MOVE_HURRICANE, MOVE_RETURN, MOVE_U_TURN },
    },
    {
        .iv = 31, .lvl = 65, .species = SPECIES_RHYDON,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = { MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_MEGAHORN, MOVE_THUNDER_PUNCH },
    },
    {
        .iv = 31, .lvl = 66, .species = SPECIES_ARCANINE,
        .heldItem = ITEM_CHOICE_BAND,
        .moves = { MOVE_FLARE_BLITZ, MOVE_EXTREME_SPEED, MOVE_IRON_HEAD, MOVE_WILD_CHARGE },
    },
    {
        .iv = 31, .lvl = 66, .species = SPECIES_GYARADOS,
        .heldItem = ITEM_LUM_BERRY,
        .moves = { MOVE_WATERFALL, MOVE_DRAGON_DANCE, MOVE_CRUNCH, MOVE_EARTHQUAKE },
    },
    {
        .iv = 31, .lvl = 67, .species = SPECIES_ALAKAZAM,
        .heldItem = ITEM_LIFE_ORB,
        .moves = { MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST, MOVE_GRASS_KNOT },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_BLASTOISE,
        .heldItem = ITEM_BLASTOISINITE,     /* Mega Stone — Mega Blastoise */
        .moves = { MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_DARK_PULSE, MOVE_AURA_SPHERE },
    },
};

/* =========================================================
 * LANCE — Johto Champion (Cinder Isle)
 * Dragon specialist; heavy Fire coverage.
 * ========================================================= */
static const struct TrainerMonItemCustomMoves sParty_Lance[] = {
    {
        .iv = 31, .lvl = 66, .species = SPECIES_AERODACTYL,
        .heldItem = ITEM_FOCUS_SASH,
        .moves = { MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE, MOVE_EARTHQUAKE, MOVE_ICE_FANG },
    },
    {
        .iv = 31, .lvl = 66, .species = SPECIES_GYARADOS,
        .heldItem = ITEM_LUM_BERRY,
        .moves = { MOVE_DRAGON_DANCE, MOVE_WATERFALL, MOVE_ICE_FANG, MOVE_EARTHQUAKE },
    },
    {
        .iv = 31, .lvl = 67, .species = SPECIES_DRAGONAIR,
        .heldItem = ITEM_EVIOLITE,
        .moves = { MOVE_DRAGON_PULSE, MOVE_THUNDER_WAVE, MOVE_AQUA_TAIL, MOVE_EXTREME_SPEED },
    },
    {
        .iv = 31, .lvl = 67, .species = SPECIES_DRAGONAIR,
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = { MOVE_OUTRAGE, MOVE_AQUA_TAIL, MOVE_FIRE_BLAST, MOVE_THUNDER_WAVE },
    },
    {
        .iv = 31, .lvl = 67, .species = SPECIES_DRAGONITE,
        .heldItem = ITEM_CHOICE_BAND,
        .moves = { MOVE_OUTRAGE, MOVE_EXTREME_SPEED, MOVE_FIRE_PUNCH, MOVE_EARTHQUAKE },
    },
    {
        .iv = 31, .lvl = 69, .species = SPECIES_DRAGONITE,
        .heldItem = ITEM_LIFE_ORB,
        .moves = { MOVE_DRACO_METEOR, MOVE_HURRICANE, MOVE_FIRE_BLAST, MOVE_THUNDER },
    },
};

/* =========================================================
 * STEVEN STONE — Hoenn Champion (Crystal Isle)
 * Steel/Rock powerhouse. Mega Metagross ace.
 * ========================================================= */
static const struct TrainerMonItemCustomMoves sParty_Steven[] = {
    {
        .iv = 31, .lvl = 66, .species = SPECIES_SKARMORY,
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = { MOVE_SPIKES, MOVE_STEALTH_ROCK, MOVE_BRAVE_BIRD, MOVE_WHIRLWIND },
    },
    {
        .iv = 31, .lvl = 66, .species = SPECIES_CRADILY,
        .heldItem = ITEM_LEFTOVERS,
        .moves = { MOVE_STEALTH_ROCK, MOVE_ENERGY_BALL, MOVE_ANCIENT_POWER, MOVE_RECOVER },
    },
    {
        .iv = 31, .lvl = 67, .species = SPECIES_ARMALDO,
        .heldItem = ITEM_CHOICE_BAND,
        .moves = { MOVE_X_SCISSOR, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_AQUA_JET },
    },
    {
        .iv = 31, .lvl = 67, .species = SPECIES_AGGRON,
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = { MOVE_IRON_HEAD, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH },
    },
    {
        .iv = 31, .lvl = 67, .species = SPECIES_CLAYDOL,
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = { MOVE_PSYCHIC, MOVE_EARTH_POWER, MOVE_ICE_BEAM, MOVE_TRICK },
    },
    {
        .iv = 31, .lvl = 70, .species = SPECIES_METAGROSS,
        .heldItem = ITEM_METAGROSSITE,      /* Mega Metagross */
        .moves = { MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_HAMMER_ARM },
    },
};

/* =========================================================
 * CYNTHIA — Sinnoh Champion (Frost Isle)
 * The hardest fight in the game. Balanced & threatening.
 * ========================================================= */
static const struct TrainerMonItemCustomMoves sParty_Cynthia[] = {
    {
        .iv = 31, .lvl = 68, .species = SPECIES_SPIRITOMB,
        .heldItem = ITEM_LEFTOVERS,
        .moves = { MOVE_WILL_O_WISP, MOVE_SHADOW_BALL, MOVE_DARK_PULSE, MOVE_REST },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_ROSERADE,
        .heldItem = ITEM_LIFE_ORB,
        .moves = { MOVE_LEAF_STORM, MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_SYNTHESIS },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_TOGEKISS,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = { MOVE_AIR_SLASH, MOVE_AURA_SPHERE, MOVE_THUNDER_WAVE, MOVE_FOLLOW_ME },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_LUCARIO,
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = { MOVE_AURA_SPHERE, MOVE_FLASH_CANNON, MOVE_DARK_PULSE, MOVE_VACUUM_WAVE },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_MILOTIC,
        .heldItem = ITEM_FLAME_ORB,
        .moves = { MOVE_SCALD, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_TOXIC },
    },
    {
        .iv = 31, .lvl = 72, .species = SPECIES_GARCHOMP,
        .heldItem = ITEM_YACHE_BERRY,
        .moves = { MOVE_EARTHQUAKE, MOVE_DRAGON_RUSH, MOVE_STONE_EDGE, MOVE_SWORDS_DANCE },
    },
};

/* =========================================================
 * IRIS — Unova Champion (Tempest Isle)
 * Dragon specialist with unexpected coverage.
 * ========================================================= */
static const struct TrainerMonItemCustomMoves sParty_Iris[] = {
    {
        .iv = 31, .lvl = 67, .species = SPECIES_DRUDDIGON,
        .heldItem = ITEM_ROCKY_HELMET,
        .moves = { MOVE_GLARE, MOVE_DRAGON_TAIL, MOVE_FIRE_PUNCH, MOVE_SUCKER_PUNCH },
    },
    {
        .iv = 31, .lvl = 67, .species = SPECIES_ARCHEOPS,
        .heldItem = ITEM_FOCUS_SASH,
        .moves = { MOVE_ACROBATICS, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_ENDEAVOR },
    },
    {
        .iv = 31, .lvl = 67, .species = SPECIES_AGGRON,
        .heldItem = ITEM_AGGRONITE,
        .moves = { MOVE_IRON_HEAD, MOVE_EARTHQUAKE, MOVE_ICE_PUNCH, MOVE_STEALTH_ROCK },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_LAPRAS,
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = { MOVE_SURF, MOVE_ICE_BEAM, MOVE_THUNDER_BOLT, MOVE_DRAGON_PULSE },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_SALAMENCE,
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = { MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_FIRE_FANG, MOVE_DRAGON_DANCE },
    },
    {
        .iv = 31, .lvl = 71, .species = SPECIES_HAXORUS,
        .heldItem = ITEM_LIFE_ORB,
        .moves = { MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_POISON_JAB, MOVE_DRAGON_DANCE },
    },
};

/* =========================================================
 * DIANTHA — Kalos Champion (Bloom Isle)
 * Tricky, status-spreading team. Mega Gardevoir hits hard.
 * ========================================================= */
static const struct TrainerMonItemCustomMoves sParty_Diantha[] = {
    {
        .iv = 31, .lvl = 67, .species = SPECIES_HAWLUCHA,
        .heldItem = ITEM_UNBURDEN_SEED,     /* Electric Seed for Unburden */
        .moves = { MOVE_HIGH_JUMP_KICK, MOVE_ACROBATICS, MOVE_SWORDS_DANCE, MOVE_ROOST },
    },
    {
        .iv = 31, .lvl = 67, .species = SPECIES_TYRANTRUM,
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = { MOVE_HEAD_SMASH, MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_ICE_FANG },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_AURORUS,
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = { MOVE_BLIZZARD, MOVE_THUNDER_BOLT, MOVE_FLASH_CANNON, MOVE_ANCIENT_POWER },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_GOURGEIST,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = { MOVE_WILL_O_WISP, MOVE_PHANTOM_FORCE, MOVE_LEECH_SEED, MOVE_SYNTHESIS },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_GOODRA,
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = { MOVE_DRAGON_PULSE, MOVE_SLUDGE_BOMB, MOVE_POWER_WHIP, MOVE_FIRE_BLAST },
    },
    {
        .iv = 31, .lvl = 71, .species = SPECIES_GARDEVOIR,
        .heldItem = ITEM_GARDEVOIRITE,      /* Mega Gardevoir */
        .moves = { MOVE_HYPER_VOICE, MOVE_PSYSHOCK, MOVE_SHADOW_BALL, MOVE_FOCUS_BLAST },
    },
};

/* =========================================================
 * HAU — Alola Champion (Sol Isle)
 * Fast, sun-based team. Deceptively dangerous.
 * ========================================================= */
static const struct TrainerMonItemCustomMoves sParty_Hau[] = {
    {
        .iv = 31, .lvl = 67, .species = SPECIES_TAUROS,
        .heldItem = ITEM_CHOICE_BAND,
        .moves = { MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_IRON_HEAD, MOVE_ZEN_HEADBUTT },
    },
    {
        .iv = 31, .lvl = 67, .species = SPECIES_CRABOMINABLE,
        .heldItem = ITEM_LIFE_ORB,
        .moves = { MOVE_CLOSE_COMBAT, MOVE_ICE_HAMMER, MOVE_IRON_HEAD, MOVE_EARTHQUAKE },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_INCINEROAR,
        .heldItem = ITEM_SITRUS_BERRY,
        .moves = { MOVE_KNOCK_OFF, MOVE_FLARE_BLITZ, MOVE_EARTHQUAKE, MOVE_FAKE_OUT },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_PRIMARINA,
        .heldItem = ITEM_CHOICE_SPECS,
        .moves = { MOVE_SPARKLING_ARIA, MOVE_MOONBLAST, MOVE_ICE_BEAM, MOVE_ENERGY_BALL },
    },
    {
        .iv = 31, .lvl = 68, .species = SPECIES_DECIDUEYE,
        .heldItem = ITEM_FOCUS_SASH,
        .moves = { MOVE_SPIRIT_SHACKLE, MOVE_LEAF_BLADE, MOVE_SHADOW_SNEAK, MOVE_DEFOG },
    },
    {
        .iv = 31, .lvl = 71, .species = SPECIES_RAICHU_ALOLAN,
        .heldItem = ITEM_LIFE_ORB,
        .moves = { MOVE_THUNDER_BOLT, MOVE_PSYCHIC, MOVE_FOCUS_BLAST, MOVE_GRASS_KNOT },
    },
};

/* =========================================================
 * LEON — Galar Champion (Crown Isle)
 * The undefeated champion. Hyper-offensive.
 * ========================================================= */
static const struct TrainerMonItemCustomMoves sParty_Leon[] = {
    {
        .iv = 31, .lvl = 69, .species = SPECIES_AEGISLASH,
        .heldItem = ITEM_AIR_BALLOON,
        .moves = { MOVE_SACRED_SWORD, MOVE_SHADOW_SNEAK, MOVE_KING_SHIELD, MOVE_SHADOW_BALL },
    },
    {
        .iv = 31, .lvl = 69, .species = SPECIES_HAXORUS,
        .heldItem = ITEM_CHOICE_SCARF,
        .moves = { MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_CLOSE_COMBAT, MOVE_IRON_HEAD },
    },
    {
        .iv = 31, .lvl = 70, .species = SPECIES_SEISMITOAD,
        .heldItem = ITEM_CHOICE_BAND,
        .moves = { MOVE_EARTHQUAKE, MOVE_WATERFALL, MOVE_DRAIN_PUNCH, MOVE_STONE_EDGE },
    },
    {
        .iv = 31, .lvl = 70, .species = SPECIES_INTELEON,
        .heldItem = ITEM_SCOPE_LENS,
        .moves = { MOVE_SNIPE_SHOT, MOVE_ICE_BEAM, MOVE_DARK_PULSE, MOVE_U_TURN },
    },
    {
        .iv = 31, .lvl = 70, .species = SPECIES_DRAGAPULT,
        .heldItem = ITEM_LIFE_ORB,
        .moves = { MOVE_DRAGON_DARTS, MOVE_SHADOW_BALL, MOVE_THUNDER_BOLT, MOVE_FLAMETHROWER },
    },
    {
        .iv = 31, .lvl = 73, .species = SPECIES_CHARIZARD,
        .heldItem = ITEM_CHARIZARDITE_X,    /* Mega Charizard X — matches Leon's Gigantamax theme */
        .moves = { MOVE_FLARE_BLITZ, MOVE_OUTRAGE, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE },
    },
};

/* =========================================================
 * GEETA — Paldea Champion (Obsidian Isle)
 * Status and speed control. Don't underestimate Glimmora.
 * ========================================================= */
static const struct TrainerMonItemCustomMoves sParty_Geeta[] = {
    {
        .iv = 31, .lvl = 70, .species = SPECIES_ESPATHRA,
        .heldItem = ITEM_SPEED_BOOST_HERB,
        .moves = { MOVE_SPEED_SWAP, MOVE_LUMINA_CRASH, MOVE_DAZZLING_GLEAM, MOVE_CALM_MIND },
    },
    {
        .iv = 31, .lvl = 70, .species = SPECIES_VELUZA,
        .heldItem = ITEM_CHOICE_BAND,
        .moves = { MOVE_FILLET_AWAY, MOVE_AQUA_CUTTER, MOVE_PSYCHO_CUT, MOVE_SUCKER_PUNCH },
    },
    {
        .iv = 31, .lvl = 71, .species = SPECIES_AVALUGG_HISUI,
        .heldItem = ITEM_LEFTOVERS,
        .moves = { MOVE_STEALTH_ROCK, MOVE_MOUNTAIN_GALE, MOVE_EARTHQUAKE, MOVE_BODY_PRESS },
    },
    {
        .iv = 31, .lvl = 71, .species = SPECIES_GOGOAT,
        .heldItem = ITEM_ASSAULT_VEST,
        .moves = { MOVE_HORN_LEECH, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BULK_UP },
    },
    {
        .iv = 31, .lvl = 71, .species = SPECIES_KINGAMBIT,
        .heldItem = ITEM_BLACK_GLASSES,
        .moves = { MOVE_KOWTOW_CLEAVE, MOVE_IRON_HEAD, MOVE_SUCKER_PUNCH, MOVE_SWORDS_DANCE },
    },
    {
        .iv = 31, .lvl = 74, .species = SPECIES_GLIMMORA,
        .heldItem = ITEM_FOCUS_SASH,
        .moves = { MOVE_MORTAL_SPIN, MOVE_SLUDGE_WAVE, MOVE_POWER_GEM, MOVE_EARTH_POWER },
    },
};

/* =========================================================
 * ETERNAL CHAMPION (Final Boss) — Grand Arena
 * Uses Soverion as ace. Perfectly balanced team.
 * Identity revealed in story Act IV.
 * ========================================================= */
static const struct TrainerMonItemCustomMoves sParty_EternalChampion[] = {
    {
        .iv = 31, .lvl = 74, .species = SPECIES_MEGA_RAYQUAZA,
        .heldItem = ITEM_NONE,          /* Mega Rayquaza doesn't need Mega Stone */
        .moves = { MOVE_DRAGON_ASCENT, MOVE_DRACO_METEOR, MOVE_EXTREME_SPEED, MOVE_V_CREATE },
    },
    {
        .iv = 31, .lvl = 74, .species = SPECIES_PRIMAL_KYOGRE,
        .heldItem = ITEM_BLUE_ORB,
        .moves = { MOVE_ORIGIN_PULSE, MOVE_ICE_BEAM, MOVE_THUNDER, MOVE_CALM_MIND },
    },
    {
        .iv = 31, .lvl = 74, .species = SPECIES_PRIMAL_GROUDON,
        .heldItem = ITEM_RED_ORB,
        .moves = { MOVE_PRECIPICE_BLADES, MOVE_ERUPTION, MOVE_FIRE_PUNCH, MOVE_STEALTH_ROCK },
    },
    {
        .iv = 31, .lvl = 74, .species = SPECIES_NECROZMA_ULTRA,
        .heldItem = ITEM_ULTRANECROZIUM_Z,
        .moves = { MOVE_SUNSTEEL_STRIKE, MOVE_MOONGEIST_BEAM, MOVE_PHOTON_GEYSER, MOVE_TRICK_ROOM },
    },
    {
        .iv = 31, .lvl = 74, .species = SPECIES_ETERNATUS,
        .heldItem = ITEM_LEFTOVERS,
        .moves = { MOVE_DYNAMAX_CANNON, MOVE_FLAMETHROWER, MOVE_SLUDGE_BOMB, MOVE_RECOVER },
    },
    {
        .iv = 31, .lvl = 80, .species = SPECIES_SOVERION,
        .heldItem = ITEM_GOLDEN_CROWN,  /* new held item: +Sp.Atk; cannot be Knocked Off */
        .moves = { MOVE_ETERNAL_ROAR, MOVE_CHAMPIONS_AURA, MOVE_CROWN_BEAM, MOVE_RECOVER },
    },
};

#endif /* GUARD_CHAMPION_PARTIES_H */
