#include "robot_data.h"

// Constructor
robotData::robotData() { 
  // Attach servos to arduino pins
  robotServos[ROBOT_BASE].attach(SERVO_JOINT_1_PIN);
  robotServos[ROBOT_SHOULDER].attach(SERVO_JOINT_2_PIN);
  robotServos[ROBOT_ELBOW].attach(SERVO_JOINT_3_PIN);
  robotServos[ROBOT_WRIST_1].attach(SERVO_JOINT_4_PIN);
  robotServos[ROBOT_WRIST_2].attach(SERVO_JOINT_5_PIN);
  robotServos[ROBOT_HAND].attach(SERVO_END_EFFECTOR_PIN);
      
  // Set homing angles to 0 degre
  setHomingAnglesZero();
}

// Getter functions
int robotData::getHomingAngle(int jointNum) {
  return homingAngles[jointNum];
}

int robotData::getOffsetAngle(int row, int col) {
  return servosOffsets[row][col];
}

int robotData::getServoAngle(int jointNum){
  return servoAngleVals[jointNum];
}

int robotData::getToolingStatus(){
  return toolingStatus;
}

bool robotData::getIsMoving() {
  return isMoving;
}

int robotData::getToolingMinAngle() {
  return toolingMinAngle;
}

int robotData::getToolingMaxAngle() {
  return toolingMaxAngle;
}

// Setter functions
void robotData::setHomingAngles(int angles[NB_SERVOS]) {
  for (int i = 0; i < NB_SERVOS; i++) {
    homingAngles[i] = angles[i];
  }
}

void robotData::setHomingAnglesZero() {
  for (int i = 0; i < NB_SERVOS; i++) {
    homingAngles[i] = 0;
  }
}

void robotData::setMinAngleTooling(int angle) {
  toolingMinAngle = angle;
}

void robotData::setMaxAngleTooling(int angle) {
  toolingMaxAngle = angle;
}

void robotData::setServoAngleVals(int angles[NB_SERVOS-1]) {
  for (int i = 0; i < NB_SERVOS; i++) {
    servoAngleVals[i] = angles[i];
  }
}

// Other functions
void robotData::homing() { // Put robot back to homing position
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
  toolingStatus = closed;
  /*** Change LED light to green ***/
}

void robotData::moveToAngles() {
  // Move robot to set angles
  robotServos[ROBOT_BASE].write(servoAngleVals[ROBOT_BASE]);
  robotServos[ROBOT_SHOULDER].write(servoAngleVals[ROBOT_SHOULDER]);
  robotServos[ROBOT_ELBOW].write(servoAngleVals[ROBOT_ELBOW]);
  robotServos[ROBOT_WRIST_1].write(servoAngleVals[ROBOT_WRIST_1]);
  robotServos[ROBOT_WRIST_2].write(servoAngleVals[ROBOT_WRIST_2]);
}

void robotData::toggleHand() {
  switch(toolingStatus){
    case closed:
      robotServos[ROBOT_HAND].write(servoAngleVals[toolingMaxAngle]);
      break;
    
    case opened:
      robotServos[ROBOT_HAND].write(servoAngleVals[toolingMinAngle]);
      break;

    default:
      break;
  }
}
