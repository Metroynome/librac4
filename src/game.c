#include "interop.h"
#include "game.h"
#include "map.h"
#include "types.h"

/* Cooperative overlay data, resolved through the native level table. */
VariableAddress_t vaCoopGameMode = {
#if RAC4_PAL
	.Battledome = 0x21de3c,
	.Catacrom = 0x21de3c,
	.Sarathos = 0x21de3c,
	.Kronos = 0x21de3c,
	.Shaar = 0x21de3c,
	.Valix = 0x21de3c,
	.Orxon = 0x21de3c,
	.Torval = 0x21de3c,
	.Stygia = 0x21de3c,
	.Maraxus = 0x21de3c,
	.GhostStation = 0x21de3c,
	.DreadZoneInterior = 0x21de3c
#elif RAC4_NTSCJ || RAC4_NTSCK
	.Battledome = 0x2385bc,
	.Catacrom = 0x2385bc,
	.Sarathos = 0x2385bc,
	.Kronos = 0x2385bc,
	.Shaar = 0x2385bc,
	.Valix = 0x2385bc,
	.Orxon = 0x2385bc,
	.Torval = 0x2385bc,
	.Stygia = 0x2385bc,
	.Maraxus = 0x2385bc,
	.GhostStation = 0x2385bc,
	.DreadZoneInterior = 0x2385bc
#else
	.Battledome = 0x21ddb4,
	.Catacrom = 0x21ddb4,
	.Sarathos = 0x21ddb4,
	.Kronos = 0x21ddb4,
	.Shaar = 0x21ddb4,
	.Valix = 0x21ddb4,
	.Orxon = 0x21ddb4,
	.Torval = 0x21ddb4,
	.Stygia = 0x21ddb4,
	.Maraxus = 0x21ddb4,
	.GhostStation = 0x21ddb4,
	.DreadZoneInterior = 0x21ddb4
#endif
};

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
