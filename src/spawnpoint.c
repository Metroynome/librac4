#include <tamtypes.h>
#include "string.h"
#include "spawnpoint.h"
#include "game.h"
#include "types.h"

/*
 * Player 1's hud.
 */
#define SPAWNPOINTS		    ((SpawnPoint*)(*(u32*)RAC4_LEVEL_CODE0(0x46A0)))

/*
 *
 */
#define SP_COUNT    (*(int*)RAC4_LEVEL_CODE0(0x46A4))

/*
 * Player 2's hud.
 */
#define SP_HILL_PTR	        (*(u32*)RAC4_LEVEL_CODE0(0x4518))

int spawnPointGetCount()
{
    return SP_COUNT;
}

short hillPointGetCount()
{
    u32 * hillInfo = (u32*)SP_HILL_PTR;
    if (!hillInfo)
        return 0;

    return *((short*)(hillInfo + 12) + 1);
}

void hillPointSetCount(short count)
{
    u32 hillInfo = (u32)SP_HILL_PTR;
    if (!hillInfo)
        return;

    *(short*)(hillInfo + 0x32) = count;
}

int hillPointGetIndex(int id)
{
    u32 hillInfo = (u32)SP_HILL_PTR;
    if (!hillInfo)
        return -1;

    return ((u32*)(hillInfo + 0x50))[id];
}

void hillPointSetIndex(int id, int value)
{
    u32 hillInfo = (u32)SP_HILL_PTR;
    if (!hillInfo)
        return;

    ((u32*)(hillInfo + 0x50))[id] = value;
}

SpawnPoint * spawnPointGet(int index)
{
    SpawnPoint * spawnPoints = SPAWNPOINTS;
    if (!spawnPoints)
        return NULL;

    return &spawnPoints[index];
}

void spawnPointSet(SpawnPoint * sp, int index)
{
    SpawnPoint * spawnPoints = SPAWNPOINTS;
    if (!spawnPoints)
        return;

    memcpy(&spawnPoints[index], sp, sizeof(SpawnPoint));
}
