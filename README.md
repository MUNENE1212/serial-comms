# ESP32 Serial / UART Projects

Progressive projects exploring UART, serial protocols, and related
communication techniques on the ESP32. Companion to
[MUNENE1212/LED](https://github.com/MUNENE1212/LED) — that repo covered
LEDs / GPIO / PWM / multiplexed display; this one focuses on
communication.

## Toolchain

- **Board:** classic ESP32 DevKit-C v4 (`board = esp32dev`)
- **Framework:** Arduino-ESP32 (v2.x, stock PlatformIO release)
- **Build:** [PlatformIO](https://platformio.org) — one `[env:]` per exercise
- **Simulator:** [Wokwi for VS Code](https://docs.wokwi.com/vscode/getting-started)

## Repo layout

Each exercise lives in `src/NN_name/main.cpp` with a matching PlatformIO
env block in `platformio.ini`. Root `diagram.json` and `wokwi.toml` are
the "currently active" simulator config — switching exercises is a build
command plus a two-line edit in `wokwi.toml`.

```
UART/
├── platformio.ini         # one [env:NN_name] per exercise
├── diagram.json           # active Wokwi wiring
├── wokwi.toml             # active firmware/elf paths
└── src/
    └── 01_serial_hello/
```

## Build & simulate

```bash
pio run -e 01_serial_hello

# In wokwi.toml, point at that env's build output:
firmware = '.pio/build/01_serial_hello/firmware.bin'
elf      = '.pio/build/01_serial_hello/firmware.elf'

# Then run Wokwi from VS Code (⌘/Ctrl-Shift-P → "Wokwi: Start Simulator").
```

## Exercises

| # | Name | What it does | Concepts |
|---|---|---|---|
| 01 | [serial_hello](src/01_serial_hello) | Prints a greeting once a second on the default UART. | `Serial.begin`, `Serial.println`. |

## Design principles

Same "real-hardware-ready" rules used across the sister LED repo:

- **No blocking `delay()` in the main path** once the exercise moves past
  the first `hello` — everything runs from `millis()`.
- **Encapsulate patterns.** Debouncers, parsers, ring buffers, framing
  logic — all become structs + helpers as soon as they repeat.
- **Data over code.** Command tables, protocol maps, and pin lists in
  arrays so adding a case is one line.
- **Brief inline comments.** One short trailing note per meaningful line
  — no block essays.
