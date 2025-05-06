#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD (address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int redPin = 11;      // PWM - Red
const int greenPin = 10;    // PWM - Green
const int yellowPin = 9;      // PWM - Blue
const int buttonPin = 2;    // Button
const int buzzerPin = 8;    // Buzzer
unsigned long startTime;    // Timer start
unsigned long reactionTime; // Reaction time in ms
unsigned long bestTime = 9999; // High score (ms)
bool gameRunning = false;   // Game state

// Team names (edit as needed, max 8 chars for LCD)
const char* teamNames[] = {
  "Alpha", "Beta", "Gamma", "Delta", "Epsilon",
  "Zeta"
};
const int numTeams = 5;
int currentTeamIndex = 0; // Tracks current team

void resetDisplay();
void setRGB(int red, int green, int yellow);

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  setRGB(0, 0, 0); // RGB off
  digitalWrite(buzzerPin, LOW);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Reactn Time Game");
  lcd.setCursor(0, 1);
  lcd.print("Press to start!");
  
  Serial.begin(9600);
  Serial.print("Reaction Time Game - Team ");
  Serial.print(teamNames[currentTeamIndex]);
  Serial.println(" press to start!");
}

void loop() {
  if (!gameRunning && digitalRead(buttonPin) == HIGH) {
    gameRunning = true;
    lcd.clear();
    Serial.print("Game Started! Team ");
    Serial.println(teamNames[currentTeamIndex]);
    
    lcd.setCursor(0, 0);
    lcd.print("Get Ready...");
    Serial.println("Get Ready...");
    setRGB(0, 0, 0);
    for (int i = 3; i > 0; i--) {
      lcd.setCursor(0, 1);
      lcd.print(i);
      lcd.print("...         ");
      Serial.print(i);
      Serial.println("...");
      tone(buzzerPin, 1000, 100);
      delay(1000);
      if (digitalRead(buttonPin) == HIGH) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Too Soon!");
        Serial.print("Team ");
        Serial.print(teamNames[currentTeamIndex]);
        Serial.println(": Too Soon!");
        setRGB(255, 255, 0); // Yellow
        tone(buzzerPin, 300, 500);
        delay(2000);
        setRGB(0, 0, 0);
        gameRunning = false;
        resetDisplay();
        return;
      }
    }
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ready...");
    Serial.println("Ready...");
    
    unsigned long delayStart = millis();
    unsigned long randomDelay = random(1000, 5000);
    while (millis() - delayStart < randomDelay) {
      if (digitalRead(buttonPin) == HIGH) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Too Soon!");
        Serial.print("Team ");
        Serial.print(teamNames[currentTeamIndex]);
        Serial.println(": Too Soon!");
        setRGB(255, 255, 0);
        tone(buzzerPin, 300, 500);
        delay(2000);
        setRGB(0, 0, 0);
        gameRunning = false;
        resetDisplay();
        return;
      }
    }
    
    setRGB(255, 255, 255); // White
    lcd.setCursor(0, 1);
    lcd.print("Go!        ");
    Serial.println("Go!");
    tone(buzzerPin, 1500, 200);
    startTime = millis();
    
    while (digitalRead(buttonPin) == LOW);
    
    reactionTime = millis() - startTime;
    
    if (reactionTime < 200) {
      setRGB(0, 255, 0); // Green
      tone(buzzerPin, 2000, 300);
    } else if (reactionTime <= 500) {
      setRGB(0, 0, 255); // Blue
      tone(buzzerPin, 2000, 300);
    } else {
      setRGB(255, 0, 0); // Red
      tone(buzzerPin, 500, 300);
    }
    
    if (reactionTime < bestTime) {
      bestTime = reactionTime;
    }
    
    lcd.clear();
    lcd.setCursor(0, 0);
    Serial.print("Team ");
    Serial.print(teamNames[currentTeamIndex]);
    Serial.print(": Reaction Time: ");
    Serial.print(reactionTime);
    Serial.print(" ms, Best: ");
    Serial.print(bestTime);
    Serial.print(" ms - ");
    if (reactionTime < 200) {
      lcd.print("Lightning Fast!");
      Serial.println("Lightning Fast!");
    } else if (reactionTime <= 500) {
      lcd.print("Good Job!");
      Serial.println("Good Job!");
    } else {
      lcd.print("Too late!");
      Serial.println("Too late!");
    }
    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print(teamNames[currentTeamIndex]);
    lcd.print(" ");
    lcd.print(reactionTime);
    lcd.print("ms");
    
    delay(7000);
    setRGB(0, 0, 0);
    
    gameRunning = false;
    currentTeamIndex = (currentTeamIndex + 1) % numTeams; // Next team
    resetDisplay();
    delay(500);
  }
}

void setRGB(int red, int green, int yellow) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(yellowPin, yellow);
}

void resetDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Reactn Time Game");
  lcd.setCursor(0, 1);
  lcd.print("Press to start!");
  Serial.print("Reactionn Time Game - Team ");
  Serial.print(teamNames[currentTeamIndex]);
  Serial.println(" press to start!");
}