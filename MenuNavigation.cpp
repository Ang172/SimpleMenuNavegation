#include "MenuNavigation.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

MenuNavigation::MenuNavigation(int buttonPin) {
  this->buttonPin = buttonPin;
  this->selectedOption = 0;
}

void MenuNavigation::init() {
  Serial.begin(9600);
  if (!display.begin(0x3C, true)) {
    Serial.println(F("Could not initialize OLED display"));
    for (;;)
      ;
  }

  pinMode(buttonPin, INPUT_PULLUP);
  display.display();
  delay(2000);
  
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Menu:");
  display.println("> 1. Option 1");
  display.println("  2. Option 2");
  display.println("  3. Option 3");
  display.display();

  delay(2000);

  display.clearDisplay();
}

void MenuNavigation::navigate() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    delay(250);

    selectedOption = (selectedOption + 1) % 3;

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Menu:");

    switch (selectedOption) {
    case 0:
      display.println("> 1. Option 1");
      display.println("  2. Option 2");
      display.println("  3. Option 3");
      break;
    case 1:
      display.println("  1. Option 1");
      display.println("> 2. Option 2");
      display.println("  3. Option 3");
      break;
    case 2:
      display.println("  1. Option 1");
      display.println("  2. Option 2");
      display.println("> 3. Option 3");
      break;
    }

    display.display();
  }
}

int MenuNavigation::getSelectedOption() {
  return selectedOption;
}