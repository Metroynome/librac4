#include "hud.h"
#include "game.h"
#include <tamtypes.h>
#include "types.h"

/*
 * Player 1's hud.
 */
#define HUD_P1			((PlayerHUDFlags*)RAC4_LEVEL_CODE0(0xEF760))

/*
 * Player 2's hud.
 */
#define HUD_P2			((PlayerHUDFlags*)RAC4_LEVEL_CODE0(0xEF770))


PlayerHUDFlags * hudGetPlayerFlags(int localPlayerIndex)
{
    if (localPlayerIndex == 0)
        return HUD_P1;
    else if (localPlayerIndex == 1)
        return HUD_P2;

    return 0;
}
