/*
 * Timer.h
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#ifndef NETWORK_TIMER_H_
#define NETWORK_TIMER_H_

#include <string>

// переписать это с учетом нового наследования - надо ли вообще все сделать виртуальным?
// но тогда вообще везде надо сделать virtual - в классе Role, например
class Timer {
public:
	Timer(float expires_, std::string& address_);
	virtual ~Timer() = 0;
	virtual void callback() = 0;
	void cancel();

	float expires;
	const std::string address;	//sender_address - возможно, удалить за ненадобностью
	bool cancelled;
};

inline Timer::~Timer(){};


// should it be in this h and .cpp file or somewhere else?
class CompareTimers{
public:
	bool operator() (const Timer* timer1, const Timer* timer2) const;
};


#endif /* NETWORK_TIMER_H_ */
