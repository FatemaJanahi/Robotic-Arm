assign5: main.o RoboticArm.o 
	g++ main.o RoboticArm.o -o assign5

main.o: main.cpp RoboticArm.h 
	g++ -g -Wall -c main.cpp -o main.o

RoboticArm.o: RoboticArm.cpp RoboticArm.h
	g++ -g -Wall -c RoboticArm.cpp -o RoboticArm.o
clean:
	rm main.o RoboticArm.o assign5
