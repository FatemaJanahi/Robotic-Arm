#ifndef ROBOTIC_ARM_H
#define ROBOTIC_ARM_H
// Physical base address of GPIO
const unsigned gpio_address = 0x400d0000;
// Length of memory-mapped IO window
const unsigned gpio_size = 0xff;

const int base_angle_offset = 0x100; // Offset for base servo angle
const int base_speed_offset = 0x104; // Offset for base servo speed
const int bicep_angle_offset = 0x108; // Offset for bicep servo angle
const int bicep_speed_offset = 0x10c; // Offset for bicep servo speed
const int elbow_angle_offset = 0x110; // Offset for elbow servo angle
const int elbow_speed_offset = 0x114; // Offset for elbow servo speed
const int wrist_angle_offset = 0x118; // Offset for wrist servo angle
const int wrist_speed_offset = 0x11c; // Offset for wrist servo speed
const int gripper_angle_offset = 0x120; // Offset for gripper servo angle
const int gripper_speed_offset = 0x124; // Offset for gripper servo speed

class RoboticArm
{
// File descriptor for memory-mapped I/O
int fd;
// Mapped address
char *pBase;
// Write a value into the given memory offset in the memory-mapped I/O.
void RegisterWrite(unsigned offset, unsigned value);
// Read a value from the given memory offset in the memory-mapped I/O.
int RegisterRead (unsigned offset);
public:
// Class constructor
RoboticArm();
// Destructor
~RoboticArm();
// Move a servo to a target position with the given speed. ARgument
// 'angle' is a value between 0 and 180. Argument 'speed' in an integer
// greater than 0, given in angles per second.
//
// Argument 'id' can take the following values:
// 0 - Base
// 1 - Bicep
// 2 - Elbow
// 3 - Wrist
// 4 - Gripper
//
void MoveServo(int id, int angle, int speed);
};
#endif
