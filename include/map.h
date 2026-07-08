/***************************************************
 * FILENAME :		map.h
 * 
 * DESCRIPTION :
 * 		Contains map specific offsets and structures for Ratchet and Clank 4.
 * 
 * NOTES :
 * 
 * 		
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBRAC4_MAP_H_
#define _LIBRAC4_MAP_H_

#include <tamtypes.h>

/*
 *
 */
enum MAP_IDS
{
    MAP_ID_BATTLEDOME = 1,
    MAP_ID_CATACROM = 2,
    MAP_ID_SARATHOS = 4,
    MAP_ID_KRONOS = 5,
    MAP_ID_SHAAR = 6,
    MAP_ID_VALIX = 7,
    MAP_ID_ORXON = 8,
    MAP_ID_TORVAL = 10,
    MAP_ID_STYGIA = 11,
    MAP_ID_MARAXUS = 13,
    MAP_ID_GHOST_STATION = 14,
    MAP_ID_DREADZONE_INTERIOR = 15
};

enum MAP_MASK_IDS
{
    MAP_MASK_NONE				= 0,
    MAP_MASK_BATTLEDOME			= (1 << 0),
    MAP_MASK_CATACROM			= (1 << 1),
    MAP_MASK_SARATHOS			= (1 << 2),
    MAP_MASK_KRONOS				= (1 << 3),
    MAP_MASK_SHAAR				= (1 << 4),
    MAP_MASK_VALIX				= (1 << 5),
    MAP_MASK_ORXON				= (1 << 6),
    MAP_MASK_TORVAL				= (1 << 7),
    MAP_MASK_STYGIA				= (1 << 8),
    MAP_MASK_MARAXUS			= (1 << 9),
    MAP_MASK_GHOST_STATION		= (1 << 10),
	MAP_MASK_DREADZONE_INTERIOR = (1 << 11),
    MAP_MASK_ALL				= -1
};

typedef enum
{
	MISSIONLOAD_IDLE = 0,
	MISSIONLOAD_LOADDATA = 1,
	MISSIONLOAD_LOADSOUND = 2,
	MISSIONLOAD_WAITFORLOAD = 3,
	MISSIONLOAD_UNZIP_INSTANCES = 4,
	MISSIONLOAD_UNZIP_CLASSES = 5,
	MISSIONLOAD_WAITFORSOUND = 6,
	MISSIONLOAD_DONE = 7
} MissionLoadState;

typedef struct
{
	/* 0x00 */ int ActiveMission;
	/* 0x04 */ int LoadingMission;
	/* 0x08 */ int ErrorCode;
	/* 0x0c */ int QueuedMission;
	/* 0x10 */ char Success;
	/* 0x11 */ char ResetLevel;
	/* 0x12 */ char Loading;
	/* 0x13 */ char Parse;
	/* 0x14 */ char Switch;
	/* 0x15 */ char DoubleBuffer;
	/* 0x16 */ char QueuedLoad;
	/* 0x17 */ char InstancesActive;
	/* 0x18 */ char ClassesActive;
	/* 0x19 */ char InstancesLoaded;
	/* 0x1a */ char ClassesLoaded;
	/* 0x1b */ char SoundLoaded;
	/* 0x1c */ void *ActiveMissionClasses;
	/* 0x20 */ void *LoadingMissionClasses;
	/* 0x24 */ MissionLoadState State;
} MISSIONLOAD;

extern MISSIONLOAD * Mission;

int mapMaskHasMask(int value, int maskValue);
int mapIdToMask(int mapId);
int mapMaskToId(int mapMask);

/*
 * NAME:		levelIsActiveLevel
 * DESCRIPTION:
 * 			Checks to see if level specified is active level
 * NOTES:
 * ARGS: 
 *      id: MAP_ID of level needed.
 * RETURN: true if active level, false if not.
 * AUTHOR: Troy "Agent Moose" Pruitt
 */
int mapIsActiveLevel(int levelId);
/*
 * NAME:		mapIsActiveMission
 * DESCRIPTION:
 * 			Returns Active Mission value.
 * NOTES:
 * ARGS: 
 * RETURN: Returns active mission value.
 * AUTHOR: Troy "Agent Moose" Pruitt
 */
int mapGetActiveMission(void);
/*
 * NAME:		mapRestartMission
 * DESCRIPTION:
 * 			Restarts current mission.
 * NOTES:
 * ARGS: 
 * RETURN:
 * AUTHOR: Troy "Agent Moose" Pruitt
 */
void mapResetMission(void);
/*
 * NAME:		mapSwitchToLevel
 * DESCRIPTION:
 * 			Switch to selected Level and Mission
 * NOTES:
 * ARGS: 
 * 			Level: Which Level
 * 			Mission: Which Mission
 * RETURN:
 * AUTHOR: Troy "Agent Moose" Pruitt
 */
void mapSwitchToLevel(int levelId, int missionId);

#endif // _LIBRAC4_MAP_H_
