
#include "moby.h"
#include "cheats.h"
#include "game.h"
#include "string.h"
#include "types.h"
#include "interop.h"

#if defined(RAC4_PAL)
VariableAddress_t vaCheatUpdateFunc = {
    .Battledome = 0x00480F78,
    .Catacrom = 0x004792F8,
    .Sarathos = 0x00478578,
    .Kronos = 0x0047AAF8,
    .Shaar = 0x00478178,
    .Valix = 0x00478578,
    .Orxon = 0x004784F8,
    .Torval = 0x00479878,
    .Stygia = 0x004777F8,
    .Maraxus = 0x00479778,
    .GhostStation = 0x00479CF8,
    .DreadZoneInterior = 0x0047DEF8,
    .MainMenu = 0x004AA178,
    .MultiplayerMenu = 0x005A8578
};
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
VariableAddress_t vaCheatUpdateFunc = {
    .Battledome = 0x0049BA78,
    .Catacrom = 0x00493CF8,
    .Sarathos = 0x00492FF8,
    .Kronos = 0x00495578,
    .Shaar = 0x00492C78,
    .Valix = 0x00492FF8,
    .Orxon = 0x00492F78,
    .Torval = 0x004942F8,
    .Stygia = 0x00492278,
    .Maraxus = 0x00494278,
    .GhostStation = 0x00494778,
    .DreadZoneInterior = 0x004989F8,
    .MainMenu = 0x004CE178,
    .MultiplayerMenu = 0x005C2C78
};
#else
VariableAddress_t vaCheatUpdateFunc = {
    .Battledome = 0x00480DF8,
    .Catacrom = 0x004790F8,
    .Sarathos = 0x00478378,
    .Kronos = 0x0047A8F8,
    .Shaar = 0x00478078,
    .Valix = 0x00478478,
    .Orxon = 0x00478378,
    .Torval = 0x004796F8,
    .Stygia = 0x00477678,
    .Maraxus = 0x00479678,
    .GhostStation = 0x00479B78,
    .DreadZoneInterior = 0x0047DD78,
    .MainMenu = 0x004AA178,
    .MultiplayerMenu = 0x005A8078
};
#endif

#if defined(RAC4_PAL)
VariableAddress_t vaWeatherModeReal = {
    .Battledome = 0x0022035C,
    .Catacrom = 0x0022035C,
    .Sarathos = 0x0022035C,
    .Kronos = 0x0022035C,
    .Shaar = 0x0022035C,
    .Valix = 0x0022035C,
    .Orxon = 0x0022035C,
    .Torval = 0x0022035C,
    .Stygia = 0x0022035C,
    .Maraxus = 0x0022035C,
    .GhostStation = 0x0022035C,
    .DreadZoneInterior = 0x0022035C,
    .MainMenu = 0x0022035C,
    .MultiplayerMenu = 0x0022035C
};
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
VariableAddress_t vaWeatherModeReal = {
    .Battledome = 0x0023AADC,
    .Catacrom = 0x0023AADC,
    .Sarathos = 0x0023AADC,
    .Kronos = 0x0023AADC,
    .Shaar = 0x0023AADC,
    .Valix = 0x0023AADC,
    .Orxon = 0x0023AADC,
    .Torval = 0x0023AADC,
    .Stygia = 0x0023AADC,
    .Maraxus = 0x0023AADC,
    .GhostStation = 0x0023AADC,
    .DreadZoneInterior = 0x0023AADC,
    .MainMenu = 0x0023AADC,
    .MultiplayerMenu = 0x0023AADC
};
#else
VariableAddress_t vaWeatherModeReal = {
    .Battledome = 0x002202DC,
    .Catacrom = 0x002202DC,
    .Sarathos = 0x002202DC,
    .Kronos = 0x002202DC,
    .Shaar = 0x002202DC,
    .Valix = 0x002202DC,
    .Orxon = 0x002202DC,
    .Torval = 0x002202DC,
    .Stygia = 0x002202DC,
    .Maraxus = 0x002202DC,
    .GhostStation = 0x002202DC,
    .DreadZoneInterior = 0x002202DC,
    .MainMenu = 0x002202DC,
    .MultiplayerMenu = 0x002202DC
};
#endif

