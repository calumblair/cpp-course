/*
 * Event.h
 *
 *  Created on: 28 Feb 2018
 *      Author: feabhas
 */

#ifndef EVENT_H_
#define EVENT_H_
#include "Instant.h"
#include "Room.h"

namespace Time {

class Event {
public:
	Event()=default;
	Event(const Instant& inst_on, const Instant& inst_off,  Home::Room&  room );
	virtual ~Event();
	void do_action(const Instant& inst);
	const Home::Room& get_room() const;

private:
	Instant inst_on {0,0};
	Instant inst_off {0,0};
	Home::Room* room { };
};

} /* namespace Time */

#endif /* EVENT_H_ */
