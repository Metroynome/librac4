#include "graphics.h"
#include "interop.h"
#include "utils.h"
#include "game.h"
#include "types.h"

#define heroStructPointerAddress (0x001eeb70)



#if RAC4_PAL
VariableAddress_t vaGetTextWidthFunc = {
	.MainMenu = 0x00454f98,
	.Battledome = 0x005610b0,
	.Catacrom = 0x005131b0,
	.Sarathos = 0x00513418,
	.Kronos = 0x00537a58,
	.Shaar = 0x0050ad88,
	.Valix = 0x004fc500,
	.Orxon = 0x00514410,
	.Torval = 0x0051f188,
	.Stygia = 0x0050bf70,
	.Maraxus = 0x00525830,
	.GhostStation = 0x0051e648,
	.DreadZoneInterior = 0x005300f0,
};
VariableAddress_t vaDrawTextFunc = {
	.MainMenu = 0x00455288,
	.Battledome = 0x005613a0,
	.Catacrom = 0x005134a0,
	.Sarathos = 0x00513708,
	.Kronos = 0x00537d48,
	.Shaar = 0x0050b078,
	.Valix = 0x004fc7f0,
	.Orxon = 0x00514700,
	.Torval = 0x0051f478,
	.Stygia = 0x0050c260,
	.Maraxus = 0x00525b20,
	.GhostStation = 0x0051e938,
	.DreadZoneInterior = 0x005303e0,
};
#elif RAC4_NTSCJ || RAC4_NTSCK
VariableAddress_t vaGetTextWidthFunc = {
	.MainMenu = 0x004786b0,
	.Battledome = 0x005795e8,
	.Catacrom = 0x0052bb10,
	.Sarathos = 0x0052bfa8,
	.Kronos = 0x00550428,
	.Shaar = 0x00523b98,
	.Valix = 0x00515190,
	.Orxon = 0x0052cda0,
	.Torval = 0x00537b58,
	.Stygia = 0x00524c00,
	.Maraxus = 0x0053e140,
	.GhostStation = 0x00536f98,
	.DreadZoneInterior = 0x00548ad8,
};
VariableAddress_t vaDrawTextFunc = {
	.MainMenu = 0x004789a0,
	.Battledome = 0x005798d8,
	.Catacrom = 0x0052be00,
	.Sarathos = 0x0052c298,
	.Kronos = 0x00550718,
	.Shaar = 0x00523e88,
	.Valix = 0x00515480,
	.Orxon = 0x0052d090,
	.Torval = 0x00537e48,
	.Stygia = 0x00524ef0,
	.Maraxus = 0x0053e430,
	.GhostStation = 0x00537288,
	.DreadZoneInterior = 0x00548dc8,
};
#else
VariableAddress_t vaGetTextWidthFunc = {
	.MainMenu = 0x00454780,
	.Battledome = 0x0055e4d0,
	.Catacrom = 0x00510bf8,
	.Sarathos = 0x00510fd0,
	.Kronos = 0x00535410,
	.Shaar = 0x00508c40,
	.Valix = 0x004fa638,
	.Orxon = 0x00511e48,
	.Torval = 0x0051cc40,
	.Stygia = 0x00509ca8,
	.Maraxus = 0x005231e8,
	.GhostStation = 0x0051c040,
	.DreadZoneInterior = 0x0052da00,
};
VariableAddress_t vaDrawTextFunc = {
	.MainMenu = 0x00454a70,
	.Battledome = 0x0055e7c0,
	.Catacrom = 0x00510ee8,
	.Sarathos = 0x005112c0,
	.Kronos = 0x00535700,
	.Shaar = 0x00508f30,
	.Valix = 0x004fa928,
	.Orxon = 0x00512138,
	.Torval = 0x0051cf30,
	.Stygia = 0x00509f98,
	.Maraxus = 0x005234d8,
	.GhostStation = 0x0051c330,
	.DreadZoneInterior = 0x0052dcf0,
};
#endif

