/*
 * MessageQueue.cpp
 *
 *  Created on: 2 Mar 2018
 *      Author: feabhas
 */

#include "MessageQueue.h"

namespace Home {

MessageQueue::MessageQueue() {
	// TODO Auto-generated constructor stub

}

MessageQueue::~MessageQueue() {
	// TODO Auto-generated destructor stub
}

bool MessageQueue::push(Time::Instant instant) {
	myqueue.push(instant);
	return true;
}

Time::Instant MessageQueue::get() {
	Time::Instant tval=myqueue.front();
	myqueue.pop();
	return tval;
}

bool MessageQueue::is_empty() {
	return myqueue.empty();
}

} /* namespace Home */
