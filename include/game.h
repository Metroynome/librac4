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

//--------------------------------------------------------
typedef struct ScoreboardItem
{
    int TeamId;
    int UNK;
    int Value;
} ScoreboardItem;


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
 * NAME :		isSceneLoading
 * 
 * DESCRIPTION :
 * 			Whether the client is currently in a scene transition.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ int isSceneLoading(void);

/*
 * NAME :		gameIsStartMenuOpen
 * 
 * DESCRIPTION :
 * 			Whether the client is in game and has the start menu open.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ int gameIsStartMenuOpen(void);


/*
 * NAME :		gameHasEnded
 * 
 * DESCRIPTION :
 * 			Whether the game has ended and/or is ending.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ int gameHasEnded(void);

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

/*
 * NAME :		gameGetFinishedExitTime
 * 
 * DESCRIPTION :
 * 			Gets the time when to leave after the game has ended.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 *          Returns 0 if the game has not ended.
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ int gameGetFinishedExitTime(void);

/*
 * NAME :		gameGetDeathHeight
 * 
 * DESCRIPTION :
 * 			Gets the level's death height.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ float gameGetDeathHeight(void);

/*
 * NAME :		gameSetDeathHeight
 * 
 * DESCRIPTION :
 * 			Sets the level's death height.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_SETTER__ void gameSetDeathHeight(float height);

/*
 * NAME :		gameGetRawTimeLimit
 * 
 * DESCRIPTION :
 * 			Gets the actual time limit in milliseconds.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBRAC4_GETTER__ int gameGetRawTimeLimit(void);

/*
 * NAME :		gameScoreboardSetTeamScore
 * 
 * DESCRIPTION :
 * 			Sets the given team's in game scoreboard value.
 * 
 */
void gameScoreboardSetTeamScore(int teamId, int score);

/*
 * NAME :		gameGetWorldId
 * 
 * DESCRIPTION :
 * 			Returns the current dme world id. -1 if not in a world.
 * 
 */
__LIBRAC4_GETTER__ int gameGetWorldId(void);

#endif // _LIBRAC4_GAME_H_
