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

Lamp::Lamp(HouseCode house_code, int unit_code):
						device {house_code, unit_code}
{
	std::cout<<"Constructing from non-default constructor: ";
	status();
}

Lamp::~Lamp(){
	state = false;
	cout<<"Destroying: ";
	status();
}

void Lamp::status(){
	if (device.first != HouseCode::INVALID){
		std::cout<<"house code:";
		std::cout <<static_cast<char>(static_cast<int>(device.first)+64);
		std::cout<<"     unit code:"<< device.second	<<
				"     device state:"<< state<<std::endl;
	}
}


void Lamp::set_id(DeviceCode d){
	device.first=d.first;
	device.second=d.second;
}

DeviceCode Lamp::id(){
	return {device.first, device.second};
}

void Lamp::on(){
	state=true;
	status();
}

void Lamp::off(){
	state=false;
	status();
}

bool Lamp::is_on() const{
	return (state && device.first!=HouseCode::INVALID);
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

	return Lamp(static_cast<HouseCode>(house_in -64), code_in);
}



void Lamp_array_on(Lamp_Array& lamp_array){
	for (Lamp& elem: lamp_array){
		if (elem.id().first != HouseCode::INVALID)
			elem.on();
	}
}

void Lamp_array_off(Lamp_Array& lamp_array){
	for (Lamp& elem: lamp_array){
		if (elem.id().first != HouseCode::INVALID)
			elem.off();
	}
}

void Lamp_status(Lamp* lmp){
	bool stat=(*lmp).is_on();
	if (stat==true){
		std::cout<<"The lamp is "<<"on"<<std::endl;
	}
	else{
		std::cout<<"The lamp is "<<"off"<<std::endl;

	}
}

void Lamp_status(const Lamp& lmp){
	bool stat=lmp.is_on();
	if (stat==true){
		std::cout<<"The lamp is "<<"on"<<std::endl;
	}
	else{
		std::cout<<"The lamp is "<<"off"<<std::endl;

	}
}
}
