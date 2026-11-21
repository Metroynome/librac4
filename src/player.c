#include "interop.h"
#include "string.h"
#include "player.h"
#include "team.h"
#include "game.h"
#include "types.h"

/* Cooperative overlay data, resolved through the native level table. */
VariableAddress_t vaCoopHeroSave = {
#if RAC4_PAL
	.Battledome = 0x171bc0,
	.Catacrom = 0x171bc0,
	.Sarathos = 0x171bc0,
	.Kronos = 0x171bc0,
	.Shaar = 0x171bc0,
	.Valix = 0x171bc0,
	.Orxon = 0x171bc0,
	.Torval = 0x171bc0,
	.Stygia = 0x171bc0,
	.Maraxus = 0x171bc0,
	.GhostStation = 0x171bc0,
	.DreadZoneInterior = 0x171bc0
#elif RAC4_NTSCJ || RAC4_NTSCK
	.Battledome = 0x171ac0,
	.Catacrom = 0x171ac0,
	.Sarathos = 0x171ac0,
	.Kronos = 0x171ac0,
	.Shaar = 0x171ac0,
	.Valix = 0x171ac0,
	.Orxon = 0x171ac0,
	.Torval = 0x171ac0,
	.Stygia = 0x171ac0,
	.Maraxus = 0x171ac0,
	.GhostStation = 0x171ac0,
	.DreadZoneInterior = 0x171ac0
#else
	.Battledome = 0x171b40,
	.Catacrom = 0x171b40,
	.Sarathos = 0x171b40,
	.Kronos = 0x171b40,
	.Shaar = 0x171b40,
	.Valix = 0x171b40,
	.Orxon = 0x171b40,
	.Torval = 0x171b40,
	.Stygia = 0x171b40,
	.Maraxus = 0x171b40,
	.GhostStation = 0x171b40,
	.DreadZoneInterior = 0x171b40
#endif
};

/* Native Cooperative overlays (levels 21-35), not campaign or libdl multiplayer.
 * Mapped against the retail 1.00 code images in rac-defs.json. */
VariableAddress_t vaCoopPlayerBestSpawn = {
#if RAC4_PAL
	.Battledome = 0x58a138,
	.Catacrom = 0x53c238,
	.Sarathos = 0x53c478,
	.Kronos = 0x560b78,
	.Shaar = 0x533df8,
	.Valix = 0x5255f8,
	.Orxon = 0x53d478,
	.Torval = 0x5481f8,
	.Stygia = 0x534ed8,
	.Maraxus = 0x54e938,
	.GhostStation = 0x5475f8,
	.DreadZoneInterior = 0x559118
#elif RAC4_NTSCJ
	.Battledome = 0x5a10c8,
	.Catacrom = 0x553608,
	.Sarathos = 0x553a88,
	.Kronos = 0x577f88,
	.Shaar = 0x54b688,
	.Valix = 0x53cd08,
	.Orxon = 0x554888,
	.Torval = 0x55f648,
	.Stygia = 0x54c5e8,
	.Maraxus = 0x565cc8,
	.GhostStation = 0x55e9c8,
	.DreadZoneInterior = 0x570568
#elif RAC4_NTSCK
	.Battledome = 0x5a10c8,
	.Catacrom = 0x553608,
	.Sarathos = 0x553a88,
	.Kronos = 0x577f88,
	.Shaar = 0x54b688,
	.Valix = 0x53cd08,
	.Orxon = 0x554888,
	.Torval = 0x55f648,
	.Stygia = 0x54c5e8,
	.Maraxus = 0x565cc8,
	.GhostStation = 0x55e9c8,
	.DreadZoneInterior = 0x570568
#else
	.Battledome = 0x585e78,
	.Catacrom = 0x538578,
	.Sarathos = 0x538938,
	.Kronos = 0x55ce38,
	.Shaar = 0x5305b8,
	.Valix = 0x522078,
	.Orxon = 0x5397f8,
	.Torval = 0x5445b8,
	.Stygia = 0x531518,
	.Maraxus = 0x54abf8,
	.GhostStation = 0x543938,
	.DreadZoneInterior = 0x555318
#endif
};

