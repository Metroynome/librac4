#ifndef _LIBRAC4_INTEROP_H_
#define _LIBRAC4_INTEROP_H_

#include <tamtypes.h>
#include "types.h"

typedef struct VariableAddress
{
    u32 MainMenu;
    u32 Battledome;
    u32 Catacrom;
    u32 Sarathos;
    u32 Kronos;
	u32 Shaar;
	u32 Valix;
	u32 Orxon;
	u32 Torval;
	u32 Stygia;
	u32 Maraxus;
	u32 GhostStation;
	u32 DreadZoneInterior;
} VariableAddress_t;

typedef union FixedAddress
{
    u32 Value;
    u32 MainMenu;
    u32 Battledome;
    u32 Catacrom;
    u32 Sarathos;
    u32 Kronos;
	u32 Shaar;
	u32 Valix;
	u32 Orxon;
	u32 Torval;
	u32 Stygia;
	u32 Maraxus;
	u32 GhostStation;
	u32 DreadZoneInterior;
} FixedAddress_t;

/* Compact tables tag MainMenu and retain Battledome as the absolute base.
 * Offset zero is unavailable; 0x8000 denotes the same address as the base. */
#define RAC4_VA_COMPACT_MENU(address) ((u32)(address) | (u32)0x80000000)
#define RAC4_VA_COMPACT_OFFSET(base, address) ((address) == 0 ? 0 : \
	(u16)(((s32)(address) - (s32)(base)) / 4 + 0x8000 + \
	0 * sizeof(char[((address) == 0 || (((s32)(address) - (s32)(base)) % 4 == 0 && \
	((s32)(address) - (s32)(base)) / 4 >= -32767 && \
	((s32)(address) - (s32)(base)) / 4 <= 32767)) ? 1 : -1])))

typedef struct rac4VariableAddressCompact {
	/* 0x00 */ u32 MainMenu;
	/* 0x04 */ u32 Battledome;
	/* 0x08 */ u16 Catacrom;
	/* 0x0a */ u16 Sarathos;
	/* 0x0c */ u16 Kronos;
	/* 0x0e */ u16 Shaar;
	/* 0x10 */ u16 Valix;
	/* 0x12 */ u16 Orxon;
	/* 0x14 */ u16 Torval;
	/* 0x16 */ u16 Stygia;
	/* 0x18 */ u16 Maraxus;
	/* 0x1a */ u16 GhostStation;
	/* 0x1c */ u16 DreadZoneInterior;
	/* 0x1e: two bytes of EE alignment padding. */
} rac4VariableAddressCompact_t;

u32 GetAddress(const void* address);
u32 GetAddressImmediate(const void* address);

#endif // _LIBRAC4_INTEROP_H_
