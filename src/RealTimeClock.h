/*
 * RealTimeClock.h
 *
 *  Created on: 2 Mar 2018
 *      Author: feabhas
 */

#ifndef REALTIMECLOCK_H_
#define REALTIMECLOCK_H_
#include "RoomController.h"
namespace Time {

class RealTimeClock {
private:
	Home::RoomController& controller;

	std::uint8_t hour {0}, minute{0}, day{0};
public:
	RealTimeClock(Home::RoomController&);
	 ~RealTimeClock();
	bool run();
};

} /* namespace Time */

#endif /* REALTIMECLOCK_H_ */
