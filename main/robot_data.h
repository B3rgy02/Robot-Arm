#ifndef ROBOT_DATA_H
#define ROBOT_DATA_H

#include <Arduino.h>
#include <Servo.h>

#define NB_SERVOS 6

#define SERVO_JOINT_1_PIN 2
#define SERVO_JOINT_2_PIN 3
#define SERVO_JOINT_3_PIN 4
#define SERVO_JOINT_4_PIN 5
#define SERVO_JOINT_5_PIN 6
#define SERVO_END_EFFECTOR_PIN 7

#define ROBOT_BASE 0
#define ROBOT_SHOULDER 1
#define ROBOT_ELBOW 2
#define ROBOT_WRIST_1 3
#define ROBOT_WRIST_2 4
#define ROBOT_HAND 5

#define OFFSET_MIN 0
#define OFFSET_MAX 1

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

    int toolingMinAngle;
    int toolingMaxAngle;

  public:
    // Constructor
    robotData();

    // Getter functions
    int getHomingAngle(int jointNum);
    int getOffsetAngle(int row, int col);
    int getServoAngle(int jointNum);
    int getToolingStatus();
    int getToolingMinAngle();
    int getToolingMaxAngle();
    bool getIsMoving();

    // Setter functions
    void setHomingAngles(int angles[NB_SERVOS]);
    void setHomingAnglesZero();
    void setMinAngleTooling(int angle);
    void setMaxAngleTooling(int angle);
    void setServoAngleVals(int angles[NB_SERVOS]);

    // Other functions
    void homing();
    void moveToAngles();
    void toggleHand();
};

#endif



















