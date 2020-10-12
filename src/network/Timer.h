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
	Timer( float expires_, std::string address_, void (Role::*fpcallback_)() );
	void cancel();

	float expires;
	const std::string address;

private:
	short cmp(const Timer& timer2) const;	// rewrite to operator? //change to char?
	bool cancelled;
public:	// make private again
	void (Role::*fpcallback)();

};

#endif /* NETWORK_TIMER_H_ */
