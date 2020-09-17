/*
 * Role.h
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#ifndef CLUSTER_ROLE_H_
#define CLUSTER_ROLE_H_

#include "../network/Timer.h"

class Node;


class Role {
public:
	Role(Node* node);
	virtual ~Role();	// del later?
	Timer setTimer(float seconds, bool callback);
	void stop();

	Node* node;
	bool running;
	//Logger& logger;
};



#endif /* CLUSTER_ROLE_H_ */
