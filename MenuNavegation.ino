#include "MenuNavigation.h"
#include "Option1.h"
#include "Option2.h"
#include "Option3.h"

#define PIN_NAVEGATION 16
#define PIN_CONFIRMATION 15

MenuNavigation menuNavigation(PIN_NAVEGATION);
Option1 option1;
Option2 option2;
Option3 option3;

void setup() {
  menuNavigation.init();
}

void loop() {
  menuNavigation.navigate();

  switch (menuNavigation.getSelectedOption()) {
    case 0:
      if (digitalRead(PIN_CONFIRMATION) == LOW) {
        option1.run(PIN_NAVEGATION);
      }
      break;
    case 1:
      if (digitalRead(PIN_CONFIRMATION) == LOW) {
        option2.run(PIN_NAVEGATION);
      }
      break;
    case 2:
      if (digitalRead(PIN_CONFIRMATION) == LOW) {
        option3.run(PIN_NAVEGATION);
      }
      break;
    default:
      //
      break;
  }
}

