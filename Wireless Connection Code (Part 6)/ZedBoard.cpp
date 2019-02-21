#include <iostream>  
#include <stdlib.h>  
#include <fcntl.h>  
#include <unistd.h>  
#include <sys/mman.h>  
#include <bitset>
#include <iomanip>
#include <cmath>
#include"ZedBoard.h"
#include"address.h"
using namespace std;
 
ZedBoard::ZedBoard()
        {
		//opens memory
                fd = open( "/dev/mem", O_RDWR);
        pBase = (char *) mmap(NULL, gpio_size, PROT_READ | PROT_WRITE, MAP_SHARED,     fd, gpio_address);
        }
	//destructor to close memory
         ZedBoard::~ZedBoard()
        {
                 munmap(pBase, gpio_size);
                close(fd);
}

/**
 * Write a 4-byte value at the specified general-purpose I/O location.
 *   * 
 *    * @param pBase  Base address returned by 'mmap'.   
 *     * @parem offset Offset where device is mapped.   
 *      * @param value Value to be written.   */  

void ZedBoard::RegisterWrite( int offset, int value) 
{		
	* (int *) (pBase + offset) = value;  
} 

/**   * Read a 4-byte value from the specified general-purpose I/O location.  
 *  *
 *   * @param pBase  Base address returned by 'mmap'.   
 *    * @param offset Offset where device is mapped.  
 *     * @return  Value read.   
 *      */

int ZedBoard::RegisterRead( int offset)
{   	
	return * (int *) (pBase + offset); 
}

char* ZedBoard::getpBase() {return pBase;}



/** Changes the state of an LED (ON or OFF) *  @param pBase base address of I/O *  @param ledNum LED number (0 to 7) *  @param state State to change to (ON or OFF) */


void ZedBoard::Write1Led(int ledNum, int state)
{
	//calculate the offset from the base
	//since the address increments by 4,
	//start at led0 which is 300 (gpio_led1_offset)and add 
	//4 multiplied by the led num.
	int offset =  gpio_led1_offset  + (ledNum*4); 
	//					
	//send the base, offset, and state to registerwrite
	RegisterWrite(offset, state);
	
}

/** Reads the value of a switch  
 *  * - Uses base address of I/O  
 *   *   @param pBase base address of I/O  
 *    *   @param switchNum Switch number (0 to 7)  
 *     *   @return  Switch value read  */ 

int Read1Switch(ZedBoard *zb, int switchNum){
        //calculate the offset from the base
        //// since the address increments by 4,
        //// start at switch0  which is 332(gpio_sw1_offset)
        //and add 4 multiplied by the switch  num.
        int offset =  gpio_sw1_offset  + (switchNum*4);
        //

	//read the value of the switch
	int value = zb->RegisterRead(offset);
	
	//return the value
	return value;
}

/** Set the state of the LEDs with the given value. 
 *  * @param pBase
 *   * Base address for general-purpose I/O  
 *    * @param value         
 *     * Value between 0 and 255 written to the LEDs  */ 


void ZedBoard::WriteAllLeds(int value)

{	
	/*//counter to know which LED number
	int count =0;
	
	//run a loop while there are LEDs
	while (count <8)
	{
		//return the last digit of the binary number and save
		//it into int last
		int last = value&1;
		//turn on/off the corrosponding LED
		Write1Led(pBase, count, last);
		//move to the next LED
		count++;
		//get rid of the last digit of the binary number
		value = value/2;  
	}	*/

	int x;
	int v = value;
	for (int i =0; i<8; i++)
	{
	
	x=v%2;

	Write1Led(i, x);
	
	v = v/2;
	
	}						
}

/** Reads all the switches and returns their value in a single integer.  
 * * @param pBase  Base address for general-purpose I/O  
 * * @return  A value that represents the value of the switches  */ 
/*

int ReadAllSwitches(ZedBoard *zb)
{

	//int status holds 1 or 0 (on or off)
	int status;
	//int decNum holds the number to return
	int decNum = 0;
	//int mult is the integer to increment to the next binary digit
	int mult = 1;
	//count keeps track of switch number
	int count = 0; 
	//run loop while there are switches
	while (count <8)
	{
	//Read the switch status and save it in status
	status= Read1Switch(zb, count);
	//make decNum equal to Decnum plus (0/1) times the digit place
	decNum = decNum + (status * mult);
	//move to next digit place
	mult = mult *2;
	//move to the next switch
	count ++;
}
//return the value
return decNum;
}

int PushButtonGet(ZedBoard *zb)
{

if(zb->RegisterRead(gpio_pbtnu_offset)!=0)
{
return 1;
}
else if(zb->RegisterRead(gpio_pbtnd_offset)!=0)
{
return 2;
}
else if(zb->RegisterRead(gpio_pbtnl_offset)!=0)
{
return 3;
}
else if(zb->RegisterRead(gpio_pbtnr_offset)!=0)
{
return 4;
}
else if(zb->RegisterRead(gpio_pbtnc_offset)!=0)
{
return 5;
}
else
{
return 0;
}
}*/

/*void ReadButtons(ZedBoard *zb)
{
//status of switch
int val; 
//int to store binary
int binary=0;

int x =0;
for (int i=0; i<8; i++)
	{	
	val = Read1Switch(zb, i);
	//	binary = binary + ( val << i);
	//binary = binary + (Read1Switch(pBase, i) << i);
	//				}
	binary = binary + (val * pow(2,i));
	//cout <<binary << endl;
	//
	//send this value (COUNTER) to WriteAllLEDs so the lights reflect the switches
	WriteAllLeds(zb, binary);
	}	//
	
	int oldStates[5]= {0, 0, 0, 0, 0};
	//
	int on;
	while (x==0)
	{	
	on = PushButtonGet(zb);	
	//			
	//
	
	if(on==0)
	{
	for(int i=0;i<5;i++)
	{
	oldStates[i]=0;
	}
	}

	if (oldStates[on-1] <1) //if it changed state
	{

	switch(on)
	{
		case 0: 
		{
		for(int i=0;i<5;i++)
		{
			oldStates[i]=0;
		}
		}
		break;

		case 1:{//if up button
		binary++;
		oldStates[0]=1;	
		WriteAllLeds(zb, binary);
		}
		break;

		case 2:{//if down button
		binary--;
		oldStates[1]=1;
		WriteAllLeds(zb, binary);}
		
		break;
	case 3:{//if left
	binary=binary*2;
	oldStates[2]=1;
	WriteAllLeds(zb, binary);}
break;
	case 4:{//if right {
	binary=binary/2;
	oldStates[3]=1;
	WriteAllLeds(zb, binary);}
break;
	case 5:{// if center{
	binary=0;
	for(int i=0; i<8; i++)
	{
	
        val = Read1Switch(zb, i);
        //      binary = binary + ( val << i);
        //binary = binary + (Read1Switch(pBase, i) << i);
        //                              }
        binary = binary + (val * pow(2,i));
        //cout <<binary << endl;
        //
        //send this value (COUNTER) to WriteAllLEDs so the lights reflect the switches
        WriteAllLeds(zb, binary);
        	
	}
	}
	break;
	
default:{
	x=1;
}
break;
}
}
}

cout << binary;

}
*/


