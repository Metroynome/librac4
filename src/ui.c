#include "ui.h"
#include "player.h"
#include "utils.h"
#include "types.h"

#define UI_ACTIVE_ID                            (*(int*)RAC4_LEVEL_CODE0(0x125338))
#define UI_DIALOG_A0                            ((void*)0x011C7000)

int internal_uiDialog(void *, const char *, const char *, int, int, int, int);
int internal_uiSelectDialog(void *, const char *, const char **, int, int, int, int);
int internal_uiInputDialog(void *, const char *, char *, int, int, int, int, int, int);

int uiGetAddressByOffset(int Offset)
{
    int HeroStruct = *(u32*)0x001eeb70;
    if (HeroStruct == 0)
        return;

    Player * player = (Player*)((u32)HeroStruct - 0x2FEC);
    PlayerVTable * vtable = playerGetVTable(player)->Update;
    int jal1 = (u32)vtable + 0x410;
    int jal2 = (u32)ConvertJALtoAddress(*(u32*)jal1) + 0x13E0;
    int func = (u32)ConvertJALtoAddress(*(u32*)jal2) + Offset;
}

void uiShowHelpPopup(int localPlayerIndex, const char * message, int seconds)
{
     // Catacrom: 0x00587D10
    int func = uiGetAddressByOffset(-0x80);
	((void (*)(int, const char *, int))func)(localPlayerIndex, message, seconds);
}

void uiShowPopup(int localPlayerIndex, const char * message)
{
    int GUI_PrintPrompt = uiGetAddressByOffset(0);
	((void (*)(int, const char *))GUI_PrintPrompt)(localPlayerIndex, message);
}

void uiShowHelpPopupByTextID(int localPlayerIndex, int textId)
{
    int func = uiGetAddressByOffset(0x20);
	((void (*)(int, int))func)(localPlayerIndex, textId);
}

void uiPrintAmmoPickup(int localPlayerIndex, int textId)
{
    int func = uiGetAddressByOffset(0x58);
     // Catacrom: 0x00587DE8
	((void (*)(int, int))func)(localPlayerIndex, textId);
}

void uiShowTimer(int localPlayerIndex, int textId)
{
    // Still can't find this.
}

int uiGetActive(void)
{
    return UI_ACTIVE_ID;
}

int uiShowYesNoDialog(const char * title, const char * description)
{
    return internal_uiDialog(UI_DIALOG_A0, title, description, 3, 0, 1, 0);
}

int uiShowOkDialog(const char * title, const char * description)
{
    return internal_uiDialog(UI_DIALOG_A0, title, description, 4, 0, 0, 0);
}

int uiShowSelectDialog(const char * title, const char * items[], int itemCount, int selectedIndex)
{
    return internal_uiSelectDialog(UI_DIALOG_A0, title, items, itemCount, selectedIndex, 0, 0);
}

int uiShowInputDialog(const char * title, char * value, int maxLength)
{
    return internal_uiInputDialog(UI_DIALOG_A0, title, value, 0, maxLength, 0, 0, 0, 0);
}

void msg_string(int textId)
{
    int jal3 = uiGetAddressByOffset(0x30);
    int msg_stringFunc = ConvertJALtoAddress(*(u32*)jal3);
    ((void (*)(int))msg_stringFunc)(textId);
}

char * uiMsgString(int textId)
{
    if (isInGame())
    {
        int (*msg_stringInit)(int) = NULL;
        void *ptr = (void *)&msg_string;
        msg_stringInit = (void (*)(int))ptr;

        msg_stringInit(textId);
    }
    // else if (isInMenus())
    // {
    //     return internal_uiMsgString_inLobby(textId);
    // }

    return NULL;
}

void uiChangeMenu(enum UiMenuIds menuId)
{
    *(int*)((int)UI_DIALOG_A0 + 0x118) = (int)menuId;
}

UiMenu_t* uiGetPointer(int id)
{
    return *(UiMenu_t**)((u32)UI_DIALOG_A0 + 0x64 + (id * 4));
}

UiMenu_t* uiGetActivePointer()
{
    return *(UiMenu_t**)((u32)UI_DIALOG_A0 + 0x64 + 0xA4);
}
