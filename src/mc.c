#include "mc.h"
#include <kernel.h>
#include "string.h"
#include "types.h"

/* Region-local addresses. */
#if RAC4_PAL
#define mcCallbackArg0Address 0x00171B70
#define mcCallbackArg1Address 0x00171B74
#define mcCallbackFuncAddress 0x0013A7A0
#define mcCallbackReadyAddress 0x00171B84
#define mcResultAddress 0x001AEE40
#define mcSemaAddress 0x00167C7C
#elif RAC4_NTSCJ || RAC4_NTSCK
#define mcCallbackArg0Address 0x00171A70
#define mcCallbackArg1Address 0x00171A74
#define mcCallbackFuncAddress 0x0013A7A0
#define mcCallbackReadyAddress 0x00171A84
#define mcResultAddress 0x001AEE40
#define mcSemaAddress 0x00167B7C
#else
#define mcCallbackArg0Address 0x00171AF0
#define mcCallbackArg1Address 0x00171AF4
#define mcCallbackFuncAddress 0x0013A7A0
#define mcCallbackReadyAddress 0x00171B04
#define mcResultAddress 0x001AEE40
#define mcSemaAddress 0x00167BFC
#endif


#define MC_SEMA                         (*(u32*)mcSemaAddress)
#define MC_RESULT                       (*(s32*)mcResultAddress)

//--------------------------------------------------------
int McPollSema(void)
{
    if (*(u32*)mcCallbackReadyAddress != 0)
    {
        if (((int (*)(int,int,int))mcCallbackFuncAddress)(1, mcCallbackArg0Address, mcCallbackArg1Address) != 1)
            return -1;
    }
    
    return *(int*)mcCallbackArg1Address;
}

//--------------------------------------------------------
int McGetResult(void)
{
    return MC_RESULT;
}
