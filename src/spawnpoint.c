#include <tamtypes.h>
#include "string.h"
#include "spawnpoint.h"
#include "game.h"
#include "types.h"

/* Region-local addresses. */
#if RAC4_PAL
#define SPAWNPOINTS         ((SpawnPoint*)(*(u32*)0x002228A0))
#define SP_COUNT            (*(int*)0x002228A4)
#define SP_HILL_PTR         (*(u32*)0x00222718)
#elif RAC4_NTSCJ || RAC4_NTSCK
#define SPAWNPOINTS         ((SpawnPoint*)(*(u32*)0x0023D020))
#define SP_COUNT            (*(int*)0x0023D024)
#define SP_HILL_PTR         (*(u32*)0x0023CE98)
#else
#define SPAWNPOINTS         ((SpawnPoint*)(*(u32*)0x00222820))
#define SP_COUNT            (*(int*)0x00222824)
#define SP_HILL_PTR         (*(u32*)0x00222698)
#endif

/*
 * Player 1's hud.
 */
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
