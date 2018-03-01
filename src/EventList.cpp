/*
 * EventList.cpp
 *
 *  Created on: 28 Feb 2018
 *      Author: feabhas
 */

#include "EventList.h"
#include "Event.h"
#include <iostream>
#include <array>
namespace Time {

bool EventList::add_event(const Instant& inst_on, const Instant& inst_off,  Home::Room&  room )
{
	if(idx==max_events){
		std::cout<<"No more events can be added"<<std::endl;
		return false;
	}
	else{

		//events_array[idx] = Event(inst_on,inst_off, room);
		//events_array[idx].Event{inst_on,inst_off, room};
		Event e{inst_on,inst_off, room};
		events_array[idx] = e;
		idx++;
		return true;
	}

}
void EventList::update_time(const Instant& inst) {
	for (auto& i : events_array ){
		i.do_action(inst);
	}
}

EventList::~EventList() {
}
} /* namespace Time */

