/***************************************************
 * FILENAME :		gid.h
 * 
 * DESCRIPTION :
 * 
 * NOTES :
 * 		Each offset is determined per app id.
 * 		This is to ensure compatibility between versions of Ratchet and Clank 4.
 * 		
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBRAC4_GID_H_
#define _LIBRAC4_GID_H_

#include <tamtypes.h>

/*
 * NAME :		Gid
 * 
 * DESCRIPTION :
 * 			Contains the gid definition struct data.
 * 
 * NOTES :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
typedef struct
{
    u32 ObjectIndex : 12;
    u32 ObjectCount : 12;
    u32 ObjectType : 4;
    u32 HostId : 4;
} Gid;

#endif // _LIBRAC4_GID_H_
