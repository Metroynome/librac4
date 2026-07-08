#ifndef _LIBRAC4_TYPES_H_
#define _LIBRAC4_TYPES_H_

#include <tamtypes.h>

#if (defined(RAC4_PAL_V100) || defined(RAC4_NTSCU_V100) || defined(RAC4_NTSCJ_V100) || defined(RAC4_NTSCK_V100)) && !defined(RAC4_V100)
#define RAC4_V100
#endif

#if (defined(RAC_PAL_V100) || defined(RAC_NTSCU_V100) || defined(RAC_NTSCJ_V100) || defined(RAC_NTSCK_V100)) && !defined(RAC_V100)
#define RAC_V100
#endif

#if (defined(RAC4_PAL) || defined(RAC4_NTSCU) || defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)) && !defined(RAC4_V100)
#define RAC4_V100
#endif

#if defined(RAC4_V100) && !defined(RAC_V100)
#define RAC_V100
#endif

#if defined(RAC4_PAL_V100) && !defined(RAC4_PAL)
#define RAC4_PAL
#endif

#if defined(RAC4_NTSCU_V100) && !defined(RAC4_NTSCU)
#define RAC4_NTSCU
#endif

#if defined(RAC4_NTSCJ_V100) && !defined(RAC4_NTSCJ)
#define RAC4_NTSCJ
#endif

#if defined(RAC4_NTSCK_V100) && !defined(RAC4_NTSCK)
#define RAC4_NTSCK
#endif

#if defined(RAC4_PAL) && !defined(RAC_PAL)
#define RAC_PAL
#endif

#if defined(RAC4_NTSCU) && !defined(RAC_NTSCU)
#define RAC_NTSCU
#endif

#if defined(RAC4_NTSCJ) && !defined(RAC_NTSCJ)
#define RAC_NTSCJ
#endif

#if defined(RAC4_NTSCK) && !defined(RAC_NTSCK)
#define RAC_NTSCK
#endif

#if defined(RAC4_PAL) && defined(RAC4_V100) && !defined(RAC4_PAL_V100)
#define RAC4_PAL_V100
#endif

#if defined(RAC4_NTSCU) && defined(RAC4_V100) && !defined(RAC4_NTSCU_V100)
#define RAC4_NTSCU_V100
#endif

#if defined(RAC4_NTSCJ) && defined(RAC4_V100) && !defined(RAC4_NTSCJ_V100)
#define RAC4_NTSCJ_V100
#endif

#if defined(RAC4_NTSCK) && defined(RAC4_V100) && !defined(RAC4_NTSCK_V100)
#define RAC4_NTSCK_V100
#endif

#if defined(RAC_PAL) && defined(RAC_V100) && !defined(RAC_PAL_V100)
#define RAC_PAL_V100
#endif

#if defined(RAC_NTSCU) && defined(RAC_V100) && !defined(RAC_NTSCU_V100)
#define RAC_NTSCU_V100
#endif

#if defined(RAC_NTSCJ) && defined(RAC_V100) && !defined(RAC_NTSCJ_V100)
#define RAC_NTSCJ_V100
#endif

#if defined(RAC_NTSCK) && defined(RAC_V100) && !defined(RAC_NTSCK_V100)
#define RAC_NTSCK_V100
#endif

#define __LIBRAC4_GETTER__    inline
#define __LIBRAC4_SETTER__    inline
#define __LIBRAC4_INLINE__    inline

#define true 1
#define false 0
typedef _Bool bool;