#define CHEAT_MIRROR_WORLD                          (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x00))
#define CHEAT_HUD_COLOR                             (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x01))
#define CHEAT_SMF_WRENCH                            (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x04))
#define CHEAT_VEHICLE_MORPH_MOD                     (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x05))
#define CHEAT_SUPER_BLOOM                           (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x06))
#define CHEAT_COLORBLIND_MODE                       (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x07))
#define CHEAT_WEATHER_MODE                          (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x08))
#define CHEAT_GANGSTA_GUNS                          (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x09))
#define CHEAT_KILL_QWARK                            (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x0A))
#define CHEAT_NINJA_RATCHET                         (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x0B))
#define CHEAT_REMOVE_HELMET                         (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x0C))

#define CHEAT_CACHED_MIRROR_WORLD                   (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x10))
#define CHEAT_CACHED_HUD_COLOR                      (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x11))
#define CHEAT_CACHED_SMF_WRENCH                     (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x14))
#define CHEAT_CACHED_VEHICLE_MORPH_MOD              (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x15))
#define CHEAT_CACHED_SUPER_BLOOM                    (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x16))
#define CHEAT_CACHED_COLORBLIND_MODE                (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x17))
#define CHEAT_CACHED_WEATHER_MODE                   (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x18))
#define CHEAT_CACHED_GANGSTA_GUNS                   (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x19))
#define CHEAT_CACHED_KILL_QWARK                     (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x1A))
#define CHEAT_CACHED_NINJA_RATCHET                  (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x1B))
#define CHEAT_CACHED_REMOVE_HELMET                  (*(u8*)(RAC4_ADDR_CHEAT_BASE + 0x1C))

/*
  This Needs Updating to Single Player
    - Troy
*/
#define CHEAT_UPDATE_FUNC                           ((void(*)(int))GetAddress(&vaCheatUpdateFunc))

#define CHEAT_WEATHER_MODE_REAL                     (*(int*)GetAddress(&vaWeatherModeReal))



//--------------------------------------------------------
int cheatsDisableHealthboxes(void)
{
    int count = 0;
    Moby* moby = mobyListGetStart();

    // Iterate through mobys and disable healthboxes
    while ((moby = mobyFindNextByOClass(moby, MOBY_ID_HEALTH_BOX_MULT)))
    {
        // move to 0,0,0
        memset(moby->Position, 0, sizeof(moby->Position));

        // move orb to 0,0,0
        if (moby->PVar)
        {
            void * subPtr = (void*)(*(u32*)(moby->PVar));
            if (subPtr)
            {
                Moby * orb = (Moby*)(*(u32*)(subPtr + 0x98));
                if (orb)
                {
                    memset(orb->Position, 0, sizeof(orb->Position));
                    ++count;
                }
            }
        }

        ++moby; // increment moby
    }
    
    return count;
}

//--------------------------------------------------------
void cheatsApplyMirrorWorld(int isOn)
{
    // 
    if (CHEAT_CACHED_MIRROR_WORLD == isOn)
        return;

    // Apply
    CHEAT_MIRROR_WORLD = isOn ? 1 : 0;
    
    if (isInGame())
    {
        // Update
        CHEAT_UPDATE_FUNC(0);
    }
    else
    {
        // If not in game then just set cached value
        CHEAT_CACHED_MIRROR_WORLD = isOn ? 1 : 0;
    }
}

//--------------------------------------------------------
void cheatsApplyColorblindMode(u8 mode)
{
    CHEAT_COLORBLIND_MODE = mode;
}

//--------------------------------------------------------
void cheatsApplyWeather(u8 weatherId)
{
    CHEAT_WEATHER_MODE = weatherId;
    CHEAT_CACHED_WEATHER_MODE = weatherId;

    // 
    if (weatherId == WEATHER_OFF)
    {
        // Disable weather
        if (CHEAT_WEATHER_MODE_REAL < 0)
            CHEAT_WEATHER_MODE_REAL = weatherId;

        return;
    }

    // Apply
    CHEAT_WEATHER_MODE_REAL = -weatherId;
}
