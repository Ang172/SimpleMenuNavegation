#ifndef MenuNavigation_h
#define MenuNavigation_h

#include <Arduino.h>

class MenuNavigation {
public:
  MenuNavigation(int buttonPin);
  void init();
  void navigate();
  int getSelectedOption();

private:
  int buttonPin;
  int selectedOption;

  void displayMenu();
};

#endif
