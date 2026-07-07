#include "string.h"
#include "player.h"
#include "team.h"
#include "camera.h"
#include "types.h"

#define GAME_CAMERA                         ((GameCamera*)RAC4_LEVEL_CODE0(0xEC40))

//--------------------------------------------------------------------------------
GameCamera* cameraGetGameCamera(int cameraIndex)
{
    return GAME_CAMERA + cameraIndex;
}
