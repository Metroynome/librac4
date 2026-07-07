#include "map.h"
#include "interop.h"
#include "types.h"

#define CURRENT_LEVEL (*(int*)RAC4_ADDR_GAME_MAP_ID)
#define MISSION_AREA (RAC4_ADDR_MISSION_AREA)
#define SAVE_FILE_CURRENT_LEVEL (RAC4_ADDR_SAVE_FILE_LEVEL_ID)

MISSIONLOAD * Mission = (MISSIONLOAD*)MISSION_AREA;

//--------------------------------------------------------
#if defined(RAC4_PAL)
VariableAddress_t vaSwitchToLevelFunc = {
    .Battledome = 0x0056B370,
    .Catacrom = 0x0051D470,
    .Sarathos = 0x0051D6D8,
    .Kronos = 0x00541D18,
    .Shaar = 0x00515048,
    .Valix = 0x005067C0,
    .Orxon = 0x0051E6D0,
    .Torval = 0x00529448,
    .Stygia = 0x00516230,
    .Maraxus = 0x0052FAF0,
    .GhostStation = 0x00528908,
    .DreadZoneInterior = 0x0053A3B0,
    .MainMenu = 0,
    .MultiplayerMenu = 0
};
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
VariableAddress_t vaSwitchToLevelFunc = {
    .Battledome = 0x005838C0,
    .Catacrom = 0x00535DE8,
    .Sarathos = 0x00536280,
    .Kronos = 0x0055A700,
    .Shaar = 0x0052DE70,
    .Valix = 0x0051F468,
    .Orxon = 0x00537078,
    .Torval = 0x00541E30,
    .Stygia = 0x0052EED8,
    .Maraxus = 0x00548418,
    .GhostStation = 0x00541270,
    .DreadZoneInterior = 0x00552DB0,
    .MainMenu = 0,
    .MultiplayerMenu = 0
};
#else
VariableAddress_t vaSwitchToLevelFunc = {
    .Battledome = 0x005687B0,
    .Catacrom = 0x0051AED8,
    .Sarathos = 0x0051B2B0,
    .Kronos = 0x0053F6F0,
    .Shaar = 0x00512F20,
    .Valix = 0x00504918,
    .Orxon = 0x0051C128,
    .Torval = 0x00526F20,
    .Stygia = 0x00513F88,
    .Maraxus = 0x0052D4C8,
    .GhostStation = 0x00526320,
    .DreadZoneInterior = 0x00537CE0,
    .MainMenu = 0,
    .MultiplayerMenu = 0
};
#endif

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

int mapIsActiveLevel(int Level)
{
    return CURRENT_LEVEL == Level;
}

int mapGetActiveMission(void)
{
    return Mission->ActiveMission;
}

void mapResetMission(void)
{
    Mission->ResetLevel = 1;
}

void mapSwitchToLevel(int Level, int Mission)
{
    internal_mapSwitchToLevel(Level, 1, Mission);
}

