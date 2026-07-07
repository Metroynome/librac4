#include "graphics.h"
#include "interop.h"
#include "utils.h"
#include "game.h"


#if defined(RAC4_PAL)
VariableAddress_t vaGetTextWidthFunc = {
    .Battledome = 0x005610B0, .Catacrom = 0x005131B0, .Sarathos = 0x00513418, .Kronos = 0x00537A58,
    .Shaar = 0x0050AD88, .Valix = 0x004FC500, .Orxon = 0x00514410, .Torval = 0x0051F188,
    .Stygia = 0x0050BF70, .Maraxus = 0x00525830, .GhostStation = 0x0051E648, .DreadZoneInterior = 0x005300F0,
    .MainMenu = 0x00454F98, .MultiplayerMenu = 0x005BEE68
};
VariableAddress_t vaDrawTextFunc = {
    .Battledome = 0x005613A0, .Catacrom = 0x005134A0, .Sarathos = 0x00513708, .Kronos = 0x00537D48,
    .Shaar = 0x0050B078, .Valix = 0x004FC7F0, .Orxon = 0x00514700, .Torval = 0x0051F478,
    .Stygia = 0x0050C260, .Maraxus = 0x00525B20, .GhostStation = 0x0051E938, .DreadZoneInterior = 0x005303E0,
    .MainMenu = 0x00455288, .MultiplayerMenu = 0x005BF230
};
#elif defined(RAC4_NTSCJ) || defined(RAC4_NTSCK)
VariableAddress_t vaGetTextWidthFunc = {
    .Battledome = 0x005795E8, .Catacrom = 0x0052BB10, .Sarathos = 0x0052BFA8, .Kronos = 0x00550428,
    .Shaar = 0x00523B98, .Valix = 0x00515190, .Orxon = 0x0052CDA0, .Torval = 0x00537B58,
    .Stygia = 0x00524C00, .Maraxus = 0x0053E140, .GhostStation = 0x00536F98, .DreadZoneInterior = 0x00548AD8,
    .MainMenu = 0x004786B0, .MultiplayerMenu = 0x005D8828
};
VariableAddress_t vaDrawTextFunc = {
    .Battledome = 0x005798D8, .Catacrom = 0x0052BE00, .Sarathos = 0x0052C298, .Kronos = 0x00550718,
    .Shaar = 0x00523E88, .Valix = 0x00515480, .Orxon = 0x0052D090, .Torval = 0x00537E48,
    .Stygia = 0x00524EF0, .Maraxus = 0x0053E430, .GhostStation = 0x00537288, .DreadZoneInterior = 0x00548DC8,
    .MainMenu = 0x004789A0, .MultiplayerMenu = 0x005D8BF0
};
#else
VariableAddress_t vaGetTextWidthFunc = {
    .Battledome = 0x0055E4D0, .Catacrom = 0x00510BF8, .Sarathos = 0x00510FD0, .Kronos = 0x00535410,
    .Shaar = 0x00508C40, .Valix = 0x004FA638, .Orxon = 0x00511E48, .Torval = 0x0051CC40,
    .Stygia = 0x00509CA8, .Maraxus = 0x005231E8, .GhostStation = 0x0051C040, .DreadZoneInterior = 0x0052DA00,
    .MainMenu = 0x00454780, .MultiplayerMenu = 0x005BDC90
};
VariableAddress_t vaDrawTextFunc = {
    .Battledome = 0x0055E7C0, .Catacrom = 0x00510EE8, .Sarathos = 0x005112C0, .Kronos = 0x00535700,
    .Shaar = 0x00508F30, .Valix = 0x004FA928, .Orxon = 0x00512138, .Torval = 0x0051CF30,
    .Stygia = 0x00509F98, .Maraxus = 0x005234D8, .GhostStation = 0x0051C330, .DreadZoneInterior = 0x0052DCF0,
    .MainMenu = 0x00454A70, .MultiplayerMenu = 0x005BE058
};
#endif

int gfxGetAddressByOffset(int Offset)
{
	int player = *(u32*)0x001eeb70;
	int hudptr = *(u32*)(player - 0x67b4);
	int ptr = *(u32*)(hudptr + 0x28);
	int ptr1 = *(u32*)(ptr + 0x80);
	int jal1 = ConvertJALtoAddress(*(u32*)(ptr1 + 0x170));
	int jal2 = ConvertJALtoAddress(*(u32*)(jal1 + 0x8));
	return jal2 + Offset;
}

int drawFunc(u32 color, const char * string, int length, int alignment, float x, float y, float scaleX, float scaleY)
{
	int draw = GetAddress(&vaDrawTextFunc);
	((void (*)(u32,const char*,long,u64,u64,u64,float,float,float,float,float,float))draw)(color, string, length, alignment, 0, 0x80000000, x, y, scaleX, scaleY, 0, 0);
}

int widthFunc(const char * string, int length, float scale)
{
	int width = GetAddress(&vaGetTextWidthFunc);
	((void (*)(const char *, int, float))width)(string, length, scale);
}

int gfxScreenSpaceText(float x, float y, float scaleX, float scaleY, u32 color, const char * string, int length, int alignment)
{
	int (*internal_drawFunc)(float, float, float, float, u32, const char *, int, int) = NULL;
	int (*internal_widthFunc)(const char *, int, float) = NULL;
	// if in game (a.k.a. Level is Loaded)
	if (isInGame())
	{
		void *drawPtr = (void *)&drawFunc;
		internal_drawFunc = (void (*)(float, float, float, float, u32, const char *, int, int))drawPtr;

		void *widthPtr = (void *)&widthFunc;
		internal_widthFunc = (void (*)(const char *, int, float))widthPtr;
	}
	// if on Main Menu
	else if (isInMenus())
	{
		internal_drawFunc = &internal_drawFunc_MainMenu;
		internal_widthFunc = &internal_widthFunc_MainMenu;
	}
	// Fallback menu renderer
	else
	{
		internal_drawFunc = &internal_drawFunc_MultiplayerMenu;
		internal_widthFunc = &internal_widthFunc_MultiplayerMenu;
	}

	internal_drawFunc(x, y, scaleX, scaleY, color, string, length, alignment);
	return x + internal_widthFunc(string, length, scaleX);
}
