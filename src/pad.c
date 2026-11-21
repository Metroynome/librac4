#include "string.h"
#include "pad.h"
#include "game.h"
#include "player.h"
#include "types.h"
#include "interop.h"

/* Native Cooperative overlays (levels 21-35), not campaign or libdl multiplayer.
 * Mapped against the retail 1.00 code images in rac-defs.json. */
VariableAddress_t vaCoopPadRead = {
#if RAC4_PAL
	.Battledome = 0x6bb298,
	.Catacrom = 0x66abd8,
	.Sarathos = 0x66aaa0,
	.Kronos = 0x691470,
	.Shaar = 0x662de8,
	.Valix = 0x655b10,
	.Orxon = 0x66db00,
	.Torval = 0x6783f8,
	.Stygia = 0x6653d8,
	.Maraxus = 0x67eca0,
	.GhostStation = 0x6788f0,
	.DreadZoneInterior = 0x688f08
#elif RAC4_NTSCJ
	.Battledome = 0x6d17b0,
	.Catacrom = 0x681570,
	.Sarathos = 0x681678,
	.Kronos = 0x6a7e48,
	.Shaar = 0x679c40,
	.Valix = 0x66c7e8,
	.Orxon = 0x6844d8,
	.Torval = 0x68ee10,
	.Stygia = 0x67c0b0,
	.Maraxus = 0x6955f8,
	.GhostStation = 0x68f288,
	.DreadZoneInterior = 0x69f920
#elif RAC4_NTSCK
	.Battledome = 0x6d17b0,
	.Catacrom = 0x681570,
	.Sarathos = 0x681678,
	.Kronos = 0x6a7e48,
	.Shaar = 0x679c40,
	.Valix = 0x66c7e8,
	.Orxon = 0x6844d8,
	.Torval = 0x68ee10,
	.Stygia = 0x67c0b0,
	.Maraxus = 0x6955f8,
	.GhostStation = 0x68f288,
	.DreadZoneInterior = 0x69f920
#else
	.Battledome = 0x6b5cb8,
	.Catacrom = 0x665c38,
	.Sarathos = 0x665c80,
	.Kronos = 0x68c450,
	.Shaar = 0x65e2c8,
	.Valix = 0x6512b0,
	.Orxon = 0x668ba0,
	.Torval = 0x6734d8,
	.Stygia = 0x660738,
	.Maraxus = 0x679c80,
	.GhostStation = 0x673950,
	.DreadZoneInterior = 0x683e28
#endif
};


/* Region-local addresses. */
#if RAC4_PAL
#define PAD_POINTER                         ((struct PAD**)0x0021de54)
#define PAD_P0                              ((struct PAD*)0x001ee680)
#define PAD_NO_INPUT_TIMER                  (*(u16*)0x00347EDA)
#define PAD_NO_CAMERA_TIMER                 (*(u16*)0x00347F22)
#elif RAC4_NTSCJ || RAC4_NTSCK
#define PAD_POINTER                         ((struct PAD**)0x002385d4)
#define PAD_P0                              ((struct PAD*)0x00208e40)
#define PAD_NO_INPUT_TIMER                  (*(u16*)0x0036265A)
#define PAD_NO_CAMERA_TIMER                 (*(u16*)0x003626A2)
#else
#define PAD_POINTER                         ((struct PAD**)0x0021DDCC)
#define PAD_P0                              ((struct PAD*)0x001ee600)
#define PAD_NO_INPUT_TIMER                  (*(u16*)0x00347E5A)
#define PAD_NO_CAMERA_TIMER                 (*(u16*)0x00347EA2)
#endif

