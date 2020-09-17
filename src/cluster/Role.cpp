/*
 * Role.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#include "Role.h"

#include <iostream>	// del later;

#include "Node.h"

Role::Role(Node* node) {
	this->node = node;
	this->node->registerRole(this);
	running = true;
	// add logger
}

Role::~Role(){
	std::cout << "Role is destructed" << std::endl;
}

Timer Role::setTimer(float seconds, bool callback){
	//set timer for node.network here;
}

void Role::stop(){
	running = false;
	node->unregisterRole(this);
}
