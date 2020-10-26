/*
 * Timer.h
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#ifndef NETWORK_TIMER_H_
#define NETWORK_TIMER_H_

#include <string>

class Role;

class Timer {
public:
	//maybe by value?
	Timer( float expires_, std::string& address_, Role* creator_, void (Role::*fpcallback_)() );
	void cancel();

	float expires;
	std::string address;
	bool cancelled;

	Role* creator;
	void (Role::*fpcallback)();
};


// should it be in this h and .cpp file or somewhere else?
class CompareTimers{
public:
	bool operator() (const Timer& timer1, const Timer& timer2) const;
};


#endif /* NETWORK_TIMER_H_ */
