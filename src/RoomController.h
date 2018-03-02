/*
 * RoomController.h
 *
 *  Created on: 2 Mar 2018
 *      Author: feabhas
 */

#ifndef ROOMCONTROLLER_H_
#define ROOMCONTROLLER_H_
#include "Instant.h"
#include "Room.h"
#include "MessageQueue.h"
#include "EventList.h"

namespace Home {

class RoomController {
private:
	MessageQueue my_message_queue {};
	Time::EventList event_list {};
public:
	RoomController();
	virtual ~RoomController();
	void add_event(Time::Instant, Time::Instant, Room&);
	void update_time(Time::Instant);
	bool run();

};

} /* namespace Home */

#endif /* ROOMCONTROLLER_H_ */
