
/* Region-local addresses. */
#if RAC4_PAL
#define Level                               (0x0021DE90)
#define Mission                             (0x00171228)
#elif RAC4_NTSCJ || RAC4_NTSCK
#define Level                               (0x00238610)
#define Mission                             (0x00171128)
#else
#define Level                               (0x0021DE10)
#define Mission                             (0x001711A8)
#endif

// fixed address function
#define FUNCTION(name, address) \
	.set	push;		        \
	.set	noreorder;	        \
	.section	.text.##name,"ax",@progbits; \
	.align 2;		            \
	.globl	name;		        \
	.type	name,@function;	    \
	.ent	name,0;		        \
name:	j address;              \
	nop;			            \
	.end	name;		        \
	.size	name,.-name;	    \
	.set	pop;

// variable address function
#define VARIABLE_FUNCTION(name, variable_address_struct) \
	.set	push;		        				\
	.set	noreorder;	        		\
	.section	.text.##name,"ax",@progbits; \
	.align 2;		            			\
	.globl	name;		        			\
	.type	name,@function;	    		\
	.ent	name,0;		        			\
	.extern variable_address_struct; \
name:												\
		addiu $sp, $sp, -0x40;			\
		sq $ra, 0x00($sp);					\
		sq $a0, 0x10($sp);					\
		sq $a1, 0x20($sp);					\
		sq $s0, 0x30($sp);					\
		la $a0, variable_address_struct; \
		la $a1, ##name##_return;				\
		j __LocalGetAddress;        \
		nop;			            			\
##name##_return:									\
		beq $zero, $v0, ##name##_exit;	\
		nop;								\
		lq $a1, 0x20($sp);					\
		jalr $v0;								\
		lq $a0, 0x10($sp);					\
##name##_exit:										\
		lq $ra, 0x00($sp);					\
		lq $s0, 0x30($sp);					\
		jr $ra;									\
		addiu $sp, $sp, 0x40;				\
	.end	name;		        				\
	.size	name,.-name;	   	 		\
	.set	pop;

__LocalGetAddress_offsets:
	// Level to VariableAddress_t byte offset.
	// Co-op map ids are normalized by subtracting 20 before this lookup.
	// 1 Battledome, 2 Catacrom, 4 Sarathos, 5 Kronos, 6 Shaar, 7 Valix,
	// 8 Orxon, 10 Torval, 11 Stygia, 13 Maraxus, 14 Ghost Station,
	// 15 DreadZone Interior, 16 Main Menu.
	.byte -1,4,8,-1,12,16,20,24,28,-1,32,36,-1,40,44,48,0;

// 
	.set	push;
	.set	noreorder;
	.section	.text.##__LocalGetAddress,"ax",@progbits;
	.align 2;
	.globl	__LocalGetAddress;
	.type	__LocalGetAddress,@function;
	.ent	__LocalGetAddress,0;
__LocalGetAddress:
	or $t9, $a1, $zero;
	j __ResolveVariableAddress;
	nop;
	.end	__LocalGetAddress;
	.size	__LocalGetAddress,.-__LocalGetAddress;
	.set	pop;

// 
	.set	push;
	.set	noreorder;
	.section	.text.##GetAddress,"ax",@progbits;
	.align 2;
	.globl	GetAddress;
	.type	GetAddress,@function;
	.ent	GetAddress,0;
GetAddress:
	or $t9, $ra, $zero;
	j __ResolveVariableAddress;
	nop;
	.end	GetAddress;
	.size	GetAddress,.-GetAddress;
	.set	pop;

// 
	.set	push;
	.set	noreorder;
	.section	.text.##GetAddressImmediate,"ax",@progbits;
	.align 2;
	.globl	GetAddressImmediate;
	.type	GetAddressImmediate,@function;
	.ent	GetAddressImmediate,0;
GetAddressImmediate:
	or $t9, $ra, $zero;
	j __ResolveVariableAddress;
	nop;
	.end	GetAddressImmediate;
	.size	GetAddressImmediate,.-GetAddressImmediate;
	.set	pop;

