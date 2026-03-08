/*
 * Pokemon Champions: Emerald Edition
 * New Move Data
 *
 * These entries extend the base game's move table.
 * Each move uses the MoveInfo struct from pokeemerald.
 */

#ifndef GUARD_MOVE_DATA_H
#define GUARD_MOVE_DATA_H

#include "global.h"
#include "pokemon.h"

/* =========================================================
 * TITAN STRIKE
 * Fighting / Physical / 120 BP / 5 PP
 * User takes 25% recoil. Destroys Light Screen and Reflect.
 * ========================================================= */
[MOVE_TITAN_STRIKE] = {
    .name           = _("TitanStrike"),
    .description    = COMPOUND_STRING(
        "A devastating blow that\n"
        "breaks barriers. User takes\n"
        "recoil damage."
    ),
    .effect         = EFFECT_RECOIL_IF_HIT,        /* custom; see move_effects.c */
    .power          = 120,
    .type           = TYPE_FIGHTING,
    .accuracy       = 90,
    .pp             = 5,
    .secondaryEffectChance = 0,
    .target         = MOVE_TARGET_SELECTED,
    .priority       = 0,
    .category       = BATTLE_CATEGORY_PHYSICAL,
    .makesContact   = TRUE,
    .additionalEffects = ADDITIONAL_EFFECTS(
        {
            .moveEffect = MOVE_EFFECT_DESTROY_SCREENS,
        }
    ),
},

/* =========================================================
 * CROWN BEAM
 * Psychic / Special / 95 BP / 10 PP
 * 30% chance to raise user's Sp. Atk by 1 stage.
 * ========================================================= */
[MOVE_CROWN_BEAM] = {
    .name           = _("CrownBeam"),
    .description    = COMPOUND_STRING(
        "A regal burst of psychic\n"
        "energy. May raise the\n"
        "user's Sp. Atk."
    ),
    .effect         = EFFECT_HIT,
    .power          = 95,
    .type           = TYPE_PSYCHIC,
    .accuracy       = 100,
    .pp             = 10,
    .secondaryEffectChance = 30,
    .target         = MOVE_TARGET_SELECTED,
    .priority       = 0,
    .category       = BATTLE_CATEGORY_SPECIAL,
    .makesContact   = FALSE,
    .additionalEffects = ADDITIONAL_EFFECTS(
        {
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self       = TRUE,
            .chance     = 30,
        }
    ),
},

/* =========================================================
 * NEXUM SURGE
 * Electric / Special / 85 BP / 10 PP
 * Sets Electric Terrain for 5 turns upon use.
 * ========================================================= */
[MOVE_NEXUM_SURGE] = {
    .name           = _("NexumSurge"),
    .description    = COMPOUND_STRING(
        "Channels Nexum's ancient\n"
        "power. Sets an Electric\n"
        "Terrain for 5 turns."
    ),
    .effect         = EFFECT_HIT_SET_REMOVE_TERRAIN,
    .power          = 85,
    .type           = TYPE_ELECTRIC,
    .accuracy       = 100,
    .pp             = 10,
    .secondaryEffectChance = 100,
    .target         = MOVE_TARGET_SELECTED,
    .priority       = 0,
    .category       = BATTLE_CATEGORY_SPECIAL,
    .makesContact   = FALSE,
    .argument       = ARG_SET_ELECTRIC_TERRAIN,
},

/* =========================================================
 * ETERNAL ROAR
 * Dragon / Special / 110 BP / 5 PP
 * Soverion's signature move. Bypasses Protect and Detect.
 * ========================================================= */
[MOVE_ETERNAL_ROAR] = {
    .name           = _("EternalRoar"),
    .description    = COMPOUND_STRING(
        "The roar of the Eternal\n"
        "Sovereign. No defense\n"
        "can stop it."
    ),
    .effect         = EFFECT_HIT,
    .power          = 110,
    .type           = TYPE_DRAGON,
    .accuracy       = 100,
    .pp             = 5,
    .secondaryEffectChance = 0,
    .target         = MOVE_TARGET_SELECTED,
    .priority       = 0,
    .category       = BATTLE_CATEGORY_SPECIAL,
    .makesContact   = FALSE,
    .ignoresProtect = TRUE,     /* bypasses Protect / Detect */
    .soundMove      = TRUE,     /* Sound-based; bypasses Soundproof? No — unique */
},

/* =========================================================
 * CHAMPION'S AURA
 * Normal / Status / — BP / 5 PP
 * Raises all of user's stats by 1 stage (all 5 combat stats).
 * ========================================================= */
[MOVE_CHAMPIONS_AURA] = {
    .name           = _("ChampAura"),
    .description    = COMPOUND_STRING(
        "The user radiates the aura\n"
        "of a true champion, raising\n"
        "all stats at once."
    ),
    .effect         = EFFECT_GEOMANCY,      /* reuse Geomancy but hit all 5 stats */
    .power          = 0,
    .type           = TYPE_NORMAL,
    .accuracy       = 0,
    .pp             = 5,
    .secondaryEffectChance = 0,
    .target         = MOVE_TARGET_USER,
    .priority       = 0,
    .category       = BATTLE_CATEGORY_STATUS,
    .zMove          = { .effect = Z_EFFECT_RESET_STATS },
    .snatchAffected = TRUE,
    .ignoresProtect = TRUE,
    .mirrorMoveBanned = TRUE,
},

/* =========================================================
 * TIDAL CLASH
 * Water / Physical / 80 BP / 15 PP
 * Power doubles if opponent used a Special move last turn.
 * ========================================================= */
[MOVE_TIDAL_CLASH] = {
    .name           = _("TidalClash"),
    .description    = COMPOUND_STRING(
        "A crashing wave attack.\n"
        "Stronger against foes\n"
        "that used a special move."
    ),
    .effect         = EFFECT_TIDAL_CLASH,       /* custom; see move_effects.c */
    .power          = 80,
    .type           = TYPE_WATER,
    .accuracy       = 100,
    .pp             = 15,
    .secondaryEffectChance = 0,
    .target         = MOVE_TARGET_SELECTED,
    .priority       = 0,
    .category       = BATTLE_CATEGORY_PHYSICAL,
    .makesContact   = TRUE,
},

/* =========================================================
 * CHAMPION'S FIST
 * Fighting / Physical / 110 BP / 10 PP
 * High-Jump-Kick clone: user takes 50% HP damage on miss/ghost.
 * ========================================================= */
[MOVE_CHAMPIONS_FIST] = {
    .name           = _("ChampFist"),
    .description    = COMPOUND_STRING(
        "A flying punch fueled by\n"
        "a champion's spirit. User\n"
        "is hurt if it misses."
    ),
    .effect         = EFFECT_JUMP_KICK,         /* HJK effect */
    .power          = 110,
    .type           = TYPE_FIGHTING,
    .accuracy       = 90,
    .pp             = 10,
    .secondaryEffectChance = 0,
    .target         = MOVE_TARGET_SELECTED,
    .priority       = 0,
    .category       = BATTLE_CATEGORY_PHYSICAL,
    .makesContact   = TRUE,
    .gravityBanned  = TRUE,
},

#endif /* GUARD_MOVE_DATA_H */
