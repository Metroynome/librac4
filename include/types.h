#ifndef _LIBRAC4_TYPES_H_
#define _LIBRAC4_TYPES_H_

#include <tamtypes.h>

#if (RAC4_PAL_V100 || RAC4_NTSCU_V100 || RAC4_NTSCJ_V100 || RAC4_NTSCK_V100) && !RAC4_V100
#define RAC4_V100 1
#endif

#if (RAC_PAL_V100 || RAC_NTSCU_V100 || RAC_NTSCJ_V100 || RAC_NTSCK_V100) && !RAC_V100
#define RAC_V100 1
#endif

#if (RAC4_PAL || RAC4_NTSCU || RAC4_NTSCJ || RAC4_NTSCK) && !RAC4_V100
#define RAC4_V100 1
#endif

#if RAC4_V100 && !RAC_V100
#define RAC_V100 1
#endif

#if RAC4_PAL_V100 && !RAC4_PAL
#define RAC4_PAL 1
#endif

#if RAC4_NTSCU_V100 && !RAC4_NTSCU
#define RAC4_NTSCU 1
#endif

#if RAC4_NTSCJ_V100 && !RAC4_NTSCJ
#define RAC4_NTSCJ 1
#endif

#if RAC4_NTSCK_V100 && !RAC4_NTSCK
#define RAC4_NTSCK 1
#endif

#if RAC4_PAL && !RAC_PAL
#define RAC_PAL 1
#endif

#if RAC4_NTSCU && !RAC_NTSCU
#define RAC_NTSCU 1
#endif

#if RAC4_NTSCJ && !RAC_NTSCJ
#define RAC_NTSCJ 1
#endif

#if RAC4_NTSCK && !RAC_NTSCK
#define RAC_NTSCK 1
#endif

#if RAC4_PAL && RAC4_V100 && !RAC4_PAL_V100
#define RAC4_PAL_V100 1
#endif

#if RAC4_NTSCU && RAC4_V100 && !RAC4_NTSCU_V100
#define RAC4_NTSCU_V100 1
#endif

#if RAC4_NTSCJ && RAC4_V100 && !RAC4_NTSCJ_V100
#define RAC4_NTSCJ_V100 1
#endif

#if RAC4_NTSCK && RAC4_V100 && !RAC4_NTSCK_V100
#define RAC4_NTSCK_V100 1
#endif

#if RAC_PAL && RAC_V100 && !RAC_PAL_V100
#define RAC_PAL_V100 1
#endif

#if RAC_NTSCU && RAC_V100 && !RAC_NTSCU_V100
#define RAC_NTSCU_V100 1
#endif

#if RAC_NTSCJ && RAC_V100 && !RAC_NTSCJ_V100
#define RAC_NTSCJ_V100 1
#endif

#if RAC_NTSCK && RAC_V100 && !RAC_NTSCK_V100
#define RAC_NTSCK_V100 1
#endif

#define __LIBRAC4_GETTER__    inline
#define __LIBRAC4_SETTER__    inline
#define __LIBRAC4_INLINE__    inline

#define true 1
#define false 0
typedef _Bool bool;



#endif
