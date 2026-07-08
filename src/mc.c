#include "mc.h"
#include <kernel.h>
#include "string.h"
#include "types.h"

#define MC_SEMA                         (*(u32*)RAC4_ADDR_MC_SEMA)
#define MC_RESULT                       (*(s32*)RAC4_ADDR_MC_RESULT)

//--------------------------------------------------------
int McPollSema(void)
{
    if (*(u32*)RAC4_ADDR_MC_CALLBACK_READY != 0)
    {
        if (((int (*)(int,int,int))RAC4_ADDR_MC_CALLBACK_FUNC)(1, RAC4_ADDR_MC_CALLBACK_ARG0, RAC4_ADDR_MC_CALLBACK_ARG1) != 1)
            return -1;
    }
    
    return *(int*)RAC4_ADDR_MC_CALLBACK_ARG1;
}

//--------------------------------------------------------
int McGetResult(void)
{
    return MC_RESULT;
}
