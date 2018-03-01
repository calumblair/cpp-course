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
#include "Event.h"
namespace Time {

class Instant;


class EventList {
private:
	static constexpr unsigned max_events{16};
	unsigned int idx {0};
	std::array<Event, max_events> events_array {};

public:
	EventList()=default;
	~EventList();
	bool add_event(const Instant& inst_on, const Instant& inst_off,  Home::Room&  room );
	void update_time(const Instant&);
};

} /* namespace Time */

#endif /* EVENTLIST_H_ */
