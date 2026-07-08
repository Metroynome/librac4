#include "hud.h"
#include "game.h"
#include <tamtypes.h>
#include "types.h"

/* Region-local addresses. */
#if RAC4_PAL
#define HUD_P1          ((PlayerHUDFlags*)0x0030D960)
#define HUD_P2          ((PlayerHUDFlags*)0x0030D970)
#elif RAC4_NTSCJ || RAC4_NTSCK
#define HUD_P1          ((PlayerHUDFlags*)0x003280E0)
#define HUD_P2          ((PlayerHUDFlags*)0x003280F0)
#else
#define HUD_P1          ((PlayerHUDFlags*)0x0030D8E0)
#define HUD_P2          ((PlayerHUDFlags*)0x0030D8F0)
#endif

/*
 * Player 1's hud.
 */

PlayerHUDFlags * hudGetPlayerFlags(int localPlayerIndex)
{
    if (localPlayerIndex == 0)
        return HUD_P1;
    else if (localPlayerIndex == 1)
        return HUD_P2;

    return 0;
}
