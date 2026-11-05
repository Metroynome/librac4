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

`GetAddress` and `GetAddressImmediate` accept both the original `VariableAddress_t` and `rac4VariableAddressCompact_t`. Existing full tables keep their layout. A compact table occupies 32 bytes instead of 52, saving 20 bytes per table before linker alignment and the shared decoder cost.

```c
rac4VariableAddressCompact_t vaExample = {
	.MainMenu = RAC4_VA_COMPACT_MENU(0),
	.Battledome = 0x00400000,
	.Catacrom = RAC4_VA_COMPACT_OFFSET(0x00400000, 0x00400100),
};
```

These are illustrative values, not game addresses. Always tag MainMenu, even when it has no address. Battledome remains a 32-bit base; later fields encode a signed word delta biased by 0x8000. Zero means unavailable; a field equal to the base encodes 0x8000. Nonzero entries must differ from the base by a multiple of four within +/-32767 words. The macro rejects constant offsets outside that range at compile time. Use a full table when it cannot fit.

The website's Address Table (Compact) formatter emits this layout, and falls back to a full table when its base is missing/ambiguous or a delta cannot fit. Recompile consumers against the updated headers and library. Do not index compact fields as an array of 32-bit addresses.

Validation: all existing regional Makefile variants build, and compiled MIPS tests match the original resolver for full and compact tables, including menu/loading states and offset boundaries. No new PCSX2 gameplay test was performed.
