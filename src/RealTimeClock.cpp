/*
 * RealTimeClock.cpp
 *
 *  Created on: 2 Mar 2018
 *      Author: feabhas
 */

#include "RealTimeClock.h"
#include <chrono>
#include <thread>
namespace Time {

RealTimeClock::RealTimeClock(Home::RoomController& _controller) :controller{_controller}{
	// TODO Auto-generated constructor stub
}

RealTimeClock::~RealTimeClock() {
	// TODO Auto-generated destructor stub
}

bool RealTimeClock::run() {
	while(1){
		controller.update_time(clock);
		clock.advance();
		std::this_thread::sleep_for (std::chrono::milliseconds{100});
		if(clock==Instant {0,0}) //if day has rolled over
			return true;
		}
}

} /* namespace Time */
