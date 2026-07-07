#include <tamtypes.h>
#include "weapon.h"
#include "interop.h"

#if defined(RAC4_PAL)
VariableAddress_t vaWrenchDefsTable = {
    .Battledome = 0x003BDA98,
    .Catacrom = 0x003B8198,
    .Sarathos = 0x003B7518,
    .Kronos = 0x003B8D98,
    .Shaar = 0x003B7218,
    .Valix = 0x003B7B98,
    .Orxon = 0x003B7518,
    .Torval = 0x003B8498,
    .Stygia = 0x003B6F98,
    .Maraxus = 0x003B7D98,
    .GhostStation = 0x003B8898,
    .DreadZoneInterior = 0x003BD118,
    .MainMenu = 0x003E2918,
    .MultiplayerMenu = 0x004A5498
};
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
VariableAddress_t vaWrenchDefsTable = {
    .Battledome = 0x003D8298,
    .Catacrom = 0x003D2918,
    .Sarathos = 0x003D1D18,
    .Kronos = 0x003D3598,
    .Shaar = 0x003D1A18,
    .Valix = 0x003D2398,
    .Orxon = 0x003D1D18,
    .Torval = 0x003D2C98,
    .Stygia = 0x003D1798,
    .Maraxus = 0x003D2598,
    .GhostStation = 0x003D3098,
    .DreadZoneInterior = 0x003D7918,
    .MainMenu = 0x003FD098,
    .MultiplayerMenu = 0x004BFC18
};
#else
VariableAddress_t vaWrenchDefsTable = {
    .Battledome = 0x003BDA98,
    .Catacrom = 0x003B8198,
    .Sarathos = 0x003B7518,
    .Kronos = 0x003B8D98,
    .Shaar = 0x003B7298,
    .Valix = 0x003B7C18,
    .Orxon = 0x003B7598,
    .Torval = 0x003B8518,
    .Stygia = 0x003B7018,
    .Maraxus = 0x003B7E18,
    .GhostStation = 0x003B8918,
    .DreadZoneInterior = 0x003BD118,
    .MainMenu = 0x003E2918,
    .MultiplayerMenu = 0x004A5498
};
#endif

#if defined(RAC4_PAL)
VariableAddress_t vaWeaponDefsTable = {
    .Battledome = 0x003BDB98,
    .Catacrom = 0x003B8298,
    .Sarathos = 0x003B7618,
    .Kronos = 0x003B8E98,
    .Shaar = 0x003B7318,
    .Valix = 0x003B7C98,
    .Orxon = 0x003B7618,
    .Torval = 0x003B8598,
    .Stygia = 0x003B7098,
    .Maraxus = 0x003B7E98,
    .GhostStation = 0x003B8998,
    .DreadZoneInterior = 0x003BD218,
    .MainMenu = 0x003E2A18,
    .MultiplayerMenu = 0x004A5598
};
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
VariableAddress_t vaWeaponDefsTable = {
    .Battledome = 0x003D8398,
    .Catacrom = 0x003D2A18,
    .Sarathos = 0x003D1E18,
    .Kronos = 0x003D3698,
    .Shaar = 0x003D1B18,
    .Valix = 0x003D2498,
    .Orxon = 0x003D1E18,
    .Torval = 0x003D2D98,
    .Stygia = 0x003D1898,
    .Maraxus = 0x003D2698,
    .GhostStation = 0x003D3198,
    .DreadZoneInterior = 0x003D7A18,
    .MainMenu = 0x003FD198,
    .MultiplayerMenu = 0x004BFD18
};
#else
VariableAddress_t vaWeaponDefsTable = {
    .Battledome = 0x003BDB98,
    .Catacrom = 0x003B8298,
    .Sarathos = 0x003B7618,
    .Kronos = 0x003B8E98,
    .Shaar = 0x003B7398,
    .Valix = 0x003B7D18,
    .Orxon = 0x003B7698,
    .Torval = 0x003B8618,
    .Stygia = 0x003B7118,
    .Maraxus = 0x003B7F18,
    .GhostStation = 0x003B8A18,
    .DreadZoneInterior = 0x003BD218,
    .MainMenu = 0x003E2A18,
    .MultiplayerMenu = 0x004A5598
};
#endif

