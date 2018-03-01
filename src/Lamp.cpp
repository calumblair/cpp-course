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
						Module {house_code, unit_code}
{
	std::cout<<"Constructing a lamp: ";
	status();
}

Lamp::~Lamp(){
	cout<<"Destroying a lamp ";
	status();
}

void Lamp::on(){
	state=true;
	std::cout << "Turning on  lamp: ";
	status();
}

void Lamp::off(){
	state=false;
	std::cout << "Turning off lamp: ";status();
}

}
