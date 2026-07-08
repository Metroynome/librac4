#include "string.h"
#include "pad.h"
#include "game.h"
#include "player.h"
#include "types.h"
#include "interop.h"

/* Region-local addresses. */
#if RAC4_PAL
#define PAD_POINTER                         ((struct PAD**)0x0021DE4C)
#define PAD_P0                              ((struct PAD*)0x001EE600)
#define PAD_NO_INPUT_TIMER                  (*(u16*)0x00347EDA)
#define PAD_NO_CAMERA_TIMER                 (*(u16*)0x00347F22)
#elif RAC4_NTSCJ || RAC4_NTSCK
#define PAD_POINTER                         ((struct PAD**)0x002385CC)
#define PAD_P0                              ((struct PAD*)0x001EE600)
#define PAD_NO_INPUT_TIMER                  (*(u16*)0x0036265A)
#define PAD_NO_CAMERA_TIMER                 (*(u16*)0x003626A2)
#else
#define PAD_POINTER                         ((struct PAD**)0x0021DDCC)
#define PAD_P0                              ((struct PAD*)0x001EE600)
#define PAD_NO_INPUT_TIMER                  (*(u16*)0x00347E5A)
#define PAD_NO_CAMERA_TIMER                 (*(u16*)0x00347EA2)
#endif

#if RAC4_PAL
VariableAddress_t vaPadProcessAddr = {
    .MainMenu = 0x0061AA30,
    .Battledome = 0x005F1830,
    .Catacrom = 0x005E9BB0,
    .Sarathos = 0x005E8E30,
    .Kronos = 0x005EB3B0,
    .Shaar = 0x005E8A30,
    .Valix = 0x005E8E30,
    .Orxon = 0x005E8DB0,
    .Torval = 0x005EA130,
    .Stygia = 0x005E80B0,
    .Maraxus = 0x005EA030,
    .GhostStation = 0x005EA5B0,
    .DreadZoneInterior = 0x005EE7B0,
};
#elif RAC4_NTSCJ || RAC4_NTSCK
VariableAddress_t vaPadProcessAddr = {
    .MainMenu = 0x0063EA30,
    .Battledome = 0x0060C330,
    .Catacrom = 0x006045B0,
    .Sarathos = 0x006038B0,
    .Kronos = 0x00605E30,
    .Shaar = 0x00603530,
    .Valix = 0x006038B0,
    .Orxon = 0x00603830,
    .Torval = 0x00604BB0,
    .Stygia = 0x00602B30,
    .Maraxus = 0x00604B30,
    .GhostStation = 0x00605030,
    .DreadZoneInterior = 0x006092B0,
};
#else
VariableAddress_t vaPadProcessAddr = {
    .MainMenu = 0x0061AA30,
    .Battledome = 0x005F16B0,
    .Catacrom = 0x005E99B0,
    .Sarathos = 0x005E8C30,
    .Kronos = 0x005EB1B0,
    .Shaar = 0x005E8930,
    .Valix = 0x005E8D30,
    .Orxon = 0x005E8C30,
    .Torval = 0x005E9FB0,
    .Stygia = 0x005E7F30,
    .Maraxus = 0x005E9F30,
    .GhostStation = 0x005EA430,
    .DreadZoneInterior = 0x005EE630,
};
#endif

#if RAC4_PAL
VariableAddress_t vaPadProcessFunc = {
    .MainMenu = 0x0061A868,
    .Battledome = 0x005F1668,
    .Catacrom = 0x005E99E8,
    .Sarathos = 0x005E8C68,
    .Kronos = 0x005EB1E8,
    .Shaar = 0x005E8868,
    .Valix = 0x005E8C68,
    .Orxon = 0x005E8BE8,
    .Torval = 0x005E9F68,
    .Stygia = 0x005E7EE8,
    .Maraxus = 0x005E9E68,
    .GhostStation = 0x005EA3E8,
    .DreadZoneInterior = 0x005EE5E8,
};
#elif RAC4_NTSCJ || RAC4_NTSCK
VariableAddress_t vaPadProcessFunc = {
    .MainMenu = 0x0063E868,
    .Battledome = 0x0060C168,
    .Catacrom = 0x006043E8,
    .Sarathos = 0x006036E8,
    .Kronos = 0x00605C68,
    .Shaar = 0x00603368,
    .Valix = 0x006036E8,
    .Orxon = 0x00603668,
    .Torval = 0x006049E8,
    .Stygia = 0x00602968,
    .Maraxus = 0x00604968,
    .GhostStation = 0x00604E68,
    .DreadZoneInterior = 0x006090E8,
};
#else
VariableAddress_t vaPadProcessFunc = {
    .MainMenu = 0x0061A868,
    .Battledome = 0x005F14E8,
    .Catacrom = 0x005E97E8,
    .Sarathos = 0x005E8A68,
    .Kronos = 0x005EAFE8,
    .Shaar = 0x005E8768,
    .Valix = 0x005E8B68,
    .Orxon = 0x005E8A68,
    .Torval = 0x005E9DE8,
    .Stygia = 0x005E7D68,
    .Maraxus = 0x005E9D68,
    .GhostStation = 0x005EA268,
    .DreadZoneInterior = 0x005EE468,
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
