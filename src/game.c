#include "game.h"
#include "map.h"
#include "ui.h"
#include "types.h"
#include "interop.h"

#if defined(RAC4_PAL)
VariableAddress_t vaGameActive = {
    .Battledome = 0x0021E26C,
    .Catacrom = 0x0021E26C,
    .Sarathos = 0x0021E26C,
    .Kronos = 0x0021E26C,
    .Shaar = 0x0021E26C,
    .Valix = 0x0021E26C,
    .Orxon = 0x0021E26C,
    .Torval = 0x0021E26C,
    .Stygia = 0x0021E26C,
    .Maraxus = 0x0021E26C,
    .GhostStation = 0x0021E26C,
    .DreadZoneInterior = 0x0021E26C,
    .MainMenu = 0x0021E26C,
    .MultiplayerMenu = 0x0021E26C
};
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
VariableAddress_t vaGameActive = {
    .Battledome = 0x002389EC,
    .Catacrom = 0x002389EC,
    .Sarathos = 0x002389EC,
    .Kronos = 0x002389EC,
    .Shaar = 0x002389EC,
    .Valix = 0x002389EC,
    .Orxon = 0x002389EC,
    .Torval = 0x002389EC,
    .Stygia = 0x002389EC,
    .Maraxus = 0x002389EC,
    .GhostStation = 0x002389EC,
    .DreadZoneInterior = 0x002389EC,
    .MainMenu = 0x002389EC,
    .MultiplayerMenu = 0x002389EC
};
#else
VariableAddress_t vaGameActive = {
    .Battledome = 0x0021E1EC,
    .Catacrom = 0x0021E1EC,
    .Sarathos = 0x0021E1EC,
    .Kronos = 0x0021E1EC,
    .Shaar = 0x0021E1EC,
    .Valix = 0x0021E1EC,
    .Orxon = 0x0021E1EC,
    .Torval = 0x0021E1EC,
    .Stygia = 0x0021E1EC,
    .Maraxus = 0x0021E1EC,
    .GhostStation = 0x0021E1EC,
    .DreadZoneInterior = 0x0021E1EC,
    .MainMenu = 0x0021E1EC,
    .MultiplayerMenu = 0x0021E1EC
};
#endif

#if defined(RAC4_PAL)
VariableAddress_t vaSceneLoaded = {
    .Battledome = 0x002202EC,
    .Catacrom = 0x002202EC,
    .Sarathos = 0x002202EC,
    .Kronos = 0x002202EC,
    .Shaar = 0x002202EC,
    .Valix = 0x002202EC,
    .Orxon = 0x002202EC,
    .Torval = 0x002202EC,
    .Stygia = 0x002202EC,
    .Maraxus = 0x002202EC,
    .GhostStation = 0x002202EC,
    .DreadZoneInterior = 0x002202EC,
    .MainMenu = 0x002202EC,
    .MultiplayerMenu = 0x002202EC
};
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
VariableAddress_t vaSceneLoaded = {
    .Battledome = 0x0023AA6C,
    .Catacrom = 0x0023AA6C,
    .Sarathos = 0x0023AA6C,
    .Kronos = 0x0023AA6C,
    .Shaar = 0x0023AA6C,
    .Valix = 0x0023AA6C,
    .Orxon = 0x0023AA6C,
    .Torval = 0x0023AA6C,
    .Stygia = 0x0023AA6C,
    .Maraxus = 0x0023AA6C,
    .GhostStation = 0x0023AA6C,
    .DreadZoneInterior = 0x0023AA6C,
    .MainMenu = 0x0023AA6C,
    .MultiplayerMenu = 0x0023AA6C
};
#else
VariableAddress_t vaSceneLoaded = {
    .Battledome = 0x0022026C,
    .Catacrom = 0x0022026C,
    .Sarathos = 0x0022026C,
    .Kronos = 0x0022026C,
    .Shaar = 0x0022026C,
    .Valix = 0x0022026C,
    .Orxon = 0x0022026C,
    .Torval = 0x0022026C,
    .Stygia = 0x0022026C,
    .Maraxus = 0x0022026C,
    .GhostStation = 0x0022026C,
    .DreadZoneInterior = 0x0022026C,
    .MainMenu = 0x0022026C,
    .MultiplayerMenu = 0x0022026C
};
#endif

