#ifndef GAMES_H
#define GAMES_H

#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// Flappy Bat Variables
int batY = 32;
int velocity = 0;
int pipeX = 128;
int pipeGapY = 25;
int gameScore = 0;

void runFlappyBat(Adafruit_SH1106G &display, int btnUp, int btnSelect) {
  display.clearDisplay();
  
  // Game physics loop
  velocity += 1; // Gravity simulation
  batY += velocity;
  pipeX -= 3;    // Scroll pipes left
  
  // Controls
  if (digitalRead(btnUp) == LOW) {
    velocity = -3; // Jump flap
  }
  
  // Boundary collisions
  if (batY > 54) batY = 54;
  if (batY < 0) batY = 0;
  
  // Respawn pipes
  if (pipeX < -15) {
    pipeX = 128;
    pipeGapY = random(15, 45);
    gameScore++;
  }
  
  // Render graphics elements
  display.fillRect(10, batY, 6, 6, SH110X_WHITE); // Draw Player Bat
  display.fillRect(pipeX, 0, 12, pipeGapY, SH110X_WHITE); // Upper Obstacle
  display.fillRect(pipeX, pipeGapY + 20, 12, 64, SH110X_WHITE); // Lower Obstacle
  
  display.setCursor(0, 0);
  display.print("Score: "); display.print(gameScore);
  display.display();
  
  // Return handle check
  if (digitalRead(btnSelect) == LOW && gameScore > 0) {
    batY = 32; pipeX = 128; gameScore = 0; // Reset state
  }
}

#endif
