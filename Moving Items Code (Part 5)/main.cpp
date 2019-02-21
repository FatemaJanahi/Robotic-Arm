/*
 * @file main.cpp
 * @Author Fatema Janahi & Julia Gangemi
 * @date December 2018
 * @brief moves robot arm to grab object
 *  
 * Program moves servo motors to certain angles 
 * at certain speeds to pick up and object and
 * throw it
 *     
 */


/*System Includes*/
#include "RoboticArm.h"
#include <unistd.h>


/*
 * Main function creates object 
 * of type RoboticArm and calls functions
 * to perform grabbing/throwing
 *
 * @param None:
 * @return 0: if successful 
 */
int main()
{
//creates object of robot arm
RoboticArm robotic_arm;

//initial conditions
robotic_arm.MoveServo(0, 80, 45); //base
robotic_arm.MoveServo(1, 130, 45); //bicep
robotic_arm.MoveServo(2, 130, 45); //elbow
robotic_arm.MoveServo(3, 130, 45); //wrist
robotic_arm.MoveServo(4, 180, 45); //gripper

//rests so next code does not run until initial positions are reached
sleep(1);
sleep(1);

//move to grab eraser
robotic_arm.MoveServo(1, 160, 45); //bicep
robotic_arm.MoveServo(2, 120, 45); //elbow

//rest
sleep(1);
sleep(1);

//grabs eraser
robotic_arm.MoveServo(4, 30, 45);  //gripper

//rest
sleep(1);
sleep(1);

//throw eraser
robotic_arm.MoveServo(1, 70, 200); //bicep
robotic_arm.MoveServo(2, 80, 200); //elbow
robotic_arm.MoveServo(4, 90, 75); //gripper

}