// 
	.set	push;
	.set	noreorder;
	.section	.text.##__ResolveVariableAddress,"ax",@progbits;
	.align 2;
	.globl	__ResolveVariableAddress;
	.type	__ResolveVariableAddress,@function;
	.ent	__ResolveVariableAddress,0;
__ResolveVariableAddress:
	lw $v0, Level;
	addiu $v1, $zero, 2;
	bge $v0, $v1, __ResolveVariableAddress_ByMap;
	nop;
	addiu $v1, $zero, 1;
	beq $v0, $v1, __ResolveVariableAddress_ByMission;
	nop;
	beq $zero, $zero, __ResolveVariableAddress_ByMenu;
	nop;

__ResolveVariableAddress_ByMission:
	lw $v1, Mission;
	blez $v1, __ResolveVariableAddress_ByMenu;
	nop;
	beq $zero, $zero, __ResolveVariableAddress_ByMap;
	nop;

__ResolveVariableAddress_ByMenu:
	beq $zero, $zero, __ResolveVariableAddress_AddByte;
	addiu $v1, $zero, 0;

__ResolveVariableAddress_ByMap:
	// Co-op campaign map ids mirror the campaign ids with +20.
	addiu $v1, $zero, 21;
	slt $t0, $v0, $v1;
	bne $t0, $zero, __ResolveVariableAddress_MapNormalized;
	nop;
	addiu $v1, $zero, 36;
	slt $t0, $v0, $v1;
	beq $t0, $zero, __ResolveVariableAddress_MapNormalized;
	nop;
	addiu $v0, $v0, -20;

__ResolveVariableAddress_MapNormalized:
	sltiu $t0, $v0, 17;
	beq $t0, $zero, __ResolveVariableAddress_Zero;
	nop;
	la $v1, __LocalGetAddress_offsets;
	addu $v1, $v1, $v0;
	lb $v1, 0($v1);
	bltz $v1, __ResolveVariableAddress_Zero;
	nop;

__ResolveVariableAddress_AddByte:
	addu $a0, $a0, $v1;
	lw $v0, 0($a0);
	jr $t9;
	nop;

__ResolveVariableAddress_Zero:
	move $v0, $zero;
	jr $t9;
	nop;
	.end	__ResolveVariableAddress;
	.size	__ResolveVariableAddress,.-__ResolveVariableAddress;
	.set	pop;


#--------------------------------------------------------
#------------------- STANDARD LIBRARY -------------------
#--------------------------------------------------------
FUNCTION(printf, 0x0011D5D8)
FUNCTION(sprintf, 0x0011D920)
FUNCTION(snprintf, 0x0011D878)
FUNCTION(memset, 0x0011A518)
FUNCTION(memcpy, 0x0011A370)
FUNCTION(memmove, 0x0011A41c)
FUNCTION(strncpy, 0x0011AFC8)
FUNCTION(strlen, 0x0011AB04)
FUNCTION(strcmp, 0x0011A8A0)
FUNCTION(strncmp, 0x0011ae00)
FUNCTION(malloc, 0x0011ef60)
FUNCTION(free, 0x0011efb0)

#--------------------------------------------------------
#------------------------- MATH -------------------------
#--------------------------------------------------------
# FUNCTION(cosf, 0x00135878)
FUNCTION(asinf, 0x00136278)
FUNCTION(powf, 0x00136788)
FUNCTION(fabsf, 0x00135960)
FUNCTION(fptodp, 0x00131918)
FUNCTION(floorf, 0x001359A8)
FUNCTION(__divdi3, 0x0012feb0)
FUNCTION(ceilf, 0x00135770)
FUNCTION(internal_fastmodf_inGame, 0x004d75a8)
FUNCTION(internal_fastmodf_inLobby, 0x005bd108)

#--------------------------------------------------------
#------------------------ MATH 3D -----------------------
#--------------------------------------------------------
FUNCTION(matrix_unit, 0x0013c478)
FUNCTION(matrix_rotate_x, 0x0013c5c0)
FUNCTION(matrix_rotate_y, 0x0013c668)
FUNCTION(matrix_rotate_z, 0x0013c518)

#--------------------------------------------------------
#------------------------ COLOR -------------------------
#--------------------------------------------------------
FUNCTION(internal_colorLerp_inGame, 0x004d75e0) # Not Ported
FUNCTION(internal_colorLerp_inLobby, 0x005bd140) # Not Ported


