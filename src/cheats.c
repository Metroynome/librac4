#include "moby.h"
#include "cheats.h"
#include "game.h"
#include "string.h"
#include "types.h"
#include "interop.h"

/* Region-local addresses. */
#if RAC4_PAL
#define CHEAT_MIRROR_WORLD                                 (*(u8*)0x0021DEB1)
#define CHEAT_HUD_COLOR                                    (*(u8*)0x0021DEB2)
#define CHEAT_SMF_WRENCH                                   (*(u8*)0x0021DEB5)
#define CHEAT_VEHICLE_MORPH_MOD                            (*(u8*)0x0021DEB6)
#define CHEAT_SUPER_BLOOM                                  (*(u8*)0x0021DEB7)
#define CHEAT_COLORBLIND_MODE                              (*(u8*)0x0021DEB8)
#define CHEAT_WEATHER_MODE                                 (*(u8*)0x0021DEB9)
#define CHEAT_GANGSTA_GUNS                                 (*(u8*)0x0021DEBA)
#define CHEAT_KILL_QWARK                                   (*(u8*)0x0021DEBB)
#define CHEAT_NINJA_RATCHET                                (*(u8*)0x0021DEBC)
#define CHEAT_REMOVE_HELMET                                (*(u8*)0x0021DEBD)
#define CHEAT_CACHED_MIRROR_WORLD                          (*(u8*)0x0021DEC1)
#define CHEAT_CACHED_HUD_COLOR                             (*(u8*)0x0021DEC2)
#define CHEAT_CACHED_SMF_WRENCH                            (*(u8*)0x0021DEC5)
#define CHEAT_CACHED_VEHICLE_MORPH_MOD                     (*(u8*)0x0021DEC6)
#define CHEAT_CACHED_SUPER_BLOOM                           (*(u8*)0x0021DEC7)
#define CHEAT_CACHED_COLORBLIND_MODE                       (*(u8*)0x0021DEC8)
#define CHEAT_CACHED_WEATHER_MODE                          (*(u8*)0x0021DEC9)
#define CHEAT_CACHED_GANGSTA_GUNS                          (*(u8*)0x0021DECA)
#define CHEAT_CACHED_KILL_QWARK                            (*(u8*)0x0021DECB)
#define CHEAT_CACHED_NINJA_RATCHET                         (*(u8*)0x0021DECC)
#define CHEAT_CACHED_REMOVE_HELMET                         (*(u8*)0x0021DECD)
#elif RAC4_NTSCJ || RAC4_NTSCK
#define CHEAT_MIRROR_WORLD                                 (*(u8*)0x00238631)
#define CHEAT_HUD_COLOR                                    (*(u8*)0x00238632)
#define CHEAT_SMF_WRENCH                                   (*(u8*)0x00238635)
#define CHEAT_VEHICLE_MORPH_MOD                            (*(u8*)0x00238636)
#define CHEAT_SUPER_BLOOM                                  (*(u8*)0x00238637)
#define CHEAT_COLORBLIND_MODE                              (*(u8*)0x00238638)
#define CHEAT_WEATHER_MODE                                 (*(u8*)0x00238639)
#define CHEAT_GANGSTA_GUNS                                 (*(u8*)0x0023863A)
#define CHEAT_KILL_QWARK                                   (*(u8*)0x0023863B)
#define CHEAT_NINJA_RATCHET                                (*(u8*)0x0023863C)
#define CHEAT_REMOVE_HELMET                                (*(u8*)0x0023863D)
#define CHEAT_CACHED_MIRROR_WORLD                          (*(u8*)0x00238641)
#define CHEAT_CACHED_HUD_COLOR                             (*(u8*)0x00238642)
#define CHEAT_CACHED_SMF_WRENCH                            (*(u8*)0x00238645)
#define CHEAT_CACHED_VEHICLE_MORPH_MOD                     (*(u8*)0x00238646)
#define CHEAT_CACHED_SUPER_BLOOM                           (*(u8*)0x00238647)
#define CHEAT_CACHED_COLORBLIND_MODE                       (*(u8*)0x00238648)
#define CHEAT_CACHED_WEATHER_MODE                          (*(u8*)0x00238649)
#define CHEAT_CACHED_GANGSTA_GUNS                          (*(u8*)0x0023864A)
#define CHEAT_CACHED_KILL_QWARK                            (*(u8*)0x0023864B)
#define CHEAT_CACHED_NINJA_RATCHET                         (*(u8*)0x0023864C)
#define CHEAT_CACHED_REMOVE_HELMET                         (*(u8*)0x0023864D)
#else
#define CHEAT_MIRROR_WORLD                                 (*(u8*)0x0021DE31)
#define CHEAT_HUD_COLOR                                    (*(u8*)0x0021DE32)
#define CHEAT_SMF_WRENCH                                   (*(u8*)0x0021DE35)
#define CHEAT_VEHICLE_MORPH_MOD                            (*(u8*)0x0021DE36)
#define CHEAT_SUPER_BLOOM                                  (*(u8*)0x0021DE37)
#define CHEAT_COLORBLIND_MODE                              (*(u8*)0x0021DE38)
#define CHEAT_WEATHER_MODE                                 (*(u8*)0x0021DE39)
#define CHEAT_GANGSTA_GUNS                                 (*(u8*)0x0021DE3A)
#define CHEAT_KILL_QWARK                                   (*(u8*)0x0021DE3B)
#define CHEAT_NINJA_RATCHET                                (*(u8*)0x0021DE3C)
#define CHEAT_REMOVE_HELMET                                (*(u8*)0x0021DE3D)
#define CHEAT_CACHED_MIRROR_WORLD                          (*(u8*)0x0021DE41)
#define CHEAT_CACHED_HUD_COLOR                             (*(u8*)0x0021DE42)
#define CHEAT_CACHED_SMF_WRENCH                            (*(u8*)0x0021DE45)
#define CHEAT_CACHED_VEHICLE_MORPH_MOD                     (*(u8*)0x0021DE46)
#define CHEAT_CACHED_SUPER_BLOOM                           (*(u8*)0x0021DE47)
#define CHEAT_CACHED_COLORBLIND_MODE                       (*(u8*)0x0021DE48)
#define CHEAT_CACHED_WEATHER_MODE                          (*(u8*)0x0021DE49)
#define CHEAT_CACHED_GANGSTA_GUNS                          (*(u8*)0x0021DE4A)
#define CHEAT_CACHED_KILL_QWARK                            (*(u8*)0x0021DE4B)
#define CHEAT_CACHED_NINJA_RATCHET                         (*(u8*)0x0021DE4C)
#define CHEAT_CACHED_REMOVE_HELMET                         (*(u8*)0x0021DE4D)
#endif


