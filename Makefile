ARM_COMPILER = arm-linux-gnueabihf-g++

all:
	g++ -o ./p1/limit ./p1/set_limit.cpp -std=c++11
	g++ -o ./p2/proj ./p2/projp2.cpp -std=c++11
	g++ -o ./p2/vr ./p2/projp2vr.cpp -std=c++11
	g++ -o ./p2/vl ./p2/projp2vl.cpp -std=c++11

arm:
	ARM_COMPILER -o ./p1/limit ./p1/set_limit.cpp -std=c++11
	ARM_COMPILER -o ./p2/proj ./p2/projp2.cpp -std=c++11
	ARM_COMPILER -o ./p2/vr ./p2/projp2vr.cpp -std=c++11
	ARM_COMPILER -o ./p2/vl ./p2/projp2vl.cpp -std=c++11