/*
 * 
 */
#define ACTIVE_LEVEL_ID                     (*(int*)RAC4_ADDR_GAME_MAP_ID)
#define SAVE_FILE_LEVEL_ID                  (*(int*)RAC4_ADDR_SAVE_FILE_LEVEL_ID)
#define GAME_MISSION_ACTIVE                 (*(u32*)RAC4_ADDR_MISSION_AREA)
#define GAME_ACTIVE                         (*(int*)GetAddress(&vaGameActive))
#define SCENE_LOADED                        (*(int*)GetAddress(&vaSceneLoaded))

/*
 * When non-zero start menu is open in-game.
 */
#define GAME_START_MENU_OPEN                (*(int*)RAC4_LEVEL_CODE0(0xDBD20))

/*
 * How many milliseconds for the game to last.
 * Negative if no time limit.
 */
#define GAME_TIME_LIMIT                     (*(int*)RAC4_LEVEL_CODE0(0x14F480))

#define GAME_START_TIME                     (*(int*)RAC4_LEVEL_CODE0(0x14F484))

/*
 * Time (ms) that the game ended.
 */
#define GAME_TIME_ENDGAME                   (*(u32*)RAC4_LEVEL_CODE0(0x14F4E4))

/*
 * Whether or not the game has ended.
 */
#define GAME_HAS_ENDED                      (GAME_TIME_ENDGAME > 0)

/*
 * Game time (ms).
 */
#define GAME_TIME                           (*(int*)RAC4_ADDR_GAME_TIME)

/*
 * 
 */
#define GAME_DEATH_BARRIER_Y                (*(float*)RAC4_LEVEL_CODE0(0x44FC))

/*
 * When non-zero, it refreshes the in-game scoreboard.
 */
#define GAME_SCOREBOARD_REFRESH_FLAG        (*(u32*)RAC4_LEVEL_CODE0(0xF20C8))

/*
 * Target scoreboard value.
 */
#define GAME_SCOREBOARD_TARGET              (*(u32*)RAC4_LEVEL_CODE0(0xDBF04))

/*
 * Collection of scoreboard items.
 */
#define GAME_SCOREBOARD_ARRAY               ((ScoreboardItem**)RAC4_LEVEL_CODE0(0xDBECC))

/*
 * Number of items in the scoreboard.
 */
#define GAME_SCOREBOARD_ITEM_COUNT          (*(u32*)RAC4_LEVEL_CODE0(0xDBE4C))


int isInGame(void)
{
    // my version
    // return ACTIVE_LEVEL_ID == SAVE_FILE_LEVEL_ID;
    // return ACTIVE_LEVEL_ID != 0 && GAME_MISSION_ACTIVE != -1;
    // dan's version
    // return GAME_ACTIVE && SCENE_LOADED == 1;
    return ACTIVE_LEVEL_ID == SAVE_FILE_LEVEL_ID && GAME_MISSION_ACTIVE != -1;
}

int isInMenus(void)
{
    // No idea why this works.  To my understanding, it shouldn't.

    // if active pointer is not the profile/menu special case
    if (uiGetActivePointer() != uiGetPointer(UI_MENU_ID_ONLINE_LOCAL_EDIT_PROFILE_MENU))
    {
        return ACTIVE_LEVEL_ID == 0 && SCENE_LOADED == 1;
    }
    else
    {
        return ACTIVE_LEVEL_ID == 1 && GAME_MISSION_ACTIVE == -1;
    }
}

int isSceneLoading(void)
{
    return SCENE_LOADED != 1;
}

int gameIsStartMenuOpen(void)
{
    return GAME_START_MENU_OPEN;
}

int gameHasEnded(void)
{
    return GAME_HAS_ENDED;
}

int gameGetTime(void)
{
    return GAME_TIME;
}

int gameGetFinishedExitTime(void)
{
    return GAME_TIME_ENDGAME;
}

float gameGetDeathHeight(void)
{
    return GAME_DEATH_BARRIER_Y;
}

void gameSetDeathHeight(float height)
{
    GAME_DEATH_BARRIER_Y = height;
}

int gameGetRawTimeLimit(void)
{
    return GAME_TIME_LIMIT;
}
