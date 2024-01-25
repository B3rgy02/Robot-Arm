# Robot-Arm

Robot Arm project is for controlling a 5 DOF robot arm.

## Physical components
- 5 MG996R servo motors (for all joints)
- 1 SG90 servo motor (for tooling)
- 1 joytstick (for moving in joint mode or linear mode)
- 4 buttons (3 to select joint/axis and 1 as confirm button)
- 1 switch (1 to select joint, complementary to the 3 buttons, and 1 for power ON/OFF)
- 1 LED (for lighting when confirm button is clicked)
- 1 LCD (for displaying)
- 2 RGB LED (1 for robot movement & 1 for power displaying)

## File structure
- main.ino contains the main file where the FSM is
- fsm_actions.cpp: all actions executed in the FSM are here
- robot_data.cpp: all functions regarding the robot are here (example: homing, moving, oggling end effector, etc.)
- controller.cpp: functions used by components on the controller are here
- kinematics.cpp: all functions calculating fowards kinematics are here
- inverse_kinematics.cpp: all functions calculating inverse kinematics are here
