/*
 * MessageQueue.cpp
 *
 *  Created on: 2 Mar 2018
 *      Author: feabhas
 */

#include "MessageQueue.h"
#include <mutex>

namespace Home {
	using Guard = std::lock_guard<std::mutex>;;

MessageQueue::MessageQueue() {
	// TODO Auto-generated constructor stub

}

MessageQueue::~MessageQueue() {
	// TODO Auto-generated destructor stub
}

bool MessageQueue::push(Time::Instant instant) {
	Guard guard{mutex};
	myqueue.push(instant);
	return true;
}

Time::Instant MessageQueue::get() {
	Guard guard{mutex};
	Time::Instant tval=myqueue.front();
	myqueue.pop();
	return tval;
}

bool MessageQueue::is_empty() {
	Guard guard{mutex};
	return myqueue.empty();
}

} /* namespace Home */
