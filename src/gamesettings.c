#include <tamtypes.h>
#include "gamesettings.h"
#include "math.h"
#include "string.h"
#include "types.h"


/*
 * Points to the active game settings.
 */
#define GLOBAL_GAMESETTINGS			            ((GameSettings*)(*(u32*)RAC4_ADDR_GLOBAL_GAMESETTINGS_PTR))


/*
 * Points to the active game options.
 */
#define GLOBAL_GAMEOPTIONS			            ((GameOptions*)(*(u32*)RAC4_ADDR_GLOBAL_GAMEOPTIONS_PTR))


//--------------------------------------------------------
GameSettings * gameGetSettings(void)
{
    return GLOBAL_GAMESETTINGS;
}

//--------------------------------------------------------
GameOptions * gameGetOptions(void)
{
    return GLOBAL_GAMEOPTIONS;
}
