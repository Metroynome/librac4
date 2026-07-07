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

/*
 *
 */
#define GAME_TIMELIMT_MINUTES                   (*(u8*)0x002126D0)

/*
 *
 */
#define GAME_KILLS_TO_WIN                       (*(u8*)0x002126D1)

/*
 *
 */
#define GAME_SURVIVOR                           (*(u8*)0x002126D6)

/*
 *
 */
#define GAME_RESPAWN_TIME                       (*(u8*)0x002126DC)


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
