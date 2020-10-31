/*
 * RoleTimer.h
 *
 *  Created on: Oct 26, 2020
 *      Author: anotherme
 */

#ifndef NETWORK_ROLETIMER_H_
#define NETWORK_ROLETIMER_H_

#include "Timer.h"

class Role;

class RoleTimer : public Timer {
public:
	RoleTimer(float expires_, std::string& address_, Role* creator_);
	void callback();
	void cancel();
private:
	Role* const creator;
};


#endif /* NETWORK_ROLETIMER_H_ */
