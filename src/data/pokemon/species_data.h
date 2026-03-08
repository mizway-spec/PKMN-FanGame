/*
 * Pokemon Champions: Emerald Edition
 * Species Data — New Pokemon & Nexum Regional Forms
 *
 * Format follows pokeemerald BaseStats struct:
 * { hp, atk, def, speed, spAtk, spDef, type1, type2,
 *   catchRate, expYield, evYield, item1, item2,
 *   genderRatio, eggCycles, friendship, growthRate,
 *   eggGroup1, eggGroup2, ability1, ability2,
 *   safariZoneRate, bodyColor, noFlip }
 */

#ifndef GUARD_SPECIES_DATA_H
#define GUARD_SPECIES_DATA_H

#include "global.h"
#include "pokemon.h"

/* =========================================================
 * SOVERION — The Eternal Sovereign (New Legendary)
 * ========================================================= */
const struct BaseStats gBaseStats_Soverion = {
    .baseHP        = 120,
    .baseAttack    = 110,
    .baseDefense   = 100,
    .baseSpeed     = 110,
    .baseSpAttack  = 130,
    .baseSpDefense = 110,
    /* BST = 680 */
    .type1         = TYPE_PSYCHIC,
    .type2         = TYPE_DRAGON,
    .catchRate     = 3,
    .expYield      = 340,
    .evYield_SpAttack = 3,
    .item1         = ITEM_NONE,
    .item2         = ITEM_NONE,
    .genderRatio   = MON_GENDERLESS,
    .eggCycles     = 120,
    .friendship    = 0,
    .growthRate    = GROWTH_SLOW,
    .eggGroup1     = EGG_GROUP_UNDISCOVERED,
    .eggGroup2     = EGG_GROUP_UNDISCOVERED,
    .ability1      = ABILITY_SOVEREIGNS_WILL,
    .ability2      = ABILITY_NONE,
    .safariZoneRate = 0,
    .bodyColor     = BODY_COLOR_GOLD,
    .noFlip        = TRUE,
};

/* =========================================================
 * NEXUM REGIONAL FORMS
 * ========================================================= */

/* Nexum Arcanine — Fire / Dragon */
const struct BaseStats gBaseStats_NexumArcanine = {
    .baseHP        = 90,
    .baseAttack    = 110,
    .baseDefense   = 80,
    .baseSpeed     = 95,
    .baseSpAttack  = 110,   /* boosted from base Arcanine's 80 */
    .baseSpDefense = 80,
    /* BST = 565 */
    .type1         = TYPE_FIRE,
    .type2         = TYPE_DRAGON,
    .catchRate     = 75,
    .expYield      = 194,
    .evYield_SpAttack = 2,
    .item1         = ITEM_CHARCOAL,
    .item2         = ITEM_DRAGON_SCALE,
    .genderRatio   = MON_MALE_75,
    .eggCycles     = 20,
    .friendship    = 70,
    .growthRate    = GROWTH_SLOW,
    .eggGroup1     = EGG_GROUP_FIELD,
    .eggGroup2     = EGG_GROUP_FIELD,
    .ability1      = ABILITY_INTIMIDATE,
    .ability2      = ABILITY_FLASH_FIRE,
    .safariZoneRate = 0,
    .bodyColor     = BODY_COLOR_RED,
    .noFlip        = FALSE,
};

/* Nexum Mantine — Water / Flying (unchanged types) */
const struct BaseStats gBaseStats_NexumMantine = {
    .baseHP        = 85,
    .baseAttack    = 40,
    .baseDefense   = 70,
    .baseSpeed     = 75,    /* boosted from base Mantine's 70 */
    .baseSpAttack  = 80,
    .baseSpDefense = 140,
    /* BST = 490 */
    .type1         = TYPE_WATER,
    .type2         = TYPE_FLYING,
    .catchRate     = 25,
    .expYield      = 161,
    .evYield_SpDefense = 2,
    .item1         = ITEM_NONE,
    .item2         = ITEM_NONE,
    .genderRatio   = MON_MALE_50,
    .eggCycles     = 25,
    .friendship    = 70,
    .growthRate    = GROWTH_SLOW,
    .eggGroup1     = EGG_GROUP_WATER_1,
    .eggGroup2     = EGG_GROUP_FLYING,
    .ability1      = ABILITY_SWIFT_SWIM,
    .ability2      = ABILITY_AERIAL_CURRENT,  /* new ability */
    .safariZoneRate = 0,
    .bodyColor     = BODY_COLOR_BLUE,
    .noFlip        = FALSE,
};

