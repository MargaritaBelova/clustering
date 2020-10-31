/*
 * RoleTimer.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: anotherme
 */

#include "RoleTimer.h"

#include "../components/Role.h"

RoleTimer::RoleTimer(float expires_, std::string& address_, Role* creator_) :
	Timer(expires_, address_), creator(creator_) {
}

void RoleTimer::callback(){
	creator->callback();
}
