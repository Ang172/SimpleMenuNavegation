#include "Option2.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

void Option2::run(int pinConfirmButton) {
  Adafruit_SH1106G display(128, 64, &Wire, -1);
  display.begin(0x3C, true);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.println("Screen Option 2");
  display.display();

  delay(1000);

  display.clearDisplay();

  while (digitalRead(pinConfirmButton) == HIGH) {
    if (digitalRead(pinConfirmButton) == LOW){
      break;
    }
    //add logic
  }
}