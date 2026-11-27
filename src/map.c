#include "map.h"
#include "game.h"
#include "interop.h"
#include "types.h"

/* Native relative mission selection, distinct from Mission->ActiveMission's data link. */
VariableAddress_t vaTravelMissionIndex = {
#if RAC4_PAL
	.Battledome = 0x0021ec58,
	.Catacrom = 0x0021eb18,
	.Sarathos = 0x0021ead8,
	.Kronos = 0x0021ead8,
	.Shaar = 0x0021ead8,
	.Valix = 0x0021ead8,
	.Orxon = 0x0021ead8,
	.Torval = 0x0021ead8,
	.Stygia = 0x0021ead8,
	.Maraxus = 0x0021ead8,
	.GhostStation = 0x0021ead8,
	.DreadZoneInterior = 0x0021eb18
#elif RAC4_NTSCJ || RAC4_NTSCK
	.Battledome = 0x00239358,
	.Catacrom = 0x00239218,
	.Sarathos = 0x002391d8,
	.Kronos = 0x002391d8,
	.Shaar = 0x002391d8,
	.Valix = 0x002391d8,
	.Orxon = 0x002391d8,
	.Torval = 0x002391d8,
	.Stygia = 0x002391d8,
	.Maraxus = 0x002391d8,
	.GhostStation = 0x002391d8,
	.DreadZoneInterior = 0x00239218
#else
	.Battledome = 0x0021ebd8,
	.Catacrom = 0x0021ea98,
	.Sarathos = 0x0021ea58,
	.Kronos = 0x0021ea58,
	.Shaar = 0x0021ea58,
	.Valix = 0x0021ea58,
	.Orxon = 0x0021ea58,
	.Torval = 0x0021ea58,
	.Stygia = 0x0021ea58,
	.Maraxus = 0x0021ea58,
	.GhostStation = 0x0021ea58,
	.DreadZoneInterior = 0x0021ea98
#endif
};


/* Region-local addresses. */
#if RAC4_PAL
#define SaveFileLevel (*(int*)0x001719FC)
MISSIONLOAD * Mission = (MISSIONLOAD*)0x00171228;
#elif RAC4_NTSCJ || RAC4_NTSCK
#define SaveFileLevel (*(int*)0x001718FC)
MISSIONLOAD * Mission = (MISSIONLOAD*)0x00171128;
#else
#define SaveFileLevel (*(int*)0x0017197C)
MISSIONLOAD * Mission = (MISSIONLOAD*)0x001711A8;
#endif

//--------------------------------------------------------
VariableAddress_t vaSwitchToLevelFunc = {
#if RAC4_PAL
	.MainMenu = 0x0045d258,
	.Battledome = 0x0056b370,
	.Catacrom = 0x0051d470,
	.Sarathos = 0x0051d6d8,
	.Kronos = 0x00541d18,
	.Shaar = 0x00515048,
	.Valix = 0x005067c0,
	.Orxon = 0x0051e6d0,
	.Torval = 0x00529448,
	.Stygia = 0x00516230,
	.Maraxus = 0x0052faf0,
	.GhostStation = 0x00528908,
	.DreadZoneInterior = 0x0053a3b0,
#elif RAC4_NTSCJ || RAC4_NTSCK
	.MainMenu = 0x00480988,
	.Battledome = 0x005838c0,
	.Catacrom = 0x00535de8,
	.Sarathos = 0x00536280,
	.Kronos = 0x0055a700,
	.Shaar = 0x0052de70,
	.Valix = 0x0051f468,
	.Orxon = 0x00537078,
	.Torval = 0x00541e30,
	.Stygia = 0x0052eed8,
	.Maraxus = 0x00548418,
	.GhostStation = 0x00541270,
	.DreadZoneInterior = 0x00552db0,
#else
	.MainMenu = 0x0045ca60,
	.Battledome = 0x005687b0,
	.Catacrom = 0x0051aed8,
	.Sarathos = 0x0051b2b0,
	.Kronos = 0x0053f6f0,
	.Shaar = 0x00512f20,
	.Valix = 0x00504918,
	.Orxon = 0x0051c128,
	.Torval = 0x00526f20,
	.Stygia = 0x00513f88,
	.Maraxus = 0x0052d4c8,
	.GhostStation = 0x00526320,
	.DreadZoneInterior = 0x00537ce0,
#endif
};

//--------------------------------------------------------
int mapMaskHasMask(int value, int maskValue)
{
    return (value & maskValue) == maskValue;
}

//--------------------------------------------------------
int mapIdToMask(int mapId)
{
    switch (mapId)
    {
        case MAP_ID_BATTLEDOME: return MAP_MASK_BATTLEDOME;
        case MAP_ID_CATACROM: return MAP_MASK_CATACROM;
        case MAP_ID_SARATHOS: return MAP_MASK_SARATHOS;
        case MAP_ID_KRONOS: return MAP_MASK_KRONOS;
        case MAP_ID_SHAAR: return MAP_MASK_SHAAR;
        case MAP_ID_VALIX: return MAP_MASK_VALIX;
        case MAP_ID_ORXON: return MAP_MASK_ORXON;
        case MAP_ID_TORVAL: return MAP_MASK_TORVAL;
        case MAP_ID_STYGIA: return MAP_MASK_STYGIA;
        case MAP_ID_MARAXUS: return MAP_MASK_MARAXUS;
        case MAP_ID_GHOST_STATION: return MAP_MASK_GHOST_STATION;
        case MAP_ID_DREADZONE_INTERIOR: return MAP_MASK_DREADZONE_INTERIOR;
        default: return 0;
    }
}

//--------------------------------------------------------
int mapMaskToId(int mapMask)
{
    switch (mapMask)
    {
        case MAP_MASK_BATTLEDOME: return MAP_ID_BATTLEDOME;
        case MAP_MASK_CATACROM: return MAP_ID_CATACROM;
        case MAP_MASK_SARATHOS: return MAP_ID_SARATHOS;
        case MAP_MASK_KRONOS: return MAP_ID_KRONOS;
        case MAP_MASK_SHAAR: return MAP_ID_SHAAR;
        case MAP_MASK_VALIX: return MAP_ID_VALIX;
        case MAP_MASK_ORXON: return MAP_ID_ORXON;
        case MAP_MASK_TORVAL: return MAP_ID_TORVAL;
        case MAP_MASK_STYGIA: return MAP_ID_STYGIA;
        case MAP_MASK_MARAXUS: return MAP_ID_MARAXUS;
        case MAP_MASK_GHOST_STATION: return MAP_ID_GHOST_STATION;
        case MAP_MASK_DREADZONE_INTERIOR: return MAP_ID_DREADZONE_INTERIOR;
        default: return 0;
    }
}

int mapIsActiveLevel(int levelId)
{
    return Level == levelId;
}

int mapGetActiveMission(void)
{
    return Mission->ActiveMission;
}

void mapResetMission(void)
{
    Mission->ResetLevel = 1;
}

void mapSwitchToLevel(int levelId, int missionId)
{
    internal_mapSwitchToLevel(levelId, 1, missionId);
}

