/***************************************************
 * FILENAME :		math.h
 * 
 * DESCRIPTION :
 * 		Contains many math related function definitions found in Ratchet and Clank 4.
 * 
 * NOTES :
 * 		Each offset is determined per app id.
 * 		This is to ensure compatibility between versions of Ratchet and Clank 4.
 * 		
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBRAC4_MATH_H_
#define _LIBRAC4_MATH_H_

#include "common.h"

//--------------------------------------------------------
#define MATH_PI                         ((float)3.141596)
#define MATH_TAU                        (MATH_PI * (float)2.0)
#define MATH_E                          ((float)2.7182818)
#define MATH_DT                         ((float)0.0166666666)
#define MATH_RAD2DEG                    ((float)180 / MATH_PI)
#define MATH_DEG2RAD                    (MATH_PI / (float)180)

//--------------------------------------------------------
__LIBRAC4_INLINE__ float cosf(float theta);
__LIBRAC4_INLINE__ float sinf(float theta);
__LIBRAC4_INLINE__ float acosf(float v);
__LIBRAC4_INLINE__ float asinf(float v);
__LIBRAC4_INLINE__ float sqrtf(float f);
__LIBRAC4_INLINE__ float powf(float base, float exp);
__LIBRAC4_INLINE__ float fabsf(float f);
__LIBRAC4_INLINE__ float lerpf(float a, float b, float t);
__LIBRAC4_INLINE__ float signf(float a);
__LIBRAC4_INLINE__ float maxf(float a, float b);
__LIBRAC4_INLINE__ float minf(float a, float b);
__LIBRAC4_INLINE__ float ceilf(float a);
__LIBRAC4_INLINE__ float floorf(float a);
__LIBRAC4_INLINE__ float lerpfAngle(float a, float b, float t);
__LIBRAC4_INLINE__ float clamp(float v, float min, float max);
__LIBRAC4_INLINE__ float clampAngle(float theta);
__LIBRAC4_INLINE__ double fmod(double x, double y);
__LIBRAC4_INLINE__ float fastmodf(float x, float y);
__LIBRAC4_INLINE__ float atan2f(float y, float x);

#endif // _LIBRAC4_MATH_H_
