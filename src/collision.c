#include "collision.h"
#include "types.h"

/*
 * 
 */
#define COLL_SPHERE_HIT_MOBIES_ARRAY                         ((Moby**)RAC4_LEVEL_CODE0(0x26C40))

/*
 * 
 */
#define COLL_LINE_FIX_HIT_MOBY                               (*(Moby**)RAC4_LEVEL_CODE0(0x21798))
#define COLL_LINE_FIX_HIT_POSITION                           ((float*)RAC4_LEVEL_CODE0(0x217A0))
#define COLL_LINE_FIX_HIT_NORMAL                             ((float*)RAC4_LEVEL_CODE0(0x217C0))
#define COLL_LINE_FIX_HIT_COLLISION_ID                       (*(u8*)RAC4_LEVEL_CODE0(0x2179C))


Moby** CollMobysSphere_Fix_GetHitMobies(void)
{
  return COLL_SPHERE_HIT_MOBIES_ARRAY;
}

Moby* CollLine_Fix_GetHitMoby(void)
{
  return COLL_LINE_FIX_HIT_MOBY;
}

float* CollLine_Fix_GetHitPosition(void)
{
  return COLL_LINE_FIX_HIT_POSITION;
}

float* CollLine_Fix_GetHitNormal(void)
{
  return COLL_LINE_FIX_HIT_NORMAL;
}

u8 CollLine_Fix_GetHitCollisionId(void)
{
  return COLL_LINE_FIX_HIT_COLLISION_ID;
}
