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
#include "RoomController.h"
#include "RealTimeClock.h"
#include <iostream>
#include <array>
#include <algorithm>
#include <thread>
using namespace std;
using namespace Home;
using namespace Time;

int main() {
	Lamp lamp_a2{ HouseCode::A, 2};
	Lamp lamp_a3 {HouseCode::A, 3};
	Lamp lamp_b1 {HouseCode::B, 1};
//	Dimmable_lamp dim_lamp1 {HouseCode::B , 2};
//	Appliance appliance1 {HouseCode::B , 3};
//	dim_lamp1.dim(0);

	Room room_a{};
	Room room_b{"Lounge"};
	room_a.add(lamp_a2);
	room_a.add(lamp_a3);


	room_b.add(lamp_b1);
//	room_b.add(dim_lamp1);
//	room_b.add(appliance1);
//
//	appliance1.on();


	RoomController controller{};
	RealTimeClock clock{controller};

	//Time::EventList events {};

	controller.add_event( Time::Instant { 0,01}, {0,20}, room_a );
	controller.add_event( Time::Instant { 0,05}, {0,20}, room_b );

	std::thread clock_thread {&RealTimeClock::run, &clock};
	std::thread controller_thread  {&RoomController::run, &controller };

	if(clock_thread.joinable()){
		clock_thread.join();
	}
	if(controller_thread.joinable()){
			controller_thread.join();
	}

	return 0;
}