#if defined(RAC4_PAL)
#define RAC4_ADDR_LEVEL_CODE0_BASE             0x0021E200
#define RAC4_ADDR_MISSION_AREA                 0x00171228
#define RAC4_ADDR_SAVE_FILE_LEVEL_ID           0x001719FC
#define RAC4_ADDR_GAME_TIME                    0x001723F8
#define RAC4_ADDR_PLAYER_LOCAL_COUNT           0x001721F4
#define RAC4_ADDR_PLAYER_1_ID                  0x0017220C
#define RAC4_ADDR_MUSIC_VOLUME                 0x00171DC4
#define RAC4_ADDR_PAD_POINTER                  0x0021DE4C
#define RAC4_ADDR_PAD_0                        0x001EE600
#define RAC4_ADDR_HERO_STRUCT_PTR              0x001EEB70
#define RAC4_ADDR_MC_RESULT                    0x001AEE40
#define RAC4_ADDR_MUSIC_LOCATION               0x001CF85C
#define RAC4_ADDR_CURRENT_TRACK                0x00206990
#define RAC4_ADDR_TRACK_DURATION               0x002069A4
#define RAC4_ADDR_PLAYER_2_ID                  0x001B6ED8
#define RAC4_ADDR_WEAPON_EQUIPSLOT             0x0020C690
#define RAC4_ADDR_UI_DIALOG_A0                 0x011C7000
#define RAC4_ADDR_GAME_MAP_ID                  0x0021DE90
#define RAC4_ADDR_GLOBAL_GAMESETTINGS_PTR      0x0021E068
#define RAC4_ADDR_GLOBAL_GAMEOPTIONS_PTR       0x0021E070
#define RAC4_ADDR_CHEAT_BASE                   0x0021DEB1
#define RAC4_ADDR_MC_SEMA                       0x00167C7C
#define RAC4_ADDR_MC_CALLBACK_READY             0x00171B84
#define RAC4_ADDR_MC_CALLBACK_ARG0              0x00171B70
#define RAC4_ADDR_MC_CALLBACK_ARG1              0x00171B74
#define RAC4_ADDR_MC_CALLBACK_FUNC              0x0013A7A0
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
#define RAC4_ADDR_LEVEL_CODE0_BASE             0x00238980
#define RAC4_ADDR_MISSION_AREA                 0x00171128
#define RAC4_ADDR_SAVE_FILE_LEVEL_ID           0x001718FC
#define RAC4_ADDR_GAME_TIME                    0x001722F8
#define RAC4_ADDR_PLAYER_LOCAL_COUNT           0x001720F4
#define RAC4_ADDR_PLAYER_1_ID                  0x0017210C
#define RAC4_ADDR_MUSIC_VOLUME                 0x00171CC4
#define RAC4_ADDR_PAD_POINTER                  0x002385CC
#define RAC4_ADDR_PAD_0                        0x001EE600
#define RAC4_ADDR_HERO_STRUCT_PTR              0x001EEB70
#define RAC4_ADDR_MC_RESULT                    0x001AEE40
#define RAC4_ADDR_MUSIC_LOCATION               0x001CF85C
#define RAC4_ADDR_CURRENT_TRACK                0x00206990
#define RAC4_ADDR_TRACK_DURATION               0x002069A4
#define RAC4_ADDR_PLAYER_2_ID                  0x001B6ED8
#define RAC4_ADDR_WEAPON_EQUIPSLOT             0x0020C690
#define RAC4_ADDR_UI_DIALOG_A0                 0x011C7000
#define RAC4_ADDR_GAME_MAP_ID                  0x00238610
#define RAC4_ADDR_GLOBAL_GAMESETTINGS_PTR      0x002387E8
#define RAC4_ADDR_GLOBAL_GAMEOPTIONS_PTR       0x002387F0
#define RAC4_ADDR_CHEAT_BASE                   0x00238631
#define RAC4_ADDR_MC_SEMA                       0x00167B7C
#define RAC4_ADDR_MC_CALLBACK_READY             0x00171A84
#define RAC4_ADDR_MC_CALLBACK_ARG0              0x00171A70
#define RAC4_ADDR_MC_CALLBACK_ARG1              0x00171A74
#define RAC4_ADDR_MC_CALLBACK_FUNC              0x0013A7A0
#else
#define RAC4_ADDR_LEVEL_CODE0_BASE             0x0021E180
#define RAC4_ADDR_MISSION_AREA                 0x001711A8
#define RAC4_ADDR_SAVE_FILE_LEVEL_ID           0x0017197C
#define RAC4_ADDR_GAME_TIME                    0x00172378
#define RAC4_ADDR_PLAYER_LOCAL_COUNT           0x00172174
#define RAC4_ADDR_PLAYER_1_ID                  0x0017218C
#define RAC4_ADDR_MUSIC_VOLUME                 0x00171D44
#define RAC4_ADDR_PAD_POINTER                  0x0021DDCC
#define RAC4_ADDR_PAD_0                        0x001EE600
#define RAC4_ADDR_HERO_STRUCT_PTR              0x001EEB70
#define RAC4_ADDR_MC_RESULT                    0x001AEE40
#define RAC4_ADDR_MUSIC_LOCATION               0x001CF85C
#define RAC4_ADDR_CURRENT_TRACK                0x00206990
#define RAC4_ADDR_TRACK_DURATION               0x002069A4
#define RAC4_ADDR_PLAYER_2_ID                  0x001B6ED8
#define RAC4_ADDR_WEAPON_EQUIPSLOT             0x0020C690
#define RAC4_ADDR_UI_DIALOG_A0                 0x011C7000
#define RAC4_ADDR_GAME_MAP_ID                  0x0021DE10
#define RAC4_ADDR_GLOBAL_GAMESETTINGS_PTR      0x0021DFE8
#define RAC4_ADDR_GLOBAL_GAMEOPTIONS_PTR       0x0021DFF0
#define RAC4_ADDR_CHEAT_BASE                   0x0021DE31
#define RAC4_ADDR_MC_SEMA                       0x00167BFC
#define RAC4_ADDR_MC_CALLBACK_READY             0x00171B04
#define RAC4_ADDR_MC_CALLBACK_ARG0              0x00171AF0
#define RAC4_ADDR_MC_CALLBACK_ARG1              0x00171AF4
#define RAC4_ADDR_MC_CALLBACK_FUNC              0x0013A7A0
#endif

#define RAC4_LEVEL_CODE0(offset) (RAC4_ADDR_LEVEL_CODE0_BASE + (offset))

#endif
