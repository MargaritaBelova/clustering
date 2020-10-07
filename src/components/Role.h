/*
 * Role.h
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#ifndef COMPONENTS_ROLE_H_
#define COMPONENTS_ROLE_H_

#include <memory>
#include "../network/Timer.h"	// rewrite later to pointer?

//del later
#include <iostream>

class Node;

enum Role_id{
	acceptor,
	replica,
	leader,
	scout,
	commander,
	bootstrap,
	seed,
	requester
};

class Role {
public:
	Role(std::weak_ptr<Node> node_);
	virtual ~Role() = 0;
	virtual Role_id getRoleName() const = 0;

	Timer setTimer(float seconds, bool callback); //is it ok for time be float?
	std::weak_ptr<Node> node;
private:
	void stop();
	bool running = false;
	//Logger& logger;
};

inline Role::~Role(){}

#endif /* COMPONENTS_ROLE_H_ */
