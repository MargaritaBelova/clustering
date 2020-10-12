/*
 * Timer.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#include "Timer.h"

Timer::Timer( float expires_, std::string address_, void (Role::*fpcallback_)() ) : expires(expires_),
	address(address_), fpcallback(fpcallback_) {
	cancelled = false;
}

short Timer::cmp(const Timer& timer2) const{
	if (expires < timer2.expires) {
		return -1;
	} else if (expires > timer2.expires) {
		return 1;
	}
	return 0;
}

void Timer::cancel(){
	cancelled = true;
}



