#include "game.h"
#include "music.h"
#include "types.h"
#include "interop.h"

#if defined(RAC4_PAL)
VariableAddress_t vaTrackRangeMin = {
    .Battledome = 0x0021EC88,
    .Catacrom = 0x0021EC88,
    .Sarathos = 0x0021EC88,
    .Kronos = 0x0021EC88,
    .Shaar = 0x0021EC88,
    .Valix = 0x0021EC88,
    .Orxon = 0x0021EC88,
    .Torval = 0x0021EC88,
    .Stygia = 0x0021EC88,
    .Maraxus = 0x0021EC88,
    .GhostStation = 0x0021EC88,
    .DreadZoneInterior = 0x0021EC88,
    .MainMenu = 0x0021EC88,
    .MultiplayerMenu = 0x0021EC88
};
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
VariableAddress_t vaTrackRangeMin = {
    .Battledome = 0x00239408,
    .Catacrom = 0x00239408,
    .Sarathos = 0x00239408,
    .Kronos = 0x00239408,
    .Shaar = 0x00239408,
    .Valix = 0x00239408,
    .Orxon = 0x00239408,
    .Torval = 0x00239408,
    .Stygia = 0x00239408,
    .Maraxus = 0x00239408,
    .GhostStation = 0x00239408,
    .DreadZoneInterior = 0x00239408,
    .MainMenu = 0x00239408,
    .MultiplayerMenu = 0x00239408
};
#else
VariableAddress_t vaTrackRangeMin = {
    .Battledome = 0x0021EC08,
    .Catacrom = 0x0021EC08,
    .Sarathos = 0x0021EC08,
    .Kronos = 0x0021EC08,
    .Shaar = 0x0021EC08,
    .Valix = 0x0021EC08,
    .Orxon = 0x0021EC08,
    .Torval = 0x0021EC08,
    .Stygia = 0x0021EC08,
    .Maraxus = 0x0021EC08,
    .GhostStation = 0x0021EC08,
    .DreadZoneInterior = 0x0021EC08,
    .MainMenu = 0x0021EC08,
    .MultiplayerMenu = 0x0021EC08
};
#endif

#if defined(RAC4_PAL)
VariableAddress_t vaTrackRangeMax = {
    .Battledome = 0x0021EC8C,
    .Catacrom = 0x0021EC8C,
    .Sarathos = 0x0021EC8C,
    .Kronos = 0x0021EC8C,
    .Shaar = 0x0021EC8C,
    .Valix = 0x0021EC8C,
    .Orxon = 0x0021EC8C,
    .Torval = 0x0021EC8C,
    .Stygia = 0x0021EC8C,
    .Maraxus = 0x0021EC8C,
    .GhostStation = 0x0021EC8C,
    .DreadZoneInterior = 0x0021EC8C,
    .MainMenu = 0x0021EC8C,
    .MultiplayerMenu = 0x0021EC8C
};
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
VariableAddress_t vaTrackRangeMax = {
    .Battledome = 0x0023940C,
    .Catacrom = 0x0023940C,
    .Sarathos = 0x0023940C,
    .Kronos = 0x0023940C,
    .Shaar = 0x0023940C,
    .Valix = 0x0023940C,
    .Orxon = 0x0023940C,
    .Torval = 0x0023940C,
    .Stygia = 0x0023940C,
    .Maraxus = 0x0023940C,
    .GhostStation = 0x0023940C,
    .DreadZoneInterior = 0x0023940C,
    .MainMenu = 0x0023940C,
    .MultiplayerMenu = 0x0023940C
};
#else
VariableAddress_t vaTrackRangeMax = {
    .Battledome = 0x0021EC0C,
    .Catacrom = 0x0021EC0C,
    .Sarathos = 0x0021EC0C,
    .Kronos = 0x0021EC0C,
    .Shaar = 0x0021EC0C,
    .Valix = 0x0021EC0C,
    .Orxon = 0x0021EC0C,
    .Torval = 0x0021EC0C,
    .Stygia = 0x0021EC0C,
    .Maraxus = 0x0021EC0C,
    .GhostStation = 0x0021EC0C,
    .DreadZoneInterior = 0x0021EC0C,
    .MainMenu = 0x0021EC0C,
    .MultiplayerMenu = 0x0021EC0C
};
#endif

//--------------------------------------------------------
void internal_musicPlayTrack_inGame(u64, u64, u64);
void internal_musicPlayTrack_inLobby(u64, u64, u64);
void internal_musicStopTrack_inGame(void);
void internal_musicStopTrack_inLobby(void);
void internal_musicPauseTrack_inGame(u64);
void internal_musicPauseTrack_inLobby(u64);
void internal_musicUnpauseTrack_inGame(void);
void internal_musicUnpauseTrack_inLobby(void);
void internal_musicTransitionTrack_inGame(u64, u64, u64, u64);
void internal_musicTransitionTrack_inLobby(u64, u64, u64, u64);
void internal_wadGetSectors(u64, u64, u64);

/*
 * Games music volume setting.
 */
#define MUSIC_VOLUME (*(u32*)RAC4_ADDR_MUSIC_VOLUME)

/*
 * This is what is used to figure out where to load the tracks from.
 */
#define MUSIC_LOCATION (*(u32*)RAC4_ADDR_MUSIC_LOCATION)

/*
 * Defines which track to start on.
 */
#define TRACK_RANGE_MIN (*(u8*)GetAddress(&vaTrackRangeMin))

/*
 * How many tracks to play, starting at TRACK_RANGE_MIN
 */
#define TRACK_RANGE_MAX (*(u8*)GetAddress(&vaTrackRangeMax))

//--------------------------------------------------------------------------------
void musicPlayTrack(int TrackNumber, int KeepPlaying)
{
    musicStopTrack();
    if (isInGame())
    {
        internal_musicPlayTrack_inGame(TrackNumber, KeepPlaying, 0x400);
    }
    else if (isInMenus())
    {
        internal_musicPlayTrack_inLobby(TrackNumber, KeepPlaying, 0x400);
    }
}

//--------------------------------------------------------------------------------
void musicStopTrack(void)
{
    if (isInGame())
    {
        internal_musicStopTrack_inGame();
    }
    else if (isInMenus())
    {
        internal_musicStopTrack_inLobby();
    }
}

//--------------------------------------------------------------------------------
void musicPauseTrack(int arg1)
{
    if (isInGame())
    {
        internal_musicPauseTrack_inGame(arg1);
    }
    else if (isInMenus())
    {
        internal_musicPauseTrack_inLobby(arg1);
    }
}

//--------------------------------------------------------------------------------
void musicUnpauseTrack(void)
{
    if (isInGame())
    {
        internal_musicUnpauseTrack_inGame();
    }
    else if (isInMenus())
    {
        internal_musicUnpauseTrack_inLobby();
    }
}

//--------------------------------------------------------------------------------
void musicTransitionTrack(short arg1, short CueTrack, short arg3, short arg4)
{
    if (isInGame())
    {
        internal_musicTransitionTrack_inGame(arg1, CueTrack, arg3, arg4);
    }
    else if (isInMenus())
    {
        internal_musicTransitionTrack_inLobby(arg1, CueTrack, arg3, arg4);
    }
}

//--------------------------------------------------------------------------------
int musicIsLoaded(void)
{
  return MUSIC_LOCATION == 0xF8D29;
}
