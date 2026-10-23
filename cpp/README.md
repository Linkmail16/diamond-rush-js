# Diamond Rush (C++)

Diamond Rush (Gameloft, 2006) as a native desktop game for **Windows and Linux**, in readable C++.

## Not an emulator

This does not run the original `.jar` and there is no Java virtual machine. The original game's Java bytecode was decompiled into plain C++ classes (`src/game/`), with readable English names for the obfuscated classes, fields and methods. The only hand-written part is `src/runtime/`, a small reimplementation of the Java / MIDP pieces the game uses (String, arrays, exceptions, Graphics, Image, RecordStore...) plus the window, keyboard and sound with SDL2.

- **Same game:** it was checked against the JavaScript version (itself checked frame by frame against the original bytecode). The whole game state is compared every 25 frames over long random play sessions, and it is identical.
- **Java semantics kept:** 32-bit integers that wrap (`-fwrapv`), `int64_t` for `long`, bounds-checked arrays and Java exceptions.
- **Single executable:** graphics, levels, texts and sounds are embedded. Saves go to the user's app data folder.

## Controls

| Key | Action |
|---|---|
| Arrows / WASD | Move |
| Space / Enter | Action (key 5) |
| E | Key 5 |
| R | Star (*) |
| Q | Left soft key (✔) |
| Esc / P / Backspace | Right soft key (↩, menu / pause) |
| 0 – 9 | Phone keypad |
| Mouse click on the bottom corners | Soft keys |
| F / F11 / Alt+Enter | Fullscreen |
| M | Mute |
| G | Smooth mode (on by default): the game keeps its 20 frames per second, the picture slides at your monitor's refresh rate |
| L | Frame rate limit when smooth mode is off (20 = original, 30, 60, unlimited; more FPS = everything faster) |

## Building

Requires CMake 3.16+, a C++17 compiler (GCC or Clang recommended) and SDL2.

**Linux**

```
sudo apt install build-essential cmake libsdl2-dev
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
./build/diamondrush
```

**Windows** (cross-compiled from Linux with MinGW-w64, SDL2 linked statically, one `.exe`)

```
sudo apt install mingw-w64
# SDL2-devel-2.x-mingw.tar.gz from https://github.com/libsdl-org/SDL/releases, unpacked in third_party/SDL2-mingw
cmake -S . -B build-win -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=cmake/mingw-w64.cmake \
      -DSDL2_MINGW_DIR=$(pwd)/third_party/SDL2-mingw/x86_64-w64-mingw32
cmake --build build-win -j
```

## Code

| Path | What it is |
|---|---|
| `src/game/game.h` | All game classes: fields and methods. |
| `src/game/Game.cpp` | The main class: menus, levels, objects, drawing. |
| `src/game/SpritePack.cpp`, `Cutscene.cpp`, `Actor.cpp`, ... | The other classes of the original. |
| `src/runtime/runtime.h` | Java / MIDP for the game: `Ref<T>` references, `Arr<T>` arrays, `String`, `Graphics`, `Image`... |
| `src/runtime/runtime.cpp` | Their implementation (software drawing, saves, sound priorities). |
| `src/runtime/platform.cpp` | Window, input, audio (SDL2) and the 20 frames per second game loop. |
| `src/res/res_data.cpp` | The original game resources and sounds, embedded. |
| `third_party/` | `stb_image.h` (PNG) and `dr_mp3.h` (MP3), public domain. |

Diamond Rush belongs to Gameloft. Non-profit fan project.
