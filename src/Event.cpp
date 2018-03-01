/*
 * Event.cpp
 *
 *  Created on: 28 Feb 2018
 *      Author: feabhas
 */

#include "Event.h"
#include "Instant.h"
#include "Room.h"

namespace Time {

Event::Event(const Instant& new_inst_on, const Instant& new_inst_off,  Home::Room&  new_room ):

		inst_on {new_inst_on}, inst_off{new_inst_off}, room {&new_room}{


}

Event::~Event() {
	// TODO Auto-generated destructor stub
}


void Event::do_action(const Instant& inst){
	if (inst.is_equal(inst_on)){
		room->all_on();
	}
	else if (inst.is_equal(inst_off)){
		room->all_off();
	}
	else{}


}

} /* namespace Time */
