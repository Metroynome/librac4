/***************************************************
 * FILENAME :		weapon.h
 * 
 * DESCRIPTION :
 * 		Contains weapon specific offsets and structures for Ratchet and Clank 4.
 * 
 * NOTES :
 * 		Each offset is determined per app id.
 * 		This is to ensure compatibility between versions of Ratchet and Clank 4.
 * 		
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBRAC4_WEAPON_H_
#define _LIBRAC4_WEAPON_H_

#include "common.h"
#include "math3d.h"

/*
 * Runtime gadget instance held by Hero::gadgets.
 */
typedef struct Gadget {
    /*  00 */ VECTOR jointPos;
    /*  10 */ VECTOR jointRot;
    /*  20 */ struct Moby* pMoby;
    /*  24 */ struct Moby* pMoby2;
    /*  28 */ int padButtonDown;
    /*  2c */ int alignPad;
    /*  30 */ int padButton;
    /*  34 */ int gsSpawnFrame;
    /*  38 */ char noAmmoTime;
    /*  39 */ char unEquipTimer;
    /*  3a */ char detached;
    /*  3b */ char unequipTime;
    /*  3c */ char unEquipStatus;
    /*  3d */ char unEquipDelay;
    /*  3e */ char pad[2];
    /*  40 */ int equippedTime;
    /*  44 */ int state;
    /*  48 */ int id;
    /*  4c */ float lightAng;
} Gadget;

typedef struct GadgetPrice {
    /*  00 */ unsigned int purchase_price;
    /*  04 */ unsigned int discount_price;
    /*  08 */ unsigned short ammo_price;
    /*  0a */ unsigned short pda_ammo_price;
    /*  0c */ unsigned short ammo_count;
    /*  0e */ unsigned short ammo_limit;
    /*  10 */ unsigned short pad;
    /*  12 */ unsigned short ammo_start;
    /*  14 */ unsigned int gold_price;
    /*  18 */ unsigned int mod_shock_price;
    /*  1c */ unsigned int mod_acid_price;
    /*  20 */ unsigned int mod_lock_on_price;
} GadgetPrice;

typedef struct GadgetFPSData {
    /*  00 */ VECTOR posOffset;
    /*  10 */ VECTOR rotOffset;
} GadgetFPSData;

typedef void (*GadgetTargetFunc)();

typedef struct GadgetLevels {
    /*  00 */ int levels[10];
} GadgetLevels;

typedef struct GadgetDef {
    /*  00 */ int level;
    /*  04 */ short pickupTag;
    /*  06 */ short uppercaseTag;
    /*  08 */ short quickSelectTag;
    /*  0a */ short description;
    /*  0c */ short basicGotTag;
    /*  0e */ short basicAmmoTag;
    /*  10 */ short basicQSTag;
    /*  12 */ short basicUCTag;
    /*  14 */ short upgQSTag;
    /*  16 */ short megaUpgQSTag;
    /*  18 */ short upgUCTag;
    /*  1a */ short megaUpgUCTag;
    /*  1c */ short upgGotTag;
    /*  1e */ short megaUpgGotTag;
    /*  20 */ short mobyClass;
    /*  22 */ short mobyClass2;
    /*  24 */ short pvarSize1;
    /*  26 */ short pvarSize2;
    /*  28 */ char isWeapon;
    /*  29 */ char plateID;
    /*  2a */ char basicPlateID;
    /*  2b */ char upgPlateID;
    /*  2c */ signed char type;
    /*  2d */ signed char joint;
    /*  2e */ signed char handGadgetType;
    /*  2f */ char knockback;
    /*  30 */ short fullFireAnim;
    /*  32 */ short armFireAnimDefault;
    /*  34 */ short armFireAnimCrouch;
    /*  36 */ unsigned short icon;
    /*  38 */ short ammotag;
    /*  3a */ short upgAmmotag;
    /*  3c */ short ammoClass;
    /*  3e */ short ammoAmount;
    /*  40 */ unsigned short padButton;
    /*  42 */ short maxAmmo;
    /*  44 */ short mpMaxAmmo;
    /*  46 */ char cycleFire;
    /*  47 */ char rootID;
    /*  48 */ float metersPerSec1;
    /*  4c */ float shotsPerSec1;
    /*  50 */ GadgetPrice gadgetPrices;
    /*  74 */ int pad[3];
    /*  80 */ GadgetFPSData gadgetFPSdata;
    /*  a0 */ GadgetTargetFunc gadgetTargetFunc;
    /*  a4 */ int pad2[3];
} GadgetDef;


