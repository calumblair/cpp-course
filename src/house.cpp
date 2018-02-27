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

void Lamp_on(Lamp& lamp){
	lamp.state=true;
	PrintLamp(lamp);
}

void Lamp_off(Lamp& lamp){
	lamp.state=false;
	PrintLamp(lamp);
}

Lamp Make_lamp(void){
	char house_in ;
	int  code_in {0};
	bool flag=false;

	while (flag==false){
		std::cout<<"Please give valid house code:"<<std::endl;
		std::cin >> house_in;
		house_in = toupper(house_in);
		if (house_in>='A' && house_in<='P'){
			flag=true;
		}
	}

	flag=false;
	while (flag==false){
		std::cout<<"Please give valid unit code:"<<std::endl;
		std::cin >> code_in;
		if (code_in<=16 && code_in!=0){
			flag=true;
		}
	}

	Lamp lamp{};
	lamp.device.first=static_cast<HouseCode>(house_in -65);
	lamp.device.second=code_in;
	lamp.state = false;
	return lamp;
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

	Lamp lamp3=Make_lamp();
	PrintLamp(lamp3);

	Lamp_on(lamp1);
	Lamp_off(lamp1);
	return 0;
}
