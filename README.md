# Reaction Time Game – Arduino Project (Beginner Friendly)

This is a fun Reaction Time Game made with Arduino. It's perfect for playing with friends to see who reacts the fastest. No electronics needed — you’ll run it virtually using **Visual Studio Code**, **PlatformIO**, and the **Wokwi simulator**.

---

## What You’ll Be Doing (Quick Summary)

- Install a few tools (VS Code + extensions)  
- Open the project  
- Click buttons to run a virtual Arduino game  
- Play by pressing a virtual button as fast as possible  

---

## What You Need to Install

1. **Visual Studio Code**  
   Download and install from here:  
   https://code.visualstudio.com/

2. **PlatformIO Extension**  
   - Open VS Code  
   - Click the **Extensions icon** (left sidebar or press `Ctrl + Shift + X`)  
   - Search for **"PlatformIO IDE"**  
   - Click **Install**

3. **Wokwi Extension (Optional but helpful)**  
   - In the same Extensions panel, search for **"Wokwi for VS Code"**  
   - Install it

---

## Getting the Game Project

1. **Open Terminal in VS Code:**  
   - Press `Ctrl + Shift + P` to open the **Command Palette**  
   - Type **“Git: Clone”** and hit Enter  
   - Paste this link:  
     ```
     https://github.com/noiz-x/reaction-time
     ```  
   - Choose a folder where you want to save the project  
   - Once it’s done cloning, click **"Open"** when prompted  

---

## Running the Game

1. **Make Sure the Project is Set Up Correctly:**  
   - Inside the project folder, there’s a file called `platformio.ini`  
     - Make sure it has:  
       ```
       board = uno
       ```

   - There should also be a file named `wokwi.toml` with this:  
     ```
     [platformio]
     board = uno

     [env]
     platform = atmelavr
     framework = arduino

     [wokwi]
     firmware = .pio/build/uno/firmware.hex
     ```

2. **Build the Code:**  
   - On the left sidebar, click the **PlatformIO icon (alien head)**  
   - Under **PROJECT TASKS > uno > General**, click **“Build”**  
     (or click the checkmark ✓ at the bottom toolbar)

3. **Start the Simulation:**  
   - Press `Ctrl + Shift + P` to open the Command Palette  
   - Type **“Wokwi: Start Simulator”** and hit Enter  
   - The virtual Arduino board should appear with a screen, LED, buzzer, and button

---

## How to Play the Game

1. **Startup:**  
   - The LCD shows:  
     ```
     Reaction Time Game
     Press to start!
     ```

2. **Start the Game:**  
   - Click the button (in the simulation)  
   - A 3-second countdown begins — **don’t press anything yet!**  
   - If you press too soon, you lose that turn

3. **Get Ready:**  
   - After the countdown, there’s a random wait time (1–5 seconds)  
   - When the screen says **“Go!”** and the LED turns white…

4. **React Fast:**  
   - Click the button as fast as you can  
   - Your reaction time is shown on the LCD

5. **Scoring:**  
   - `< 200ms` → **"Lightning Fast!"** (green)  
   - `200–500ms` → **"Good Job!"** (blue)  
   - `> 500ms` → **"Too Late!"** (red)

6. **Next Player:**  
   - Game rotates to the next player automatically (up to 5 teams)

---

## Trouble? Try This:

- If **Wokwi Simulator doesn’t open**, try:  
  - Rebuilding the project  
  - Checking the `wokwi.toml` file for errors  
  - Restarting VS Code and trying again

- If **PlatformIO doesn’t show up**, make sure the extension is installed, then restart VS Code

---

## Want to Edit the Game?

If you ever want to tweak the game:

- Change team names in the `teamNames[]` array in the code  
- Adjust how many teams can play (`numTeams`)  
- Customize colors or messages inside the code  

But if you just want to **play**, everything is already good to go.

---