/*
 *
 */
struct tNW_GadgetEventMessage
{
	/*   0 */ short int gadgetId;
	/*   2 */ char playerIndex;
	/*   3 */ char gadgetEventType;
	/*   4 */ char extraData;
	/*   8 */ int activeTime;
	/*   c */ unsigned int targetUID;
	/*  10 */ float firingLoc[3];
	/*  1c */ float targetDir[3];
};

/*
 *
 */
typedef struct GadgetEvent
{
	/*   0 */ unsigned char gadgetID;
	/*   1 */ unsigned char cPlayerIndex;
	/*   2 */ char cGadgetType;
	/*   3 */ char gadgetEventType;
	/*   4 */ int iActiveTime;
	/*   8 */ unsigned int targetUID;
	/*  10 */ VECTOR targetOffsetQuat;
	/*  20 */ struct GadgetEvent* pNextGadgetEvent;
	/*  24 */ struct tNW_GadgetEventMessage gadgetEventMsg;
} GadgetEvent;

/*
 *
 */
typedef struct GadgetEntry
{
    short level;
    short sAmmo;
    unsigned int sXP;
    int iActionFrame;
    int modActivePostFX;
    int modActiveWeapon;
    int modActiveBasic[10];
    int modWeapon[2];
} GadgetEntry;

/*
 *
 */
typedef struct GadgetBox
{
	/*   0 */ char initialized;
	/*   1 */ char level;
	/*   2 */ char bButtonDown[10];
	/*   c */ short int sButtonUpFrames[10];
	/*  20 */ char cNumGadgetEvents;
	/*  21 */ char modBasic[8];
	/*  2a */ short int modPostFX;
	/*  2c */ struct GadgetEvent* pNextGadgetEvent;
	/*  30 */ struct GadgetEvent gadgetEventSlots[32];
	/* a30 */ struct GadgetEntry gadgets[32];
} GadgetBox;

/*
 *
 */
typedef struct GadgetLevelDef
{
    int level;
    int levelUpExperience;
    int mpLevelUpExperience;
    int padding;
    float gadgetDamage[4];
} GadgetLevelDef;

typedef GadgetLevelDef GadgetDefsEntry;

typedef struct GadgetMegaLevelInfo {
    int levelUpExperience;
    float damageIncrement;
    int levelUpExperienceBase;
    int ipadB;
} GadgetMegaLevelInfo;

typedef struct Weapon_ThirdPerson {
    float maxYaw;
    float maxElv;
    float maxRange;
    float scaleElv;
    float scaleAng;
    float blendFactorLimit;
} Weapon_ThirdPerson;

typedef struct Weapon_Interface_t {
    void (*SetSoftAim)();
    void (*GetSoftAim)();
} Weapon_Interface_t;


/*
 *
 */
typedef struct WeaponDefsData
{
    GadgetDefsEntry Entries[10];
} WeaponDefsData;

/*
 *
 */
typedef struct WrenchDefsData
{
    GadgetDefsEntry Entries[8];
} WrenchDefsData;

