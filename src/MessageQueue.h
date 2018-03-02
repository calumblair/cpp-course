/*
 * MessageQueue.h
 *
 *  Created on: 2 Mar 2018
 *      Author: feabhas
 */

#ifndef MESSAGEQUEUE_H_
#define MESSAGEQUEUE_H_
#include "Instant.h"
#include <queue>
#include <mutex>
namespace Home {

class MessageQueue {
private:
	 std::queue<Time::Instant> myqueue {};
	 std::mutex mutex;
public:
	MessageQueue();
	virtual ~MessageQueue();
	bool push(Time::Instant);
	Time::Instant get();
	bool is_empty();
};

} /* namespace Home */

#endif /* MESSAGEQUEUE_H_ */
