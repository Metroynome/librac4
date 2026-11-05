# librac4
librac4 is built upon dnawrkshp's "libdl".  Majority credits to him.

libdl: https://github.com/Dnawrkshp/libdl

Small C library for developing integrated programs for Ratchet and Clank 4 campaign/cooperative PS2

Campaign graphics helpers (`gfxScreenSpaceText`, `gfxGetFontWidth` and
`gfxScreenSpaceBox`) resolve through `VariableAddress_t` tables for NTSC-U,
PAL, NTSC-J and NTSC-K, including the boot menu and co-op planets. Boxes use
normalized screen coordinates; text positions and widths use 512 by 416 units.
Call these helpers only after the corresponding overlay and renderer are ready,
while the current VU chain is being built, before `VU1_sendChain` submits it.

## Building

Building librac4 requires an installation of the open source PS2SDK. I recommend using a prebuilt docker image.

### Grab the latest ps2dev docker image

```docker pull ps2dev/ps2dev```

### Clone and enter the repo

```git clone https://github.com/Metroynome/librac4.git && cd librac4```

### Launch a new docker container with the current directory mounted

```docker run -it --rm -v "$PWD\:/src" ps2dev/ps2dev```

### Add make

```apk add make```

### Enter mounted directory

```cd src```

### Build

```make```

## Installing

You can run ```make install``` to install the library into your local PS2SDK lib folder.

## Testing

I have a few sample tests that make use of the library to do simple things. You can build these individually by ```cd```ing into the target /test/ directory and running ```make```

## Compact address tables

The resolver accepts original full `VariableAddress_t` tables, fixed-base `rac4VariableAddressCompact_t` tables, and selectable-base `rac4VariableAddressCompactBase_t` tables. Full-table ABI is unchanged. Fixed compact tables occupy 32 bytes; custom-base tables occupy 32 bytes on the EE.

```c
/* Illustrative values; not verified game addresses. */
rac4VariableAddressCompact_t vaFixed = {
	.MainMenu = 0,
	.Battledome = RAC4_VA_COMPACT_BASE(0x00400000),
	.Catacrom = RAC4_VA_COMPACT_OFFSET(0x00400000, 0x00400100),
};

rac4VariableAddressCompactBase_t vaCustom = {
	.MainMenu = 0,
	.Base = RAC4_VA_COMPACT_CUSTOM_BASE(0x00400100),
	.Battledome = RAC4_VA_COMPACT_OFFSET(0x00400100, 0x00400000),
	.Catacrom = RAC4_VA_COMPACT_OFFSET(0x00400100, 0x00400100),
};
```

The first stored word carries the format marker: 0x80000000 for fixed-base compact, 0xc0000000 for custom-base compact. The resolver removes both marker bits before using the base. Use low EE addresses (or REL offsets), without marker bits, as OFFSET arguments. Nonzero map entries must differ from the chosen base by a multiple of four within +/-32767 words. Encoded zero is unavailable; 0x8000 represents the same address as the base. A custom base need not match any map entry, and omitted maps remain unavailable.

`MainMenu` is a plain 32-bit address at byte 4 in both compact layouts. You may write its initializer first; designated initializer order does not control struct layout. The fixed layout stores `Battledome` first internally; the custom layout stores `Base` first.

The unpublished menu/lobby-tagged compact layout has been replaced. Update old compact initializers and rebuild their consumers together with this resolver; old compact binaries are not supported by the revised menu-bearing layouts. Full tables remain compatible. librac3's existing fixed Veldin layout retains its encoding. No live PCSX2 verification was performed for this change.
