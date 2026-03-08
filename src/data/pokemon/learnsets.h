/*
 * Pokemon Champions: Emerald Edition
 * Learnsets for new Pokemon and Nexum Forms
 *
 * Uses LEVEL_UP_MOVE(level, move) macro from pokeemerald.
 * LEVEL_UP_END terminates each table.
 */

#ifndef GUARD_LEARNSETS_H
#define GUARD_LEARNSETS_H

#include "global.h"
#include "pokemon.h"

/* =========================================================
 * SOVERION
 * ========================================================= */
const struct LevelUpMove gLevelUpLearnset_Soverion[] = {
    LEVEL_UP_MOVE( 1,  MOVE_CONFUSION),
    LEVEL_UP_MOVE( 1,  MOVE_DRAGON_BREATH),
    LEVEL_UP_MOVE( 1,  MOVE_LEER),
    LEVEL_UP_MOVE( 1,  MOVE_GROWL),
    LEVEL_UP_MOVE( 8,  MOVE_SWIFT),
    LEVEL_UP_MOVE(15,  MOVE_PSYBEAM),
    LEVEL_UP_MOVE(20,  MOVE_DRAGON_RAGE),
    LEVEL_UP_MOVE(26,  MOVE_CALM_MIND),
    LEVEL_UP_MOVE(32,  MOVE_CROWN_BEAM),        /* new move */
    LEVEL_UP_MOVE(38,  MOVE_PSYCHIC),
    LEVEL_UP_MOVE(44,  MOVE_DRAGON_PULSE),
    LEVEL_UP_MOVE(50,  MOVE_CHAMPIONS_AURA),    /* new move */
    LEVEL_UP_MOVE(56,  MOVE_RECOVER),
    LEVEL_UP_MOVE(62,  MOVE_SPACIAL_REND),
    LEVEL_UP_MOVE(70,  MOVE_ETERNAL_ROAR),      /* signature move */
    LEVEL_UP_MOVE(80,  MOVE_JUDGMENT),
    LEVEL_UP_END
};

/* =========================================================
 * NEXUM ARCANINE
 * ========================================================= */
const struct LevelUpMove gLevelUpLearnset_NexumArcanine[] = {
    LEVEL_UP_MOVE( 1,  MOVE_BITE),
    LEVEL_UP_MOVE( 1,  MOVE_ROAR),
    LEVEL_UP_MOVE( 1,  MOVE_EMBER),
    LEVEL_UP_MOVE( 1,  MOVE_LEER),
    LEVEL_UP_MOVE( 9,  MOVE_ODOR_SLEUTH),
    LEVEL_UP_MOVE(18,  MOVE_DRAGON_BREATH),
    LEVEL_UP_MOVE(23,  MOVE_FLAME_WHEEL),
    LEVEL_UP_MOVE(30,  MOVE_AGILITY),
    LEVEL_UP_MOVE(39,  MOVE_DRAGON_RUSH),
    LEVEL_UP_MOVE(50,  MOVE_FLAMETHROWER),
    LEVEL_UP_MOVE(58,  MOVE_FIRE_BLAST),
    LEVEL_UP_MOVE(65,  MOVE_DRACO_METEOR),
    LEVEL_UP_END
};

/* =========================================================
 * NEXUM MANTINE
 * ========================================================= */
const struct LevelUpMove gLevelUpLearnset_NexumMantine[] = {
    LEVEL_UP_MOVE( 1,  MOVE_TACKLE),
    LEVEL_UP_MOVE( 1,  MOVE_BUBBLE),
    LEVEL_UP_MOVE( 7,  MOVE_SUPERSONIC),
    LEVEL_UP_MOVE(13,  MOVE_BUBBLE_BEAM),
    LEVEL_UP_MOVE(18,  MOVE_WING_ATTACK),
    LEVEL_UP_MOVE(22,  MOVE_WATER_PULSE),
    LEVEL_UP_MOVE(29,  MOVE_TAKE_DOWN),
    LEVEL_UP_MOVE(34,  MOVE_MIST),
    LEVEL_UP_MOVE(40,  MOVE_TIDAL_CLASH),       /* new move */
    LEVEL_UP_MOVE(47,  MOVE_SURF),
    LEVEL_UP_MOVE(56,  MOVE_HYDRO_PUMP),
    LEVEL_UP_MOVE(64,  MOVE_AIR_SLASH),
    LEVEL_UP_END
};

