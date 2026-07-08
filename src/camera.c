#include "string.h"
#include "player.h"
#include "team.h"
#include "camera.h"
#include "types.h"

/* Region-local addresses. */
#if RAC4_PAL
#define GAME_CAMERA                         ((GameCamera*)0x0022CE40)
#elif RAC4_NTSCJ || RAC4_NTSCK
#define GAME_CAMERA                         ((GameCamera*)0x002475C0)
#else
#define GAME_CAMERA                         ((GameCamera*)0x0022CDC0)
#endif

//--------------------------------------------------------------------------------
GameCamera* cameraGetGameCamera(int cameraIndex)
{
    return GAME_CAMERA + cameraIndex;
}
