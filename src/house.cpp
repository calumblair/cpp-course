//============================================================================
// Name        : house.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <utility>
#include "lamp.h"
using namespace std;


void PrintLamp(const Lamp& lamp){
	std::cout<<"house code:"<< static_cast<char>(static_cast<int>(lamp.device.first)+65)<<std::endl;
	std::cout<<"unit code:"<< lamp.device.second<<std::endl;
	std::cout<<"device state:"<< lamp.state<<std::endl;
}


int main() {

	Lamp lamp1 {{HouseCode::A, 1}, false };
	Lamp lamp2{};

	lamp2.device.first=HouseCode::B;
	lamp2.device.second=2;
	lamp2.state=false;

	std::cout<<"Lamp1"<<endl;
	PrintLamp(lamp1);
	std::cout<<"Lamp2"<<endl;
	PrintLamp(lamp2);

	return 0;
}
