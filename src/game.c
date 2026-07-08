#include "game.h"
#include "map.h"
#include "types.h"

/* Region-local addresses. */
#if RAC4_PAL
#define SaveFileLevel                       (*(int*)0x001719FC)
#define GameTime                            (*(int*)0x001723F8)
#define gameMode                            (*(volatile gameMode_t*)0x0021E034)
#define currentGameMode                     (*(volatile gameMode_t*)0x0021E034)
#define previousGameMode                    (*(volatile gameMode_t*)0x0021EE40)
#elif RAC4_NTSCJ || RAC4_NTSCK
#define SaveFileLevel                       (*(int*)0x001718FC)
#define GameTime                            (*(int*)0x001722F8)
#define gameMode                            (*(volatile gameMode_t*)0x002387B4)
#define currentGameMode                     (*(volatile gameMode_t*)0x002387B4)
#define previousGameMode                    (*(volatile gameMode_t*)0x002395C0)
#else
#define SaveFileLevel                       (*(int*)0x0017197C)
#define GameTime                            (*(int*)0x00172378)
#define gameMode                            (*(volatile gameMode_t*)0x0021DFB4)
#define currentGameMode                     (*(volatile gameMode_t*)0x0021DFB4)
#define previousGameMode                    (*(volatile gameMode_t*)0x0021EDC0)
#endif

int isInGame(void)
{
    return Level == SaveFileLevel && Mission->ActiveMission != -1;
}

int isInMenus(void)
{
    return Level == 0 || (Level == 1 && Mission->ActiveMission == -1);
}

int gameGetTime(void)
{
    return GameTime;
}
