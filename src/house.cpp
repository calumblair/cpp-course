//============================================================================
// Name        : house.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "lamp.h"

#include "Dimmablelamp.h"
#include "Appliance.h"
#include "Room.h"
#include "EventList.h"
#include "Event.h"
#include "Instant.h"
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
using namespace Home;
using namespace Time;

int main() {
	Lamp lamp_a2{ HouseCode::A, 2};
	Lamp lamp_a3 {HouseCode::A, 3};
	Lamp lamp_b1 {HouseCode::B, 1};
	Dimmable_lamp dim_lamp1 {HouseCode::B , 2};
	Appliance appliance1 {HouseCode::B , 3};
	dim_lamp1.dim(0);

	Room room_a{};
	Room room_b{"Lounge"};
	room_a.add(lamp_a2);
	room_a.add(lamp_a3);


	room_b.add(lamp_b1);
	room_b.add(dim_lamp1);
	room_b.add(appliance1);

	appliance1.on();


	room_b.status();


room_a.status();

	Time::Event e1 { Instant {0,0}, Instant {0,0}, room_a};
	Time::Event e2 { };

	Time::EventList events {};

	events.add_event( Time::Instant { 9,00}, {9,10}, room_a );
	events.add_event( Time::Instant { 9,05}, {9,10}, room_b );

	events.remove_room(room_b);

	//update clock
	std::cout << "0900:" <<std::endl;events.update_time( Time::Instant { 9, 00});
	std::cout << "0901:" <<std::endl;events.update_time( Time::Instant { 9, 01});
	std::cout << "0905:" <<std::endl;events.update_time( Time::Instant { 9, 05});
	std::cout << "0910:" <<std::endl;events.update_time( Time::Instant { 9, 10});

	return 0;
}
