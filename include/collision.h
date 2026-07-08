/***************************************************
 * FILENAME :		collision.h
 * 
 * DESCRIPTION :
 * 		
 * 		
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBRAC4_COLLISION_H_
#define _LIBRAC4_COLLISION_H_

#include <tamtypes.h>
#include "moby.h"


typedef struct COLL_DAM_OUT { // 0x40
	/* 0x00 */ VECTOR ip;
	/* 0x10 */ VECTOR momentum;
	/* 0x20 */ Moby *pDamager;
	/* 0x24 */ int damageFlags;
	/* 0x28 */ unsigned char damageClass;
	/* 0x29 */ unsigned char damageStrength;
	/* 0x2a */ short unsigned int damageIndex;
	/* 0x2c */ float damageHp;
	/* 0x30 */ int flags;
	/* 0x34 */ float damageHeroHp;
	/* 0x38 */ int shotUID;
	/* 0x3c */ Moby *pMoby;
} COLL_DAM_OUT_t;


/*
 * NAME :		CollMobysSphere_Fix
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
int CollMobysSphere_Fix(VECTOR position, u64 hitFlag, Moby * moby, u64 a3, float radius);


/*
 * NAME :		CollMobysSphere_Fix_GetHitMobies
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ Moby** CollMobysSphere_Fix_GetHitMobies(void);

/*
 * NAME :		CollLine_Fix
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
int CollLine_Fix(VECTOR from, VECTOR to, u64 hitFlag, Moby * moby, u64 t0);

/*
 * NAME :		CollLine_Fix_GetHitMoby
 * 
 * DESCRIPTION :
 * 		 
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ Moby* CollLine_Fix_GetHitMoby(void);

/*
 * NAME :		CollLine_Fix_GetHitPosition
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ float* CollLine_Fix_GetHitPosition(void);

/*
 * NAME :		CollLine_Fix_GetHitNormal
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ float* CollLine_Fix_GetHitNormal(void);

/*
 * NAME :		CollLine_Fix_GetHitCollisionId
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ u8 CollLine_Fix_GetHitCollisionId(void);


#endif // _LIBRAC4_COLLISION_H_