/* =========================================================
 * NEXUM ABSOL
 * ========================================================= */
const struct LevelUpMove gLevelUpLearnset_NexumAbsol[] = {
    LEVEL_UP_MOVE( 1,  MOVE_SCRATCH),
    LEVEL_UP_MOVE( 1,  MOVE_LEER),
    LEVEL_UP_MOVE( 5,  MOVE_TAUNT),
    LEVEL_UP_MOVE( 9,  MOVE_QUICK_ATTACK),
    LEVEL_UP_MOVE(13,  MOVE_RAZOR_WIND),
    LEVEL_UP_MOVE(17,  MOVE_BITE),
    LEVEL_UP_MOVE(21,  MOVE_SWORDS_DANCE),
    LEVEL_UP_MOVE(25,  MOVE_CALM_MIND),
    LEVEL_UP_MOVE(29,  MOVE_PSYCHO_CUT),
    LEVEL_UP_MOVE(33,  MOVE_CROWN_BEAM),        /* new move */
    LEVEL_UP_MOVE(39,  MOVE_NIGHT_SLASH),
    LEVEL_UP_MOVE(45,  MOVE_PSYCHIC),
    LEVEL_UP_MOVE(53,  MOVE_PERISH_SONG),
    LEVEL_UP_END
};

/* =========================================================
 * NEXUM BRELOOM
 * ========================================================= */
const struct LevelUpMove gLevelUpLearnset_NexumBreloom[] = {
    LEVEL_UP_MOVE( 1,  MOVE_ABSORB),
    LEVEL_UP_MOVE( 1,  MOVE_TACKLE),
    LEVEL_UP_MOVE( 7,  MOVE_STUN_SPORE),
    LEVEL_UP_MOVE(13,  MOVE_LEECH_SEED),
    LEVEL_UP_MOVE(19,  MOVE_MEGA_DRAIN),
    LEVEL_UP_MOVE(25,  MOVE_HEADBUTT),
    LEVEL_UP_MOVE(31,  MOVE_MACH_PUNCH),
    LEVEL_UP_MOVE(37,  MOVE_CHAMPIONS_FIST),    /* new move: like HJK, 110BP */
    LEVEL_UP_MOVE(43,  MOVE_SEED_BOMB),
    LEVEL_UP_MOVE(50,  MOVE_SKY_UPPERCUT),
    LEVEL_UP_MOVE(58,  MOVE_SPORE),
    LEVEL_UP_MOVE(64,  MOVE_FOCUS_PUNCH),
    LEVEL_UP_END
};

/* =========================================================
 * NEXUM AGGRON
 * ========================================================= */
const struct LevelUpMove gLevelUpLearnset_NexumAggron[] = {
    LEVEL_UP_MOVE( 1,  MOVE_TACKLE),
    LEVEL_UP_MOVE( 1,  MOVE_HARDEN),
    LEVEL_UP_MOVE( 7,  MOVE_MUD_SLAP),
    LEVEL_UP_MOVE(13,  MOVE_HEADBUTT),
    LEVEL_UP_MOVE(19,  MOVE_IRON_DEFENSE),
    LEVEL_UP_MOVE(25,  MOVE_SURF),
    LEVEL_UP_MOVE(32,  MOVE_METAL_SOUND),
    LEVEL_UP_MOVE(39,  MOVE_TIDAL_CLASH),       /* new move */
    LEVEL_UP_MOVE(46,  MOVE_IRON_TAIL),
    LEVEL_UP_MOVE(53,  MOVE_HYDRO_PUMP),
    LEVEL_UP_MOVE(62,  MOVE_DOUBLE_EDGE),
    LEVEL_UP_MOVE(70,  MOVE_TITAN_STRIKE),      /* new move */
    LEVEL_UP_END
};

#endif /* GUARD_LEARNSETS_H */
