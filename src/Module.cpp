/*
 * Module.cpp
 *
 *  Created on: 1 Mar 2018
 *      Author: feabhas
 */

#include "Module.h"
#include <iostream>
#include <utility>
#include <array>
#include <algorithm>
using namespace std;

namespace Home {

Module::Module( HouseCode house_code, int unit_code):device {house_code, unit_code}
{
	std::cout<<"Constructing from non-default constructor: ";
	status();
}

Module::~Module() {
	state = false;
		cout<<"is being destroyed: ";
		status();
}

void Module::status(){
	if (device.first != HouseCode::INVALID){
		std::cout<<"house code:";
		std::cout <<static_cast<char>(static_cast<int>(device.first)+64);
		std::cout<<"     unit code:"<< device.second	<<
				"     device state: "<<
				(state ? "on" : "off")
				<<std::endl;
	}
}


void Module::set_id(DeviceCode d){
	device.first=d.first;
	device.second=d.second;
}


DeviceCode Module::id(){
	return {device.first, device.second};
}

bool Module::is_on() const{
	return (state && device.first!=HouseCode::INVALID);
}



}/* namespace Home */
