# Reaction Time Game – Arduino Project

This is a simple multi-team Reaction Time Game built using Arduino. It uses an RGB LED, buzzer, button, and an LCD display to simulate a "ready-set-go" style challenge where players compete for the fastest reaction time.

## ⚙️ Hardware Simulation (Wokwi)

This project is designed to be run using the **Wokwi simulator** inside **PlatformIO** on **Visual Studio Code**.

### 🧩 Components Used:
- Arduino UNO
- 16x2 I2C LCD (0x27)
- RGB LED (PWM pins: Red - D11, Green - D10, Blue - D9)
- Push Button (D2)
- Buzzer (D8)

## 🖥️ Local Setup (PlatformIO + Wokwi)

### 🔧 Prerequisites
- [VS Code](https://code.visualstudio.com/)
- [PlatformIO extension](https://platformio.org/install)
- [Wokwi extension (optional)](https://docs.wokwi.com/guides/vscode)

### 🛠️ Setup Instructions

1. **Clone the Repository**
   ```bash
   git clone https://github.com/noiz-x/reaction-time
   cd reaction-time
    ```

2. **Open in VS Code**
   Launch VS Code and open the folder you just cloned.

3. **Build & Simulate with Wokwi**

   * Make sure `platformio.ini` is set up with `board = uno`.
   * Ensure there's a `wokwi.toml` file configured (see below).
   * Hit the "Run" button or use:

     ```bash
     pio run
     ```

4. **Start Wokwi Simulator**

   * Use `Wokwi: Start Simulator` from the Command Palette.
   * You should see the Arduino board and components boot up in the simulation window.

### 📁 Example `wokwi.toml`

```toml
[platformio]
board = uno

[env]
platform = atmelavr
framework = arduino

[wokwi]
firmware = .pio/build/uno/firmware.hex
```

## 🎮 How to Play the Game (Manual Instructions)

1. **Initial Display**:

   * LCD shows: `Reaction Time Game`
   * Prompt: `Press to start!`

2. **Game Start**:

   * Press the button once.
   * The LCD will show a 3-second countdown.
   * DO NOT press during countdown — if you do, it shows **"Too Soon!"** and you lose that turn.

3. **Get Ready**:

   * After countdown, a random delay (1–5 sec) is triggered.
   * Wait until you see **"Go!"** and RGB turns white.

4. **React!**:

   * Press the button as quickly as you can.
   * Your reaction time (in ms) is displayed.

5. **Scoring**:

   * Fast reactions:

     * `< 200 ms`: "Lightning Fast!" (Green)
     * `200–500 ms`: "Good Job!" (Blue)
     * `> 500 ms`: "Too Late!" (Red)
   * Buzzer and LED colors give feedback.
   * Best time is recorded for each session.

6. **Next Team**:

   * Game automatically rotates to the next team.
   * Up to 5 teams (editable in the code).

## ✍️ Customize It

* To add more teams, edit the `teamNames[]` array and `numTeams`.
* To track best score per team or add EEPROM saving, you can expand logic easily.
* Refactor `setRGB()` to add new colors if needed.

## 🧠 Notes

* Make sure your RGB LED uses **PWM-capable pins** (e.g., 9, 10, 11 on Arduino UNO).
* Wokwi handles the I2C LCD setup internally, so no wiring needed manually—just use the correct address (`0x27`).

Fuck you man 😂💔🔥
