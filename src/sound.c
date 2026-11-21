#include "sound.h"
#include "interop.h"

static VariableAddress_t vaPlayMenuSound = {
#if RAC4_PAL
	.MainMenu = 0x4985f0,
	.Battledome = 0x5dcd18,
	.Catacrom = 0x58cf90,
	.Sarathos = 0x58cb38,
	.Kronos = 0x5b2cc8,
	.Shaar = 0x584d18,
	.Valix = 0x577cf0,
	.Orxon = 0x58f6f8,
	.Torval = 0x59a030,
	.Stygia = 0x586dd0,
	.Maraxus = 0x5a0678,
	.GhostStation = 0x59a6e0,
	.DreadZoneInterior = 0x5aaf28,
#elif RAC4_NTSCJ || RAC4_NTSCK
	.MainMenu = 0x4bb630,
	.Battledome = 0x5f33c0,
	.Catacrom = 0x5a3ab8,
	.Sarathos = 0x5a38a0,
	.Kronos = 0x5c9830,
	.Shaar = 0x59bd00,
	.Valix = 0x58eb58,
	.Orxon = 0x5a6260,
	.Torval = 0x5b0bd8,
	.Stygia = 0x59dc38,
	.Maraxus = 0x5b7160,
	.GhostStation = 0x5b1208,
	.DreadZoneInterior = 0x5c1ad0,
#else
	.MainMenu = 0x497980,
	.Battledome = 0x5d8268,
	.Catacrom = 0x588b20,
	.Sarathos = 0x588848,
	.Kronos = 0x5ae7d8,
	.Shaar = 0x580d28,
	.Valix = 0x573fc0,
	.Orxon = 0x58b2c8,
	.Torval = 0x595c40,
	.Stygia = 0x582c60,
	.Maraxus = 0x59c188,
	.GhostStation = 0x596270,
	.DreadZoneInterior = 0x5a6978,
#endif
};

SoundData* soundGetData(short soundId)
{
    return (SoundData*)(0x1D2200 + 0x80*soundId + 0x2c0);
}

/*
 * NAME : soundPlayMenu
 * DESCRIPTION : Play a native GUI sound.
 * NOTES : Retail boot/campaign/co-op bindings; skip unloaded or changed code.
 * ARGS : Native GUI sound ID (5 select, 11 open, 12 close, 16 move).
 * RETURN :
 * AUTHOR : Troy "Metroynome" Pruitt
 */
void soundPlayMenu(int sound)
{
	u32 address = GetAddressImmediate(&vaPlayMenuSound);
	const volatile u32* code = (const volatile u32*)address;
	if (!address || code[0] != 0x27bdfff0 || code[1] != 0x0000282d ||
	    code[2] != 0xffbf0000 || code[4] != 0x0000302d)
		return;
	((void (*)(int))address)(sound);
}
