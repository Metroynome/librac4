#include "interop.h"
#include "moby.h"
#include <string.h>

/* Native Cooperative overlays (levels 21-35), not campaign or libdl multiplayer.
 * Mapped against the retail 1.00 code images in rac-defs.json. */
VariableAddress_t vaCoopMobySnapAnimation = {
#if RAC4_PAL
	.Battledome = 0x595c20,
	.Catacrom = 0x547bd0,
	.Sarathos = 0x547e10,
	.Kronos = 0x56c660,
	.Shaar = 0x53f790,
	.Valix = 0x530d30,
	.Orxon = 0x548e10,
	.Torval = 0x553b90,
	.Stygia = 0x540870,
	.Maraxus = 0x55a2d0,
	.GhostStation = 0x552f90,
	.DreadZoneInterior = 0x564ab0
#elif RAC4_NTSCJ
	.Battledome = 0x5acb90,
	.Catacrom = 0x55ef80,
	.Sarathos = 0x55f400,
	.Kronos = 0x583a50,
	.Shaar = 0x557000,
	.Valix = 0x548420,
	.Orxon = 0x560200,
	.Torval = 0x56afc0,
	.Stygia = 0x557f60,
	.Maraxus = 0x571640,
	.GhostStation = 0x56a340,
	.DreadZoneInterior = 0x57bee0
#elif RAC4_NTSCK
	.Battledome = 0x5acb90,
	.Catacrom = 0x55ef80,
	.Sarathos = 0x55f400,
	.Kronos = 0x583a50,
	.Shaar = 0x557000,
	.Valix = 0x548420,
	.Orxon = 0x560200,
	.Torval = 0x56afc0,
	.Stygia = 0x557f60,
	.Maraxus = 0x571640,
	.GhostStation = 0x56a340,
	.DreadZoneInterior = 0x57bee0
#else
	.Battledome = 0x591940,
	.Catacrom = 0x543ef0,
	.Sarathos = 0x5442b0,
	.Kronos = 0x568900,
	.Shaar = 0x53bf30,
	.Valix = 0x52d790,
	.Orxon = 0x545170,
	.Torval = 0x54ff30,
	.Stygia = 0x53ce90,
	.Maraxus = 0x556570,
	.GhostStation = 0x54f2b0,
	.DreadZoneInterior = 0x560c90
#endif
};

VariableAddress_t vaCoopMobyListStart = {
#if RAC4_PAL
	.Battledome = 0x222e14,
	.Catacrom = 0x222894,
	.Sarathos = 0x222814,
	.Kronos = 0x222c14,
	.Shaar = 0x222694,
	.Valix = 0x222694,
	.Orxon = 0x222714,
	.Torval = 0x222994,
	.Stygia = 0x222794,
	.Maraxus = 0x222994,
	.GhostStation = 0x222894,
	.DreadZoneInterior = 0x222794
#elif RAC4_NTSCJ
	.Battledome = 0x23d514,
	.Catacrom = 0x23cf14,
	.Sarathos = 0x23cf14,
	.Kronos = 0x23d314,
	.Shaar = 0x23cd94,
	.Valix = 0x23cd94,
	.Orxon = 0x23ce14,
	.Torval = 0x23d094,
	.Stygia = 0x23ce94,
	.Maraxus = 0x23d094,
	.GhostStation = 0x23cf94,
	.DreadZoneInterior = 0x23ce94
#elif RAC4_NTSCK
	.Battledome = 0x23d514,
	.Catacrom = 0x23cf14,
	.Sarathos = 0x23cf14,
	.Kronos = 0x23d314,
	.Shaar = 0x23cd94,
	.Valix = 0x23cd94,
	.Orxon = 0x23ce14,
	.Torval = 0x23d094,
	.Stygia = 0x23ce94,
	.Maraxus = 0x23d094,
	.GhostStation = 0x23cf94,
	.DreadZoneInterior = 0x23ce94
#else
	.Battledome = 0x222d14,
	.Catacrom = 0x222794,
	.Sarathos = 0x222714,
	.Kronos = 0x222b14,
	.Shaar = 0x222614,
	.Valix = 0x222614,
	.Orxon = 0x222694,
	.Torval = 0x222914,
	.Stygia = 0x222714,
	.Maraxus = 0x222914,
	.GhostStation = 0x222814,
	.DreadZoneInterior = 0x222694
#endif
};

VariableAddress_t vaCoopMobyListEnd = {
#if RAC4_PAL
	.Battledome = 0x222e30,
	.Catacrom = 0x2228b0,
	.Sarathos = 0x222830,
	.Kronos = 0x222c30,
	.Shaar = 0x2226b0,
	.Valix = 0x2226b0,
	.Orxon = 0x222730,
	.Torval = 0x2229b0,
	.Stygia = 0x2227b0,
	.Maraxus = 0x2229b0,
	.GhostStation = 0x2228b0,
	.DreadZoneInterior = 0x2227b0
#elif RAC4_NTSCJ
	.Battledome = 0x23d530,
	.Catacrom = 0x23cf30,
	.Sarathos = 0x23cf30,
	.Kronos = 0x23d330,
	.Shaar = 0x23cdb0,
	.Valix = 0x23cdb0,
	.Orxon = 0x23ce30,
	.Torval = 0x23d0b0,
	.Stygia = 0x23ceb0,
	.Maraxus = 0x23d0b0,
	.GhostStation = 0x23cfb0,
	.DreadZoneInterior = 0x23ceb0
#elif RAC4_NTSCK
	.Battledome = 0x23d530,
	.Catacrom = 0x23cf30,
	.Sarathos = 0x23cf30,
	.Kronos = 0x23d330,
	.Shaar = 0x23cdb0,
	.Valix = 0x23cdb0,
	.Orxon = 0x23ce30,
	.Torval = 0x23d0b0,
	.Stygia = 0x23ceb0,
	.Maraxus = 0x23d0b0,
	.GhostStation = 0x23cfb0,
	.DreadZoneInterior = 0x23ceb0
#else
	.Battledome = 0x222d30,
	.Catacrom = 0x2227b0,
	.Sarathos = 0x222730,
	.Kronos = 0x222b30,
	.Shaar = 0x222630,
	.Valix = 0x222630,
	.Orxon = 0x2226b0,
	.Torval = 0x222930,
	.Stygia = 0x222730,
	.Maraxus = 0x222930,
	.GhostStation = 0x222830,
	.DreadZoneInterior = 0x2226b0
#endif
};


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
