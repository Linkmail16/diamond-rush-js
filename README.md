# Diamond Rush (HTML5)

Diamond Rush (Gameloft, 2006) running in the browser, in readable JavaScript.

Open `index.html` to play (no server needed).

## Not an emulator

This is **not an emulator** and it does **not** run the original `.jar`. There is no Java virtual machine and no J2ME emulation.

The original game's Java bytecode was decompiled and translated into plain JavaScript: real classes and real `if` / `while` / `for` / `switch` code, with readable English names for the obfuscated classes, fields and methods. The only part that stands in for the phone is `rt.js`, a small reimplementation of the Java / MIDP classes the game uses (Graphics, Image, StringBuffer, RecordStore...) on top of `<canvas>` and Web Audio.

- **Same game:** same levels, rules, timing and quirks as the original. The readable code was checked frame by frame against a direct translation of the original bytecode: the same screen on every frame and the same save data.
- **Java math kept:** 32-bit integers (`| 0`, `Math.imul`), `BigInt` for `long`, booleans as `0` / `1`.
- **Graphics, levels and texts:** the original resources (`res.js`). **Music and sounds:** the original MIDI files rendered to MP3 (`snd.js`).
- **Static:** no server, no dependencies, no build step. Works offline.
- **Changes from the original:** "More Games" in the main menu does nothing, on-screen soft key buttons, smooth mode and FPS limit, and a line in the credits.

## Controls

- Arrows or WASD: move
- Space or Enter: action (key 5)
- Q: left soft key (✔)
- Esc or P: right soft key (↩, menu / pause)
- Both soft keys are also the buttons under the screen, or tap the bottom corners of the screen
- M: mute · F: fullscreen
- G: smooth mode (draws at the monitor refresh rate without changing the game speed)
- L: frame rate limit

## Code

| File | What it is |
|---|---|
| `src/Game.js` | The main class: menus, levels, objects, drawing. |
| `src/SpritePack.js` | Sprite and font packs. |
| `src/Cutscene.js` | Cutscenes and dialogs. |
| `src/Actor.js` | Animated sprite with a position. |
| `src/FallingRocks.js` | Falling rocks. |
| `src/MoreGames.js` | "More games" screen. |
| `src/Rnd.js`, `src/Tables.js` | Random numbers and constant tables. |
| `src/Midlet.js` | Startup. |
| `rt.js` | The "phone": Graphics, Image, StringBuffer, RecordStore... on a `<canvas>`, sound and the 20 frames per second loop. |
| `app.js`, `index.html`, `style.css` | The page: keys, buttons and screen. |
| `res.js`, `snd.js` | Resources and sounds from the original game. |

Diamond Rush belongs to Gameloft. Non-profit fan project.
