/*
 * PriorityQueueThreadSafe.cpp
 *
 *  Created on: Nov 13, 2020
 *      Author: anotherme
 */
#include "TimersPriorityQueue.h"

Timer* TimersPriorityQueue::pop(){
	std::lock_guard<std::mutex> lock(mu);
	queue.pop();
}

void TimersPriorityQueue::push(Timer* timer){
	std::lock_guard<std::mutex> lock(mu);
	queue.push(timer);
}

Timer* TimersPriorityQueue::top(){
	std::lock_guard<std::mutex> lock(mu);
	return queue.top();
}

bool TimersPriorityQueue::empty(){
	return queue.empty();
}
