#include "moby.h"
#include "types.h"

//--------------------------------------------------------
#define SPAWN_MOBY_FUNC                         (0x004F7200)
#define BEGIN_MOBY_PTR                          ((Moby**)RAC4_LEVEL_CODE0(0x4614))
#define END_MOBY_PTR                            ((Moby**)RAC4_LEVEL_CODE0(0x4630))
#define MOBY_UPDATE_FUNC                        (0x004FE720)
#define MOBY_DESTROY_FUNC                       (0x004F76A0)
#define MOBY_CLASS_LOADED_ADDR                  ((u16*)RAC4_LEVEL_CODE0(0x2BCB0))

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
    return moby && moby->State <= -2;
}

/*
 * 
 */
int mobyGetNumSpawnableMobys(void)
{
    return *(int*)RAC4_LEVEL_CODE0(0x4610);
}

/*
 * Returns a pointer to the next living moby of the given oclass.
 * Returns NULL if none found.
 */
Moby* mobyFindNextByOClass(Moby* start, int oClass)
{
    Moby* mEnd = mobyListGetEnd();
    
	// find
	if (oClass > 0 && start) {
		while (start < mEnd && (start->OClass != oClass || mobyIsDestroyed(start)))
			++start;
	}

    // found
    if (start < mEnd)
        return start;
    
    // couldn't find
    return NULL;
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
