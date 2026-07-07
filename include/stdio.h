/***************************************************
 * FILENAME :		stdio.h
 * 
 * DESCRIPTION :
 * 		Contains useful functions for debugging.
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBRAC4_STDIO_H_
#define _LIBRAC4_STDIO_H_

#include "common.h"


//--------------------------------------------------------
__LIBRAC4_INLINE__ int sprintf(char * buffer, const char * format, ...);
__LIBRAC4_INLINE__ int snprintf(char * buffer, long n, const char * format, ...);
__LIBRAC4_INLINE__ int printf(const char * format, ...);


//--------------------------------------------------------
#ifdef DEBUG
    #define DPRINTF(fmt, ...)       \
        printf("%s"fmt, "", ##__VA_ARGS__);
#else
    #define DPRINTF(fmt, ...) 
#endif


#endif // _LIBRAC4_STDIO_H_
