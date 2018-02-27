/*
 * Lamp.cpp
 *
 *  Created on: 27 Feb 2018
 *      Author: feabhas
 */

#include <iostream>
#include <utility>
#include <array>
#include <algorithm>
#include "lamp.h"
using namespace std;



namespace Home{
void PrintLamp(const Lamp& lamp){
	std::cout<<"house code:";

	if (lamp.device.first == HouseCode::INVALID){
		std::cout << " invalid" ;
	}else{
		std::cout <<static_cast<char>(static_cast<int>(lamp.device.first)+64);
	}
	std::cout	<<std::endl;
	std::cout<<"unit code:"<< lamp.device.second<<std::endl;
	std::cout<<"device state:"<< lamp.state<<std::endl;
}

void Lamp_on(Lamp& lamp){
	lamp.state=true;
	//PrintLamp(lamp);
}

void Lamp_off(Lamp& lamp){
	lamp.state=false;
	//PrintLamp(lamp);
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
	lamp.device.first=static_cast<HouseCode>(house_in -64);
	lamp.device.second=code_in;
	lamp.state = false;
	return lamp;
}

void Lamp_array_on(Lamp_Array& lamp_array){
	for (Lamp& elem: lamp_array){
			if (elem.device.first != HouseCode::INVALID)
				Lamp_on( elem);
		}
}

void Lamp_array_off(Lamp_Array& lamp_array){
	for (Lamp& elem: lamp_array){
			if (elem.device.first != HouseCode::INVALID)
				Lamp_off(elem);
		}
}

bool is_lamp_on(const Lamp& lamp){
	return (lamp.state && lamp.device.first!=HouseCode::INVALID);
}


}


