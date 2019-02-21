#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include"WiimoteBtns.h"

using namespace std;

WiimoteBtns::WiimoteBtns()
{
//opens memory
fd=open("/dev/input/event2", O_RDONLY);

//error if memory fails
if (fd == -1)
 {
 std::cerr << "Error: Could not open event file - forgot sudo?\n";
 exit(1);
 } 

}
//destructor to close memory
WiimoteBtns::~WiimoteBtns()
{

close(fd);
}
//function to read buttons pressed, returns button code
int WiimoteBtns::Listen()
{
int code, value;
//while (true)
 //{
 // Read a packet of 32 bytes from Wiimote
 char buffer[32];
 read(fd, buffer, 32);

 // Extract code (byte 10) and value (byte 12) from packet
  code = buffer[10];
 value = buffer[12];
 
 // Send to ButtonEvent()
 ButtonEvent(code,value); 

//}
return (code);
}

//function to print button pressed
void WiimoteBtns::ButtonEvent(int code, int value)
{

cout<<"Code= "<<code<<", value = "<<value<<endl;

}



