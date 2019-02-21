/*
 * @file main.cpp
 * @Author Fatema Janahi & Julia Gangemi
 * @date December 2018
 * @brief moves robot arm using wiimote button inputs
 *  
 * Program moves servo motors to certain angles 
 * depending on which buttons are pressed on the
 * Wiimote
 *     
 */
 
/*System Includes*/
#include "RoboticArm.h"
#include "WiimoteBtns.h"
#include "WiimoteAccel.h"
#include "ZedBoard.h"
#include "address.h"
#include <unistd.h>


/*
 * Main function creates objects
 * of type RoboticArm and WiimoteBtns 
 * to listen to which buttons are pressed
 * and move robot arm accordingly
 *
 * @param None:
 * @return 0: if successful 
 */
int main()
{
//creates object of robot arm
RoboticArm robotic_arm;

//creates object of Wiimote
WiimoteBtns b;

//integers to hold number of button, number of servo, and angle
int Bcode, servo, angle;

angle=90; //set angle to 90 initially

//buttons with corresponding servos and code
//
//up button --> base --> 103
//down button --> bicep --> 108
//right button --> elbow --> 106
//left button --> wrist --> 105
//A button --> gripper --> 48

//infinite while loop
while(true)

{
//listen to button value and store in Bcode
Bcode =b.Listen();


//Moving arm using buttons

if (Bcode ==103) //button up
{
	servo = 0; //base servo
}
else if (Bcode==108) //button down
{
	servo = 1; //bicep servo
}
else if (Bcode==106) //right arrow
{

	servo=2; //elbow
}

else if (Bcode==105) //left arrow
{

        servo=3; //wrist
}
else if(Bcode==48)
{
	servo=4;
}
else
{
}


if (Bcode==151) //+ button
{
	angle=angle+10;
	
	if (angle >= 180)
	{
	angle=180;
	}
}
else if (Bcode==156) //- button
{
        angle=angle-10;

        if (angle <= 0)
        {
        angle=0;
        }
}

//move arm accordingly
robotic_arm.MoveServo(servo, angle, 45);

}
}

