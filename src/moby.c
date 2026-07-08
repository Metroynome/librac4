#include "moby.h"
#include <string.h>

/* Region-local addresses. */
#if RAC4_PAL
#define BEGIN_MOBY_PTR                          ((Moby**)0x00222814)
#define END_MOBY_PTR                            ((Moby**)0x00222830)
#define MOBY_CLASS_LOADED_ADDR                  ((u16*)0x00249EB0)
#define MOBY_CLASS_INDEX_ADDR                   ((u8*)0x0024A190)
#define MOBY_CLASS_LIST_ADDR                    ((struct MobyClass**)0x00249640)
#define MOBY_SPAWNABLE_COUNT                    (*(int*)0x00222810)
#elif RAC4_NTSCJ || RAC4_NTSCK
#define BEGIN_MOBY_PTR                          ((Moby**)0x0023CF94)
#define END_MOBY_PTR                            ((Moby**)0x0023CFB0)
#define MOBY_CLASS_LOADED_ADDR                  ((u16*)0x00264630)
#define MOBY_CLASS_INDEX_ADDR                   ((u8*)0x00264910)
#define MOBY_CLASS_LIST_ADDR                    ((struct MobyClass**)0x00263D40)
#define MOBY_SPAWNABLE_COUNT                    (*(int*)0x0023CF90)
#else
#define BEGIN_MOBY_PTR                          ((Moby**)0x00222794)
#define END_MOBY_PTR                            ((Moby**)0x002227B0)
#define MOBY_CLASS_LOADED_ADDR                  ((u16*)0x00249E30)
#define MOBY_CLASS_INDEX_ADDR                   ((u8*)0x0024A110)
#define MOBY_CLASS_LIST_ADDR                    ((struct MobyClass**)0x002495C0)
#define MOBY_SPAWNABLE_COUNT                    (*(int*)0x00222790)
#endif

//--------------------------------------------------------
/*
 * Returns pointer to the start of the moby list.
 */
Moby * mobyListGetStart(void)
{
    return *BEGIN_MOBY_PTR;
}

/*
 * Returns pointer to the end of the moby list.
 */
Moby * mobyListGetEnd(void)
{
    return *END_MOBY_PTR;
}

u16 * mobyGetLoadedMobyClassList(void)
{
    return MOBY_CLASS_LOADED_ADDR;
}


/*
 * Returns non-zero if the given moby is destroyed.
 */
int mobyIsDestroyed(Moby* moby)
{
    return moby && moby->state <= -2;
}

/*
 * 
 */
int mobyGetNumSpawnableMobys(void)
{
    return MOBY_SPAWNABLE_COUNT;
}

/*
 * Returns a pointer to the next living moby of the given oClass.
 * Returns NULL if none found.
 */
Moby* mobyFindNextByOClass(Moby* start, int oClass)
{
    Moby* mEnd = mobyListGetEnd();
    
  // find
  if (oClass > 0 && start) {
    while (start < mEnd && (start->oClass != oClass || mobyIsDestroyed(start)))
      ++start;
  }

    // found
    if (start < mEnd)
        return start;
    
    // couldn't find
    return NULL;
}

/*
 * Returns a pointer to the moby with the given uid.
 * Returns NULL if none found.
 */
Moby* mobyFindByUID(int uid)
{
  Moby* mStart = mobyListGetStart();
  Moby* mEnd = mobyListGetEnd();
  
  while (mStart < mEnd)
  {
    if (mStart->UID == uid)
      return mStart;
    ++mStart;
  }

  return NULL;
}

/*
 * Returns pointer to the moby's MobyClass (if loaded).
 */
void * mobyGetClass(int oClass)
{
  int mClass = MOBY_CLASS_INDEX_ADDR[oClass];
  if (mClass == 255) return NULL;

  return MOBY_CLASS_LIST_ADDR[mClass];
}

/*
 * Returns non-zero if the given o class is loaded in the map.
 */
int mobyClassIsLoaded(int oClass)
{
    u16 * list = mobyGetLoadedMobyClassList();
    u16 class = 0;
    while ((class = *list++) != 0xFFFF)
    {
        if (class == oClass)
            return 1;
    }

    return 0;
}

/*
 * Computes the world space joint matrix for the given moby's joint.
 */
void mobyComputeJointWorldMatrix(Moby* moby, int jointIdx, MATRIX out)
{
  if (!moby->jointCache) return;
  if (jointIdx >= moby->jointCnt) return;

  MATRIX* mtxs = (MATRIX*)moby->jointCache;
  memcpy(out, mtxs[jointIdx], sizeof(MATRIX));
  MATRIX mrot;
  memset(mrot, 0, sizeof(mrot));
  memcpy(mrot, moby->rot, 12);
  vector_scale(&out[12], &out[12], moby->scale / 1024.0);
  matrix_multiply(out, out, mrot);
  vector_add(&out[12], &out[12], moby->pos);
}
