/*
 * Role.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#include "Role.h"

#include <iostream>	// del later;

#include "Node.h"

Role::Role(std::weak_ptr<Node> node) {
	this->node = node;
	this->node.lock()->registerRole(this); // is it safe?
	running = true;
	// add logger
}

Timer Role::setTimer(float seconds, bool callback){
	//set timer for node.network here;
}

void Role::stop(){
	running = false;
	node.lock()->unregisterRole(this);
}
