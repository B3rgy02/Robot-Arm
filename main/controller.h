#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>

/*
Goal of this file:
Create function to facilitate the FSM code
*/

/*
BOM:
- Robot control:
  - 6 servo motors: motors
  - 1 joytstick: for moving in joint mode or linear mode
  - 3 buttons: to select joint/axis
  - 1 switch: to select joint
  - 1 button: confirm button
  - 1 LED for lighting when clicked
  - 1 LCD for displaying
  - 2 RGB LED: 1 for robot movement & 1 for power displaying
  - 1 Switch: for power on/off
*/

void controllerSetup();

#endif