#if RAC4_PAL
rac4VariableAddressCompact_t vaPadProcessAddr = {
	.MainMenu = 0x0061AA30,
	.Battledome = RAC4_VA_COMPACT_BASE(0x005F1830),
	.Catacrom = RAC4_VA_COMPACT_OFFSET(0x005F1830, 0x005E9BB0),
	.Sarathos = RAC4_VA_COMPACT_OFFSET(0x005F1830, 0x005E8E30),
	.Kronos = RAC4_VA_COMPACT_OFFSET(0x005F1830, 0x005EB3B0),
	.Shaar = RAC4_VA_COMPACT_OFFSET(0x005F1830, 0x005E8A30),
	.Valix = RAC4_VA_COMPACT_OFFSET(0x005F1830, 0x005E8E30),
	.Orxon = RAC4_VA_COMPACT_OFFSET(0x005F1830, 0x005E8DB0),
	.Torval = RAC4_VA_COMPACT_OFFSET(0x005F1830, 0x005EA130),
	.Stygia = RAC4_VA_COMPACT_OFFSET(0x005F1830, 0x005E80B0),
	.Maraxus = RAC4_VA_COMPACT_OFFSET(0x005F1830, 0x005EA030),
	.GhostStation = RAC4_VA_COMPACT_OFFSET(0x005F1830, 0x005EA5B0),
	.DreadZoneInterior = RAC4_VA_COMPACT_OFFSET(0x005F1830, 0x005EE7B0),
};
#elif RAC4_NTSCJ || RAC4_NTSCK
rac4VariableAddressCompact_t vaPadProcessAddr = {
	.MainMenu = 0x0063EA30,
	.Battledome = RAC4_VA_COMPACT_BASE(0x0060C330),
	.Catacrom = RAC4_VA_COMPACT_OFFSET(0x0060C330, 0x006045B0),
	.Sarathos = RAC4_VA_COMPACT_OFFSET(0x0060C330, 0x006038B0),
	.Kronos = RAC4_VA_COMPACT_OFFSET(0x0060C330, 0x00605E30),
	.Shaar = RAC4_VA_COMPACT_OFFSET(0x0060C330, 0x00603530),
	.Valix = RAC4_VA_COMPACT_OFFSET(0x0060C330, 0x006038B0),
	.Orxon = RAC4_VA_COMPACT_OFFSET(0x0060C330, 0x00603830),
	.Torval = RAC4_VA_COMPACT_OFFSET(0x0060C330, 0x00604BB0),
	.Stygia = RAC4_VA_COMPACT_OFFSET(0x0060C330, 0x00602B30),
	.Maraxus = RAC4_VA_COMPACT_OFFSET(0x0060C330, 0x00604B30),
	.GhostStation = RAC4_VA_COMPACT_OFFSET(0x0060C330, 0x00605030),
	.DreadZoneInterior = RAC4_VA_COMPACT_OFFSET(0x0060C330, 0x006092B0),
};
#else
rac4VariableAddressCompact_t vaPadProcessAddr = {
	.MainMenu = 0x0061AA30,
	.Battledome = RAC4_VA_COMPACT_BASE(0x005F16B0),
	.Catacrom = RAC4_VA_COMPACT_OFFSET(0x005F16B0, 0x005E99B0),
	.Sarathos = RAC4_VA_COMPACT_OFFSET(0x005F16B0, 0x005E8C30),
	.Kronos = RAC4_VA_COMPACT_OFFSET(0x005F16B0, 0x005EB1B0),
	.Shaar = RAC4_VA_COMPACT_OFFSET(0x005F16B0, 0x005E8930),
	.Valix = RAC4_VA_COMPACT_OFFSET(0x005F16B0, 0x005E8D30),
	.Orxon = RAC4_VA_COMPACT_OFFSET(0x005F16B0, 0x005E8C30),
	.Torval = RAC4_VA_COMPACT_OFFSET(0x005F16B0, 0x005E9FB0),
	.Stygia = RAC4_VA_COMPACT_OFFSET(0x005F16B0, 0x005E7F30),
	.Maraxus = RAC4_VA_COMPACT_OFFSET(0x005F16B0, 0x005E9F30),
	.GhostStation = RAC4_VA_COMPACT_OFFSET(0x005F16B0, 0x005EA430),
	.DreadZoneInterior = RAC4_VA_COMPACT_OFFSET(0x005F16B0, 0x005EE630),
};
#endif

