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
