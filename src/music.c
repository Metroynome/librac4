#include "game.h"
#include "music.h"
#include "types.h"
#include "interop.h"

/* Region-local addresses. */
#if RAC4_PAL
#define musicLocationAddress 0x001CF85C
#define settingsMusicVolumeAddress 0x00171DC4
#elif RAC4_NTSCJ || RAC4_NTSCK
#define musicLocationAddress 0x001CF85C
#define settingsMusicVolumeAddress 0x00171CC4
#else
#define musicLocationAddress 0x001CF85C
#define settingsMusicVolumeAddress 0x00171D44
#endif


#if RAC4_PAL
#define trackRangeMin 0x0021EC88
#define trackRangeMin_MainMenu 0x0021EC88
#elif RAC4_NTSCJ || RAC4_NTSCK
#define trackRangeMin 0x00239408
#define trackRangeMin_MainMenu 0x00239408
#else
#define trackRangeMin 0x0021EC08
#define trackRangeMin_MainMenu 0x0021EC08
#endif

#if RAC4_PAL
#define trackRangeMax 0x0021EC8C
#define trackRangeMax_MainMenu 0x0021EC8C
#elif RAC4_NTSCJ || RAC4_NTSCK
#define trackRangeMax 0x0023940C
#define trackRangeMax_MainMenu 0x0023940C
#else
#define trackRangeMax 0x0021EC0C
#define trackRangeMax_MainMenu 0x0021EC0C
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
#define SettingsMusicVolume (*(u32*)settingsMusicVolumeAddress)

/*
 * This is what is used to figure out where to load the tracks from.
 */
#define MUSIC_LOCATION (*(u32*)musicLocationAddress)

/*
 * Defines which track to start on.
 */
#define TRACK_RANGE_MIN (*(u8*)trackRangeMin)

/*
 * How many tracks to play, starting at TRACK_RANGE_MIN
 */
#define TRACK_RANGE_MAX (*(u8*)trackRangeMax)

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
