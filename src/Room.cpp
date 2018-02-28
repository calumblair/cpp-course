/*
 * Room.cpp
 *
 *  Created on: 28 Feb 2018
 *      Author: feabhas
 */

#include "Room.h"
#include "lamp.h"
#include <iostream>
#include <algorithm>

namespace Home{
//helper functions for count_if
static bool exists_and_is_on(Lamp* lamp){
	return (lamp != nullptr && lamp->is_on());
}
static bool exists_and_is_off(Lamp* lamp){
	return (lamp && !lamp->is_on());
}


Room::Room(const char* new_name): name{new_name}{
}

Room::~Room() {
	// TODO Auto-generated destructor stub
}

bool Room::add(Lamp& device){

	if(idx==max_lamps){
		std::cout<<"No more lamps can be added"<<std::endl;
		return false;
	}
	else{
		lamp_array[idx]=&device;
		idx++;
		return true;
	}

}

void Room::all_on(void){
	for (unsigned i=0; i<idx; i++ ){
		(lamp_array[i])->on();
	}
}

void Room::all_off(void){
	for (unsigned i=0; i<idx; i++ ){
		(lamp_array[i])->off();
	}
}

void Room::status(void){
	int lights_on  = std::count_if(lamp_array.begin(), lamp_array.end(), &exists_and_is_on);
	int lights_off = std::count_if(lamp_array.begin(), lamp_array.end(), &exists_and_is_off);
	std::cout << "In " << name << " there are " << lights_on << " lamps on and "
			<< lights_off << " lamps off.\n";
}

void Room::set_name(const char* new_name) {
	name = new_name;
}

}