/*
 * NAME :		WEAPON_IDS
 * 
 * DESCRIPTION :
 * 			Defines the value for each weapon id.
 * 
 * NOTES :
 *          
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
enum WEAPON_IDS
{
    WEAPON_ID_EMPTY =               0,
    WEAPON_ID_WRENCH =              1,
    WEAPON_ID_VIPERS =              2,
    WEAPON_ID_MAGMA_CANNON =        3,
    WEAPON_ID_ARBITER =             4,
    WEAPON_ID_FUSION_RIFLE =        5,
    WEAPON_ID_MINE_LAUNCHER =       6,
    WEAPON_ID_B6 =                  7,
    WEAPON_ID_OMNI_SHIELD =         8,
    WEAPON_ID_EMP =                 12,
    WEAPON_ID_HACKER_RAY =          13,
    WEAPON_ID_SWINGSHOT =           14,
    WEAPON_ID_FLAIL =               15
};

/*
 * NAME :		WEAPON_SLOT_INDEX
 * 
 * DESCRIPTION :
 * 			Defines the equip slot index for each weapon.
 * 
 * NOTES :
 *          
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
enum WEAPON_SLOT_INDEX
{
    WEAPON_SLOT_WRENCH =              0,
    WEAPON_SLOT_VIPERS =              1,
    WEAPON_SLOT_MAGMA_CANNON =        2,
    WEAPON_SLOT_ARBITER =             3,
    WEAPON_SLOT_FUSION_RIFLE =        4,
    WEAPON_SLOT_MINE_LAUNCHER =       5,
    WEAPON_SLOT_B6 =                  6,
    WEAPON_SLOT_FLAIL =               7,
    WEAPON_SLOT_OMNI_SHIELD =         8
};

/*
 * NAME :		ALPHA_MOD_IDS
 * 
 * DESCRIPTION :
 * 			Defines the value for each alpha mod.
 * 
 * NOTES :
 *          
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
enum ALPHA_MOD_IDS
{
    ALPHA_MOD_EMPTY =                   0,
    ALPHA_MOD_SPEED =                   1,
    ALPHA_MOD_AMMO =                    2,
    ALPHA_MOD_AIMING =                  3,
    ALPHA_MOD_IMPACT =                  4,
    ALPHA_MOD_AREA =                    5,
    ALPHA_MOD_XP =                      6,
    ALPHA_MOD_JACKPOT =                 7,
    ALPHA_MOD_NANOLEECH =               8,
};

/*
 * NAME :		OMEGA_MOD_IDS
 * 
 * DESCRIPTION :
 * 			Defines the value for each omega mod.
 * 
 * NOTES :
 *          
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
enum OMEGA_MOD_IDS
{
    OMEGA_MOD_EMPTY =                   0,
    OMEGA_MOD_NAPALM =                  1,
    OMEGA_MOD_TIME_BOMB =               2,
    OMEGA_MOD_FREEZE =                  3,
    OMEGA_MOD_MINI_BOMB =               4,
    OMEGA_MOD_MORPH =                   5,
    OMEGA_MOD_BRAINWASH =               6,
    OMEGA_MOD_ACID =                    7,
    OMEGA_MOD_SHOCK =                   8,
};

/*
 * NAME :		weaponGetGunLevelDefs
 * 
 * DESCRIPTION :
 * 			Returns pointer to array of weapon level definitions starting at dual vipers.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      slotId      :           Slot index.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
WeaponDefsData* weaponGetGunLevelDefs(void);

/*
 * NAME :		weaponGetFlailLevelDefs
 * 
 * DESCRIPTION :
 * 			Returns pointer to block of flail level definitions.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      slotId      :           Slot index.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
WeaponDefsData* weaponGetFlailLevelDefs(void);

/*
 * NAME :		weaponGetWrenchLevelDefs
 * 
 * DESCRIPTION :
 * 			Returns pointer to block of wrench level definitions.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      slotId      :           Slot index.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
WrenchDefsData* weaponGetWrenchLevelDefs(void);

/*
 * NAME :		weaponSlotToId
 * 
 * DESCRIPTION :
 * 			Converts a WEAPON_SLOT_INDEX to the respective WEAPON_IDS
 * 
 * NOTES :
 * 
 * ARGS : 
 *      slotId      :           Slot index.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
int weaponSlotToId(int slotId);

/*
 * NAME :		weaponIdToSlot
 * 
 * DESCRIPTION :
 * 			Converts a WEAPON_IDS to the respective WEAPON_SLOT_INDEX
 * 
 * NOTES :
 * 
 * ARGS : 
 *      id      :               Weapon id.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
int weaponIdToSlot(int id);

/*
 * NAME :		weaponSetDamage
 * 
 * DESCRIPTION :
 * 			Sets the damage of the given weapon at the given level.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      weaponId        :           Target weapon.
 *      level           :           Target weapon level.
 *      damage          :           Target damage.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
void weaponSetDamage(int weaponId, int level, float damage);

/*
 * NAME :		weaponTurnOnHoloshields
 * 
 * DESCRIPTION :
 * 			Enables holoshields for use in collision detection.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
void weaponTurnOnHoloshields(int team);

/*
 * NAME :		weaponTurnOffHoloshields
 * 
 * DESCRIPTION :
 * 			Disables holoshields for use in collision detection.
 * 
 * NOTES :
 *          Always call this after you are done using weaponTurnOnHoloshields().
 * 
 * ARGS : 
 *      weaponId        :           Target weapon.
 *      level           :           Target weapon level.
 *      damage          :           Target damage.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
void weaponTurnOffHoloshields(void);

#endif // _LIBRAC4_WEAPON_H_
