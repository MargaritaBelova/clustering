/*
 * Role.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#include "Role.h"
#include "Node.h"

Role::Role(Node* node) {
	this->node = node;
	//this->node->registerRole(this);
	running = true;
	// add logger
}
