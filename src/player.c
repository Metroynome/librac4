#include "string.h"
#include "player.h"
#include "team.h"
#include "game.h"
#include "types.h"

/* Region-local addresses. */
#if RAC4_PAL
#define PLAYER_STRUCT_ARRAY                         ((Player**)0x00344CB8)
#define PLAYER_1_ID                                 (*(u32*)0x0017220C)
#define PLAYER_2_ID                                 (*(u32*)0x001B6ED8)
#define PLAYER_LOCAL_COUNT                          (*(int*)0x001721F4)
#define WEAPON_EQUIPSLOT                            ((int*)0x0020C690)
#elif RAC4_NTSCJ || RAC4_NTSCK
#define PLAYER_STRUCT_ARRAY                         ((Player**)0x0035F438)
#define PLAYER_1_ID                                 (*(u32*)0x0017210C)
#define PLAYER_2_ID                                 (*(u32*)0x001B6ED8)
#define PLAYER_LOCAL_COUNT                          (*(int*)0x001720F4)
#define WEAPON_EQUIPSLOT                            ((int*)0x0020C690)
#else
#define PLAYER_STRUCT_ARRAY                         ((Player**)0x00344C38)
#define PLAYER_1_ID                                 (*(u32*)0x0017218C)
#define PLAYER_2_ID                                 (*(u32*)0x001B6ED8)
#define PLAYER_LOCAL_COUNT                          (*(int*)0x00172174)
#define WEAPON_EQUIPSLOT                            ((int*)0x0020C690)
#endif

void internal_playerSetPosRot(Player *, VECTOR, VECTOR, int, int, int, int, int);

/*
 * 
 */
// 
extern const PadHistory DefaultPadHistory;

// Player pad history
PadHistory PlayerPadHistory[GAME_MAX_PLAYERS];

//--------------------------------------------------------------------------------
Player ** playerGetAll(void)
{
    return PLAYER_STRUCT_ARRAY;
}

//--------------------------------------------------------------------------------
Player * playerGetFromIndex(int idx)
{
    if (idx < 0 || idx >= GAME_MAX_PLAYERS)
        return NULL;

    return PLAYER_STRUCT_ARRAY[idx];
}

//--------------------------------------------------------------------------------
int playerIsValid(Player * player)
{
    return player && player->pMoby && player->pNetPlayer && playerIsConnected(player);
}

//--------------------------------------------------------------------------------
void playerSetLocalEquipslot(int localPlayerId, int slot, int weaponId)
{
    int * equipslots = WEAPON_EQUIPSLOT;
    equipslots[slot + (localPlayerId * 3)] = weaponId;
}

//--------------------------------------------------------------------------------
int playerGetLocalEquipslot(int localPlayerId, int slot)
{
    int * equipslots = WEAPON_EQUIPSLOT;
    return equipslots[slot + (localPlayerId * 3)];
}

//--------------------------------------------------------------------------------
void playerSetHealth(Player * player, float health)
{
    if (!player)
        return;

    player->hitPoints = health;
    if (player->pNetPlayer && player->pNetPlayer->pNetPlayerData)
        player->pNetPlayer->pNetPlayerData->hitPoints = health;
}

//--------------------------------------------------------------------------------
void playerSetTeam(Player * player, int teamId)
{
    if (!player)
        return;

    
    player->mpTeam = teamId;
    player->pMoby->GlowRGBA = TEAM_COLORS[teamId];
    player->pMoby->ModeBits2 = (player->pMoby->ModeBits2 & 0xff) | ((0x80 + (8 * teamId)) << 8);
    player->pMoby->Triggers = 0;
}

//--------------------------------------------------------------------------------
int playerIsLocal(Player * player)
{
    return (int)player >= 0x00300000 && (int)player <= 0x00400000;
}

//--------------------------------------------------------------------------------
int playerGetNumLocals(void)
{
    return PLAYER_LOCAL_COUNT;
}

//--------------------------------------------------------------------------------
int playerIdIsLocal(int playerId)
{
    return PLAYER_1_ID == playerId || PLAYER_2_ID == playerId;
}

//--------------------------------------------------------------------------------
void playerSetPosRot(Player * player, VECTOR p, VECTOR r)
{
    internal_playerSetPosRot(player, p, r, 0, 1, 1, 1, 1);
}

