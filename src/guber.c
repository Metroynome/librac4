#include "guber.h"
#include "interop.h"

#if defined(RAC4_PAL)
VariableAddress_t vaFirstGuberMobyPtr = {
    .Battledome = 0x00220790,
    .Catacrom = 0x00220790,
    .Sarathos = 0x00220790,
    .Kronos = 0x00220790,
    .Shaar = 0x00220790,
    .Valix = 0x00220790,
    .Orxon = 0x00220790,
    .Torval = 0x00220790,
    .Stygia = 0x00220790,
    .Maraxus = 0x00220790,
    .GhostStation = 0x00220790,
    .DreadZoneInterior = 0x00220790,
    .MainMenu = 0x00220790,
    .MultiplayerMenu = 0x00220790
};
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
VariableAddress_t vaFirstGuberMobyPtr = {
    .Battledome = 0x0023AF10,
    .Catacrom = 0x0023AF10,
    .Sarathos = 0x0023AF10,
    .Kronos = 0x0023AF10,
    .Shaar = 0x0023AF10,
    .Valix = 0x0023AF10,
    .Orxon = 0x0023AF10,
    .Torval = 0x0023AF10,
    .Stygia = 0x0023AF10,
    .Maraxus = 0x0023AF10,
    .GhostStation = 0x0023AF10,
    .DreadZoneInterior = 0x0023AF10,
    .MainMenu = 0x0023AF10,
    .MultiplayerMenu = 0x0023AF10
};
#else
VariableAddress_t vaFirstGuberMobyPtr = {
    .Battledome = 0x00220710,
    .Catacrom = 0x00220710,
    .Sarathos = 0x00220710,
    .Kronos = 0x00220710,
    .Shaar = 0x00220710,
    .Valix = 0x00220710,
    .Orxon = 0x00220710,
    .Torval = 0x00220710,
    .Stygia = 0x00220710,
    .Maraxus = 0x00220710,
    .GhostStation = 0x00220710,
    .DreadZoneInterior = 0x00220710,
    .MainMenu = 0x00220710,
    .MultiplayerMenu = 0x00220710
};
#endif

//--------------------------------------------------------
#define FIRST_GUBER_MOBY_PTR                         ((GuberMoby**)GetAddress(&vaFirstGuberMobyPtr))

/*
 * Returns the first guber moby.
 */
GuberMoby * guberMobyGetFirst(void)
{
    return *FIRST_GUBER_MOBY_PTR;
}
