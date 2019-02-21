assign6: main.o RoboticArm.o WiimoteAccel.o WiimoteBtns.o ZedBoard.o
	g++ main.o RoboticArm.o WiimoteAccel.o WiimoteBtns.o ZedBoard.o -o assign6

main.o: main.cpp RoboticArm.h WiimoteAccel.h WiimoteBtns.h ZedBoard.h
	g++ -g -Wall -c main.cpp -o main.o

RoboticArm.o: RoboticArm.cpp RoboticArm.h
	g++ -g -Wall -c RoboticArm.cpp -o RoboticArm.o

WiimoteAccel.o: WiimoteAccel.cpp WiimoteAccel.h
	g++ -g -Wall -c WiimoteAccel.cpp -o WiimoteAccel.o

WiimoteBtns.o: WiimoteBtns.cpp WiimoteBtns.h
	g++ -g -Wall -c WiimoteBtns.cpp -o WiimoteBtns.o

ZedBoard.o: ZedBoard.cpp ZedBoard.h
	g++ -g -Wall -c ZedBoard.cpp -o ZedBoard.o

clean:
	rm main.o RoboticArm.o WiimoteBtns.o WiimoteAccel.o ZedBoard.o assign6