VariableAddress_t vaCoopPlayerCheckSpawn = {
#if RAC4_PAL
	.Battledome = 0x58a4a0,
	.Catacrom = 0x53c5a0,
	.Sarathos = 0x53c7e0,
	.Kronos = 0x560ee0,
	.Shaar = 0x534160,
	.Valix = 0x525960,
	.Orxon = 0x53d7e0,
	.Torval = 0x548560,
	.Stygia = 0x535240,
	.Maraxus = 0x54eca0,
	.GhostStation = 0x547960,
	.DreadZoneInterior = 0x559480
#elif RAC4_NTSCJ
	.Battledome = 0x5a1430,
	.Catacrom = 0x553970,
	.Sarathos = 0x553df0,
	.Kronos = 0x5782f0,
	.Shaar = 0x54b9f0,
	.Valix = 0x53d070,
	.Orxon = 0x554bf0,
	.Torval = 0x55f9b0,
	.Stygia = 0x54c950,
	.Maraxus = 0x566030,
	.GhostStation = 0x55ed30,
	.DreadZoneInterior = 0x5708d0
#elif RAC4_NTSCK
	.Battledome = 0x5a1430,
	.Catacrom = 0x553970,
	.Sarathos = 0x553df0,
	.Kronos = 0x5782f0,
	.Shaar = 0x54b9f0,
	.Valix = 0x53d070,
	.Orxon = 0x554bf0,
	.Torval = 0x55f9b0,
	.Stygia = 0x54c950,
	.Maraxus = 0x566030,
	.GhostStation = 0x55ed30,
	.DreadZoneInterior = 0x5708d0
#else
	.Battledome = 0x5861e0,
	.Catacrom = 0x5388e0,
	.Sarathos = 0x538ca0,
	.Kronos = 0x55d1a0,
	.Shaar = 0x530920,
	.Valix = 0x5223e0,
	.Orxon = 0x539b60,
	.Torval = 0x544920,
	.Stygia = 0x531880,
	.Maraxus = 0x54af60,
	.GhostStation = 0x543ca0,
	.DreadZoneInterior = 0x555680
#endif
};

VariableAddress_t vaCoopPlayerWarp = {
#if RAC4_PAL
	.Battledome = 0x688b00,
	.Catacrom = 0x6384b0,
	.Sarathos = 0x6381c0,
	.Kronos = 0x65eb90,
	.Shaar = 0x6306c0,
	.Valix = 0x623488,
	.Orxon = 0x63b3d8,
	.Torval = 0x645cd0,
	.Stygia = 0x632af8,
	.Maraxus = 0x64c3c0,
	.GhostStation = 0x646010,
	.DreadZoneInterior = 0x6567e0
#elif RAC4_NTSCJ
	.Battledome = 0x69f0f8,
	.Catacrom = 0x64ef28,
	.Sarathos = 0x64ee78,
	.Kronos = 0x675648,
	.Shaar = 0x6475f8,
	.Valix = 0x63a240,
	.Orxon = 0x651e90,
	.Torval = 0x65c7c8,
	.Stygia = 0x6498b0,
	.Maraxus = 0x662df8,
	.GhostStation = 0x65ca88,
	.DreadZoneInterior = 0x66d2d8
#elif RAC4_NTSCK
	.Battledome = 0x69f0f8,
	.Catacrom = 0x64ef28,
	.Sarathos = 0x64ee78,
	.Kronos = 0x675648,
	.Shaar = 0x6475f8,
	.Valix = 0x63a240,
	.Orxon = 0x651e90,
	.Torval = 0x65c7c8,
	.Stygia = 0x6498b0,
	.Maraxus = 0x662df8,
	.GhostStation = 0x65ca88,
	.DreadZoneInterior = 0x66d2d8
#else
	.Battledome = 0x6837b8,
	.Catacrom = 0x6337a8,
	.Sarathos = 0x633638,
	.Kronos = 0x659e08,
	.Shaar = 0x62be38,
	.Valix = 0x61eec0,
	.Orxon = 0x636710,
	.Torval = 0x641048,
	.Stygia = 0x62e0f0,
	.Maraxus = 0x647638,
	.GhostStation = 0x641308,
	.DreadZoneInterior = 0x651998
#endif
};

VariableAddress_t vaCoopPlayers = {
#if RAC4_PAL
	.Battledome = 0x3660f8,
	.Catacrom = 0x362c78,
	.Sarathos = 0x362bf8,
	.Kronos = 0x363038,
	.Shaar = 0x362ab8,
	.Valix = 0x362a38,
	.Orxon = 0x362ab8,
	.Torval = 0x362db8,
	.Stygia = 0x362b38,
	.Maraxus = 0x362db8,
	.GhostStation = 0x362c78,
	.DreadZoneInterior = 0x362c38
#elif RAC4_NTSCJ
	.Battledome = 0x3808f8,
	.Catacrom = 0x37d3f8,
	.Sarathos = 0x37d3f8,
	.Kronos = 0x37d838,
	.Shaar = 0x37d2b8,
	.Valix = 0x37d238,
	.Orxon = 0x37d2f8,
	.Torval = 0x37d5b8,
	.Stygia = 0x37d338,
	.Maraxus = 0x37d5b8,
	.GhostStation = 0x37d478,
	.DreadZoneInterior = 0x37d438
#elif RAC4_NTSCK
	.Battledome = 0x3808f8,
	.Catacrom = 0x37d3f8,
	.Sarathos = 0x37d3f8,
	.Kronos = 0x37d838,
	.Shaar = 0x37d2b8,
	.Valix = 0x37d238,
	.Orxon = 0x37d2f8,
	.Torval = 0x37d5b8,
	.Stygia = 0x37d338,
	.Maraxus = 0x37d5b8,
	.GhostStation = 0x37d478,
	.DreadZoneInterior = 0x37d438
#else
	.Battledome = 0x3660f8,
	.Catacrom = 0x362c78,
	.Sarathos = 0x362bf8,
	.Kronos = 0x363038,
	.Shaar = 0x362b38,
	.Valix = 0x362ab8,
	.Orxon = 0x362b38,
	.Torval = 0x362e38,
	.Stygia = 0x362bb8,
	.Maraxus = 0x362e38,
	.GhostStation = 0x362cf8,
	.DreadZoneInterior = 0x362c38
#endif
};

