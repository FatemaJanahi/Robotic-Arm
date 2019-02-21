#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#ifndef WIIMOTEACCEL_H
#define WIIMOTEACCEL_H
class WiimoteAccel
{

private:
int fd; //int to hold memory

public:
WiimoteAccel(); //construtor
~WiimoteAccel(); //destructor
short Listen();  //function to read acceleration
virtual void AccelerationEvent(int code, int acceleration);
int ListenDir();  //returns acceleration
};

#endif

