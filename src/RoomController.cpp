/*
 * RoomController.cpp
 *
 *  Created on: 2 Mar 2018
 *      Author: feabhas
 */

#include "RoomController.h"

namespace Home {

RoomController::RoomController() {
	// TODO Auto-generated constructor stub

}

RoomController::~RoomController() {
	// TODO Auto-generated destructor stub
}

void RoomController::add_event(Time::Instant instant, Time::Instant instant1,
		Room& room) {
	event_list.add_event(instant,instant1,room);

}

void RoomController::update_time(Time::Instant instant) {

	my_message_queue.push(instant);
	queue_occupied.notify_all();
}

bool RoomController::run() {

	std::unique_lock<std::mutex> guard {mutex};
	while(1){
		while (my_message_queue.is_empty()){
			queue_occupied.wait(guard);
		}
		Time::Instant inst = my_message_queue.get();
		event_list.update_time(inst);
	}
}

} /* namespace Home */
