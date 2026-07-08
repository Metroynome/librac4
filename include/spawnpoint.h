/***************************************************
 * FILENAME :		spawnpoint.h
 * 
 * DESCRIPTION :
 * 		Contains spawnpoint specific offsets and structures for Ratchet and Clank 4.
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBRAC4_SPAWNPOINT_H_
#define _LIBRAC4_SPAWNPOINT_H_

#include "math3d.h"
#include "common.h"

/*
 * NAME :		SpawnPoint
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
typedef struct SpawnPoint
{
    MATRIX M0;
    MATRIX M1;
} SpawnPoint;

typedef struct Path {
    /* 0x0 */ int nNodes;
    /* 0x4 */ int bPathNormalized;
    /* 0x8 */ char pad[8];
    /* 0x10 */ VECTOR nodes[0];
} Path_t;

/*
 * NAME :		spawnPointGetCount
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
__LIBRAC4_GETTER__ int spawnPointGetCount();

/*
 * NAME :		hillPointGetCount
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
__LIBRAC4_GETTER__ short hillPointGetCount();

/*
 * NAME :		hillPointSetCount
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
__LIBRAC4_SETTER__ void hillPointSetCount(short count);

/*
 * NAME :		hillPointGetIndex
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
__LIBRAC4_GETTER__ int hillPointGetIndex(int id);

/*
 * NAME :		hillPointSetIndex
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
__LIBRAC4_SETTER__ void hillPointSetIndex(int id, int value);

/*
 * NAME :		spawnPointGet
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
__LIBRAC4_GETTER__ SpawnPoint * spawnPointGet(int index);

/*
 * NAME :		spawnPointSet
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
__LIBRAC4_SETTER__ void spawnPointSet(SpawnPoint * sp, int index);

#endif // _LIBRAC4_SPAWNPOINT_H_