#if RAC4_PAL
rac4VariableAddressCompact_t vaPadProcessFunc = {
	.MainMenu = 0x0061A868,
	.Battledome = RAC4_VA_COMPACT_BASE(0x005F1668),
	.Catacrom = RAC4_VA_COMPACT_OFFSET(0x005F1668, 0x005E99E8),
	.Sarathos = RAC4_VA_COMPACT_OFFSET(0x005F1668, 0x005E8C68),
	.Kronos = RAC4_VA_COMPACT_OFFSET(0x005F1668, 0x005EB1E8),
	.Shaar = RAC4_VA_COMPACT_OFFSET(0x005F1668, 0x005E8868),
	.Valix = RAC4_VA_COMPACT_OFFSET(0x005F1668, 0x005E8C68),
	.Orxon = RAC4_VA_COMPACT_OFFSET(0x005F1668, 0x005E8BE8),
	.Torval = RAC4_VA_COMPACT_OFFSET(0x005F1668, 0x005E9F68),
	.Stygia = RAC4_VA_COMPACT_OFFSET(0x005F1668, 0x005E7EE8),
	.Maraxus = RAC4_VA_COMPACT_OFFSET(0x005F1668, 0x005E9E68),
	.GhostStation = RAC4_VA_COMPACT_OFFSET(0x005F1668, 0x005EA3E8),
	.DreadZoneInterior = RAC4_VA_COMPACT_OFFSET(0x005F1668, 0x005EE5E8),
};
#elif RAC4_NTSCJ || RAC4_NTSCK
rac4VariableAddressCompact_t vaPadProcessFunc = {
	.MainMenu = 0x0063E868,
	.Battledome = RAC4_VA_COMPACT_BASE(0x0060C168),
	.Catacrom = RAC4_VA_COMPACT_OFFSET(0x0060C168, 0x006043E8),
	.Sarathos = RAC4_VA_COMPACT_OFFSET(0x0060C168, 0x006036E8),
	.Kronos = RAC4_VA_COMPACT_OFFSET(0x0060C168, 0x00605C68),
	.Shaar = RAC4_VA_COMPACT_OFFSET(0x0060C168, 0x00603368),
	.Valix = RAC4_VA_COMPACT_OFFSET(0x0060C168, 0x006036E8),
	.Orxon = RAC4_VA_COMPACT_OFFSET(0x0060C168, 0x00603668),
	.Torval = RAC4_VA_COMPACT_OFFSET(0x0060C168, 0x006049E8),
	.Stygia = RAC4_VA_COMPACT_OFFSET(0x0060C168, 0x00602968),
	.Maraxus = RAC4_VA_COMPACT_OFFSET(0x0060C168, 0x00604968),
	.GhostStation = RAC4_VA_COMPACT_OFFSET(0x0060C168, 0x00604E68),
	.DreadZoneInterior = RAC4_VA_COMPACT_OFFSET(0x0060C168, 0x006090E8),
};
#else
rac4VariableAddressCompact_t vaPadProcessFunc = {
	.MainMenu = 0x0061A868,
	.Battledome = RAC4_VA_COMPACT_BASE(0x005F14E8),
	.Catacrom = RAC4_VA_COMPACT_OFFSET(0x005F14E8, 0x005E97E8),
	.Sarathos = RAC4_VA_COMPACT_OFFSET(0x005F14E8, 0x005E8A68),
	.Kronos = RAC4_VA_COMPACT_OFFSET(0x005F14E8, 0x005EAFE8),
	.Shaar = RAC4_VA_COMPACT_OFFSET(0x005F14E8, 0x005E8768),
	.Valix = RAC4_VA_COMPACT_OFFSET(0x005F14E8, 0x005E8B68),
	.Orxon = RAC4_VA_COMPACT_OFFSET(0x005F14E8, 0x005E8A68),
	.Torval = RAC4_VA_COMPACT_OFFSET(0x005F14E8, 0x005E9DE8),
	.Stygia = RAC4_VA_COMPACT_OFFSET(0x005F14E8, 0x005E7D68),
	.Maraxus = RAC4_VA_COMPACT_OFFSET(0x005F14E8, 0x005E9D68),
	.GhostStation = RAC4_VA_COMPACT_OFFSET(0x005F14E8, 0x005EA268),
	.DreadZoneInterior = RAC4_VA_COMPACT_OFFSET(0x005F14E8, 0x005EE468),
};
#endif

