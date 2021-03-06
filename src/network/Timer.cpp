/*
 * Timer.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#include "Timer.h"

Timer::Timer( float expires_, const std::string& address_) : expires(expires_), address(address_){
	cancelled = false;
}


void Timer::cancel(){
	cancelled = true;
}


// check later
bool CompareTimers::operator() (const Timer* timer1, const Timer* timer2) const{
	return timer1->expires > timer2->expires;
}