//--------------------------------------------------------------------------------
PadButtonStatus * playerGetPad(Player * player)
{
    if (!player)
        return 0;

    if (playerIsLocal(player))
    {
        return player->pPad;
    }
    else
    {
        struct tNW_Player* netPlayer = player->pNetPlayer;
        if (!netPlayer)
            return 0;

        return (PadButtonStatus*)(&netPlayer->padMessageElems[0].msg.pad_data);
    }
}

//--------------------------------------------------------------------------------
void playerPadUpdate(void)
{
    int i;
    PadButtonStatus * playerPad;
    struct PadHistory * padHistory;
    Player ** players = playerGetAll();
    Player * player;

    // Update player pad in game
    if (isInGame())
    {
        for (i = 0; i < GAME_MAX_PLAYERS; ++i)
        {
            player = players[i];
            padHistory = &PlayerPadHistory[i];
            playerPad = playerGetPad(player);

            // Copy last player pad
            if (playerPad)
            {
                memcpy(padHistory, &playerPad->btns, sizeof(struct PadHistory));
                padHistory->id = player->mpIndex;
            }
            // Reset pad if no player
            else if (padHistory->id >= 0)
            {
                memcpy(padHistory, &DefaultPadHistory, sizeof(struct PadHistory));
            }
        }
    }

    // Reset player pad history when not in game
    else if (PlayerPadHistory[0].id >= 0)
    {
        for (i = 0; i < GAME_MAX_PLAYERS; ++i)
            memcpy(PlayerPadHistory + i, &DefaultPadHistory, sizeof(struct PadHistory));
    }
}

//--------------------------------------------------------------------------------
int playerPadGetButton(Player * player, u16 buttonMask)
{
    if (!player)
        return 0;

    PadButtonStatus * paddata = playerGetPad(player);
    if (!paddata)
        return 0;

    return (paddata->btns & buttonMask) == 0;
}

//--------------------------------------------------------------------------------
int playerPadGetAnyButton(Player * player, u16 buttonMask)
{
    if (!player)
        return 0;

    PadButtonStatus * paddata = playerGetPad(player);
    if (!paddata)
        return 0;

    return (paddata->btns & buttonMask) != buttonMask;
}

//--------------------------------------------------------------------------------
int playerPadGetButtonDown(Player * player, u16 buttonMask)
{
    if (!player)
        return 0;

    return playerPadGetButton(player, buttonMask) &&
            (PlayerPadHistory[player->mpIndex].btns & buttonMask) != 0;
}

//--------------------------------------------------------------------------------
int playerPadGetAnyButtonDown(Player * player, u16 buttonMask)
{
    if (!player)
        return 0;

    return playerPadGetAnyButton(player, buttonMask) &&
            (PlayerPadHistory[player->mpIndex].btns & buttonMask) == buttonMask;
}

//--------------------------------------------------------------------------------
int playerPadGetButtonUp(Player * player, u16 buttonMask)
{
    if (!player)
        return 0;

    return !playerPadGetButton(player, buttonMask) &&
        (PlayerPadHistory[player->mpIndex].btns & buttonMask) == 0;
}

//--------------------------------------------------------------------------------
int playerPadGetAnyButtonUp(Player * player, u16 buttonMask)
{
    if (!player)
        return 0;

    return !playerPadGetAnyButton(player, buttonMask) &&
        (PlayerPadHistory[player->mpIndex].btns & buttonMask) != buttonMask;
}

//--------------------------------------------------------------------------------
PlayerVTable* playerGetVTable(Player * player)
{
    if (!player)
        return NULL;

    return (PlayerVTable*)player->Guber.Vtable;
}

//--------------------------------------------------------------------------------
int playerStateIsDead(int state)
{
	return state == PLAYER_STATE_DEATH
        || state == PLAYER_STATE_DROWN
        || state == PLAYER_STATE_DEATH_FALL
        || state == PLAYER_STATE_DEATHSAND_SINK
        || state == PLAYER_STATE_LAVA_DEATH
        || state == PLAYER_STATE_DEATH_NO_FALL
        || state == PLAYER_STATE_WAIT_FOR_RESURRECT
        ;
}

//--------------------------------------------------------------------------------
int playerIsDead(Player * player)
{
    return playerStateIsDead(player->state);
}