#--------------------------------------------------------
#----------------------- GRAPHICS -----------------------
#--------------------------------------------------------
#VARIABLE_FUNCTION(internal_drawFunc, vaDrawTextFunc)
#VARIABLE_FUNCTION(gfxGetFontWidth, vaGetTextWidthFunc)

FUNCTION(EnableFontColors_Multiplayer, 0x005C07C8)
FUNCTION(DisableFontColors_Multiplayer, 0x005C07E8)

FUNCTION(internal_drawFunc_MainMenu, 0x00454A70)

FUNCTION(internal_widthFunc_MainMenu, 0x00454780)

FUNCTION(internal_drawBox_inGame, 0x005BE610) # Not Ported
FUNCTION(internal_drawBox_inLobby, 0x00699C08) # Not Ported
FUNCTION(internal_doGifPaging_inGame, 0x004c3f40) # Not Ported
FUNCTION(internal_doGifPaging_inLobby, 0x005af9e8) # Not Ported
FUNCTION(internal_setupGifPaging_inGame, 0x004c3e10) # Not Ported
FUNCTION(internal_setupGifPaging_inLobby, 0x005af8b8) # Not Ported
FUNCTION(internal_getFrameTex_inGame, 0x004e4d70) # Not Ported
FUNCTION(internal_getFrameTex_inLobby, 0x005cab40) # Not Ported
FUNCTION(internal_getEffectTex_inGame, 0x004c4200) # Not Ported
FUNCTION(internal_getEffectTex_inLobby, 0x005afbe8) # Not Ported
FUNCTION(internal_drawSprite_inGame, 0x004c5b30) # Not Ported
FUNCTION(internal_drawSprite_inLobby, 0x005b1518) # Not Ported
FUNCTION(gfxDrawCubicLine, 0x004d1780) # Not Ported
FUNCTION(gfxRegisterDrawFunction, 0x004C4650) # Not Ported
FUNCTION(gfxDrawQuad, 0x004CA188) # Not Ported
FUNCTION(gfxResetQuad, 0x005b6378) # Not Ported
FUNCTION(gfxSetBlendMode, 0x004c97d8) # Not Ported
FUNCTION(gfxSetTexture, 0x004c9a58) # Not Ported

#--------------------------------------------------------
#---------------------- MEMORY CARD ---------------------
#--------------------------------------------------------
FUNCTION(McOpen, 0x0013A160)
FUNCTION(McClose, 0x0013A2C0)
FUNCTION(McSeek, 0x0013A380)
FUNCTION(McRead, 0x0013A510)
FUNCTION(McWrite, 0x0013A628)

#--------------------------------------------------------
#------------------------- MOBY -------------------------
#--------------------------------------------------------
FUNCTION(mobySpawn, 0x004F7200) # Not Ported
FUNCTION(mobyDestroy, 0x004F76A0) # Not Ported
FUNCTION(mobyUpdateTransform, 0x004FE720) # Not Ported
FUNCTION(mobyGetFunctions, 0x0051F358) # Not Ported
FUNCTION(mobySetState, 0x00502250) # Not Ported
FUNCTION(mobyGetDamage, 0x00504248) # Not Ported
FUNCTION(mobyPlaySound, 0x0058f6d0) # Not Ported
FUNCTION(mobyPlaySoundByClass, 0x0058f778) # Not Ported
FUNCTION(mobyBlowCorn, 0x0050e318) # Not Ported
FUNCTION(mobyAnimTransition, 0x00502030) # Not Ported
FUNCTION(mobyCollDamageDirect, 0x00503408) # Not Ported
FUNCTION(mobyIsHero, 0x005cd578) # Not Ported
FUNCTION(mobyMoveSystemUpdate, 0x0051d528) # Not Ported
FUNCTION(mobyMoveSystemInit, 0x0051a758) # Not Ported
FUNCTION(mobySetMoveDistanceThresholds, 0x0051ef30) # Not Ported
FUNCTION(mobySetMoveSpeedLimits, 0x0051efa0) # Not Ported
FUNCTION(mobySetMoveAngularSpeeds, 0x0051f040) # Not Ported
FUNCTION(mobySetAnimCache, 0x0051aba0) # Not Ported
FUNCTION(mobyProcessDamage, 0x005184d0) # Not Ported
FUNCTION(mobyMove, 0x005169F8) # Not Ported
FUNCTION(mobyStand, 0x00516a70) # Not Ported
FUNCTION(mobyStartFlash, 0x00506960) # Not Ported
FUNCTION(mobyUpdateFlash, 0x00506b88) # Not Ported
FUNCTION(mobyGetJointMatrix, 0x004f8150) # Not Ported
FUNCTION(mobySpawnExplosion, 0x003c3b38) # Not Ported
FUNCTION(mobySpawnSplash, 0x0042e9f0) # Not Ported
FUNCTION(mobySpawnMinibombs, 0x0040a8c0) # Not Ported
FUNCTION(mobyGetTargetVars, 0x00506068) # Not Ported

