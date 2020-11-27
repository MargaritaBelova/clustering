/*
 * PriorityQueueThreadSafe.h
 *
 *  Created on: Nov 13, 2020
 *      Author: anotherme
 */

#ifndef NETWORK_TIMERSPRIORITYQUEUE_H_
#define NETWORK_TIMERSPRIORITYQUEUE_H_

#include <queue>
#include <mutex>
#include <vector>

#include "Timer.h"	//тут class CompareTimers, поэтому без forward declaration
// можно потом обернуть class template от Timers*


class TimersPriorityQueue{
public:
	Timer* pop();
	void push(Timer* timer);
	bool empty();
	Timer* top();

private:
	std::priority_queue<Timer*, std::vector<Timer*>, CompareTimers> queue;
	std::mutex mu;
};


#endif /* NETWORK_TIMERSPRIORITYQUEUE_H_ */