/* Nexum Absol — Dark / Psychic */
const struct BaseStats gBaseStats_NexumAbsol = {
    .baseHP        = 65,
    .baseAttack    = 100,
    .baseDefense   = 60,
    .baseSpeed     = 75,
    .baseSpAttack  = 100,   /* boosted from base Absol's 75 */
    .baseSpDefense = 60,
    /* BST = 460 */
    .type1         = TYPE_DARK,
    .type2         = TYPE_PSYCHIC,
    .catchRate     = 30,
    .expYield      = 163,
    .evYield_Attack  = 1,
    .evYield_SpAttack = 1,
    .item1         = ITEM_NONE,
    .item2         = ITEM_NONE,
    .genderRatio   = MON_MALE_50,
    .eggCycles     = 25,
    .friendship    = 35,
    .growthRate    = GROWTH_MEDIUM_SLOW,
    .eggGroup1     = EGG_GROUP_FIELD,
    .eggGroup2     = EGG_GROUP_FIELD,
    .ability1      = ABILITY_PRESSURE,
    .ability2      = ABILITY_SUPER_LUCK,
    .safariZoneRate = 0,
    .bodyColor     = BODY_COLOR_WHITE,
    .noFlip        = FALSE,
};

/* Nexum Breloom — Grass / Fighting (unchanged types) */
const struct BaseStats gBaseStats_NexumBreloom = {
    .baseHP        = 60,
    .baseAttack    = 130,   /* boosted from base Breloom's 130 - same */
    .baseDefense   = 80,
    .baseSpeed     = 90,    /* boosted from base Breloom's 70 */
    .baseSpAttack  = 60,
    .baseSpDefense = 60,
    /* BST = 480 */
    .type1         = TYPE_GRASS,
    .type2         = TYPE_FIGHTING,
    .catchRate     = 90,
    .expYield      = 161,
    .evYield_Attack = 2,
    .item1         = ITEM_NONE,
    .item2         = ITEM_NONE,
    .genderRatio   = MON_MALE_50,
    .eggCycles     = 20,
    .friendship    = 70,
    .growthRate    = GROWTH_MEDIUM_SLOW,
    .eggGroup1     = EGG_GROUP_FAIRY,
    .eggGroup2     = EGG_GROUP_FIELD,
    .ability1      = ABILITY_EFFECT_SPORE,
    .ability2      = ABILITY_TECHNICIAN,
    .safariZoneRate = 0,
    .bodyColor     = BODY_COLOR_GREEN,
    .noFlip        = FALSE,
};

/* Nexum Aggron — Steel / Water */
const struct BaseStats gBaseStats_NexumAggron = {
    .baseHP        = 110,   /* boosted from base Aggron's 70 */
    .baseAttack    = 110,
    .baseDefense   = 180,
    .baseSpeed     = 50,
    .baseSpAttack  = 60,
    .baseSpDefense = 80,    /* boosted from base Aggron's 60 */
    /* BST = 590 */
    .type1         = TYPE_STEEL,
    .type2         = TYPE_WATER,
    .catchRate     = 45,
    .expYield      = 239,
    .evYield_Defense = 3,
    .item1         = ITEM_NONE,
    .item2         = ITEM_NONE,
    .genderRatio   = MON_MALE_75,
    .eggCycles     = 35,
    .friendship    = 35,
    .growthRate    = GROWTH_SLOW,
    .eggGroup1     = EGG_GROUP_MONSTER,
    .eggGroup2     = EGG_GROUP_FIELD,
    .ability1      = ABILITY_STURDY,
    .ability2      = ABILITY_ROCK_HEAD,
    .safariZoneRate = 0,
    .bodyColor     = BODY_COLOR_GRAY,
    .noFlip        = FALSE,
};

#endif /* GUARD_SPECIES_DATA_H */
