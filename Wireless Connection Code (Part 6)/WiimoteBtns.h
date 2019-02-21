#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

class WiimoteBtns
{
private:
int fd;  //int for memory

public:
WiimoteBtns();  //constructor
~WiimoteBtns();  //desructor
int Listen();  //function to return button pressed
void ButtonEvent(int code, int value);  //function to print button pressed
};



