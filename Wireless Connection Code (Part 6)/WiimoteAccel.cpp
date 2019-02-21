#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include"WiimoteAccel.h"

using namespace std;
WiimoteAccel::WiimoteAccel()
{
//opens memorry
fd=open("/dev/input/event0", O_RDONLY);

//if memory fails
if (fd == -1)
 {
 std::cerr << "Error: Could not open event file - forgot sudo?\n";
 exit(1);
 } 

}

//destructor to close memory
WiimoteAccel::~WiimoteAccel()
{

close(fd);
}

//function to read values of accleration
short WiimoteAccel::Listen()
{

//while (true)
 //{
 // Read a packet of 16  bytes from Wiimote
 char buffer[16];
 read(fd, buffer, 16);

 // Extract code (byte 10) and value (byte 12) from packet
 int code = buffer[10];
 short acceleration= *(short *) (buffer+12);
 

 // Send to ButtonEvent()
 AccelerationEvent(code,acceleration); 

//}
return(acceleration);
}

//function to return acceleration
int WiimoteAccel::ListenDir()
{

//while (true)
 //{
 // Read a packet of 16  bytes from Wiimote
 char buffer[16];
 read(fd, buffer, 16);

 // Extract code (byte 10) and value (byte 12) from packet
 int code = buffer[10];
 //short acceleration= *(short *) (buffer+12);


 // Send to ButtonEvent()
 //AccelerationEvent(code,acceleration);

//}
return(code);
}


//function to print out acceleration and direction
void WiimoteAccel::AccelerationEvent(int code, int acceleration)
{

cout<<"Code= "<<code<<", acceleration = "<<acceleration<<endl;

//return(code);
}



