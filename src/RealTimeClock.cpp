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
	minute++;
	if (minute == 60){
		minute = 0;
		hour++;
		if(hour == 24){
			hour = 0;
			day++;
		}
	}
	Time::Instant current_time {hour,minute};
	controller.update_time(current_time);

	//std::this_thread::sleep_for (std::chrono::milliseconds{1000});

	if(day==1)
		return true;
	else
		return false;
}

} /* namespace Time */