#if defined(RAC4_PAL)
VariableAddress_t vaFlailDefsTable = {
    .Battledome = 0x003BE758,
    .Catacrom = 0x003B8E58,
    .Sarathos = 0x003B81D8,
    .Kronos = 0x003B9A58,
    .Shaar = 0x003B7ED8,
    .Valix = 0x003B8858,
    .Orxon = 0x003B81D8,
    .Torval = 0x003B9158,
    .Stygia = 0x003B7C58,
    .Maraxus = 0x003B8A58,
    .GhostStation = 0x003B9558,
    .DreadZoneInterior = 0x003BDDD8,
    .MainMenu = 0x003E35D8,
    .MultiplayerMenu = 0x004A6158
};
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
VariableAddress_t vaFlailDefsTable = {
    .Battledome = 0x003D8F58,
    .Catacrom = 0x003D35D8,
    .Sarathos = 0x003D29D8,
    .Kronos = 0x003D4258,
    .Shaar = 0x003D26D8,
    .Valix = 0x003D3058,
    .Orxon = 0x003D29D8,
    .Torval = 0x003D3958,
    .Stygia = 0x003D2458,
    .Maraxus = 0x003D3258,
    .GhostStation = 0x003D3D58,
    .DreadZoneInterior = 0x003D85D8,
    .MainMenu = 0x003FDD58,
    .MultiplayerMenu = 0x004C08D8
};
#else
VariableAddress_t vaFlailDefsTable = {
    .Battledome = 0x003BE758,
    .Catacrom = 0x003B8E58,
    .Sarathos = 0x003B81D8,
    .Kronos = 0x003B9A58,
    .Shaar = 0x003B7F58,
    .Valix = 0x003B88D8,
    .Orxon = 0x003B8258,
    .Torval = 0x003B91D8,
    .Stygia = 0x003B7CD8,
    .Maraxus = 0x003B8AD8,
    .GhostStation = 0x003B95D8,
    .DreadZoneInterior = 0x003BDDD8,
    .MainMenu = 0x003E35D8,
    .MultiplayerMenu = 0x004A6158
};
#endif

#define WRENCH_DEFS_TABLE                   ((WrenchDefsData*)GetAddress(&vaWrenchDefsTable))
#define WEAPON_DEFS_TABLE                   ((WeaponDefsData*)GetAddress(&vaWeaponDefsTable))
#define FLAIL_DEFS_TABLE                    ((WeaponDefsData*)GetAddress(&vaFlailDefsTable))
#define OMNI_DAMAGE_V1_PATCH                (0x003FFE00)
#define OMNI_DAMAGE_V2_PATCH                (0x003FFE10)


WeaponDefsData* weaponGetGunLevelDefs(void)
{
    return WEAPON_DEFS_TABLE;
}

WeaponDefsData* weaponGetFlailLevelDefs(void)
{
    return FLAIL_DEFS_TABLE;
}

WrenchDefsData* weaponGetWrenchLevelDefs(void)
{
    return WRENCH_DEFS_TABLE;
}

int weaponSlotToId(int slotId)
{
    switch (slotId)
    {
        case WEAPON_SLOT_WRENCH: return WEAPON_ID_WRENCH;
        case WEAPON_SLOT_VIPERS: return WEAPON_ID_VIPERS;
        case WEAPON_SLOT_MAGMA_CANNON: return WEAPON_ID_MAGMA_CANNON;
        case WEAPON_SLOT_ARBITER: return WEAPON_ID_ARBITER;
        case WEAPON_SLOT_FUSION_RIFLE: return WEAPON_ID_FUSION_RIFLE;
        case WEAPON_SLOT_MINE_LAUNCHER: return WEAPON_ID_MINE_LAUNCHER;
        case WEAPON_SLOT_B6: return WEAPON_ID_B6;
        case WEAPON_SLOT_FLAIL: return WEAPON_ID_FLAIL;
        case WEAPON_SLOT_OMNI_SHIELD: return WEAPON_ID_OMNI_SHIELD;
        default: return WEAPON_ID_EMPTY;
    }
}

int weaponIdToSlot(int id)
{
    switch (id)
    {
        case WEAPON_ID_WRENCH: return WEAPON_SLOT_WRENCH;
        case WEAPON_ID_VIPERS: return WEAPON_SLOT_VIPERS;
        case WEAPON_ID_MAGMA_CANNON: return WEAPON_SLOT_MAGMA_CANNON;
        case WEAPON_ID_ARBITER: return WEAPON_SLOT_ARBITER;
        case WEAPON_ID_FUSION_RIFLE: return WEAPON_SLOT_FUSION_RIFLE;
        case WEAPON_ID_MINE_LAUNCHER: return WEAPON_SLOT_MINE_LAUNCHER;
        case WEAPON_ID_B6: return WEAPON_SLOT_B6;
        case WEAPON_ID_FLAIL: return WEAPON_SLOT_FLAIL;
        case WEAPON_ID_OMNI_SHIELD: return WEAPON_SLOT_OMNI_SHIELD;
        default: return WEAPON_SLOT_WRENCH;
    }
}

void weaponSetDamage(int weaponId, int level, float damage)
{
    switch (weaponId)
    {
        case WEAPON_ID_WRENCH:
        {
            WRENCH_DEFS_TABLE->Entries[level].Damage[2] = damage;
            break;
        }
        case WEAPON_ID_OMNI_SHIELD:
        {
            if (level == 0)
                *(u16*)OMNI_DAMAGE_V1_PATCH = *(((u16*)&damage)+1);
            else
                *(u16*)OMNI_DAMAGE_V2_PATCH = *(((u16*)&damage)+1);
            break;
        }
        case WEAPON_ID_FLAIL:
        {
            FLAIL_DEFS_TABLE->Entries[level].Damage[2] = damage;
            break;
        }
        default:
        {
            WEAPON_DEFS_TABLE[weaponId - WEAPON_ID_VIPERS].Entries[level].Damage[2] = damage;
            break;
        }
    }
}