#if RAC4_PAL
VariableAddress_t vaCheatUpdateFunc = {
    .MainMenu = 0x004AA178,
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
};
#elif RAC4_NTSCJ || RAC4_NTSCK
VariableAddress_t vaCheatUpdateFunc = {
    .MainMenu = 0x004CE178,
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
};
#else
VariableAddress_t vaCheatUpdateFunc = {
    .MainMenu = 0x004AA178,
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
};
#endif

#if RAC4_PAL
#define weatherModeReal 0x0022035C
#define weatherModeReal_MainMenu 0x0022035C
#elif RAC4_NTSCJ || RAC4_NTSCK
#define weatherModeReal 0x0023AADC
#define weatherModeReal_MainMenu 0x0023AADC
#else
#define weatherModeReal 0x002202DC
#define weatherModeReal_MainMenu 0x002202DC
#endif

#define CHEAT_UPDATE_FUNC                           ((void(*)(int))GetAddress(&vaCheatUpdateFunc))

#define CHEAT_WEATHER_MODE_REAL                     (*(int*)weatherModeReal)



//--------------------------------------------------------
int cheatsDisableHealthboxes(void)
{
    int count = 0;
    Moby* moby = mobyListGetStart();

    // Iterate through mobys and disable healthboxes
    while ((moby = mobyFindNextByOClass(moby, MOBY_ID_HEALTH_BOX_MULT)))
    {
        // move to 0,0,0
        memset(moby->pos, 0, sizeof(moby->pos));

        // move orb to 0,0,0
        if (moby->pVar)
        {
            void * subPtr = (void*)(*(u32*)(moby->pVar));
            if (subPtr)
            {
                Moby * orb = (Moby*)(*(u32*)(subPtr + 0x98));
                if (orb)
                {
                    memset(orb->pos, 0, sizeof(orb->pos));
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
