#ifndef ROBOT_DATA_H
#define ROBOT_DATA_H

#include <Arduino.h>
#include <Servo.h>

#define NB_SERVOS 6

class robotData {
  private:
    Servo robotServos[NB_SERVOS];     // Servo object array
    
    int servosOffsets[2][NB_SERVOS];  // Servo offsets values for true 0 degre and true 180 degres
    int servoAngleVals[NB_SERVOS];    // Angle values of each servo

    int homingAngles[NB_SERVOS];      // Homing position servo angles
    
    bool isMoving = false;            // Boolean value to toggle LED when the robot is moving
    enum toolingState {               // Flags to determined tooling state (closed, opened or moving)
      closed = 0,
      opened = 1,
      moving = 2
    } toolingStatus;

  public:
    // Constructor
    robotData() { 
      if(NB_SERVOS > 12) { // Allow a maximum of 12 servo motors
        for (int i = 2; i <= 13; i++) {
          robotServos[i-2].attach(i);
        }
      } else {
        for (int i = 2; i <= NB_SERVOS + 1; i++) {
          robotServos[i-2].attach(i);
        }
      }
    }

    // Getter functions
    
    // Setter functions

    // Other functions
    void homing() { // Put robot back to homing position
      // Change moving states
      isMoving = true;
      toolingStatus = moving;
      /*** Change LED light to red ***/

      // Move all joints to homing angle values
      for (int i = 0; i < NB_SERVOS; i++){
        robotServos[i].write(homingAngles[i]);
      }

      // Delay to allow servos to complete movement
      delay(500);

      // Change moving states
      isMoving = false;
      toolingStatus = opened;
      /*** Change LED light to green ***/
    }
  };

#endif



