VariableAddress_t vaCoopPlayerLookup = {
#if RAC4_PAL
	.Battledome = 0x66aa58,
	.Catacrom = 0x61a408,
	.Sarathos = 0x61a118,
	.Kronos = 0x640a58,
	.Shaar = 0x612588,
	.Valix = 0x6053e0,
	.Orxon = 0x61d330,
	.Torval = 0x627c28,
	.Stygia = 0x614a50,
	.Maraxus = 0x62e318,
	.GhostStation = 0x627f68,
	.DreadZoneInterior = 0x6386a8
#elif RAC4_NTSCJ
	.Battledome = 0x681158,
	.Catacrom = 0x630f88,
	.Sarathos = 0x630ed8,
	.Kronos = 0x657618,
	.Shaar = 0x6295c8,
	.Valix = 0x61c2a0,
	.Orxon = 0x633ef0,
	.Torval = 0x63e828,
	.Stygia = 0x62b910,
	.Maraxus = 0x644e58,
	.GhostStation = 0x63eae8,
	.DreadZoneInterior = 0x64f2a8
#elif RAC4_NTSCK
	.Battledome = 0x681158,
	.Catacrom = 0x630f88,
	.Sarathos = 0x630ed8,
	.Kronos = 0x657618,
	.Shaar = 0x6295c8,
	.Valix = 0x61c2a0,
	.Orxon = 0x633ef0,
	.Torval = 0x63e828,
	.Stygia = 0x62b910,
	.Maraxus = 0x644e58,
	.GhostStation = 0x63eae8,
	.DreadZoneInterior = 0x64f2a8
#else
	.Battledome = 0x6658c0,
	.Catacrom = 0x6158b0,
	.Sarathos = 0x615740,
	.Kronos = 0x63be80,
	.Shaar = 0x60deb0,
	.Valix = 0x600fc8,
	.Orxon = 0x618818,
	.Torval = 0x623150,
	.Stygia = 0x6101f8,
	.Maraxus = 0x629740,
	.GhostStation = 0x623410,
	.DreadZoneInterior = 0x633a10
#endif
};

VariableAddress_t vaCoopPlayerInitBodyState = {
#if RAC4_PAL
	.Battledome = 0x69f008,
	.Catacrom = 0x64e948,
	.Sarathos = 0x64e658,
	.Kronos = 0x675028,
	.Shaar = 0x646b58,
	.Valix = 0x639920,
	.Orxon = 0x651870,
	.Torval = 0x65c168,
	.Stygia = 0x648f90,
	.Maraxus = 0x662858,
	.GhostStation = 0x65c4a8,
	.DreadZoneInterior = 0x66cc78
#elif RAC4_NTSCJ
	.Battledome = 0x6b55b0,
	.Catacrom = 0x665370,
	.Sarathos = 0x6652c0,
	.Kronos = 0x68ba90,
	.Shaar = 0x65da40,
	.Valix = 0x650688,
	.Orxon = 0x6682d8,
	.Torval = 0x672c10,
	.Stygia = 0x65fcf8,
	.Maraxus = 0x679240,
	.GhostStation = 0x672ed0,
	.DreadZoneInterior = 0x683720
#elif RAC4_NTSCK
	.Battledome = 0x6b55b0,
	.Catacrom = 0x665370,
	.Sarathos = 0x6652c0,
	.Kronos = 0x68ba90,
	.Shaar = 0x65da40,
	.Valix = 0x650688,
	.Orxon = 0x6682d8,
	.Torval = 0x672c10,
	.Stygia = 0x65fcf8,
	.Maraxus = 0x679240,
	.GhostStation = 0x672ed0,
	.DreadZoneInterior = 0x683720
#else
	.Battledome = 0x699c70,
	.Catacrom = 0x649bf0,
	.Sarathos = 0x649a80,
	.Kronos = 0x670250,
	.Shaar = 0x642280,
	.Valix = 0x635308,
	.Orxon = 0x64cb58,
	.Torval = 0x657490,
	.Stygia = 0x644538,
	.Maraxus = 0x65da80,
	.GhostStation = 0x657750,
	.DreadZoneInterior = 0x667de0
#endif
};


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
    player->pMoby->glow_rgba = TEAM_COLORS[teamId];
    player->pMoby->modeBits2 = (player->pMoby->modeBits2 & 0xff) | ((0x80 + (8 * teamId)) << 8);
    player->pMoby->triggers = 0;
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
