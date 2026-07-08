#include "collision.h"
#include "types.h"

/* Region-local addresses. */
#if RAC4_PAL
#define COLL_SPHERE_HIT_MOBIES_ARRAY                         ((Moby**)0x00244E40)
#define COLL_LINE_FIX_HIT_MOBY                               (*(Moby**)0x0023F998)
#define COLL_LINE_FIX_HIT_POSITION                           ((float*)0x0023F9A0)
#define COLL_LINE_FIX_HIT_NORMAL                             ((float*)0x0023F9C0)
#define COLL_LINE_FIX_HIT_COLLISION_ID                       (*(u8*)0x0023F99C)
#elif RAC4_NTSCJ || RAC4_NTSCK
#define COLL_SPHERE_HIT_MOBIES_ARRAY                         ((Moby**)0x0025F5C0)
#define COLL_LINE_FIX_HIT_MOBY                               (*(Moby**)0x0025A118)
#define COLL_LINE_FIX_HIT_POSITION                           ((float*)0x0025A120)
#define COLL_LINE_FIX_HIT_NORMAL                             ((float*)0x0025A140)
#define COLL_LINE_FIX_HIT_COLLISION_ID                       (*(u8*)0x0025A11C)
#else
#define COLL_SPHERE_HIT_MOBIES_ARRAY                         ((Moby**)0x00244DC0)
#define COLL_LINE_FIX_HIT_MOBY                               (*(Moby**)0x0023F918)
#define COLL_LINE_FIX_HIT_POSITION                           ((float*)0x0023F920)
#define COLL_LINE_FIX_HIT_NORMAL                             ((float*)0x0023F940)
#define COLL_LINE_FIX_HIT_COLLISION_ID                       (*(u8*)0x0023F91C)
#endif

/*
 * 
 */

/*
 * 
 */

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