#--------------------------------------------------------
#------------------------ PLAYER ------------------------
#--------------------------------------------------------
FUNCTION(playerGiveWeapon, 0x00628018) # Not Ported
FUNCTION(playerEquipWeapon, 0x005F0208) # Not Ported
FUNCTION(playerGetWeaponMaxAmmo, 0x00626FB8) # Not Ported
FUNCTION(playerStripWeapons, 0x005e2e68) # Not Ported
FUNCTION(playerRespawn, 0x005E2940) # Not Ported
FUNCTION(playerDropFlag, 0x005F05E8) # Not Ported
FUNCTION(playerGetFromUID, 0x005cd480) # Not Ported
FUNCTION(internal_playerSetPosRot, 0x005EB448) # Not Ported
FUNCTION(playerIncHealth, 0x005D1140) # Not Ported
FUNCTION(playerDecHealth, 0x005D1038) # Not Ported
FUNCTION(playerGetFromSlot, 0x005cd3d0) # Not Ported
FUNCTION(playerGetSpawnpoint, 0x006242d0) # Not Ported
FUNCTION(playerGetJuggSafeTeam, 0x005d0fd8) # Not Ported
FUNCTION(playerIsConnected, 0x004447e8) # Not Ported
FUNCTION(playerGetWeaponAlphaModCount, 0x006299a8) # Not Ported

#--------------------------------------------------------
#------------------------ MASTER ------------------------
#--------------------------------------------------------
FUNCTION(masterGet, 0x005cf340) # Not Ported
FUNCTION(masterDelete, 0x005cf4c8) # Not Ported
FUNCTION(masterCreate, 0x005cf3f8) # Not Ported

#--------------------------------------------------------
#------------------------ WEAPON ------------------------
#--------------------------------------------------------
FUNCTION(weaponTurnOnHoloshields, 0x005a37f0)
FUNCTION(weaponTurnOffHoloshields, 0x005a3940)

#--------------------------------------------------------
#-------------------------- UI --------------------------
#--------------------------------------------------------
FUNCTION(internal_uiDialog, 0x00719A28) # Not Ported
FUNCTION(internal_uiSelectDialog, 0x00719C68) # Not Ported
FUNCTION(internal_uiInputDialog, 0x00719B80) # Not Ported

#FUNCTION(uiShowPopup, 0x00540170)
#FUNCTION(uiShowHelpPopup, 0x00540140)

FUNCTION(internal_uiMsgString_inGame,  0x004E4180) # Not Ported
FUNCTION(internal_uiMsgString_inLobby,  0x005c9f50) # Not Ported
#FUNCTION(uiShowTimer, 0x005401E8)
FUNCTION(uiRunCallbacks, 0x0015a050) # Not Ported

#--------------------------------------------------------
#------------------------- TIME -------------------------
#--------------------------------------------------------
FUNCTION(timerGetSystemTime, 0x0012e370)

#--------------------------------------------------------
#------------------------ VEHICLE -----------------------
#--------------------------------------------------------
FUNCTION(vehicleRemovePlayer, 0x00619140)
FUNCTION(vehicleAddPlayer, 0x006158E8)

