#ifndef ARDUINO_SETUP_H
#define ARDUINO_SETUP_H

#include <Arduino.h>

/*
List of all components used:
- 6x servo motors (5x MG996R & 1x SG90): For robot movement
- 1x joystick: For robot control
- 3x buttons: For axis/joint selection
- 1x Switch: For joint selection
- 1x Switch: For robot power on
- 1x LCD: For display
- 1x RGB LED: For power on/off state
*/

#define SERVO_JOINT_1_PIN 2
#define SERVO_JOINT_2_PIN 3
#define SERVO_JOINT_3_PIN 4
#define SERVO_JOINT_4_PIN 5
#define SERVO_JOINT_5_PIN 6
#define SERVO_END_EFFECTOR_PIN 7

#define BUTTON_1_PIN 22
#define BUTTON_2_PIN 23
#define BUTTON_3_PIN 24

#define SWITCH_POWER_PIN 25
#define SWITCH_SELECTION_PIN 26


#endif