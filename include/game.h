/***************************************************
 * FILENAME :		game.h
 * 
 * DESCRIPTION :
 * 		Contains game specific offsets and structures for Ratchet and Clank 4.
 * 
 * NOTES :
 * 		Each offset is determined per app id.
 * 		This is to ensure compatibility between versions of Ratchet and Clank 4.
 * 		
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBRAC4_GAME_H_
#define _LIBRAC4_GAME_H_

#include <tamtypes.h>
#include "moby.h"
#include "gamesettings.h"
#include "common.h"
#include "types.h"

/* Region-local addresses. */
#if RAC4_PAL
#define Level (*(volatile int*)0x0021DE90)
#elif RAC4_NTSCJ || RAC4_NTSCK
#define Level (*(volatile int*)0x00238610)
#else
#define Level (*(volatile int*)0x0021DE10)
#endif


typedef enum {
    GAME_MODE_NONE = -2,
    GAME_MODE_DEBUG = -1,
    GAME_MODE_NORMAL = 0,
    GAME_MODE_MOVIE = 1,
    GAME_MODE_SCENE = 2,
    GAME_MODE_PAUSE = 3,
    GAME_MODE_FREEZE = 4,
    GAME_MODE_VENDOR = 5,
    GAME_MODE_SPACE = 6,
    GAME_MODE_PUZZLE = 7,
    GAME_MODE_WEAPON_UPGRADE = 8,
    GAME_MODE_CREDITS = 9,
    GAME_MODE_LOBBY = 10,
    GAME_MODE_FLYBY = 11,
    GAME_MODE_THERMAL = 12,
    GAME_MODE_PRE_LOBBY_MEMCARD_LOAD = 13,
    GAME_MODE_PRE_LOBBY = 14,
    GAME_MODE_WAIT_FOR_MPSTART = 15,
    GAME_MODE_EXEC_MP_MEMCARD_COMMAND = 16,
    GAME_MODE_IOP_DEBUG = 17,
    GAME_MODE_MAX = 18
} gameMode_t;


//--------------------------------------------------------
typedef struct PlayerGameStats
{
    short WeaponKills[GAME_MAX_PLAYERS][9];
    short WeaponDeaths[GAME_MAX_PLAYERS][9];
    short WeaponShots[GAME_MAX_PLAYERS][9];
    short WeaponShotsHitBy[GAME_MAX_PLAYERS][9];
    float VehicleTime[GAME_MAX_PLAYERS];
    short VehicleWeaponKills[GAME_MAX_PLAYERS];
    short VehicleWeaponDeaths[GAME_MAX_PLAYERS];
    short VehicleRoadKills[GAME_MAX_PLAYERS];
    short VehicleRoadDeaths[GAME_MAX_PLAYERS];
    short VehicleShotsFired[GAME_MAX_PLAYERS];
    short VehicleShotsHit[GAME_MAX_PLAYERS];
    short Kills[GAME_MAX_PLAYERS];
    short Deaths[GAME_MAX_PLAYERS];
    short Suicides[GAME_MAX_PLAYERS];
    short MultiKills[GAME_MAX_PLAYERS];
    short SniperKills[GAME_MAX_PLAYERS];
    short WrenchKills[GAME_MAX_PLAYERS];
    char ConquestNodesCaptured[GAME_MAX_PLAYERS];
    char ConquestNodeSaves[GAME_MAX_PLAYERS];
    char ConquestDefensiveKills[GAME_MAX_PLAYERS];
    char ConquestPoints[GAME_MAX_PLAYERS];
    char CtfFlagsCaptures[GAME_MAX_PLAYERS];
    char CtfFlagsSaved[GAME_MAX_PLAYERS];
    float KingHillHoldTime[GAME_MAX_PLAYERS];
    float InternalKingHillHoldTime[GAME_MAX_PLAYERS];
    float JuggernautTime[GAME_MAX_PLAYERS];
    short Squats[GAME_MAX_PLAYERS];
    short VehicleSquats[GAME_MAX_PLAYERS];
    short TicketScore[GAME_MAX_PLAYERS];
} PlayerGameStats;

//--------------------------------------------------------
typedef struct LocalPlayerYourBaseGameData
{
    int Team1_SpawnPts[3];
    int Team2_SpawnPts[3];
    int NodeResurrectionPts[8];
    Moby* BaseMobys[8];
    Moby* NodeMobys[8];
    int Team1_StartBase;
    int Team2_StartBase;
    int BaseTeam[8];
    int NodeTeam[8];
    int OrigBaseTeam[8];
    int BaseHealth[8];
    float TotalHudHealth[8];
    float PrevHudHealth[8];
    float HudHealth[8];
    int NumBases;
    int WinScore;
    int Team3_SpawnPts[3];
    int Team4_SpawnPts[3];
    Moby* HomeNodeMobys[2];
    int pad[8];
} LocalPlayerYourBaseGameData;

/*
 * NAME :		isInGame
 * 
 * DESCRIPTION :
 * 			Whether the client is currently in game world.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ int isInGame(void);

/*
 * NAME :		isInMenus
 * 
 * DESCRIPTION :
 * 			Whether the client is currently in the menus.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ int isInMenus(void);

/*
 * NAME :		gameGetTime
 * 
 * DESCRIPTION :
 * 			Gets the current game time in milliseconds.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ int gameGetTime(void);

#endif // _LIBRAC4_GAME_H_