/* Rectangle entry points matched against every retail campaign/co-op overlay. */
#if RAC4_PAL
VariableAddress_t vaDrawBoxFunc = {
	.MainMenu = 0x502fd8,
	.Battledome = 0x65bcf0,
	.Catacrom = 0x60b6a0,
	.Sarathos = 0x60b3b0,
	.Kronos = 0x631cf0,
	.Shaar = 0x603820,
	.Valix = 0x5f6678,
	.Orxon = 0x60e5c8,
	.Torval = 0x618ec0,
	.Stygia = 0x605ce8,
	.Maraxus = 0x61f5b0,
	.GhostStation = 0x619200,
	.DreadZoneInterior = 0x629940
};
#elif RAC4_NTSCJ || RAC4_NTSCK
VariableAddress_t vaDrawBoxFunc = {
	.MainMenu = 0x526320,
	.Battledome = 0x672458,
	.Catacrom = 0x622288,
	.Sarathos = 0x6221d8,
	.Kronos = 0x648918,
	.Shaar = 0x61a8c8,
	.Valix = 0x60d5a0,
	.Orxon = 0x6251f0,
	.Torval = 0x62fb28,
	.Stygia = 0x61cc10,
	.Maraxus = 0x636158,
	.GhostStation = 0x62fde8,
	.DreadZoneInterior = 0x6405a8
};
#else
VariableAddress_t vaDrawBoxFunc = {
	.MainMenu = 0x501f68,
	.Battledome = 0x656bc0,
	.Catacrom = 0x606bb0,
	.Sarathos = 0x606a40,
	.Kronos = 0x62d180,
	.Shaar = 0x5ff1b0,
	.Valix = 0x5f22c8,
	.Orxon = 0x609b18,
	.Torval = 0x614450,
	.Stygia = 0x6014f8,
	.Maraxus = 0x61aa40,
	.GhostStation = 0x614710,
	.DreadZoneInterior = 0x624d10
};
#endif

int gfxGetAddressByOffset(int Offset)
{
	int player = *(u32*)heroStructPointerAddress;
	int hudptr = *(u32*)(player - 0x67b4);
	int ptr = *(u32*)(hudptr + 0x28);
	int ptr1 = *(u32*)(ptr + 0x80);
	int jal1 = ConvertJALtoAddress(*(u32*)(ptr1 + 0x170));
	int jal2 = ConvertJALtoAddress(*(u32*)(jal1 + 0x8));
	return jal2 + Offset;
}

int drawFunc(u32 color, const char* text, int length, int alignment, float x, float y, float scaleX, float scaleY)
{
	u32 draw = GetAddressImmediate(&vaDrawTextFunc);
	if (!draw || !text)
		return 0;
	((void (*)(u32, const char*, long, u64, u64, u64, float, float, float, float, float, float))draw)
		(color, text, length, alignment, 1, 0x80000000, x, y, scaleX, scaleY, 1, 1);
	return 0;
}

int widthFunc(const char* text, int length, float scale)
{
	u32 width = GetAddressImmediate(&vaGetTextWidthFunc);
	return width && text ? ((int (*)(const char*, int, float))width)(text, length, scale) : 0;
}

int gfxGetFontWidth(const char* text, int length, float scale)
{
	return widthFunc(text, length, scale);
}

int gfxScreenSpaceText(float x, float y, float scaleX, float scaleY, u32 color,
                      const char* text, int length, int alignment)
{
	drawFunc(color, text, length, alignment, x, y, scaleX, scaleY);
	return x + widthFunc(text, length, scaleX);
}

void gfxScreenSpaceBox(float x, float y, float width, float height, u32 color)
{
	u32 draw = GetAddressImmediate(&vaDrawBoxFunc);
	float rect[8] __attribute__((aligned(16))) = {
		x, y, x + width, y, x, y + height, x + width, y + height
	};
	u32 data[11] __attribute__((aligned(16))) = {
		8, 0, 0, 0, 0, 0xbe130000, color, color, color, color, 2
	};
	if (draw)
		((void (*)(const float*, const u32*))draw)(rect, data);
}
