ARM_COMPILER = arm-linux-gnueabihf-g++

all:
	g++ -o limit ./p1/set_limit.cpp -std=c++11
	g++ -o proj ./p2/projp2.cpp -std=c++11
	g++ -o vr ./p2/projp2vr.cpp -std=c++11
	g++ -o vl ./p2/projp2vl.cpp -std=c++11

arm:
	ARM_COMPILER -o limit ./p1/set_limit.cpp -std=c++11
	ARM_COMPILER -o proj ./p2/projp2.cpp -std=c++11
	ARM_COMPILER -o vr ./p2/projp2vr.cpp -std=c++11
	ARM_COMPILER -o vl ./p2/projp2vl.cpp -std=c++11
