#include <tamtypes.h>
#include "gamesettings.h"
#include "math.h"
#include "string.h"
#include "types.h"

/* Region-local addresses. */
#if RAC4_PAL
#define gameOptionsAddress 0x0021E070
#define gameSettingsAddress 0x0021E068
#elif RAC4_NTSCJ || RAC4_NTSCK
#define gameOptionsAddress 0x002387F0
#define gameSettingsAddress 0x002387E8
#else
#define gameOptionsAddress 0x0021DFF0
#define gameSettingsAddress 0x0021DFE8
#endif



/*
 * Points to the active game settings.
 */
#define GameSettingsGlobal                  ((GameSettings*)(*(u32*)gameSettingsAddress))


/*
 * Points to the active game options.
 */
#define GameOptionsGlobal                   ((GameOptions*)(*(u32*)gameOptionsAddress))


//--------------------------------------------------------
GameSettings * gameGetSettings(void)
{
    return GameSettingsGlobal;
}

//--------------------------------------------------------
GameOptions * gameGetOptions(void)
{
    return GameOptionsGlobal;
}
