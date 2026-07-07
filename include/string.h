/***************************************************
 * FILENAME :		string.h
 * 
 * DESCRIPTION :
 * 
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBRAC4_STRING_H_
#define _LIBRAC4_STRING_H_

#include "common.h"

//--------------------------------------------------------
__LIBRAC4_INLINE__ void * memset(void * ptr, int value, int num);
__LIBRAC4_INLINE__ void * memcpy(void * destination, const void * source, int num);
__LIBRAC4_INLINE__ void * memmove(void * destination, const void * source, int num);
__LIBRAC4_INLINE__ char * strncpy(char *dest, const char *src, int n);
__LIBRAC4_INLINE__ int strlen(char *str);
__LIBRAC4_INLINE__ char * strcmp(const char *str1, const char *str2);

#endif // _LIBRAC4_STRING_H_