#--------------------------------------------------------
#------------------------ GUBER -------------------------
#--------------------------------------------------------
FUNCTION(guberEventRead, 0x00611880)
FUNCTION(guberEventWrite, 0x00611808)
FUNCTION(guberEventCreateEvent, 0x00611338)
FUNCTION(guberMobyCreateSpawned, 0x0061C2B0)
FUNCTION(guberGetObjectByUID, 0x005ce6e0)
FUNCTION(guberGetObjectByMoby, 0x005cec98)
FUNCTION(guberGetUID, 0x005cec68)
FUNCTION(guberMobyGetPlayerDamager, 0x005ce5c8)
FUNCTION(guberMobyDestroy, 0x0061c450)

#--------------------------------------------------------
#------------------------ SOUND -------------------------
#--------------------------------------------------------
FUNCTION(soundPlay, 0x0058f340)
FUNCTION(soundCreateHandle, 0x0058ce58)
FUNCTION(soundKillByHandle, 0x0058f228)
FUNCTION(soundKillById, 0x0058f118)

#--------------------------------------------------------
#------------------------- SIF --------------------------
#--------------------------------------------------------
FUNCTION(SifInitRpc, 0x00129d90)
FUNCTION(SifExitRpc, 0x00129f30)
FUNCTION(SifRpcGetOtherData, 0x0012a270)
FUNCTION(SifBindRpc, 0x0012a538)
FUNCTION(SifCallRpc, 0x0012a718)

FUNCTION(SifCheckStatRpc, 0x0012a918)
FUNCTION(SifInitIopHeap, 0x0012c1b8)
FUNCTION(SifAllocIopHeap, 0x0012c240)
FUNCTION(SifFreeIopHeap, 0x0012C3A8)
FUNCTION(SifIopReset, 0x0012cc30)
FUNCTION(SifIopSync, 0x0012cdb0)
FUNCTION(_SifLoadModuleBuffer, 0x0012CBC0)

FUNCTION(SifWriteBackDCache, 0x00129ce0)
FUNCTION(SifSetDma, 0x00126f60)
FUNCTION(SifDmaStat, 0x00126f40)

#--------------------------------------------------------
#------------------------- MUSIC ------------------------
#--------------------------------------------------------
FUNCTION(internal_musicPlayTrack_inGame, 0x0051F980)
FUNCTION(internal_musicPlayTrack_inLobby, 0x005FEDE8)
FUNCTION(internal_musicStopTrack_inGame, 0x0051FD28)
FUNCTION(internal_musicStopTrack_inLobby, 0x005FF190)
FUNCTION(internal_musicPauseTrack_inGame, 0x0051FE18)
FUNCTION(internal_musicPauseTrack_inLobby, 0x005FF280)
FUNCTION(internal_musicUnpauseTrack_inGame, 0x0051FE38)
FUNCTION(internal_musicUnpauseTrack_inLobby, 0x005FF2A0)
FUNCTION(internal_musicTransitionTrack_inGame, 0x0051FBC8)
FUNCTION(internal_musicTransitionTrack_inLobby, 0x005FF030)

#--------------------------------------------------------
#------------------------- WAD --------------------------
#--------------------------------------------------------
FUNCTION(internal_wadGetSectors, 0x00159A00)

#--------------------------------------------------------
#----------------------- COLLISION ----------------------
#--------------------------------------------------------
FUNCTION(CollMobysSphere_Fix, 0x004bb788)
FUNCTION(CollLine_Fix, 0x004b7e50)

#--------------------------------------------------------
#------------------------ RANDOM ------------------------
#--------------------------------------------------------
FUNCTION(rand, 0x005006d0)
FUNCTION(randVector, 0x004b7e50)
FUNCTION(randVectorRangeNeg, 0x005083c8)
FUNCTION(randVectorRange, 0x00508448)
FUNCTION(randRange, 0x00500748)
FUNCTION(randRangeNeg, 0x005007a0)
FUNCTION(randRangeInt, 0x00500700)
FUNCTION(randRadian, 0x00500800)

#--------------------------------------------------------
#-------------------------- MAP -------------------------
#--------------------------------------------------------
VARIABLE_FUNCTION(internal_SwitchToLevel, vaSwitchToLevelFunc)
