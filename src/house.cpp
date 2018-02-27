//============================================================================
// Name        : house.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <utility>
#include <array>
#include <algorithm>
#include "lamp.h"
using namespace std;


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

static bool is_lamp_on(const Lamp& lamp){
	return (lamp.state && lamp.device.first!=HouseCode::INVALID);
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

	std::array <Lamp, 10> lamp_array{Lamp{{HouseCode::A, 1}, false},
		Lamp{  {HouseCode::B, 2}, false},
		Lamp{  {HouseCode::B, 2}, false},
		Lamp{}};

	Lamp_array_on(lamp_array);

	for (Lamp& elem: lamp_array){
		if (elem.device.first != HouseCode::INVALID)
			PrintLamp(elem);
	}

	size_t n_lamps_on = std::count_if(lamp_array.begin(),lamp_array.end(),&is_lamp_on);
	std::cout << "there are " <<n_lamps_on <<" lamps on" <<std::endl;

//	for(size_t i=0;i<lamp_array.size();i+=2){
//		std::cout<<lamp_array[i].device.second<<std::endl;
//	}
//
//	for(auto it = std::begin(lamp_array); it != std::end(lamp_array); it+=2){
//		std::cout<<it->device.second<<std::endl;}


	//
	//	Lamp lamp3=Make_lamp();
	//	PrintLamp(lamp3);
	//
	//
	//
	//
	//	Lamp_on(lamp1);
	//	Lamp_off(lamp1);
	return 0;
}
