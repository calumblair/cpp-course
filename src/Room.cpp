/*
 * Room.cpp
 *
 *  Created on: 28 Feb 2018
 *      Author: feabhas
 */

#include "Room.h"
#include "lamp.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "Dimmablelamp.h"

namespace Home{
//helper functions for count_if
static bool exists_and_is_on(I_switchable* lamp){
	return (lamp != nullptr && lamp->is_on());
}
static bool exists_and_is_off(I_switchable* lamp){
	return (lamp && !lamp->is_on());
}


Room::Room(const char* new_name): name{new_name}{
	switches.reserve(initial_switches);
}

Room::~Room() {
	// TODO Auto-generated destructor stub
}

bool Room::add(I_switchable& device){
	switches.push_back(&device);
	return true;
}

void Room::all_on(void){
	for (auto s:switches){
		s->on();
	}
}

void Room::all_off(void){
	for (auto s:switches){
			s->off();
		}
}
void Room::dim(uint32_t percent){
	for (auto s:switches ){
		Dimmable_lamp* dim_lamp{dynamic_cast<Dimmable_lamp*>(s)};
		if(dim_lamp !=nullptr){
			dim_lamp->dim(percent);
		}
	}
}

void Room::status(void){
	int lights_on  = std::count_if(switches.begin(), switches.end(), &exists_and_is_on);
	int lights_off = std::count_if(switches.begin(), switches.end(), &exists_and_is_off);
	std::cout << "In " << name << " there are " << lights_on << " switches on and "
			<< lights_off << " lamps off.\n";
}

void Room::set_name(const char* new_name) {
	name = new_name;
}

}