#define P1_PAD                              ((PadButtonStatus*)((u32)padGetPad(0) + 0x574))
#define P2_PAD                              ((PadButtonStatus*)((u32)padGetPad(1) + 0x574))
#define PAD_PROCESS_ADDR                    (*(u32*)GetAddress(&vaPadProcessAddr))
#define PAD_PROCESS_VALUE                   (0x0C000000 | (GetAddress(&vaPadProcessFunc) >> 2))

// Default value for pad history
const PadHistory DefaultPadHistory = {
    0xFFFF,
    0x7F,
    0x7F,
    0x7F,
    0x7F,
    -1
};

// Local pad history
PadHistory LocalPadHistory[PAD_PORT_MAX];

struct PAD* padGetPad(int localPlayerIdx)
{
    if (localPlayerIdx < 0 || localPlayerIdx >= PAD_PORT_MAX)
        return NULL;

    struct PAD* pad = PAD_POINTER[localPlayerIdx];
    if (!pad && !localPlayerIdx)
        return PAD_P0;

    return pad;
}

/*
 * NAME :		padUpdate
 * 
 * DESCRIPTION :
 * 			Processes pad state, registering when a button is pressed and released.
 * 
 * NOTES :
 *          This must be called every tick in order for pad functionality to work.
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
void padUpdate(void)
{
    // Update local pad
    memcpy(LocalPadHistory, &P1_PAD->btns, 6);
    memcpy(LocalPadHistory+1, &P2_PAD->btns, 6);
}

/*
 * NAME :		padGetButton
 * 
 * DESCRIPTION :
 * 			Returns 1 when the user is pressing the given button combination.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          port:                       Which controller port to read.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
int padGetButton(int port, u16 buttonMask)
{
    switch (port)
    {
        case 0: return (P1_PAD->btns & buttonMask) == 0;
        case 1: return (P2_PAD->btns & buttonMask) == 0;
        default: return -1;
    }
}

/*
 * NAME :		padGetButtonDown
 * 
 * DESCRIPTION :
 * 			Returns 1 during the frame that the user starts pressing the given button combination.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          port:                       Which controller port to read.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
int padGetButtonDown(int port, u16 buttonMask)
{
    if (port < 0 || port >= PAD_PORT_MAX)
        return -1;

    return padGetButton(port, buttonMask) &&
            (LocalPadHistory[port].btns & buttonMask) != 0;
}

/*
 * NAME :		padGetButtonUp
 * 
 * DESCRIPTION :
 * 			Returns 1 during the frame that the user releases the given button combination.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          port:                       Which controller port to read.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
int padGetButtonUp(int port, u16 buttonMask)
{
    if (port < 0 || port >= PAD_PORT_MAX)
        return -1;

    return !padGetButton(port, buttonMask) &&
        (LocalPadHistory[port].btns & buttonMask) == 0;
}

/*
 * NAME :		padResetInput
 * 
 * DESCRIPTION :
 * 			Resets the given ports inputs.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          port:                       Which controller port to reset.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
void padResetInput(int port)
{
    if (port < 0 || port >= PAD_PORT_MAX)
        return;

    PadButtonStatus * pad = port ? P2_PAD : P1_PAD;

    u64 defaultValue = 0x7F7F7F7FFFFF7900;
    memcpy((void*)pad, &defaultValue, 8);
    memcpy((void*)((u32)pad + 0x80), &defaultValue, 8);
}

/*
 * NAME :		padDisableInput
 * 
 * DESCRIPTION :
 * 			Disables the pad input.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
void padDisableInput(void)
{
    if (PAD_PROCESS_ADDR == PAD_PROCESS_VALUE)
        PAD_PROCESS_ADDR = 0;

    if (isInGame())
    {
        // no input timer
        PAD_NO_INPUT_TIMER = 0x7FFF;

        // no cam
        PAD_NO_CAMERA_TIMER = 0x7FFF;
    }
}

/*
 * NAME :		padEnableInput
 * 
 * DESCRIPTION :
 * 			Enables the pad input.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
void padEnableInput(void)
{
    PAD_PROCESS_ADDR = PAD_PROCESS_VALUE;

    if (isInGame())
    {
        // no input timer
        PAD_NO_INPUT_TIMER = 0;

        // no cam
        PAD_NO_CAMERA_TIMER = 0;
    }
}
