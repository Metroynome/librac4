#include "guber.h"
#include "types.h"
#include "interop.h"

#if RAC4_PAL
#define firstGuberMobyPtr 0x00220790
#define firstGuberMobyPtr_MainMenu 0x00220790
#elif RAC4_NTSCJ || RAC4_NTSCK
#define firstGuberMobyPtr 0x0023AF10
#define firstGuberMobyPtr_MainMenu 0x0023AF10
#else
#define firstGuberMobyPtr 0x00220710
#define firstGuberMobyPtr_MainMenu 0x00220710
#endif

//--------------------------------------------------------
#define FIRST_GUBER_MOBY_PTR                         ((GuberMoby**)firstGuberMobyPtr)

/*
 * Returns the first guber moby.
 */
GuberMoby * guberMobyGetFirst(void)
{
    return *FIRST_GUBER_MOBY_PTR;
}
