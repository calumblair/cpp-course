//============================================================================
// Name        : house.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "lamp.h"
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
using namespace Home;

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
