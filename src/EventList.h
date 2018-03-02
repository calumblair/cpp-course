/*
 * EventList.h
 *
 *  Created on: 28 Feb 2018
 *      Author: feabhas
 */

#ifndef EVENTLIST_H_
#define EVENTLIST_H_
#include <array>
#include "Room.h"
#include "Instant.h"
#include <list>
#include "Event.h"
#include <memory>
namespace Time {

class Instant;


class EventList {
private:

	std::list<std::unique_ptr<Event>> events_list {};

public:
	EventList()=default;
	~EventList();
	bool add_event(const Instant& inst_on, const Instant& inst_off,  Home::Room&  room );
	void update_time(const Instant&);
	void remove_room(const Home::Room&);
};

} /* namespace Time */

#endif /* EVENTLIST_H_ */
